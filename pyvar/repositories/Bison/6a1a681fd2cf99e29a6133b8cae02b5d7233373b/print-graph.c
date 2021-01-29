@@ -47,7 +47,7 @@
 static void
 print_core (struct obstack *oout, state *s)
 {
-  item_number const *sitems = s->items;
+  item_index const *sitems = s->items;
   sym_content *previous_lhs = NULL;
   size_t snritems = s->nitems;
 
