@@ -482,7 +482,7 @@ output_skeleton (void)
   char *full_skeleton;
   char const *p;
   char const *m4 = (p = getenv ("M4")) ? p : M4;
-  char const *pkgdatadir = (p = getenv ("BISON_PKGDATADIR")) ? p : PKGDATADIR;
+  char const *pkgdatadir = compute_pkgdatadir ();
   size_t skeleton_size = strlen (skeleton) + 1;
   size_t pkgdatadirlen = strlen (pkgdatadir);
   while (pkgdatadirlen && pkgdatadir[pkgdatadirlen - 1] == '/')
@@ -602,12 +602,10 @@ prepare (void)
 
   /* About the skeletons.  */
   {
-    char const *pkgdatadir = getenv ("BISON_PKGDATADIR");
     /* b4_pkgdatadir is used inside m4_include in the skeletons, so digraphs
        would never be expanded.  Hopefully no one has M4-special characters in
        his Bison installation path.  */
-    MUSCLE_INSERT_STRING_RAW ("pkgdatadir",
-                              pkgdatadir ? pkgdatadir : PKGDATADIR);
+    MUSCLE_INSERT_STRING_RAW ("pkgdatadir", compute_pkgdatadir ());
   }
 }
 
@@ -633,3 +631,10 @@ output (void)
 
   obstack_free (&format_obstack, NULL);
 }
+
+char const *
+compute_pkgdatadir (void)
+{
+  char const *pkgdatadir = getenv ("BISON_PKGDATADIR");
+  return pkgdatadir ? pkgdatadir : PKGDATADIR;
+}
