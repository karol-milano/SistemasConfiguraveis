@@ -18,9 +18,23 @@
 # You should have received a copy of the GNU General Public License
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
-# This hack will go away when we mv push.c yacc.c.
-m4_ifndef([b4_percent_define(api.push_pull)],
-[m4_if(b4_use_push_for_pull_flag, [0], [
+# Check the value of %define api.push_pull.
+b4_percent_define_default([[api.push_pull]], [[pull]])
+b4_percent_define_check_values([[[[api.push_pull]],
+                               [[pull]], [[push]], [[both]]]])
+b4_define_flag_if([pull]) m4_define([b4_pull_flag], [[1]])
+b4_define_flag_if([push]) m4_define([b4_push_flag], [[1]])
+m4_case(b4_percent_define_get([[api.push_pull]]),
+        [pull], [m4_define([b4_push_flag], [[0]])],
+        [push], [m4_define([b4_pull_flag], [[0]])])
+
+# Handle BISON_USE_PUSH_FOR_PULL for the test suite.  So that push parsing
+# tests function as written, don't let BISON_USE_PUSH_FOR_PULL modify Bison's
+# behavior at all when push parsing is already requested.
+b4_define_flag_if([use_push_for_pull])
+b4_use_push_for_pull_if([
+  b4_push_if([m4_define([b4_use_push_for_pull_flag], [[0]])],
+             [m4_define([b4_push_flag], [[1]])])])
 
 m4_include(b4_pkgdatadir/[c.m4])
 
@@ -69,7 +83,6 @@ b4_locations_if([, [[YYLTYPE *], [&yylloc]]])m4_ifdef([b4_lex_param], [, ])])dnl
 m4_ifdef([b4_lex_param], b4_lex_param)))
 
 
-
 ## ------------ ##
 ## Data Types.  ##
 ## ------------ ##
