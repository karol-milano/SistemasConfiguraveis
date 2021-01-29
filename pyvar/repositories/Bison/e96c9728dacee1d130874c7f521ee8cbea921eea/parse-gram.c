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
+
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
@@ -90,10 +100,114 @@ symbol_t *current_lhs;
 associativity current_assoc;
 int current_prec = 0;
 
-#line 72 "parse-gram.y"
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
+     PERCENT_LEFT = 267,
+     PERCENT_RIGHT = 268,
+     PERCENT_NONASSOC = 269,
+     PERCENT_PREC = 270,
+     PERCENT_VERBOSE = 271,
+     PERCENT_ERROR_VERBOSE = 272,
+     PERCENT_OUTPUT = 273,
+     PERCENT_FILE_PREFIX = 274,
+     PERCENT_NAME_PREFIX = 275,
+     PERCENT_DEFINE = 276,
+     PERCENT_PURE_PARSER = 277,
+     PERCENT_DEFINES = 278,
+     PERCENT_YACC = 279,
+     PERCENT_DEBUG = 280,
+     PERCENT_LOCATIONS = 281,
+     PERCENT_NO_LINES = 282,
+     PERCENT_SKELETON = 283,
+     PERCENT_TOKEN_TABLE = 284,
+     TYPE = 285,
+     EQUAL = 286,
+     SEMICOLON = 287,
+     COLON = 288,
+     PIPE = 289,
+     ID = 290,
+     PERCENT_PERCENT = 291,
+     PROLOGUE = 292,
+     EPILOGUE = 293,
+     BRACED_CODE = 294
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
+#define PERCENT_LEFT 267
+#define PERCENT_RIGHT 268
+#define PERCENT_NONASSOC 269
+#define PERCENT_PREC 270
+#define PERCENT_VERBOSE 271
+#define PERCENT_ERROR_VERBOSE 272
+#define PERCENT_OUTPUT 273
+#define PERCENT_FILE_PREFIX 274
+#define PERCENT_NAME_PREFIX 275
+#define PERCENT_DEFINE 276
+#define PERCENT_PURE_PARSER 277
+#define PERCENT_DEFINES 278
+#define PERCENT_YACC 279
+#define PERCENT_DEBUG 280
+#define PERCENT_LOCATIONS 281
+#define PERCENT_NO_LINES 282
+#define PERCENT_SKELETON 283
+#define PERCENT_TOKEN_TABLE 284
+#define TYPE 285
+#define EQUAL 286
+#define SEMICOLON 287
+#define COLON 288
+#define PIPE 289
+#define ID 290
+#define PERCENT_PERCENT 291
+#define PROLOGUE 292
+#define EPILOGUE 293
+#define BRACED_CODE 294
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
+#line 73 "parse-gram.y"
+typedef union {
   symbol_t *symbol;
   int integer;
   char *string;
@@ -108,282 +222,20 @@ typedef struct yyltype
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
+/* Copy the second part of user declarations.  */
 
 
-#define	YYFINAL		94
-#define	YYFLAG		-32768
-#define	YYNTBASE	41
+/* Line 217 of /usr/local/share/bison/bison.simple.  */
+#line 237 "parse-gram.c"
 
-/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */
-#define YYTRANSLATE(x) ((unsigned)(x) <= 293 ? yytranslate[x] : 68)
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
-      51,    53,    55,    57,    58,    62,    65,    66,    70,    71,
-      76,    80,    81,    86,    88,    90,    92,    93,    95,    97,
-     100,   102,   105,   107,   109,   112,   115,   119,   121,   124,
-     126,   129,   130,   136,   138,   142,   143,   146,   149,   153,
-     155,   157,   159,   161,   163,   165,   166,   169,   170
-};
-static const short yyrhs[] =
-{
-      -1,    42,    43,    37,    57,    66,     0,     0,    43,    44,
-       0,    45,     0,    38,     0,    26,     0,    22,    65,    65,
-       0,    24,     0,    18,     0,    11,     6,     0,    20,    32,
-      65,     0,    27,     0,    21,    32,    65,     0,    28,     0,
-      19,    32,    65,     0,    23,     0,    29,    65,     0,    30,
-       0,    17,     0,    25,     0,    49,     0,     0,     8,    46,
-      56,     0,    12,    62,     0,     0,     7,    47,    56,     0,
-       0,     9,    31,    48,    53,     0,    10,    40,    67,     0,
-       0,    51,    52,    50,    54,     0,    13,     0,    14,     0,
-      15,     0,     0,    31,     0,    36,     0,    53,    36,     0,
-      62,     0,    54,    62,     0,    31,     0,    36,     0,    36,
-       6,     0,    36,    64,     0,    36,     6,    64,     0,    55,
-       0,    56,    55,     0,    58,     0,    57,    58,     0,     0,
-      36,    34,    59,    60,    33,     0,    61,     0,    60,    35,
-      61,     0,     0,    61,    62,     0,    61,    63,     0,    61,
-      16,    62,     0,    36,     0,    64,     0,     5,     0,    40,
-       0,     4,     0,     4,     0,     0,    37,    39,     0,     0,
-      33,     0
-};
-
-#endif
-
-#if YYDEBUG
-/* YYRLINE[YYN] -- source line where rule number YYN was defined. */
-static const short yyrline[] =
-{
-       0,   131,   131,   139,   141,   144,   146,   150,   151,   152,
-     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
-     163,   164,   167,   169,   169,   174,   178,   178,   183,   183,
-     187,   195,   195,   202,   204,   205,   208,   210,   214,   216,
-     220,   226,   235,   240,   245,   251,   257,   267,   270,   274,
-     276,   279,   279,   284,   286,   289,   292,   294,   296,   300,
-     302,   303,   306,   312,   321,   329,   334,   340,   342
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
-  "PROLOGUE", "EPILOGUE", "BRACED_CODE", "input", "@1", "directives", 
-  "directive", "grammar_directives", "@2", "@3", "@4", 
-  "precedence_directives", "@5", "precedence_directive", "type.opt", 
-  "nterms_to_type.1", "terms_to_prec.1", "symbol_def", "symbol_defs.1", 
-  "gram", "rules", "@6", "rhses.1", "rhs", "symbol", "action", 
-  "string_as_id", "string_content", "epilogue.opt", "semi_colon_opt", 0
-};
-#endif
-
-/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives. */
-static const short yyr1[] =
-{
-       0,    42,    41,    43,    43,    44,    44,    44,    44,    44,
-      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
-      44,    44,    45,    46,    45,    45,    47,    45,    48,    45,
-      45,    50,    49,    51,    51,    51,    52,    52,    53,    53,
-      54,    54,    55,    55,    55,    55,    55,    56,    56,    57,
-      57,    59,    58,    60,    60,    61,    61,    61,    61,    62,
-      62,    62,    63,    64,    65,    66,    66,    67,    67
-};
-
-/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN. */
-static const short yyr2[] =
-{
-       0,     0,     5,     0,     2,     1,     1,     1,     3,     1,
-       1,     2,     3,     1,     3,     1,     3,     1,     2,     1,
-       1,     1,     1,     0,     3,     2,     0,     3,     0,     4,
-       3,     0,     4,     1,     1,     1,     0,     1,     1,     2,
-       1,     2,     1,     1,     2,     2,     3,     1,     2,     1,
-       2,     0,     5,     1,     3,     0,     2,     2,     3,     1,
-       1,     1,     1,     1,     1,     0,     2,     0,     1
-};
-
-/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
-   doesn't specify something else to do.  Zero means the default is an
-   error. */
-static const short yydefact[] =
-{
-       1,     3,     0,    26,    23,     0,     0,     0,     0,    33,
-      34,    35,    20,    10,     0,     0,     0,     0,    17,     9,
-      21,     7,    13,    15,     0,    19,     0,     6,     4,     5,
-      22,    36,     0,     0,    28,    67,    11,    63,    61,    59,
-      25,    60,     0,     0,     0,    64,     0,    18,     0,    65,
-      49,    37,    31,    42,    43,    47,    27,    24,     0,    68,
-      30,    16,    12,    14,     8,    51,     0,    50,     2,     0,
-      44,    45,    48,    38,    29,    55,    66,    32,    40,    46,
-      39,     0,    53,    41,    52,    55,     0,    62,    56,    57,
-      54,    58,     0,     0,     0
-};
-
-static const short yydefgoto[] =
-{
-      92,     1,     2,    28,    29,    33,    32,    58,    30,    69,
-      31,    52,    74,    77,    55,    56,    49,    50,    75,    81,
-      82,    88,    89,    41,    46,    68,    60
-};
-
-static const short yypact[] =
-{
-  -32768,-32768,    72,-32768,-32768,   -22,   -29,     8,    -1,-32768,
-  -32768,-32768,-32768,-32768,   -16,   -14,   -11,    22,-32768,-32768,
-  -32768,-32768,-32768,-32768,    22,-32768,    -6,-32768,-32768,-32768,
-  -32768,     0,   -24,   -24,-32768,     1,-32768,-32768,-32768,-32768,
-  -32768,-32768,    22,    22,    22,-32768,    22,-32768,    -2,   -17,
-  -32768,-32768,-32768,-32768,     4,-32768,   -24,   -24,     2,-32768,
-  -32768,-32768,-32768,-32768,-32768,-32768,     3,-32768,-32768,    -1,
-      32,-32768,-32768,-32768,     5,-32768,-32768,    -1,-32768,-32768,
-  -32768,   -18,    -3,-32768,-32768,-32768,    -1,-32768,-32768,-32768,
-      -3,-32768,    39,    40,-32768
-};
-
-static const short yypgoto[] =
-{
-  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-  -32768,-32768,-32768,-32768,   -28,    10,-32768,    -5,-32768,-32768,
-     -40,    -8,-32768,   -48,   -19,-32768,-32768
-};
-
-
-#define	YYLAST		110
-
-
-static const short yytable[] =
-{
-      40,    37,    38,    37,    38,    47,    71,    53,    37,    34,
-      70,    35,    54,    86,    36,    84,    42,    85,    43,    48,
-      66,    44,    79,    61,    62,    63,    45,    64,    72,    72,
-      48,    51,    65,    39,    59,    39,    37,    87,    73,    93,
-      94,    80,    76,    57,    67,    90,     0,     0,     0,     0,
-       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,    78,     0,     0,     0,     0,     0,     0,     0,    83,
-       0,     0,     0,     0,     0,     0,     0,     0,    91,     3,
-       4,     5,     6,     7,     8,     9,    10,    11,     0,    12,
-      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
-      23,    24,    25,     0,     0,     0,     0,     0,     0,    26,
-      27
-};
-
-static const short yycheck[] =
-{
-       8,     4,     5,     4,     5,    24,    54,    31,     4,    31,
-       6,    40,    36,    16,     6,    33,    32,    35,    32,    36,
-      37,    32,    70,    42,    43,    44,     4,    46,    56,    57,
-      36,    31,    34,    36,    33,    36,     4,    40,    36,     0,
-       0,    36,    39,    33,    49,    85,    -1,    -1,    -1,    -1,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
-      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,     7,
-       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
-      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
-      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    37,
-      38
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
-
-/* This is the parser code that is written into each bison parser when
-   the %semantic_parser declaration is not specified in the grammar.
-   It was written by Richard Stallman by simplifying the hairy parser
-   used when %semantic_parser is specified.  */
-
-/* All symbols defined below should begin with yy or YY, to avoid
-   infringing on user name space.  This should be done even for local
-   variables, as they might otherwise be expanded by user macros.
-   There are some unavoidable exceptions within include files to
-   define necessary library symbols; they are noted "INFRINGES ON
-   USER NAME SPACE" below.  */
-
-#if ! defined (yyoverflow) || defined (YYERROR_VERBOSE)
+#if ! defined (yyoverflow) || YYERROR_VERBOSE
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
 
@@ -412,7 +264,7 @@ static const short yycheck[] =
 #  define YYSTACK_ALLOC malloc
 #  define YYSTACK_FREE free
 # endif
-#endif /* ! defined (yyoverflow) || defined (YYERROR_VERBOSE) */
+#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */
 
 
 #if (! defined (yyoverflow) \
@@ -456,7 +308,7 @@ union yyalloc
 	{					\
 	  register YYSIZE_T yyi;		\
 	  for (yyi = 0; yyi < (Count); yyi++)	\
-	    (To)[yyi] = (From)[yyi];		\
+	    (To)[yyi] = (From)[yyi];	\
 	}					\
       while (0)
 #  endif
@@ -480,6 +332,270 @@ union yyalloc
 
 #endif
 
+/* YYFINAL -- State number of the termination state. */
+#define YYFINAL  3
+#define YYFLAG	 -32768
+#define YYLAST   110
+
+/* YYNTOKENS -- Number of terminals. */
+#define YYNTOKENS  40
+/* YYNNTS -- Number of nonterminals. */
+#define YYNNTS  28
+/* YYNRULES -- Number of rules. */
+#define YYNRULES  69
+/* YYNRULES -- Number of states. */
+#define YYNSTATES  94
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
+       0,     0,     3,     4,    10,    11,    14,    16,    18,    20,
+      24,    26,    28,    31,    35,    37,    41,    43,    47,    49,
+      52,    54,    56,    58,    60,    61,    65,    68,    69,    73,
+      74,    79,    83,    84,    89,    91,    93,    95,    96,    98,
+     100,   103,   105,   108,   110,   112,   115,   118,   122,   124,
+     127,   129,   132,   133,   139,   141,   145,   146,   149,   152,
+     156,   158,   160,   162,   164,   166,   168,   169,   172,   173
+};
+
+/* YYRHS -- A `-1'-separated list of the rules' RHS. */
+static const signed char yyrhs[] =
+{
+      41,     0,    -1,    -1,    42,    43,    36,    57,    66,    -1,
+      -1,    43,    44,    -1,    45,    -1,    37,    -1,    25,    -1,
+      21,    65,    65,    -1,    23,    -1,    17,    -1,    10,     5,
+      -1,    19,    31,    65,    -1,    26,    -1,    20,    31,    65,
+      -1,    27,    -1,    18,    31,    65,    -1,    22,    -1,    28,
+      65,    -1,    29,    -1,    16,    -1,    24,    -1,    49,    -1,
+      -1,     7,    46,    56,    -1,    11,    62,    -1,    -1,     6,
+      47,    56,    -1,    -1,     8,    30,    48,    53,    -1,     9,
+      39,    67,    -1,    -1,    51,    52,    50,    54,    -1,    12,
+      -1,    13,    -1,    14,    -1,    -1,    30,    -1,    35,    -1,
+      53,    35,    -1,    62,    -1,    54,    62,    -1,    30,    -1,
+      35,    -1,    35,     5,    -1,    35,    64,    -1,    35,     5,
+      64,    -1,    55,    -1,    56,    55,    -1,    58,    -1,    57,
+      58,    -1,    -1,    35,    33,    59,    60,    32,    -1,    61,
+      -1,    60,    34,    61,    -1,    -1,    61,    62,    -1,    61,
+      63,    -1,    61,    15,    62,    -1,    35,    -1,    64,    -1,
+       4,    -1,    39,    -1,     3,    -1,     3,    -1,    -1,    36,
+      38,    -1,    -1,    32,    -1
+};
+
+/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
+static const unsigned short yyrline[] =
+{
+       0,   131,   131,   131,   139,   141,   144,   146,   150,   151,
+     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
+     162,   163,   164,   167,   169,   169,   174,   178,   178,   183,
+     183,   187,   195,   195,   202,   204,   205,   208,   210,   214,
+     216,   220,   226,   235,   240,   245,   251,   257,   267,   270,
+     274,   276,   279,   279,   284,   286,   289,   292,   294,   296,
+     300,   302,   303,   306,   312,   321,   329,   334,   340,   342
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
+  "\"%start\"", "\"%left\"", "\"%right\"", "\"%nonassoc\"", "\"%prec\"", 
+  "\"%verbose\"", "\"%error-verbose\"", "\"%output\"", "\"%file-prefix\"", 
+  "\"%name-prefix\"", "\"%define\"", "\"%pure-parser\"", "\"%defines\"", 
+  "\"%yacc\"", "\"%debug\"", "\"%locations\"", "\"%no-lines\"", 
+  "\"%skeleton\"", "\"%token-table\"", "TYPE", "\"=\"", "\";\"", "\":\"", 
+  "\"|\"", "\"identifier\"", "\"%%\"", "PROLOGUE", "EPILOGUE", 
+  "BRACED_CODE", "$axiom", "input", "@1", "directives", "directive", 
+  "grammar_directives", "@2", "@3", "@4", "precedence_directives", "@5", 
+  "precedence_directive", "type.opt", "nterms_to_type.1", 
+  "terms_to_prec.1", "symbol_def", "symbol_defs.1", "gram", "rules", "@6", 
+  "rhses.1", "rhs", "symbol", "action", "string_as_id", "string_content", 
+  "epilogue.opt", "semi_colon_opt", 0
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
+      44,    44,    44,    45,    46,    45,    45,    47,    45,    48,
+      45,    45,    50,    49,    51,    51,    51,    52,    52,    53,
+      53,    54,    54,    55,    55,    55,    55,    55,    56,    56,
+      57,    57,    59,    58,    60,    60,    61,    61,    61,    61,
+      62,    62,    62,    63,    64,    65,    66,    66,    67,    67
+};
+
+/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
+static const unsigned char yyr2[] =
+{
+       0,     2,     0,     5,     0,     2,     1,     1,     1,     3,
+       1,     1,     2,     3,     1,     3,     1,     3,     1,     2,
+       1,     1,     1,     1,     0,     3,     2,     0,     3,     0,
+       4,     3,     0,     4,     1,     1,     1,     0,     1,     1,
+       2,     1,     2,     1,     1,     2,     2,     3,     1,     2,
+       1,     2,     0,     5,     1,     3,     0,     2,     2,     3,
+       1,     1,     1,     1,     1,     1,     0,     2,     0,     1
+};
+
+/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
+   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
+   means the default is an error.  */
+static const short yydefact[] =
+{
+       2,     0,     4,     0,     0,    27,    24,     0,     0,     0,
+       0,    34,    35,    36,    21,    11,     0,     0,     0,     0,
+      18,    10,    22,     8,    14,    16,     0,    20,     0,     7,
+       5,     6,    23,    37,     0,     0,    29,    68,    12,    64,
+      62,    60,    26,    61,     0,     0,     0,    65,     0,    19,
+       0,    66,    50,    38,    32,    43,    44,    48,    28,    25,
+       0,    69,    31,    17,    13,    15,     9,    52,     0,    51,
+       3,     0,    45,    46,    49,    39,    30,    56,    67,    33,
+      41,    47,    40,     0,    54,    42,    53,    56,     0,    63,
+      57,    58,    55,    59
+};
+
+/* YYPGOTO[NTERM-NUM]. */
+static const short yydefgoto[] =
+{
+      -1,     1,     2,     4,    30,    31,    35,    34,    60,    32,
+      71,    33,    54,    76,    79,    57,    58,    51,    52,    77,
+      83,    84,    90,    91,    43,    48,    70,    62
+};
+
+/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
+   STATE-NUM.  */
+static const short yypact[] =
+{
+  -32768,     9,-32768,-32768,    73,-32768,-32768,   -19,   -24,    12,
+       0,-32768,-32768,-32768,-32768,-32768,    -5,    -3,    -1,    26,
+  -32768,-32768,-32768,-32768,-32768,-32768,    26,-32768,    -4,-32768,
+  -32768,-32768,-32768,     2,   -23,   -23,-32768,     4,-32768,-32768,
+  -32768,-32768,-32768,-32768,    26,    26,    26,-32768,    26,-32768,
+       1,   -17,-32768,-32768,-32768,-32768,     5,-32768,   -23,   -23,
+       3,-32768,-32768,-32768,-32768,-32768,-32768,-32768,     6,-32768,
+  -32768,     0,    36,-32768,-32768,-32768,     7,-32768,-32768,     0,
+  -32768,-32768,-32768,   -18,    -2,-32768,-32768,-32768,     0,-32768,
+  -32768,-32768,    -2,-32768
+};
+
+/* YYPGOTO[NTERM-NUM].  */
+static const short yypgoto[] =
+{
+  -32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
+  -32768,-32768,-32768,-32768,-32768,   -38,     8,-32768,   -11,-32768,
+  -32768,   -46,   -10,-32768,   -50,   -21,-32768,-32768
+};
+
+/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
+   positive, shift that token.  If negative, reduce the rule which
+   number is the opposite.  If zero, do what YYDEFACT says.  */
+static const short yytable[] =
+{
+      42,    39,    40,    39,    40,    49,    73,    55,    39,     3,
+      72,    36,    56,    88,    86,    37,    87,    38,    50,    68,
+      74,    74,    81,    63,    64,    65,    44,    66,    45,    47,
+      46,    50,    53,    41,    67,    41,    61,    89,    75,    39,
+      69,    92,    82,    59,    78,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,    80,     0,     0,     0,     0,     0,     0,     0,    85,
+       0,     0,     0,     0,     0,     0,     0,     0,    93,     5,
+       6,     7,     8,     9,    10,    11,    12,    13,     0,    14,
+      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
+      25,    26,    27,     0,     0,     0,     0,     0,     0,    28,
+      29
+};
+
+static const short yycheck[] =
+{
+      10,     3,     4,     3,     4,    26,    56,    30,     3,     0,
+       5,    30,    35,    15,    32,    39,    34,     5,    35,    36,
+      58,    59,    72,    44,    45,    46,    31,    48,    31,     3,
+      31,    35,    30,    35,    33,    35,    32,    39,    35,     3,
+      51,    87,    35,    35,    38,    -1,    -1,    -1,    -1,    -1,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
+      -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
+      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,     6,
+       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
+      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
+      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    36,
+      37
+};
+
+#if YYDEBUG
+/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
+   symbol of state STATE-NUM.  */
+static const unsigned char yystos[] =
+{
+       0,    41,    42,     0,    43,     6,     7,     8,     9,    10,
+      11,    12,    13,    14,    16,    17,    18,    19,    20,    21,
+      22,    23,    24,    25,    26,    27,    28,    29,    36,    37,
+      44,    45,    49,    51,    47,    46,    30,    39,     5,     3,
+       4,    35,    62,    64,    31,    31,    31,     3,    65,    65,
+      35,    57,    58,    30,    52,    30,    35,    55,    56,    56,
+      48,    32,    67,    65,    65,    65,    65,    33,    36,    58,
+      66,    50,     5,    64,    55,    35,    53,    59,    38,    54,
+      62,    64,    35,    60,    61,    62,    32,    34,    15,    39,
+      62,    63,    61,    62
+};
+#endif
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
 # define YYSIZE_T __SIZE_TYPE__
