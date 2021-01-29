@@ -512,7 +512,7 @@ output_skeleton (void)
   full_skeleton = xmalloc (pkgdatadirlen + 1
 			   + (skeleton_size < sizeof m4sugar
 			      ? sizeof m4sugar : skeleton_size));
-  strncpy (full_skeleton, pkgdatadir, pkgdatadirlen);
+  memcpy (full_skeleton, pkgdatadir, pkgdatadirlen);
   full_skeleton[pkgdatadirlen] = '/';
   strcpy (full_skeleton + pkgdatadirlen + 1, m4sugar);
   full_m4sugar = xstrdup (full_skeleton);
