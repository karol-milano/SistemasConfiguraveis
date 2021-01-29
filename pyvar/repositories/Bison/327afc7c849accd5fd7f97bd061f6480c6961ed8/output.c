@@ -501,7 +501,7 @@ output_skeleton (void)
   FILE *in;
   FILE *out;
   int filter_fd[2];
-  char const *argv[5];
+  char const *argv[6];
   pid_t pid;
 
   /* Compute the names of the package data dir and skeleton file.
@@ -538,7 +538,8 @@ output_skeleton (void)
   argv[1] = full_m4sugar;
   argv[2] = "-";
   argv[3] = full_skeleton;
-  argv[4] = NULL;
+  argv[4] = trace_flag & trace_m4 ? "-dV" : NULL;
+  argv[5] = NULL;
 
   init_subpipe ();
   pid = create_subpipe (argv, filter_fd);
@@ -582,11 +583,11 @@ static void
 prepare (void)
 {
   /* Flags. */
-  MUSCLE_INSERT_BOOL ("debug", debug_flag);
+  MUSCLE_INSERT_BOOL ("debug_flag", debug_flag);
   MUSCLE_INSERT_BOOL ("defines_flag", defines_flag);
-  MUSCLE_INSERT_BOOL ("error_verbose", error_verbose);
+  MUSCLE_INSERT_BOOL ("error_verbose_flag", error_verbose);
   MUSCLE_INSERT_BOOL ("locations_flag", locations_flag);
-  MUSCLE_INSERT_BOOL ("pure", pure_parser);
+  MUSCLE_INSERT_BOOL ("pure_flag", pure_parser);
   MUSCLE_INSERT_BOOL ("synclines_flag", !no_lines_flag);
 
   /* File names.  */
