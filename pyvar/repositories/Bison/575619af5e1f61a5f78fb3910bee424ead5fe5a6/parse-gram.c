@@ -1,9 +1,8 @@
-/* A Bison parser, made by GNU Bison 2.4.542-10bae.  */
+/* A Bison parser, made by GNU Bison 2.4.547-d397.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
-   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
-   2007, 2008, 2009, 2010 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -45,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.542-10bae"
+#define YYBISON_VERSION "2.4.547-d397"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -77,8 +76,7 @@
 #line 1 "src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
-   Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010
-   Free Software Foundation, Inc.
+   Copyright (C) 2002-2011 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -129,7 +127,7 @@ static void gram_error (location const *, char const *);
 static char const *char_name (char);
 
 /* Line 269 of yacc.c  */
-#line 133 "src/parse-gram.c"
+#line 131 "src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -151,7 +149,7 @@ static char const *char_name (char);
 
 /* "%code requires" blocks.  */
 /* Line 289 of yacc.c  */
-#line 203 "src/parse-gram.y"
+#line 202 "src/parse-gram.y"
 
 # ifndef PARAM_TYPE
 #  define PARAM_TYPE
@@ -166,7 +164,7 @@ static char const *char_name (char);
 
 
 /* Line 289 of yacc.c  */
-#line 170 "src/parse-gram.c"
+#line 168 "src/parse-gram.c"
 
 /* Tokens.  */
 #ifndef YYTOKENTYPE
@@ -295,7 +293,7 @@ static char const *char_name (char);
 typedef union YYSTYPE
 {
 /* Line 294 of yacc.c  */
-#line 89 "src/parse-gram.y"
+#line 88 "src/parse-gram.y"
 
   assoc assoc;
   char *code;
@@ -308,13 +306,13 @@ typedef union YYSTYPE
   unsigned char character;
 
 /* Line 294 of yacc.c  */
-#line 227 "src/parse-gram.y"
+#line 226 "src/parse-gram.y"
 
   param_type param;
 
 
 /* Line 294 of yacc.c  */
-#line 318 "src/parse-gram.c"
+#line 316 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -338,10 +336,10 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 344 of yacc.c  */
-#line 342 "src/parse-gram.c"
+#line 340 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
 /* Line 345 of yacc.c  */
-#line 56 "src/parse-gram.y"
+#line 55 "src/parse-gram.y"
 
   static int current_prec = 0;
   static location current_lhs_location;
@@ -356,7 +354,7 @@ typedef struct YYLTYPE
   #define YYTYPE_UINT8 uint_fast8_t
 
 /* Line 345 of yacc.c  */
-#line 216 "src/parse-gram.y"
+#line 215 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -369,7 +367,7 @@ typedef struct YYLTYPE
 
 
 /* Line 345 of yacc.c  */
-#line 373 "src/parse-gram.c"
+#line 371 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -628,18 +626,18 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   252,   252,   260,   262,   266,   267,   277,   281,   286,
-     287,   292,   297,   298,   299,   300,   301,   306,   315,   316,
-     317,   318,   319,   320,   321,   322,   322,   323,   324,   348,
-     349,   350,   351,   355,   356,   365,   366,   367,   371,   378,
-     385,   389,   393,   400,   415,   416,   420,   432,   432,   437,
-     437,   442,   453,   468,   469,   470,   471,   475,   476,   481,
-     483,   488,   489,   494,   496,   501,   502,   506,   507,   508,
-     509,   514,   519,   524,   530,   536,   547,   548,   557,   558,
-     564,   565,   566,   573,   573,   578,   579,   580,   585,   587,
-     589,   591,   593,   595,   597,   602,   604,   614,   615,   620,
-     621,   622,   631,   651,   653,   662,   667,   668,   673,   680,
-     682
+       0,   251,   251,   259,   261,   265,   266,   276,   280,   285,
+     286,   291,   296,   297,   298,   299,   300,   305,   314,   315,
+     316,   317,   318,   319,   320,   321,   321,   322,   323,   347,
+     348,   349,   350,   354,   355,   364,   365,   366,   370,   377,
+     384,   388,   392,   399,   414,   415,   419,   431,   431,   436,
+     436,   441,   452,   467,   468,   469,   470,   474,   475,   480,
+     482,   487,   488,   493,   495,   500,   501,   505,   506,   507,
+     508,   513,   518,   523,   529,   535,   546,   547,   556,   557,
+     563,   564,   565,   572,   572,   577,   578,   579,   584,   586,
+     588,   590,   592,   594,   596,   601,   603,   613,   614,   619,
+     620,   621,   630,   650,   652,   661,   666,   667,   672,   679,
+     681
 };
 #endif
 
