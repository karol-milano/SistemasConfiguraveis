@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.5.1_rc2.  */
+/* A Bison parser, made by GNU Bison 2.5.1.19-ced26-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
    
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.5.1_rc2"
+#define YYBISON_VERSION "2.5.1.19-ced26-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -73,7 +73,7 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 268 of yacc.c  */
+/* Line 323 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -169,7 +169,7 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 268 of yacc.c  */
+/* Line 323 of yacc.c  */
 #line 174 "parse-gram.c"
 
 # ifndef YY_NULL
@@ -180,11 +180,6 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 #  endif
 # endif
 
-/* Enabling traces.  */
-#ifndef YYDEBUG
-# define YYDEBUG 1
-#endif
-
 /* Enabling verbose error messages.  */
 #ifdef YYERROR_VERBOSE
 # undef YYERROR_VERBOSE
@@ -198,178 +193,13 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 # define YYTOKEN_TABLE 0
 #endif
 
-
-/* Tokens.  */
-#ifndef YYTOKENTYPE
-# define YYTOKENTYPE
-   /* Put the tokens into the symbol table, so that GDB and other debuggers
-      know about them.  */
-   enum yytokentype {
-     GRAM_EOF = 0,
-     STRING = 258,
-     INT = 259,
-     PERCENT_TOKEN = 260,
-     PERCENT_NTERM = 261,
-     PERCENT_TYPE = 262,
-     PERCENT_DESTRUCTOR = 263,
-     PERCENT_PRINTER = 264,
-     PERCENT_LEFT = 265,
-     PERCENT_RIGHT = 266,
-     PERCENT_NONASSOC = 267,
-     PERCENT_PREC = 268,
-     PERCENT_DPREC = 269,
-     PERCENT_MERGE = 270,
-     PERCENT_CODE = 271,
-     PERCENT_DEBUG = 272,
-     PERCENT_DEFAULT_PREC = 273,
-     PERCENT_DEFINE = 274,
-     PERCENT_DEFINES = 275,
-     PERCENT_ERROR_VERBOSE = 276,
-     PERCENT_EXPECT = 277,
-     PERCENT_EXPECT_RR = 278,
-     PERCENT_FILE_PREFIX = 279,
-     PERCENT_GLR_PARSER = 280,
-     PERCENT_INITIAL_ACTION = 281,
-     PERCENT_LANGUAGE = 282,
-     PERCENT_LEX_PARAM = 283,
-     PERCENT_LOCATIONS = 284,
-     PERCENT_NAME_PREFIX = 285,
-     PERCENT_NO_DEFAULT_PREC = 286,
-     PERCENT_NO_LINES = 287,
-     PERCENT_NONDETERMINISTIC_PARSER = 288,
-     PERCENT_OUTPUT = 289,
-     PERCENT_PARSE_PARAM = 290,
-     PERCENT_PURE_PARSER = 291,
-     PERCENT_REQUIRE = 292,
-     PERCENT_SKELETON = 293,
-     PERCENT_START = 294,
-     PERCENT_TOKEN_TABLE = 295,
-     PERCENT_VERBOSE = 296,
-     PERCENT_YACC = 297,
-     BRACED_CODE = 298,
-     BRACKETED_ID = 299,
-     CHAR = 300,
-     EPILOGUE = 301,
-     EQUAL = 302,
-     ID = 303,
-     ID_COLON = 304,
-     PERCENT_PERCENT = 305,
-     PIPE = 306,
-     PROLOGUE = 307,
-     SEMICOLON = 308,
-     TYPE = 309,
-     TYPE_TAG_ANY = 310,
-     TYPE_TAG_NONE = 311,
-     PERCENT_UNION = 312
-   };
-#endif
-/* Tokens.  */
-#define GRAM_EOF 0
-#define STRING 258
-#define INT 259
-#define PERCENT_TOKEN 260
-#define PERCENT_NTERM 261
-#define PERCENT_TYPE 262
-#define PERCENT_DESTRUCTOR 263
-#define PERCENT_PRINTER 264
-#define PERCENT_LEFT 265
-#define PERCENT_RIGHT 266
-#define PERCENT_NONASSOC 267
-#define PERCENT_PREC 268
-#define PERCENT_DPREC 269
-#define PERCENT_MERGE 270
-#define PERCENT_CODE 271
-#define PERCENT_DEBUG 272
-#define PERCENT_DEFAULT_PREC 273
-#define PERCENT_DEFINE 274
-#define PERCENT_DEFINES 275
-#define PERCENT_ERROR_VERBOSE 276
-#define PERCENT_EXPECT 277
-#define PERCENT_EXPECT_RR 278
-#define PERCENT_FILE_PREFIX 279
-#define PERCENT_GLR_PARSER 280
-#define PERCENT_INITIAL_ACTION 281
-#define PERCENT_LANGUAGE 282
-#define PERCENT_LEX_PARAM 283
-#define PERCENT_LOCATIONS 284
-#define PERCENT_NAME_PREFIX 285
-#define PERCENT_NO_DEFAULT_PREC 286
-#define PERCENT_NO_LINES 287
-#define PERCENT_NONDETERMINISTIC_PARSER 288
-#define PERCENT_OUTPUT 289
-#define PERCENT_PARSE_PARAM 290
-#define PERCENT_PURE_PARSER 291
-#define PERCENT_REQUIRE 292
-#define PERCENT_SKELETON 293
-#define PERCENT_START 294
-#define PERCENT_TOKEN_TABLE 295
-#define PERCENT_VERBOSE 296
-#define PERCENT_YACC 297
-#define BRACED_CODE 298
-#define BRACKETED_ID 299
-#define CHAR 300
-#define EPILOGUE 301
-#define EQUAL 302
-#define ID 303
-#define ID_COLON 304
-#define PERCENT_PERCENT 305
-#define PIPE 306
-#define PROLOGUE 307
-#define SEMICOLON 308
-#define TYPE 309
-#define TYPE_TAG_ANY 310
-#define TYPE_TAG_NONE 311
-#define PERCENT_UNION 312
-
-
-
-
-#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
-typedef union YYSTYPE
-{
-
-/* Line 295 of yacc.c  */
-#line 114 "parse-gram.y"
-
-  symbol *symbol;
-  symbol_list *list;
-  int integer;
-  char const *chars;
-  char *code;
-  assoc assoc;
-  uniqstr uniqstr;
-  unsigned char character;
-  named_ref *named_ref;
-
-
-
-/* Line 295 of yacc.c  */
-#line 348 "parse-gram.c"
-} YYSTYPE;
-# define YYSTYPE_IS_TRIVIAL 1
-# define yystype YYSTYPE /* obsolescent; will be withdrawn */
-# define YYSTYPE_IS_DECLARED 1
-#endif
-
-#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
-typedef struct YYLTYPE
-{
-  int first_line;
-  int first_column;
-  int last_line;
-  int last_column;
-} YYLTYPE;
-# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
-# define YYLTYPE_IS_DECLARED 1
-# define YYLTYPE_IS_TRIVIAL 1
-#endif
-
+#include "parse-gram.h"
 
 /* Copy the second part of user declarations.  */
 
 
