@@ -1,56 +1,66 @@
 /* A Bison parser, made from parse-gram.y
-   by GNU bison 1.35.  */
+   by GNU bison 1.49b.  */
 
-#define YYBISON 1  /* Identify Bison output.  */
+/* Skeleton output parser for Bison,
+   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
+   Foundation, Inc.
+
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
+
+   This program is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software
+   Foundation, Inc., 59 Temple Place - Suite 330,
+   Boston, MA 02111-1307, USA.  */
+
+/* As a special exception, when this file is copied by Bison into a
+   Bison output file, you may use that output file without restriction.
+   This special exception was added by the Free Software Foundation
+   in version 1.24 of Bison.  */
+
+/* This is the parser code that is written into each bison parser when
+   the %semantic_parser declaration is not specified in the grammar.
+   It was written by Richard Stallman by simplifying the original so
+   called ``semantic'' parser.  */
+
+/* All symbols defined below should begin with yy or YY, to avoid
+   infringing on user name space.  This should be done even for local
+   variables, as they might otherwise be expanded by user macros.
+   There are some unavoidable exceptions within include files to
+   define necessary library symbols; they are noted "INFRINGES ON
+   USER NAME SPACE" below.  */
+
+/* Identify Bison output.  */
+#define YYBISON	1
+
+/* Pure parsers.  */
+#define YYPURE	1
+
+/* Using locations.  */
+#define YYLSP_NEEDED 1
 
+/* If NAME_PREFIX is specified substitute the variables and functions
+   names.  */
 #define yyparse gram_parse
-#define yylex gram_lex
+#define yylex   gram_lex
 #define yyerror gram_error
-#define yylval gram_lval
-#define yychar gram_char
+#define yylval  gram_lval
+#define yychar  gram_char
 #define yydebug gram_debug
 #define yynerrs gram_nerrs
-#define YYLSP_NEEDED 1
+#if YYLSP_NEEDED
+# define yylloc gram_lloc
+#endif
 
-# define	GRAM_EOF	0
-# define	STRING	257
-# define	CHARACTER	258
-# define	INT	259
-# define	PERCENT_TOKEN	260
-# define	PERCENT_NTERM	261
-# define	PERCENT_TYPE	262
-# define	PERCENT_UNION	263
-# define	PERCENT_EXPECT	264
-# define	PERCENT_START	265
-# define	PERCENT_LEFT	266
-# define	PERCENT_RIGHT	267
-# define	PERCENT_NONASSOC	268
-# define	PERCENT_PREC	269
-# define	PERCENT_VERBOSE	270
-# define	PERCENT_ERROR_VERBOSE	271
-# define	PERCENT_OUTPUT	272
-# define	PERCENT_FILE_PREFIX	273
-# define	PERCENT_NAME_PREFIX	274
-# define	PERCENT_DEFINE	275
-# define	PERCENT_PURE_PARSER	276
-# define	PERCENT_DEFINES	277
-# define	PERCENT_YACC	278
-# define	PERCENT_DEBUG	279
-# define	PERCENT_LOCATIONS	280
-# define	PERCENT_NO_LINES	281
-# define	PERCENT_SKELETON	282
-# define	PERCENT_TOKEN_TABLE	283
-# define	TYPE	284
-# define	EQUAL	285
-# define	SEMICOLON	286
-# define	COLON	287
-# define	PIPE	288
-# define	ID	289
-# define	PERCENT_PERCENT	290
-# define	PROLOGUE	291
-# define	EPILOGUE	292
-# define	BRACED_CODE	293
 
+/* Copy the first part of user declarations.  */
 #line 31 "parse-gram.y"
 
 #include "system.h"
@@ -91,15 +101,121 @@ symbol_t *current_lhs;
 associativity current_assoc;
 int current_prec = 0;
 
-#line 73 "parse-gram.y"
+
+/* Tokens.  */
+#ifndef YYTOKENTYPE
+# if defined (__STDC__) || defined (__cplusplus)
+   /* Put the tokens into the symbol table, so that GDB and other debuggers
+      know about them.  */
+   enum yytokentype {
+     GRAM_EOF = 0,
+     STRING = 258,
+     CHARACTER = 259,
+     INT = 260,
+     PERCENT_TOKEN = 261,
+     PERCENT_NTERM = 262,
+     PERCENT_TYPE = 263,
+     PERCENT_UNION = 264,
+     PERCENT_EXPECT = 265,
+     PERCENT_START = 266,
+     PERCENT_PREC = 267,
+     PERCENT_VERBOSE = 268,
+     PERCENT_ERROR_VERBOSE = 269,
+     PERCENT_OUTPUT = 270,
+     PERCENT_FILE_PREFIX = 271,
+     PERCENT_NAME_PREFIX = 272,
+     PERCENT_DEFINE = 273,
+     PERCENT_PURE_PARSER = 274,
+     PERCENT_DEFINES = 275,
+     PERCENT_YACC = 276,
+     PERCENT_DEBUG = 277,
+     PERCENT_LOCATIONS = 278,
+     PERCENT_NO_LINES = 279,
+     PERCENT_SKELETON = 280,
+     PERCENT_TOKEN_TABLE = 281,
+     TYPE = 282,
+     EQUAL = 283,
+     SEMICOLON = 284,
+     COLON = 285,
+     PIPE = 286,
+     ID = 287,
+     PERCENT_PERCENT = 288,
+     PROLOGUE = 289,
+     EPILOGUE = 290,
+     BRACED_CODE = 291,
+     PERCENT_LEFT = 292,
+     PERCENT_RIGHT = 293,
+     PERCENT_NONASSOC = 294
+   };
+# endif
+  /* POSIX requires `int' for tokens in interfaces.  */
+# define YYTOKENTYPE int
+#endif /* !YYTOKENTYPE */
+#define GRAM_EOF 0
+#define STRING 258
+#define CHARACTER 259
+#define INT 260
+#define PERCENT_TOKEN 261
+#define PERCENT_NTERM 262
+#define PERCENT_TYPE 263
+#define PERCENT_UNION 264
+#define PERCENT_EXPECT 265
+#define PERCENT_START 266
+#define PERCENT_PREC 267
+#define PERCENT_VERBOSE 268
+#define PERCENT_ERROR_VERBOSE 269
+#define PERCENT_OUTPUT 270
+#define PERCENT_FILE_PREFIX 271
+#define PERCENT_NAME_PREFIX 272
+#define PERCENT_DEFINE 273
+#define PERCENT_PURE_PARSER 274
+#define PERCENT_DEFINES 275
+#define PERCENT_YACC 276
+#define PERCENT_DEBUG 277
+#define PERCENT_LOCATIONS 278
+#define PERCENT_NO_LINES 279
+#define PERCENT_SKELETON 280
+#define PERCENT_TOKEN_TABLE 281
+#define TYPE 282
+#define EQUAL 283
+#define SEMICOLON 284
+#define COLON 285
+#define PIPE 286
+#define ID 287
+#define PERCENT_PERCENT 288
+#define PROLOGUE 289
+#define EPILOGUE 290
+#define BRACED_CODE 291
+#define PERCENT_LEFT 292
+#define PERCENT_RIGHT 293
+#define PERCENT_NONASSOC 294
+
+
+
+
+/* Enabling traces.  */
+#ifndef YYDEBUG
+# define YYDEBUG 1
+#endif
+
+/* Enabling verbose error messages.  */
+#ifdef YYERROR_VERBOSE
+# undef YYERROR_VERBOSE
+# define YYERROR_VERBOSE 1
+#else
+# define YYERROR_VERBOSE 0
+#endif
+
 #ifndef YYSTYPE
