// // Copyright Igor Roshchin <mosgreyday@gmail.com>

// /*
//  * Mongo Agent
//  *   Agent#1
//  *       It is od to download all files from MongoDB collection.
//  *       All credentials will be provided from parent programm.
//  */


// #ifndef Mongo_agent_hpp
// #define Mongo_agent_hpp

// #endif /* Mongo_agent_hpp */

// #include <stdio.h>
// #include <string>
// #include <iostream>
// #include <fstream>
// #include <cstdint>
// #include <iostream>
// #include <vector>
// #include <bsoncxx/json.hpp>
// #include <mongocxx/client.hpp>
// #include <mongocxx/stdx.hpp>
// #include <mongocxx/uri.hpp>

// using bsoncxx::builder::stream::close_array;
// using bsoncxx::builder::stream::close_document;
// using bsoncxx::builder::stream::document;
// using bsoncxx::builder::stream::finalize;
// using bsoncxx::builder::stream::open_array;
// using bsoncxx::builder::stream::open_document;

// class Mongo_agent {
//     std::string uri_string;
//     std::string database_name;
//     std::string collection_name;
//     mongocxx::instance instance;
//     mongocxx::client client;
//     mongocxx::uri uri;
//     mongocxx::database db;
//     mongocxx::collection coll;
    
// public:
// private:
//     Mongo_agent(std::string uri,
//                 std::string database_name,
//                 std::string collection_name)
//         : uri_string{"mongodb://localhost:27017"},
//         database_name{"database"},
//         collection_name("collection")
//     {
//         instance{}; // This should be done only once.
//         uri{"mongodb://localhost:27017"};
//         client{uri};
//         db = client[this.database_name];
//         coll = db[this.collection_name];
//     }
//     auto find_cursor() -> mongocxx::cursor{
//         return mongocxx::cursor cursor = this.coll.find({});
//     }
//     auto archive() -> void{
//         int i = 0;
//         for(auto doc : find_cursor()) {
//             //std::cout << bsoncxx::to_json(doc) << "\n";
//             doc_string_to_file(bsoncxx::to_json(doc),
//                     "file_num_" + nicer_file_numbers_from_i(i++));
//         }
//     }
// };


// auto doc_string_to_file(std::string doc, std::string filename) -> void {
//     std::ofstream o(filename);
//     o << doc;
//     o.close();
// }

// auto nicer_file_numbers_from_i(int i) -> std::string{
//     std::string s{std::to_string(i)};
//     unsigned long int a = 10 - s.length();
//     std::string out(a, '0');
//     return out+s;
// }
