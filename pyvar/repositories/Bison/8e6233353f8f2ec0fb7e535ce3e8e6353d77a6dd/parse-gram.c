@@ -1121,7 +1121,7 @@ static void
 yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 {
   YYFPRINTF (yyo, "%s %s (",
-             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);
+             yytype < YYNTOKENS ? "token" : "nterm", yysymbol_name (yytype));
 
   YY_LOCATION_PRINT (yyo, *yylocationp);
   YYFPRINTF (yyo, ": ");
