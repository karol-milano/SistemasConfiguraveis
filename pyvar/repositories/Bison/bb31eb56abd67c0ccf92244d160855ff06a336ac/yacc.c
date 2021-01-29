@@ -24,7 +24,7 @@ m4_pushdef([b4_copyright_years],
 # Check the value of %define api.push-pull.
 b4_percent_define_default([[api.push-pull]], [[pull]])
 b4_percent_define_check_values([[[[api.push-pull]],
-                               [[pull]], [[push]], [[both]]]])
+                                 [[pull]], [[push]], [[both]]]])
 b4_define_flag_if([pull]) m4_define([b4_pull_flag], [[1]])
 b4_define_flag_if([push]) m4_define([b4_push_flag], [[1]])
 m4_case(b4_percent_define_get([[api.push-pull]]),
@@ -148,6 +148,68 @@ m4_define([b4_rhs_location],
           [(yylsp@{b4_subtract([$2], [$1])@})])
 
 
+## ------------------ ##
+## Parser variables.  ##
+## ------------------ ##
+
+# b4_declare_scanner_communication_variables
+# ------------------------------------------
+# Declare the variables that are global, or local to YYPARSE if
+# pure-parser.
+m4_define([b4_declare_scanner_communication_variables], [[
+/* The lookahead symbol.  */
+int yychar;
+
+/* The semantic value of the lookahead symbol.  */
+YYSTYPE yylval;]b4_locations_if([[
+
+/* Location data for the lookahead symbol.  */
+YYLTYPE yylloc;]])b4_pure_if([], [[
+
+/* Number of syntax errors so far.  */
+int yynerrs;]])])
+
+
+# b4_declare_parser_state_variables
+# ---------------------------------
+# Declare all the variables that are needed to maintain the parser state
+# between calls to yypush_parse.
+m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
+    /* Number of syntax errors so far.  */
+    int yynerrs;
+]])[
+    int yystate;
+    /* Number of tokens to shift before error messages enabled.  */
+    int yyerrstatus;
+
+    /* The stacks and their tools:
+       `yyss': related to states.
+       `yyvs': related to semantic values.]b4_locations_if([[
+       `yyls': related to locations.]])[
+
+       Refer to the stacks thru separate pointers, to allow yyoverflow
+       to reallocate them elsewhere.  */
+
+    /* The state stack.  */
+    yytype_int16 yyssa[YYINITDEPTH];
+    yytype_int16 *yyss;
+    yytype_int16 *yyssp;
+
+    /* The semantic value stack.  */
+    YYSTYPE yyvsa[YYINITDEPTH];
+    YYSTYPE *yyvs;
+    YYSTYPE *yyvsp;]b4_locations_if([[
+
+    /* The location stack.  */
+    YYLTYPE yylsa[YYINITDEPTH];
+    YYLTYPE *yyls;
+    YYLTYPE *yylsp;
+
+    /* The locations where the error started and ended.  */
+    YYLTYPE yyerror_range[2];]])[
+
+    YYSIZE_T yystacksize;]])
+
 
 ## --------------------------------------------------------- ##
 ## Defining symbol actions, e.g., printers and destructors.  ##
