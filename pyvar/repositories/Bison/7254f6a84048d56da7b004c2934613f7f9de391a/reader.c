@@ -555,6 +555,17 @@ reader (void)
   gram_scanner_initialize ();
   gram_parse ();
 
+  muscle_percent_define_default ("lr.default_rules", "all");
+
+  /* Check front-end %define variable values.  */
+  {
+    static char const * const values[] = {
+      "lr.default_rules", "all", "consistent", "accepting", NULL,
+      NULL
+    };
+    muscle_percent_define_check_values (values);
+  }
+
   if (! complaint_issued)
     check_and_convert_grammar ();
 
