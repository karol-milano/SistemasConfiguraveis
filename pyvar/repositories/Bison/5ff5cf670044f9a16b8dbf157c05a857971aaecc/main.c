@@ -142,8 +142,7 @@ main (int argc, char *argv[])
   tables_generate ();
   timevar_pop (TV_ACTIONS);
 
-  grammar_rules_useless_report
-    (_("rule useless in parser due to conflicts"));
+  grammar_rules_useless_report (_("rule useless in parser due to conflicts"));
 
   /* Output file names. */
   compute_output_file_names ();
