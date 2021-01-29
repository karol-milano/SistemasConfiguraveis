@@ -29,6 +29,13 @@
 #include "gram.h"
 #include "symtab.h"
 
+/*-------------------------------------------------------------------.
+| Symbols sorted by tag.  Allocated by the first invocation of       |
+| symbols_do, after which no more symbols should be created.         |
+`-------------------------------------------------------------------*/
+
+static symbol **symbols_sorted = NULL;
+
 /*------------------------.
 | Distinguished symbols.  |
 `------------------------*/
@@ -583,10 +590,10 @@ static void
 user_token_number_redeclaration (int num, symbol *first, symbol *second)
 {
   /* User token numbers are not assigned during the parsing, but in a
-     second step, via a (nondeterministic) traversal of the symbol
-     hash table.
+     second step, via a traversal of the symbol table sorted on tag.
 
-     Make errors deterministic: keep the first declaration first.  */
+     However, error messages make more sense if we keep the first
+     declaration first.  */
   if (location_cmp (first->location, second->location) > 0)
     {
       symbol* tmp = first;
@@ -730,6 +737,7 @@ symbol_from_uniqstr (const uniqstr key, location loc)
   if (!entry)
     {
       /* First insertion in the hash. */
+      aver (!symbols_sorted);
       entry = symbol_new (key, loc);
       if (!hash_insert (symbol_table, entry))
         xalloc_die ();
@@ -824,6 +832,7 @@ symbols_free (void)
   hash_free (symbol_table);
   hash_free (semantic_type_table);
   free (symbols);
+  free (symbols_sorted);
 }
 
 
@@ -832,13 +841,36 @@ symbols_free (void)
 | terminals.                                                     |
 `---------------------------------------------------------------*/
 
+static int
+symbols_cmp (symbol const *a, symbol const *b)
+{
+  return strcmp (a->tag, b->tag);
+}
+
+static int
+symbols_cmp_qsort (void const *a, void const *b)
+{
+  return symbols_cmp (*(symbol * const *)a, *(symbol * const *)b);
+}
+
 static void
 symbols_do (Hash_processor processor, void *processor_data)
 {
-  hash_do_for_each (symbol_table, processor, processor_data);
+  size_t count = hash_get_n_entries (symbol_table);
+  if (!symbols_sorted)
+    {
+      symbols_sorted = xnmalloc (count, sizeof *symbols_sorted);
+      hash_get_entries (symbol_table, (void**)symbols_sorted, count);
+      qsort (symbols_sorted, count, sizeof *symbols_sorted,
+             symbols_cmp_qsort);
+    }
+  {
+    size_t i;
+    for (i = 0; i < count; ++i)
+      processor (symbols_sorted[i], processor_data);
+  }
 }
 
-
 /*--------------------------------------------------------------.
 | Check that all the symbols are defined.  Report any undefined |
 | symbols and consider them nonterminals.                       |
