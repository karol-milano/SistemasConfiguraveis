@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.5.118-ae42b.  */
+/* A Bison parser, made by GNU Bison 2.5.127-8555-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
    
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.5.118-ae42b"
+#define YYBISON_VERSION "2.5.127-8555-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -109,6 +109,7 @@
 #include "symlist.h"
 #include "scan-gram.h"
 #include "scan-code.h"
+#include "xmemdup0.h"
 
 #define YYLLOC_DEFAULT(Current, Rhs, N)  (Current) = lloc_default (Rhs, N)
 static YYLTYPE lloc_default (YYLTYPE const *, int);
@@ -169,7 +170,7 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 
 
 /* Line 268 of yacc.c  */
-#line 173 "parse-gram.c"
+#line 174 "parse-gram.c"
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -328,7 +329,7 @@ typedef union YYSTYPE
 {
 
 /* Line 295 of yacc.c  */
-#line 113 "parse-gram.y"
+#line 114 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -343,7 +344,7 @@ typedef union YYSTYPE
 
 
 /* Line 295 of yacc.c  */
-#line 347 "parse-gram.c"
+#line 348 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -368,7 +369,7 @@ typedef struct YYLTYPE
 
 
 /* Line 345 of yacc.c  */
-#line 372 "parse-gram.c"
+#line 373 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -675,17 +676,17 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   228,   228,   236,   238,   242,   243,   253,   254,   259,
-     260,   265,   266,   267,   268,   269,   270,   275,   284,   285,
-     286,   287,   288,   289,   290,   291,   292,   293,   294,   309,
-     310,   334,   335,   336,   337,   341,   342,   343,   347,   354,
-     361,   365,   369,   376,   391,   392,   396,   408,   408,   413,
-     413,   418,   429,   444,   445,   446,   450,   451,   456,   458,
-     463,   464,   469,   471,   476,   477,   481,   482,   483,   484,
-     489,   494,   499,   505,   511,   522,   523,   532,   533,   539,
-     540,   541,   548,   548,   556,   557,   558,   563,   565,   567,
-     569,   571,   573,   578,   580,   591,   592,   597,   598,   599,
-     608,   628,   630,   639,   644,   645,   650,   657,   659
+       0,   229,   229,   237,   239,   243,   244,   254,   255,   260,
+     261,   266,   267,   268,   269,   270,   271,   276,   285,   286,
+     287,   288,   289,   290,   291,   292,   293,   294,   295,   310,
+     311,   335,   336,   337,   338,   342,   343,   344,   348,   355,
+     362,   366,   370,   377,   392,   393,   397,   409,   409,   414,
+     414,   419,   430,   445,   446,   447,   451,   452,   457,   459,
+     464,   465,   470,   472,   477,   478,   482,   483,   484,   485,
+     490,   495,   500,   506,   512,   523,   524,   533,   534,   540,
+     541,   542,   549,   549,   557,   558,   559,   564,   566,   568,
+     570,   572,   574,   579,   581,   592,   593,   598,   599,   600,
+     609,   629,   631,   640,   645,   646,   651,   658,   660
 };
 #endif
 
@@ -1060,164 +1061,164 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 
 /* Line 823 of yacc.c  */
-#line 203 "parse-gram.y"
+#line 204 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 823 of yacc.c  */
-#line 1068 "parse-gram.c"
+#line 1069 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
 /* Line 823 of yacc.c  */
-#line 215 "parse-gram.y"
+#line 216 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 823 of yacc.c  */
-#line 1077 "parse-gram.c"
+#line 1078 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
 /* Line 823 of yacc.c  */
-#line 205 "parse-gram.y"
+#line 206 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
 /* Line 823 of yacc.c  */
-#line 1086 "parse-gram.c"
+#line 1087 "parse-gram.c"
 	break;
       case 44: /* "\"[identifier]\"" */
 
 /* Line 823 of yacc.c  */
-#line 210 "parse-gram.y"
+#line 211 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", (yyvaluep->uniqstr)); };
 
 /* Line 823 of yacc.c  */
-#line 1095 "parse-gram.c"
+#line 1096 "parse-gram.c"
 	break;
       case 45: /* "\"char\"" */
 
 /* Line 823 of yacc.c  */
