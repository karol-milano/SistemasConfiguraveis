@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.7.1164-a174b-dirty.  */
+/* A Bison parser, made by GNU Bison 2.7.1.1188-e7178.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.7.1164-a174b-dirty"
+#define YYBISON_VERSION "2.7.1.1188-e7178"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -58,6 +58,13 @@
 /* Pull parsers.  */
 #define YYPULL 1
 
+/* "%code top" blocks.  */
+#line 27 "src/parse-gram.y" /* yacc.c:333  */
+
+  /* On column 0 to please syntax-check.  */
+#include <config.h>
+
+#line 68 "src/parse-gram.c" /* yacc.c:333  */
 /* Substitute the type names.  */
 #define YYSTYPE         GRAM_STYPE
 #define YYLTYPE         GRAM_LTYPE
@@ -71,7 +78,7 @@
 
 /* Copy the first part of user declarations.  */
 
-#line 75 "src/parse-gram.c" /* yacc.c:356  */
+#line 82 "src/parse-gram.c" /* yacc.c:356  */
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -113,7 +120,7 @@ extern int gram_debug;
 
   #include "symlist.h"
   #include "symtab.h"
-#line 216 "src/parse-gram.y" /* yacc.c:372  */
+#line 221 "src/parse-gram.y" /* yacc.c:372  */
 
   typedef enum
   {
@@ -122,10 +129,10 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 640 "src/parse-gram.y" /* yacc.c:372  */
+#line 645 "src/parse-gram.y" /* yacc.c:372  */
 #include "muscle-tab.h"
 
-#line 129 "src/parse-gram.c" /* yacc.c:372  */
+#line 136 "src/parse-gram.c" /* yacc.c:372  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -196,27 +203,27 @@ extern int gram_debug;
 typedef union GRAM_STYPE GRAM_STYPE;
 union GRAM_STYPE
 {
-#line 177 "src/parse-gram.y" /* yacc.c:372  */
+#line 182 "src/parse-gram.y" /* yacc.c:372  */
 unsigned char character;
-#line 181 "src/parse-gram.y" /* yacc.c:372  */
-char *code;
 #line 186 "src/parse-gram.y" /* yacc.c:372  */
+char *code;
+#line 191 "src/parse-gram.y" /* yacc.c:372  */
 uniqstr uniqstr;
-#line 194 "src/parse-gram.y" /* yacc.c:372  */
+#line 199 "src/parse-gram.y" /* yacc.c:372  */
 int integer;
-#line 198 "src/parse-gram.y" /* yacc.c:372  */
-symbol *symbol;
 #line 203 "src/parse-gram.y" /* yacc.c:372  */
+symbol *symbol;
+#line 208 "src/parse-gram.y" /* yacc.c:372  */
 assoc assoc;
-#line 206 "src/parse-gram.y" /* yacc.c:372  */
+#line 211 "src/parse-gram.y" /* yacc.c:372  */
 symbol_list *list;
-#line 209 "src/parse-gram.y" /* yacc.c:372  */
+#line 214 "src/parse-gram.y" /* yacc.c:372  */
 named_ref *named_ref;
-#line 236 "src/parse-gram.y" /* yacc.c:372  */
+#line 241 "src/parse-gram.y" /* yacc.c:372  */
 param_type param;
-#line 404 "src/parse-gram.y" /* yacc.c:372  */
+#line 409 "src/parse-gram.y" /* yacc.c:372  */
 code_props_type code_type;
-#line 642 "src/parse-gram.y" /* yacc.c:372  */
+#line 647 "src/parse-gram.y" /* yacc.c:372  */
 
   struct
   {
@@ -224,7 +231,7 @@ code_props_type code_type;
     muscle_kind kind;
   } value;
 
-#line 228 "src/parse-gram.c" /* yacc.c:372  */
+#line 235 "src/parse-gram.c" /* yacc.c:372  */
 };
 # define GRAM_STYPE_IS_TRIVIAL 1
 # define GRAM_STYPE_IS_DECLARED 1
@@ -252,11 +259,10 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-#line 256 "src/parse-gram.c" /* yacc.c:375  */
+#line 263 "src/parse-gram.c" /* yacc.c:375  */
 /* Unqualified %code blocks.  */
-#line 27 "src/parse-gram.y" /* yacc.c:376  */
+#line 33 "src/parse-gram.y" /* yacc.c:376  */
 
-  #include <config.h>
   #include "system.h"
 
   #include "c-ctype.h"
@@ -318,7 +324,7 @@ int gram_parse (void);
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 226 "src/parse-gram.y" /* yacc.c:376  */
+#line 231 "src/parse-gram.y" /* yacc.c:376  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -329,7 +335,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 333 "src/parse-gram.c" /* yacc.c:376  */
+#line 339 "src/parse-gram.c" /* yacc.c:376  */
 
 #ifdef short
 # undef short
@@ -573,18 +579,18 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   259,   259,   268,   269,   273,   274,   280,   284,   289,
-     290,   295,   301,   302,   303,   304,   309,   314,   315,   316,
-     317,   318,   319,   319,   320,   321,   345,   346,   347,   348,
-     352,   353,   362,   363,   364,   368,   380,   384,   388,   396,
-     407,   408,   418,   419,   423,   435,   435,   440,   440,   445,
-     456,   471,   472,   473,   474,   478,   479,   484,   486,   491,
-     496,   506,   508,   513,   514,   518,   519,   523,   524,   525,
-     530,   535,   540,   546,   552,   563,   564,   573,   574,   580,
-     581,   582,   589,   589,   597,   598,   599,   604,   607,   609,
-     611,   613,   615,   617,   619,   624,   625,   635,   636,   661,
-     662,   663,   664,   676,   678,   687,   692,   693,   698,   706,
-     707
+       0,   264,   264,   273,   274,   278,   279,   285,   289,   294,
+     295,   300,   306,   307,   308,   309,   314,   319,   320,   321,
+     322,   323,   324,   324,   325,   326,   350,   351,   352,   353,
+     357,   358,   367,   368,   369,   373,   385,   389,   393,   401,
+     412,   413,   423,   424,   428,   440,   440,   445,   445,   450,
+     461,   476,   477,   478,   479,   483,   484,   489,   491,   496,
+     501,   511,   513,   518,   519,   523,   524,   528,   529,   530,
+     535,   540,   545,   551,   557,   568,   569,   578,   579,   585,
+     586,   587,   594,   594,   602,   603,   604,   609,   612,   614,
+     616,   618,   620,   622,   624,   629,   630,   640,   641,   666,
+     667,   668,   669,   681,   683,   692,   697,   698,   703,   711,
+     712
 };
 #endif
 
