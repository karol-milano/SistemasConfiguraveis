@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.6.1.828-a3c9.  */
+/* A Bison parser, made by GNU Bison 2.6.1.835-7c52-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.1.828-a3c9"
+#define YYBISON_VERSION "2.6.1.835-7c52-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -455,30 +455,19 @@ typedef short int yytype_int16;
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
-#if ! defined lint || defined __GNUC__
+#ifdef __GNUC__
 # define YYUSE(e) ((void) (e))
 #else
 # define YYUSE(e) /* empty */
 #endif
 
-/* Identity function, used to suppress warnings about constant conditions.  */
-#ifndef lint
-# define YYID(n) (n)
-#else
-static int
-YYID (int yyi)
-{
-  return yyi;
-}
-#endif
-
 #if 1
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
 
 # ifdef YYSTACK_ALLOC
    /* Pacify GCC's `empty if-body' warning.  */
-#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
+#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
 #  ifndef YYSTACK_ALLOC_MAXIMUM
     /* The OS might guarantee only one guard page at the bottom of the stack,
        and a page size can be as small as 4096 bytes.  So we cannot safely
@@ -555,7 +544,7 @@ union yyalloc
         yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
         yyptr += yynewbytes / sizeof (*yyptr);                          \
       }                                                                 \
-    while (YYID (0))
+    while (0)
 
 #endif
 
@@ -574,7 +563,7 @@ union yyalloc
           for (yyi = 0; yyi < (Count); yyi++)   \
             (Dst)[yyi] = (Src)[yyi];            \
         }                                       \
-      while (YYID (0))
+      while (0)
 #  endif
 # endif
 #endif /* !YYCOPY_NEEDED */
@@ -710,7 +699,7 @@ static const yytype_uint16 yytoknum[] =
 #define YYTABLE_NINF -112
 
 #define yytable_value_is_error(yytable_value) \
-  YYID (0)
+  0
 
   /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
      STATE-NUM.    */
@@ -902,7 +891,7 @@ do                                                              \
       yyerror (YY_("syntax error: cannot back up")); \
       YYERROR;                                                  \
     }                                                           \
-while (YYID (0))
+while (0)
 
 
 #define YYTERROR        1
@@ -916,7 +905,7 @@ while (YYID (0))
 #ifndef YYLLOC_DEFAULT
 # define YYLLOC_DEFAULT(Current, Rhs, N)                                \
     do                                                                  \
-      if (YYID (N))                                                     \
+      if (N)                                                            \
         {                                                               \
           (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
           (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
@@ -930,7 +919,7 @@ while (YYID (0))
           (Current).first_column = (Current).last_column =              \
             YYRHSLOC (Rhs, 0).last_column;                              \
         }                                                               \
-    while (YYID (0))
+    while (0)
 #endif
 
 #define YYRHSLOC(Rhs, K) ((Rhs)[K])
@@ -971,7 +960,7 @@ while (YYID (0))
 do {                                            \
   if (yydebug)                                  \
     YYFPRINTF Args;                             \
-} while (YYID (0))
+} while (0)
 
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
 do {                                                                      \
@@ -982,14 +971,13 @@ do {                                                                      \
                   Type, Value, Location); \
       YYFPRINTF (stderr, "\n");                                           \
     }                                                                     \
-} while (YYID (0))
+} while (0)
 
 
 /*--------------------------------.
 | Print this symbol on YYOUTPUT.  |
 `--------------------------------*/
 
