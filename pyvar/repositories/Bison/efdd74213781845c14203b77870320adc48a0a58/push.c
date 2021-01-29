@@ -152,9 +152,9 @@ b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
 m4_if(b4_prefix, [yy], [],
 [/* Substitute the variable and function names.  */
 #define yyparse b4_prefix[]parse
-#define yypushparse b4_prefix[]pushparse
+]b4_push_if([#define yypushparse b4_prefix[]pushparse
 #define yypvarsinit b4_prefix[]pvarsinit
-#define yypvars b4_prefix[]pvars
+#define yypvars b4_prefix[]pvars])[
 #define yylex   b4_prefix[]lex
 #define yyerror b4_prefix[]error
 #define yylval  b4_prefix[]lval
@@ -1002,6 +1002,9 @@ int yynerrs;b4_locations_if([
 YYLTYPE yylloc;])
 ])
 
+m4_define([b4_yyssa],b4_push_if([pv->yyssa],[yyssa]))
+m4_define([b4_yyerror_range],b4_push_if([pv->yyerror_range],[yyerror_range]))
+
 # b4_declare_yyparse_variables
 # ----------------------------
 # Declare all the variables that are needed local to YYPARSE
@@ -1027,7 +1030,6 @@ m4_define([b4_declare_yyparse_variables],
 
     /* The state stack.  */
     yytype_int16 yyssa[YYINITDEPTH];
-    yytype_int16 *yyssa_ptr;
     yytype_int16 *yyss;
     yytype_int16 *yyssp;
 
@@ -1040,8 +1042,7 @@ m4_define([b4_declare_yyparse_variables],
     YYLTYPE *yyls;
     YYLTYPE *yylsp;
     /* The locations where the error started and ended.  */
-    YYLTYPE yyerror_range[2];
-    YYLTYPE *yyerror_range_ptr;]]])[
+    YYLTYPE yyerror_range[2];]]])[
     YYSIZE_T yystacksize;
     int yylen;
     /* The variables used to return semantic value and location from the
@@ -1062,7 +1063,6 @@ yypvarsinit (void)
   pv->yyerrstatus = 0;
   pv->yytoken = 0;
 
-  pv->yyssa_ptr = pv->yyssa;
   pv->yyss = pv->yyssa;
   pv->yyvs = pv->yyvsa;
 
@@ -1153,7 +1153,6 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 
   /* The state stack.  */
   yytype_int16 yyssa[YYINITDEPTH];
-  yytype_int16 *yyssa_ptr = yyssa;
   yytype_int16 *yyss = yyssa;
   yytype_int16 *yyssp;
 
@@ -1169,7 +1168,6 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   YYLTYPE *yylsp;
   /* The locations where the error started and ended.  */
   YYLTYPE yyerror_range[2];
-  YYLTYPE *yyerror_range_ptr = yyerror_range;
   ]])[
 
 #define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N)]b4_locations_if([, yylsp -= (N)])[)
@@ -1234,7 +1232,6 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	yyerrstatus = pv->yyerrstatus;
 	yytoken = pv->yytoken;
 
-	yyssa_ptr = pv->yyssa_ptr;
 	yyss = pv->yyss;
 	yyssp = pv->yyssp;
 
@@ -1243,9 +1240,7 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 
 	]b4_locations_if([[  /* The location stack.  */
 	yyls = pv->yyls;
-	yylsp = pv->yylsp;
-
-	yyerror_range_ptr = pv->yyerror_range_ptr;]])[
+	yylsp = pv->yylsp;]])[
 
 	yystacksize = pv->yystacksize;
 	yylen = pv->yylen;
@@ -1317,7 +1312,7 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	YYSTACK_RELOCATE (yyvs);
 ]b4_locations_if([	YYSTACK_RELOCATE (yyls);])[
 #  undef YYSTACK_RELOCATE
-	if (yyss1 != yyssa_ptr)
+	if (yyss1 != ]b4_yyssa[)
 	  YYSTACK_FREE (yyss1);
       }
 # endif
@@ -1374,7 +1369,6 @@ yybackup:
 	pv->yyerrstatus = yyerrstatus;
 	pv->yytoken = yytoken;
 
-	pv->yyssa_ptr = yyssa_ptr;
 	pv->yyss = yyss;
 	pv->yyssp = yyssp;
 
@@ -1383,8 +1377,7 @@ yybackup:
 
 	]b4_locations_if([[  /* The location stack.  */
 	pv->yyls = yyls;
-	pv->yylsp = yylsp;
-	pv->yyerror_range_ptr = yyerror_range_ptr;]])[
+	pv->yylsp = yylsp;]])[
 
 	pv->yystacksize = yystacksize;
 	pv->yylen = yylen;
@@ -1543,7 +1536,7 @@ yyerrlab:
 #endif
     }
 
-]b4_locations_if([[  yyerror_range[0] = yylloc;]])[
+]b4_locations_if([[  ]b4_yyerror_range[[0] = yylloc;]])[
 
   if (yyerrstatus == 3)
     {
@@ -1580,7 +1573,7 @@ yyerrorlab:
   if (/*CONSTCOND*/ 0)
      goto yyerrorlab;
 
-]b4_locations_if([[  yyerror_range[0] = yylsp[1-yylen];
+]b4_locations_if([[  ]b4_yyerror_range[[0] = yylsp[1-yylen];
 ]])[  /* Do not reclaim the symbols of the rule which action triggered
      this YYERROR.  */
   YYPOPSTACK (yylen);
@@ -1614,7 +1607,7 @@ yyerrlab1:
       if (yyssp == yyss)
 	YYABORT;
 
-]b4_locations_if([[      yyerror_range[0] = *yylsp;]])[
+]b4_locations_if([[      ]b4_yyerror_range[[0] = *yylsp;]])[
       yydestruct ("Error: popping",
 		  yystos[yystate], yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
       YYPOPSTACK (1);
@@ -1624,10 +1617,10 @@ yyerrlab1:
 
   *++yyvsp = yylval;
 ]b4_locations_if([[
-  yyerror_range[1] = yylloc;
+  ]b4_yyerror_range[[1] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
      the lookahead.  YYLOC is available though.  */
-  YYLLOC_DEFAULT (yyloc, (yyerror_range- 1), 2);
+  YYLLOC_DEFAULT (yyloc, (]b4_yyerror_range[- 1), 2);
   *++yylsp = yyloc;]])[
 
   /* Shift the error token.  */
@@ -1676,7 +1669,7 @@ yyreturn:
       YYPOPSTACK (1);
     }
 #ifndef yyoverflow
-  if (yyss != yyssa_ptr)
+  if (yyss != ]b4_yyssa[)
     YYSTACK_FREE (yyss);
 #endif
 ]b4_push_if([yypushreturn:])[
