@@ -1,9 +1,8 @@
-/* A Bison parser, made by GNU Bison 2.4.457-4395a.  */
+/* A Bison parser, made by GNU Bison 2.4.462-882b.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
-   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
-   2007, 2008, 2009 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989-1990, 2000-2010 Free Software Foundation, Inc.
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -45,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.457-4395a"
+#define YYBISON_VERSION "2.4.462-882b"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -73,12 +72,11 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 253 of yacc.c  */
+/* Line 252 of yacc.c  */
 #line 1 "src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
-   Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009 Free Software
-   Foundation, Inc.
+   Copyright (C) 2002-2010 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -128,8 +126,8 @@ static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
 
-/* Line 253 of yacc.c  */
-#line 133 "src/parse-gram.c"
+/* Line 252 of yacc.c  */
+#line 131 "src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -150,8 +148,8 @@ static char const *char_name (char);
 #endif
 
 /* "%code requires" blocks.  */
-/* Line 273 of yacc.c  */
-#line 202 "src/parse-gram.y"
+/* Line 272 of yacc.c  */
+#line 201 "src/parse-gram.y"
 
 # ifndef PARAM_TYPE
 #  define PARAM_TYPE
@@ -165,8 +163,8 @@ static char const *char_name (char);
 # endif
 
 
-/* Line 273 of yacc.c  */
-#line 170 "src/parse-gram.c"
+/* Line 272 of yacc.c  */
+#line 168 "src/parse-gram.c"
 
 /* Tokens.  */
 #ifndef YYTOKENTYPE
@@ -292,8 +290,8 @@ static char const *char_name (char);
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 278 of yacc.c  */
-#line 88 "src/parse-gram.y"
+/* Line 277 of yacc.c  */
+#line 87 "src/parse-gram.y"
 
   assoc assoc;
   char *code;
@@ -305,14 +303,14 @@ typedef union YYSTYPE
   uniqstr uniqstr;
   unsigned char character;
 
-/* Line 278 of yacc.c  */
-#line 226 "src/parse-gram.y"
+/* Line 277 of yacc.c  */
+#line 225 "src/parse-gram.y"
 
   param_type param;
 
 
-/* Line 278 of yacc.c  */
-#line 316 "src/parse-gram.c"
+/* Line 277 of yacc.c  */
+#line 314 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -335,11 +333,11 @@ typedef struct YYLTYPE
 
 /* Copy the second part of user declarations.  */
 
-/* Line 328 of yacc.c  */
-#line 340 "src/parse-gram.c"
+/* Line 327 of yacc.c  */
+#line 338 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
-/* Line 329 of yacc.c  */
-#line 56 "src/parse-gram.y"
+/* Line 328 of yacc.c  */
+#line 55 "src/parse-gram.y"
 
   static int current_prec = 0;
   static location current_lhs_location;
@@ -353,8 +351,8 @@ typedef struct YYLTYPE
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-/* Line 329 of yacc.c  */
-#line 215 "src/parse-gram.y"
+/* Line 328 of yacc.c  */
+#line 214 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -366,8 +364,8 @@ typedef struct YYLTYPE
   static param_type current_param = param_none;
 
 
-/* Line 329 of yacc.c  */
-#line 371 "src/parse-gram.c"
+/* Line 328 of yacc.c  */
+#line 369 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -645,17 +643,17 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   251,   251,   259,   261,   265,   266,   276,   280,   285,
-     286,   291,   296,   297,   298,   299,   300,   305,   314,   315,
-     316,   317,   318,   319,   320,   321,   321,   322,   323,   347,
-     348,   349,   350,   354,   355,   364,   365,   366,   370,   377,
-     384,   388,   392,   399,   414,   415,   419,   431,   431,   436,
-     436,   441,   452,   467,   468,   469,   470,   474,   475,   480,
-     482,   487,   488,   493,   495,   500,   501,   505,   506,   507,
-     508,   513,   518,   523,   529,   535,   546,   547,   556,   557,
-     563,   564,   565,   572,   572,   577,   578,   579,   584,   586,
-     588,   590,   592,   594,   599,   601,   612,   613,   618,   619,
-     620,   629,   649,   651,   660,   665,   666,   671,   678,   680
+       0,   250,   250,   258,   260,   264,   265,   275,   279,   284,
+     285,   290,   295,   296,   297,   298,   299,   304,   313,   314,
+     315,   316,   317,   318,   319,   320,   320,   321,   322,   346,
+     347,   348,   349,   353,   354,   363,   364,   365,   369,   376,
+     383,   387,   391,   398,   413,   414,   418,   430,   430,   435,
+     435,   440,   451,   466,   467,   468,   469,   473,   474,   479,
+     481,   486,   487,   492,   494,   499,   500,   504,   505,   506,
+     507,   512,   517,   522,   528,   534,   545,   546,   555,   556,
+     562,   563,   564,   571,   571,   576,   577,   578,   583,   585,
+     587,   589,   591,   593,   598,   600,   611,   612,   617,   618,
+     619,   628,   648,   650,   659,   664,   665,   670,   677,   679
 };
 #endif
 
