@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.6.2.13-429e.  */
+/* A Bison parser, made by GNU Bison 2.6.3.3-b10d3.  */
 
 /* Bison implementation for Yacc-like parsers in C
    
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.2.13-429e"
+#define YYBISON_VERSION "2.6.3.3-b10d3"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -70,7 +70,7 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 336 of yacc.c  */
+/* Line 358 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -166,7 +166,7 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 #define YYTYPE_UINT16 uint_fast16_t
 #define YYTYPE_UINT8 uint_fast8_t
 
-/* Line 336 of yacc.c  */
+/* Line 358 of yacc.c  */
 #line 171 "parse-gram.c"
 
 # ifndef YY_NULL
@@ -187,8 +187,8 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 
 /* In a future release of Bison, this section will be replaced
    by #include "parse-gram.h".  */
-#ifndef GRAM_Y_TAB_H
-# define GRAM_Y_TAB_H
+#ifndef YY_GRAM_Y_TAB_H_INCLUDED
+# define YY_GRAM_Y_TAB_H_INCLUDED
 /* Enabling traces.  */
 #ifndef YYDEBUG
 # define YYDEBUG 1
@@ -324,7 +324,7 @@ extern int gram_debug;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 352 of yacc.c  */
+/* Line 374 of yacc.c  */
 #line 115 "parse-gram.y"
 
   symbol *symbol;
@@ -338,7 +338,7 @@ typedef union YYSTYPE
   named_ref *named_ref;
 
 
-/* Line 352 of yacc.c  */
+/* Line 374 of yacc.c  */
 #line 343 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -374,11 +374,11 @@ int gram_parse ();
 #endif
 #endif /* ! YYPARSE_PARAM */
 
-#endif /* !GRAM_Y_TAB_H  */
+#endif /* !YY_GRAM_Y_TAB_H_INCLUDED  */
 
 /* Copy the second part of user declarations.  */
 
-/* Line 355 of yacc.c  */
+/* Line 377 of yacc.c  */
 #line 383 "parse-gram.c"
 
 #ifdef short
@@ -432,24 +432,24 @@ typedef short int yytype_int16;
 # if defined YYENABLE_NLS && YYENABLE_NLS
 #  if ENABLE_NLS
 #   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
-#   define YY_(msgid) dgettext ("bison-runtime", msgid)
+#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
 #  endif
 # endif
 # ifndef YY_
-#  define YY_(msgid) msgid
+#  define YY_(Msgid) Msgid
 # endif
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
 #if ! defined lint || defined __GNUC__
-# define YYUSE(e) ((void) (e))
+# define YYUSE(E) ((void) (E))
 #else
-# define YYUSE(e) /* empty */
+# define YYUSE(E) /* empty */
 #endif
 
 /* Identity function, used to suppress warnings about constant conditions.  */
 #ifndef lint
-# define YYID(n) (n)
+# define YYID(N) (N)
 #else
 #if (defined __STDC__ || defined __C99__FUNC__ \
      || defined __cplusplus || defined _MSC_VER)
@@ -863,10 +863,10 @@ static const yytype_int16 yytable[] =
       42
 };
 
-#define yypact_value_is_default(yystate) \
-  ((yystate) == (-91))
+#define yypact_value_is_default(Yystate) \
+  (!!((Yystate) == (-91)))
 
-#define yytable_value_is_error(yytable_value) \
+#define yytable_value_is_error(Yytable_value) \
   YYID (0)
 
 static const yytype_uint8 yycheck[] =
