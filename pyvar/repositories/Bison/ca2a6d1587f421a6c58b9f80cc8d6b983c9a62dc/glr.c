@@ -402,6 +402,13 @@ static const ]b4_int_type_for([b4_merger])[ yymerger[] =
   ]b4_merger[
 };
 
+/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
+   in the case of predicates.  */
+static const yybool yyimmediate[] =
+{
+  ]b4_immediate[
+};
+
 /* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
    list of conflicting reductions corresponding to action entry for
    state STATE-NUM in yytable.  0 means no conflicts.  The list in
@@ -693,7 +700,7 @@ struct yyGLRState {
   yyStateNum yylrState;
   /** Preceding state in this stack */
   yyGLRState* yypred;
-  /** Source position of the first token produced by my symbol */
+  /** Source position of the last token produced by my symbol */
   size_t yyposn;
   union {
     /** First in a chain of alternative reductions producing the
@@ -806,9 +813,16 @@ yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
   s = yyvsp[yylow0].yystate.yypred;
   for (i = yylow0-1; i >= yylow1; i -= 1)
     {
-      YYASSERT (s->yyresolved);
-      yyvsp[i].yystate.yyresolved = yytrue;
-      yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
+#if YYDEBUG
+      yyvsp[i].yystate.yylrState = s->yylrState;
+#endif
+      yyvsp[i].yystate.yyresolved = s->yyresolved;
+      if (s->yyresolved)
+	yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
+      else
+	/* The effect of using yysval or yyloc (in an immediate rule) is
+         * undefined.  */
+	yyvsp[i].yystate.yysemantics.yyfirstVal = NULL;
       yyvsp[i].yystate.yyloc = s->yyloc;
       s = yyvsp[i].yystate.yypred = s->yypred;
     }
@@ -948,7 +962,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
     }
 }
 
-/** Left-hand-side symbol for rule #RULE.  */
+/** Left-hand-side symbol for rule #YYRULE.  */
 static inline yySymbol
 yylhsNonterm (yyRuleNum yyrule)
 {
@@ -958,7 +972,7 @@ yylhsNonterm (yyRuleNum yyrule)
 #define yypact_value_is_default(yystate) \
   ]b4_table_value_equals([[pact]], [[yystate]], [b4_pact_ninf])[
 
-/** True iff LR state STATE has only a default reduction (regardless
+/** True iff LR state YYSTATE has only a default reduction (regardless
  *  of token).  */
 static inline yybool
 yyisDefaultedState (yyStateNum yystate)
@@ -966,7 +980,7 @@ yyisDefaultedState (yyStateNum yystate)
   return yypact_value_is_default (yypact[yystate]);
 }
 
-/** The default reduction for STATE, assuming it has one.  */
+/** The default reduction for YYSTATE, assuming it has one.  */
 static inline yyRuleNum
 yydefaultAction (yyStateNum yystate)
 {
@@ -981,8 +995,8 @@ yydefaultAction (yyStateNum yystate)
  *    R < 0:  Reduce on rule -R.
  *    R = 0:  Error.
  *    R > 0:  Shift to state R.
- *  Set *CONFLICTS to a pointer into yyconfl to 0-terminated list of
- *  conflicting reductions.
+ *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
+ *  of conflicting reductions.
  */
 static inline void
 yygetLRActions (yyStateNum yystate, int yytoken,
@@ -1031,9 +1045,10 @@ yyisErrorAction (int yyaction)
 
 				/* GLRStates */
 
-/** Return a fresh GLRStackItem.  Callers should call
- * YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
- * headroom.  */
+/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
+ *  if YYISSTATE, and otherwise a semantic option.  Callers should call
+ *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
+ *  headroom.  */
 
 static inline yyGLRStackItem*
 yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
@@ -1046,9 +1061,9 @@ yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
 }
 
 /** Add a new semantic action that will execute the action for rule
- *  RULENUM on the semantic values in RHS to the list of
- *  alternative actions for STATE.  Assumes that RHS comes from
- *  stack #K of *STACKP. */
+ *  YYRULE on the semantic values in YYRHS to the list of
+ *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
+ *  stack #YYK of *YYSTACKP. */
 static void
 yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
 		     yyGLRState* yyrhs, yyRuleNum yyrule)
