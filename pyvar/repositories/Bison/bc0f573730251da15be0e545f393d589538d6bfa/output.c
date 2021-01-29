@@ -702,7 +702,6 @@ prepare (void)
   /* Flags. */
   MUSCLE_INSERT_BOOL ("defines_flag", defines_flag);
   MUSCLE_INSERT_BOOL ("glr_flag", glr_parser);
-  MUSCLE_INSERT_BOOL ("locations_flag", locations_flag);
   MUSCLE_INSERT_BOOL ("nondeterministic_flag", nondeterministic_parser);
   MUSCLE_INSERT_BOOL ("synclines_flag", !no_lines_flag);
   MUSCLE_INSERT_BOOL ("tag_seen_flag", tag_seen);
