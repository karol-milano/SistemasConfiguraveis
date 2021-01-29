@@ -2107,7 +2107,7 @@ yypcontext_expected_tokens (const yyGLRStack* yystackp,
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
       int yyx;
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-        if (yycheck[yyx + yyn] == yyx && yyx != ]b4_symbol_prefix[YYERROR
+        if (yycheck[yyx + yyn] == yyx && yyx != ]b4_symbol(1, kind)[
             && !yytable_value_is_error (yytable[yyx + yyn]))
           {
             if (!yyarg)
@@ -2365,8 +2365,8 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
       int yyj = yypact[yys->yylrState];
       if (! yypact_value_is_default (yyj))
         {
-          yyj += ]b4_symbol_prefix[YYERROR;
-          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == ]b4_symbol_prefix[YYERROR
+          yyj += ]b4_symbol(1, kind)[;
+          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == ]b4_symbol(1, kind)[
               && yyisShiftAction (yytable[yyj]))
             {
               /* Shift the error token.  */
