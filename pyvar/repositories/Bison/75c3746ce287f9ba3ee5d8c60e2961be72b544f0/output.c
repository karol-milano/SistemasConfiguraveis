@@ -810,7 +810,7 @@ prepare (void)
   MUSCLE_INSERT_INT ("required_version", required_version);
 
   /* Flags. */
-  MUSCLE_INSERT_BOOL ("defines_flag", defines_flag);
+  MUSCLE_INSERT_BOOL ("header_flag", header_flag);
   MUSCLE_INSERT_BOOL ("glr_flag", glr_parser);
   MUSCLE_INSERT_BOOL ("nondeterministic_flag", nondeterministic_parser);
   MUSCLE_INSERT_BOOL ("synclines_flag", !no_lines_flag);
