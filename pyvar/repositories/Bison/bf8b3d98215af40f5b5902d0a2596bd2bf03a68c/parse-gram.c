@@ -214,7 +214,7 @@
 static YYLTYPE lloc_default (YYLTYPE const *, int);
 
 #define YY_LOCATION_PRINT(File, Loc) \
-          location_print (File, Loc)
+	  location_print (File, Loc)
 
 static void version_check (location const *loc, char const *version);
 
@@ -222,7 +222,7 @@ static void version_check (location const *loc, char const *version);
    FIXME: depends on the undocumented availability of YYLLOC.  */
 #undef  yyerror
 #define yyerror(Msg) \
-        gram_error (&yylloc, Msg)
+	gram_error (&yylloc, Msg)
 static void gram_error (location const *, char const *);
 
 static void add_param (char const *, char *, location);
@@ -233,6 +233,19 @@ static symbol *current_lhs;
 static location current_lhs_location;
 static int current_prec = 0;
 
+#ifdef UINT_FAST8_MAX
+# define YYTYPE_UINT8 uint_fast8_t
+#endif
+#ifdef INT_FAST8_MAX
+# define YYTYPE_INT8 int_fast8_t
+#endif
+#ifdef UINT_FAST16_MAX
+# define YYTYPE_UINT16 uint_fast16_t
+#endif
+#ifdef INT_FAST16_MAX
+# define YYTYPE_INT16 int_fast16_t
+#endif
+
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -252,9 +265,9 @@ static int current_prec = 0;
 # define YYTOKEN_TABLE 0
 #endif
 
-#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-typedef union YYSTYPE 
-#line 82 "parse-gram.y"
+#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
+typedef union YYSTYPE
+#line 95 "parse-gram.y"
 {
   symbol *symbol;
   symbol_list *list;
@@ -263,15 +276,15 @@ typedef union YYSTYPE
   assoc assoc;
   uniqstr uniqstr;
 }
-/* Line 197 of yacc.c.  */
-#line 268 "parse-gram.c"
+/* Line 198 of yacc.c.  */
+#line 281 "parse-gram.c"
 	YYSTYPE;
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
 
-#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
+#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
 typedef struct YYLTYPE
 {
   int first_line;
@@ -288,16 +301,47 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 220 of yacc.c.  */
-#line 293 "parse-gram.c"
+/* Line 221 of yacc.c.  */
+#line 306 "parse-gram.c"
+
+#ifdef short
+# undef short
+#endif
+
+#ifdef YYTYPE_UINT8
+typedef YYTYPE_UINT8 yytype_uint8;
+#else
+typedef unsigned char yytype_uint8;
+#endif
+
+#ifdef YYTYPE_INT8
+typedef YYTYPE_INT8 yytype_int8;
+#elif (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
+typedef signed char yytype_int8;
+#else
+typedef short int yytype_int8;
+#endif
+
+#ifdef YYTYPE_UINT16
+typedef YYTYPE_UINT16 yytype_uint16;
+#else
+typedef unsigned short int yytype_uint16;
+#endif
+
+#ifdef YYTYPE_INT16
+typedef YYTYPE_INT16 yytype_int16;
+#else
+typedef short int yytype_int16;
+#endif
 
 #ifndef YYSIZE_T
-# if defined (__SIZE_TYPE__)
+# ifdef __SIZE_TYPE__
 #  define YYSIZE_T __SIZE_TYPE__
-# elif defined (size_t)
+# elif defined size_t
 #  define YYSIZE_T size_t
-# elif ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__C99__FUNC__) \
-     || defined (__cplusplus) || defined (_MSC_VER))
+# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 #  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYSIZE_T size_t
 # else
@@ -320,7 +364,7 @@ typedef struct YYLTYPE
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
-#ifndef lint
+#if ! defined lint || defined __GNUC__
 # define YYUSE(e) ((void) (e))
 #else
 # define YYUSE(e) /* empty */
@@ -330,8 +374,8 @@ typedef struct YYLTYPE
 #ifndef lint
 # define YYID(n) (n)
 #else
-#if (defined (__STDC__) || defined (__C99__FUNC__) \
-     || defined (__cplusplus) || defined (_MSC_VER))
+#if (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 static int
 YYID (int i)
 #else
@@ -344,7 +388,7 @@ YYID (i)
 }
 #endif
 
-#if ! defined (yyoverflow) || YYERROR_VERBOSE
+#if ! defined yyoverflow || YYERROR_VERBOSE
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
 
@@ -352,17 +396,17 @@ YYID (i)
 #  if YYSTACK_USE_ALLOCA
 #   ifdef __GNUC__
 #    define YYSTACK_ALLOC __builtin_alloca
