@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.6.2.950-7c7ce-dirty.  */
+/* A Bison parser, made by GNU Bison 2.6.2.957-b074-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.2.950-7c7ce-dirty"
+#define YYBISON_VERSION "2.6.2.957-b074-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -58,7 +58,9 @@
 /* Pull parsers.  */
 #define YYPULL 1
 
-
+/* Substitute the type names.  */
+#define YYSTYPE         GRAM_STYPE
+#define YYLTYPE         GRAM_LTYPE
 /* Substitute the variable and function names.  */
 #define yyparse         gram_parse
 #define yylex           gram_lex
@@ -128,7 +130,7 @@ static void gram_error (location const *, char const *);
 static char const *char_name (char);
 
 /* Line 353 of yacc.c  */
-#line 132 "src/parse-gram.c"
+#line 134 "src/parse-gram.c"
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -151,10 +153,18 @@ static char const *char_name (char);
 #ifndef YY_GRAM_SRC_PARSE_GRAM_H_INCLUDED
 # define YY_GRAM_SRC_PARSE_GRAM_H_INCLUDED
 /* Enabling traces.  */
-#ifndef YYDEBUG
-# define YYDEBUG 1
-#endif
+#ifndef GRAM_DEBUG
+# if defined YYDEBUG
 #if YYDEBUG
+#   define GRAM_DEBUG 1
+#  else
+#   define GRAM_DEBUG 0
+#  endif
+# else /* ! defined YYDEBUG */
+#  define GRAM_DEBUG 1
+# endif /* ! defined YYDEBUG */
+#endif  /* ! defined GRAM_DEBUG */
+#if GRAM_DEBUG
 extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
@@ -174,14 +184,14 @@ extern int gram_debug;
 
 
 /* Line 369 of yacc.c  */
-#line 178 "src/parse-gram.c"
+#line 188 "src/parse-gram.c"
 
 /* Tokens.  */
-#ifndef YYTOKENTYPE
-# define YYTOKENTYPE
+#ifndef GRAM_TOKENTYPE
+# define GRAM_TOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
-  enum yytokentype
+  enum gram_tokentype
   {
     GRAM_EOF = 0,
     STRING = 258,
@@ -297,8 +307,8 @@ extern int gram_debug;
 #define PERCENT_PARAM 310
 #define PERCENT_UNION 311
 
-#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
-typedef union YYSTYPE
+#if ! defined GRAM_STYPE && ! defined GRAM_STYPE_IS_DECLARED
+typedef union GRAM_STYPE
 {
 /* Line 369 of yacc.c  */
 #line 109 "src/parse-gram.y"
@@ -323,22 +333,22 @@ typedef union YYSTYPE
 code_props_type code_type;
 
 /* Line 369 of yacc.c  */
-#line 327 "src/parse-gram.c"
-} YYSTYPE;
-# define YYSTYPE_IS_TRIVIAL 1
-# define YYSTYPE_IS_DECLARED 1
+#line 337 "src/parse-gram.c"
+} GRAM_STYPE;
+# define GRAM_STYPE_IS_TRIVIAL 1
+# define GRAM_STYPE_IS_DECLARED 1
 #endif
 
-#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
-typedef struct YYLTYPE
+#if ! defined GRAM_LTYPE && ! defined GRAM_LTYPE_IS_DECLARED
+typedef struct GRAM_LTYPE
 {
   int first_line;
   int first_column;
   int last_line;
   int last_column;
-} YYLTYPE;
-# define YYLTYPE_IS_DECLARED 1
-# define YYLTYPE_IS_TRIVIAL 1
+} GRAM_LTYPE;
+# define GRAM_LTYPE_IS_DECLARED 1
+# define GRAM_LTYPE_IS_TRIVIAL 1
 #endif
 
 
@@ -349,7 +359,7 @@ int gram_parse (void);
 /* Copy the second part of user declarations.  */
 
 /* Line 372 of yacc.c  */
-#line 353 "src/parse-gram.c"
+#line 363 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
 /* Line 373 of yacc.c  */
 #line 58 "src/parse-gram.y"
@@ -398,7 +408,7 @@ int gram_parse (void);
 
 
 /* Line 373 of yacc.c  */
-#line 402 "src/parse-gram.c"
+#line 412 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -509,8 +519,8 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 
 #if (! defined yyoverflow \
      && (! defined __cplusplus \
-         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
-             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))
+         || (defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL \
+             && defined GRAM_STYPE_IS_TRIVIAL && GRAM_STYPE_IS_TRIVIAL)))
 
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
@@ -629,7 +639,7 @@ static const yytype_uint8 yytranslate[] =
       55,    56
 };
 
