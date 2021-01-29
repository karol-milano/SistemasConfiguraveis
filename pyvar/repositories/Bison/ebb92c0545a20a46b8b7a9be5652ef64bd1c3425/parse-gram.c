@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.2.1.  */
+/* A Bison parser, made by GNU Bison 3.2.1.9-1e55d.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -47,7 +47,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.2.1"
+#define YYBISON_VERSION "3.2.1.9-1e55d"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -124,7 +124,7 @@ extern int gram_debug;
 
   #include "symlist.h"
   #include "symtab.h"
-#line 214 "src/parse-gram.y" /* yacc.c:353  */
+#line 218 "src/parse-gram.y" /* yacc.c:353  */
 
   typedef enum
   {
@@ -133,7 +133,7 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 627 "src/parse-gram.y" /* yacc.c:353  */
+#line 608 "src/parse-gram.y" /* yacc.c:353  */
 
   #include "muscle-tab.h"
   typedef struct
@@ -352,7 +352,11 @@ int gram_parse (void);
      string from the scanner (should be CODE). */
   static char const *translate_code_braceless (char *code, location loc);
 
-  static void version_check (location const *loc, char const *version);
+  /* Handle a %require directive.  */
+  static void do_require (location const *loc, char const *version);
+
+  /* Handle a %skeleton directive.  */
+  static void do_skeleton (location const *loc, char const *skel);
 
   static void gram_error (location const *, char const *);
 
@@ -363,7 +367,7 @@ int gram_parse (void);
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 224 "src/parse-gram.y" /* yacc.c:356  */
+#line 228 "src/parse-gram.y" /* yacc.c:356  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -374,7 +378,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 378 "src/parse-gram.c" /* yacc.c:356  */
+#line 382 "src/parse-gram.c" /* yacc.c:356  */
 
 #ifdef short
 # undef short
@@ -647,17 +651,17 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   256,   256,   265,   266,   270,   271,   277,   281,   286,
-     287,   292,   293,   294,   295,   300,   305,   306,   307,   308,
-     309,   310,   310,   311,   312,   336,   337,   338,   339,   343,
-     344,   353,   354,   355,   359,   370,   374,   378,   386,   396,
-     397,   407,   408,   414,   426,   426,   431,   431,   436,   446,
-     460,   461,   462,   463,   467,   468,   473,   475,   480,   485,
-     495,   497,   502,   503,   507,   508,   512,   513,   514,   519,
-     524,   529,   535,   541,   552,   553,   562,   563,   569,   570,
-     571,   578,   578,   586,   587,   588,   593,   596,   598,   600,
-     602,   604,   606,   608,   613,   614,   623,   647,   648,   649,
-     650,   662,   664,   673,   678,   679,   684,   692,   693
+       0,   260,   260,   269,   270,   274,   275,   281,   285,   290,
+     291,   296,   297,   298,   299,   304,   309,   310,   311,   312,
+     313,   314,   314,   315,   316,   317,   318,   319,   320,   324,
+     325,   334,   335,   336,   340,   351,   355,   359,   367,   377,
+     378,   388,   389,   395,   407,   407,   412,   412,   417,   427,
+     441,   442,   443,   444,   448,   449,   454,   456,   461,   466,
+     476,   478,   483,   484,   488,   489,   493,   494,   495,   500,
+     505,   510,   516,   522,   533,   534,   543,   544,   550,   551,
+     552,   559,   559,   567,   568,   569,   574,   577,   579,   581,
+     583,   585,   587,   589,   594,   595,   604,   628,   629,   630,
+     631,   643,   645,   654,   659,   660,   665,   673,   674
 };
 #endif
 
