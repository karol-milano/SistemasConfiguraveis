@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.5.1.19-ced26-dirty.  */
+/* A Bison parser, made by GNU Bison 2.6.22-9f3f1.  */
 
 /* Bison implementation for Yacc-like parsers in C
    
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.5.1.19-ced26-dirty"
+#define YYBISON_VERSION "2.6.22-9f3f1"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -58,8 +58,6 @@
 /* Pull parsers.  */
 #define YYPULL 1
 
-/* Using locations.  */
-#define YYLSP_NEEDED 1
 
 /* Substitute the variable and function names.  */
 #define yyparse         gram_parse
@@ -73,7 +71,7 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 323 of yacc.c  */
+/* Line 336 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -169,8 +167,8 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 323 of yacc.c  */
-#line 174 "parse-gram.c"
+/* Line 336 of yacc.c  */
+#line 172 "parse-gram.c"
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -188,18 +186,204 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 # define YYERROR_VERBOSE 1
 #endif
 
-/* Enabling the token table.  */
-#ifndef YYTOKEN_TABLE
-# define YYTOKEN_TABLE 0
+/* In a future release of Bison, this section will be replaced
+   by #include "parse-gram.h".  */
+#ifndef GRAM_Y_TAB_H
+# define GRAM_Y_TAB_H
+/* Enabling traces.  */
+#ifndef YYDEBUG
+# define YYDEBUG 1
+#endif
+#if YYDEBUG
+extern int gram_debug;
+#endif
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
+     PERCENT_PREC = 268,
+     PERCENT_DPREC = 269,
+     PERCENT_MERGE = 270,
+     PERCENT_CODE = 271,
+     PERCENT_DEBUG = 272,
+     PERCENT_DEFAULT_PREC = 273,
+     PERCENT_DEFINE = 274,
+     PERCENT_DEFINES = 275,
+     PERCENT_ERROR_VERBOSE = 276,
+     PERCENT_EXPECT = 277,
+     PERCENT_EXPECT_RR = 278,
+     PERCENT_FILE_PREFIX = 279,
+     PERCENT_GLR_PARSER = 280,
+     PERCENT_INITIAL_ACTION = 281,
+     PERCENT_LANGUAGE = 282,
+     PERCENT_LEX_PARAM = 283,
+     PERCENT_LOCATIONS = 284,
+     PERCENT_NAME_PREFIX = 285,
+     PERCENT_NO_DEFAULT_PREC = 286,
+     PERCENT_NO_LINES = 287,
+     PERCENT_NONDETERMINISTIC_PARSER = 288,
+     PERCENT_OUTPUT = 289,
+     PERCENT_PARSE_PARAM = 290,
+     PERCENT_PURE_PARSER = 291,
+     PERCENT_REQUIRE = 292,
+     PERCENT_SKELETON = 293,
+     PERCENT_START = 294,
+     PERCENT_TOKEN_TABLE = 295,
+     PERCENT_VERBOSE = 296,
+     PERCENT_YACC = 297,
+     BRACED_CODE = 298,
+     BRACKETED_ID = 299,
+     CHAR = 300,
+     EPILOGUE = 301,
+     EQUAL = 302,
+     ID = 303,
+     ID_COLON = 304,
+     PERCENT_PERCENT = 305,
+     PIPE = 306,
+     PROLOGUE = 307,
+     SEMICOLON = 308,
+     TYPE = 309,
+     TYPE_TAG_ANY = 310,
+     TYPE_TAG_NONE = 311,
+     PERCENT_UNION = 312
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
+#define PERCENT_PREC 268
+#define PERCENT_DPREC 269
+#define PERCENT_MERGE 270
+#define PERCENT_CODE 271
+#define PERCENT_DEBUG 272
+#define PERCENT_DEFAULT_PREC 273
+#define PERCENT_DEFINE 274
+#define PERCENT_DEFINES 275
+#define PERCENT_ERROR_VERBOSE 276
+#define PERCENT_EXPECT 277
+#define PERCENT_EXPECT_RR 278
+#define PERCENT_FILE_PREFIX 279
+#define PERCENT_GLR_PARSER 280
+#define PERCENT_INITIAL_ACTION 281
+#define PERCENT_LANGUAGE 282
+#define PERCENT_LEX_PARAM 283
+#define PERCENT_LOCATIONS 284
+#define PERCENT_NAME_PREFIX 285
+#define PERCENT_NO_DEFAULT_PREC 286
+#define PERCENT_NO_LINES 287
+#define PERCENT_NONDETERMINISTIC_PARSER 288
+#define PERCENT_OUTPUT 289
+#define PERCENT_PARSE_PARAM 290
+#define PERCENT_PURE_PARSER 291
+#define PERCENT_REQUIRE 292
+#define PERCENT_SKELETON 293
+#define PERCENT_START 294
+#define PERCENT_TOKEN_TABLE 295
+#define PERCENT_VERBOSE 296
+#define PERCENT_YACC 297
+#define BRACED_CODE 298
+#define BRACKETED_ID 299
+#define CHAR 300
+#define EPILOGUE 301
+#define EQUAL 302
+#define ID 303
+#define ID_COLON 304
+#define PERCENT_PERCENT 305
+#define PIPE 306
+#define PROLOGUE 307
+#define SEMICOLON 308
+#define TYPE 309
+#define TYPE_TAG_ANY 310
+#define TYPE_TAG_NONE 311
+#define PERCENT_UNION 312
+
+
+
+#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
+typedef union YYSTYPE
+{
+
+/* Line 350 of yacc.c  */
+#line 114 "parse-gram.y"
+
+  symbol *symbol;
+  symbol_list *list;
+  int integer;
+  char const *chars;
+  char *code;
+  assoc assoc;
+  uniqstr uniqstr;
+  unsigned char character;
+  named_ref *named_ref;
+
+
+
+/* Line 350 of yacc.c  */
+#line 346 "parse-gram.c"
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
 #endif
 
-#include "parse-gram.h"
+
+#ifdef YYPARSE_PARAM
+#if defined __STDC__ || defined __cplusplus
+int gram_parse (void *YYPARSE_PARAM);
+#else
+int gram_parse ();
+#endif
+#else /* ! YYPARSE_PARAM */
+#if defined __STDC__ || defined __cplusplus
+int gram_parse (void);
+#else
+int gram_parse ();
+#endif
+#endif /* ! YYPARSE_PARAM */
+
+#endif /* !GRAM_Y_TAB_H  */
 
 /* Copy the second part of user declarations.  */
 
 
-/* Line 344 of yacc.c  */
-#line 203 "parse-gram.c"
+/* Line 353 of yacc.c  */
+#line 387 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -520,7 +704,7 @@ static const yytype_uint16 yyrline[] =
 };
 #endif
 
