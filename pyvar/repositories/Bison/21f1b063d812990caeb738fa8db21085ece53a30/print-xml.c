@@ -584,9 +584,6 @@ print_xml (void)
   /* print rules never reduced */
   print_rules_never_reduced (out, level + 1);
 
-  /* print conflicts */
-  conflicts_output_xml (out, level + 1);
-
   /* print grammar */
   print_grammar (out, level + 1);
 
