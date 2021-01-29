@@ -555,11 +555,22 @@ reader (void)
   gram_scanner_initialize ();
   gram_parse ();
 
-  muscle_percent_define_default ("lr.default_rules", "all");
+  /* IELR would be a better default, but LALR is historically the default.  */
+  {
+    char *lr_type;
+    muscle_percent_define_default ("lr.type", "LALR");
+    lr_type = muscle_percent_define_get ("lr.type");
+    if (0 != strcmp (lr_type, "canonical LR"))
+      muscle_percent_define_default ("lr.default_rules", "all");
+    else
+      muscle_percent_define_default ("lr.default_rules", "accepting");
+    free (lr_type);
+  }
 
   /* Check front-end %define variable values.  */
   {
     static char const * const values[] = {
+      "lr.type", "LALR", "IELR", "canonical LR", NULL,
       "lr.default_rules", "all", "consistent", "accepting", NULL,
       NULL
     };
