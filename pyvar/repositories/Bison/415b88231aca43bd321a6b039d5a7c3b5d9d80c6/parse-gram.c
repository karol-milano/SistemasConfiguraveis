@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.5.1.779-71bff.  */
+/* A Bison parser, made by GNU Bison 2.5.1.815-22b0.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.5.1.779-71bff"
+#define YYBISON_VERSION "2.5.1.815-22b0"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -58,9 +58,6 @@
 /* Pull parsers.  */
 #define YYPULL 1
 
-/* Using locations.  */
-#define YYLSP_NEEDED 1
-
 /* Substitute the variable and function names.  */
 #define yyparse         gram_parse
 #define yylex           gram_lex
@@ -72,7 +69,7 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 324 of yacc.c  */
+/* Line 328 of yacc.c  */
 #line 1 "src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -127,8 +124,8 @@ static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
 
-/* Line 324 of yacc.c  */
-#line 132 "src/parse-gram.c"
+/* Line 328 of yacc.c  */
+#line 129 "src/parse-gram.c"
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -146,17 +143,224 @@ static char const *char_name (char);
 # define YYERROR_VERBOSE 1
 #endif
 
-/* Enabling the token table.  */
-#ifndef YYTOKEN_TABLE
-# define YYTOKEN_TABLE 0
+/* In a future release of Bison, this section will be replaced
+   by #include "src/parse-gram.h".  */
+#ifndef GRAM_Y_TAB_H
+# define GRAM_Y_TAB_H
+/* Enabling traces.  */
+#ifndef YYDEBUG
+# define YYDEBUG 1
+#endif
+#if YYDEBUG
+extern int gram_debug;
+#endif
+/* "%code requires" blocks.  */
+/* Line 342 of yacc.c  */
+#line 221 "src/parse-gram.y"
+
+# ifndef PARAM_TYPE
+#  define PARAM_TYPE
+  typedef enum
+  {
+    param_none   = 0,
+    param_lex    = 1 << 0,
+    param_parse  = 1 << 1,
+    param_both   = param_lex | param_parse
+  } param_type;
+# endif
+
+
+/* Line 342 of yacc.c  */
+#line 175 "src/parse-gram.c"
+
+/* Tokens.  */
+#ifndef YYTOKENTYPE
+# define YYTOKENTYPE
+   /* Put the tokens into the symbol table, so that GDB and other debuggers
+      know about them.  */
+   enum yytokentype {
+     GRAM_EOF = 0,
+     STRING = 258,
+     INT = 259,
+     PERCENT_TOKEN = 260,
+     PERCENT_NTERM = 261,
+     PERCENT_TYPE = 262,
+     PERCENT_DESTRUCTOR = 263,
+     PERCENT_PRINTER = 264,
+     PERCENT_LEFT = 265,
+     PERCENT_RIGHT = 266,
+     PERCENT_NONASSOC = 267,
+     PERCENT_PRECEDENCE = 268,
+     PERCENT_PREC = 269,
+     PERCENT_DPREC = 270,
+     PERCENT_MERGE = 271,
+     PERCENT_CODE = 272,
+     PERCENT_DEFAULT_PREC = 273,
+     PERCENT_DEFINE = 274,
+     PERCENT_DEFINES = 275,
+     PERCENT_ERROR_VERBOSE = 276,
+     PERCENT_EXPECT = 277,
+     PERCENT_EXPECT_RR = 278,
+     PERCENT_FLAG = 279,
+     PERCENT_FILE_PREFIX = 280,
+     PERCENT_GLR_PARSER = 281,
+     PERCENT_INITIAL_ACTION = 282,
+     PERCENT_LANGUAGE = 283,
+     PERCENT_NAME_PREFIX = 284,
+     PERCENT_NO_DEFAULT_PREC = 285,
+     PERCENT_NO_LINES = 286,
+     PERCENT_NONDETERMINISTIC_PARSER = 287,
+     PERCENT_OUTPUT = 288,
+     PERCENT_REQUIRE = 289,
+     PERCENT_SKELETON = 290,
+     PERCENT_START = 291,
+     PERCENT_TOKEN_TABLE = 292,
+     PERCENT_VERBOSE = 293,
+     PERCENT_YACC = 294,
+     BRACED_CODE = 295,
+     BRACED_PREDICATE = 296,
+     BRACKETED_ID = 297,
+     CHAR = 298,
+     EPILOGUE = 299,
+     EQUAL = 300,
+     ID = 301,
+     ID_COLON = 302,
+     PERCENT_PERCENT = 303,
+     PIPE = 304,
+     PROLOGUE = 305,
+     SEMICOLON = 306,
+     TAG = 307,
+     TAG_ANY = 308,
+     TAG_NONE = 309,
+     PERCENT_PARAM = 310,
+     PERCENT_UNION = 311
+   };
+#endif
+/* Tokens.  */
+#define GRAM_EOF 0
+#define STRING 258
+#define INT 259
+#define PERCENT_TOKEN 260
+#define PERCENT_NTERM 261
+#define PERCENT_TYPE 262
+#define PERCENT_DESTRUCTOR 263
+#define PERCENT_PRINTER 264
+#define PERCENT_LEFT 265
+#define PERCENT_RIGHT 266
+#define PERCENT_NONASSOC 267
+#define PERCENT_PRECEDENCE 268
+#define PERCENT_PREC 269
+#define PERCENT_DPREC 270
+#define PERCENT_MERGE 271
+#define PERCENT_CODE 272
+#define PERCENT_DEFAULT_PREC 273
+#define PERCENT_DEFINE 274
+#define PERCENT_DEFINES 275
+#define PERCENT_ERROR_VERBOSE 276
+#define PERCENT_EXPECT 277
+#define PERCENT_EXPECT_RR 278
+#define PERCENT_FLAG 279
+#define PERCENT_FILE_PREFIX 280
+#define PERCENT_GLR_PARSER 281
+#define PERCENT_INITIAL_ACTION 282
+#define PERCENT_LANGUAGE 283
+#define PERCENT_NAME_PREFIX 284
+#define PERCENT_NO_DEFAULT_PREC 285
+#define PERCENT_NO_LINES 286
+#define PERCENT_NONDETERMINISTIC_PARSER 287
+#define PERCENT_OUTPUT 288
+#define PERCENT_REQUIRE 289
+#define PERCENT_SKELETON 290
+#define PERCENT_START 291
+#define PERCENT_TOKEN_TABLE 292
+#define PERCENT_VERBOSE 293
+#define PERCENT_YACC 294
+#define BRACED_CODE 295
+#define BRACED_PREDICATE 296
+#define BRACKETED_ID 297
+#define CHAR 298
+#define EPILOGUE 299
+#define EQUAL 300
+#define ID 301
+#define ID_COLON 302
+#define PERCENT_PERCENT 303
+#define PIPE 304
+#define PROLOGUE 305
+#define SEMICOLON 306
+#define TAG 307
+#define TAG_ANY 308
+#define TAG_NONE 309
+#define PERCENT_PARAM 310
+#define PERCENT_UNION 311
+
+
+
+#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
+typedef union YYSTYPE
+{
+/* Line 342 of yacc.c  */
+#line 107 "src/parse-gram.y"
+
+  assoc assoc;
+  char *code;
+  char const *chars;
+  int integer;
+  named_ref *named_ref;
+  symbol *symbol;
+  symbol_list *list;
+  uniqstr uniqstr;
+  unsigned char character;
+
+/* Line 342 of yacc.c  */
+#line 245 "src/parse-gram.y"
+
+  param_type param;
+
+
+/* Line 342 of yacc.c  */
+#line 322 "src/parse-gram.c"
+} YYSTYPE;
+# define YYSTYPE_IS_TRIVIAL 1
+# define yystype YYSTYPE /* obsolescent; will be withdrawn */
+# define YYSTYPE_IS_DECLARED 1
+#endif
+
+#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
+typedef struct YYLTYPE
+{
+  int first_line;
+  int first_column;
+  int last_line;
+  int last_column;
+} YYLTYPE;
+# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
+# define YYLTYPE_IS_DECLARED 1
+# define YYLTYPE_IS_TRIVIAL 1
+#endif
+
+
+#ifdef YYPARSE_PARAM
+#if (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
+int gram_parse (void *YYPARSE_PARAM);
+#else
+int gram_parse ();
 #endif