-#   elif defined (__BUILTIN_VA_ARG_INCR)
+#   elif defined __BUILTIN_VA_ARG_INCR
 #    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
-#   elif defined (_AIX)
+#   elif defined _AIX
 #    define YYSTACK_ALLOC __alloca
-#   elif defined (_MSC_VER)
+#   elif defined _MSC_VER
 #    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
 #    define alloca _alloca
 #   else
 #    define YYSTACK_ALLOC alloca
-#    if ! defined (_ALLOCA_H) && ! defined (_STDLIB_H) && (defined (__STDC__) || defined (__C99__FUNC__) \
-     || defined (__cplusplus) || defined (_MSC_VER))
+#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 #     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
 #     ifndef _STDLIB_H
 #      define _STDLIB_H 1
@@ -393,15 +437,15 @@ extern "C" {
 #  endif
 #  ifndef YYMALLOC
 #   define YYMALLOC malloc
-#   if ! defined (malloc) && ! defined (_STDLIB_H) && (defined (__STDC__) || defined (__C99__FUNC__) \
-     || defined (__cplusplus) || defined (_MSC_VER))
+#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
 #  ifndef YYFREE
 #   define YYFREE free
-#   if ! defined (free) && ! defined (_STDLIB_H) && (defined (__STDC__) || defined (__C99__FUNC__) \
-     || defined (__cplusplus) || defined (_MSC_VER))
+#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 void free (void *); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
@@ -409,18 +453,18 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 }
 #  endif
 # endif
-#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */
+#endif /* ! defined yyoverflow || YYERROR_VERBOSE */
 
 
-#if (! defined (yyoverflow) \
-     && (! defined (__cplusplus) \
-	 || (defined (YYLTYPE_IS_TRIVIAL) && YYLTYPE_IS_TRIVIAL \
-             && defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))
+#if (! defined yyoverflow \
+     && (! defined __cplusplus \
+	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
+	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))
 
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
 {
-  short int yyss;
+  yytype_int16 yyss;
   YYSTYPE yyvs;
     YYLTYPE yyls;
 };
@@ -431,13 +475,13 @@ union yyalloc
 /* The size of an array large to enough to hold all stacks, each with
    N elements.  */
 # define YYSTACK_BYTES(N) \
