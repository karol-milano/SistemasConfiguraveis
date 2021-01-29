@@ -132,8 +132,8 @@ main (int argc, char *argv[])
   tables_generate ();
   timevar_pop (TV_ACTIONS);
 
-  grammar_rules_never_reduced_report
-    (_("rule never reduced because of conflicts"));
+  grammar_rules_useless_report
+    (_("rule useless in parser due to conflicts"));
 
   /* Output file names. */
   compute_output_file_names ();
