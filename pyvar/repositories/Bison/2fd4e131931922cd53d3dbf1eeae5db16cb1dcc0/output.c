@@ -513,7 +513,7 @@ output_skeleton (void)
   FILE *in;
   FILE *out;
   int filter_fd[2];
-  char const *argv[7];
+  char const *argv[6];
   pid_t pid;
 
   /* Compute the names of the package data dir and skeleton file.
@@ -521,6 +521,8 @@ output_skeleton (void)
      installation.  A faulty installation can cause deadlock, so a
      cheap sanity check is worthwhile.  */
   char const m4sugar[] = "m4sugar/m4sugar.m4";
+  char *full_m4sugar;
+  char *full_cm4;
   char *full_path;
   char const *p;
   char const *m4 = (p = getenv ("M4")) ? p : M4;
@@ -535,25 +537,29 @@ output_skeleton (void)
   strcpy (full_path, pkgdatadir);
   full_path[pkgdatadirlen] = '/';
   strcpy (full_path + pkgdatadirlen + 1, m4sugar);
-  xfclose (xfopen (full_path, "r"));
+  full_m4sugar = xstrdup (full_path);
+  strcpy (full_path + pkgdatadirlen + 1, "c.m4");
+  full_cm4 = xstrdup (full_path);
   strcpy (full_path + pkgdatadirlen + 1, skeleton);
+  xfclose (xfopen (full_m4sugar, "r"));
 
   /* Create an m4 subprocess connected to us via two pipes.  */
 
   if (trace_flag & trace_tools)
-    fprintf (stderr, "running: %s -I %s %s - %s\n",
-	     m4, pkgdatadir, m4sugar, full_path);
+    fprintf (stderr, "running: %s %s - %s %s\n",
+	     m4, full_m4sugar, full_cm4, full_path);
 
   argv[0] = m4;
-  argv[1] = "-I";
-  argv[2] = pkgdatadir;
-  argv[3] = m4sugar;
-  argv[4] = "-";
-  argv[5] = full_path;
-  argv[6] = NULL;
+  argv[1] = full_m4sugar;
+  argv[2] = "-";
+  argv[3] = full_cm4;
+  argv[4] = full_path;
+  argv[5] = NULL;
 
   init_subpipe ();
   pid = create_subpipe (argv, filter_fd);
+  free (full_m4sugar);
+  free (full_cm4);
   free (full_path);
 
   out = fdopen (filter_fd[0], "w");
