@@ -833,20 +833,20 @@ symbols_cmp_qsort (void const *a, void const *b)
 }
 
 static void
-symbols_do (Hash_processor processor, void *processor_data)
+symbols_do (Hash_processor processor, void *processor_data,
+            struct hash_table *table, symbol **sorted)
 {
-  size_t count = hash_get_n_entries (symbol_table);
-  if (!symbols_sorted)
+  size_t count = hash_get_n_entries (table);
+  if (!sorted)
     {
-      symbols_sorted = xnmalloc (count, sizeof *symbols_sorted);
-      hash_get_entries (symbol_table, (void**)symbols_sorted, count);
-      qsort (symbols_sorted, count, sizeof *symbols_sorted,
-             symbols_cmp_qsort);
+      sorted = xnmalloc (count, sizeof *sorted);
+      hash_get_entries (table, (void**)sorted, count);
+      qsort (sorted, count, sizeof *sorted, symbols_cmp_qsort);
     }
   {
     size_t i;
     for (i = 0; i < count; ++i)
-      processor (symbols_sorted[i], processor_data);
+      processor (sorted[i], processor_data);
   }
 }
 
@@ -858,7 +858,8 @@ symbols_do (Hash_processor processor, void *processor_data)
 void
 symbols_check_defined (void)
 {
-  symbols_do (symbol_check_defined_processor, NULL);
+  symbols_do (symbol_check_defined_processor, NULL,
+              symbol_table, symbols_sorted);
 }
 
 /*------------------------------------------------------------------.
@@ -912,7 +913,8 @@ symbols_token_translations_init (void)
      number for $undefined, which represents all invalid inputs.  */
   for (i = 0; i < max_user_token_number + 1; i++)
     token_translations[i] = undeftoken->number;
-  symbols_do (symbol_translation_processor, NULL);
+  symbols_do (symbol_translation_processor, NULL,
+              symbol_table, symbols_sorted);
 }
 
 
@@ -924,10 +926,11 @@ symbols_token_translations_init (void)
 void
 symbols_pack (void)
 {
-  symbols_do (symbol_check_alias_consistency_processor, NULL);
+  symbols_do (symbol_check_alias_consistency_processor, NULL,
+              symbol_table, symbols_sorted);
 
   symbols = xcalloc (nsyms, sizeof *symbols);
-  symbols_do (symbol_pack_processor, NULL);
+  symbols_do (symbol_pack_processor, NULL, symbol_table, symbols_sorted);
 
   /* Aliases leave empty slots in symbols, so remove them.  */
   {
