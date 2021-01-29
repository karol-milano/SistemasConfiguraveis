@@ -1,6 +1,6 @@
 /* Output the generated parsing program for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004, 2005
+   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004, 2005, 2006
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -506,7 +506,7 @@ output_skeleton (void)
   FILE *in;
   FILE *out;
   int filter_fd[2];
-  char const *argv[6];
+  char const *argv[5];
   pid_t pid;
 
   /* Compute the names of the package data dir and skeleton file.
@@ -515,7 +515,6 @@ output_skeleton (void)
      cheap sanity check is worthwhile.  */
   char const m4sugar[] = "m4sugar/m4sugar.m4";
   char *full_m4sugar;
-  char *full_cm4;
   char *full_skeleton;
   char const *p;
   char const *m4 = (p = getenv ("M4")) ? p : M4;
@@ -531,28 +530,24 @@ output_skeleton (void)
   full_skeleton[pkgdatadirlen] = '/';
   strcpy (full_skeleton + pkgdatadirlen + 1, m4sugar);
   full_m4sugar = xstrdup (full_skeleton);
-  strcpy (full_skeleton + pkgdatadirlen + 1, "c.m4");
-  full_cm4 = xstrdup (full_skeleton);
   strcpy (full_skeleton + pkgdatadirlen + 1, skeleton);
   xfclose (xfopen (full_m4sugar, "r"));
 
   /* Create an m4 subprocess connected to us via two pipes.  */
 
   if (trace_flag & trace_tools)
-    fprintf (stderr, "running: %s %s - %s %s\n",
-	     m4, full_m4sugar, full_cm4, full_skeleton);
+    fprintf (stderr, "running: %s %s - %s\n",
+	     m4, full_m4sugar, full_skeleton);
 
   argv[0] = m4;
   argv[1] = full_m4sugar;
   argv[2] = "-";
-  argv[3] = full_cm4;
-  argv[4] = full_skeleton;
-  argv[5] = NULL;
+  argv[3] = full_skeleton;
+  argv[4] = NULL;
 
   init_subpipe ();
   pid = create_subpipe (argv, filter_fd);
   free (full_m4sugar);
-  free (full_cm4);
   free (full_skeleton);
 
   out = fdopen (filter_fd[0], "w");
