@@ -923,7 +923,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
     *yyvalp = yyval_default;
   else
     *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
-  YYLLOC_DEFAULT (*yylocp, yyvsp - yyrhslen, yyrhslen);
+  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
 ]b4_location_if([[  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
 ]])[
   switch (yyn)
@@ -2119,7 +2119,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	    yyGLRStackItem yyerror_range[3];
 	    yyerror_range[1].yystate.yyloc = yys->yyloc;
 	    yyerror_range[2].yystate.yyloc = yylloc;
-	    YYLLOC_DEFAULT (yys->yyloc, yyerror_range, 2);]])[
+	    YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);]])[
 	    yydestruct ("Error: discarding",
 			*yytokenp, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
 	  }
@@ -2166,7 +2166,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	      /* Shift the error token having adjusted its location.  */
 	      YYLTYPE yyerrloc;]b4_location_if([[
 	      yystackp->yyerror_range[2].yystate.yyloc = yylloc;
-	      YYLLOC_DEFAULT (yyerrloc, yystackp->yyerror_range, 2);]])[
+	      YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);]])[
 	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
 			       &yylval, &yyerrloc);
 	      yyglrShift (yystackp, 0, yytable[yyj],
