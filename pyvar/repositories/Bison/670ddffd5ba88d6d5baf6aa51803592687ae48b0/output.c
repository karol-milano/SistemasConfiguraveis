@@ -1002,7 +1002,7 @@ output_skeleton (void)
     if (!bison_pkgdatadir)
       bison_pkgdatadir = PKGDATADIR;
     pkg_data_len = strlen (bison_pkgdatadir);
-    full_skeleton = XMALLOC (char, pkg_data_len + strlen (skeleton) + 1);
+    full_skeleton = XMALLOC (char, pkg_data_len + strlen (skeleton) + 2);
     if (bison_pkgdatadir[pkg_data_len-1] == '/')
       sprintf (full_skeleton, "%s%s", bison_pkgdatadir, skeleton);
     else
