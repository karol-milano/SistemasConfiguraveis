@@ -170,6 +170,28 @@ m4_define([b4_declare_scanner_communication_variables], [[
 /* The lookahead symbol.  */
 int yychar;
 
+]b4_pure_if([[
+#if defined __GNUC__ && (4 < __GNUC__ + (6 <= __GNUC_MINOR__))
+/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
+# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
+    _Pragma ("GCC diagnostic push") \
+    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
+# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
+    _Pragma ("GCC diagnostic pop")
+#else
+/* Default value used for initialization, for pacifying older GCCs
+   or non-GCC compilers.  */
+static YYSTYPE yyval_default;
+# define YYLVAL_INITIALIZE() (yylval = yyval_default)
+#endif]])[
+#ifndef YYLVAL_INITIALIZE
+# define YYLVAL_INITIALIZE()
+#endif
+#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
+# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
+# define YY_IGNORE_MAYBE_UNINITIALIZED_END
+#endif
+
 /* The semantic value of the lookahead symbol.  */
 YYSTYPE yylval;]b4_locations_if([[
 
@@ -1563,8 +1585,9 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
      The wasted elements are never initialized.  */
   yyssp = yyss;
   yyvsp = yyvs;]b4_locations_if([[
-  yylsp = yyls;
+  yylsp = yyls;]])[
 
+  YYLVAL_INITIALIZE ();]b4_locations_if([[
 #if defined ]b4_api_PREFIX[LTYPE_IS_TRIVIAL && ]b4_api_PREFIX[LTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
   yylloc.first_line   = yylloc.last_line   = ]b4_location_initial_line[;
@@ -1750,7 +1773,9 @@ yyread_pushed_token:]])[
   YY_LAC_DISCARD ("shift");]])[
 
   yystate = yyn;
+  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   *++yyvsp = yylval;
+  YY_IGNORE_MAYBE_UNINITIALIZED_END
 ]b4_locations_if([  *++yylsp = yylloc;])[
   goto yynewstate;
 
@@ -1970,7 +1995,9 @@ yyerrlab1:
      current lookahead token, the shift below will for sure.  */
   YY_LAC_DISCARD ("error recovery");]])[
 
+  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   *++yyvsp = yylval;
+  YY_IGNORE_MAYBE_UNINITIALIZED_END
 ]b4_locations_if([[
   yyerror_range[2] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
