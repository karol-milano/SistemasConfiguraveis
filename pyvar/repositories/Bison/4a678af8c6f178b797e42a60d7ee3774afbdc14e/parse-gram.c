@@ -1584,8 +1584,8 @@ YYLTYPE yylloc;
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
-  boundary_set (&yylloc.start, current_file, 1, 0);
-  boundary_set (&yylloc.end, current_file, 1, 0);
+  boundary_set (&yylloc.start, current_file, 1, 1);
+  boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1085 of yacc.c.  */
 #line 1592 "parse-gram.c"
