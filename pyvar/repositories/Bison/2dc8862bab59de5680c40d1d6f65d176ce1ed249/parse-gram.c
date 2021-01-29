@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.7.1116-42fef.  */
+/* A Bison parser, made by GNU Bison 2.7.1127-02879-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.7.1116-42fef"
+#define YYBISON_VERSION "2.7.1127-02879-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -70,7 +70,7 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 1 "src/parse-gram.y" /* yacc.c:357  */
+#line 1 "src/parse-gram.y" /* yacc.c:356  */
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002-2013 Free Software Foundation, Inc.
@@ -122,7 +122,7 @@ static void gram_error (location const *, char const *);
 /* A string that describes a char (e.g., 'a' -> "'a'").  */
 static char const *char_name (char);
 
-#line 126 "src/parse-gram.c" /* yacc.c:357  */
+#line 126 "src/parse-gram.c" /* yacc.c:356  */
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -160,7 +160,7 @@ static char const *char_name (char);
 extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
-#line 219 "src/parse-gram.y" /* yacc.c:373  */
+#line 219 "src/parse-gram.y" /* yacc.c:372  */
 
 # ifndef PARAM_TYPE
 #  define PARAM_TYPE
@@ -174,7 +174,7 @@ extern int gram_debug;
 # endif
 
 
-#line 178 "src/parse-gram.c" /* yacc.c:373  */
+#line 178 "src/parse-gram.c" /* yacc.c:372  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -239,70 +239,13 @@ extern int gram_debug;
     PERCENT_EMPTY = 312
   };
 #endif
-/* Tokens.  */
-#define GRAM_EOF 0
-#define STRING 258
-#define INT 259
-#define PERCENT_TOKEN 260
-#define PERCENT_NTERM 261
-#define PERCENT_TYPE 262
-#define PERCENT_DESTRUCTOR 263
-#define PERCENT_PRINTER 264
-#define PERCENT_LEFT 265
-#define PERCENT_RIGHT 266
-#define PERCENT_NONASSOC 267
-#define PERCENT_PRECEDENCE 268
-#define PERCENT_PREC 269
-#define PERCENT_DPREC 270
-#define PERCENT_MERGE 271
-#define PERCENT_CODE 272
-#define PERCENT_DEFAULT_PREC 273
-#define PERCENT_DEFINE 274
-#define PERCENT_DEFINES 275
-#define PERCENT_ERROR_VERBOSE 276
-#define PERCENT_EXPECT 277
-#define PERCENT_EXPECT_RR 278
-#define PERCENT_FLAG 279
-#define PERCENT_FILE_PREFIX 280
-#define PERCENT_GLR_PARSER 281
-#define PERCENT_INITIAL_ACTION 282
-#define PERCENT_LANGUAGE 283
-#define PERCENT_NAME_PREFIX 284
-#define PERCENT_NO_DEFAULT_PREC 285
-#define PERCENT_NO_LINES 286
-#define PERCENT_NONDETERMINISTIC_PARSER 287
-#define PERCENT_OUTPUT 288
-#define PERCENT_REQUIRE 289
-#define PERCENT_SKELETON 290
-#define PERCENT_START 291
-#define PERCENT_TOKEN_TABLE 292
-#define PERCENT_VERBOSE 293
-#define PERCENT_YACC 294
-#define BRACED_CODE 295
-#define BRACED_PREDICATE 296
-#define BRACKETED_ID 297
-#define CHAR 298
-#define EPILOGUE 299
-#define EQUAL 300
-#define ID 301
-#define ID_COLON 302
-#define PERCENT_PERCENT 303
-#define PIPE 304
-#define PROLOGUE 305
-#define SEMICOLON 306
-#define TAG 307
-#define TAG_ANY 308
-#define TAG_NONE 309
-#define PERCENT_PARAM 310
-#define PERCENT_UNION 311
-#define PERCENT_EMPTY 312
 
 /* Value type.  */
 #if ! defined GRAM_STYPE && ! defined GRAM_STYPE_IS_DECLARED
 typedef union GRAM_STYPE GRAM_STYPE;
 union GRAM_STYPE
 {
-#line 105 "src/parse-gram.y" /* yacc.c:373  */
+#line 105 "src/parse-gram.y" /* yacc.c:372  */
 
   assoc assoc;
   char *code;
@@ -314,14 +257,14 @@ union GRAM_STYPE
   uniqstr uniqstr;
   unsigned char character;
 
-#line 243 "src/parse-gram.y" /* yacc.c:373  */
+#line 243 "src/parse-gram.y" /* yacc.c:372  */
 
   param_type param;
 
-#line 419 "src/parse-gram.y" /* yacc.c:373  */
+#line 419 "src/parse-gram.y" /* yacc.c:372  */
 code_props_type code_type;
 
-#line 325 "src/parse-gram.c" /* yacc.c:373  */
+#line 268 "src/parse-gram.c" /* yacc.c:372  */
 };
 # define GRAM_STYPE_IS_TRIVIAL 1
 # define GRAM_STYPE_IS_DECLARED 1
