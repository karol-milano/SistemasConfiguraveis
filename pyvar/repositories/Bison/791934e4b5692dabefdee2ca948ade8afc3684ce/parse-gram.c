@@ -2053,7 +2053,7 @@ yyreduce:
 
 /* Line 1269 of yacc.c  */
 #line 258 "parse-gram.y"
-    { push_parser = true; }
+    { push_parser = true; pure_parser = true; }
     break;
 
   case 29:
