@@ -1,5 +1,5 @@
 
-/* A Bison parser, made by GNU Bison 2.3b.  */
+/* A Bison parser, made by GNU Bison 2.3b.21-d67c5-dirty.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
@@ -46,7 +46,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.3b"
+#define YYBISON_VERSION "2.3b.21-d67c5-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -100,8 +100,6 @@
 #include <config.h>
 #include "system.h"
 
-#include <strverscmp.h>
-
 #include "complain.h"
 #include "conflicts.h"
 #include "files.h"
@@ -153,7 +151,7 @@ static int current_prec = 0;
 
 
 /* Line 189 of yacc.c  */
-#line 157 "parse-gram.c"
+#line 155 "parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -301,8 +299,8 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 
-/* Line 214 of yacc.c  */
-#line 94 "parse-gram.y"
+/* Line 222 of yacc.c  */
+#line 92 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -315,8 +313,8 @@ typedef union YYSTYPE
 
 
 
-/* Line 214 of yacc.c  */
-#line 320 "parse-gram.c"
+/* Line 222 of yacc.c  */
+#line 318 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -341,7 +339,7 @@ typedef struct YYLTYPE
 
 
 /* Line 264 of yacc.c  */
-#line 345 "parse-gram.c"
+#line 343 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -666,17 +664,17 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   204,   204,   212,   214,   218,   219,   229,   230,   234,
-     235,   240,   241,   242,   243,   244,   245,   250,   259,   260,
-     261,   262,   263,   264,   265,   266,   267,   268,   269,   282,
-     283,   307,   308,   309,   310,   314,   315,   316,   320,   327,
-     334,   338,   342,   349,   364,   365,   369,   381,   381,   386,
-     386,   391,   402,   417,   418,   419,   423,   424,   429,   431,
-     436,   437,   442,   444,   449,   450,   454,   455,   456,   457,
-     462,   467,   472,   478,   484,   495,   496,   505,   506,   512,
-     513,   514,   521,   521,   525,   526,   527,   532,   533,   535,
-     537,   539,   541,   551,   552,   558,   561,   570,   590,   592,
-     601,   606,   607,   612,   619,   621
+       0,   202,   202,   210,   212,   216,   217,   227,   228,   232,
+     233,   238,   239,   240,   241,   242,   243,   248,   257,   258,
+     259,   260,   261,   262,   263,   264,   265,   266,   267,   280,
+     281,   305,   306,   307,   308,   312,   313,   314,   318,   325,
+     332,   336,   340,   347,   362,   363,   367,   379,   379,   384,
+     384,   389,   400,   415,   416,   417,   421,   422,   427,   429,
+     434,   435,   440,   442,   447,   448,   452,   453,   454,   455,
+     460,   465,   470,   476,   482,   493,   494,   503,   504,   510,
+     511,   512,   519,   519,   523,   524,   525,   530,   531,   533,
+     535,   537,   539,   549,   550,   556,   559,   568,   588,   590,
+     599,   604,   605,   610,   617,   619
 };
 #endif
 
@@ -1032,146 +1030,146 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 
 /* Line 715 of yacc.c  */
-#line 182 "parse-gram.y"
+#line 180 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 715 of yacc.c  */
-#line 1040 "parse-gram.c"
+#line 1038 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
 /* Line 715 of yacc.c  */
-#line 193 "parse-gram.y"
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 715 of yacc.c  */
-#line 1049 "parse-gram.c"
+#line 1047 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
 /* Line 715 of yacc.c  */
-#line 184 "parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
 /* Line 715 of yacc.c  */
-#line 1058 "parse-gram.c"
+#line 1056 "parse-gram.c"
 	break;
       case 44: /* "\"char\"" */
 
 /* Line 715 of yacc.c  */
-#line 176 "parse-gram.y"
+#line 174 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 715 of yacc.c  */
-#line 1067 "parse-gram.c"
+#line 1065 "parse-gram.c"
 	break;
       case 45: /* "\"epilogue\"" */
 
 /* Line 715 of yacc.c  */
-#line 184 "parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 715 of yacc.c  */
-#line 1076 "parse-gram.c"
+#line 1074 "parse-gram.c"
 	break;
       case 47: /* "\"identifier\"" */
 
 /* Line 715 of yacc.c  */
-#line 189 "parse-gram.y"
+#line 187 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 715 of yacc.c  */
-#line 1085 "parse-gram.c"
+#line 1083 "parse-gram.c"
 	break;
       case 48: /* "\"identifier:\"" */
 
 /* Line 715 of yacc.c  */
-#line 190 "parse-gram.y"
+#line 188 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 715 of yacc.c  */
-#line 1094 "parse-gram.c"
+#line 1092 "parse-gram.c"
 	break;
       case 51: /* "\"%{...%}\"" */
 
 /* Line 715 of yacc.c  */
