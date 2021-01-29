@@ -311,15 +311,20 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 # define YYLONGJMP(Env, Val)                    \
  do {                                           \
    longjmp (Env, Val);                          \
-   YYASSERT (0);                                \
+   YY_ASSERT (0);                               \
  } while (yyfalse)
 #endif
 
 ]b4_attribute_define([noreturn])[
 
-#ifndef YYASSERT
-# define YYASSERT(Condition) ((void) ((Condition) || (abort (), 0)))
+]b4_parse_assert_if([[#ifdef NDEBUG
+# define YY_ASSERT(E) ((void) (0 && (E)))
+#else
+# include <assert.h> /* INFRINGES ON USER NAME SPACE */
+# define YY_ASSERT(E) assert (E)
 #endif
+]],
+[[#define YY_ASSERT(E) ((void) (0 && (E)))]])[
 
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  ]b4_final_state_number[
@@ -756,10 +761,7 @@ yyMemoryExhausted (yyGLRStack* yystackp)
 static inline const char*
 yytokenName (yySymbol yytoken)
 {
-  if (yytoken == YYEMPTY)
-    return "";
-
-  return yytname[yytoken];
+  return yytoken == YYEMPTY ? "" : yytname[yytoken];
 }
 #endif
 
@@ -1090,7 +1092,7 @@ yyaddDeferredAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyGLRState* yystate,
 {
   yySemanticOption* yynewOption =
     &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
-  YYASSERT (!yynewOption->yyisState);
+  YY_ASSERT (!yynewOption->yyisState);
   yynewOption->yystate = yyrhs;
   yynewOption->yyrule = yyrule;
   if (yystackp->yytops.yylookaheadNeeds[yyk])
@@ -1336,7 +1338,7 @@ yyglrShiftDefer (yyGLRStack* yystackp, ptrdiff_t yyk, yyStateNum yylrState,
                  ptrdiff_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
 {
   yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
-  YYASSERT (yynewState->yyisState);
+  YY_ASSERT (yynewState->yyisState);
 
   yynewState->yylrState = yylrState;
   yynewState->yyposn = yyposn;
@@ -1406,7 +1408,7 @@ yydoAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
       /* Standard special case: single stack.  */
       yyGLRStackItem* yyrhs
         = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
-      YYASSERT (yyk == 0);
+      YY_ASSERT (yyk == 0);
       yystackp->yynextFree -= yynrhs;
       yystackp->yyspaceLeft += yynrhs;
       yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
@@ -1426,7 +1428,7 @@ yydoAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
       for (yyi = 0; yyi < yynrhs; yyi += 1)
         {
           yys = yys->yypred;
-          YYASSERT (yys);
+          YY_ASSERT (yys);
         }
       yyupdateSplit (yystackp, yys);
       yystackp->yytops.yystates[yyk] = yys;
@@ -1482,7 +1484,7 @@ yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
            0 < yyn; yyn -= 1)
         {
           yys = yys->yypred;
-          YYASSERT (yys);
+          YY_ASSERT (yys);
         }
       yyupdateSplit (yystackp, yys);
       yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
@@ -1520,7 +1522,7 @@ yysplitStack (yyGLRStack* yystackp, ptrdiff_t yyk)
 {
   if (yystackp->yysplitPoint == YY_NULLPTR)
     {
-      YYASSERT (yyk == 0);
+      YY_ASSERT (yyk == 0);
       yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
     }
   if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
@@ -1674,7 +1676,7 @@ yyresolveStates (yyGLRState* yys, int yyn,
 {
   if (0 < yyn)
     {
-      YYASSERT (yys->yypred);
+      YY_ASSERT (yys->yypred);
       YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp]b4_user_args[));
       if (! yys->yyresolved)
         YYCHK (yyresolveValue (yys, yystackp]b4_user_args[));
@@ -1807,7 +1809,7 @@ yyresolveLocations (yyGLRState *yys1, int yyn1,
           yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
           int yynrhs;
           yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
-          YYASSERT (yyoption);
+          YY_ASSERT (yyoption);
           yynrhs = yyrhsLength (yyoption->yyrule);
           if (0 < yynrhs)
             {
@@ -1882,7 +1884,7 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
               yymerge = yyfalse;
               break;
             default:
-              /* This cannot happen so it is not worth a YYASSERT (yyfalse),
+              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                  but some compilers complain if the default case is
                  omitted.  */
               break;
@@ -1985,7 +1987,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
       yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
       YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n", yyk, yystate));
 
-      YYASSERT (yystate != YYFINAL);
+      YY_ASSERT (yystate != YYFINAL);
 
       if (yyisDefaultedState (yystate))
         {
@@ -2492,7 +2494,7 @@ b4_dollar_popdef])[]dnl
   goto yyreturn;
 
  yybuglab:
-  YYASSERT (yyfalse);
+  YY_ASSERT (yyfalse);
   goto yyabortlab;
 
  yyabortlab:
@@ -2586,8 +2588,8 @@ yypdumpstack (yyGLRStack* yystackp)
                    YY_CAST (long, yyp - yystackp->yyitems)));
       if (*YY_REINTERPRET_CAST (yybool *, yyp))
         {
-          YYASSERT (yyp->yystate.yyisState);
-          YYASSERT (yyp->yyoption.yyisState);
+          YY_ASSERT (yyp->yystate.yyisState);
+          YY_ASSERT (yyp->yyoption.yyisState);
           YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                        yyp->yystate.yyresolved, yyp->yystate.yylrState,
                        YY_CAST (long, yyp->yystate.yyposn),
@@ -2598,8 +2600,8 @@ yypdumpstack (yyGLRStack* yystackp)
         }
       else
         {
-          YYASSERT (!yyp->yystate.yyisState);
-          YYASSERT (!yyp->yyoption.yyisState);
+          YY_ASSERT (!yyp->yystate.yyisState);
+          YY_ASSERT (!yyp->yyoption.yyisState);
           YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                        yyp->yyoption.yyrule - 1,
                        YYINDEX (yyp->yyoption.yystate),