@@ -1016,106 +1014,106 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 3: // "string"
 
 /* Line 751 of yacc.c  */
-#line 176 "src/parse-gram.y"
+#line 175 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
 /* Line 751 of yacc.c  */
-#line 1023 "src/parse-gram.c"
+#line 1021 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
 /* Line 751 of yacc.c  */
-#line 189 "src/parse-gram.y"
+#line 188 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
 /* Line 751 of yacc.c  */
-#line 1032 "src/parse-gram.c"
+#line 1030 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
 
 /* Line 751 of yacc.c  */
-#line 185 "src/parse-gram.y"
+#line 184 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 751 of yacc.c  */
-#line 1041 "src/parse-gram.c"
+#line 1039 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
 
 /* Line 751 of yacc.c  */
-#line 178 "src/parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 751 of yacc.c  */
-#line 1050 "src/parse-gram.c"
+#line 1048 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
 
 /* Line 751 of yacc.c  */
-#line 183 "src/parse-gram.y"
+#line 182 "src/parse-gram.y"
         { fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); }
 /* Line 751 of yacc.c  */
-#line 1059 "src/parse-gram.c"
+#line 1057 "src/parse-gram.c"
         break;
 
             case 43: // "char"
 
 /* Line 751 of yacc.c  */
-#line 170 "src/parse-gram.y"
+#line 169 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
 /* Line 751 of yacc.c  */
-#line 1068 "src/parse-gram.c"
+#line 1066 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
 
 /* Line 751 of yacc.c  */
-#line 178 "src/parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 751 of yacc.c  */
-#line 1077 "src/parse-gram.c"
+#line 1075 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
 
 /* Line 751 of yacc.c  */
-#line 182 "src/parse-gram.y"
+#line 181 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 751 of yacc.c  */
-#line 1086 "src/parse-gram.c"
+#line 1084 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
 
 /* Line 751 of yacc.c  */
-#line 184 "src/parse-gram.y"
+#line 183 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 751 of yacc.c  */
-#line 1095 "src/parse-gram.c"
+#line 1093 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
 
 /* Line 751 of yacc.c  */
-#line 178 "src/parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 751 of yacc.c  */
-#line 1104 "src/parse-gram.c"
+#line 1102 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
 
 /* Line 751 of yacc.c  */
-#line 186 "src/parse-gram.y"
+#line 185 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 751 of yacc.c  */
-#line 1113 "src/parse-gram.c"
+#line 1111 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
 
 /* Line 751 of yacc.c  */
-#line 232 "src/parse-gram.y"
+#line 231 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
     {
@@ -1129,79 +1127,79 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     }
 }
 /* Line 751 of yacc.c  */
-#line 1133 "src/parse-gram.c"
+#line 1131 "src/parse-gram.c"
         break;
 
             case 72: // symbol.prec
 
 /* Line 751 of yacc.c  */
-#line 192 "src/parse-gram.y"
+#line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 751 of yacc.c  */
-#line 1142 "src/parse-gram.c"
+#line 1140 "src/parse-gram.c"
         break;
 
             case 85: // variable
 
 /* Line 751 of yacc.c  */
-#line 182 "src/parse-gram.y"
+#line 181 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 751 of yacc.c  */
-#line 1151 "src/parse-gram.c"
+#line 1149 "src/parse-gram.c"
         break;
 
             case 86: // content.opt
 
 /* Line 751 of yacc.c  */
-#line 178 "src/parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 751 of yacc.c  */
-#line 1160 "src/parse-gram.c"
+#line 1158 "src/parse-gram.c"
         break;
 
             case 87: // braceless
 
 /* Line 751 of yacc.c  */
-#line 178 "src/parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 751 of yacc.c  */
-#line 1169 "src/parse-gram.c"
+#line 1167 "src/parse-gram.c"
         break;
 
             case 88: // id
 
 /* Line 751 of yacc.c  */
