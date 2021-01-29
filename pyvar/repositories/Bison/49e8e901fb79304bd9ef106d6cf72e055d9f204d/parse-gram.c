@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.1.266-7e5e.  */
+/* A Bison parser, made by GNU Bison 2.4.1.287-8f46.  */
 
 /* Bison implementation for Yacc-like parsers in C
    
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.266-7e5e"
+#define YYBISON_VERSION "2.4.1.287-8f46"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -138,11 +138,30 @@ static void add_param (char const *type, char *decl, location loc);
 
 static symbol_class current_class = unknown_sym;
 static uniqstr current_type = NULL;
-static symbol *current_lhs;
+static symbol *current_lhs_symbol;
 static location current_lhs_location;
 static named_ref *current_lhs_named_ref;
 static int current_prec = 0;
 
+/** Set the new current left-hand side symbol, possibly common
+ * to several right-hand side parts of rule.
+ */
+static
+void
+current_lhs(symbol *sym, location loc, named_ref *ref)
+{
+  current_lhs_symbol = sym;
+  current_lhs_location = loc;
+  /* In order to simplify memory management, named references for lhs
+     are always assigned by deep copy into the current symbol_list
+     node.  This is because a single named-ref in the grammar may
+     result in several uses when the user factors lhs between several
+     rules using "|".  Therefore free the parser's original copy.  */
+  free (current_lhs_named_ref);
+  current_lhs_named_ref = ref;
+}
+
+
 #define YYTYPE_INT16 int_fast16_t
 #define YYTYPE_INT8 int_fast8_t
 #define YYTYPE_UINT16 uint_fast16_t
@@ -150,7 +169,7 @@ static int current_prec = 0;
 
 
 /* Line 268 of yacc.c  */
-#line 154 "parse-gram.c"
+#line 173 "parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -301,7 +320,7 @@ typedef union YYSTYPE
 {
 
 /* Line 293 of yacc.c  */
-#line 94 "parse-gram.y"
+#line 113 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -316,7 +335,7 @@ typedef union YYSTYPE
 
 
 /* Line 293 of yacc.c  */
-#line 320 "parse-gram.c"
+#line 339 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -341,7 +360,7 @@ typedef struct YYLTYPE
 
 
 /* Line 343 of yacc.c  */
-#line 345 "parse-gram.c"
+#line 364 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -648,17 +667,17 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   209,   209,   217,   219,   223,   224,   234,   235,   240,
-     241,   246,   247,   248,   249,   250,   251,   256,   265,   266,
-     267,   268,   269,   270,   271,   272,   273,   274,   275,   290,
-     291,   315,   316,   317,   318,   322,   323,   324,   328,   335,
-     342,   346,   350,   357,   372,   373,   377,   389,   389,   394,
-     394,   399,   410,   425,   426,   427,   431,   432,   437,   439,
-     444,   445,   450,   452,   457,   458,   462,   463,   464,   465,
-     470,   475,   480,   486,   492,   503,   504,   513,   514,   520,
-     521,   522,   529,   529,   534,   535,   536,   541,   543,   545,
-     547,   549,   551,   556,   558,   569,   570,   575,   576,   577,
-     586,   606,   608,   617,   622,   623,   628,   635,   637
+       0,   228,   228,   236,   238,   242,   243,   253,   254,   259,
+     260,   265,   266,   267,   268,   269,   270,   275,   284,   285,
+     286,   287,   288,   289,   290,   291,   292,   293,   294,   309,
+     310,   334,   335,   336,   337,   341,   342,   343,   347,   354,
+     361,   365,   369,   376,   391,   392,   396,   408,   408,   413,
+     413,   418,   429,   444,   445,   446,   450,   451,   456,   458,
+     463,   464,   469,   471,   476,   477,   481,   482,   483,   484,
+     489,   494,   499,   505,   511,   522,   523,   532,   533,   539,
+     540,   541,   548,   548,   556,   557,   558,   563,   565,   567,
+     569,   571,   573,   578,   580,   591,   592,   597,   598,   599,
+     608,   628,   630,   639,   644,   645,   650,   657,   659
 };
 #endif
 
@@ -1030,164 +1049,164 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 
 /* Line 819 of yacc.c  */
-#line 184 "parse-gram.y"
+#line 203 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 819 of yacc.c  */
-#line 1038 "parse-gram.c"
+#line 1057 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
 /* Line 819 of yacc.c  */
