@@ -61,7 +61,7 @@ hash_pair_free (hash_pair *hp)
   free (hp);
 }
 
-Hash_table *
+static Hash_table *
 hash_pair_table_create (int size)
 {
   return hash_xinitialize (size,
@@ -333,7 +333,7 @@ gen_lookaheads (void)
 
 bitsetv firsts = NULL;
 
-void
+static void
 init_firsts (void)
 {
   firsts = bitsetv_create (nvars, nsyms, BITSET_FIXED);
