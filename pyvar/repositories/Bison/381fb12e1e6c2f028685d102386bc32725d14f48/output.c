@@ -956,60 +956,71 @@ output_actions (void)
 static void
 output_skeleton (void)
 {
-  /* Find the right skeleton file.  */
-  if (!skeleton)
-    {
-      if (semantic_parser)
-	skeleton = "bison.hairy";
-      else
-	skeleton = "bison.simple";
-    }
-
-  /* Parse the skeleton file and output the needed parsers.  */
-  muscle_insert ("skeleton", skeleton);
-
   /* Store the definition of all the muscles. */
-  {
-    FILE *muscles_m4 = xfopen ("/tmp/muscles.m4", "w");
-    /* There are no comments, especially not `#': we do want M4 expansion
-       after `#': think of CPP macros!  */
-    fprintf (muscles_m4, "m4_changecom()\n");
-    fprintf (muscles_m4, "m4_init()\n");
-
-    fprintf (muscles_m4, "m4_define([b4_actions], \n[[");
-    actions_output (muscles_m4);
-    fprintf (muscles_m4, "]])\n\n");
-
-    fprintf (muscles_m4, "m4_define([b4_guards], \n[[");
-    guards_output (muscles_m4);
-    fprintf (muscles_m4, "]])\n\n");
-
-    fprintf (muscles_m4, "m4_define([b4_tokendef], \n[[");
-    token_definitions_output (muscles_m4);
-    fprintf (muscles_m4, "]])\n\n");
+  char *tempdir = getenv ("TMPDIR");
+  char *tempfile = NULL;
+  FILE *out = NULL;
+  ssize_t bytes_read;
+  int fd;
+
+  if (tempdir == NULL)
+    tempdir = DEFAULT_TMPDIR;
+  tempfile = xmalloc (strlen (tempdir) + 11);
+  sprintf (tempfile, "%s/bsnXXXXXX", tempdir);
+  fd = mkstemp (tempfile);
+  if (fd == -1)
+    error (EXIT_FAILURE, errno, "%s", tempfile);
+
+  out = fdopen (fd, "w");
+  if (out == NULL)
+    error (EXIT_FAILURE, errno, "%s", tempfile);
+
+  /* There are no comments, especially not `#': we do want M4 expansion
+     after `#': think of CPP macros!  */
+  fputs ("m4_changecom()\n", out);
+  fputs ("m4_init()\n", out);
+
+  fputs ("m4_define([b4_actions], \n[[", out);
+  actions_output (out);
+  fputs ("]])\n\n", out);
+
+  fputs ("m4_define([b4_guards], \n[[", out);
+  guards_output (out);
+  fputs ("]])\n\n", out);
+
+  fputs ("m4_define([b4_tokendef], \n[[", out);
+  token_definitions_output (out);
+  fputs ("]])\n\n", out);
 
-    muscles_m4_output (muscles_m4);
+  muscles_m4_output (out);
 
-    fprintf (muscles_m4, "m4_wrap([m4_divert_pop(0)])\n");
-    fprintf (muscles_m4, "m4_divert_push(0)dnl\n");
-    xfclose (muscles_m4);
-  }
+  fputs ("m4_wrap([m4_divert_pop(0)])\n", out);
+  fputs ("m4_divert_push(0)dnl\n", out);
+  xfclose (out);
 
   /* Invoke m4 on the definition of the muscles, and the skeleton. */
   {
     const char *bison_pkgdatadir = getenv ("BISON_PKGDATADIR");
     if (!bison_pkgdatadir)
       bison_pkgdatadir = PKGDATADIR;
+    if (trace_flag)
+      fprintf (stderr,
+	       "running: m4 -I %s m4sugar/m4sugar.m4 %s %s\n",
+	       bison_pkgdatadir, tempfile, skeleton);
     skel_in = readpipe ("m4",
 			"-I",
 			bison_pkgdatadir,
 			"m4sugar/m4sugar.m4",
-			"/tmp/muscles.m4",
+			tempfile,
 			skeleton,
 			NULL);
     if (!skel_in)
       error (EXIT_FAILURE, errno, "cannot run m4");
     skel_lex ();
+
+    /* If `debugging', keep this file alive. */
+    if (!trace_flag)
+      unlink (tempfile);
   }
 }
 
@@ -1040,6 +1051,22 @@ prepare (void)
 
   MUSCLE_INSERT_INT ("locations_flag", locations_flag);
   MUSCLE_INSERT_INT ("defines_flag", defines_flag);
+
+  /* Copy definitions in directive.  */
+  obstack_1grow (&attrs_obstack, 0);
+  muscle_insert ("prologue", obstack_finish (&attrs_obstack));
+
+  /* Find the right skeleton file.  */
+  if (!skeleton)
+    {
+      if (semantic_parser)
+	skeleton = "bison.hairy";
+      else
+	skeleton = "bison.simple";
+    }
+
+  /* Parse the skeleton file and output the needed parsers.  */
+  muscle_insert ("skeleton", skeleton);
 }
 
 /*-------------------------.
@@ -1122,9 +1149,6 @@ output (void)
   output_actions ();
 
   prepare ();
-  /* Copy definitions in directive.  */
-  obstack_1grow (&attrs_obstack, 0);
-  muscle_insert ("prologue", obstack_finish (&attrs_obstack));
 
   /* Process the selected skeleton file.  */
   output_skeleton ();
