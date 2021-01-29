@@ -88,6 +88,7 @@
 #include "system.h"
 #include "quotearg.h"
 #include "error.h"
+#include "subpipe.h"
 #include "getargs.h"
 #include "files.h"
 #include "gram.h"
@@ -99,7 +100,7 @@
 #include "muscle_tab.h"
 
 /* From src/scan-skel.l. */
-void m4_invoke PARAMS ((const char *definitions));
+void scan_skel (FILE *);
 
 
 static struct obstack format_obstack;
@@ -526,23 +527,59 @@ prepare_actions (void)
 static void
 output_skeleton (void)
 {
-  /* Store the definition of all the muscles. */
-  const char *tempdir = getenv ("TMPDIR");
-  char *tempfile = NULL;
-  FILE *out = NULL;
-  int fd;
-
-  if (tempdir == NULL)
-    tempdir = DEFAULT_TMPDIR;
-  tempfile = xmalloc (strlen (tempdir) + 11);
-  sprintf (tempfile, "%s/bsnXXXXXX", tempdir);
-  fd = mkstemp (tempfile);
-  if (fd == -1)
-    error (EXIT_FAILURE, errno, "%s", tempfile);
-
-  out = fdopen (fd, "w");
-  if (out == NULL)
-    error (EXIT_FAILURE, errno, "%s", tempfile);
+  FILE *in;
+  FILE *out;
+  int filter_fd[2];
+  char const *argv[7];
+  pid_t pid;
+
+  /* Compute the names of the package data dir and skeleton file.
+     Test whether m4sugar.m4 is readable, to check for proper
+     installation.  A faulty installation can cause deadlock, so a
+     cheap sanity check is worthwhile.  */
+  char const m4sugar[] = "m4sugar/m4sugar.m4";
+  char *full_path;
+  char const *p;
+  char const *m4 = (p = getenv ("M4")) ? p : M4;
+  char const *pkgdatadir = (p = getenv ("BISON_PKGDATADIR")) ? p : PKGDATADIR;
+  size_t skeleton_size = strlen (skeleton) + 1;
+  size_t pkgdatadirlen = strlen (pkgdatadir);
+  while (pkgdatadirlen && pkgdatadir[pkgdatadirlen - 1] == '/')
+    pkgdatadirlen--;
+  full_path = xmalloc (pkgdatadirlen + 1
+		       + (skeleton_size < sizeof m4sugar
+			  ? sizeof m4sugar : skeleton_size));
+  strcpy (full_path, pkgdatadir);
+  full_path[pkgdatadirlen] = '/';
+  strcpy (full_path + pkgdatadirlen + 1, m4sugar);
+  in = fopen (full_path, "r");
+  if (! in || fclose (in) != 0)
+    error (EXIT_FAILURE, errno, "%s", full_path);
+  strcpy (full_path + pkgdatadirlen + 1, skeleton);
+
+  /* Create an m4 subprocess connected to us via two pipes.  */
+
+  if (trace_flag & trace_tools)
+    fprintf (stderr, "running: %s -I %s %s - %s\n",
+	     m4, pkgdatadir, m4sugar, full_path);
+
+  argv[0] = m4;
+  argv[1] = "-I";
+  argv[2] = pkgdatadir;
+  argv[3] = m4sugar;
+  argv[4] = "-";
+  argv[5] = full_path;
+  argv[6] = NULL;
+
+  init_subpipe ();
+  pid = create_subpipe (argv, filter_fd);
+  free (full_path);
+
+  out = fdopen (filter_fd[0], "w");
+  if (! out)
+    error (EXIT_FAILURE, errno, "fdopen");
+
+  /* Output the definitions of all the muscles.  */
 
   /* There are no comments, especially not `#': we do want M4 expansion
      after `#': think of CPP macros!  */
@@ -559,17 +596,21 @@ output_skeleton (void)
 
   fputs ("m4_wrap([m4_divert_pop(0)])\n", out);
   fputs ("m4_divert_push(0)dnl\n", out);
+  if (ferror (out))
+    error (EXIT_FAILURE, 0, "pipe output error");
   xfclose (out);
 
+  /* Read and process m4's output.  */
   timevar_push (TV_M4);
-  m4_invoke (tempfile);
+  in = fdopen (filter_fd[1], "r");
+  if (! in)
+    error (EXIT_FAILURE, errno, "fdopen");
+  scan_skel (in);
+  if (ferror (in))
+    error (EXIT_FAILURE, 0, "pipe input error");
+  xfclose (in);
+  reap_subpipe (pid, m4);
   timevar_pop (TV_M4);
-
-  /* If `debugging', keep this file alive. */
-  if (!(trace_flag & trace_tools))
-    unlink (tempfile);
-
-  free (tempfile);
 }
 
 static void