@@ -349,9 +292,9 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-#line 353 "src/parse-gram.c" /* yacc.c:376  */
+#line 296 "src/parse-gram.c" /* yacc.c:375  */
 /* Unqualified %code blocks.  */
-#line 54 "src/parse-gram.y" /* yacc.c:377  */
+#line 54 "src/parse-gram.y" /* yacc.c:376  */
 
   static int current_prec = 0;
   static location current_lhs_location;
@@ -383,7 +326,7 @@ int gram_parse (void);
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-#line 232 "src/parse-gram.y" /* yacc.c:377  */
+#line 232 "src/parse-gram.y" /* yacc.c:376  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -395,7 +338,7 @@ int gram_parse (void);
   static param_type current_param = param_none;
 
 
-#line 399 "src/parse-gram.c" /* yacc.c:377  */
+#line 342 "src/parse-gram.c" /* yacc.c:376  */
 
 #ifdef short
 # undef short
@@ -636,12 +579,12 @@ static const yytype_uint16 yyrline[] =
      368,   369,   378,   379,   380,   384,   396,   400,   404,   411,
      422,   423,   433,   434,   438,   450,   450,   455,   455,   460,
      471,   486,   487,   488,   489,   493,   494,   499,   501,   506,
-     507,   512,   514,   519,   520,   524,   525,   529,   530,   531,
-     536,   541,   546,   552,   558,   569,   570,   579,   580,   586,
-     587,   588,   595,   595,   603,   604,   605,   610,   613,   615,
-     617,   619,   621,   623,   625,   630,   631,   641,   642,   647,
-     648,   649,   658,   678,   680,   689,   694,   695,   700,   708,
-     709
+     511,   521,   523,   528,   529,   533,   534,   538,   539,   540,
+     545,   550,   555,   561,   567,   578,   579,   588,   589,   595,
+     596,   597,   604,   604,   612,   613,   614,   619,   622,   624,
+     626,   628,   630,   632,   634,   639,   640,   650,   651,   656,
+     657,   658,   667,   687,   689,   698,   703,   704,   709,   717,
+     718
 };
 #endif
 
@@ -1012,73 +955,73 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
     case 3: /* "string"  */
