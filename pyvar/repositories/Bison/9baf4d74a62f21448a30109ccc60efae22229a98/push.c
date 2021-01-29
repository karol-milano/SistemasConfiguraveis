@@ -1002,7 +1002,6 @@ int yynerrs;])b4_locations_if([[
 YYLTYPE yylloc;]])
 ])
 
-m4_define([b4_yyssa],b4_push_if([yyps->yyssa],[yyssa]))
 m4_define([b4_yyerror_range],b4_push_if([yyps->yyerror_range],[yyerror_range]))
 
 # b4_declare_parser_state_variables
@@ -1017,7 +1016,7 @@ m4_define([b4_declare_parser_state_variables],
     /* Number of tokens to shift before error messages enabled.  */
     int yyerrstatus;
     /* Look-ahead token as an internal (translated) token number.  */
-    int yytoken]b4_push_if([], [[ = 0]])[;
+    int yytoken;
 
     /* Three stacks and their tools:
        `yyss': related to states,
@@ -1029,25 +1028,26 @@ m4_define([b4_declare_parser_state_variables],
 
     /* The state stack.  */
     yytype_int16 yyssa[YYINITDEPTH];
-    yytype_int16 *yyss]b4_push_if([], [[ = yyssa]])[;
+    yytype_int16 *yyss;
     yytype_int16 *yyssp;
 
     /* The semantic value stack.  */
     YYSTYPE yyvsa[YYINITDEPTH];
-    YYSTYPE *yyvs]b4_push_if([], [[ = yyvsa]])[;
-    YYSTYPE *yyvsp;]b4_locations_if([[
+    YYSTYPE *yyvs;
+    YYSTYPE *yyvsp;
+]b4_locations_if([[
     /* The location stack.  */
     YYLTYPE yylsa[YYINITDEPTH];
-    YYLTYPE *yyls]b4_push_if([], [[ = yylsa]])[;
+    YYLTYPE *yyls;
     YYLTYPE *yylsp;
     /* The locations where the error started and ended.  */
     YYLTYPE yyerror_range[2];]])[
-    YYSIZE_T yystacksize]b4_push_if([], [[ = YYINITDEPTH]])[;
+    YYSIZE_T yystacksize;
     /* The variables used to return semantic value and location from the
        action routines.  */
-    YYSTYPE yyval;]b4_locations_if([[
-    YYLTYPE yyloc;]])
-])
+    YYSTYPE yyval;
+]b4_locations_if([[  YYLTYPE yyloc;
+]])])
 
 m4_divert_pop([KILL])dnl# ====================== End of M4 code.
 
@@ -1066,25 +1066,8 @@ b4_push_if(
 ]b4_c_function_def([[yypstate_new]], [[yypstate *]])[
 {
   yypstate *yyps = (yypstate *) malloc (sizeof *yyps);
-  yyps->yystate = 0;
   yyps->yyresult = -1;
-  yyps->yyerrstatus = 0;
-  yyps->yytoken = 0;
-
-  yyps->yyss = yyps->yyssa;
-  yyps->yyvs = yyps->yyvsa;
-
-  ]b4_locations_if([
-    yyps->yyls = yyps->yylsa;])[
-  yyps->yystacksize = YYINITDEPTH;
-
-  yyps->yyssp = yyps->yyss;
-  yyps->yyvsp = yyps->yyvs;
-
   yyps->yynew = 1;
-
-]b4_locations_if([  yyps->yylsp = yyps->yyls;])[
-
   return yyps;
 }
 
@@ -1099,11 +1082,14 @@ b4_push_if(
 #define yyresult yyps->yyresult
 #define yyerrstatus yyps->yyerrstatus
 #define yytoken yyps->yytoken
+#define yyssa yyps->yyssa
 #define yyss yyps->yyss
 #define yyssp yyps->yyssp
+#define yyvsa yyps->yyvsa
 #define yyvs yyps->yyvs
 #define yyvsp yyps->yyvsp
-]b4_locations_if([[#define yyls yyps->yyls
+]b4_locations_if([[#define yylsa yyps->yylsa
+#define yyls yyps->yyls
 #define yylsp yyps->yylsp
 ]])[#define yystacksize yyps->yystacksize
 #define yyval yyps->yyval
@@ -1141,9 +1127,6 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   /* The number of symbols on the RHS of the reduced rule.
      Keep to zero when no symbol should be popped.  */
   int yylen = 0;
-
-  YYDPRINTF ((stderr, "Starting parse\n"));
-
 ]b4_push_if([  yychar = yynchar;
   if (yynlval)
     yylval = *yynlval;
@@ -1151,7 +1134,22 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
      yylloc = *yynlloc;])[],[yynerrs = 0;
   yychar = YYEMPTY; /* Cause a token to be read.  */])[
 
-]b4_push_if([],[[
+  ]b4_push_if([
+      if (yyps->yynew == 0)
+      {
+	goto gottoken;
+      }
+      yyps->yynew= 0;])[
+
+  yytoken = 0;
+  yyss = yyssa;
+  yyvs = yyvsa;
+]b4_locations_if([[  yyls = yylsa;
+]])[
+  yystacksize = YYINITDEPTH;
+
+  YYDPRINTF ((stderr, "Starting parse\n"));
+
   yystate = 0;
   yyerrstatus = 0;
 
@@ -1162,18 +1160,13 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   yyssp = yyss;
   yyvsp = yyvs;
 ]b4_locations_if([[  yylsp = yyls;
+
 #if YYLTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
   yylloc.first_line   = yylloc.last_line   = ]b4_location_initial_line[;
   yylloc.first_column = yylloc.last_column = ]b4_location_initial_column[;
-#endif]])
-])
-[  ]b4_push_if([
-      if (yyps->yynew == 0)
-      {
-	goto gottoken;
-      }
-      yyps->yynew= 0;])
+#endif
+]])
 m4_ifdef([b4_initial_action], [
 m4_pushdef([b4_at_dollar],     [m4_define([b4_at_dollar_used])yylloc])dnl
 m4_pushdef([b4_dollar_dollar], [m4_define([b4_dollar_dollar_used])yylval])dnl
@@ -1247,7 +1240,7 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
 ]b4_locations_if([	YYSTACK_RELOCATE (yyls_alloc, yyls);])[
 #  undef YYSTACK_RELOCATE
-	if (yyss1 != ]b4_yyssa[)
+	if (yyss1 != yyssa)
 	  YYSTACK_FREE (yyss1);
       }
 # endif
@@ -1578,7 +1571,7 @@ yyreturn:
       YYPOPSTACK (1);
     }
 #ifndef yyoverflow
-  if (yyss != ]b4_yyssa[)
+  if (yyss != yyssa)
     YYSTACK_FREE (yyss);
 #endif
 ]b4_push_if([yypushreturn:])[
