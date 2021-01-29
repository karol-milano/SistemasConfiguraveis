@@ -1324,7 +1324,8 @@ do {                                    \
 `----------------------------------------------------------------------*/
 
 /*ARGSUSED*/ static inline void
-yy_reduce_print (int yynormal, yyGLRStackItem* yyvsp, size_t yyk, yyRuleNum yyrule]b4_user_formals[)
+yy_reduce_print (int yynormal, yyGLRStackItem* yyvsp, size_t yyk,
+                 yyRuleNum yyrule]b4_user_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);]b4_locations_if([
   int yylow = 1;])[
@@ -1452,7 +1453,8 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       yyupdateSplit (yystackp, yys);
       yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
       YYDPRINTF ((stderr,
-                  "Reduced stack %lu by rule #%d; action deferred.  Now in state %d.\n",
+                  "Reduced stack %lu by rule #%d; action deferred.  "
+                  "Now in state %d.\n",
                   (unsigned long int) yyk, yyrule - 1, yynewLRState));
       for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
         if (yyi != yyk && yystackp->yytops.yystates[yyi] != NULL)
@@ -1986,7 +1988,9 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
           yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]]b4_user_args[);
           if (yyflag == yyerr)
             {
-              YYDPRINTF ((stderr, "Stack %lu dies (predicate failure or explicit user error).\n",
+              YYDPRINTF ((stderr,
+                          "Stack %lu dies "
+                          "(predicate failure or explicit user error).\n",
                           (unsigned long int) yyk));
               yymarkStackDeleted (yystackp, yyk);
               return yyok;
@@ -2059,7 +2063,9 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
                                                 yyimmediate[-yyaction]]b4_user_args[);
               if (yyflag == yyerr)
                 {
-                  YYDPRINTF ((stderr, "Stack %lu dies (predicate failure or explicit user error).\n",
+                  YYDPRINTF ((stderr,
+                              "Stack %lu dies "
+                              "(predicate failure or explicit user error).\n",
                               (unsigned long int) yyk));
                   yymarkStackDeleted (yystackp, yyk);
                   break;
