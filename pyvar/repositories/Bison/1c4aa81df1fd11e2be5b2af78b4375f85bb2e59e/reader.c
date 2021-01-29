@@ -555,9 +555,12 @@ reader (void)
   gram_scanner_initialize ();
   gram_parse ();
 
-  /* IELR would be a better default, but LALR is historically the default.  */
+  /* Set front-end %define variable defaults.  */
+  muscle_percent_define_default ("lr.keep_unreachable_states", "false");
   {
     char *lr_type;
+    /* IELR would be a better default, but LALR is historically the
+       default.  */
     muscle_percent_define_default ("lr.type", "LALR");
     lr_type = muscle_percent_define_get ("lr.type");
     if (0 != strcmp (lr_type, "canonical LR"))
@@ -567,7 +570,7 @@ reader (void)
     free (lr_type);
   }
 
-  /* Check front-end %define variable values.  */
+  /* Check front-end %define variables.  */
   {
     static char const * const values[] = {
       "lr.type", "LALR", "IELR", "canonical LR", NULL,
