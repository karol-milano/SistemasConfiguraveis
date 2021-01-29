@@ -54,22 +54,28 @@
 /* Pure parsers.  */
 #define YYPURE 1
 
+/* Push parsers.  */
+#define YYPUSH 0
+
+/* Pull parsers.  */
+#define YYPULL 1
+
 /* Using locations.  */
 #define YYLSP_NEEDED 1
 
 /* Substitute the variable and function names.  */
-#define yyparse gram_parse
-#define yylex   gram_lex
-#define yyerror gram_error
-#define yylval  gram_lval
-#define yychar  gram_char
-#define yydebug gram_debug
-#define yynerrs gram_nerrs
-#define yylloc gram_lloc
+#define yyparse         gram_parse
+#define yylex           gram_lex
+#define yyerror         gram_error
+#define yylval          gram_lval
+#define yychar          gram_char
+#define yydebug         gram_debug
+#define yynerrs         gram_nerrs
+#define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
 
-/* Line 22 of yacc.c  */
+/* Line 189 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -146,8 +152,8 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 22 of yacc.c  */
-#line 151 "parse-gram.c"
+/* Line 189 of yacc.c  */
+#line 157 "parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -295,7 +301,7 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 
-/* Line 22 of yacc.c  */
+/* Line 214 of yacc.c  */
 #line 94 "parse-gram.y"
 
   symbol *symbol;
@@ -309,8 +315,8 @@ typedef union YYSTYPE
 
 
 
-/* Line 22 of yacc.c  */
-#line 314 "parse-gram.c"
+/* Line 214 of yacc.c  */
+#line 320 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -334,8 +340,8 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 22 of yacc.c  */
-#line 339 "parse-gram.c"
+/* Line 264 of yacc.c  */
+#line 345 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -499,9 +505,9 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
 {
-  yytype_int16 yyss;
-  YYSTYPE yyvs;
-    YYLTYPE yyls;
+  yytype_int16 yyss_alloc;
+  YYSTYPE yyvs_alloc;
+  YYLTYPE yyls_alloc;
 };
 
 /* The size of the maximum gap between one aligned stack and the next.  */
@@ -536,12 +542,12 @@ union yyalloc
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
@@ -1025,147 +1031,147 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 182 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 22 of yacc.c  */
-#line 1034 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1040 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 193 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 22 of yacc.c  */
-#line 1043 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1049 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 22 of yacc.c  */
-#line 1052 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1058 "parse-gram.c"
 	break;
       case 44: /* "\"char\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 176 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 22 of yacc.c  */
-#line 1061 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1067 "parse-gram.c"
 	break;
       case 45: /* "\"epilogue\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 22 of yacc.c  */
-#line 1070 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1076 "parse-gram.c"
 	break;
       case 47: /* "\"identifier\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 189 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 22 of yacc.c  */
-#line 1079 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1085 "parse-gram.c"
 	break;
       case 48: /* "\"identifier:\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 22 of yacc.c  */
-#line 1088 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1094 "parse-gram.c"
 	break;
       case 51: /* "\"%{...%}\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 22 of yacc.c  */
-#line 1097 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1103 "parse-gram.c"
 	break;
       case 53: /* "\"type\"" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 188 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 22 of yacc.c  */
-#line 1106 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1112 "parse-gram.c"
 	break;
       case 82: /* "variable" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 189 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 22 of yacc.c  */
-#line 1115 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1121 "parse-gram.c"
 	break;
       case 83: /* "content.opt" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 22 of yacc.c  */
-#line 1124 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1130 "parse-gram.c"
 	break;
       case 84: /* "braceless" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 22 of yacc.c  */
-#line 1133 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1139 "parse-gram.c"
 	break;
       case 85: /* "id" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 22 of yacc.c  */
-#line 1142 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1148 "parse-gram.c"
 	break;
       case 86: /* "id_colon" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 22 of yacc.c  */
-#line 1151 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1157 "parse-gram.c"
 	break;
       case 87: /* "symbol" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 22 of yacc.c  */
-#line 1160 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1166 "parse-gram.c"
 	break;
       case 88: /* "string_as_id" */
 
-/* Line 22 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 22 of yacc.c  */
-#line 1169 "parse-gram.c"
+/* Line 715 of yacc.c  */
+#line 1175 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1543,10 +1549,8 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
 	break;
     }
 }
-
 
 /* Prevent warnings from -Wmissing-prototypes.  */
-
 #ifdef YYPARSE_PARAM
 #if defined __STDC__ || defined __cplusplus
 int yyparse (void *YYPARSE_PARAM);
@@ -1565,10 +1569,9 @@ int yyparse ();
 
 
 
-
-/*----------.
-| yyparse.  |
-`----------*/
+/*-------------------------.
+| yyparse or yypush_parse.  |
+`-------------------------*/
 
 #ifdef YYPARSE_PARAM
 #if (defined __STDC__ || defined __C99__FUNC__ \