+#else /* ! YYPARSE_PARAM */
+#if (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
+int gram_parse (void);
+#else
+int gram_parse ();
+#endif
+#endif /* ! YYPARSE_PARAM */
 
-#include "src/parse-gram.h"
+#endif /* !GRAM_Y_TAB_H  */
 
 /* Copy the second part of user declarations.  */
 
 /* Line 345 of yacc.c  */
-#line 160 "src/parse-gram.c"
+#line 364 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
 /* Line 346 of yacc.c  */
 #line 56 "src/parse-gram.y"
@@ -205,7 +409,7 @@ static char const *char_name (char);
 
 
 /* Line 346 of yacc.c  */
-#line 209 "src/parse-gram.c"
+#line 413 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -479,7 +683,7 @@ static const yytype_uint16 yyrline[] =
 };
 #endif
 
-#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
+#if YYDEBUG || YYERROR_VERBOSE || 1
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
@@ -856,7 +1060,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 194 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
 /* Line 754 of yacc.c  */
-#line 860 "src/parse-gram.c"
+#line 1064 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
@@ -865,7 +1069,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 207 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
 /* Line 754 of yacc.c  */
-#line 869 "src/parse-gram.c"
+#line 1073 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
@@ -874,7 +1078,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 203 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 754 of yacc.c  */
-#line 878 "src/parse-gram.c"
+#line 1082 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
@@ -883,7 +1087,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 754 of yacc.c  */
-#line 887 "src/parse-gram.c"
+#line 1091 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
@@ -892,7 +1096,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 201 "src/parse-gram.y"
         { fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); }
 /* Line 754 of yacc.c  */