-/* Line 345 of yacc.c  */
-#line 373 "parse-gram.c"
+/* Line 344 of yacc.c  */
+#line 203 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -1060,165 +890,165 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 204 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 823 of yacc.c  */
-#line 1069 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 899 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 216 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 823 of yacc.c  */
-#line 1078 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 908 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 206 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 823 of yacc.c  */
-#line 1087 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 917 "parse-gram.c"
 	break;
       case 44: /* "\"[identifier]\"" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 211 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", (yyvaluep->uniqstr)); };
 
-/* Line 823 of yacc.c  */
-#line 1096 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 926 "parse-gram.c"
 	break;
       case 45: /* "\"char\"" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 198 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 823 of yacc.c  */
-#line 1105 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 935 "parse-gram.c"
 	break;
       case 46: /* "\"epilogue\"" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 206 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 823 of yacc.c  */
-#line 1114 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 944 "parse-gram.c"
 	break;
       case 48: /* "\"identifier\"" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 210 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 823 of yacc.c  */
-#line 1123 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 953 "parse-gram.c"
 	break;
       case 49: /* "\"identifier:\"" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 212 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 823 of yacc.c  */
-#line 1132 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 962 "parse-gram.c"
 	break;
       case 52: /* "\"%{...%}\"" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 206 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 823 of yacc.c  */