-typedef union
-{
+#line 74 "parse-gram.y"
+typedef union {
   symbol_t *symbol;
   int integer;
   char *string;
   associativity assoc;
 } yystype;
+/* Line 199 of /home/akim/src/bison/data/bison.simple.  */
+#line 219 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
@@ -109,275 +225,20 @@ typedef struct yyltype
 {
   int first_line;
   int first_column;
-
   int last_line;
   int last_column;
 } yyltype;
-
 # define YYLTYPE yyltype
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
-#ifndef YYDEBUG
-# define YYDEBUG 1
-#endif
-
-
-
-#define	YYFINAL		95
-#define	YYFLAG		-32768
-#define	YYNTBASE	41
-
-/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
-#define YYTRANSLATE(x) ((unsigned)(x) <= 293 ? yytranslate[x] : 69)
-
-/* YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX. */
-static const char yytranslate[] =
-{
-       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     1,     4,     5,     6,
-       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
-      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
-      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
-      37,    38,    39,    40
-};
-
-#if YYDEBUG
-static const short yyprhs[] =
-{
-       0,     0,     1,     7,     8,    11,    13,    15,    17,    21,
-      23,    25,    28,    32,    34,    38,    40,    44,    46,    49,
-      51,    53,    55,    57,    59,    62,    66,    67,    71,    72,
-      76,    77,    82,    83,    88,    90,    92,    94,    95,    97,
-      99,   102,   104,   107,   109,   111,   114,   117,   121,   123,
-     126,   128,   131,   132,   138,   140,   144,   145,   148,   151,
-     155,   157,   159,   161,   163,   165,   167,   168,   171,   172
-};
-static const short yyrhs[] =
-{
-      -1,    42,    43,    37,    58,    67,     0,     0,    43,    44,
-       0,    45,     0,    38,     0,    26,     0,    22,    66,    66,
-       0,    24,     0,    18,     0,    11,     6,     0,    20,    32,
-      66,     0,    27,     0,    21,    32,    66,     0,    28,     0,
-      19,    32,    66,     0,    23,     0,    29,    66,     0,    30,
-       0,    17,     0,    25,     0,    50,     0,    46,     0,    12,
-      63,     0,    10,    40,    68,     0,     0,     8,    47,    57,
-       0,     0,     7,    48,    57,     0,     0,     9,    31,    49,
-      54,     0,     0,    52,    53,    51,    55,     0,    13,     0,
-      14,     0,    15,     0,     0,    31,     0,    36,     0,    54,
-      36,     0,    63,     0,    55,    63,     0,    31,     0,    36,
-       0,    36,     6,     0,    36,    65,     0,    36,     6,    65,
-       0,    56,     0,    57,    56,     0,    59,     0,    58,    59,
-       0,     0,    36,    34,    60,    61,    33,     0,    62,     0,
-      61,    35,    62,     0,     0,    62,    63,     0,    62,    64,
-       0,    62,    16,    63,     0,    36,     0,    65,     0,     5,
-       0,    40,     0,     4,     0,     4,     0,     0,    37,    39,
-       0,     0,    33,     0
-};
-
-#endif
-
-#if YYDEBUG
-/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
-static const short yyrline[] =
-{
-       0,   134,   134,   147,   149,   152,   154,   155,   156,   157,
-     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
-     168,   169,   172,   174,   175,   179,   187,   187,   193,   193,
-     198,   198,   204,   204,   211,   213,   214,   217,   219,   223,
-     225,   229,   235,   243,   248,   253,   259,   265,   275,   278,
-     287,   289,   292,   292,   297,   299,   302,   305,   307,   309,
-     313,   315,   316,   319,   325,   334,   342,   347,   353,   355
-};
-#endif
-
-
-#if (YYDEBUG) || defined YYERROR_VERBOSE
-
-/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */
-static const char *const yytname[] =
-{
-  "$", "error", "$undefined.", "\"end of string\"", "STRING", "CHARACTER", 
-  "INT", "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%union\"", 
-  "\"%expect\"", "\"%start\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"", 
-  "\"%prec\"", "\"%verbose\"", "\"%error-verbose\"", "\"%output\"", 
-  "\"%file-prefix\"", "\"%name-prefix\"", "\"%define\"", 
-  "\"%pure-parser\"", "\"%defines\"", "\"%yacc\"", "\"%debug\"", 
-  "\"%locations\"", "\"%no-lines\"", "\"%skeleton\"", "\"%token-table\"", 
-  "TYPE", "\"=\"", "\";\"", "\":\"", "\"|\"", "\"identifier\"", "\"%%\"", 
-  "PROLOGUE", "EPILOGUE", "BRACED_CODE", "input", "@1", "declarations", 
-  "declaration", "grammar_declaration", "symbol_declaration", "@2", "@3", 
-  "@4", "precedence_declaration", "@5", "precedence_declarator", 
-  "type.opt", "nterms_to_type.1", "terms_to_prec.1", "symbol_def", 
-  "symbol_defs.1", "grammar", "rules", "@6", "rhses.1", "rhs", "symbol", 
-  "action", "string_as_id", "string_content", "epilogue.opt", 
-  "semi_colon_opt", 0
-};
-#endif
-
-/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
-static const short yyr1[] =
-{
-       0,    42,    41,    43,    43,    44,    44,    44,    44,    44,
-      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
-      44,    44,    45,    45,    45,    45,    47,    46,    48,    46,
-      49,    46,    51,    50,    52,    52,    52,    53,    53,    54,
-      54,    55,    55,    56,    56,    56,    56,    56,    57,    57,
-      58,    58,    60,    59,    61,    61,    62,    62,    62,    62,
-      63,    63,    63,    64,    65,    66,    67,    67,    68,    68
-};
-
-/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
-static const short yyr2[] =
-{
-       0,     0,     5,     0,     2,     1,     1,     1,     3,     1,
-       1,     2,     3,     1,     3,     1,     3,     1,     2,     1,
-       1,     1,     1,     1,     2,     3,     0,     3,     0,     3,
-       0,     4,     0,     4,     1,     1,     1,     0,     1,     1,
-       2,     1,     2,     1,     1,     2,     2,     3,     1,     2,
-       1,     2,     0,     5,     1,     3,     0,     2,     2,     3,
-       1,     1,     1,     1,     1,     1,     0,     2,     0,     1
-};
-
-/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
-   doesn't specify something else to do.  Zero means the default is an
-   error. */
-static const short yydefact[] =
-{
-       1,     3,     0,    28,    26,     0,     0,     0,     0,    34,
-      35,    36,    20,    10,     0,     0,     0,     0,    17,     9,
-      21,     7,    13,    15,     0,    19,     0,     6,     4,     5,
-      23,    22,    37,     0,     0,    30,    68,    11,    64,    62,
-      60,    24,    61,     0,     0,     0,    65,     0,    18,     0,
-      66,    50,    38,    32,    43,    44,    48,    29,    27,     0,
-      69,    25,    16,    12,    14,     8,    52,     0,    51,     2,
-       0,    45,    46,    49,    39,    31,    56,    67,    33,    41,
-      47,    40,     0,    54,    42,    53,    56,     0,    63,    57,
-      58,    55,    59,     0,     0,     0
-};
-
-static const short yydefgoto[] =
-{
-      93,     1,     2,    28,    29,    30,    34,    33,    59,    31,
-      70,    32,    53,    75,    78,    56,    57,    50,    51,    76,
-      82,    83,    89,    90,    42,    47,    69,    61
-};
-
-static const short yypact[] =
-{
-  -32768,-32768,    31,-32768,-32768,   -22,   -29,     8,    -1,-32768,
-  -32768,-32768,-32768,-32768,   -16,   -14,   -11,    19,-32768,-32768,
-  -32768,-32768,-32768,-32768,    19,-32768,    -9,-32768,-32768,-32768,
-  -32768,-32768,     0,   -24,   -24,-32768,     1,-32768,-32768,-32768,
-  -32768,-32768,-32768,    19,    19,    19,-32768,    19,-32768,    -2,
-     -17,-32768,-32768,-32768,-32768,     4,-32768,   -24,   -24,    11,
-  -32768,-32768,-32768,-32768,-32768,-32768,-32768,    24,-32768,-32768,
-      -1,    32,-32768,-32768,-32768,    28,-32768,-32768,    -1,-32768,
-  -32768,-32768,   -18,    -3,-32768,-32768,-32768,    -1,-32768,-32768,
-  -32768,    -3,-32768,    65,    66,-32768
-};
-
-static const short yypgoto[] =
-{
-  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-  -32768,-32768,-32768,-32768,-32768,   -28,    33,-32768,    21,-32768,
-  -32768,   -13,    -8,-32768,   -49,   -19,-32768,-32768
-};
-
-
-#define	YYLAST		79
-
-
-static const short yytable[] =
-{
-      41,    38,    39,    38,    39,    48,    72,    54,    38,    35,
-      71,    36,    55,    87,    37,    85,    43,    86,    44,    49,
-      67,    45,    80,    46,    62,    63,    64,    49,    65,    73,
-      73,    52,    66,    40,    60,    40,    38,    88,     3,     4,
-       5,     6,     7,     8,     9,    10,    11,    74,    12,    13,
-      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
-      24,    25,    79,    77,    81,    94,    95,    58,    26,    27,
-      84,    68,     0,    91,     0,     0,     0,     0,     0,    92
-};
-
-static const short yycheck[] =
-{
-       8,     4,     5,     4,     5,    24,    55,    31,     4,    31,
-       6,    40,    36,    16,     6,    33,    32,    35,    32,    36,
-      37,    32,    71,     4,    43,    44,    45,    36,    47,    57,
-      58,    31,    34,    36,    33,    36,     4,    40,     7,     8,
-       9,    10,    11,    12,    13,    14,    15,    36,    17,    18,
-      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
-      29,    30,    70,    39,    36,     0,     0,    34,    37,    38,
-      78,    50,    -1,    86,    -1,    -1,    -1,    -1,    -1,    87
-};
-#define YYPURE 1
-
-/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
-#line 3 "/usr/share/bison/bison.simple"
-
-/* Skeleton output parser for bison,
-
-   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
-   Foundation, Inc.
-
-   This program is free software; you can redistribute it and/or modify
-   it under the terms of the GNU General Public License as published by
-   the Free Software Foundation; either version 2, or (at your option)
-   any later version.
-
-   This program is distributed in the hope that it will be useful,
-   but WITHOUT ANY WARRANTY; without even the implied warranty of
-   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-   GNU General Public License for more details.
-
-   You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software
-   Foundation, Inc., 59 Temple Place - Suite 330,
-   Boston, MA 02111-1307, USA.  */
-
-/* As a special exception, when this file is copied by Bison into a
-   Bison output file, you may use that output file without restriction.
-   This special exception was added by the Free Software Foundation
-   in version 1.24 of Bison.  */
+/* Copy the second part of user declarations.  */
 
-/* This is the parser code that is written into each bison parser when
-   the %semantic_parser declaration is not specified in the grammar.
-   It was written by Richard Stallman by simplifying the hairy parser
-   used when %semantic_parser is specified.  */
 
-/* All symbols defined below should begin with yy or YY, to avoid
-   infringing on user name space.  This should be done even for local
-   variables, as they might otherwise be expanded by user macros.
-   There are some unavoidable exceptions within include files to
-   define necessary library symbols; they are noted "INFRINGES ON
-   USER NAME SPACE" below.  */
+/* Line 219 of /home/akim/src/bison/data/bison.simple.  */
+#line 240 "parse-gram.c"
 
-#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)
+#if ! defined (yyoverflow) || YYERROR_VERBOSE
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
 
@@ -406,7 +267,7 @@ static const short yycheck[] =
 #  define YYSTACK_ALLOC malloc
 #  define YYSTACK_FREE free
 # endif
-#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */
+#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */
 
 
 #if (! defined (yyoverflow) \
@@ -450,7 +311,7 @@ union yyalloc
 	{					\
 	  register YYSIZE_T yyi;		\
 	  for (yyi = 0; yyi < (Count); yyi++)	\
-	    (To)[yyi] = (From)[yyi];		\
+	    (To)[yyi] = (From)[yyi];	\
 	}					\
       while (0)
 #  endif
@@ -474,6 +335,272 @@ union yyalloc
 
 #endif
 
+/* YYFINAL -- State number of the termination state. */
+#define YYFINAL  3
+#define YYFLAG	 -32768
+#define YYLAST   91
+
+/* YYNTOKENS -- Number of terminals. */
+#define YYNTOKENS  40
+/* YYNNTS -- Number of nonterminals. */
+#define YYNNTS  30
+/* YYNRULES -- Number of rules. */
+#define YYNRULES  72
+/* YYNRULES -- Number of states. */
+#define YYNSTATES  98
+
+/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
+#define YYUNDEFTOK  2
+#define YYMAXUTOK   294
+
+#define YYTRANSLATE(X) \
+  ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)
+
+/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
+static const unsigned char yytranslate[] =
+{
+       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
+       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
+       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
+      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
+      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
+      35,    36,    37,    38,    39
+};
+
+#if YYDEBUG
+/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
+   YYRHS.  */
+static const unsigned char yyprhs[] =
+{
+       0,     0,     3,     4,    10,    11,    15,    17,    19,    21,
+      25,    27,    29,    32,    36,    38,    42,    44,    48,    50,
+      53,    55,    57,    59,    61,    63,    66,    69,    70,    74,
+      75,    79,    80,    85,    86,    91,    93,    95,    97,    98,
+     100,   102,   105,   107,   110,   112,   114,   117,   120,   124,
+     126,   129,   131,   134,   136,   139,   140,   146,   148,   152,
+     153,   156,   159,   163,   165,   167,   169,   171,   173,   175,
+     176,   179,   180
+};
+
+/* YYRHS -- A `-1'-separated list of the rules' RHS. */
+static const signed char yyrhs[] =
+{
+      41,     0,    -1,    -1,    42,    43,    33,    58,    68,    -1,
+      -1,    43,    44,    69,    -1,    45,    -1,    34,    -1,    22,
+      -1,    18,    67,    67,    -1,    20,    -1,    14,    -1,    10,
+       5,    -1,    16,    28,    67,    -1,    23,    -1,    17,    28,
+      67,    -1,    24,    -1,    15,    28,    67,    -1,    19,    -1,
+      25,    67,    -1,    26,    -1,    13,    -1,    21,    -1,    50,
+      -1,    46,    -1,    11,    64,    -1,     9,    36,    -1,    -1,
+       7,    47,    57,    -1,    -1,     6,    48,    57,    -1,    -1,
+       8,    27,    49,    54,    -1,    -1,    52,    53,    51,    55,
+      -1,    37,    -1,    38,    -1,    39,    -1,    -1,    27,    -1,
+      32,    -1,    54,    32,    -1,    64,    -1,    55,    64,    -1,
+      27,    -1,    32,    -1,    32,     5,    -1,    32,    66,    -1,
+      32,     5,    66,    -1,    56,    -1,    57,    56,    -1,    59,
+      -1,    58,    59,    -1,    60,    -1,    45,    29,    -1,    -1,
+      32,    30,    61,    62,    29,    -1,    63,    -1,    62,    31,
+      63,    -1,    -1,    63,    64,    -1,    63,    65,    -1,    63,
+      12,    64,    -1,    32,    -1,    66,    -1,     4,    -1,    36,
+      -1,     3,    -1,     3,    -1,    -1,    33,    35,    -1,    -1,
+      29,    -1
+};
+
+/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
+static const unsigned short yyrline[] =
+{
+       0,   131,   131,   131,   144,   146,   149,   151,   152,   153,
+     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
+     164,   165,   166,   169,   171,   172,   176,   184,   184,   190,
+     190,   195,   195,   201,   201,   211,   213,   214,   217,   219,
+     223,   225,   229,   235,   243,   248,   253,   259,   265,   275,
+     278,   287,   289,   295,   297,   300,   300,   305,   307,   310,
+     313,   315,   317,   321,   323,   324,   327,   333,   342,   350,
+     355,   361,   363
+};
+#endif
+
+#if YYDEBUG || YYERROR_VERBOSE
+/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
+   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
+static const char *const yytname[] =
+{
+  "\"end of string\"", "error", "$undefined.", "STRING", "CHARACTER", "INT", 
+  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%union\"", "\"%expect\"", 
+  "\"%start\"", "\"%prec\"", "\"%verbose\"", "\"%error-verbose\"", 
+  "\"%output\"", "\"%file-prefix\"", "\"%name-prefix\"", "\"%define\"", 
+  "\"%pure-parser\"", "\"%defines\"", "\"%yacc\"", "\"%debug\"", 
+  "\"%locations\"", "\"%no-lines\"", "\"%skeleton\"", "\"%token-table\"", 
+  "TYPE", "\"=\"", "\";\"", "\":\"", "\"|\"", "\"identifier\"", "\"%%\"", 
+  "PROLOGUE", "EPILOGUE", "BRACED_CODE", "\"%left\"", "\"%right\"", 
+  "\"%nonassoc\"", "$axiom", "input", "@1", "declarations", "declaration", 
+  "grammar_declaration", "symbol_declaration", "@2", "@3", "@4", 
+  "precedence_declaration", "@5", "precedence_declarator", "type.opt", 
+  "nterms_to_type.1", "terms_to_prec.1", "symbol_def", "symbol_defs.1", 
+  "grammar", "rules_or_grammar_declaration", "rules", "@6", "rhses.1", 
+  "rhs", "symbol", "action", "string_as_id", "string_content", 
+  "epilogue.opt", "semi_colon.opt", 0
+};
+#endif
+
+/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
+   token YYLEX-NUM.  */
+static const short yytoknum[] =
+{
+       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
+     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
+     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
+     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
+      -1
+};
+
+/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
+static const unsigned char yyr1[] =
+{
+       0,    40,    42,    41,    43,    43,    44,    44,    44,    44,
+      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
+      44,    44,    44,    45,    45,    45,    45,    47,    46,    48,
+      46,    49,    46,    51,    50,    52,    52,    52,    53,    53,
+      54,    54,    55,    55,    56,    56,    56,    56,    56,    57,
+      57,    58,    58,    59,    59,    61,    60,    62,    62,    63,
+      63,    63,    63,    64,    64,    64,    65,    66,    67,    68,
+      68,    69,    69
+};
+
+/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
+static const unsigned char yyr2[] =
+{
+       0,     2,     0,     5,     0,     3,     1,     1,     1,     3,
+       1,     1,     2,     3,     1,     3,     1,     3,     1,     2,
+       1,     1,     1,     1,     1,     2,     2,     0,     3,     0,
+       3,     0,     4,     0,     4,     1,     1,     1,     0,     1,
+       1,     2,     1,     2,     1,     1,     2,     2,     3,     1,
+       2,     1,     2,     1,     2,     0,     5,     1,     3,     0,
+       2,     2,     3,     1,     1,     1,     1,     1,     1,     0,
+       2,     0,     1
+};
+
+/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
+   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
+   means the default is an error.  */
+static const short yydefact[] =
+{
+       2,     0,     4,     0,     0,    29,    27,     0,     0,     0,
+       0,    21,    11,     0,     0,     0,     0,    18,    10,    22,
+       8,    14,    16,     0,    20,     0,     7,    35,    36,    37,
+      71,     6,    24,    23,    38,     0,     0,    31,    26,    12,
+      67,    65,    63,    25,    64,     0,     0,     0,    68,     0,
+      19,     0,     0,    69,    51,    53,    72,     5,    39,    33,
+      44,    45,    49,    30,    28,     0,    17,    13,    15,     9,
+      55,    54,     0,    52,     3,     0,    46,    47,    50,    40,
+      32,    59,    70,    34,    42,    48,    41,     0,    57,    43,
+      56,    59,     0,    66,    60,    61,    58,    62
+};
+
+/* YYPGOTO[NTERM-NUM]. */
+static const short yydefgoto[] =
+{
+      -1,     1,     2,     4,    30,    52,    32,    36,    35,    65,
+      33,    75,    34,    59,    80,    83,    62,    63,    53,    54,
+      55,    81,    87,    88,    94,    95,    44,    49,    74,    57
+};
+
+/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
+   STATE-NUM.  */
+static const short yypact[] =
+{
+  -32768,     7,-32768,-32768,    -5,-32768,-32768,    -1,    11,    51,
+      38,-32768,-32768,    36,    43,    44,    66,-32768,-32768,-32768,
+  -32768,-32768,-32768,    66,-32768,    29,-32768,-32768,-32768,-32768,
+      45,-32768,-32768,-32768,    48,    18,    18,-32768,-32768,-32768,
+  -32768,-32768,-32768,-32768,-32768,    66,    66,    66,-32768,    66,
+  -32768,    46,    49,    16,-32768,-32768,-32768,-32768,-32768,-32768,
+  -32768,    41,-32768,    18,    18,    52,-32768,-32768,-32768,-32768,
+  -32768,-32768,    42,-32768,-32768,    38,    82,-32768,-32768,-32768,
+      54,-32768,-32768,    38,-32768,-32768,-32768,    31,    27,-32768,
+  -32768,-32768,    38,-32768,-32768,-32768,    27,-32768
+};
+
+/* YYPGOTO[NTERM-NUM].  */
+static const short yypgoto[] =
+{
+  -32768,-32768,-32768,-32768,-32768,    83,-32768,-32768,-32768,-32768,
+  -32768,-32768,-32768,-32768,-32768,-32768,   -12,    53,-32768,    35,
+  -32768,-32768,-32768,     0,   -10,-32768,   -18,    34,-32768,-32768
+};
+
+/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
+   positive, shift that token.  If negative, reduce the rule which
+   number is the opposite.  If zero, do what YYDEFACT says.  */
+static const short yytable[] =
+{
+      43,     5,     6,     7,     8,     9,    10,     3,    11,    12,
+      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
+      23,    24,     5,     6,     7,     8,    37,    10,    25,    26,
+      40,    41,    27,    28,    29,     5,     6,     7,     8,    92,
+      10,    40,    41,    77,    40,    60,    76,    38,    51,    72,
+      61,    78,    78,    27,    28,    29,    39,    50,    85,    42,
+      90,    51,    91,    93,    45,    84,    27,    28,    29,    48,
+      42,    46,    47,    89,    56,    58,    70,    82,    71,    66,
+      67,    68,    97,    69,    79,    40,    86,    31,    73,    64,
+       0,    96
+};
+
+static const short yycheck[] =
+{
+      10,     6,     7,     8,     9,    10,    11,     0,    13,    14,
+      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
+      25,    26,     6,     7,     8,     9,    27,    11,    33,    34,
+       3,     4,    37,    38,    39,     6,     7,     8,     9,    12,
+      11,     3,     4,    61,     3,    27,     5,    36,    32,    33,
+      32,    63,    64,    37,    38,    39,     5,    23,    76,    32,
+      29,    32,    31,    36,    28,    75,    37,    38,    39,     3,
+      32,    28,    28,    83,    29,    27,    30,    35,    29,    45,
+      46,    47,    92,    49,    32,     3,    32,     4,    53,    36,
+      -1,    91
+};
+
+#if YYDEBUG
+/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
+   symbol of state STATE-NUM.  */
+static const unsigned char yystos[] =
+{
+       0,    41,    42,     0,    43,     6,     7,     8,     9,    10,
+      11,    13,    14,    15,    16,    17,    18,    19,    20,    21,
+      22,    23,    24,    25,    26,    33,    34,    37,    38,    39,
+      44,    45,    46,    50,    52,    48,    47,    27,    36,     5,
+       3,     4,    32,    64,    66,    28,    28,    28,     3,    67,
+      67,    32,    45,    58,    59,    60,    29,    69,    27,    53,
+      27,    32,    56,    57,    57,    49,    67,    67,    67,    67,
+      30,    29,    33,    59,    68,    51,     5,    66,    56,    32,
+      54,    61,    35,    55,    64,    66,    32,    62,    63,    64,
+      29,    31,    12,    36,    64,    65,    63,    64
+};
+#endif
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
 # define YYSIZE_T __SIZE_TYPE__