@@ -956,79 +962,79 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
           case 3: /* "string"  */
-#line 183 "src/parse-gram.y" /* yacc.c:701  */
+#line 188 "src/parse-gram.y" /* yacc.c:701  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).code)), yyo); }
-#line 962 "src/parse-gram.c" /* yacc.c:701  */
+#line 968 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 23: /* "%<flag>"  */
-#line 191 "src/parse-gram.y" /* yacc.c:701  */
+#line 196 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 968 "src/parse-gram.c" /* yacc.c:701  */
+#line 974 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 39: /* "{...}"  */
-#line 184 "src/parse-gram.y" /* yacc.c:701  */
+#line 189 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 974 "src/parse-gram.c" /* yacc.c:701  */
+#line 980 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 40: /* "%?{...}"  */
-#line 184 "src/parse-gram.y" /* yacc.c:701  */
+#line 189 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 980 "src/parse-gram.c" /* yacc.c:701  */
+#line 986 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 41: /* "[identifier]"  */
-#line 189 "src/parse-gram.y" /* yacc.c:701  */
+#line 194 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 986 "src/parse-gram.c" /* yacc.c:701  */
+#line 992 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 42: /* "char"  */
-#line 179 "src/parse-gram.y" /* yacc.c:701  */
+#line 184 "src/parse-gram.y" /* yacc.c:701  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 992 "src/parse-gram.c" /* yacc.c:701  */
+#line 998 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 43: /* "epilogue"  */
-#line 184 "src/parse-gram.y" /* yacc.c:701  */
+#line 189 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 998 "src/parse-gram.c" /* yacc.c:701  */
+#line 1004 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 45: /* "identifier"  */
-#line 188 "src/parse-gram.y" /* yacc.c:701  */
+#line 193 "src/parse-gram.y" /* yacc.c:701  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1004 "src/parse-gram.c" /* yacc.c:701  */
+#line 1010 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 46: /* "identifier:"  */
-#line 190 "src/parse-gram.y" /* yacc.c:701  */
+#line 195 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1010 "src/parse-gram.c" /* yacc.c:701  */
+#line 1016 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 49: /* "%{...%}"  */
-#line 184 "src/parse-gram.y" /* yacc.c:701  */
+#line 189 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1016 "src/parse-gram.c" /* yacc.c:701  */
+#line 1022 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 51: /* "<tag>"  */
-#line 192 "src/parse-gram.y" /* yacc.c:701  */
+#line 197 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1022 "src/parse-gram.c" /* yacc.c:701  */
+#line 1028 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 54: /* "integer"  */
-#line 196 "src/parse-gram.y" /* yacc.c:701  */
+#line 201 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1028 "src/parse-gram.c" /* yacc.c:701  */
+#line 1034 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 55: /* "%param"  */
-#line 239 "src/parse-gram.y" /* yacc.c:701  */
+#line 244 "src/parse-gram.y" /* yacc.c:701  */
       {
   switch (((*yyvaluep).param))
     {
@@ -1041,35 +1047,35 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-#line 1045 "src/parse-gram.c" /* yacc.c:701  */
+#line 1051 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 65: /* code_props_type  */
-#line 405 "src/parse-gram.y" /* yacc.c:701  */
+#line 410 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1051 "src/parse-gram.c" /* yacc.c:701  */
+#line 1057 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 74: /* symbol.prec  */
-#line 200 "src/parse-gram.y" /* yacc.c:701  */
+#line 205 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1057 "src/parse-gram.c" /* yacc.c:701  */
+#line 1063 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 78: /* tag  */
-#line 192 "src/parse-gram.y" /* yacc.c:701  */
+#line 197 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1063 "src/parse-gram.c" /* yacc.c:701  */
+#line 1069 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 88: /* variable  */
-#line 188 "src/parse-gram.y" /* yacc.c:701  */
+#line 193 "src/parse-gram.y" /* yacc.c:701  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1069 "src/parse-gram.c" /* yacc.c:701  */
+#line 1075 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 89: /* value  */
-#line 651 "src/parse-gram.y" /* yacc.c:701  */
+#line 656 "src/parse-gram.y" /* yacc.c:701  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1078,31 +1084,31 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1082 "src/parse-gram.c" /* yacc.c:701  */
+#line 1088 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 90: /* id  */
-#line 200 "src/parse-gram.y" /* yacc.c:701  */
+#line 205 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1088 "src/parse-gram.c" /* yacc.c:701  */
+#line 1094 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 91: /* id_colon  */
-#line 201 "src/parse-gram.y" /* yacc.c:701  */
+#line 206 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1094 "src/parse-gram.c" /* yacc.c:701  */
+#line 1100 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 92: /* symbol  */
-#line 200 "src/parse-gram.y" /* yacc.c:701  */
+#line 205 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1100 "src/parse-gram.c" /* yacc.c:701  */
+#line 1106 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 93: /* string_as_id  */
-#line 200 "src/parse-gram.y" /* yacc.c:701  */
+#line 205 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1106 "src/parse-gram.c" /* yacc.c:701  */
+#line 1112 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
 
@@ -1814,7 +1820,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 103 "src/parse-gram.y" /* yacc.c:1446  */
+#line 108 "src/parse-gram.y" /* yacc.c:1446  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1822,7 +1828,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1826 "src/parse-gram.c" /* yacc.c:1446  */
+#line 1832 "src/parse-gram.c" /* yacc.c:1446  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2016,143 +2022,143 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-#line 275 "src/parse-gram.y" /* yacc.c:1663  */
+#line 280 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2026 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2032 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 7:
-#line 281 "src/parse-gram.y" /* yacc.c:1663  */
+#line 286 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2034 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2040 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 8:
-#line 285 "src/parse-gram.y" /* yacc.c:1663  */
+#line 290 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2043 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2049 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 9:
-#line 289 "src/parse-gram.y" /* yacc.c:1663  */
+#line 294 "src/parse-gram.y" /* yacc.c:1663  */
     { defines_flag = true; }
-#line 2049 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2055 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 10:
-#line 291 "src/parse-gram.y" /* yacc.c:1663  */
+#line 296 "src/parse-gram.y" /* yacc.c:1663  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].code));
     }
-#line 2058 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2064 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 11:
-#line 296 "src/parse-gram.y" /* yacc.c:1663  */
+#line 301 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), muscle_keyword,
                                     "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2068 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2074 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 12:
-#line 301 "src/parse-gram.y" /* yacc.c:1663  */
+#line 306 "src/parse-gram.y" /* yacc.c:1663  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2074 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2080 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 13:
-#line 302 "src/parse-gram.y" /* yacc.c:1663  */
+#line 307 "src/parse-gram.y" /* yacc.c:1663  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2080 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2086 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 14:
-#line 303 "src/parse-gram.y" /* yacc.c:1663  */
+#line 308 "src/parse-gram.y" /* yacc.c:1663  */
     { spec_file_prefix = (yyvsp[0].code); }
-#line 2086 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2092 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 15:
-#line 305 "src/parse-gram.y" /* yacc.c:1663  */
+#line 310 "src/parse-gram.y" /* yacc.c:1663  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2095 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2101 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 16:
-#line 310 "src/parse-gram.y" /* yacc.c:1663  */
+#line 315 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].code), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2104 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2110 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 17:
-#line 314 "src/parse-gram.y" /* yacc.c:1663  */
+#line 319 "src/parse-gram.y" /* yacc.c:1663  */
     { language_argmatch ((yyvsp[0].code), grammar_prio, (yylsp[-1])); }
-#line 2110 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2116 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 18:
-#line 315 "src/parse-gram.y" /* yacc.c:1663  */
+#line 320 "src/parse-gram.y" /* yacc.c:1663  */
     { spec_name_prefix = (yyvsp[0].code); }
-#line 2116 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2122 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 19:
-#line 316 "src/parse-gram.y" /* yacc.c:1663  */
+#line 321 "src/parse-gram.y" /* yacc.c:1663  */
     { no_lines_flag = true; }
-#line 2122 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2128 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 20:
-#line 317 "src/parse-gram.y" /* yacc.c:1663  */
+#line 322 "src/parse-gram.y" /* yacc.c:1663  */
     { nondeterministic_parser = true; }
-#line 2128 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2134 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 21:
-#line 318 "src/parse-gram.y" /* yacc.c:1663  */
+#line 323 "src/parse-gram.y" /* yacc.c:1663  */
     { spec_outfile = (yyvsp[0].code); }
-#line 2134 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2140 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 22:
-#line 319 "src/parse-gram.y" /* yacc.c:1663  */
+#line 324 "src/parse-gram.y" /* yacc.c:1663  */
     { current_param = (yyvsp[0].param); }
-#line 2140 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2146 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 23:
-#line 319 "src/parse-gram.y" /* yacc.c:1663  */
+#line 324 "src/parse-gram.y" /* yacc.c:1663  */
     { current_param = param_none; }
-#line 2146 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2152 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 24:
-#line 320 "src/parse-gram.y" /* yacc.c:1663  */
+#line 325 "src/parse-gram.y" /* yacc.c:1663  */
     { version_check (&(yylsp[0]), (yyvsp[0].code)); }
-#line 2152 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2158 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 25:
-#line 322 "src/parse-gram.y" /* yacc.c:1663  */
+#line 327 "src/parse-gram.y" /* yacc.c:1663  */
     {
       char const *skeleton_user = (yyvsp[0].code);
       if (strchr (skeleton_user, '/'))
@@ -2176,49 +2182,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2180 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2186 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 26:
-#line 345 "src/parse-gram.y" /* yacc.c:1663  */
+#line 350 "src/parse-gram.y" /* yacc.c:1663  */
     { token_table_flag = true; }
-#line 2186 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2192 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 27:
-#line 346 "src/parse-gram.y" /* yacc.c:1663  */
+#line 351 "src/parse-gram.y" /* yacc.c:1663  */
     { report_flag |= report_states; }
-#line 2192 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2198 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 28:
-#line 347 "src/parse-gram.y" /* yacc.c:1663  */
+#line 352 "src/parse-gram.y" /* yacc.c:1663  */
     { yacc_flag = true; }
-#line 2198 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2204 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 30:
-#line 352 "src/parse-gram.y" /* yacc.c:1663  */
+#line 357 "src/parse-gram.y" /* yacc.c:1663  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2204 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2210 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 31:
-#line 353 "src/parse-gram.y" /* yacc.c:1663  */
+#line 358 "src/parse-gram.y" /* yacc.c:1663  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2210 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2216 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 34:
-#line 365 "src/parse-gram.y" /* yacc.c:1663  */
+#line 370 "src/parse-gram.y" /* yacc.c:1663  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2218 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2224 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 35:
-#line 369 "src/parse-gram.y" /* yacc.c:1663  */
+#line 374 "src/parse-gram.y" /* yacc.c:1663  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2230,27 +2236,27 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2234 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2240 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 36:
-#line 381 "src/parse-gram.y" /* yacc.c:1663  */
+#line 386 "src/parse-gram.y" /* yacc.c:1663  */
     {
       default_prec = true;
     }
-#line 2242 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2248 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 37:
-#line 385 "src/parse-gram.y" /* yacc.c:1663  */
+#line 390 "src/parse-gram.y" /* yacc.c:1663  */
     {
       default_prec = false;
     }
-#line 2250 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2256 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 38:
-#line 389 "src/parse-gram.y" /* yacc.c:1663  */
+#line 394 "src/parse-gram.y" /* yacc.c:1663  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2258,84 +2264,84 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2262 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2268 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 39:
-#line 397 "src/parse-gram.y" /* yacc.c:1663  */
+#line 402 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2271 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2277 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 40:
-#line 407 "src/parse-gram.y" /* yacc.c:1663  */
+#line 412 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.code_type) = destructor; }
-#line 2277 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2283 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 41:
-#line 408 "src/parse-gram.y" /* yacc.c:1663  */
+#line 413 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.code_type) = printer; }
-#line 2283 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2289 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 42:
-#line 418 "src/parse-gram.y" /* yacc.c:1663  */
+#line 423 "src/parse-gram.y" /* yacc.c:1663  */
     {}
-#line 2289 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2295 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 43:
-#line 419 "src/parse-gram.y" /* yacc.c:1663  */
+#line 424 "src/parse-gram.y" /* yacc.c:1663  */
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2295 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2301 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 44:
-#line 424 "src/parse-gram.y" /* yacc.c:1663  */
+#line 429 "src/parse-gram.y" /* yacc.c:1663  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2305 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2311 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 45:
-#line 435 "src/parse-gram.y" /* yacc.c:1663  */
+#line 440 "src/parse-gram.y" /* yacc.c:1663  */
     { current_class = nterm_sym; }
-#line 2311 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2317 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 46:
-#line 436 "src/parse-gram.y" /* yacc.c:1663  */
+#line 441 "src/parse-gram.y" /* yacc.c:1663  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2320 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2326 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 47:
-#line 440 "src/parse-gram.y" /* yacc.c:1663  */
+#line 445 "src/parse-gram.y" /* yacc.c:1663  */
     { current_class = token_sym; }
-#line 2326 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2332 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 48:
-#line 441 "src/parse-gram.y" /* yacc.c:1663  */
+#line 446 "src/parse-gram.y" /* yacc.c:1663  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2335 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2341 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 49:
-#line 446 "src/parse-gram.y" /* yacc.c:1663  */
+#line 451 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_list *list;
       tag_seen = true;
@@ -2343,11 +2349,11 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2347 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2353 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 50:
-#line 457 "src/parse-gram.y" /* yacc.c:1663  */
+#line 462 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_list *list;
       ++current_prec;
@@ -2359,341 +2365,341 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2363 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2369 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 51:
-#line 471 "src/parse-gram.y" /* yacc.c:1663  */
+#line 476 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = left_assoc; }
-#line 2369 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2375 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 52:
-#line 472 "src/parse-gram.y" /* yacc.c:1663  */
+#line 477 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = right_assoc; }
-#line 2375 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2381 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 53:
-#line 473 "src/parse-gram.y" /* yacc.c:1663  */
+#line 478 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = non_assoc; }
-#line 2381 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2387 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 54:
-#line 474 "src/parse-gram.y" /* yacc.c:1663  */
+#line 479 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2387 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2393 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 55:
-#line 478 "src/parse-gram.y" /* yacc.c:1663  */
+#line 483 "src/parse-gram.y" /* yacc.c:1663  */
     { current_type = NULL; }
-#line 2393 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2399 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 56:
-#line 479 "src/parse-gram.y" /* yacc.c:1663  */
+#line 484 "src/parse-gram.y" /* yacc.c:1663  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2399 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2405 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 57:
-#line 485 "src/parse-gram.y" /* yacc.c:1663  */
+#line 490 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2405 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2411 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 58:
-#line 487 "src/parse-gram.y" /* yacc.c:1663  */
+#line 492 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2411 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2417 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 59:
-#line 492 "src/parse-gram.y" /* yacc.c:1663  */
+#line 497 "src/parse-gram.y" /* yacc.c:1663  */
     {
       (yyval.symbol) = (yyvsp[0].symbol);
       symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2420 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2426 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 60:
-#line 497 "src/parse-gram.y" /* yacc.c:1663  */
+#line 502 "src/parse-gram.y" /* yacc.c:1663  */
     {
       (yyval.symbol) = (yyvsp[-1].symbol);
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
     }
-#line 2430 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2436 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 61:
-#line 507 "src/parse-gram.y" /* yacc.c:1663  */
+#line 512 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2436 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2442 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 62:
-#line 509 "src/parse-gram.y" /* yacc.c:1663  */
+#line 514 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2442 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2448 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 63:
-#line 513 "src/parse-gram.y" /* yacc.c:1663  */
+#line 518 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2448 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2454 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 64:
-#line 514 "src/parse-gram.y" /* yacc.c:1663  */
+#line 519 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2454 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2460 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 65:
-#line 518 "src/parse-gram.y" /* yacc.c:1663  */
+#line 523 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2460 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2466 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 66:
-#line 519 "src/parse-gram.y" /* yacc.c:1663  */
+#line 524 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2466 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2472 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 68:
-#line 524 "src/parse-gram.y" /* yacc.c:1663  */
+#line 529 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2472 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2478 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 69:
-#line 525 "src/parse-gram.y" /* yacc.c:1663  */
+#line 530 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2478 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2484 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 70:
-#line 531 "src/parse-gram.y" /* yacc.c:1663  */
+#line 536 "src/parse-gram.y" /* yacc.c:1663  */
     {
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2487 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2493 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 71:
-#line 536 "src/parse-gram.y" /* yacc.c:1663  */
+#line 541 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2496 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2502 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 72:
-#line 541 "src/parse-gram.y" /* yacc.c:1663  */
+#line 546 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2506 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2512 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 73:
-#line 547 "src/parse-gram.y" /* yacc.c:1663  */
+#line 552 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2516 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2522 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 74:
-#line 553 "src/parse-gram.y" /* yacc.c:1663  */
+#line 558 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2527 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2533 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 81:
-#line 583 "src/parse-gram.y" /* yacc.c:1663  */
+#line 588 "src/parse-gram.y" /* yacc.c:1663  */
     {
       yyerrok;
     }
-#line 2535 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2541 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 82:
-#line 589 "src/parse-gram.y" /* yacc.c:1663  */
+#line 594 "src/parse-gram.y" /* yacc.c:1663  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2541 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2547 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 83:
-#line 590 "src/parse-gram.y" /* yacc.c:1663  */
+#line 595 "src/parse-gram.y" /* yacc.c:1663  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2550 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2556 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 84:
-#line 597 "src/parse-gram.y" /* yacc.c:1663  */
+#line 602 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2556 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2562 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 85:
-#line 598 "src/parse-gram.y" /* yacc.c:1663  */
+#line 603 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2562 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2568 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 87:
-#line 605 "src/parse-gram.y" /* yacc.c:1663  */
+#line 610 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2569 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2575 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 88:
-#line 608 "src/parse-gram.y" /* yacc.c:1663  */
+#line 613 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2575 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2581 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 89:
-#line 610 "src/parse-gram.y" /* yacc.c:1663  */
+#line 615 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-#line 2581 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2587 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 90:
-#line 612 "src/parse-gram.y" /* yacc.c:1663  */
+#line 617 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-#line 2587 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2593 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 91:
-#line 614 "src/parse-gram.y" /* yacc.c:1663  */
+#line 619 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2593 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2599 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 92:
-#line 616 "src/parse-gram.y" /* yacc.c:1663  */
+#line 621 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2599 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2605 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 93:
-#line 618 "src/parse-gram.y" /* yacc.c:1663  */
+#line 623 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2605 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2611 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 94:
-#line 620 "src/parse-gram.y" /* yacc.c:1663  */
+#line 625 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2611 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2617 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 95:
-#line 624 "src/parse-gram.y" /* yacc.c:1663  */
+#line 629 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.named_ref) = 0; }
-#line 2617 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2623 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 96:
-#line 625 "src/parse-gram.y" /* yacc.c:1663  */
+#line 630 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2623 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2629 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 98:
-#line 636 "src/parse-gram.y" /* yacc.c:1663  */
+#line 641 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].code)); }
-#line 2629 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2635 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 99:
-#line 661 "src/parse-gram.y" /* yacc.c:1663  */
+#line 666 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2635 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2641 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 100:
-#line 662 "src/parse-gram.y" /* yacc.c:1663  */
+#line 667 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].uniqstr); }
-#line 2641 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2647 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 101:
-#line 663 "src/parse-gram.y" /* yacc.c:1663  */
+#line 668 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].code); }
-#line 2647 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2653 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 102:
-#line 664 "src/parse-gram.y" /* yacc.c:1663  */
+#line 669 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].code)); }
-#line 2653 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2659 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 103:
-#line 677 "src/parse-gram.y" /* yacc.c:1663  */
+#line 682 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2659 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2665 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 104:
-#line 679 "src/parse-gram.y" /* yacc.c:1663  */
+#line 684 "src/parse-gram.y" /* yacc.c:1663  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2669 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2675 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 105:
-#line 687 "src/parse-gram.y" /* yacc.c:1663  */
+#line 692 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2675 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2681 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 108:
-#line 699 "src/parse-gram.y" /* yacc.c:1663  */
+#line 704 "src/parse-gram.y" /* yacc.c:1663  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].code)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2684 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2690 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 110:
-#line 708 "src/parse-gram.y" /* yacc.c:1663  */
+#line 713 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2693 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2699 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
 
-#line 2697 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2703 "src/parse-gram.c" /* yacc.c:1663  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2940,7 +2946,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 714 "src/parse-gram.y" /* yacc.c:1923  */
+#line 719 "src/parse-gram.y" /* yacc.c:1923  */
 
 
 /* Return the location of the left-hand side of a rule whose
