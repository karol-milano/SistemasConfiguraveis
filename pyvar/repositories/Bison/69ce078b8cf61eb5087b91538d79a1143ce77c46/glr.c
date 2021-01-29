@@ -507,8 +507,8 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 
 # define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
-             (Loc).first_line, (Loc).first_column,	\
-             (Loc).last_line,  (Loc).last_column)
+	     (Loc).first_line, (Loc).first_column,	\
+	     (Loc).last_line,  (Loc).last_column)
 #endif
 ]],[
 #ifndef YYLLOC_DEFAULT
@@ -566,7 +566,7 @@ do {									    \
     {									    \
       YYFPRINTF (stderr, "%s ", Title);					    \
       yysymprint (stderr,						    \
-                  Type, Value]b4_location_if([, Location])[]b4_user_args[); \
+		  Type, Value]b4_location_if([, Location])[]b4_user_args[); \
       YYFPRINTF (stderr, "\n");						    \
     }									    \
 } while (/*CONSTCOND*/ 0)
@@ -867,7 +867,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 	      YYSTYPE* yyvalp,
 	      YYLTYPE* YYOPTIONAL_LOC (yylocp),
 	      yyGLRStack* yystack
-              ]b4_user_formals[)
+	      ]b4_user_formals[)
 {
   yybool yynormal __attribute__ ((__unused__)) =
     (yystack->yysplitPoint == NULL);
@@ -962,15 +962,15 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 #endif
 
       if (yys->yysemantics.yyfirstVal)
-        {
-          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
-          yyGLRState *yyrh;
-          int yyn;
-          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
-               yyn > 0;
-               yyrh = yyrh->yypred, yyn -= 1)
-            yydestroyGLRState (yymsg, yyrh]b4_user_args[);
-        }
+	{
+	  yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
+	  yyGLRState *yyrh;
+	  int yyn;
+	  for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
+	       yyn > 0;
+	       yyrh = yyrh->yypred, yyn -= 1)
+	    yydestroyGLRState (yymsg, yyrh]b4_user_args[);
+	}
     }
 }
 
@@ -1016,7 +1016,7 @@ yydefaultAction (yyStateNum yystate)
  */
 static inline void
 yygetLRActions (yyStateNum yystate, int yytoken,
-	        int* yyaction, const short int** yyconflicts)
+		int* yyaction, const short int** yyconflicts)
 {
   int yyindex = yypact[yystate] + yytoken;
   if (yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
@@ -1340,7 +1340,7 @@ yydoAction (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 	= yystack->yytops.yystates[yyk];]b4_location_if([[
       if (yynrhs == 0)
 	/* Set default location. */
-        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;]])[
+	yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;]])[
       for (yyi = 0; yyi < yynrhs; yyi += 1)
 	{
 	  yys = yys->yypred;
@@ -1387,9 +1387,9 @@ yy_reduce_print (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
     {
       fprintf (stderr, "   $%d = ", yyi + 1);
       yysymprint (stderr, yyrhs[yyprhs[yyrule] + yyi],
-                  &]b4_rhs_value(yynrhs, yyi + 1)[
-                  ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
-	          b4_user_args[);
+		  &]b4_rhs_value(yynrhs, yyi + 1)[
+		  ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
+		  b4_user_args[);
       fprintf (stderr, "\n");
     }
 }
@@ -1408,7 +1408,7 @@ yy_reduce_print (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
  */
 static inline YYRESULTTAG
 yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
-             yybool yyforceEval]b4_user_formals[)
+	     yybool yyforceEval]b4_user_formals[)
 {
   size_t yyposn = yystack->yytops.yystates[yyk]->yyposn;
 
@@ -1623,7 +1623,7 @@ yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack]b4_user_formals[)
 
 static YYRESULTTAG
 yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
-	         YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
+		 YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
   yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
   int yynrhs;
@@ -1748,7 +1748,7 @@ yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
 	      break;
 	    default:
 	      /* This cannot happen so it is not worth a YYASSERT (yyfalse),
-	         but some compilers complain if the default case is
+		 but some compilers complain if the default case is
 		 omitted.  */
 	      break;
 	    }
@@ -1827,7 +1827,7 @@ yycompressStack (yyGLRStack* yystack)
 
 static YYRESULTTAG
 yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
-	           size_t yyposn, YYSTYPE* yylvalp, YYLTYPE* yyllocp
+		   size_t yyposn, YYSTYPE* yylvalp, YYLTYPE* yyllocp
 		  ]b4_pure_formals[)
 {
   int yyaction;
@@ -1880,16 +1880,7 @@ yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
 	    }
 
 	  if (yyisShiftAction (yyaction))
-	    {
-	      YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yyk));
-	      YY_SYMBOL_PRINT ("shifting", *yytokenp, yylvalp, yyllocp);
-	      yyglrShift (yystack, yyk, yyaction, yyposn+1,
-			  *yylvalp, yyllocp);
-	      YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
-			  (unsigned long int) yyk,
-			  yystack->yytops.yystates[yyk]->yylrState));
-	      break;
-	    }
+	    break;
 	  else if (yyisErrorAction (yyaction))
 	    {
 	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
@@ -2187,7 +2178,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	  const short int* yyconflicts;
 
 	  yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
-          YYDPRINTF ((stderr, "Entering state %d\n", yystate));
+	  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
 	  if (yystate == YYFINAL)
 	    goto yyacceptlab;
 	  if (yyisDefaultedState (yystate))
@@ -2208,7 +2199,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		  YYDPRINTF ((stderr, "Reading a token: "));
 		  yychar = YYLEX;
 		  yytoken = YYTRANSLATE (yychar);
-                  YY_SYMBOL_PRINT ("Next token is", yytoken, yylvalp, yyllocp);
+		  YY_SYMBOL_PRINT ("Next token is", yytoken, yylvalp, yyllocp);
 		}
 	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
 	      if (*yyconflicts != 0)