@@ -495,14 +622,19 @@ union yyalloc
 #define yyclearin	(yychar = YYEMPTY)
 #define YYEMPTY		-2
 #define YYEOF		0
+
 #define YYACCEPT	goto yyacceptlab
-#define YYABORT 	goto yyabortlab
+#define YYABORT		goto yyabortlab
 #define YYERROR		goto yyerrlab1
+
 /* Like YYERROR except do call yyerror.  This remains here temporarily
    to ease the transition to the new meaning of YYERROR, for GCC.
    Once GCC version 2 has supplanted version 1, this can go.  */
+
 #define YYFAIL		goto yyerrlab
+
 #define YYRECOVERING()  (!!yyerrstatus)
+
 #define YYBACKUP(Token, Value)					\
 do								\
   if (yychar == YYEMPTY && yylen == 1)				\
@@ -523,21 +655,17 @@ while (0)
 #define YYTERROR	1
 #define YYERRCODE	256
 
-
 /* YYLLOC_DEFAULT -- Compute the default location (before the actions
-   are run).
-
-   When YYLLOC_DEFAULT is run, CURRENT is set the location of the
-   first token.  By default, to implement support for ranges, extend
-   its range to the last symbol.  */
+   are run).  */
 
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(Current, Rhs, N)       	\
-   Current.last_line   = Rhs[N].last_line;	\
-   Current.last_column = Rhs[N].last_column;
+# define YYLLOC_DEFAULT(Current, Rhs, N)           \
+  Current.first_line   = Rhs[1].first_line;      \
+  Current.first_column = Rhs[1].first_column;    \
+  Current.last_line    = Rhs[N].last_line;       \
+  Current.last_column  = Rhs[N].last_column;
 #endif
 
