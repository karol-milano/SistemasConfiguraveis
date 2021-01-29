@@ -52,7 +52,7 @@ m4_define([b4_user_formals],
 # Yes, this is quite ugly...
 m4_define([b4_lex_param],
 m4_dquote(b4_pure_if([[[[YYSTYPE *]], [[&yylval]]][]dnl
-b4_location_if([, [[YYLTYPE *], [&yylloc]]])])dnl
+b4_locations_if([, [[YYLTYPE *], [&yylloc]]])])dnl
 m4_ifdef([b4_lex_param], [, ]b4_lex_param)))
 
 
@@ -61,7 +61,7 @@ m4_ifdef([b4_lex_param], [, ]b4_lex_param)))
 # Optional effective arguments passed to yyerror: user args plus yylloc, and
 # a trailing comma.
 m4_define([b4_yyerror_args],
-[b4_pure_if([b4_location_if([yylocp, ])])dnl
+[b4_pure_if([b4_locations_if([yylocp, ])])dnl
 m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 
 
@@ -69,7 +69,7 @@ m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 # ----------------
 # Same as above, but on the look-ahead, hence &yylloc instead of yylocp.
 m4_define([b4_lyyerror_args],
-[b4_pure_if([b4_location_if([&yylloc, ])])dnl
+[b4_pure_if([b4_locations_if([&yylloc, ])])dnl
 m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 
 
@@ -77,21 +77,21 @@ m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 # ------------
 # Same as b4_yyerror_args, but with a leading comma.
 m4_define([b4_pure_args],
-[b4_pure_if([b4_location_if([, yylocp])])[]b4_user_args])
+[b4_pure_if([b4_locations_if([, yylocp])])[]b4_user_args])
 
 
 # b4_lpure_args
 # -------------
 # Same as above, but on the look-ahead, hence &yylloc instead of yylocp.
 m4_define([b4_lpure_args],
-[b4_pure_if([b4_location_if([, &yylloc])])[]b4_user_args])
+[b4_pure_if([b4_locations_if([, &yylloc])])[]b4_user_args])
 
 
 # b4_pure_formals
 # ---------------
 # Arguments passed to yyerror: user formals plus yylocp.
 m4_define([b4_pure_formals],
-[b4_pure_if([b4_location_if([, YYLTYPE *yylocp])])[]b4_user_formals])
+[b4_pure_if([b4_locations_if([, YYLTYPE *yylocp])])[]b4_user_formals])
 
 
 ## ----------------- ##
@@ -186,7 +186,7 @@ b4_syncline([@oline@], [@ofile@])
 #if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
 typedef struct YYLTYPE
 {
-]b4_location_if([
+]b4_locations_if([
   int first_line;
   int first_column;
   int last_line;
@@ -200,13 +200,12 @@ typedef struct YYLTYPE
 #endif
 ]])
 
-m4_if(b4_defines_flag, 0,
-      [b4_shared_declarations],
-      [#include @output_header_name@])[
+b4_defines_if([#include @output_header_name@],
+              [b4_shared_declarations])[
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
-# define YYDEBUG ]b4_debug[
+# define YYDEBUG ]b4_debug_flag[
 #endif
 
 /* Enabling verbose error messages.  */
@@ -214,7 +213,7 @@ m4_if(b4_defines_flag, 0,
 # undef YYERROR_VERBOSE
 # define YYERROR_VERBOSE 1
 #else
-# define YYERROR_VERBOSE ]b4_error_verbose[
+# define YYERROR_VERBOSE ]b4_error_verbose_flag[
 #endif
 
 /* Enabling the token table.  */
@@ -308,7 +307,7 @@ b4_syncline([@oline@], [@ofile@])
 # endif
 #endif
 
-]b4_location_if([#define YYOPTIONAL_LOC(Name) Name],[
+]b4_locations_if([#define YYOPTIONAL_LOC(Name) Name],[
 #ifdef __cplusplus
 # define YYOPTIONAL_LOC(Name) /* empty */
 #else
@@ -486,7 +485,7 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
    If N is 0, then set CURRENT to the empty location which ends
    the previous symbol: RHS[0] (always defined).  */
 
-]b4_location_if([[
+]b4_locations_if([[
 #define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)
 #ifndef YYLLOC_DEFAULT
 # define YYLLOC_DEFAULT(Current, Rhs, N)				\
@@ -581,7 +580,7 @@ do {									    \
     {									    \
       YYFPRINTF (stderr, "%s ", Title);					    \
       yy_symbol_print (stderr, Type,					    \
-		       Value]b4_location_if([, Location])[]b4_user_args[);  \
+		       Value]b4_locations_if([, Location])[]b4_user_args[);  \
       YYFPRINTF (stderr, "\n");						    \
     }									    \
 } while (YYID (0))
@@ -622,7 +621,7 @@ int yydebug;
 
 #ifndef YYSTACKEXPANDABLE
 # if (! defined __cplusplus \
-      || (]b4_location_if([[defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
+      || (]b4_locations_if([[defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
 	  && ]])[defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL))
 #  define YYSTACKEXPANDABLE 1
 # else
@@ -794,7 +793,7 @@ union yyGLRStackItem {
 
 struct yyGLRStack {
   int yyerrState;
-]b4_location_if([[  /* To compute the location of the error token.  */
+]b4_locations_if([[  /* To compute the location of the error token.  */
   yyGLRStackItem yyerror_range[3];]])[
 ]b4_pure_if(
 [
@@ -923,7 +922,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   else
     *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
   YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
-]b4_location_if([[  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
+]b4_locations_if([[  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
 ]])[
   switch (yyn)
     {
@@ -973,7 +972,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 {
   if (yys->yyresolved)
     yydestruct (yymsg, yystos[yys->yylrState],
-		&yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[]b4_user_args[);
+		&yys->yysemantics.yysval]b4_locations_if([, &yys->yyloc])[]b4_user_args[);
   else
     {
 #if YYDEBUG
@@ -984,7 +983,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 	  else
 	    YYFPRINTF (stderr, "%s incomplete ", yymsg);
 	  yy_symbol_print (stderr, yystos[yys->yylrState],
-			   NULL]b4_location_if([, &yys->yyloc])[]b4_user_args[);
+			   NULL]b4_locations_if([, &yys->yyloc])[]b4_user_args[);
 	  YYFPRINTF (stderr, "\n");
 	}
 #endif
@@ -1392,7 +1391,7 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       yyGLRState* yys;
       yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
       yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
-	= yystackp->yytops.yystates[yyk];]b4_location_if([[
+	= yystackp->yytops.yystates[yyk];]b4_locations_if([[
       if (yynrhs == 0)
 	/* Set default location.  */
 	yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;]])[
@@ -1443,7 +1442,7 @@ yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       fprintf (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
 		       &]b4_rhs_value(yynrhs, yyi + 1)[
-		       ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
+		       ]b4_locations_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
 		       b4_user_args[);
       fprintf (stderr, "\n");
     }
@@ -1716,7 +1715,7 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
       return yyflag;
     }
 
-  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;]b4_location_if([[
+  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;]b4_locations_if([[
   if (yynrhs == 0)
     /* Set default location.  */
     yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;]])[
@@ -1929,7 +1928,7 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
 		  {
 		    yydestruct ("Cleanup: discarding incompletely merged value for",
 				yystos[yys->yylrState],
-				&yysval]b4_location_if([, yylocp])[]b4_user_args[);
+				&yysval]b4_locations_if([, yylocp])[]b4_user_args[);
 		    break;
 		  }
 		yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
@@ -2189,7 +2188,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	if (yychar == YYEOF)
 	  yyFail (yystackp][]b4_lpure_args[, NULL);
 	if (yychar != YYEMPTY)
-	  {]b4_location_if([[
+	  {]b4_locations_if([[
 	    /* We throw away the lookahead, but the error range
 	       of the shifted error token must take it into account.  */
 	    yyGLRState *yys = yystackp->yytops.yystates[0];
@@ -2199,7 +2198,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	    YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);]])[
 	    yytoken = YYTRANSLATE (yychar);
 	    yydestruct ("Error: discarding",
-			yytoken, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
+			yytoken, &yylval]b4_locations_if([, &yylloc])[]b4_user_args[);
 	  }
 	YYDPRINTF ((stderr, "Reading a token: "));
 	yychar = YYLEX;
@@ -2242,7 +2241,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	      && yyisShiftAction (yytable[yyj]))
 	    {
 	      /* Shift the error token having adjusted its location.  */
-	      YYLTYPE yyerrloc;]b4_location_if([[
+	      YYLTYPE yyerrloc;]b4_locations_if([[
 	      yystackp->yyerror_range[2].yystate.yyloc = yylloc;
 	      YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);]])[
 	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
@@ -2253,7 +2252,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	      break;
 	    }
 	}
-]b4_location_if([[      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
+]b4_locations_if([[      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
       yydestroyGLRState ("Error: popping", yys]b4_user_args[);
       yystackp->yytops.yystates[0] = yys->yypred;
       yystackp->yynextFree -= 1;
@@ -2295,7 +2294,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 
   yychar = YYEMPTY;
   yylval = yyval_default;
-]b4_location_if([
+]b4_locations_if([
 #if YYLTYPE_IS_TRIVIAL
   yylloc.first_line   = yylloc.last_line   = 1;
   yylloc.first_column = yylloc.last_column = 0;
@@ -2344,7 +2343,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	      yyrule = yydefaultAction (yystate);
 	      if (yyrule == 0)
 		{
-]b4_location_if([[		  yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+]b4_locations_if([[		  yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
 		  yyreportSyntaxError (&yystack]b4_user_args[);
 		  goto yyuser_error;
 		}
@@ -2377,7 +2376,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		}
 	      else if (yyisErrorAction (yyaction))
 		{
-]b4_location_if([[		  yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+]b4_locations_if([[		  yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
 		  yyreportSyntaxError (&yystack]b4_user_args[);
 		  goto yyuser_error;
 		}
@@ -2423,7 +2422,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		yyFail (&yystack][]b4_lpure_args[, YY_("syntax error"));
 	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
 	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
-]b4_location_if([[	      yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+]b4_locations_if([[	      yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
 	      yyreportSyntaxError (&yystack]b4_user_args[);
 	      goto yyuser_error;
 	    }
@@ -2488,7 +2487,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
   if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
 		YYTRANSLATE (yychar),
-		&yylval]b4_location_if([, &yylloc])[]b4_user_args[);
+		&yylval]b4_locations_if([, &yylloc])[]b4_user_args[);
 
   /* If the stack is well-formed, pop the stack until it is empty,
      destroying its entries as we go.  But free the stack regardless
@@ -2506,7 +2505,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		while (yystates[yyk])
 		  {
 		    yyGLRState *yys = yystates[yyk];
-]b4_location_if([[		    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
+]b4_locations_if([[		    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
 )[		    yydestroyGLRState ("Cleanup: popping", yys]b4_user_args[);
 		    yystates[yyk] = yys->yypred;
 		    yystack.yynextFree -= 1;
@@ -2595,7 +2594,7 @@ yypdumpstack (yyGLRStack* yystackp)
 ]
 
 b4_epilogue
-m4_if(b4_defines_flag, 0, [],
+b4_defines_if(
 [@output @output_header_name@
 b4_copyright([Skeleton interface for Bison GLR parsers in C],
   [2002, 2003, 2004, 2005, 2006])
@@ -2604,7 +2603,7 @@ b4_shared_declarations
 
 extern YYSTYPE b4_prefix[]lval;
 
-b4_location_if([b4_pure_if([],
+b4_locations_if([b4_pure_if([],
 [extern YYLTYPE b4_prefix[]lloc;])
 ])
 ])