@@ -1073,7 +1088,7 @@ yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
 
 				/* GLRStacks */
 
-/** Initialize SET to a singleton set containing an empty stack.  */
+/** Initialize YYSET to a singleton set containing an empty stack.  */
 static yybool
 yyinitStateSet (yyGLRStateSet* yyset)
 {
@@ -1099,8 +1114,8 @@ static void yyfreeStateSet (yyGLRStateSet* yyset)
   YYFREE (yyset->yylookaheadNeeds);
 }
 
-/** Initialize STACK to a single empty stack, with total maximum
- *  capacity for all stacks of SIZE.  */
+/** Initialize *YYSTACKP to a single empty stack, with total maximum
+ *  capacity for all stacks of YYSIZE.  */
 static yybool
 yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
 {
@@ -1122,7 +1137,7 @@ yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
 # define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
   &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE
 
-/** If STACK is expandable, extend it.  WARNING: Pointers into the
+/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
     stack from outside should be considered invalid after this call.
     We always expand when there are 1 or fewer items left AFTER an
     allocation, so that we can avoid having external pointers exist
@@ -1192,9 +1207,9 @@ yyfreeGLRStack (yyGLRStack* yystackp)
   yyfreeStateSet (&yystackp->yytops);
 }
 
-/** Assuming that S is a GLRState somewhere on STACK, update the
- *  splitpoint of STACK, if needed, so that it is at least as deep as
- *  S.  */
+/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
+ *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
+ *  YYS.  */
 static inline void
 yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
 {
@@ -1202,7 +1217,7 @@ yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
     yystackp->yysplitPoint = yys;
 }
 
-/** Invalidate stack #K in STACK.  */
+/** Invalidate stack #YYK in *YYSTACKP.  */
 static inline void
 yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
 {
@@ -1211,8 +1226,8 @@ yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
   yystackp->yytops.yystates[yyk] = NULL;
 }
 
-/** Undelete the last stack that was marked as deleted.  Can only be
-    done once after a deletion, and only when all other stacks have
+/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
+    only be done once after a deletion, and only when all other stacks have
     been deleted.  */
 static void
 yyundeleteLastStack (yyGLRStack* yystackp)
@@ -1261,8 +1276,9 @@ yyremoveDeletes (yyGLRStack* yystackp)
     }
 }
 
-/** Shift to a new state on stack #K of STACK, corresponding to LR state
- * LRSTATE, at input position POSN, with (resolved) semantic value SVAL.  */
+/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
+ * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
+ * value *YYVALP and source location *YYLOCP.  */
 static inline void
 yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
 	    size_t yyposn,
@@ -1281,7 +1297,7 @@ yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
   YY_RESERVE_GLRSTACK (yystackp);
 }
 
-/** Shift stack #K of YYSTACK, to a new state corresponding to LR
+/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
  *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
  *  semantic value of YYRHS under the action for YYRULE.  */
 static inline void
@@ -1301,11 +1317,51 @@ yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
   yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
 }
 
