// Copyright Igor Roshchin
// contact me: mosgreyday@gmail.com
// 
// insert_many.hpp
// 
// This is simple insert many json strings
// in to provided collection function
// - provide collection to insert 
// - function inserts json strings into
// collection

#include <assert.h>
#include <bson/bcon.h>
#include <mongoc/mongoc.h>
#include <stdio.h>

/*
	dumb_insert_many

-provide:
	collection    : mongoc_collection_t
	quantity      : unsigned long int
	info_display  : bool 
		[t(display info)/f(silent)]
-does:
	inserts quantity of docs into
	collection.
	docs are "{_id: "i"}", where 
	i = 0 to quantity.
*/
static void dumb_insert_many (
	mongoc_collection_t *collection, 
	unsigned long int quantity,
	bool info_display
	)
{
   mongoc_bulk_operation_t *bulk;
   bson_error_t error;
   bson_t *doc;
   bson_t reply;
   char *str;
   bool ret;
   int i;

   bulk = mongoc_collection_create_bulk_operation_with_opts (collection, NULL);

   for (i = 0; i < quantity; i++) {
      doc = BCON_NEW ("i", BCON_INT32 (i));
      mongoc_bulk_operation_insert (bulk, doc);
      bson_destroy (doc);
   }

   ret = mongoc_bulk_operation_execute (bulk, &reply, &error);

   str = bson_as_canonical_extended_json (&reply, NULL);
   printf ("%s\n", str);
   bson_free (str);

   if (!ret) { std::cout << error.massage << std::endl; }

   bson_destroy (&reply);
   mongoc_bulk_operation_destroy (bulk);
}