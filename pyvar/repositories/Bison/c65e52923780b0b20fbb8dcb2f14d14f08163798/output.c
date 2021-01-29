@@ -488,7 +488,6 @@ static void
 output_skeleton (void)
 {
   FILE *in;
-  FILE *out;
   int filter_fd[2];
   char const *argv[9];
   pid_t pid;
@@ -576,12 +575,17 @@ output_skeleton (void)
   free (full_m4bison);
   free (full_skeleton);
 
-  out = fdopen (filter_fd[0], "w");
-  if (! out)
-    error (EXIT_FAILURE, get_errno (),
-	   "fdopen");
-  muscles_output (out);
-  xfclose (out);
+
+  if (trace_flag & trace_muscles)
+    muscles_output (stderr);
+  {
+    FILE *out = fdopen (filter_fd[0], "w");
+    if (! out)
+      error (EXIT_FAILURE, get_errno (),
+             "fdopen");
+    muscles_output (out);
+    xfclose (out);
+  }
 
   /* Read and process m4's output.  */
   timevar_push (TV_M4);
