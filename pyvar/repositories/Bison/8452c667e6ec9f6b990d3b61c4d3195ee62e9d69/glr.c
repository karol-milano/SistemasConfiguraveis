@@ -1108,11 +1108,11 @@ yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
  *  stack #K of *STACKP. */
 static void
 yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
-		     yyGLRState* rhs, yyRuleNum yyrule)
+		     yyGLRState* yyrhs, yyRuleNum yyrule)
 {
   yySemanticOption* yynewOption =
     &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
-  yynewOption->yystate = rhs;
+  yynewOption->yystate = yyrhs;
   yynewOption->yyrule = yyrule;
   if (yystackp->yytops.yylookaheadNeeds[yyk])
     {
@@ -1343,7 +1343,7 @@ yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
  *  semantic value of YYRHS under the action for YYRULE.  */
 static inline void
 yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
-		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
+		 size_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
 {
   yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
 
@@ -1355,7 +1355,7 @@ yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
   yystackp->yytops.yystates[yyk] = yynewState;
 
   /* Invokes YY_RESERVE_GLRSTACK.  */
-  yyaddDeferredAction (yystackp, yyk, yynewState, rhs, yyrule);
+  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
 }
 
 /** Pop the symbols consumed by reduction #RULE from the top of stack
@@ -1373,12 +1373,12 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
   if (yystackp->yysplitPoint == NULL)
     {
       /* Standard special case: single stack.  */
-      yyGLRStackItem* rhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
+      yyGLRStackItem* yyrhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
       YYASSERT (yyk == 0);
       yystackp->yynextFree -= yynrhs;
       yystackp->yyspaceLeft += yynrhs;
       yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
-      return yyuserAction (yyrule, yynrhs, rhs,
+      return yyuserAction (yyrule, yynrhs, yyrhs,
 			   yyvalp, yylocp, yystackp]b4_user_args[);
     }
   else