-#line 184 "parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 715 of yacc.c  */
-#line 1103 "parse-gram.c"
+#line 1101 "parse-gram.c"
 	break;
       case 53: /* "\"type\"" */
 
 /* Line 715 of yacc.c  */
-#line 188 "parse-gram.y"
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 715 of yacc.c  */
-#line 1112 "parse-gram.c"
+#line 1110 "parse-gram.c"
 	break;
       case 82: /* "variable" */
 
 /* Line 715 of yacc.c  */
-#line 189 "parse-gram.y"
+#line 187 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 715 of yacc.c  */
-#line 1121 "parse-gram.c"
+#line 1119 "parse-gram.c"
 	break;
       case 83: /* "content.opt" */
 
 /* Line 715 of yacc.c  */
-#line 184 "parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 715 of yacc.c  */
-#line 1130 "parse-gram.c"
+#line 1128 "parse-gram.c"
 	break;
       case 84: /* "braceless" */
 
 /* Line 715 of yacc.c  */
-#line 184 "parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 715 of yacc.c  */
-#line 1139 "parse-gram.c"
+#line 1137 "parse-gram.c"
 	break;
       case 85: /* "id" */
 
 /* Line 715 of yacc.c  */
-#line 196 "parse-gram.y"
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 715 of yacc.c  */
-#line 1148 "parse-gram.c"
+#line 1146 "parse-gram.c"
 	break;
       case 86: /* "id_colon" */
 
 /* Line 715 of yacc.c  */
-#line 197 "parse-gram.y"
+#line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 715 of yacc.c  */
-#line 1157 "parse-gram.c"
+#line 1155 "parse-gram.c"
 	break;
       case 87: /* "symbol" */
 
 /* Line 715 of yacc.c  */
-#line 196 "parse-gram.y"
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 715 of yacc.c  */
-#line 1166 "parse-gram.c"
+#line 1164 "parse-gram.c"
 	break;
       case 88: /* "string_as_id" */
 
 /* Line 715 of yacc.c  */
-#line 196 "parse-gram.y"
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 715 of yacc.c  */
-#line 1175 "parse-gram.c"
+#line 1173 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1690,8 +1688,8 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1242 of yacc.c  */
-#line 86 "parse-gram.y"
+/* Line 1248 of yacc.c  */
+#line 84 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1699,8 +1697,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1242 of yacc.c  */
-#line 1704 "parse-gram.c"
+/* Line 1248 of yacc.c  */
+#line 1702 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1888,7 +1886,7 @@ yyreduce:
         case 6:
 
 /* Line 1455 of yacc.c  */
-#line 220 "parse-gram.y"
+#line 218 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
@@ -1903,14 +1901,14 @@ yyreduce:
   case 7:
 
 /* Line 1455 of yacc.c  */
-#line 229 "parse-gram.y"
+#line 227 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
 /* Line 1455 of yacc.c  */
-#line 231 "parse-gram.y"
+#line 229 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars));
     }
@@ -1919,14 +1917,14 @@ yyreduce:
   case 9:
 
 /* Line 1455 of yacc.c  */
-#line 234 "parse-gram.y"
+#line 232 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
 /* Line 1455 of yacc.c  */
-#line 236 "parse-gram.y"
+#line 234 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1936,42 +1934,42 @@ yyreduce:
   case 11:
 
 /* Line 1455 of yacc.c  */
-#line 240 "parse-gram.y"
+#line 238 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
 /* Line 1455 of yacc.c  */
-#line 241 "parse-gram.y"
+#line 239 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1455 of yacc.c  */
-#line 242 "parse-gram.y"
+#line 240 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
 /* Line 1455 of yacc.c  */
-#line 243 "parse-gram.y"
+#line 241 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
 /* Line 1455 of yacc.c  */
-#line 244 "parse-gram.y"
+#line 242 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
 /* Line 1455 of yacc.c  */
-#line 246 "parse-gram.y"
+#line 244 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1981,7 +1979,7 @@ yyreduce:
   case 17:
 
 /* Line 1455 of yacc.c  */
-#line 251 "parse-gram.y"
+#line 249 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -1995,77 +1993,77 @@ yyreduce:
   case 18:
 
 /* Line 1455 of yacc.c  */
-#line 259 "parse-gram.y"
+#line 257 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
 /* Line 1455 of yacc.c  */
-#line 260 "parse-gram.y"
+#line 258 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
 /* Line 1455 of yacc.c  */
-#line 261 "parse-gram.y"
+#line 259 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
 /* Line 1455 of yacc.c  */
-#line 262 "parse-gram.y"
+#line 260 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
 /* Line 1455 of yacc.c  */
