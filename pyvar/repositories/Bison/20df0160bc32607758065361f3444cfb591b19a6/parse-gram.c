@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.6.3.3-b10d3.  */
+/* A Bison parser, made by GNU Bison 2.6.4.4-8c79c-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
    
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.3.3-b10d3"
+#define YYBISON_VERSION "2.6.4.4-8c79c-dirty"
 
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
@@ -167,7 +169,7 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 #define YYTYPE_UINT8 uint_fast8_t
 
 /* Line 358 of yacc.c  */
-#line 171 "parse-gram.c"
+#line 173 "parse-gram.c"
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -190,19 +192,27 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 #ifndef YY_GRAM_Y_TAB_H_INCLUDED
 # define YY_GRAM_Y_TAB_H_INCLUDED
 /* Enabling traces.  */
-#ifndef YYDEBUG
-# define YYDEBUG 1
-#endif
-#if YYDEBUG
+#ifndef GRAM_DEBUG
+# if defined YYDEBUG
+#  if YYDEBUG
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
 
 /* Tokens.  */
-#ifndef YYTOKENTYPE
-# define YYTOKENTYPE
+#ifndef GRAM_TOKENTYPE
+# define GRAM_TOKENTYPE
    /* Put the tokens into the symbol table, so that GDB and other debuggers
       know about them.  */
-   enum yytokentype {
+   enum gram_tokentype {
      GRAM_EOF = 0,
      STRING = 258,
      INT = 259,
@@ -321,8 +331,8 @@ extern int gram_debug;
 
 
 
-#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
-typedef union YYSTYPE
+#if ! defined GRAM_STYPE && ! defined GRAM_STYPE_IS_DECLARED
+typedef union GRAM_STYPE
 {
 /* Line 374 of yacc.c  */
 #line 115 "parse-gram.y"
@@ -339,24 +349,24 @@ typedef union YYSTYPE
 
 
 /* Line 374 of yacc.c  */
-#line 343 "parse-gram.c"
-} YYSTYPE;
-# define YYSTYPE_IS_TRIVIAL 1
-# define yystype YYSTYPE /* obsolescent; will be withdrawn */
-# define YYSTYPE_IS_DECLARED 1
+#line 353 "parse-gram.c"
+} GRAM_STYPE;
+# define GRAM_STYPE_IS_TRIVIAL 1
+# define gram_stype GRAM_STYPE /* obsolescent; will be withdrawn */
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
-# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
-# define YYLTYPE_IS_DECLARED 1
-# define YYLTYPE_IS_TRIVIAL 1
+} GRAM_LTYPE;
+# define gram_ltype GRAM_LTYPE /* obsolescent; will be withdrawn */
+# define GRAM_LTYPE_IS_DECLARED 1
+# define GRAM_LTYPE_IS_TRIVIAL 1
 #endif
 
 
@@ -379,7 +389,7 @@ int gram_parse ();
 /* Copy the second part of user declarations.  */
 
 /* Line 377 of yacc.c  */
-#line 383 "parse-gram.c"
+#line 393 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -514,8 +524,8 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 
 #if (! defined yyoverflow \
      && (! defined __cplusplus \
-	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
-	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))
+	 || (defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL \
+	     && defined GRAM_STYPE_IS_TRIVIAL && GRAM_STYPE_IS_TRIVIAL)))
 
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
@@ -632,7 +642,7 @@ static const yytype_uint8 yytranslate[] =
       55,    56,    57
 };
 
-#if YYDEBUG
+#if GRAM_DEBUG
 /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
    YYRHS.  */
 static const yytype_uint16 yyprhs[] =
@@ -700,7 +710,7 @@ static const yytype_uint16 yyrline[] =
 };
 #endif
 
-#if YYDEBUG || YYERROR_VERBOSE || 1
+#if GRAM_DEBUG || YYERROR_VERBOSE || 1
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
@@ -993,7 +1003,7 @@ while (YYID (0))
    we won't break user code: when these are the locations we know.  */
 
 #ifndef YY_LOCATION_PRINT
-# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
+# if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
 #  define YY_LOCATION_PRINT(File, Loc)			\
      fprintf (File, "%d.%d-%d.%d",			\
 	      (Loc).first_line, (Loc).first_column,	\
@@ -1013,7 +1023,7 @@ while (YYID (0))
 #endif
 
 /* Enable debugging if requested.  */
-#if YYDEBUG
+#if GRAM_DEBUG
 
 # ifndef YYFPRINTF
 #  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
@@ -1074,126 +1084,126 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 205 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); };
 /* Line 833 of yacc.c  */
-#line 1078 "parse-gram.c"
+#line 1088 "parse-gram.c"
 	break;
       case 4: /* "integer" */
 /* Line 833 of yacc.c  */
 #line 217 "parse-gram.y"
 	{ fprintf (stderr, "%d", ((*yyvaluep).integer)); };
 /* Line 833 of yacc.c  */
-#line 1085 "parse-gram.c"
+#line 1095 "parse-gram.c"
 	break;
       case 43: /* "{...}" */
 /* Line 833 of yacc.c  */
 #line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); };
 /* Line 833 of yacc.c  */
-#line 1092 "parse-gram.c"
+#line 1102 "parse-gram.c"
 	break;
       case 44: /* "[identifier]" */
 /* Line 833 of yacc.c  */
 #line 212 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); };
 /* Line 833 of yacc.c  */
