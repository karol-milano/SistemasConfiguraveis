@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.7.1067-29fb-dirty.  */
+/* A Bison parser, made by GNU Bison 2.7.1081-93af.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,13 +44,13 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.7.1067-29fb-dirty"
+#define YYBISON_VERSION "2.7.1081-93af"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
 
 /* Pure parsers.  */
-#define YYPURE 1
+#define YYPURE 2
 
 /* Push parsers.  */
 #define YYPUSH 0
@@ -117,16 +117,12 @@ static YYLTYPE lloc_default (YYLTYPE const *, int);
 
 static void version_check (location const *loc, char const *version);
 
-/* Request detailed syntax error messages, and pass them to GRAM_ERROR.
-   FIXME: depends on the undocumented availability of YYLLOC.  */
-#undef  yyerror
-#define yyerror(Msg) \
-        gram_error (&yylloc, Msg)
 static void gram_error (location const *, char const *);
 
+/// A string that describes a char (e.g., 'a' -> "'a'").
 static char const *char_name (char);
 
-#line 130 "src/parse-gram.c" /* yacc.c:357  */
+#line 126 "src/parse-gram.c" /* yacc.c:357  */
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -164,7 +160,7 @@ static char const *char_name (char);
 extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
-#line 223 "src/parse-gram.y" /* yacc.c:373  */
+#line 219 "src/parse-gram.y" /* yacc.c:373  */
 
 # ifndef PARAM_TYPE
 #  define PARAM_TYPE
@@ -178,7 +174,7 @@ extern int gram_debug;
 # endif
 
 
-#line 182 "src/parse-gram.c" /* yacc.c:373  */
+#line 178 "src/parse-gram.c" /* yacc.c:373  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -304,7 +300,7 @@ extern int gram_debug;
 typedef union GRAM_STYPE GRAM_STYPE;
 union GRAM_STYPE
 {
-#line 109 "src/parse-gram.y" /* yacc.c:373  */
+#line 105 "src/parse-gram.y" /* yacc.c:373  */
 
   assoc assoc;
   char *code;
@@ -316,14 +312,14 @@ union GRAM_STYPE
   uniqstr uniqstr;
   unsigned char character;
 
-#line 247 "src/parse-gram.y" /* yacc.c:373  */
+#line 243 "src/parse-gram.y" /* yacc.c:373  */
 
   param_type param;
 
-#line 423 "src/parse-gram.y" /* yacc.c:373  */
+#line 419 "src/parse-gram.y" /* yacc.c:373  */
 code_props_type code_type;
 
-#line 327 "src/parse-gram.c" /* yacc.c:373  */
+#line 323 "src/parse-gram.c" /* yacc.c:373  */
 };
 # define GRAM_STYPE_IS_TRIVIAL 1
 # define GRAM_STYPE_IS_DECLARED 1
@@ -351,9 +347,9 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-#line 355 "src/parse-gram.c" /* yacc.c:376  */
+#line 351 "src/parse-gram.c" /* yacc.c:376  */
 /* Unqualified %code blocks.  */
-#line 58 "src/parse-gram.y" /* yacc.c:377  */
+#line 54 "src/parse-gram.y" /* yacc.c:377  */
 
   static int current_prec = 0;
   static location current_lhs_location;
@@ -367,7 +363,7 @@ int gram_parse (void);
    */
   static
   void
