@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.5.1.931-4323e-dirty.  */
+/* A Bison parser, made by GNU Bison 2.6.1.828-a3c9.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.5.1.931-4323e-dirty"
+#define YYBISON_VERSION "2.6.1.828-a3c9"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -70,7 +70,7 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 337 of yacc.c  */
+/* Line 331 of yacc.c  */
 #line 1 "src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -126,7 +126,7 @@ static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
 
-/* Line 337 of yacc.c  */
+/* Line 331 of yacc.c  */
 #line 131 "src/parse-gram.c"
 
 # ifndef YY_NULL
@@ -157,7 +157,7 @@ static char const *char_name (char);
 extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
-/* Line 351 of yacc.c  */
+/* Line 345 of yacc.c  */
 #line 222 "src/parse-gram.y"
 
 # ifndef PARAM_TYPE
@@ -172,7 +172,7 @@ extern int gram_debug;
 # endif
 
 
-/* Line 351 of yacc.c  */
+/* Line 345 of yacc.c  */
 #line 177 "src/parse-gram.c"
 
 /* Tokens.  */
@@ -299,7 +299,7 @@ extern int gram_debug;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 351 of yacc.c  */
+/* Line 345 of yacc.c  */
 #line 108 "src/parse-gram.y"
 
   assoc assoc;
@@ -312,16 +312,16 @@ typedef union YYSTYPE
   uniqstr uniqstr;
   unsigned char character;
 
-/* Line 351 of yacc.c  */
+/* Line 345 of yacc.c  */
 #line 246 "src/parse-gram.y"
 
   param_type param;
 
-/* Line 351 of yacc.c  */
+/* Line 345 of yacc.c  */
 #line 425 "src/parse-gram.y"
 code_props_type code_type;
 
-/* Line 351 of yacc.c  */
+/* Line 345 of yacc.c  */
 #line 326 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -341,30 +341,16 @@ typedef struct YYLTYPE
 #endif
 
 
-#ifdef YYPARSE_PARAM
-#if (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
-int gram_parse (void *YYPARSE_PARAM);
-#else
-int gram_parse ();
-#endif
-#else /* ! YYPARSE_PARAM */
-#if (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
 int gram_parse (void);
-#else
-int gram_parse ();
-#endif
-#endif /* ! YYPARSE_PARAM */
 
 #endif /* !GRAM_SRC_PARSE_GRAM_H  */
 
 /* Copy the second part of user declarations.  */
 
-/* Line 354 of yacc.c  */
-#line 366 "src/parse-gram.c"
+/* Line 348 of yacc.c  */
+#line 352 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
-/* Line 355 of yacc.c  */
+/* Line 349 of yacc.c  */
 #line 57 "src/parse-gram.y"
 
   static int current_prec = 0;
@@ -397,7 +383,7 @@ int gram_parse ();
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-/* Line 355 of yacc.c  */
+/* Line 349 of yacc.c  */
 #line 235 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
@@ -410,8 +396,8 @@ int gram_parse ();
   static param_type current_param = param_none;
 
 
-/* Line 355 of yacc.c  */
-#line 415 "src/parse-gram.c"
+/* Line 349 of yacc.c  */
+#line 401 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -425,11 +411,8 @@ typedef unsigned char yytype_uint8;
 
 #ifdef YYTYPE_INT8
 typedef YYTYPE_INT8 yytype_int8;
-#elif (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
-typedef signed char yytype_int8;
 #else
-typedef short int yytype_int8;
+typedef signed char yytype_int8;
 #endif
 
 #ifdef YYTYPE_UINT16
@@ -449,8 +432,7 @@ typedef short int yytype_int16;
 #  define YYSIZE_T __SIZE_TYPE__
 # elif defined size_t
 #  define YYSIZE_T size_t
-# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
+# elif ! defined YYSIZE_T
 #  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYSIZE_T size_t
 # else
@@ -483,15 +465,8 @@ typedef short int yytype_int16;
 #ifndef lint
 # define YYID(n) (n)
 #else
-#if (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
 static int
 YYID (int yyi)
-#else
-static int
-YYID (yyi)
-    int yyi;
-#endif
 {
   return yyi;
 }
@@ -527,15 +502,13 @@ YYID (yyi)
 #  endif
 #  ifndef YYMALLOC
 #   define YYMALLOC malloc
-#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
+#   if ! defined malloc && ! defined EXIT_SUCCESS
 void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
 #  ifndef YYFREE
 #   define YYFREE free
-#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
+#   if ! defined free && ! defined EXIT_SUCCESS
 void free (void *); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