-#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
+#if YYDEBUG || YYERROR_VERBOSE || 1
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
@@ -780,32 +964,33 @@ while (YYID (0))
 #define YYTERROR	1
 #define YYERRCODE	256
 
-
 /* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
    If N is 0, then set CURRENT to the empty location which ends
    the previous symbol: RHS[0] (always defined).  */
 
-#define YYRHSLOC(Rhs, K) ((Rhs)[K])
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(Current, Rhs, N)				\
-    do									\
-      if (YYID (N))                                                    \
-	{								\
-	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
-	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
-	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
-	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
-	}								\
-      else								\
-	{								\
-	  (Current).first_line   = (Current).last_line   =		\
-	    YYRHSLOC (Rhs, 0).last_line;				\
-	  (Current).first_column = (Current).last_column =		\
-	    YYRHSLOC (Rhs, 0).last_column;				\
-	}								\
+# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
+    do                                                                  \
+      if (YYID (N))                                                     \
+        {                                                               \
+          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
+          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
+          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
+          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
+        }                                                               \
+      else                                                              \
+        {                                                               \
+          (Current).first_line   = (Current).last_line   =              \
+            YYRHSLOC (Rhs, 0).last_line;                                \
+          (Current).first_column = (Current).last_column =              \
+            YYRHSLOC (Rhs, 0).last_column;                              \
+        }                                                               \
     while (YYID (0))
 #endif
 
+#define YYRHSLOC(Rhs, K) ((Rhs)[K])
+
+
 
 /* YY_LOCATION_PRINT -- Print the location on the stream.
    This macro was not mandated originally: define only if we know
@@ -888,167 +1073,167 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 # endif
   switch (yytype)
     {
-      case 3: /* "\"string\"" */
+      case 3: /* "string" */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 204 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 822 of yacc.c  */
-#line 899 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1084 "parse-gram.c"
 	break;
