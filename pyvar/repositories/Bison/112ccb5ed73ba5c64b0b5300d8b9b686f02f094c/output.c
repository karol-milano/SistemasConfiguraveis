@@ -549,11 +549,12 @@ output_skeleton (void)
   /* Compute the names of the package data dir and skeleton files.  */
   char const *m4 = (m4 = getenv ("M4")) ? m4 : M4;
   char const *datadir = pkgdatadir ();
+  char *skeldir = xpath_join (datadir, "skeletons");
   char *m4sugar = xpath_join (datadir, "m4sugar/m4sugar.m4");
-  char *m4bison = xpath_join (datadir, "bison.m4");
+  char *m4bison = xpath_join (skeldir, "bison.m4");
   char *skel = (IS_PATH_WITH_DIR (skeleton)
                 ? xstrdup (skeleton)
-                : xpath_join (datadir, skeleton));
+                : xpath_join (skeldir, skeleton));
 
   /* Test whether m4sugar.m4 is readable, to check for proper
      installation.  A faulty installation can cause deadlock, so a
@@ -608,6 +609,7 @@ output_skeleton (void)
                             true, filter_fd);
   }
 
+  free (skeldir);
   free (m4sugar);
   free (m4bison);
   free (skel);
@@ -680,10 +682,12 @@ prepare (void)
 
   /* About the skeletons.  */
   {
-    /* b4_pkgdatadir is used inside m4_include in the skeletons, so digraphs
+    /* b4_skeletonsdir is used inside m4_include in the skeletons, so digraphs
        would never be expanded.  Hopefully no one has M4-special characters in
        his Bison installation path.  */
-    MUSCLE_INSERT_STRING_RAW ("pkgdatadir", pkgdatadir ());
+    char *skeldir = xpath_join (pkgdatadir (), "skeletons");
+    MUSCLE_INSERT_STRING_RAW ("skeletonsdir", skeldir);
+    free (skeldir);
   }
 }
 
