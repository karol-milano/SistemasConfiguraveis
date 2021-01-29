@@ -110,7 +110,8 @@ print_core (FILE *out, state *s)
 	fprintf (out, " %s", symbols[*sp]->tag);
 
       /* Display the lookahead tokens?  */
-      if (report_flag & report_lookahead_tokens)
+      if (report_flag & report_lookahead_tokens
+          && item_number_is_rule_number (*sp1))
 	state_rule_lookahead_tokens_print (s, &rules[r], out);
 
       fputc ('\n', out);
