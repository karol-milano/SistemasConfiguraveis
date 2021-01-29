@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.687-d4fc-dirty.  */
+/* A Bison parser, made by GNU Bison 2.5.1_rc2.741-bfd9.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.687-d4fc-dirty"
+#define YYBISON_VERSION "2.5.1_rc2.741-bfd9"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -108,6 +108,7 @@
 #include "symlist.h"
 #include "scan-gram.h"
 #include "scan-code.h"
+#include "xmemdup0.h"
 
 #define YYLLOC_DEFAULT(Current, Rhs, N)  (Current) = lloc_default (Rhs, N)
 static YYLTYPE lloc_default (YYLTYPE const *, int);
@@ -127,7 +128,15 @@ static void gram_error (location const *, char const *);
 static char const *char_name (char);
 
 /* Line 269 of yacc.c  */
-#line 131 "src/parse-gram.c"
+#line 132 "src/parse-gram.c"
+
+# ifndef YY_NULL
+#  if defined __cplusplus && 201103L <= __cplusplus
+#   define YY_NULL nullptr
+#  else
+#   define YY_NULL 0
+#  endif
+# endif
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -148,8 +157,8 @@ static char const *char_name (char);
 #endif
 
 /* "%code requires" blocks.  */
-/* Line 289 of yacc.c  */
-#line 220 "src/parse-gram.y"
+/* Line 291 of yacc.c  */
+#line 221 "src/parse-gram.y"
 
 # ifndef PARAM_TYPE
 #  define PARAM_TYPE
@@ -163,8 +172,8 @@ static char const *char_name (char);
 # endif
 
 
-/* Line 289 of yacc.c  */
-#line 168 "src/parse-gram.c"
+/* Line 291 of yacc.c  */
+#line 177 "src/parse-gram.c"
 
 /* Tokens.  */
 #ifndef YYTOKENTYPE
@@ -292,8 +301,8 @@ static char const *char_name (char);
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 294 of yacc.c  */
-#line 106 "src/parse-gram.y"
+/* Line 296 of yacc.c  */
+#line 107 "src/parse-gram.y"
 
   assoc assoc;
   char *code;
@@ -305,14 +314,14 @@ typedef union YYSTYPE
   uniqstr uniqstr;
   unsigned char character;
 
-/* Line 294 of yacc.c  */
-#line 244 "src/parse-gram.y"
+/* Line 296 of yacc.c  */
+#line 245 "src/parse-gram.y"
 
   param_type param;
 
 
-/* Line 294 of yacc.c  */
-#line 316 "src/parse-gram.c"
+/* Line 296 of yacc.c  */
+#line 325 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -335,11 +344,11 @@ typedef struct YYLTYPE
 
 /* Copy the second part of user declarations.  */
 
-/* Line 344 of yacc.c  */
-#line 340 "src/parse-gram.c"
+/* Line 346 of yacc.c  */
+#line 349 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
-/* Line 345 of yacc.c  */
-#line 55 "src/parse-gram.y"
+/* Line 347 of yacc.c  */
+#line 56 "src/parse-gram.y"
 
   static int current_prec = 0;
   static location current_lhs_location;
@@ -371,8 +380,8 @@ typedef struct YYLTYPE
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-/* Line 345 of yacc.c  */
-#line 233 "src/parse-gram.y"
+/* Line 347 of yacc.c  */
+#line 234 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -384,8 +393,8 @@ typedef struct YYLTYPE
   static param_type current_param = param_none;
 
 
