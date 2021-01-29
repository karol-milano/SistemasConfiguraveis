@@ -682,7 +682,7 @@ static void
 output_skeleton (void)
 {
   /* Compute the names of the package data dir and skeleton files.  */
-  char const *m4 = (m4 = getenv ("M4")) ? m4 : M4;
+  char const *m4 = m4path ();
   char const *datadir = pkgdatadir ();
   char *skeldir = xpath_join (datadir, "skeletons");
   char *m4sugar = xpath_join (datadir, "m4sugar/m4sugar.m4");
