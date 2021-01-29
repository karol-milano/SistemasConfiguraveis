@@ -49,7 +49,7 @@ m4_define([b4_yacc_pure_if],
 # ---------------
 # Arguments passed to yyerror: user args plus yylloc.
 m4_define([b4_yyerror_args],
-[b4_yacc_pure_if([b4_location_if([&yylloc, ])])dnl
+[b4_yacc_pure_if([b4_locations_if([&yylloc, ])])dnl
 m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 
 
@@ -59,7 +59,7 @@ m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 # b4_lex_param arrives quoted twice, but we want to keep only one level.
 m4_define([b4_lex_param],
 m4_dquote(b4_pure_if([[[[YYSTYPE *]], [[&yylval]]][]dnl
-b4_location_if([, [[YYLTYPE *], [&yylloc]]])m4_ifdef([b4_lex_param], [, ])])dnl
+b4_locations_if([, [[YYLTYPE *], [&yylloc]]])m4_ifdef([b4_lex_param], [, ])])dnl
 m4_ifdef([b4_lex_param], b4_lex_param)))
 
 
@@ -135,7 +135,7 @@ m4_define([b4_rhs_location],
 m4_changecom()
 m4_divert(0)dnl
 @output @output_parser_name@
-b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],
+b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])[
 
 /* C LALR(1) parser skeleton written by Richard Stallman, by
@@ -158,7 +158,7 @@ m4_if(b4_prefix, [yy], [],
 #define yychar  b4_prefix[]char
 #define yydebug b4_prefix[]debug
 #define yynerrs b4_prefix[]nerrs
-b4_location_if([#define yylloc b4_prefix[]lloc])])[
+b4_locations_if([#define yylloc b4_prefix[]lloc])])[
 
 ]b4_token_enums_defines(b4_tokens)[
 
@@ -167,7 +167,7 @@ b4_location_if([#define yylloc b4_prefix[]lloc])])[
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
-# define YYDEBUG ]b4_debug[
+# define YYDEBUG ]b4_debug_flag[
 #endif
 
 /* Enabling verbose error messages.  */
@@ -175,7 +175,7 @@ b4_location_if([#define yylloc b4_prefix[]lloc])])[
 # undef YYERROR_VERBOSE
 # define YYERROR_VERBOSE 1
 #else
-# define YYERROR_VERBOSE ]b4_error_verbose[
+# define YYERROR_VERBOSE ]b4_error_verbose_flag[
 #endif
 
 /* Enabling the token table.  */
@@ -196,7 +196,7 @@ b4_syncline([@oline@], [@ofile@])
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
 
-]b4_location_if([#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
+]b4_locations_if([#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
 typedef struct YYLTYPE
 {
   int first_line;
@@ -359,7 +359,7 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 
 #if (! defined yyoverflow \
      && (! defined __cplusplus \
-	 || (]b4_location_if([[defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
+	 || (]b4_locations_if([[defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
 	     && ]])[defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))
 
 /* A type that is properly aligned for any stack member.  */
@@ -367,7 +367,7 @@ union yyalloc
 {
   yytype_int16 yyss;
   YYSTYPE yyvs;
-  ]b4_location_if([  YYLTYPE yyls;
+  ]b4_locations_if([  YYLTYPE yyls;
 ])dnl
 [};
 
@@ -376,7 +376,7 @@ union yyalloc
 
 /* The size of an array large to enough to hold all stacks, each with
    N elements.  */
-]b4_location_if(
+]b4_locations_if(
 [# define YYSTACK_BYTES(N) \
      ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
       + 2 * YYSTACK_GAP_MAXIMUM)],
@@ -633,7 +633,7 @@ while (YYID (0))
 /* YYLEX -- calling `yylex' with the right arguments.  */
 
 #ifdef YYLEX_PARAM
-# define YYLEX yylex (]b4_pure_if([&yylval[]b4_location_if([, &yylloc]), ])[YYLEX_PARAM)
+# define YYLEX yylex (]b4_pure_if([&yylval[]b4_locations_if([, &yylloc]), ])[YYLEX_PARAM)
 #else
 # define YYLEX ]b4_c_function_call([yylex], [int], b4_lex_param)[
 #endif
@@ -658,7 +658,7 @@ do {									  \
     {									  \
       YYFPRINTF (stderr, "%s ", Title);					  \
       yy_symbol_print (stderr,						  \
-		  Type, Value]b4_location_if([, Location])[]b4_user_args[); \
+		  Type, Value]b4_locations_if([, Location])[]b4_user_args[); \
       YYFPRINTF (stderr, "\n");						  \
     }									  \
 } while (YYID (0))
@@ -693,7 +693,7 @@ do {								\
 
 ]b4_c_function_def([yy_reduce_print], [static void],
 		   [[YYSTYPE *yyvsp], [yyvsp]],
-    b4_location_if([[[YYLTYPE *yylsp], [yylsp]],])
+    b4_locations_if([[[YYLTYPE *yylsp], [yylsp]],])
 		   [[int yyrule], [yyrule]]m4_ifset([b4_parse_param], [,])
 		   b4_parse_param)[
 {
@@ -708,7 +708,7 @@ do {								\
       fprintf (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
 		       &]b4_rhs_value(yynrhs, yyi + 1)[
-		       ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
+		       ]b4_locations_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
 		       b4_user_args[);
       fprintf (stderr, "\n");
     }
@@ -717,7 +717,7 @@ do {								\
 # define YY_REDUCE_PRINT(Rule)		\
 do {					\
   if (yydebug)				\
-    yy_reduce_print (yyvsp, ]b4_location_if([yylsp, ])[Rule]b4_user_args[); \
+    yy_reduce_print (yyvsp, ]b4_locations_if([yylsp, ])[Rule]b4_user_args[); \
 } while (YYID (0))
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
@@ -971,7 +971,7 @@ int yychar;
 YYSTYPE yylval;
 
 /* Number of syntax errors so far.  */
-int yynerrs;b4_location_if([
+int yynerrs;b4_locations_if([
 /* Location data for the look-ahead symbol.  */
 YYLTYPE yylloc;])
 ])
@@ -1024,7 +1024,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   YYSTYPE *yyvs = yyvsa;
   YYSTYPE *yyvsp;
 
-]b4_location_if(
+]b4_locations_if(
 [[  /* The location stack.  */
   YYLTYPE yylsa[YYINITDEPTH];
   YYLTYPE *yyls = yylsa;
@@ -1032,14 +1032,14 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   /* The locations where the error started and ended.  */
   YYLTYPE yyerror_range[2];]])[
 
-#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N)]b4_location_if([, yylsp -= (N)])[)
+#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N)]b4_locations_if([, yylsp -= (N)])[)
 
   YYSIZE_T yystacksize = YYINITDEPTH;
 
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;
-]b4_location_if([  YYLTYPE yyloc;])[
+]b4_locations_if([  YYLTYPE yyloc;])[
 
   /* The number of symbols on the RHS of the reduced rule.
      Keep to zero when no symbol should be popped.  */
@@ -1059,7 +1059,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 
   yyssp = yyss;
   yyvsp = yyvs;
-]b4_location_if([[  yylsp = yyls;
+]b4_locations_if([[  yylsp = yyls;
 #if YYLTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
   yylloc.first_line   = yylloc.last_line   = 1;
@@ -1105,7 +1105,7 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	   memory.  */
 	YYSTYPE *yyvs1 = yyvs;
 	yytype_int16 *yyss1 = yyss;
-]b4_location_if([	YYLTYPE *yyls1 = yyls;])[
+]b4_locations_if([	YYLTYPE *yyls1 = yyls;])[
 
 	/* Each stack pointer address is followed by the size of the
 	   data in use in that stack, in bytes.  This used to be a
@@ -1114,9 +1114,9 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	yyoverflow (YY_("memory exhausted"),
 		    &yyss1, yysize * sizeof (*yyssp),
 		    &yyvs1, yysize * sizeof (*yyvsp),
-]b4_location_if([		    &yyls1, yysize * sizeof (*yylsp),])[
+]b4_locations_if([		    &yyls1, yysize * sizeof (*yylsp),])[
 		    &yystacksize);
-]b4_location_if([	yyls = yyls1;])[
+]b4_locations_if([	yyls = yyls1;])[
 	yyss = yyss1;
 	yyvs = yyvs1;
       }
@@ -1139,7 +1139,7 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	  goto yyexhaustedlab;
 	YYSTACK_RELOCATE (yyss);
 	YYSTACK_RELOCATE (yyvs);
-]b4_location_if([	YYSTACK_RELOCATE (yyls);])[
+]b4_locations_if([	YYSTACK_RELOCATE (yyls);])[
 #  undef YYSTACK_RELOCATE
 	if (yyss1 != yyssa)
 	  YYSTACK_FREE (yyss1);
@@ -1149,7 +1149,7 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 
       yyssp = yyss + yysize - 1;
       yyvsp = yyvs + yysize - 1;
-]b4_location_if([      yylsp = yyls + yysize - 1;])[
+]b4_locations_if([      yylsp = yyls + yysize - 1;])[
 
       YYDPRINTF ((stderr, "Stack size increased to %lu\n",
 		  (unsigned long int) yystacksize));
@@ -1226,7 +1226,7 @@ yybackup:
 
   yystate = yyn;
   *++yyvsp = yylval;
-]b4_location_if([  *++yylsp = yylloc;])[
+]b4_locations_if([  *++yylsp = yylloc;])[
   goto yynewstate;
 
 
@@ -1257,7 +1257,7 @@ yyreduce:
      GCC warning that YYVAL may be used uninitialized.  */
   yyval = yyvsp[1-yylen];
 
-]b4_location_if(
+]b4_locations_if(
 [[  /* Default location.  */
   YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);]])[
   YY_REDUCE_PRINT (yyn);
@@ -1275,7 +1275,7 @@ b4_syncline([@oline@], [@ofile@])[
   YY_STACK_PRINT (yyss, yyssp);
 
   *++yyvsp = yyval;
-]b4_location_if([  *++yylsp = yyloc;])[
+]b4_locations_if([  *++yylsp = yyloc;])[
 
   /* Now `shift' the result of the reduction.  Determine what state
      that goes to, based on the state we popped back to and the rule
@@ -1337,7 +1337,7 @@ yyerrlab:
 #endif
     }
 
-]b4_location_if([[  yyerror_range[0] = yylloc;]])[
+]b4_locations_if([[  yyerror_range[0] = yylloc;]])[
 
   if (yyerrstatus == 3)
     {
@@ -1353,7 +1353,7 @@ yyerrlab:
       else
 	{
 	  yydestruct ("Error: discarding",
-		      yytoken, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
+		      yytoken, &yylval]b4_locations_if([, &yylloc])[]b4_user_args[);
 	  yychar = YYEMPTY;
 	}
     }
@@ -1374,7 +1374,7 @@ yyerrorlab:
   if (/*CONSTCOND*/ 0)
      goto yyerrorlab;
 
-]b4_location_if([[  yyerror_range[0] = yylsp[1-yylen];
+]b4_locations_if([[  yyerror_range[0] = yylsp[1-yylen];
 ]])[  /* Do not reclaim the symbols of the rule which action triggered
      this YYERROR.  */
   YYPOPSTACK (yylen);
@@ -1408,9 +1408,9 @@ yyerrlab1:
       if (yyssp == yyss)
 	YYABORT;
 
-]b4_location_if([[      yyerror_range[0] = *yylsp;]])[
+]b4_locations_if([[      yyerror_range[0] = *yylsp;]])[
       yydestruct ("Error: popping",
-		  yystos[yystate], yyvsp]b4_location_if([, yylsp])[]b4_user_args[);
+		  yystos[yystate], yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
       YYPOPSTACK (1);
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
@@ -1420,7 +1420,7 @@ yyerrlab1:
     YYACCEPT;
 
   *++yyvsp = yylval;
-]b4_location_if([[
+]b4_locations_if([[
   yyerror_range[1] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
      the look-ahead.  YYLOC is available though.  */
@@ -1461,7 +1461,7 @@ yyexhaustedlab:
 yyreturn:
   if (yychar != YYEOF && yychar != YYEMPTY)
      yydestruct ("Cleanup: discarding lookahead",
-		 yytoken, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
+		 yytoken, &yylval]b4_locations_if([, &yylloc])[]b4_user_args[);
   /* Do not reclaim the symbols of the rule which action triggered
      this YYABORT or YYACCEPT.  */
   YYPOPSTACK (yylen);
@@ -1469,7 +1469,7 @@ yyreturn:
   while (yyssp != yyss)
     {
       yydestruct ("Cleanup: popping",
-		  yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[]b4_user_args[);
+		  yystos[*yyssp], yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
       YYPOPSTACK (1);
     }
 #ifndef yyoverflow
@@ -1485,9 +1485,9 @@ yyreturn:
 
 
 b4_epilogue
-m4_if(b4_defines_flag, 0, [],
+b4_defines_if(
 [@output @output_header_name@
-b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],
+b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
   [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
 
 b4_token_enums_defines(b4_tokens)
@@ -1508,7 +1508,7 @@ b4_syncline([@oline@], [@ofile@])
 b4_pure_if([],
 [extern YYSTYPE b4_prefix[]lval;])
 
-b4_location_if(
+b4_locations_if(
 [#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
 typedef struct YYLTYPE
 {
@@ -1522,7 +1522,7 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
-m4_if(b4_pure, [0],
-[extern YYLTYPE b4_prefix[]lloc;])
-])
-])
+b4_pure_if([],
+	   [extern YYLTYPE b4_prefix[]lloc;])
+])dnl b4_locations_if
+])dnl b4_defines_if