-#line 1099 "parse-gram.c"
+#line 1109 "parse-gram.c"
 	break;
       case 45: /* "char" */
 /* Line 833 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fputs (char_name (((*yyvaluep).character)), stderr); };
 /* Line 833 of yacc.c  */
-#line 1106 "parse-gram.c"
+#line 1116 "parse-gram.c"
 	break;
       case 46: /* "epilogue" */
 /* Line 833 of yacc.c  */
 #line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 /* Line 833 of yacc.c  */
-#line 1113 "parse-gram.c"
+#line 1123 "parse-gram.c"
 	break;
       case 48: /* "identifier" */
 /* Line 833 of yacc.c  */
 #line 211 "parse-gram.y"
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
 /* Line 833 of yacc.c  */
-#line 1120 "parse-gram.c"
+#line 1130 "parse-gram.c"
 	break;
       case 49: /* "identifier:" */
 /* Line 833 of yacc.c  */
 #line 213 "parse-gram.y"
 	{ fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); };
 /* Line 833 of yacc.c  */
-#line 1127 "parse-gram.c"
+#line 1137 "parse-gram.c"
 	break;
       case 52: /* "%{...%}" */
 /* Line 833 of yacc.c  */
 #line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 /* Line 833 of yacc.c  */
-#line 1134 "parse-gram.c"
+#line 1144 "parse-gram.c"
 	break;
       case 54: /* "type" */
 /* Line 833 of yacc.c  */
 #line 214 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); };
 /* Line 833 of yacc.c  */
-#line 1141 "parse-gram.c"
+#line 1151 "parse-gram.c"
 	break;
       case 71: /* symbol.prec */
 /* Line 833 of yacc.c  */
 #line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 /* Line 833 of yacc.c  */
-#line 1148 "parse-gram.c"
+#line 1158 "parse-gram.c"
 	break;
       case 84: /* variable */
 /* Line 833 of yacc.c  */
 #line 211 "parse-gram.y"
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
 /* Line 833 of yacc.c  */
-#line 1155 "parse-gram.c"
+#line 1165 "parse-gram.c"
 	break;
       case 85: /* content.opt */
 /* Line 833 of yacc.c  */
 #line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 /* Line 833 of yacc.c  */
-#line 1162 "parse-gram.c"
+#line 1172 "parse-gram.c"
 	break;
       case 86: /* braceless */
 /* Line 833 of yacc.c  */
 #line 207 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 /* Line 833 of yacc.c  */
-#line 1169 "parse-gram.c"
+#line 1179 "parse-gram.c"
 	break;
       case 87: /* id */
 /* Line 833 of yacc.c  */
 #line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 /* Line 833 of yacc.c  */
-#line 1176 "parse-gram.c"
+#line 1186 "parse-gram.c"
 	break;
       case 88: /* id_colon */
 /* Line 833 of yacc.c  */
 #line 221 "parse-gram.y"
 	{ fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); };
 /* Line 833 of yacc.c  */
-#line 1183 "parse-gram.c"
+#line 1193 "parse-gram.c"
 	break;
       case 89: /* symbol */
 /* Line 833 of yacc.c  */
 #line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 /* Line 833 of yacc.c  */
-#line 1190 "parse-gram.c"
+#line 1200 "parse-gram.c"
 	break;
       case 90: /* string_as_id */
 /* Line 833 of yacc.c  */
 #line 220 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 /* Line 833 of yacc.c  */
-#line 1197 "parse-gram.c"
+#line 1207 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1302,12 +1312,12 @@ do {					\
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
@@ -1338,7 +1348,7 @@ int yydebug;
    required.  Return 1 if memory is exhausted.  */
 static int
 yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
-#if YYDEBUG
+#if GRAM_DEBUG
                       char const *yydebug_prefix,
                       char const *yydebug_suffix,
 #endif
@@ -1441,7 +1451,7 @@ do {                                                             \
    the parser stacks to try to find a new initial context in which the
    current lookahead is syntactically acceptable.  If it fails to find
    such a context, it discards the lookahead.  */
-#if YYDEBUG
+#if GRAM_DEBUG
 # define YY_LAC_DISCARD(Event)                                           \
 do {                                                                     \
   if (yy_lac_established)                                                \
@@ -1544,7 +1554,7 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
         else
           {
             if (yy_lac_stack_realloc (yyes_capacity, 1,
-#if YYDEBUG
+#if GRAM_DEBUG
                                       " (", ")",
 #endif
                                       yyes, yyesa, &yyesp, yyes_prev))
@@ -1746,7 +1756,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                 yysize = yysize1;
               }
         }
-# if YYDEBUG
+# if GRAM_DEBUG
       else if (yydebug)
         YYFPRINTF (stderr, "No expected tokens.\n");
 # endif
@@ -1984,7 +1994,7 @@ YYLTYPE yylloc;
   yylsp = yyls;
 
   YYLVAL_INITIALIZE ();
-#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
+#if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
   yylloc.first_line   = yylloc.last_line   = 1;
   yylloc.first_column = yylloc.last_column = 1;
@@ -2000,7 +2010,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1596 of yacc.c  */
-#line 2004 "parse-gram.c"
+#line 2014 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2888,7 +2898,7 @@ yyreduce:
 
 
 /* Line 1813 of yacc.c  */
-#line 2892 "parse-gram.c"
+#line 2902 "parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
