@@ -761,11 +761,11 @@ struct yyGLRState {
 
 struct yyGLRStateSet {
   yyGLRState** yystates;
-  /** During nondeterministic operation, yylookaheadStatuses tracks which
+  /** During nondeterministic operation, yylookaheadNeeds tracks which
    *  stacks have actually needed the current lookahead.  During deterministic
-   *  operation, yylookaheadStatuses[0] is not maintained since it would merely
+   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
    *  duplicate yychar != YYEMPTY.  */
-  yybool* yylookaheadStatuses;
+  yybool* yylookaheadNeeds;
   size_t yysize, yycapacity;
 };
 
@@ -1113,7 +1113,7 @@ yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
     &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
   yynewOption->yystate = rhs;
   yynewOption->yyrule = yyrule;
-  if (yystackp->yytops.yylookaheadStatuses[yyk])
+  if (yystackp->yytops.yylookaheadNeeds[yyk])
     {
       yynewOption->yyrawchar = yychar;
       yynewOption->yyval = yylval;
@@ -1139,9 +1139,9 @@ yyinitStateSet (yyGLRStateSet* yyset)
   if (! yyset->yystates)
     return yyfalse;
   yyset->yystates[0] = NULL;
-  yyset->yylookaheadStatuses =
-    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadStatuses[0]);
-  if (! yyset->yylookaheadStatuses)
+  yyset->yylookaheadNeeds =
+    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
+  if (! yyset->yylookaheadNeeds)
     {
       YYFREE (yyset->yystates);
       return yyfalse;
@@ -1152,7 +1152,7 @@ yyinitStateSet (yyGLRStateSet* yyset)
 static void yyfreeStateSet (yyGLRStateSet* yyset)
 {
   YYFREE (yyset->yystates);
-  YYFREE (yyset->yylookaheadStatuses);
+  YYFREE (yyset->yylookaheadNeeds);
 }
 
 /** Initialize STACK to a single empty stack, with total maximum
@@ -1300,12 +1300,12 @@ yyremoveDeletes (yyGLRStack* yystackp)
 	{
 	  yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
 	  /* In the current implementation, it's unnecessary to copy
-	     yystackp->yytops.yylookaheadStatuses[yyi] since, after
+	     yystackp->yytops.yylookaheadNeeds[yyi] since, after
 	     yyremoveDeletes returns, the parser immediately either enters
 	     deterministic operation or shifts a token.  However, it doesn't
 	     hurt, and the code might evolve to need it.  */
-	  yystackp->yytops.yylookaheadStatuses[yyj] =
-	    yystackp->yytops.yylookaheadStatuses[yyi];
+	  yystackp->yytops.yylookaheadNeeds[yyj] =
+	    yystackp->yytops.yylookaheadNeeds[yyi];
 	  if (yyj != yyi)
 	    {
 	      YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
@@ -1533,7 +1533,7 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
   if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
     {
       yyGLRState** yynewStates;
-      yybool* yynewLookaheadStatuses;
+      yybool* yynewLookaheadNeeds;
 
       yynewStates = NULL;
       
@@ -1550,18 +1550,18 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
 	yyMemoryExhausted (yystackp);
       yystackp->yytops.yystates = yynewStates;
 
-      yynewLookaheadStatuses =
-	(yybool*) YYREALLOC (yystackp->yytops.yylookaheadStatuses,
+      yynewLookaheadNeeds =
+	(yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
 			     (yystackp->yytops.yycapacity
-			      * sizeof yynewLookaheadStatuses[0]));
-      if (yynewLookaheadStatuses == NULL)
+			      * sizeof yynewLookaheadNeeds[0]));
+      if (yynewLookaheadNeeds == NULL)
 	yyMemoryExhausted (yystackp);
-      yystackp->yytops.yylookaheadStatuses = yynewLookaheadStatuses;
+      yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
     }
   yystackp->yytops.yystates[yystackp->yytops.yysize]
     = yystackp->yytops.yystates[yyk];
-  yystackp->yytops.yylookaheadStatuses[yystackp->yytops.yysize]
-    = yystackp->yytops.yylookaheadStatuses[yyk];
+  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
+    = yystackp->yytops.yylookaheadNeeds[yyk];
   yystackp->yytops.yysize += 1;
   return yystackp->yytops.yysize-1;
 }
@@ -1953,7 +1953,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 	}
       else
 	{
-	  yystackp->yytops.yylookaheadStatuses[yyk] = yytrue;
+	  yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
 	  if (*yytokenp == YYEMPTY)
 	    {
 	      YYDPRINTF ((stderr, "Reading a token: "));
@@ -2318,7 +2318,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	  size_t yyn = yystack.yytops.yysize;
 
 	  for (yys = 0; yys < yyn; yys += 1)
-	    yystackp->yytops.yylookaheadStatuses[yys] = yychar != YYEMPTY;
+	    yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;
 
 	  /* yyprocessOneStack returns one of three things:
 
