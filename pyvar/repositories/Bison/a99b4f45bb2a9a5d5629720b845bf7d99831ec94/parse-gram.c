@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.0.5.75-d835.  */
+/* A Bison parser, made by GNU Bison 3.1.220-3e56-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.0.5.75-d835"
+#define YYBISON_VERSION "3.1.220-3e56-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -81,10 +81,14 @@
 #line 82 "src/parse-gram.c" /* yacc.c:339  */
 
 # ifndef YY_NULLPTR
-#  if defined __cplusplus && 201103L <= __cplusplus
-#   define YY_NULLPTR nullptr
+#  if defined __cplusplus
+#   if 201103L <= __cplusplus
+#    define YY_NULLPTR nullptr
+#   else
+#    define YY_NULLPTR 0
+#   endif
 #  else
-#   define YY_NULLPTR 0
+#   define YY_NULLPTR ((void*)0)
 #  endif
 # endif
 
@@ -120,7 +124,7 @@ extern int gram_debug;
 
   #include "symlist.h"
   #include "symtab.h"
-#line 221 "src/parse-gram.y" /* yacc.c:355  */
+#line 222 "src/parse-gram.y" /* yacc.c:355  */
 
   typedef enum
   {
@@ -129,10 +133,10 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 644 "src/parse-gram.y" /* yacc.c:355  */
+#line 645 "src/parse-gram.y" /* yacc.c:355  */
 #include "muscle-tab.h"
 
-#line 136 "src/parse-gram.c" /* yacc.c:355  */
+#line 140 "src/parse-gram.c" /* yacc.c:355  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -203,27 +207,27 @@ extern int gram_debug;
 
 union GRAM_STYPE
 {
-#line 182 "src/parse-gram.y" /* yacc.c:355  */
+#line 183 "src/parse-gram.y" /* yacc.c:355  */
 unsigned char character;
-#line 186 "src/parse-gram.y" /* yacc.c:355  */
+#line 187 "src/parse-gram.y" /* yacc.c:355  */
 char *code;
-#line 191 "src/parse-gram.y" /* yacc.c:355  */
+#line 192 "src/parse-gram.y" /* yacc.c:355  */
 uniqstr uniqstr;
-#line 199 "src/parse-gram.y" /* yacc.c:355  */
+#line 200 "src/parse-gram.y" /* yacc.c:355  */
 int integer;
-#line 203 "src/parse-gram.y" /* yacc.c:355  */
+#line 204 "src/parse-gram.y" /* yacc.c:355  */
 symbol *symbol;
-#line 208 "src/parse-gram.y" /* yacc.c:355  */
+#line 209 "src/parse-gram.y" /* yacc.c:355  */
 assoc assoc;
-#line 211 "src/parse-gram.y" /* yacc.c:355  */
+#line 212 "src/parse-gram.y" /* yacc.c:355  */
 symbol_list *list;
-#line 214 "src/parse-gram.y" /* yacc.c:355  */
+#line 215 "src/parse-gram.y" /* yacc.c:355  */
 named_ref *named_ref;
-#line 241 "src/parse-gram.y" /* yacc.c:355  */
+#line 242 "src/parse-gram.y" /* yacc.c:355  */
 param_type param;
-#line 408 "src/parse-gram.y" /* yacc.c:355  */
+#line 409 "src/parse-gram.y" /* yacc.c:355  */
 code_props_type code_type;
-#line 646 "src/parse-gram.y" /* yacc.c:355  */
+#line 647 "src/parse-gram.y" /* yacc.c:355  */
 
   struct
   {
@@ -231,7 +235,7 @@ code_props_type code_type;
     muscle_kind kind;
   } value;
 
-#line 235 "src/parse-gram.c" /* yacc.c:355  */
+#line 239 "src/parse-gram.c" /* yacc.c:355  */
 };
 
 typedef union GRAM_STYPE GRAM_STYPE;
@@ -261,11 +265,12 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-#line 265 "src/parse-gram.c" /* yacc.c:358  */
+#line 269 "src/parse-gram.c" /* yacc.c:358  */
 /* Unqualified %code blocks.  */
 #line 33 "src/parse-gram.y" /* yacc.c:359  */
 
   #include "system.h"
+  #include <errno.h>
 
   #include "c-ctype.h"
   #include "complain.h"
@@ -326,7 +331,7 @@ int gram_parse (void);
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 231 "src/parse-gram.y" /* yacc.c:359  */
+#line 232 "src/parse-gram.y" /* yacc.c:359  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -337,7 +342,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 341 "src/parse-gram.c" /* yacc.c:359  */
+#line 346 "src/parse-gram.c" /* yacc.c:359  */
 
 #ifdef short
 # undef short
@@ -428,7 +433,7 @@ typedef short yytype_int16;
 # define YYUSE(E) /* empty */
 #endif
 
-#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
+#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
 /* Suppress an incorrect diagnostic about yylval being uninitialized.  */
 # define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
     _Pragma ("GCC diagnostic push") \
@@ -619,18 +624,18 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   264,   264,   273,   274,   278,   279,   285,   289,   294,
-     295,   300,   306,   307,   308,   309,   314,   319,   320,   321,
-     322,   323,   324,   324,   325,   326,   350,   351,   352,   353,
-     357,   358,   367,   368,   369,   373,   384,   388,   392,   400,
-     411,   412,   422,   423,   429,   441,   441,   446,   446,   451,
-     461,   475,   476,   477,   478,   482,   483,   488,   490,   495,
-     500,   510,   512,   517,   518,   522,   523,   527,   528,   529,
-     534,   539,   544,   550,   556,   567,   568,   577,   578,   584,
-     585,   586,   593,   593,   601,   602,   603,   608,   611,   613,
-     615,   617,   619,   621,   623,   628,   629,   639,   640,   665,
-     666,   667,   668,   680,   682,   691,   696,   697,   702,   710,
-     711
+       0,   265,   265,   274,   275,   279,   280,   286,   290,   295,
+     296,   301,   307,   308,   309,   310,   315,   320,   321,   322,
+     323,   324,   325,   325,   326,   327,   351,   352,   353,   354,
+     358,   359,   368,   369,   370,   374,   385,   389,   393,   401,
+     412,   413,   423,   424,   430,   442,   442,   447,   447,   452,
+     462,   476,   477,   478,   479,   483,   484,   489,   491,   496,
+     501,   511,   513,   518,   519,   523,   524,   528,   529,   530,
+     535,   540,   545,   551,   557,   568,   569,   578,   579,   585,
+     586,   587,   594,   594,   602,   603,   604,   609,   612,   614,
+     616,   618,   620,   622,   624,   629,   630,   640,   641,   666,
+     667,   668,   669,   681,   683,   692,   697,   698,   703,   711,
+     712
 };
 #endif
 
@@ -1002,79 +1007,79 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
           case 3: /* "string"  */
-#line 188 "src/parse-gram.y" /* yacc.c:684  */
+#line 189 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).code)), yyo); }
-#line 1008 "src/parse-gram.c" /* yacc.c:684  */
+#line 1013 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 23: /* "%<flag>"  */
-#line 196 "src/parse-gram.y" /* yacc.c:684  */
+#line 197 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 1014 "src/parse-gram.c" /* yacc.c:684  */
+#line 1019 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 39: /* "{...}"  */
-#line 189 "src/parse-gram.y" /* yacc.c:684  */
+#line 190 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1020 "src/parse-gram.c" /* yacc.c:684  */
+#line 1025 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 40: /* "%?{...}"  */
-#line 189 "src/parse-gram.y" /* yacc.c:684  */
+#line 190 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1026 "src/parse-gram.c" /* yacc.c:684  */
+#line 1031 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 41: /* "[identifier]"  */
-#line 194 "src/parse-gram.y" /* yacc.c:684  */
+#line 195 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 1032 "src/parse-gram.c" /* yacc.c:684  */
+#line 1037 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 42: /* "char"  */
-#line 184 "src/parse-gram.y" /* yacc.c:684  */
+#line 185 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 1038 "src/parse-gram.c" /* yacc.c:684  */
+#line 1043 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 43: /* "epilogue"  */
-#line 189 "src/parse-gram.y" /* yacc.c:684  */
+#line 190 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1044 "src/parse-gram.c" /* yacc.c:684  */
+#line 1049 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 45: /* "identifier"  */
-#line 193 "src/parse-gram.y" /* yacc.c:684  */
+#line 194 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1050 "src/parse-gram.c" /* yacc.c:684  */
+#line 1055 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 46: /* "identifier:"  */
-#line 195 "src/parse-gram.y" /* yacc.c:684  */
+#line 196 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1056 "src/parse-gram.c" /* yacc.c:684  */
+#line 1061 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 49: /* "%{...%}"  */
-#line 189 "src/parse-gram.y" /* yacc.c:684  */
+#line 190 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1062 "src/parse-gram.c" /* yacc.c:684  */
+#line 1067 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 51: /* "<tag>"  */
-#line 197 "src/parse-gram.y" /* yacc.c:684  */
+#line 198 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1068 "src/parse-gram.c" /* yacc.c:684  */
+#line 1073 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 54: /* "integer"  */
-#line 201 "src/parse-gram.y" /* yacc.c:684  */
+#line 202 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1074 "src/parse-gram.c" /* yacc.c:684  */
+#line 1079 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 55: /* "%param"  */
-#line 244 "src/parse-gram.y" /* yacc.c:684  */
+#line 245 "src/parse-gram.y" /* yacc.c:684  */
       {
   switch (((*yyvaluep).param))
     {
@@ -1087,35 +1092,35 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-#line 1091 "src/parse-gram.c" /* yacc.c:684  */
+#line 1096 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 65: /* code_props_type  */
-#line 409 "src/parse-gram.y" /* yacc.c:684  */
+#line 410 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1097 "src/parse-gram.c" /* yacc.c:684  */
+#line 1102 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 74: /* symbol.prec  */
-#line 205 "src/parse-gram.y" /* yacc.c:684  */
+#line 206 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1103 "src/parse-gram.c" /* yacc.c:684  */
+#line 1108 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 78: /* tag  */
-#line 197 "src/parse-gram.y" /* yacc.c:684  */
+#line 198 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1109 "src/parse-gram.c" /* yacc.c:684  */
+#line 1114 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 88: /* variable  */
-#line 193 "src/parse-gram.y" /* yacc.c:684  */
+#line 194 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1115 "src/parse-gram.c" /* yacc.c:684  */
+#line 1120 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 89: /* value  */
-#line 655 "src/parse-gram.y" /* yacc.c:684  */
+#line 656 "src/parse-gram.y" /* yacc.c:684  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1124,31 +1129,31 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1128 "src/parse-gram.c" /* yacc.c:684  */
+#line 1133 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 90: /* id  */
-#line 205 "src/parse-gram.y" /* yacc.c:684  */
+#line 206 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1134 "src/parse-gram.c" /* yacc.c:684  */
+#line 1139 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 91: /* id_colon  */
-#line 206 "src/parse-gram.y" /* yacc.c:684  */
+#line 207 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1140 "src/parse-gram.c" /* yacc.c:684  */
+#line 1145 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 92: /* symbol  */
-#line 205 "src/parse-gram.y" /* yacc.c:684  */
+#line 206 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1146 "src/parse-gram.c" /* yacc.c:684  */
+#line 1151 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 93: /* string_as_id  */
-#line 205 "src/parse-gram.y" /* yacc.c:684  */
+#line 206 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1152 "src/parse-gram.c" /* yacc.c:684  */
+#line 1157 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
 
@@ -1843,7 +1848,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 108 "src/parse-gram.y" /* yacc.c:1433  */
+#line 109 "src/parse-gram.y" /* yacc.c:1433  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1851,7 +1856,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1855 "src/parse-gram.c" /* yacc.c:1433  */
+#line 1860 "src/parse-gram.c" /* yacc.c:1433  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2046,143 +2051,143 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-#line 280 "src/parse-gram.y" /* yacc.c:1651  */
+#line 281 "src/parse-gram.y" /* yacc.c:1651  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2056 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2061 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 7:
-#line 286 "src/parse-gram.y" /* yacc.c:1651  */
+#line 287 "src/parse-gram.y" /* yacc.c:1651  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2064 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2069 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 8:
-#line 290 "src/parse-gram.y" /* yacc.c:1651  */
+#line 291 "src/parse-gram.y" /* yacc.c:1651  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2073 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2078 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 9:
-#line 294 "src/parse-gram.y" /* yacc.c:1651  */
+#line 295 "src/parse-gram.y" /* yacc.c:1651  */
     { defines_flag = true; }
-#line 2079 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2084 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 10:
-#line 296 "src/parse-gram.y" /* yacc.c:1651  */
+#line 297 "src/parse-gram.y" /* yacc.c:1651  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].code));
     }
-#line 2088 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2093 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 11:
-#line 301 "src/parse-gram.y" /* yacc.c:1651  */
+#line 302 "src/parse-gram.y" /* yacc.c:1651  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), muscle_keyword,
                                     "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2098 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2103 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 12:
-#line 306 "src/parse-gram.y" /* yacc.c:1651  */
+#line 307 "src/parse-gram.y" /* yacc.c:1651  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2104 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2109 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 13:
-#line 307 "src/parse-gram.y" /* yacc.c:1651  */
+#line 308 "src/parse-gram.y" /* yacc.c:1651  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2110 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2115 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 14:
-#line 308 "src/parse-gram.y" /* yacc.c:1651  */
+#line 309 "src/parse-gram.y" /* yacc.c:1651  */
     { spec_file_prefix = (yyvsp[0].code); }
-#line 2116 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2121 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 15:
-#line 310 "src/parse-gram.y" /* yacc.c:1651  */
+#line 311 "src/parse-gram.y" /* yacc.c:1651  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2125 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2130 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 16:
-#line 315 "src/parse-gram.y" /* yacc.c:1651  */
+#line 316 "src/parse-gram.y" /* yacc.c:1651  */
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].code), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2134 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2139 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 17:
-#line 319 "src/parse-gram.y" /* yacc.c:1651  */
+#line 320 "src/parse-gram.y" /* yacc.c:1651  */
     { language_argmatch ((yyvsp[0].code), grammar_prio, (yylsp[-1])); }
