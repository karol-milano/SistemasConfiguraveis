@@ -829,14 +829,14 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
           // Map errors caught in the scanner to the undefined token,
           // so that error handling is started.  However, record this
           // with this special value of yychar.
-          *yycharp = ]b4_symbol(1, id)[;
+          *yycharp = ]b4_symbol(error, id)[;
         }
 #endif // YY_EXCEPTIONS]], [[
       *yycharp = ]b4_lex[;]])[
     }
-  if (*yycharp <= ]b4_symbol(0, [id])[)
+  if (*yycharp <= ]b4_symbol(eof, [id])[)
     {
-      *yycharp = ]b4_symbol(0, [id])[;
+      *yycharp = ]b4_symbol(eof, [id])[;
       yytoken = ]b4_symbol_prefix[YYEOF;
       YY_DPRINTF ((stderr, "Now at end of input.\n"));
     }
@@ -1034,7 +1034,7 @@ static inline int
 yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
 {
   int yyindex = yypact[yystate] + yytoken;
-  if (yytoken == ]b4_symbol(1, kind)[)
+  if (yytoken == ]b4_symbol(error, kind)[)
     {
       // This is the error token.
       *yyconflicts = yyconfl;
@@ -2112,7 +2112,7 @@ yypcontext_expected_tokens (const yyGLRStack* yystackp,
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
       int yyx;
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-        if (yycheck[yyx + yyn] == yyx && yyx != ]b4_symbol(1, kind)[
+        if (yycheck[yyx + yyn] == yyx && yyx != ]b4_symbol(error, kind)[
             && !yytable_value_is_error (yytable[yyx + yyn]))
           {
             if (!yyarg)
@@ -2320,7 +2320,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
       {
         yysymbol_kind_t yytoken;
         int yyj;
-        if (yychar == ]b4_symbol(0, [id])[)
+        if (yychar == ]b4_symbol(eof, [id])[)
           yyFail (yystackp][]b4_lpure_args[, YY_NULLPTR);
         if (yychar != ]b4_symbol(empty, id)[)
           {]b4_locations_if([[
@@ -2372,8 +2372,8 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
       int yyj = yypact[yys->yylrState];
       if (! yypact_value_is_default (yyj))
         {
-          yyj += ]b4_symbol(1, kind)[;
-          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == ]b4_symbol(1, kind)[
+          yyj += ]b4_symbol(error, kind)[;
+          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == ]b4_symbol(error, kind)[
               && yyisShiftAction (yytable[yyj]))
             {
               /* Shift the error token.  */
@@ -2496,7 +2496,7 @@ b4_dollar_popdef])[]dnl
                   yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
                   /* Issue an error message unless the scanner already
                      did. */
-                  if (yychar != ]b4_symbol(1, id)[)
+                  if (yychar != ]b4_symbol(error, id)[)
                     yyreportSyntaxError (&yystack]b4_user_args[);
                   goto yyuser_error;
                 }
