@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.5.1_rc2.741-bfd9.  */
+/* A Bison parser, made by GNU Bison 2.5.1.779-71bff.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.5.1_rc2.741-bfd9"
+#define YYBISON_VERSION "2.5.1.779-71bff"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -72,7 +72,7 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 269 of yacc.c  */
+/* Line 324 of yacc.c  */
 #line 1 "src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -127,7 +127,7 @@ static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
 
-/* Line 269 of yacc.c  */
+/* Line 324 of yacc.c  */
 #line 132 "src/parse-gram.c"
 
 # ifndef YY_NULL
@@ -138,11 +138,6 @@ static char const *char_name (char);
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
@@ -156,198 +151,14 @@ static char const *char_name (char);
 # define YYTOKEN_TABLE 0
 #endif
 
-/* "%code requires" blocks.  */
-/* Line 291 of yacc.c  */
-#line 221 "src/parse-gram.y"
-
-# ifndef PARAM_TYPE
-#  define PARAM_TYPE
-  typedef enum
-  {
-    param_none   = 0,
-    param_lex    = 1 << 0,
-    param_parse  = 1 << 1,
-    param_both   = param_lex | param_parse
-  } param_type;
-# endif
-
-
-/* Line 291 of yacc.c  */
-#line 177 "src/parse-gram.c"
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
-     PERCENT_PRECEDENCE = 268,
-     PERCENT_PREC = 269,
-     PERCENT_DPREC = 270,
-     PERCENT_MERGE = 271,
-     PERCENT_CODE = 272,
-     PERCENT_DEFAULT_PREC = 273,
-     PERCENT_DEFINE = 274,
-     PERCENT_DEFINES = 275,
-     PERCENT_ERROR_VERBOSE = 276,
-     PERCENT_EXPECT = 277,
-     PERCENT_EXPECT_RR = 278,
-     PERCENT_FLAG = 279,
-     PERCENT_FILE_PREFIX = 280,
-     PERCENT_GLR_PARSER = 281,
-     PERCENT_INITIAL_ACTION = 282,
-     PERCENT_LANGUAGE = 283,
-     PERCENT_NAME_PREFIX = 284,
-     PERCENT_NO_DEFAULT_PREC = 285,
-     PERCENT_NO_LINES = 286,
-     PERCENT_NONDETERMINISTIC_PARSER = 287,
-     PERCENT_OUTPUT = 288,
-     PERCENT_REQUIRE = 289,
-     PERCENT_SKELETON = 290,
-     PERCENT_START = 291,
-     PERCENT_TOKEN_TABLE = 292,
-     PERCENT_VERBOSE = 293,
-     PERCENT_YACC = 294,
-     BRACED_CODE = 295,
-     BRACED_PREDICATE = 296,
-     BRACKETED_ID = 297,
-     CHAR = 298,
-     EPILOGUE = 299,
-     EQUAL = 300,
-     ID = 301,
-     ID_COLON = 302,
-     PERCENT_PERCENT = 303,
-     PIPE = 304,
-     PROLOGUE = 305,
-     SEMICOLON = 306,
-     TAG = 307,
-     TAG_ANY = 308,
-     TAG_NONE = 309,
-     PERCENT_PARAM = 310,
-     PERCENT_UNION = 311
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
-#define PERCENT_PRECEDENCE 268
-#define PERCENT_PREC 269
-#define PERCENT_DPREC 270
-#define PERCENT_MERGE 271
-#define PERCENT_CODE 272
-#define PERCENT_DEFAULT_PREC 273
-#define PERCENT_DEFINE 274
-#define PERCENT_DEFINES 275
-#define PERCENT_ERROR_VERBOSE 276
-#define PERCENT_EXPECT 277
-#define PERCENT_EXPECT_RR 278
-#define PERCENT_FLAG 279
-#define PERCENT_FILE_PREFIX 280
-#define PERCENT_GLR_PARSER 281
-#define PERCENT_INITIAL_ACTION 282
-#define PERCENT_LANGUAGE 283
-#define PERCENT_NAME_PREFIX 284
-#define PERCENT_NO_DEFAULT_PREC 285
-#define PERCENT_NO_LINES 286
-#define PERCENT_NONDETERMINISTIC_PARSER 287
-#define PERCENT_OUTPUT 288
-#define PERCENT_REQUIRE 289
-#define PERCENT_SKELETON 290
-#define PERCENT_START 291
-#define PERCENT_TOKEN_TABLE 292
-#define PERCENT_VERBOSE 293
-#define PERCENT_YACC 294
-#define BRACED_CODE 295
-#define BRACED_PREDICATE 296
-#define BRACKETED_ID 297
-#define CHAR 298
-#define EPILOGUE 299
-#define EQUAL 300
-#define ID 301
-#define ID_COLON 302
-#define PERCENT_PERCENT 303
-#define PIPE 304
-#define PROLOGUE 305
-#define SEMICOLON 306
-#define TAG 307
-#define TAG_ANY 308
-#define TAG_NONE 309
-#define PERCENT_PARAM 310
-#define PERCENT_UNION 311
-
-
-
-
-#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
-typedef union YYSTYPE
-{
-/* Line 296 of yacc.c  */
-#line 107 "src/parse-gram.y"
-
-  assoc assoc;
-  char *code;
-  char const *chars;
-  int integer;
-  named_ref *named_ref;
-  symbol *symbol;
-  symbol_list *list;
-  uniqstr uniqstr;
-  unsigned char character;
-
-/* Line 296 of yacc.c  */
-#line 245 "src/parse-gram.y"
-
-  param_type param;
-
-
-/* Line 296 of yacc.c  */
-#line 325 "src/parse-gram.c"
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
+#include "src/parse-gram.h"
 
 /* Copy the second part of user declarations.  */
 
-/* Line 346 of yacc.c  */
-#line 349 "src/parse-gram.c"
+/* Line 345 of yacc.c  */
+#line 160 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
-/* Line 347 of yacc.c  */
+/* Line 346 of yacc.c  */
 #line 56 "src/parse-gram.y"
 
   static int current_prec = 0;
@@ -380,7 +191,7 @@ typedef struct YYLTYPE
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-/* Line 347 of yacc.c  */
+/* Line 346 of yacc.c  */
 #line 234 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
@@ -393,8 +204,8 @@ typedef struct YYLTYPE
   static param_type current_param = param_none;
 
 
-/* Line 347 of yacc.c  */
-#line 398 "src/parse-gram.c"
+/* Line 346 of yacc.c  */
+#line 209 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -1041,106 +852,106 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
             case 3: // "string"
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 194 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
-/* Line 755 of yacc.c  */
-#line 1049 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 860 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 207 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
-/* Line 755 of yacc.c  */
-#line 1058 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 869 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 203 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 755 of yacc.c  */
-#line 1067 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 878 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 755 of yacc.c  */
-#line 1076 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 887 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 201 "src/parse-gram.y"
         { fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 755 of yacc.c  */
-#line 1085 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 896 "src/parse-gram.c"
         break;
 
             case 43: // "char"
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 188 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
-/* Line 755 of yacc.c  */
-#line 1094 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 905 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 755 of yacc.c  */
-#line 1103 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 914 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 200 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 755 of yacc.c  */
-#line 1112 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 923 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 202 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 755 of yacc.c  */
-#line 1121 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 932 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 755 of yacc.c  */
-#line 1130 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 941 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 204 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 755 of yacc.c  */
-#line 1139 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 950 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 250 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
@@ -1154,80 +965,80 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case param_none: aver (false); break;
     }
 }