@@ -1031,79 +1035,79 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
   switch (yytype)
     {
           case 3: /* "string"  */
-#line 187 "src/parse-gram.y" /* yacc.c:681  */
+#line 191 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (quotearg_style (c_quoting_style, (*(char**)(&(*yyvaluep)))), yyo); }
-#line 1037 "src/parse-gram.c" /* yacc.c:681  */
+#line 1041 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 22: /* "%<flag>"  */
-#line 194 "src/parse-gram.y" /* yacc.c:681  */
+#line 198 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%%%s", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1043 "src/parse-gram.c" /* yacc.c:681  */
+#line 1047 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 38: /* "{...}"  */
-#line 188 "src/parse-gram.y" /* yacc.c:681  */
+#line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1049 "src/parse-gram.c" /* yacc.c:681  */
+#line 1053 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 39: /* "%?{...}"  */
-#line 188 "src/parse-gram.y" /* yacc.c:681  */
+#line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1055 "src/parse-gram.c" /* yacc.c:681  */
+#line 1059 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 40: /* "[identifier]"  */
-#line 192 "src/parse-gram.y" /* yacc.c:681  */
+#line 196 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "[%s]", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1061 "src/parse-gram.c" /* yacc.c:681  */
+#line 1065 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 41: /* "char"  */
-#line 184 "src/parse-gram.y" /* yacc.c:681  */
+#line 188 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (char_name ((*(unsigned char*)(&(*yyvaluep)))), yyo); }
-#line 1067 "src/parse-gram.c" /* yacc.c:681  */
+#line 1071 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 42: /* "epilogue"  */
-#line 188 "src/parse-gram.y" /* yacc.c:681  */
+#line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1073 "src/parse-gram.c" /* yacc.c:681  */
+#line 1077 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 44: /* "identifier"  */
-#line 191 "src/parse-gram.y" /* yacc.c:681  */
+#line 195 "src/parse-gram.y" /* yacc.c:681  */
       { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
-#line 1079 "src/parse-gram.c" /* yacc.c:681  */
+#line 1083 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 45: /* "identifier:"  */
-#line 193 "src/parse-gram.y" /* yacc.c:681  */
+#line 197 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1085 "src/parse-gram.c" /* yacc.c:681  */
+#line 1089 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 48: /* "%{...%}"  */
-#line 188 "src/parse-gram.y" /* yacc.c:681  */
+#line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1091 "src/parse-gram.c" /* yacc.c:681  */
+#line 1095 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 50: /* "<tag>"  */
-#line 195 "src/parse-gram.y" /* yacc.c:681  */
+#line 199 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1097 "src/parse-gram.c" /* yacc.c:681  */
+#line 1101 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 53: /* "integer"  */
-#line 198 "src/parse-gram.y" /* yacc.c:681  */
+#line 202 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%d", (*(int*)(&(*yyvaluep)))); }
-#line 1103 "src/parse-gram.c" /* yacc.c:681  */
+#line 1107 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 54: /* "%param"  */
-#line 236 "src/parse-gram.y" /* yacc.c:681  */
+#line 240 "src/parse-gram.y" /* yacc.c:681  */
       {
   switch ((*(param_type*)(&(*yyvaluep))))
     {
@@ -1116,35 +1120,35 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 1120 "src/parse-gram.c" /* yacc.c:681  */
+#line 1124 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 64: /* code_props_type  */
-#line 394 "src/parse-gram.y" /* yacc.c:681  */
+#line 375 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", code_props_type_string ((*(code_props_type*)(&(*yyvaluep))))); }
-#line 1126 "src/parse-gram.c" /* yacc.c:681  */
+#line 1130 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 73: /* symbol.prec  */
-#line 201 "src/parse-gram.y" /* yacc.c:681  */
+#line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1132 "src/parse-gram.c" /* yacc.c:681  */
+#line 1136 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 77: /* tag  */
-#line 195 "src/parse-gram.y" /* yacc.c:681  */
+#line 199 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1138 "src/parse-gram.c" /* yacc.c:681  */
+#line 1142 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 87: /* variable  */
-#line 191 "src/parse-gram.y" /* yacc.c:681  */
+#line 195 "src/parse-gram.y" /* yacc.c:681  */
       { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
-#line 1144 "src/parse-gram.c" /* yacc.c:681  */
+#line 1148 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 88: /* value  */
-#line 637 "src/parse-gram.y" /* yacc.c:681  */
+#line 618 "src/parse-gram.y" /* yacc.c:681  */
       {
   switch ((*(value_type*)(&(*yyvaluep))).kind)
     {
@@ -1153,31 +1157,31 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
     case muscle_string:  fprintf (yyo, "\"%s\"", (*(value_type*)(&(*yyvaluep))).chars); break;
     }
 }
-#line 1157 "src/parse-gram.c" /* yacc.c:681  */
+#line 1161 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 89: /* id  */
-#line 201 "src/parse-gram.y" /* yacc.c:681  */
+#line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1163 "src/parse-gram.c" /* yacc.c:681  */
+#line 1167 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 90: /* id_colon  */
-#line 202 "src/parse-gram.y" /* yacc.c:681  */
+#line 206 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1169 "src/parse-gram.c" /* yacc.c:681  */
+#line 1173 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 91: /* symbol  */
-#line 201 "src/parse-gram.y" /* yacc.c:681  */
+#line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1175 "src/parse-gram.c" /* yacc.c:681  */
+#line 1179 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 92: /* string_as_id  */
-#line 201 "src/parse-gram.y" /* yacc.c:681  */
+#line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1181 "src/parse-gram.c" /* yacc.c:681  */
+#line 1185 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
 
@@ -1871,7 +1875,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 110 "src/parse-gram.y" /* yacc.c:1428  */
+#line 114 "src/parse-gram.y" /* yacc.c:1428  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1879,7 +1883,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1883 "src/parse-gram.c" /* yacc.c:1428  */
+#line 1887 "src/parse-gram.c" /* yacc.c:1428  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2073,199 +2077,177 @@ yyreduce:
     switch (yyn)
       {
   case 6:
-#line 272 "src/parse-gram.y" /* yacc.c:1644  */
+#line 276 "src/parse-gram.y" /* yacc.c:1644  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2083 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2087 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 7:
-#line 278 "src/parse-gram.y" /* yacc.c:1644  */
+#line 282 "src/parse-gram.y" /* yacc.c:1644  */
     {
       muscle_percent_define_ensure ((*(uniqstr*)(&yyvsp[0])), (yylsp[0]), true);
     }
-#line 2091 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2095 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 8:
-#line 282 "src/parse-gram.y" /* yacc.c:1644  */
+#line 286 "src/parse-gram.y" /* yacc.c:1644  */
     {
       muscle_percent_define_insert ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), (*(value_type*)(&yyvsp[0])).kind, (*(value_type*)(&yyvsp[0])).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2100 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2104 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 9:
-#line 286 "src/parse-gram.y" /* yacc.c:1644  */
+#line 290 "src/parse-gram.y" /* yacc.c:1644  */
     { defines_flag = true; }
-#line 2106 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2110 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 10:
-#line 288 "src/parse-gram.y" /* yacc.c:1644  */
+#line 292 "src/parse-gram.y" /* yacc.c:1644  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((*(char**)(&yyvsp[0])));
     }
-#line 2115 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2119 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 11:
-#line 292 "src/parse-gram.y" /* yacc.c:1644  */
+#line 296 "src/parse-gram.y" /* yacc.c:1644  */
     { expected_sr_conflicts = (*(int*)(&yyvsp[0])); }
-#line 2121 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2125 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 12:
-#line 293 "src/parse-gram.y" /* yacc.c:1644  */
+#line 297 "src/parse-gram.y" /* yacc.c:1644  */
     { expected_rr_conflicts = (*(int*)(&yyvsp[0])); }
-#line 2127 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2131 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 13:
-#line 294 "src/parse-gram.y" /* yacc.c:1644  */
+#line 298 "src/parse-gram.y" /* yacc.c:1644  */
     { spec_file_prefix = (*(char**)(&yyvsp[0])); }
-#line 2133 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2137 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 14:
-#line 296 "src/parse-gram.y" /* yacc.c:1644  */
+#line 300 "src/parse-gram.y" /* yacc.c:1644  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2142 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2146 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 15:
-#line 301 "src/parse-gram.y" /* yacc.c:1644  */
+#line 305 "src/parse-gram.y" /* yacc.c:1644  */
     {
       muscle_code_grow ("initial_action", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2151 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2155 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 16:
-#line 305 "src/parse-gram.y" /* yacc.c:1644  */
+#line 309 "src/parse-gram.y" /* yacc.c:1644  */
     { language_argmatch ((*(char**)(&yyvsp[0])), grammar_prio, (yylsp[-1])); }
-#line 2157 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2161 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 17:
-#line 306 "src/parse-gram.y" /* yacc.c:1644  */
+#line 310 "src/parse-gram.y" /* yacc.c:1644  */
     { spec_name_prefix = (*(char**)(&yyvsp[0])); }
-#line 2163 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2167 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 18:
-#line 307 "src/parse-gram.y" /* yacc.c:1644  */
+#line 311 "src/parse-gram.y" /* yacc.c:1644  */
     { no_lines_flag = true; }
-#line 2169 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2173 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 19:
-#line 308 "src/parse-gram.y" /* yacc.c:1644  */
+#line 312 "src/parse-gram.y" /* yacc.c:1644  */
     { nondeterministic_parser = true; }
-#line 2175 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2179 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 20:
-#line 309 "src/parse-gram.y" /* yacc.c:1644  */
+#line 313 "src/parse-gram.y" /* yacc.c:1644  */
     { spec_outfile = (*(char**)(&yyvsp[0])); }
-#line 2181 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2185 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 21:
-#line 310 "src/parse-gram.y" /* yacc.c:1644  */
+#line 314 "src/parse-gram.y" /* yacc.c:1644  */
     { current_param = (*(param_type*)(&yyvsp[0])); }
-#line 2187 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2191 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 22:
-#line 310 "src/parse-gram.y" /* yacc.c:1644  */
+#line 314 "src/parse-gram.y" /* yacc.c:1644  */
     { current_param = param_none; }
-#line 2193 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2197 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 23:
-#line 311 "src/parse-gram.y" /* yacc.c:1644  */
-    { version_check (&(yylsp[0]), (*(char**)(&yyvsp[0]))); }
-#line 2199 "src/parse-gram.c" /* yacc.c:1644  */
+#line 315 "src/parse-gram.y" /* yacc.c:1644  */
+    { do_require (&(yylsp[0]), (*(char**)(&yyvsp[0]))); }
+#line 2203 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 24:
-#line 313 "src/parse-gram.y" /* yacc.c:1644  */
-    {
-      char const *skeleton_user = (*(char**)(&yyvsp[0]));
-      if (strchr (skeleton_user, '/'))
-        {
-          size_t dir_length = strlen (current_file);
-          char *skeleton_build;
-          while (dir_length && current_file[dir_length - 1] != '/')
-            --dir_length;
-          while (dir_length && current_file[dir_length - 1] == '/')
-            --dir_length;
-          skeleton_build =
-            xmalloc (dir_length + 1 + strlen (skeleton_user) + 1);
-          if (dir_length > 0)
-            {
-              memcpy (skeleton_build, current_file, dir_length);
-              skeleton_build[dir_length++] = '/';
-            }
-          strcpy (skeleton_build + dir_length, skeleton_user);
-          skeleton_user = uniqstr_new (skeleton_build);
-          free (skeleton_build);
-        }
-      skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
-    }
-#line 2227 "src/parse-gram.c" /* yacc.c:1644  */
+#line 316 "src/parse-gram.y" /* yacc.c:1644  */
+    { do_skeleton (&(yylsp[0]), (*(char**)(&yyvsp[0]))); }
+#line 2209 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 25:
-#line 336 "src/parse-gram.y" /* yacc.c:1644  */
+#line 317 "src/parse-gram.y" /* yacc.c:1644  */
     { token_table_flag = true; }
-#line 2233 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2215 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 26:
-#line 337 "src/parse-gram.y" /* yacc.c:1644  */
+#line 318 "src/parse-gram.y" /* yacc.c:1644  */
     { report_flag |= report_states; }
-#line 2239 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2221 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 27:
-#line 338 "src/parse-gram.y" /* yacc.c:1644  */
+#line 319 "src/parse-gram.y" /* yacc.c:1644  */
     { yacc_flag = true; }
-#line 2245 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2227 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 29:
-#line 343 "src/parse-gram.y" /* yacc.c:1644  */
+#line 324 "src/parse-gram.y" /* yacc.c:1644  */
     { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2251 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2233 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 30:
-#line 344 "src/parse-gram.y" /* yacc.c:1644  */
+#line 325 "src/parse-gram.y" /* yacc.c:1644  */
     { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2257 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2239 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 33:
-#line 356 "src/parse-gram.y" /* yacc.c:1644  */
+#line 337 "src/parse-gram.y" /* yacc.c:1644  */
     {
       grammar_start_symbol_set ((*(symbol**)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2265 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2247 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 34:
-#line 360 "src/parse-gram.y" /* yacc.c:1644  */
+#line 341 "src/parse-gram.y" /* yacc.c:1644  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (*(char**)(&yyvsp[-1])), (yylsp[-1]));
@@ -2276,27 +2258,27 @@ yyreduce:
         symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
       }
     }
-#line 2280 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2262 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 35:
-#line 371 "src/parse-gram.y" /* yacc.c:1644  */
+#line 352 "src/parse-gram.y" /* yacc.c:1644  */
     {
       default_prec = true;
     }
-#line 2288 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2270 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 36:
-#line 375 "src/parse-gram.y" /* yacc.c:1644  */
+#line 356 "src/parse-gram.y" /* yacc.c:1644  */
     {
       default_prec = false;
     }
-#line 2296 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2278 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 37:
-#line 379 "src/parse-gram.y" /* yacc.c:1644  */
+#line 360 "src/parse-gram.y" /* yacc.c:1644  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2304,97 +2286,97 @@ yyreduce:
                         translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2308 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2290 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 38:
-#line 387 "src/parse-gram.y" /* yacc.c:1644  */
+#line 368 "src/parse-gram.y" /* yacc.c:1644  */
     {
       muscle_percent_code_grow ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2317 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2299 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 39:
-#line 396 "src/parse-gram.y" /* yacc.c:1644  */
+#line 377 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(code_props_type*)(&yyval)) = destructor; }
-#line 2323 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2305 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 40:
-#line 397 "src/parse-gram.y" /* yacc.c:1644  */
+#line 378 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(code_props_type*)(&yyval)) = printer; }
-#line 2329 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2311 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 41:
-#line 407 "src/parse-gram.y" /* yacc.c:1644  */
+#line 388 "src/parse-gram.y" /* yacc.c:1644  */
     {}
-#line 2335 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2317 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 42:
-#line 408 "src/parse-gram.y" /* yacc.c:1644  */
+#line 389 "src/parse-gram.y" /* yacc.c:1644  */
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (*(uniqstr*)(&yyvsp[0])),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2343 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2325 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 43:
-#line 415 "src/parse-gram.y" /* yacc.c:1644  */
+#line 396 "src/parse-gram.y" /* yacc.c:1644  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2353 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2335 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 44:
-#line 426 "src/parse-gram.y" /* yacc.c:1644  */
+#line 407 "src/parse-gram.y" /* yacc.c:1644  */
     { current_class = nterm_sym; }
-#line 2359 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2341 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 45:
-#line 427 "src/parse-gram.y" /* yacc.c:1644  */
+#line 408 "src/parse-gram.y" /* yacc.c:1644  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2368 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2350 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 46:
-#line 431 "src/parse-gram.y" /* yacc.c:1644  */
+#line 412 "src/parse-gram.y" /* yacc.c:1644  */
     { current_class = token_sym; }
-#line 2374 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2356 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 47:
-#line 432 "src/parse-gram.y" /* yacc.c:1644  */
+#line 413 "src/parse-gram.y" /* yacc.c:1644  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2383 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2365 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 48:
-#line 437 "src/parse-gram.y" /* yacc.c:1644  */
+#line 418 "src/parse-gram.y" /* yacc.c:1644  */
     {
       tag_seen = true;
       for (symbol_list *list = (*(symbol_list**)(&yyvsp[0])); list; list = list->next)
         symbol_type_set (list->content.sym, (*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]));
       symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
     }
-#line 2394 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2376 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 49:
-#line 447 "src/parse-gram.y" /* yacc.c:1644  */
+#line 428 "src/parse-gram.y" /* yacc.c:1644  */
     {
       ++current_prec;
       for (symbol_list *list = (*(symbol_list**)(&yyvsp[0])); list; list = list->next)
@@ -2405,335 +2387,335 @@ yyreduce:
       symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
       current_type = NULL;
     }
-#line 2409 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2391 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 50:
-#line 460 "src/parse-gram.y" /* yacc.c:1644  */
+#line 441 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(assoc*)(&yyval)) = left_assoc; }
-#line 2415 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2397 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 51:
-#line 461 "src/parse-gram.y" /* yacc.c:1644  */
+#line 442 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(assoc*)(&yyval)) = right_assoc; }
-#line 2421 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2403 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 52:
-#line 462 "src/parse-gram.y" /* yacc.c:1644  */
+#line 443 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(assoc*)(&yyval)) = non_assoc; }
-#line 2427 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2409 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 53:
-#line 463 "src/parse-gram.y" /* yacc.c:1644  */
+#line 444 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(assoc*)(&yyval)) = precedence_assoc; }
-#line 2433 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2415 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 54:
-#line 467 "src/parse-gram.y" /* yacc.c:1644  */
+#line 448 "src/parse-gram.y" /* yacc.c:1644  */
     { current_type = NULL; }
-#line 2439 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2421 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 55:
-#line 468 "src/parse-gram.y" /* yacc.c:1644  */
+#line 449 "src/parse-gram.y" /* yacc.c:1644  */
     { current_type = (*(uniqstr*)(&yyvsp[0])); tag_seen = true; }
-#line 2445 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2427 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 56:
-#line 474 "src/parse-gram.y" /* yacc.c:1644  */
+#line 455 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2451 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2433 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 57:
-#line 476 "src/parse-gram.y" /* yacc.c:1644  */
+#line 457 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
-#line 2457 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2439 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 58:
-#line 481 "src/parse-gram.y" /* yacc.c:1644  */
+#line 462 "src/parse-gram.y" /* yacc.c:1644  */
     {
       (*(symbol**)(&yyval)) = (*(symbol**)(&yyvsp[0]));
       symbol_class_set ((*(symbol**)(&yyvsp[0])), token_sym, (yylsp[0]), false);
     }
-#line 2466 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2448 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 59:
-#line 486 "src/parse-gram.y" /* yacc.c:1644  */
+#line 467 "src/parse-gram.y" /* yacc.c:1644  */
     {
       (*(symbol**)(&yyval)) = (*(symbol**)(&yyvsp[-1]));
       symbol_user_token_number_set ((*(symbol**)(&yyvsp[-1])), (*(int*)(&yyvsp[0])), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyvsp[-1])), token_sym, (yylsp[-1]), false);
     }
-#line 2476 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2458 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 60:
-#line 496 "src/parse-gram.y" /* yacc.c:1644  */
+#line 477 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2482 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2464 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 61:
-#line 498 "src/parse-gram.y" /* yacc.c:1644  */
+#line 479 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
-#line 2488 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2470 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 62:
-#line 502 "src/parse-gram.y" /* yacc.c:1644  */
+#line 483 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = (*(symbol_list**)(&yyvsp[0])); }
-#line 2494 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2476 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 63:
-#line 503 "src/parse-gram.y" /* yacc.c:1644  */
+#line 484 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), (*(symbol_list**)(&yyvsp[0]))); }
-#line 2500 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2482 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 64:
-#line 507 "src/parse-gram.y" /* yacc.c:1644  */
+#line 488 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2506 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2488 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 65:
-#line 508 "src/parse-gram.y" /* yacc.c:1644  */
+#line 489 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol_list**)(&yyval)) = symbol_list_type_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2512 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2494 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 67:
-#line 513 "src/parse-gram.y" /* yacc.c:1644  */
+#line 494 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(uniqstr*)(&yyval)) = uniqstr_new ("*"); }
-#line 2518 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2500 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 68:
-#line 514 "src/parse-gram.y" /* yacc.c:1644  */
+#line 495 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(uniqstr*)(&yyval)) = uniqstr_new (""); }
-#line 2524 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2506 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 69:
-#line 520 "src/parse-gram.y" /* yacc.c:1644  */
+#line 501 "src/parse-gram.y" /* yacc.c:1644  */
     {
       current_type = (*(uniqstr*)(&yyvsp[0]));
       tag_seen = true;
     }
-#line 2533 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2515 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 70:
-#line 525 "src/parse-gram.y" /* yacc.c:1644  */
+#line 506 "src/parse-gram.y" /* yacc.c:1644  */
     {
       symbol_class_set ((*(symbol**)(&yyvsp[0])), current_class, (yylsp[0]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[0])), current_type, (yylsp[0]));
     }
-#line 2542 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2524 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 71:
-#line 530 "src/parse-gram.y" /* yacc.c:1644  */
+#line 511 "src/parse-gram.y" /* yacc.c:1644  */
     {
       symbol_class_set ((*(symbol**)(&yyvsp[-1])), current_class, (yylsp[-1]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[-1])), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((*(symbol**)(&yyvsp[-1])), (*(int*)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2552 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2534 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 72:
-#line 536 "src/parse-gram.y" /* yacc.c:1644  */
+#line 517 "src/parse-gram.y" /* yacc.c:1644  */
     {
       symbol_class_set ((*(symbol**)(&yyvsp[-1])), current_class, (yylsp[-1]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[-1])), current_type, (yylsp[-1]));
       symbol_make_alias ((*(symbol**)(&yyvsp[-1])), (*(symbol**)(&yyvsp[0])), (yyloc));
     }
-#line 2562 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2544 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 73:
-#line 542 "src/parse-gram.y" /* yacc.c:1644  */
+#line 523 "src/parse-gram.y" /* yacc.c:1644  */
     {
       symbol_class_set ((*(symbol**)(&yyvsp[-2])), current_class, (yylsp[-2]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[-2])), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((*(symbol**)(&yyvsp[-2])), (*(int*)(&yyvsp[-1])), (yylsp[-1]));
       symbol_make_alias ((*(symbol**)(&yyvsp[-2])), (*(symbol**)(&yyvsp[0])), (yyloc));
     }
-#line 2573 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2555 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 80:
-#line 572 "src/parse-gram.y" /* yacc.c:1644  */
+#line 553 "src/parse-gram.y" /* yacc.c:1644  */
     {
       yyerrok;
     }
-#line 2581 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2563 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 81:
-#line 578 "src/parse-gram.y" /* yacc.c:1644  */
+#line 559 "src/parse-gram.y" /* yacc.c:1644  */
     { current_lhs ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
-#line 2587 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2569 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 82:
-#line 579 "src/parse-gram.y" /* yacc.c:1644  */
+#line 560 "src/parse-gram.y" /* yacc.c:1644  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2596 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2578 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 83:
-#line 586 "src/parse-gram.y" /* yacc.c:1644  */
+#line 567 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2602 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2584 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 84:
-#line 587 "src/parse-gram.y" /* yacc.c:1644  */
+#line 568 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2608 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2590 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 86:
-#line 594 "src/parse-gram.y" /* yacc.c:1644  */
+#line 575 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2615 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2597 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 87:
-#line 597 "src/parse-gram.y" /* yacc.c:1644  */
+#line 578 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_symbol_append ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
-#line 2621 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2603 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 88:
-#line 599 "src/parse-gram.y" /* yacc.c:1644  */
+#line 580 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_action_append ((*(char**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0])), current_type); }
-#line 2627 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2609 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 89:
-#line 601 "src/parse-gram.y" /* yacc.c:1644  */
+#line 582 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_predicate_append ((*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2633 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2615 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 90:
-#line 603 "src/parse-gram.y" /* yacc.c:1644  */
+#line 584 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2639 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2621 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 91:
-#line 605 "src/parse-gram.y" /* yacc.c:1644  */
+#line 586 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_prec_set ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2645 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2627 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 92:
-#line 607 "src/parse-gram.y" /* yacc.c:1644  */
+#line 588 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_dprec_set ((*(int*)(&yyvsp[0])), (yylsp[0])); }
-#line 2651 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2633 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 93:
-#line 609 "src/parse-gram.y" /* yacc.c:1644  */
+#line 590 "src/parse-gram.y" /* yacc.c:1644  */
     { grammar_current_rule_merge_set ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2657 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2639 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 94:
-#line 613 "src/parse-gram.y" /* yacc.c:1644  */
+#line 594 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(named_ref**)(&yyval)) = 0; }
-#line 2663 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2645 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 95:
-#line 614 "src/parse-gram.y" /* yacc.c:1644  */
+#line 595 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(named_ref**)(&yyval)) = named_ref_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2669 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2651 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 97:
-#line 647 "src/parse-gram.y" /* yacc.c:1644  */
+#line 628 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = ""; }
-#line 2675 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2657 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 98:
-#line 648 "src/parse-gram.y" /* yacc.c:1644  */
+#line 629 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = (*(uniqstr*)(&yyvsp[0])); }
-#line 2681 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2663 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 99:
-#line 649 "src/parse-gram.y" /* yacc.c:1644  */
+#line 630 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(value_type*)(&yyval)).kind = muscle_string;  (*(value_type*)(&yyval)).chars = (*(char**)(&yyvsp[0])); }
-#line 2687 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2669 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 100:
-#line 650 "src/parse-gram.y" /* yacc.c:1644  */
+#line 631 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(value_type*)(&yyval)).kind = muscle_code;    (*(value_type*)(&yyval)).chars = strip_braces ((*(char**)(&yyvsp[0]))); }
-#line 2693 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2675 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 101:
-#line 663 "src/parse-gram.y" /* yacc.c:1644  */
+#line 644 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2699 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2681 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 102:
-#line 665 "src/parse-gram.y" /* yacc.c:1644  */
+#line 646 "src/parse-gram.y" /* yacc.c:1644  */
     {
       (*(symbol**)(&yyval)) = symbol_get (char_name ((*(unsigned char*)(&yyvsp[0]))), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((*(symbol**)(&yyval)), (*(unsigned char*)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2709 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2691 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 103:
-#line 673 "src/parse-gram.y" /* yacc.c:1644  */
+#line 654 "src/parse-gram.y" /* yacc.c:1644  */
     { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2715 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2697 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 106:
-#line 685 "src/parse-gram.y" /* yacc.c:1644  */
+#line 666 "src/parse-gram.y" /* yacc.c:1644  */
     {
       (*(symbol**)(&yyval)) = symbol_get (quotearg_style (c_quoting_style, (*(char**)(&yyvsp[0]))), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
     }
-#line 2724 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2706 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
   case 108:
-#line 694 "src/parse-gram.y" /* yacc.c:1644  */
+#line 675 "src/parse-gram.y" /* yacc.c:1644  */
     {
       muscle_code_grow ("epilogue", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2733 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2715 "src/parse-gram.c" /* yacc.c:1644  */
     break;
 
 
-#line 2737 "src/parse-gram.c" /* yacc.c:1644  */
+#line 2719 "src/parse-gram.c" /* yacc.c:1644  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2978,7 +2960,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 700 "src/parse-gram.y" /* yacc.c:1902  */
+#line 681 "src/parse-gram.y" /* yacc.c:1902  */
 
 
 /* Return the location of the left-hand side of a rule whose
@@ -3084,7 +3066,7 @@ add_param (param_type type, char *decl, location loc)
 
 
 static void
-version_check (location const *loc, char const *version)
+do_require (location const *loc, char const *version)
 {
   /* Changes of behavior are only on minor version changes, so "3.0.5"
      is the same as "3.0". */
@@ -3121,6 +3103,32 @@ version_check (location const *loc, char const *version)
     }
 }
 
+static void
+do_skeleton (location const *loc, char const *skel)
+{
+  char const *skeleton_user = skel;
+  if (strchr (skeleton_user, '/'))
+    {
+      size_t dir_length = strlen (current_file);
+      while (dir_length && current_file[dir_length - 1] != '/')
+        --dir_length;
+      while (dir_length && current_file[dir_length - 1] == '/')
+        --dir_length;
+      char *skeleton_build =
+        xmalloc (dir_length + 1 + strlen (skeleton_user) + 1);
+      if (dir_length > 0)
+        {
+          memcpy (skeleton_build, current_file, dir_length);
+          skeleton_build[dir_length++] = '/';
+        }
+      strcpy (skeleton_build + dir_length, skeleton_user);
+      skeleton_user = uniqstr_new (skeleton_build);
+      free (skeleton_build);
+    }
+  skeleton_arg (skeleton_user, grammar_prio, *loc);
+}
+
+
 static void
 gram_error (location const *loc, char const *msg)
 {
