@@ -626,11 +626,7 @@ yysymbol_name (yySymbol yysymbol)
 {
   return yytname[yysymbol];
 }]],
-[[/* The user-facing name of the symbol whose (internal) number is
-   YYSYMBOL.  No bounds checking.  */
-static const char *yysymbol_name (yySymbol yysymbol) YY_ATTRIBUTE_UNUSED;
-
-static const char *
+[[static const char *
 yysymbol_name (yySymbol yysymbol)
 {
   static const char *const yy_sname[] =
