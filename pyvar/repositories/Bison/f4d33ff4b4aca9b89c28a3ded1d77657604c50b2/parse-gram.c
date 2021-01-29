@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.7.2.43-1ae84.  */
+/* A Bison parser, made by GNU Bison 3.7.2.67-44c6.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -49,7 +49,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.7.2.43-1ae84"
+#define YYBISON_VERSION "3.7.2.67-44c6"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1844,6 +1844,7 @@ YYLTYPE yylloc = yyloc_default;
 
   yychar = GRAM_EMPTY; /* Cause a token to be read.  */
 
+
 /* User initialization code.  */
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1945,6 +1946,7 @@ yysetstate:
     }
 #endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */
 
+
   if (yystate == YYFINAL)
     YYACCEPT;
 
@@ -2008,8 +2010,8 @@ yybackup:
     {
       if (yytable_value_is_error (yyn))
         goto yyerrlab;
-      YY_LAC_ESTABLISH;
       yyn = -yyn;
+      YY_LAC_ESTABLISH;
       goto yyreduce;
     }
 
@@ -2709,6 +2711,7 @@ yyerrorlab:
      label yyerrorlab therefore never appears in user code.  */
   if (0)
     YYERROR;
+  ++yynerrs;
 
   /* Do not reclaim the symbols of the rule whose action triggered
      this YYERROR.  */