-     ((N) * (sizeof (short int) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
+     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
       + 2 * YYSTACK_GAP_MAXIMUM)
 
 /* Copy COUNT objects from FROM to TO.  The source and destination do
    not overlap.  */
 # ifndef YYCOPY
-#  if defined (__GNUC__) && 1 < __GNUC__
+#  if defined __GNUC__ && 1 < __GNUC__
 #   define YYCOPY(To, From, Count) \
       __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
 #  else
@@ -470,13 +514,6 @@ union yyalloc
 
 #endif
 
-#if (defined (__STDC__) || defined (__C99__FUNC__) \
-     || defined (__cplusplus) || defined (_MSC_VER))
-   typedef signed char yysigned_char;
-#else
-   typedef short int yysigned_char;
-#endif
-
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
@@ -499,7 +536,7 @@ union yyalloc
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
-static const unsigned char yytranslate[] =
+static const yytype_uint8 yytranslate[] =
 {
        0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
        2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
@@ -537,7 +574,7 @@ static const unsigned char yytranslate[] =
 #if YYDEBUG
 /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
    YYRHS.  */
-static const unsigned char yyprhs[] =
+static const yytype_uint8 yyprhs[] =
 {
        0,     0,     3,     8,     9,    12,    14,    16,    18,    21,
       25,    27,    29,    32,    35,    39,    41,    43,    45,    47,
@@ -551,7 +588,7 @@ static const unsigned char yyprhs[] =
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
-static const yysigned_char yyrhs[] =
+static const yytype_int8 yyrhs[] =
 {
       53,     0,    -1,    54,    48,    66,    76,    -1,    -1,    54,
       55,    -1,    56,    -1,    49,    -1,    17,    -1,    19,    75,
@@ -577,17 +614,17 @@ static const yysigned_char yyrhs[] =
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
-static const unsigned short int yyrline[] =
+static const yytype_uint16 yyrline[] =
 {
-       0,   192,   192,   200,   202,   206,   207,   208,   209,   210,
-     211,   212,   213,   214,   215,   216,   221,   225,   226,   227,
-     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
-     238,   242,   243,   244,   248,   264,   271,   278,   282,   289,
-     289,   294,   294,   299,   309,   324,   325,   326,   330,   331,
-     337,   338,   343,   347,   352,   358,   364,   375,   376,   385,
-     386,   392,   393,   394,   401,   401,   405,   406,   407,   412,
-     413,   415,   417,   419,   421,   426,   427,   431,   437,   446,
-     451,   453
+       0,   205,   205,   213,   215,   219,   220,   221,   222,   227,
+     228,   229,   230,   231,   232,   233,   238,   242,   243,   244,
+     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
+     255,   259,   260,   261,   265,   281,   288,   295,   299,   306,
+     306,   311,   311,   316,   326,   341,   342,   343,   347,   348,
+     354,   355,   360,   364,   369,   375,   381,   392,   393,   402,
+     403,   409,   410,   411,   418,   418,   422,   423,   424,   429,
+     430,   432,   434,   436,   438,   443,   444,   448,   454,   463,
+     468,   470
 };
 #endif
 
@@ -621,7 +658,7 @@ static const char *const yytname[] =
 # ifdef YYPRINT
 /* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
    token YYLEX-NUM.  */
-static const unsigned short int yytoknum[] =
+static const yytype_uint16 yytoknum[] =
 {
        0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
@@ -633,7 +670,7 @@ static const unsigned short int yytoknum[] =
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
-static const unsigned char yyr1[] =
+static const yytype_uint8 yyr1[] =
 {
        0,    52,    53,    54,    54,    55,    55,    55,    55,    55,
       55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
@@ -647,7 +684,7 @@ static const unsigned char yyr1[] =
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
-static const unsigned char yyr2[] =
+static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     2,     3,
        1,     1,     2,     2,     3,     1,     1,     1,     1,     3,
@@ -663,7 +700,7 @@ static const unsigned char yyr2[] =
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
    STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
    means the default is an error.  */
-static const unsigned char yydefact[] =
+static const yytype_uint8 yydefact[] =
 {
        3,     0,     0,     1,    41,    39,     0,     0,     0,    34,
       45,    46,    47,     7,    37,     0,    10,    11,     0,     0,
@@ -679,7 +716,7 @@ static const unsigned char yydefact[] =
 };
 
 /* YYDEFGOTO[NTERM-NUM].  */
-static const yysigned_char yydefgoto[] =
+static const yytype_int8 yydefgoto[] =
 {
       -1,     1,     2,    41,    67,    43,    47,    46,    44,    45,
       72,    51,    75,    76,    68,    69,    70,    85,    94,    95,
@@ -689,7 +726,7 @@ static const yysigned_char yydefgoto[] =
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
 #define YYPACT_NINF -69
-static const yysigned_char yypact[] =
+static const yytype_int8 yypact[] =
 {
      -69,     5,   112,   -69,   -69,   -69,   -35,     0,     0,   -69,
      -69,   -69,   -69,   -69,   -69,    13,   -69,   -69,    20,    31,
@@ -705,7 +742,7 @@ static const yysigned_char yypact[] =
 };
 
 /* YYPGOTO[NTERM-NUM].  */
-static const yysigned_char yypgoto[] =
+static const yytype_int8 yypgoto[] =
 {
      -69,   -69,   -69,   -69,    47,   -69,   -69,   -69,   -69,   -69,
      -69,    -7,   -58,     7,   -69,   -15,   -69,   -69,   -69,   -44,
@@ -717,7 +754,7 @@ static const yysigned_char yypgoto[] =
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
 #define YYTABLE_NINF -81
-static const yysigned_char yytable[] =
+static const yytype_int8 yytable[] =
 {
       64,    54,    49,    49,    73,     3,    92,    48,    74,    49,
       91,    98,    99,   100,   101,   102,    55,    79,    93,    93,
@@ -738,7 +775,7 @@ static const yysigned_char yytable[] =
       39,    40
 };
 
-static const yysigned_char yycheck[] =
+static const yytype_int8 yycheck[] =
 {
       34,     8,     3,     3,    42,     0,    74,    42,    46,     3,
        4,    44,    45,    14,    15,    16,     3,    51,    76,    77,
@@ -761,7 +798,7 @@ static const yysigned_char yycheck[] =
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
-static const unsigned char yystos[] =
+static const yytype_uint8 yystos[] =
 {
        0,    53,    54,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
@@ -850,8 +887,8 @@ while (YYID (0))
 # if YYLTYPE_IS_TRIVIAL
 #  define YY_LOCATION_PRINT(File, Loc)			\
      fprintf (File, "%d.%d-%d.%d",			\
-              (Loc).first_line, (Loc).first_column,	\
-              (Loc).last_line,  (Loc).last_column)
+	      (Loc).first_line, (Loc).first_column,	\
+	      (Loc).last_line,  (Loc).last_column)
 # else
 #  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
 # endif
@@ -886,7 +923,7 @@ do {									  \
     {									  \
       YYFPRINTF (stderr, "%s ", Title);					  \
       yy_symbol_print (stderr,						  \
-                  Type, Value, Location); \
+		  Type, Value, Location); \
       YYFPRINTF (stderr, "\n");						  \
     }									  \
 } while (YYID (0))
@@ -897,8 +934,8 @@ do {									  \
 `--------------------------------*/
 
 /*ARGSUSED*/
-#if (defined (__STDC__) || defined (__C99__FUNC__) \
-     || defined (__cplusplus) || defined (_MSC_VER))
+#if (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 static void
 yy_symbol_value_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep, const YYLTYPE * const yylocationp)
 #else
@@ -910,106 +947,109 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     const YYLTYPE * const yylocationp;
 #endif
 {
-  YYUSE (yyvaluep);
+  if (!yyvaluep)
+    return;
   YYUSE (yylocationp);
 # ifdef YYPRINT
   if (yytype < YYNTOKENS)
     YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
+# else
+  YYUSE (yyoutput);
 # endif
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 169 "parse-gram.y"
-        { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 925 "parse-gram.c"
-        break;
-      case 4: /* "\"integer\"" */
 #line 182 "parse-gram.y"
-        { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 930 "parse-gram.c"
-        break;
+	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
+#line 965 "parse-gram.c"
+	break;
+      case 4: /* "\"integer\"" */
+#line 195 "parse-gram.y"
+	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
+#line 970 "parse-gram.c"
+	break;
       case 8: /* "\"%destructor {...}\"" */
-#line 171 "parse-gram.y"
-        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 935 "parse-gram.c"
-        break;
+#line 184 "parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 975 "parse-gram.c"
+	break;
       case 9: /* "\"%printer {...}\"" */
-#line 175 "parse-gram.y"
-        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 940 "parse-gram.c"
-        break;
+#line 188 "parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 980 "parse-gram.c"
+	break;
       case 10: /* "\"%union {...}\"" */
-#line 176 "parse-gram.y"
-        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 945 "parse-gram.c"
-        break;
+#line 189 "parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 985 "parse-gram.c"
+	break;
       case 26: /* "\"%initial-action {...}\"" */
-#line 172 "parse-gram.y"
-        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 950 "parse-gram.c"
-        break;
+#line 185 "parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 990 "parse-gram.c"
+	break;
       case 27: /* "\"%lex-param {...}\"" */
-#line 173 "parse-gram.y"
-        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 955 "parse-gram.c"
-        break;
+#line 186 "parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 995 "parse-gram.c"
+	break;
       case 34: /* "\"%parse-param {...}\"" */
-#line 174 "parse-gram.y"
-        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 960 "parse-gram.c"
-        break;
+#line 187 "parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1000 "parse-gram.c"
+	break;
       case 42: /* "\"type\"" */
-#line 180 "parse-gram.y"
-        { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 965 "parse-gram.c"
-        break;
+#line 193 "parse-gram.y"
+	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
+#line 1005 "parse-gram.c"
+	break;
       case 46: /* "\"identifier\"" */
-#line 184 "parse-gram.y"
-        { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 970 "parse-gram.c"
-        break;
+#line 197 "parse-gram.y"
+	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
+#line 1010 "parse-gram.c"
+	break;
       case 47: /* "\"identifier:\"" */
-#line 186 "parse-gram.y"
-        { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 975 "parse-gram.c"
-        break;
+#line 199 "parse-gram.y"
+	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
+#line 1015 "parse-gram.c"
+	break;
       case 49: /* "\"%{...%}\"" */
-#line 178 "parse-gram.y"
-        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 980 "parse-gram.c"
-        break;
+#line 191 "parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1020 "parse-gram.c"
+	break;
       case 50: /* "\"epilogue\"" */
-#line 178 "parse-gram.y"
-        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 985 "parse-gram.c"
-        break;
+#line 191 "parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1025 "parse-gram.c"
+	break;
       case 51: /* "\"{...}\"" */
-#line 177 "parse-gram.y"
-        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 990 "parse-gram.c"
-        break;
+#line 190 "parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1030 "parse-gram.c"
+	break;
       case 72: /* "symbol" */
-#line 184 "parse-gram.y"
-        { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 995 "parse-gram.c"
-        break;
+#line 197 "parse-gram.y"
+	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
+#line 1035 "parse-gram.c"
+	break;
       case 73: /* "action" */
-#line 177 "parse-gram.y"
-        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1000 "parse-gram.c"
-        break;
+#line 190 "parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1040 "parse-gram.c"
+	break;
       case 74: /* "string_as_id" */
-#line 184 "parse-gram.y"
-        { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1005 "parse-gram.c"
-        break;
+#line 197 "parse-gram.y"
+	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
+#line 1045 "parse-gram.c"
+	break;
       case 75: /* "string_content" */
-#line 169 "parse-gram.y"
-        { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1010 "parse-gram.c"
-        break;
+#line 182 "parse-gram.y"
+	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
+#line 1050 "parse-gram.c"
+	break;
       default:
-        break;
+	break;
     }
 }
 
@@ -1018,8 +1058,8 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 | Print this symbol on YYOUTPUT.  |
 `--------------------------------*/
 
-#if (defined (__STDC__) || defined (__C99__FUNC__) \
-     || defined (__cplusplus) || defined (_MSC_VER))
+#if (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 static void
 yy_symbol_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep, const YYLTYPE * const yylocationp)
 #else
@@ -1047,15 +1087,15 @@ yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
 | TOP (included).                                                   |
 `------------------------------------------------------------------*/
 
-#if (defined (__STDC__) || defined (__C99__FUNC__) \
-     || defined (__cplusplus) || defined (_MSC_VER))
+#if (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 static void
-yy_stack_print (short int *bottom, short int *top)
+yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
 #else
 static void
 yy_stack_print (bottom, top)
-    short int *bottom;
-    short int *top;
+    yytype_int16 *bottom;
+    yytype_int16 *top;
 #endif
 {
   YYFPRINTF (stderr, "Stack now");
@@ -1075,14 +1115,14 @@ do {								\
 | Report that the YYRULE is going to be reduced.  |
 `------------------------------------------------*/
 
-#if (defined (__STDC__) || defined (__C99__FUNC__) \
-     || defined (__cplusplus) || defined (_MSC_VER))
+#if (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 static void
 yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
 #else
 static void
 yy_reduce_print (yyvsp, yylsp, yyrule
-                   )
+		   )
     YYSTYPE *yyvsp;
     YYLTYPE *yylsp;
     int yyrule;
@@ -1092,14 +1132,14 @@ yy_reduce_print (yyvsp, yylsp, yyrule
   int yyi;
   unsigned long int yylno = yyrline[yyrule];
   YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
-             yyrule - 1, yylno);
+	     yyrule - 1, yylno);
   /* The symbols being reduced.  */
   for (yyi = 0; yyi < yynrhs; yyi++)
     {
       fprintf (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
-                       &(yyvsp[(yyi + 1) - (yynrhs)])
-                       , &(yylsp[(yyi + 1) - (yynrhs)])	               );
+		       &(yyvsp[(yyi + 1) - (yynrhs)])
+		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
       fprintf (stderr, "\n");
     }
 }
@@ -1142,12 +1182,12 @@ int yydebug;
 #if YYERROR_VERBOSE
 
 # ifndef yystrlen
-#  if defined (__GLIBC__) && defined (_STRING_H)
+#  if defined __GLIBC__ && defined _STRING_H
 #   define yystrlen strlen
 #  else
 /* Return the length of YYSTR.  */
-#if (defined (__STDC__) || defined (__C99__FUNC__) \
-     || defined (__cplusplus) || defined (_MSC_VER))
+#if (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 static YYSIZE_T
 yystrlen (const char *yystr)
 #else
@@ -1165,13 +1205,13 @@ yystrlen (yystr)
 # endif
 
 # ifndef yystpcpy
-#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
+#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
 #   define yystpcpy stpcpy
 #  else
 /* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
    YYDEST.  */
-#if (defined (__STDC__) || defined (__C99__FUNC__) \
-     || defined (__cplusplus) || defined (_MSC_VER))
+#if (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 static char *
 yystpcpy (char *yydest, const char *yysrc)
 #else