-#line 896 "src/parse-gram.c"
+#line 1100 "src/parse-gram.c"
         break;
 
             case 43: // "char"
@@ -901,7 +1105,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 188 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
 /* Line 754 of yacc.c  */
-#line 905 "src/parse-gram.c"
+#line 1109 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
@@ -910,7 +1114,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 754 of yacc.c  */
-#line 914 "src/parse-gram.c"
+#line 1118 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
@@ -919,7 +1123,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 200 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 754 of yacc.c  */
-#line 923 "src/parse-gram.c"
+#line 1127 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
@@ -928,7 +1132,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 202 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 754 of yacc.c  */
-#line 932 "src/parse-gram.c"
+#line 1136 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
@@ -937,7 +1141,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 754 of yacc.c  */
-#line 941 "src/parse-gram.c"
+#line 1145 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
@@ -946,7 +1150,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 204 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 754 of yacc.c  */
-#line 950 "src/parse-gram.c"
+#line 1154 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
@@ -966,7 +1170,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     }
 }
 /* Line 754 of yacc.c  */
-#line 970 "src/parse-gram.c"
+#line 1174 "src/parse-gram.c"
         break;
 
             case 72: // symbol.prec
@@ -975,7 +1179,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 754 of yacc.c  */
-#line 979 "src/parse-gram.c"
+#line 1183 "src/parse-gram.c"
         break;
 
             case 85: // variable
@@ -984,7 +1188,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 200 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 754 of yacc.c  */
-#line 988 "src/parse-gram.c"
+#line 1192 "src/parse-gram.c"
         break;
 
             case 86: // content.opt
@@ -993,7 +1197,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 754 of yacc.c  */
-#line 997 "src/parse-gram.c"
+#line 1201 "src/parse-gram.c"
         break;
 
             case 87: // braceless
@@ -1002,7 +1206,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 754 of yacc.c  */
-#line 1006 "src/parse-gram.c"
+#line 1210 "src/parse-gram.c"
         break;
 
             case 88: // id
@@ -1011,7 +1215,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 754 of yacc.c  */
-#line 1015 "src/parse-gram.c"
+#line 1219 "src/parse-gram.c"
         break;
 
             case 89: // id_colon
@@ -1020,7 +1224,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 211 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 754 of yacc.c  */
-#line 1024 "src/parse-gram.c"
+#line 1228 "src/parse-gram.c"
         break;
 
             case 90: // symbol
@@ -1029,7 +1233,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 754 of yacc.c  */
-#line 1033 "src/parse-gram.c"
+#line 1237 "src/parse-gram.c"
         break;
 
             case 91: // string_as_id
@@ -1038,7 +1242,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 754 of yacc.c  */
-#line 1042 "src/parse-gram.c"
+#line 1246 "src/parse-gram.c"
         break;
 
       default:
@@ -1824,7 +2028,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1519 of yacc.c  */
-#line 1828 "src/parse-gram.c"
+#line 2032 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2029,7 +2233,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1735 of yacc.c  */
-#line 2033 "src/parse-gram.c"
+#line 2237 "src/parse-gram.c"
     break;
 
   case 7:
