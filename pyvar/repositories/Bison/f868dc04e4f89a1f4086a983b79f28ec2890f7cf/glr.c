@@ -111,7 +111,7 @@ m4_define([b4_lhs_value],
 # Expansion of $<TYPE>NUM, where the current rule has RULE-LENGTH
 # symbols on RHS.
 m4_define([b4_rhs_value],
-[yyvsp@{m4_eval([$2 - $1])@}.yystate.yysemantics.yysval[]m4_ifval([$3], [.$3])])
+[yyvsp@{YYFILL (m4_eval([$2 - $1]))@}.yystate.yysemantics.yysval[]m4_ifval([$3], [.$3])])
 
 
 
@@ -131,8 +131,7 @@ m4_define([b4_lhs_location],
 # Expansion of @NUM, where the current rule has RULE-LENGTH symbols
 # on RHS.
 m4_define([b4_rhs_location],
-[yyvsp@{m4_eval([$2 - $1])@}.yystate.yyloc])
-
+[yyvsp@{YYFILL (m4_eval([$2 - $1]))@}.yystate.yyloc])
 
 # We do want M4 expansion after # for CPP macros.
 m4_changecom()
@@ -614,6 +613,28 @@ yytokenName (yySymbol yytoken)
 }
 #endif
 
+/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
+ *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
+ *  containing the pointer to the next state in the chain. Assumes 
+ *  YYLOW1 < YYLOW0.  For convenience, returns YYLOW1. */
+static int
+yyfill (yyGLRStackItem* yyvsp, int yylow0, int yylow1) 
+{
+  yyGLRState* s;
+  int i;
+  s = yyvsp[yylow0].yystate.yypred; 
+  for (i = yylow0-1; i >= yylow1; i -= 1)
+    {
+      if (! s->yyresolved)
+	abort ();
+      yyvsp[i].yystate.yyresolved = yytrue;
+      yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
+      yyvsp[i].yystate.yyloc = s->yyloc;
+      s = yyvsp[i].yystate.yypred = s->yypred;
+    }
+  return yylow1;
+}
+
 /** Perform user action for rule number YYN, with RHS length YYRHSLEN,
  *  and top stack item YYVSP.  YYLVALP points to place to put semantic
  *  value ($$), and yylocp points to place for location information
@@ -624,8 +645,8 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 	      YYSTYPE* yyvalp, YYLTYPE* yylocp, yyGLRStack* yystack
               ]b4_user_formals[)
 {
-  /* Avoid `unused' warnings in there are no $n. */
-  (void) yystack;
+  int yynormal = (yystack->yysplitPoint == NULL);
+  int yylow;
 
   if (yyrhslen == 0)
     {
@@ -649,6 +670,9 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # define YYRECOVERING (yystack->yyerrState != 0)
 # undef yyclearin
 # define yyclearin (yychar = *(yystack->yytokenp) = YYEMPTY)
+# undef YYFILL
+# define YYFILL(N)							     \
+  ((yynormal || yylow <= (N)) ? (N) : (yylow = yyfill (yyvsp, yylow, N)))
 # undef YYBACKUP
 # define YYBACKUP(Token, Value)						     \
   do {									     \
@@ -657,6 +681,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   } while (0)
 
 ]
+   yylow = 1;
    switch (yyn)
      {
        b4_actions
@@ -998,9 +1023,9 @@ yyglrShift (yyGLRStack* yystack, int yyk, yyStateNum yylrState, size_t yyposn,
     yyexpandGLRStack (yystack]b4_pure_args[);
 }
 
-/** Shift to a new state on stack #K of STACK, to a new state
- *  corresponding to LR state LRSTATE, at input position POSN, with
- * the (unresolved) semantic value of RHS under the action for RULE. */
+/** Shift stack #K of YYSTACK, to a new state corresponding to LR
+ *  state YYLRSTATE, at input position YYPOSN, with the (unresolved) 
+ *  semantic value of YYRHS under the action for YYRULE. */
 static inline void
 yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState,
 		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule]b4_pure_formals[)
