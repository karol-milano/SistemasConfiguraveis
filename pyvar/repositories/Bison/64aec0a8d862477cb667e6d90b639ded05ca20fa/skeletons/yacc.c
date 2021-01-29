@@ -714,8 +714,7 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 enum { YYENOMEM = -2 };
 
 #define yyerrok         (yyerrstatus = 0)
-#define yyclearin       (yychar = YYEMPTY)
-#define YYEMPTY         (-2)
+#define yyclearin       (yychar = ]b4_symbol(-2, id)[)
 
 #define YYACCEPT        goto yyacceptlab
 #define YYABORT         goto yyabortlab
@@ -726,7 +725,7 @@ enum { YYENOMEM = -2 };
 
 #define YYBACKUP(Token, Value)                                    \
   do                                                              \
-    if (yychar == YYEMPTY)                                        \
+    if (yychar == ]b4_symbol(-2, id)[)                                        \
       {                                                           \
         yychar = (Token);                                         \
         yylval = (Value);                                         \
@@ -1613,7 +1612,7 @@ b4_initialize_parser_state_variables])[
 
   YYDPRINTF ((stderr, "Starting parse\n"));
 
-  yychar = YYEMPTY; /* Cause a token to be read.  */
+  yychar = ]b4_symbol(-2, id)[; /* Cause a token to be read.  */
 ]m4_ifdef([b4_initial_action], [
 b4_dollar_pushdef([m4_define([b4_dollar_dollar_used])yylval], [], [],
                   [b4_push_if([b4_pure_if([*])yypushed_loc], [yylloc])])dnl
@@ -1735,7 +1734,7 @@ yybackup:
   /* Not known => get a lookahead token if don't already have one.  */
 
   /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
-  if (yychar == YYEMPTY)
+  if (yychar == ]b4_symbol(-2, id)[)
     {]b4_push_if([[
       if (!yyps->yynew)
         {]b4_use_push_for_pull_if([], [[
@@ -1763,7 +1762,7 @@ yyread_pushed_token:]])[
   if (yychar <= ]b4_symbol(0, [id])[)
     {
       yychar = ]b4_symbol(0, [id])[;
-      yytoken = ]b4_symbol_prefix[YYEOF;
+      yytoken = ]b4_symbol(0, [kind])[;
       YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
   else
@@ -1805,7 +1804,7 @@ yyread_pushed_token:]])[
   *++yylsp = yylloc;])[
 
   /* Discard the shifted token.  */
-  yychar = YYEMPTY;]b4_lac_if([[
+  yychar = ]b4_symbol(-2, id)[;]b4_lac_if([[
   YY_LAC_DISCARD ("shift");]])[
   goto yynewstate;
 
@@ -1896,8 +1895,7 @@ yyreduce:
 yyerrlab:
   /* Make sure we have latest lookahead translation.  See comments at
      user semantic actions for why this is necessary.  */
-  yytoken = yychar == YYEMPTY ? ]b4_symbol_prefix[YYEMPTY : YYTRANSLATE (yychar);
-
+  yytoken = yychar == ]b4_symbol(-2, id)[ ? ]b4_symbol_prefix[YYEMPTY : YYTRANSLATE (yychar);
   /* If not already recovering from an error, report this error.  */
   if (!yyerrstatus)
     {
@@ -1907,7 +1905,7 @@ yyerrlab:
 [[      {
         yypcontext_t yyctx
           = {]b4_push_if([[yyps]], [[yyssp]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])])[, yytoken]b4_locations_if([[, &yylloc]])[};]b4_lac_if([[
-        if (yychar != YYEMPTY)
+        if (yychar != ]b4_symbol(-2, id)[)
           YY_LAC_ESTABLISH;]])[
         if (yyreport_syntax_error (&yyctx]m4_ifset([b4_parse_param],
                                   [[, ]b4_args(b4_parse_param)])[) == 2)
@@ -1920,7 +1918,7 @@ yyerrlab:
           = {]b4_push_if([[yyps]], [[yyssp]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])])[, yytoken]b4_locations_if([[, &yylloc]])[};
         char const *yymsgp = YY_("syntax error");
         int yysyntax_error_status;]b4_lac_if([[
-        if (yychar != YYEMPTY)
+        if (yychar != ]b4_symbol(-2, id)[)
           YY_LAC_ESTABLISH;]])[
         yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
         if (yysyntax_error_status == 0)
@@ -1967,7 +1965,7 @@ yyerrlab:
         {
           yydestruct ("Error: discarding",
                       yytoken, &yylval]b4_locations_if([, &yylloc])[]b4_user_args[);
-          yychar = YYEMPTY;
+          yychar = ]b4_symbol(-2, id)[;
         }
     }
 
@@ -2078,7 +2076,7 @@ yyexhaustedlab:
 | yyreturn -- parsing is finished, return the result.  |
 `-----------------------------------------------------*/
 yyreturn:
-  if (yychar != YYEMPTY)
+  if (yychar != ]b4_symbol(-2, id)[)
     {
       /* Make sure we have latest lookahead translation.  See comments at
          user semantic actions for why this is necessary.  */
