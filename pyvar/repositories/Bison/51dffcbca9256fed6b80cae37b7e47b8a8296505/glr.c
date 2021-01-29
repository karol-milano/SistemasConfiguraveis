@@ -146,7 +146,6 @@ b4_copyright([Skeleton parser for GLR parsing with Bison], [2002])
 [
 /* This is the parser code for GLR (Generalized LR) parser. */
 
-#include <assert.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -1038,7 +1037,8 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
     {
       /* Standard special case: single stack. */
       yyGLRStackItem* rhs = (yyGLRStackItem*) yystack->yytops.yystates[yyk];
-      assert (yyk == 0);
+      if (yyk != 0)
+	abort ();
       yystack->yynextFree -= yynrhs;
       yystack->yyspaceLeft += yynrhs;
       yystack->yytops.yystates[0] = & yystack->yynextFree[-1].yystate;
@@ -1063,7 +1063,8 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
       for (yyi = yynrhs-1, yys = yystack->yytops.yystates[yyk]; 0 <= yyi;
 	   yyi -= 1, yys = yys->yypred)
 	{
-	  assert (yys->yypred != NULL);
+	  if (! yys->yypred)
+	    abort ();
 	  yyrhsVals[yyi].yystate.yyresolved = yytrue;
 	  yyrhsVals[yyi].yystate.yysemantics.yysval = yys->yysemantics.yysval;
 	  yyrhsVals[yyi].yystate.yyloc = yys->yyloc;
@@ -1151,7 +1152,8 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 	   0 < yyn; yyn -= 1)
 	{
 	  yys = yys->yypred;
-	  assert (yys != NULL);
+	  if (! yys)
+	    abort ();
 	}
       yyupdateSplit (yystack, yys);
       yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
@@ -1188,7 +1190,8 @@ yysplitStack (yyGLRStack* yystack, int yyk)
 {
   if (yystack->yysplitPoint == NULL)
     {
-      assert (yyk == 0);
+      if (yyk != 0)
+	abort ();
       yystack->yysplitPoint = yystack->yytops.yystates[yyk];
     }
   if (yystack->yytops.yysize >= yystack->yytops.yycapacity)
@@ -1286,7 +1289,8 @@ yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack]b4_user_formals[)
   YYRESULTTAG yyflag;
   if (0 < yyn)
     {
-      assert (yys->yypred != NULL);
+      if (! yys->yypred)
+	abort ();
       yyflag = yyresolveStates (yys->yypred, yyn-1, yystack]b4_user_args[);
       if (yyflag != yyok)
 	return yyflag;
@@ -1316,7 +1320,8 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
   for (yyi = yynrhs-1, yys = yyopt->yystate; 0 <= yyi;
        yyi -= 1, yys = yys->yypred)
     {
-      assert (yys->yypred != NULL);
+      if (! yys->yypred)
+	abort ();
       yyrhsVals[yyi].yystate.yyresolved = yytrue;
       yyrhsVals[yyi].yystate.yysemantics.yysval = yys->yysemantics.yysval;
       yyrhsVals[yyi].yystate.yyloc = yys->yyloc;
@@ -1508,7 +1513,8 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
       yyStateNum yystate = yystack->yytops.yystates[yyk]->yylrState;
       YYDPRINTF ((stderr, "Stack %d Entering state %d\n", yyk, yystate));
 
-      assert (yystate != YYFINAL);
+      if (yystate == YYFINAL)
+	abort ();
       if (yyisDefaultedState (yystate))
 	{
 	  yyrule = yydefaultAction (yystate);