-/* Line 345 of yacc.c  */
-#line 389 "src/parse-gram.c"
+/* Line 347 of yacc.c  */
+#line 398 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -644,18 +653,18 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   269,   269,   277,   279,   283,   284,   294,   298,   303,
-     304,   309,   314,   315,   316,   317,   318,   323,   332,   333,
-     334,   335,   336,   337,   338,   339,   339,   340,   341,   365,
-     366,   367,   368,   372,   373,   382,   383,   384,   388,   395,
-     402,   406,   410,   417,   432,   433,   437,   449,   449,   454,
-     454,   459,   470,   485,   486,   487,   488,   492,   493,   498,
-     500,   505,   506,   511,   513,   518,   519,   523,   524,   525,
-     526,   531,   536,   541,   547,   553,   564,   565,   574,   575,
-     581,   582,   583,   590,   590,   598,   599,   600,   605,   607,
-     609,   611,   613,   615,   617,   622,   624,   634,   635,   640,
-     641,   642,   651,   671,   673,   682,   687,   688,   693,   700,
-     702
+       0,   270,   270,   278,   280,   284,   285,   295,   299,   304,
+     305,   310,   315,   316,   317,   318,   319,   324,   333,   334,
+     335,   336,   337,   338,   339,   340,   340,   341,   342,   366,
+     367,   368,   369,   373,   374,   383,   384,   385,   389,   396,
+     403,   407,   411,   418,   433,   434,   438,   450,   450,   455,
+     455,   460,   471,   486,   487,   488,   489,   493,   494,   499,
+     501,   506,   507,   512,   514,   519,   520,   524,   525,   526,
+     527,   532,   537,   542,   548,   554,   565,   566,   575,   576,
+     582,   583,   584,   591,   591,   599,   600,   601,   606,   608,
+     610,   612,   614,   616,   618,   623,   625,   635,   636,   641,
+     642,   643,   652,   672,   674,   683,   688,   689,   694,   701,
+     703
 };
 #endif
 
@@ -685,7 +694,7 @@ static const char *const yytname[] =
   "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
   "rules_or_grammar_declaration", "rules", "$@4", "rhses.1", "rhs",
   "named_ref.opt", "variable", "content.opt", "braceless", "id",
-  "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
+  "id_colon", "symbol", "string_as_id", "epilogue.opt", YY_NULL
 };
 #endif
 