-
 /* YYLEX -- calling `yylex' with the right arguments.  */
 
 #if YYPURE
@@ -558,7 +686,6 @@ while (0)
 # define YYLEX			yylex ()
 #endif /* !YYPURE */
 
-
 /* Enable debugging if requested.  */
 #if YYDEBUG
 
@@ -598,8 +725,10 @@ int yydebug;
 #ifndef YYMAXDEPTH
 # define YYMAXDEPTH 10000
 #endif
+
 
-#ifdef YYERROR_VERBOSE
+
+#if YYERROR_VERBOSE
 
 # ifndef yystrlen
 #  if defined (__GLIBC__) && defined (_STRING_H)
@@ -649,10 +778,10 @@ yystpcpy (yydest, yysrc)
 }
 #  endif
 # endif
-#endif
-
-#line 315 "/usr/share/bison/bison.simple"
 
+#endif /* !YYERROR_VERBOSE */
+
+
 
 /* The user can define YYPARSE_PARAM as the name of an argument to be passed
    into yyparse.  The argument should have type void *.
@@ -689,7 +818,7 @@ int yyparse (void);
 /* The lookahead symbol.  */				\
 int yychar;						\
 							\
-/* The semantic value of the lookahead symbol. */	\
+/* The semantic value of the lookahead symbol.  */	\
 YYSTYPE yylval;						\
 							\
 /* Number of parse errors so far.  */			\