@@ -2236,14 +2227,59 @@ b4_syncline([@oline@], [@ofile@])])dnl
 
       while (yytrue)
 	{
+	  yySymbol yytoken_to_shift;
 	  size_t yys;
 	  size_t yyn = yystack.yytops.yysize;
+
+	  /* yyprocessOneStack returns one of three things:
+
+	      - An error flag.  If the caller is yyprocessOneStack, it
+		immediately returns as well.  When the caller is finally
+		yyparse, it jumps to an error label via YYCHK1.
+
+	      - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
+		(&yystack, yys), which sets the top state of yys to NULL.  Thus,
+		yyparse's following invocation of yyremoveDeletes will remove
+		the stack.
+
+	      - yyok, when ready to shift a token.
+
+	     Except in the first case, yyparse will invoke yyremoveDeletes and
+	     then shift the next token onto all remaining stacks.  This
+	     synchronization of the shift (that is, after all preceding
+	     reductions on all stacks) helps prevents double destructor calls
+	     on yylval in the event of memory exhaustion.  */
+
 	  for (yys = 0; yys < yyn; yys += 1)
 	    YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn,
 				       yylvalp, yyllocp]b4_lpure_args[));
+	  yyremoveDeletes (&yystack);
+	  yyn = yystack.yytops.yysize;
+
+	  /* If any yyglrShift call fails, it will fail after shifting.  Thus,
+	     a copy of yylval will already be on stack 0 in the event of a
+	     failure in the following loop.  Thus, yytoken is set to YYEMPTY
+	     before the loop to make sure the user destructor for yylval isn't
+	     called twice.  */
+	  yytoken_to_shift = yytoken;
 	  yytoken = YYEMPTY;
 	  yyposn += 1;
-	  yyremoveDeletes (&yystack);
+	  for (yys = 0; yys < yyn; yys += 1)
+	    {
+	      int yyaction;
+	      const short int* yyconflicts;
+	      yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
+	      yygetLRActions (yystate, yytoken_to_shift, &yyaction,
+			      &yyconflicts);
+	      /* Note that yyconflicts were handled by yyprocessOneStack.  */
+	      YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
+	      YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, yylvalp, yyllocp);
+	      yyglrShift (&yystack, yys, yyaction, yyposn,
+			  *yylvalp, yyllocp);
+	      YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
+			  (unsigned long int) yys,
+			  yystack.yytops.yystates[yys]->yylrState));
+	    }
 	  if (yystack.yytops.yysize == 0)
 	    {
 	      yyundeleteLastStack (&yystack);
@@ -2289,7 +2325,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
  yyreturn:
   if (yytoken != YYEOF && yytoken != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
-                yytoken, yylvalp]b4_location_if([, yyllocp])[]b4_user_args[);
+		yytoken, yylvalp]b4_location_if([, yyllocp])[]b4_user_args[);
 
   /* If the stack is well-formed, pop the stack until it is empty,
      destroying its entries as we go.  But free the stack regardless
@@ -2298,15 +2334,24 @@ b4_syncline([@oline@], [@ofile@])])dnl
     {
       yyGLRState** yystates = yystack.yytops.yystates;
       if (yystates)
-	while (yystates[0])
-	  {
-	    yyGLRState *yys = yystates[0];
-]b4_location_if([[	  yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
-)[	    yydestroyGLRState ("Cleanup: popping", yys]b4_user_args[);
-	    yystates[0] = yys->yypred;
-	    yystack.yynextFree -= 1;
-	    yystack.yyspaceLeft += 1;
-	  }
+	{
+	  size_t yysize = yystack.yytops.yysize;
+	  size_t yyk;
+	  for (yyk = 0; yyk < yysize; yyk += 1)
+	    if (yystates[yyk])
+	      {
+		while (yystates[yyk])
+		  {
+		    yyGLRState *yys = yystates[yyk];
+]b4_location_if([[		    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
+)[		    yydestroyGLRState ("Cleanup: popping", yys]b4_user_args[);
+		    yystates[yyk] = yys->yypred;
+		    yystack.yynextFree -= 1;
+		    yystack.yyspaceLeft += 1;
+		  }
+		break;
+	      }
+	}
       yyfreeGLRStack (&yystack);
     }
 
@@ -2390,7 +2435,7 @@ b4_epilogue
 m4_if(b4_defines_flag, 0, [],
 [@output @output_header_name@
 b4_copyright([Skeleton parser for GLR parsing with Bison],
-             [2002, 2003, 2004, 2005])[
+	     [2002, 2003, 2004, 2005])[
 
 /* As a special exception, when this parser skeleton is copied by
    Bison into a Bison output file, you may use that output file
