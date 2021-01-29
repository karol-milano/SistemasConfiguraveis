@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.6.2.957-b074-dirty.  */
+/* A Bison parser, made by GNU Bison 2.6.5.977-6d58-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.2.957-b074-dirty"
+#define YYBISON_VERSION "2.6.5.977-6d58-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -72,7 +72,7 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 353 of yacc.c  */
+/* Line 355 of yacc.c  */
 #line 1 "src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -129,7 +129,7 @@ static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
 
-/* Line 353 of yacc.c  */
+/* Line 355 of yacc.c  */
 #line 134 "src/parse-gram.c"
 
 # ifndef YY_NULL
@@ -168,7 +168,7 @@ static char const *char_name (char);
 extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
-/* Line 369 of yacc.c  */
+/* Line 371 of yacc.c  */
 #line 223 "src/parse-gram.y"
 
 # ifndef PARAM_TYPE
@@ -183,7 +183,7 @@ extern int gram_debug;
 # endif
 
 
-/* Line 369 of yacc.c  */
+/* Line 371 of yacc.c  */
 #line 188 "src/parse-gram.c"
 
 /* Tokens.  */
@@ -310,7 +310,7 @@ extern int gram_debug;
 #if ! defined GRAM_STYPE && ! defined GRAM_STYPE_IS_DECLARED
 typedef union GRAM_STYPE
 {
-/* Line 369 of yacc.c  */
+/* Line 371 of yacc.c  */
 #line 109 "src/parse-gram.y"
 
   assoc assoc;
@@ -323,16 +323,16 @@ typedef union GRAM_STYPE
   uniqstr uniqstr;
   unsigned char character;
 
-/* Line 369 of yacc.c  */
+/* Line 371 of yacc.c  */
 #line 247 "src/parse-gram.y"
 
   param_type param;
 
-/* Line 369 of yacc.c  */
+/* Line 371 of yacc.c  */
 #line 423 "src/parse-gram.y"
 code_props_type code_type;
 
-/* Line 369 of yacc.c  */
+/* Line 371 of yacc.c  */
 #line 337 "src/parse-gram.c"
 } GRAM_STYPE;
 # define GRAM_STYPE_IS_TRIVIAL 1
@@ -358,10 +358,10 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-/* Line 372 of yacc.c  */
+/* Line 374 of yacc.c  */
 #line 363 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
-/* Line 373 of yacc.c  */
+/* Line 375 of yacc.c  */
 #line 58 "src/parse-gram.y"
 
   static int current_prec = 0;
@@ -394,7 +394,7 @@ int gram_parse (void);
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-/* Line 373 of yacc.c  */
+/* Line 375 of yacc.c  */
 #line 236 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
@@ -407,7 +407,7 @@ int gram_parse (void);
   static param_type current_param = param_none;
 
 
-/* Line 373 of yacc.c  */
+/* Line 375 of yacc.c  */
 #line 412 "src/parse-gram.c"
 
 #ifdef short
@@ -899,7 +899,7 @@ do                                                              \
     }                                                           \
 while (0)
 
-
+/* Error token number */
 #define YYTERROR        1
 #define YYERRCODE       256
 
@@ -930,16 +930,21 @@ while (0)
 
 #define YYRHSLOC(Rhs, K) ((Rhs)[K])
 
+
 /* YY_LOCATION_PRINT -- Print the location on the stream.
    This macro was not mandated originally: define only if we know
    we won't break user code: when these are the locations we know.  */
 
 #ifndef YY_LOCATION_PRINT
 # if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
-#  define YY_LOCATION_PRINT(File, Loc)                  \
-     fprintf (File, "%d.%d-%d.%d",                      \
-              (Loc).first_line, (Loc).first_column,     \
-              (Loc).last_line,  (Loc).last_column)
+#  define YY_LOCATION_PRINT(File, Loc)                                   \
+  do {                                                                   \
+    fprintf (File, "%d.%d", (Loc).first_line, (Loc).first_column);       \
+    if ((Loc).first_line < (Loc).last_line)                              \
+      fprintf (File, "-%d.%d", (Loc).last_line,  (Loc).last_column - 1); \
+    else if ((Loc).first_column < (Loc).last_column - 1)                 \
+      fprintf (File, "-%d", (Loc).last_column - 1);                      \
+  } while (0)
 # else
 #  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
 # endif
