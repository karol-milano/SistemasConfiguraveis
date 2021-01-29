@@ -152,9 +152,9 @@ b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
 m4_if(b4_prefix, [yy], [],
 [/* Substitute the variable and function names.  */
 #define yyparse b4_prefix[]parse
-]b4_push_if([#define yypushparse b4_prefix[]pushparse
-#define yypvarsinit b4_prefix[]pvarsinit
-#define yypvars b4_prefix[]pvars])[
+]b4_push_if([#define yypush_parse b4_prefix[]push_parse
+#define yypstate_init b4_prefix[]pstate_init
+#define yypstate b4_prefix[]pstate])[
 #define yylex   b4_prefix[]lex
 #define yyerror b4_prefix[]error
 #define yylval  b4_prefix[]lval
@@ -968,11 +968,11 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 #endif /* ! YYPARSE_PARAM */
 
 ]b4_push_if([
-struct yypvars;
+struct yypstate;
 enum { YYPUSH_MORE = 4 };
-]b4_c_function_decl([yypvarsinit], [struct yypvars *], [[void], []])[
-]b4_c_function_decl([yypushparse], [int],
-   [[struct yypvars *yypvars], [yypvars]],
+]b4_c_function_decl([yypstate_init], [struct yypstate *], [[void], []])[
+]b4_c_function_decl([yypush_parse], [int],
+   [[struct yypstate *yyps], [yyps]],
    [[int yynchar], [yynchar]],
    [[YYSTYPE *yynlval], [yynlval]]
    b4_locations_if([,[[YYLTYPE *yynlloc], [yynlloc]]]))[
@@ -997,14 +997,14 @@ int yynerrs;])[b4_locations_if([
 YYLTYPE yylloc;])
 ])
 
-m4_define([b4_yyssa],b4_push_if([pv->yyssa],[yyssa]))
-m4_define([b4_yyerror_range],b4_push_if([pv->yyerror_range],[yyerror_range]))
+m4_define([b4_yyssa],b4_push_if([yyps->yyssa],[yyssa]))
+m4_define([b4_yyerror_range],b4_push_if([yyps->yyerror_range],[yyerror_range]))
 
 # b4_declare_yyparse_variables
 # ----------------------------
 # Declare all the variables that are needed local to YYPARSE
 m4_define([b4_declare_yyparse_variables],
-[[struct yypvars
+[[struct yypstate
   {
     int yystate;
     int yyn;
@@ -1047,30 +1047,30 @@ m4_define([b4_declare_yyparse_variables],
   };
 
 /* Initialize the parser data structure.  */
-struct yypvars*
-yypvarsinit (void)
+struct yypstate*
+yypstate_init (void)
 {
-  struct yypvars *pv = (struct yypvars *) malloc (sizeof *pv);
-  pv->yystate = 0;
-  pv->yyresult = -1;
-  pv->yyerrstatus = 0;
-  pv->yytoken = 0;
+  struct yypstate *yyps = (struct yypstate *) malloc (sizeof *yyps);
+  yyps->yystate = 0;
+  yyps->yyresult = -1;
+  yyps->yyerrstatus = 0;
+  yyps->yytoken = 0;
 
-  pv->yyss = pv->yyssa;
-  pv->yyvs = pv->yyvsa;
+  yyps->yyss = yyps->yyssa;
+  yyps->yyvs = yyps->yyvsa;
 
   ]b4_locations_if([
-    pv->yyls = pv->yylsa;])[
-  pv->yystacksize = YYINITDEPTH;
+    yyps->yyls = yyps->yylsa;])[
+  yyps->yystacksize = YYINITDEPTH;
 
-  pv->yyssp = pv->yyss;
-  pv->yyvsp = pv->yyvs;
+  yyps->yyssp = yyps->yyss;
+  yyps->yyvsp = yyps->yyvs;
 
-  pv->yynew = 1;
+  yyps->yynew = 1;
 
-]b4_locations_if([  pv->yylsp = pv->yyls;])[
+]b4_locations_if([  yyps->yylsp = yyps->yyls;])[
 
-  return pv;
+  return yyps;
 }])
 m4_divert_pop([KILL])dnl# ====================== End of M4 code.
 
@@ -1080,11 +1080,11 @@ b4_push_if([],[b4_pure_if([],
 b4_push_if([b4_declare_yyparse_variables])
 
 /*-------------------------.
-| yyparse or yypushparse.  |
+| yyparse or yypush_parse.  |
 `-------------------------*/
 
 b4_push_if([
-b4_c_function_def([yypushparse], [int], [[struct yypvars *yypvars], [yypvars]], 
+b4_c_function_def([yypush_parse], [int], [[struct yypstate *yyps], [yyps]], 
                   [[int yynchar], [yynchar]], [[YYSTYPE *yynlval], [yynlval]]
 		  b4_locations_if([,[[YYLTYPE *yynlloc], [yynlloc]]]))],[
 #ifdef YYPARSE_PARAM
@@ -1095,7 +1095,6 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 {[
   ]b4_pure_if([b4_declare_parser_variables])[
   ]b4_push_if([b4_declare_parser_variables])[
-  ]b4_push_if([struct yypvars *pv;])[
   int yystate;
   int yyn;
   int yyresult;
@@ -1155,7 +1154,6 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   yystate = 0;
   yyerrstatus = 0;
 ]b4_push_if([  yychar = yynchar;
-  pv = yypvars;
   if (yynlval)
     yylval = *yynlval;
 ]b4_locations_if([  if (yynlloc)
@@ -1190,30 +1188,30 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 ]])dnl
 [  ]b4_push_if([
 	/* Initialize the locals to the current context. */
-	yystate = pv->yystate;
-	yyn = pv->yyn;
-	yyresult = pv->yyresult;
-	yyerrstatus = pv->yyerrstatus;
-	yytoken = pv->yytoken;
+	yystate = yyps->yystate;
+	yyn = yyps->yyn;
+	yyresult = yyps->yyresult;
+	yyerrstatus = yyps->yyerrstatus;
+	yytoken = yyps->yytoken;
 
-	yyss = pv->yyss;
-	yyssp = pv->yyssp;
+	yyss = yyps->yyss;
+	yyssp = yyps->yyssp;
 
-	yyvs = pv->yyvs;
-	yyvsp = pv->yyvsp;
+	yyvs = yyps->yyvs;
+	yyvsp = yyps->yyvsp;
 
 	]b4_locations_if([[  /* The location stack.  */
-	yyls = pv->yyls;
-	yylsp = pv->yylsp;]])[
+	yyls = yyps->yyls;
+	yylsp = yyps->yylsp;]])[
 
-	yystacksize = pv->yystacksize;
-	yyval = pv->yyval;
-	]b4_locations_if([yyloc = pv->yyloc;])[
-      if (pv->yynew == 0)
+	yystacksize = yyps->yystacksize;
+	yyval = yyps->yyval;
+	]b4_locations_if([yyloc = yyps->yyloc;])[
+      if (yyps->yynew == 0)
       {
 	goto gottoken;
       }
-      pv->yynew= 0;])[
+      yyps->yynew= 0;])[
   goto yysetstate;
 
 /*------------------------------------------------------------.
@@ -1321,24 +1319,24 @@ yybackup:
 	YYDPRINTF ((stderr, "Return for a new token:\n"));
 	yyresult = YYPUSH_MORE;
 	/* Initialize the locals to the current context. */
-	pv->yystate = yystate;
-	pv->yyn = yyn;
-	pv->yyerrstatus = yyerrstatus;
-	pv->yytoken = yytoken;
+	yyps->yystate = yystate;
+	yyps->yyn = yyn;
+	yyps->yyerrstatus = yyerrstatus;
+	yyps->yytoken = yytoken;
 
-	pv->yyss = yyss;
-	pv->yyssp = yyssp;
+	yyps->yyss = yyss;
+	yyps->yyssp = yyssp;
 
-	pv->yyvs = yyvs;
-	pv->yyvsp = yyvsp;
+	yyps->yyvs = yyvs;
+	yyps->yyvsp = yyvsp;
 
 	]b4_locations_if([[  /* The location stack.  */
-	pv->yyls = yyls;
-	pv->yylsp = yylsp;]])[
+	yyps->yyls = yyls;
+	yyps->yylsp = yylsp;]])[
 
-	pv->yystacksize = yystacksize;
-	pv->yyval = yyval;
-	]b4_locations_if([pv->yyloc = yyloc;])[
+	yyps->yystacksize = yystacksize;
+	yyps->yyval = yyval;
+	]b4_locations_if([yyps->yyloc = yyloc;])[
 	goto yypushreturn;
 gottoken:])[
       YYDPRINTF ((stderr, "Reading a token: "));
@@ -1633,7 +1631,7 @@ yyreturn:
   if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);
 #endif
-  ]b4_push_if([pv->yyresult = YYID (yyresult);])[
+  ]b4_push_if([yyps->yyresult = YYID (yyresult);])[
   /* Make sure YYID is used.  */
   return YYID (yyresult);
 ]}
@@ -1680,7 +1678,13 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
-]b4_push_if([struct ]b4_prefix[pvars;
+]b4_push_if([struct ]b4_prefix[pstate;
+]b4_c_function_decl([]b4_prefix[pstate_init], [struct ]b4_prefix[pstate *], [[void], []])[
+]b4_c_function_decl([]b4_prefix[push_parse], [int],
+   [[struct ]b4_prefix[pstate *]b4_prefix[pstate], []b4_prefix[pstate]],
+   [[int yynchar], [yynchar]],
+   [[YYSTYPE *yynlval], [yynlval]]
+   b4_locations_if([,[[YYLTYPE *yynlloc], [yynlloc]]]))[
 enum { YYPUSH_MORE = 4 };])[
 ]b4_pure_if([],
 	   [extern YYLTYPE b4_prefix[]lloc;])
