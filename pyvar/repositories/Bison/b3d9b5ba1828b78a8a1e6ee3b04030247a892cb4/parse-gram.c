@@ -70,7 +70,7 @@
 
 /* Copy the first part of user declarations.  */
 /* Line 164 of yacc.c.  */
-#line 1 "../../src/parse-gram.y"
+#line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
@@ -96,6 +96,8 @@
 #include <config.h>
 #include "system.h"
 
+#include <strverscmp.h>
+
 #include "complain.h"
 #include "conflicts.h"
 #include "files.h"
@@ -107,7 +109,6 @@
 #include "symlist.h"
 #include "scan-gram.h"
 #include "scan-code.h"
-#include "strverscmp.h"
 
 #define YYLLOC_DEFAULT(Current, Rhs, N)  (Current) = lloc_default (Rhs, N)
 static YYLTYPE lloc_default (YYLTYPE const *, int);
@@ -134,18 +135,10 @@ static symbol *current_lhs;
 static location current_lhs_location;
 static int current_prec = 0;
 
-#ifdef UINT_FAST8_MAX
-# define YYTYPE_UINT8 uint_fast8_t
-#endif
-#ifdef INT_FAST8_MAX
-# define YYTYPE_INT8 int_fast8_t
-#endif
-#ifdef UINT_FAST16_MAX
-# define YYTYPE_UINT16 uint_fast16_t
-#endif
-#ifdef INT_FAST16_MAX
-# define YYTYPE_INT16 int_fast16_t
-#endif
+#define YYTYPE_INT16 int_fast16_t
+#define YYTYPE_INT8 int_fast8_t
+#define YYTYPE_UINT16 uint_fast16_t
+#define YYTYPE_UINT8 uint_fast8_t
 
 
 /* Enabling traces.  */
@@ -293,7 +286,7 @@ static int current_prec = 0;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 /* Line 195 of yacc.c.  */
-#line 97 "../../src/parse-gram.y"
+#line 90 "parse-gram.y"
 {
   symbol *symbol;
   symbol_list *list;
@@ -304,7 +297,7 @@ typedef union YYSTYPE
   unsigned char character;
 }
 /* Line 195 of yacc.c.  */
-#line 308 "../../src/parse-gram.c"
+#line 301 "parse-gram.c"
 	YYSTYPE;
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -328,7 +321,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 219 of yacc.c.  */
-#line 332 "../../src/parse-gram.c"
+#line 325 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -648,15 +641,15 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   202,   202,   210,   212,   216,   217,   221,   227,   233,
-     234,   239,   240,   241,   247,   248,   249,   250,   251,   256,
-     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
-     270,   276,   277,   278,   279,   283,   284,   285,   289,   297,
-     305,   309,   323,   324,   328,   350,   350,   355,   355,   360,
-     370,   385,   386,   387,   391,   392,   397,   398,   403,   407,
-     412,   418,   424,   435,   436,   445,   446,   452,   453,   454,
-     461,   461,   465,   466,   467,   472,   473,   475,   477,   479,
-     481,   494,   496,   505,   510,   511,   516,   525,   530,   532
+       0,   195,   195,   203,   205,   209,   210,   214,   220,   226,
+     227,   232,   233,   234,   240,   241,   242,   243,   244,   249,
+     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
+     263,   269,   270,   271,   272,   276,   277,   278,   282,   290,
+     298,   302,   316,   317,   321,   343,   343,   348,   348,   353,
+     363,   378,   379,   380,   384,   385,   390,   391,   396,   400,
+     405,   411,   417,   428,   429,   438,   439,   445,   446,   447,
+     454,   454,   458,   459,   460,   465,   466,   468,   470,   472,
+     474,   487,   489,   498,   503,   504,   509,   518,   523,   525
 };
 #endif
 