-/** Pop the symbols consumed by reduction #RULE from the top of stack
- *  #K of STACK, and perform the appropriate semantic action on their
+#if !YYDEBUG
+# define YY_REDUCE_PRINT(Args)
+#else
+# define YY_REDUCE_PRINT(Args)		\
+do {					\
+  if (yydebug)				\
+    yy_reduce_print Args;		\
+} while (YYID (0))
+
+/*----------------------------------------------------------------------.
+| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
+`----------------------------------------------------------------------*/
+
+/*ARGSUSED*/ static inline void
+yy_reduce_print (int yynormal, yyGLRStackItem* yyrhsVals, size_t yyk, yyRuleNum yyrule]b4_user_formals[)
+{
+  int yynrhs = yyrhsLength (yyrule);
+  int yyi;
+]b4_parse_param_use[]dnl
+[  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
+	     (unsigned long int) yyk, yyrule - 1,
+	     (unsigned long int) yyrline[yyrule]);
+  if (! yynormal)
+    yyfillin (yyrhsVals, 1, -yynrhs);
+  /* The symbols being reduced.  */
+  for (yyi = 0; yyi < yynrhs; yyi++)
+    {
+      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
+      yy_symbol_print (stderr,
+		       yystos[yyrhsVals[yyi - yynrhs + 1].yystate.yylrState],
+		       &yyrhsVals[yyi - yynrhs + 1].yystate.yysemantics.yysval
+		       ]b4_locations_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
+		       b4_user_args[);
+      if (!yyrhsVals[yyi - yynrhs + 1].yystate.yyresolved)
+        YYFPRINTF (stderr, " (unresolved)");
+      YYFPRINTF (stderr, "\n");
+    }
+}
+#endif
+
+/** Pop the symbols consumed by reduction #YYRULE from the top of stack
+ *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
  *  semantic values.  Assumes that all ambiguities in semantic values
- *  have been previously resolved.  Set *VALP to the resulting value,
- *  and *LOCP to the computed location (if any).  Return value is as
+ *  have been previously resolved.  Set *YYVALP to the resulting value,
+ *  and *YYLOCP to the computed location (if any).  Return value is as
  *  for userAction.  */
 static inline YYRESULTTAG
 yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
@@ -1321,15 +1377,12 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       yystackp->yynextFree -= yynrhs;
       yystackp->yyspaceLeft += yynrhs;
       yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
+      YY_REDUCE_PRINT ((1, yyrhs, yyk, yyrule]b4_user_args[));
       return yyuserAction (yyrule, yynrhs, yyrhs,
 			   yyvalp, yylocp, yystackp]b4_user_args[);
     }
   else
     {
-      /* At present, doAction is never called in nondeterministic
-       * mode, so this branch is never taken.  It is here in
-       * anticipation of a future feature that will allow immediate
-       * evaluation of selected actions in nondeterministic mode.  */
       int yyi;
       yyGLRState* yys;
       yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
@@ -1345,60 +1398,21 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 	}
       yyupdateSplit (yystackp, yys);
       yystackp->yytops.yystates[yyk] = yys;
+      YY_REDUCE_PRINT ((0, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule]b4_user_args[));
       return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
 			   yyvalp, yylocp, yystackp]b4_user_args[);
     }
 }
 
-#if !YYDEBUG
-# define YY_REDUCE_PRINT(Args)
-#else
-# define YY_REDUCE_PRINT(Args)		\
-do {					\
-  if (yydebug)				\
-    yy_reduce_print Args;		\
-} while (YYID (0))
-
-/*----------------------------------------------------------.
-| Report that the RULE is going to be reduced on stack #K.  |
-`----------------------------------------------------------*/
-
-/*ARGSUSED*/ static inline void
-yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule]b4_user_formals[)
-{
-  int yynrhs = yyrhsLength (yyrule);
-  yybool yynormal __attribute__ ((__unused__)) =
-    (yystackp->yysplitPoint == NULL);
-  yyGLRStackItem* yyvsp = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
-  int yylow = 1;
-  int yyi;
-]b4_parse_param_use[]dnl
-[  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
-	     (unsigned long int) yyk, yyrule - 1,
-	     (unsigned long int) yyrline[yyrule]);
-  /* The symbols being reduced.  */
-  for (yyi = 0; yyi < yynrhs; yyi++)
-    {
-      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
-      yy_symbol_print (stderr,
-                       ]yystos@{b4_rhs_data(yynrhs, yyi + 1).yylrState@}[,
-		       &]b4_rhs_value(yynrhs, yyi + 1)[
-		       ]b4_locations_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
-		       b4_user_args[);
-      YYFPRINTF (stderr, "\n");
-    }
-}
-#endif
-
-/** Pop items off stack #K of STACK according to grammar rule RULE,
+/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
  *  and push back on the resulting nonterminal symbol.  Perform the
- *  semantic action associated with RULE and store its value with the
- *  newly pushed state, if FORCEEVAL or if STACK is currently
+ *  semantic action associated with YYRULE and store its value with the
+ *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
  *  unambiguous.  Otherwise, store the deferred semantic action with
  *  the new state.  If the new state would have an identical input
  *  position, LR state, and predecessor to an existing state on the stack,
- *  it is identified with that existing state, eliminating stack #K from
- *  the STACK.  In this case, the (necessarily deferred) semantic value is
+ *  it is identified with that existing state, eliminating stack #YYK from
+ *  *YYSTACKP.  In this case, the semantic value is
  *  added to the options for the existing state's semantic value.
  */
 static inline YYRESULTTAG
