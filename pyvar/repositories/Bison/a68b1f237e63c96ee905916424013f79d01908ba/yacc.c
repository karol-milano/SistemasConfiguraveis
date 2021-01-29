@@ -181,22 +181,23 @@ int yychar;
 #else
 /* Default value used for initialization, for pacifying older GCCs
    or non-GCC compilers.  */
-static YYSTYPE yyval_default;
-# define YYLVAL_INITIALIZE() (yylval = yyval_default)
+static YYSTYPE yyval_default;]b4_locations_if([
+b4_yyloc_default_define])[
+# define YY_INITIAL_VALUE(Value) = Value
 #endif]])[
-#ifndef YYLVAL_INITIALIZE
-# define YYLVAL_INITIALIZE()
-#endif
 #ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
 # define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
 # define YY_IGNORE_MAYBE_UNINITIALIZED_END
 #endif
+#ifndef YY_INITIAL_VALUE
+# define YY_INITIAL_VALUE(Value) /* Nothing. */
+#endif
 
 /* The semantic value of the lookahead symbol.  */
-YYSTYPE yylval;]b4_locations_if([[
+YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);]b4_locations_if([[
 
 /* Location data for the lookahead symbol.  */
-YYLTYPE yylloc;]])b4_pure_if([], [[
+YYLTYPE yylloc YY_INITIAL_VALUE(yyloc_default);]])b4_pure_if([], [[
 
 /* Number of syntax errors so far.  */
 int yynerrs;]])])
@@ -1581,14 +1582,7 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   yyssp = yyss;
   yyvsp = yyvs;]b4_locations_if([[
   yylsp = yyls;]])[
-
-  YYLVAL_INITIALIZE ();]b4_locations_if([[
-#if defined ]b4_api_PREFIX[LTYPE_IS_TRIVIAL && ]b4_api_PREFIX[LTYPE_IS_TRIVIAL
-  /* Initialize the default location before parsing starts.  */
-  yylloc.first_line   = yylloc.last_line   = ]b4_location_initial_line[;
-  yylloc.first_column = yylloc.last_column = ]b4_location_initial_column[;
-#endif]])
-m4_ifdef([b4_initial_action],[
+]m4_ifdef([b4_initial_action],[
 b4_dollar_pushdef([m4_define([b4_dollar_dollar_used])yylval], [],
                   [m4_define([b4_at_dollar_used])yylloc])dnl
 /* User initialization code.  */
