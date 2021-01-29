@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.5.1.815-22b0.  */
+/* A Bison parser, made by GNU Bison 2.5.1.885-485b-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.5.1.815-22b0"
+#define YYBISON_VERSION "2.5.1.885-485b-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -58,6 +58,7 @@
 /* Pull parsers.  */
 #define YYPULL 1
 
+
 /* Substitute the variable and function names.  */
 #define yyparse         gram_parse
 #define yylex           gram_lex
@@ -69,7 +70,7 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 328 of yacc.c  */
+/* Line 337 of yacc.c  */
 #line 1 "src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -124,8 +125,8 @@ static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
 
-/* Line 328 of yacc.c  */
-#line 129 "src/parse-gram.c"
+/* Line 337 of yacc.c  */
+#line 130 "src/parse-gram.c"
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -145,8 +146,8 @@ static char const *char_name (char);
 
 /* In a future release of Bison, this section will be replaced
    by #include "src/parse-gram.h".  */
-#ifndef GRAM_Y_TAB_H
-# define GRAM_Y_TAB_H
+#ifndef GRAM_SRC_PARSE_GRAM_H
+# define GRAM_SRC_PARSE_GRAM_H
 /* Enabling traces.  */
 #ifndef YYDEBUG
 # define YYDEBUG 1
@@ -155,7 +156,7 @@ static char const *char_name (char);
 extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
-/* Line 342 of yacc.c  */
+/* Line 351 of yacc.c  */
 #line 221 "src/parse-gram.y"
 
 # ifndef PARAM_TYPE
@@ -170,71 +171,72 @@ extern int gram_debug;
 # endif
 
 
-/* Line 342 of yacc.c  */
-#line 175 "src/parse-gram.c"
+/* Line 351 of yacc.c  */
+#line 176 "src/parse-gram.c"
 
 /* Tokens.  */
 #ifndef YYTOKENTYPE
 # define YYTOKENTYPE
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
+  /* Put the tokens into the symbol table, so that GDB and other debuggers
+     know about them.  */
+  enum yytokentype
+  {
+    GRAM_EOF = 0,
+    STRING = 258,
+    INT = 259,
+    PERCENT_TOKEN = 260,
+    PERCENT_NTERM = 261,
+    PERCENT_TYPE = 262,
+    PERCENT_DESTRUCTOR = 263,
+    PERCENT_PRINTER = 264,
+    PERCENT_LEFT = 265,
+    PERCENT_RIGHT = 266,
+    PERCENT_NONASSOC = 267,
+    PERCENT_PRECEDENCE = 268,
+    PERCENT_PREC = 269,
+    PERCENT_DPREC = 270,
+    PERCENT_MERGE = 271,
+    PERCENT_CODE = 272,
+    PERCENT_DEFAULT_PREC = 273,
+    PERCENT_DEFINE = 274,
+    PERCENT_DEFINES = 275,
+    PERCENT_ERROR_VERBOSE = 276,
+    PERCENT_EXPECT = 277,
+    PERCENT_EXPECT_RR = 278,
+    PERCENT_FLAG = 279,
+    PERCENT_FILE_PREFIX = 280,
+    PERCENT_GLR_PARSER = 281,
+    PERCENT_INITIAL_ACTION = 282,
+    PERCENT_LANGUAGE = 283,
+    PERCENT_NAME_PREFIX = 284,
+    PERCENT_NO_DEFAULT_PREC = 285,
+    PERCENT_NO_LINES = 286,
+    PERCENT_NONDETERMINISTIC_PARSER = 287,
+    PERCENT_OUTPUT = 288,
+    PERCENT_REQUIRE = 289,
+    PERCENT_SKELETON = 290,
+    PERCENT_START = 291,
+    PERCENT_TOKEN_TABLE = 292,
+    PERCENT_VERBOSE = 293,
+    PERCENT_YACC = 294,
+    BRACED_CODE = 295,
+    BRACED_PREDICATE = 296,
+    BRACKETED_ID = 297,
+    CHAR = 298,
+    EPILOGUE = 299,
+    EQUAL = 300,
+    ID = 301,
+    ID_COLON = 302,
+    PERCENT_PERCENT = 303,
+    PIPE = 304,
+    PROLOGUE = 305,
+    SEMICOLON = 306,
+    TAG = 307,
+    TAG_ANY = 308,
+    TAG_NONE = 309,
+    PERCENT_PARAM = 310,
+    PERCENT_UNION = 311
+  };
 #endif
 /* Tokens.  */
 #define GRAM_EOF 0
