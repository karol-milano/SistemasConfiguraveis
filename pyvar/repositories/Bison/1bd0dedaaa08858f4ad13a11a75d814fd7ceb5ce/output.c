@@ -618,8 +618,8 @@ prepare (void)
 
   /* About the skeletons. */
   {
-    char const* p = getenv ("BISON_PKGDATADIR");
-    MUSCLE_INSERT_STRING ("pkgdatadir", p ? p : PKGDATADIR);
+    char const *pkgdatadir = getenv ("BISON_PKGDATADIR");
+    MUSCLE_INSERT_STRING ("pkgdatadir", pkgdatadir ? pkgdatadir : PKGDATADIR);
     MUSCLE_INSERT_C_STRING ("skeleton", skeleton);
   }
 }
