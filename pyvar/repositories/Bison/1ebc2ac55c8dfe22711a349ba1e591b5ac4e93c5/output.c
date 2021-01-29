@@ -687,6 +687,7 @@ output_skeleton (void)
   char *skeldir = xpath_join (datadir, "skeletons");
   char *m4sugar = xpath_join (datadir, "m4sugar/m4sugar.m4");
   char *m4bison = xpath_join (skeldir, "bison.m4");
+  char *traceon = xpath_join (skeldir, "traceon.m4");
   char *skel = (IS_PATH_WITH_DIR (skeleton)
                 ? xstrdup (skeleton)
                 : xpath_join (skeldir, skeleton));
@@ -701,7 +702,7 @@ output_skeleton (void)
   int filter_fd[2];
   pid_t pid;
   {
-    char const *argv[10];
+    char const *argv[11];
     int i = 0;
     argv[i++] = m4;
 
@@ -720,17 +721,16 @@ output_skeleton (void)
     argv[i++] = "-I";
     argv[i++] = datadir;
     /* Some future version of GNU M4 (most likely 1.6) may treat the
-       -dV in a position-dependent manner.  Keep it as the first
-       argument so that all files are traced.
-
-       See the thread starting at
+       -dV in a position-dependent manner.  See the thread starting at
        <http://lists.gnu.org/archive/html/bug-bison/2008-07/msg00000.html>
        for details.  */
-    if (trace_flag & trace_m4)
+    if (trace_flag & trace_m4_early)
       argv[i++] = "-dV";
     argv[i++] = m4sugar;
     argv[i++] = "-";
     argv[i++] = m4bison;
+    if (trace_flag & trace_m4)
+      argv[i++] = traceon;
     argv[i++] = skel;
     argv[i++] = NULL;
     aver (i <= ARRAY_CARDINALITY (argv));
@@ -751,6 +751,7 @@ output_skeleton (void)
   free (skeldir);
   free (m4sugar);
   free (m4bison);
+  free (traceon);
   free (skel);
 
   if (trace_flag & trace_muscles)