-/*ARGSUSED*/
 static void
 yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 {
@@ -1005,95 +993,95 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
             case 3: // "string"
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 195 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-/* Line 717 of yacc.c  */
-#line 1013 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1001 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 208 "src/parse-gram.y"
         { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-/* Line 717 of yacc.c  */
-#line 1021 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1009 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 204 "src/parse-gram.y"
         { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 717 of yacc.c  */
-#line 1029 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1017 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 717 of yacc.c  */
-#line 1037 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1025 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 202 "src/parse-gram.y"
         { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 717 of yacc.c  */
-#line 1045 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1033 "src/parse-gram.c"
         break;
 
             case 43: // "char"
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 189 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), yyo); }
-/* Line 717 of yacc.c  */
-#line 1053 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1041 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 717 of yacc.c  */
-#line 1061 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1049 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 201 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 717 of yacc.c  */
-#line 1069 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1057 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 203 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 717 of yacc.c  */
-#line 1077 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1065 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 717 of yacc.c  */
-#line 1085 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1073 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 205 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 717 of yacc.c  */
-#line 1093 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1081 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 251 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
@@ -1107,88 +1095,88 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-/* Line 717 of yacc.c  */
-#line 1112 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1100 "src/parse-gram.c"
         break;
 
             case 64: // code_props_type
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 426 "src/parse-gram.y"
         { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-/* Line 717 of yacc.c  */
-#line 1120 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1108 "src/parse-gram.c"
         break;
 
             case 73: // symbol.prec
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 717 of yacc.c  */
-#line 1128 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1116 "src/parse-gram.c"
         break;
 
             case 77: // tag
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 205 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 717 of yacc.c  */
-#line 1136 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1124 "src/parse-gram.c"
         break;
 
             case 87: // variable
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 201 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 717 of yacc.c  */
-#line 1144 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1132 "src/parse-gram.c"
         break;
 
             case 88: // content.opt
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 717 of yacc.c  */
-#line 1152 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1140 "src/parse-gram.c"
         break;
 
             case 89: // braceless
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 717 of yacc.c  */
-#line 1160 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1148 "src/parse-gram.c"
         break;
 
             case 90: // id
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 717 of yacc.c  */
-#line 1168 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1156 "src/parse-gram.c"
         break;
 
             case 91: // id_colon
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 717 of yacc.c  */
-#line 1176 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1164 "src/parse-gram.c"
         break;
 
             case 92: // symbol
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 717 of yacc.c  */
-#line 1184 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1172 "src/parse-gram.c"
         break;
 
             case 93: // string_as_id
-/* Line 717 of yacc.c  */
+/* Line 707 of yacc.c  */
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 717 of yacc.c  */
-#line 1192 "src/parse-gram.c"
+/* Line 707 of yacc.c  */
+#line 1180 "src/parse-gram.c"
         break;
 
       default:
@@ -1236,7 +1224,7 @@ yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
 do {                                                            \
   if (yydebug)                                                  \
     yy_stack_print ((Bottom), (Top));                           \
-} while (YYID (0))
+} while (0)
 
 
 /*------------------------------------------------.
@@ -1267,7 +1255,7 @@ yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule
 do {                                    \
   if (yydebug)                          \
     yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
-} while (YYID (0))
+} while (0)
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
@@ -1398,7 +1386,7 @@ do {                                                             \
           goto yyerrlab;                                         \
       }                                                          \
     }                                                            \
-} while (YYID (0))
+} while (0)
 
 /* Discard any previous initial lookahead context because of Event,
    which may be a lookahead change or an invalidation of the currently
@@ -1421,7 +1409,7 @@ do {                                                                     \
                    Event "\n");                                          \
       yy_lac_established = 0;                                            \
     }                                                                    \
-} while (YYID (0))
+} while (0)
 #else
 # define YY_LAC_DISCARD(Event) yy_lac_established = 0
 #endif
@@ -1758,7 +1746,6 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 | Release the memory associated to this symbol.  |
 `-----------------------------------------------*/
 
-/*ARGSUSED*/
 static void
 yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
 {
@@ -1889,7 +1876,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1473 of yacc.c  */
+/* Line 1463 of yacc.c  */
 #line 100 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1897,8 +1884,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1473 of yacc.c  */
-#line 1902 "src/parse-gram.c"
+/* Line 1463 of yacc.c  */
+#line 1889 "src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2090,7 +2077,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 287 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2101,106 +2088,106 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1688 of yacc.c  */
-#line 2106 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2093 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 297 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1688 of yacc.c  */
-#line 2116 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2103 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 301 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1688 of yacc.c  */
-#line 2127 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2114 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 305 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1688 of yacc.c  */
-#line 2135 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2122 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 307 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1688 of yacc.c  */
-#line 2146 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2133 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 312 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1688 of yacc.c  */
-#line 2157 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2144 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 316 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1688 of yacc.c  */
-#line 2165 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2152 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1688 of yacc.c  */
-#line 2173 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2160 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 318 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1688 of yacc.c  */
-#line 2181 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2168 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 319 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1688 of yacc.c  */
-#line 2189 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2176 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 321 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1688 of yacc.c  */
-#line 2200 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2187 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 326 "src/parse-gram.y"
     {
       code_props action;
@@ -2210,92 +2197,92 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1688 of yacc.c  */
-#line 2215 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2202 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 334 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1688 of yacc.c  */
-#line 2223 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2210 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 335 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1688 of yacc.c  */
-#line 2231 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2218 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 336 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1688 of yacc.c  */
-#line 2239 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2226 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 337 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1688 of yacc.c  */
-#line 2247 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2234 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 338 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1688 of yacc.c  */
-#line 2255 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2242 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 339 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1688 of yacc.c  */
-#line 2263 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2250 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 340 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1688 of yacc.c  */
-#line 2271 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2258 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 341 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1688 of yacc.c  */
-#line 2279 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2266 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 341 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1688 of yacc.c  */
-#line 2287 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2274 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 342 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1688 of yacc.c  */
-#line 2295 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2282 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 344 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2320,62 +2307,62 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1688 of yacc.c  */
-#line 2325 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2312 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 367 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1688 of yacc.c  */
-#line 2333 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2320 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 368 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1688 of yacc.c  */
-#line 2341 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2328 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 369 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1688 of yacc.c  */
-#line 2349 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2336 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 374 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2357 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2344 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 375 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2365 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2352 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 387 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1688 of yacc.c  */
-#line 2375 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2362 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 391 "src/parse-gram.y"
     {
       code_props code;
@@ -2388,32 +2375,32 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-/* Line 1688 of yacc.c  */
-#line 2393 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2380 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 403 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1688 of yacc.c  */
-#line 2403 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2390 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 407 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1688 of yacc.c  */
-#line 2413 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2400 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 411 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2421,105 +2408,105 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1688 of yacc.c  */
-#line 2426 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2413 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 418 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1688 of yacc.c  */
-#line 2437 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2424 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 428 "src/parse-gram.y"
     { (yyval.code_type) = destructor; }
-/* Line 1688 of yacc.c  */
-#line 2445 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2432 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 429 "src/parse-gram.y"
     { (yyval.code_type) = printer; }
-/* Line 1688 of yacc.c  */
-#line 2453 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2440 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 439 "src/parse-gram.y"
     {}
-/* Line 1688 of yacc.c  */
-#line 2461 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2448 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 440 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2469 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2456 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 445 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1688 of yacc.c  */
-#line 2481 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2468 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 456 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1688 of yacc.c  */
-#line 2489 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2476 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 457 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1688 of yacc.c  */
-#line 2500 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2487 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 461 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1688 of yacc.c  */
-#line 2508 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2495 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 462 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1688 of yacc.c  */
-#line 2519 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2506 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 467 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2528,12 +2515,12 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1688 of yacc.c  */
-#line 2533 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2520 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 478 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2546,202 +2533,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1688 of yacc.c  */
-#line 2551 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2538 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 492 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1688 of yacc.c  */
-#line 2559 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2546 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 493 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1688 of yacc.c  */
-#line 2567 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2554 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 494 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1688 of yacc.c  */
-#line 2575 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2562 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 495 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1688 of yacc.c  */
-#line 2583 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2570 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 499 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1688 of yacc.c  */
-#line 2591 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2578 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 500 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1688 of yacc.c  */
-#line 2599 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2586 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2607 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2594 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 508 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1688 of yacc.c  */
-#line 2615 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2602 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 512 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1688 of yacc.c  */
-#line 2623 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2610 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 513 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2631 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2618 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 519 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2639 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2626 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 521 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1688 of yacc.c  */
-#line 2647 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2634 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 525 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1688 of yacc.c  */
-#line 2655 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2642 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 526 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1688 of yacc.c  */
-#line 2663 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2650 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 530 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2671 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2658 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 531 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2679 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2666 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 536 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-/* Line 1688 of yacc.c  */
-#line 2687 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2674 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 537 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new (""); }
-/* Line 1688 of yacc.c  */
-#line 2695 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2682 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 543 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1688 of yacc.c  */
-#line 2706 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2693 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 548 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1688 of yacc.c  */
-#line 2717 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2704 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 553 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1688 of yacc.c  */
-#line 2729 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2716 "src/parse-gram.c"
     break;
 
   case 76:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 559 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1688 of yacc.c  */
-#line 2741 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2728 "src/parse-gram.c"
     break;
 
   case 77:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 565 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2749,154 +2736,154 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1688 of yacc.c  */
-#line 2754 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2741 "src/parse-gram.c"
     break;
 
   case 84:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 595 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1688 of yacc.c  */
-#line 2764 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2751 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 601 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1688 of yacc.c  */
-#line 2772 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2759 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 602 "src/parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-/* Line 1688 of yacc.c  */
-#line 2783 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2770 "src/parse-gram.c"
     break;
 
   case 87:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 609 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2791 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2778 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 610 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2799 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2786 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 616 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-/* Line 1688 of yacc.c  */
-#line 2808 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2795 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 619 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1688 of yacc.c  */
-#line 2816 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2803 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 621 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1688 of yacc.c  */
-#line 2824 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2811 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 623 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1688 of yacc.c  */
-#line 2832 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2819 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 625 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2840 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2827 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 627 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2848 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2835 "src/parse-gram.c"
     break;
 
   case 96:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 629 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2856 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2843 "src/parse-gram.c"
     break;
 
   case 97:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 633 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1688 of yacc.c  */
-#line 2864 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2851 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 635 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2872 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2859 "src/parse-gram.c"
     break;
 
   case 100:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 646 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1688 of yacc.c  */
-#line 2880 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2867 "src/parse-gram.c"
     break;
 
   case 101:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 651 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1688 of yacc.c  */
-#line 2888 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2875 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 652 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1688 of yacc.c  */
-#line 2896 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2883 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 663 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2906,51 +2893,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1688 of yacc.c  */
-#line 2911 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2898 "src/parse-gram.c"
     break;
 
   case 105:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 683 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2919 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2906 "src/parse-gram.c"
     break;
 
   case 106:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 685 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1688 of yacc.c  */
-#line 2931 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2918 "src/parse-gram.c"
     break;
 
   case 107:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 693 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1688 of yacc.c  */
-#line 2939 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2926 "src/parse-gram.c"
     break;
 
   case 110:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 705 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1688 of yacc.c  */
-#line 2950 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2937 "src/parse-gram.c"
     break;
 
   case 112:
-/* Line 1688 of yacc.c  */
+/* Line 1678 of yacc.c  */
 #line 714 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2960,13 +2947,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1688 of yacc.c  */
-#line 2965 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2952 "src/parse-gram.c"
     break;
 
 
-/* Line 1688 of yacc.c  */
-#line 2970 "src/parse-gram.c"
+/* Line 1678 of yacc.c  */
+#line 2957 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3209,11 +3196,10 @@ yyreturn:
   if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);
 #endif
-  /* Make sure YYID is used.  */
-  return YYID (yyresult);
+  return yyresult;
 }
 
-/* Line 1948 of yacc.c  */
+/* Line 1937 of yacc.c  */
 #line 724 "src/parse-gram.y"
 
 
