@@ -593,6 +593,7 @@ prepare (void)
   MUSCLE_INSERT_BOOL ("glr_flag", glr_parser);
   MUSCLE_INSERT_BOOL ("locations_flag", locations_flag);
   MUSCLE_INSERT_BOOL ("nondeterministic_flag", nondeterministic_parser);
+  MUSCLE_INSERT_BOOL ("pull_flag", pull_parser);
   MUSCLE_INSERT_BOOL ("pure_flag", pure_parser);
   MUSCLE_INSERT_BOOL ("push_flag", push_parser);
   MUSCLE_INSERT_BOOL ("synclines_flag", !no_lines_flag);