@@ -1028,107 +1026,107 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
             case 3: // "string"
 
-/* Line 730 of yacc.c  */
-#line 175 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 174 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
-/* Line 730 of yacc.c  */
-#line 1036 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1034 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
-/* Line 730 of yacc.c  */
-#line 188 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 187 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
-/* Line 730 of yacc.c  */
-#line 1045 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1043 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
 
-/* Line 730 of yacc.c  */
-#line 184 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 183 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 730 of yacc.c  */
-#line 1054 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1052 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
 
-/* Line 730 of yacc.c  */
-#line 177 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 176 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 730 of yacc.c  */
-#line 1063 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1061 "src/parse-gram.c"
         break;
 
             case 41: // "[identifier]"
 
-/* Line 730 of yacc.c  */
-#line 182 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 181 "src/parse-gram.y"
         { fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 730 of yacc.c  */
-#line 1072 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1070 "src/parse-gram.c"
         break;
 
             case 42: // "char"
 
-/* Line 730 of yacc.c  */
-#line 169 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 168 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
-/* Line 730 of yacc.c  */
-#line 1081 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1079 "src/parse-gram.c"
         break;
 
             case 43: // "epilogue"
 
-/* Line 730 of yacc.c  */
-#line 177 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 176 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 730 of yacc.c  */
-#line 1090 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1088 "src/parse-gram.c"
         break;
 
             case 45: // "identifier"
 
-/* Line 730 of yacc.c  */
-#line 181 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 180 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 730 of yacc.c  */
-#line 1099 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1097 "src/parse-gram.c"
         break;
 
             case 46: // "identifier:"
 
-/* Line 730 of yacc.c  */
-#line 183 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 182 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 730 of yacc.c  */
-#line 1108 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1106 "src/parse-gram.c"
         break;
 
             case 49: // "%{...%}"
 
-/* Line 730 of yacc.c  */
-#line 177 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 176 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 730 of yacc.c  */
-#line 1117 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1115 "src/parse-gram.c"
         break;
 
             case 51: // "<tag>"
 
-/* Line 730 of yacc.c  */
-#line 185 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 184 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 730 of yacc.c  */
-#line 1126 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1124 "src/parse-gram.c"
         break;
 
             case 54: // "%param"
 
-/* Line 730 of yacc.c  */
-#line 231 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 230 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
     {
@@ -1141,80 +1139,80 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case param_none: aver (false); break;
     }
 }
-/* Line 730 of yacc.c  */
-#line 1146 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1144 "src/parse-gram.c"
         break;
 
             case 71: // symbol.prec
 
-/* Line 730 of yacc.c  */
-#line 191 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 190 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 730 of yacc.c  */
-#line 1155 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1153 "src/parse-gram.c"
         break;
 
             case 84: // variable
 
-/* Line 730 of yacc.c  */
-#line 181 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 180 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 730 of yacc.c  */
-#line 1164 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1162 "src/parse-gram.c"
         break;
 
             case 85: // content.opt
 
-/* Line 730 of yacc.c  */
-#line 177 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 176 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 730 of yacc.c  */
-#line 1173 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1171 "src/parse-gram.c"
         break;
 
             case 86: // braceless
 
-/* Line 730 of yacc.c  */
-#line 177 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 176 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 730 of yacc.c  */
-#line 1182 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1180 "src/parse-gram.c"
         break;
 
             case 87: // id
 
