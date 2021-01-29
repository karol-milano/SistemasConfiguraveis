@@ -1001,15 +1001,17 @@ output_skeleton (void)
   /* Invoke m4 on the definition of the muscles, and the skeleton. */
   {
     const char *bison_pkgdatadir = getenv ("BISON_PKGDATADIR");
+    const char *m4 = getenv ("M4");
+    if (!m4)
+      m4 = M4;
     if (!bison_pkgdatadir)
       bison_pkgdatadir = PKGDATADIR;
     if (trace_flag)
       fprintf (stderr,
-	       "running: m4 -I %s m4sugar/m4sugar.m4 %s %s\n",
-	       bison_pkgdatadir, tempfile, skeleton);
-    skel_in = readpipe ("m4",
-			"-I",
-			bison_pkgdatadir,
+	       "running: %s -I %s m4sugar/m4sugar.m4 %s %s\n",
+	       m4, bison_pkgdatadir, tempfile, skeleton);
+    skel_in = readpipe (m4,
+			"-I", bison_pkgdatadir,
 			"m4sugar/m4sugar.m4",
 			tempfile,
 			skeleton,
