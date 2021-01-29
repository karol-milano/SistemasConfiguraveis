@@ -249,6 +249,7 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 #include <string.h>
 
 ]b4_c99_int_type_define[
+]b4_sizes_types_define[
 
 #ifndef YY_
 # if defined YYENABLE_NLS && YYENABLE_NLS
@@ -277,9 +278,6 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 # define YYREALLOC realloc
 #endif
 
-#define YYSIZEMAX \
-  (PTRDIFF_MAX < SIZE_MAX ? PTRDIFF_MAX : YY_CAST (ptrdiff_t, SIZE_MAX))
-
 #ifdef __cplusplus
   typedef bool yybool;
 # define yytrue true
@@ -507,7 +505,7 @@ struct yyGLRState {
   /** Preceding state in this stack */
   yyGLRState* yypred;
   /** Source position of the last token produced by my symbol */
-  ptrdiff_t yyposn;
+  YYPTRDIFF_T yyposn;
   union {
     /** First in a chain of alternative reductions producing the
      *  nonterminal corresponding to this state, threaded through
@@ -527,8 +525,8 @@ struct yyGLRStateSet {
    *  operation, yylookaheadNeeds[0] is not maintained since it would merely
    *  duplicate yychar != ]b4_symbol(-2, id)[.  */
   yybool* yylookaheadNeeds;
-  ptrdiff_t yysize;
-  ptrdiff_t yycapacity;
+  YYPTRDIFF_T yysize;
+  YYPTRDIFF_T yycapacity;
 };
 
 struct yySemanticOption {
@@ -568,7 +566,7 @@ struct yyGLRStack {
   YYJMP_BUF yyexception_buffer;
   yyGLRStackItem* yyitems;
   yyGLRStackItem* yynextFree;
-  ptrdiff_t yyspaceLeft;
+  YYPTRDIFF_T yyspaceLeft;
   yyGLRState* yysplitPoint;
   yyGLRState* yylastDeleted;
   yyGLRStateSet yytops;
@@ -680,7 +678,7 @@ yysymbol_name (yysymbol_kind_t yysymbol)
    multiple parsers can coexist.  */
 int yydebug;
 
-static void yypstack (yyGLRStack* yystackp, ptrdiff_t yyk)
+static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
   YY_ATTRIBUTE_UNUSED;
 static void yypdumpstack (yyGLRStack* yystackp)
   YY_ATTRIBUTE_UNUSED;
@@ -696,7 +694,7 @@ static void yypdumpstack (yyGLRStack* yystackp)
          [simple],
 [[]],
 [[#ifndef yystrlen
-# define yystrlen(S) (YY_CAST (ptrdiff_t, strlen (S)))
+# define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
 #endif
 
 ]b4_parse_error_bmatch(
@@ -731,12 +729,12 @@ yystpcpy (char *yydest, const char *yysrc)
    backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
    null, do not copy; instead, return the length of what the result
    would have been.  */
-static ptrdiff_t
+static YYPTRDIFF_T
 yytnamerr (char *yyres, const char *yystr)
 {
   if (*yystr == '"')
     {
-      ptrdiff_t yyn = 0;
+      YYPTRDIFF_T yyn = 0;
       char const *yyp = yystr;
 
       for (;;)
@@ -1104,7 +1102,7 @@ yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
  *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
  *  stack #YYK of *YYSTACKP. */
 static void
-yyaddDeferredAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyGLRState* yystate,
+yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                      yyGLRState* yyrhs, yyRuleNum yyrule)
 {
   yySemanticOption* yynewOption =
@@ -1136,14 +1134,14 @@ yyinitStateSet (yyGLRStateSet* yyset)
   yyset->yycapacity = 16;
   yyset->yystates
     = YY_CAST (yyGLRState**,
-               YYMALLOC (YY_CAST (size_t, yyset->yycapacity)
+               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                          * sizeof yyset->yystates[0]));
   if (! yyset->yystates)
     return yyfalse;
   yyset->yystates[0] = YY_NULLPTR;
   yyset->yylookaheadNeeds
     = YY_CAST (yybool*,
-               YYMALLOC (YY_CAST (size_t, yyset->yycapacity)
+               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                          * sizeof yyset->yylookaheadNeeds[0]));
   if (! yyset->yylookaheadNeeds)
     {
@@ -1152,7 +1150,7 @@ yyinitStateSet (yyGLRStateSet* yyset)
     }
   memset (yyset->yylookaheadNeeds,
           0,
-          YY_CAST (size_t, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
+          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
   return yytrue;
 }
 
@@ -1165,14 +1163,14 @@ static void yyfreeStateSet (yyGLRStateSet* yyset)
 /** Initialize *YYSTACKP to a single empty stack, with total maximum
  *  capacity for all stacks of YYSIZE.  */
 static yybool
-yyinitGLRStack (yyGLRStack* yystackp, ptrdiff_t yysize)
+yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
 {
   yystackp->yyerrState = 0;
   yynerrs = 0;
   yystackp->yyspaceLeft = yysize;
   yystackp->yyitems
     = YY_CAST (yyGLRStackItem*,
-               YYMALLOC (YY_CAST (size_t, yysize)
+               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                          * sizeof yystackp->yynextFree[0]));
   if (!yystackp->yyitems)
     return yyfalse;
@@ -1198,9 +1196,9 @@ yyexpandGLRStack (yyGLRStack* yystackp)
 {
   yyGLRStackItem* yynewItems;
   yyGLRStackItem* yyp0, *yyp1;
-  ptrdiff_t yynewSize;
-  ptrdiff_t yyn;
-  ptrdiff_t yysize = yystackp->yynextFree - yystackp->yyitems;
+  YYPTRDIFF_T yynewSize;
+  YYPTRDIFF_T yyn;
+  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
   if (YYMAXDEPTH - YYHEADROOM < yysize)
     yyMemoryExhausted (yystackp);
   yynewSize = 2*yysize;
@@ -1208,7 +1206,7 @@ yyexpandGLRStack (yyGLRStack* yystackp)
     yynewSize = YYMAXDEPTH;
   yynewItems
     = YY_CAST (yyGLRStackItem*,
-               YYMALLOC (YY_CAST (size_t, yynewSize)
+               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                          * sizeof yynewItems[0]));
   if (! yynewItems)
     yyMemoryExhausted (yystackp);
@@ -1273,7 +1271,7 @@ yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
 
 /** Invalidate stack #YYK in *YYSTACKP.  */
 static inline void
-yymarkStackDeleted (yyGLRStack* yystackp, ptrdiff_t yyk)
+yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
 {
   if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
     yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
@@ -1297,7 +1295,7 @@ yyundeleteLastStack (yyGLRStack* yystackp)
 static inline void
 yyremoveDeletes (yyGLRStack* yystackp)
 {
-  ptrdiff_t yyi, yyj;
+  YYPTRDIFF_T yyi, yyj;
   yyi = yyj = 0;
   while (yyj < yystackp->yytops.yysize)
     {
@@ -1330,8 +1328,8 @@ yyremoveDeletes (yyGLRStack* yystackp)
  * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
  * value *YYVALP and source location *YYLOCP.  */
 static inline void
-yyglrShift (yyGLRStack* yystackp, ptrdiff_t yyk, yy_state_t yylrState,
-            ptrdiff_t yyposn,
+yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
+            YYPTRDIFF_T yyposn,
             YYSTYPE* yyvalp]b4_locations_if([, YYLTYPE* yylocp])[)
 {
   yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
@@ -1351,8 +1349,8 @@ yyglrShift (yyGLRStack* yystackp, ptrdiff_t yyk, yy_state_t yylrState,
  *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
  *  semantic value of YYRHS under the action for YYRULE.  */
 static inline void
-yyglrShiftDefer (yyGLRStack* yystackp, ptrdiff_t yyk, yy_state_t yylrState,
-                 ptrdiff_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
+yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
+                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
 {
   yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
   YY_ASSERT (yynewState->yyisState);
@@ -1382,7 +1380,7 @@ yyglrShiftDefer (yyGLRStack* yystackp, ptrdiff_t yyk, yy_state_t yylrState,
 `----------------------------------------------------------------------*/
 
 static inline void
-yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, ptrdiff_t yyk,
+yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                  yyRuleNum yyrule]b4_user_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);]b4_locations_if([
@@ -1415,7 +1413,7 @@ yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, ptrdiff_t yyk,
  *  and *YYLOCP to the computed location (if any).  Return value is as
  *  for userAction.  */
 static inline YYRESULTTAG
-yydoAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
+yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             YYSTYPE* yyvalp]b4_locuser_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);
@@ -1467,10 +1465,10 @@ yydoAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
  *  added to the options for the existing state's semantic value.
  */
 static inline YYRESULTTAG
-yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
+yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
              yybool yyforceEval]b4_user_formals[)
 {
-  ptrdiff_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;
+  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;
 
   if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
     {
@@ -1492,7 +1490,7 @@ yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
     }
   else
     {
-      ptrdiff_t yyi;
+      YYPTRDIFF_T yyi;
       int yyn;
       yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
       yy_state_t yynewLRState;
@@ -1534,8 +1532,8 @@ yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
   return yyok;
 }
 
-static ptrdiff_t
-yysplitStack (yyGLRStack* yystackp, ptrdiff_t yyk)
+static YYPTRDIFF_T
+yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
 {
   if (yystackp->yysplitPoint == YY_NULLPTR)
     {
@@ -1544,8 +1542,8 @@ yysplitStack (yyGLRStack* yystackp, ptrdiff_t yyk)
     }
   if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
     {
-      ptrdiff_t state_size = sizeof yystackp->yytops.yystates[0];
-      ptrdiff_t half_max_capacity = YYSIZEMAX / 2 / state_size;
+      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
+      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
       if (half_max_capacity < yystackp->yytops.yycapacity)
         yyMemoryExhausted (yystackp);
       yystackp->yytops.yycapacity *= 2;
@@ -1554,7 +1552,7 @@ yysplitStack (yyGLRStack* yystackp, ptrdiff_t yyk)
         yyGLRState** yynewStates
           = YY_CAST (yyGLRState**,
                      YYREALLOC (yystackp->yytops.yystates,
-                                (YY_CAST (size_t, yystackp->yytops.yycapacity)
+                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                  * sizeof yynewStates[0])));
         if (yynewStates == YY_NULLPTR)
           yyMemoryExhausted (yystackp);
@@ -1565,7 +1563,7 @@ yysplitStack (yyGLRStack* yystackp, ptrdiff_t yyk)
         yybool* yynewLookaheadNeeds
           = YY_CAST (yybool*,
                      YYREALLOC (yystackp->yytops.yylookaheadNeeds,
-                                (YY_CAST (size_t, yystackp->yytops.yycapacity)
+                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                  * sizeof yynewLookaheadNeeds[0])));
         if (yynewLookaheadNeeds == YY_NULLPTR)
           yyMemoryExhausted (yystackp);
@@ -1996,8 +1994,8 @@ yycompressStack (yyGLRStack* yystackp)
 }
 
 static YYRESULTTAG
-yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
-                   ptrdiff_t yyposn]b4_pure_formals[)
+yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
+                   YYPTRDIFF_T yyposn]b4_pure_formals[)
 {
   while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
     {
@@ -2040,7 +2038,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
           for (/* nothing */; *yyconflicts; yyconflicts += 1)
             {
               YYRESULTTAG yyflag;
-              ptrdiff_t yynewStack = yysplitStack (yystackp, yyk);
+              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
               YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                            YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
               yyflag = yyglrReduce (yystackp, yynewStack,
@@ -2228,7 +2226,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
      one per "expected"). */
   yysymbol_kind_t yyarg[YYARGS_MAX];
   /* Cumulated lengths of YYARG.  */
-  ptrdiff_t yysize = 0;
+  YYPTRDIFF_T yysize = 0;
 
   /* Actual size of YYARG. */
   int yycount
@@ -2259,11 +2257,11 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
     int yyi;
     for (yyi = 0; yyi < yycount; ++yyi)
       {
-        ptrdiff_t yysz
+        YYPTRDIFF_T yysz
           = ]b4_parse_error_case(
                      [verbose], [[yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]])]],
                      [[yystrlen (yysymbol_name (yyarg[yyi]))]]);[
-        if (YYSIZEMAX - yysize < yysz)
+        if (YYSIZE_MAXIMUM - yysize < yysz)
           yysize_overflow = yytrue;
         else
           yysize += yysz;
@@ -2271,7 +2269,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   }
 
   if (!yysize_overflow)
-    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (size_t, yysize)));
+    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (YYSIZE_T, yysize)));
 
   if (yymsg)
     {
@@ -2348,7 +2346,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 
   /* Reduce to one stack.  */
   {
-    ptrdiff_t yyk;
+    YYPTRDIFF_T yyk;
     for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
       if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
         break;
@@ -2423,7 +2421,7 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
   int yyresult;
   yyGLRStack yystack;
   yyGLRStack* const yystackp = &yystack;
-  ptrdiff_t yyposn;
+  YYPTRDIFF_T yyposn;
 
   YY_DPRINTF ((stderr, "Starting parse\n"));
 
@@ -2505,7 +2503,7 @@ b4_dollar_popdef])[]dnl
       while (yytrue)
         {
           yysymbol_kind_t yytoken_to_shift;
-          ptrdiff_t yys;
+          YYPTRDIFF_T yys;
 
           for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
             yystackp->yytops.yylookaheadNeeds[yys] = yychar != ]b4_symbol(-2, id)[;
@@ -2612,8 +2610,8 @@ b4_dollar_popdef])[]dnl
       yyGLRState** yystates = yystack.yytops.yystates;
       if (yystates)
         {
-          ptrdiff_t yysize = yystack.yytops.yysize;
-          ptrdiff_t yyk;
+          YYPTRDIFF_T yysize = yystack.yytops.yysize;
+          YYPTRDIFF_T yyk;
           for (yyk = 0; yyk < yysize; yyk += 1)
             if (yystates[yyk])
               {
@@ -2660,7 +2658,7 @@ yypstates (yyGLRState* yyst)
 }
 
 static void
-yypstack (yyGLRStack* yystackp, ptrdiff_t yyk)
+yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
 {
   yypstates (yystackp->yytops.yystates[yyk]);
 }
@@ -2705,7 +2703,7 @@ yypdumpstack (yyGLRStack* yystackp)
 
   YY_FPRINTF ((stderr, "Tops:"));
   {
-    ptrdiff_t yyi;
+    YYPTRDIFF_T yyi;
     for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
       YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                    YYINDEX (yystackp->yytops.yystates[yyi])));
