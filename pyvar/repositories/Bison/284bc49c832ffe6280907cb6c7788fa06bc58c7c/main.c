@@ -144,6 +144,8 @@ main (int argc, char *argv[])
 
   grammar_rules_useless_report (_("rule useless in parser due to conflicts"));
 
+  print_precedence_warnings ();
+
   /* Output file names. */
   compute_output_file_names ();
 
