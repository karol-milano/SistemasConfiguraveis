@@ -36,14 +36,14 @@ typedef enum {false = 0, true = 1} bool;
 #include <assert.h>
 
 #ifndef HAVE_DECL_FREE
-# error "this configure-time declaration test was not run"
+"this configure-time declaration test was not run"
 #endif
 #if !HAVE_DECL_FREE
 void free ();
 #endif
 
 #ifndef HAVE_DECL_MALLOC
-# error "this configure-time declaration test was not run"
+"this configure-time declaration test was not run"
 #endif
 #if !HAVE_DECL_MALLOC
 char *malloc ();
@@ -61,6 +61,40 @@ char *malloc ();
 
 #include "hash.h"
 
+struct hash_table
+  {
+    /* The array of buckets starts at BUCKET and extends to BUCKET_LIMIT-1,
+       for a possibility of N_BUCKETS.  Among those, N_BUCKETS_USED buckets
+       are not empty, there are N_ENTRIES active entries in the table.  */
+    struct hash_entry *bucket;
+    struct hash_entry *bucket_limit;
+    unsigned n_buckets;
+    unsigned n_buckets_used;
+    unsigned n_entries;
+
+    /* Tuning arguments, kept in a physicaly separate structure.  */
+    const Hash_tuning *tuning;
+
+    /* Three functions are given to `hash_initialize', see the documentation
+       block for this function.  In a word, HASHER randomizes a user entry
+       into a number up from 0 up to some maximum minus 1; COMPARATOR returns
+       true if two user entries compare equally; and DATA_FREER is the cleanup
+       function for a user entry.  */
+    Hash_hasher hasher;
+    Hash_comparator comparator;
+    Hash_data_freer data_freer;
+
+    /* A linked list of freed struct hash_entry structs.  */
+    struct hash_entry *free_entry_list;
+
+#if USE_OBSTACK
+    /* Whenever obstacks are used, it is possible to allocate all overflowed
+       entries into a single stack, so they all can be freed in a single
+       operation.  It is not clear if the speedup is worth the trouble.  */
+    struct obstack entry_stack;
+#endif
+  };
+
 /* A hash table contains many internal entries, each holding a pointer to
    some user provided data (also called a user entry).  An entry indistinctly
    refers to both the internal entry and its associated user entry.  A user
@@ -576,19 +610,22 @@ void
 hash_clear (Hash_table *table)
 {
   struct hash_entry *bucket;
-  struct hash_entry *cursor;
 
   for (bucket = table->bucket; bucket < table->bucket_limit; bucket++)
     {
       if (bucket->data)
 	{
+	  struct hash_entry *cursor;
+	  struct hash_entry *next;
+
 	  /* Free the bucket overflow.  */
-	  for (cursor = bucket->next; cursor; cursor = cursor->next)
+	  for (cursor = bucket->next; cursor; cursor = next)
 	    {
 	      if (table->data_freer)
 		(*table->data_freer) (cursor->data);
 	      cursor->data = NULL;
 
+	      next = cursor->next;
 	      /* Relinking is done one entry at a time, as it is to be expected
 		 that overflows are either rare or short.  */
 	      cursor->next = table->free_entry_list;
@@ -995,13 +1032,14 @@ hash_print (const Hash_table *table)
       struct hash_entry *cursor;
 
       if (bucket)
-	printf ("%d:\n", slot);
+	printf ("%d:\n", bucket - table->bucket);
 
       for (cursor = bucket; cursor; cursor = cursor->next)
 	{
 	  char *s = (char *) cursor->data;
 	  /* FIXME */
-	  printf ("  %s\n", s);
+	  if (s)
+	    printf ("  %s\n", s);
 	}
     }
 }
