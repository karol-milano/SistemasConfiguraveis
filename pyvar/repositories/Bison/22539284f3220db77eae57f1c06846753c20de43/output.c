@@ -571,7 +571,6 @@ static void
 output_skeleton (void)
 {
   int filter_fd[2];
-  char const *argv[10];
   pid_t pid;
 
   /* Compute the names of the package data dir and skeleton files.  */
@@ -602,6 +601,7 @@ output_skeleton (void)
      <http://lists.gnu.org/archive/html/bug-bison/2008-07/msg00000.html>
      for details.  */
   {
+    char const *argv[10];
     int i = 0;
     argv[i++] = m4;
 
@@ -627,11 +627,12 @@ output_skeleton (void)
     argv[i++] = skel;
     argv[i++] = NULL;
     aver (i <= ARRAY_CARDINALITY (argv));
+
+    /* The ugly cast is because gnulib gets the const-ness wrong.  */
+    pid = create_pipe_bidi ("m4", m4, (char **)(void*)argv, false, true,
+                            true, filter_fd);
   }
 
-  /* The ugly cast is because gnulib gets the const-ness wrong.  */
-  pid = create_pipe_bidi ("m4", m4, (char **)(void*)argv, false, true,
-                          true, filter_fd);
   free (m4sugar);
   free (m4bison);
   free (skel);
@@ -639,10 +640,7 @@ output_skeleton (void)
   if (trace_flag & trace_muscles)
     muscles_output (stderr);
   {
-    FILE *out = fdopen (filter_fd[1], "w");
-    if (! out)
-      error (EXIT_FAILURE, get_errno (),
-             "fdopen");
+    FILE *out = xfdopen (filter_fd[1], "w");
     muscles_output (out);
     xfclose (out);
   }
@@ -650,10 +648,7 @@ output_skeleton (void)
   /* Read and process m4's output.  */
   timevar_push (TV_M4);
   {
-    FILE *in = fdopen (filter_fd[0], "r");
-    if (! in)
-      error (EXIT_FAILURE, get_errno (),
-	     "fdopen");
+    FILE *in = xfdopen (filter_fd[0], "r");
     scan_skel (in);
     /* scan_skel should have read all of M4's output.  Otherwise, when we
        close the pipe, we risk letting M4 report a broken-pipe to the
