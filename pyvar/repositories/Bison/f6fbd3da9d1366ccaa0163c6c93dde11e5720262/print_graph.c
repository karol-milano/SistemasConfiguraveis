@@ -49,9 +49,9 @@ static FILE *fgraph = NULL;
 static void
 print_core (struct obstack *oout, state *s)
 {
-  int i;
+  size_t i;
   item_number *sitems = s->items;
-  int snritems = s->nitems;
+  size_t snritems = s->nitems;
 
   /* Output all the items of a state, not only its kernel.  */
   if (report_flag & report_itemsets)
