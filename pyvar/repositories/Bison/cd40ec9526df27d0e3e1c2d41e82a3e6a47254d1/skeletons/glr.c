@@ -527,7 +527,7 @@ struct yyGLRStateSet {
   /** During nondeterministic operation, yylookaheadNeeds tracks which
    *  stacks have actually needed the current lookahead.  During deterministic
    *  operation, yylookaheadNeeds[0] is not maintained since it would merely
-   *  duplicate yychar != ]b4_symbol(-2, id)[.  */
+   *  duplicate yychar != ]b4_symbol(empty, id)[.  */
   yybool* yylookaheadNeeds;
   YYPTRDIFF_T yysize;
   YYPTRDIFF_T yycapacity;
@@ -811,7 +811,7 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
 {
   yysymbol_kind_t yytoken;
 ]b4_parse_param_use()dnl
-[  if (*yycharp == ]b4_symbol(-2, id)[)
+[  if (*yycharp == ]b4_symbol(empty, id)[)
     {
       YY_DPRINTF ((stderr, "Reading a token\n"));]b4_glr_cc_if([[
 #if YY_EXCEPTIONS
@@ -889,7 +889,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef YYRECOVERING
 # define YYRECOVERING() (yystackp->yyerrState != 0)
 # undef yyclearin
-# define yyclearin (yychar = ]b4_symbol(-2, id)[)
+# define yyclearin (yychar = ]b4_symbol(empty, id)[)
 # undef YYFILL
 # define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
 # undef YYBACKUP
@@ -1121,7 +1121,7 @@ yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
       yynewOption->yyloc = yylloc;])[
     }
   else
-    yynewOption->yyrawchar = ]b4_symbol(-2, id)[;
+    yynewOption->yyrawchar = ]b4_symbol(empty, id)[;
   yynewOption->yynext = yystate->yysemantics.yyfirstVal;
   yystate->yysemantics.yyfirstVal = yynewOption;
 
@@ -2124,7 +2124,7 @@ yypcontext_expected_tokens (const yyGLRStack* yystackp,
           }
     }
   if (yyarg && yycount == 0 && 0 < yyargn)
-    yyarg[0] = ]b4_symbol(-2, kind)[;
+    yyarg[0] = ]b4_symbol(empty, kind)[;
   return yycount;
 }]])[
 
@@ -2143,7 +2143,7 @@ static yysymbol_kind_t
 yypcontext_token (const yyGLRStack *yystackp)
 {
   YYUSE (yystackp);
-  yysymbol_kind_t yytoken = yychar == ]b4_symbol(-2, id)[ ? ]b4_symbol(-2, kind)[ : YYTRANSLATE (yychar);
+  yysymbol_kind_t yytoken = yychar == ]b4_symbol(empty, id)[ ? ]b4_symbol(empty, kind)[ : YYTRANSLATE (yychar);
   return yytoken;
 }
 
@@ -2162,7 +2162,7 @@ yypcontext_location (const yyGLRStack *yystackp)
 yy_syntax_error_arguments (const yyGLRStack* yystackp,
                            yysymbol_kind_t yyarg[], int yyargn)
 {
-  yysymbol_kind_t yytoken = yychar == ]b4_symbol(-2, id)[ ? ]b4_symbol(-2, kind)[ : YYTRANSLATE (yychar);
+  yysymbol_kind_t yytoken = yychar == ]b4_symbol(empty, id)[ ? ]b4_symbol(empty, kind)[ : YYTRANSLATE (yychar);
   /* Actual size of YYARG. */
   int yycount = 0;
   /* There are many possibilities here to consider:
@@ -2193,7 +2193,7 @@ yy_syntax_error_arguments (const yyGLRStack* yystackp,
        one exception: it will still contain any token that will not be
        accepted due to an error action in a later state.]])[
   */
-  if (yytoken != ]b4_symbol(-2, kind)[)
+  if (yytoken != ]b4_symbol(empty, kind)[)
     {
       int yyn;
       if (yyarg)
@@ -2322,7 +2322,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
         int yyj;
         if (yychar == ]b4_symbol(0, [id])[)
           yyFail (yystackp][]b4_lpure_args[, YY_NULLPTR);
-        if (yychar != ]b4_symbol(-2, id)[)
+        if (yychar != ]b4_symbol(empty, id)[)
           {]b4_locations_if([[
             /* We throw away the lookahead, but the error range
                of the shifted error token must take it into account.  */
@@ -2334,7 +2334,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
             yytoken = YYTRANSLATE (yychar);
             yydestruct ("Error: discarding",
                         yytoken, &yylval]b4_locuser_args([&yylloc])[);
-            yychar = ]b4_symbol(-2, id)[;
+            yychar = ]b4_symbol(empty, id)[;
           }
         yytoken = ]b4_yygetToken_call[;
         yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
@@ -2431,7 +2431,7 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
 
   YY_DPRINTF ((stderr, "Starting parse\n"));
 
-  yychar = ]b4_symbol(-2, id)[;
+  yychar = ]b4_symbol(empty, id)[;
   yylval = yyval_default;]b4_locations_if([
   yylloc = yyloc_default;])[
 ]m4_ifdef([b4_initial_action], [
@@ -2485,7 +2485,7 @@ b4_dollar_popdef])[]dnl
               if (yyisShiftAction (yyaction))
                 {
                   YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
-                  yychar = ]b4_symbol(-2, id)[;
+                  yychar = ]b4_symbol(empty, id)[;
                   yyposn += 1;
                   yyglrShift (&yystack, 0, yyaction, yyposn, &yylval]b4_locations_if([, &yylloc])[);
                   if (0 < yystack.yyerrState)
@@ -2512,7 +2512,7 @@ b4_dollar_popdef])[]dnl
           YYPTRDIFF_T yys;
 
           for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
-            yystackp->yytops.yylookaheadNeeds[yys] = yychar != ]b4_symbol(-2, id)[;
+            yystackp->yytops.yylookaheadNeeds[yys] = yychar != ]b4_symbol(empty, id)[;
 
           /* yyprocessOneStack returns one of three things:
 
@@ -2550,11 +2550,11 @@ b4_dollar_popdef])[]dnl
 
           /* If any yyglrShift call fails, it will fail after shifting.  Thus,
              a copy of yylval will already be on stack 0 in the event of a
-             failure in the following loop.  Thus, yychar is set to ]b4_symbol(-2, id)[
+             failure in the following loop.  Thus, yychar is set to ]b4_symbol(empty, id)[
              before the loop to make sure the user destructor for yylval isn't
              called twice.  */
           yytoken_to_shift = YYTRANSLATE (yychar);
-          yychar = ]b4_symbol(-2, id)[;
+          yychar = ]b4_symbol(empty, id)[;
           yyposn += 1;
           for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
             {
@@ -2604,7 +2604,7 @@ b4_dollar_popdef])[]dnl
   goto yyreturn;
 
  yyreturn:
-  if (yychar != ]b4_symbol(-2, id)[)
+  if (yychar != ]b4_symbol(empty, id)[)
     yydestruct ("Cleanup: discarding lookahead",
                 YYTRANSLATE (yychar), &yylval]b4_locuser_args([&yylloc])[);
 
