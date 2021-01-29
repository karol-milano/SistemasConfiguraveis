@@ -548,6 +548,8 @@ print_results (void)
   FILE *out = xfopen (spec_verbose_file, "w");
 
   reduce_output (out);
+  grammar_rules_partial_print (out,
+			       _("Rules never reduced"), rule_never_reduced_p);
   conflicts_output (out);
 
   print_grammar (out);
