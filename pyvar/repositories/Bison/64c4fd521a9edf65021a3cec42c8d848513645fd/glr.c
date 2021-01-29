@@ -249,6 +249,10 @@ b4_syncline([@oline@], [@ofile@])
 # endif
 #endif
 
+#ifndef YYASSERT
+# define YYASSERT(condition) ((void) ((condition) || (abort (), 0)))
+#endif
+
 #ifndef ATTRIBUTE_UNUSED
 # define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
 #endif
@@ -649,8 +653,7 @@ yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
   s = yyvsp[yylow0].yystate.yypred;
   for (i = yylow0-1; i >= yylow1; i -= 1)
     {
-      if (! s->yyresolved)
-	abort ();
+      YYASSERT (s->yyresolved);
       yyvsp[i].yystate.yyresolved = yytrue;
       yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
       yyvsp[i].yystate.yyloc = s->yyloc;
@@ -1099,8 +1102,7 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
     {
       /* Standard special case: single stack. */
       yyGLRStackItem* rhs = (yyGLRStackItem*) yystack->yytops.yystates[yyk];
-      if (yyk != 0)
-	abort ();
+      YYASSERT (yyk == 0);
       yystack->yynextFree -= yynrhs;
       yystack->yyspaceLeft += yynrhs;
       yystack->yytops.yystates[0] = & yystack->yynextFree[-1].yystate;
@@ -1117,8 +1119,7 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
       for (yyi = 0; yyi < yynrhs; yyi += 1)
 	{
 	  yys = yys->yypred;
-	  if (yys == NULL)
-	    abort ();
+	  YYASSERT (yys);
 	}
       yyupdateSplit (yystack, yys);
       yystack->yytops.yystates[yyk] = yys;
@@ -1194,8 +1195,7 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 	   0 < yyn; yyn -= 1)
 	{
 	  yys = yys->yypred;
-	  if (yys == NULL)
-	    abort ();
+	  YYASSERT (yys);
 	}
       yyupdateSplit (yystack, yys);
       yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
@@ -1232,8 +1232,7 @@ yysplitStack (yyGLRStack* yystack, int yyk)
 {
   if (yystack->yysplitPoint == NULL)
     {
-      if (yyk != 0)
-	abort ();
+      YYASSERT (yyk == 0);
       yystack->yysplitPoint = yystack->yytops.yystates[yyk];
     }
   if (yystack->yytops.yysize >= yystack->yytops.yycapacity)
@@ -1331,8 +1330,7 @@ yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack]b4_user_formals[)
   YYRESULTTAG yyflag;
   if (0 < yyn)
     {
-      if (yys->yypred == NULL)
-	abort ();
+      YYASSERT (yys->yypred);
       yyflag = yyresolveStates (yys->yypred, yyn-1, yystack]b4_user_args[);
       if (yyflag != yyok)
 	return yyflag;
@@ -1549,8 +1547,8 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
       yyStateNum yystate = yystack->yytops.yystates[yyk]->yylrState;
       YYDPRINTF ((stderr, "Stack %d Entering state %d\n", yyk, yystate));
 
-      if (yystate == YYFINAL)
-	abort ();
+      YYASSERT (yystate != YYFINAL);
+
       if (yyisDefaultedState (yystate))
 	{
 	  yyrule = yydefaultAction (yystate);
