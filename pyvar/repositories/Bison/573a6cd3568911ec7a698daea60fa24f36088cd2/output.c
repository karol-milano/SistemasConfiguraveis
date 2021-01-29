@@ -591,8 +591,7 @@ prepare (void)
   MUSCLE_INSERT_INT ("pure", pure_parser);
   MUSCLE_INSERT_INT ("synclines_flag", !no_lines_flag);
 
-  /* FIXME: This is wrong: the muscles should decide whether they hold
-     a copy or not, but the situation is too obscure currently.  */
+  /* File names.  */
   MUSCLE_INSERT_STRING ("prefix", spec_name_prefix ? spec_name_prefix : "yy");
 
   /* User Code.  */