-#line 196 "parse-gram.y"
+#line 215 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 819 of yacc.c  */
-#line 1047 "parse-gram.c"
+#line 1066 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
 /* Line 819 of yacc.c  */
-#line 186 "parse-gram.y"
+#line 205 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
 /* Line 819 of yacc.c  */
-#line 1056 "parse-gram.c"
+#line 1075 "parse-gram.c"
 	break;
       case 44: /* "\"[identifier]\"" */
 
 /* Line 819 of yacc.c  */
-#line 191 "parse-gram.y"
+#line 210 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", (yyvaluep->uniqstr)); };
 
 /* Line 819 of yacc.c  */
-#line 1065 "parse-gram.c"
+#line 1084 "parse-gram.c"
 	break;
       case 45: /* "\"char\"" */
 
 /* Line 819 of yacc.c  */
-#line 178 "parse-gram.y"
+#line 197 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 819 of yacc.c  */
-#line 1074 "parse-gram.c"
+#line 1093 "parse-gram.c"
 	break;
       case 46: /* "\"epilogue\"" */
 
 /* Line 819 of yacc.c  */
-#line 186 "parse-gram.y"
+#line 205 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 819 of yacc.c  */
-#line 1083 "parse-gram.c"
+#line 1102 "parse-gram.c"
 	break;
       case 48: /* "\"identifier\"" */
 
 /* Line 819 of yacc.c  */
-#line 190 "parse-gram.y"
+#line 209 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 819 of yacc.c  */
-#line 1092 "parse-gram.c"
+#line 1111 "parse-gram.c"
 	break;
       case 49: /* "\"identifier:\"" */
 
 /* Line 819 of yacc.c  */
-#line 192 "parse-gram.y"
+#line 211 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 819 of yacc.c  */
-#line 1101 "parse-gram.c"
+#line 1120 "parse-gram.c"
 	break;
       case 52: /* "\"%{...%}\"" */
 
 /* Line 819 of yacc.c  */
-#line 186 "parse-gram.y"
+#line 205 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 819 of yacc.c  */
-#line 1110 "parse-gram.c"
+#line 1129 "parse-gram.c"
 	break;
       case 54: /* "\"type\"" */
 
 /* Line 819 of yacc.c  */
-#line 193 "parse-gram.y"
+#line 212 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 819 of yacc.c  */
-#line 1119 "parse-gram.c"
+#line 1138 "parse-gram.c"
 	break;
       case 71: /* "symbol.prec" */
 
 /* Line 819 of yacc.c  */
-#line 199 "parse-gram.y"
+#line 218 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 819 of yacc.c  */
-#line 1128 "parse-gram.c"
+#line 1147 "parse-gram.c"
 	break;
       case 84: /* "variable" */
 
 /* Line 819 of yacc.c  */
-#line 190 "parse-gram.y"
+#line 209 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 819 of yacc.c  */
-#line 1137 "parse-gram.c"
+#line 1156 "parse-gram.c"
 	break;
       case 85: /* "content.opt" */
 
 /* Line 819 of yacc.c  */
-#line 186 "parse-gram.y"
+#line 205 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 819 of yacc.c  */
-#line 1146 "parse-gram.c"
+#line 1165 "parse-gram.c"
 	break;
       case 86: /* "braceless" */
 
 /* Line 819 of yacc.c  */
-#line 186 "parse-gram.y"
+#line 205 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 819 of yacc.c  */
-#line 1155 "parse-gram.c"
+#line 1174 "parse-gram.c"
 	break;
       case 87: /* "id" */
 
 /* Line 819 of yacc.c  */
-#line 199 "parse-gram.y"
+#line 218 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 819 of yacc.c  */
-#line 1164 "parse-gram.c"
+#line 1183 "parse-gram.c"
 	break;
       case 88: /* "id_colon" */
 
 /* Line 819 of yacc.c  */
-#line 200 "parse-gram.y"
+#line 219 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 819 of yacc.c  */
-#line 1173 "parse-gram.c"
+#line 1192 "parse-gram.c"
 	break;
       case 89: /* "symbol" */
 
 /* Line 819 of yacc.c  */
-#line 199 "parse-gram.y"
+#line 218 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 819 of yacc.c  */
-#line 1182 "parse-gram.c"
+#line 1201 "parse-gram.c"
 	break;
       case 90: /* "string_as_id" */
 
 /* Line 819 of yacc.c  */
