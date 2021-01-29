@@ -975,7 +975,7 @@ yydefaultAction (yyStateNum yystate)
 #define yytable_value_is_error(Yytable_value) \
   ]b4_table_value_equals([[table]], [[Yytable_value]], [b4_table_ninf])[
 
-/** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
+/** The action to take in YYSTATE on seeing YYTOKEN.
  *  Result R means
  *    R < 0:  Reduce on rule -R.
  *    R = 0:  Error.
@@ -983,26 +983,25 @@ yydefaultAction (yyStateNum yystate)
  *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
  *  of conflicting reductions.
  */
-static inline void
-yygetLRActions (yyStateNum yystate, int yytoken,
-                int* yyaction, const short** yyconflicts)
+static inline int
+yygetLRActions (yyStateNum yystate, yySymbol yytoken, const short** yyconflicts)
 {
   int yyindex = yypact[yystate] + yytoken;
   if (yyisDefaultedState (yystate)
       || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
     {
-      *yyaction = -yydefact[yystate];
       *yyconflicts = yyconfl;
+      return -yydefact[yystate];
     }
   else if (! yytable_value_is_error (yytable[yyindex]))
     {
-      *yyaction = yytable[yyindex];
       *yyconflicts = yyconfl + yyconflp[yyindex];
+      return yytable[yyindex];
     }
   else
     {
-      *yyaction = 0;
       *yyconflicts = yyconfl + yyconflp[yyindex];
+      return 0;
     }
 }
 
@@ -1977,7 +1976,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 
           yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
           yytoken = ]b4_yygetToken_call[;
-          yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
+          yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
 
           while (*yyconflicts != 0)
             {
@@ -2338,9 +2337,8 @@ b4_dollar_popdef])[]dnl
           else
             {
               yySymbol yytoken = ]b4_yygetToken_call;[
-              int yyaction;
               const short* yyconflicts;
-              yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
+              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
               if (*yyconflicts != 0)
                 break;
               if (yyisShiftAction (yyaction))
@@ -2418,10 +2416,9 @@ b4_dollar_popdef])[]dnl
           yyposn += 1;
           for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
             {
-              int yyaction;
-              const short* yyconflicts;
               yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
-              yygetLRActions (yystate, yytoken_to_shift, &yyaction,
+              const short* yyconflicts;
+              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                               &yyconflicts);
               /* Note that yyconflicts were handled by yyprocessOneStack.  */
               YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long) yys));