@@ -1070,129 +1070,129 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "string" */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 205 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1078 "parse-gram.c"
 	break;
       case 4: /* "integer" */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 217 "parse-gram.y"
 	{ fprintf (stderr, "%d", ((*yyvaluep).integer)); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1085 "parse-gram.c"
 	break;
       case 43: /* "{...}" */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1092 "parse-gram.c"
 	break;
       case 44: /* "[identifier]" */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 212 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1099 "parse-gram.c"
 	break;
       case 45: /* "char" */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fputs (char_name (((*yyvaluep).character)), stderr); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1106 "parse-gram.c"
 	break;
       case 46: /* "epilogue" */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1113 "parse-gram.c"
 	break;
       case 48: /* "identifier" */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 211 "parse-gram.y"
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1120 "parse-gram.c"
 	break;
       case 49: /* "identifier:" */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 213 "parse-gram.y"
 	{ fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1127 "parse-gram.c"
 	break;
       case 52: /* "%{...%}" */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1134 "parse-gram.c"
 	break;
       case 54: /* "type" */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 214 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1141 "parse-gram.c"
 	break;
       case 71: /* symbol.prec */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1148 "parse-gram.c"
 	break;
       case 84: /* variable */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 211 "parse-gram.y"
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1155 "parse-gram.c"
 	break;
       case 85: /* content.opt */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1162 "parse-gram.c"
 	break;
       case 86: /* braceless */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1169 "parse-gram.c"
 	break;
       case 87: /* id */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1176 "parse-gram.c"
 	break;
       case 88: /* id_colon */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 221 "parse-gram.y"
 	{ fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1183 "parse-gram.c"
 	break;
       case 89: /* symbol */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1190 "parse-gram.c"
 	break;
       case 90: /* string_as_id */
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 811 of yacc.c  */
+/* Line 833 of yacc.c  */
 #line 1197 "parse-gram.c"
 	break;
       default:
@@ -1868,6 +1868,28 @@ yyparse ()
 /* The lookahead symbol.  */
 int yychar;
 
+
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
+#endif
+#ifndef YYLVAL_INITIALIZE
+# define YYLVAL_INITIALIZE()
+#endif
+#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
+# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
+# define YY_IGNORE_MAYBE_UNINITIALIZED_END
+#endif
+
 /* The semantic value of the lookahead symbol.  */
 YYSTYPE yylval;
 
@@ -1961,6 +1983,7 @@ YYLTYPE yylloc;
   yyvsp = yyvs;
   yylsp = yyls;
 
+  YYLVAL_INITIALIZE ();
 #if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
   yylloc.first_line   = yylloc.last_line   = 1;
@@ -1968,7 +1991,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1573 of yacc.c  */
+/* Line 1596 of yacc.c  */
 #line 107 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1976,8 +1999,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1573 of yacc.c  */
-#line 1981 "parse-gram.c"
+/* Line 1596 of yacc.c  */
+#line 2004 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2129,7 +2152,9 @@ yybackup:
   YY_LAC_DISCARD ("shift");
 
   yystate = yyn;
+  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   *++yyvsp = yylval;
+  YY_IGNORE_MAYBE_UNINITIALIZED_END
   *++yylsp = yylloc;
   goto yynewstate;
 
@@ -2169,7 +2194,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 246 "parse-gram.y"
     {
       code_props plain_code;
@@ -2183,13 +2208,13 @@ yyreduce:
     break;
 
   case 7:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 255 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 257 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -2198,13 +2223,13 @@ yyreduce:
     break;
 
   case 9:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 261 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 263 "parse-gram.y"
     {
       defines_flag = true;
@@ -2213,37 +2238,37 @@ yyreduce:
     break;
 
   case 11:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 267 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 268 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 269 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 270 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 271 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 273 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -2252,7 +2277,7 @@ yyreduce:
     break;
 
   case 17:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 278 "parse-gram.y"
     {
       code_props action;
@@ -2265,67 +2290,67 @@ yyreduce:
     break;
 
   case 18:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 286 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 287 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 288 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 289 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 290 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 291 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 292 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 293 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 294 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 295 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 297 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2344,13 +2369,13 @@ yyreduce:
     break;
 
   case 29:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 311 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 313 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2378,25 +2403,25 @@ yyreduce:
     break;
 
   case 31:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 336 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 337 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 338 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 346 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2404,7 +2429,7 @@ yyreduce:
     break;
 
   case 38:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 350 "parse-gram.y"
     {
       code_props code;
@@ -2420,7 +2445,7 @@ yyreduce:
     break;
 
   case 39:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 362 "parse-gram.y"
     {
       code_props code;
@@ -2436,7 +2461,7 @@ yyreduce:
     break;
 
   case 40:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 374 "parse-gram.y"
     {
       default_prec = true;
@@ -2444,7 +2469,7 @@ yyreduce:
     break;
 
   case 41:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 378 "parse-gram.y"
     {
       default_prec = false;
@@ -2452,7 +2477,7 @@ yyreduce:
     break;
 
   case 42:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 382 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2463,7 +2488,7 @@ yyreduce:
     break;
 
   case 43:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 389 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2472,19 +2497,19 @@ yyreduce:
     break;
 
   case 44:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 403 "parse-gram.y"
     {}
     break;
 
   case 45:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 404 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 409 "parse-gram.y"
     {
       union_seen = true;
@@ -2494,13 +2519,13 @@ yyreduce:
     break;
 
   case 47:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 420 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 421 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2509,13 +2534,13 @@ yyreduce:
     break;
 
   case 49:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 425 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 426 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2524,7 +2549,7 @@ yyreduce:
     break;
 
   case 51:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 431 "parse-gram.y"
     {
       symbol_list *list;
@@ -2536,7 +2561,7 @@ yyreduce:
     break;
 
   case 52:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 442 "parse-gram.y"
     {
       symbol_list *list;
@@ -2552,109 +2577,109 @@ yyreduce:
     break;
 
   case 53:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 456 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 457 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 458 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 462 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 463 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 469 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 471 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 475 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 476 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 482 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 484 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 488 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 489 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 493 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 494 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 495 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 496 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 502 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2663,7 +2688,7 @@ yyreduce:
     break;
 
   case 71:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 507 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2672,7 +2697,7 @@ yyreduce:
     break;
 
   case 72:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 512 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2682,7 +2707,7 @@ yyreduce:
     break;
 
   case 73:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 518 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2692,7 +2717,7 @@ yyreduce:
     break;
 
   case 74:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 524 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2703,7 +2728,7 @@ yyreduce:
     break;
 
   case 81:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 554 "parse-gram.y"
     {
       yyerrok;
@@ -2711,13 +2736,13 @@ yyreduce:
     break;
 
   case 82:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 560 "parse-gram.y"
     { current_lhs ((yyvsp[(1) - (2)].symbol), (yylsp[(1) - (2)]), (yyvsp[(2) - (2)].named_ref)); }
     break;
 
   case 83:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 561 "parse-gram.y"
     {
     /* Free the current lhs. */
@@ -2726,86 +2751,86 @@ yyreduce:
     break;
 
   case 84:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 568 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 569 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 575 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
 				  current_lhs_named_ref); }
     break;
 
   case 88:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 578 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 580 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 582 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 584 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 586 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 590 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 592 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 604 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 609 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 610 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 621 "parse-gram.y"
     {
       code_props plain_code;
@@ -2818,13 +2843,13 @@ yyreduce:
     break;
 
   case 101:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 641 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 643 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2834,13 +2859,13 @@ yyreduce:
     break;
 
   case 103:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 651 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 663 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2849,7 +2874,7 @@ yyreduce:
     break;
 
   case 108:
-/* Line 1788 of yacc.c  */
+/* Line 1813 of yacc.c  */
 #line 672 "parse-gram.y"
     {
       code_props plain_code;
@@ -2862,8 +2887,8 @@ yyreduce:
     break;
 
 
-/* Line 1788 of yacc.c  */
-#line 2867 "parse-gram.c"
+/* Line 1813 of yacc.c  */
+#line 2892 "parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3038,7 +3063,9 @@ yyerrlab1:
      current lookahead token, the shift below will for sure.  */
   YY_LAC_DISCARD ("error recovery");
 
+  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   *++yyvsp = yylval;
+  YY_IGNORE_MAYBE_UNINITIALIZED_END
 
   yyerror_range[2] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
@@ -3111,7 +3138,7 @@ yyreturn:
 }
 
 
-/* Line 2049 of yacc.c  */
+/* Line 2076 of yacc.c  */
 #line 682 "parse-gram.y"
 
 