@@ -1592,94 +1595,103 @@ yyparse ()
 #endif
 #endif
 {
-  /* The lookahead symbol.  */
+/* The lookahead symbol.  */
 int yychar;
 
 /* The semantic value of the lookahead symbol.  */
 YYSTYPE yylval;
 
-/* Number of syntax errors so far.  */
-int yynerrs;
 /* Location data for the lookahead symbol.  */
 YYLTYPE yylloc;
 
-  int yystate;
-  int yyn;
-  int yyresult;
-  /* Number of tokens to shift before error messages enabled.  */
-  int yyerrstatus;
-  /* Lookahead token as an internal (translated) token number.  */
-  int yytoken = 0;
-#if YYERROR_VERBOSE
-  /* Buffer for error messages, and its allocated size.  */
-  char yymsgbuf[128];
-  char *yymsg = yymsgbuf;
-  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
-#endif
+    /* Number of syntax errors so far.  */
+    int yynerrs;
 
-  /* The stacks and their tools:
-     `yyss' is related to states.
-     `yyvs' is related to semantic values.
-     `yyls' is related to locations.
+    int yystate;
+    /* Number of tokens to shift before error messages enabled.  */
+    int yyerrstatus;
 
-     Refer to the stacks thru separate pointers, to allow yyoverflow
-     to reallocate them elsewhere.  */
+    /* The stacks and their tools:
+       `yyss': related to states.
+       `yyvs': related to semantic values.
+       `yyls': related to locations.
 
-  /* The state stack.  */
-  yytype_int16 yyssa[YYINITDEPTH];
-  yytype_int16 *yyss = yyssa;
-  yytype_int16 *yyssp;
+       Refer to the stacks thru separate pointers, to allow yyoverflow
+       to reallocate them elsewhere.  */
 
-  /* The semantic value stack.  */
-  YYSTYPE yyvsa[YYINITDEPTH];
-  YYSTYPE *yyvs = yyvsa;
-  YYSTYPE *yyvsp;
+    /* The state stack.  */
+    yytype_int16 yyssa[YYINITDEPTH];
+    yytype_int16 *yyss;
+    yytype_int16 *yyssp;
 
-  /* The location stack.  */
-  YYLTYPE yylsa[YYINITDEPTH];
-  YYLTYPE *yyls = yylsa;
-  YYLTYPE *yylsp;
-  /* The locations where the error started and ended.  */
-  YYLTYPE yyerror_range[2];
+    /* The semantic value stack.  */
+    YYSTYPE yyvsa[YYINITDEPTH];
+    YYSTYPE *yyvs;
+    YYSTYPE *yyvsp;
 
-#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))
+    /* The location stack.  */
+    YYLTYPE yylsa[YYINITDEPTH];
+    YYLTYPE *yyls;
+    YYLTYPE *yylsp;
+
+    /* The locations where the error started and ended.  */
+    YYLTYPE yyerror_range[2];
 
-  YYSIZE_T yystacksize = YYINITDEPTH;
+    YYSIZE_T yystacksize;
 
+  int yyn;
+  int yyresult;
+  /* Lookahead token as an internal (translated) token number.  */
+  int yytoken;
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;
   YYLTYPE yyloc;
 
+#if YYERROR_VERBOSE
+  /* Buffer for error messages, and its allocated size.  */
+  char yymsgbuf[128];
+  char *yymsg = yymsgbuf;
+  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
+#endif
+
+#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))
+
   /* The number of symbols on the RHS of the reduced rule.
      Keep to zero when no symbol should be popped.  */
   int yylen = 0;
 
+  yytoken = 0;
+  yyss = yyssa;
+  yyvs = yyvsa;
+  yyls = yylsa;
+
+  yystacksize = YYINITDEPTH;
+
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
   yyvsp = yyvs;
   yylsp = yyls;
+
 #if YYLTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
   yylloc.first_line   = yylloc.last_line   = 1;
   yylloc.first_column = yylloc.last_column = 1;
 #endif
 
+/* User initialization code.  */
 
-  /* User initialization code.  */
-  
-/* Line 22 of yacc.c  */
+/* Line 1247 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1688,9 +1700,10 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 22 of yacc.c  */
-#line 1693 "parse-gram.c"
+/* Line 1247 of yacc.c  */
+#line 1705 "parse-gram.c"
   yylsp[0] = yylloc;
+
   goto yysetstate;
 
 /*------------------------------------------------------------.
@@ -1727,6 +1740,7 @@ YYLTYPE yylloc;
 		    &yyvs1, yysize * sizeof (*yyvsp),
 		    &yyls1, yysize * sizeof (*yylsp),
 		    &yystacksize);
+
 	yyls = yyls1;
 	yyss = yyss1;
 	yyvs = yyvs1;
@@ -1748,9 +1762,9 @@ YYLTYPE yylloc;
 	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
 	if (! yyptr)
 	  goto yyexhaustedlab;
-	YYSTACK_RELOCATE (yyss);
-	YYSTACK_RELOCATE (yyvs);
-	YYSTACK_RELOCATE (yyls);
+	YYSTACK_RELOCATE (yyss_alloc, yyss);
+	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
+	YYSTACK_RELOCATE (yyls_alloc, yyls);
 #  undef YYSTACK_RELOCATE
 	if (yyss1 != yyssa)
 	  YYSTACK_FREE (yyss1);
@@ -1874,7 +1888,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 220 "parse-gram.y"
     {
       code_props plain_code;
@@ -1889,14 +1903,14 @@ yyreduce:
 
   case 7:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 229 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 231 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars));
@@ -1905,14 +1919,14 @@ yyreduce:
 
   case 9:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 234 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 236 "parse-gram.y"
     {
       defines_flag = true;
@@ -1922,42 +1936,42 @@ yyreduce:
 
   case 11:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 240 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 241 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 242 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 243 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 244 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 246 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -1967,7 +1981,7 @@ yyreduce:
 
   case 17:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 251 "parse-gram.y"
     {
       code_props action;
@@ -1981,77 +1995,77 @@ yyreduce:
 
   case 18:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 259 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 260 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 261 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 262 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 263 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 264 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 265 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 266 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 267 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 268 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 270 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2069,14 +2083,14 @@ yyreduce:
 
   case 29:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 282 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 284 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2105,28 +2119,28 @@ yyreduce:
 
   case 31:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 307 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 308 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 309 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 317 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2135,7 +2149,7 @@ yyreduce:
 
   case 38:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 321 "parse-gram.y"
     {
       symbol_list *list;
@@ -2147,7 +2161,7 @@ yyreduce:
 
   case 39:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 328 "parse-gram.y"
     {
       symbol_list *list;
@@ -2159,7 +2173,7 @@ yyreduce:
 
   case 40:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 335 "parse-gram.y"
     {
       default_prec = true;
@@ -2168,7 +2182,7 @@ yyreduce:
 
   case 41:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 339 "parse-gram.y"
     {
       default_prec = false;
@@ -2177,7 +2191,7 @@ yyreduce:
 
   case 42:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 343 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2189,7 +2203,7 @@ yyreduce:
 
   case 43:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 350 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2199,21 +2213,21 @@ yyreduce:
 
   case 44:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 364 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 365 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 370 "parse-gram.y"
     {
       union_seen = true;
@@ -2224,14 +2238,14 @@ yyreduce:
 
   case 47:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 381 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 382 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2241,14 +2255,14 @@ yyreduce:
 
   case 49:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 386 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 387 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2258,7 +2272,7 @@ yyreduce:
 
   case 51:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 392 "parse-gram.y"
     {
       symbol_list *list;
@@ -2271,7 +2285,7 @@ yyreduce:
 
   case 52:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 403 "parse-gram.y"
     {
       symbol_list *list;
@@ -2288,126 +2302,126 @@ yyreduce:
 
   case 53:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 417 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 418 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 419 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 423 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 424 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 432 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 436 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 437 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 445 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 449 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 450 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 454 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 455 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 456 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 457 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 463 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2417,7 +2431,7 @@ yyreduce:
 
   case 71:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 468 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2427,7 +2441,7 @@ yyreduce:
 
   case 72:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 473 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2438,7 +2452,7 @@ yyreduce:
 
   case 73:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 479 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2449,7 +2463,7 @@ yyreduce:
 
   case 74:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 485 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2461,7 +2475,7 @@ yyreduce:
 
   case 81:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 515 "parse-gram.y"
     {
       yyerrok;
@@ -2470,77 +2484,77 @@ yyreduce:
 
   case 82:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 521 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 84:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 525 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 526 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 532 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 88:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 534 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 89:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 536 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 90:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 538 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 540 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 542 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 94:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 552 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 95:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 558 "parse-gram.y"
     {
       (yyval.chars) = "";
@@ -2549,7 +2563,7 @@ yyreduce:
 
   case 97:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 571 "parse-gram.y"
     {
       code_props plain_code;
@@ -2563,14 +2577,14 @@ yyreduce:
 
   case 98:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 591 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 99:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 593 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2581,14 +2595,14 @@ yyreduce:
 
   case 100:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 601 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 103:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 613 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2598,7 +2612,7 @@ yyreduce:
 
   case 105:
 
-/* Line 22 of yacc.c  */
+/* Line 1464 of yacc.c  */
 #line 622 "parse-gram.y"
     {
       code_props plain_code;
@@ -2612,8 +2626,8 @@ yyreduce:
 
 
 
-/* Line 22 of yacc.c  */
-#line 2617 "parse-gram.c"
+/* Line 1464 of yacc.c  */
+#line 2631 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2831,7 +2845,7 @@ yyreturn:
 
 
 
-/* Line 22 of yacc.c  */
+/* Line 1684 of yacc.c  */
 #line 632 "parse-gram.y"
 
 