@@ -293,12 +295,10 @@ extern int gram_debug;
 #define PERCENT_PARAM 310
 #define PERCENT_UNION 311
 
-
-
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 342 of yacc.c  */
+/* Line 351 of yacc.c  */
 #line 107 "src/parse-gram.y"
 
   assoc assoc;
@@ -311,13 +311,13 @@ typedef union YYSTYPE
   uniqstr uniqstr;
   unsigned char character;
 
-/* Line 342 of yacc.c  */
+/* Line 351 of yacc.c  */
 #line 245 "src/parse-gram.y"
 
   param_type param;
 
 
-/* Line 342 of yacc.c  */
+/* Line 351 of yacc.c  */
 #line 322 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -355,14 +355,14 @@ int gram_parse ();
 #endif
 #endif /* ! YYPARSE_PARAM */
 
-#endif /* !GRAM_Y_TAB_H  */
+#endif /* !GRAM_SRC_PARSE_GRAM_H  */
 
 /* Copy the second part of user declarations.  */
 
-/* Line 345 of yacc.c  */
+/* Line 354 of yacc.c  */
 #line 364 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
-/* Line 346 of yacc.c  */
+/* Line 355 of yacc.c  */
 #line 56 "src/parse-gram.y"
 
   static int current_prec = 0;
@@ -395,7 +395,7 @@ int gram_parse ();
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-/* Line 346 of yacc.c  */
+/* Line 355 of yacc.c  */
 #line 234 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
@@ -408,7 +408,7 @@ int gram_parse ();
   static param_type current_param = param_none;
 
 
-/* Line 346 of yacc.c  */
+/* Line 355 of yacc.c  */
 #line 413 "src/parse-gram.c"
 
 #ifdef short
@@ -953,11 +953,10 @@ while (YYID (0))
    If N is 0, then set CURRENT to the empty location which ends
    the previous symbol: RHS[0] (always defined).  */
 
-#define YYRHSLOC(Rhs, K) ((Rhs)[K])
 #ifndef YYLLOC_DEFAULT
 # define YYLLOC_DEFAULT(Current, Rhs, N)                                \
     do                                                                  \
