@@ -541,10 +541,8 @@ muscle_percent_define_ensure (char const *variable, location loc,
 
   /* Don't complain is VARIABLE is already defined, but be sure to set
      its value to VAL.  */
-  if (!muscle_find_const (name))
-    muscle_percent_define_insert (variable, loc, muscle_keyword, val,
-                                  MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
-  if (muscle_percent_define_flag_if (variable) != value)
+  if (!muscle_find_const (name)
+      || muscle_percent_define_flag_if (variable) != value)
     muscle_percent_define_insert (variable, loc, muscle_keyword, val,
                                   MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
 }
