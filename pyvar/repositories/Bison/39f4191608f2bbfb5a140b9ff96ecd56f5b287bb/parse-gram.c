@@ -236,7 +236,7 @@ typedef union {
   char *string;
   associativity assoc;
 } yystype;
-/* Line 272 of /home/lrde/prof/akim/src/bison/data/yacc.c.  */
+/* Line 272 of /usr/local/share/bison/yacc.c.  */
 #line 241 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
@@ -257,7 +257,7 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line 292 of /home/lrde/prof/akim/src/bison/data/yacc.c.  */
+/* Line 292 of /usr/local/share/bison/yacc.c.  */
 #line 262 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
@@ -1479,7 +1479,7 @@ yyreduce:
 
   case 67:
 #line 371 "parse-gram.y"
-    { yyval.symbol = getsym (yyvsp[0].string, yylsp[0]); }
+    { yyval.symbol = symbol_get (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 68:
@@ -1490,7 +1490,7 @@ yyreduce:
   case 69:
 #line 382 "parse-gram.y"
     {
-      yyval.symbol = getsym (yyvsp[0].string, yylsp[0]);
+      yyval.symbol = symbol_get (yyvsp[0].string, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
     }
     break;
@@ -1520,7 +1520,7 @@ yyreduce:
 
     }
 
-/* Line 1040 of /home/lrde/prof/akim/src/bison/data/yacc.c.  */
+/* Line 1040 of /usr/local/share/bison/yacc.c.  */
 #line 1525 "parse-gram.c"
 
   yyvsp -= yylen;
