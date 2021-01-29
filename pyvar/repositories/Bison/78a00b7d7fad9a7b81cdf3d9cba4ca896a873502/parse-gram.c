@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 1.75e.  */
+/* A Bison parser, made by GNU Bison 1.75f.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
@@ -221,7 +221,7 @@ typedef union YYSTYPE {
   assoc assoc;
   uniqstr uniqstr;
 } YYSTYPE;
-/* Line 192 of yacc.c.  */
+/* Line 191 of yacc.c.  */
 #line 225 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -245,7 +245,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 215 of yacc.c.  */
+/* Line 214 of yacc.c.  */
 #line 249 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
@@ -1032,6 +1032,7 @@ YYLTYPE yylloc;
   YYLTYPE yylsa[YYINITDEPTH];
   YYLTYPE *yyls = yylsa;
   YYLTYPE *yylsp;
+  YYLTYPE *yylerrsp;
 
 #define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
 
@@ -1334,7 +1335,7 @@ yyreduce:
 
   case 23:
 #line 192 "parse-gram.y"
-    { report_flag = 1; }
+    { report_flag = report_states; }
     break;
 
   case 24:
@@ -1610,7 +1611,7 @@ yyreduce:
     }
 
 /* Line 991 of yacc.c.  */
-#line 1613 "parse-gram.c"
+#line 1614 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1694,6 +1695,8 @@ yyerrlab:
 	yyerror ("syntax error");
     }
 
+  yylerrsp = yylsp;
+
   if (yyerrstatus == 3)
     {
       /* If just tried and failed to reuse lookahead token after an
@@ -1717,17 +1720,34 @@ yyerrlab:
       YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
       yydestruct (yytoken, &yylval, &yylloc);
       yychar = YYEMPTY;
+      *++yylerrsp = yylloc;
     }
 
   /* Else will try to reuse lookahead token after shifting the error
      token.  */
-  goto yyerrlab1;
+  goto yyerrlab2;
 
 
 /*----------------------------------------------------.
 | yyerrlab1 -- error raised explicitly by an action.  |
 `----------------------------------------------------*/
 yyerrlab1:
+
+  /* Suppress GCC warning that yyerrlab1 is unused when no action
+     invokes YYERROR.  */
+#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
+  __attribute__ ((__unused__))
+#endif
+
+  yylerrsp = yylsp;
+  *++yylerrsp = yyloc;
+  goto yyerrlab2;
+
+
+/*---------------------------------------------------------------.
+| yyerrlab2 -- pop states until the error token can be shifted.  |
+`---------------------------------------------------------------*/
+yyerrlab2:
   yyerrstatus = 3;	/* Each real token shifted decrements this.  */
 
   for (;;)
@@ -1762,7 +1782,8 @@ yyerrlab1:
   YYDPRINTF ((stderr, "Shifting error token, "));
 
   *++yyvsp = yylval;
-  *++yylsp = yylloc;
+  YYLLOC_DEFAULT (yyloc, yylsp, (yylerrsp - yylsp));
+  *++yylsp = yyloc;
 
   yystate = yyn;
   goto yynewstate;