-#line 2140 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2145 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 18:
-#line 320 "src/parse-gram.y" /* yacc.c:1651  */
+#line 321 "src/parse-gram.y" /* yacc.c:1651  */
     { spec_name_prefix = (yyvsp[0].code); }
-#line 2146 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2151 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 19:
-#line 321 "src/parse-gram.y" /* yacc.c:1651  */
+#line 322 "src/parse-gram.y" /* yacc.c:1651  */
     { no_lines_flag = true; }
-#line 2152 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2157 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 20:
-#line 322 "src/parse-gram.y" /* yacc.c:1651  */
+#line 323 "src/parse-gram.y" /* yacc.c:1651  */
     { nondeterministic_parser = true; }
-#line 2158 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2163 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 21:
-#line 323 "src/parse-gram.y" /* yacc.c:1651  */
+#line 324 "src/parse-gram.y" /* yacc.c:1651  */
     { spec_outfile = (yyvsp[0].code); }
-#line 2164 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2169 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 22:
-#line 324 "src/parse-gram.y" /* yacc.c:1651  */
+#line 325 "src/parse-gram.y" /* yacc.c:1651  */
     { current_param = (yyvsp[0].param); }
-#line 2170 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2175 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 23:
-#line 324 "src/parse-gram.y" /* yacc.c:1651  */
+#line 325 "src/parse-gram.y" /* yacc.c:1651  */
     { current_param = param_none; }