-#line 197 "parse-gram.y"
+#line 198 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 823 of yacc.c  */
-#line 1104 "parse-gram.c"
+#line 1105 "parse-gram.c"
 	break;
       case 46: /* "\"epilogue\"" */
 
 /* Line 823 of yacc.c  */
-#line 205 "parse-gram.y"
+#line 206 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 823 of yacc.c  */
-#line 1113 "parse-gram.c"
+#line 1114 "parse-gram.c"
 	break;
       case 48: /* "\"identifier\"" */
 
 /* Line 823 of yacc.c  */
-#line 209 "parse-gram.y"
+#line 210 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 823 of yacc.c  */
-#line 1122 "parse-gram.c"
+#line 1123 "parse-gram.c"
 	break;
       case 49: /* "\"identifier:\"" */
 
 /* Line 823 of yacc.c  */
-#line 211 "parse-gram.y"
+#line 212 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 823 of yacc.c  */
-#line 1131 "parse-gram.c"
+#line 1132 "parse-gram.c"
 	break;
       case 52: /* "\"%{...%}\"" */
 
 /* Line 823 of yacc.c  */
-#line 205 "parse-gram.y"
+#line 206 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 823 of yacc.c  */
-#line 1140 "parse-gram.c"
+#line 1141 "parse-gram.c"
 	break;
       case 54: /* "\"type\"" */
 
 /* Line 823 of yacc.c  */
-#line 212 "parse-gram.y"
+#line 213 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 823 of yacc.c  */
-#line 1149 "parse-gram.c"
+#line 1150 "parse-gram.c"
 	break;
       case 71: /* "symbol.prec" */
 
 /* Line 823 of yacc.c  */
-#line 218 "parse-gram.y"
+#line 219 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 823 of yacc.c  */
-#line 1158 "parse-gram.c"
+#line 1159 "parse-gram.c"
 	break;
       case 84: /* "variable" */
 
 /* Line 823 of yacc.c  */
-#line 209 "parse-gram.y"
+#line 210 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 823 of yacc.c  */
-#line 1167 "parse-gram.c"
+#line 1168 "parse-gram.c"
 	break;
       case 85: /* "content.opt" */
 
 /* Line 823 of yacc.c  */
-#line 205 "parse-gram.y"
+#line 206 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 823 of yacc.c  */
-#line 1176 "parse-gram.c"
+#line 1177 "parse-gram.c"
 	break;
       case 86: /* "braceless" */
 
 /* Line 823 of yacc.c  */
-#line 205 "parse-gram.y"
+#line 206 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 823 of yacc.c  */
-#line 1185 "parse-gram.c"
+#line 1186 "parse-gram.c"
 	break;
       case 87: /* "id" */
 
 /* Line 823 of yacc.c  */
-#line 218 "parse-gram.y"
+#line 219 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 823 of yacc.c  */
-#line 1194 "parse-gram.c"
+#line 1195 "parse-gram.c"
 	break;
       case 88: /* "id_colon" */
 
 /* Line 823 of yacc.c  */
-#line 219 "parse-gram.y"
+#line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 823 of yacc.c  */
-#line 1203 "parse-gram.c"
+#line 1204 "parse-gram.c"
 	break;
       case 89: /* "symbol" */
 
 /* Line 823 of yacc.c  */
-#line 218 "parse-gram.y"
+#line 219 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 823 of yacc.c  */
-#line 1212 "parse-gram.c"
+#line 1213 "parse-gram.c"
 	break;
       case 90: /* "string_as_id" */
 
 /* Line 823 of yacc.c  */
-#line 218 "parse-gram.y"
+#line 219 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 823 of yacc.c  */
-#line 1221 "parse-gram.c"
+#line 1222 "parse-gram.c"
 	break;
       default:
 	break;
@@ -2009,7 +2010,7 @@ YYLTYPE yylloc;
 /* User initialization code.  */
 
 /* Line 1594 of yacc.c  */
-#line 105 "parse-gram.y"
+#line 106 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -2018,7 +2019,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 1594 of yacc.c  */
-#line 2022 "parse-gram.c"
+#line 2023 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2213,7 +2214,7 @@ yyreduce:
           case 6:
 
 /* Line 1810 of yacc.c  */