@@ -998,95 +1003,95 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
             case 3: // "string"
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 196 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-/* Line 727 of yacc.c  */
-#line 1006 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1011 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 209 "src/parse-gram.y"
         { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-/* Line 727 of yacc.c  */
-#line 1014 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1019 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 205 "src/parse-gram.y"
         { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 727 of yacc.c  */
-#line 1022 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1027 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 727 of yacc.c  */
-#line 1030 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1035 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 203 "src/parse-gram.y"
         { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 727 of yacc.c  */
-#line 1038 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1043 "src/parse-gram.c"
         break;
 
             case 43: // "char"
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 190 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), yyo); }
-/* Line 727 of yacc.c  */
-#line 1046 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1051 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 727 of yacc.c  */
-#line 1054 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1059 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 202 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 727 of yacc.c  */
-#line 1062 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1067 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 204 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 727 of yacc.c  */
-#line 1070 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1075 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 727 of yacc.c  */
-#line 1078 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1083 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 206 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 727 of yacc.c  */
-#line 1086 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1091 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 252 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
@@ -1100,88 +1105,88 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-/* Line 727 of yacc.c  */
-#line 1105 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1110 "src/parse-gram.c"
         break;
 
             case 64: // code_props_type
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 424 "src/parse-gram.y"
         { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-/* Line 727 of yacc.c  */
-#line 1113 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1118 "src/parse-gram.c"
         break;
 
             case 73: // symbol.prec
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 727 of yacc.c  */
-#line 1121 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1126 "src/parse-gram.c"
         break;
 
             case 77: // tag
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 206 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 727 of yacc.c  */
-#line 1129 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1134 "src/parse-gram.c"
         break;
 
             case 87: // variable
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 202 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 727 of yacc.c  */
-#line 1137 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1142 "src/parse-gram.c"
         break;
 
             case 88: // content.opt
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 727 of yacc.c  */
-#line 1145 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1150 "src/parse-gram.c"
         break;
 
             case 89: // braceless
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 727 of yacc.c  */
-#line 1153 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1158 "src/parse-gram.c"
         break;
 
             case 90: // id
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 727 of yacc.c  */
-#line 1161 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1166 "src/parse-gram.c"
         break;
 
             case 91: // id_colon
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 213 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 727 of yacc.c  */
-#line 1169 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1174 "src/parse-gram.c"
         break;
 
             case 92: // symbol
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 727 of yacc.c  */
-#line 1177 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1182 "src/parse-gram.c"
         break;
 
             case 93: // string_as_id
-/* Line 727 of yacc.c  */
+/* Line 711 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 727 of yacc.c  */
-#line 1185 "src/parse-gram.c"
+/* Line 711 of yacc.c  */
+#line 1190 "src/parse-gram.c"
         break;
 
       default:
@@ -1781,10 +1786,11 @@ yyparse (void)
 int yychar;
 
 
-#if defined __GNUC__ && (4 < __GNUC__ + (6 <= __GNUC_MINOR__))
+#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
 /* Suppress an incorrect diagnostic about yylval being uninitialized.  */
 # define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
     _Pragma ("GCC diagnostic push") \
+    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
     _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
 # define YY_IGNORE_MAYBE_UNINITIALIZED_END \
     _Pragma ("GCC diagnostic pop")
@@ -1792,21 +1798,26 @@ int yychar;
 /* Default value used for initialization, for pacifying older GCCs
    or non-GCC compilers.  */
 static YYSTYPE yyval_default;
-# define YYLVAL_INITIALIZE() (yylval = yyval_default)
-#endif
-#ifndef YYLVAL_INITIALIZE
-# define YYLVAL_INITIALIZE()
+# define YY_INITIAL_VALUE(Value) = Value
 #endif
 #ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
 # define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
 # define YY_IGNORE_MAYBE_UNINITIALIZED_END
 #endif
+#ifndef YY_INITIAL_VALUE
+# define YY_INITIAL_VALUE(Value) /* Nothing. */
+#endif
 
 /* The semantic value of the lookahead symbol.  */
-YYSTYPE yylval;
+YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);
 
 /* Location data for the lookahead symbol.  */
-YYLTYPE yylloc;
+YYLTYPE yylloc
+# if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
+  = { 1, 1, 1, 1 }
+# endif
+;
+
 
     /* Number of syntax errors so far.  */
     int yynerrs;