-#line 2176 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2181 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 24:
-#line 325 "src/parse-gram.y" /* yacc.c:1651  */
+#line 326 "src/parse-gram.y" /* yacc.c:1651  */
     { version_check (&(yylsp[0]), (yyvsp[0].code)); }
-#line 2182 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2187 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 25:
-#line 327 "src/parse-gram.y" /* yacc.c:1651  */
+#line 328 "src/parse-gram.y" /* yacc.c:1651  */
     {
       char const *skeleton_user = (yyvsp[0].code);
       if (strchr (skeleton_user, '/'))
@@ -2206,49 +2211,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2210 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2215 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 26:
-#line 350 "src/parse-gram.y" /* yacc.c:1651  */
+#line 351 "src/parse-gram.y" /* yacc.c:1651  */
     { token_table_flag = true; }
-#line 2216 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2221 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 27:
-#line 351 "src/parse-gram.y" /* yacc.c:1651  */
+#line 352 "src/parse-gram.y" /* yacc.c:1651  */
     { report_flag |= report_states; }
-#line 2222 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2227 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 28:
-#line 352 "src/parse-gram.y" /* yacc.c:1651  */
+#line 353 "src/parse-gram.y" /* yacc.c:1651  */
     { yacc_flag = true; }
-#line 2228 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2233 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 30:
-#line 357 "src/parse-gram.y" /* yacc.c:1651  */
+#line 358 "src/parse-gram.y" /* yacc.c:1651  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2234 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2239 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 31:
-#line 358 "src/parse-gram.y" /* yacc.c:1651  */
+#line 359 "src/parse-gram.y" /* yacc.c:1651  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2240 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2245 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 34:
-#line 370 "src/parse-gram.y" /* yacc.c:1651  */
+#line 371 "src/parse-gram.y" /* yacc.c:1651  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2248 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2253 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 35:
-#line 374 "src/parse-gram.y" /* yacc.c:1651  */
+#line 375 "src/parse-gram.y" /* yacc.c:1651  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2259,27 +2264,27 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2263 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2268 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 36:
-#line 385 "src/parse-gram.y" /* yacc.c:1651  */
+#line 386 "src/parse-gram.y" /* yacc.c:1651  */
     {
       default_prec = true;
     }
-#line 2271 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2276 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 37:
-#line 389 "src/parse-gram.y" /* yacc.c:1651  */
+#line 390 "src/parse-gram.y" /* yacc.c:1651  */
     {
       default_prec = false;
     }
-#line 2279 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2284 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 38:
-#line 393 "src/parse-gram.y" /* yacc.c:1651  */
+#line 394 "src/parse-gram.y" /* yacc.c:1651  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2287,97 +2292,97 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2291 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2296 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 39:
-#line 401 "src/parse-gram.y" /* yacc.c:1651  */
+#line 402 "src/parse-gram.y" /* yacc.c:1651  */
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2300 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2305 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 40:
-#line 411 "src/parse-gram.y" /* yacc.c:1651  */
+#line 412 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.code_type) = destructor; }
-#line 2306 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2311 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 41:
-#line 412 "src/parse-gram.y" /* yacc.c:1651  */
+#line 413 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.code_type) = printer; }
-#line 2312 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2317 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 42:
-#line 422 "src/parse-gram.y" /* yacc.c:1651  */
+#line 423 "src/parse-gram.y" /* yacc.c:1651  */
     {}
-#line 2318 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2323 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 43:
-#line 423 "src/parse-gram.y" /* yacc.c:1651  */
+#line 424 "src/parse-gram.y" /* yacc.c:1651  */
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].uniqstr),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2326 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2331 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 44:
-#line 430 "src/parse-gram.y" /* yacc.c:1651  */
+#line 431 "src/parse-gram.y" /* yacc.c:1651  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2336 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2341 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 45:
-#line 441 "src/parse-gram.y" /* yacc.c:1651  */
+#line 442 "src/parse-gram.y" /* yacc.c:1651  */
     { current_class = nterm_sym; }