@@ -501,14 +617,19 @@ union yyalloc
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
@@ -529,21 +650,17 @@ while (0)
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
@@ -564,7 +681,6 @@ while (0)
 # define YYLEX			yylex ()
 #endif /* !YYPURE */
 
-
 /* Enable debugging if requested.  */
 #if YYDEBUG
 
@@ -604,8 +720,10 @@ int yydebug;
 #ifndef YYMAXDEPTH
 # define YYMAXDEPTH 10000
 #endif
+
 
-#ifdef YYERROR_VERBOSE
+
+#if YYERROR_VERBOSE
 
 # ifndef yystrlen
 #  if defined (__GLIBC__) && defined (_STRING_H)
@@ -655,10 +773,10 @@ yystpcpy (yydest, yysrc)
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
@@ -695,7 +813,7 @@ int yyparse (void);
 /* The lookahead symbol.  */				\
 int yychar;						\
 							\
-/* The semantic value of the lookahead symbol. */	\
+/* The semantic value of the lookahead symbol.  */	\
 YYSTYPE yylval;						\
 							\
 /* Number of parse errors so far.  */			\
@@ -712,8 +830,7 @@ YYLTYPE yylloc;
 YY_DECL_NON_LSP_VARIABLES
 #endif
 
-
-/* If nonreentrant, generate the variables here. */
+/* If nonreentrant, generate the variables here.  */
 
 #if !YYPURE
 YY_DECL_VARIABLES