@@ -1870,9 +1881,9 @@ YYLTYPE yylloc;
      Keep to zero when no symbol should be popped.  */
   int yylen = 0;
 
-  yyss = yyssa;
-  yyvs = yyvsa;
-  yyls = yylsa;
+  yyssp = yyss = yyssa;
+  yyvsp = yyvs = yyvsa;
+  yylsp = yyls = yylsa;
   yystacksize = YYINITDEPTH;
 
   yyes = yyesa;
@@ -1887,23 +1898,8 @@ YYLTYPE yylloc;
   yynerrs = 0;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
-  /* Initialize stack pointers.
-     Waste one element of value and location stack
-     so that they stay on the same level as the state stack.
-     The wasted elements are never initialized.  */
-  yyssp = yyss;
-  yyvsp = yyvs;
-  yylsp = yyls;
-
-  YYLVAL_INITIALIZE ();
-#if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
-  /* Initialize the default location before parsing starts.  */
-  yylloc.first_line   = yylloc.last_line   = 1;
-  yylloc.first_column = yylloc.last_column = 1;
-#endif
-
 /* User initialization code.  */
-/* Line 1483 of yacc.c  */
+/* Line 1452 of yacc.c  */
 #line 101 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1911,8 +1907,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1483 of yacc.c  */
