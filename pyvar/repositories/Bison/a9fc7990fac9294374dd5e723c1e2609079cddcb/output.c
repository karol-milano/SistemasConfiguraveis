@@ -476,10 +476,7 @@ output_skeleton (void)
   char const *argv[7];
   pid_t pid;
 
-  /* Compute the names of the package data dir and skeleton file.
-     Test whether m4sugar.m4 is readable, to check for proper
-     installation.  A faulty installation can cause deadlock, so a
-     cheap sanity check is worthwhile.  */
+  /* Compute the names of the package data dir and skeleton files.  */
   char const m4sugar[] = "m4sugar/m4sugar.m4";
   char const m4bison[] = "bison.m4";
   char *full_m4sugar;
@@ -505,26 +502,59 @@ output_skeleton (void)
     strcpy (full_skeleton, skeleton);
   else
     strcpy (full_skeleton + pkgdatadirlen + 1, skeleton);
+
+  /* Test whether m4sugar.m4 is readable, to check for proper
+     installation.  A faulty installation can cause deadlock, so a
+     cheap sanity check is worthwhile.  */
   xfclose (xfopen (full_m4sugar, "r"));
 
   /* Create an m4 subprocess connected to us via two pipes.  */
 
   if (trace_flag & trace_tools)
     fprintf (stderr, "running: %s %s - %s %s\n",
-	     m4, full_m4sugar, full_m4bison, full_skeleton);
+             m4, full_m4sugar, full_m4bison, full_skeleton);
 
-  argv[0] = m4;
-  argv[1] = full_m4sugar;
-  argv[2] = "-";
-  argv[3] = full_m4bison;
-  argv[4] = full_skeleton;
-  argv[5] = trace_flag & trace_m4 ? "-dV" : NULL;
-  argv[6] = NULL;
+  /* Some future version of GNU M4 (most likely 1.6) may treat the -dV in a
+     position-dependent manner.  Keep it as the first argument so that all
+     files are traced.
 
+     See the thread starting at
+     <http://lists.gnu.org/archive/html/bug-bison/2008-07/msg00000.html>
+     for details.  */
+  {
+    int i = 0;
+    argv[i++] = m4;
+    if (trace_flag & trace_m4)
+      argv[i++] = "-dV";
+    argv[i++] = full_m4sugar;
+    argv[i++] = "-";
+    argv[i++] = full_m4bison;
+    argv[i++] = full_skeleton;
+    argv[i++] = NULL;
+  }
+  /* When POSIXLY_CORRECT is set, some future versions of GNU M4 (most likely
+     2.0) may drop some of the GNU extensions that Bison's skeletons depend
+     upon.  So that the next release of Bison is forward compatible with those
+     future versions of GNU M4, we unset POSIXLY_CORRECT here.
+
+     FIXME: A user might set POSIXLY_CORRECT to affect processes run from
+     macros like m4_syscmd in a custom skeleton.  For now, Bison makes no
+     promises about the behavior of custom skeletons, so this scenario is not a
+     concern.  However, we eventually want to eliminate this shortcoming.  The
+     next release of GNU M4 (1.4.12 or 1.6) will accept the -g command-line
+     option as a no-op, and later releases will accept it to indicate that
+     POSIXLY_CORRECT should be ignored.  Once the GNU M4 versions that accept
+     -g are pervasive, Bison should use -g instead of unsetting
+     POSIXLY_CORRECT.
+
+     See the thread starting at
+     <http://lists.gnu.org/archive/html/bug-bison/2008-07/msg00000.html>
+     for details.  */
+  unsetenv ("POSIXLY_CORRECT");
   init_subpipe ();
   pid = create_subpipe (argv, filter_fd);
-  free (full_m4bison);
   free (full_m4sugar);
+  free (full_m4bison);
   free (full_skeleton);
 
   out = fdopen (filter_fd[0], "w");