-/* Line 730 of yacc.c  */
-#line 191 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 190 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 730 of yacc.c  */
-#line 1191 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1189 "src/parse-gram.c"
         break;
 
             case 88: // id_colon
 
-/* Line 730 of yacc.c  */
-#line 192 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 730 of yacc.c  */
-#line 1200 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1198 "src/parse-gram.c"
         break;
 
             case 89: // symbol
 
-/* Line 730 of yacc.c  */
-#line 191 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 190 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 730 of yacc.c  */
-#line 1209 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1207 "src/parse-gram.c"
         break;
 
             case 90: // string_as_id
 
-/* Line 730 of yacc.c  */
-#line 191 "src/parse-gram.y"
+/* Line 729 of yacc.c  */
+#line 190 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 730 of yacc.c  */
-#line 1218 "src/parse-gram.c"
+/* Line 729 of yacc.c  */
+#line 1216 "src/parse-gram.c"
         break;
 
       default:
@@ -1744,16 +1742,16 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1215 of yacc.c  */
-#line 80 "src/parse-gram.y"
+/* Line 1214 of yacc.c  */
+#line 79 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1215 of yacc.c  */
-#line 1757 "src/parse-gram.c"
+/* Line 1214 of yacc.c  */
+#line 1755 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1939,8 +1937,8 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-/* Line 1428 of yacc.c  */
-#line 267 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 266 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -1950,107 +1948,107 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1428 of yacc.c  */
-#line 1955 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 1953 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1428 of yacc.c  */
-#line 277 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 276 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1428 of yacc.c  */
-#line 1965 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 1963 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1428 of yacc.c  */
-#line 281 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 280 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1428 of yacc.c  */
-#line 1976 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 1974 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1428 of yacc.c  */
-#line 285 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 284 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1428 of yacc.c  */
-#line 1984 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 1982 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1428 of yacc.c  */
-#line 287 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 286 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1428 of yacc.c  */
-#line 1995 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 1993 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1428 of yacc.c  */
-#line 292 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 291 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1428 of yacc.c  */
-#line 2006 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2004 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1428 of yacc.c  */
-#line 296 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 295 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1428 of yacc.c  */
-#line 2014 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2012 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1428 of yacc.c  */
-#line 297 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 296 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1428 of yacc.c  */
-#line 2022 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2020 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1428 of yacc.c  */
-#line 298 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 297 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1428 of yacc.c  */
-#line 2030 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2028 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1428 of yacc.c  */
-#line 299 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 298 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1428 of yacc.c  */
-#line 2038 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2036 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1428 of yacc.c  */
-#line 301 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 300 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1428 of yacc.c  */
-#line 2049 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2047 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1428 of yacc.c  */
-#line 306 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 305 "src/parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2059,93 +2057,93 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1428 of yacc.c  */
-#line 2064 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2062 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1428 of yacc.c  */
-#line 314 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 313 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1428 of yacc.c  */
-#line 2072 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2070 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1428 of yacc.c  */
-#line 315 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 314 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1428 of yacc.c  */
-#line 2080 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2078 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1428 of yacc.c  */
-#line 316 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 315 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1428 of yacc.c  */
-#line 2088 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2086 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1428 of yacc.c  */
-#line 317 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 316 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1428 of yacc.c  */
-#line 2096 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2094 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1428 of yacc.c  */
-#line 318 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 317 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1428 of yacc.c  */
-#line 2104 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2102 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1428 of yacc.c  */
-#line 319 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 318 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1428 of yacc.c  */
-#line 2112 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2110 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1428 of yacc.c  */
-#line 320 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 319 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1428 of yacc.c  */
-#line 2120 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2118 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1428 of yacc.c  */
-#line 321 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 320 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1428 of yacc.c  */
-#line 2128 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2126 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1428 of yacc.c  */
-#line 321 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 320 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1428 of yacc.c  */
-#line 2136 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2134 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1428 of yacc.c  */
-#line 322 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 321 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1428 of yacc.c  */
-#line 2144 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2142 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1428 of yacc.c  */
-#line 324 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 323 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2169,199 +2167,199 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1428 of yacc.c  */
-#line 2174 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2172 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1428 of yacc.c  */
-#line 347 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 346 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1428 of yacc.c  */
-#line 2182 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2180 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1428 of yacc.c  */
-#line 348 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 347 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1428 of yacc.c  */
-#line 2190 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2188 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1428 of yacc.c  */
-#line 349 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 348 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1428 of yacc.c  */
-#line 2198 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2196 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1428 of yacc.c  */
-#line 354 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 353 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2206 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2204 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1428 of yacc.c  */
-#line 355 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 354 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2214 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2212 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1428 of yacc.c  */
-#line 367 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 366 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1428 of yacc.c  */
-#line 2224 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2222 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1428 of yacc.c  */
-#line 371 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 370 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
 	symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1428 of yacc.c  */
