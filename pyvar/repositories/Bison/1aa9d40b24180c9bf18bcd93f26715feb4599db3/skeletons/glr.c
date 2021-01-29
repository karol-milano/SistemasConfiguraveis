@@ -577,7 +577,7 @@ yytnamerr (char *yyres, const char *yystr)
 ]])[
 
 /** State numbers. */
-typedef int yyStateNum;
+typedef int yy_state_t;
 
 /** Rule numbers. */
 typedef int yyRuleNum;
@@ -601,7 +601,7 @@ struct yyGLRState {
    *  yyfirstVal applies.  */
   yybool yyresolved;
   /** Number of corresponding LALR(1) machine state.  */
-  yyStateNum yylrState;
+  yy_state_t yylrState;
   /** Preceding state in this stack */
   yyGLRState* yypred;
   /** Source position of the last token produced by my symbol */
@@ -984,14 +984,14 @@ yylhsNonterm (yyRuleNum yyrule)
 /** True iff LR state YYSTATE has only a default reduction (regardless
  *  of token).  */
 static inline yybool
-yyisDefaultedState (yyStateNum yystate)
+yyisDefaultedState (yy_state_t yystate)
 {
   return yypact_value_is_default (yypact[yystate]);
 }
 
 /** The default reduction for YYSTATE, assuming it has one.  */
 static inline yyRuleNum
-yydefaultAction (yyStateNum yystate)
+yydefaultAction (yy_state_t yystate)
 {
   return yydefact[yystate];
 }
@@ -1008,7 +1008,7 @@ yydefaultAction (yyStateNum yystate)
  *  of conflicting reductions.
  */
 static inline int
-yygetLRActions (yyStateNum yystate, yySymbol yytoken, const short** yyconflicts)
+yygetLRActions (yy_state_t yystate, yySymbol yytoken, const short** yyconflicts)
 {
   int yyindex = yypact[yystate] + yytoken;
   if (yyisDefaultedState (yystate)
@@ -1033,8 +1033,8 @@ yygetLRActions (yyStateNum yystate, yySymbol yytoken, const short** yyconflicts)
  * \param yystate   the current state
  * \param yysym     the nonterminal to push on the stack
  */
-static inline yyStateNum
-yyLRgotoState (yyStateNum yystate, yySymbol yysym)
+static inline yy_state_t
+yyLRgotoState (yy_state_t yystate, yySymbol yysym)
 {
   int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
   if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
@@ -1303,7 +1303,7 @@ yyremoveDeletes (yyGLRStack* yystackp)
  * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
  * value *YYVALP and source location *YYLOCP.  */
 static inline void
-yyglrShift (yyGLRStack* yystackp, ptrdiff_t yyk, yyStateNum yylrState,
+yyglrShift (yyGLRStack* yystackp, ptrdiff_t yyk, yy_state_t yylrState,
             ptrdiff_t yyposn,
             YYSTYPE* yyvalp]b4_locations_if([, YYLTYPE* yylocp])[)
 {
@@ -1324,7 +1324,7 @@ yyglrShift (yyGLRStack* yystackp, ptrdiff_t yyk, yyStateNum yylrState,
  *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
  *  semantic value of YYRHS under the action for YYRULE.  */
 static inline void
-yyglrShiftDefer (yyGLRStack* yystackp, ptrdiff_t yyk, yyStateNum yylrState,
+yyglrShiftDefer (yyGLRStack* yystackp, ptrdiff_t yyk, yy_state_t yylrState,
                  ptrdiff_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
 {
   yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
@@ -1468,7 +1468,7 @@ yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
       ptrdiff_t yyi;
       int yyn;
       yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
-      yyStateNum yynewLRState;
+      yy_state_t yynewLRState;
 
       for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
            0 < yyn; yyn -= 1)
@@ -1974,7 +1974,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
 {
   while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
     {
-      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
+      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
       YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                    YY_CAST (long, yyk), yystate));
 
@@ -2350,7 +2350,7 @@ b4_dollar_popdef])[]dnl
       /* Standard mode */
       while (yytrue)
         {
-          yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
+          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
           YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
           if (yystate == YYFINAL)
             goto yyacceptlab;
@@ -2447,7 +2447,7 @@ b4_dollar_popdef])[]dnl
           yyposn += 1;
           for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
             {
-              yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
+              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
               const short* yyconflicts;
               int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                               &yyconflicts);
