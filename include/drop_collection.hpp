// Copyright Igor Roshchin
// contact me: mosgreyday@gmail.com
//
// drop_collection.hpp:
//
// This is simple drop collection function
// provide collection to drop 
// function drops collection

#include <assert.h>
#include <bson/bcon.h>
#include <mongoc/mongoc.h>
#include <stdio.h>
#include <string>

static void drop (mongoc_collection_t *collection)
{
   mongoc_bulk_operation_t *bulk;
   bson_error_t error;
   bson_t *query;
   bson_t *doc;
   bson_t *opts;
   bson_t reply;
   char *str;
   bool ret;
   int i;

   bulk = mongoc_collection_create_bulk_operation_with_opts (collection, NULL);

   /* Remove everything */
   query = bson_new ();
   mongoc_bulk_operation_remove (bulk, query);
   bson_destroy (query);

   ret = mongoc_bulk_operation_execute (bulk, &reply, &error);

   str = bson_as_canonical_extended_json (&reply, NULL);
   printf ("%s\n", str);
   bson_free (str);

   if (!ret) {
      printf ("Error: %s\n", error.message);
   }

   bson_destroy (&reply);
   mongoc_bulk_operation_destroy (bulk);
}