@@ -782,8 +782,7 @@ yytokenName (yySymbol yytoken)
 
 /** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
  *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
- *  containing the pointer to the next state in the chain. Assumes
- *  YYLOW1 < YYLOW0.  */
+ *  containing the pointer to the next state in the chain. */
 static void yyfillin (yyGLRStackItem *, int, int) __attribute__ ((__unused__));
 static void
 yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
@@ -802,8 +801,8 @@ yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
 }
 
 /* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
-   YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
-   For convenience, always return YYLOW1.  */
+ * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
+ * For convenience, always return YYLOW1.  */
 static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
      __attribute__ ((__unused__));
 static inline int
@@ -1286,11 +1285,18 @@ yydoAction (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
     }
   else
     {
+      /* At present, doAction is never called in nondeterministic
+       * mode, so this branch is never taken.  It is here in
+       * anticipation of a future feature that will allow immediate
+       * evaluation of selected actions in nondeterministic mode. */
       int yyi;
       yyGLRState* yys;
       yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
       yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
-	= yystack->yytops.yystates[yyk];
+	= yystack->yytops.yystates[yyk];]b4_location_if([[
+      if (yynrhs == 0)
+	/* Set default location. */
+        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;]])[
       for (yyi = 0; yyi < yynrhs; yyi += 1)
 	{
 	  yys = yys->yypred;
@@ -1564,7 +1570,10 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
 
   yynrhs = yyrhsLength (yyopt->yyrule);
   YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystack]b4_user_args[));
-  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
+  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;]b4_location_if([[
+  if (yynrhs == 0)
+    /* Set default location. */
+    yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;]])[
   return yyuserAction (yyopt->yyrule, yynrhs,
 		       yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
 		       yyvalp, yylocp, yystack]b4_user_args[);
