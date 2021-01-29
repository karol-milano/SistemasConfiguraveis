@@ -429,8 +429,6 @@ int yychar;])[
 
 enum { YYENOMEM = -2 };
 
-static const int YYEMPTY = -2;
-
 typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 
 #define YYCHK(YYE)                              \
@@ -525,7 +523,7 @@ struct yyGLRStateSet {
   /** During nondeterministic operation, yylookaheadNeeds tracks which
    *  stacks have actually needed the current lookahead.  During deterministic
    *  operation, yylookaheadNeeds[0] is not maintained since it would merely
-   *  duplicate yychar != YYEMPTY.  */
+   *  duplicate yychar != ]b4_symbol(-2, id)[.  */
   yybool* yylookaheadNeeds;
   ptrdiff_t yysize;
   ptrdiff_t yycapacity;
@@ -809,7 +807,7 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
 {
   yysymbol_kind_t yytoken;
 ]b4_parse_param_use()dnl
-[  if (*yycharp == YYEMPTY)
+[  if (*yycharp == ]b4_symbol(-2, id)[)
     {
       YY_DPRINTF ((stderr, "Reading a token\n"));]b4_glr_cc_if([[
 #if YY_EXCEPTIONS
@@ -887,7 +885,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef YYRECOVERING
 # define YYRECOVERING() (yystackp->yyerrState != 0)
 # undef yyclearin
-# define yyclearin (yychar = YYEMPTY)
+# define yyclearin (yychar = ]b4_symbol(-2, id)[)
 # undef YYFILL
 # define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
 # undef YYBACKUP
@@ -1113,7 +1111,7 @@ yyaddDeferredAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyGLRState* yystate,
       yynewOption->yyloc = yylloc;])[
     }
   else
-    yynewOption->yyrawchar = YYEMPTY;
+    yynewOption->yyrawchar = ]b4_symbol(-2, id)[;
   yynewOption->yynext = yystate->yysemantics.yyfirstVal;
   yystate->yysemantics.yyfirstVal = yynewOption;
 
@@ -2134,7 +2132,7 @@ static yysymbol_kind_t
 yypcontext_token (const yyGLRStack *yystackp)
 {
   YYUSE (yystackp);
-  yysymbol_kind_t yytoken = yychar == YYEMPTY ? ]b4_symbol_prefix[YYEMPTY : YYTRANSLATE (yychar);
+  yysymbol_kind_t yytoken = yychar == ]b4_symbol(-2, id)[ ? ]b4_symbol_prefix[YYEMPTY : YYTRANSLATE (yychar);
   return yytoken;
 }
 
@@ -2153,7 +2151,7 @@ yypcontext_location (const yyGLRStack *yystackp)
 yy_syntax_error_arguments (const yyGLRStack* yystackp,
                            yysymbol_kind_t yyarg[], int yyargn)
 {
-  yysymbol_kind_t yytoken = yychar == YYEMPTY ? ]b4_symbol_prefix[YYEMPTY : YYTRANSLATE (yychar);
+  yysymbol_kind_t yytoken = yychar == ]b4_symbol(-2, id)[ ? ]b4_symbol_prefix[YYEMPTY : YYTRANSLATE (yychar);
   /* Actual size of YYARG. */
   int yycount = 0;
   /* There are many possibilities here to consider:
@@ -2313,7 +2311,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
         int yyj;
         if (yychar == ]b4_symbol(0, [id])[)
           yyFail (yystackp][]b4_lpure_args[, YY_NULLPTR);
-        if (yychar != YYEMPTY)
+        if (yychar != ]b4_symbol(-2, id)[)
           {]b4_locations_if([[
             /* We throw away the lookahead, but the error range
                of the shifted error token must take it into account.  */
@@ -2325,7 +2323,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
             yytoken = YYTRANSLATE (yychar);
             yydestruct ("Error: discarding",
                         yytoken, &yylval]b4_locuser_args([&yylloc])[);
-            yychar = YYEMPTY;
+            yychar = ]b4_symbol(-2, id)[;
           }
         yytoken = ]b4_yygetToken_call[;
         yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
@@ -2422,7 +2420,7 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
 
   YY_DPRINTF ((stderr, "Starting parse\n"));
 
-  yychar = YYEMPTY;
+  yychar = ]b4_symbol(-2, id)[;
   yylval = yyval_default;]b4_locations_if([
   yylloc = yyloc_default;])[
 ]m4_ifdef([b4_initial_action], [
@@ -2475,7 +2473,7 @@ b4_dollar_popdef])[]dnl
               if (yyisShiftAction (yyaction))
                 {
                   YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
-                  yychar = YYEMPTY;
+                  yychar = ]b4_symbol(-2, id)[;
                   yyposn += 1;
                   yyglrShift (&yystack, 0, yyaction, yyposn, &yylval]b4_locations_if([, &yylloc])[);
                   if (0 < yystack.yyerrState)
@@ -2501,7 +2499,7 @@ b4_dollar_popdef])[]dnl
           ptrdiff_t yys;
 
           for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
-            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;
+            yystackp->yytops.yylookaheadNeeds[yys] = yychar != ]b4_symbol(-2, id)[;
 
           /* yyprocessOneStack returns one of three things:
 
@@ -2539,11 +2537,11 @@ b4_dollar_popdef])[]dnl
 
           /* If any yyglrShift call fails, it will fail after shifting.  Thus,
              a copy of yylval will already be on stack 0 in the event of a
-             failure in the following loop.  Thus, yychar is set to YYEMPTY
+             failure in the following loop.  Thus, yychar is set to ]b4_symbol(-2, id)[
              before the loop to make sure the user destructor for yylval isn't
              called twice.  */
           yytoken_to_shift = YYTRANSLATE (yychar);
-          yychar = YYEMPTY;
+          yychar = ]b4_symbol(-2, id)[;
           yyposn += 1;
           for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
             {
@@ -2593,7 +2591,7 @@ b4_dollar_popdef])[]dnl
   goto yyreturn;
 
  yyreturn:
-  if (yychar != YYEMPTY)
+  if (yychar != ]b4_symbol(-2, id)[)
     yydestruct ("Cleanup: discarding lookahead",
                 YYTRANSLATE (yychar), &yylval]b4_locuser_args([&yylloc])[);
 