@@ -1005,101 +998,101 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 /* Line 668 of yacc.c.  */
-#line 181 "../../src/parse-gram.y"
+#line 174 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 /* Line 668 of yacc.c.  */
-#line 1012 "../../src/parse-gram.c"
+#line 1005 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 /* Line 668 of yacc.c.  */
-#line 191 "../../src/parse-gram.y"
+#line 184 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 /* Line 668 of yacc.c.  */
-#line 1019 "../../src/parse-gram.c"
+#line 1012 "parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
 /* Line 668 of yacc.c.  */
-#line 183 "../../src/parse-gram.y"
+#line 176 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 668 of yacc.c.  */
-#line 1026 "../../src/parse-gram.c"
+#line 1019 "parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
 /* Line 668 of yacc.c.  */
-#line 178 "../../src/parse-gram.y"
+#line 171 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 /* Line 668 of yacc.c.  */
-#line 1033 "../../src/parse-gram.c"
+#line 1026 "parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
 /* Line 668 of yacc.c.  */
-#line 183 "../../src/parse-gram.y"
+#line 176 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 668 of yacc.c.  */
-#line 1040 "../../src/parse-gram.c"
+#line 1033 "parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
 /* Line 668 of yacc.c.  */
-#line 187 "../../src/parse-gram.y"
+#line 180 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 /* Line 668 of yacc.c.  */
-#line 1047 "../../src/parse-gram.c"
+#line 1040 "parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
 /* Line 668 of yacc.c.  */
-#line 188 "../../src/parse-gram.y"
+#line 181 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 /* Line 668 of yacc.c.  */
-#line 1054 "../../src/parse-gram.c"
+#line 1047 "parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
 /* Line 668 of yacc.c.  */
-#line 183 "../../src/parse-gram.y"
+#line 176 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 668 of yacc.c.  */
-#line 1061 "../../src/parse-gram.c"
+#line 1054 "parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
 /* Line 668 of yacc.c.  */
-#line 186 "../../src/parse-gram.y"
+#line 179 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 /* Line 668 of yacc.c.  */
-#line 1068 "../../src/parse-gram.c"
+#line 1061 "parse-gram.c"
 	break;
       case 78: /* "id" */
 /* Line 668 of yacc.c.  */
-#line 194 "../../src/parse-gram.y"
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 668 of yacc.c.  */
-#line 1075 "../../src/parse-gram.c"
+#line 1068 "parse-gram.c"
 	break;
       case 79: /* "id_colon" */
 /* Line 668 of yacc.c.  */
-#line 195 "../../src/parse-gram.y"
+#line 188 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 /* Line 668 of yacc.c.  */
-#line 1082 "../../src/parse-gram.c"
+#line 1075 "parse-gram.c"
 	break;
       case 80: /* "symbol" */
 /* Line 668 of yacc.c.  */
-#line 194 "../../src/parse-gram.y"
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 668 of yacc.c.  */
-#line 1089 "../../src/parse-gram.c"
+#line 1082 "parse-gram.c"
 	break;
       case 81: /* "string_as_id" */
 /* Line 668 of yacc.c.  */
-#line 194 "../../src/parse-gram.y"
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 668 of yacc.c.  */
-#line 1096 "../../src/parse-gram.c"
+#line 1089 "parse-gram.c"
 	break;
       case 82: /* "string_content" */
 /* Line 668 of yacc.c.  */
-#line 181 "../../src/parse-gram.y"
+#line 174 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 /* Line 668 of yacc.c.  */
-#line 1103 "../../src/parse-gram.c"
+#line 1096 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1604,13 +1597,13 @@ YYLTYPE yylloc;
 #if YYLTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
   yylloc.first_line   = yylloc.last_line   = 1;
-  yylloc.first_column = yylloc.last_column = 0;
+  yylloc.first_column = yylloc.last_column = 1;
 #endif
 
 
   /* User initialization code.  */
   /* Line 1077 of yacc.c.  */