@@ -1267,7 +1307,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 
 # if 0
       /* This is so xgettext sees the translatable formats that are
-         constructed on the fly.  */
+	 constructed on the fly.  */
       YY_("syntax error, unexpected %s");
       YY_("syntax error, unexpected %s, expecting %s");
       YY_("syntax error, unexpected %s, expecting %s or %s");
@@ -1280,13 +1320,13 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       static char const yyexpecting[] = ", expecting %s";
       static char const yyor[] = " or %s";
       char yyformat[sizeof yyunexpected
-                    + sizeof yyexpecting - 1
-                    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
-                       * (sizeof yyor - 1))];
+		    + sizeof yyexpecting - 1
+		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
+		       * (sizeof yyor - 1))];
       char const *yyprefix = yyexpecting;
 
       /* Start YYX at -YYN if negative to avoid negative indexes in
-         YYCHECK.  */
+	 YYCHECK.  */
       int yyxbegin = yyn < 0 ? -yyn : 0;
 
       /* Stay within bounds of both yycheck and yytname.  */
@@ -1298,22 +1338,22 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       yyfmt = yystpcpy (yyformat, yyunexpected);
 
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-        if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
-          {
-            if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
-              {
-                yycount = 1;
-                yysize = yysize0;
-                yyformat[sizeof yyunexpected - 1] = '\0';
-                break;
-              }
-            yyarg[yycount++] = yytname[yyx];
-            yysize1 = yysize + yytnamerr (0, yytname[yyx]);
-            yysize_overflow |= (yysize1 < yysize);
-            yysize = yysize1;
-            yyfmt = yystpcpy (yyfmt, yyprefix);
-            yyprefix = yyor;
-          }
+	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+	  {
+	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
+	      {
+		yycount = 1;
+		yysize = yysize0;
+		yyformat[sizeof yyunexpected - 1] = '\0';
+		break;
+	      }
+	    yyarg[yycount++] = yytname[yyx];
+	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
+	    yysize_overflow |= (yysize1 < yysize);
+	    yysize = yysize1;
+	    yyfmt = yystpcpy (yyfmt, yyprefix);
+	    yyprefix = yyor;
+	  }
 
       yyf = YY_(yyformat);
       yysize1 = yysize + yystrlen (yyf);
