@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.6.2.834-6d7b9.  */
+/* A Bison parser, made by GNU Bison 2.6.2.847-e4c0-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.2.834-6d7b9"
+#define YYBISON_VERSION "2.6.2.847-e4c0-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -128,7 +128,7 @@ static void gram_error (location const *, char const *);
 static char const *char_name (char);
 
 /* Line 331 of yacc.c  */
-#line 131 "src/parse-gram.c"
+#line 132 "src/parse-gram.c"
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -159,7 +159,7 @@ extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
 /* Line 345 of yacc.c  */
-#line 222 "src/parse-gram.y"
+#line 223 "src/parse-gram.y"
 
 # ifndef PARAM_TYPE
 #  define PARAM_TYPE
@@ -174,7 +174,7 @@ extern int gram_debug;
 
 
 /* Line 345 of yacc.c  */
-#line 177 "src/parse-gram.c"
+#line 178 "src/parse-gram.c"
 
 /* Tokens.  */
 #ifndef YYTOKENTYPE
@@ -301,7 +301,7 @@ extern int gram_debug;
 typedef union YYSTYPE
 {
 /* Line 345 of yacc.c  */
-#line 108 "src/parse-gram.y"
+#line 109 "src/parse-gram.y"
 
   assoc assoc;
   char *code;
@@ -314,16 +314,16 @@ typedef union YYSTYPE
   unsigned char character;
 
 /* Line 345 of yacc.c  */
-#line 246 "src/parse-gram.y"
+#line 247 "src/parse-gram.y"
 
   param_type param;
 
 /* Line 345 of yacc.c  */
-#line 425 "src/parse-gram.y"
+#line 426 "src/parse-gram.y"
 code_props_type code_type;
 
 /* Line 345 of yacc.c  */
-#line 326 "src/parse-gram.c"
+#line 327 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define YYSTYPE_IS_DECLARED 1
@@ -349,10 +349,10 @@ int gram_parse (void);
 /* Copy the second part of user declarations.  */
 
 /* Line 348 of yacc.c  */
-#line 352 "src/parse-gram.c"
+#line 353 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
 /* Line 349 of yacc.c  */
-#line 57 "src/parse-gram.y"
+#line 58 "src/parse-gram.y"
 
   static int current_prec = 0;
   static location current_lhs_location;
@@ -385,7 +385,7 @@ int gram_parse (void);
   #define YYTYPE_UINT8 uint_fast8_t
 
 /* Line 349 of yacc.c  */
-#line 235 "src/parse-gram.y"
+#line 236 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -398,7 +398,7 @@ int gram_parse (void);
 
 
 /* Line 349 of yacc.c  */
-#line 401 "src/parse-gram.c"
+#line 402 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -633,18 +633,18 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   271,   271,   279,   281,   285,   286,   296,   300,   305,
-     306,   311,   316,   317,   318,   319,   320,   325,   334,   335,
-     336,   337,   338,   339,   340,   341,   341,   342,   343,   367,
-     368,   369,   370,   374,   375,   384,   385,   386,   390,   402,
-     406,   410,   417,   428,   429,   439,   440,   444,   456,   456,
-     461,   461,   466,   477,   492,   493,   494,   495,   499,   500,
-     505,   507,   512,   513,   518,   520,   525,   526,   530,   531,
-     535,   536,   537,   542,   547,   552,   558,   564,   575,   576,
-     585,   586,   592,   593,   594,   601,   601,   609,   610,   611,
-     616,   618,   620,   622,   624,   626,   628,   633,   635,   645,
-     646,   651,   652,   653,   662,   682,   684,   693,   698,   699,
-     704,   711,   713
+       0,   272,   272,   280,   282,   286,   287,   297,   301,   306,
+     307,   312,   317,   318,   319,   320,   321,   326,   335,   336,
+     337,   338,   339,   340,   341,   342,   342,   343,   344,   368,
+     369,   370,   371,   375,   376,   385,   386,   387,   391,   403,
+     407,   411,   418,   429,   430,   440,   441,   445,   457,   457,
+     462,   462,   467,   478,   493,   494,   495,   496,   500,   501,
+     506,   508,   513,   514,   519,   521,   526,   527,   531,   532,
+     536,   537,   538,   543,   548,   553,   559,   565,   576,   577,
+     586,   587,   593,   594,   595,   602,   602,   610,   611,   612,
+     617,   619,   621,   623,   625,   627,   629,   634,   636,   646,
+     647,   652,   653,   654,   663,   683,   685,   694,   699,   700,
+     705,   712,   714
 };
 #endif
 
