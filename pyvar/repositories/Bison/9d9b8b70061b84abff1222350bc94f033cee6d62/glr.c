@@ -151,7 +151,7 @@ m4_divert(0)dnl
 b4_copyright([Skeleton parser for GLR parsing with Bison],
   [2002, 2003, 2004, 2005])
 [
-/* This is the parser code for GLR (Generalized LR) parser. */
+/* This is the parser code for GLR (Generalized LR) parser.  */
 
 ]b4_identification
 
@@ -230,7 +230,7 @@ m4_if(b4_defines_flag, 0,
    right-hand sides.  Unlike the standard yacc.c template,
    here we set the default value of $$ to a zeroed-out value.
    Since the default value is undefined, this behavior is
-   technically correct. */
+   technically correct.  */
 static YYSTYPE yyval_default;
 
 /* Copy the second part of user declarations.  */
@@ -323,23 +323,23 @@ b4_syncline([@oline@], [@ofile@])
 # define YYASSERT(condition) ((void) ((condition) || (abort (), 0)))
 #endif
 
-/* YYFINAL -- State number of the termination state. */
+/* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  ]b4_final_state_number[
 /* YYLAST -- Last index in YYTABLE.  */
 #define YYLAST   ]b4_last[
 
-/* YYNTOKENS -- Number of terminals. */
+/* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  ]b4_tokens_number[
-/* YYNNTS -- Number of nonterminals. */
+/* YYNNTS -- Number of nonterminals.  */
 #define YYNNTS  ]b4_nterms_number[
-/* YYNRULES -- Number of rules. */
+/* YYNRULES -- Number of rules.  */
 #define YYNRULES  ]b4_rules_number[
-/* YYNRULES -- Number of states. */
+/* YYNRULES -- Number of states.  */
 #define YYNSTATES  ]b4_states_number[
-/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule. */
+/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
 #define YYMAXRHS ]b4_r2_max[
 /* YYMAXLEFT -- Maximum number of symbols to the left of a handle
-   accessed by $0, $-1, etc., in any rule. */
+   accessed by $0, $-1, etc., in any rule.  */
 #define YYMAXLEFT ]b4_max_left_semantic_context[
 
 /* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
@@ -364,7 +364,7 @@ static const ]b4_int_type_for([b4_prhs])[ yyprhs[] =
   ]b4_prhs[
 };
 
-/* YYRHS -- A `-1'-separated list of the rules' RHS. */
+/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
 static const ]b4_int_type_for([b4_rhs])[ yyrhs[] =
 {
   ]b4_rhs[
@@ -379,7 +379,7 @@ static const ]b4_int_type_for([b4_rline])[ yyrline[] =
 
 #if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
-   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
+   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
 {
   ]b4_tname[
@@ -398,13 +398,13 @@ static const ]b4_int_type_for([b4_r2])[ yyr2[] =
   ]b4_r2[
 };
 
-/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none). */
+/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
 static const ]b4_int_type_for([b4_dprec])[ yydprec[] =
 {
   ]b4_dprec[
 };
 
-/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM. */
+/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
 static const ]b4_int_type_for([b4_merger])[ yymerger[] =
 {
   ]b4_merger[
@@ -418,7 +418,7 @@ static const ]b4_int_type_for([b4_defact])[ yydefact[] =
   ]b4_defact[
 };
 
-/* YYPDEFGOTO[NTERM-NUM]. */
+/* YYPDEFGOTO[NTERM-NUM].  */
 static const ]b4_int_type_for([b4_defgoto])[ yydefgoto[] =
 {
   ]b4_defgoto[
@@ -621,7 +621,7 @@ int yydebug;
    allocation.  This is to allow allocation and initialization
    to be completed by functions that call yyexpandGLRStack before the
    stack is expanded, thus insuring that all necessary pointers get
-   properly redirected to new data. */
+   properly redirected to new data.  */
 #define YYHEADROOM 2
 
 #ifndef YYSTACKEXPANDABLE
@@ -740,12 +740,12 @@ typedef union yyGLRStackItem yyGLRStackItem;
 typedef struct yyGLRStack yyGLRStack;
 
 struct yyGLRState {
-  /** Type tag: always true. */
+  /** Type tag: always true.  */
   yybool yyisState;
-  /** Type tag for yysemantics. If true, yysval applies, otherwise
-   *  yyfirstVal applies. */
+  /** Type tag for yysemantics.  If true, yysval applies, otherwise
+   *  yyfirstVal applies.  */
   yybool yyresolved;
-  /** Number of corresponding LALR(1) machine state. */
+  /** Number of corresponding LALR(1) machine state.  */
   yyStateNum yylrState;
   /** Preceding state in this stack */
   yyGLRState* yypred;
@@ -754,12 +754,12 @@ struct yyGLRState {
   union {
     /** First in a chain of alternative reductions producing the
      *  non-terminal corresponding to this state, threaded through
-     *  yynext. */
+     *  yynext.  */
     yySemanticOption* yyfirstVal;
-    /** Semantic value for this state. */
+    /** Semantic value for this state.  */
     YYSTYPE yysval;
   } yysemantics;
-  /** Source location for this state. */
+  /** Source location for this state.  */
   YYLTYPE yyloc;
 };
 
@@ -769,19 +769,19 @@ struct yyGLRStateSet {
 };
 
 struct yySemanticOption {
-  /** Type tag: always false. */
+  /** Type tag: always false.  */
   yybool yyisState;
   /** Rule number for this reduction */
   yyRuleNum yyrule;
-  /** The last RHS state in the list of states to be reduced. */
+  /** The last RHS state in the list of states to be reduced.  */
   yyGLRState* yystate;
-  /** Next sibling in chain of options. To facilitate merging,
-   *  options are chained in decreasing order by address. */
+  /** Next sibling in chain of options.  To facilitate merging,
+   *  options are chained in decreasing order by address.  */
   yySemanticOption* yynext;
 };
 
-/** Type of the items in the GLR stack. The yyisState field
- *  indicates which item of the union is valid. */
+/** Type of the items in the GLR stack.  The yyisState field
+ *  indicates which item of the union is valid.  */
 union yyGLRStackItem {
   yyGLRState yystate;
   yySemanticOption yyoption;
@@ -844,7 +844,7 @@ yytokenName (yySymbol yytoken)
 
 /** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
  *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
- *  containing the pointer to the next state in the chain. */
+ *  containing the pointer to the next state in the chain.  */
 static void yyfillin (yyGLRStackItem *, int, int) __attribute__ ((__unused__));
 static void
 yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
@@ -881,8 +881,8 @@ yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
 /** Perform user action for rule number YYN, with RHS length YYRHSLEN,
  *  and top stack item YYVSP.  YYLVALP points to place to put semantic
  *  value ($$), and yylocp points to place for location information
- *  (@@$). Returns yyok for normal return, yyaccept for YYACCEPT,
- *  yyerr for YYERROR, yyabort for YYABORT. */
+ *  (@@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
+ *  yyerr for YYERROR, yyabort for YYABORT.  */
 /*ARGSUSED*/ static YYRESULTTAG
 yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 	      YYSTYPE* yyvalp,
@@ -995,7 +995,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
     }
 }
 
-/** Left-hand-side symbol for rule #RULE. */
+/** Left-hand-side symbol for rule #RULE.  */
 static inline yySymbol
 yylhsNonterm (yyRuleNum yyrule)
 {
@@ -1008,14 +1008,14 @@ yylhsNonterm (yyRuleNum yyrule)
 	 [((yystate) == YYPACT_NINF)])[
 
 /** True iff LR state STATE has only a default reduction (regardless
- *  of token). */
+ *  of token).  */
 static inline yybool
 yyisDefaultedState (yyStateNum yystate)
 {
   return yyis_pact_ninf (yypact[yystate]);
 }
 
-/** The default reduction for STATE, assuming it has one. */
+/** The default reduction for STATE, assuming it has one.  */
 static inline yyRuleNum
 yydefaultAction (yyStateNum yystate)
 {
@@ -1112,7 +1112,7 @@ yyaddDeferredAction (yyGLRStack* yystackp, yyGLRState* yystate,
 
 				/* GLRStacks */
 
-/** Initialize SET to a singleton set containing an empty stack. */
+/** Initialize SET to a singleton set containing an empty stack.  */
 static yybool
 yyinitStateSet (yyGLRStateSet* yyset)
 {
@@ -1131,7 +1131,7 @@ static void yyfreeStateSet (yyGLRStateSet* yyset)
 }
 
 /** Initialize STACK to a single empty stack, with total maximum
- *  capacity for all stacks of SIZE. */
+ *  capacity for all stacks of SIZE.  */
 static yybool
 yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
 {
@@ -1157,7 +1157,7 @@ yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
     stack from outside should be considered invalid after this call.
     We always expand when there are 1 or fewer items left AFTER an
     allocation, so that we can avoid having external pointers exist
-    across an allocation. */
+    across an allocation.  */
 static void
 yyexpandGLRStack (yyGLRStack* yystackp)
 {
@@ -1225,7 +1225,7 @@ yyfreeGLRStack (yyGLRStack* yystackp)
 
 /** Assuming that S is a GLRState somewhere on STACK, update the
  *  splitpoint of STACK, if needed, so that it is at least as deep as
- *  S. */
+ *  S.  */
 static inline void
 yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
 {
@@ -1233,7 +1233,7 @@ yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
     yystackp->yysplitPoint = yys;
 }
 
-/** Invalidate stack #K in STACK. */
+/** Invalidate stack #K in STACK.  */
 static inline void
 yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
 {
@@ -1244,7 +1244,7 @@ yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
 
 /** Undelete the last stack that was marked as deleted.  Can only be
     done once after a deletion, and only when all other stacks have
-    been deleted. */
+    been deleted.  */
 static void
 yyundeleteLastStack (yyGLRStack* yystackp)
 {
@@ -1286,7 +1286,7 @@ yyremoveDeletes (yyGLRStack* yystackp)
 }
 
 /** Shift to a new state on stack #K of STACK, corresponding to LR state
- * LRSTATE, at input position POSN, with (resolved) semantic value SVAL. */
+ * LRSTATE, at input position POSN, with (resolved) semantic value SVAL.  */
 static inline void
 yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
 	    size_t yyposn,
@@ -1307,7 +1307,7 @@ yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
 
 /** Shift stack #K of YYSTACK, to a new state corresponding to LR
  *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
- *  semantic value of YYRHS under the action for YYRULE. */
+ *  semantic value of YYRHS under the action for YYRULE.  */
 static inline void
 yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
 		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
@@ -1321,16 +1321,16 @@ yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
   yynewState->yysemantics.yyfirstVal = NULL;
   yystackp->yytops.yystates[yyk] = yynewState;
 
-  /* Invokes YY_RESERVE_GLRSTACK. */
+  /* Invokes YY_RESERVE_GLRSTACK.  */
   yyaddDeferredAction (yystackp, yynewState, rhs, yyrule);
 }
 
 /** Pop the symbols consumed by reduction #RULE from the top of stack
  *  #K of STACK, and perform the appropriate semantic action on their
  *  semantic values.  Assumes that all ambiguities in semantic values
- *  have been previously resolved. Set *VALP to the resulting value,
+ *  have been previously resolved.  Set *VALP to the resulting value,
  *  and *LOCP to the computed location (if any).  Return value is as
- *  for userAction. */
+ *  for userAction.  */
 static inline YYRESULTTAG
 yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 	    YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
@@ -1339,7 +1339,7 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 
   if (yystackp->yysplitPoint == NULL)
     {
-      /* Standard special case: single stack. */
+      /* Standard special case: single stack.  */
       yyGLRStackItem* rhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
       YYASSERT (yyk == 0);
       yystackp->yynextFree -= yynrhs;
@@ -1353,14 +1353,14 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       /* At present, doAction is never called in nondeterministic
        * mode, so this branch is never taken.  It is here in
        * anticipation of a future feature that will allow immediate
-       * evaluation of selected actions in nondeterministic mode. */
+       * evaluation of selected actions in nondeterministic mode.  */
       int yyi;
       yyGLRState* yys;
       yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
       yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
 	= yystackp->yytops.yystates[yyk];]b4_location_if([[
       if (yynrhs == 0)
-	/* Set default location. */
+	/* Set default location.  */
 	yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;]])[
       for (yyi = 0; yyi < yynrhs; yyi += 1)
 	{
@@ -1424,7 +1424,7 @@ yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
  *  the new state.  If the new state would have an identical input
  *  position, LR state, and predecessor to an existing state on the stack,
  *  it is identified with that existing state, eliminating stack #K from
- *  the STACK. In this case, the (necessarily deferred) semantic value is
+ *  the STACK.  In this case, the (necessarily deferred) semantic value is
  *  added to the options for the existing state's semantic value.
  */
 static inline YYRESULTTAG
@@ -1463,7 +1463,7 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       yyupdateSplit (yystackp, yys);
       yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
       YYDPRINTF ((stderr,
-		  "Reduced stack %lu by rule #%d; action deferred. Now in state %d.\n",
+		  "Reduced stack %lu by rule #%d; action deferred.  Now in state %d.\n",
 		  (unsigned long int) yyk, yyrule - 1, yynewLRState));
       for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
 	if (yyi != yyk && yystackp->yytops.yystates[yyi] != NULL)
@@ -1518,7 +1518,7 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
 
 /** True iff Y0 and Y1 represent identical options at the top level.
  *  That is, they represent the same rule applied to RHS symbols
- *  that produce the same terminal symbols. */
+ *  that produce the same terminal symbols.  */
 static yybool
 yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
 {
@@ -1539,7 +1539,7 @@ yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
 }
 
 /** Assuming identicalOptions (Y0,Y1), destructively merge the
- *  alternative semantic values for the RHS-symbols of Y1 and Y0. */
+ *  alternative semantic values for the RHS-symbols of Y1 and Y0.  */
 static void
 yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
 {
@@ -1593,7 +1593,7 @@ yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
 
 /** Y0 and Y1 represent two possible actions to take in a given
  *  parsing state; return 0 if no combination is possible,
- *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred. */
+ *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
 static int
 yypreference (yySemanticOption* y0, yySemanticOption* y1)
 {
@@ -1655,7 +1655,7 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
   YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystackp]b4_user_args[));
   yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;]b4_location_if([[
   if (yynrhs == 0)
-    /* Set default location. */
+    /* Set default location.  */
     yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;]])[
   return yyuserAction (yyopt->yyrule, yynrhs,
 		       yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
@@ -1733,7 +1733,7 @@ yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
 
 
 /** Resolve the ambiguity represented by OPTIONLIST, perform the indicated
- *  actions, and return the result. */
+ *  actions, and return the result.  */
 static YYRESULTTAG
 yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystackp,
 		YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
@@ -2040,7 +2040,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	if (*yytokenp != YYEMPTY)
 	  {]b4_location_if([[
 	    /* We throw away the lookahead, but the error range
-	       of the shifted error token must take it into account. */
+	       of the shifted error token must take it into account.  */
 	    yyGLRState *yys = yystackp->yytops.yystates[0];
 	    yyGLRStackItem yyerror_range[3];
 	    yyerror_range[1].yystate.yyloc = yys->yyloc;
@@ -2077,7 +2077,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   yyremoveDeletes (yystackp);
   yycompressStack (yystackp);
 
-  /* Now pop stack until we find a state that shifts the error token. */
+  /* Now pop stack until we find a state that shifts the error token.  */
   yystackp->yyerrState = 3;
   while (yystackp->yytops.yystates[0] != NULL)
     {
@@ -2153,7 +2153,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 m4_ifdef([b4_initial_action], [
 m4_pushdef([b4_at_dollar],     [yylloc])dnl
 m4_pushdef([b4_dollar_dollar], [yylval])dnl
-  /* User initialization code. */
+  /* User initialization code.  */
   b4_initial_action
 m4_popdef([b4_dollar_dollar])dnl
 m4_popdef([b4_at_dollar])dnl
