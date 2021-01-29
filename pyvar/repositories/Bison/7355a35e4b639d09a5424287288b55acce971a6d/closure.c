@@ -51,7 +51,7 @@ static bitsetv firsts = NULL;
 `-----------------*/
 
 static void
-print_closure (char const *title, item_number const *array, size_t size)
+closure_print (char const *title, item_number const *array, size_t size)
 {
   fprintf (stderr, "Closure: %s\n", title);
   for (size_t i = 0; i < size; ++i)
@@ -167,7 +167,7 @@ set_fderives (void)
 
 
 void
-new_closure (unsigned n)
+closure_new (unsigned n)
 {
   itemset = xnmalloc (n, sizeof *itemset);
 
@@ -182,7 +182,7 @@ void
 closure (item_number const *core, size_t n)
 {
   if (trace_flag & trace_sets)
-    print_closure ("input", core, n);
+    closure_print ("input", core, n);
 
   bitset_zero (ruleset);
 
@@ -219,12 +219,12 @@ closure (item_number const *core, size_t n)
     }
 
   if (trace_flag & trace_sets)
-    print_closure ("output", itemset, nitemset);
+    closure_print ("output", itemset, nitemset);
 }
 
 
 void
-free_closure (void)
+closure_free (void)
 {
   free (itemset);
   bitset_free (ruleset);
