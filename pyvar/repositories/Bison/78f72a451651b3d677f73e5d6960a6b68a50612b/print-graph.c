@@ -96,7 +96,7 @@ print_core (struct obstack *oout, state *s)
         obstack_sgrow (oout, " %empty");
 
       /* Experimental feature: display the lookahead tokens. */
-      if (report_flag & report_lookahead_tokens
+      if (report_flag & report_lookaheads
           && item_number_is_rule_number (*sp1))
         {
           /* Find the reduction we are handling.  */
@@ -104,13 +104,13 @@ print_core (struct obstack *oout, state *s)
           int redno = state_reduction_find (s, r);
 
           /* Print them if there are.  */
-          if (reds->lookahead_tokens && redno != -1)
+          if (reds->lookaheads && redno != -1)
             {
               bitset_iterator biter;
               int k;
               char const *sep = "";
               obstack_sgrow (oout, "  [");
-              BITSET_FOR_EACH (biter, reds->lookahead_tokens[redno], k, 0)
+              BITSET_FOR_EACH (biter, reds->lookaheads[redno], k, 0)
                 {
                   obstack_sgrow (oout, sep);
                   obstack_backslash (oout, symbols[k]->tag);
