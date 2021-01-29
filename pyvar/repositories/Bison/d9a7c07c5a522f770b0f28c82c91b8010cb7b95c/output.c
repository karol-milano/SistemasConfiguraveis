@@ -21,8 +21,10 @@
 #include <config.h>
 #include "system.h"
 
+#include <concat-filename.h>
 #include <configmake.h>
 #include <error.h>
+#include <filename.h>
 #include <get-errno.h>
 #include <quotearg.h>
 #include <spawn-pipe.h>
@@ -568,48 +570,29 @@ muscles_output (FILE *out)
 static void
 output_skeleton (void)
 {
-  FILE *in;
   int filter_fd[2];
   char const *argv[10];
   pid_t pid;
 
   /* Compute the names of the package data dir and skeleton files.  */
-  char const m4sugar[] = "m4sugar/m4sugar.m4";
-  char const m4bison[] = "bison.m4";
-  char *full_m4sugar;
-  char *full_m4bison;
-  char *full_skeleton;
-  char const *p;
-  char const *m4 = (p = getenv ("M4")) ? p : M4;
-  char const *pkgdatadir = compute_pkgdatadir ();
-  size_t skeleton_size = strlen (skeleton) + 1;
-  size_t pkgdatadirlen = strlen (pkgdatadir);
-  while (pkgdatadirlen && pkgdatadir[pkgdatadirlen - 1] == '/')
-    pkgdatadirlen--;
-  full_skeleton = xmalloc (pkgdatadirlen + 1
-                           + (skeleton_size < sizeof m4sugar
-                              ? sizeof m4sugar : skeleton_size));
-  strncpy (full_skeleton, pkgdatadir, pkgdatadirlen);
-  full_skeleton[pkgdatadirlen] = '/';
-  strcpy (full_skeleton + pkgdatadirlen + 1, m4sugar);
-  full_m4sugar = xstrdup (full_skeleton);
-  strcpy (full_skeleton + pkgdatadirlen + 1, m4bison);
-  full_m4bison = xstrdup (full_skeleton);
-  if (mbschr (skeleton, '/'))
-    strcpy (full_skeleton, skeleton);
-  else
-    strcpy (full_skeleton + pkgdatadirlen + 1, skeleton);
+  char const *m4 = (m4 = getenv ("M4")) ? m4 : M4;
+  char const *datadir = pkgdatadir ();
+  char *m4sugar = xconcatenated_filename (datadir, "m4sugar/m4sugar.m4", NULL);
+  char *m4bison = xconcatenated_filename (datadir, "bison.m4", NULL);
+  char *skel = (IS_PATH_WITH_DIR (skeleton)
+		? xstrdup (skeleton)
+		: xconcatenated_filename (datadir, skeleton, NULL));
 
   /* Test whether m4sugar.m4 is readable, to check for proper
      installation.  A faulty installation can cause deadlock, so a
      cheap sanity check is worthwhile.  */
-  xfclose (xfopen (full_m4sugar, "r"));
+  xfclose (xfopen (m4sugar, "r"));
 
   /* Create an m4 subprocess connected to us via two pipes.  */
 
   if (trace_flag & trace_tools)
     fprintf (stderr, "running: %s %s - %s %s\n",
-             m4, full_m4sugar, full_m4bison, full_skeleton);
+             m4, m4sugar, m4bison, skel);
 
   /* Some future version of GNU M4 (most likely 1.6) may treat the -dV in a
      position-dependent manner.  Keep it as the first argument so that all
@@ -635,13 +618,13 @@ output_skeleton (void)
       argv[i++] = M4_GNU_OPTION;
 
     argv[i++] = "-I";
-    argv[i++] = pkgdatadir;
+    argv[i++] = datadir;
     if (trace_flag & trace_m4)
       argv[i++] = "-dV";
-    argv[i++] = full_m4sugar;
+    argv[i++] = m4sugar;
     argv[i++] = "-";
-    argv[i++] = full_m4bison;
-    argv[i++] = full_skeleton;
+    argv[i++] = m4bison;
+    argv[i++] = skel;
     argv[i++] = NULL;
     aver (i <= ARRAY_CARDINALITY (argv));
   }
@@ -649,9 +632,9 @@ output_skeleton (void)
   /* The ugly cast is because gnulib gets the const-ness wrong.  */
   pid = create_pipe_bidi ("m4", m4, (char **)(void*)argv, false, true,
                           true, filter_fd);
-  free (full_m4sugar);
-  free (full_m4bison);
-  free (full_skeleton);
+  free (m4sugar);
+  free (m4bison);
+  free (skel);
 
   if (trace_flag & trace_muscles)
     muscles_output (stderr);
@@ -666,16 +649,18 @@ output_skeleton (void)
 
   /* Read and process m4's output.  */
   timevar_push (TV_M4);
-  in = fdopen (filter_fd[0], "r");
-  if (! in)
-    error (EXIT_FAILURE, get_errno (),
-           "fdopen");
-  scan_skel (in);
-  /* scan_skel should have read all of M4's output.  Otherwise, when we
-     close the pipe, we risk letting M4 report a broken-pipe to the
-     Bison user.  */
-  aver (feof (in));
-  xfclose (in);
+  {
+    FILE *in = fdopen (filter_fd[0], "r");
+    if (! in)
+      error (EXIT_FAILURE, get_errno (),
+	     "fdopen");
+    scan_skel (in);
+    /* scan_skel should have read all of M4's output.  Otherwise, when we
+       close the pipe, we risk letting M4 report a broken-pipe to the
+       Bison user.  */
+    aver (feof (in));
+    xfclose (in);
+  }
   wait_subprocess (pid, "m4", false, false, true, true, NULL);
   timevar_pop (TV_M4);
 }
@@ -725,7 +710,7 @@ prepare (void)
     /* b4_pkgdatadir is used inside m4_include in the skeletons, so digraphs
        would never be expanded.  Hopefully no one has M4-special characters in
        his Bison installation path.  */
-    MUSCLE_INSERT_STRING_RAW ("pkgdatadir", compute_pkgdatadir ());
+    MUSCLE_INSERT_STRING_RAW ("pkgdatadir", pkgdatadir ());
   }
 }
 
@@ -754,8 +739,8 @@ output (void)
 }
 
 char const *
-compute_pkgdatadir (void)
+pkgdatadir (void)
 {
-  char const *pkgdatadir = getenv ("BISON_PKGDATADIR");
-  return pkgdatadir ? pkgdatadir : PKGDATADIR;
+  char const *cp = getenv ("BISON_PKGDATADIR");
+  return cp ? cp : PKGDATADIR;
 }
