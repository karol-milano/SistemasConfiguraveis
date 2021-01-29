@@ -2338,9 +2338,8 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	{
 	  yySymbol yytoken_to_shift;
 	  size_t yys;
-	  size_t yyn = yystack.yytops.yysize;
 
-	  for (yys = 0; yys < yyn; yys += 1)
+	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
 	    yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;
 
 	  /* yyprocessOneStack returns one of three things:
@@ -2359,13 +2358,23 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	     Except in the first case, yyparse will invoke yyremoveDeletes and
 	     then shift the next token onto all remaining stacks.  This
 	     synchronization of the shift (that is, after all preceding
-	     reductions on all stacks) helps prevents double destructor calls
+	     reductions on all stacks) helps prevent double destructor calls
 	     on yylval in the event of memory exhaustion.  */
 
-	  for (yys = 0; yys < yyn; yys += 1)
+	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
 	    YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn]b4_lpure_args[));
 	  yyremoveDeletes (&yystack);
-	  yyn = yystack.yytops.yysize;
+	  if (yystack.yytops.yysize == 0)
+	    {
+	      yyundeleteLastStack (&yystack);
+	      if (yystack.yytops.yysize == 0)
+		yyFail (&yystack][]b4_lpure_args[, YY_("syntax error"));
+	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
+	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
+]b4_location_if([[	      yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+	      yyreportSyntaxError (&yystack]b4_user_args[);
+	      goto yyuser_error;
+	    }
 
 	  /* If any yyglrShift call fails, it will fail after shifting.  Thus,
 	     a copy of yylval will already be on stack 0 in the event of a
@@ -2375,7 +2384,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	  yytoken_to_shift = YYTRANSLATE (yychar);
 	  yychar = YYEMPTY;
 	  yyposn += 1;
-	  for (yys = 0; yys < yyn; yys += 1)
+	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
 	    {
 	      int yyaction;
 	      const short int* yyconflicts;
@@ -2391,18 +2400,8 @@ b4_syncline([@oline@], [@ofile@])])dnl
 			  (unsigned long int) yys,
 			  yystack.yytops.yystates[yys]->yylrState));
 	    }
-	  if (yystack.yytops.yysize == 0)
-	    {
-	      yyundeleteLastStack (&yystack);
-	      if (yystack.yytops.yysize == 0)
-		yyFail (&yystack][]b4_lpure_args[, YY_("syntax error"));
-	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
-	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
-]b4_location_if([[	      yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
-	      yyreportSyntaxError (&yystack]b4_user_args[);
-	      goto yyuser_error;
-	    }
-	  else if (yystack.yytops.yysize == 1)
+
+	  if (yystack.yytops.yysize == 1)
 	    {
 	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
 	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