-/* Line 755 of yacc.c  */
-#line 1159 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 970 "src/parse-gram.c"
         break;
 
             case 72: // symbol.prec
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 755 of yacc.c  */
-#line 1168 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 979 "src/parse-gram.c"
         break;
 
             case 85: // variable
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 200 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 755 of yacc.c  */
-#line 1177 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 988 "src/parse-gram.c"
         break;
 
             case 86: // content.opt
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 755 of yacc.c  */
-#line 1186 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 997 "src/parse-gram.c"
         break;
 
             case 87: // braceless
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 755 of yacc.c  */
-#line 1195 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 1006 "src/parse-gram.c"
         break;
 
             case 88: // id
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 755 of yacc.c  */
-#line 1204 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 1015 "src/parse-gram.c"
         break;
 
             case 89: // id_colon
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 211 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 755 of yacc.c  */
-#line 1213 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 1024 "src/parse-gram.c"
         break;
 
             case 90: // symbol
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 755 of yacc.c  */
-#line 1222 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 1033 "src/parse-gram.c"
         break;
 
             case 91: // string_as_id
 
-/* Line 755 of yacc.c  */
+/* Line 754 of yacc.c  */
 #line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 755 of yacc.c  */
-#line 1231 "src/parse-gram.c"
+/* Line 754 of yacc.c  */
+#line 1042 "src/parse-gram.c"
         break;
 
       default:
@@ -1872,22 +1683,6 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
 }
 
 
-/* Prevent warnings from -Wmissing-prototypes.  */
-#ifdef YYPARSE_PARAM
-#if (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
-int yyparse (void *YYPARSE_PARAM);
-#else
-int yyparse ();
-#endif
-#else /* ! YYPARSE_PARAM */
-#if (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
-int yyparse (void);
-#else
-int yyparse ();
-#endif
-#endif /* ! YYPARSE_PARAM */
 
 
 /*----------.
@@ -2020,7 +1815,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1528 of yacc.c  */
+/* Line 1519 of yacc.c  */
 #line 99 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -2028,8 +1823,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1528 of yacc.c  */
-#line 2033 "src/parse-gram.c"
+/* Line 1519 of yacc.c  */
+#line 1828 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2222,7 +2017,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 286 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2233,106 +2028,106 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1744 of yacc.c  */
-#line 2238 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2033 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 296 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1744 of yacc.c  */
-#line 2248 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2043 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 300 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1744 of yacc.c  */
-#line 2259 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2054 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 304 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1744 of yacc.c  */
-#line 2267 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2062 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 306 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1744 of yacc.c  */
-#line 2278 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2073 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 311 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1744 of yacc.c  */
-#line 2289 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2084 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 315 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1744 of yacc.c  */
-#line 2297 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2092 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 316 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1744 of yacc.c  */
-#line 2305 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2100 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1744 of yacc.c  */
-#line 2313 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2108 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 318 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1744 of yacc.c  */
-#line 2321 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2116 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 320 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1744 of yacc.c  */
-#line 2332 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2127 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 325 "src/parse-gram.y"
     {
       code_props action;
@@ -2342,92 +2137,92 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1744 of yacc.c  */
-#line 2347 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2142 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 333 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1744 of yacc.c  */
-#line 2355 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2150 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 334 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1744 of yacc.c  */
-#line 2363 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2158 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 335 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1744 of yacc.c  */
-#line 2371 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2166 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 336 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1744 of yacc.c  */
-#line 2379 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2174 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 337 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1744 of yacc.c  */
-#line 2387 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2182 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 338 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1744 of yacc.c  */
-#line 2395 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2190 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 339 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1744 of yacc.c  */
-#line 2403 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2198 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 340 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1744 of yacc.c  */
-#line 2411 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2206 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 340 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1744 of yacc.c  */
-#line 2419 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2214 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 341 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1744 of yacc.c  */
-#line 2427 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2222 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 343 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2452,62 +2247,62 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1744 of yacc.c  */
-#line 2457 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2252 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 366 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1744 of yacc.c  */
-#line 2465 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2260 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 367 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1744 of yacc.c  */
-#line 2473 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2268 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 368 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1744 of yacc.c  */
-#line 2481 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2276 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 373 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2489 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2284 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 374 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2497 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2292 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 386 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1744 of yacc.c  */
-#line 2507 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2302 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 390 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2515,12 +2310,12 @@ yyreduce:
         symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1744 of yacc.c  */
-#line 2520 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2315 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 397 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2528,32 +2323,32 @@ yyreduce:
         symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1744 of yacc.c  */
-#line 2533 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2328 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 404 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1744 of yacc.c  */
-#line 2543 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2338 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 408 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1744 of yacc.c  */
-#line 2553 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2348 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 412 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2561,89 +2356,89 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1744 of yacc.c  */
-#line 2566 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2361 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 419 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1744 of yacc.c  */
-#line 2577 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2372 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 433 "src/parse-gram.y"
     {}
-/* Line 1744 of yacc.c  */
-#line 2585 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2380 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 434 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2593 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2388 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 439 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1744 of yacc.c  */
-#line 2605 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2400 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 450 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1744 of yacc.c  */
-#line 2613 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2408 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 451 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1744 of yacc.c  */
-#line 2624 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2419 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 455 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1744 of yacc.c  */
-#line 2632 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2427 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 456 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1744 of yacc.c  */
-#line 2643 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2438 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 461 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2652,12 +2447,12 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1744 of yacc.c  */
-#line 2657 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2452 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 472 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2670,202 +2465,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1744 of yacc.c  */
-#line 2675 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2470 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 486 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1744 of yacc.c  */
-#line 2683 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2478 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 487 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1744 of yacc.c  */
-#line 2691 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2486 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 488 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1744 of yacc.c  */
-#line 2699 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2494 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 489 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1744 of yacc.c  */
-#line 2707 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2502 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 493 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1744 of yacc.c  */
-#line 2715 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2510 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 494 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1744 of yacc.c  */
-#line 2723 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2518 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 500 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2731 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2526 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 502 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1744 of yacc.c  */
-#line 2739 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2534 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 506 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1744 of yacc.c  */
-#line 2747 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2542 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 507 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2755 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2550 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 513 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2763 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2558 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 515 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1744 of yacc.c  */
-#line 2771 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2566 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 519 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1744 of yacc.c  */
-#line 2779 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2574 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 520 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1744 of yacc.c  */
-#line 2787 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2582 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 524 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2795 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2590 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 525 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2803 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2598 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 526 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2811 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2606 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 527 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2819 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2614 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 533 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1744 of yacc.c  */
-#line 2830 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2625 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 538 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1744 of yacc.c  */
-#line 2841 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2636 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 543 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1744 of yacc.c  */
-#line 2853 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2648 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 549 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1744 of yacc.c  */
-#line 2865 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2660 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 555 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2873,154 +2668,154 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1744 of yacc.c  */
-#line 2878 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2673 "src/parse-gram.c"
     break;
 
   case 82:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 585 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1744 of yacc.c  */
-#line 2888 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2683 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 591 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1744 of yacc.c  */
-#line 2896 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2691 "src/parse-gram.c"
     break;
 
   case 84:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 592 "src/parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-/* Line 1744 of yacc.c  */
-#line 2907 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2702 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 599 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2915 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2710 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 600 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2923 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2718 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 606 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-/* Line 1744 of yacc.c  */
-#line 2932 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2727 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 609 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1744 of yacc.c  */
-#line 2940 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2735 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 611 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1744 of yacc.c  */
-#line 2948 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2743 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 613 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1744 of yacc.c  */
-#line 2956 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2751 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 615 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2964 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2759 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 617 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2972 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2767 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 619 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2980 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2775 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 623 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1744 of yacc.c  */
-#line 2988 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2783 "src/parse-gram.c"
     break;
 
   case 96:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 625 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 2996 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2791 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 636 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1744 of yacc.c  */
-#line 3004 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2799 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 641 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1744 of yacc.c  */
-#line 3012 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2807 "src/parse-gram.c"
     break;
 
   case 100:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 642 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1744 of yacc.c  */
-#line 3020 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2815 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 653 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -3030,51 +2825,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1744 of yacc.c  */
-#line 3035 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2830 "src/parse-gram.c"
     break;
 
   case 103:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 673 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 3043 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2838 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 675 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1744 of yacc.c  */
-#line 3055 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2850 "src/parse-gram.c"
     break;
 
   case 105:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 683 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1744 of yacc.c  */
-#line 3063 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2858 "src/parse-gram.c"
     break;
 
   case 108:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 695 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1744 of yacc.c  */
-#line 3074 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2869 "src/parse-gram.c"
     break;
 
   case 110:
-/* Line 1744 of yacc.c  */
+/* Line 1735 of yacc.c  */
 #line 704 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -3084,13 +2879,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1744 of yacc.c  */
-#line 3089 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2884 "src/parse-gram.c"
     break;
 
 
-/* Line 1744 of yacc.c  */
-#line 3094 "src/parse-gram.c"
+/* Line 1735 of yacc.c  */
+#line 2889 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3337,7 +3132,7 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 2004 of yacc.c  */
+/* Line 1995 of yacc.c  */
 #line 714 "src/parse-gram.y"
 
 
