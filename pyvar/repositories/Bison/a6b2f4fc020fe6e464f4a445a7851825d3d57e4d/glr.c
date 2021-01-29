@@ -1727,10 +1727,10 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
         {
           if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
             YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
-                       yytokenName (yystos[yystates[yyi-1]->yylrState]));
+                       yytokenName (yystos[yystates[yyi]->yylrState]));
           else
             YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
-                       yytokenName (yystos[yystates[yyi-1]->yylrState]),
+                       yytokenName (yystos[yystates[yyi]->yylrState]),
                        (unsigned long int) (yystates[yyi-1]->yyposn + 1),
                        (unsigned long int) yystates[yyi]->yyposn);
         }
