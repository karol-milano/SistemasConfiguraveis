@@ -71,9 +71,9 @@ max_length (size_t *width, const char *str)
 static void
 print_core (FILE *out, state *s)
 {
-  int i;
+  size_t i;
   item_number *sitems = s->items;
-  int snritems = s->nitems;
+  size_t snritems = s->nitems;
   symbol *previous_lhs = NULL;
 
   /* Output all the items of a state, not only its kernel.  */