-  current_lhs(symbol *sym, location loc, named_ref *ref)
+  current_lhs (symbol *sym, location loc, named_ref *ref)
   {
     current_lhs_symbol = sym;
     current_lhs_location = loc;
@@ -385,7 +381,7 @@ int gram_parse (void);
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-#line 236 "src/parse-gram.y" /* yacc.c:377  */
+#line 232 "src/parse-gram.y" /* yacc.c:377  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -397,7 +393,7 @@ int gram_parse (void);
   static param_type current_param = param_none;
 
 
-#line 401 "src/parse-gram.c" /* yacc.c:377  */
+#line 397 "src/parse-gram.c" /* yacc.c:377  */
 
 #ifdef short
 # undef short
@@ -632,17 +628,17 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   272,   272,   280,   282,   286,   287,   297,   301,   306,
-     307,   312,   317,   318,   319,   320,   325,   334,   335,   336,
-     337,   338,   339,   339,   340,   341,   365,   366,   367,   368,
-     372,   373,   382,   383,   384,   388,   400,   404,   408,   415,
-     426,   427,   437,   438,   442,   454,   454,   459,   459,   464,
-     475,   490,   491,   492,   493,   497,   498,   503,   505,   510,
-     511,   516,   518,   523,   524,   528,   529,   533,   534,   535,
-     540,   545,   550,   556,   562,   573,   574,   583,   584,   590,
-     591,   592,   599,   599,   607,   608,   609,   614,   616,   618,
-     620,   622,   624,   626,   631,   633,   643,   644,   649,   650,
-     651,   660,   680,   682,   691,   696,   697,   702,   709,   711
+       0,   268,   268,   276,   278,   282,   283,   293,   297,   302,
+     303,   308,   313,   314,   315,   316,   321,   330,   331,   332,
+     333,   334,   335,   335,   336,   337,   361,   362,   363,   364,
+     368,   369,   378,   379,   380,   384,   396,   400,   404,   411,
+     422,   423,   433,   434,   438,   450,   450,   455,   455,   460,
+     471,   486,   487,   488,   489,   493,   494,   499,   501,   506,
+     507,   512,   514,   519,   520,   524,   525,   529,   530,   531,
+     536,   541,   546,   552,   558,   569,   570,   579,   580,   586,
+     587,   588,   595,   595,   603,   604,   605,   610,   612,   614,
+     616,   618,   620,   622,   627,   629,   639,   640,   645,   646,
+     647,   656,   676,   678,   687,   692,   693,   698,   705,   707
 };
 #endif
 
@@ -883,7 +879,7 @@ do                                                              \
     }                                                           \
   else                                                          \
     {                                                           \
-      yyerror (YY_("syntax error: cannot back up")); \
+      yyerror (&yylloc, YY_("syntax error: cannot back up")); \
       YYERROR;                                                  \
     }                                                           \
 while (0)
@@ -1010,146 +1006,146 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
     case 3: /* "string"  */
-#line 196 "src/parse-gram.y" /* yacc.c:707  */
+#line 192 "src/parse-gram.y" /* yacc.c:707  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-#line 1016 "src/parse-gram.c" /* yacc.c:707  */
+#line 1012 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 4: /* "integer"  */
-#line 209 "src/parse-gram.y" /* yacc.c:707  */
+#line 205 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1022 "src/parse-gram.c" /* yacc.c:707  */
+#line 1018 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 24: /* "%<flag>"  */
-#line 205 "src/parse-gram.y" /* yacc.c:707  */
+#line 201 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 1028 "src/parse-gram.c" /* yacc.c:707  */
+#line 1024 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 40: /* "{...}"  */
-#line 198 "src/parse-gram.y" /* yacc.c:707  */
+#line 194 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1034 "src/parse-gram.c" /* yacc.c:707  */
+#line 1030 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 42: /* "[identifier]"  */
-#line 203 "src/parse-gram.y" /* yacc.c:707  */
+#line 199 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 1040 "src/parse-gram.c" /* yacc.c:707  */
+#line 1036 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 43: /* "char"  */
-#line 190 "src/parse-gram.y" /* yacc.c:707  */
+#line 186 "src/parse-gram.y" /* yacc.c:707  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 1046 "src/parse-gram.c" /* yacc.c:707  */
+#line 1042 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 44: /* "epilogue"  */
-#line 198 "src/parse-gram.y" /* yacc.c:707  */
+#line 194 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1052 "src/parse-gram.c" /* yacc.c:707  */
+#line 1048 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 46: /* "identifier"  */
-#line 202 "src/parse-gram.y" /* yacc.c:707  */
+#line 198 "src/parse-gram.y" /* yacc.c:707  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1058 "src/parse-gram.c" /* yacc.c:707  */
+#line 1054 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 47: /* "identifier:"  */
-#line 204 "src/parse-gram.y" /* yacc.c:707  */
+#line 200 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1064 "src/parse-gram.c" /* yacc.c:707  */
+#line 1060 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 50: /* "%{...%}"  */
-#line 198 "src/parse-gram.y" /* yacc.c:707  */
+#line 194 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1070 "src/parse-gram.c" /* yacc.c:707  */
+#line 1066 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 52: /* "<tag>"  */
-#line 206 "src/parse-gram.y" /* yacc.c:707  */
+#line 202 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1076 "src/parse-gram.c" /* yacc.c:707  */
+#line 1072 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 55: /* "%param"  */
-#line 252 "src/parse-gram.y" /* yacc.c:707  */
+#line 248 "src/parse-gram.y" /* yacc.c:707  */
       {
   switch (((*yyvaluep).param))
     {
 #define CASE(In, Out)                                           \
       case param_ ## In: fputs ("%" #Out, stderr); break
-      CASE(lex,   lex-param);
-      CASE(parse, parse-param);
-      CASE(both,  param);
+      CASE (lex,   lex-param);
+      CASE (parse, parse-param);
+      CASE (both,  param);
 #undef CASE
       case param_none: aver (false); break;
     }
 }