-#line 88 "../../src/parse-gram.y"
+#line 81 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1618,7 +1611,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1077 of yacc.c.  */
-#line 1622 "../../src/parse-gram.c"
+#line 1615 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1804,7 +1797,7 @@ yyreduce:
     {
         case 6:
 /* Line 1265 of yacc.c.  */
-#line 218 "../../src/parse-gram.y"
+#line 211 "parse-gram.y"
     {
       prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), typed);
     }
@@ -1812,7 +1805,7 @@ yyreduce:
 
   case 7:
 /* Line 1265 of yacc.c.  */
-#line 222 "../../src/parse-gram.y"
+#line 215 "parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
       (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
@@ -1822,7 +1815,7 @@ yyreduce:
 
   case 8:
 /* Line 1265 of yacc.c.  */
-#line 228 "../../src/parse-gram.y"
+#line 221 "parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
       (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
@@ -1832,13 +1825,13 @@ yyreduce:
 
   case 9:
 /* Line 1265 of yacc.c.  */
-#line 233 "../../src/parse-gram.y"
+#line 226 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 10:
 /* Line 1265 of yacc.c.  */
-#line 235 "../../src/parse-gram.y"
+#line 228 "parse-gram.y"
     {
       static char one[] = "1";
       muscle_insert ((yyvsp[(2) - (2)].chars), one);
@@ -1847,19 +1840,19 @@ yyreduce:
 
   case 11:
 /* Line 1265 of yacc.c.  */
-#line 239 "../../src/parse-gram.y"
+#line 232 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 12:
 /* Line 1265 of yacc.c.  */
-#line 240 "../../src/parse-gram.y"
+#line 233 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 13:
 /* Line 1265 of yacc.c.  */
-#line 242 "../../src/parse-gram.y"
+#line 235 "parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
       (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
@@ -1869,31 +1862,31 @@ yyreduce:
 
   case 14:
 /* Line 1265 of yacc.c.  */
-#line 247 "../../src/parse-gram.y"
+#line 240 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 15:
 /* Line 1265 of yacc.c.  */
-#line 248 "../../src/parse-gram.y"
+#line 241 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 16:
 /* Line 1265 of yacc.c.  */
-#line 249 "../../src/parse-gram.y"
+#line 242 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 17:
 /* Line 1265 of yacc.c.  */
-#line 250 "../../src/parse-gram.y"
+#line 243 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 18:
 /* Line 1265 of yacc.c.  */
-#line 252 "../../src/parse-gram.y"
+#line 245 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1902,7 +1895,7 @@ yyreduce:
 
   case 19:
 /* Line 1265 of yacc.c.  */
-#line 257 "../../src/parse-gram.y"
+#line 250 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
@@ -1910,67 +1903,67 @@ yyreduce:
 
   case 20:
 /* Line 1265 of yacc.c.  */
-#line 260 "../../src/parse-gram.y"
+#line 253 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 21:
 /* Line 1265 of yacc.c.  */
-#line 261 "../../src/parse-gram.y"
+#line 254 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 22:
 /* Line 1265 of yacc.c.  */
-#line 262 "../../src/parse-gram.y"
+#line 255 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 /* Line 1265 of yacc.c.  */
-#line 263 "../../src/parse-gram.y"
+#line 256 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 /* Line 1265 of yacc.c.  */
-#line 264 "../../src/parse-gram.y"
+#line 257 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 /* Line 1265 of yacc.c.  */
-#line 265 "../../src/parse-gram.y"
+#line 258 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 26:
 /* Line 1265 of yacc.c.  */
-#line 266 "../../src/parse-gram.y"
+#line 259 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 27:
 /* Line 1265 of yacc.c.  */
-#line 267 "../../src/parse-gram.y"
+#line 260 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 28:
 /* Line 1265 of yacc.c.  */
-#line 268 "../../src/parse-gram.y"
+#line 261 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 29:
 /* Line 1265 of yacc.c.  */
-#line 269 "../../src/parse-gram.y"
+#line 262 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 30:
 /* Line 1265 of yacc.c.  */
-#line 271 "../../src/parse-gram.y"
+#line 264 "parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
       (yyvsp[(2) - (2)].chars)[strlen ((yyvsp[(2) - (2)].chars)) - 1] = '\n';
@@ -1980,25 +1973,25 @@ yyreduce:
 
   case 31:
 /* Line 1265 of yacc.c.  */
-#line 276 "../../src/parse-gram.y"
+#line 269 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 /* Line 1265 of yacc.c.  */
-#line 277 "../../src/parse-gram.y"
+#line 270 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 33:
 /* Line 1265 of yacc.c.  */
-#line 278 "../../src/parse-gram.y"
+#line 271 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 /* Line 1265 of yacc.c.  */
-#line 286 "../../src/parse-gram.y"
+#line 279 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2006,7 +1999,7 @@ yyreduce:
 
   case 38:
 /* Line 1265 of yacc.c.  */
-#line 290 "../../src/parse-gram.y"
+#line 283 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -2018,7 +2011,7 @@ yyreduce:
 
   case 39:
 /* Line 1265 of yacc.c.  */
-#line 298 "../../src/parse-gram.y"
+#line 291 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -2030,7 +2023,7 @@ yyreduce:
 
   case 40:
 /* Line 1265 of yacc.c.  */
-#line 306 "../../src/parse-gram.y"
+#line 299 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2038,7 +2031,7 @@ yyreduce:
 
   case 41:
 /* Line 1265 of yacc.c.  */
-#line 310 "../../src/parse-gram.y"
+#line 303 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2046,19 +2039,19 @@ yyreduce:
 
   case 42:
 /* Line 1265 of yacc.c.  */
-#line 323 "../../src/parse-gram.y"
+#line 316 "parse-gram.y"
     {}
     break;
 
   case 43:
 /* Line 1265 of yacc.c.  */
-#line 324 "../../src/parse-gram.y"
+#line 317 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 44:
 /* Line 1265 of yacc.c.  */
-#line 329 "../../src/parse-gram.y"
+#line 322 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
 
@@ -2078,13 +2071,13 @@ yyreduce:
 
   case 45:
 /* Line 1265 of yacc.c.  */
-#line 350 "../../src/parse-gram.y"
+#line 343 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 46:
 /* Line 1265 of yacc.c.  */
-#line 351 "../../src/parse-gram.y"
+#line 344 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2093,13 +2086,13 @@ yyreduce:
 
   case 47:
 /* Line 1265 of yacc.c.  */
-#line 355 "../../src/parse-gram.y"
+#line 348 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 48:
 /* Line 1265 of yacc.c.  */
-#line 356 "../../src/parse-gram.y"
+#line 349 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2108,7 +2101,7 @@ yyreduce:
 
   case 49:
 /* Line 1265 of yacc.c.  */
-#line 361 "../../src/parse-gram.y"
+#line 354 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2119,7 +2112,7 @@ yyreduce:
 
   case 50:
 /* Line 1265 of yacc.c.  */
-#line 371 "../../src/parse-gram.y"
+#line 364 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2135,49 +2128,49 @@ yyreduce:
 
   case 51:
 /* Line 1265 of yacc.c.  */
-#line 385 "../../src/parse-gram.y"
+#line 378 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 52:
 /* Line 1265 of yacc.c.  */
-#line 386 "../../src/parse-gram.y"
+#line 379 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 53:
 /* Line 1265 of yacc.c.  */
-#line 387 "../../src/parse-gram.y"
+#line 380 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 54:
 /* Line 1265 of yacc.c.  */
-#line 391 "../../src/parse-gram.y"
+#line 384 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 55:
 /* Line 1265 of yacc.c.  */
-#line 392 "../../src/parse-gram.y"
+#line 385 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 56:
 /* Line 1265 of yacc.c.  */
-#line 397 "../../src/parse-gram.y"
+#line 390 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 57:
 /* Line 1265 of yacc.c.  */
-#line 398 "../../src/parse-gram.y"
+#line 391 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 58:
 /* Line 1265 of yacc.c.  */
-#line 404 "../../src/parse-gram.y"
+#line 397 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
      }
@@ -2185,7 +2178,7 @@ yyreduce:
 
   case 59:
 /* Line 1265 of yacc.c.  */
-#line 408 "../../src/parse-gram.y"
+#line 401 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2194,7 +2187,7 @@ yyreduce:
 
   case 60:
 /* Line 1265 of yacc.c.  */
-#line 413 "../../src/parse-gram.y"
+#line 406 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2204,7 +2197,7 @@ yyreduce:
 
   case 61:
 /* Line 1265 of yacc.c.  */
-#line 419 "../../src/parse-gram.y"
+#line 412 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2214,7 +2207,7 @@ yyreduce:
 
   case 62:
 /* Line 1265 of yacc.c.  */
-#line 425 "../../src/parse-gram.y"
+#line 418 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2225,7 +2218,7 @@ yyreduce:
 
   case 69:
 /* Line 1265 of yacc.c.  */
-#line 455 "../../src/parse-gram.y"
+#line 448 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2233,67 +2226,67 @@ yyreduce:
 
   case 70:
 /* Line 1265 of yacc.c.  */
-#line 461 "../../src/parse-gram.y"
+#line 454 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 72:
 /* Line 1265 of yacc.c.  */
-#line 465 "../../src/parse-gram.y"
+#line 458 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 73:
 /* Line 1265 of yacc.c.  */
-#line 466 "../../src/parse-gram.y"
+#line 459 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 75:
 /* Line 1265 of yacc.c.  */
-#line 472 "../../src/parse-gram.y"
+#line 465 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 76:
 /* Line 1265 of yacc.c.  */
-#line 474 "../../src/parse-gram.y"
+#line 467 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 77:
 /* Line 1265 of yacc.c.  */
-#line 476 "../../src/parse-gram.y"
+#line 469 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 78:
 /* Line 1265 of yacc.c.  */
-#line 478 "../../src/parse-gram.y"
+#line 471 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 79:
 /* Line 1265 of yacc.c.  */
-#line 480 "../../src/parse-gram.y"
+#line 473 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 80:
 /* Line 1265 of yacc.c.  */
-#line 482 "../../src/parse-gram.y"
+#line 475 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 81:
 /* Line 1265 of yacc.c.  */
-#line 495 "../../src/parse-gram.y"
+#line 488 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 82:
 /* Line 1265 of yacc.c.  */
-#line 497 "../../src/parse-gram.y"
+#line 490 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2303,13 +2296,13 @@ yyreduce:
 
   case 83:
 /* Line 1265 of yacc.c.  */
-#line 505 "../../src/parse-gram.y"
+#line 498 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 86:
 /* Line 1265 of yacc.c.  */
-#line 517 "../../src/parse-gram.y"
+#line 510 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2318,13 +2311,13 @@ yyreduce:
 
   case 87:
 /* Line 1265 of yacc.c.  */
-#line 526 "../../src/parse-gram.y"
+#line 519 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 89:
 /* Line 1265 of yacc.c.  */
-#line 533 "../../src/parse-gram.y"
+#line 526 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2333,7 +2326,7 @@ yyreduce:
 
 
 /* Line 1265 of yacc.c.  */
-#line 2337 "../../src/parse-gram.c"
+#line 2330 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2554,7 +2547,7 @@ yyreturn:
 
 
 /* Line 1485 of yacc.c.  */
-#line 539 "../../src/parse-gram.y"
+#line 532 "parse-gram.y"
 
 
 