-#line 1141 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 971 "parse-gram.c"
 	break;
       case 54: /* "\"type\"" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 213 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 823 of yacc.c  */
-#line 1150 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 980 "parse-gram.c"
 	break;
       case 71: /* "symbol.prec" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 219 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 823 of yacc.c  */
-#line 1159 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 989 "parse-gram.c"
 	break;
       case 84: /* "variable" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 210 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 823 of yacc.c  */
-#line 1168 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 998 "parse-gram.c"
 	break;
       case 85: /* "content.opt" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 206 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 823 of yacc.c  */
-#line 1177 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 1007 "parse-gram.c"
 	break;
       case 86: /* "braceless" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 206 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 823 of yacc.c  */
-#line 1186 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 1016 "parse-gram.c"
 	break;
       case 87: /* "id" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 219 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 823 of yacc.c  */
-#line 1195 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 1025 "parse-gram.c"
 	break;
       case 88: /* "id_colon" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 823 of yacc.c  */
-#line 1204 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 1034 "parse-gram.c"
 	break;
       case 89: /* "symbol" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 219 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 823 of yacc.c  */
-#line 1213 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 1043 "parse-gram.c"
 	break;
       case 90: /* "string_as_id" */
 
-/* Line 823 of yacc.c  */
+/* Line 822 of yacc.c  */
 #line 219 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 823 of yacc.c  */
-#line 1222 "parse-gram.c"
+/* Line 822 of yacc.c  */
+#line 1052 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1862,20 +1692,6 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
 }
 
 
-/* Prevent warnings from -Wmissing-prototypes.  */
-#ifdef YYPARSE_PARAM
-#if defined __STDC__ || defined __cplusplus
-int yyparse (void *YYPARSE_PARAM);
-#else
-int yyparse ();
-#endif
-#else /* ! YYPARSE_PARAM */
-#if defined __STDC__ || defined __cplusplus
-int yyparse (void);
-#else
-int yyparse ();
-#endif
-#endif /* ! YYPARSE_PARAM */
 
 
 /*----------.
@@ -2009,7 +1825,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1594 of yacc.c  */
+/* Line 1585 of yacc.c  */
 #line 106 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -2018,8 +1834,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1594 of yacc.c  */
