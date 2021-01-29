@@ -1343,9 +1343,9 @@ yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, size_t yyk,
   int yynrhs = yyrhsLength (yyrule);]b4_locations_if([
   int yylow = 1;])[
   int yyi;
-  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
+  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %d):\n",
              (unsigned long) yyk, yyrule - 1,
-             (unsigned long) yyrline[yyrule]);
+             yyrline[yyrule]);
   if (! yynormal)
     yyfillin (yyvsp, 1, -yynrhs);
   /* The symbols being reduced.  */
@@ -2253,14 +2253,15 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
           if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
               && yyisShiftAction (yytable[yyj]))
             {
-              /* Shift the error token.  */]b4_locations_if([[
+              /* Shift the error token.  */
+              int yyaction = yytable[yyj];]b4_locations_if([[
               /* First adjust its location.*/
               YYLTYPE yyerrloc;
               yystackp->yyerror_range[2].yystate.yyloc = yylloc;
               YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);]])[
-              YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
+              YY_SYMBOL_PRINT ("Shifting", yystos[yyaction],
                                &yylval, &yyerrloc);
-              yyglrShift (yystackp, 0, yytable[yyj],
+              yyglrShift (yystackp, 0, yyaction,
                           yys->yyposn, &yylval]b4_locations_if([, &yyerrloc])[);
               yys = yystackp->yytops.yystates[0];
               break;
