@@ -808,6 +808,7 @@ yyuserAction (yyRuleNum yyn, size_t yyrhslen, yyGLRStackItem* yyvsp,
     *yyvalp = yyval_default;
   else
     *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;]b4_locations_if([[
+  /* Default location. */
   YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
   yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
 ]])[
@@ -2305,8 +2306,8 @@ b4_dollar_popdef])[]dnl
             {
               yyrule = yydefaultAction (yystate);
               if (yyrule == 0)
-                {
-]b4_locations_if([[               yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+                {]b4_locations_if([[
+                  yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
                   yyreportSyntaxError (&yystack]b4_user_args[);
                   goto yyuser_error;
                 }
@@ -2345,8 +2346,8 @@ b4_dollar_popdef])[]dnl
                     yystack.yyerrState -= 1;
                 }
               else if (yyisErrorAction (yyaction))
-                {
-]b4_locations_if([[               yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+                {]b4_locations_if([[
+                  yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
                   yyreportSyntaxError (&yystack]b4_user_args[);
                   goto yyuser_error;
                 }
@@ -2391,8 +2392,8 @@ b4_dollar_popdef])[]dnl
               if (yystack.yytops.yysize == 0)
                 yyFail (&yystack][]b4_lpure_args[, YY_("syntax error"));
               YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
-              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
-]b4_locations_if([[           yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));]b4_locations_if([[
+              yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
               yyreportSyntaxError (&yystack]b4_user_args[);
               goto yyuser_error;
             }
@@ -2473,9 +2474,9 @@ b4_dollar_popdef])[]dnl
               {
                 while (yystates[yyk])
                   {
-                    yyGLRState *yys = yystates[yyk];
-]b4_locations_if([[                 yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
-)[                  if (yys->yypred != YY_NULLPTR)
+                    yyGLRState *yys = yystates[yyk];]b4_locations_if([[
+                    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
+                    if (yys->yypred != YY_NULLPTR)
                       yydestroyGLRState ("Cleanup: popping", yys]b4_user_args[);
                     yystates[yyk] = yys->yypred;
                     yystack.yynextFree -= 1;
