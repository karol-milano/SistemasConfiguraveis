@@ -941,6 +941,46 @@ output_actions (void)
 }
 
 
+/*----------------------.
+| Run our backend, M4.  |
+`----------------------*/
+
+static void
+m4_invoke (const char *definitions)
+{
+  /* Invoke m4 on the definition of the muscles, and the skeleton. */
+  const char *bison_pkgdatadir = getenv ("BISON_PKGDATADIR");
+  const char *m4 = getenv ("M4");
+  int pkg_data_len;
+  char *full_skeleton;
+
+  if (!m4)
+    m4 = M4;
+  if (!bison_pkgdatadir)
+    bison_pkgdatadir = PKGDATADIR;
+  pkg_data_len = strlen (bison_pkgdatadir);
+  full_skeleton = XMALLOC (char, pkg_data_len + strlen (skeleton) + 2);
+  if (bison_pkgdatadir[pkg_data_len-1] == '/')
+    sprintf (full_skeleton, "%s%s", bison_pkgdatadir, skeleton);
+  else
+    sprintf (full_skeleton, "%s/%s", bison_pkgdatadir, skeleton);
+  if (trace_flag)
+    fprintf (stderr,
+	     "running: %s -I %s m4sugar/m4sugar.m4 %s %s\n",
+	     m4, bison_pkgdatadir, definitions, full_skeleton);
+  skel_in = readpipe (m4,
+		      "-I", bison_pkgdatadir,
+		      "m4sugar/m4sugar.m4",
+		      definitions,
+		      full_skeleton,
+		      NULL);
+  XFREE (full_skeleton);
+  if (!skel_in)
+    error (EXIT_FAILURE, errno, "cannot run m4");
+  skel_lex ();
+
+}
+
 /*---------------------------.
 | Call the skeleton parser.  |
 `---------------------------*/
@@ -985,42 +1025,13 @@ output_skeleton (void)
   fputs ("m4_divert_push(0)dnl\n", out);
   xfclose (out);
 
-  /* Invoke m4 on the definition of the muscles, and the skeleton. */
-  {
-    const char *bison_pkgdatadir = getenv ("BISON_PKGDATADIR");
-    const char *m4 = getenv ("M4");
-    int pkg_data_len;
-    char *full_skeleton;
-
-    if (!m4)
-      m4 = M4;
-    if (!bison_pkgdatadir)
-      bison_pkgdatadir = PKGDATADIR;
-    pkg_data_len = strlen (bison_pkgdatadir);
-    full_skeleton = XMALLOC (char, pkg_data_len + strlen (skeleton) + 2);
-    if (bison_pkgdatadir[pkg_data_len-1] == '/')
-      sprintf (full_skeleton, "%s%s", bison_pkgdatadir, skeleton);
-    else
-      sprintf (full_skeleton, "%s/%s", bison_pkgdatadir, skeleton);
-    if (trace_flag)
-      fprintf (stderr,
-	       "running: %s -I %s m4sugar/m4sugar.m4 %s %s\n",
-	       m4, bison_pkgdatadir, tempfile, full_skeleton);
-    skel_in = readpipe (m4,
-			"-I", bison_pkgdatadir,
-			"m4sugar/m4sugar.m4",
-			tempfile,
-			full_skeleton,
-			NULL);
-    XFREE (full_skeleton);
-    if (!skel_in)
-      error (EXIT_FAILURE, errno, "cannot run m4");
-    skel_lex ();
-
-    /* If `debugging', keep this file alive. */
-    if (!trace_flag)
-      unlink (tempfile);
-  }
+  m4_invoke (tempfile);
+
+  /* If `debugging', keep this file alive. */
+  if (!trace_flag)
+    unlink (tempfile);
+
+  free (tempfile);
 }
 
 static void
