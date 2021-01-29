@@ -42,11 +42,12 @@ location_t startsymbol_location;
 `---------------------------------*/
 
 static symbol_t *
-symbol_new (const char *tag, location_t location)
+symbol_new (struniq_t tag, location_t location)
 {
   symbol_t *res = XMALLOC (symbol_t, 1);
 
-  res->tag = xstrdup (tag);
+  struniq_assert (tag);
+  res->tag = tag;
   res->location = location;
 
   res->type_name = NULL;
@@ -72,13 +73,14 @@ symbol_new (const char *tag, location_t location)
 `------------------------------------------------------------------*/
 
 void
-symbol_type_set (symbol_t *symbol, char *type_name, location_t location)
+symbol_type_set (symbol_t *symbol, struniq_t type_name, location_t location)
 {
   if (type_name)
     {
       if (symbol->type_name)
 	complain_at (location,
 		     _("type redeclaration for %s"), symbol->tag);
+      struniq_assert (type_name);
       symbol->type_name = type_name;
     }
 }
@@ -200,7 +202,6 @@ symbol_user_token_number_set (symbol_t *symbol,
 static void
 symbol_free (symbol_t *this)
 {
-  free (this->tag);
   free (this);
 }
 
@@ -376,15 +377,17 @@ symbol_translation (symbol_t *this)
 static struct hash_table *symbol_table = NULL;
 
 static bool
-hash_compare_symbol_t (const symbol_t *m1, const symbol_t *m2)
+hash_compare_symbol (const symbol_t *m1, const symbol_t *m2)
 {
-  return strcmp (m1->tag, m2->tag) == 0;
+  /* Since tags are unique, we can compare the pointers themselves.  */
+  return STRUNIQ_EQ (m1->tag, m2->tag);
 }
 
 static unsigned int
-hash_symbol_t (const symbol_t *m, unsigned int tablesize)
+hash_symbol (const symbol_t *m, unsigned int tablesize)
 {
-  return hash_string (m->tag, tablesize);
+  /* Since tags are unique, we can hash the pointer itself.  */
+  return ((size_t) m->tag) % tablesize;
 }
 
 
@@ -397,8 +400,8 @@ symbols_new (void)
 {
   symbol_table = hash_initialize (HT_INITIAL_CAPACITY,
 				  NULL,
-				  (Hash_hasher) hash_symbol_t,
-				  (Hash_comparator) hash_compare_symbol_t,
+				  (Hash_hasher) hash_symbol,
+				  (Hash_comparator) hash_compare_symbol,
 				  (Hash_data_freer) symbol_free);
 }
 
@@ -415,7 +418,7 @@ symbol_get (const char *key, location_t location)
   symbol_t *entry;
 
   /* Keep the symbol in a printable form.  */
-  key = quotearg_style (escape_quoting_style, key);
+  key = struniq_new (quotearg_style (escape_quoting_style, key));
   *(char const **) &probe.tag = key;
   entry = hash_lookup (symbol_table, &probe);
 
