@@ -1558,9 +1558,9 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
       goto yyread_pushed_token;
     }]])[
 
-  yyss = yyssa;
-  yyvs = yyvsa;]b4_locations_if([[
-  yyls = yylsa;]])[
+  yyssp = yyss = yyssa;
+  yyvsp = yyvs = yyvsa;]b4_locations_if([[
+  yylsp = yyls = yylsa;]])[
   yystacksize = YYINITDEPTH;]b4_lac_if([[
 
   yyes = yyesa;
@@ -1574,14 +1574,6 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   yyerrstatus = 0;
   yynerrs = 0;
   yychar = YYEMPTY; /* Cause a token to be read.  */
-
-  /* Initialize stack pointers.
-     Waste one element of value and location stack
-     so that they stay on the same level as the state stack.
-     The wasted elements are never initialized.  */
-  yyssp = yyss;
-  yyvsp = yyvs;]b4_locations_if([[
-  yylsp = yyls;]])[
 ]m4_ifdef([b4_initial_action],[
 b4_dollar_pushdef([m4_define([b4_dollar_dollar_used])yylval], [],
                   [m4_define([b4_at_dollar_used])yylloc])dnl
