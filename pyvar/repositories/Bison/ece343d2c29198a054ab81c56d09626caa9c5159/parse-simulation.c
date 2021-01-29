@@ -594,8 +594,8 @@ print_parse_state (parse_state *ps)
   FILE *out = stderr;
   fprintf (out, "(size %zu depth %d rc %d)\n",
           ps->state_items.total_size, ps->depth, ps->reference_count);
-  print_state_item (ps->state_items.head_elt, out, "");
-  print_state_item (ps->state_items.tail_elt, out, "");
+  state_item_print (ps->state_items.head_elt, out, "");
+  state_item_print (ps->state_items.tail_elt, out, "");
   if (ps->derivs.total_size > 0)
     derivation_print (ps->derivs.head_elt, out, "");
   putc ('\n', out);
