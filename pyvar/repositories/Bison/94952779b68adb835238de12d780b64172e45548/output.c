@@ -698,17 +698,6 @@ output_skeleton (void)
 
   /* Create an m4 subprocess connected to us via two pipes.  */
 
-  if (trace_flag & trace_tools)
-    fprintf (stderr, "running: %s %s - %s %s\n",
-             m4, m4sugar, m4bison, skel);
-
-  /* Some future version of GNU M4 (most likely 1.6) may treat the -dV in a
-     position-dependent manner.  Keep it as the first argument so that all
-     files are traced.
-
-     See the thread starting at
-     <http://lists.gnu.org/archive/html/bug-bison/2008-07/msg00000.html>
-     for details.  */
   int filter_fd[2];
   pid_t pid;
   {
@@ -730,6 +719,13 @@ output_skeleton (void)
 
     argv[i++] = "-I";
     argv[i++] = datadir;
+    /* Some future version of GNU M4 (most likely 1.6) may treat the
+       -dV in a position-dependent manner.  Keep it as the first
+       argument so that all files are traced.
+
+       See the thread starting at
+       <http://lists.gnu.org/archive/html/bug-bison/2008-07/msg00000.html>
+       for details.  */
     if (trace_flag & trace_m4)
       argv[i++] = "-dV";
     argv[i++] = m4sugar;
@@ -739,6 +735,14 @@ output_skeleton (void)
     argv[i++] = NULL;
     aver (i <= ARRAY_CARDINALITY (argv));
 
+    if (trace_flag & trace_tools)
+      {
+        fputs ("running:", stderr);
+        for (int j = 0; argv[j]; ++j)
+          fprintf (stderr, " %s", argv[j]);
+        fputc ('\n', stderr);
+      }
+
     /* The ugly cast is because gnulib gets the const-ness wrong.  */
     pid = create_pipe_bidi ("m4", m4, (char **)(void*)argv, false, true,
                             true, filter_fd);