@@ -1017,18 +990,8 @@ do {                                                                      \
 `--------------------------------*/
 
 /*ARGSUSED*/
-#if (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
 static void
 yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
-#else
-static void
-yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
-    FILE *yyoutput;
-    int yytype;
-    YYSTYPE const * const yyvaluep;
-    YYLTYPE const * const yylocationp;
-#endif
 {
   FILE *yyo = yyoutput;
   YYUSE(yyo);
@@ -1042,95 +1005,95 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
             case 3: // "string"
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 195 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-/* Line 725 of yacc.c  */
-#line 1050 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1013 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 208 "src/parse-gram.y"
         { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-/* Line 725 of yacc.c  */
-#line 1058 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1021 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 204 "src/parse-gram.y"
         { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 725 of yacc.c  */
-#line 1066 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1029 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 725 of yacc.c  */
-#line 1074 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1037 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 202 "src/parse-gram.y"
         { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 725 of yacc.c  */
-#line 1082 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1045 "src/parse-gram.c"
         break;
 
             case 43: // "char"
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 189 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), yyo); }
-/* Line 725 of yacc.c  */
-#line 1090 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1053 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 725 of yacc.c  */
-#line 1098 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1061 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 201 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 725 of yacc.c  */
-#line 1106 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1069 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 203 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 725 of yacc.c  */
-#line 1114 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1077 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 725 of yacc.c  */
-#line 1122 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1085 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 205 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 725 of yacc.c  */
-#line 1130 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1093 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 251 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
@@ -1144,88 +1107,88 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case param_none: aver (false); break;
     }
 }
-/* Line 725 of yacc.c  */
-#line 1149 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1112 "src/parse-gram.c"
         break;
 
             case 64: // code_props_type
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 426 "src/parse-gram.y"
         { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-/* Line 725 of yacc.c  */
-#line 1157 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1120 "src/parse-gram.c"
         break;
 
             case 73: // symbol.prec
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 725 of yacc.c  */
-#line 1165 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1128 "src/parse-gram.c"
         break;
 
             case 77: // tag
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 205 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 725 of yacc.c  */
-#line 1173 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1136 "src/parse-gram.c"
         break;
 
             case 87: // variable
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 201 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 725 of yacc.c  */
-#line 1181 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1144 "src/parse-gram.c"
         break;
 
             case 88: // content.opt
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 725 of yacc.c  */
-#line 1189 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1152 "src/parse-gram.c"
         break;
 
             case 89: // braceless
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 725 of yacc.c  */
-#line 1197 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1160 "src/parse-gram.c"
         break;
 
             case 90: // id
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 725 of yacc.c  */
-#line 1205 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1168 "src/parse-gram.c"
         break;
 
             case 91: // id_colon
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 725 of yacc.c  */
-#line 1213 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1176 "src/parse-gram.c"
         break;
 
             case 92: // symbol
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 725 of yacc.c  */
-#line 1221 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1184 "src/parse-gram.c"
         break;
 
             case 93: // string_as_id
-/* Line 725 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 725 of yacc.c  */
-#line 1229 "src/parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1192 "src/parse-gram.c"
         break;
 
       default:
@@ -1238,18 +1201,8 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 | Print this symbol on YYOUTPUT.  |
 `--------------------------------*/
 
-#if (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
 static void
 yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
-#else
-static void
-yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
-    FILE *yyoutput;
-    int yytype;
-    YYSTYPE const * const yyvaluep;
-    YYLTYPE const * const yylocationp;
-#endif
 {
   if (yytype < YYNTOKENS)
     YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
@@ -1267,16 +1220,8 @@ yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
 | TOP (included).                                                   |
 `------------------------------------------------------------------*/
 
-#if (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
 static void
 yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
-#else
-static void
-yy_stack_print (yybottom, yytop)
-    yytype_int16 *yybottom;
-    yytype_int16 *yytop;
-#endif
 {
   YYFPRINTF (stderr, "Stack now");
   for (; yybottom <= yytop; yybottom++)
@@ -1298,18 +1243,8 @@ do {                                                            \
 | Report that the YYRULE is going to be reduced.  |
 `------------------------------------------------*/
 
-#if (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
 static void
 yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
-#else
-static void
-yy_reduce_print (yyssp, yyvsp, yylsp, yyrule)
-    yytype_int16 *yyssp;
-    YYSTYPE *yyvsp;
-    YYLTYPE *yylsp;
-    int yyrule;
-#endif
 {
   unsigned long int yylno = yyrline[yyrule];
   int yynrhs = yyr2[yyrule];
@@ -1602,15 +1537,8 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
 #   define yystrlen strlen
 #  else
 /* Return the length of YYSTR.  */
-#if (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
 static YYSIZE_T
 yystrlen (const char *yystr)
-#else
-static YYSIZE_T
-yystrlen (yystr)
-    const char *yystr;
-#endif
 {
   YYSIZE_T yylen;
   for (yylen = 0; yystr[yylen]; yylen++)
@@ -1626,16 +1554,8 @@ yystrlen (yystr)
 #  else
 /* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
    YYDEST.  */
-#if (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
 static char *
 yystpcpy (char *yydest, const char *yysrc)
-#else
-static char *
-yystpcpy (yydest, yysrc)
-    char *yydest;
-    const char *yysrc;
-#endif
 {
   char *yyd = yydest;
   const char *yys = yysrc;
@@ -1839,18 +1759,8 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 `-----------------------------------------------*/
 
 /*ARGSUSED*/
-#if (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
 static void
 yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
-#else
-static void
-yydestruct (yymsg, yytype, yyvaluep, yylocationp)
-    const char *yymsg;
-    int yytype;
-    YYSTYPE *yyvaluep;
-    YYLTYPE *yylocationp;
-#endif
 {
   YYUSE(yyvaluep);
   YYUSE (yylocationp);
@@ -1872,27 +1782,8 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
 | yyparse.  |
 `----------*/
 
-#ifdef YYPARSE_PARAM
-#if (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
-int
-yyparse (void *YYPARSE_PARAM)
-#else
-int
-yyparse (YYPARSE_PARAM)
-    void *YYPARSE_PARAM;
-#endif
-#else /* ! YYPARSE_PARAM */
-#if (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
 int
 yyparse (void)
-#else
-int
-yyparse ()
-
-#endif
-#endif
 {
 /* The lookahead symbol.  */
 int yychar;
@@ -1998,7 +1889,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1486 of yacc.c  */
+/* Line 1473 of yacc.c  */
 #line 100 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -2006,8 +1897,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1486 of yacc.c  */
-#line 2011 "src/parse-gram.c"
+/* Line 1473 of yacc.c  */
+#line 1902 "src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2199,7 +2090,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 287 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2210,106 +2101,106 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1701 of yacc.c  */
-#line 2215 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2106 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 297 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1701 of yacc.c  */
-#line 2225 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2116 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 301 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1701 of yacc.c  */
-#line 2236 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2127 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 305 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1701 of yacc.c  */
-#line 2244 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2135 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 307 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1701 of yacc.c  */
-#line 2255 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2146 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 312 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1701 of yacc.c  */
-#line 2266 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2157 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 316 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1701 of yacc.c  */
-#line 2274 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2165 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1701 of yacc.c  */
-#line 2282 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2173 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 318 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1701 of yacc.c  */
-#line 2290 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2181 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 319 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1701 of yacc.c  */
-#line 2298 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2189 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 321 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1701 of yacc.c  */
-#line 2309 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2200 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 326 "src/parse-gram.y"
     {
       code_props action;
@@ -2319,92 +2210,92 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1701 of yacc.c  */
-#line 2324 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2215 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 334 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1701 of yacc.c  */
-#line 2332 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2223 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 335 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1701 of yacc.c  */
-#line 2340 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2231 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 336 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1701 of yacc.c  */
-#line 2348 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2239 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 337 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1701 of yacc.c  */
-#line 2356 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2247 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 338 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1701 of yacc.c  */
-#line 2364 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2255 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 339 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1701 of yacc.c  */
-#line 2372 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2263 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 340 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1701 of yacc.c  */
-#line 2380 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2271 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 341 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1701 of yacc.c  */
-#line 2388 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2279 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 341 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1701 of yacc.c  */
-#line 2396 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2287 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 342 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1701 of yacc.c  */
-#line 2404 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2295 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 344 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2429,62 +2320,62 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1701 of yacc.c  */
-#line 2434 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2325 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 367 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1701 of yacc.c  */
-#line 2442 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2333 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 368 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1701 of yacc.c  */
-#line 2450 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2341 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 369 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1701 of yacc.c  */
-#line 2458 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2349 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 374 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 2466 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2357 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 375 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 2474 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2365 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 387 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1701 of yacc.c  */
-#line 2484 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2375 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 391 "src/parse-gram.y"
     {
       code_props code;
@@ -2497,32 +2388,32 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-/* Line 1701 of yacc.c  */
-#line 2502 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2393 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 403 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1701 of yacc.c  */
-#line 2512 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2403 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 407 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1701 of yacc.c  */
-#line 2522 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2413 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 411 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2530,105 +2421,105 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1701 of yacc.c  */
-#line 2535 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2426 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 418 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1701 of yacc.c  */
-#line 2546 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2437 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 428 "src/parse-gram.y"
     { (yyval.code_type) = destructor; }
-/* Line 1701 of yacc.c  */
-#line 2554 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2445 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 429 "src/parse-gram.y"
     { (yyval.code_type) = printer; }
-/* Line 1701 of yacc.c  */
-#line 2562 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2453 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 439 "src/parse-gram.y"
     {}
-/* Line 1701 of yacc.c  */
-#line 2570 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2461 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 440 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 2578 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2469 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 445 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1701 of yacc.c  */
-#line 2590 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2481 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 456 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1701 of yacc.c  */
-#line 2598 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2489 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 457 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1701 of yacc.c  */
-#line 2609 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2500 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 461 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1701 of yacc.c  */
-#line 2617 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2508 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 462 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1701 of yacc.c  */
-#line 2628 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2519 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 467 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2637,12 +2528,12 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1701 of yacc.c  */
-#line 2642 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2533 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 478 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2655,202 +2546,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1701 of yacc.c  */
-#line 2660 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2551 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 492 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1701 of yacc.c  */
-#line 2668 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2559 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 493 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1701 of yacc.c  */
-#line 2676 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2567 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 494 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1701 of yacc.c  */
-#line 2684 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2575 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 495 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1701 of yacc.c  */
-#line 2692 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2583 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 499 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1701 of yacc.c  */
-#line 2700 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2591 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 500 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1701 of yacc.c  */
-#line 2708 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2599 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 2716 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2607 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 508 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1701 of yacc.c  */
-#line 2724 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2615 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 512 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1701 of yacc.c  */
-#line 2732 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2623 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 513 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 2740 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2631 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 519 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 2748 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2639 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 521 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1701 of yacc.c  */
-#line 2756 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2647 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 525 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1701 of yacc.c  */
-#line 2764 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2655 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 526 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1701 of yacc.c  */
-#line 2772 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2663 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 530 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 2780 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2671 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 531 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 2788 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2679 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 536 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-/* Line 1701 of yacc.c  */
-#line 2796 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2687 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 537 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new (""); }
-/* Line 1701 of yacc.c  */
-#line 2804 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2695 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 543 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1701 of yacc.c  */
-#line 2815 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2706 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 548 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1701 of yacc.c  */
-#line 2826 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2717 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 553 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1701 of yacc.c  */
-#line 2838 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2729 "src/parse-gram.c"
     break;
 
   case 76:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 559 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1701 of yacc.c  */
-#line 2850 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2741 "src/parse-gram.c"
     break;
 
   case 77:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 565 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2858,154 +2749,154 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1701 of yacc.c  */
-#line 2863 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2754 "src/parse-gram.c"
     break;
 
   case 84:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 595 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1701 of yacc.c  */
-#line 2873 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2764 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 601 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1701 of yacc.c  */
-#line 2881 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2772 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 602 "src/parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-/* Line 1701 of yacc.c  */
-#line 2892 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2783 "src/parse-gram.c"
     break;
 
   case 87:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 609 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 2900 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2791 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 610 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 2908 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2799 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 616 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-/* Line 1701 of yacc.c  */
-#line 2917 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2808 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 619 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1701 of yacc.c  */
-#line 2925 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2816 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 621 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1701 of yacc.c  */
-#line 2933 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2824 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 623 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1701 of yacc.c  */
-#line 2941 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2832 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 625 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 2949 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2840 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 627 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 2957 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2848 "src/parse-gram.c"
     break;
 
   case 96:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 629 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 2965 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2856 "src/parse-gram.c"
     break;
 
   case 97:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 633 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1701 of yacc.c  */
-#line 2973 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2864 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 635 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 2981 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2872 "src/parse-gram.c"
     break;
 
   case 100:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 646 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1701 of yacc.c  */
-#line 2989 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2880 "src/parse-gram.c"
     break;
 
   case 101:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 651 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1701 of yacc.c  */
-#line 2997 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2888 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 652 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1701 of yacc.c  */
-#line 3005 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2896 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 663 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -3015,51 +2906,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1701 of yacc.c  */
-#line 3020 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2911 "src/parse-gram.c"
     break;
 
   case 105:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 683 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 3028 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2919 "src/parse-gram.c"
     break;
 
   case 106:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 685 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1701 of yacc.c  */
-#line 3040 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2931 "src/parse-gram.c"
     break;
 
   case 107:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 693 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1701 of yacc.c  */
-#line 3048 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2939 "src/parse-gram.c"
     break;
 
   case 110:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 705 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1701 of yacc.c  */
-#line 3059 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2950 "src/parse-gram.c"
     break;
 
   case 112:
-/* Line 1701 of yacc.c  */
+/* Line 1688 of yacc.c  */
 #line 714 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -3069,13 +2960,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1701 of yacc.c  */
-#line 3074 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2965 "src/parse-gram.c"
     break;
 
 
-/* Line 1701 of yacc.c  */
-#line 3079 "src/parse-gram.c"
+/* Line 1688 of yacc.c  */
+#line 2970 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3322,7 +3213,7 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 1961 of yacc.c  */
+/* Line 1948 of yacc.c  */
 #line 724 "src/parse-gram.y"
 
 
