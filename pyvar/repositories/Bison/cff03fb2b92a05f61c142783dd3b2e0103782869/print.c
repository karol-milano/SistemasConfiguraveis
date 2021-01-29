@@ -492,7 +492,8 @@ print_results (void)
 
   reduce_output (out);
   grammar_rules_partial_print (out,
-			       _("Rules never reduced"), rule_never_reduced_p);
+			       _("Rules useless in parser due to conflicts"),
+                                 rule_useless_in_parser_p);
   conflicts_output (out);
 
   print_grammar (out);
