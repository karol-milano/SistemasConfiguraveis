@@ -562,7 +562,7 @@ output_skeleton (void)
 {
   FILE *in;
   int filter_fd[2];
-  char const *argv[9];
+  char const *argv[10];
   pid_t pid;
 
   /* Compute the names of the package data dir and skeleton files.  */
@@ -613,6 +613,19 @@ output_skeleton (void)
   {
     int i = 0;
     argv[i++] = m4;
+
+    /* When POSIXLY_CORRECT is set, GNU M4 1.6 and later disable GNU
+       extensions, which Bison's skeletons depend on.  With older M4,
+       it has no effect.  M4 1.4.12 added a -g/--gnu command-line
+       option to make it explicit that a program wants GNU M4
+       extensions even when POSIXLY_CORRECT is set.
+
+       See the thread starting at
+       <http://lists.gnu.org/archive/html/bug-bison/2008-07/msg00000.html>
+       for details.  */
+    if (*M4_GNU_OPTION)
+      argv[i++] = M4_GNU_OPTION;
+
     argv[i++] = "-I";
     argv[i++] = pkgdatadir;
     if (trace_flag & trace_m4)
@@ -623,25 +636,7 @@ output_skeleton (void)
     argv[i++] = full_skeleton;
     argv[i++] = NULL;
   }
-  /* When POSIXLY_CORRECT is set, some future versions of GNU M4 (most likely
-     2.0) may drop some of the GNU extensions that Bison's skeletons depend
-     upon.  So that the next release of Bison is forward compatible with those
-     future versions of GNU M4, we unset POSIXLY_CORRECT here.
-
-     FIXME: A user might set POSIXLY_CORRECT to affect processes run from
-     macros like m4_syscmd in a custom skeleton.  For now, Bison makes no
-     promises about the behavior of custom skeletons, so this scenario is not a
-     concern.  However, we eventually want to eliminate this shortcoming.  The
-     next release of GNU M4 (1.4.12 or 1.6) will accept the -g command-line
-     option as a no-op, and later releases will accept it to indicate that
-     POSIXLY_CORRECT should be ignored.  Once the GNU M4 versions that accept
-     -g are pervasive, Bison should use -g instead of unsetting
-     POSIXLY_CORRECT.
 
-     See the thread starting at
-     <http://lists.gnu.org/archive/html/bug-bison/2008-07/msg00000.html>
-     for details.  */
-  unsetenv ("POSIXLY_CORRECT");
   init_subpipe ();
   pid = create_subpipe (argv, filter_fd);
   free (full_m4sugar);
