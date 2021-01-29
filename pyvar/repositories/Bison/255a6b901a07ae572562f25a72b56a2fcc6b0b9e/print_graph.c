@@ -82,7 +82,8 @@ print_core (struct obstack *oout, state *s)
 	obstack_fgrow1 (oout, " %s", symbols[*sp]->tag);
 
       /* Experimental feature: display the lookahead tokens. */
-      if (report_flag & report_lookahead_tokens)
+      if (report_flag & report_lookahead_tokens
+          && item_number_is_rule_number (*sp1))
 	{
 	  /* Find the reduction we are handling.  */
 	  reductions *reds = s->reductions;
