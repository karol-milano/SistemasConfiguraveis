@@ -585,6 +585,7 @@ prepare (void)
   MUSCLE_INSERT_BOOL ("error_verbose_flag", error_verbose);
   MUSCLE_INSERT_BOOL ("locations_flag", locations_flag);
   MUSCLE_INSERT_BOOL ("pure_flag", pure_parser);
+  MUSCLE_INSERT_BOOL ("push_flag", push_parser);
   MUSCLE_INSERT_BOOL ("synclines_flag", !no_lines_flag);
   MUSCLE_INSERT_BOOL ("tag_seen_flag", tag_seen);
   MUSCLE_INSERT_BOOL ("yacc_flag", yacc_flag);
