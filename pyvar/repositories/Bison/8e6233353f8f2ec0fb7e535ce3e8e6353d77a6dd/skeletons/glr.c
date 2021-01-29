@@ -693,7 +693,7 @@ yyMemoryExhausted (yyGLRStack* yystackp)
 #if ]b4_error_verbose_if([[1]], [b4_api_PREFIX[DEBUG]])[
 /** A printable representation of TOKEN.  */
 static inline const char*
-yytokenName (yySymbol yytoken)
+yysymbol_name (yySymbol yytoken)
 {
   return yytoken == YYEMPTY ? "" : yytname[yytoken];
 }
@@ -1738,11 +1738,11 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
 
   if (yyx->yystate->yyposn < yys->yyposn + 1)
     YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
-                 yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
+                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                  yyx->yyrule - 1));
   else
     YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
-                 yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
+                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                  yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                  YY_CAST (long, yyx->yystate->yyposn)));
   for (yyi = 1; yyi <= yynrhs; yyi += 1)
@@ -1751,10 +1751,10 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
         {
           if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
             YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
-                         yytokenName (yystos[yystates[yyi]->yylrState])));
+                         yysymbol_name (yystos[yystates[yyi]->yylrState])));
           else
             YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
-                         yytokenName (yystos[yystates[yyi]->yylrState]),
+                         yysymbol_name (yystos[yystates[yyi]->yylrState]),
                          YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                          YY_CAST (long, yystates[yyi]->yyposn)));
         }
@@ -2111,7 +2111,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   if (yytoken != YYEMPTY)
     {
       int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
-      yyarg[yycount++] = yytokenName (yytoken);
+      yyarg[yycount++] = yysymbol_name (yytoken);
       if (!yypact_value_is_default (yyn))
         {
           /* Start YYX at -YYN if negative to avoid negative indexes in
@@ -2131,7 +2131,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
                     yycount = 1;
                     break;
                   }
-                yyarg[yycount++] = yytokenName (yyx);
+                yyarg[yycount++] = yysymbol_name (yyx);
               }
         }
     }
