@@ -622,16 +622,13 @@ prepare (void)
   muscle_insert ("pre_prologue", obstack_finish (&pre_prologue_obstack));
   muscle_insert ("post_prologue", obstack_finish (&post_prologue_obstack));
 
-  /* Find the right skeleton file.  */
-  if (!skeleton)
-    {
-      if (glr_parser || nondeterministic_parser)
-	skeleton = "glr.c";
-      else
-	skeleton = "yacc.c";
-    }
+  /* Find the right skeleton file, and add muscles about the skeletons.  */
+  if (skeleton)
+    MUSCLE_INSERT_C_STRING ("skeleton", skeleton);
+  else
+    skeleton = language->skeleton;
 
-  /* About the skeletons. */
+  /* About the skeletons.  */
   {
     char const *pkgdatadir = getenv ("BISON_PKGDATADIR");
     /* b4_pkgdatadir is used inside m4_include in the skeletons, so digraphs
@@ -639,7 +636,6 @@ prepare (void)
        his Bison installation path.  */
     MUSCLE_INSERT_STRING_RAW ("pkgdatadir",
                               pkgdatadir ? pkgdatadir : PKGDATADIR);
-    MUSCLE_INSERT_C_STRING ("skeleton", skeleton);
   }
 }
 