-      case 4: /* "\"integer\"" */
+      case 4: /* "integer" */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 216 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 822 of yacc.c  */
-#line 908 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1093 "parse-gram.c"
 	break;
-      case 43: /* "\"{...}\"" */
+      case 43: /* "{...}" */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 206 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 822 of yacc.c  */
-#line 917 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1102 "parse-gram.c"
 	break;
-      case 44: /* "\"[identifier]\"" */
+      case 44: /* "[identifier]" */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 211 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", (yyvaluep->uniqstr)); };
 
-/* Line 822 of yacc.c  */
-#line 926 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1111 "parse-gram.c"
 	break;
-      case 45: /* "\"char\"" */
+      case 45: /* "char" */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 198 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 822 of yacc.c  */
-#line 935 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1120 "parse-gram.c"
 	break;
-      case 46: /* "\"epilogue\"" */
+      case 46: /* "epilogue" */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 206 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 822 of yacc.c  */
-#line 944 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1129 "parse-gram.c"
 	break;
-      case 48: /* "\"identifier\"" */
+      case 48: /* "identifier" */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 210 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 822 of yacc.c  */
-#line 953 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1138 "parse-gram.c"
 	break;
-      case 49: /* "\"identifier:\"" */
+      case 49: /* "identifier:" */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 212 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 822 of yacc.c  */
-#line 962 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1147 "parse-gram.c"
 	break;
-      case 52: /* "\"%{...%}\"" */
+      case 52: /* "%{...%}" */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 206 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 822 of yacc.c  */
-#line 971 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1156 "parse-gram.c"
 	break;
-      case 54: /* "\"type\"" */
+      case 54: /* "type" */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 213 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 822 of yacc.c  */
-#line 980 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1165 "parse-gram.c"
 	break;
-      case 71: /* "symbol.prec" */
+      case 71: /* symbol.prec */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 219 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 822 of yacc.c  */
-#line 989 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1174 "parse-gram.c"
 	break;
-      case 84: /* "variable" */
+      case 84: /* variable */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 210 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 822 of yacc.c  */
-#line 998 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1183 "parse-gram.c"
 	break;
-      case 85: /* "content.opt" */
+      case 85: /* content.opt */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 206 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 822 of yacc.c  */
-#line 1007 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1192 "parse-gram.c"
 	break;
-      case 86: /* "braceless" */
+      case 86: /* braceless */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 206 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 822 of yacc.c  */
-#line 1016 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1201 "parse-gram.c"
 	break;
-      case 87: /* "id" */
+      case 87: /* id */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 219 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 822 of yacc.c  */
-#line 1025 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1210 "parse-gram.c"
 	break;
-      case 88: /* "id_colon" */
+      case 88: /* id_colon */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 822 of yacc.c  */
-#line 1034 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1219 "parse-gram.c"
 	break;
-      case 89: /* "symbol" */
+      case 89: /* symbol */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 219 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 822 of yacc.c  */
-#line 1043 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1228 "parse-gram.c"
 	break;
-      case 90: /* "string_as_id" */
+      case 90: /* string_as_id */
 
-/* Line 822 of yacc.c  */
+/* Line 809 of yacc.c  */
 #line 219 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 822 of yacc.c  */
-#line 1052 "parse-gram.c"
+/* Line 809 of yacc.c  */
+#line 1237 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1825,7 +2010,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1585 of yacc.c  */
+/* Line 1572 of yacc.c  */
 #line 106 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1834,8 +2019,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1585 of yacc.c  */