-#line 199 "parse-gram.y"
+#line 218 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 819 of yacc.c  */
-#line 1191 "parse-gram.c"
+#line 1210 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1979,7 +1998,7 @@ YYLTYPE yylloc;
 /* User initialization code.  */
 
 /* Line 1590 of yacc.c  */
-#line 86 "parse-gram.y"
+#line 105 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1988,7 +2007,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 1590 of yacc.c  */
-#line 1992 "parse-gram.c"
+#line 2011 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2183,7 +2202,7 @@ yyreduce:
           case 6:
 
 /* Line 1806 of yacc.c  */
-#line 225 "parse-gram.y"
+#line 244 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
@@ -2198,14 +2217,14 @@ yyreduce:
   case 7:
 
 /* Line 1806 of yacc.c  */
-#line 234 "parse-gram.y"
+#line 253 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
 /* Line 1806 of yacc.c  */
-#line 236 "parse-gram.y"
+#line 255 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
@@ -2215,14 +2234,14 @@ yyreduce:
   case 9:
 
 /* Line 1806 of yacc.c  */
-#line 240 "parse-gram.y"
+#line 259 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
 /* Line 1806 of yacc.c  */
-#line 242 "parse-gram.y"
+#line 261 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -2232,42 +2251,42 @@ yyreduce:
   case 11:
 
 /* Line 1806 of yacc.c  */
-#line 246 "parse-gram.y"
+#line 265 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
 /* Line 1806 of yacc.c  */
-#line 247 "parse-gram.y"
+#line 266 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1806 of yacc.c  */
-#line 248 "parse-gram.y"
+#line 267 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
 /* Line 1806 of yacc.c  */
-#line 249 "parse-gram.y"
+#line 268 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
 /* Line 1806 of yacc.c  */
-#line 250 "parse-gram.y"
+#line 269 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
 /* Line 1806 of yacc.c  */
-#line 252 "parse-gram.y"
+#line 271 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -2277,7 +2296,7 @@ yyreduce:
   case 17:
 
 /* Line 1806 of yacc.c  */
-#line 257 "parse-gram.y"
+#line 276 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -2291,77 +2310,77 @@ yyreduce:
   case 18:
 
 /* Line 1806 of yacc.c  */
-#line 265 "parse-gram.y"
+#line 284 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
 /* Line 1806 of yacc.c  */
-#line 266 "parse-gram.y"
+#line 285 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
 /* Line 1806 of yacc.c  */
-#line 267 "parse-gram.y"
+#line 286 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
 /* Line 1806 of yacc.c  */
-#line 268 "parse-gram.y"
+#line 287 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
 /* Line 1806 of yacc.c  */
-#line 269 "parse-gram.y"
+#line 288 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
 /* Line 1806 of yacc.c  */
-#line 270 "parse-gram.y"
+#line 289 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
 /* Line 1806 of yacc.c  */
-#line 271 "parse-gram.y"
+#line 290 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
 /* Line 1806 of yacc.c  */
-#line 272 "parse-gram.y"
+#line 291 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
 /* Line 1806 of yacc.c  */
-#line 273 "parse-gram.y"
+#line 292 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
 /* Line 1806 of yacc.c  */
-#line 274 "parse-gram.y"
+#line 293 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
 /* Line 1806 of yacc.c  */