@@ -1325,25 +1365,25 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 
       if (yyresult)
 	{
-          /* Avoid sprintf, as that infringes on the user's name space.
-             Don't have undefined behavior even if the translation
-             produced a string with the wrong number of "%s"s.  */
-          char *yyp = yyresult;
-          int yyi = 0;
-          while ((*yyp = *yyf) != '\0')
-            {
-              if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
-                {
-                  yyp += yytnamerr (yyp, yyarg[yyi++]);
-                  yyf += 2;
-                }
-              else
-                {
-                  yyp++;
-                  yyf++;
-                }
-            }
-        }
+	  /* Avoid sprintf, as that infringes on the user's name space.
+	     Don't have undefined behavior even if the translation
+	     produced a string with the wrong number of "%s"s.  */
+	  char *yyp = yyresult;
+	  int yyi = 0;
+	  while ((*yyp = *yyf) != '\0')
+	    {
+	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
+		{
+		  yyp += yytnamerr (yyp, yyarg[yyi++]);
+		  yyf += 2;
+		}
+	      else
+		{
+		  yyp++;
+		  yyf++;
+		}
+	    }
+	}
       return yysize;
     }
 }
@@ -1355,8 +1395,8 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 `-----------------------------------------------*/
 
 /*ARGSUSED*/
-#if (defined (__STDC__) || defined (__C99__FUNC__) \
-     || defined (__cplusplus) || defined (_MSC_VER))
+#if (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 static void
 yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
 #else
@@ -1379,7 +1419,7 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
     {
 
       default:
-        break;
+	break;
     }
 }
 
@@ -1387,13 +1427,13 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
 /* Prevent warnings from -Wmissing-prototypes.  */
 
 #ifdef YYPARSE_PARAM
-#if defined (__STDC__) || defined (__cplusplus)
+#if defined __STDC__ || defined __cplusplus
 int yyparse (void *YYPARSE_PARAM);
 #else
 int yyparse ();
 #endif
 #else /* ! YYPARSE_PARAM */
-#if defined (__STDC__) || defined (__cplusplus)
+#if defined __STDC__ || defined __cplusplus
 int yyparse (void);
 #else
 int yyparse ();
@@ -1410,8 +1450,8 @@ int yyparse ();
 `----------*/
 
 #ifdef YYPARSE_PARAM
