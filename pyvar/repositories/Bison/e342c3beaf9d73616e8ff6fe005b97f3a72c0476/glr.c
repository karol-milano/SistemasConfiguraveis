@@ -425,8 +425,6 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
    the previous symbol: RHS[0] (always defined).  */
 
 ]b4_location_if([[
-#define YYRHSLOC(yyRhs,YYK) ((yyRhs)[YYK].yystate.yyloc)
-
 #ifndef YYLLOC_DEFAULT
 # define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN)				\
 do {									\
@@ -614,6 +612,8 @@ union yyGLRStackItem {
 struct yyGLRStack {
   int yyerrflag;
   int yyerrState;
+]b4_location_if([[  /* To compute the location of the error token,  */
+  YYLTYPE yyerror_range[2];]])[
 ]b4_pure_if(
 [
   int yyerrcnt;
@@ -735,8 +735,9 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
     *yyvalp = yyval_default;
   else
     *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
+# define YYRHSLOC(yyRhs,YYK) ((yyRhs)[YYK].yystate.yyloc)
   YYLLOC_DEFAULT (*yylocp, yyvsp - yyrhslen, yyrhslen);
-
+# undef YYRHSLOC
 ]
   switch (yyn)
     {
@@ -1719,6 +1720,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    while (yystack->yytops.yystates[0] != NULL)
 	      {
 		yyGLRState *yys = yystack->yytops.yystates[0];
+]b4_location_if([[		yystack->yyerror_range[0] = yys->yyloc;]])[
 		yydestruct ("Error: popping",
                             yystos[yys->yylrState],
 			    &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
@@ -1729,8 +1731,15 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    yyFail (yystack][]b4_lpure_args[, NULL);
 	  }
 	if (*yytokenp != YYEMPTY)
-	  yydestruct ("Error: discarding",
-                      *yytokenp, yylvalp]b4_location_if([, yyllocp])[);
+	  {]b4_location_if([[
+	    /* We throw away the lookahead, but the error range
+	       of the shifted error token must take it into account. */
+	    yyGLRState *yys = yystack->yytops.yystates[0];
+	    yys->yyloc.last_line   = yyllocp->last_line;
+	    yys->yyloc.last_column = yyllocp->last_column;]])[
+	    yydestruct ("Error: discarding",
+			*yytokenp, yylvalp]b4_location_if([, yyllocp])[);
+	  }
 	YYDPRINTF ((stderr, "Reading a token: "));
 	yychar = YYLEX;
 	*yytokenp = YYTRANSLATE (yychar);
@@ -1771,13 +1780,21 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	  if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
 	      && yyisShiftAction (yytable[yyj]))
 	    {
+	      /* Shift the error token having adjusted its location.  */
+	      YYLTYPE yyerrloc;]b4_location_if([[
+	      yystack->yyerror_range[1] = *yyllocp;
+#             define YYRHSLOC(yyRhs,YYK) ((yyRhs)[YYK])
+	      YYLLOC_DEFAULT (yyerrloc, yystack->yyerror_range - 1, 2);
+#             undef YYRHSLOC]])[
 	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
-			       yylvalp, yyllocp);
+			       yylvalp, &yyerrloc);
 	      yyglrShift (yystack, 0, yytable[yyj],
-			  yys->yyposn, *yylvalp, yyllocp]b4_user_args[);
+			  yys->yyposn, *yylvalp, &yyerrloc]b4_user_args[);
+	      yys = yystack->yytops.yystates[0];
 	      break;
 	    }
 	}
+]b4_location_if([[      yystack->yyerror_range[0] = yys->yyloc;]])[
       yydestruct ("Error: popping",
 		  yystos[yys->yylrState],
 	          &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
@@ -1876,6 +1893,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	      yyrule = yydefaultAction (yystate);
 	      if (yyrule == 0)
 		{
+]b4_location_if([[		  yystack.yyerror_range[0] = *yyllocp;]])[
 		  yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 		  goto yyuser_error;
 		}
@@ -1906,6 +1924,8 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		}
 	      else if (yyisErrorAction (yyaction))
 		{
+		  yyGLRState *yys = yystack.yytops.yystates[0];
+]b4_location_if([[		  yystack.yyerror_range[0] = *yyllocp;]])[
 		  yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 		  goto yyuser_error;
 		}
@@ -1931,6 +1951,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		yyFail (&yystack][]b4_lpure_args[, "syntax error");
 	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
 	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
+]b4_location_if([[	      yystack.yyerror_range[0] = *yyllocp;]])[
 	      yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 	      goto yyuser_error;
 	    }
@@ -2066,7 +2087,7 @@ b4_location_if([
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
-b4_location_if([m4_if(b4_pure, [0],
+b4_location_if([b4_pure_if([],
 [extern YYLTYPE b4_prefix[]lloc;])
 ])
 ])