@@ -1019,9 +1028,9 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     YYLTYPE const * const yylocationp;
 #endif
 {
-  YYUSE(yyoutput);
+  FILE *yyo = yyoutput;
+  YYUSE(yyo);
   YYUSE (yylocationp);
-
   if (!yyvaluep)
     return;
 # ifdef YYPRINT
@@ -1032,107 +1041,107 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
             case 3: // "string"
 
-/* Line 753 of yacc.c  */
-#line 193 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 194 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
-/* Line 753 of yacc.c  */
-#line 1040 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1049 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
-/* Line 753 of yacc.c  */
-#line 206 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 207 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
-/* Line 753 of yacc.c  */
-#line 1049 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1058 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
 
-/* Line 753 of yacc.c  */
-#line 202 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 203 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 753 of yacc.c  */
-#line 1058 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1067 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
 
-/* Line 753 of yacc.c  */
-#line 195 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 753 of yacc.c  */
-#line 1067 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1076 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
 
-/* Line 753 of yacc.c  */
-#line 200 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 201 "src/parse-gram.y"
         { fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 753 of yacc.c  */
-#line 1076 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1085 "src/parse-gram.c"
         break;
 
             case 43: // "char"
 
-/* Line 753 of yacc.c  */
-#line 187 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 188 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
-/* Line 753 of yacc.c  */
-#line 1085 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1094 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
 
-/* Line 753 of yacc.c  */
-#line 195 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 753 of yacc.c  */
-#line 1094 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1103 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
 
-/* Line 753 of yacc.c  */
-#line 199 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 200 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 753 of yacc.c  */
-#line 1103 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1112 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
 
-/* Line 753 of yacc.c  */
-#line 201 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 202 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 753 of yacc.c  */
-#line 1112 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1121 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
 
-/* Line 753 of yacc.c  */
-#line 195 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 753 of yacc.c  */
-#line 1121 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1130 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
 
-/* Line 753 of yacc.c  */
-#line 203 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 204 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 753 of yacc.c  */
-#line 1130 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1139 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
 
-/* Line 753 of yacc.c  */
-#line 249 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 250 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
     {
@@ -1145,80 +1154,80 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case param_none: aver (false); break;
     }
 }
-/* Line 753 of yacc.c  */
-#line 1150 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1159 "src/parse-gram.c"
         break;
 
             case 72: // symbol.prec
 
-/* Line 753 of yacc.c  */
-#line 209 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 753 of yacc.c  */
-#line 1159 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1168 "src/parse-gram.c"
         break;
 
             case 85: // variable
 
-/* Line 753 of yacc.c  */
-#line 199 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 200 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 753 of yacc.c  */
-#line 1168 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1177 "src/parse-gram.c"
         break;
 
             case 86: // content.opt
 
-/* Line 753 of yacc.c  */
-#line 195 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 753 of yacc.c  */
-#line 1177 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1186 "src/parse-gram.c"
         break;
 
             case 87: // braceless
 
-/* Line 753 of yacc.c  */
-#line 195 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 196 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 753 of yacc.c  */
-#line 1186 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1195 "src/parse-gram.c"
         break;
 
             case 88: // id
 
-/* Line 753 of yacc.c  */
-#line 209 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 753 of yacc.c  */
-#line 1195 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1204 "src/parse-gram.c"
         break;
 
             case 89: // id_colon
 
-/* Line 753 of yacc.c  */
-#line 210 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 211 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 753 of yacc.c  */
-#line 1204 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1213 "src/parse-gram.c"
         break;
 
             case 90: // symbol
 
-/* Line 753 of yacc.c  */
-#line 209 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 753 of yacc.c  */
-#line 1213 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1222 "src/parse-gram.c"
         break;
 
             case 91: // string_as_id
 
-/* Line 753 of yacc.c  */
-#line 209 "src/parse-gram.y"
+/* Line 755 of yacc.c  */
+#line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 753 of yacc.c  */
-#line 1222 "src/parse-gram.c"
+/* Line 755 of yacc.c  */
+#line 1231 "src/parse-gram.c"
         break;
 
       default:
@@ -1704,12 +1713,12 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                 yytype_int16 *yyesa, yytype_int16 **yyes,
                 YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
 {
-  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
+  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
   YYSIZE_T yysize1;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
-  const char *yyformat = 0;
+  const char *yyformat = YY_NULL;
   /* Arguments of yyformat. */
   char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
   /* Number of reported tokens (one for the "unexpected", one per
@@ -1767,7 +1776,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                     break;
                   }
                 yyarg[yycount++] = yytname[yyx];
-                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
+                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                 if (! (yysize <= yysize1
                        && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                   return 2;
@@ -1851,7 +1860,6 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
 {
   YYUSE(yyvaluep);
   YYUSE (yylocationp);
-
   if (!yymsg)
     yymsg = "Deleting";
   YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);
@@ -2012,16 +2020,16 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1526 of yacc.c  */
-#line 98 "src/parse-gram.y"
+/* Line 1528 of yacc.c  */
+#line 99 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1526 of yacc.c  */
-#line 2025 "src/parse-gram.c"
+/* Line 1528 of yacc.c  */
+#line 2033 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2214,8 +2222,8 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1742 of yacc.c  */
-#line 285 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 286 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2225,107 +2233,107 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1742 of yacc.c  */
-#line 2230 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2238 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1742 of yacc.c  */
-#line 295 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 296 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1742 of yacc.c  */
-#line 2240 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2248 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1742 of yacc.c  */
-#line 299 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 300 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1742 of yacc.c  */
-#line 2251 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2259 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1742 of yacc.c  */
-#line 303 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 304 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1742 of yacc.c  */
-#line 2259 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2267 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1742 of yacc.c  */
-#line 305 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 306 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1742 of yacc.c  */
-#line 2270 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2278 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1742 of yacc.c  */
-#line 310 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 311 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1742 of yacc.c  */
-#line 2281 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2289 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1742 of yacc.c  */
-#line 314 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 315 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1742 of yacc.c  */
-#line 2289 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2297 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1742 of yacc.c  */
-#line 315 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 316 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1742 of yacc.c  */
-#line 2297 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2305 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1742 of yacc.c  */
-#line 316 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 317 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1742 of yacc.c  */
-#line 2305 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2313 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1742 of yacc.c  */
-#line 317 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 318 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1742 of yacc.c  */
-#line 2313 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2321 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1742 of yacc.c  */
-#line 319 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 320 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1742 of yacc.c  */
-#line 2324 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2332 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1742 of yacc.c  */
-#line 324 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 325 "src/parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2334,93 +2342,93 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1742 of yacc.c  */
-#line 2339 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2347 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1742 of yacc.c  */
-#line 332 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 333 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1742 of yacc.c  */
-#line 2347 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2355 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1742 of yacc.c  */
-#line 333 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 334 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1742 of yacc.c  */
-#line 2355 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2363 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1742 of yacc.c  */
-#line 334 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 335 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1742 of yacc.c  */
-#line 2363 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2371 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1742 of yacc.c  */
-#line 335 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 336 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1742 of yacc.c  */
-#line 2371 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2379 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1742 of yacc.c  */
-#line 336 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 337 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1742 of yacc.c  */
-#line 2379 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2387 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1742 of yacc.c  */
-#line 337 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 338 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1742 of yacc.c  */
-#line 2387 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2395 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1742 of yacc.c  */
-#line 338 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 339 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1742 of yacc.c  */
-#line 2395 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2403 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1742 of yacc.c  */
-#line 339 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 340 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1742 of yacc.c  */
-#line 2403 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2411 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1742 of yacc.c  */
-#line 339 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 340 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1742 of yacc.c  */
-#line 2411 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2419 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1742 of yacc.c  */
-#line 340 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 341 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1742 of yacc.c  */
-#line 2419 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2427 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1742 of yacc.c  */
-#line 342 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 343 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (mbschr (skeleton_user, '/'))
@@ -2435,7 +2443,7 @@ yyreduce:
             xmalloc (dir_length + 1 + strlen (skeleton_user) + 1);
           if (dir_length > 0)
             {
-              strncpy (skeleton_build, current_file, dir_length);
+              memcpy (skeleton_build, current_file, dir_length);
               skeleton_build[dir_length++] = '/';
             }
           strcpy (skeleton_build + dir_length, skeleton_user);
@@ -2444,199 +2452,199 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1742 of yacc.c  */
-#line 2449 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2457 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1742 of yacc.c  */
-#line 365 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 366 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1742 of yacc.c  */
-#line 2457 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2465 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1742 of yacc.c  */
-#line 366 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 367 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1742 of yacc.c  */
-#line 2465 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2473 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1742 of yacc.c  */
-#line 367 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 368 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1742 of yacc.c  */
-#line 2473 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2481 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1742 of yacc.c  */
-#line 372 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 373 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2481 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2489 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1742 of yacc.c  */
-#line 373 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 374 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2489 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2497 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1742 of yacc.c  */
-#line 385 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 386 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1742 of yacc.c  */
-#line 2499 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2507 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1742 of yacc.c  */
-#line 389 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 390 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
         symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1742 of yacc.c  */
-#line 2512 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2520 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1742 of yacc.c  */
-#line 396 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 397 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
         symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1742 of yacc.c  */
-#line 2525 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2533 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1742 of yacc.c  */
-#line 403 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 404 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1742 of yacc.c  */
-#line 2535 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2543 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1742 of yacc.c  */
-#line 407 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 408 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1742 of yacc.c  */
-#line 2545 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2553 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1742 of yacc.c  */
-#line 411 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 412 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1742 of yacc.c  */
-#line 2558 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2566 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1742 of yacc.c  */
-#line 418 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 419 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1742 of yacc.c  */
-#line 2569 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2577 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1742 of yacc.c  */
-#line 432 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 433 "src/parse-gram.y"
     {}
-/* Line 1742 of yacc.c  */
-#line 2577 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2585 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1742 of yacc.c  */
-#line 433 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 434 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2585 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2593 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1742 of yacc.c  */
-#line 438 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 439 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1742 of yacc.c  */
-#line 2597 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2605 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1742 of yacc.c  */
-#line 449 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 450 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1742 of yacc.c  */
-#line 2605 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2613 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1742 of yacc.c  */
-#line 450 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 451 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1742 of yacc.c  */
-#line 2616 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2624 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1742 of yacc.c  */
-#line 454 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 455 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1742 of yacc.c  */
-#line 2624 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2632 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1742 of yacc.c  */
-#line 455 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 456 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1742 of yacc.c  */
-#line 2635 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2643 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1742 of yacc.c  */
-#line 460 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 461 "src/parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2644,13 +2652,13 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1742 of yacc.c  */
-#line 2649 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2657 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1742 of yacc.c  */
-#line 471 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 472 "src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2662,358 +2670,358 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1742 of yacc.c  */
-#line 2667 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2675 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1742 of yacc.c  */
-#line 485 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 486 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1742 of yacc.c  */
-#line 2675 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2683 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1742 of yacc.c  */
-#line 486 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 487 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1742 of yacc.c  */
-#line 2683 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2691 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1742 of yacc.c  */
-#line 487 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 488 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1742 of yacc.c  */
-#line 2691 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2699 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1742 of yacc.c  */
-#line 488 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 489 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1742 of yacc.c  */
-#line 2699 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2707 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1742 of yacc.c  */
-#line 492 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 493 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1742 of yacc.c  */
-#line 2707 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2715 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1742 of yacc.c  */
-#line 493 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 494 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1742 of yacc.c  */
-#line 2715 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2723 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1742 of yacc.c  */
-#line 499 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 500 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2723 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2731 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1742 of yacc.c  */
-#line 501 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 502 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1742 of yacc.c  */
-#line 2731 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2739 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1742 of yacc.c  */
-#line 505 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 506 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1742 of yacc.c  */
-#line 2739 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2747 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1742 of yacc.c  */
-#line 506 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 507 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2747 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2755 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1742 of yacc.c  */
-#line 512 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 513 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2755 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2763 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1742 of yacc.c  */
-#line 514 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 515 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1742 of yacc.c  */
-#line 2763 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2771 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1742 of yacc.c  */
-#line 518 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 519 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1742 of yacc.c  */
-#line 2771 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2779 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1742 of yacc.c  */
-#line 519 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 520 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1742 of yacc.c  */
-#line 2779 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2787 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1742 of yacc.c  */
-#line 523 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 524 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2787 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2795 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1742 of yacc.c  */
-#line 524 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 525 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2795 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2803 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1742 of yacc.c  */
-#line 525 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 526 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2803 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2811 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1742 of yacc.c  */
-#line 526 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 527 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2811 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2819 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1742 of yacc.c  */
-#line 532 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 533 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1742 of yacc.c  */
-#line 2822 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2830 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1742 of yacc.c  */
-#line 537 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 538 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1742 of yacc.c  */
-#line 2833 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2841 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1742 of yacc.c  */
-#line 542 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 543 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1742 of yacc.c  */
-#line 2845 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2853 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1742 of yacc.c  */
-#line 548 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 549 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1742 of yacc.c  */
-#line 2857 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2865 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1742 of yacc.c  */
-#line 554 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 555 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1742 of yacc.c  */
-#line 2870 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2878 "src/parse-gram.c"
     break;
 
   case 82:
-/* Line 1742 of yacc.c  */
-#line 584 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 585 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1742 of yacc.c  */
-#line 2880 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2888 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1742 of yacc.c  */
-#line 590 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 591 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1742 of yacc.c  */
-#line 2888 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2896 "src/parse-gram.c"
     break;
 
   case 84:
-/* Line 1742 of yacc.c  */
-#line 591 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 592 "src/parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-/* Line 1742 of yacc.c  */
-#line 2899 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2907 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1742 of yacc.c  */
-#line 598 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 599 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2907 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2915 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1742 of yacc.c  */
-#line 599 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 600 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2915 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2923 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1742 of yacc.c  */
-#line 605 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 606 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-/* Line 1742 of yacc.c  */
-#line 2924 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2932 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1742 of yacc.c  */
-#line 608 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 609 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1742 of yacc.c  */
-#line 2932 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2940 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1742 of yacc.c  */
-#line 610 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 611 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1742 of yacc.c  */
-#line 2940 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2948 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1742 of yacc.c  */
-#line 612 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 613 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1742 of yacc.c  */
-#line 2948 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2956 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1742 of yacc.c  */
-#line 614 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 615 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2956 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2964 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1742 of yacc.c  */
-#line 616 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 617 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2964 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2972 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1742 of yacc.c  */
-#line 618 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 619 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2972 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2980 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1742 of yacc.c  */
-#line 622 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 623 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1742 of yacc.c  */
-#line 2980 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2988 "src/parse-gram.c"
     break;
 
   case 96:
-/* Line 1742 of yacc.c  */
-#line 624 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 625 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 2988 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 2996 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1742 of yacc.c  */
-#line 635 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 636 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1742 of yacc.c  */
-#line 2996 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 3004 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1742 of yacc.c  */
-#line 640 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 641 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1742 of yacc.c  */
-#line 3004 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 3012 "src/parse-gram.c"
     break;
 
   case 100:
-/* Line 1742 of yacc.c  */
-#line 641 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 642 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1742 of yacc.c  */
-#line 3012 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 3020 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1742 of yacc.c  */
-#line 652 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 653 "src/parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -3022,52 +3030,52 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1742 of yacc.c  */
-#line 3027 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 3035 "src/parse-gram.c"
     break;
 
   case 103:
-/* Line 1742 of yacc.c  */
-#line 672 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 673 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 3035 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 3043 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1742 of yacc.c  */
-#line 674 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 675 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1742 of yacc.c  */
-#line 3047 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 3055 "src/parse-gram.c"
     break;
 
   case 105:
-/* Line 1742 of yacc.c  */
-#line 682 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 683 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1742 of yacc.c  */
-#line 3055 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 3063 "src/parse-gram.c"
     break;
 
   case 108:
-/* Line 1742 of yacc.c  */
-#line 694 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 695 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1742 of yacc.c  */
-#line 3066 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 3074 "src/parse-gram.c"
     break;
 
   case 110:
-/* Line 1742 of yacc.c  */
-#line 703 "src/parse-gram.y"
+/* Line 1744 of yacc.c  */
+#line 704 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -3076,13 +3084,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1742 of yacc.c  */
-#line 3081 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 3089 "src/parse-gram.c"
     break;
 
 
-/* Line 1742 of yacc.c  */
-#line 3086 "src/parse-gram.c"
+/* Line 1744 of yacc.c  */
+#line 3094 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3329,8 +3337,8 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 2002 of yacc.c  */
-#line 713 "src/parse-gram.y"
+/* Line 2004 of yacc.c  */
+#line 714 "src/parse-gram.y"
 
 
 
@@ -3396,17 +3404,7 @@ add_param (param_type type, char *decl, location loc)
     complain_at (loc, _("missing identifier in parameter declaration"));
   else
     {
-      char *name;
-      size_t name_len;
-
-      for (name_len = 1;
-           memchr (alphanum, name_start[name_len], sizeof alphanum);
-           name_len++)
-        continue;
-
-      name = xmalloc (name_len + 1);
-      memcpy (name, name_start, name_len);
-      name[name_len] = '\0';
+      char *name = xmemdup0 (name_start, strspn (name_start, alphanum));
       if (type & param_lex)
         muscle_pair_list_grow ("lex_param", decl, name);
       if (type & param_parse)