-#line 244 "parse-gram.y"
+#line 245 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
@@ -2228,14 +2229,14 @@ yyreduce:
   case 7:
 
 /* Line 1810 of yacc.c  */
-#line 253 "parse-gram.y"
+#line 254 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
 /* Line 1810 of yacc.c  */
-#line 255 "parse-gram.y"
+#line 256 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
@@ -2245,14 +2246,14 @@ yyreduce:
   case 9:
 
 /* Line 1810 of yacc.c  */
-#line 259 "parse-gram.y"
+#line 260 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
 /* Line 1810 of yacc.c  */
-#line 261 "parse-gram.y"
+#line 262 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -2262,42 +2263,42 @@ yyreduce:
   case 11:
 
 /* Line 1810 of yacc.c  */
-#line 265 "parse-gram.y"
+#line 266 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
 /* Line 1810 of yacc.c  */
-#line 266 "parse-gram.y"
+#line 267 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1810 of yacc.c  */
-#line 267 "parse-gram.y"
+#line 268 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
 /* Line 1810 of yacc.c  */
-#line 268 "parse-gram.y"
+#line 269 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
 /* Line 1810 of yacc.c  */
-#line 269 "parse-gram.y"
+#line 270 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
 /* Line 1810 of yacc.c  */
-#line 271 "parse-gram.y"
+#line 272 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -2307,7 +2308,7 @@ yyreduce:
   case 17:
 
 /* Line 1810 of yacc.c  */
-#line 276 "parse-gram.y"
+#line 277 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -2321,77 +2322,77 @@ yyreduce:
   case 18:
 
 /* Line 1810 of yacc.c  */
-#line 284 "parse-gram.y"
+#line 285 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
 /* Line 1810 of yacc.c  */
-#line 285 "parse-gram.y"
+#line 286 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
 /* Line 1810 of yacc.c  */
-#line 286 "parse-gram.y"
+#line 287 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
 /* Line 1810 of yacc.c  */
-#line 287 "parse-gram.y"
+#line 288 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
 /* Line 1810 of yacc.c  */
-#line 288 "parse-gram.y"
+#line 289 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
 /* Line 1810 of yacc.c  */
-#line 289 "parse-gram.y"
+#line 290 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
 /* Line 1810 of yacc.c  */
-#line 290 "parse-gram.y"
+#line 291 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
 /* Line 1810 of yacc.c  */
-#line 291 "parse-gram.y"
+#line 292 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
 /* Line 1810 of yacc.c  */
-#line 292 "parse-gram.y"
+#line 293 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
 /* Line 1810 of yacc.c  */
-#line 293 "parse-gram.y"
+#line 294 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
 /* Line 1810 of yacc.c  */