@@ -1058,15 +1083,13 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
     {
       int yyi;
       yyGLRState* yys;
-      yyGLRStackItem yyrhsVals[YYMAXRHS];
-      for (yyi = yynrhs-1, yys = yystack->yytops.yystates[yyk]; 0 <= yyi;
-	   yyi -= 1, yys = yys->yypred)
+      yyGLRStackItem yyrhsVals[YYMAXRHS+1];
+      yys = yyrhsVals[YYMAXRHS].yystate.yypred = yystack->yytops.yystates[yyk];
+      for (yyi = 0; yyi < yynrhs; yyi += 1)
 	{
-	  if (! yys->yypred)
+	  yys = yys->yypred;
+	  if (yys == NULL)
 	    abort ();
-	  yyrhsVals[yyi].yystate.yyresolved = yytrue;
-	  yyrhsVals[yyi].yystate.yysemantics.yysval = yys->yysemantics.yysval;
-	  yyrhsVals[yyi].yystate.yyloc = yys->yyloc;
 	}
       yyupdateSplit (yystack, yys);
       yystack->yytops.yystates[yyk] = yys;
@@ -1077,10 +1100,10 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
 	}
       else
 	{
-	  *yyvalp = yyrhsVals[0].yystate.yysemantics.yysval;
-	  *yylocp = yyrhsVals[0].yystate.yyloc;
+	  *yyvalp = yyrhsVals[1].yystate.yysemantics.yysval;
+	  *yylocp = yyrhsVals[1].yystate.yyloc;
 	}
-      return yyuserAction (yyrule, yynrhs, yyrhsVals + (yynrhs-1),
+      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS - 1,
 			   yyvalp, yylocp, yystack]b4_user_args[);
     }
 }
@@ -1152,7 +1175,7 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 	   0 < yyn; yyn -= 1)
 	{
 	  yys = yys->yypred;
-	  if (! yys)
+	  if (yys == NULL)
 	    abort ();
 	}
       yyupdateSplit (yystack, yys);
@@ -1289,7 +1312,7 @@ yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack]b4_user_formals[)
   YYRESULTTAG yyflag;
   if (0 < yyn)
     {
-      if (! yys->yypred)
+      if (yys->yypred == NULL)
 	abort ();
       yyflag = yyresolveStates (yys->yypred, yyn-1, yystack]b4_user_args[);
       if (yyflag != yyok)
@@ -1311,22 +1334,13 @@ static YYRESULTTAG
 yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
 	         YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
-  yyGLRStackItem yyrhsVals[YYMAXRHS];
-  int yynrhs, yyi;
-  yyGLRState* yys;
+  yyGLRStackItem yyrhsVals[YYMAXRHS+1];
+  int yynrhs;
 
   yynrhs = yyrhsLength (yyopt->yyrule);
   YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystack]b4_user_args[));
-  for (yyi = yynrhs-1, yys = yyopt->yystate; 0 <= yyi;
-       yyi -= 1, yys = yys->yypred)
-    {
-      if (! yys->yypred)
-	abort ();
-      yyrhsVals[yyi].yystate.yyresolved = yytrue;
-      yyrhsVals[yyi].yystate.yysemantics.yysval = yys->yysemantics.yysval;
-      yyrhsVals[yyi].yystate.yyloc = yys->yyloc;
-    }
-  return yyuserAction (yyopt->yyrule, yynrhs, yyrhsVals + (yynrhs-1),
+  yyrhsVals[YYMAXRHS].yystate.yypred = yyopt->yystate;
+  return yyuserAction (yyopt->yyrule, yynrhs, yyrhsVals + YYMAXRHS - 1,
 		       yyvalp, yylocp, yystack]b4_user_args[);
 }
 