@@ -723,7 +840,7 @@ int
 yyparse (YYPARSE_PARAM_ARG)
      YYPARSE_PARAM_DECL
 {
-  /* If reentrant, generate the variables here. */
+  /* If reentrant, generate the variables here.  */
 #if YYPURE
   YY_DECL_VARIABLES
 #endif  /* !YYPURE */
@@ -744,7 +861,7 @@ yyparse (YYPARSE_PARAM_ARG)
      Refer to the stacks thru separate pointers, to allow yyoverflow
      to reallocate them elsewhere.  */
 
-  /* The state stack. */
+  /* The state stack.  */
   short	yyssa[YYINITDEPTH];
   short *yyss = yyssa;
   register short *yyssp;
@@ -769,7 +886,6 @@ yyparse (YYPARSE_PARAM_ARG)
 
   YYSIZE_T yystacksize = YYINITDEPTH;
 
-
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;
@@ -778,7 +894,7 @@ yyparse (YYPARSE_PARAM_ARG)
 #endif
 
   /* When reducing, the number of symbols on the RHS of the reduced
-     rule. */
+     rule.  */
   int yylen;
 
   YYDPRINTF ((stderr, "Starting parse\n"));
@@ -865,10 +981,10 @@ yyparse (YYPARSE_PARAM_ARG)
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
@@ -892,7 +1008,6 @@ yyparse (YYPARSE_PARAM_ARG)
 
   goto yybackup;
 
-
 /*-----------.
 | yybackup.  |
 `-----------*/
@@ -919,12 +1034,12 @@ yybackup:
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
@@ -1025,9 +1140,7 @@ yyreduce:
   yyval = yyvsp[1-yylen];
 
 #if YYLSP_NEEDED
-  /* Similarly for the default location.  Let the user run additional
-     commands if for instance locations are ranges.  */
-  yyloc = yylsp[1-yylen];
+  /* Default location. */
   YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
 #endif
 
@@ -1039,314 +1152,374 @@ yyreduce:
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
+  switch (yyn)
+    {
+        case 2:
 #line 131 "parse-gram.y"
-{ LOCATION_RESET (yylloc); }
+    { LOCATION_RESET (yylloc); }
     break;
-case 2:
+
+  case 3:
 #line 133 "parse-gram.y"
-{
+    {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0].first_line);
     }
     break;
-case 6:
+
+  case 7:
 #line 147 "parse-gram.y"
-{
+    {
      prologue_augment (yyvsp[0].string, yylsp[0].first_line);
    }
     break;
-case 7:
+
+  case 8:
 #line 150 "parse-gram.y"
-{ debug_flag = 1; }
+    { debug_flag = 1; }
     break;
-case 8:
+
+  case 9:
 #line 151 "parse-gram.y"
-{ muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
+    { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
-case 9:
+
+  case 10:
 #line 152 "parse-gram.y"
-{ defines_flag = 1; }
+    { defines_flag = 1; }
     break;
-case 10:
+
+  case 11:
 #line 153 "parse-gram.y"
-{ error_verbose = 1; }
+    { error_verbose = 1; }
     break;
-case 11:
+
+  case 12:
 #line 154 "parse-gram.y"
-{ expected_conflicts = yyvsp[0].integer; }
+    { expected_conflicts = yyvsp[0].integer; }
     break;
-case 12:
+
+  case 13:
 #line 155 "parse-gram.y"
-{ spec_file_prefix = yyvsp[0].string; }
+    { spec_file_prefix = yyvsp[0].string; }
     break;
-case 13:
+
+  case 14:
 #line 156 "parse-gram.y"
-{ locations_flag = 1; }
+    { locations_flag = 1; }
     break;
-case 14:
+
+  case 15:
 #line 157 "parse-gram.y"
-{ spec_name_prefix = yyvsp[0].string; }
+    { spec_name_prefix = yyvsp[0].string; }
     break;
-case 15:
+
+  case 16:
 #line 158 "parse-gram.y"
-{ no_lines_flag = 1; }
+    { no_lines_flag = 1; }
     break;
-case 16:
+
+  case 17:
 #line 159 "parse-gram.y"
-{ spec_outfile = yyvsp[0].string; }
+    { spec_outfile = yyvsp[0].string; }
     break;
-case 17:
+
+  case 18:
 #line 160 "parse-gram.y"
-{ pure_parser = 1; }
+    { pure_parser = 1; }
     break;
-case 18:
+
+  case 19:
 #line 161 "parse-gram.y"
-{ skeleton = yyvsp[0].string; }
+    { skeleton = yyvsp[0].string; }
     break;
-case 19:
+
+  case 20:
 #line 162 "parse-gram.y"
-{ token_table_flag = 1; }
+    { token_table_flag = 1; }
     break;
-case 20:
+
+  case 21:
 #line 163 "parse-gram.y"
-{ report_flag = 1; }
+    { report_flag = 1; }
     break;
-case 21:
+
+  case 22:
 #line 164 "parse-gram.y"
-{ yacc_flag = 1; }
+    { yacc_flag = 1; }
     break;
-case 23:
+
+  case 24:
 #line 169 "parse-gram.y"
-{ current_class = nterm_sym; }
+    { current_class = nterm_sym; }
     break;
-case 24:
+
+  case 25:
 #line 170 "parse-gram.y"
-{
+    {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
-case 25:
+
+  case 26:
 #line 175 "parse-gram.y"
-{
+    {
       grammar_start_symbol_set (yyvsp[0].symbol);
     }
     break;
-case 26:
+
+  case 27:
 #line 178 "parse-gram.y"
-{ current_class = token_sym; }
+    { current_class = token_sym; }
     break;
-case 27:
+
+  case 28:
 #line 179 "parse-gram.y"
-{
+    {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
-case 28:
+
+  case 29:
 #line 183 "parse-gram.y"
-{current_type = yyvsp[0].string; }
+    {current_type = yyvsp[0].string; }
     break;
-case 29:
+
+  case 30:
 #line 184 "parse-gram.y"
-{
+    {
       current_type = NULL;
     }
     break;
-case 30:
+
+  case 31:
 #line 188 "parse-gram.y"
-{
+    {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[-1].first_line);
       muscle_insert ("stype", yyvsp[-1].string);
     }
     break;
-case 31:
+
+  case 32:
 #line 197 "parse-gram.y"
-{ current_assoc = yyvsp[-1].assoc; ++current_prec; }
+    { current_assoc = yyvsp[-1].assoc; ++current_prec; }
     break;
-case 32:
+
+  case 33:
 #line 199 "parse-gram.y"
-{ current_assoc = non_assoc; current_type = NULL; }
+    { current_assoc = non_assoc; current_type = NULL; }
     break;
-case 33:
+
+  case 34:
 #line 203 "parse-gram.y"
-{ yyval.assoc = left_assoc; }
+    { yyval.assoc = left_assoc; }
     break;
-case 34:
+
+  case 35:
 #line 204 "parse-gram.y"
-{ yyval.assoc = right_assoc; }
+    { yyval.assoc = right_assoc; }
     break;
-case 35:
+
+  case 36:
 #line 205 "parse-gram.y"
-{ yyval.assoc = non_assoc; }
+    { yyval.assoc = non_assoc; }
     break;
-case 36:
+
+  case 37:
 #line 209 "parse-gram.y"
-{ current_type = NULL;}
+    { current_type = NULL;}
     break;
-case 37:
+
+  case 38:
 #line 210 "parse-gram.y"
-{ current_type = yyvsp[0].string; }
+    { current_type = yyvsp[0].string; }
     break;
-case 38:
+
+  case 39:
 #line 215 "parse-gram.y"
-{ symbol_type_set (yyvsp[0].symbol, current_type); }
+    { symbol_type_set (yyvsp[0].symbol, current_type); }
     break;
-case 39:
+
+  case 40:
 #line 216 "parse-gram.y"
-{ symbol_type_set (yyvsp[0].symbol, current_type); }
+    { symbol_type_set (yyvsp[0].symbol, current_type); }
     break;
-case 40:
+
+  case 41:
 #line 222 "parse-gram.y"
-{
+    {
       symbol_type_set (yyvsp[0].symbol, current_type);
       symbol_precedence_set (yyvsp[0].symbol, current_prec, current_assoc);
     }
     break;
-case 41:
+
+  case 42:
 #line 227 "parse-gram.y"
-{
+    {
       symbol_type_set (yyvsp[0].symbol, current_type);
       symbol_precedence_set (yyvsp[0].symbol, current_prec, current_assoc);
     }
     break;
-case 42:
+
+  case 43:
 #line 237 "parse-gram.y"
-{
+    {
        current_type = yyvsp[0].string;
      }
     break;
-case 43:
+
+  case 44:
 #line 241 "parse-gram.y"
-{
+    {
        symbol_class_set (yyvsp[0].symbol, current_class);
        symbol_type_set (yyvsp[0].symbol, current_type);
      }
     break;
-case 44:
+
+  case 45:
 #line 246 "parse-gram.y"
-{
+    {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, current_type);
       symbol_user_token_number_set (yyvsp[-1].symbol, yyvsp[0].integer);
     }
     break;
-case 45:
+
+  case 46:
 #line 252 "parse-gram.y"
-{
+    {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, current_type);
       symbol_make_alias (yyvsp[-1].symbol, yyvsp[0].symbol);
     }
     break;
-case 46:
+
+  case 47:
 #line 258 "parse-gram.y"
-{
+    {
       symbol_class_set (yyvsp[-2].symbol, current_class);
       symbol_type_set (yyvsp[-2].symbol, current_type);
       symbol_user_token_number_set (yyvsp[-2].symbol, yyvsp[-1].integer);
       symbol_make_alias (yyvsp[-2].symbol, yyvsp[0].symbol);
     }
     break;
-case 47:
+
+  case 48:
 #line 269 "parse-gram.y"
-{;}
+    {;}
     break;
-case 48:
+
+  case 49:
 #line 271 "parse-gram.y"
-{;}
+    {;}
     break;
-case 51:
+
+  case 52:
 #line 280 "parse-gram.y"
-{ current_lhs = yyvsp[-1].symbol; }
+    { current_lhs = yyvsp[-1].symbol; }
     break;
-case 52:
+
+  case 53:
 #line 281 "parse-gram.y"
-{;}
+    {;}
     break;
-case 53:
+
+  case 54:
 #line 285 "parse-gram.y"
-{ grammar_rule_end (); }
+    { grammar_rule_end (); }
     break;
-case 54:
+
+  case 55:
 #line 286 "parse-gram.y"
-{ grammar_rule_end (); }
+    { grammar_rule_end (); }
     break;
-case 55:
+
+  case 56:
 #line 291 "parse-gram.y"
-{ grammar_rule_begin (current_lhs); }
+    { grammar_rule_begin (current_lhs); }
     break;
-case 56:
+
+  case 57:
 #line 293 "parse-gram.y"
-{ grammar_current_rule_symbol_append (yyvsp[0].symbol); }
+    { grammar_current_rule_symbol_append (yyvsp[0].symbol); }
     break;
-case 57:
+
+  case 58:
 #line 295 "parse-gram.y"
-{ grammar_current_rule_action_append (yyvsp[0].string, yylsp[0].first_line); }
+    { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0].first_line); }
     break;
-case 58:
+
+  case 59:
 #line 297 "parse-gram.y"
-{ grammar_current_rule_prec_set (yyvsp[0].symbol); }
+    { grammar_current_rule_prec_set (yyvsp[0].symbol); }
     break;
-case 59:
+
+  case 60:
 #line 301 "parse-gram.y"
-{ yyval.symbol = yyvsp[0].symbol; }
+    { yyval.symbol = yyvsp[0].symbol; }
     break;
-case 60:
+
+  case 61:
 #line 302 "parse-gram.y"
-{ yyval.symbol = yyvsp[0].symbol; }
+    { yyval.symbol = yyvsp[0].symbol; }
     break;
-case 61:
+
+  case 62:
 #line 303 "parse-gram.y"
-{ yyval.symbol = getsym (yyvsp[0].string); }
+    { yyval.symbol = getsym (yyvsp[0].string); }
     break;
-case 62:
+
+  case 63:
 #line 308 "parse-gram.y"
-{ yyval.string = yyvsp[0].string; }
+    { yyval.string = yyvsp[0].string; }
     break;
-case 63:
+
+  case 64:
 #line 314 "parse-gram.y"
-{
+    {
       yyval.symbol = getsym (yyvsp[0].string);
       symbol_class_set (yyval.symbol, token_sym);
     }
     break;
-case 64:
+
+  case 65:
 #line 323 "parse-gram.y"
-{
+    {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
     }
     break;
-case 65:
+
+  case 66:
 #line 331 "parse-gram.y"
-{
+    {
       yyval.string = xstrdup ("");
     }
     break;
-case 66:
+
+  case 67:
 #line 335 "parse-gram.y"
-{
+    {
       yyval.string = yyvsp[0].string;
     }
     break;
-}
 
-#line 705 "/usr/share/bison/bison.simple"
 
+    }
+
+/* Line 1010 of /usr/local/share/bison/bison.simple.  */
+#line 1523 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1376,11 +1549,11 @@ case 66:
 
   yyn = yyr1[yyn];
 
-  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
+  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
   if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
     yystate = yytable[yystate];
   else
-    yystate = yydefgoto[yyn - YYNTBASE];
+    yystate = yydefgoto[yyn - YYNTOKENS];
 
   goto yynewstate;
 
@@ -1394,7 +1567,7 @@ yyerrlab:
     {
       ++yynerrs;
 
-#ifdef YYERROR_VERBOSE
+#if YYERROR_VERBOSE
       yyn = yypact[yystate];
 
       if (yyn > YYFLAG && yyn < YYLAST)
@@ -1434,27 +1607,27 @@ yyerrlab:
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
@@ -1465,73 +1638,63 @@ yyerrlab1:
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
@@ -1576,6 +1739,7 @@ yyreturn:
 #endif
   return yyresult;
 }
+
 #line 344 "parse-gram.y"
 
 /*------------------------------------------------------------------.
@@ -1626,3 +1790,4 @@ gram_error (gram_control_t *control ATTRIBUTE_UNUSED,
   LOCATION_PRINT (stderr, *yylloc);
   fprintf (stderr, ": %s\n", msg);
 }
+
