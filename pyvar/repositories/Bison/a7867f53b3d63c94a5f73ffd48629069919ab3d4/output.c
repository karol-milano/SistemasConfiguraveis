@@ -492,13 +492,16 @@ output_skeleton (void)
   full_skeleton = xmalloc (pkgdatadirlen + 1
 			   + (skeleton_size < sizeof m4sugar
 			      ? sizeof m4sugar : skeleton_size));
-  strcpy (full_skeleton, pkgdatadir);
+  strncpy (full_skeleton, pkgdatadir, pkgdatadirlen);
   full_skeleton[pkgdatadirlen] = '/';
   strcpy (full_skeleton + pkgdatadirlen + 1, m4sugar);
   full_m4sugar = xstrdup (full_skeleton);
   strcpy (full_skeleton + pkgdatadirlen + 1, m4bison);
   full_m4bison = xstrdup (full_skeleton);
-  strcpy (full_skeleton + pkgdatadirlen + 1, skeleton);
+  if (strchr (skeleton, '/'))
+    strcpy (full_skeleton, skeleton);
+  else
+    strcpy (full_skeleton + pkgdatadirlen + 1, skeleton);
   xfclose (xfopen (full_m4sugar, "r"));
 
   /* Create an m4 subprocess connected to us via two pipes.  */