-#line 2237 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2235 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1428 of yacc.c  */
-#line 378 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 377 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
 	symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1428 of yacc.c  */
-#line 2250 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2248 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1428 of yacc.c  */
-#line 385 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 384 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1428 of yacc.c  */
-#line 2260 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2258 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1428 of yacc.c  */
-#line 389 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 388 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1428 of yacc.c  */
-#line 2270 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2268 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1428 of yacc.c  */
-#line 393 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 392 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1428 of yacc.c  */
-#line 2283 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2281 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1428 of yacc.c  */
-#line 400 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 399 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1428 of yacc.c  */
-#line 2294 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2292 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1428 of yacc.c  */
-#line 414 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 413 "src/parse-gram.y"
     {}
-/* Line 1428 of yacc.c  */
-#line 2302 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2300 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1428 of yacc.c  */
-#line 415 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 414 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2310 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2308 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1428 of yacc.c  */
-#line 420 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 419 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1428 of yacc.c  */
-#line 2322 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2320 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1428 of yacc.c  */
-#line 431 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 430 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1428 of yacc.c  */
-#line 2330 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2328 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1428 of yacc.c  */
-#line 432 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 431 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1428 of yacc.c  */
-#line 2341 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2339 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1428 of yacc.c  */
-#line 436 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 435 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1428 of yacc.c  */
-#line 2349 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2347 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1428 of yacc.c  */
-#line 437 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 436 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1428 of yacc.c  */
-#line 2360 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2358 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1428 of yacc.c  */
-#line 442 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 441 "src/parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2369,13 +2367,13 @@ yyreduce:
 	symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1428 of yacc.c  */
-#line 2374 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2372 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1428 of yacc.c  */
-#line 453 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 452 "src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2387,340 +2385,340 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1428 of yacc.c  */
-#line 2392 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2390 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1428 of yacc.c  */
-#line 467 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 466 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1428 of yacc.c  */
-#line 2400 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2398 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1428 of yacc.c  */
-#line 468 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 467 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1428 of yacc.c  */
-#line 2408 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2406 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1428 of yacc.c  */
-#line 469 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 468 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1428 of yacc.c  */
-#line 2416 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2414 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1428 of yacc.c  */
-#line 470 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 469 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1428 of yacc.c  */
-#line 2424 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2422 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1428 of yacc.c  */
-#line 474 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 473 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1428 of yacc.c  */
-#line 2432 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2430 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1428 of yacc.c  */
-#line 475 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 474 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1428 of yacc.c  */
-#line 2440 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2438 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1428 of yacc.c  */
-#line 481 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 480 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2448 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2446 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1428 of yacc.c  */
-#line 483 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 482 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1428 of yacc.c  */
-#line 2456 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2454 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1428 of yacc.c  */
-#line 487 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 486 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1428 of yacc.c  */
-#line 2464 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2462 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1428 of yacc.c  */
-#line 488 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 487 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2472 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2470 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1428 of yacc.c  */
-#line 494 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 493 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2480 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2478 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1428 of yacc.c  */
-#line 496 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 495 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1428 of yacc.c  */
-#line 2488 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2486 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1428 of yacc.c  */
-#line 500 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 499 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1428 of yacc.c  */
-#line 2496 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2494 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1428 of yacc.c  */
-#line 501 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 500 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1428 of yacc.c  */
-#line 2504 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2502 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1428 of yacc.c  */
-#line 505 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 504 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2512 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2510 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1428 of yacc.c  */
-#line 506 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 505 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2520 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2518 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1428 of yacc.c  */
-#line 507 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2528 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2526 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1428 of yacc.c  */
-#line 508 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 507 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2536 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2534 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1428 of yacc.c  */
-#line 514 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 513 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1428 of yacc.c  */
-#line 2547 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2545 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1428 of yacc.c  */
-#line 519 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 518 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1428 of yacc.c  */
-#line 2558 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2556 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1428 of yacc.c  */
-#line 524 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 523 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1428 of yacc.c  */
-#line 2570 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2568 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1428 of yacc.c  */
-#line 530 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 529 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1428 of yacc.c  */
-#line 2582 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2580 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1428 of yacc.c  */
-#line 536 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 535 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1428 of yacc.c  */
-#line 2595 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2593 "src/parse-gram.c"
     break;
 
   case 82:
