@@ -761,6 +761,11 @@ struct yyGLRState {
 
 struct yyGLRStateSet {
   yyGLRState** yystates;
+  /** During nondeterministic operation, yylookaheadStatuses tracks which
+   *  stacks have actually needed the current lookahead.  During deterministic
+   *  operation, yylookaheadStatuses[0] is not maintained since it would merely
+   *  duplicate yychar != YYEMPTY.  */
+  yybool* yylookaheadStatuses;
   size_t yysize, yycapacity;
 };
 
@@ -771,6 +776,10 @@ struct yySemanticOption {
   yyRuleNum yyrule;
   /** The last RHS state in the list of states to be reduced.  */
   yyGLRState* yystate;
+  /** The lookahead for this reduction.  */
+  int yyrawchar;
+  YYSTYPE yyval;
+  YYLTYPE yyloc;
   /** Next sibling in chain of options.  To facilitate merging,
    *  options are chained in decreasing order by address.  */
   yySemanticOption* yynext;
@@ -1092,14 +1101,24 @@ yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
   return yynewItem;
 }
 
+/** Stack #K = the stack from which RHS is taken.  This might not be the stack
+ *  containing STATE, to which the deferred action is added.  */
 static void
-yyaddDeferredAction (yyGLRStack* yystackp, yyGLRState* yystate,
+yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
 		     yyGLRState* rhs, yyRuleNum yyrule)
 {
   yySemanticOption* yynewOption =
     &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
   yynewOption->yystate = rhs;
   yynewOption->yyrule = yyrule;
+  if (yystackp->yytops.yylookaheadStatuses[yyk])
+    {
+      yynewOption->yyrawchar = yychar;
+      yynewOption->yyval = yylval;
+      yynewOption->yyloc = yylloc;
+    }
+  else
+    yynewOption->yyrawchar = YYEMPTY;
   yynewOption->yynext = yystate->yysemantics.yyfirstVal;
   yystate->yysemantics.yyfirstVal = yynewOption;
 
@@ -1118,12 +1137,20 @@ yyinitStateSet (yyGLRStateSet* yyset)
   if (! yyset->yystates)
     return yyfalse;
   yyset->yystates[0] = NULL;
+  yyset->yylookaheadStatuses =
+    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadStatuses[0]);
+  if (! yyset->yylookaheadStatuses)
+    {
+      YYFREE (yyset->yystates);
+      return yyfalse;
+    }
   return yytrue;
 }
 
 static void yyfreeStateSet (yyGLRStateSet* yyset)
 {
   YYFREE (yyset->yystates);
+  YYFREE (yyset->yylookaheadStatuses);
 }
 
 /** Initialize STACK to a single empty stack, with total maximum
@@ -1270,6 +1297,13 @@ yyremoveDeletes (yyGLRStack* yystackp)
       else
 	{
 	  yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
+	  /* In the current implementation, it's unnecessary to copy
+	     yystackp->yytops.yylookaheadStatuses[yyi] since, after
+	     yyremoveDeletes returns, the parser immediately either enters
+	     deterministic operation or shifts a token.  However, it doesn't
+	     hurt, and the code might evolve to need it.  */
+	  yystackp->yytops.yylookaheadStatuses[yyj] =
+	    yystackp->yytops.yylookaheadStatuses[yyi];
 	  if (yyj != yyi)
 	    {
 	      YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
@@ -1318,7 +1352,7 @@ yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
   yystackp->yytops.yystates[yyk] = yynewState;
 
   /* Invokes YY_RESERVE_GLRSTACK.  */
-  yyaddDeferredAction (yystackp, yynewState, rhs, yyrule);
+  yyaddDeferredAction (yystackp, yyk, yynewState, rhs, yyrule);
 }
 
 /** Pop the symbols consumed by reduction #RULE from the top of stack
@@ -1470,7 +1504,7 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 	      {
 		if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
 		  {
-		    yyaddDeferredAction (yystackp, yyp, yys0, yyrule);
+		    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
 		    yymarkStackDeleted (yystackp, yyk);
 		    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
 				(unsigned long int) yyk,
@@ -1497,6 +1531,7 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
   if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
     {
       yyGLRState** yynewStates;
+      yybool* yynewLookaheadStatuses;
       if (! ((yystackp->yytops.yycapacity
 	      <= (YYSIZEMAX / (2 * sizeof yynewStates[0])))
 	     && (yynewStates =
@@ -1505,9 +1540,17 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
 					    * sizeof yynewStates[0])))))
 	yyMemoryExhausted (yystackp);
       yystackp->yytops.yystates = yynewStates;
+      if (! (yynewLookaheadStatuses =
+	     (yybool*) YYREALLOC (yystackp->yytops.yylookaheadStatuses,
+				  ((yystackp->yytops.yycapacity)
+				   * sizeof yynewLookaheadStatuses[0]))))
+	yyMemoryExhausted (yystackp);
+      yystackp->yytops.yylookaheadStatuses = yynewLookaheadStatuses;
     }
   yystackp->yytops.yystates[yystackp->yytops.yysize]
     = yystackp->yytops.yystates[yyk];
+  yystackp->yytops.yylookaheadStatuses[yystackp->yytops.yysize]
+    = yystackp->yytops.yylookaheadStatuses[yyk];
   yystackp->yytops.yysize += 1;
   return yystackp->yytops.yysize-1;
 }
@@ -1647,6 +1690,10 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
 {
   yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
   int yynrhs;
+  int yychar_current;
+  YYSTYPE yylval_current;
+  YYLTYPE yylloc_current;
+  YYRESULTTAG yyresult;
 
   yynrhs = yyrhsLength (yyopt->yyrule);
   YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystackp]b4_user_args[));
@@ -1654,9 +1701,19 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
   if (yynrhs == 0)
     /* Set default location.  */
     yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;]])[
-  return yyuserAction (yyopt->yyrule, yynrhs,
-		       yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
-		       yyvalp, yylocp, yystackp]b4_user_args[);
+  yychar_current = yychar;
+  yylval_current = yylval;
+  yylloc_current = yylloc;
+  yychar = yyopt->yyrawchar;
+  yylval = yyopt->yyval;
+  yylloc = yyopt->yyloc;
+  yyresult = yyuserAction (yyopt->yyrule, yynrhs,
+			   yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
+			   yyvalp, yylocp, yystackp]b4_user_args[);
+  yychar = yychar_current;
+  yylval = yylval_current;
+  yylloc = yylloc_current;
+  return yyresult;
 }
 
 #if YYDEBUG