-#if YYDEBUG
+#if GRAM_DEBUG
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
@@ -647,7 +657,7 @@ static const yytype_uint16 yyrline[] =
 };
 #endif
 
-#if YYDEBUG || YYERROR_VERBOSE || 1
+#if GRAM_DEBUG || YYERROR_VERBOSE || 1
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
@@ -925,7 +935,7 @@ while (0)
    we won't break user code: when these are the locations we know.  */
 
 #ifndef YY_LOCATION_PRINT
-# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
+# if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
 #  define YY_LOCATION_PRINT(File, Loc)                  \
      fprintf (File, "%d.%d-%d.%d",                      \
               (Loc).first_line, (Loc).first_column,     \
@@ -937,7 +947,6 @@ while (0)
 
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
-
 #ifdef YYLEX_PARAM
 # define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
 #else
@@ -945,7 +954,7 @@ while (0)
 #endif
 
 /* Enable debugging if requested.  */
-#if YYDEBUG
+#if GRAM_DEBUG
 
 # ifndef YYFPRINTF
 #  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
@@ -989,95 +998,95 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
             case 3: // "string"
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 196 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-/* Line 731 of yacc.c  */
-#line 997 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1006 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 209 "src/parse-gram.y"
         { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-/* Line 731 of yacc.c  */
-#line 1005 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1014 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 205 "src/parse-gram.y"
         { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 731 of yacc.c  */
-#line 1013 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1022 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 731 of yacc.c  */
-#line 1021 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1030 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 203 "src/parse-gram.y"
         { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 731 of yacc.c  */
-#line 1029 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1038 "src/parse-gram.c"
         break;
 
             case 43: // "char"
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 190 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), yyo); }
-/* Line 731 of yacc.c  */
-#line 1037 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1046 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 731 of yacc.c  */
-#line 1045 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1054 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 202 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 731 of yacc.c  */
-#line 1053 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1062 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 204 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 731 of yacc.c  */
-#line 1061 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1070 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 731 of yacc.c  */
-#line 1069 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1078 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 206 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 731 of yacc.c  */
-#line 1077 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1086 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 252 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
@@ -1091,88 +1100,88 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-/* Line 731 of yacc.c  */
-#line 1096 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1105 "src/parse-gram.c"
         break;
 
             case 64: // code_props_type
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 424 "src/parse-gram.y"
         { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-/* Line 731 of yacc.c  */
-#line 1104 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1113 "src/parse-gram.c"
         break;
 
             case 73: // symbol.prec
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 731 of yacc.c  */
-#line 1112 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1121 "src/parse-gram.c"
         break;
 
             case 77: // tag
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 206 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 731 of yacc.c  */
-#line 1120 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1129 "src/parse-gram.c"
         break;
 
             case 87: // variable
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 202 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 731 of yacc.c  */
-#line 1128 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1137 "src/parse-gram.c"
         break;
 
             case 88: // content.opt
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 731 of yacc.c  */
-#line 1136 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1145 "src/parse-gram.c"
         break;
 
             case 89: // braceless
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 731 of yacc.c  */
-#line 1144 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1153 "src/parse-gram.c"
         break;
 
             case 90: // id
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 731 of yacc.c  */
-#line 1152 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1161 "src/parse-gram.c"
         break;
 
             case 91: // id_colon
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 213 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 731 of yacc.c  */
-#line 1160 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1169 "src/parse-gram.c"
         break;
 
             case 92: // symbol
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 731 of yacc.c  */
-#line 1168 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1177 "src/parse-gram.c"
         break;
 
             case 93: // string_as_id
-/* Line 731 of yacc.c  */
+/* Line 727 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 731 of yacc.c  */
-#line 1176 "src/parse-gram.c"
+/* Line 727 of yacc.c  */
+#line 1185 "src/parse-gram.c"
         break;
 
       default:
@@ -1256,12 +1265,12 @@ do {                                    \
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
 int yydebug;
-#else /* !YYDEBUG */
+#else /* !GRAM_DEBUG */
 # define YYDPRINTF(Args)
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 # define YY_STACK_PRINT(Bottom, Top)
 # define YY_REDUCE_PRINT(Rule)
-#endif /* !YYDEBUG */
+#endif /* !GRAM_DEBUG */
 
 
 /* YYINITDEPTH -- initial size of the parser's stacks.  */
@@ -1292,7 +1301,7 @@ int yydebug;
    required.  Return 1 if memory is exhausted.  */
 static int
 yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
-#if YYDEBUG
+#if GRAM_DEBUG
                       char const *yydebug_prefix,
                       char const *yydebug_suffix,
 #endif
@@ -1395,7 +1404,7 @@ do {                                                             \
    the parser stacks to try to find a new initial context in which the
    current lookahead is syntactically acceptable.  If it fails to find
    such a context, it discards the lookahead.  */
-#if YYDEBUG
+#if GRAM_DEBUG
 # define YY_LAC_DISCARD(Event)                                           \
 do {                                                                     \
   if (yy_lac_established)                                                \
@@ -1498,7 +1507,7 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
         else
           {
             if (yy_lac_stack_realloc (yyes_capacity, 1,
-#if YYDEBUG
+#if GRAM_DEBUG
                                       " (", ")",
 #endif
                                       yyes, yyesa, &yyesp, yyes_prev))
@@ -1681,7 +1690,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                 yysize = yysize1;
               }
         }
-# if YYDEBUG
+# if GRAM_DEBUG
       else if (yydebug)
         YYFPRINTF (stderr, "No expected tokens.\n");
 # endif
@@ -1887,14 +1896,14 @@ YYLTYPE yylloc;
   yylsp = yyls;
 
   YYLVAL_INITIALIZE ();
-#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
+#if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
   yylloc.first_line   = yylloc.last_line   = 1;
   yylloc.first_column = yylloc.last_column = 1;
 #endif
 
 /* User initialization code.  */
-/* Line 1487 of yacc.c  */
+/* Line 1483 of yacc.c  */
 #line 101 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1902,8 +1911,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1487 of yacc.c  */
-#line 1907 "src/parse-gram.c"
+/* Line 1483 of yacc.c  */
+#line 1916 "src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2097,7 +2106,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 288 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2108,98 +2117,98 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1704 of yacc.c  */
-#line 2113 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2122 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 298 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1704 of yacc.c  */
-#line 2123 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2132 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 302 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1704 of yacc.c  */
-#line 2134 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2143 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 306 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1704 of yacc.c  */
-#line 2142 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2151 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 308 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1704 of yacc.c  */
-#line 2153 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2162 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 313 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1704 of yacc.c  */
-#line 2164 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2173 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1704 of yacc.c  */
-#line 2172 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2181 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 318 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1704 of yacc.c  */
-#line 2180 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2189 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 319 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1704 of yacc.c  */
-#line 2188 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2197 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 321 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1704 of yacc.c  */
-#line 2199 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2208 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 326 "src/parse-gram.y"
     {
       code_props action;
@@ -2209,76 +2218,76 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1704 of yacc.c  */
-#line 2214 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2223 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 334 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1704 of yacc.c  */
-#line 2222 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2231 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 335 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1704 of yacc.c  */
-#line 2230 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2239 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 336 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1704 of yacc.c  */
-#line 2238 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2247 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 337 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1704 of yacc.c  */
-#line 2246 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2255 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 338 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1704 of yacc.c  */
-#line 2254 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2263 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 339 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1704 of yacc.c  */
-#line 2262 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2271 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 339 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1704 of yacc.c  */
-#line 2270 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2279 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 340 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1704 of yacc.c  */
-#line 2278 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2287 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 342 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2303,62 +2312,62 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1704 of yacc.c  */
-#line 2308 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2317 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 365 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1704 of yacc.c  */
-#line 2316 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2325 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 366 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1704 of yacc.c  */
-#line 2324 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2333 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 367 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1704 of yacc.c  */
-#line 2332 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2341 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 372 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2340 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2349 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 373 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2348 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2357 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 385 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1704 of yacc.c  */
-#line 2358 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2367 "src/parse-gram.c"
     break;
 
   case 35:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 389 "src/parse-gram.y"
     {
       code_props code;
@@ -2371,32 +2380,32 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-/* Line 1704 of yacc.c  */
-#line 2376 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2385 "src/parse-gram.c"
     break;
 
   case 36:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 401 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1704 of yacc.c  */
-#line 2386 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2395 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 405 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1704 of yacc.c  */
-#line 2396 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2405 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 409 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2404,105 +2413,105 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1704 of yacc.c  */
-#line 2409 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2418 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 416 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1704 of yacc.c  */
-#line 2420 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2429 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 426 "src/parse-gram.y"
     { (yyval.code_type) = destructor; }
-/* Line 1704 of yacc.c  */
-#line 2428 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2437 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 427 "src/parse-gram.y"
     { (yyval.code_type) = printer; }
-/* Line 1704 of yacc.c  */
-#line 2436 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2445 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 437 "src/parse-gram.y"
     {}
-/* Line 1704 of yacc.c  */
-#line 2444 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2453 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 438 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2452 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2461 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 443 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1704 of yacc.c  */
-#line 2464 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2473 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 454 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1704 of yacc.c  */
-#line 2472 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2481 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 455 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1704 of yacc.c  */
-#line 2483 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2492 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 459 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1704 of yacc.c  */
-#line 2491 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2500 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 460 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1704 of yacc.c  */
-#line 2502 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2511 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 465 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2511,12 +2520,12 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1704 of yacc.c  */
-#line 2516 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2525 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 476 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2529,202 +2538,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1704 of yacc.c  */
-#line 2534 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2543 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 490 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1704 of yacc.c  */
-#line 2542 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2551 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 491 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1704 of yacc.c  */
-#line 2550 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2559 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 492 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1704 of yacc.c  */
-#line 2558 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2567 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 493 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1704 of yacc.c  */
-#line 2566 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2575 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 497 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1704 of yacc.c  */
-#line 2574 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2583 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 498 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1704 of yacc.c  */
-#line 2582 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2591 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 504 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2590 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2599 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1704 of yacc.c  */
-#line 2598 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2607 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 510 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1704 of yacc.c  */
-#line 2606 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2615 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 511 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2614 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2623 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 517 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2622 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2631 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 519 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1704 of yacc.c  */
-#line 2630 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2639 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 523 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1704 of yacc.c  */
-#line 2638 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2647 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 524 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1704 of yacc.c  */
-#line 2646 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2655 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 528 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2654 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2663 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 529 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2662 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2671 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 534 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-/* Line 1704 of yacc.c  */
-#line 2670 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2679 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 535 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new (""); }
-/* Line 1704 of yacc.c  */
-#line 2678 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2687 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 541 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1704 of yacc.c  */
-#line 2689 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2698 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 546 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1704 of yacc.c  */
-#line 2700 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2709 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 551 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1704 of yacc.c  */
-#line 2712 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2721 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 557 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1704 of yacc.c  */
-#line 2724 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2733 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 563 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2732,154 +2741,154 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1704 of yacc.c  */
-#line 2737 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2746 "src/parse-gram.c"
     break;
 
   case 81:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 593 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1704 of yacc.c  */
-#line 2747 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2756 "src/parse-gram.c"
     break;
 
   case 82:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 599 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1704 of yacc.c  */
-#line 2755 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2764 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 600 "src/parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-/* Line 1704 of yacc.c  */
-#line 2766 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2775 "src/parse-gram.c"
     break;
 
   case 84:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 607 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2774 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2783 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 608 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2782 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2791 "src/parse-gram.c"
     break;
 
   case 87:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 614 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-/* Line 1704 of yacc.c  */
-#line 2791 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2800 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 617 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1704 of yacc.c  */
-#line 2799 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2808 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 619 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1704 of yacc.c  */
-#line 2807 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2816 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 621 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1704 of yacc.c  */
-#line 2815 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2824 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 623 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2823 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2832 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 625 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2831 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2840 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 627 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2839 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2848 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 631 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1704 of yacc.c  */
-#line 2847 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2856 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 633 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2855 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2864 "src/parse-gram.c"
     break;
 
   case 97:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 644 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1704 of yacc.c  */
-#line 2863 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2872 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 649 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1704 of yacc.c  */
-#line 2871 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2880 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 650 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1704 of yacc.c  */
-#line 2879 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2888 "src/parse-gram.c"
     break;
 
   case 101:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 661 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2889,51 +2898,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1704 of yacc.c  */
-#line 2894 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2903 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 681 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2902 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2911 "src/parse-gram.c"
     break;
 
   case 103:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 683 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1704 of yacc.c  */
-#line 2914 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2923 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 691 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1704 of yacc.c  */
-#line 2922 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2931 "src/parse-gram.c"
     break;
 
   case 107:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 703 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1704 of yacc.c  */
-#line 2933 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2942 "src/parse-gram.c"
     break;
 
   case 109:
-/* Line 1704 of yacc.c  */
+/* Line 1700 of yacc.c  */
 #line 712 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2943,13 +2952,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1704 of yacc.c  */
-#line 2948 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2957 "src/parse-gram.c"
     break;
 
 
-/* Line 1704 of yacc.c  */
-#line 2953 "src/parse-gram.c"
+/* Line 1700 of yacc.c  */
+#line 2962 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3196,7 +3205,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-/* Line 1964 of yacc.c  */
+/* Line 1960 of yacc.c  */
 #line 722 "src/parse-gram.y"
 
 
