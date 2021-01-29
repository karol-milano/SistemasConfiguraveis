@@ -161,11 +161,7 @@ m4_if(b4_prefix, [yy], [],
 #define yychar  b4_prefix[]char
 #define yydebug b4_prefix[]debug
 #define yynerrs b4_prefix[]nerrs
-b4_locations_if([#define yylloc b4_prefix[]lloc])
-b4_push_if([
-#define yychar_set b4_prefix[]char_set
-#define yylval_set b4_prefix[]lval_set
-#define yylloc_set b4_prefix[]lloc_set])])[
+b4_locations_if([#define yylloc b4_prefix[]lloc])])[
 
 /* Copy the first part of user declarations.  */
 ]b4_user_pre_prologue[
@@ -974,14 +970,12 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 ]b4_push_if([
 struct yypvars;
 enum { YYPUSH_MORE = 4 };
-]b4_c_function_decl([yychar_set], [void], [[struct yypvars *YYPVARS], [YYPVARS]], [[int yychar], [yychar]])[
-]b4_c_function_decl([yylval_set], [void], [[struct yypvars *YYPVARS], [YYPVARS]], [[YYSTYPE yylval], [yylval]])[
-#ifdef YYLTYPE_IS_TRIVIAL
-]b4_c_function_decl([yylloc_set], [void], [[struct yypvars *YYPVARS], [YYPVARS]], [[YYLTYPE yylloc], [yylloc]])[
-#endif
 ]b4_c_function_decl([yypvarsinit], [void *], [[void], []])[
 ]b4_c_function_decl([yypushparse], [int],
-   [[struct yypvars *YYPVARS], [YYPVARS]])[
+   [[struct yypvars *yypvars], [yypvars]],
+   [[int yynchar], [yynchar]],
+   [[YYSTYPE *yynlval], [yynlval]]
+   b4_locations_if([,[[YYLTYPE *yynlloc], [yynlloc]]]))[
 ])[
 
 ]m4_divert_push([KILL])# ======================== M4 code.
@@ -997,7 +991,8 @@ int yychar;
 YYSTYPE yylval;
 
 /* Number of syntax errors so far.  */
-int yynerrs;b4_locations_if([
+]b4_push_if([],[
+int yynerrs;])[b4_locations_if([
 /* Location data for the lookahead symbol.  */
 YYLTYPE yylloc;])
 ])
@@ -1011,7 +1006,6 @@ m4_define([b4_yyerror_range],b4_push_if([pv->yyerror_range],[yyerror_range]))
 m4_define([b4_declare_yyparse_variables],
 [[struct yypvars
   {
-]]b4_declare_parser_variables[[
     int yystate;
     int yyn;
     int yyresult;
@@ -1073,45 +1067,16 @@ yypvarsinit (void)
   pv->yyssp = pv->yyss;
   pv->yyvsp = pv->yyvs;
 
-#if YYLTYPE_IS_TRIVIAL
-  /* Initialize the default location before parsing starts.  */
-  pv->yylloc.first_line   = pv->yylloc.last_line   = ]b4_location_initial_line[;
-  pv->yylloc.first_column = pv->yylloc.last_column = ]b4_location_initial_column[;
-#endif
-
   pv->yynew = 1;
 
 ]b4_locations_if([  pv->yylsp = pv->yyls;])[
 
   return (void *) pv;
-}
-
-void
-yychar_set (struct yypvars *YYPVARS, int yychar)
-{
-  if (YYPVARS)
-    YYPVARS->yychar = yychar;
-}
-
-void
-yylval_set (struct yypvars *YYPVARS, YYSTYPE yylval)
-{
-  if (YYPVARS)
-    YYPVARS->yylval = yylval;
-}
-
-#ifdef YYLTYPE_IS_TRIVIAL
-void
-yylloc_set (struct yypvars *YYPVARS, YYLTYPE yylloc)
-{
-  if (YYPVARS)
-    YYPVARS->yylloc = yylloc;
-}
-#endif])
+}])
 m4_divert_pop([KILL])dnl# ====================== End of M4 code.
 
-b4_pure_if([],
-	   [b4_declare_parser_variables])
+b4_push_if([],[b4_pure_if([],
+	   [b4_declare_parser_variables])])
 
 b4_push_if([b4_declare_yyparse_variables])
 
@@ -1120,7 +1085,9 @@ b4_push_if([b4_declare_yyparse_variables])
 `-------------------------*/
 
 b4_push_if([
-b4_c_function_def([yypushparse], [int], [[struct yypvars *YYPVARS], [YYPVARS]])],[
+b4_c_function_def([yypushparse], [int], [[struct yypvars *yypvars], [yypvars]], 
+                  [[int yynchar], [yynchar]], [[YYSTYPE *yynlval], [yynlval]]
+		  b4_locations_if([,[[YYLTYPE *yynlloc], [yynlloc]]]))],[
 #ifdef YYPARSE_PARAM
 b4_c_function_def([yyparse], [int], [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])
 #else /* ! YYPARSE_PARAM */
@@ -1128,6 +1095,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 #endif])
 {[
   ]b4_pure_if([b4_declare_parser_variables])[
+  ]b4_push_if([b4_declare_parser_variables])[
   ]b4_push_if([struct yypvars *pv;])[
   int yystate;
   int yyn;
@@ -1167,7 +1135,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   YYLTYPE *yyls = yylsa;
   YYLTYPE *yylsp;
   /* The locations where the error started and ended.  */
-  YYLTYPE yyerror_range[2];
+  ]b4_push_if([],[YYLTYPE yyerror_range[[2]]])[;
   ]])[
 
 #define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N)]b4_locations_if([, yylsp -= (N)])[)
@@ -1185,12 +1153,15 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 
   YYDPRINTF ((stderr, "Starting parse\n"));
 
-  ]b4_push_if([pv = YYPVARS;])[
-
   yystate = 0;
   yyerrstatus = 0;
-  yynerrs = 0;
-  yychar = YYEMPTY;		/* Cause a token to be read.  */
+]b4_push_if([  yychar = yynchar;
+  pv = yypvars;
+  if (yynlval)
+    yylval = *yynlval;
+]b4_locations_if([  if (yynlloc)
+     yylloc = *yynlloc;])[],[yynerrs = 0;
+  yychar = YYEMPTY; /* Cause a token to be read.  */])[
 
   /* Initialize stack pointers.
      Waste one element of value and location stack
@@ -1220,12 +1191,6 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 ]])dnl
 [  ]b4_push_if([
 	/* Initialize the locals to the current context. */
-	yychar = pv->yychar;
-	yylval = pv->yylval;
-	yynerrs = pv->yynerrs;
-	]b4_locations_if([
-	yylloc = pv->yylloc;])[
-
 	yystate = pv->yystate;
 	yyn = pv->yyn;
 	yyresult = pv->yyresult;
@@ -1358,12 +1323,6 @@ yybackup:
 	YYDPRINTF ((stderr, "Return for a new token:\n"));
 	yyresult = YYPUSH_MORE;
 	/* Initialize the locals to the current context. */
-	pv->yychar = yychar;
-	pv->yylval = yylval;
-	pv->yynerrs = yynerrs;
-	]b4_locations_if([
-	pv->yylloc = yylloc;])[
-
 	pv->yystate = yystate;
 	pv->yyn = yyn;
 	pv->yyerrstatus = yyerrstatus;
@@ -1498,7 +1457,7 @@ yyerrlab:
   /* If not already recovering from an error, report this error.  */
   if (!yyerrstatus)
     {
-      ++yynerrs;
+]b4_push_if([],[ ++yynerrs;])[
 #if ! YYERROR_VERBOSE
       yyerror (]b4_yyerror_args[YY_("syntax error"));
 #else
@@ -1682,28 +1641,6 @@ yyreturn:
   return YYID (yyresult);
 ]}
 
-b4_push_if([
-#ifdef YYPARSE_PARAM
-b4_c_function_def([yyparse], [int], [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])
-#else /* ! YYPARSE_PARAM */
-b4_c_function_def([yyparse], [int], b4_parse_param)
-#endif
-{[
-  struct yypvars *ctx = yypvarsinit ();
-  int status;
-  do {
-    yychar_set (ctx, yylex ());
-    yylval_set (ctx, yylval);
-#ifdef YYLTYPE_IS_TRIVIAL
-    yylloc_set (ctx, yylloc);
-#endif
-    status = yypushparse (ctx);
-  } while (status == YYPUSH_MORE);
-  free (ctx);
-  return status;
-]}])
-
-
 b4_epilogue
 b4_defines_if(
 [@output @output_header_name@
