@@ -52,7 +52,7 @@ static bitsetv firsts = NULL;
 `-----------------*/
 
 static void
-print_closure (char const *title, item_number *array, size_t size)
+print_closure (char const *title, item_number const *array, size_t size)
 {
   size_t i;
   fprintf (stderr, "Closure: %s\n", title);
@@ -189,7 +189,7 @@ new_closure (unsigned int n)
 
 
 void
-closure (item_number *core, size_t n)
+closure (item_number const *core, size_t n)
 {
   /* Index over CORE. */
   size_t c;
