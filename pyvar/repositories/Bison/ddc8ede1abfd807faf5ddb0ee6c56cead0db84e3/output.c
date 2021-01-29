@@ -590,6 +590,7 @@ prepare (void)
   MUSCLE_INSERT_BOOL ("locations_flag", locations_flag);
   MUSCLE_INSERT_BOOL ("pure_flag", pure_parser);
   MUSCLE_INSERT_BOOL ("synclines_flag", !no_lines_flag);
+  MUSCLE_INSERT_BOOL ("tag_seen_flag", tag_seen);
   MUSCLE_INSERT_BOOL ("yacc_flag", yacc_flag);
 
   /* File names.  */
