@@ -801,6 +801,7 @@ symbols_free (void)
   hash_free (semantic_type_table);
   free (symbols);
   free (symbols_sorted);
+  free (semantic_types_sorted);
 }
 
 
@@ -823,19 +824,19 @@ symbols_cmp_qsort (void const *a, void const *b)
 
 static void
 symbols_do (Hash_processor processor, void *processor_data,
-            struct hash_table *table, symbol **sorted)
+            struct hash_table *table, symbol ***sorted)
 {
   size_t count = hash_get_n_entries (table);
-  if (!sorted)
+  if (!*sorted)
     {
-      sorted = xnmalloc (count, sizeof *sorted);
-      hash_get_entries (table, (void**)sorted, count);
-      qsort (sorted, count, sizeof *sorted, symbols_cmp_qsort);
+      *sorted = xnmalloc (count, sizeof **sorted);
+      hash_get_entries (table, (void**)*sorted, count);
+      qsort (*sorted, count, sizeof **sorted, symbols_cmp_qsort);
     }
   {
     size_t i;
     for (i = 0; i < count; ++i)
-      processor (sorted[i], processor_data);
+      processor ((*sorted)[i], processor_data);
   }
 }
 
@@ -848,9 +849,9 @@ void
 symbols_check_defined (void)
 {
   symbols_do (symbol_check_defined_processor, NULL,
-              symbol_table, symbols_sorted);
+              symbol_table, &symbols_sorted);
   symbols_do (semantic_type_check_defined_processor, NULL,
-              semantic_type_table, semantic_types_sorted);
+              semantic_type_table, &semantic_types_sorted);
 }
 
 /*------------------------------------------------------------------.
@@ -905,7 +906,7 @@ symbols_token_translations_init (void)
   for (i = 0; i < max_user_token_number + 1; i++)
     token_translations[i] = undeftoken->number;
   symbols_do (symbol_translation_processor, NULL,
-              symbol_table, symbols_sorted);
+              symbol_table, &symbols_sorted);
 }
 
 
@@ -918,10 +919,10 @@ void
 symbols_pack (void)
 {
   symbols_do (symbol_check_alias_consistency_processor, NULL,
-              symbol_table, symbols_sorted);
+              symbol_table, &symbols_sorted);
 
   symbols = xcalloc (nsyms, sizeof *symbols);
-  symbols_do (symbol_pack_processor, NULL, symbol_table, symbols_sorted);
+  symbols_do (symbol_pack_processor, NULL, symbol_table, &symbols_sorted);
 
   /* Aliases leave empty slots in symbols, so remove them.  */
   {