@@ -1409,12 +1423,19 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 
   if (yyforceEval || yystackp->yysplitPoint == NULL)
     {
+      YYRESULTTAG yyflag;
       YYSTYPE yysval;
       YYLTYPE yyloc;
 
-      YY_REDUCE_PRINT ((yystackp, yyk, yyrule]b4_user_args[));
-      YYCHK (yydoAction (yystackp, yyk, yyrule, &yysval,
-			 &yyloc]b4_user_args[));
+      yyflag = yydoAction (yystackp, yyk, yyrule, &yysval,
+			   &yyloc]b4_user_args[);
+      if (yyflag == yyerr)
+        {
+	  YYDPRINTF ((stderr, "Parse on stack %lu rejected by rule #%d.\n",
+		     (unsigned long int) yyk, yyrule - 1));
+        }
+      if (yyflag != yyok)
+        return yyflag;      
       YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
       yyglrShift (yystackp, yyk,
 		  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
@@ -1508,7 +1529,7 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
   return yystackp->yytops.yysize-1;
 }
 
-/** True iff Y0 and Y1 represent identical options at the top level.
+/** True iff YYY0 and YYY1 represent identical options at the top level.
  *  That is, they represent the same rule applied to RHS symbols
  *  that produce the same terminal symbols.  */
 static yybool
@@ -1530,8 +1551,8 @@ yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
     return yyfalse;
 }
 
-/** Assuming identicalOptions (Y0,Y1), destructively merge the
- *  alternative semantic values for the RHS-symbols of Y1 and Y0.  */
+/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
+ *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
 static void
 yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
 {
@@ -1612,11 +1633,11 @@ static YYRESULTTAG yyresolveValue (yyGLRState* yys,
 				   yyGLRStack* yystackp]b4_user_formals[);
 
 
-/** Resolve the previous N states starting at and including state S.  If result
- *  != yyok, some states may have been left unresolved possibly with empty
- *  semantic option chains.  Regardless of whether result = yyok, each state
- *  has been left with consistent data so that yydestroyGLRState can be invoked
- *  if necessary.  */
+/** Resolve the previous YYN states starting at and including state YYS
+ *  on *YYSTACKP. If result != yyok, some states may have been left
+ *  unresolved possibly with empty semantic option chains.  Regardless
+ *  of whether result = yyok, each state has been left with consistent
+ *  data so that yydestroyGLRState can be invoked if necessary.  */
 static YYRESULTTAG
 yyresolveStates (yyGLRState* yys, int yyn,
 		 yyGLRStack* yystackp]b4_user_formals[)
@@ -1631,9 +1652,10 @@ yyresolveStates (yyGLRState* yys, int yyn,
   return yyok;
 }
 
-/** Resolve the states for the RHS of OPT, perform its user action, and return
- *  the semantic value and location.  Regardless of whether result = yyok, all
- *  RHS states have been destroyed (assuming the user action destroys all RHS
+/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
+ *  user action, and return the semantic value and location in *YYVALP
+ *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
+ *  have been destroyed (assuming the user action destroys all RHS
  *  semantic values if invoked).  */
 static YYRESULTTAG
 yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
@@ -1743,9 +1765,9 @@ yyreportAmbiguity (yySemanticOption* yyx0,
   return yyabort;
 }
 
-/** Starting at and including state S1, resolve the location for each of the
- *  previous N1 states that is unresolved.  The first semantic option of a state
- *  is always chosen.  */
+/** Resolve the locations for each of the YYN1 states in *YYSTACKP,
+ *  ending at YYS1.  Has no effect on previously resolved states.
+ *  The first semantic option of a state is always chosen.  */
 static void
 yyresolveLocations (yyGLRState* yys1, int yyn1,
 		    yyGLRStack *yystackp]b4_user_formals[)
@@ -1801,11 +1823,12 @@ yyresolveLocations (yyGLRState* yys1, int yyn1,
     }
 }
 
