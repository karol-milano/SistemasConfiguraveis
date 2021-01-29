@@ -395,6 +395,13 @@ static const ]b4_int_type_for([b4_check])[ yycheck[] =
   ]b4_check[
 };
 
+/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
+   symbol of state STATE-NUM.  */
+static const ]b4_int_type_for([b4_stos])[ yystos[] =
+{
+  ]b4_stos[
+};
+
 
 /* Prevent warning if -Wmissing-prototypes.  */
 ]b4_c_ansi_function_decl([yyparse], [int], b4_parse_param)[
@@ -451,12 +458,25 @@ do {						\
   if (yydebug)					\
     YYFPRINTF Args;				\
 } while (0)
+
+]b4_yysymprint_generate([b4_c_ansi_function_def])[
+
+# define YYDSYMPRINT(Args)			\
+do {						\
+  if (yydebug)					\
+    yysymprint Args;				\
+} while (0)
+
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
 int yydebug;
+
 #else /* !YYDEBUG */
+
   /* Avoid empty `if' bodies.  */
-# define YYDPRINTF(Args)  {}
+# define YYDPRINTF(Args)   {}
+# define YYDSYMPRINT(Args) {}
+
 #endif /* !YYDEBUG */
 
 /* YYINITDEPTH -- initial size of the parser's stacks.  */
@@ -611,8 +631,6 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
       *yyvalp = yyvsp[1-yyrhslen].yystate.yysemantics.yysval;
       *yylocp = yyvsp[1-yyrhslen].yystate.yyloc;
     }
-# undef yyval
-# define yyval (*yyvalp)
 # undef yyerrok
 # define yyerrok (yystack->yyerrState = 0)
 # undef YYACCEPT
@@ -639,7 +657,6 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
      }
 
    return yyok;
-# undef yyval
 # undef yyerrok
 # undef YYABORT
 # undef YYACCEPT
@@ -669,6 +686,8 @@ yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 [
 			      /* Bison grammar-table manipulation.  */
 
+]b4_yydestruct_generate([b4_c_ansi_function_def])[
+
 /** Number of symbols composing the right hand side of rule #RULE. */
 static inline int
 yyrhsLength (yyRuleNum yyrule)
@@ -1621,10 +1640,31 @@ yyrecoverParseError (yyGLRStack* yystack,
     while (yytrue)
       {
 	if (*yytokenp == YYEOF)
-	  yyFail (yystack][]b4_lpure_args[, NULL);
+	  {
+	    /* Now pop stack until we find a state that shifts the
+	       error token.  */
+	    while (yystack->yytops.yystates[0] != NULL)
+	      {
+		yyGLRState *yys = yystack->yytops.yystates[0];
+		YYDPRINTF ((stderr, "Error: popping "));
+		YYDSYMPRINT ((stderr,
+			      yystos[yys->yylrState],
+			      &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[));
+		YYDPRINTF ((stderr, "\n"));
+		yydestruct (yystos[yys->yylrState],
+			    &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
+		yystack->yytops.yystates[0] = yys->yypred;
+		yystack->yynextFree -= 1;
+		yystack->yyspaceLeft += 1;
+	      }
+	    yyFail (yystack][]b4_lpure_args[, NULL);
+	  }
 	if (*yytokenp != YYEMPTY)
-	  YYDPRINTF ((stderr, "Discarding token %s\n",
-		      yytokenName (*yytokenp)));
+	  {
+	    YYDPRINTF ((stderr, "Discarding token %s\n",
+			yytokenName (*yytokenp)));
+	    yydestruct (*yytokenp, yylvalp]b4_location_if([, yyllocp])[);
+	  }
 	YYDPRINTF ((stderr, "Reading a token: "));
 	yychar = YYLEX;
 	*yytokenp = YYTRANSLATE (yychar);
@@ -1657,20 +1697,28 @@ yyrecoverParseError (yyGLRStack* yystack,
   /* Now pop stack until we find a state that shifts the error token. */
   while (yystack->yytops.yystates[0] != NULL)
     {
-      yyj = yypact[yystack->yytops.yystates[0]->yylrState];
+      yyGLRState *yys = yystack->yytops.yystates[0];
+      yyj = yypact[yys->yylrState];
       if (! yyis_pact_ninf (yyj))
 	{
 	  yyj += YYTERROR;
 	  if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
 	      && yyisShiftAction (yytable[yyj]))
 	    {
+	      YYDPRINTF ((stderr, "Shifting error token, "));
 	      yyglrShift (yystack, 0, yytable[yyj],
-			  yystack->yytops.yystates[0]->yyposn,
-			  *yylvalp, yyllocp]b4_user_args[);
+			  yys->yyposn, *yylvalp, yyllocp]b4_user_args[);
 	      break;
 	    }
 	}
-      yystack->yytops.yystates[0] = yystack->yytops.yystates[0]->yypred;
+      YYDPRINTF ((stderr, "Error: popping "));
+      YYDSYMPRINT ((stderr,
+ 		    yystos[yys->yylrState],
+ 		    &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[));
+      YYDPRINTF ((stderr, "\n"));
+      yydestruct (yystos[yys->yylrState],
+ 	          &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
+      yystack->yytops.yystates[0] = yys->yypred;
       yystack->yynextFree -= 1;
       yystack->yyspaceLeft += 1;
     }