@@ -706,8 +835,7 @@ YYLTYPE yylloc;
 YY_DECL_NON_LSP_VARIABLES
 #endif
 
-
-/* If nonreentrant, generate the variables here. */
+/* If nonreentrant, generate the variables here.  */
 
 #if !YYPURE
 YY_DECL_VARIABLES
@@ -717,7 +845,7 @@ int
 yyparse (YYPARSE_PARAM_ARG)
      YYPARSE_PARAM_DECL
 {
-  /* If reentrant, generate the variables here. */
+  /* If reentrant, generate the variables here.  */
 #if YYPURE
   YY_DECL_VARIABLES
 #endif  /* !YYPURE */
@@ -738,7 +866,7 @@ yyparse (YYPARSE_PARAM_ARG)
      Refer to the stacks thru separate pointers, to allow yyoverflow
      to reallocate them elsewhere.  */
 
-  /* The state stack. */
+  /* The state stack.  */
   short	yyssa[YYINITDEPTH];
   short *yyss = yyssa;
   register short *yyssp;
@@ -763,7 +891,6 @@ yyparse (YYPARSE_PARAM_ARG)
 
   YYSIZE_T yystacksize = YYINITDEPTH;
 
-
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;
@@ -772,7 +899,7 @@ yyparse (YYPARSE_PARAM_ARG)
 #endif
 
   /* When reducing, the number of symbols on the RHS of the reduced
-     rule. */
+     rule.  */
   int yylen;
 
   YYDPRINTF ((stderr, "Starting parse\n"));
@@ -859,10 +986,10 @@ yyparse (YYPARSE_PARAM_ARG)
 	  goto yyoverflowlab;
 	YYSTACK_RELOCATE (yyss);
 	YYSTACK_RELOCATE (yyvs);
-# if YYLSP_NEEDED
+#  if YYLSP_NEEDED
 	YYSTACK_RELOCATE (yyls);
-# endif
-# undef YYSTACK_RELOCATE
+#  endif
+#  undef YYSTACK_RELOCATE
 	if (yyss1 != yyssa)
 	  YYSTACK_FREE (yyss1);
       }
