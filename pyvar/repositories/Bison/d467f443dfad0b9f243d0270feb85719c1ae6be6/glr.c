@@ -1325,26 +1325,27 @@ do {					\
 `----------------------------------------------------------------------*/
 
 /*ARGSUSED*/ static inline void
-yy_reduce_print (int yynormal, yyGLRStackItem* yyrhsVals, size_t yyk, yyRuleNum yyrule]b4_user_formals[)
+yy_reduce_print (int yynormal, yyGLRStackItem* yyvsp, size_t yyk, yyRuleNum yyrule]b4_user_formals[)
 {
-  int yynrhs = yyrhsLength (yyrule);
+  int yynrhs = yyrhsLength (yyrule);]b4_locations_if([
+  int yylow = 1;])[
   int yyi;
 ]b4_parse_param_use[]dnl
 [  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
 	     (unsigned long int) yyk, yyrule - 1,
 	     (unsigned long int) yyrline[yyrule]);
   if (! yynormal)
-    yyfillin (yyrhsVals, 1, -yynrhs);
+    yyfillin (yyvsp, 1, -yynrhs);
   /* The symbols being reduced.  */
   for (yyi = 0; yyi < yynrhs; yyi++)
     {
       YYFPRINTF (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr,
-		       yystos[yyrhsVals[yyi - yynrhs + 1].yystate.yylrState],
-		       &yyrhsVals[yyi - yynrhs + 1].yystate.yysemantics.yysval
+		       yystos[yyvsp[yyi - yynrhs + 1].yystate.yylrState],
+		       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval
 		       ]b4_locations_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
 		       b4_user_args[);
-      if (!yyrhsVals[yyi - yynrhs + 1].yystate.yyresolved)
+      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
         YYFPRINTF (stderr, " (unresolved)");
       YYFPRINTF (stderr, "\n");
     }
@@ -1423,7 +1424,7 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 
       yyflag = yydoAction (yystackp, yyk, yyrule, &yysval,
 			   &yyloc]b4_user_args[);
-      if (yyflag == yyerr)
+      if (yyflag == yyerr && yystackp->yysplitPoint != NULL)
         {
 	  YYDPRINTF ((stderr, "Parse on stack %lu rejected by rule #%d.\n",
 		     (unsigned long int) yyk, yyrule - 1));