-#line 1093 "src/parse-gram.c" /* yacc.c:707  */
+#line 1089 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 64: /* code_props_type  */
-#line 424 "src/parse-gram.y" /* yacc.c:707  */
+#line 420 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1099 "src/parse-gram.c" /* yacc.c:707  */
+#line 1095 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 73: /* symbol.prec  */
-#line 212 "src/parse-gram.y" /* yacc.c:707  */
+#line 208 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1105 "src/parse-gram.c" /* yacc.c:707  */
+#line 1101 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 77: /* tag  */
-#line 206 "src/parse-gram.y" /* yacc.c:707  */
+#line 202 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1111 "src/parse-gram.c" /* yacc.c:707  */
+#line 1107 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 87: /* variable  */
-#line 202 "src/parse-gram.y" /* yacc.c:707  */
+#line 198 "src/parse-gram.y" /* yacc.c:707  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1117 "src/parse-gram.c" /* yacc.c:707  */
+#line 1113 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 88: /* content.opt  */
-#line 198 "src/parse-gram.y" /* yacc.c:707  */
+#line 194 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1123 "src/parse-gram.c" /* yacc.c:707  */
+#line 1119 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 89: /* braceless  */
-#line 198 "src/parse-gram.y" /* yacc.c:707  */
+#line 194 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1129 "src/parse-gram.c" /* yacc.c:707  */
+#line 1125 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 90: /* id  */
-#line 212 "src/parse-gram.y" /* yacc.c:707  */
+#line 208 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1135 "src/parse-gram.c" /* yacc.c:707  */
+#line 1131 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 91: /* id_colon  */
-#line 213 "src/parse-gram.y" /* yacc.c:707  */
+#line 209 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1141 "src/parse-gram.c" /* yacc.c:707  */
+#line 1137 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 92: /* symbol  */
-#line 212 "src/parse-gram.y" /* yacc.c:707  */
+#line 208 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1147 "src/parse-gram.c" /* yacc.c:707  */
+#line 1143 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 93: /* string_as_id  */
-#line 212 "src/parse-gram.y" /* yacc.c:707  */
+#line 208 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1153 "src/parse-gram.c" /* yacc.c:707  */
+#line 1149 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
       default:
@@ -1864,14 +1860,14 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 101 "src/parse-gram.y" /* yacc.c:1452  */
+#line 97 "src/parse-gram.y" /* yacc.c:1452  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-#line 1875 "src/parse-gram.c" /* yacc.c:1452  */
+#line 1871 "src/parse-gram.c" /* yacc.c:1452  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2065,7 +2061,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-#line 288 "src/parse-gram.y" /* yacc.c:1669  */
+#line 284 "src/parse-gram.y" /* yacc.c:1669  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2075,79 +2071,79 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2079 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2075 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 7:
-#line 298 "src/parse-gram.y" /* yacc.c:1669  */
+#line 294 "src/parse-gram.y" /* yacc.c:1669  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2087 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2083 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 8:
-#line 302 "src/parse-gram.y" /* yacc.c:1669  */
+#line 298 "src/parse-gram.y" /* yacc.c:1669  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2096 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2092 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 9:
-#line 306 "src/parse-gram.y" /* yacc.c:1669  */
+#line 302 "src/parse-gram.y" /* yacc.c:1669  */
     { defines_flag = true; }
