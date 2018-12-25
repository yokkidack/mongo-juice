#include <bson/bson.h>
#include <mongoc/mongoc.h>
#include <stdio.h>

// count

class Mongo_test {
public:
    mongoc_client_t* client;
    mongoc_collection_t* collection;

    Mongo_test(const char* database_name, const char* collection_name)
    {
        mongoc_init();
        client = mongoc_client_new("mongodb://localhost:27017/?appname=count-example");
        collection = mongoc_client_get_collection(client, database_name,
            collection_name);
    }
    ~Mongo_test()
    {
        mongoc_collection_destroy(this.collection);
        mongoc_client_destroy(this.client);
        mongoc_cleanup();
    }
    auto count(std::string json) -> long int
    {
        bson_t* doc{ bson_new_from_json((const uint8_t*)json, -1, &error) };
        bson_error_t error;
        int64_t count = mongoc_collection_count(
            this.collection,
            MONGOC_QUERY_NONE,
            doc, 0, 0, NULL, &error) if (count < 0) throw(error.message);
        return count;
    }
    auto delete_one(bson_t* doc) -> void
    {
        if (!mongoc_collection_delete_one(
                this.collection, doc,
                NULL, NULL, &error))
            throw(error.message);
    }
    auto drop_collection() -> void
    {
        bson_t* query = bson_new();
        bson_oid_init(&oid, NULL);
        BSON_APPEND_OID(doc, "_id", &oid);
        cursor = mongoc_collection_find_with_opts(
            this.collection, query, NULL, NULL);
        while (mongoc_cursor_next(cursor, &query)) {
            try {
                delete_one(query);
            }
            catch (error e) {
                throw(e);
            }
        }
    }
};
