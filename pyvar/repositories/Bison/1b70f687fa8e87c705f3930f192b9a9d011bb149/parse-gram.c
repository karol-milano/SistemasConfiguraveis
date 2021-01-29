@@ -1787,8 +1787,8 @@ YYLTYPE yylloc = yyloc_default;
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
-  boundary_set (&yylloc.start, current_file, 1, 1);
-  boundary_set (&yylloc.end, current_file, 1, 1);
+  boundary_set (&yylloc.start, current_file, 1, 1, 1);
+  boundary_set (&yylloc.end, current_file, 1, 1, 1);
 }
 
 