-      if (YYID (N))                                                    \
+      if (YYID (N))                                                     \
         {                                                               \
           (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
           (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
@@ -974,6 +973,7 @@ while (YYID (0))
     while (YYID (0))
 #endif
 
+#define YYRHSLOC(Rhs, K) ((Rhs)[K])
 
 /* YY_LOCATION_PRINT -- Print the location on the stream.
    This macro was not mandated originally: define only if we know
@@ -1056,106 +1056,106 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
             case 3: // "string"
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 194 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1064 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 207 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1073 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 203 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1082 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1091 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 201 "src/parse-gram.y"
         { fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1100 "src/parse-gram.c"
         break;
 
             case 43: // "char"
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 188 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1109 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1118 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 200 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1127 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 202 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1136 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1145 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 204 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1154 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 250 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
@@ -1169,79 +1169,79 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case param_none: aver (false); break;
     }
 }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1174 "src/parse-gram.c"
         break;
 
             case 72: // symbol.prec
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1183 "src/parse-gram.c"
         break;
 
             case 85: // variable
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 200 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1192 "src/parse-gram.c"
         break;
 
             case 86: // content.opt
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1201 "src/parse-gram.c"
         break;
 
             case 87: // braceless
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1210 "src/parse-gram.c"
         break;
 
             case 88: // id
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1219 "src/parse-gram.c"
         break;
 
             case 89: // id_colon
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 211 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1228 "src/parse-gram.c"
         break;
 
             case 90: // symbol
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1237 "src/parse-gram.c"
         break;
 
             case 91: // string_as_id
 
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 754 of yacc.c  */
+/* Line 740 of yacc.c  */
 #line 1246 "src/parse-gram.c"
         break;
 
@@ -2019,7 +2019,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1519 of yacc.c  */
+/* Line 1505 of yacc.c  */
 #line 99 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -2027,7 +2027,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1519 of yacc.c  */
+/* Line 1505 of yacc.c  */
 #line 2032 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
@@ -2221,7 +2221,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 286 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2232,106 +2232,106 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2237 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 296 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2247 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 300 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2258 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 304 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2266 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 306 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2277 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 311 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2288 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 315 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2296 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 316 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2304 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2312 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 318 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2320 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 320 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2331 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 325 "src/parse-gram.y"
     {
       code_props action;
@@ -2341,92 +2341,92 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2346 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 333 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2354 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 334 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2362 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 335 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2370 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 336 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2378 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 337 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2386 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 338 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2394 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 339 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2402 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 340 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2410 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 340 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2418 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 341 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2426 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 343 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2451,62 +2451,62 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2456 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 366 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2464 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 367 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2472 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 368 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2480 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 373 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2488 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 374 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2496 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 386 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2506 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 390 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2514,12 +2514,12 @@ yyreduce:
         symbol_list_code_props_set (list, destructor, (yylsp[-1]), (yyvsp[-1].code));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2519 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 397 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2527,32 +2527,32 @@ yyreduce:
         symbol_list_code_props_set (list, printer, (yylsp[-1]), (yyvsp[-1].code));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2532 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 404 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2542 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 408 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2552 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 412 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2560,89 +2560,89 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2565 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 419 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2576 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 433 "src/parse-gram.y"
     {}
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2584 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 434 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2592 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 439 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2604 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 450 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2612 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 451 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2623 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 455 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2631 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 456 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2642 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 461 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2651,12 +2651,12 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2656 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 472 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2669,202 +2669,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2674 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 486 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2682 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 487 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2690 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 488 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2698 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 489 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2706 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 493 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2714 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 494 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2722 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 500 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2730 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 502 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2738 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 506 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2746 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 507 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2754 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 513 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2762 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 515 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2770 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 519 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2778 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 520 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2786 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 524 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2794 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 525 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2802 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 526 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2810 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 527 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2818 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 533 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2829 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 538 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2840 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 543 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2852 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 549 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2864 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 555 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2872,154 +2872,154 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2877 "src/parse-gram.c"
     break;
 
   case 82:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 585 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2887 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 591 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2895 "src/parse-gram.c"
     break;
 
   case 84:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 592 "src/parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2906 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 599 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2914 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 600 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2922 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 606 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2931 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 609 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2939 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 611 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2947 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 613 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2955 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 615 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2963 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 617 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2971 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 619 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2979 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 623 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2987 "src/parse-gram.c"
     break;
 
   case 96:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 625 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 2995 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 636 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 3003 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 641 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 3011 "src/parse-gram.c"
     break;
 
   case 100:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 642 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 3019 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 653 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -3029,51 +3029,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 3034 "src/parse-gram.c"
     break;
 
   case 103:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 673 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 3042 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 675 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 3054 "src/parse-gram.c"
     break;
 
   case 105:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 683 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 3062 "src/parse-gram.c"
     break;
 
   case 108:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 695 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 3073 "src/parse-gram.c"
     break;
 
   case 110:
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 704 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -3083,12 +3083,12 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 3088 "src/parse-gram.c"
     break;
 
 
-/* Line 1735 of yacc.c  */
+/* Line 1721 of yacc.c  */
 #line 3093 "src/parse-gram.c"
         default: break;
       }
@@ -3336,7 +3336,7 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 1995 of yacc.c  */
+/* Line 1981 of yacc.c  */
 #line 714 "src/parse-gram.y"
 
 
