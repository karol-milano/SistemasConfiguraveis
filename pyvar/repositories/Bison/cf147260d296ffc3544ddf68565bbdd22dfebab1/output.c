@@ -616,8 +616,12 @@ prepare (void)
 	skeleton = "yacc.c";
     }
 
-  /* Parse the skeleton file and output the needed parsers.  */
-  MUSCLE_INSERT_C_STRING ("skeleton", skeleton);
+  /* About the skeletons. */
+  {
+    char const* p = getenv ("BISON_PKGDATADIR");
+    MUSCLE_INSERT_STRING ("pkgdatadir", p ? p : PKGDATADIR);
+    MUSCLE_INSERT_C_STRING ("skeleton", skeleton);
+  }
 }
 
 
