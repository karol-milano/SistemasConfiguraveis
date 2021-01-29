@@ -1348,7 +1348,7 @@ yysyntax_error_arguments (const yyparse_context_t *yyctx,
        one exception: it will still contain any token that will not be
        accepted due to an error action in a later state.]])[
   */
-  if (yyctx->yytoken != YYEMPTY)
+  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
     {
       int yyn;]b4_lac_if([[
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
@@ -1576,7 +1576,7 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])[
   /* The return value of yyparse.  */
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
-  yysymbol_type_t yytoken = 0;
+  yysymbol_type_t yytoken = YYSYMBOL_YYEMPTY;
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;]b4_locations_if([[
@@ -1889,7 +1889,7 @@ yyreduce:
 yyerrlab:
   /* Make sure we have latest lookahead translation.  See comments at
      user semantic actions for why this is necessary.  */
-  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
+  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
 
   /* If not already recovering from an error, report this error.  */
   if (!yyerrstatus)
