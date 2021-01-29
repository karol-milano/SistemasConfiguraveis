@@ -1351,7 +1351,7 @@ yy_syntax_error_arguments (const yypcontext_t *yyctx,
        one exception: it will still contain any token that will not be
        accepted due to an error action in a later state.]])[
   */
-  if (yyctx->yytoken != ]b4_symbol_prefix[YYEMPTY)
+  if (yyctx->yytoken != ]b4_symbol(-2, kind)[)
     {
       int yyn;]b4_lac_if([[
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
@@ -1582,7 +1582,7 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])[
   /* The return value of yyparse.  */
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
-  yysymbol_kind_t yytoken = ]b4_symbol_prefix[YYEMPTY;
+  yysymbol_kind_t yytoken = ]b4_symbol(-2, kind)[;
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;]b4_locations_if([[
@@ -1895,7 +1895,7 @@ yyreduce:
 yyerrlab:
   /* Make sure we have latest lookahead translation.  See comments at
      user semantic actions for why this is necessary.  */
-  yytoken = yychar == ]b4_symbol(-2, id)[ ? ]b4_symbol_prefix[YYEMPTY : YYTRANSLATE (yychar);
+  yytoken = yychar == ]b4_symbol(-2, id)[ ? ]b4_symbol(-2, kind)[ : YYTRANSLATE (yychar);
   /* If not already recovering from an error, report this error.  */
   if (!yyerrstatus)
     {