-#if (defined (__STDC__) || defined (__C99__FUNC__) \
-     || defined (__cplusplus) || defined (_MSC_VER))
+#if (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 int
 yyparse (void *YYPARSE_PARAM)
 #else
@@ -1420,8 +1460,8 @@ yyparse (YYPARSE_PARAM)
     void *YYPARSE_PARAM;
 #endif
 #else /* ! YYPARSE_PARAM */
-#if (defined (__STDC__) || defined (__C99__FUNC__) \
-     || defined (__cplusplus) || defined (_MSC_VER))
+#if (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
 int
 yyparse (void)
 #else
@@ -1465,9 +1505,9 @@ YYLTYPE yylloc;
      to reallocate them elsewhere.  */
 
   /* The state stack.  */
-  short int yyssa[YYINITDEPTH];
-  short int *yyss = yyssa;
-  short int *yyssp;
+  yytype_int16 yyssa[YYINITDEPTH];
+  yytype_int16 *yyss = yyssa;
+  yytype_int16 *yyssp;
 
   /* The semantic value stack.  */
   YYSTYPE yyvsa[YYINITDEPTH];
@@ -1517,7 +1557,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code.  */
-#line 72 "parse-gram.y"
+#line 85 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1525,8 +1565,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 1056 of yacc.c.  */
-#line 1530 "parse-gram.c"
+/* Line 1081 of yacc.c.  */
+#line 1570 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1552,7 +1592,7 @@ YYLTYPE yylloc;
 	   these so that the &'s don't force the real ones into
 	   memory.  */
 	YYSTYPE *yyvs1 = yyvs;