-#line 2102 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2098 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 10:
-#line 308 "src/parse-gram.y" /* yacc.c:1669  */
+#line 304 "src/parse-gram.y" /* yacc.c:1669  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-#line 2111 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2107 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 11:
-#line 313 "src/parse-gram.y" /* yacc.c:1669  */
+#line 309 "src/parse-gram.y" /* yacc.c:1669  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2120 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2116 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 12:
-#line 317 "src/parse-gram.y" /* yacc.c:1669  */
+#line 313 "src/parse-gram.y" /* yacc.c:1669  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2126 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2122 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 13:
-#line 318 "src/parse-gram.y" /* yacc.c:1669  */
+#line 314 "src/parse-gram.y" /* yacc.c:1669  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2132 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2128 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 14:
-#line 319 "src/parse-gram.y" /* yacc.c:1669  */
+#line 315 "src/parse-gram.y" /* yacc.c:1669  */
     { spec_file_prefix = (yyvsp[0].chars); }
-#line 2138 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2134 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 15:
-#line 321 "src/parse-gram.y" /* yacc.c:1669  */
+#line 317 "src/parse-gram.y" /* yacc.c:1669  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2147 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2143 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 16:
-#line 326 "src/parse-gram.y" /* yacc.c:1669  */
+#line 322 "src/parse-gram.y" /* yacc.c:1669  */
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2156,59 +2152,59 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2160 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2156 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 17:
-#line 334 "src/parse-gram.y" /* yacc.c:1669  */
+#line 330 "src/parse-gram.y" /* yacc.c:1669  */
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-#line 2166 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2162 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 18:
-#line 335 "src/parse-gram.y" /* yacc.c:1669  */
+#line 331 "src/parse-gram.y" /* yacc.c:1669  */
     { spec_name_prefix = (yyvsp[0].chars); }
-#line 2172 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2168 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 19:
-#line 336 "src/parse-gram.y" /* yacc.c:1669  */
+#line 332 "src/parse-gram.y" /* yacc.c:1669  */
     { no_lines_flag = true; }
-#line 2178 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2174 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 20:
-#line 337 "src/parse-gram.y" /* yacc.c:1669  */
+#line 333 "src/parse-gram.y" /* yacc.c:1669  */
     { nondeterministic_parser = true; }
-#line 2184 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2180 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 21:
-#line 338 "src/parse-gram.y" /* yacc.c:1669  */
+#line 334 "src/parse-gram.y" /* yacc.c:1669  */
     { spec_outfile = (yyvsp[0].chars); }
-#line 2190 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2186 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 22:
-#line 339 "src/parse-gram.y" /* yacc.c:1669  */
+#line 335 "src/parse-gram.y" /* yacc.c:1669  */
     { current_param = (yyvsp[0].param); }
-#line 2196 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2192 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 23:
-#line 339 "src/parse-gram.y" /* yacc.c:1669  */
+#line 335 "src/parse-gram.y" /* yacc.c:1669  */
     { current_param = param_none; }
-#line 2202 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2198 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 24:
-#line 340 "src/parse-gram.y" /* yacc.c:1669  */
+#line 336 "src/parse-gram.y" /* yacc.c:1669  */
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-#line 2208 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2204 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 25:
-#line 342 "src/parse-gram.y" /* yacc.c:1669  */
+#line 338 "src/parse-gram.y" /* yacc.c:1669  */
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2232,49 +2228,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2236 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2232 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 26:
-#line 365 "src/parse-gram.y" /* yacc.c:1669  */
+#line 361 "src/parse-gram.y" /* yacc.c:1669  */
     { token_table_flag = true; }
-#line 2242 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2238 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 27:
-#line 366 "src/parse-gram.y" /* yacc.c:1669  */
+#line 362 "src/parse-gram.y" /* yacc.c:1669  */
     { report_flag |= report_states; }
-#line 2248 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2244 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 28:
-#line 367 "src/parse-gram.y" /* yacc.c:1669  */
+#line 363 "src/parse-gram.y" /* yacc.c:1669  */
     { yacc_flag = true; }