-#line 1839 "parse-gram.c"
+/* Line 1572 of yacc.c  */
+#line 2024 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2029,7 +2214,7 @@ yyreduce:
       {
           case 6:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 245 "parse-gram.y"
     {
       code_props plain_code;
@@ -2044,14 +2229,14 @@ yyreduce:
 
   case 7:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 254 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 256 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -2061,14 +2246,14 @@ yyreduce:
 
   case 9:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 260 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 262 "parse-gram.y"
     {
       defines_flag = true;
@@ -2078,42 +2263,42 @@ yyreduce:
 
   case 11:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 266 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 267 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 268 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 269 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 270 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 272 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -2123,7 +2308,7 @@ yyreduce:
 
   case 17:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 277 "parse-gram.y"
     {
       code_props action;
@@ -2137,77 +2322,77 @@ yyreduce:
 
   case 18:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 285 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 286 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 287 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 288 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 289 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 290 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 291 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 292 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 293 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 294 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 296 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2227,14 +2412,14 @@ yyreduce:
 
   case 29:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 310 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 312 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2263,28 +2448,28 @@ yyreduce:
 
   case 31:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 335 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 336 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 337 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 345 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2293,7 +2478,7 @@ yyreduce:
 
   case 38:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 349 "parse-gram.y"
     {
       symbol_list *list;
@@ -2305,7 +2490,7 @@ yyreduce:
 
   case 39:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 356 "parse-gram.y"
     {
       symbol_list *list;
@@ -2317,7 +2502,7 @@ yyreduce:
 
   case 40:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 363 "parse-gram.y"
     {
       default_prec = true;
@@ -2326,7 +2511,7 @@ yyreduce:
 
   case 41:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 367 "parse-gram.y"
     {
       default_prec = false;
@@ -2335,7 +2520,7 @@ yyreduce:
 
   case 42:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 371 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2347,7 +2532,7 @@ yyreduce:
 
   case 43:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 378 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2357,21 +2542,21 @@ yyreduce:
 
   case 44:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 392 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 393 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 398 "parse-gram.y"
     {
       union_seen = true;
@@ -2382,14 +2567,14 @@ yyreduce:
 
   case 47:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 409 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 410 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2399,14 +2584,14 @@ yyreduce:
 
   case 49:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 414 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 415 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2416,7 +2601,7 @@ yyreduce:
 
   case 51:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 420 "parse-gram.y"
     {
       symbol_list *list;
@@ -2429,7 +2614,7 @@ yyreduce:
 
   case 52:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 431 "parse-gram.y"
     {
       symbol_list *list;
@@ -2446,126 +2631,126 @@ yyreduce:
 
   case 53:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 445 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 446 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 447 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 451 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 452 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 458 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 460 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 464 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 465 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 471 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 473 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 477 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 478 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 482 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 483 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 484 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 485 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 491 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2575,7 +2760,7 @@ yyreduce:
 
   case 71:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 496 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2585,7 +2770,7 @@ yyreduce:
 
   case 72:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 501 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2596,7 +2781,7 @@ yyreduce:
 
   case 73:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 507 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2607,7 +2792,7 @@ yyreduce:
 
   case 74:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 513 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2619,7 +2804,7 @@ yyreduce:
 
   case 81:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 543 "parse-gram.y"
     {
       yyerrok;
@@ -2628,14 +2813,14 @@ yyreduce:
 
   case 82:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 549 "parse-gram.y"
     { current_lhs ((yyvsp[(1) - (2)].symbol), (yylsp[(1) - (2)]), (yyvsp[(2) - (2)].named_ref)); }
     break;
 
   case 83:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 550 "parse-gram.y"
     {
     /* Free the current lhs. */
@@ -2645,21 +2830,21 @@ yyreduce:
 
   case 84:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 557 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 558 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 564 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
 				  current_lhs_named_ref); }
@@ -2667,77 +2852,77 @@ yyreduce:
 
   case 88:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 567 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 569 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 571 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 573 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 575 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 579 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 581 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 593 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 598 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 599 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 610 "parse-gram.y"
     {
       code_props plain_code;
@@ -2751,14 +2936,14 @@ yyreduce:
 
   case 101:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 630 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 632 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2769,14 +2954,14 @@ yyreduce:
 
   case 103:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 640 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 652 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2786,7 +2971,7 @@ yyreduce:
 
   case 108:
 
-/* Line 1801 of yacc.c  */
+/* Line 1788 of yacc.c  */
 #line 661 "parse-gram.y"
     {
       code_props plain_code;
@@ -2800,8 +2985,8 @@ yyreduce:
 
 
 
-/* Line 1801 of yacc.c  */
-#line 2805 "parse-gram.c"
+/* Line 1788 of yacc.c  */
+#line 2990 "parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3050,7 +3235,7 @@ yyreturn:
 
 
 
-/* Line 2062 of yacc.c  */
+/* Line 2049 of yacc.c  */
 #line 671 "parse-gram.y"
 
 