-/** Resolve the ambiguity represented in state S, perform the indicated
- *  actions, and set the semantic value of S.  If result != yyok, the chain of
- *  semantic options in S has been cleared instead or it has been left
- *  unmodified except that redundant options may have been removed.  Regardless
- *  of whether result = yyok, S has been left with consistent data so that
+/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
+ *  perform the indicated actions, and set the semantic value of YYS.
+ *  If result != yyok, the chain of semantic options in YYS has been
+ *  cleared instead or it has been left unmodified except that
+ *  redundant options may have been removed.  Regardless of whether
+ *  result = yyok, YYS has been left with consistent data so that
  *  yydestroyGLRState can be invoked if necessary.  */
 static YYRESULTTAG
 yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
@@ -1950,6 +1973,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
   int yyaction;
   const short int* yyconflicts;
   yyRuleNum yyrule;
+  YYRESULTTAG yyflag;
 
   while (yystackp->yytops.yystates[yyk] != NULL)
     {
@@ -1969,11 +1993,21 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 	      yymarkStackDeleted (yystackp, yyk);
 	      return yyok;
 	    }
-	  YYCHK (yyglrReduce (yystackp, yyk, yyrule, yyfalse]b4_user_args[));
+	  yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]]b4_user_args[);
+          if (yyflag == yyerr)
+            {
+	      YYDPRINTF ((stderr, "Stack %lu dies (predicate failure or explicit user error).\n",
+			  (unsigned long int) yyk));
+	      yymarkStackDeleted (yystackp, yyk);
+	      return yyok;
+	    }
+	  if (yyflag != yyok)
+            return yyflag;
 	}
       else
 	{
 	  yySymbol yytoken;
+
 	  yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
 	  if (yychar == YYEMPTY)
 	    {
@@ -1996,14 +2030,25 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 
 	  while (*yyconflicts != 0)
 	    {
+	      YYRESULTTAG yyflag;
 	      size_t yynewStack = yysplitStack (yystackp, yyk);
 	      YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
 			  (unsigned long int) yynewStack,
 			  (unsigned long int) yyk));
-	      YYCHK (yyglrReduce (yystackp, yynewStack,
-				  *yyconflicts, yyfalse]b4_user_args[));
-	      YYCHK (yyprocessOneStack (yystackp, yynewStack,
-					yyposn]b4_pure_args[));
+	      yyflag = yyglrReduce (yystackp, yynewStack,
+				    *yyconflicts,
+				    yyimmediate[*yyconflicts]]b4_user_args[);
+              if (yyflag == yyok)
+	        YYCHK (yyprocessOneStack (yystackp, yynewStack,
+					  yyposn]b4_pure_args[));
+	      else if (yyflag == yyerr)
+		{
+		  YYDPRINTF ((stderr, "Stack %lu dies.\n", 
+			      (unsigned long int) yynewStack));
+		  yymarkStackDeleted (yystackp, yynewStack);
+		}
+	      else
+		return yyflag;
 	      yyconflicts += 1;
 	    }
 
@@ -2017,8 +2062,19 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 	      break;
 	    }
 	  else
-	    YYCHK (yyglrReduce (yystackp, yyk, -yyaction,
-				yyfalse]b4_user_args[));
+            {
+	      yyflag = yyglrReduce (yystackp, yyk, -yyaction,
+		  		    yyimmediate[-yyaction]]b4_user_args[);
+	      if (yyflag == yyerr)
+                {
+	          YYDPRINTF ((stderr, "Stack %lu dies (predicate failure or explicit user error).\n",
+			      (unsigned long int) yyk));
+	          yymarkStackDeleted (yystackp, yyk);
+                  break;
+		}
+	      else if (yyflag != yyok)
+                return yyflag;
+            }
 	}
     }
   return yyok;
@@ -2249,7 +2305,6 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
     }									     \
   } while (YYID (0))
 
-
 /*----------.
 | yyparse.  |
 `----------*/