@@ -886,7 +1013,6 @@ yyparse (YYPARSE_PARAM_ARG)
 
   goto yybackup;
 
-
 /*-----------.
 | yybackup.  |
 `-----------*/
@@ -913,12 +1039,12 @@ yybackup:
       yychar = YYLEX;
     }
 
-  /* Convert token to internal form (in yychar1) for indexing tables with */
+  /* Convert token to internal form (in yychar1) for indexing tables with.  */
 
-  if (yychar <= 0)		/* This means end of input. */
+  if (yychar <= 0)		/* This means end of input.  */
     {
       yychar1 = 0;
-      yychar = YYEOF;		/* Don't call YYLEX any more */
+      yychar = YYEOF;		/* Don't call YYLEX any more.  */
 
       YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
@@ -1019,9 +1145,7 @@ yyreduce:
   yyval = yyvsp[1-yylen];
 
 #if YYLSP_NEEDED
-  /* Similarly for the default location.  Let the user run additional
-     commands if for instance locations are ranges.  */
-  yyloc = yylsp[1-yylen];
+  /* Default location. */
   YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
 #endif
 
@@ -1033,312 +1157,372 @@ yyreduce:
       int yyi;
 
       YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
-		 yyn, yyrline[yyn]);
+		 yyn - 1, yyrline[yyn]);
 
       /* Print the symbols being reduced, and their result.  */
-      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++)
+      for (yyi = yyprhs[yyn]; yyrhs[yyi] >= 0; yyi++)
 	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
       YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
     }
 #endif