-#line 2254 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2250 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 30:
-#line 372 "src/parse-gram.y" /* yacc.c:1669  */
+#line 368 "src/parse-gram.y" /* yacc.c:1669  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2260 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2256 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 31:
-#line 373 "src/parse-gram.y" /* yacc.c:1669  */
+#line 369 "src/parse-gram.y" /* yacc.c:1669  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2266 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2262 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 34:
-#line 385 "src/parse-gram.y" /* yacc.c:1669  */
+#line 381 "src/parse-gram.y" /* yacc.c:1669  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2274 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2270 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 35:
-#line 389 "src/parse-gram.y" /* yacc.c:1669  */
+#line 385 "src/parse-gram.y" /* yacc.c:1669  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2286,111 +2282,111 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2290 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2286 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 36:
-#line 401 "src/parse-gram.y" /* yacc.c:1669  */
+#line 397 "src/parse-gram.y" /* yacc.c:1669  */
     {
       default_prec = true;
     }
-#line 2298 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2294 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 37:
-#line 405 "src/parse-gram.y" /* yacc.c:1669  */
+#line 401 "src/parse-gram.y" /* yacc.c:1669  */
     {
       default_prec = false;
     }
-#line 2306 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2302 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 38:
-#line 409 "src/parse-gram.y" /* yacc.c:1669  */
+#line 405 "src/parse-gram.y" /* yacc.c:1669  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2317 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2313 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 39:
-#line 416 "src/parse-gram.y" /* yacc.c:1669  */
+#line 412 "src/parse-gram.y" /* yacc.c:1669  */
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2326 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2322 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 40:
-#line 426 "src/parse-gram.y" /* yacc.c:1669  */
+#line 422 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.code_type) = destructor; }
-#line 2332 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2328 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 41:
-#line 427 "src/parse-gram.y" /* yacc.c:1669  */
+#line 423 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.code_type) = printer; }
-#line 2338 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2334 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 42:
-#line 437 "src/parse-gram.y" /* yacc.c:1669  */
+#line 433 "src/parse-gram.y" /* yacc.c:1669  */
     {}
-#line 2344 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2340 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 43:
-#line 438 "src/parse-gram.y" /* yacc.c:1669  */
+#line 434 "src/parse-gram.y" /* yacc.c:1669  */
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2350 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2346 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 44:
-#line 443 "src/parse-gram.y" /* yacc.c:1669  */
+#line 439 "src/parse-gram.y" /* yacc.c:1669  */
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2360 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2356 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 45:
-#line 454 "src/parse-gram.y" /* yacc.c:1669  */
+#line 450 "src/parse-gram.y" /* yacc.c:1669  */
     { current_class = nterm_sym; }
-#line 2366 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2362 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 46:
-#line 455 "src/parse-gram.y" /* yacc.c:1669  */
+#line 451 "src/parse-gram.y" /* yacc.c:1669  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2375 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2371 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 47:
-#line 459 "src/parse-gram.y" /* yacc.c:1669  */
+#line 455 "src/parse-gram.y" /* yacc.c:1669  */
     { current_class = token_sym; }