-#line 2023 "parse-gram.c"
+/* Line 1585 of yacc.c  */
+#line 1839 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2213,7 +2029,7 @@ yyreduce:
       {
           case 6:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 245 "parse-gram.y"
     {
       code_props plain_code;
@@ -2228,14 +2044,14 @@ yyreduce:
 
   case 7:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 254 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 256 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -2245,14 +2061,14 @@ yyreduce:
 
   case 9:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 260 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 262 "parse-gram.y"
     {
       defines_flag = true;
@@ -2262,42 +2078,42 @@ yyreduce:
 
   case 11:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 266 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 267 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 268 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 269 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 270 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 272 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -2307,7 +2123,7 @@ yyreduce:
 
   case 17:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 277 "parse-gram.y"
     {
       code_props action;
@@ -2321,77 +2137,77 @@ yyreduce:
 
   case 18:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 285 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 286 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 287 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 288 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 289 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 290 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 291 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 292 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 293 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 294 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 296 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2411,14 +2227,14 @@ yyreduce:
 
   case 29:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 310 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 312 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2447,28 +2263,28 @@ yyreduce:
 
   case 31:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 335 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 336 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 337 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 345 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2477,7 +2293,7 @@ yyreduce:
 
   case 38:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 349 "parse-gram.y"
     {
       symbol_list *list;
@@ -2489,7 +2305,7 @@ yyreduce:
 
   case 39:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 356 "parse-gram.y"
     {
       symbol_list *list;
@@ -2501,7 +2317,7 @@ yyreduce:
 
   case 40:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 363 "parse-gram.y"
     {
       default_prec = true;
@@ -2510,7 +2326,7 @@ yyreduce:
 
   case 41:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 367 "parse-gram.y"
     {
       default_prec = false;
@@ -2519,7 +2335,7 @@ yyreduce:
 
   case 42:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 371 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2531,7 +2347,7 @@ yyreduce:
 
   case 43:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 378 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2541,21 +2357,21 @@ yyreduce:
 
   case 44:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 392 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 393 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 398 "parse-gram.y"
     {
       union_seen = true;
@@ -2566,14 +2382,14 @@ yyreduce:
 
   case 47:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 409 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 410 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2583,14 +2399,14 @@ yyreduce:
 
   case 49:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 414 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 415 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2600,7 +2416,7 @@ yyreduce:
 
   case 51:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 420 "parse-gram.y"
     {
       symbol_list *list;
@@ -2613,7 +2429,7 @@ yyreduce:
 
   case 52:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 431 "parse-gram.y"
     {
       symbol_list *list;
@@ -2630,126 +2446,126 @@ yyreduce:
 
   case 53:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 445 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 446 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 447 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 451 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 452 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 458 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 460 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 464 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 465 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 471 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 473 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 477 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 478 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 482 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 483 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 484 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 485 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 491 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2759,7 +2575,7 @@ yyreduce:
 
   case 71:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 496 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2769,7 +2585,7 @@ yyreduce:
 
   case 72:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 501 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2780,7 +2596,7 @@ yyreduce:
 
   case 73:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 507 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2791,7 +2607,7 @@ yyreduce:
 
   case 74:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 513 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2803,7 +2619,7 @@ yyreduce:
 
   case 81:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 543 "parse-gram.y"
     {
       yyerrok;
@@ -2812,14 +2628,14 @@ yyreduce:
 
   case 82:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 549 "parse-gram.y"
     { current_lhs ((yyvsp[(1) - (2)].symbol), (yylsp[(1) - (2)]), (yyvsp[(2) - (2)].named_ref)); }
     break;
 
   case 83:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 550 "parse-gram.y"
     {
     /* Free the current lhs. */
@@ -2829,21 +2645,21 @@ yyreduce:
 
   case 84:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 557 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 558 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 564 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
 				  current_lhs_named_ref); }
@@ -2851,77 +2667,77 @@ yyreduce:
 
   case 88:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 567 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 569 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 571 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 573 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 575 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 579 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 581 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 593 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 598 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 599 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 610 "parse-gram.y"
     {
       code_props plain_code;
@@ -2935,14 +2751,14 @@ yyreduce:
 
   case 101:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 630 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 632 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2953,14 +2769,14 @@ yyreduce:
 
   case 103:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 640 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 652 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2970,7 +2786,7 @@ yyreduce:
 
   case 108:
 
-/* Line 1810 of yacc.c  */
+/* Line 1801 of yacc.c  */
 #line 661 "parse-gram.y"
     {
       code_props plain_code;
@@ -2984,8 +2800,8 @@ yyreduce:
 
 
 
-/* Line 1810 of yacc.c  */
-#line 2989 "parse-gram.c"
+/* Line 1801 of yacc.c  */
+#line 2805 "parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3234,7 +3050,7 @@ yyreturn:
 
 
 
-/* Line 2071 of yacc.c  */
+/* Line 2062 of yacc.c  */
 #line 671 "parse-gram.y"
 
 