@@ -2039,7 +2243,7 @@ yyreduce:
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
 /* Line 1735 of yacc.c  */
-#line 2043 "src/parse-gram.c"
+#line 2247 "src/parse-gram.c"
     break;
 
   case 8:
@@ -2050,7 +2254,7 @@ yyreduce:
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1735 of yacc.c  */
-#line 2054 "src/parse-gram.c"
+#line 2258 "src/parse-gram.c"
     break;
 
   case 9:
@@ -2058,7 +2262,7 @@ yyreduce:
 #line 304 "src/parse-gram.y"
     { defines_flag = true; }
 /* Line 1735 of yacc.c  */
-#line 2062 "src/parse-gram.c"
+#line 2266 "src/parse-gram.c"
     break;
 
   case 10:
@@ -2069,7 +2273,7 @@ yyreduce:
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 /* Line 1735 of yacc.c  */
-#line 2073 "src/parse-gram.c"
+#line 2277 "src/parse-gram.c"
     break;
 
   case 11:
@@ -2080,7 +2284,7 @@ yyreduce:
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1735 of yacc.c  */
-#line 2084 "src/parse-gram.c"
+#line 2288 "src/parse-gram.c"
     break;
 
   case 12:
@@ -2088,7 +2292,7 @@ yyreduce:
 #line 315 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1735 of yacc.c  */
-#line 2092 "src/parse-gram.c"
+#line 2296 "src/parse-gram.c"
     break;
 
   case 13:
@@ -2096,7 +2300,7 @@ yyreduce:
 #line 316 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1735 of yacc.c  */
-#line 2100 "src/parse-gram.c"
+#line 2304 "src/parse-gram.c"
     break;
 
   case 14:
@@ -2104,7 +2308,7 @@ yyreduce:
 #line 317 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1735 of yacc.c  */
-#line 2108 "src/parse-gram.c"
+#line 2312 "src/parse-gram.c"
     break;
 
   case 15:
@@ -2112,7 +2316,7 @@ yyreduce:
 #line 318 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1735 of yacc.c  */
-#line 2116 "src/parse-gram.c"
+#line 2320 "src/parse-gram.c"
     break;
 
   case 16:
@@ -2123,7 +2327,7 @@ yyreduce:
       glr_parser = true;
     }
 /* Line 1735 of yacc.c  */
-#line 2127 "src/parse-gram.c"
+#line 2331 "src/parse-gram.c"
     break;
 
   case 17:
@@ -2138,7 +2342,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1735 of yacc.c  */
-#line 2142 "src/parse-gram.c"
+#line 2346 "src/parse-gram.c"
     break;
 
   case 18:
@@ -2146,7 +2350,7 @@ yyreduce:
 #line 333 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1735 of yacc.c  */
-#line 2150 "src/parse-gram.c"
+#line 2354 "src/parse-gram.c"
     break;
 
   case 19:
@@ -2154,7 +2358,7 @@ yyreduce:
 #line 334 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1735 of yacc.c  */
-#line 2158 "src/parse-gram.c"
+#line 2362 "src/parse-gram.c"
     break;
 
   case 20:
@@ -2162,7 +2366,7 @@ yyreduce:
 #line 335 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1735 of yacc.c  */
-#line 2166 "src/parse-gram.c"
+#line 2370 "src/parse-gram.c"
     break;
 
   case 21:
@@ -2170,7 +2374,7 @@ yyreduce:
 #line 336 "src/parse-gram.y"
     { no_lines_flag = true; }
 /* Line 1735 of yacc.c  */
-#line 2174 "src/parse-gram.c"
+#line 2378 "src/parse-gram.c"
     break;
 
   case 22:
@@ -2178,7 +2382,7 @@ yyreduce:
 #line 337 "src/parse-gram.y"
     { nondeterministic_parser = true; }
 /* Line 1735 of yacc.c  */
-#line 2182 "src/parse-gram.c"
+#line 2386 "src/parse-gram.c"
     break;
 
   case 23:
@@ -2186,7 +2390,7 @@ yyreduce:
 #line 338 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1735 of yacc.c  */
-#line 2190 "src/parse-gram.c"
+#line 2394 "src/parse-gram.c"
     break;
 
   case 24:
@@ -2194,7 +2398,7 @@ yyreduce:
 #line 339 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1735 of yacc.c  */