-#line 2381 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2377 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 48:
-#line 460 "src/parse-gram.y" /* yacc.c:1669  */
+#line 456 "src/parse-gram.y" /* yacc.c:1669  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2390 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2386 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 49:
-#line 465 "src/parse-gram.y" /* yacc.c:1669  */
+#line 461 "src/parse-gram.y" /* yacc.c:1669  */
     {
       symbol_list *list;
       tag_seen = true;
@@ -2398,11 +2394,11 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2402 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2398 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 50:
-#line 476 "src/parse-gram.y" /* yacc.c:1669  */
+#line 472 "src/parse-gram.y" /* yacc.c:1669  */
     {
       symbol_list *list;
       ++current_prec;
@@ -2414,276 +2410,276 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2418 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2414 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 51:
-#line 490 "src/parse-gram.y" /* yacc.c:1669  */
+#line 486 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.assoc) = left_assoc; }
-#line 2424 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2420 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 52:
-#line 491 "src/parse-gram.y" /* yacc.c:1669  */
+#line 487 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.assoc) = right_assoc; }
-#line 2430 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2426 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 53:
-#line 492 "src/parse-gram.y" /* yacc.c:1669  */
+#line 488 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.assoc) = non_assoc; }
-#line 2436 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2432 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 54:
-#line 493 "src/parse-gram.y" /* yacc.c:1669  */
+#line 489 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2442 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2438 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 55:
-#line 497 "src/parse-gram.y" /* yacc.c:1669  */
+#line 493 "src/parse-gram.y" /* yacc.c:1669  */
     { current_type = NULL; }
-#line 2448 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2444 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 56:
-#line 498 "src/parse-gram.y" /* yacc.c:1669  */
+#line 494 "src/parse-gram.y" /* yacc.c:1669  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2454 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2450 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 57:
-#line 504 "src/parse-gram.y" /* yacc.c:1669  */
+#line 500 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2460 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2456 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 58:
-#line 506 "src/parse-gram.y" /* yacc.c:1669  */
+#line 502 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2466 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2462 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 59:
-#line 510 "src/parse-gram.y" /* yacc.c:1669  */
+#line 506 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.symbol) = (yyvsp[0].symbol); }
-#line 2472 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2468 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 60:
-#line 511 "src/parse-gram.y" /* yacc.c:1669  */
+#line 507 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-#line 2478 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2474 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 61:
-#line 517 "src/parse-gram.y" /* yacc.c:1669  */
+#line 513 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2484 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2480 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 62:
-#line 519 "src/parse-gram.y" /* yacc.c:1669  */
+#line 515 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2490 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2486 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 63:
-#line 523 "src/parse-gram.y" /* yacc.c:1669  */
+#line 519 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2496 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2492 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 64:
-#line 524 "src/parse-gram.y" /* yacc.c:1669  */
+#line 520 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2502 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2498 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 65:
-#line 528 "src/parse-gram.y" /* yacc.c:1669  */
+#line 524 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2508 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2504 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 66:
-#line 529 "src/parse-gram.y" /* yacc.c:1669  */
+#line 525 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2514 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2510 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 68:
-#line 534 "src/parse-gram.y" /* yacc.c:1669  */
+#line 530 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2520 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2516 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 69:
-#line 535 "src/parse-gram.y" /* yacc.c:1669  */
+#line 531 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2526 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2522 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 70:
-#line 541 "src/parse-gram.y" /* yacc.c:1669  */
+#line 537 "src/parse-gram.y" /* yacc.c:1669  */
     {
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2535 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2531 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 71:
-#line 546 "src/parse-gram.y" /* yacc.c:1669  */
+#line 542 "src/parse-gram.y" /* yacc.c:1669  */
     {
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2544 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2540 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 72:
-#line 551 "src/parse-gram.y" /* yacc.c:1669  */
+#line 547 "src/parse-gram.y" /* yacc.c:1669  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2554 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2550 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 73:
-#line 557 "src/parse-gram.y" /* yacc.c:1669  */
+#line 553 "src/parse-gram.y" /* yacc.c:1669  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2564 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2560 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 74:
-#line 563 "src/parse-gram.y" /* yacc.c:1669  */
+#line 559 "src/parse-gram.y" /* yacc.c:1669  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2575 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2571 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 81:
-#line 593 "src/parse-gram.y" /* yacc.c:1669  */
+#line 589 "src/parse-gram.y" /* yacc.c:1669  */
     {
       yyerrok;
     }
-#line 2583 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2579 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 82:
-#line 599 "src/parse-gram.y" /* yacc.c:1669  */
+#line 595 "src/parse-gram.y" /* yacc.c:1669  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2589 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2585 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 83:
-#line 600 "src/parse-gram.y" /* yacc.c:1669  */
+#line 596 "src/parse-gram.y" /* yacc.c:1669  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2598 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2594 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 84:
-#line 607 "src/parse-gram.y" /* yacc.c:1669  */
+#line 603 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2604 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2600 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 85:
-#line 608 "src/parse-gram.y" /* yacc.c:1669  */
+#line 604 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2610 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2606 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 87:
-#line 614 "src/parse-gram.y" /* yacc.c:1669  */
+#line 610 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2617 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2613 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 88:
-#line 617 "src/parse-gram.y" /* yacc.c:1669  */
+#line 613 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2623 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2619 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 89:
-#line 619 "src/parse-gram.y" /* yacc.c:1669  */
+#line 615 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-#line 2629 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2625 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 90:
-#line 621 "src/parse-gram.y" /* yacc.c:1669  */
+#line 617 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-#line 2635 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2631 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 91:
-#line 623 "src/parse-gram.y" /* yacc.c:1669  */
+#line 619 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2641 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2637 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 92:
-#line 625 "src/parse-gram.y" /* yacc.c:1669  */
+#line 621 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2647 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2643 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 93:
-#line 627 "src/parse-gram.y" /* yacc.c:1669  */
+#line 623 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2653 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2649 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 94:
-#line 631 "src/parse-gram.y" /* yacc.c:1669  */
+#line 627 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.named_ref) = 0; }
-#line 2659 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2655 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 95:
-#line 633 "src/parse-gram.y" /* yacc.c:1669  */
-    { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2665 "src/parse-gram.c" /* yacc.c:1669  */
+#line 629 "src/parse-gram.y" /* yacc.c:1669  */
+    { (yyval.named_ref) = named_ref_new ((yyvsp[0].uniqstr), (yylsp[0])); }
+#line 2661 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 97:
-#line 644 "src/parse-gram.y" /* yacc.c:1669  */
+#line 640 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-#line 2671 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2667 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 98:
-#line 649 "src/parse-gram.y" /* yacc.c:1669  */
+#line 645 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.chars) = ""; }
-#line 2677 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2673 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 99:
-#line 650 "src/parse-gram.y" /* yacc.c:1669  */
+#line 646 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-#line 2683 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2679 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 101:
-#line 661 "src/parse-gram.y" /* yacc.c:1669  */
+#line 657 "src/parse-gram.y" /* yacc.c:1669  */
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2692,42 +2688,42 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-#line 2696 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2692 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 102:
-#line 681 "src/parse-gram.y" /* yacc.c:1669  */
+#line 677 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2702 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2698 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 103:
-#line 683 "src/parse-gram.y" /* yacc.c:1669  */
+#line 679 "src/parse-gram.y" /* yacc.c:1669  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2712 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2708 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 104:
-#line 691 "src/parse-gram.y" /* yacc.c:1669  */
+#line 687 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2718 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2714 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 107:
-#line 703 "src/parse-gram.y" /* yacc.c:1669  */
+#line 699 "src/parse-gram.y" /* yacc.c:1669  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2727 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2723 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 109:
-#line 712 "src/parse-gram.y" /* yacc.c:1669  */
+#line 708 "src/parse-gram.y" /* yacc.c:1669  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2736,11 +2732,11 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2740 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2736 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
 
-#line 2744 "src/parse-gram.c" /* yacc.c:1669  */
+#line 2740 "src/parse-gram.c" /* yacc.c:1669  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2794,7 +2790,7 @@ yyerrlab:
     {
       ++yynerrs;
 #if ! YYERROR_VERBOSE
-      yyerror (YY_("syntax error"));
+      yyerror (&yylloc, YY_("syntax error"));
 #else
 # define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                         yyesa, &yyes, &yyes_capacity, \
@@ -2824,7 +2820,7 @@ yyerrlab:
                 yymsgp = yymsg;
               }
           }
-        yyerror (yymsgp);
+        yyerror (&yylloc, yymsgp);
         if (yysyntax_error_status == 2)
           goto yyexhaustedlab;
       }
@@ -2951,7 +2947,7 @@ yyabortlab:
 | yyexhaustedlab -- memory exhaustion comes here.  |
 `-------------------------------------------------*/
 yyexhaustedlab:
-  yyerror (YY_("memory exhausted"));
+  yyerror (&yylloc, YY_("memory exhausted"));
   yyresult = 2;
   /* Fall through.  */
 #endif
@@ -2987,7 +2983,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 722 "src/parse-gram.y" /* yacc.c:1929  */
+#line 718 "src/parse-gram.y" /* yacc.c:1929  */
 
 
 /* Return the location of the left-hand side of a rule whose