@@ -172,14 +234,14 @@ b4_copyright([Implementation for Bison's Yacc-like parsers in C])[
 ]b4_identification
 b4_percent_code_get([[top]])[]dnl
 m4_if(b4_prefix, [yy], [],
-[[/* Substitute the variable and function names.  */
-]b4_pull_if([[#define yyparse         ]b4_prefix[parse
-]])b4_push_if([[#define yypush_parse    ]b4_prefix[push_parse
-]b4_pull_if([[#define yypull_parse    ]b4_prefix[pull_parse
-]])[#define yypstate_new    ]b4_prefix[pstate_new
+[[/* Substitute the variable and function names.  */]b4_pull_if([[
+#define yyparse         ]b4_prefix[parse]])b4_push_if([[
+#define yypush_parse    ]b4_prefix[push_parse]b4_pull_if([[
+#define yypull_parse    ]b4_prefix[pull_parse]])[
+#define yypstate_new    ]b4_prefix[pstate_new
 #define yypstate_delete ]b4_prefix[pstate_delete
-#define yypstate        ]b4_prefix[pstate
-]])[#define yylex           ]b4_prefix[lex
+#define yypstate        ]b4_prefix[pstate]])[
+#define yylex           ]b4_prefix[lex
 #define yyerror         ]b4_prefix[error
 #define yylval          ]b4_prefix[lval
 #define yychar          ]b4_prefix[char
@@ -930,85 +992,22 @@ yysyntax_error (char *yyresult, int yystate, int yytoken)
 #endif /* YYERROR_VERBOSE */
 
 
-]b4_yydestruct_generate([b4_c_function_def])[
+]b4_yydestruct_generate([b4_c_function_def])b4_push_if([], [[
 
-]b4_push_if([],
-[[/* Prevent warnings from -Wmissing-prototypes.  */
+
+/* Prevent warnings from -Wmissing-prototypes.  */
 #ifdef YYPARSE_PARAM
 ]b4_c_function_decl([yyparse], [int],
-   [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])[
+                    [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])[
 #else /* ! YYPARSE_PARAM */
 ]b4_c_function_decl([yyparse], [int], b4_parse_param)[
-#endif /* ! YYPARSE_PARAM */]])
+#endif /* ! YYPARSE_PARAM */]])b4_pure_if([], [
 
-m4_divert_push([KILL])# ======================== M4 code.
-# b4_declare_scanner_communication_variables
-# ------------------------------------------
-# Declare the variables that are global, or local to YYPARSE if
-# pure-parser.
-m4_define([b4_declare_scanner_communication_variables],
-[[/* The lookahead symbol.  */
-int yychar;
-
-/* The semantic value of the lookahead symbol.  */
-YYSTYPE yylval;
-]b4_locations_if([[
-/* Location data for the lookahead symbol.  */
-YYLTYPE yylloc;
-]])b4_pure_if([], [[
-/* Number of syntax errors so far.  */
-int yynerrs;
-]])])
-
-# b4_declare_parser_state_variables
-# ---------------------------------
-# Declare all the variables that are needed to maintain the parser state
-# between calls to yypush_parse.
-m4_define([b4_declare_parser_state_variables],
-[b4_pure_if([[    /* Number of syntax errors so far.  */
-    int yynerrs;
-]])[
-    int yystate;
-    /* Number of tokens to shift before error messages enabled.  */
-    int yyerrstatus;
-
-    /* The stacks and their tools:
-       `yyss': related to states.
-       `yyvs': related to semantic values.]b4_locations_if([[
-       `yyls': related to locations.]])[
-
-       Refer to the stacks thru separate pointers, to allow yyoverflow
-       to reallocate them elsewhere.  */
-
-    /* The state stack.  */
-    yytype_int16 yyssa[YYINITDEPTH];
-    yytype_int16 *yyss;
-    yytype_int16 *yyssp;
-
-    /* The semantic value stack.  */
-    YYSTYPE yyvsa[YYINITDEPTH];
-    YYSTYPE *yyvs;
-    YYSTYPE *yyvsp;
-]b4_locations_if([[
-    /* The location stack.  */
-    YYLTYPE yylsa[YYINITDEPTH];
-    YYLTYPE *yyls;
-    YYLTYPE *yylsp;
+b4_declare_scanner_communication_variables])[]b4_push_if([[
 
-    /* The locations where the error started and ended.  */
-    YYLTYPE yyerror_range[2];
-]])[
-    YYSIZE_T yystacksize;
-]])
 
-m4_divert_pop([KILL])dnl# ====================== End of M4 code.
-
-b4_pure_if([], [b4_declare_scanner_communication_variables])
-
-b4_push_if(
-[[struct yypstate
-  {
-    ]b4_declare_parser_state_variables[
+struct yypstate
+  {]b4_declare_parser_state_variables[
     /* Used to determine if this is the first time this instance has
        been used.  */
     int yynew;
@@ -1080,44 +1079,53 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   free (yyps);]b4_pure_if([], [[
   yypstate_allocated = 0;]])[
 }
-
-]b4_pure_if([[#define ]b4_prefix[nerrs yyps->]b4_prefix[nerrs
-]])[#define yystate yyps->yystate
+]b4_pure_if([[
+#define ]b4_prefix[nerrs yyps->]b4_prefix[nerrs]])[
+#define yystate yyps->yystate
 #define yyerrstatus yyps->yyerrstatus
 #define yyssa yyps->yyssa
 #define yyss yyps->yyss
 #define yyssp yyps->yyssp
 #define yyvsa yyps->yyvsa
 #define yyvs yyps->yyvs
-#define yyvsp yyps->yyvsp
-]b4_locations_if([[#define yylsa yyps->yylsa
+#define yyvsp yyps->yyvsp]b4_locations_if([[
+#define yylsa yyps->yylsa
 #define yyls yyps->yyls
 #define yylsp yyps->yylsp
-#define yyerror_range yyps->yyerror_range
-]])[#define yystacksize yyps->yystacksize
-]])[
-/*-------------------------.
-| yyparse or yypush_parse.  |
-`-------------------------*/
-]b4_push_if([
-b4_c_function_def([[yypush_parse]], [[int]],
+#define yyerror_range yyps->yyerror_range]])[
+#define yystacksize yyps->yystacksize
+
+
+/*---------------.
+| yypush_parse.  |
+`---------------*/
+
+]b4_c_function_def([[yypush_parse]], [[int]],
   [[[yypstate *yyps]], [[yyps]]]b4_pure_if([,
   [[[int yypushed_char]], [[yypushed_char]]],
   [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
   [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
-  b4_parse_param]))], [
+  b4_parse_param]))], [[
+
+
+/*----------.
+| yyparse.  |
+`----------*/
+
 #ifdef YYPARSE_PARAM
-b4_c_function_def([yyparse], [int], [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])
+]b4_c_function_def([yyparse], [int],
+                   [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])[
 #else /* ! YYPARSE_PARAM */
-b4_c_function_def([yyparse], [int], b4_parse_param)
-#endif])[
-{
-]b4_pure_if([b4_declare_scanner_communication_variables])
-b4_push_if([b4_pure_if([], [[  int yypushed_char = yychar;
-  YYSTYPE yypushed_val = yylval;
-  ]b4_locations_if([[YYLTYPE yypushed_loc = yylloc;
-]])])],
-  [b4_declare_parser_state_variables])[
+]b4_c_function_def([yyparse], [int], b4_parse_param)[
+#endif]])[
+{]b4_pure_if([b4_declare_scanner_communication_variables
+])b4_push_if([b4_pure_if([], [[
+  int yypushed_char = yychar;
+  YYSTYPE yypushed_val = yylval;]b4_locations_if([[
+  YYLTYPE yypushed_loc = yylloc;]])
+])],
+  [b4_declare_parser_state_variables
+])[
   int yyn;
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
@@ -1592,11 +1600,11 @@ yyreturn:
 #ifndef yyoverflow
   if (yyss != yyssa)
     YYSTACK_FREE (yyss);
-#endif
-]b4_push_if([[  yyps->yynew = 1;
+#endif]b4_push_if([[
+  yyps->yynew = 1;
 
-yypushreturn:
-]])[#if YYERROR_VERBOSE
+yypushreturn:]])[
+#if YYERROR_VERBOSE
   if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);
 #endif