-#line 276 "parse-gram.y"
+#line 295 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
          `%define api.pure' in a backward-compatible manner here.  First, don't
@@ -2381,14 +2400,14 @@ yyreduce:
   case 29:
 
 /* Line 1806 of yacc.c  */
-#line 290 "parse-gram.y"
+#line 309 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
 /* Line 1806 of yacc.c  */
-#line 292 "parse-gram.y"
+#line 311 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (strchr (skeleton_user, '/'))
@@ -2417,28 +2436,28 @@ yyreduce:
   case 31:
 
 /* Line 1806 of yacc.c  */
-#line 315 "parse-gram.y"
+#line 334 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
 /* Line 1806 of yacc.c  */
-#line 316 "parse-gram.y"
+#line 335 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
 /* Line 1806 of yacc.c  */
-#line 317 "parse-gram.y"
+#line 336 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
 /* Line 1806 of yacc.c  */
-#line 325 "parse-gram.y"
+#line 344 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2447,7 +2466,7 @@ yyreduce:
   case 38:
 
 /* Line 1806 of yacc.c  */
-#line 329 "parse-gram.y"
+#line 348 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2459,7 +2478,7 @@ yyreduce:
   case 39:
 
 /* Line 1806 of yacc.c  */
-#line 336 "parse-gram.y"
+#line 355 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2471,7 +2490,7 @@ yyreduce:
   case 40:
 
 /* Line 1806 of yacc.c  */
-#line 343 "parse-gram.y"
+#line 362 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2480,7 +2499,7 @@ yyreduce:
   case 41:
 
 /* Line 1806 of yacc.c  */
-#line 347 "parse-gram.y"
+#line 366 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2489,7 +2508,7 @@ yyreduce:
   case 42:
 
 /* Line 1806 of yacc.c  */
-#line 351 "parse-gram.y"
+#line 370 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2501,7 +2520,7 @@ yyreduce:
   case 43:
 
 /* Line 1806 of yacc.c  */
-#line 358 "parse-gram.y"
+#line 377 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
@@ -2511,21 +2530,21 @@ yyreduce:
   case 44:
 
 /* Line 1806 of yacc.c  */
-#line 372 "parse-gram.y"
+#line 391 "parse-gram.y"
     {}
     break;
 
   case 45:
 
 /* Line 1806 of yacc.c  */
-#line 373 "parse-gram.y"
+#line 392 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
 /* Line 1806 of yacc.c  */
-#line 378 "parse-gram.y"
+#line 397 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2536,14 +2555,14 @@ yyreduce:
   case 47:
 
 /* Line 1806 of yacc.c  */
-#line 389 "parse-gram.y"
+#line 408 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
 /* Line 1806 of yacc.c  */
-#line 390 "parse-gram.y"
+#line 409 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2553,14 +2572,14 @@ yyreduce:
   case 49:
 
 /* Line 1806 of yacc.c  */
-#line 394 "parse-gram.y"
+#line 413 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
 /* Line 1806 of yacc.c  */
-#line 395 "parse-gram.y"
+#line 414 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2570,7 +2589,7 @@ yyreduce:
   case 51:
 
 /* Line 1806 of yacc.c  */
-#line 400 "parse-gram.y"
+#line 419 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2583,7 +2602,7 @@ yyreduce:
   case 52:
 
 /* Line 1806 of yacc.c  */
-#line 411 "parse-gram.y"
+#line 430 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2600,126 +2619,126 @@ yyreduce:
   case 53:
 
 /* Line 1806 of yacc.c  */
-#line 425 "parse-gram.y"
+#line 444 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
 /* Line 1806 of yacc.c  */
-#line 426 "parse-gram.y"
+#line 445 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
 /* Line 1806 of yacc.c  */
-#line 427 "parse-gram.y"
+#line 446 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
 /* Line 1806 of yacc.c  */
-#line 431 "parse-gram.y"
+#line 450 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
 /* Line 1806 of yacc.c  */
-#line 432 "parse-gram.y"
+#line 451 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
 /* Line 1806 of yacc.c  */
-#line 438 "parse-gram.y"
+#line 457 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
 /* Line 1806 of yacc.c  */
-#line 440 "parse-gram.y"
+#line 459 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
 /* Line 1806 of yacc.c  */
-#line 444 "parse-gram.y"
+#line 463 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
 /* Line 1806 of yacc.c  */
-#line 445 "parse-gram.y"
+#line 464 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
 /* Line 1806 of yacc.c  */
-#line 451 "parse-gram.y"
+#line 470 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
 /* Line 1806 of yacc.c  */
-#line 453 "parse-gram.y"
+#line 472 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
 /* Line 1806 of yacc.c  */
-#line 457 "parse-gram.y"
+#line 476 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
 /* Line 1806 of yacc.c  */
-#line 458 "parse-gram.y"
+#line 477 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
 /* Line 1806 of yacc.c  */
-#line 462 "parse-gram.y"
+#line 481 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
 /* Line 1806 of yacc.c  */
-#line 463 "parse-gram.y"
+#line 482 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
 /* Line 1806 of yacc.c  */
-#line 464 "parse-gram.y"
+#line 483 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
 /* Line 1806 of yacc.c  */
-#line 465 "parse-gram.y"
+#line 484 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
 /* Line 1806 of yacc.c  */
-#line 471 "parse-gram.y"
+#line 490 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2729,7 +2748,7 @@ yyreduce:
   case 71:
 
 /* Line 1806 of yacc.c  */
-#line 476 "parse-gram.y"
+#line 495 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2739,7 +2758,7 @@ yyreduce:
   case 72:
 
 /* Line 1806 of yacc.c  */
-#line 481 "parse-gram.y"
+#line 500 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2750,7 +2769,7 @@ yyreduce:
   case 73:
 
 /* Line 1806 of yacc.c  */
-#line 487 "parse-gram.y"
+#line 506 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2761,7 +2780,7 @@ yyreduce:
   case 74:
 
 /* Line 1806 of yacc.c  */
-#line 493 "parse-gram.y"
+#line 512 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2773,7 +2792,7 @@ yyreduce:
   case 81:
 
 /* Line 1806 of yacc.c  */
-#line 523 "parse-gram.y"
+#line 542 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2782,107 +2801,116 @@ yyreduce:
   case 82:
 
 /* Line 1806 of yacc.c  */
-#line 529 "parse-gram.y"
-    { current_lhs = (yyvsp[(1) - (2)].symbol); current_lhs_location = (yylsp[(1) - (2)]);
-    current_lhs_named_ref = (yyvsp[(2) - (2)].named_ref); }
+#line 548 "parse-gram.y"
+    { current_lhs ((yyvsp[(1) - (2)].symbol), (yylsp[(1) - (2)]), (yyvsp[(2) - (2)].named_ref)); }
+    break;
+
+  case 83:
+
+/* Line 1806 of yacc.c  */
+#line 549 "parse-gram.y"
+    {
+    /* Free the current lhs. */
+    current_lhs (0, (yylsp[(1) - (4)]), 0);
+  }
     break;
 
   case 84:
 
 /* Line 1806 of yacc.c  */
-#line 534 "parse-gram.y"
+#line 556 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
 /* Line 1806 of yacc.c  */
-#line 535 "parse-gram.y"
+#line 557 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
 /* Line 1806 of yacc.c  */
-#line 541 "parse-gram.y"
-    { grammar_current_rule_begin (current_lhs, current_lhs_location,
+#line 563 "parse-gram.y"
+    { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
 				  current_lhs_named_ref); }
     break;
 
   case 88:
 
 /* Line 1806 of yacc.c  */
-#line 544 "parse-gram.y"
+#line 566 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
 /* Line 1806 of yacc.c  */
-#line 546 "parse-gram.y"
+#line 568 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
 /* Line 1806 of yacc.c  */
-#line 548 "parse-gram.y"
+#line 570 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
 /* Line 1806 of yacc.c  */
-#line 550 "parse-gram.y"
+#line 572 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
 /* Line 1806 of yacc.c  */
-#line 552 "parse-gram.y"
+#line 574 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
 /* Line 1806 of yacc.c  */
-#line 556 "parse-gram.y"
+#line 578 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
 /* Line 1806 of yacc.c  */
-#line 558 "parse-gram.y"
+#line 580 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
 /* Line 1806 of yacc.c  */
-#line 570 "parse-gram.y"
+#line 592 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
 /* Line 1806 of yacc.c  */
-#line 575 "parse-gram.y"
+#line 597 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
 /* Line 1806 of yacc.c  */
-#line 576 "parse-gram.y"
+#line 598 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
 /* Line 1806 of yacc.c  */
-#line 587 "parse-gram.y"
+#line 609 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2896,14 +2924,14 @@ yyreduce:
   case 101:
 
 /* Line 1806 of yacc.c  */
-#line 607 "parse-gram.y"
+#line 629 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
 /* Line 1806 of yacc.c  */
-#line 609 "parse-gram.y"
+#line 631 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2914,14 +2942,14 @@ yyreduce:
   case 103:
 
 /* Line 1806 of yacc.c  */
-#line 617 "parse-gram.y"
+#line 639 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
 /* Line 1806 of yacc.c  */
-#line 629 "parse-gram.y"
+#line 651 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2931,7 +2959,7 @@ yyreduce:
   case 108:
 
 /* Line 1806 of yacc.c  */
-#line 638 "parse-gram.y"
+#line 660 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2945,7 +2973,7 @@ yyreduce:
 
 
 /* Line 1806 of yacc.c  */
-#line 2949 "parse-gram.c"
+#line 2977 "parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3195,7 +3223,7 @@ yyreturn:
 
 
 /* Line 2067 of yacc.c  */
-#line 648 "parse-gram.y"
+#line 670 "parse-gram.y"
 
 
 
