@@ -572,7 +572,7 @@ simulate_reduction (parse_state *ps, int rule_len, bitset symbol_set)
 gl_list_t
 parser_prepend (parse_state *ps)
 {
-  gl_list_t result = parse_state_list_new ();
+  gl_list_t res = parse_state_list_new ();
   const state_item *head = ps->state_items.head_elt;
   symbol_number prepend_sym =
     item_number_as_symbol_number (*(head->item - 1));
@@ -584,19 +584,20 @@ parser_prepend (parse_state *ps)
     ps_si_prepend (copy, state_items + sin);
     if (SI_TRANSITION (head))
       ps_derivs_prepend (copy, derivation_new_leaf (prepend_sym));
-    parse_state_list_append (result, copy);
+    parse_state_list_append (res, copy);
   }
-  return result;
+  return res;
 }
 
 void
 print_parse_state (parse_state *ps)
 {
-  printf ("(size %zu depth %d rc %d)\n",
+  FILE *out = stderr;
+  fprintf (out, "(size %zu depth %d rc %d)\n",
           ps->state_items.total_size, ps->depth, ps->reference_count);
-  print_state_item (ps->state_items.head_elt, stdout);
-  print_state_item (ps->state_items.tail_elt, stdout);
+  print_state_item (ps->state_items.head_elt, out);
+  print_state_item (ps->state_items.tail_elt, out);
   if (ps->derivs.total_size > 0)
-    derivation_print (ps->derivs.head_elt, stdout);
-  putc ('\n', stdout);
+    derivation_print (ps->derivs.head_elt, out);
+  putc ('\n', out);
 }