-#line 263 "parse-gram.y"
+#line 261 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
 /* Line 1455 of yacc.c  */
-#line 264 "parse-gram.y"
+#line 262 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
 /* Line 1455 of yacc.c  */
-#line 265 "parse-gram.y"
+#line 263 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
 /* Line 1455 of yacc.c  */
-#line 266 "parse-gram.y"
+#line 264 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
 /* Line 1455 of yacc.c  */
-#line 267 "parse-gram.y"
+#line 265 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
 /* Line 1455 of yacc.c  */
-#line 268 "parse-gram.y"
+#line 266 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
 /* Line 1455 of yacc.c  */
-#line 270 "parse-gram.y"
+#line 268 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
          `%define api.pure' in a backward-compatible manner here.  First, don't
@@ -2083,14 +2081,14 @@ yyreduce:
   case 29:
 
 /* Line 1455 of yacc.c  */
-#line 282 "parse-gram.y"
+#line 280 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
 /* Line 1455 of yacc.c  */
-#line 284 "parse-gram.y"
+#line 282 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (strchr (skeleton_user, '/'))
@@ -2119,28 +2117,28 @@ yyreduce:
   case 31:
 
 /* Line 1455 of yacc.c  */
-#line 307 "parse-gram.y"
+#line 305 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
 /* Line 1455 of yacc.c  */
-#line 308 "parse-gram.y"
+#line 306 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
 /* Line 1455 of yacc.c  */
-#line 309 "parse-gram.y"
+#line 307 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
 /* Line 1455 of yacc.c  */
-#line 317 "parse-gram.y"
+#line 315 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2149,7 +2147,7 @@ yyreduce:
   case 38:
 
 /* Line 1455 of yacc.c  */
-#line 321 "parse-gram.y"
+#line 319 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2161,7 +2159,7 @@ yyreduce:
   case 39:
 
 /* Line 1455 of yacc.c  */
-#line 328 "parse-gram.y"
+#line 326 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2173,7 +2171,7 @@ yyreduce:
   case 40:
 
 /* Line 1455 of yacc.c  */
-#line 335 "parse-gram.y"
+#line 333 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2182,7 +2180,7 @@ yyreduce:
   case 41:
 
 /* Line 1455 of yacc.c  */
-#line 339 "parse-gram.y"
+#line 337 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2191,7 +2189,7 @@ yyreduce:
   case 42:
 
 /* Line 1455 of yacc.c  */
-#line 343 "parse-gram.y"
+#line 341 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2203,7 +2201,7 @@ yyreduce:
   case 43:
 
 /* Line 1455 of yacc.c  */
-#line 350 "parse-gram.y"
+#line 348 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
@@ -2213,21 +2211,21 @@ yyreduce:
   case 44:
 
 /* Line 1455 of yacc.c  */
-#line 364 "parse-gram.y"
+#line 362 "parse-gram.y"
     {}
     break;
 
   case 45:
 
 /* Line 1455 of yacc.c  */
-#line 365 "parse-gram.y"
+#line 363 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
 /* Line 1455 of yacc.c  */
-#line 370 "parse-gram.y"
+#line 368 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2238,14 +2236,14 @@ yyreduce:
   case 47:
 
 /* Line 1455 of yacc.c  */
-#line 381 "parse-gram.y"
+#line 379 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
 /* Line 1455 of yacc.c  */
-#line 382 "parse-gram.y"
+#line 380 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2255,14 +2253,14 @@ yyreduce:
   case 49:
 
 /* Line 1455 of yacc.c  */
-#line 386 "parse-gram.y"
+#line 384 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
 /* Line 1455 of yacc.c  */
-#line 387 "parse-gram.y"
+#line 385 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2272,7 +2270,7 @@ yyreduce:
   case 51:
 
 /* Line 1455 of yacc.c  */
-#line 392 "parse-gram.y"
+#line 390 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2285,7 +2283,7 @@ yyreduce:
   case 52:
 
 /* Line 1455 of yacc.c  */
-#line 403 "parse-gram.y"
+#line 401 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2302,126 +2300,126 @@ yyreduce:
   case 53:
 
 /* Line 1455 of yacc.c  */
-#line 417 "parse-gram.y"
+#line 415 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
 /* Line 1455 of yacc.c  */
-#line 418 "parse-gram.y"
+#line 416 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
 /* Line 1455 of yacc.c  */
-#line 419 "parse-gram.y"
+#line 417 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
 /* Line 1455 of yacc.c  */
-#line 423 "parse-gram.y"
+#line 421 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
 /* Line 1455 of yacc.c  */
-#line 424 "parse-gram.y"
+#line 422 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
 /* Line 1455 of yacc.c  */
-#line 430 "parse-gram.y"
+#line 428 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
 /* Line 1455 of yacc.c  */
-#line 432 "parse-gram.y"
+#line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
 /* Line 1455 of yacc.c  */
-#line 436 "parse-gram.y"
+#line 434 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
 /* Line 1455 of yacc.c  */
-#line 437 "parse-gram.y"
+#line 435 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
 /* Line 1455 of yacc.c  */
-#line 443 "parse-gram.y"
+#line 441 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
 /* Line 1455 of yacc.c  */
-#line 445 "parse-gram.y"
+#line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
 /* Line 1455 of yacc.c  */
-#line 449 "parse-gram.y"
+#line 447 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
 /* Line 1455 of yacc.c  */
-#line 450 "parse-gram.y"
+#line 448 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
 /* Line 1455 of yacc.c  */
-#line 454 "parse-gram.y"
+#line 452 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
 /* Line 1455 of yacc.c  */
-#line 455 "parse-gram.y"
+#line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
 /* Line 1455 of yacc.c  */
-#line 456 "parse-gram.y"
+#line 454 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
 /* Line 1455 of yacc.c  */
-#line 457 "parse-gram.y"
+#line 455 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
 /* Line 1455 of yacc.c  */
-#line 463 "parse-gram.y"
+#line 461 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2431,7 +2429,7 @@ yyreduce:
   case 71:
 
 /* Line 1455 of yacc.c  */
-#line 468 "parse-gram.y"
+#line 466 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2441,7 +2439,7 @@ yyreduce:
   case 72:
 
 /* Line 1455 of yacc.c  */
-#line 473 "parse-gram.y"
+#line 471 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2452,7 +2450,7 @@ yyreduce:
   case 73:
 
 /* Line 1455 of yacc.c  */
-#line 479 "parse-gram.y"
+#line 477 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2463,7 +2461,7 @@ yyreduce:
   case 74:
 
 /* Line 1455 of yacc.c  */
-#line 485 "parse-gram.y"
+#line 483 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2475,7 +2473,7 @@ yyreduce:
   case 81:
 
 /* Line 1455 of yacc.c  */
-#line 515 "parse-gram.y"
+#line 513 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2484,77 +2482,77 @@ yyreduce:
   case 82:
 
 /* Line 1455 of yacc.c  */
-#line 521 "parse-gram.y"
+#line 519 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 84:
 
 /* Line 1455 of yacc.c  */
-#line 525 "parse-gram.y"
+#line 523 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
 /* Line 1455 of yacc.c  */
-#line 526 "parse-gram.y"
+#line 524 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
 /* Line 1455 of yacc.c  */
-#line 532 "parse-gram.y"
+#line 530 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 88:
 
 /* Line 1455 of yacc.c  */
-#line 534 "parse-gram.y"
+#line 532 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 89:
 
 /* Line 1455 of yacc.c  */
-#line 536 "parse-gram.y"
+#line 534 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 90:
 
 /* Line 1455 of yacc.c  */
-#line 538 "parse-gram.y"
+#line 536 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
 /* Line 1455 of yacc.c  */
-#line 540 "parse-gram.y"
+#line 538 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
 /* Line 1455 of yacc.c  */
-#line 542 "parse-gram.y"
+#line 540 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 94:
 
 /* Line 1455 of yacc.c  */
-#line 552 "parse-gram.y"
+#line 550 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 95:
 
 /* Line 1455 of yacc.c  */
-#line 558 "parse-gram.y"
+#line 556 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
@@ -2563,7 +2561,7 @@ yyreduce:
   case 97:
 
 /* Line 1455 of yacc.c  */
-#line 571 "parse-gram.y"
+#line 569 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2577,14 +2575,14 @@ yyreduce:
   case 98:
 
 /* Line 1455 of yacc.c  */
-#line 591 "parse-gram.y"
+#line 589 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 99:
 
 /* Line 1455 of yacc.c  */
-#line 593 "parse-gram.y"
+#line 591 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2595,14 +2593,14 @@ yyreduce:
   case 100:
 
 /* Line 1455 of yacc.c  */
-#line 601 "parse-gram.y"
+#line 599 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 103:
 
 /* Line 1455 of yacc.c  */
-#line 613 "parse-gram.y"
+#line 611 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2612,7 +2610,7 @@ yyreduce:
   case 105:
 
 /* Line 1455 of yacc.c  */
-#line 622 "parse-gram.y"
+#line 620 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2626,7 +2624,7 @@ yyreduce:
 
 
 /* Line 1455 of yacc.c  */
-#line 2630 "parse-gram.c"
+#line 2628 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2845,7 +2843,7 @@ yyreturn:
 
 
 /* Line 1675 of yacc.c  */
-#line 632 "parse-gram.y"
+#line 630 "parse-gram.y"
 
 
 
