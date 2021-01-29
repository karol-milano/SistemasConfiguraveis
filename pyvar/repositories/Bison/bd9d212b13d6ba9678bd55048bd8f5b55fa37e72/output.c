@@ -603,6 +603,8 @@ prepare (void)
   if (spec_name_prefix)
     MUSCLE_INSERT_STRING ("prefix", spec_name_prefix);
 
+  MUSCLE_INSERT_STRING ("file_name_all_but_ext", all_but_ext);
+
 #define DEFINE(Name) MUSCLE_INSERT_STRING (#Name, Name ? Name : "")
   DEFINE (dir_prefix);
   DEFINE (parser_file_name);
@@ -632,7 +634,11 @@ prepare (void)
   /* About the skeletons. */
   {
     char const *pkgdatadir = getenv ("BISON_PKGDATADIR");
-    MUSCLE_INSERT_STRING ("pkgdatadir", pkgdatadir ? pkgdatadir : PKGDATADIR);
+    /* b4_pkgdatadir is used inside m4_include in the skeletons, so digraphs
+       would never be expanded.  Hopefully no one has M4-special characters in
+       his Bison installation path.  */
+    MUSCLE_INSERT_STRING_RAW ("pkgdatadir",
+                              pkgdatadir ? pkgdatadir : PKGDATADIR);
     MUSCLE_INSERT_C_STRING ("skeleton", skeleton);
   }
 }
