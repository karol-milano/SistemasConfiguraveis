@@ -925,8 +925,8 @@ symbols_free (void)
 static int
 symbol_cmp (void const *a, void const *b)
 {
-  return strcmp ((*(symbol * const *)a)->tag,
-                 (*(symbol * const *)b)->tag);
+  return location_cmp ((*(symbol * const *)a)->location,
+                       (*(symbol * const *)b)->location);
 }
 
 /* Store in *SORTED an array of pointers to the symbols contained in
@@ -952,14 +952,13 @@ void
 symbols_check_defined (void)
 {
   table_sort (symbol_table, &symbols_sorted);
-  /* semantic_type, like symbol, starts with a 'tag' field.  And here
-     we only deal with arrays/hashes of pointers, sizeof is not an
-     issue.
+  /* semantic_type, like symbol, starts with a 'tag' field and then a
+     'location' field.  And here we only deal with arrays/hashes of
+     pointers, sizeof is not an issue.
 
      So instead of implementing table_sort (and symbol_cmp) once for
      each type, let's lie a bit to the typing system, and treat
-     'semantic_type' as if it were 'symbol'.  Anyway this is only
-     about arrays of pointers.  */
+     'semantic_type' as if it were 'symbol'. */
   table_sort (semantic_type_table, (symbol ***) &semantic_types_sorted);
 
   for (int i = 0; symbols_sorted[i]; ++i)
@@ -1019,7 +1018,7 @@ symbols_token_translations_init (void)
   for (int i = 0; i < max_user_token_number + 1; ++i)
     token_translations[i] = undeftoken->content->number;
   for (int i = 0; symbols_sorted[i]; ++i)
-    symbol_translation(symbols_sorted[i]);
+    symbol_translation (symbols_sorted[i]);
 }
 
 
@@ -1033,7 +1032,7 @@ symbols_pack (void)
 {
   symbols = xcalloc (nsyms, sizeof *symbols);
   for (int i = 0; symbols_sorted[i]; ++i)
-    symbol_pack(symbols_sorted[i]);
+    symbol_pack (symbols_sorted[i]);
 
   /* Aliases leave empty slots in symbols, so remove them.  */
   {