-#line 2198 "src/parse-gram.c"
+#line 2402 "src/parse-gram.c"
     break;
 
   case 25:
@@ -2202,7 +2406,7 @@ yyreduce:
 #line 340 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
 /* Line 1735 of yacc.c  */
-#line 2206 "src/parse-gram.c"
+#line 2410 "src/parse-gram.c"
     break;
 
   case 26:
@@ -2210,7 +2414,7 @@ yyreduce:
 #line 340 "src/parse-gram.y"
     { current_param = param_none; }
 /* Line 1735 of yacc.c  */
-#line 2214 "src/parse-gram.c"
+#line 2418 "src/parse-gram.c"
     break;
 
   case 27:
@@ -2218,7 +2422,7 @@ yyreduce:
 #line 341 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1735 of yacc.c  */
-#line 2222 "src/parse-gram.c"
+#line 2426 "src/parse-gram.c"
     break;
 
   case 28:
@@ -2248,7 +2452,7 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1735 of yacc.c  */
-#line 2252 "src/parse-gram.c"
+#line 2456 "src/parse-gram.c"
     break;
 
   case 29:
@@ -2256,7 +2460,7 @@ yyreduce:
 #line 366 "src/parse-gram.y"
     { token_table_flag = true; }
 /* Line 1735 of yacc.c  */
-#line 2260 "src/parse-gram.c"
+#line 2464 "src/parse-gram.c"
     break;
 
   case 30:
@@ -2264,7 +2468,7 @@ yyreduce:
 #line 367 "src/parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1735 of yacc.c  */
-#line 2268 "src/parse-gram.c"
+#line 2472 "src/parse-gram.c"
     break;
 
   case 31:
@@ -2272,7 +2476,7 @@ yyreduce:
 #line 368 "src/parse-gram.y"
     { yacc_flag = true; }
 /* Line 1735 of yacc.c  */
-#line 2276 "src/parse-gram.c"
+#line 2480 "src/parse-gram.c"
     break;
 
   case 33:
@@ -2280,7 +2484,7 @@ yyreduce:
 #line 373 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2284 "src/parse-gram.c"
+#line 2488 "src/parse-gram.c"
     break;
 
   case 34:
@@ -2288,7 +2492,7 @@ yyreduce:
 #line 374 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2292 "src/parse-gram.c"
+#line 2496 "src/parse-gram.c"
     break;
 
   case 37:
@@ -2298,7 +2502,7 @@ yyreduce:
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1735 of yacc.c  */
-#line 2302 "src/parse-gram.c"
+#line 2506 "src/parse-gram.c"
     break;
 
   case 38:
@@ -2311,7 +2515,7 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1735 of yacc.c  */
-#line 2315 "src/parse-gram.c"
+#line 2519 "src/parse-gram.c"
     break;
 
   case 39:
@@ -2324,7 +2528,7 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1735 of yacc.c  */
-#line 2328 "src/parse-gram.c"
+#line 2532 "src/parse-gram.c"
     break;
 
   case 40:
@@ -2334,7 +2538,7 @@ yyreduce:
       default_prec = true;
     }
 /* Line 1735 of yacc.c  */
-#line 2338 "src/parse-gram.c"
+#line 2542 "src/parse-gram.c"
     break;
 
   case 41:
@@ -2344,7 +2548,7 @@ yyreduce:
       default_prec = false;
     }
 /* Line 1735 of yacc.c  */
-#line 2348 "src/parse-gram.c"
+#line 2552 "src/parse-gram.c"
     break;
 
   case 42:
@@ -2357,7 +2561,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1735 of yacc.c  */
-#line 2361 "src/parse-gram.c"
+#line 2565 "src/parse-gram.c"
     break;
 
   case 43:
@@ -2368,7 +2572,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1735 of yacc.c  */
-#line 2372 "src/parse-gram.c"
+#line 2576 "src/parse-gram.c"
     break;
 
   case 44:
@@ -2376,7 +2580,7 @@ yyreduce:
 #line 433 "src/parse-gram.y"
     {}
 /* Line 1735 of yacc.c  */
-#line 2380 "src/parse-gram.c"
+#line 2584 "src/parse-gram.c"
     break;
 
   case 45:
@@ -2384,7 +2588,7 @@ yyreduce:
 #line 434 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2388 "src/parse-gram.c"
+#line 2592 "src/parse-gram.c"
     break;
 
   case 46:
@@ -2396,7 +2600,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1735 of yacc.c  */
-#line 2400 "src/parse-gram.c"
+#line 2604 "src/parse-gram.c"
     break;
 
   case 47:
@@ -2404,7 +2608,7 @@ yyreduce:
 #line 450 "src/parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1735 of yacc.c  */
-#line 2408 "src/parse-gram.c"
+#line 2612 "src/parse-gram.c"
     break;
 
   case 48:
@@ -2415,7 +2619,7 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1735 of yacc.c  */
-#line 2419 "src/parse-gram.c"
+#line 2623 "src/parse-gram.c"
     break;
 
   case 49:
@@ -2423,7 +2627,7 @@ yyreduce:
 #line 455 "src/parse-gram.y"
     { current_class = token_sym; }
 /* Line 1735 of yacc.c  */
-#line 2427 "src/parse-gram.c"
+#line 2631 "src/parse-gram.c"
     break;
 
   case 50:
@@ -2434,7 +2638,7 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1735 of yacc.c  */
-#line 2438 "src/parse-gram.c"
+#line 2642 "src/parse-gram.c"
     break;
 
   case 51:
@@ -2448,7 +2652,7 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1735 of yacc.c  */
-#line 2452 "src/parse-gram.c"
+#line 2656 "src/parse-gram.c"
     break;
 
   case 52:
@@ -2466,7 +2670,7 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1735 of yacc.c  */
-#line 2470 "src/parse-gram.c"
+#line 2674 "src/parse-gram.c"
     break;
 
   case 53:
@@ -2474,7 +2678,7 @@ yyreduce:
 #line 486 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1735 of yacc.c  */
-#line 2478 "src/parse-gram.c"
+#line 2682 "src/parse-gram.c"
     break;
 
   case 54:
@@ -2482,7 +2686,7 @@ yyreduce:
 #line 487 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1735 of yacc.c  */
-#line 2486 "src/parse-gram.c"
+#line 2690 "src/parse-gram.c"
     break;
 
   case 55:
@@ -2490,7 +2694,7 @@ yyreduce:
 #line 488 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1735 of yacc.c  */
-#line 2494 "src/parse-gram.c"
+#line 2698 "src/parse-gram.c"
     break;
 
   case 56:
@@ -2498,7 +2702,7 @@ yyreduce:
 #line 489 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1735 of yacc.c  */
-#line 2502 "src/parse-gram.c"
+#line 2706 "src/parse-gram.c"
     break;
 
   case 57:
@@ -2506,7 +2710,7 @@ yyreduce:
 #line 493 "src/parse-gram.y"
     { current_type = NULL; }
 /* Line 1735 of yacc.c  */
-#line 2510 "src/parse-gram.c"
+#line 2714 "src/parse-gram.c"
     break;
 
   case 58:
@@ -2514,7 +2718,7 @@ yyreduce:
 #line 494 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1735 of yacc.c  */
-#line 2518 "src/parse-gram.c"
+#line 2722 "src/parse-gram.c"
     break;
 
   case 59:
@@ -2522,7 +2726,7 @@ yyreduce:
 #line 500 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2526 "src/parse-gram.c"
+#line 2730 "src/parse-gram.c"
     break;
 
   case 60:
@@ -2530,7 +2734,7 @@ yyreduce:
 #line 502 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1735 of yacc.c  */
-#line 2534 "src/parse-gram.c"
+#line 2738 "src/parse-gram.c"
     break;
 
   case 61:
@@ -2538,7 +2742,7 @@ yyreduce:
 #line 506 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1735 of yacc.c  */
-#line 2542 "src/parse-gram.c"
+#line 2746 "src/parse-gram.c"
     break;
 
   case 62:
@@ -2546,7 +2750,7 @@ yyreduce:
 #line 507 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2550 "src/parse-gram.c"
+#line 2754 "src/parse-gram.c"
     break;
 
   case 63:
@@ -2554,7 +2758,7 @@ yyreduce:
 #line 513 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2558 "src/parse-gram.c"
+#line 2762 "src/parse-gram.c"
     break;
 
   case 64:
@@ -2562,7 +2766,7 @@ yyreduce:
 #line 515 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1735 of yacc.c  */
-#line 2566 "src/parse-gram.c"
+#line 2770 "src/parse-gram.c"
     break;
 
   case 65:
