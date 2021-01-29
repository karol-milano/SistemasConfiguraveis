@@ -184,7 +184,8 @@ int yychar;
    or non-GCC compilers.  */
 static YYSTYPE yyval_default;
 # define YY_INITIAL_VALUE(Value) = Value
-#endif]])[
+#endif]b4_locations_if([[
+static YYLTYPE yyloc_default][]b4_yyloc_default[;]])])[
 #ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
 # define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
 # define YY_IGNORE_MAYBE_UNINITIALIZED_END
@@ -197,7 +198,7 @@ static YYSTYPE yyval_default;
 YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);]b4_locations_if([[
 
 /* Location data for the lookahead symbol.  */
-YYLTYPE yylloc][]b4_yyloc_default[;
+YYLTYPE yylloc]b4_pure_if([ = yyloc_default], [b4_yyloc_default])[;
 ]])b4_pure_if([], [[
 
 /* Number of syntax errors so far.  */
@@ -1410,7 +1411,8 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   yypstate *yyps_local;]b4_pure_if([[
   int yychar;
   YYSTYPE yylval;]b4_locations_if([[
-  YYLTYPE yylloc][]b4_yyloc_default[;]])])[
+  static YYLTYPE yyloc_default][]b4_yyloc_default[;
+  YYLTYPE yylloc = yyloc_default;]])])[
   if (yyps)
     yyps_local = yyps;
   else
@@ -1559,8 +1561,7 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   yychar = YYEMPTY; /* Cause a token to be read.  */
 ]m4_ifdef([b4_initial_action], [
 b4_dollar_pushdef([m4_define([b4_dollar_dollar_used])yylval], [],
-               [m4_define([b4_at_dollar_used])dnl
-b4_push_if([b4_pure_if([*])yypushed_loc], [yylloc])])dnl
+                  [b4_push_if([b4_pure_if([*])yypushed_loc], [yylloc])])dnl
 /* User initialization code.  */
 b4_user_initial_action
 b4_dollar_popdef[]dnl