@@ -995,95 +995,95 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
     {
             case 3: // "string"
 /* Line 707 of yacc.c  */
-#line 195 "src/parse-gram.y"
+#line 196 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
 /* Line 707 of yacc.c  */
-#line 1001 "src/parse-gram.c"
+#line 1002 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
 /* Line 707 of yacc.c  */
-#line 208 "src/parse-gram.y"
+#line 209 "src/parse-gram.y"
         { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
 /* Line 707 of yacc.c  */
-#line 1009 "src/parse-gram.c"
+#line 1010 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
 /* Line 707 of yacc.c  */
-#line 204 "src/parse-gram.y"
+#line 205 "src/parse-gram.y"
         { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 707 of yacc.c  */
-#line 1017 "src/parse-gram.c"
+#line 1018 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
 /* Line 707 of yacc.c  */
-#line 197 "src/parse-gram.y"
+#line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 707 of yacc.c  */
-#line 1025 "src/parse-gram.c"
+#line 1026 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
 /* Line 707 of yacc.c  */
-#line 202 "src/parse-gram.y"
+#line 203 "src/parse-gram.y"
         { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
 /* Line 707 of yacc.c  */
-#line 1033 "src/parse-gram.c"
+#line 1034 "src/parse-gram.c"
         break;
 
             case 43: // "char"
 /* Line 707 of yacc.c  */
-#line 189 "src/parse-gram.y"
+#line 190 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), yyo); }
 /* Line 707 of yacc.c  */
-#line 1041 "src/parse-gram.c"
+#line 1042 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
 /* Line 707 of yacc.c  */
-#line 197 "src/parse-gram.y"
+#line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 707 of yacc.c  */
-#line 1049 "src/parse-gram.c"
+#line 1050 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
 /* Line 707 of yacc.c  */
-#line 201 "src/parse-gram.y"
+#line 202 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
 /* Line 707 of yacc.c  */
-#line 1057 "src/parse-gram.c"
+#line 1058 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
 /* Line 707 of yacc.c  */
-#line 203 "src/parse-gram.y"
+#line 204 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 707 of yacc.c  */
-#line 1065 "src/parse-gram.c"
+#line 1066 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
 /* Line 707 of yacc.c  */
-#line 197 "src/parse-gram.y"
+#line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 707 of yacc.c  */
-#line 1073 "src/parse-gram.c"
+#line 1074 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
 /* Line 707 of yacc.c  */
-#line 205 "src/parse-gram.y"
+#line 206 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 707 of yacc.c  */
-#line 1081 "src/parse-gram.c"
+#line 1082 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
 /* Line 707 of yacc.c  */
-#line 251 "src/parse-gram.y"
+#line 252 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
     {
@@ -1097,87 +1097,87 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
     }
 }
 /* Line 707 of yacc.c  */
-#line 1100 "src/parse-gram.c"
+#line 1101 "src/parse-gram.c"
         break;
 
             case 64: // code_props_type
 /* Line 707 of yacc.c  */
-#line 426 "src/parse-gram.y"
+#line 427 "src/parse-gram.y"
         { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
 /* Line 707 of yacc.c  */
-#line 1108 "src/parse-gram.c"
+#line 1109 "src/parse-gram.c"
         break;
 
             case 73: // symbol.prec
 /* Line 707 of yacc.c  */
-#line 211 "src/parse-gram.y"
+#line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 707 of yacc.c  */
-#line 1116 "src/parse-gram.c"
+#line 1117 "src/parse-gram.c"
         break;
 
             case 77: // tag
 /* Line 707 of yacc.c  */
-#line 205 "src/parse-gram.y"
+#line 206 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 707 of yacc.c  */
-#line 1124 "src/parse-gram.c"
+#line 1125 "src/parse-gram.c"
         break;
 
             case 87: // variable
 /* Line 707 of yacc.c  */
-#line 201 "src/parse-gram.y"
+#line 202 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
 /* Line 707 of yacc.c  */
-#line 1132 "src/parse-gram.c"
+#line 1133 "src/parse-gram.c"
         break;
 
             case 88: // content.opt
 /* Line 707 of yacc.c  */
-#line 197 "src/parse-gram.y"
+#line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 707 of yacc.c  */
-#line 1140 "src/parse-gram.c"
+#line 1141 "src/parse-gram.c"
         break;
 
             case 89: // braceless
 /* Line 707 of yacc.c  */
-#line 197 "src/parse-gram.y"
+#line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 707 of yacc.c  */
-#line 1148 "src/parse-gram.c"
+#line 1149 "src/parse-gram.c"
         break;
 
             case 90: // id
 /* Line 707 of yacc.c  */
-#line 211 "src/parse-gram.y"
+#line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 707 of yacc.c  */
-#line 1156 "src/parse-gram.c"
+#line 1157 "src/parse-gram.c"
         break;
 
             case 91: // id_colon
 /* Line 707 of yacc.c  */
-#line 212 "src/parse-gram.y"
+#line 213 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 707 of yacc.c  */
-#line 1164 "src/parse-gram.c"
+#line 1165 "src/parse-gram.c"
         break;
 
             case 92: // symbol
 /* Line 707 of yacc.c  */
-#line 211 "src/parse-gram.y"
+#line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 707 of yacc.c  */
-#line 1172 "src/parse-gram.c"
+#line 1173 "src/parse-gram.c"
         break;
 
             case 93: // string_as_id
 /* Line 707 of yacc.c  */
-#line 211 "src/parse-gram.y"
+#line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 707 of yacc.c  */
-#line 1180 "src/parse-gram.c"
+#line 1181 "src/parse-gram.c"
         break;
 
       default:
@@ -1825,7 +1825,7 @@ YYLTYPE yylloc;
   int yyn;
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
-  int yytoken;
+  int yytoken = 0;
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;
@@ -1844,7 +1844,6 @@ YYLTYPE yylloc;
      Keep to zero when no symbol should be popped.  */
   int yylen = 0;
 
-  yytoken = 0;
   yyss = yyssa;
   yyvs = yyvsa;
   yyls = yylsa;
@@ -1877,15 +1876,15 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1463 of yacc.c  */
-#line 100 "src/parse-gram.y"
+/* Line 1462 of yacc.c  */
+#line 101 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1463 of yacc.c  */
+/* Line 1462 of yacc.c  */
 #line 1889 "src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
@@ -2078,8 +2077,8 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1678 of yacc.c  */
-#line 287 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 288 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2089,107 +2088,107 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2093 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1678 of yacc.c  */
-#line 297 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 298 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2103 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1678 of yacc.c  */
-#line 301 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 302 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2114 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1678 of yacc.c  */
-#line 305 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 306 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2122 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1678 of yacc.c  */
-#line 307 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 308 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2133 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1678 of yacc.c  */
-#line 312 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 313 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2144 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1678 of yacc.c  */
-#line 316 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 317 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2152 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1678 of yacc.c  */
-#line 317 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 318 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2160 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1678 of yacc.c  */
-#line 318 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 319 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2168 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1678 of yacc.c  */
-#line 319 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 320 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2176 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1678 of yacc.c  */
-#line 321 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 322 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2187 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1678 of yacc.c  */
-#line 326 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 327 "src/parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2198,93 +2197,93 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2202 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1678 of yacc.c  */
-#line 334 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 335 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2210 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1678 of yacc.c  */
-#line 335 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 336 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2218 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1678 of yacc.c  */
-#line 336 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 337 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2226 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1678 of yacc.c  */
-#line 337 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 338 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2234 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1678 of yacc.c  */
-#line 338 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 339 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2242 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1678 of yacc.c  */
-#line 339 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 340 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2250 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1678 of yacc.c  */
-#line 340 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 341 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2258 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1678 of yacc.c  */
-#line 341 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 342 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2266 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1678 of yacc.c  */
-#line 341 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 342 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2274 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1678 of yacc.c  */
-#line 342 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 343 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2282 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1678 of yacc.c  */
-#line 344 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 345 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2308,63 +2307,63 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2312 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1678 of yacc.c  */
-#line 367 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 368 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2320 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1678 of yacc.c  */
-#line 368 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 369 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2328 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1678 of yacc.c  */
-#line 369 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 370 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2336 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1678 of yacc.c  */
-#line 374 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 375 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2344 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1678 of yacc.c  */
-#line 375 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 376 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2352 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1678 of yacc.c  */
-#line 387 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 388 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2362 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1678 of yacc.c  */
-#line 391 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 392 "src/parse-gram.y"
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2376,139 +2375,139 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2380 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1678 of yacc.c  */
-#line 403 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 404 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2390 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1678 of yacc.c  */
-#line 407 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 408 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2400 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1678 of yacc.c  */
-#line 411 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 412 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2413 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1678 of yacc.c  */
-#line 418 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 419 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2424 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1678 of yacc.c  */
-#line 428 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 429 "src/parse-gram.y"
     { (yyval.code_type) = destructor; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2432 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1678 of yacc.c  */
-#line 429 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 430 "src/parse-gram.y"
     { (yyval.code_type) = printer; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2440 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1678 of yacc.c  */
-#line 439 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 440 "src/parse-gram.y"
     {}
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2448 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1678 of yacc.c  */
-#line 440 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 441 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2456 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1678 of yacc.c  */
-#line 445 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 446 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2468 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1678 of yacc.c  */
-#line 456 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 457 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2476 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1678 of yacc.c  */
-#line 457 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 458 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2487 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1678 of yacc.c  */
-#line 461 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 462 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2495 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1678 of yacc.c  */
-#line 462 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 463 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2506 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1678 of yacc.c  */
-#line 467 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 468 "src/parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2516,13 +2515,13 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2520 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1678 of yacc.c  */
-#line 478 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 479 "src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2534,358 +2533,358 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2538 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1678 of yacc.c  */
-#line 492 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 493 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2546 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1678 of yacc.c  */
-#line 493 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 494 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2554 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1678 of yacc.c  */
-#line 494 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 495 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2562 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1678 of yacc.c  */
-#line 495 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 496 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2570 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1678 of yacc.c  */
-#line 499 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 500 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2578 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1678 of yacc.c  */
-#line 500 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 501 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2586 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1678 of yacc.c  */
-#line 506 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 507 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2594 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1678 of yacc.c  */
-#line 508 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 509 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2602 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1678 of yacc.c  */
-#line 512 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 513 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2610 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1678 of yacc.c  */
-#line 513 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 514 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2618 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1678 of yacc.c  */
-#line 519 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 520 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2626 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1678 of yacc.c  */
-#line 521 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 522 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2634 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1678 of yacc.c  */
-#line 525 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 526 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2642 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1678 of yacc.c  */
-#line 526 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 527 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2650 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1678 of yacc.c  */
-#line 530 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 531 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2658 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1678 of yacc.c  */
-#line 531 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 532 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2666 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1678 of yacc.c  */
-#line 536 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 537 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2674 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1678 of yacc.c  */
-#line 537 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 538 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new (""); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2682 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1678 of yacc.c  */
-#line 543 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 544 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2693 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1678 of yacc.c  */
-#line 548 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 549 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2704 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1678 of yacc.c  */
-#line 553 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 554 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2716 "src/parse-gram.c"
     break;
 
   case 76:
-/* Line 1678 of yacc.c  */
-#line 559 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 560 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2728 "src/parse-gram.c"
     break;
 
   case 77:
-/* Line 1678 of yacc.c  */
-#line 565 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 566 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2741 "src/parse-gram.c"
     break;
 
   case 84:
-/* Line 1678 of yacc.c  */
-#line 595 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 596 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2751 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1678 of yacc.c  */
-#line 601 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 602 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2759 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1678 of yacc.c  */
-#line 602 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 603 "src/parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2770 "src/parse-gram.c"
     break;
 
   case 87:
-/* Line 1678 of yacc.c  */
-#line 609 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 610 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2778 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1678 of yacc.c  */
-#line 610 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 611 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2786 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1678 of yacc.c  */
-#line 616 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 617 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2795 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1678 of yacc.c  */
-#line 619 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 620 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2803 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1678 of yacc.c  */
-#line 621 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 622 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2811 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1678 of yacc.c  */
-#line 623 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 624 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2819 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1678 of yacc.c  */
-#line 625 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 626 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2827 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1678 of yacc.c  */
-#line 627 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 628 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2835 "src/parse-gram.c"
     break;
 
   case 96:
-/* Line 1678 of yacc.c  */
-#line 629 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 630 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2843 "src/parse-gram.c"
     break;
 
   case 97:
-/* Line 1678 of yacc.c  */
-#line 633 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 634 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2851 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1678 of yacc.c  */
-#line 635 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 636 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2859 "src/parse-gram.c"
     break;
 
   case 100:
-/* Line 1678 of yacc.c  */
-#line 646 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 647 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2867 "src/parse-gram.c"
     break;
 
   case 101:
-/* Line 1678 of yacc.c  */
-#line 651 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 652 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2875 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1678 of yacc.c  */
-#line 652 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 653 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2883 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1678 of yacc.c  */
-#line 663 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 664 "src/parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2894,52 +2893,52 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2898 "src/parse-gram.c"
     break;
 
   case 105:
-/* Line 1678 of yacc.c  */
-#line 683 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 684 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2906 "src/parse-gram.c"
     break;
 
   case 106:
-/* Line 1678 of yacc.c  */
-#line 685 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 686 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2918 "src/parse-gram.c"
     break;
 
   case 107:
-/* Line 1678 of yacc.c  */
-#line 693 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 694 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2926 "src/parse-gram.c"
     break;
 
   case 110:
-/* Line 1678 of yacc.c  */
-#line 705 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 706 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2937 "src/parse-gram.c"
     break;
 
   case 112:
-/* Line 1678 of yacc.c  */
-#line 714 "src/parse-gram.y"
+/* Line 1677 of yacc.c  */
+#line 715 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2948,12 +2947,12 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2952 "src/parse-gram.c"
     break;
 
 
-/* Line 1678 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 2957 "src/parse-gram.c"
         default: break;
       }
@@ -3199,8 +3198,8 @@ yyreturn:
 #endif
   return yyresult;
 }
-/* Line 1936 of yacc.c  */
-#line 724 "src/parse-gram.y"
+/* Line 1935 of yacc.c  */
+#line 725 "src/parse-gram.y"
 
 
 
