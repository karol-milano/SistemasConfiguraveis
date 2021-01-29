@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.0.  */
+/* A Bison parser, made by GNU Bison 2.0a.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
@@ -251,7 +251,7 @@ typedef union YYSTYPE {
   assoc assoc;
   uniqstr uniqstr;
 } YYSTYPE;
-/* Line 190 of yacc.c.  */
+/* Line 191 of yacc.c.  */
 #line 256 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -275,7 +275,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 213 of yacc.c.  */
+/* Line 214 of yacc.c.  */
 #line 280 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
@@ -1147,7 +1147,7 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 842 of yacc.c.  */
+/* Line 843 of yacc.c.  */
 #line 1152 "parse-gram.c"
   yyvsp[0] = yylval;
     yylsp[0] = yylloc;
@@ -1732,10 +1732,11 @@ yyreduce:
     break;
 
 
+      default: break;
     }
 
-/* Line 1037 of yacc.c.  */
-#line 1739 "parse-gram.c"
+/* Line 1039 of yacc.c.  */
+#line 1740 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1870,12 +1871,11 @@ yyerrlab:
 `---------------------------------------------------*/
 yyerrorlab:
 
-#ifdef __GNUC__
-  /* Pacify GCC when the user code never invokes YYERROR and the label
-     yyerrorlab therefore never appears in user code.  */
+  /* Pacify compilers like GCC when the user code never invokes
+     YYERROR and the label yyerrorlab therefore never appears in user
+     code.  */
   if (0)
      goto yyerrorlab;
-#endif
 
   yyerror_range[0] = yylsp[1-yylen];
   yylsp -= yylen;
