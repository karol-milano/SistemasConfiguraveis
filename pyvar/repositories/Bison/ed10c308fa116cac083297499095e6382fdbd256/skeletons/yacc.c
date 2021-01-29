@@ -219,26 +219,6 @@ m4_define([b4_declare_parser_state_variables],
                    [ : YYMAXDEPTH])])[;]])])
 
 
-# b4_initialize_parser_state_variables
-# ------------------------------------
-# Initialize these variables.
-m4_define([b4_initialize_parser_state_variables],
-[[  yynerrs = 0;
-  yystate = 0;
-  yyerrstatus = 0;
-
-  yystacksize = YYINITDEPTH;
-  yyssp = yyss = yyssa;
-  yyvsp = yyvs = yyvsa;]b4_locations_if([[
-  yylsp = yyls = yylsa;]])[]b4_lac_if([[
-
-  yyes = yyesa;
-  yyes_capacity = ]b4_percent_define_get([[parse.lac.es-capacity-initial]])[;
-  if (YYMAXDEPTH < yyes_capacity)
-    yyes_capacity = YYMAXDEPTH;]])[
-]])
-
-
 m4_define([b4_macro_define],
 [[#]define $1 $2])
 
@@ -1479,7 +1459,19 @@ yypull_parse (yypstate *yyps]b4_user_formals[)
 static void
 yypstate_clear (yypstate *yyps)
 {
-]b4_initialize_parser_state_variables[
+  yynerrs = 0;
+  yystate = 0;
+  yyerrstatus = 0;
+
+  yystacksize = YYINITDEPTH;
+  yyssp = yyss = yyssa;
+  yyvsp = yyvs = yyvsa;]b4_locations_if([[
+  yylsp = yyls = yylsa;]])[]b4_lac_if([[
+
+  yyes = yyesa;
+  yyes_capacity = ]b4_percent_define_get([[parse.lac.es-capacity-initial]])[;
+  if (YYMAXDEPTH < yyes_capacity)
+    yyes_capacity = YYMAXDEPTH;]])[
   /* Initialize the state stack, in case yypcontext_expected_tokens is
      called before the first call to yyparse. */
   *yyssp = 0;
