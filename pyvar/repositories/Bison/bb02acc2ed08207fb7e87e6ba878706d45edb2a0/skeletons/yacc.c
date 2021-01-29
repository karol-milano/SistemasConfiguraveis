@@ -621,11 +621,7 @@ yysymbol_name (int yysymbol)
 {
   return yytname[yysymbol];
 }]],
-[[/* The user-facing name of the symbol whose (internal) number is
-   YYSYMBOL.  No bounds checking.  */
-static const char *yysymbol_name (int yysymbol) YY_ATTRIBUTE_UNUSED;
-
-static const char *
+[[static const char *
 yysymbol_name (int yysymbol)
 {
   static const char *const yy_sname[] =