@@ -1710,7 +1767,7 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
 static void yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
 			       yyGLRStack* yystackp]b4_pure_formals[)
   __attribute__ ((__noreturn__));
-static void
+/*ARGSUSED*/ static void
 yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
 		   yyGLRStack* yystackp]b4_pure_formals[)
 {
@@ -1885,6 +1942,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 	}
       else
 	{
+	  yystackp->yytops.yylookaheadStatuses[yyk] = yytrue;
 	  if (*yytokenp == YYEMPTY)
 	    {
 	      YYDPRINTF ((stderr, "Reading a token: "));
@@ -2147,6 +2205,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 
   YYDPRINTF ((stderr, "Starting parse\n"));
 
+  yychar = YYEMPTY;
   yytoken = YYEMPTY;
   yylval = yyval_default;
 ]b4_location_if([
@@ -2221,7 +2280,10 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		{
 		  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 		  if (yytoken != YYEOF)
-		    yytoken = YYEMPTY;
+		    {
+		      yychar = YYEMPTY;
+		      yytoken = YYEMPTY;
+		    }
 		  yyposn += 1;
 		  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
 		  if (0 < yystack.yyerrState)
@@ -2244,6 +2306,9 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	  size_t yys;
 	  size_t yyn = yystack.yytops.yysize;
 
+	  for (yys = 0; yys < yyn; yys += 1)
+	    yystackp->yytops.yylookaheadStatuses[yys] = yychar != YYEMPTY;
+
 	  /* yyprocessOneStack returns one of three things:
 
 	      - An error flag.  If the caller is yyprocessOneStack, it
@@ -2274,6 +2339,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	     before the loop to make sure the user destructor for yylval isn't
 	     called twice.  */
 	  yytoken_to_shift = yytoken;
+	  yychar = YYEMPTY;
 	  yytoken = YYEMPTY;
 	  yyposn += 1;
 	  for (yys = 0; yys < yyn; yys += 1)
