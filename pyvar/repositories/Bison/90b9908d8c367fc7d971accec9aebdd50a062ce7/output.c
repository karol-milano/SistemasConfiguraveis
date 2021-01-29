@@ -499,7 +499,7 @@ output_skeleton (void)
   FILE *in;
   FILE *out;
   int filter_fd[2];
-  char const *argv[6];
+  char const *argv[7];
   pid_t pid;
 
   /* Compute the names of the package data dir and skeleton file.
@@ -507,7 +507,9 @@ output_skeleton (void)
      installation.  A faulty installation can cause deadlock, so a
      cheap sanity check is worthwhile.  */
   char const m4sugar[] = "m4sugar/m4sugar.m4";
+  char const m4bison[] = "bison.m4";
   char *full_m4sugar;
+  char *full_m4bison;
   char *full_skeleton;
   char const *p;
   char const *m4 = (p = getenv ("M4")) ? p : M4;
@@ -523,24 +525,28 @@ output_skeleton (void)
   full_skeleton[pkgdatadirlen] = '/';
   strcpy (full_skeleton + pkgdatadirlen + 1, m4sugar);
   full_m4sugar = xstrdup (full_skeleton);
+  strcpy (full_skeleton + pkgdatadirlen + 1, m4bison);
+  full_m4bison = xstrdup (full_skeleton);
   strcpy (full_skeleton + pkgdatadirlen + 1, skeleton);
   xfclose (xfopen (full_m4sugar, "r"));
 
   /* Create an m4 subprocess connected to us via two pipes.  */
 
   if (trace_flag & trace_tools)
-    fprintf (stderr, "running: %s %s - %s\n",
-	     m4, full_m4sugar, full_skeleton);
+    fprintf (stderr, "running: %s %s - %s %s\n",
+	     m4, full_m4sugar, full_m4bison, full_skeleton);
 
   argv[0] = m4;
   argv[1] = full_m4sugar;
   argv[2] = "-";
-  argv[3] = full_skeleton;
-  argv[4] = trace_flag & trace_m4 ? "-dV" : NULL;
-  argv[5] = NULL;
+  argv[3] = full_m4bison;
+  argv[4] = full_skeleton;
+  argv[5] = trace_flag & trace_m4 ? "-dV" : NULL;
+  argv[6] = NULL;
 
   init_subpipe ();
   pid = create_subpipe (argv, filter_fd);
+  free (full_m4bison);
   free (full_m4sugar);
   free (full_skeleton);
 
@@ -584,7 +590,9 @@ prepare (void)
   MUSCLE_INSERT_BOOL ("debug_flag", debug_flag);
   MUSCLE_INSERT_BOOL ("defines_flag", defines_flag);
   MUSCLE_INSERT_BOOL ("error_verbose_flag", error_verbose);
+  MUSCLE_INSERT_BOOL ("glr_flag", glr_parser);
   MUSCLE_INSERT_BOOL ("locations_flag", locations_flag);
+  MUSCLE_INSERT_BOOL ("nondeterministic_flag", nondeterministic_parser);
   MUSCLE_INSERT_BOOL ("pure_flag", pure_parser);
   MUSCLE_INSERT_BOOL ("push_flag", push_parser);
   MUSCLE_INSERT_BOOL ("synclines_flag", !no_lines_flag);
@@ -592,7 +600,9 @@ prepare (void)
   MUSCLE_INSERT_BOOL ("yacc_flag", yacc_flag);
 
   /* File names.  */
-  MUSCLE_INSERT_STRING ("prefix", spec_name_prefix ? spec_name_prefix : "yy");
+  if (spec_name_prefix)
+    MUSCLE_INSERT_STRING ("prefix", spec_name_prefix);
+
 #define DEFINE(Name) MUSCLE_INSERT_STRING (#Name, Name ? Name : "")
   DEFINE (dir_prefix);
   DEFINE (parser_file_name);