-#line 192 "src/parse-gram.y" /* yacc.c:707  */
+#line 192 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-#line 1018 "src/parse-gram.c" /* yacc.c:707  */
+#line 961 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 4: /* "integer"  */
-#line 205 "src/parse-gram.y" /* yacc.c:707  */
+#line 205 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1024 "src/parse-gram.c" /* yacc.c:707  */
+#line 967 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 24: /* "%<flag>"  */
-#line 201 "src/parse-gram.y" /* yacc.c:707  */
+#line 201 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 1030 "src/parse-gram.c" /* yacc.c:707  */
+#line 973 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 40: /* "{...}"  */
-#line 194 "src/parse-gram.y" /* yacc.c:707  */
+#line 194 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1036 "src/parse-gram.c" /* yacc.c:707  */
+#line 979 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 42: /* "[identifier]"  */
-#line 199 "src/parse-gram.y" /* yacc.c:707  */
+#line 199 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 1042 "src/parse-gram.c" /* yacc.c:707  */
+#line 985 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 43: /* "char"  */
-#line 186 "src/parse-gram.y" /* yacc.c:707  */
+#line 186 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 1048 "src/parse-gram.c" /* yacc.c:707  */
+#line 991 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 44: /* "epilogue"  */
-#line 194 "src/parse-gram.y" /* yacc.c:707  */
+#line 194 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1054 "src/parse-gram.c" /* yacc.c:707  */
+#line 997 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 46: /* "identifier"  */
-#line 198 "src/parse-gram.y" /* yacc.c:707  */
+#line 198 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1060 "src/parse-gram.c" /* yacc.c:707  */
+#line 1003 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 47: /* "identifier:"  */
-#line 200 "src/parse-gram.y" /* yacc.c:707  */
+#line 200 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1066 "src/parse-gram.c" /* yacc.c:707  */
+#line 1009 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 50: /* "%{...%}"  */
-#line 194 "src/parse-gram.y" /* yacc.c:707  */
+#line 194 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1072 "src/parse-gram.c" /* yacc.c:707  */
+#line 1015 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 52: /* "<tag>"  */
-#line 202 "src/parse-gram.y" /* yacc.c:707  */
+#line 202 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1078 "src/parse-gram.c" /* yacc.c:707  */
+#line 1021 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 55: /* "%param"  */
-#line 248 "src/parse-gram.y" /* yacc.c:707  */
+#line 248 "src/parse-gram.y" /* yacc.c:706  */
       {
   switch (((*yyvaluep).param))
     {
@@ -1091,67 +1034,67 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-#line 1095 "src/parse-gram.c" /* yacc.c:707  */
+#line 1038 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 65: /* code_props_type  */
-#line 420 "src/parse-gram.y" /* yacc.c:707  */
+#line 420 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1101 "src/parse-gram.c" /* yacc.c:707  */
+#line 1044 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 74: /* symbol.prec  */
-#line 208 "src/parse-gram.y" /* yacc.c:707  */
+#line 208 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1107 "src/parse-gram.c" /* yacc.c:707  */
+#line 1050 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 78: /* tag  */
-#line 202 "src/parse-gram.y" /* yacc.c:707  */
+#line 202 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1113 "src/parse-gram.c" /* yacc.c:707  */
+#line 1056 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 88: /* variable  */
-#line 198 "src/parse-gram.y" /* yacc.c:707  */
+#line 198 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1119 "src/parse-gram.c" /* yacc.c:707  */
+#line 1062 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 89: /* content.opt  */
-#line 194 "src/parse-gram.y" /* yacc.c:707  */
+#line 194 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1125 "src/parse-gram.c" /* yacc.c:707  */
+#line 1068 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 90: /* braceless  */
-#line 194 "src/parse-gram.y" /* yacc.c:707  */
+#line 194 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1131 "src/parse-gram.c" /* yacc.c:707  */
+#line 1074 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 91: /* id  */
-#line 208 "src/parse-gram.y" /* yacc.c:707  */
+#line 208 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1137 "src/parse-gram.c" /* yacc.c:707  */
+#line 1080 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 92: /* id_colon  */
-#line 209 "src/parse-gram.y" /* yacc.c:707  */
+#line 209 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1143 "src/parse-gram.c" /* yacc.c:707  */
+#line 1086 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 93: /* symbol  */
-#line 208 "src/parse-gram.y" /* yacc.c:707  */
+#line 208 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1149 "src/parse-gram.c" /* yacc.c:707  */
+#line 1092 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 94: /* string_as_id  */
-#line 208 "src/parse-gram.y" /* yacc.c:707  */
+#line 208 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1155 "src/parse-gram.c" /* yacc.c:707  */
+#line 1098 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
       default:
@@ -1866,14 +1809,14 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 97 "src/parse-gram.y" /* yacc.c:1452  */
+#line 97 "src/parse-gram.y" /* yacc.c:1451  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-#line 1877 "src/parse-gram.c" /* yacc.c:1452  */
+#line 1820 "src/parse-gram.c" /* yacc.c:1451  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2067,7 +2010,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-#line 284 "src/parse-gram.y" /* yacc.c:1669  */
+#line 284 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2077,79 +2020,79 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2081 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2024 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 7:
-#line 294 "src/parse-gram.y" /* yacc.c:1669  */
+#line 294 "src/parse-gram.y" /* yacc.c:1668  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2089 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2032 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 8:
-#line 298 "src/parse-gram.y" /* yacc.c:1669  */
+#line 298 "src/parse-gram.y" /* yacc.c:1668  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2098 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2041 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 9:
-#line 302 "src/parse-gram.y" /* yacc.c:1669  */
+#line 302 "src/parse-gram.y" /* yacc.c:1668  */
     { defines_flag = true; }
-#line 2104 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2047 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 10:
-#line 304 "src/parse-gram.y" /* yacc.c:1669  */
+#line 304 "src/parse-gram.y" /* yacc.c:1668  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-#line 2113 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2056 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 11:
-#line 309 "src/parse-gram.y" /* yacc.c:1669  */
+#line 309 "src/parse-gram.y" /* yacc.c:1668  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2122 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2065 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 12:
-#line 313 "src/parse-gram.y" /* yacc.c:1669  */
+#line 313 "src/parse-gram.y" /* yacc.c:1668  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2128 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2071 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 13:
-#line 314 "src/parse-gram.y" /* yacc.c:1669  */
+#line 314 "src/parse-gram.y" /* yacc.c:1668  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2134 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2077 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 14:
-#line 315 "src/parse-gram.y" /* yacc.c:1669  */
+#line 315 "src/parse-gram.y" /* yacc.c:1668  */
     { spec_file_prefix = (yyvsp[0].chars); }
-#line 2140 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2083 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 15:
-#line 317 "src/parse-gram.y" /* yacc.c:1669  */
+#line 317 "src/parse-gram.y" /* yacc.c:1668  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2149 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2092 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 16:
-#line 322 "src/parse-gram.y" /* yacc.c:1669  */
+#line 322 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2158,59 +2101,59 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2162 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2105 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 17:
-#line 330 "src/parse-gram.y" /* yacc.c:1669  */
+#line 330 "src/parse-gram.y" /* yacc.c:1668  */
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-#line 2168 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2111 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 18:
-#line 331 "src/parse-gram.y" /* yacc.c:1669  */
+#line 331 "src/parse-gram.y" /* yacc.c:1668  */
     { spec_name_prefix = (yyvsp[0].chars); }
-#line 2174 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2117 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 19:
-#line 332 "src/parse-gram.y" /* yacc.c:1669  */
+#line 332 "src/parse-gram.y" /* yacc.c:1668  */
     { no_lines_flag = true; }
-#line 2180 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2123 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 20:
-#line 333 "src/parse-gram.y" /* yacc.c:1669  */
+#line 333 "src/parse-gram.y" /* yacc.c:1668  */
     { nondeterministic_parser = true; }
-#line 2186 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2129 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 21:
-#line 334 "src/parse-gram.y" /* yacc.c:1669  */
+#line 334 "src/parse-gram.y" /* yacc.c:1668  */
     { spec_outfile = (yyvsp[0].chars); }
-#line 2192 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2135 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 22:
-#line 335 "src/parse-gram.y" /* yacc.c:1669  */
+#line 335 "src/parse-gram.y" /* yacc.c:1668  */
     { current_param = (yyvsp[0].param); }
-#line 2198 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2141 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 23:
-#line 335 "src/parse-gram.y" /* yacc.c:1669  */
+#line 335 "src/parse-gram.y" /* yacc.c:1668  */
     { current_param = param_none; }
-#line 2204 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2147 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 24:
-#line 336 "src/parse-gram.y" /* yacc.c:1669  */
+#line 336 "src/parse-gram.y" /* yacc.c:1668  */
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-#line 2210 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2153 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 25:
-#line 338 "src/parse-gram.y" /* yacc.c:1669  */
+#line 338 "src/parse-gram.y" /* yacc.c:1668  */
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2234,49 +2177,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2238 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2181 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 26:
-#line 361 "src/parse-gram.y" /* yacc.c:1669  */
+#line 361 "src/parse-gram.y" /* yacc.c:1668  */
     { token_table_flag = true; }
-#line 2244 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2187 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 27:
-#line 362 "src/parse-gram.y" /* yacc.c:1669  */
+#line 362 "src/parse-gram.y" /* yacc.c:1668  */
     { report_flag |= report_states; }
-#line 2250 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2193 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 28:
-#line 363 "src/parse-gram.y" /* yacc.c:1669  */
+#line 363 "src/parse-gram.y" /* yacc.c:1668  */
     { yacc_flag = true; }
-#line 2256 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2199 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 30:
-#line 368 "src/parse-gram.y" /* yacc.c:1669  */
+#line 368 "src/parse-gram.y" /* yacc.c:1668  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2262 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2205 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 31:
-#line 369 "src/parse-gram.y" /* yacc.c:1669  */
+#line 369 "src/parse-gram.y" /* yacc.c:1668  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2268 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2211 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 34:
-#line 381 "src/parse-gram.y" /* yacc.c:1669  */
+#line 381 "src/parse-gram.y" /* yacc.c:1668  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2276 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2219 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 35:
-#line 385 "src/parse-gram.y" /* yacc.c:1669  */
+#line 385 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2288,111 +2231,111 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2292 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2235 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 36:
-#line 397 "src/parse-gram.y" /* yacc.c:1669  */
+#line 397 "src/parse-gram.y" /* yacc.c:1668  */
     {
       default_prec = true;
     }
-#line 2300 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2243 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 37:
-#line 401 "src/parse-gram.y" /* yacc.c:1669  */
+#line 401 "src/parse-gram.y" /* yacc.c:1668  */
     {
       default_prec = false;
     }
-#line 2308 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2251 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 38:
-#line 405 "src/parse-gram.y" /* yacc.c:1669  */
+#line 405 "src/parse-gram.y" /* yacc.c:1668  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2319 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2262 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 39:
-#line 412 "src/parse-gram.y" /* yacc.c:1669  */
+#line 412 "src/parse-gram.y" /* yacc.c:1668  */
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2328 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2271 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 40:
-#line 422 "src/parse-gram.y" /* yacc.c:1669  */
+#line 422 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.code_type) = destructor; }
-#line 2334 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2277 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 41:
-#line 423 "src/parse-gram.y" /* yacc.c:1669  */
+#line 423 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.code_type) = printer; }
-#line 2340 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2283 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 42:
-#line 433 "src/parse-gram.y" /* yacc.c:1669  */
+#line 433 "src/parse-gram.y" /* yacc.c:1668  */
     {}
-#line 2346 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2289 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 43:
-#line 434 "src/parse-gram.y" /* yacc.c:1669  */
+#line 434 "src/parse-gram.y" /* yacc.c:1668  */
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2352 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2295 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 44:
-#line 439 "src/parse-gram.y" /* yacc.c:1669  */
+#line 439 "src/parse-gram.y" /* yacc.c:1668  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2362 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2305 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 45:
-#line 450 "src/parse-gram.y" /* yacc.c:1669  */
+#line 450 "src/parse-gram.y" /* yacc.c:1668  */
     { current_class = nterm_sym; }
-#line 2368 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2311 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 46:
-#line 451 "src/parse-gram.y" /* yacc.c:1669  */
+#line 451 "src/parse-gram.y" /* yacc.c:1668  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2377 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2320 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 47:
-#line 455 "src/parse-gram.y" /* yacc.c:1669  */
+#line 455 "src/parse-gram.y" /* yacc.c:1668  */
     { current_class = token_sym; }
-#line 2383 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2326 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 48:
-#line 456 "src/parse-gram.y" /* yacc.c:1669  */
+#line 456 "src/parse-gram.y" /* yacc.c:1668  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2392 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2335 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 49:
-#line 461 "src/parse-gram.y" /* yacc.c:1669  */
+#line 461 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_list *list;
       tag_seen = true;
@@ -2400,11 +2343,11 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2404 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2347 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 50:
-#line 472 "src/parse-gram.y" /* yacc.c:1669  */
+#line 472 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_list *list;
       ++current_prec;
@@ -2416,288 +2359,295 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2420 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2363 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 51:
-#line 486 "src/parse-gram.y" /* yacc.c:1669  */
+#line 486 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = left_assoc; }
-#line 2426 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2369 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 52:
-#line 487 "src/parse-gram.y" /* yacc.c:1669  */
+#line 487 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = right_assoc; }
-#line 2432 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2375 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 53:
-#line 488 "src/parse-gram.y" /* yacc.c:1669  */
+#line 488 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = non_assoc; }
-#line 2438 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2381 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 54:
-#line 489 "src/parse-gram.y" /* yacc.c:1669  */
+#line 489 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2444 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2387 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 55:
-#line 493 "src/parse-gram.y" /* yacc.c:1669  */
+#line 493 "src/parse-gram.y" /* yacc.c:1668  */
     { current_type = NULL; }
-#line 2450 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2393 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 56:
-#line 494 "src/parse-gram.y" /* yacc.c:1669  */
+#line 494 "src/parse-gram.y" /* yacc.c:1668  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2456 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2399 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 57:
-#line 500 "src/parse-gram.y" /* yacc.c:1669  */
+#line 500 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2462 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2405 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 58:
-#line 502 "src/parse-gram.y" /* yacc.c:1669  */
+#line 502 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2468 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2411 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 59:
-#line 506 "src/parse-gram.y" /* yacc.c:1669  */
-    { (yyval.symbol) = (yyvsp[0].symbol); }
-#line 2474 "src/parse-gram.c" /* yacc.c:1669  */
+#line 507 "src/parse-gram.y" /* yacc.c:1668  */
+    {
+      (yyval.symbol) = (yyvsp[0].symbol);
+      symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
+    }
+#line 2420 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 60:
-#line 507 "src/parse-gram.y" /* yacc.c:1669  */
-    { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-#line 2480 "src/parse-gram.c" /* yacc.c:1669  */
+#line 512 "src/parse-gram.y" /* yacc.c:1668  */
+    {
+      (yyval.symbol) = (yyvsp[-1].symbol);
+      symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
+      symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
+    }
+#line 2430 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 61:
-#line 513 "src/parse-gram.y" /* yacc.c:1669  */
+#line 522 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2486 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2436 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 62:
-#line 515 "src/parse-gram.y" /* yacc.c:1669  */
+#line 524 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2492 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2442 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 63:
-#line 519 "src/parse-gram.y" /* yacc.c:1669  */
+#line 528 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2498 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2448 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 64:
-#line 520 "src/parse-gram.y" /* yacc.c:1669  */
+#line 529 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2504 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2454 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 65:
-#line 524 "src/parse-gram.y" /* yacc.c:1669  */
+#line 533 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2510 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2460 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 66:
-#line 525 "src/parse-gram.y" /* yacc.c:1669  */
+#line 534 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2516 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2466 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 68:
-#line 530 "src/parse-gram.y" /* yacc.c:1669  */
+#line 539 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2522 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2472 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 69:
-#line 531 "src/parse-gram.y" /* yacc.c:1669  */
+#line 540 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2528 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2478 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 70:
-#line 537 "src/parse-gram.y" /* yacc.c:1669  */
+#line 546 "src/parse-gram.y" /* yacc.c:1668  */
     {
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2537 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2487 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 71:
-#line 542 "src/parse-gram.y" /* yacc.c:1669  */
+#line 551 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2546 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2496 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 72:
-#line 547 "src/parse-gram.y" /* yacc.c:1669  */
+#line 556 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2556 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2506 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 73:
-#line 553 "src/parse-gram.y" /* yacc.c:1669  */
+#line 562 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2566 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2516 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 74:
-#line 559 "src/parse-gram.y" /* yacc.c:1669  */
+#line 568 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2577 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2527 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 81:
-#line 589 "src/parse-gram.y" /* yacc.c:1669  */
+#line 598 "src/parse-gram.y" /* yacc.c:1668  */
     {
       yyerrok;
     }
-#line 2585 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2535 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 82:
-#line 595 "src/parse-gram.y" /* yacc.c:1669  */
+#line 604 "src/parse-gram.y" /* yacc.c:1668  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2591 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2541 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 83:
-#line 596 "src/parse-gram.y" /* yacc.c:1669  */
+#line 605 "src/parse-gram.y" /* yacc.c:1668  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2600 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2550 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 84:
-#line 603 "src/parse-gram.y" /* yacc.c:1669  */
+#line 612 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2606 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2556 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 85:
-#line 604 "src/parse-gram.y" /* yacc.c:1669  */
+#line 613 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2612 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2562 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 87:
-#line 611 "src/parse-gram.y" /* yacc.c:1669  */
+#line 620 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2619 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2569 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 88:
-#line 614 "src/parse-gram.y" /* yacc.c:1669  */
+#line 623 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2625 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2575 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 89:
-#line 616 "src/parse-gram.y" /* yacc.c:1669  */
+#line 625 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-#line 2631 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2581 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 90:
-#line 618 "src/parse-gram.y" /* yacc.c:1669  */
+#line 627 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-#line 2637 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2587 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 91:
-#line 620 "src/parse-gram.y" /* yacc.c:1669  */
+#line 629 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2643 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2593 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 92:
-#line 622 "src/parse-gram.y" /* yacc.c:1669  */
+#line 631 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2649 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2599 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 93:
-#line 624 "src/parse-gram.y" /* yacc.c:1669  */
+#line 633 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2655 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2605 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 94:
-#line 626 "src/parse-gram.y" /* yacc.c:1669  */
+#line 635 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2661 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2611 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 95:
-#line 630 "src/parse-gram.y" /* yacc.c:1669  */
+#line 639 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.named_ref) = 0; }
-#line 2667 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2617 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 96:
-#line 631 "src/parse-gram.y" /* yacc.c:1669  */
+#line 640 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2673 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2623 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 98:
-#line 642 "src/parse-gram.y" /* yacc.c:1669  */
+#line 651 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-#line 2679 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2629 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 99:
-#line 647 "src/parse-gram.y" /* yacc.c:1669  */
+#line 656 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.chars) = ""; }
-#line 2685 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2635 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 100:
-#line 648 "src/parse-gram.y" /* yacc.c:1669  */
+#line 657 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-#line 2691 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2641 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 101:
-#line 649 "src/parse-gram.y" /* yacc.c:1669  */
+#line 658 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.chars) = (yyvsp[0].chars); }
-#line 2697 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2647 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 102:
-#line 659 "src/parse-gram.y" /* yacc.c:1669  */
+#line 668 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2706,42 +2656,42 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-#line 2710 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2660 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 103:
-#line 679 "src/parse-gram.y" /* yacc.c:1669  */
+#line 688 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2716 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2666 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 104:
-#line 681 "src/parse-gram.y" /* yacc.c:1669  */
+#line 690 "src/parse-gram.y" /* yacc.c:1668  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2726 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2676 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 105:
-#line 689 "src/parse-gram.y" /* yacc.c:1669  */
+#line 698 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2732 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2682 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 108:
-#line 701 "src/parse-gram.y" /* yacc.c:1669  */
+#line 710 "src/parse-gram.y" /* yacc.c:1668  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2741 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2691 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 110:
-#line 710 "src/parse-gram.y" /* yacc.c:1669  */
+#line 719 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2750,11 +2700,11 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2754 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2704 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
 
-#line 2758 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2708 "src/parse-gram.c" /* yacc.c:1668  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3001,7 +2951,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 720 "src/parse-gram.y" /* yacc.c:1929  */
+#line 729 "src/parse-gram.y" /* yacc.c:1928  */
 
 
 /* Return the location of the left-hand side of a rule whose
