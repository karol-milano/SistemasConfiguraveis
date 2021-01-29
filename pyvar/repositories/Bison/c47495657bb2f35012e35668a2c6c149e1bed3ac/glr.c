@@ -613,14 +613,14 @@ yytokenName (yySymbol yytoken)
 
 /** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
  *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
- *  containing the pointer to the next state in the chain. Assumes 
+ *  containing the pointer to the next state in the chain. Assumes
  *  YYLOW1 < YYLOW0.  For convenience, returns YYLOW1. */
 static int
-yyfill (yyGLRStackItem* yyvsp, int yylow0, int yylow1) 
+yyfill (yyGLRStackItem* yyvsp, int yylow0, int yylow1)
 {
   yyGLRState* s;
   int i;
-  s = yyvsp[yylow0].yystate.yypred; 
+  s = yyvsp[yylow0].yystate.yypred;
   for (i = yylow0-1; i >= yylow1; i -= 1)
     {
       if (! s->yyresolved)
@@ -1022,7 +1022,7 @@ yyglrShift (yyGLRStack* yystack, int yyk, yyStateNum yylrState, size_t yyposn,
 }
 
 /** Shift stack #K of YYSTACK, to a new state corresponding to LR
- *  state YYLRSTATE, at input position YYPOSN, with the (unresolved) 
+ *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
  *  semantic value of YYRHS under the action for YYRULE. */
 static inline void
 yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState,
@@ -1597,29 +1597,28 @@ yyreportSyntaxError (yyGLRStack* yystack,
 #if YYERROR_VERBOSE
       yySymbol* const yytokenp = yystack->yytokenp;
       int yyn;
-      const char* yyprefix;
       yyn = yypact[yystack->yytops.yystates[0]->yylrState];
       if (YYPACT_NINF < yyn && yyn < YYLAST)
 	{
 	  size_t yysize = 0;
+	  const char* yyprefix;
 	  char* yymsg;
 	  int yyx;
 
 	  /* Start YYX at -YYN if negative to avoid negative indexes in
 	     YYCHECK.  */
-	  int yyxbase = yyn < 0 ? -yyn : 0;
+	  int yyxbegin = yyn < 0 ? -yyn : 0;
 
 	  /* Stay within bounds of both yycheck and yytname.  */
 	  int yychecklim = YYLAST - yyn;
-	  int yynsyms = sizeof (yytname) / sizeof (yytname[0]);
-	  int yyxlim = yychecklim < yynsyms ? yychecklim : yynsyms;
+	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
 	  int yycount = 0;
 
 	  yyprefix = ", expecting ";
-	  for (yyx = yyxbase; yyx < yyxlim && yycount < 5; yyx += 1)
+	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 	      {
-		yysize += strlen (yytokenName (yyx)) + strlen (yyprefix);
+		yysize += strlen (yyprefix) + strlen (yytokenName (yyx));
 		yycount += 1;
 		if (yycount == 5)
 		  {
@@ -1640,7 +1639,7 @@ yyreportSyntaxError (yyGLRStack* yystack,
 	      if (yycount < 5)
 		{
 		  yyprefix = ", expecting ";
-		  for (yyx = yyxbase; yyx < yyxlim; yyx += 1)
+		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 		      {
 			sprintf (yyp, "%s%s", yyprefix, yytokenName (yyx));
