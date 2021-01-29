@@ -1741,7 +1741,7 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
   int yynrhs = yyrhsLength (yyx->yyrule);
   int yyi;
   yyGLRState* yys;
-  yyGLRState* yystates[YYMAXRHS];
+  yyGLRState* yystates[1 + YYMAXRHS];
   yyGLRState yyleftmost_state;
 
   for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
@@ -1757,11 +1757,11 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
   if (yyx->yystate->yyposn < yys->yyposn + 1)
     YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
 	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
-	       yyx->yyrule);
+	       yyx->yyrule - 1);
   else
     YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
 	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
-	       yyx->yyrule, (unsigned long int) (yys->yyposn + 1),
+	       yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
 	       (unsigned long int) yyx->yystate->yyposn);
   for (yyi = 1; yyi <= yynrhs; yyi += 1)
     {
@@ -2578,7 +2578,7 @@ yypdumpstack (yyGLRStack* yystackp)
       else
 	{
 	  fprintf (stderr, "Option. rule: %d, state: %ld, next: %ld",
-		   yyp->yyoption.yyrule,
+		   yyp->yyoption.yyrule - 1,
 		   (long int) YYINDEX (yyp->yyoption.yystate),
 		   (long int) YYINDEX (yyp->yyoption.yynext));
 	}