-	short int *yyss1 = yyss;
+	yytype_int16 *yyss1 = yyss;
 	YYLTYPE *yyls1 = yyls;
 
 	/* Each stack pointer address is followed by the size of the
@@ -1580,7 +1620,7 @@ YYLTYPE yylloc;
 	yystacksize = YYMAXDEPTH;
 
       {
-	short int *yyss1 = yyss;
+	yytype_int16 *yyss1 = yyss;
 	union yyalloc *yyptr =
 	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
 	if (! yyptr)
@@ -1706,144 +1746,147 @@ yyreduce:
   yyval = yyvsp[1-yylen];
 
   /* Default location.  */
-  YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);
+  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
   YY_REDUCE_PRINT (yyn);
   switch (yyn)
     {
         case 6:
-#line 207 "parse-gram.y"
+#line 220 "parse-gram.y"
     { prologue_augment ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 7:
-#line 208 "parse-gram.y"
+#line 221 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 209 "parse-gram.y"
-    { muscle_insert ((yyvsp[(2) - (2)].chars), "1"); }
+#line 223 "parse-gram.y"
+    {
+      static char one[] = "1";
+      muscle_insert ((yyvsp[(2) - (2)].chars), one);
+    }
     break;
 
   case 9:
-#line 210 "parse-gram.y"
+#line 227 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 10:
-#line 211 "parse-gram.y"
+#line 228 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 11:
-#line 212 "parse-gram.y"
+#line 229 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-#line 213 "parse-gram.y"
+#line 230 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-#line 214 "parse-gram.y"
+#line 231 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-#line 215 "parse-gram.y"
+#line 232 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 15:
-#line 217 "parse-gram.y"
+#line 234 "parse-gram.y"
     {
-    nondeterministic_parser = true;
-    glr_parser = true;
-  }
+      nondeterministic_parser = true;
+      glr_parser = true;
+    }
     break;
 
   case 16:
-#line 222 "parse-gram.y"
+#line 239 "parse-gram.y"
     {
-    muscle_code_grow ("initial_action", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
-  }
+      muscle_code_grow ("initial_action", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
+    }
     break;
 
   case 17:
-#line 225 "parse-gram.y"
+#line 242 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 18:
-#line 226 "parse-gram.y"
+#line 243 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 19:
-#line 227 "parse-gram.y"
+#line 244 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 20:
-#line 228 "parse-gram.y"
+#line 245 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 21:
-#line 229 "parse-gram.y"
+#line 246 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 22:
-#line 230 "parse-gram.y"
+#line 247 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-#line 231 "parse-gram.y"
+#line 248 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 24:
-#line 232 "parse-gram.y"
+#line 249 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 25:
-#line 233 "parse-gram.y"
+#line 250 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 26:
-#line 234 "parse-gram.y"
+#line 251 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 27:
-#line 235 "parse-gram.y"
+#line 252 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 28:
-#line 236 "parse-gram.y"
+#line 253 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 29:
-#line 237 "parse-gram.y"
+#line 254 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 33:
-#line 245 "parse-gram.y"
+#line 262 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
   case 34:
-#line 249 "parse-gram.y"
+#line 266 "parse-gram.y"
     {
       char const *body = (yyvsp[(1) - (1)].chars);
 
@@ -1862,7 +1905,7 @@ yyreduce:
     break;
 
   case 35:
-#line 265 "parse-gram.y"
+#line 282 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
@@ -1872,7 +1915,7 @@ yyreduce:
     break;
 
   case 36:
-#line 272 "parse-gram.y"
+#line 289 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
@@ -1882,26 +1925,26 @@ yyreduce:
     break;
 
   case 37:
-#line 279 "parse-gram.y"
+#line 296 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 38:
-#line 283 "parse-gram.y"
+#line 300 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 39:
-#line 289 "parse-gram.y"
+#line 306 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 40:
-#line 290 "parse-gram.y"
+#line 307 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1909,12 +1952,12 @@ yyreduce:
     break;
 
   case 41:
-#line 294 "parse-gram.y"
+#line 311 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 42:
-#line 295 "parse-gram.y"
+#line 312 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1922,7 +1965,7 @@ yyreduce:
     break;
 
   case 43:
-#line 300 "parse-gram.y"
+#line 317 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -1932,7 +1975,7 @@ yyreduce:
     break;
 
   case 44:
-#line 310 "parse-gram.y"
+#line 327 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1947,49 +1990,49 @@ yyreduce:
     break;
 
   case 45:
-#line 324 "parse-gram.y"
+#line 341 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 46:
-#line 325 "parse-gram.y"
+#line 342 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 47:
-#line 326 "parse-gram.y"
+#line 343 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 48:
-#line 330 "parse-gram.y"
+#line 347 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 49:
-#line 331 "parse-gram.y"
+#line 348 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 50:
-#line 337 "parse-gram.y"
+#line 354 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 51:
-#line 338 "parse-gram.y"
+#line 355 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 52:
-#line 344 "parse-gram.y"
+#line 361 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
      }
     break;
 
   case 53:
-#line 348 "parse-gram.y"
+#line 365 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -1997,7 +2040,7 @@ yyreduce:
     break;
 
   case 54:
-#line 353 "parse-gram.y"
+#line 370 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2006,7 +2049,7 @@ yyreduce:
     break;
 
   case 55:
-#line 359 "parse-gram.y"
+#line 376 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2015,7 +2058,7 @@ yyreduce:
     break;
 
   case 56:
-#line 365 "parse-gram.y"
+#line 382 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2025,74 +2068,74 @@ yyreduce:
     break;
 
   case 63:
-#line 395 "parse-gram.y"
+#line 412 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 64:
-#line 401 "parse-gram.y"
+#line 418 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 66:
-#line 405 "parse-gram.y"
+#line 422 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
-#line 406 "parse-gram.y"
+#line 423 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 69:
-#line 412 "parse-gram.y"
+#line 429 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 70:
-#line 414 "parse-gram.y"
+#line 431 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 71:
-#line 416 "parse-gram.y"
+#line 433 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 72:
-#line 418 "parse-gram.y"
+#line 435 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 73:
-#line 420 "parse-gram.y"
+#line 437 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 74:
-#line 422 "parse-gram.y"
+#line 439 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 75:
-#line 426 "parse-gram.y"
+#line 443 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 76:
-#line 427 "parse-gram.y"
+#line 444 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 77:
-#line 432 "parse-gram.y"
+#line 449 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 78:
-#line 438 "parse-gram.y"
+#line 455 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2100,12 +2143,12 @@ yyreduce:
     break;
 
   case 79:
-#line 447 "parse-gram.y"
+#line 464 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 81:
-#line 454 "parse-gram.y"
+#line 471 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       scanner_last_string_free ();
@@ -2113,8 +2156,8 @@ yyreduce:
     break;
 
 
-/* Line 1245 of yacc.c.  */
-#line 2118 "parse-gram.c"
+/* Line 1270 of yacc.c.  */
+#line 2161 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2194,15 +2237,15 @@ yyerrlab:
 	 error, discard it.  */
 
       if (yychar <= YYEOF)
-        {
+	{
 	  /* Return failure if at end of input.  */
 	  if (yychar == YYEOF)
 	    YYABORT;
-        }
+	}
       else
 	{
 	  yydestruct ("Error: discarding",
-                      yytoken, &yylval, &yylloc);
+		      yytoken, &yylval, &yylloc);
 	  yychar = YYEMPTY;
 	}
     }
@@ -2259,7 +2302,7 @@ yyerrlab1:
 
       yyerror_range[0] = *yylsp;
       yydestruct ("Error: popping",
-                  yystos[yystate], yyvsp, yylsp);
+		  yystos[yystate], yyvsp, yylsp);
       YYPOPSTACK (1);
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
@@ -2273,7 +2316,7 @@ yyerrlab1:
   yyerror_range[1] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
      the look-ahead.  YYLOC is available though.  */
-  YYLLOC_DEFAULT (yyloc, yyerror_range - 1, 2);
+  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
   *++yylsp = yyloc;
 
   /* Shift the error token.  */
@@ -2333,7 +2376,7 @@ yyreturn:
 }
 
 
-#line 460 "parse-gram.y"
+#line 477 "parse-gram.y"
 
 
 
