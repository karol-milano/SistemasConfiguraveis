@@ -556,7 +556,7 @@ reader (void)
   gram_parse ();
 
   /* Set front-end %define variable defaults.  */
-  muscle_percent_define_default ("lr.keep_unreachable_states", "false");
+  muscle_percent_define_default ("lr.keep-unreachable-states", "false");
   {
     char *lr_type;
     /* IELR would be a better default, but LALR is historically the
