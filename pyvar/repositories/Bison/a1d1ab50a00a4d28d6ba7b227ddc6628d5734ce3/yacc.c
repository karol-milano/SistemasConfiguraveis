@@ -181,8 +181,7 @@ int yychar;
 #else
 /* Default value used for initialization, for pacifying older GCCs
    or non-GCC compilers.  */
-static YYSTYPE yyval_default;]b4_locations_if([
-b4_yyloc_default_define])[
+static YYSTYPE yyval_default;
 # define YY_INITIAL_VALUE(Value) = Value
 #endif]])[
 #ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
@@ -197,7 +196,8 @@ b4_yyloc_default_define])[
 YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);]b4_locations_if([[
 
 /* Location data for the lookahead symbol.  */
-YYLTYPE yylloc YY_INITIAL_VALUE(yyloc_default);]])b4_pure_if([], [[
+YYLTYPE yylloc][]b4_yyloc_default[;
+]])b4_pure_if([], [[
 
 /* Number of syntax errors so far.  */
 int yynerrs;]])])
@@ -265,7 +265,7 @@ typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
   [[b4_prefix[pstate *ps]], [[ps]]]b4_pure_if([,
   [[[int pushed_char]], [[pushed_char]]],
   [[b4_api_PREFIX[STYPE const *pushed_val]], [[pushed_val]]]b4_locations_if([,
-  [[b4_api_PREFIX[LTYPE const *pushed_loc]], [[pushed_loc]]]])])m4_ifset([b4_parse_param], [,
+  [[b4_api_PREFIX[LTYPE *pushed_loc]], [[pushed_loc]]]])])m4_ifset([b4_parse_param], [,
   b4_parse_param]))
 b4_pull_if([b4_c_function_decl([b4_prefix[pull_parse]], [[int]],
   [[b4_prefix[pstate *ps]], [[ps]]]m4_ifset([b4_parse_param], [,
@@ -1409,7 +1409,7 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   yypstate *yyps_local;]b4_pure_if([[
   int yychar;
   YYSTYPE yylval;]b4_locations_if([[
-  YYLTYPE yylloc;]])])[
+  YYLTYPE yylloc][]b4_yyloc_default[;]])])[
   if (yyps)
     yyps_local = yyps;
   else
@@ -1489,7 +1489,7 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   [[[yypstate *yyps]], [[yyps]]]b4_pure_if([,
   [[[int yypushed_char]], [[yypushed_char]]],
   [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
-  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
+  [[[YYLTYPE *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
   b4_parse_param]))], [[
 
 
@@ -1556,16 +1556,17 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   yyerrstatus = 0;
   yynerrs = 0;
   yychar = YYEMPTY; /* Cause a token to be read.  */
-]m4_ifdef([b4_initial_action],[
+]m4_ifdef([b4_initial_action], [
 b4_dollar_pushdef([m4_define([b4_dollar_dollar_used])yylval], [],
-                  [m4_define([b4_at_dollar_used])yylloc])dnl
+               [m4_define([b4_at_dollar_used])dnl
+b4_push_if([b4_pure_if([*])yypushed_loc], [yylloc])])dnl
 /* User initialization code.  */
 b4_user_initial_action
 b4_dollar_popdef[]dnl
 m4_ifdef([b4_dollar_dollar_used],[[  yyvsp[0] = yylval;
-]])dnl
-m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 ]])])dnl
+b4_locations_if([[  yylsp[0] = ]b4_push_if([b4_pure_if([*])yypushed_loc], [yylloc])[;
+]])dnl
 [  goto yysetstate;
 
 /*------------------------------------------------------------.
