@@ -57,7 +57,7 @@ static struct escape_buf escape_bufs[num_escape_bufs];
 static void
 print_core (FILE *out, int level, state *s)
 {
-  item_number *sitems = s->items;
+  item_index *sitems = s->items;
   size_t snritems = s->nitems;
 
   /* Output all the items of a state, not only its kernel.  */
