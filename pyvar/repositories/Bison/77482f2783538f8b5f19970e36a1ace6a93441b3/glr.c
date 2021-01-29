@@ -964,6 +964,7 @@ yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
 {
   yySemanticOption* yynewOption =
     &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
+  YYASSERT (!yynewOption->yyisState);
   yynewOption->yystate = yyrhs;
   yynewOption->yyrule = yyrule;
   if (yystackp->yytops.yylookaheadNeeds[yyk])
@@ -1199,6 +1200,7 @@ yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
                  size_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
 {
   yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
+  YYASSERT (yynewState->yyisState);
 
   yynewState->yylrState = yylrState;
   yynewState->yyposn = yyposn;
@@ -2501,6 +2503,8 @@ yypdumpstack (yyGLRStack* yystackp)
                  (unsigned long int) (yyp - yystackp->yyitems));
       if (*(yybool *) yyp)
         {
+          YYASSERT (yyp->yystate.yyisState);
+          YYASSERT (yyp->yyoption.yyisState);
           YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
                      yyp->yystate.yyresolved, yyp->yystate.yylrState,
                      (unsigned long int) yyp->yystate.yyposn,
@@ -2512,6 +2516,8 @@ yypdumpstack (yyGLRStack* yystackp)
         }
       else
         {
+          YYASSERT (!yyp->yystate.yyisState);
+          YYASSERT (!yyp->yyoption.yyisState);
           YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
                      yyp->yyoption.yyrule - 1,
                      (long int) YYINDEX (yyp->yyoption.yystate),
