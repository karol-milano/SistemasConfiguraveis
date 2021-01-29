@@ -981,11 +981,11 @@ enum { YYPUSH_MORE = 4 };
 #endif /* ! YYPARSE_PARAM */])[
 
 ]m4_divert_push([KILL])# ======================== M4 code.
-# b4_declare_parser_variables
-# ---------------------------
+# b4_declare_scanner_communication_variables
+# ------------------------------------------
 # Declare the variables that are global, or local to YYPARSE if
 # pure-parser.
-m4_define([b4_declare_parser_variables],
+m4_define([b4_declare_scanner_communication_variables],
 [/* The lookahead symbol.  */
 int yychar;
 
@@ -1002,19 +1002,19 @@ YYLTYPE yylloc;])
 m4_define([b4_yyssa],b4_push_if([yyps->yyssa],[yyssa]))
 m4_define([b4_yyerror_range],b4_push_if([yyps->yyerror_range],[yyerror_range]))
 
-# b4_declare_yyparse_variables
-# ----------------------------
-# Declare all the variables that are needed local to YYPARSE
-m4_define([b4_declare_yyparse_variables],
-[[struct yypstate
-  {
+# b4_declare_parser_state_variables
+# ---------------------------------
+# Declare all the variables that are needed to maintain the parser state
+# between calls to yypush_parse.
+m4_define([b4_declare_parser_state_variables],
+[[
     int yystate;
     int yyn;
     int yyresult;
     /* Number of tokens to shift before error messages enabled.  */
     int yyerrstatus;
     /* Look-ahead token as an internal (translated) token number.  */
-    int yytoken;
+    int yytoken]b4_push_if([], [[ = 0]])[;
 
     /* Three stacks and their tools:
        `yyss': related to states,
@@ -1026,26 +1026,37 @@ m4_define([b4_declare_yyparse_variables],
 
     /* The state stack.  */
     yytype_int16 yyssa[YYINITDEPTH];
-    yytype_int16 *yyss;
+    yytype_int16 *yyss]b4_push_if([], [[ = yyssa]])[;
     yytype_int16 *yyssp;
 
     /* The semantic value stack.  */
     YYSTYPE yyvsa[YYINITDEPTH];
-    YYSTYPE *yyvs;
-    YYSTYPE *yyvsp;]]b4_locations_if([[[
+    YYSTYPE *yyvs]b4_push_if([], [[ = yyvsa]])[;
+    YYSTYPE *yyvsp;]b4_locations_if([[
     /* The location stack.  */
     YYLTYPE yylsa[YYINITDEPTH];
-    YYLTYPE *yyls;
+    YYLTYPE *yyls]b4_push_if([], [[ = yylsa]])[;
     YYLTYPE *yylsp;
     /* The locations where the error started and ended.  */
-    YYLTYPE yyerror_range[2];]]])[
-    YYSIZE_T yystacksize;
+    YYLTYPE yyerror_range[2];]])[
+    YYSIZE_T yystacksize]b4_push_if([], [[ = YYINITDEPTH]])[;
     /* The variables used to return semantic value and location from the
        action routines.  */
-    YYSTYPE yyval;
+    YYSTYPE yyval;]b4_locations_if([[
+    YYLTYPE yyloc;]])
+])
+
+m4_divert_pop([KILL])dnl# ====================== End of M4 code.
+
+b4_pure_if([], [b4_declare_scanner_communication_variables])
+
+b4_push_if(
+[[struct yypstate
+  {
+    ]b4_declare_parser_state_variables[
     /* Used to determine if this is the first time this instance has
        been used.  */
-    int yynew;]b4_locations_if([YYLTYPE yyloc;])[
+    int yynew;
   };
 
 /* Initialize the parser data structure.  */
@@ -1079,18 +1090,28 @@ m4_define([b4_declare_yyparse_variables],
 {
   free (yyps);
 }
-])
-m4_divert_pop([KILL])dnl# ====================== End of M4 code.
 
-b4_pure_if([], [b4_declare_parser_variables])
-
-b4_push_if([b4_declare_yyparse_variables])
+#define yystate yyps->yystate
+#define yyn yyps->yyn
+#define yyresult yyps->yyresult
+#define yyerrstatus yyps->yyerrstatus
+#define yytoken yyps->yytoken
+#define yyss yyps->yyss
+#define yyssp yyps->yyssp
+#define yyvs yyps->yyvs
+#define yyvsp yyps->yyvsp
+]b4_locations_if([[#define yyls yyps->yyls
+#define yylsp yyps->yylsp
+]])[#define yystacksize yyps->yystacksize
+#define yyval yyps->yyval
+]b4_locations_if([[#define yyloc yyps->yyloc
+]])])[
 
 /*-------------------------.
 | yyparse or yypush_parse.  |
 `-------------------------*/
 
-b4_push_if([
+]b4_push_if([
 b4_c_function_def([yypush_parse], [int], [[yypstate *yyps], [yyps]], 
                   [[int yynchar], [yynchar]],
                   [[YYSTYPE const *yynlval], [yynlval]]
@@ -1100,16 +1121,11 @@ b4_c_function_def([yypush_parse], [int], [[yypstate *yyps], [yyps]],
 b4_c_function_def([yyparse], [int], [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])
 #else /* ! YYPARSE_PARAM */
 b4_c_function_def([yyparse], [int], b4_parse_param)
-#endif])
-{[
-  ]b4_pure_if([b4_declare_parser_variables])[
-  int yystate;
-  int yyn;
-  int yyresult;
-  /* Number of tokens to shift before error messages enabled.  */
-  int yyerrstatus;
-  /* Lookahead token as an internal (translated) token number.  */
-  int yytoken = 0;
+#endif])[
+{
+  ]b4_pure_if([b4_declare_scanner_communication_variables])
+  b4_push_if([], [b4_declare_parser_state_variables])[
+
 #if YYERROR_VERBOSE
   /* Buffer for error messages, and its allocated size.  */
   char yymsgbuf[128];
@@ -1117,50 +1133,14 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
 #endif
 
-  /* Three stacks and their tools:
-     `yyss': related to states,
-     `yyvs': related to semantic values,
-     `yyls': related to locations.
-
-     Refer to the stacks thru separate pointers, to allow yyoverflow
-     to reallocate them elsewhere.  */
-
-  /* The state stack.  */
-  yytype_int16 yyssa[YYINITDEPTH];
-  yytype_int16 *yyss = yyssa;
-  yytype_int16 *yyssp;
-
-  /* The semantic value stack.  */
-  YYSTYPE yyvsa[YYINITDEPTH];
-  YYSTYPE *yyvs = yyvsa;
-  YYSTYPE *yyvsp;
-
-]b4_locations_if(
-[[  /* The location stack.  */
-  YYLTYPE yylsa[YYINITDEPTH];
-  YYLTYPE *yyls = yylsa;
-  YYLTYPE *yylsp;
-  /* The locations where the error started and ended.  */
-  ]b4_push_if([],[YYLTYPE yyerror_range[[2]]])[;
-  ]])[
-
 #define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N)]b4_locations_if([, yylsp -= (N)])[)
 
-  YYSIZE_T yystacksize = YYINITDEPTH;
-
-  /* The variables used to return semantic value and location from the
-     action routines.  */
-  YYSTYPE yyval;
-]b4_locations_if([  YYLTYPE yyloc;])[
-
   /* The number of symbols on the RHS of the reduced rule.
      Keep to zero when no symbol should be popped.  */
   int yylen = 0;
 
   YYDPRINTF ((stderr, "Starting parse\n"));
 
-  yystate = 0;
-  yyerrstatus = 0;
 ]b4_push_if([  yychar = yynchar;
   if (yynlval)
     yylval = *yynlval;
@@ -1168,6 +1148,10 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
      yylloc = *yynlloc;])[],[yynerrs = 0;
   yychar = YYEMPTY; /* Cause a token to be read.  */])[
 
+]b4_push_if([],[[
+  yystate = 0;
+  yyerrstatus = 0;
+
   /* Initialize stack pointers.
      Waste one element of value and location stack
      so that they stay on the same level as the state stack.
@@ -1176,13 +1160,18 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   yyssp = yyss;
   yyvsp = yyvs;
 ]b4_locations_if([[  yylsp = yyls;
-]b4_push_if([],[
 #if YYLTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
   yylloc.first_line   = yylloc.last_line   = ]b4_location_initial_line[;
   yylloc.first_column = yylloc.last_column = ]b4_location_initial_column[;
-#endif])[
-]])
+#endif]])
+])
+[  ]b4_push_if([
+      if (yyps->yynew == 0)
+      {
+	goto gottoken;
+      }
+      yyps->yynew= 0;])
 m4_ifdef([b4_initial_action], [
 m4_pushdef([b4_at_dollar],     [m4_define([b4_at_dollar_used])yylloc])dnl
 m4_pushdef([b4_dollar_dollar], [m4_define([b4_dollar_dollar_used])yylval])dnl
@@ -1194,32 +1183,7 @@ m4_ifdef([b4_dollar_dollar_used],[[  yyvsp[0] = yylval;
 ]])dnl
 m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 ]])dnl
-[  ]b4_push_if([
-	/* Initialize the locals to the current context. */
-	yystate = yyps->yystate;
-	yyn = yyps->yyn;
-	yyresult = yyps->yyresult;
-	yyerrstatus = yyps->yyerrstatus;
-	yytoken = yyps->yytoken;
-
-	yyss = yyps->yyss;
-	yyssp = yyps->yyssp;
-
-	yyvs = yyps->yyvs;
-	yyvsp = yyps->yyvsp;
-
-	]b4_locations_if([[  /* The location stack.  */
-	yyls = yyps->yyls;
-	yylsp = yyps->yylsp;]])[
-
-	yystacksize = yyps->yystacksize;
-	yyval = yyps->yyval;
-	]b4_locations_if([yyloc = yyps->yyloc;])[
-      if (yyps->yynew == 0)
-      {
-	goto gottoken;
-      }
-      yyps->yynew= 0;])[
+[
   goto yysetstate;
 
 /*------------------------------------------------------------.
@@ -1326,25 +1290,6 @@ yybackup:
       ]b4_push_if([
 	YYDPRINTF ((stderr, "Return for a new token:\n"));
 	yyresult = YYPUSH_MORE;
-	/* Initialize the locals to the current context. */
-	yyps->yystate = yystate;
-	yyps->yyn = yyn;
-	yyps->yyerrstatus = yyerrstatus;
-	yyps->yytoken = yytoken;
-
-	yyps->yyss = yyss;
-	yyps->yyssp = yyssp;
-
-	yyps->yyvs = yyvs;
-	yyps->yyvsp = yyvsp;
-
-	]b4_locations_if([[  /* The location stack.  */
-	yyps->yyls = yyls;
-	yyps->yylsp = yylsp;]])[
-
-	yyps->yystacksize = yystacksize;
-	yyps->yyval = yyval;
-	]b4_locations_if([yyps->yyloc = yyloc;])[
 	goto yypushreturn;
 gottoken:])[
       YYDPRINTF ((stderr, "Reading a token: "));
@@ -1639,7 +1584,6 @@ yyreturn:
   if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);
 #endif
-  ]b4_push_if([yyps->yyresult = YYID (yyresult);])[
   /* Make sure YYID is used.  */
   return YYID (yyresult);
 ]}
