@@ -61,7 +61,7 @@ max_length (size_t *width, const char *str)
 static void
 print_core (FILE *out, state *s)
 {
-  item_number *sitems = s->items;
+  item_index *sitems = s->items;
   size_t snritems = s->nitems;
   /* Output all the items of a state, not only its kernel.  */
   if (report_flag & report_itemsets)