-
-  switch (yyn) {
-
-case 1:
-#line 134 "parse-gram.y"
-{ LOCATION_RESET (yylloc); }
+  switch (yyn)
+    {
+        case 2:
+#line 131 "parse-gram.y"
+    { LOCATION_RESET (yylloc); }
     break;
-case 2:
-#line 136 "parse-gram.y"
-{
+
+  case 3:
+#line 133 "parse-gram.y"
+    {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
     }
     break;
-case 6:
+
+  case 7:
+#line 151 "parse-gram.y"
+    { prologue_augment (yyvsp[0].string, yylsp[0]); }
+    break;
+
+  case 8:
+#line 152 "parse-gram.y"
+    { debug_flag = 1; }
+    break;
+
+  case 9:
+#line 153 "parse-gram.y"
+    { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
+    break;
+
+  case 10:
 #line 154 "parse-gram.y"
-{ prologue_augment (yyvsp[0].string, yylsp[0]); }
+    { defines_flag = 1; }
     break;
-case 7:
+
+  case 11:
 #line 155 "parse-gram.y"
-{ debug_flag = 1; }
+    { error_verbose = 1; }
     break;
-case 8:
+
+  case 12:
 #line 156 "parse-gram.y"
-{ muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
+    { expected_conflicts = yyvsp[0].integer; }
     break;
-case 9:
+
+  case 13:
 #line 157 "parse-gram.y"
-{ defines_flag = 1; }
+    { spec_file_prefix = yyvsp[0].string; }
     break;
-case 10:
+
+  case 14:
 #line 158 "parse-gram.y"
-{ error_verbose = 1; }
+    { locations_flag = 1; }
     break;
-case 11:
+
+  case 15:
 #line 159 "parse-gram.y"
-{ expected_conflicts = yyvsp[0].integer; }
+    { spec_name_prefix = yyvsp[0].string; }
     break;
-case 12:
+
+  case 16:
 #line 160 "parse-gram.y"
-{ spec_file_prefix = yyvsp[0].string; }
+    { no_lines_flag = 1; }
     break;
-case 13:
+
+  case 17:
 #line 161 "parse-gram.y"
-{ locations_flag = 1; }
+    { spec_outfile = yyvsp[0].string; }
     break;
-case 14:
+
+  case 18:
 #line 162 "parse-gram.y"
-{ spec_name_prefix = yyvsp[0].string; }
+    { pure_parser = 1; }
     break;
-case 15:
+
+  case 19:
 #line 163 "parse-gram.y"
-{ no_lines_flag = 1; }
+    { skeleton = yyvsp[0].string; }
     break;
-case 16:
+
+  case 20:
 #line 164 "parse-gram.y"
-{ spec_outfile = yyvsp[0].string; }
+    { token_table_flag = 1; }
     break;
-case 17:
+
+  case 21:
 #line 165 "parse-gram.y"
-{ pure_parser = 1; }
+    { report_flag = 1; }
     break;
-case 18:
+
+  case 22:
 #line 166 "parse-gram.y"
-{ skeleton = yyvsp[0].string; }
-    break;
-case 19:
-#line 167 "parse-gram.y"
-{ token_table_flag = 1; }
-    break;
-case 20:
-#line 168 "parse-gram.y"
-{ report_flag = 1; }
+    { yacc_flag = 1; }
     break;
-case 21:
-#line 169 "parse-gram.y"
-{ yacc_flag = 1; }
-    break;
-case 24:
-#line 176 "parse-gram.y"
-{
+
+  case 25:
+#line 173 "parse-gram.y"
+    {
       grammar_start_symbol_set (yyvsp[0].symbol);
     }
     break;
-case 25:
-#line 180 "parse-gram.y"
-{
+
+  case 26:
+#line 177 "parse-gram.y"
+    {
       typed = 1;
-      MUSCLE_INSERT_INT ("stype_line", yylsp[-1].first_line);
-      muscle_insert ("stype", yyvsp[-1].string);
+      MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
+      muscle_insert ("stype", yyvsp[0].string);
     }
     break;
-case 26:
-#line 188 "parse-gram.y"
-{ current_class = nterm_sym; }
+
+  case 27:
+#line 185 "parse-gram.y"
+    { current_class = nterm_sym; }
     break;
-case 27:
-#line 189 "parse-gram.y"
-{
+
+  case 28:
+#line 186 "parse-gram.y"
+    {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
-case 28:
-#line 193 "parse-gram.y"
-{ current_class = token_sym; }
+
+  case 29:
+#line 190 "parse-gram.y"
+    { current_class = token_sym; }
     break;
-case 29:
-#line 194 "parse-gram.y"
-{
+
+  case 30:
+#line 191 "parse-gram.y"
+    {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
-case 30:
-#line 198 "parse-gram.y"
-{current_type = yyvsp[0].string; }
+
+  case 31:
+#line 195 "parse-gram.y"
+    {current_type = yyvsp[0].string; }
     break;
-case 31:
-#line 199 "parse-gram.y"
-{
+
+  case 32:
+#line 196 "parse-gram.y"
+    {
       current_type = NULL;
     }
     break;
-case 32:
-#line 206 "parse-gram.y"
-{ current_assoc = yyvsp[-1].assoc; ++current_prec; }
+
+  case 33:
+#line 203 "parse-gram.y"
+    { current_assoc = yyvsp[-1].assoc; ++current_prec; }
     break;
-case 33:
-#line 208 "parse-gram.y"
-{ current_assoc = non_assoc; current_type = NULL; }
+
+  case 34:
+#line 205 "parse-gram.y"
+    { current_assoc = non_assoc; current_type = NULL; }
     break;
-case 34:
+
+  case 35:
 #line 212 "parse-gram.y"
-{ yyval.assoc = left_assoc; }
+    { yyval.assoc = left_assoc; }
     break;
-case 35:
+
+  case 36:
 #line 213 "parse-gram.y"
-{ yyval.assoc = right_assoc; }
+    { yyval.assoc = right_assoc; }
     break;
-case 36:
+
+  case 37:
 #line 214 "parse-gram.y"
-{ yyval.assoc = non_assoc; }
+    { yyval.assoc = non_assoc; }
     break;
-case 37:
+
+  case 38:
 #line 218 "parse-gram.y"
-{ current_type = NULL;}
+    { current_type = NULL;}
     break;
-case 38:
+
+  case 39:
 #line 219 "parse-gram.y"
-{ current_type = yyvsp[0].string; }
+    { current_type = yyvsp[0].string; }
     break;
-case 39:
+
+  case 40:
 #line 224 "parse-gram.y"
-{ symbol_type_set (yyvsp[0].symbol, current_type); }
+    { symbol_type_set (yyvsp[0].symbol, current_type); }
     break;
-case 40:
+
+  case 41:
 #line 225 "parse-gram.y"
-{ symbol_type_set (yyvsp[0].symbol, current_type); }
+    { symbol_type_set (yyvsp[0].symbol, current_type); }
     break;
-case 41:
+
+  case 42:
 #line 231 "parse-gram.y"
-{
+    {
       symbol_type_set (yyvsp[0].symbol, current_type);
       symbol_precedence_set (yyvsp[0].symbol, current_prec, current_assoc);
     }
     break;
-case 42:
+
+  case 43:
 #line 236 "parse-gram.y"
-{
+    {
       symbol_type_set (yyvsp[0].symbol, current_type);
       symbol_precedence_set (yyvsp[0].symbol, current_prec, current_assoc);
     }
     break;
-case 43:
+
+  case 44:
 #line 245 "parse-gram.y"
-{
+    {
        current_type = yyvsp[0].string;
      }
     break;
-case 44:
+
+  case 45:
 #line 249 "parse-gram.y"
-{
+    {
        symbol_class_set (yyvsp[0].symbol, current_class);
        symbol_type_set (yyvsp[0].symbol, current_type);
      }
     break;
-case 45:
+
+  case 46:
 #line 254 "parse-gram.y"
-{
+    {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, current_type);
       symbol_user_token_number_set (yyvsp[-1].symbol, yyvsp[0].integer);
     }
     break;
-case 46:
+
+  case 47:
 #line 260 "parse-gram.y"
-{
+    {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, current_type);
       symbol_make_alias (yyvsp[-1].symbol, yyvsp[0].symbol);
     }
     break;
-case 47:
+
+  case 48:
 #line 266 "parse-gram.y"
-{
+    {
       symbol_class_set (yyvsp[-2].symbol, current_class);
       symbol_type_set (yyvsp[-2].symbol, current_type);
       symbol_user_token_number_set (yyvsp[-2].symbol, yyvsp[-1].integer);
       symbol_make_alias (yyvsp[-2].symbol, yyvsp[0].symbol);
     }
     break;
-case 48:
+
+  case 49:
 #line 277 "parse-gram.y"
-{;}
+    {;}
     break;
-case 49:
+
+  case 50:
 #line 279 "parse-gram.y"
-{;}
+    {;}
     break;
-case 52:
-#line 293 "parse-gram.y"
-{ current_lhs = yyvsp[-1].symbol; }
+
+  case 55:
+#line 301 "parse-gram.y"
+    { current_lhs = yyvsp[-1].symbol; }
     break;
-case 53:
-#line 294 "parse-gram.y"
-{;}
+
+  case 56:
+#line 302 "parse-gram.y"
+    {;}
     break;
-case 54:
-#line 298 "parse-gram.y"
-{ grammar_rule_end (); }
+
+  case 57:
+#line 306 "parse-gram.y"
+    { grammar_rule_end (); }
     break;
-case 55:
-#line 299 "parse-gram.y"
-{ grammar_rule_end (); }
+
+  case 58:
+#line 307 "parse-gram.y"
+    { grammar_rule_end (); }
     break;
-case 56:
-#line 304 "parse-gram.y"
-{ grammar_rule_begin (current_lhs); }
+
+  case 59:
+#line 312 "parse-gram.y"
+    { grammar_rule_begin (current_lhs); }
     break;
-case 57:
-#line 306 "parse-gram.y"
-{ grammar_current_rule_symbol_append (yyvsp[0].symbol); }
+
+  case 60:
+#line 314 "parse-gram.y"
+    { grammar_current_rule_symbol_append (yyvsp[0].symbol); }
     break;
-case 58:
-#line 308 "parse-gram.y"
-{ grammar_current_rule_action_append (yyvsp[0].string, yylsp[0].first_line); }
+
+  case 61:
+#line 316 "parse-gram.y"
+    { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0].first_line); }
     break;
-case 59:
-#line 310 "parse-gram.y"
-{ grammar_current_rule_prec_set (yyvsp[0].symbol); }
+
+  case 62:
+#line 318 "parse-gram.y"
+    { grammar_current_rule_prec_set (yyvsp[0].symbol); }
     break;
-case 60:
-#line 314 "parse-gram.y"
-{ yyval.symbol = yyvsp[0].symbol; }
+
+  case 63:
+#line 322 "parse-gram.y"
+    { yyval.symbol = yyvsp[0].symbol; }
     break;
-case 61:
-#line 315 "parse-gram.y"
-{ yyval.symbol = yyvsp[0].symbol; }
+
+  case 64:
+#line 323 "parse-gram.y"
+    { yyval.symbol = yyvsp[0].symbol; }
     break;
-case 62:
-#line 316 "parse-gram.y"
-{ yyval.symbol = getsym (yyvsp[0].string); }
+
+  case 65:
+#line 324 "parse-gram.y"
+    { yyval.symbol = getsym (yyvsp[0].string); }
     break;
-case 63:
-#line 321 "parse-gram.y"
-{ yyval.string = yyvsp[0].string; }
+
+  case 66:
+#line 329 "parse-gram.y"
+    { yyval.string = yyvsp[0].string; }
     break;
-case 64:
-#line 327 "parse-gram.y"
-{
+
+  case 67:
+#line 335 "parse-gram.y"
+    {
       yyval.symbol = getsym (yyvsp[0].string);
       symbol_class_set (yyval.symbol, token_sym);
     }
     break;
-case 65:
-#line 336 "parse-gram.y"
-{
+
+  case 68:
+#line 344 "parse-gram.y"
+    {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
     }
     break;
-case 66:
-#line 344 "parse-gram.y"
-{
+
+  case 69:
+#line 352 "parse-gram.y"
+    {
       yyval.string = xstrdup ("");
     }
     break;
-case 67:
-#line 348 "parse-gram.y"
-{
+
+  case 70:
+#line 356 "parse-gram.y"
+    {
       yyval.string = yyvsp[0].string;
     }
     break;
-}
 
-#line 705 "/usr/share/bison/bison.simple"
 
+    }
+
+/* Line 1012 of /home/akim/src/bison/data/bison.simple.  */
+#line 1526 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1368,11 +1552,11 @@ case 67:
 
   yyn = yyr1[yyn];
 
-  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
+  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
   if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
     yystate = yytable[yystate];
   else
-    yystate = yydefgoto[yyn - YYNTBASE];
+    yystate = yydefgoto[yyn - YYNTOKENS];
 
   goto yynewstate;
 
@@ -1386,7 +1570,7 @@ yyerrlab:
     {
       ++yynerrs;
 
-#ifdef YYERROR_VERBOSE
+#if YYERROR_VERBOSE
       yyn = yypact[yystate];
 
       if (yyn > YYFLAG && yyn < YYLAST)
@@ -1426,27 +1610,27 @@ yyerrlab:
 		}
 	      yyerror (yymsg);
 	      YYSTACK_FREE (yymsg);
-	    }
-	  else
-	    yyerror ("parse error; also virtual memory exhausted");
-	}
+  	    }
+  	  else
+  	    yyerror ("parse error; also virtual memory exhausted");
+        }
       else
-#endif /* defined (YYERROR_VERBOSE) */
-	yyerror ("parse error");
+#endif /* YYERROR_VERBOSE */
+        yyerror ("parse error");
     }
   goto yyerrlab1;
 
 
-/*--------------------------------------------------.
-| yyerrlab1 -- error raised explicitly by an action |
-`--------------------------------------------------*/
+/*----------------------------------------------------.
+| yyerrlab1 -- error raised explicitly by an action.  |
+`----------------------------------------------------*/
 yyerrlab1:
   if (yyerrstatus == 3)
     {
       /* If just tried and failed to reuse lookahead token after an
 	 error, discard it.  */
 
-      /* return failure if at end of input */
+      /* Return failure if at end of input.  */
       if (yychar == YYEOF)
 	YYABORT;
       YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
@@ -1457,73 +1641,63 @@ yyerrlab1:
   /* Else will try to reuse lookahead token after shifting the error
      token.  */
 
-  yyerrstatus = 3;		/* Each real token shifted decrements this */
-
-  goto yyerrhandle;
+  yyerrstatus = 3;	/* Each real token shifted decrements this.  */
 
+  for (;;)
+    {
+      yyn = yypact[yystate];
+      if (yyn != YYFLAG)
+	{
+	  yyn += YYTERROR;
+	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
+	    {
+	      yyn = yytable[yyn];
+	      if (0 < yyn)
+		break;
+	    }
+	}
 
-/*-------------------------------------------------------------------.
-| yyerrdefault -- current state does not do anything special for the |
-| error token.                                                       |
-`-------------------------------------------------------------------*/
-yyerrdefault:
-#if 0
-  /* This is wrong; only states that explicitly want error tokens
-     should shift them.  */
+      /* Pop the current state because it cannot handle the error token.  */
+      if (yyssp == yyss)
+	YYABORT;
 
-  /* If its default is to accept any token, ok.  Otherwise pop it.  */
-  yyn = yydefact[yystate];
-  if (yyn)
-    goto yydefault;
+#if YYDEBUG
+      if (yydebug)
+	{
+	  if (yystos[yystate] < YYNTOKENS)
+	    {
+	      YYFPRINTF (stderr, "Error: popping token %d (%s",
+			 yytoknum[yystos[yystate]], yytname[yystos[yystate]]);
+# ifdef YYPRINT
+	      YYPRINT (stderr, yytoknum[yystos[yystate]], *yyvsp);
+# endif
+	      YYFPRINTF (stderr, ")\n");
+	    }
+	  else
+	    {
+	      YYFPRINTF (stderr, "Error: popping nonterminal (%s)\n",
+			 yytname[yystos[yystate]]);
+	    }
+	}
 #endif
 
-
-/*---------------------------------------------------------------.
-| yyerrpop -- pop the current state because it cannot handle the |
-| error token                                                    |
-`---------------------------------------------------------------*/
-yyerrpop:
-  if (yyssp == yyss)
-    YYABORT;
-  yyvsp--;
-  yystate = *--yyssp;
+      yyvsp--;
+      yystate = *--yyssp;
 #if YYLSP_NEEDED
-  yylsp--;
+      yylsp--;
 #endif
 
 #if YYDEBUG
-  if (yydebug)
-    {
-      short *yyssp1 = yyss - 1;
-      YYFPRINTF (stderr, "Error: state stack now");
-      while (yyssp1 != yyssp)
-	YYFPRINTF (stderr, " %d", *++yyssp1);
-      YYFPRINTF (stderr, "\n");
-    }
+      if (yydebug)
+	{
+	  short *yyssp1 = yyss - 1;
+	  YYFPRINTF (stderr, "Error: state stack now");
+	  while (yyssp1 != yyssp)
+	    YYFPRINTF (stderr, " %d", *++yyssp1);
+	  YYFPRINTF (stderr, "\n");
+	}
 #endif
-
-/*--------------.
-| yyerrhandle.  |
-`--------------*/
-yyerrhandle:
-  yyn = yypact[yystate];
-  if (yyn == YYFLAG)
-    goto yyerrdefault;
-
-  yyn += YYTERROR;
-  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
-    goto yyerrdefault;
-
-  yyn = yytable[yyn];
-  if (yyn < 0)
-    {
-      if (yyn == YYFLAG)
-	goto yyerrpop;
-      yyn = -yyn;
-      goto yyreduce;
     }
-  else if (yyn == 0)
-    goto yyerrpop;
 
   if (yyn == YYFINAL)
     YYACCEPT;
@@ -1568,7 +1742,8 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 357 "parse-gram.y"
+
+#line 365 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
@@ -1618,3 +1793,4 @@ gram_error (gram_control_t *control ATTRIBUTE_UNUSED,
   LOCATION_PRINT (stderr, *yylloc);
   fprintf (stderr, ": %s\n", msg);
 }
+