@@ -157,15 +170,20 @@ b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
 ]b4_identification
 b4_percent_code_get([[top]])[]dnl
 m4_if(b4_prefix, [yy], [],
-[/* Substitute the variable and function names.  */
-#define yyparse b4_prefix[]parse
-#define yylex   b4_prefix[]lex
-#define yyerror b4_prefix[]error
-#define yylval  b4_prefix[]lval
-#define yychar  b4_prefix[]char
-#define yydebug b4_prefix[]debug
-#define yynerrs b4_prefix[]nerrs
-b4_locations_if([#define yylloc b4_prefix[]lloc])])[
+[[/* Substitute the variable and function names.  */
+]b4_pull_if([[#define yyparse         ]b4_prefix[parse
+]])b4_push_if([[#define yypush_parse    ]b4_prefix[push_parse
+]b4_pull_if([[#define yypull_parse    ]b4_prefix[pull_parse
+]])[#define yypstate_new    ]b4_prefix[pstate_new
+#define yypstate_delete ]b4_prefix[pstate_delete
+#define yypstate        ]b4_prefix[pstate
+]])[#define yylex           ]b4_prefix[lex
+#define yyerror         ]b4_prefix[error
+#define yylval          ]b4_prefix[lval
+#define yychar          ]b4_prefix[char
+#define yydebug         ]b4_prefix[debug
+#define yynerrs         ]b4_prefix[nerrs
+]b4_locations_if([[#define yylloc          ]b4_prefix[lloc]])])[
 
 /* Copy the first part of user declarations.  */
 ]b4_user_pre_prologue[
@@ -204,9 +222,9 @@ b4_token_enums_defines(b4_tokens)[
 # define YYSTYPE_IS_TRIVIAL 1]])])[
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
-#endif
+#endif]b4_locations_if([[
 
-]b4_locations_if([#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
+#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
 typedef struct YYLTYPE
 {
   int first_line;
@@ -217,7 +235,28 @@ typedef struct YYLTYPE
 # define yyltype YYLTYPE /* obsolescent; will be withdrawn */
 # define YYLTYPE_IS_DECLARED 1
 # define YYLTYPE_IS_TRIVIAL 1
-#endif])
+#endif]])b4_push_if([[
+
+#ifndef YYPUSH_DECLS
+#  define YYPUSH_DECLS
+struct yypstate;
+typedef struct yypstate yypstate;
+enum { YYPUSH_MORE = 4 };
+
+]b4_pull_if([b4_c_function_decl([[yyparse]], [[int]], b4_parse_param)
+])b4_c_function_decl([[yypush_parse]], [[int]],
+  [[[yypstate *yyps]], [[yyps]]]b4_pure_if([,
+  [[[int yypushed_char]], [[yypushed_char]]],
+  [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
+  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
+  b4_parse_param]))
+b4_pull_if([b4_c_function_decl([[yypull_parse]], [[int]],
+  [[[yypstate *yyps]], [[yyps]]]m4_ifset([b4_parse_param], [,
+  b4_parse_param]))])
+b4_c_function_decl([[yypstate_new]], [[yypstate *]], [[[void]], []])
+b4_c_function_decl([[yypstate_delete]], [[void]],
+                   [[[yypstate *yyps]], [[yyps]]])[
+#endif]])
 
 b4_percent_code_get([[provides]])[]dnl
 
@@ -301,7 +340,8 @@ typedef short int yytype_int16;
 
 #if ! defined yyoverflow || YYERROR_VERBOSE
 
-/* The parser invokes alloca or malloc; define the necessary symbols.  */
+]b4_push_if([],
+[[/* The parser invokes alloca or malloc; define the necessary symbols.  */
 
 # ifdef YYSTACK_USE_ALLOCA
 #  if YYSTACK_USE_ALLOCA
@@ -326,7 +366,8 @@ typedef short int yytype_int16;
 #  endif
 # endif
 
-# ifdef YYSTACK_ALLOC
+]])dnl
+[# ifdef YYSTACK_ALLOC
    /* Pacify GCC's `empty if-body' warning.  */
 #  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
 #  ifndef YYSTACK_ALLOC_MAXIMUM
@@ -374,11 +415,10 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
 {
-  yytype_int16 yyss;
-  YYSTYPE yyvs;
-  ]b4_locations_if([  YYLTYPE yyls;
-])dnl
-[};
+  yytype_int16 yyss_alloc;
+  YYSTYPE yyvs_alloc;]b4_locations_if([
+  YYLTYPE yyls_alloc;])[
+};
 
 /* The size of the maximum gap between one aligned stack and the next.  */
 # define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)
@@ -416,12 +456,12 @@ union yyalloc
    elements in the stack, and YYPTR gives the new location of the
    stack.  Advance YYPTR to a properly aligned location for the next
    stack.  */
-# define YYSTACK_RELOCATE(Stack)					\
+# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
     do									\
       {									\
 	YYSIZE_T yynewbytes;						\
-	YYCOPY (&yyptr->Stack, Stack, yysize);				\
-	Stack = &yyptr->Stack;						\
+	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
+	Stack = &yyptr->Stack_alloc;					\
 	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
 	yyptr += yynewbytes / sizeof (*yyptr);				\
       }									\
@@ -707,7 +747,7 @@ do {								\
 		   [[YYSTYPE *yyvsp], [yyvsp]],
     b4_locations_if([[[YYLTYPE *yylsp], [yylsp]],
 		   ])[[int yyrule], [yyrule]]m4_ifset([b4_parse_param], [,
-		   ])b4_parse_param)[
+		   b4_parse_param]))[
 {
   int yynrhs = yyr2[yyrule];
   int yyi;
@@ -958,59 +998,206 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 
 
 ]b4_yydestruct_generate([b4_c_function_def])[
-
-
-/* Prevent warnings from -Wmissing-prototypes.  */
 
+]b4_push_if([],
+[[/* Prevent warnings from -Wmissing-prototypes.  */
 #ifdef YYPARSE_PARAM
 ]b4_c_function_decl([yyparse], [int],
    [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])[
 #else /* ! YYPARSE_PARAM */
 ]b4_c_function_decl([yyparse], [int], b4_parse_param)[
-#endif /* ! YYPARSE_PARAM */
-
+#endif /* ! YYPARSE_PARAM */]])
 
-]m4_divert_push([KILL])# ======================== M4 code.
-# b4_declare_parser_variables
-# ---------------------------
+m4_divert_push([KILL])# ======================== M4 code.
+# b4_declare_scanner_communication_variables
+# ------------------------------------------
 # Declare the variables that are global, or local to YYPARSE if
 # pure-parser.
-m4_define([b4_declare_parser_variables],
-[/* The lookahead symbol.  */
+m4_define([b4_declare_scanner_communication_variables],
+[[/* The lookahead symbol.  */
 int yychar;
 
 /* The semantic value of the lookahead symbol.  */
 YYSTYPE yylval;
-
-/* Number of syntax errors so far.  */
-int yynerrs;b4_locations_if([
+]b4_locations_if([[
 /* Location data for the lookahead symbol.  */
-YYLTYPE yylloc;])
-])
+YYLTYPE yylloc;
+]])b4_pure_if([], [[
+/* Number of syntax errors so far.  */
+int yynerrs;
+]])])
+
+# b4_declare_parser_state_variables
+# ---------------------------------
+# Declare all the variables that are needed to maintain the parser state
+# between calls to yypush_parse.
+m4_define([b4_declare_parser_state_variables],
+[b4_pure_if([[    /* Number of syntax errors so far.  */
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
+    YYSTYPE *yyvsp;
+]b4_locations_if([[
+    /* The location stack.  */
+    YYLTYPE yylsa[YYINITDEPTH];
+    YYLTYPE *yyls;
+    YYLTYPE *yylsp;
+
+    /* The locations where the error started and ended.  */
+    YYLTYPE yyerror_range[2];
+]])[
+    YYSIZE_T yystacksize;
+]])
+
 m4_divert_pop([KILL])dnl# ====================== End of M4 code.
 
-b4_pure_if([],
-	   [b4_declare_parser_variables])
+b4_pure_if([], [b4_declare_scanner_communication_variables])
+
+b4_push_if(
+[[struct yypstate
+  {
+    ]b4_declare_parser_state_variables[
+    /* Used to determine if this is the first time this instance has
+       been used.  */
+    int yynew;
+  };
 
+]b4_pull_if([b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
+{
+  return yypull_parse (0]m4_ifset([b4_parse_param],
+                                  [[, ]b4_c_args(b4_parse_param)])[);
+}]b4_pure_if([], [[
 
-/*----------.
-| yyparse.  |
-`----------*/
+static char yypstate_allocated = 0;]])[
 
+]b4_c_function_def([[yypull_parse]], [[int]],
+  [[[yypstate *yyps]], [[yyps]]]m4_ifset([b4_parse_param], [,
+  b4_parse_param]))[
+{
+  int yystatus;
+  yypstate *yyps_local;
+]b4_pure_if([[  int yychar;
+  YYSTYPE yylval;
+]b4_locations_if([[  YYLTYPE yylloc;
+]])])[
+  if (yyps == 0)
+    {
+      yyps_local = yypstate_new ();
+      if (!yyps_local)
+        {]b4_pure_if([[
+          yyerror (]b4_yyerror_args[YY_("memory exhausted"));]], [[
+          if (!yypstate_allocated)
+            yyerror (]b4_yyerror_args[YY_("memory exhausted"));]])[
+          return 2;
+        }
+    }
+  else
+    yyps_local = yyps;
+  do {
+    yychar = YYLEX;
+    yystatus =
+      yypush_parse (yyps_local]b4_pure_if([[, yychar, &yylval]b4_locations_if([[, &yylloc]])])m4_ifset([b4_parse_param], [, b4_c_args(b4_parse_param)])[);
+  } while (yystatus == YYPUSH_MORE);
+  if (yyps == 0)
+    yypstate_delete (yyps_local);
+  return yystatus;
+}
+]])[
+/* Initialize the parser data structure.  */
+]b4_c_function_def([[yypstate_new]], [[yypstate *]])[
+{
+  yypstate *yyps;]b4_pure_if([], [[
+  if (yypstate_allocated)
+    {
+      yyerror (]b4_yyerror_args[YY_("cannot allocate multiple impure push-parser instances"));
+      return 0;
+    }]])[
+  yyps = (yypstate *) malloc (sizeof *yyps);
+  if (!yyps)
+    return 0;
+  yyps->yynew = 1;]b4_pure_if([], [[
+  yypstate_allocated = 1;]])[
+  return yyps;
+}
+
+]b4_c_function_def([[yypstate_delete]], [[void]],
+                   [[[yypstate *yyps]], [[yyps]]])[
+{
+#ifndef yyoverflow
+  /* If the stack was reallocated but the parse did not complete, then the
+     stack still needs to be freed.  */
+  if (!yyps->yynew && yyps->yyss != yyps->yyssa)
+    YYSTACK_FREE (yyps->yyss);
+#endif
+  free (yyps);]b4_pure_if([], [[
+  yypstate_allocated = 0;]])[
+}
+
+]b4_pure_if([[#define ]b4_prefix[nerrs yyps->]b4_prefix[nerrs
+]])[#define yystate yyps->yystate
+#define yyerrstatus yyps->yyerrstatus
+#define yyssa yyps->yyssa
+#define yyss yyps->yyss
+#define yyssp yyps->yyssp
+#define yyvsa yyps->yyvsa
+#define yyvs yyps->yyvs
+#define yyvsp yyps->yyvsp
+]b4_locations_if([[#define yylsa yyps->yylsa
+#define yyls yyps->yyls
+#define yylsp yyps->yylsp
+#define yyerror_range yyps->yyerror_range
+]])[#define yystacksize yyps->yystacksize
+]])[
+/*-------------------------.
+| yyparse or yypush_parse.  |
+`-------------------------*/
+]b4_push_if([
+b4_c_function_def([[yypush_parse]], [[int]],
+  [[[yypstate *yyps]], [[yyps]]]b4_pure_if([,
+  [[[int yypushed_char]], [[yypushed_char]]],
+  [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
+  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
+  b4_parse_param]))], [
 #ifdef YYPARSE_PARAM
 b4_c_function_def([yyparse], [int], [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])
 #else /* ! YYPARSE_PARAM */
 b4_c_function_def([yyparse], [int], b4_parse_param)
-#endif
-{[
-  ]b4_pure_if([b4_declare_parser_variables])[
-  int yystate;
+#endif])[
+{
+]b4_pure_if([b4_declare_scanner_communication_variables])
+b4_push_if([b4_pure_if([], [[  int yypushed_char = yychar;
+  YYSTYPE yypushed_val = yylval;
+  ]b4_locations_if([[YYLTYPE yypushed_loc = yylloc;
+]])])],
+  [b4_declare_parser_state_variables])[
   int yyn;
   int yyresult;
-  /* Number of tokens to shift before error messages enabled.  */
-  int yyerrstatus;
   /* Lookahead token as an internal (translated) token number.  */
-  int yytoken = 0;
+  int yytoken;
+  /* The variables used to return semantic value and location from the
+     action routines.  */
+  YYSTYPE yyval;
+]b4_locations_if([[  YYLTYPE yyloc;
+]])[
 #if YYERROR_VERBOSE
   /* Buffer for error messages, and its allocated size.  */
   char yymsgbuf[128];
@@ -1018,78 +1205,57 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
 #endif
 
-  /* The stacks and their tools:
-     `yyss' is related to states.
-     `yyvs' is related to semantic values.]b4_locations_if([[
-     `yyls' is related to locations.]])[
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
-  YYLTYPE yyerror_range[2];]])[
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
+]b4_push_if([[
+  if (!yyps->yynew)
+    {
+      yyn = yypact[yystate];
+      goto yyread_pushed_token;
+    }
+]])[
+  yytoken = 0;
+  yyss = yyssa;
+  yyvs = yyvsa;
+]b4_locations_if([[  yyls = yylsa;
+]])[
+  yystacksize = YYINITDEPTH;
 
   YYDPRINTF ((stderr, "Starting parse\n"));
 
   yystate = 0;
   yyerrstatus = 0;
   yynerrs = 0;
-  yychar = YYEMPTY;		/* Cause a token to be read.  */
+  yychar = YYEMPTY; /* Cause a token to be read.  */
 
   /* Initialize stack pointers.
      Waste one element of value and location stack
      so that they stay on the same level as the state stack.
      The wasted elements are never initialized.  */
-
   yyssp = yyss;
-  yyvsp = yyvs;
-]b4_locations_if([[  yylsp = yyls;
+  yyvsp = yyvs;]b4_locations_if([[
+  yylsp = yyls;
+
 #if YYLTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
   yylloc.first_line   = yylloc.last_line   = ]b4_location_initial_line[;
   yylloc.first_column = yylloc.last_column = ]b4_location_initial_column[;
-#endif
-]])
-m4_ifdef([b4_initial_action], [
+#endif]])
+m4_ifdef([b4_initial_action],[
 m4_pushdef([b4_at_dollar],     [m4_define([b4_at_dollar_used])yylloc])dnl
 m4_pushdef([b4_dollar_dollar], [m4_define([b4_dollar_dollar_used])yylval])dnl
-  /* User initialization code.  */
-  b4_user_initial_action
+/* User initialization code.  */
+b4_user_initial_action
 m4_popdef([b4_dollar_dollar])dnl
 m4_popdef([b4_at_dollar])])dnl
 m4_ifdef([b4_dollar_dollar_used],[[  yyvsp[0] = yylval;
 ]])dnl
 m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
-]])dnl
-[  goto yysetstate;
+]])[
+  goto yysetstate;
 
 /*------------------------------------------------------------.
 | yynewstate -- Push a new state, which is found in yystate.  |
@@ -1113,8 +1279,8 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	   these so that the &'s don't force the real ones into
 	   memory.  */
 	YYSTYPE *yyvs1 = yyvs;
-	yytype_int16 *yyss1 = yyss;
-]b4_locations_if([	YYLTYPE *yyls1 = yyls;])[
+	yytype_int16 *yyss1 = yyss;]b4_locations_if([
+	YYLTYPE *yyls1 = yyls;])[
 
 	/* Each stack pointer address is followed by the size of the
 	   data in use in that stack, in bytes.  This used to be a
@@ -1122,10 +1288,11 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	   be undefined if yyoverflow is a macro.  */
 	yyoverflow (YY_("memory exhausted"),
 		    &yyss1, yysize * sizeof (*yyssp),
-		    &yyvs1, yysize * sizeof (*yyvsp),
-]b4_locations_if([		    &yyls1, yysize * sizeof (*yylsp),])[
+		    &yyvs1, yysize * sizeof (*yyvsp),]b4_locations_if([
+		    &yyls1, yysize * sizeof (*yylsp),])[
 		    &yystacksize);
-]b4_locations_if([	yyls = yyls1;])[
+]b4_locations_if([
+	yyls = yyls1;])[
 	yyss = yyss1;
 	yyvs = yyvs1;
       }
@@ -1146,9 +1313,9 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
 	if (! yyptr)
 	  goto yyexhaustedlab;
-	YYSTACK_RELOCATE (yyss);
-	YYSTACK_RELOCATE (yyvs);
-]b4_locations_if([	YYSTACK_RELOCATE (yyls);])[
+	YYSTACK_RELOCATE (yyss_alloc, yyss);
+	YYSTACK_RELOCATE (yyvs_alloc, yyvs);]b4_locations_if([
+	YYSTACK_RELOCATE (yyls_alloc, yyls);])[
 #  undef YYSTACK_RELOCATE
 	if (yyss1 != yyssa)
 	  YYSTACK_FREE (yyss1);
@@ -1157,8 +1324,8 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 #endif /* no yyoverflow */
 
       yyssp = yyss + yysize - 1;
-      yyvsp = yyvs + yysize - 1;
-]b4_locations_if([      yylsp = yyls + yysize - 1;])[
+      yyvsp = yyvs + yysize - 1;]b4_locations_if([
+      yylsp = yyls + yysize - 1;])[
 
       YYDPRINTF ((stderr, "Stack size increased to %lu\n",
 		  (unsigned long int) yystacksize));
@@ -1192,9 +1359,32 @@ yybackup:
   /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
   if (yychar == YYEMPTY)
     {
-      YYDPRINTF ((stderr, "Reading a token: "));
-      yychar = YYLEX;
-    }
+]b4_push_if([[      if (!yyps->yynew)
+        {
+]b4_use_push_for_pull_if([],
+[[          YYDPRINTF ((stderr, "Return for a new token:\n"));
+]])[          yyresult = YYPUSH_MORE;
+          goto yypushreturn;
+        }
+      yyps->yynew = 0;
+]b4_pure_if([], [[
+      /* Restoring the pushed token is only necessary for the first
+         yypush_parse invocation since subsequent invocations don't overwrite
+         it before jumping to yyread_pushed_token.  */
+      yychar = yypushed_char;
+      yylval = yypushed_val;
+      ]b4_locations_if([[yylloc = yypushed_loc;
+]])])[
+yyread_pushed_token:
+]])[      YYDPRINTF ((stderr, "Reading a token: "));
+]b4_push_if([b4_pure_if([[      yychar = yypushed_char;
+      if (yypushed_val)
+        yylval = *yypushed_val;
+]b4_locations_if([[      if (yypushed_loc)
+        yylloc = *yypushed_loc;
+]])])],
+[[      yychar = YYLEX;
+]])[    }
 
   if (yychar <= YYEOF)
     {
@@ -1280,8 +1470,8 @@ yyreduce:
   yylen = 0;
   YY_STACK_PRINT (yyss, yyssp);
 
-  *++yyvsp = yyval;
-]b4_locations_if([  *++yylsp = yyloc;])[
+  *++yyvsp = yyval;]b4_locations_if([
+  *++yylsp = yyloc;])[
 
   /* Now `shift' the result of the reduction.  Determine what state
      that goes to, based on the state we popped back to and the rule
@@ -1479,16 +1669,19 @@ yyreturn:
   if (yyss != yyssa)
     YYSTACK_FREE (yyss);
 #endif
-#if YYERROR_VERBOSE
+]b4_push_if([[  yyps->yynew = 1;
+
+yypushreturn:
+]])[#if YYERROR_VERBOSE
   if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);
 #endif
   /* Make sure YYID is used.  */
   return YYID (yyresult);
-]}
+}
 
 
-b4_epilogue
+]b4_epilogue
 b4_defines_if(
 [@output(b4_spec_defines_file@)
 b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
@@ -1512,8 +1705,7 @@ b4_token_enums_defines(b4_tokens)
 # define YYSTYPE_IS_DECLARED 1
 #endif
 
-]b4_pure_if([],
-[extern YYSTYPE b4_prefix[]lval;])
+]b4_pure_if([], [[extern YYSTYPE ]b4_prefix[lval;]])
 
 b4_locations_if(
 [#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
@@ -1529,14 +1721,30 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
-]b4_pure_if([],
-	   [extern YYLTYPE b4_prefix[]lloc;])
+]b4_pure_if([], [[extern YYLTYPE ]b4_prefix[lloc;]])
 )dnl b4_locations_if
-
-b4_percent_code_get([[provides]])
+b4_push_if([[
+#ifndef YYPUSH_DECLS
+#  define YYPUSH_DECLS
+struct ]b4_prefix[pstate;
+typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
+enum { YYPUSH_MORE = 4 };
+]b4_pull_if([b4_c_function_decl([b4_prefix[parse]], [[int]], b4_parse_param)
+])b4_c_function_decl([b4_prefix[push_parse]], [[int]],
+  [[b4_prefix[pstate *yyps]], [[yyps]]]b4_pure_if([,
+  [[[int yypushed_char]], [[yypushed_char]]],
+  [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
+  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
+  b4_parse_param]))
+b4_pull_if([b4_c_function_decl([b4_prefix[pull_parse]], [[int]],
+  [[b4_prefix[pstate *yyps]], [[yyps]]]m4_ifset([b4_parse_param], [,
+  b4_parse_param]))])
+b4_c_function_decl([b4_prefix[pstate_new]], [b4_prefix[pstate *]],
+                    [[[void]], []])
+b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
+                   [[b4_prefix[pstate *yyps]], [[yyps]]])[
+#endif
+]])
+b4_percent_code_get([[provides]])[]dnl
 ])dnl b4_defines_if
 m4_divert_pop(0)
-
-],
-[m4_include(b4_pkgdatadir/[push.c])])],
-[m4_include(b4_pkgdatadir/[push.c])])