-#line 192 "src/parse-gram.y"
+#line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 751 of yacc.c  */
-#line 1178 "src/parse-gram.c"
+#line 1176 "src/parse-gram.c"
         break;
 
             case 89: // id_colon
 
 /* Line 751 of yacc.c  */
-#line 193 "src/parse-gram.y"
+#line 192 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 751 of yacc.c  */
-#line 1187 "src/parse-gram.c"
+#line 1185 "src/parse-gram.c"
         break;
 
             case 90: // symbol
 
 /* Line 751 of yacc.c  */
-#line 192 "src/parse-gram.y"
+#line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 751 of yacc.c  */
-#line 1196 "src/parse-gram.c"
+#line 1194 "src/parse-gram.c"
         break;
 
             case 91: // string_as_id
 
 /* Line 751 of yacc.c  */
-#line 192 "src/parse-gram.y"
+#line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 751 of yacc.c  */
-#line 1205 "src/parse-gram.c"
+#line 1203 "src/parse-gram.c"
         break;
 
       default:
@@ -1995,16 +1993,16 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1525 of yacc.c  */
-#line 81 "src/parse-gram.y"
+/* Line 1524 of yacc.c  */
+#line 80 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1525 of yacc.c  */
-#line 2008 "src/parse-gram.c"
+/* Line 1524 of yacc.c  */
+#line 2006 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2197,8 +2195,8 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1741 of yacc.c  */
-#line 268 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 267 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2208,107 +2206,107 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1741 of yacc.c  */
-#line 2213 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2211 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1741 of yacc.c  */
-#line 278 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 277 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1741 of yacc.c  */
-#line 2223 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2221 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1741 of yacc.c  */
-#line 282 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 281 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1741 of yacc.c  */
-#line 2234 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2232 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1741 of yacc.c  */
-#line 286 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 285 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1741 of yacc.c  */
-#line 2242 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2240 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1741 of yacc.c  */
-#line 288 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 287 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1741 of yacc.c  */
-#line 2253 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2251 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1741 of yacc.c  */
-#line 293 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 292 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1741 of yacc.c  */
-#line 2264 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2262 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1741 of yacc.c  */
-#line 297 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 296 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1741 of yacc.c  */
-#line 2272 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2270 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1741 of yacc.c  */
-#line 298 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 297 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1741 of yacc.c  */
-#line 2280 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2278 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1741 of yacc.c  */
-#line 299 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 298 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1741 of yacc.c  */
-#line 2288 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2286 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1741 of yacc.c  */
-#line 300 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 299 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1741 of yacc.c  */
-#line 2296 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2294 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1741 of yacc.c  */
-#line 302 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 301 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1741 of yacc.c  */
-#line 2307 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2305 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1741 of yacc.c  */
-#line 307 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 306 "src/parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2317,93 +2315,93 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1741 of yacc.c  */
-#line 2322 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2320 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1741 of yacc.c  */
-#line 315 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 314 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1741 of yacc.c  */
-#line 2330 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2328 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1741 of yacc.c  */
-#line 316 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 315 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1741 of yacc.c  */
-#line 2338 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2336 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1741 of yacc.c  */
-#line 317 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 316 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1741 of yacc.c  */
-#line 2346 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2344 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1741 of yacc.c  */
-#line 318 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 317 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1741 of yacc.c  */
-#line 2354 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2352 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1741 of yacc.c  */
-#line 319 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 318 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1741 of yacc.c  */
-#line 2362 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2360 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1741 of yacc.c  */
-#line 320 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 319 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1741 of yacc.c  */
-#line 2370 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2368 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1741 of yacc.c  */
-#line 321 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 320 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1741 of yacc.c  */
-#line 2378 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2376 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1741 of yacc.c  */
-#line 322 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 321 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1741 of yacc.c  */
-#line 2386 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2384 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1741 of yacc.c  */
-#line 322 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 321 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1741 of yacc.c  */
-#line 2394 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2392 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1741 of yacc.c  */
-#line 323 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 322 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1741 of yacc.c  */
-#line 2402 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2400 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1741 of yacc.c  */
-#line 325 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 324 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2427,199 +2425,199 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1741 of yacc.c  */
-#line 2432 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2430 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1741 of yacc.c  */
-#line 348 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 347 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1741 of yacc.c  */
-#line 2440 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2438 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1741 of yacc.c  */
-#line 349 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 348 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1741 of yacc.c  */
-#line 2448 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2446 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1741 of yacc.c  */
-#line 350 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 349 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1741 of yacc.c  */
-#line 2456 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2454 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1741 of yacc.c  */
-#line 355 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 354 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2464 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2462 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1741 of yacc.c  */
-#line 356 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 355 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2472 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2470 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1741 of yacc.c  */
-#line 368 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 367 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1741 of yacc.c  */
-#line 2482 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2480 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1741 of yacc.c  */
-#line 372 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 371 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
 	symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1741 of yacc.c  */