-/* Line 1428 of yacc.c  */
-#line 566 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 565 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1428 of yacc.c  */
-#line 2605 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2603 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1428 of yacc.c  */
-#line 572 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 571 "src/parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
-/* Line 1428 of yacc.c  */
-#line 2614 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2612 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1428 of yacc.c  */
-#line 577 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 576 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2622 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2620 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1428 of yacc.c  */
-#line 578 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 577 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2630 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2628 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1428 of yacc.c  */
-#line 584 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 583 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
-/* Line 1428 of yacc.c  */
-#line 2639 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2637 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1428 of yacc.c  */
-#line 587 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 586 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1428 of yacc.c  */
-#line 2647 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2645 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1428 of yacc.c  */
-#line 589 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 588 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1428 of yacc.c  */
-#line 2655 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2653 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1428 of yacc.c  */
-#line 591 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 590 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2663 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2661 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1428 of yacc.c  */
-#line 593 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 592 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2671 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2669 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1428 of yacc.c  */
-#line 595 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 594 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2679 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2677 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1428 of yacc.c  */
-#line 599 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 598 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1428 of yacc.c  */
-#line 2687 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2685 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1428 of yacc.c  */
-#line 601 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 600 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2695 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2693 "src/parse-gram.c"
     break;
 
   case 97:
-/* Line 1428 of yacc.c  */
-#line 613 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 612 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1428 of yacc.c  */
-#line 2703 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2701 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1428 of yacc.c  */
-#line 618 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 617 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1428 of yacc.c  */
-#line 2711 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2709 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1428 of yacc.c  */
-#line 619 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 618 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1428 of yacc.c  */
-#line 2719 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2717 "src/parse-gram.c"
     break;
 
   case 101:
-/* Line 1428 of yacc.c  */
-#line 630 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 629 "src/parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2729,52 +2727,52 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1428 of yacc.c  */
-#line 2734 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2732 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1428 of yacc.c  */
-#line 650 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 649 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2742 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2740 "src/parse-gram.c"
     break;
 
   case 103:
-/* Line 1428 of yacc.c  */
-#line 652 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 651 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1428 of yacc.c  */
-#line 2754 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2752 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1428 of yacc.c  */
-#line 660 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 659 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1428 of yacc.c  */
-#line 2762 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2760 "src/parse-gram.c"
     break;
 
   case 107:
-/* Line 1428 of yacc.c  */
-#line 672 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 671 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1428 of yacc.c  */
-#line 2773 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2771 "src/parse-gram.c"
     break;
 
   case 109:
-/* Line 1428 of yacc.c  */
-#line 681 "src/parse-gram.y"
+/* Line 1427 of yacc.c  */
+#line 680 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2783,13 +2781,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1428 of yacc.c  */
-#line 2788 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2786 "src/parse-gram.c"
     break;
 
 
-/* Line 1428 of yacc.c  */
-#line 2793 "src/parse-gram.c"
+/* Line 1427 of yacc.c  */
+#line 2791 "src/parse-gram.c"
       default: break;
     }
   /* User semantic actions sometimes alter yychar, and that requires
@@ -3016,8 +3014,8 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 1658 of yacc.c  */
-#line 691 "src/parse-gram.y"
+/* Line 1657 of yacc.c  */
+#line 690 "src/parse-gram.y"
 
 
 