@@ -2570,7 +2774,7 @@ yyreduce:
 #line 519 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1735 of yacc.c  */
-#line 2574 "src/parse-gram.c"
+#line 2778 "src/parse-gram.c"
     break;
 
   case 66:
@@ -2578,7 +2782,7 @@ yyreduce:
 #line 520 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1735 of yacc.c  */
-#line 2582 "src/parse-gram.c"
+#line 2786 "src/parse-gram.c"
     break;
 
   case 67:
@@ -2586,7 +2790,7 @@ yyreduce:
 #line 524 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2590 "src/parse-gram.c"
+#line 2794 "src/parse-gram.c"
     break;
 
   case 68:
@@ -2594,7 +2798,7 @@ yyreduce:
 #line 525 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2598 "src/parse-gram.c"
+#line 2802 "src/parse-gram.c"
     break;
 
   case 69:
@@ -2602,7 +2806,7 @@ yyreduce:
 #line 526 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2606 "src/parse-gram.c"
+#line 2810 "src/parse-gram.c"
     break;
 
   case 70:
@@ -2610,7 +2814,7 @@ yyreduce:
 #line 527 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2614 "src/parse-gram.c"
+#line 2818 "src/parse-gram.c"
     break;
 
   case 71:
@@ -2621,7 +2825,7 @@ yyreduce:
        tag_seen = true;
      }
 /* Line 1735 of yacc.c  */
-#line 2625 "src/parse-gram.c"
+#line 2829 "src/parse-gram.c"
     break;
 
   case 72:
@@ -2632,7 +2836,7 @@ yyreduce:
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1735 of yacc.c  */
-#line 2636 "src/parse-gram.c"
+#line 2840 "src/parse-gram.c"
     break;
 
   case 73:
@@ -2644,7 +2848,7 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1735 of yacc.c  */
-#line 2648 "src/parse-gram.c"
+#line 2852 "src/parse-gram.c"
     break;
 
   case 74:
@@ -2656,7 +2860,7 @@ yyreduce:
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1735 of yacc.c  */
-#line 2660 "src/parse-gram.c"
+#line 2864 "src/parse-gram.c"
     break;
 
   case 75:
@@ -2669,7 +2873,7 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1735 of yacc.c  */
-#line 2673 "src/parse-gram.c"
+#line 2877 "src/parse-gram.c"
     break;
 
   case 82:
@@ -2679,7 +2883,7 @@ yyreduce:
       yyerrok;
     }
 /* Line 1735 of yacc.c  */
-#line 2683 "src/parse-gram.c"
+#line 2887 "src/parse-gram.c"
     break;
 
   case 83:
@@ -2687,7 +2891,7 @@ yyreduce:
 #line 591 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1735 of yacc.c  */
-#line 2691 "src/parse-gram.c"
+#line 2895 "src/parse-gram.c"
     break;
 
   case 84:
@@ -2698,7 +2902,7 @@ yyreduce:
     current_lhs (0, (yylsp[-3]), 0);
   }
 /* Line 1735 of yacc.c  */
-#line 2702 "src/parse-gram.c"
+#line 2906 "src/parse-gram.c"
     break;
 
   case 85:
@@ -2706,7 +2910,7 @@ yyreduce:
 #line 599 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2710 "src/parse-gram.c"
+#line 2914 "src/parse-gram.c"
     break;
 
   case 86:
@@ -2714,7 +2918,7 @@ yyreduce:
 #line 600 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2718 "src/parse-gram.c"
+#line 2922 "src/parse-gram.c"
     break;
 
   case 88:
@@ -2723,7 +2927,7 @@ yyreduce:
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
 /* Line 1735 of yacc.c  */
-#line 2727 "src/parse-gram.c"
+#line 2931 "src/parse-gram.c"
     break;
 
   case 89:
@@ -2731,7 +2935,7 @@ yyreduce:
 #line 609 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1735 of yacc.c  */
-#line 2735 "src/parse-gram.c"
+#line 2939 "src/parse-gram.c"
     break;
 
   case 90:
@@ -2739,7 +2943,7 @@ yyreduce:
 #line 611 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
 /* Line 1735 of yacc.c  */
-#line 2743 "src/parse-gram.c"
+#line 2947 "src/parse-gram.c"
     break;
 
   case 91:
@@ -2747,7 +2951,7 @@ yyreduce:
 #line 613 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
 /* Line 1735 of yacc.c  */
