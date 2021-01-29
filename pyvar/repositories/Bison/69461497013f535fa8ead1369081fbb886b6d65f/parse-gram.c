@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.5.1.3-1587-dirty.  */
+/* A Bison parser, made by GNU Bison 3.5.1.123-b0950.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.5.1.3-1587-dirty"
+#define YYBISON_VERSION "3.5.1.123-b0950"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -526,10 +526,6 @@ static const yytype_int16 yyrline[] =
    YYSYMBOL.  No bounds checking.  */
 static const char *yysymbol_name (int yysymbol) YY_ATTRIBUTE_UNUSED;
 
-/* The user-facing name of the symbol whose (internal) number is
-   YYSYMBOL.  No bounds checking.  */
-static const char *yysymbol_name (int yysymbol) YY_ATTRIBUTE_UNUSED;
-
 static const char *
 yysymbol_name (int yysymbol)
 {
@@ -1764,6 +1760,7 @@ yysetstate:
   YY_IGNORE_USELESS_CAST_BEGIN
   *yyssp = YY_CAST (yy_state_t, yystate);
   YY_IGNORE_USELESS_CAST_END
+  YY_STACK_PRINT (yyss, yyssp);
 
   if (yyss + yystacksize - 1 <= yyssp)
 #if !defined yyoverflow && !defined YYSTACK_RELOCATE
@@ -1856,7 +1853,7 @@ yybackup:
   /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
   if (yychar == YYEMPTY)
     {
-      YYDPRINTF ((stderr, "Reading a token: "));
+      YYDPRINTF ((stderr, "Reading a token\n"));
       yychar = yylex (&yylval, &yylloc);
     }
 
@@ -2508,7 +2505,6 @@ yyreduce:
 
   YYPOPSTACK (yylen);
   yylen = 0;
-  YY_STACK_PRINT (yyss, yyssp);
 
   *++yyvsp = yyval;
   *++yylsp = yyloc;
