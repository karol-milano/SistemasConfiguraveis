@@ -259,7 +259,9 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 ]b4_user_post_prologue[
 ]b4_percent_code_get[]dnl
 
-[#include <stdio.h>
+[#include <stddef.h>
+#include <stdint.h>
+#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
@@ -285,7 +287,7 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 # define YYREALLOC realloc
 #endif
 
-#define YYSIZEMAX ((size_t) -1)
+#define YYSIZEMAX (PTRDIFF_MAX < SIZE_MAX ? PTRDIFF_MAX : (ptrdiff_t) SIZE_MAX)
 
 #ifdef __cplusplus
   typedef bool yybool;
@@ -293,7 +295,7 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 # define yyfalse false
 #else
   /* When we move to stdbool, get rid of the various casts to yybool.  */
-  typedef unsigned char yybool;
+  typedef signed char yybool;
 # define yytrue 1
 # define yyfalse 0
 #endif
@@ -349,7 +351,7 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 ]b4_api_token_raw_if(dnl
 [[#define YYTRANSLATE(YYX) (YYX)]],
 [[#define YYTRANSLATE(YYX)                         \
-  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
+  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex.  */
@@ -490,7 +492,7 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 int yydebug;
 
 struct yyGLRStack;
-static void yypstack (struct yyGLRStack* yystackp, size_t yyk)
+static void yypstack (struct yyGLRStack* yystackp, ptrdiff_t yyk)
   YY_ATTRIBUTE_UNUSED;
 static void yypdumpstack (struct yyGLRStack* yystackp)
   YY_ATTRIBUTE_UNUSED;
@@ -574,12 +576,12 @@ yystpcpy (char *yydest, const char *yysrc)
    backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
    null, do not copy; instead, return the length of what the result
    would have been.  */
-static size_t
+static ptrdiff_t
 yytnamerr (char *yyres, const char *yystr)
 {
   if (*yystr == '"')
     {
-      size_t yyn = 0;
+      ptrdiff_t yyn = 0;
       char const *yyp = yystr;
 
       for (;;)
@@ -611,9 +613,9 @@ yytnamerr (char *yyres, const char *yystr)
     }
 
   if (! yyres)
-    return strlen (yystr);
+    return (ptrdiff_t) strlen (yystr);
 
-  return (size_t) (yystpcpy (yyres, yystr) - yyres);
+  return yystpcpy (yyres, yystr) - yyres;
 }
 # endif
 
@@ -648,7 +650,7 @@ struct yyGLRState {
   /** Preceding state in this stack */
   yyGLRState* yypred;
   /** Source position of the last token produced by my symbol */
-  size_t yyposn;
+  ptrdiff_t yyposn;
   union {
     /** First in a chain of alternative reductions producing the
      *  nonterminal corresponding to this state, threaded through
@@ -668,7 +670,7 @@ struct yyGLRStateSet {
    *  operation, yylookaheadNeeds[0] is not maintained since it would merely
    *  duplicate yychar != YYEMPTY.  */
   yybool* yylookaheadNeeds;
-  size_t yysize, yycapacity;
+  ptrdiff_t yysize, yycapacity;
 };
 
 struct yySemanticOption {
@@ -708,7 +710,7 @@ struct yyGLRStack {
   YYJMP_BUF yyexception_buffer;
   yyGLRStackItem* yyitems;
   yyGLRStackItem* yynextFree;
-  size_t yyspaceLeft;
+  ptrdiff_t yyspaceLeft;
   yyGLRState* yysplitPoint;
   yyGLRState* yylastDeleted;
   yyGLRStateSet yytops;
@@ -1066,7 +1068,7 @@ yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
  *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
  *  stack #YYK of *YYSTACKP. */
 static void
-yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
+yyaddDeferredAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyGLRState* yystate,
                      yyGLRState* yyrhs, yyRuleNum yyrule)
 {
   yySemanticOption* yynewOption =
@@ -1097,19 +1099,21 @@ yyinitStateSet (yyGLRStateSet* yyset)
   yyset->yysize = 1;
   yyset->yycapacity = 16;
   yyset->yystates
-    = (yyGLRState**) YYMALLOC (yyset->yycapacity * sizeof yyset->yystates[0]);
+    = (yyGLRState**) YYMALLOC ((size_t) yyset->yycapacity
+                               * sizeof yyset->yystates[0]);
   if (! yyset->yystates)
     return yyfalse;
   yyset->yystates[0] = YY_NULLPTR;
   yyset->yylookaheadNeeds
-    = (yybool*) YYMALLOC (yyset->yycapacity * sizeof yyset->yylookaheadNeeds[0]);
+    = (yybool*) YYMALLOC ((size_t) yyset->yycapacity
+                          * sizeof yyset->yylookaheadNeeds[0]);
   if (! yyset->yylookaheadNeeds)
     {
       YYFREE (yyset->yystates);
       return yyfalse;
     }
   memset (yyset->yylookaheadNeeds,
-          0, yyset->yycapacity * sizeof yyset->yylookaheadNeeds[0]);
+          0, (size_t) yyset->yycapacity * sizeof yyset->yylookaheadNeeds[0]);
   return yytrue;
 }
 
@@ -1122,13 +1126,14 @@ static void yyfreeStateSet (yyGLRStateSet* yyset)
 /** Initialize *YYSTACKP to a single empty stack, with total maximum
  *  capacity for all stacks of YYSIZE.  */
 static yybool
-yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
+yyinitGLRStack (yyGLRStack* yystackp, ptrdiff_t yysize)
 {
   yystackp->yyerrState = 0;
   yynerrs = 0;
   yystackp->yyspaceLeft = yysize;
   yystackp->yyitems =
-    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystackp->yynextFree[0]);
+    (yyGLRStackItem*) YYMALLOC ((size_t) yysize
+                                * sizeof yystackp->yynextFree[0]);
   if (!yystackp->yyitems)
     return yyfalse;
   yystackp->yynextFree = yystackp->yyitems;
@@ -1152,15 +1157,16 @@ yyexpandGLRStack (yyGLRStack* yystackp)
 {
   yyGLRStackItem* yynewItems;
   yyGLRStackItem* yyp0, *yyp1;
-  size_t yynewSize;
-  size_t yyn;
-  size_t yysize = (size_t) (yystackp->yynextFree - yystackp->yyitems);
+  ptrdiff_t yynewSize;
+  ptrdiff_t yyn;
+  ptrdiff_t yysize = yystackp->yynextFree - yystackp->yyitems;
   if (YYMAXDEPTH - YYHEADROOM < yysize)
     yyMemoryExhausted (yystackp);
   yynewSize = 2*yysize;
   if (YYMAXDEPTH < yynewSize)
     yynewSize = YYMAXDEPTH;
-  yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
+  yynewItems = (yyGLRStackItem*) YYMALLOC ((size_t) yynewSize
+                                           * sizeof yynewItems[0]);
   if (! yynewItems)
     yyMemoryExhausted (yystackp);
   for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
@@ -1224,7 +1230,7 @@ yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
 
 /** Invalidate stack #YYK in *YYSTACKP.  */
 static inline void
-yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
+yymarkStackDeleted (yyGLRStack* yystackp, ptrdiff_t yyk)
 {
   if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
     yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
@@ -1248,7 +1254,7 @@ yyundeleteLastStack (yyGLRStack* yystackp)
 static inline void
 yyremoveDeletes (yyGLRStack* yystackp)
 {
-  size_t yyi, yyj;
+  ptrdiff_t yyi, yyj;
   yyi = yyj = 0;
   while (yyj < yystackp->yytops.yysize)
     {
@@ -1272,8 +1278,8 @@ yyremoveDeletes (yyGLRStack* yystackp)
             yystackp->yytops.yylookaheadNeeds[yyi];
           if (yyj != yyi)
             {
-              YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
-                          (unsigned long) yyi, (unsigned long) yyj));
+              YYDPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
+                          (long) yyi, (long) yyj));
             }
           yyj += 1;
         }
@@ -1285,8 +1291,8 @@ yyremoveDeletes (yyGLRStack* yystackp)
  * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
  * value *YYVALP and source location *YYLOCP.  */
 static inline void
-yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
-            size_t yyposn,
+yyglrShift (yyGLRStack* yystackp, ptrdiff_t yyk, yyStateNum yylrState,
+            ptrdiff_t yyposn,
             YYSTYPE* yyvalp]b4_locations_if([, YYLTYPE* yylocp])[)
 {
   yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
@@ -1306,8 +1312,8 @@ yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
  *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
  *  semantic value of YYRHS under the action for YYRULE.  */
 static inline void
-yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
-                 size_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
+yyglrShiftDefer (yyGLRStack* yystackp, ptrdiff_t yyk, yyStateNum yylrState,
+                 ptrdiff_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
 {
   yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
   YYASSERT (yynewState->yyisState);
@@ -1337,15 +1343,14 @@ yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
 `----------------------------------------------------------------------*/
 
 static inline void
-yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, size_t yyk,
+yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, ptrdiff_t yyk,
                  yyRuleNum yyrule]b4_user_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);]b4_locations_if([
   int yylow = 1;])[
   int yyi;
-  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %d):\n",
-             (unsigned long) yyk, yyrule - 1,
-             yyrline[yyrule]);
+  YYFPRINTF (stderr, "Reducing stack %ld by rule %d (line %d):\n",
+             (long) yyk, yyrule - 1, yyrline[yyrule]);
   if (! yynormal)
     yyfillin (yyvsp, 1, -yynrhs);
   /* The symbols being reduced.  */
@@ -1371,7 +1376,7 @@ yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, size_t yyk,
  *  and *YYLOCP to the computed location (if any).  Return value is as
  *  for userAction.  */
 static inline YYRESULTTAG
-yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
+yydoAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
             YYSTYPE* yyvalp]b4_locuser_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);
@@ -1382,7 +1387,7 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       yyGLRStackItem* yyrhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
       YYASSERT (yyk == 0);
       yystackp->yynextFree -= yynrhs;
-      yystackp->yyspaceLeft += (size_t) yynrhs;
+      yystackp->yyspaceLeft += yynrhs;
       yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
       YY_REDUCE_PRINT ((yytrue, yyrhs, yyk, yyrule]b4_user_args[));
       return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
@@ -1422,10 +1427,10 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
  *  added to the options for the existing state's semantic value.
  */
 static inline YYRESULTTAG
-yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
+yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
              yybool yyforceEval]b4_user_formals[)
 {
-  size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;
+  ptrdiff_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;
 
   if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
     {
@@ -1435,8 +1440,8 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval]b4_locuser_args([&yyloc])[);
       if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
         {
-          YYDPRINTF ((stderr, "Parse on stack %lu rejected by rule #%d.\n",
-                     (unsigned long) yyk, yyrule - 1));
+          YYDPRINTF ((stderr, "Parse on stack %ld rejected by rule #%d.\n",
+                     (long) yyk, yyrule - 1));
         }
       if (yyflag != yyok)
         return yyflag;
@@ -1448,7 +1453,7 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
     }
   else
     {
-      size_t yyi;
+      ptrdiff_t yyi;
       int yyn;
       yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
       yyStateNum yynewLRState;
@@ -1462,9 +1467,9 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       yyupdateSplit (yystackp, yys);
       yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
       YYDPRINTF ((stderr,
-                  "Reduced stack %lu by rule #%d; action deferred.  "
+                  "Reduced stack %ld by rule #%d; action deferred.  "
                   "Now in state %d.\n",
-                  (unsigned long) yyk, yyrule - 1, yynewLRState));
+                  (long) yyk, yyrule - 1, yynewLRState));
       for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
         if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
           {
@@ -1476,9 +1481,8 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
                   {
                     yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                     yymarkStackDeleted (yystackp, yyk);
-                    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
-                                (unsigned long) yyk,
-                                (unsigned long) yyi));
+                    YYDPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
+                                (long) yyk, (long) yyi));
                     return yyok;
                   }
                 yyp = yyp->yypred;
@@ -1490,8 +1494,8 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
   return yyok;
 }
 
-static size_t
-yysplitStack (yyGLRStack* yystackp, size_t yyk)
+static ptrdiff_t
+yysplitStack (yyGLRStack* yystackp, ptrdiff_t yyk)
 {
   if (yystackp->yysplitPoint == YY_NULLPTR)
     {
@@ -1502,15 +1506,15 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
     {
       yyGLRState** yynewStates = YY_NULLPTR;
       yybool* yynewLookaheadNeeds;
+      ptrdiff_t half_max_capacity = YYSIZEMAX / (2 * sizeof yynewStates[0]);
 
-      if (yystackp->yytops.yycapacity
-          > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
+      if (half_max_capacity < yystackp->yytops.yycapacity)
         yyMemoryExhausted (yystackp);
       yystackp->yytops.yycapacity *= 2;
 
       yynewStates =
         (yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
-                                  (yystackp->yytops.yycapacity
+                                  ((size_t) yystackp->yytops.yycapacity
                                    * sizeof yynewStates[0]));
       if (yynewStates == YY_NULLPTR)
         yyMemoryExhausted (yystackp);
@@ -1518,7 +1522,7 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
 
       yynewLookaheadNeeds =
         (yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
-                             (yystackp->yytops.yycapacity
+                             ((size_t) yystackp->yytops.yycapacity
                               * sizeof yynewLookaheadNeeds[0]));
       if (yynewLookaheadNeeds == YY_NULLPTR)
         yyMemoryExhausted (yystackp);
@@ -1720,10 +1724,10 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
                yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
                yyx->yyrule - 1);
   else
-    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
+    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
-               yyx->yyrule - 1, (unsigned long) (yys->yyposn + 1),
-               (unsigned long) yyx->yystate->yyposn);
+               yyx->yyrule - 1, (long) (yys->yyposn + 1),
+               (long) yyx->yystate->yyposn);
   for (yyi = 1; yyi <= yynrhs; yyi += 1)
     {
       if (yystates[yyi]->yyresolved)
@@ -1732,10 +1736,10 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
             YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
                        yytokenName (yystos[yystates[yyi]->yylrState]));
           else
-            YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
+            YYFPRINTF (stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                        yytokenName (yystos[yystates[yyi]->yylrState]),
-                       (unsigned long) (yystates[yyi-1]->yyposn + 1),
-                       (unsigned long) yystates[yyi]->yyposn);
+                       (long) (yystates[yyi-1]->yyposn + 1),
+                       (long) yystates[yyi]->yyposn);
         }
       else
         yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
@@ -1930,9 +1934,9 @@ yycompressStack (yyGLRStack* yystackp)
        yyr = yyp, yyp = yyq, yyq = yyp->yypred)
     yyp->yypred = yyr;
 
-  yystackp->yyspaceLeft += (size_t) (yystackp->yynextFree - yystackp->yyitems);
+  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
   yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
-  yystackp->yyspaceLeft -= (size_t) (yystackp->yynextFree - yystackp->yyitems);
+  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
   yystackp->yysplitPoint = YY_NULLPTR;
   yystackp->yylastDeleted = YY_NULLPTR;
 
@@ -1948,14 +1952,13 @@ yycompressStack (yyGLRStack* yystackp)
 }
 
 static YYRESULTTAG
-yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
-                   size_t yyposn]b4_pure_formals[)
+yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
+                   ptrdiff_t yyposn]b4_pure_formals[)
 {
   while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
     {
       yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
-      YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
-                  (unsigned long) yyk, yystate));
+      YYDPRINTF ((stderr, "Stack %ld Entering state %d\n", yyk, yystate));
 
       YYASSERT (yystate != YYFINAL);
 
@@ -1965,8 +1968,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
           yyRuleNum yyrule = yydefaultAction (yystate);
           if (yyrule == 0)
             {
-              YYDPRINTF ((stderr, "Stack %lu dies.\n",
-                          (unsigned long) yyk));
+              YYDPRINTF ((stderr, "Stack %ld dies.\n", (long) yyk));
               yymarkStackDeleted (yystackp, yyk);
               return yyok;
             }
@@ -1974,9 +1976,9 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
           if (yyflag == yyerr)
             {
               YYDPRINTF ((stderr,
-                          "Stack %lu dies "
+                          "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
-                          (unsigned long) yyk));
+                          (long) yyk));
               yymarkStackDeleted (yystackp, yyk);
               return yyok;
             }
@@ -1996,10 +1998,9 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
           while (*yyconflicts != 0)
             {
               YYRESULTTAG yyflag;
-              size_t yynewStack = yysplitStack (yystackp, yyk);
-              YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
-                          (unsigned long) yynewStack,
-                          (unsigned long) yyk));
+              ptrdiff_t yynewStack = yysplitStack (yystackp, yyk);
+              YYDPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
+                          (long) yynewStack, (long) yyk));
               yyflag = yyglrReduce (yystackp, yynewStack,
                                     *yyconflicts,
                                     yyimmediate[*yyconflicts]]b4_user_args[);
@@ -2008,8 +2009,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
                                           yyposn]b4_pure_args[));
               else if (yyflag == yyerr)
                 {
-                  YYDPRINTF ((stderr, "Stack %lu dies.\n",
-                              (unsigned long) yynewStack));
+                  YYDPRINTF ((stderr, "Stack %ld dies.\n", (long) yynewStack));
                   yymarkStackDeleted (yystackp, yynewStack);
                 }
               else
@@ -2021,8 +2021,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
             break;
           else if (yyisErrorAction (yyaction))
             {
-              YYDPRINTF ((stderr, "Stack %lu dies.\n",
-                          (unsigned long) yyk));
+              YYDPRINTF ((stderr, "Stack %ld dies.\n", (long) yyk));
               yymarkStackDeleted (yystackp, yyk);
               break;
             }
@@ -2033,9 +2032,9 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
               if (yyflag == yyerr)
                 {
                   YYDPRINTF ((stderr,
-                              "Stack %lu dies "
+                              "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
-                              (unsigned long) yyk));
+                              (long) yyk));
                   yymarkStackDeleted (yystackp, yyk);
                   break;
                 }
@@ -2057,8 +2056,8 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 #else
   {
   yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
-  size_t yysize0 = yytnamerr (YY_NULLPTR, yytokenName (yytoken));
-  size_t yysize = yysize0;
+  ptrdiff_t yysize0 = yytnamerr (YY_NULLPTR, yytokenName (yytoken));
+  ptrdiff_t yysize = yysize0;
   yybool yysize_overflow = yyfalse;
   char* yymsg = YY_NULLPTR;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
@@ -2119,10 +2118,11 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
                   }
                 yyarg[yycount++] = yytokenName (yyx);
                 {
-                  size_t yysz = yysize + yytnamerr (YY_NULLPTR, yytokenName (yyx));
-                  if (yysz < yysize)
+                  ptrdiff_t yysz = yytnamerr (YY_NULLPTR, yytokenName (yyx));
+                  if (YYSIZEMAX - yysize < yysz)
                     yysize_overflow = yytrue;
-                  yysize = yysz;
+                  else
+                    yysize += yysz;
                 }
               }
         }
@@ -2145,14 +2145,15 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
     }
 
   {
-    size_t yysz = yysize + strlen (yyformat);
-    if (yysz < yysize)
+    ptrdiff_t yysz = (ptrdiff_t) strlen (yyformat);
+    if (YYSIZEMAX - yysize < yysz)
       yysize_overflow = yytrue;
-    yysize = yysz;
+    else
+      yysize += yysz;
   }
 
   if (!yysize_overflow)
-    yymsg = (char *) YYMALLOC (yysize);
+    yymsg = (char *) YYMALLOC ((size_t) yysize);
 
   if (yymsg)
     {
@@ -2229,7 +2230,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 
   /* Reduce to one stack.  */
   {
-    size_t yyk;
+    ptrdiff_t yyk;
     for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
       if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
         break;
@@ -2303,7 +2304,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   int yyresult;
   yyGLRStack yystack;
   yyGLRStack* const yystackp = &yystack;
-  size_t yyposn;
+  ptrdiff_t yyposn;
 
   YYDPRINTF ((stderr, "Starting parse\n"));
 
@@ -2383,7 +2384,7 @@ b4_dollar_popdef])[]dnl
       while (yytrue)
         {
           yySymbol yytoken_to_shift;
-          size_t yys;
+          ptrdiff_t yys;
 
           for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
             yystackp->yytops.yylookaheadNeeds[yys] = (yybool) (yychar != YYEMPTY);
@@ -2437,12 +2438,12 @@ b4_dollar_popdef])[]dnl
               int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                               &yyconflicts);
               /* Note that yyconflicts were handled by yyprocessOneStack.  */
-              YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long) yys));
+              YYDPRINTF ((stderr, "On stack %ld, ", (long) yys));
               YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
               yyglrShift (&yystack, yys, yyaction, yyposn,
                           &yylval]b4_locations_if([, &yylloc])[);
-              YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
-                          (unsigned long) yys,
+              YYDPRINTF ((stderr, "Stack %ld now in state #%d\n",
+                          (long) yys,
                           yystack.yytops.yystates[yys]->yylrState));
             }
 
@@ -2490,8 +2491,8 @@ b4_dollar_popdef])[]dnl
       yyGLRState** yystates = yystack.yytops.yystates;
       if (yystates)
         {
-          size_t yysize = yystack.yytops.yysize;
-          size_t yyk;
+          ptrdiff_t yysize = yystack.yytops.yysize;
+          ptrdiff_t yyk;
           for (yyk = 0; yyk < yysize; yyk += 1)
             if (yystates[yyk])
               {
@@ -2524,8 +2525,7 @@ yy_yypstack (yyGLRState* yys)
       yy_yypstack (yys->yypred);
       YYFPRINTF (stderr, " -> ");
     }
-  YYFPRINTF (stderr, "%d@@%lu", yys->yylrState,
-             (unsigned long) yys->yyposn);
+  YYFPRINTF (stderr, "%d@@%ld", yys->yylrState, (long) yys->yyposn);
 }
 
 static void
@@ -2539,7 +2539,7 @@ yypstates (yyGLRState* yyst)
 }
 
 static void
-yypstack (yyGLRStack* yystackp, size_t yyk)
+yypstack (yyGLRStack* yystackp, ptrdiff_t yyk)
 {
   yypstates (yystackp->yytops.yystates[yyk]);
 }
@@ -2552,18 +2552,18 @@ static void
 yypdumpstack (yyGLRStack* yystackp)
 {
   yyGLRStackItem* yyp;
-  size_t yyi;
+  ptrdiff_t yyi;
   for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
     {
-      YYFPRINTF (stderr, "%3lu. ",
-                 (unsigned long) (yyp - yystackp->yyitems));
+      YYFPRINTF (stderr, "%3ld. ",
+                 (long) (yyp - yystackp->yyitems));
       if (*(yybool *) yyp)
         {
           YYASSERT (yyp->yystate.yyisState);
           YYASSERT (yyp->yyoption.yyisState);
-          YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
+          YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                      yyp->yystate.yyresolved, yyp->yystate.yylrState,
-                     (unsigned long) yyp->yystate.yyposn,
+                     (long) yyp->yystate.yyposn,
                      (long) YYINDEX (yyp->yystate.yypred));
           if (! yyp->yystate.yyresolved)
             YYFPRINTF (stderr, ", firstVal: %ld",
@@ -2583,7 +2583,7 @@ yypdumpstack (yyGLRStack* yystackp)
     }
   YYFPRINTF (stderr, "Tops:");
   for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
-    YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long) yyi,
+    YYFPRINTF (stderr, "%ld: %ld; ", (long) yyi,
                (long) YYINDEX (yystackp->yytops.yystates[yyi]));
   YYFPRINTF (stderr, "\n");
 }