-#line 295 "parse-gram.y"
+#line 296 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
          `%define api.pure' in a backward-compatible manner here.  First, don't
@@ -2411,14 +2412,14 @@ yyreduce:
   case 29:
 
 /* Line 1810 of yacc.c  */
-#line 309 "parse-gram.y"
+#line 310 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
 /* Line 1810 of yacc.c  */
-#line 311 "parse-gram.y"
+#line 312 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (mbschr (skeleton_user, '/'))
@@ -2447,28 +2448,28 @@ yyreduce:
   case 31:
 
 /* Line 1810 of yacc.c  */
-#line 334 "parse-gram.y"
+#line 335 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
 /* Line 1810 of yacc.c  */
-#line 335 "parse-gram.y"
+#line 336 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
 /* Line 1810 of yacc.c  */
-#line 336 "parse-gram.y"
+#line 337 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
 /* Line 1810 of yacc.c  */
-#line 344 "parse-gram.y"
+#line 345 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2477,7 +2478,7 @@ yyreduce:
   case 38:
 
 /* Line 1810 of yacc.c  */
-#line 348 "parse-gram.y"
+#line 349 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2489,7 +2490,7 @@ yyreduce:
   case 39:
 
 /* Line 1810 of yacc.c  */
-#line 355 "parse-gram.y"
+#line 356 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2501,7 +2502,7 @@ yyreduce:
   case 40:
 
 /* Line 1810 of yacc.c  */
-#line 362 "parse-gram.y"
+#line 363 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2510,7 +2511,7 @@ yyreduce:
   case 41:
 
 /* Line 1810 of yacc.c  */
-#line 366 "parse-gram.y"
+#line 367 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2519,7 +2520,7 @@ yyreduce:
   case 42:
 
 /* Line 1810 of yacc.c  */
-#line 370 "parse-gram.y"
+#line 371 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2531,7 +2532,7 @@ yyreduce:
   case 43:
 
 /* Line 1810 of yacc.c  */
-#line 377 "parse-gram.y"
+#line 378 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
@@ -2541,21 +2542,21 @@ yyreduce:
   case 44:
 
 /* Line 1810 of yacc.c  */
-#line 391 "parse-gram.y"
+#line 392 "parse-gram.y"
     {}
     break;
 
   case 45:
 
 /* Line 1810 of yacc.c  */
-#line 392 "parse-gram.y"
+#line 393 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
 /* Line 1810 of yacc.c  */
-#line 397 "parse-gram.y"
+#line 398 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2566,14 +2567,14 @@ yyreduce:
   case 47:
 
 /* Line 1810 of yacc.c  */
-#line 408 "parse-gram.y"
+#line 409 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
 /* Line 1810 of yacc.c  */
-#line 409 "parse-gram.y"
+#line 410 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2583,14 +2584,14 @@ yyreduce:
   case 49:
 
 /* Line 1810 of yacc.c  */
-#line 413 "parse-gram.y"
+#line 414 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
 /* Line 1810 of yacc.c  */
-#line 414 "parse-gram.y"
+#line 415 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2600,7 +2601,7 @@ yyreduce:
   case 51:
 
 /* Line 1810 of yacc.c  */
-#line 419 "parse-gram.y"
+#line 420 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2613,7 +2614,7 @@ yyreduce:
   case 52:
 
 /* Line 1810 of yacc.c  */
-#line 430 "parse-gram.y"
+#line 431 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2630,126 +2631,126 @@ yyreduce:
   case 53:
 
 /* Line 1810 of yacc.c  */
-#line 444 "parse-gram.y"
+#line 445 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
 /* Line 1810 of yacc.c  */
-#line 445 "parse-gram.y"
+#line 446 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
 /* Line 1810 of yacc.c  */
-#line 446 "parse-gram.y"
+#line 447 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
 /* Line 1810 of yacc.c  */
-#line 450 "parse-gram.y"
+#line 451 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
 /* Line 1810 of yacc.c  */
-#line 451 "parse-gram.y"
+#line 452 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
 /* Line 1810 of yacc.c  */
-#line 457 "parse-gram.y"
+#line 458 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
 /* Line 1810 of yacc.c  */
-#line 459 "parse-gram.y"
+#line 460 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
 /* Line 1810 of yacc.c  */
-#line 463 "parse-gram.y"
+#line 464 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
 /* Line 1810 of yacc.c  */
-#line 464 "parse-gram.y"
+#line 465 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
 /* Line 1810 of yacc.c  */
-#line 470 "parse-gram.y"
+#line 471 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
 /* Line 1810 of yacc.c  */
-#line 472 "parse-gram.y"
+#line 473 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
 /* Line 1810 of yacc.c  */
-#line 476 "parse-gram.y"
+#line 477 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
 /* Line 1810 of yacc.c  */
-#line 477 "parse-gram.y"
+#line 478 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
 /* Line 1810 of yacc.c  */
-#line 481 "parse-gram.y"
+#line 482 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
 /* Line 1810 of yacc.c  */
-#line 482 "parse-gram.y"
+#line 483 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
 /* Line 1810 of yacc.c  */
-#line 483 "parse-gram.y"
+#line 484 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
 /* Line 1810 of yacc.c  */
-#line 484 "parse-gram.y"
+#line 485 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
 /* Line 1810 of yacc.c  */
-#line 490 "parse-gram.y"
+#line 491 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2759,7 +2760,7 @@ yyreduce:
   case 71:
 
 /* Line 1810 of yacc.c  */
-#line 495 "parse-gram.y"
+#line 496 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2769,7 +2770,7 @@ yyreduce:
   case 72:
 
 /* Line 1810 of yacc.c  */
-#line 500 "parse-gram.y"
+#line 501 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2780,7 +2781,7 @@ yyreduce:
   case 73:
 
 /* Line 1810 of yacc.c  */
-#line 506 "parse-gram.y"
+#line 507 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2791,7 +2792,7 @@ yyreduce:
   case 74:
 
 /* Line 1810 of yacc.c  */
-#line 512 "parse-gram.y"
+#line 513 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2803,7 +2804,7 @@ yyreduce:
   case 81:
 
 /* Line 1810 of yacc.c  */
-#line 542 "parse-gram.y"
+#line 543 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2812,14 +2813,14 @@ yyreduce:
   case 82:
 
 /* Line 1810 of yacc.c  */
-#line 548 "parse-gram.y"
+#line 549 "parse-gram.y"
     { current_lhs ((yyvsp[(1) - (2)].symbol), (yylsp[(1) - (2)]), (yyvsp[(2) - (2)].named_ref)); }
     break;
 
   case 83:
 
 /* Line 1810 of yacc.c  */
-#line 549 "parse-gram.y"
+#line 550 "parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[(1) - (4)]), 0);
@@ -2829,21 +2830,21 @@ yyreduce:
   case 84:
 
 /* Line 1810 of yacc.c  */
-#line 556 "parse-gram.y"
+#line 557 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
 /* Line 1810 of yacc.c  */
-#line 557 "parse-gram.y"
+#line 558 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
 /* Line 1810 of yacc.c  */
-#line 563 "parse-gram.y"
+#line 564 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
 				  current_lhs_named_ref); }
     break;
@@ -2851,77 +2852,77 @@ yyreduce:
   case 88:
 
 /* Line 1810 of yacc.c  */
-#line 566 "parse-gram.y"
+#line 567 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
 /* Line 1810 of yacc.c  */
-#line 568 "parse-gram.y"
+#line 569 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
 /* Line 1810 of yacc.c  */
-#line 570 "parse-gram.y"
+#line 571 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
 /* Line 1810 of yacc.c  */
-#line 572 "parse-gram.y"
+#line 573 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
 /* Line 1810 of yacc.c  */
-#line 574 "parse-gram.y"
+#line 575 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
 /* Line 1810 of yacc.c  */
-#line 578 "parse-gram.y"
+#line 579 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
 /* Line 1810 of yacc.c  */
-#line 580 "parse-gram.y"
+#line 581 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
 /* Line 1810 of yacc.c  */
-#line 592 "parse-gram.y"
+#line 593 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
 /* Line 1810 of yacc.c  */
-#line 597 "parse-gram.y"
+#line 598 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
 /* Line 1810 of yacc.c  */
-#line 598 "parse-gram.y"
+#line 599 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
 /* Line 1810 of yacc.c  */
-#line 609 "parse-gram.y"
+#line 610 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2935,14 +2936,14 @@ yyreduce:
   case 101:
 
 /* Line 1810 of yacc.c  */
-#line 629 "parse-gram.y"
+#line 630 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
 /* Line 1810 of yacc.c  */
-#line 631 "parse-gram.y"
+#line 632 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2953,14 +2954,14 @@ yyreduce:
   case 103:
 
 /* Line 1810 of yacc.c  */
-#line 639 "parse-gram.y"
+#line 640 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
 /* Line 1810 of yacc.c  */
-#line 651 "parse-gram.y"
+#line 652 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2970,7 +2971,7 @@ yyreduce:
   case 108:
 
 /* Line 1810 of yacc.c  */
-#line 660 "parse-gram.y"
+#line 661 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2984,7 +2985,7 @@ yyreduce:
 
 
 /* Line 1810 of yacc.c  */
-#line 2988 "parse-gram.c"
+#line 2989 "parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3234,7 +3235,7 @@ yyreturn:
 
 
 /* Line 2071 of yacc.c  */
-#line 670 "parse-gram.y"
+#line 671 "parse-gram.y"
 
 
 
@@ -3301,9 +3302,7 @@ add_param (char const *type, char *decl, location loc)
     complain_at (loc, _("missing identifier in parameter declaration"));
   else
     {
-      size_t name_len = strspn (name_start, alphanum);
-      char *name = xmemdup (name_start, name_len + 1);
-      name[name_len] = '\0';
+      char *name = xmemdup0 (name_start, strspn (name_start, alphanum));
       muscle_pair_list_grow (type, decl, name);
       free (name);
     }
