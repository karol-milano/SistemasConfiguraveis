@@ -1213,8 +1213,6 @@ counterexample_report_shift_reduce (state_item_number itm1, state_item_number it
                                     symbol_number next_sym, FILE *out)
 {
   fprintf (out, _("Shift/reduce conflict on token %s:\n"), symbols[next_sym]->tag);
-  print_state_item (&state_items[itm1], out);
-  print_state_item (&state_items[itm2], out);
   counterexample_report (itm1, itm2, next_sym, true, out);
 }
 
@@ -1236,8 +1234,6 @@ counterexample_report_reduce_reduce (state_item_number itm1, state_item_number i
       }
     fputs (_(":\n"), out);
   }
-  print_state_item (&state_items[itm1], out);
-  print_state_item (&state_items[itm2], out);
   counterexample_report (itm1, itm2, bitset_first (conflict_syms), false, out);
 }
 