-#line 2751 "src/parse-gram.c"
+#line 2955 "src/parse-gram.c"
     break;
 
   case 92:
@@ -2755,7 +2959,7 @@ yyreduce:
 #line 615 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2759 "src/parse-gram.c"
+#line 2963 "src/parse-gram.c"
     break;
 
   case 93:
@@ -2763,7 +2967,7 @@ yyreduce:
 #line 617 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2767 "src/parse-gram.c"
+#line 2971 "src/parse-gram.c"
     break;
 
   case 94:
@@ -2771,7 +2975,7 @@ yyreduce:
 #line 619 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2775 "src/parse-gram.c"
+#line 2979 "src/parse-gram.c"
     break;
 
   case 95:
@@ -2779,7 +2983,7 @@ yyreduce:
 #line 623 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
 /* Line 1735 of yacc.c  */
-#line 2783 "src/parse-gram.c"
+#line 2987 "src/parse-gram.c"
     break;
 
   case 96:
@@ -2787,7 +2991,7 @@ yyreduce:
 #line 625 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2791 "src/parse-gram.c"
+#line 2995 "src/parse-gram.c"
     break;
 
   case 98:
@@ -2795,7 +2999,7 @@ yyreduce:
 #line 636 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1735 of yacc.c  */
-#line 2799 "src/parse-gram.c"
+#line 3003 "src/parse-gram.c"
     break;
 
   case 99:
@@ -2803,7 +3007,7 @@ yyreduce:
 #line 641 "src/parse-gram.y"
     { (yyval.chars) = ""; }
 /* Line 1735 of yacc.c  */
-#line 2807 "src/parse-gram.c"
+#line 3011 "src/parse-gram.c"
     break;
 
   case 100:
@@ -2811,7 +3015,7 @@ yyreduce:
 #line 642 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
 /* Line 1735 of yacc.c  */
-#line 2815 "src/parse-gram.c"
+#line 3019 "src/parse-gram.c"
     break;
 
   case 102:
@@ -2826,7 +3030,7 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1735 of yacc.c  */
-#line 2830 "src/parse-gram.c"
+#line 3034 "src/parse-gram.c"
     break;
 
   case 103:
@@ -2834,7 +3038,7 @@ yyreduce:
 #line 673 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2838 "src/parse-gram.c"
+#line 3042 "src/parse-gram.c"
     break;
 
   case 104:
@@ -2846,7 +3050,7 @@ yyreduce:
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1735 of yacc.c  */
-#line 2850 "src/parse-gram.c"
+#line 3054 "src/parse-gram.c"
     break;
 
   case 105:
@@ -2854,7 +3058,7 @@ yyreduce:
 #line 683 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1735 of yacc.c  */
-#line 2858 "src/parse-gram.c"
+#line 3062 "src/parse-gram.c"
     break;
 
   case 108:
@@ -2865,7 +3069,7 @@ yyreduce:
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1735 of yacc.c  */
-#line 2869 "src/parse-gram.c"
+#line 3073 "src/parse-gram.c"
     break;
 
   case 110:
@@ -2880,12 +3084,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1735 of yacc.c  */
-#line 2884 "src/parse-gram.c"
+#line 3088 "src/parse-gram.c"
     break;
 
 
 /* Line 1735 of yacc.c  */
-#line 2889 "src/parse-gram.c"
+#line 3093 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3196,7 +3400,8 @@ add_param (param_type type, char *decl, location loc)
   }
 
   if (! name_start)
-    complain_at (loc, _("missing identifier in parameter declaration"));
+    complain_at (loc, complaint,
+                 _("missing identifier in parameter declaration"));
   else
     {
       char *name = xmemdup0 (name_start, strspn (name_start, alphanum));
@@ -3216,7 +3421,7 @@ version_check (location const *loc, char const *version)
 {
   if (strverscmp (version, PACKAGE_VERSION) > 0)
     {
-      complain_at (*loc, "require bison %s, but have %s",
+      complain_at (*loc, complaint, "require bison %s, but have %s",
                    version, PACKAGE_VERSION);
       exit (EX_MISMATCH);
     }
@@ -3225,7 +3430,7 @@ version_check (location const *loc, char const *version)
 static void
 gram_error (location const *loc, char const *msg)
 {
-  complain_at (*loc, "%s", msg);
+  complain_at (*loc, complaint, "%s", msg);
 }
 
 char const *
