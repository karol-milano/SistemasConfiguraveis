@@ -122,7 +122,8 @@ print_core (FILE *out, int level, state *s)
       sp = rules[r].rhs;
 
       /* Display the lookahead tokens?  */
-      if (report_flag & report_lookahead_tokens)
+      if (report_flag & report_lookahead_tokens
+          && item_number_is_rule_number (*sp1))
 	{
 	  reductions *reds = s->reductions;
 	  int red = state_reduction_find (s, &rules[r]);