-#line 2495 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2493 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1741 of yacc.c  */
-#line 379 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 378 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
 	symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1741 of yacc.c  */
-#line 2508 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2506 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1741 of yacc.c  */
-#line 386 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 385 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1741 of yacc.c  */
-#line 2518 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2516 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1741 of yacc.c  */
-#line 390 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 389 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1741 of yacc.c  */
-#line 2528 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2526 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1741 of yacc.c  */
-#line 394 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 393 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1741 of yacc.c  */
-#line 2541 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2539 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1741 of yacc.c  */
-#line 401 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 400 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1741 of yacc.c  */
-#line 2552 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2550 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1741 of yacc.c  */
-#line 415 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 414 "src/parse-gram.y"
     {}
-/* Line 1741 of yacc.c  */
-#line 2560 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2558 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1741 of yacc.c  */
-#line 416 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 415 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2568 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2566 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1741 of yacc.c  */
-#line 421 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 420 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1741 of yacc.c  */
-#line 2580 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2578 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1741 of yacc.c  */
-#line 432 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 431 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1741 of yacc.c  */
-#line 2588 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2586 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1741 of yacc.c  */
-#line 433 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 432 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1741 of yacc.c  */
-#line 2599 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2597 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1741 of yacc.c  */
-#line 437 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 436 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1741 of yacc.c  */
-#line 2607 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2605 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1741 of yacc.c  */
-#line 438 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 437 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1741 of yacc.c  */
-#line 2618 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2616 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1741 of yacc.c  */
-#line 443 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 442 "src/parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2627,13 +2625,13 @@ yyreduce:
 	symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1741 of yacc.c  */
-#line 2632 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2630 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1741 of yacc.c  */
-#line 454 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 453 "src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2645,348 +2643,348 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1741 of yacc.c  */
-#line 2650 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2648 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1741 of yacc.c  */
-#line 468 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 467 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1741 of yacc.c  */
-#line 2658 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2656 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1741 of yacc.c  */
-#line 469 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 468 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1741 of yacc.c  */
-#line 2666 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2664 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1741 of yacc.c  */
-#line 470 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 469 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1741 of yacc.c  */
-#line 2674 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2672 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1741 of yacc.c  */
-#line 471 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 470 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1741 of yacc.c  */
-#line 2682 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2680 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1741 of yacc.c  */
-#line 475 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 474 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1741 of yacc.c  */
-#line 2690 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2688 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1741 of yacc.c  */
-#line 476 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 475 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1741 of yacc.c  */
-#line 2698 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2696 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1741 of yacc.c  */
-#line 482 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 481 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2706 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2704 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1741 of yacc.c  */
-#line 484 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 483 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1741 of yacc.c  */
-#line 2714 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2712 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1741 of yacc.c  */
-#line 488 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 487 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1741 of yacc.c  */
-#line 2722 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2720 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1741 of yacc.c  */
-#line 489 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 488 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2730 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2728 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1741 of yacc.c  */
-#line 495 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 494 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2738 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2736 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1741 of yacc.c  */
-#line 497 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 496 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1741 of yacc.c  */
-#line 2746 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2744 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1741 of yacc.c  */
-#line 501 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 500 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1741 of yacc.c  */
-#line 2754 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2752 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1741 of yacc.c  */
-#line 502 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 501 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1741 of yacc.c  */
-#line 2762 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2760 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1741 of yacc.c  */
-#line 506 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 505 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2770 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2768 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1741 of yacc.c  */
-#line 507 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2778 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2776 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1741 of yacc.c  */
-#line 508 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 507 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2786 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2784 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1741 of yacc.c  */
-#line 509 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 508 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2794 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2792 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1741 of yacc.c  */
-#line 515 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 514 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1741 of yacc.c  */
-#line 2805 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2803 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1741 of yacc.c  */
-#line 520 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 519 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1741 of yacc.c  */
-#line 2816 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2814 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1741 of yacc.c  */
-#line 525 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 524 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1741 of yacc.c  */
-#line 2828 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2826 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1741 of yacc.c  */
-#line 531 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 530 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1741 of yacc.c  */
-#line 2840 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2838 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1741 of yacc.c  */
-#line 537 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 536 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1741 of yacc.c  */
-#line 2853 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2851 "src/parse-gram.c"
     break;
 
   case 82:
-/* Line 1741 of yacc.c  */
-#line 567 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 566 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1741 of yacc.c  */
-#line 2863 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2861 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1741 of yacc.c  */
-#line 573 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 572 "src/parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
-/* Line 1741 of yacc.c  */
-#line 2872 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2870 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1741 of yacc.c  */
-#line 578 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 577 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2880 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2878 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1741 of yacc.c  */
-#line 579 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 578 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2888 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2886 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1741 of yacc.c  */
-#line 585 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 584 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
-/* Line 1741 of yacc.c  */
-#line 2897 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2895 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1741 of yacc.c  */
-#line 588 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 587 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1741 of yacc.c  */
-#line 2905 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2903 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1741 of yacc.c  */
-#line 590 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 589 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1741 of yacc.c  */
-#line 2913 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2911 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1741 of yacc.c  */
-#line 592 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 591 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1741 of yacc.c  */
-#line 2921 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2919 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1741 of yacc.c  */
-#line 594 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 593 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2929 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2927 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1741 of yacc.c  */
-#line 596 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 595 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2937 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2935 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1741 of yacc.c  */
-#line 598 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 597 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2945 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2943 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1741 of yacc.c  */
-#line 602 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 601 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1741 of yacc.c  */
-#line 2953 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2951 "src/parse-gram.c"
     break;
 
   case 96:
-/* Line 1741 of yacc.c  */
-#line 604 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 603 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 2961 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2959 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1741 of yacc.c  */
-#line 615 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 614 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1741 of yacc.c  */
-#line 2969 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2967 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1741 of yacc.c  */
-#line 620 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 619 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1741 of yacc.c  */
-#line 2977 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2975 "src/parse-gram.c"
     break;
 
   case 100:
-/* Line 1741 of yacc.c  */
-#line 621 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 620 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1741 of yacc.c  */
-#line 2985 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2983 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1741 of yacc.c  */
-#line 632 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 631 "src/parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2995,52 +2993,52 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1741 of yacc.c  */
-#line 3000 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 2998 "src/parse-gram.c"
     break;
 
   case 103:
-/* Line 1741 of yacc.c  */
-#line 652 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 651 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 3008 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 3006 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1741 of yacc.c  */
-#line 654 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 653 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1741 of yacc.c  */
-#line 3020 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 3018 "src/parse-gram.c"
     break;
 
   case 105:
-/* Line 1741 of yacc.c  */
-#line 662 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 661 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1741 of yacc.c  */
-#line 3028 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 3026 "src/parse-gram.c"
     break;
 
   case 108:
-/* Line 1741 of yacc.c  */
-#line 674 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 673 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1741 of yacc.c  */
-#line 3039 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 3037 "src/parse-gram.c"
     break;
 
   case 110:
-/* Line 1741 of yacc.c  */
-#line 683 "src/parse-gram.y"
+/* Line 1740 of yacc.c  */
+#line 682 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -3049,13 +3047,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1741 of yacc.c  */
-#line 3054 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 3052 "src/parse-gram.c"
     break;
 
 
-/* Line 1741 of yacc.c  */
-#line 3059 "src/parse-gram.c"
+/* Line 1740 of yacc.c  */
+#line 3057 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3302,8 +3300,8 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 2001 of yacc.c  */
-#line 693 "src/parse-gram.y"
+/* Line 2000 of yacc.c  */
+#line 692 "src/parse-gram.y"
 
 
 
