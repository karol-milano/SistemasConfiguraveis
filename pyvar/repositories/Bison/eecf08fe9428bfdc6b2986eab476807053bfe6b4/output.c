@@ -518,7 +518,7 @@ output_skeleton (void)
   char const m4sugar[] = "m4sugar/m4sugar.m4";
   char *full_m4sugar;
   char *full_cm4;
-  char *full_path;
+  char *full_skeleton;
   char const *p;
   char const *m4 = (p = getenv ("M4")) ? p : M4;
   char const *pkgdatadir = (p = getenv ("BISON_PKGDATADIR")) ? p : PKGDATADIR;
@@ -526,36 +526,36 @@ output_skeleton (void)
   size_t pkgdatadirlen = strlen (pkgdatadir);
   while (pkgdatadirlen && pkgdatadir[pkgdatadirlen - 1] == '/')
     pkgdatadirlen--;
-  full_path = xmalloc (pkgdatadirlen + 1
-		       + (skeleton_size < sizeof m4sugar
-			  ? sizeof m4sugar : skeleton_size));
-  strcpy (full_path, pkgdatadir);
-  full_path[pkgdatadirlen] = '/';
-  strcpy (full_path + pkgdatadirlen + 1, m4sugar);
-  full_m4sugar = xstrdup (full_path);
-  strcpy (full_path + pkgdatadirlen + 1, "c.m4");
-  full_cm4 = xstrdup (full_path);
-  strcpy (full_path + pkgdatadirlen + 1, skeleton);
+  full_skeleton = xmalloc (pkgdatadirlen + 1
+			   + (skeleton_size < sizeof m4sugar
+			      ? sizeof m4sugar : skeleton_size));
+  strcpy (full_skeleton, pkgdatadir);
+  full_skeleton[pkgdatadirlen] = '/';
+  strcpy (full_skeleton + pkgdatadirlen + 1, m4sugar);
+  full_m4sugar = xstrdup (full_skeleton);
+  strcpy (full_skeleton + pkgdatadirlen + 1, "c.m4");
+  full_cm4 = xstrdup (full_skeleton);
+  strcpy (full_skeleton + pkgdatadirlen + 1, skeleton);
   xfclose (xfopen (full_m4sugar, "r"));
 
   /* Create an m4 subprocess connected to us via two pipes.  */
 
   if (trace_flag & trace_tools)
     fprintf (stderr, "running: %s %s - %s %s\n",
-	     m4, full_m4sugar, full_cm4, full_path);
+	     m4, full_m4sugar, full_cm4, full_skeleton);
 
   argv[0] = m4;
   argv[1] = full_m4sugar;
   argv[2] = "-";
   argv[3] = full_cm4;
-  argv[4] = full_path;
+  argv[4] = full_skeleton;
   argv[5] = NULL;
 
   init_subpipe ();
   pid = create_subpipe (argv, filter_fd);
   free (full_m4sugar);
   free (full_cm4);
-  free (full_path);
+  free (full_skeleton);
 
   out = fdopen (filter_fd[0], "w");
   if (! out)