-#line 1916 "src/parse-gram.c"
+/* Line 1452 of yacc.c  */
+#line 1912 "src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2106,7 +2102,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 288 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2117,98 +2113,98 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1700 of yacc.c  */
-#line 2122 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2118 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 298 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1700 of yacc.c  */
-#line 2132 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2128 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 302 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1700 of yacc.c  */
-#line 2143 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2139 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 306 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1700 of yacc.c  */
-#line 2151 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2147 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 308 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1700 of yacc.c  */
-#line 2162 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2158 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 313 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1700 of yacc.c  */
-#line 2173 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2169 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1700 of yacc.c  */
-#line 2181 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2177 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 318 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1700 of yacc.c  */
-#line 2189 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2185 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 319 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1700 of yacc.c  */
-#line 2197 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2193 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 321 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1700 of yacc.c  */
-#line 2208 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2204 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 326 "src/parse-gram.y"
     {
       code_props action;
@@ -2218,76 +2214,76 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1700 of yacc.c  */
-#line 2223 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2219 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 334 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1700 of yacc.c  */
-#line 2231 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2227 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 335 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1700 of yacc.c  */
-#line 2239 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2235 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 336 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1700 of yacc.c  */
-#line 2247 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2243 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 337 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1700 of yacc.c  */
-#line 2255 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2251 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 338 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1700 of yacc.c  */
-#line 2263 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2259 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 339 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1700 of yacc.c  */
-#line 2271 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2267 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 339 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1700 of yacc.c  */
-#line 2279 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2275 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 340 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1700 of yacc.c  */
-#line 2287 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2283 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 342 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2312,62 +2308,62 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1700 of yacc.c  */
-#line 2317 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2313 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 365 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1700 of yacc.c  */
-#line 2325 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2321 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 366 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1700 of yacc.c  */
-#line 2333 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2329 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 367 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1700 of yacc.c  */
-#line 2341 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2337 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 372 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2349 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2345 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 373 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2357 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2353 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 385 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1700 of yacc.c  */
-#line 2367 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2363 "src/parse-gram.c"
     break;
 
   case 35:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 389 "src/parse-gram.y"
     {
       code_props code;
@@ -2380,32 +2376,32 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-/* Line 1700 of yacc.c  */
-#line 2385 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2381 "src/parse-gram.c"
     break;
 
   case 36:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 401 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1700 of yacc.c  */
-#line 2395 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2391 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 405 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1700 of yacc.c  */
-#line 2405 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2401 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 409 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2413,105 +2409,105 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1700 of yacc.c  */
-#line 2418 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2414 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 416 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1700 of yacc.c  */
-#line 2429 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2425 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 426 "src/parse-gram.y"
     { (yyval.code_type) = destructor; }
-/* Line 1700 of yacc.c  */
-#line 2437 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2433 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 427 "src/parse-gram.y"
     { (yyval.code_type) = printer; }
-/* Line 1700 of yacc.c  */
-#line 2445 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2441 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 437 "src/parse-gram.y"
     {}
-/* Line 1700 of yacc.c  */
-#line 2453 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2449 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 438 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2461 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2457 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 443 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1700 of yacc.c  */
-#line 2473 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2469 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 454 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1700 of yacc.c  */
-#line 2481 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2477 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 455 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1700 of yacc.c  */
-#line 2492 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2488 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 459 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1700 of yacc.c  */
-#line 2500 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2496 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 460 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1700 of yacc.c  */
-#line 2511 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2507 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 465 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2520,12 +2516,12 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1700 of yacc.c  */
-#line 2525 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2521 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 476 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2538,202 +2534,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1700 of yacc.c  */
-#line 2543 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2539 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 490 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1700 of yacc.c  */
-#line 2551 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2547 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 491 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1700 of yacc.c  */
-#line 2559 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2555 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 492 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1700 of yacc.c  */
-#line 2567 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2563 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 493 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1700 of yacc.c  */
-#line 2575 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2571 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 497 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1700 of yacc.c  */
-#line 2583 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2579 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 498 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1700 of yacc.c  */
-#line 2591 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2587 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 504 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2599 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2595 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1700 of yacc.c  */
-#line 2607 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2603 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 510 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1700 of yacc.c  */
-#line 2615 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2611 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 511 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2623 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2619 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 517 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2631 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2627 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 519 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1700 of yacc.c  */
-#line 2639 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2635 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 523 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1700 of yacc.c  */
-#line 2647 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2643 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 524 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1700 of yacc.c  */
-#line 2655 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2651 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 528 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2663 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2659 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 529 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2671 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2667 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 534 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-/* Line 1700 of yacc.c  */
-#line 2679 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2675 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 535 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new (""); }
-/* Line 1700 of yacc.c  */
-#line 2687 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2683 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 541 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1700 of yacc.c  */
-#line 2698 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2694 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 546 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1700 of yacc.c  */
-#line 2709 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2705 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 551 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1700 of yacc.c  */
-#line 2721 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2717 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 557 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1700 of yacc.c  */
-#line 2733 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2729 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 563 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2741,154 +2737,154 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1700 of yacc.c  */
-#line 2746 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2742 "src/parse-gram.c"
     break;
 
   case 81:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 593 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1700 of yacc.c  */
-#line 2756 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2752 "src/parse-gram.c"
     break;
 
   case 82:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 599 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1700 of yacc.c  */
-#line 2764 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2760 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 600 "src/parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-/* Line 1700 of yacc.c  */
-#line 2775 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2771 "src/parse-gram.c"
     break;
 
   case 84:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 607 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2783 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2779 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 608 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2791 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2787 "src/parse-gram.c"
     break;
 
   case 87:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 614 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-/* Line 1700 of yacc.c  */
-#line 2800 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2796 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 617 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1700 of yacc.c  */
-#line 2808 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2804 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 619 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1700 of yacc.c  */
-#line 2816 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2812 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 621 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1700 of yacc.c  */
-#line 2824 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2820 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 623 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2832 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2828 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 625 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2840 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2836 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 627 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2848 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2844 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 631 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1700 of yacc.c  */
-#line 2856 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2852 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 633 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2864 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2860 "src/parse-gram.c"
     break;
 
   case 97:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 644 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1700 of yacc.c  */
-#line 2872 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2868 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 649 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1700 of yacc.c  */
-#line 2880 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2876 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 650 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1700 of yacc.c  */
-#line 2888 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2884 "src/parse-gram.c"
     break;
 
   case 101:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 661 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2898,51 +2894,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1700 of yacc.c  */
-#line 2903 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2899 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 681 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2911 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2907 "src/parse-gram.c"
     break;
 
   case 103:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 683 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1700 of yacc.c  */
-#line 2923 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2919 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 691 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1700 of yacc.c  */
-#line 2931 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2927 "src/parse-gram.c"
     break;
 
   case 107:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 703 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1700 of yacc.c  */
-#line 2942 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2938 "src/parse-gram.c"
     break;
 
   case 109:
-/* Line 1700 of yacc.c  */
+/* Line 1670 of yacc.c  */
 #line 712 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2952,13 +2948,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1700 of yacc.c  */
-#line 2957 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2953 "src/parse-gram.c"
     break;
 
 
-/* Line 1700 of yacc.c  */
-#line 2962 "src/parse-gram.c"
+/* Line 1670 of yacc.c  */
+#line 2958 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3205,7 +3201,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-/* Line 1960 of yacc.c  */
+/* Line 1930 of yacc.c  */
 #line 722 "src/parse-gram.y"
 
 
