@@ -526,10 +526,7 @@ output_skeleton (void)
   strcpy (full_path, pkgdatadir);
   full_path[pkgdatadirlen] = '/';
   strcpy (full_path + pkgdatadirlen + 1, m4sugar);
-  in = fopen (full_path, "r");
-  if (! in)
-    error (EXIT_FAILURE, errno, "%s", full_path);
-  xfclose (in);
+  xfclose (xfopen (full_path, "r"));
   strcpy (full_path + pkgdatadirlen + 1, skeleton);
 
   /* Create an m4 subprocess connected to us via two pipes.  */
