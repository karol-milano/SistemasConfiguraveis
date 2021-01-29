@@ -308,7 +308,7 @@ static int current_prec = 0;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 191 of yacc.c  */
+/* Line 198 of yacc.c  */
 #line 97 "parse-gram.y"
 
   symbol *symbol;
@@ -321,7 +321,7 @@ typedef union YYSTYPE
   unsigned char character;
 }
 
-/* Line 191 of yacc.c  */
+/* Line 198 of yacc.c  */
 #line 326 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -1698,7 +1698,7 @@ YYLTYPE yylloc;
 
   /* User initialization code.  */
   
-/* Line 1076 of yacc.c  */
+/* Line 1082 of yacc.c  */
 #line 89 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1707,7 +1707,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1076 of yacc.c  */
+/* Line 1082 of yacc.c  */
 #line 1712 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
@@ -2064,7 +2064,7 @@ yyreduce:
 
 /* Line 1269 of yacc.c  */
 #line 260 "parse-gram.y"
-    { push_parser = true; pure_parser = true; }
+    { push_parser = true; }
     break;
 
   case 30:
