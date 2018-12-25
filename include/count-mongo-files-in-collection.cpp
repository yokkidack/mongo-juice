#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include <stdio.h>
#include <string>
#include <iostream>

int
print_query_count (mongoc_collection_t *collection, bson_t *query)
{
   bson_error_t error;
   int64_t count;

   count = mongoc_collection_count_documents (
        collection, 
	bson_new(),
	NULL,
	NULL,
	NULL,
	&error);
      return count;
}

int main () {

 std::string mod = "mongo_local";// = config_json["mongo_agent_mod"].get<std::string>();
    std::string db_name ="test"; // (config_json[mod]["database"]).get<std::string>();
    std::string coll_name = "test"; // (config_json[mod]["collection"]).get<std::string>();

    mongoc_client_t* client;
    mongoc_collection_t* collection;
    mongoc_cursor_t* cursor;
    mongoc_uri_t *uri_mongoc;
    const bson_t* doc;
    bson_t* query;
    char* str;
    bson_error_t error;
    const char* database_name{ db_name.c_str() };
    const char* collection_name{ coll_name.c_str() };

    mongoc_init();


    std::string uri {"mongodb://localhost:27017"};//{config_json[mod]["uri"] };
    uri+="/?appname=";
    uri+="replicating-mongo-agent";// config_json["mongo_agent_application_name"];

    //parseing uri string
    uri_mongoc = mongoc_uri_new_with_error (uri.c_str(), &error);

    if (!uri_mongoc) {
       std::cout << "Faild to parse uri."
       <<"Check uri in config."<<std::endl
       <<"Uri provided: " << uri <<std::endl;
       exit(EXIT_FAILURE);
    }

    client = mongoc_client_new_from_uri (uri_mongoc);

    if (!client) {
       std::cout << "Faild to create client"<< std::endl;
       return EXIT_FAILURE;
    }

    std::string path {"/home/yok/Documents/m-ad/files/"};// {config_json["path"]};
    path += "file_num_";
    collection = mongoc_client_get_collection(
        client,
        database_name,
        collection_name);
    query = bson_new();
	int a = print_query_count(collection, bson_new());
	std::cout << a;
	return a;
}