-#line 2342 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2347 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 46:
-#line 442 "src/parse-gram.y" /* yacc.c:1651  */
+#line 443 "src/parse-gram.y" /* yacc.c:1651  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2351 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2356 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 47:
-#line 446 "src/parse-gram.y" /* yacc.c:1651  */
+#line 447 "src/parse-gram.y" /* yacc.c:1651  */
     { current_class = token_sym; }
-#line 2357 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2362 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 48:
-#line 447 "src/parse-gram.y" /* yacc.c:1651  */
+#line 448 "src/parse-gram.y" /* yacc.c:1651  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2366 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2371 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 49:
-#line 452 "src/parse-gram.y" /* yacc.c:1651  */
+#line 453 "src/parse-gram.y" /* yacc.c:1651  */
     {
       tag_seen = true;
       for (symbol_list *list = (yyvsp[0].list); list; list = list->next)
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2377 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2382 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 50:
-#line 462 "src/parse-gram.y" /* yacc.c:1651  */
+#line 463 "src/parse-gram.y" /* yacc.c:1651  */
     {
       ++current_prec;
       for (symbol_list *list = (yyvsp[0].list); list; list = list->next)
@@ -2388,341 +2393,365 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2392 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2397 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 51:
-#line 475 "src/parse-gram.y" /* yacc.c:1651  */
+#line 476 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.assoc) = left_assoc; }
-#line 2398 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2403 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 52:
-#line 476 "src/parse-gram.y" /* yacc.c:1651  */
+#line 477 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.assoc) = right_assoc; }
-#line 2404 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2409 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 53:
-#line 477 "src/parse-gram.y" /* yacc.c:1651  */
+#line 478 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.assoc) = non_assoc; }
-#line 2410 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2415 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 54:
-#line 478 "src/parse-gram.y" /* yacc.c:1651  */
+#line 479 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2416 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2421 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 55:
-#line 482 "src/parse-gram.y" /* yacc.c:1651  */
+#line 483 "src/parse-gram.y" /* yacc.c:1651  */
     { current_type = NULL; }
-#line 2422 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2427 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 56:
-#line 483 "src/parse-gram.y" /* yacc.c:1651  */
+#line 484 "src/parse-gram.y" /* yacc.c:1651  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2428 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2433 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 57:
-#line 489 "src/parse-gram.y" /* yacc.c:1651  */
+#line 490 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2434 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2439 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 58:
-#line 491 "src/parse-gram.y" /* yacc.c:1651  */
+#line 492 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2440 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2445 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 59:
-#line 496 "src/parse-gram.y" /* yacc.c:1651  */
+#line 497 "src/parse-gram.y" /* yacc.c:1651  */
     {
       (yyval.symbol) = (yyvsp[0].symbol);
       symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2449 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2454 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 60:
-#line 501 "src/parse-gram.y" /* yacc.c:1651  */
+#line 502 "src/parse-gram.y" /* yacc.c:1651  */
     {
       (yyval.symbol) = (yyvsp[-1].symbol);
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
     }
-#line 2459 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2464 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 61:
-#line 511 "src/parse-gram.y" /* yacc.c:1651  */
+#line 512 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2465 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2470 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 62:
-#line 513 "src/parse-gram.y" /* yacc.c:1651  */
+#line 514 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2471 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2476 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 63:
-#line 517 "src/parse-gram.y" /* yacc.c:1651  */
+#line 518 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2477 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2482 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 64:
-#line 518 "src/parse-gram.y" /* yacc.c:1651  */
+#line 519 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2483 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2488 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 65:
-#line 522 "src/parse-gram.y" /* yacc.c:1651  */
+#line 523 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2489 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2494 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 66:
-#line 523 "src/parse-gram.y" /* yacc.c:1651  */
+#line 524 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2495 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2500 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
-  case 68:
+  case 67:
 #line 528 "src/parse-gram.y" /* yacc.c:1651  */
+    { (yyval.uniqstr) = (yyvsp[0].uniqstr); }
+#line 2506 "src/parse-gram.c" /* yacc.c:1651  */
+    break;
+
+  case 68:
+#line 529 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2501 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2512 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 69:
-#line 529 "src/parse-gram.y" /* yacc.c:1651  */
+#line 530 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2507 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2518 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 70:
-#line 535 "src/parse-gram.y" /* yacc.c:1651  */
+#line 536 "src/parse-gram.y" /* yacc.c:1651  */
     {
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2516 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2527 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 71:
-#line 540 "src/parse-gram.y" /* yacc.c:1651  */
+#line 541 "src/parse-gram.y" /* yacc.c:1651  */
     {
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2525 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2536 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 72:
-#line 545 "src/parse-gram.y" /* yacc.c:1651  */
+#line 546 "src/parse-gram.y" /* yacc.c:1651  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2535 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2546 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 73:
-#line 551 "src/parse-gram.y" /* yacc.c:1651  */
+#line 552 "src/parse-gram.y" /* yacc.c:1651  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2545 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2556 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 74:
-#line 557 "src/parse-gram.y" /* yacc.c:1651  */
+#line 558 "src/parse-gram.y" /* yacc.c:1651  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2556 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2567 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 81:
-#line 587 "src/parse-gram.y" /* yacc.c:1651  */
+#line 588 "src/parse-gram.y" /* yacc.c:1651  */
     {
       yyerrok;
     }
-#line 2564 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2575 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 82:
-#line 593 "src/parse-gram.y" /* yacc.c:1651  */
+#line 594 "src/parse-gram.y" /* yacc.c:1651  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2570 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2581 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 83:
-#line 594 "src/parse-gram.y" /* yacc.c:1651  */
+#line 595 "src/parse-gram.y" /* yacc.c:1651  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2579 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2590 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 84:
-#line 601 "src/parse-gram.y" /* yacc.c:1651  */
+#line 602 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2585 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2596 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 85:
-#line 602 "src/parse-gram.y" /* yacc.c:1651  */
+#line 603 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2591 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2602 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 87:
-#line 609 "src/parse-gram.y" /* yacc.c:1651  */
+#line 610 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2598 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2609 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 88:
-#line 612 "src/parse-gram.y" /* yacc.c:1651  */
+#line 613 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2604 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2615 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 89:
-#line 614 "src/parse-gram.y" /* yacc.c:1651  */
+#line 615 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), current_type); }
-#line 2610 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2621 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 90:
-#line 616 "src/parse-gram.y" /* yacc.c:1651  */
+#line 617 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_predicate_append ((yyvsp[0].code), (yylsp[0])); }
-#line 2616 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2627 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 91:
-#line 618 "src/parse-gram.y" /* yacc.c:1651  */
+#line 619 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2622 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2633 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 92:
-#line 620 "src/parse-gram.y" /* yacc.c:1651  */
+#line 621 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2628 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2639 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 93:
-#line 622 "src/parse-gram.y" /* yacc.c:1651  */
+#line 623 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2634 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2645 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 94:
-#line 624 "src/parse-gram.y" /* yacc.c:1651  */
+#line 625 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2640 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2651 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 95:
-#line 628 "src/parse-gram.y" /* yacc.c:1651  */
+#line 629 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.named_ref) = 0; }
-#line 2646 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2657 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 96:
-#line 629 "src/parse-gram.y" /* yacc.c:1651  */
+#line 630 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.named_ref) = named_ref_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2652 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2663 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
-  case 98:
+  case 97:
 #line 640 "src/parse-gram.y" /* yacc.c:1651  */
+    { (yyval.uniqstr) = (yyvsp[0].uniqstr); }
+#line 2669 "src/parse-gram.c" /* yacc.c:1651  */
+    break;
+
+  case 98:
+#line 641 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].code)); }
-#line 2658 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2675 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 99:
-#line 665 "src/parse-gram.y" /* yacc.c:1651  */
+#line 666 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2664 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2681 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 100:
-#line 666 "src/parse-gram.y" /* yacc.c:1651  */
+#line 667 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].uniqstr); }
-#line 2670 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2687 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 101:
-#line 667 "src/parse-gram.y" /* yacc.c:1651  */
+#line 668 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].code); }
-#line 2676 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2693 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 102:
-#line 668 "src/parse-gram.y" /* yacc.c:1651  */
+#line 669 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].code)); }
-#line 2682 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2699 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 103:
-#line 681 "src/parse-gram.y" /* yacc.c:1651  */
+#line 682 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2688 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2705 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 104:
-#line 683 "src/parse-gram.y" /* yacc.c:1651  */
+#line 684 "src/parse-gram.y" /* yacc.c:1651  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2698 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2715 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 105:
-#line 691 "src/parse-gram.y" /* yacc.c:1651  */
+#line 692 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2704 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2721 "src/parse-gram.c" /* yacc.c:1651  */
+    break;
+
+  case 106:
+#line 697 "src/parse-gram.y" /* yacc.c:1651  */
+    { (yyval.symbol) = (yyvsp[0].symbol); }
+#line 2727 "src/parse-gram.c" /* yacc.c:1651  */
+    break;
+
+  case 107:
+#line 698 "src/parse-gram.y" /* yacc.c:1651  */
+    { (yyval.symbol) = (yyvsp[0].symbol); }
+#line 2733 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 108:
-#line 703 "src/parse-gram.y" /* yacc.c:1651  */
+#line 704 "src/parse-gram.y" /* yacc.c:1651  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].code)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2713 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2742 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 110:
-#line 712 "src/parse-gram.y" /* yacc.c:1651  */
+#line 713 "src/parse-gram.y" /* yacc.c:1651  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2722 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2751 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
 
-#line 2726 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2755 "src/parse-gram.c" /* yacc.c:1651  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2968,7 +2997,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 718 "src/parse-gram.y" /* yacc.c:1910  */
+#line 719 "src/parse-gram.y" /* yacc.c:1910  */
 
 
 /* Return the location of the left-hand side of a rule whose
@@ -3076,10 +3105,37 @@ add_param (param_type type, char *decl, location loc)
 static void
 version_check (location const *loc, char const *version)
 {
-  if (strverscmp (version, PACKAGE_VERSION) > 0)
+  /* Changes of behavior are only on minor version changes, so "3.0.5"
+     is the same as "3.0". */
+  errno = 0;
+  char* cp = NULL;
+  unsigned long major = strtoul (version, &cp, 10);
+  if (errno || *cp != '.')
+    {
+      complain (loc, complaint, _("invalid version requirement: %s"),
+                version);
+      return;
+    }
+  ++cp;
+  unsigned long minor = strtoul (cp, NULL, 10);
+  if (errno)
+    {
+      complain (loc, complaint, _("invalid version requirement: %s"),
+                version);
+      return;
+    }
+  required_version = major * 100 + minor;
+  /* Pretend to be at least 3.2, even if we are only 3.1-211, as it
+     allows us to check features published in 3.2 while developping
+     3.2.  */
+  const char* api_version = "3.2";
+  const char* package_version =
+    strverscmp (api_version, PACKAGE_VERSION) > 0
+    ? api_version : PACKAGE_VERSION;
+  if (strverscmp (version, package_version) > 0)
     {
-      complain (loc, complaint, "require bison %s, but have %s",
-                version, PACKAGE_VERSION);
+      complain (loc, complaint, _("require bison %s, but have %s"),
+                version, package_version);
       exit (EX_MISMATCH);
     }
 }
