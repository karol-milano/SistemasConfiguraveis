@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.462-882b.  */
+/* A Bison parser, made by GNU Bison 2.4.483-4ad39-dirty.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.462-882b"
+#define YYBISON_VERSION "2.4.483-4ad39-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1688,7 +1688,7 @@ YYLTYPE yylloc;
     YYLTYPE *yylsp;
 
     /* The locations where the error started and ended.  */
-    YYLTYPE yyerror_range[2];
+    YYLTYPE yyerror_range[3];
 
     YYSIZE_T yystacksize;
 
@@ -2865,7 +2865,7 @@ yyerrlab:
 #endif
     }
 
-  yyerror_range[0] = yylloc;
+  yyerror_range[1] = yylloc;
 
   if (yyerrstatus == 3)
     {
@@ -2902,7 +2902,7 @@ yyerrorlab:
   if (/*CONSTCOND*/ 0)
      goto yyerrorlab;
 
-  yyerror_range[0] = yylsp[1-yylen];
+  yyerror_range[1] = yylsp[1-yylen];
   /* Do not reclaim the symbols of the rule which action triggered
      this YYERROR.  */
   YYPOPSTACK (yylen);
@@ -2936,7 +2936,7 @@ yyerrlab1:
       if (yyssp == yyss)
 	YYABORT;
 
-      yyerror_range[0] = *yylsp;
+      yyerror_range[1] = *yylsp;
       yydestruct ("Error: popping",
 		  yystos[yystate], yyvsp, yylsp);
       YYPOPSTACK (1);
@@ -2946,10 +2946,10 @@ yyerrlab1:
 
   *++yyvsp = yylval;
 
-  yyerror_range[1] = yylloc;
+  yyerror_range[2] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
      the lookahead.  YYLOC is available though.  */
-  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
+  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
   *++yylsp = yyloc;
 
   /* Shift the error token.  */
