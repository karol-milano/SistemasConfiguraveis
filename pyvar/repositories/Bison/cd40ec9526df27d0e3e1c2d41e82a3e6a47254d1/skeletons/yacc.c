@@ -727,7 +727,7 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 enum { YYENOMEM = -2 };
 
 #define yyerrok         (yyerrstatus = 0)
-#define yyclearin       (yychar = ]b4_symbol(-2, id)[)
+#define yyclearin       (yychar = ]b4_symbol(empty, id)[)
 
 #define YYACCEPT        goto yyacceptlab
 #define YYABORT         goto yyabortlab
@@ -738,7 +738,7 @@ enum { YYENOMEM = -2 };
 
 #define YYBACKUP(Token, Value)                                    \
   do                                                              \
-    if (yychar == ]b4_symbol(-2, id)[)                                        \
+    if (yychar == ]b4_symbol(empty, id)[)                                        \
       {                                                           \
         yychar = (Token);                                         \
         yylval = (Value);                                         \
@@ -1206,7 +1206,7 @@ yypcontext_expected_tokens (const yypcontext_t *yyctx,
           }
     }]])[
   if (yyarg && yycount == 0 && 0 < yyargn)
-    yyarg[0] = ]b4_symbol(-2, kind)[;
+    yyarg[0] = ]b4_symbol(empty, kind)[;
   return yycount;
 }
 
@@ -1369,7 +1369,7 @@ yy_syntax_error_arguments (const yypcontext_t *yyctx,
        one exception: it will still contain any token that will not be
        accepted due to an error action in a later state.]])[
   */
-  if (yyctx->yytoken != ]b4_symbol(-2, kind)[)
+  if (yyctx->yytoken != ]b4_symbol(empty, kind)[)
     {
       int yyn;]b4_lac_if([[
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
@@ -1635,7 +1635,7 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])]
   /* The return value of yyparse.  */
   int yyresult;
   /* Lookahead symbol kind.  */
-  yysymbol_kind_t yytoken = ]b4_symbol(-2, kind)[;
+  yysymbol_kind_t yytoken = ]b4_symbol(empty, kind)[;
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;]b4_locations_if([[
@@ -1671,7 +1671,7 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])]
   YYDPRINTF ((stderr, "Starting parse\n"));
 
 ]m4_ifdef([b4_start_symbols], [],
-[[  yychar = ]b4_symbol(-2, id)[; /* Cause a token to be read.  */
+[[  yychar = ]b4_symbol(empty, id)[; /* Cause a token to be read.  */
 ]])[
 ]m4_ifdef([b4_initial_action], [
 b4_dollar_pushdef([m4_define([b4_dollar_dollar_used])yylval], [], [],
@@ -1795,7 +1795,7 @@ yybackup:
   /* Not known => get a lookahead token if don't already have one.  */
 
   /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
-  if (yychar == ]b4_symbol(-2, id)[)
+  if (yychar == ]b4_symbol(empty, id)[)
     {]b4_push_if([[
       if (!yyps->yynew)
         {]b4_use_push_for_pull_if([], [[
@@ -1876,7 +1876,7 @@ yyread_pushed_token:]])[
   *++yylsp = yylloc;])[
 
   /* Discard the shifted token.  */
-  yychar = ]b4_symbol(-2, id)[;]b4_lac_if([[
+  yychar = ]b4_symbol(empty, id)[;]b4_lac_if([[
   YY_LAC_DISCARD ("shift");]])[
   goto yynewstate;
 
@@ -1967,7 +1967,7 @@ yyreduce:
 yyerrlab:
   /* Make sure we have latest lookahead translation.  See comments at
      user semantic actions for why this is necessary.  */
-  yytoken = yychar == ]b4_symbol(-2, id)[ ? ]b4_symbol(-2, kind)[ : YYTRANSLATE (yychar);
+  yytoken = yychar == ]b4_symbol(empty, id)[ ? ]b4_symbol(empty, kind)[ : YYTRANSLATE (yychar);
   /* If not already recovering from an error, report this error.  */
   if (!yyerrstatus)
     {
@@ -1977,7 +1977,7 @@ yyerrlab:
 [[      {
         yypcontext_t yyctx
           = {]b4_push_if([[yyps]], [[yyssp]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])])[, yytoken]b4_locations_if([[, &yylloc]])[};]b4_lac_if([[
-        if (yychar != ]b4_symbol(-2, id)[)
+        if (yychar != ]b4_symbol(empty, id)[)
           YY_LAC_ESTABLISH;]])[
         if (yyreport_syntax_error (&yyctx]m4_ifset([b4_parse_param],
                                   [[, ]b4_args(b4_parse_param)])[) == 2)
@@ -1990,7 +1990,7 @@ yyerrlab:
           = {]b4_push_if([[yyps]], [[yyssp]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])])[, yytoken]b4_locations_if([[, &yylloc]])[};
         char const *yymsgp = YY_("syntax error");
         int yysyntax_error_status;]b4_lac_if([[
-        if (yychar != ]b4_symbol(-2, id)[)
+        if (yychar != ]b4_symbol(empty, id)[)
           YY_LAC_ESTABLISH;]])[
         yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
         if (yysyntax_error_status == 0)
@@ -2036,7 +2036,7 @@ yyerrlab:
         {
           yydestruct ("Error: discarding",
                       yytoken, &yylval]b4_locations_if([, &yylloc])[]b4_user_args[);
-          yychar = ]b4_symbol(-2, id)[;
+          yychar = ]b4_symbol(empty, id)[;
         }
     }
 
@@ -2147,7 +2147,7 @@ yyexhaustedlab:
 | yyreturn -- parsing is finished, clean up and return.  |
 `-------------------------------------------------------*/
 yyreturn:
-  if (yychar != ]b4_symbol(-2, id)[)
+  if (yychar != ]b4_symbol(empty, id)[)
     {
       /* Make sure we have latest lookahead translation.  See comments at
          user semantic actions for why this is necessary.  */
