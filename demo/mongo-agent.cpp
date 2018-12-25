/* Copyright Igor Roshchin
//  __    __ _____ _____ ___   _____
// |   \/   |     |   | |  _|_|     | contact me: mosgreyday@gmail.com
// |  |\/|  |  |  | | | |   | |  |  | "mongo_agent.hpp"
// |__|  |__|_____|_|___|_____|_____| mongo agent downloads all files
//                                    from provided db.coll of mongoDB
//
// TODO:
// - 4: mongo_agent_nice todos
*/

#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <boost/program_options.hpp>
#include <nlohmann/json.hpp>
#include "mongo_agent_nice.hpp"

std::string CONFIG{ "../config.json" };
namespace po = boost::program_options;

using namespace std;

int main(int argc, char* argv[])
{

    std::string mod; //= opts["mod"].as<std::string>();
    std::string db_name; //= opts["db_name"].as<std::string>();
    std::string coll_name; // = opts["coll_name"].as<std::string>();
    std::string uri; // = opts["uri"].as<std::string>();
    std::string app_name; // = opts["app_name"].as<std::string>();
    std::string path; // = opts["path"].as<std::string>();
    bool logging;
    try {
        po::options_description desc("Allowed options");
        desc.add_options()
        ("help", "produce help message")
        ("bd", po::value<std::string>(&db_name)->
default_value("test"),"spec bd name")
        ("coll", po::value<std::string>(&coll_name)->
default_value("test"), "spec coll name")
        ("uri", po::value<std::string>(&uri)->
default_value("mongodb://localhost:27017"), "spec uri")
        ("app", po::value<std::string>(&app_name)->
default_value("replicating-mongo-agent"), "spec app display name")
        ("path", po::value<std::string>(&path)->
default_value("/home/yok/Documents/m-ad/files/"), "spec path")
        /*("logging", po::value<bool>(&logging)->
default_value(true), "Do you really need all this logging?")*/
        ;

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help")) {
            cout << desc << "\n";
            return 0;
        }
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch (...) {
        cerr << "Exception of unknown type!\n";
    }

   
    mongoc_client_t* client;
    mongoc_collection_t* collection;
    mongoc_cursor_t* cursor;
    mongoc_uri_t* uri_mongoc;
    const bson_t* doc;
    bson_t* query;
    char* str;
    bson_error_t error;
    const char* database_name{ db_name.c_str() };
    const char* collection_name{ coll_name.c_str() };

    mongoc_init();

    uri_mongoc = mongoc_uri_new_with_error(uri.c_str(), &error);

    if (!uri_mongoc) {
        std::cout << "Faild to parse uri." << std::endl
                  << "Check uri in config." << std::endl
                  << "Uri provided: " << uri << std::endl;
        exit(EXIT_FAILURE);
    }

    client = mongoc_client_new_from_uri(uri_mongoc);

    if (!client) {
        std::cout << "Faild to create client" << std::endl;
        return EXIT_FAILURE;
    }

    collection = mongoc_client_get_collection(
        client,
        database_name,
        collection_name);
    query = bson_new();
    cursor = mongoc_collection_find_with_opts(
        collection,
        query,
        NULL,
        NULL);
    for (int i = 0; mongoc_cursor_next(cursor, &doc);) {
        str = bson_as_canonical_extended_json(doc, NULL);
        std::string str_oid = std::string(str).substr(22, 24);
        // according to oid length 
        // now files will have names like 
        // 5bfe9d31700db5cf39efd266
        // or
        // 5bfe9d95700db5cf39eff9f7
        // instead of file_num_0000000000
        doc_string_to_file(
            str,
            path + str_oid);
        bson_free(str);
    }

    bson_destroy(query);
    mongoc_cursor_destroy(cursor);
    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
    mongoc_cleanup();
    return 0;
}

