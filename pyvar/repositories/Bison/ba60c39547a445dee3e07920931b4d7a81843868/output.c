@@ -595,7 +595,7 @@ output_skeleton (void)
   full_m4sugar = xstrdup (full_skeleton);
   strcpy (full_skeleton + pkgdatadirlen + 1, m4bison);
   full_m4bison = xstrdup (full_skeleton);
-  if (strchr (skeleton, '/'))
+  if (mbschr (skeleton, '/'))
     strcpy (full_skeleton, skeleton);
   else
     strcpy (full_skeleton + pkgdatadirlen + 1, skeleton);
