@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.2.1.57-7965.  */
+/* A Bison parser, made by GNU Bison 3.2.1.64-49972.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -47,7 +47,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.2.1.57-7965"
+#define YYBISON_VERSION "3.2.1.64-49972"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -133,7 +133,7 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 621 "src/parse-gram.y" /* yacc.c:353  */
+#line 620 "src/parse-gram.y" /* yacc.c:353  */
 
   #include "muscle-tab.h"
   typedef struct
@@ -265,6 +265,8 @@ union GRAM_STYPE
   uniqstr ID_COLON;
   /* "<tag>"  */
   uniqstr TAG;
+  /* tag.opt  */
+  uniqstr yytype_71;
   /* tag  */
   uniqstr tag;
   /* variable  */
@@ -273,7 +275,7 @@ union GRAM_STYPE
   unsigned char CHAR;
   /* value  */
   value_type value;
-#line 277 "src/parse-gram.c" /* yacc.c:353  */
+#line 279 "src/parse-gram.c" /* yacc.c:353  */
 };
 
 typedef union GRAM_STYPE GRAM_STYPE;
@@ -382,7 +384,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 386 "src/parse-gram.c" /* yacc.c:356  */
+#line 388 "src/parse-gram.c" /* yacc.c:356  */
 
 #ifdef short
 # undef short
@@ -660,13 +662,13 @@ static const yytype_uint16 yyrline[] =
      313,   314,   314,   315,   316,   317,   318,   319,   320,   321,
      325,   326,   335,   336,   337,   341,   352,   356,   360,   368,
      378,   379,   389,   390,   396,   408,   408,   413,   413,   418,
-     428,   442,   443,   444,   445,   449,   450,   455,   457,   462,
-     467,   477,   479,   484,   485,   489,   490,   494,   495,   496,
-     501,   506,   533,   534,   539,   540,   552,   553,   559,   560,
-     561,   568,   568,   576,   577,   578,   583,   586,   588,   590,
-     592,   594,   596,   598,   600,   602,   607,   608,   617,   641,
-     642,   643,   644,   656,   658,   673,   678,   679,   684,   693,
-     694,   698,   699
+     428,   441,   442,   443,   444,   448,   449,   454,   456,   461,
+     466,   476,   478,   483,   484,   488,   489,   493,   494,   495,
+     500,   505,   532,   533,   538,   539,   551,   552,   558,   559,
+     560,   567,   567,   575,   576,   577,   582,   585,   587,   589,
+     591,   593,   595,   597,   599,   601,   606,   607,   616,   640,
+     641,   642,   643,   655,   657,   672,   677,   678,   683,   692,
+     693,   697,   698
 };
 #endif
 
@@ -1050,73 +1052,73 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
           case 3: /* "string"  */
 #line 191 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (quotearg_style (c_quoting_style, (*(char**)(&(*yyvaluep)))), yyo); }
-#line 1054 "src/parse-gram.c" /* yacc.c:681  */
+#line 1056 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 22: /* "%<flag>"  */
 #line 198 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%%%s", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1060 "src/parse-gram.c" /* yacc.c:681  */
+#line 1062 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 38: /* "{...}"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1066 "src/parse-gram.c" /* yacc.c:681  */
+#line 1068 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 39: /* "%?{...}"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1072 "src/parse-gram.c" /* yacc.c:681  */
+#line 1074 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 40: /* "[identifier]"  */
 #line 196 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "[%s]", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1078 "src/parse-gram.c" /* yacc.c:681  */
+#line 1080 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 41: /* "char"  */
 #line 188 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (char_name ((*(unsigned char*)(&(*yyvaluep)))), yyo); }
-#line 1084 "src/parse-gram.c" /* yacc.c:681  */
+#line 1086 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 42: /* "epilogue"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1090 "src/parse-gram.c" /* yacc.c:681  */
+#line 1092 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 44: /* "identifier"  */
 #line 195 "src/parse-gram.y" /* yacc.c:681  */
       { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
-#line 1096 "src/parse-gram.c" /* yacc.c:681  */
+#line 1098 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 45: /* "identifier:"  */
 #line 197 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1102 "src/parse-gram.c" /* yacc.c:681  */
+#line 1104 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 48: /* "%{...%}"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
-#line 1108 "src/parse-gram.c" /* yacc.c:681  */
+#line 1110 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 50: /* "<tag>"  */
 #line 199 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1114 "src/parse-gram.c" /* yacc.c:681  */
+#line 1116 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 53: /* "integer"  */
 #line 202 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%d", (*(int*)(&(*yyvaluep)))); }
-#line 1120 "src/parse-gram.c" /* yacc.c:681  */
+#line 1122 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 54: /* "%param"  */
@@ -1133,41 +1135,47 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 1137 "src/parse-gram.c" /* yacc.c:681  */
+#line 1139 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 64: /* code_props_type  */
 #line 376 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", code_props_type_string ((*(code_props_type*)(&(*yyvaluep))))); }
-#line 1143 "src/parse-gram.c" /* yacc.c:681  */
+#line 1145 "src/parse-gram.c" /* yacc.c:681  */
+        break;
+
+    case 71: /* tag.opt  */
+#line 195 "src/parse-gram.y" /* yacc.c:681  */
+      { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
+#line 1151 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 73: /* symbol.prec  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1149 "src/parse-gram.c" /* yacc.c:681  */
+#line 1157 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 77: /* tag  */
 #line 199 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
-#line 1155 "src/parse-gram.c" /* yacc.c:681  */
+#line 1163 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 79: /* int.opt  */
 #line 202 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%d", (*(int*)(&(*yyvaluep)))); }
-#line 1161 "src/parse-gram.c" /* yacc.c:681  */
+#line 1169 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 88: /* variable  */
 #line 195 "src/parse-gram.y" /* yacc.c:681  */
       { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
-#line 1167 "src/parse-gram.c" /* yacc.c:681  */
+#line 1175 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 89: /* value  */
-#line 631 "src/parse-gram.y" /* yacc.c:681  */
+#line 630 "src/parse-gram.y" /* yacc.c:681  */
       {
   switch ((*(value_type*)(&(*yyvaluep))).kind)
     {
@@ -1176,37 +1184,37 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
     case muscle_string:  fprintf (yyo, "\"%s\"", (*(value_type*)(&(*yyvaluep))).chars); break;
     }
 }
-#line 1180 "src/parse-gram.c" /* yacc.c:681  */
+#line 1188 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 90: /* id  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1186 "src/parse-gram.c" /* yacc.c:681  */
+#line 1194 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 91: /* id_colon  */
 #line 206 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1192 "src/parse-gram.c" /* yacc.c:681  */
+#line 1200 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 92: /* symbol  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1198 "src/parse-gram.c" /* yacc.c:681  */
+#line 1206 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 93: /* string_as_id  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1204 "src/parse-gram.c" /* yacc.c:681  */
+#line 1212 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 94: /* string_as_id.opt  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
-#line 1210 "src/parse-gram.c" /* yacc.c:681  */
+#line 1218 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
 
@@ -1908,7 +1916,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1912 "src/parse-gram.c" /* yacc.c:1428  */
+#line 1920 "src/parse-gram.c" /* yacc.c:1428  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2113,7 +2121,7 @@ yyreduce:
                         translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2117 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2125 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 7:
@@ -2121,7 +2129,7 @@ yyreduce:
     {
       muscle_percent_define_ensure ((*(uniqstr*)(&yyvsp[0])), (yylsp[0]), true);
     }
-#line 2125 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2133 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 8:
@@ -2130,13 +2138,13 @@ yyreduce:
       muscle_percent_define_insert ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), (*(value_type*)(&yyvsp[0])).kind, (*(value_type*)(&yyvsp[0])).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2134 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2142 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 9:
 #line 290 "src/parse-gram.y" /* yacc.c:1649  */
     { defines_flag = true; }
-#line 2140 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2148 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 10:
@@ -2145,25 +2153,25 @@ yyreduce:
       defines_flag = true;
       spec_defines_file = xstrdup ((*(char**)(&yyvsp[0])));
     }
-#line 2149 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2157 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 11:
 #line 296 "src/parse-gram.y" /* yacc.c:1649  */
     { expected_sr_conflicts = (*(int*)(&yyvsp[0])); }
-#line 2155 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2163 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 12:
 #line 297 "src/parse-gram.y" /* yacc.c:1649  */
     { expected_rr_conflicts = (*(int*)(&yyvsp[0])); }
-#line 2161 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2169 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 13:
 #line 298 "src/parse-gram.y" /* yacc.c:1649  */
     { spec_file_prefix = (*(char**)(&yyvsp[0])); }
-#line 2167 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2175 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 14:
@@ -2172,7 +2180,7 @@ yyreduce:
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2176 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2184 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 15:
@@ -2181,97 +2189,97 @@ yyreduce:
       muscle_code_grow ("initial_action", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2185 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2193 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 16:
 #line 309 "src/parse-gram.y" /* yacc.c:1649  */
     { language_argmatch ((*(char**)(&yyvsp[0])), grammar_prio, (yylsp[-1])); }
-#line 2191 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2199 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 17:
 #line 310 "src/parse-gram.y" /* yacc.c:1649  */
     { spec_name_prefix = (*(char**)(&yyvsp[0])); }
-#line 2197 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2205 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 18:
 #line 311 "src/parse-gram.y" /* yacc.c:1649  */
     { no_lines_flag = true; }
-#line 2203 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2211 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 19:
 #line 312 "src/parse-gram.y" /* yacc.c:1649  */
     { nondeterministic_parser = true; }
-#line 2209 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2217 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 20:
 #line 313 "src/parse-gram.y" /* yacc.c:1649  */
     { spec_outfile = (*(char**)(&yyvsp[0])); }
-#line 2215 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2223 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 21:
 #line 314 "src/parse-gram.y" /* yacc.c:1649  */
     { current_param = (*(param_type*)(&yyvsp[0])); }
-#line 2221 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2229 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 22:
 #line 314 "src/parse-gram.y" /* yacc.c:1649  */
     { current_param = param_none; }
-#line 2227 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2235 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 23:
 #line 315 "src/parse-gram.y" /* yacc.c:1649  */
     { do_require (&(yylsp[0]), (*(char**)(&yyvsp[0]))); }
-#line 2233 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2241 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 24:
 #line 316 "src/parse-gram.y" /* yacc.c:1649  */
     { do_skeleton (&(yylsp[0]), (*(char**)(&yyvsp[0]))); }
-#line 2239 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2247 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 25:
 #line 317 "src/parse-gram.y" /* yacc.c:1649  */
     { token_table_flag = true; }
-#line 2245 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2253 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 26:
 #line 318 "src/parse-gram.y" /* yacc.c:1649  */
     { report_flag |= report_states; }
-#line 2251 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2259 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 27:
 #line 319 "src/parse-gram.y" /* yacc.c:1649  */
     { yacc_flag = true; }
-#line 2257 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2265 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 28:
 #line 320 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = unknown_sym; yyerrok; }
-#line 2263 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2271 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 30:
 #line 325 "src/parse-gram.y" /* yacc.c:1649  */
     { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2269 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2277 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 31:
 #line 326 "src/parse-gram.y" /* yacc.c:1649  */
     { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2275 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2283 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 34:
@@ -2279,7 +2287,7 @@ yyreduce:
     {
       grammar_start_symbol_set ((*(symbol**)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2283 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2291 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 35:
@@ -2294,7 +2302,7 @@ yyreduce:
         symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
       }
     }
-#line 2298 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2306 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 36:
@@ -2302,7 +2310,7 @@ yyreduce:
     {
       default_prec = true;
     }
-#line 2306 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2314 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 37:
@@ -2310,7 +2318,7 @@ yyreduce:
     {
       default_prec = false;
     }
-#line 2314 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2322 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 38:
@@ -2322,7 +2330,7 @@ yyreduce:
                         translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2326 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2334 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 39:
@@ -2331,25 +2339,25 @@ yyreduce:
       muscle_percent_code_grow ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2335 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2343 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 40:
 #line 378 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(code_props_type*)(&yyval)) = destructor; }
-#line 2341 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2349 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 41:
 #line 379 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(code_props_type*)(&yyval)) = printer; }
-#line 2347 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2355 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 42:
 #line 389 "src/parse-gram.y" /* yacc.c:1649  */
     {}
-#line 2353 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2361 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 43:
@@ -2357,7 +2365,7 @@ yyreduce:
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (*(uniqstr*)(&yyvsp[0])),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2361 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2369 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 44:
@@ -2367,13 +2375,13 @@ yyreduce:
       muscle_code_grow ("union_members", translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2371 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2379 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 45:
 #line 408 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = nterm_sym; }
-#line 2377 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2385 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 46:
@@ -2382,13 +2390,13 @@ yyreduce:
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2386 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2394 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 47:
 #line 413 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = token_sym; }
-#line 2392 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2400 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 48:
@@ -2397,7 +2405,7 @@ yyreduce:
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2401 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2409 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 49:
@@ -2408,7 +2416,7 @@ yyreduce:
         symbol_type_set (list->content.sym, (*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]));
       symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
     }
-#line 2412 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2420 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 50:
@@ -2417,141 +2425,134 @@ yyreduce:
       ++current_prec;
       for (symbol_list *list = (*(symbol_list**)(&yyvsp[0])); list; list = list->next)
         {
-          symbol_type_set (list->content.sym, current_type, (yylsp[-1]));
+          symbol_type_set (list->content.sym, (*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]));
           symbol_precedence_set (list->content.sym, current_prec, (*(assoc*)(&yyvsp[-2])), (yylsp[-2]));
         }
       symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
-      current_type = NULL;
     }
-#line 2427 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2434 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 51:
-#line 442 "src/parse-gram.y" /* yacc.c:1649  */
+#line 441 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(assoc*)(&yyval)) = left_assoc; }
-#line 2433 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2440 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 52:
-#line 443 "src/parse-gram.y" /* yacc.c:1649  */
+#line 442 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(assoc*)(&yyval)) = right_assoc; }
-#line 2439 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2446 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 53:
-#line 444 "src/parse-gram.y" /* yacc.c:1649  */
+#line 443 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(assoc*)(&yyval)) = non_assoc; }
-#line 2445 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2452 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 54:
-#line 445 "src/parse-gram.y" /* yacc.c:1649  */
+#line 444 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(assoc*)(&yyval)) = precedence_assoc; }
-#line 2451 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2458 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 55:
-#line 449 "src/parse-gram.y" /* yacc.c:1649  */
-    { current_type = NULL; }
-#line 2457 "src/parse-gram.c" /* yacc.c:1649  */
+#line 448 "src/parse-gram.y" /* yacc.c:1649  */
+    { (*(uniqstr*)(&yyval)) = NULL; }
+#line 2464 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 56:
-#line 450 "src/parse-gram.y" /* yacc.c:1649  */
-    { current_type = (*(uniqstr*)(&yyvsp[0])); tag_seen = true; }
-#line 2463 "src/parse-gram.c" /* yacc.c:1649  */
+#line 449 "src/parse-gram.y" /* yacc.c:1649  */
+    { (*(uniqstr*)(&yyval)) = (*(uniqstr*)(&yyvsp[0])); tag_seen = true; }
+#line 2470 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 57:
-#line 456 "src/parse-gram.y" /* yacc.c:1649  */
+#line 455 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2469 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2476 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 58:
-#line 458 "src/parse-gram.y" /* yacc.c:1649  */
+#line 457 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
-#line 2475 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2482 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 59:
-#line 463 "src/parse-gram.y" /* yacc.c:1649  */
+#line 462 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (*(symbol**)(&yyval)) = (*(symbol**)(&yyvsp[0]));
       symbol_class_set ((*(symbol**)(&yyvsp[0])), token_sym, (yylsp[0]), false);
     }
-#line 2484 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2491 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 60:
-#line 468 "src/parse-gram.y" /* yacc.c:1649  */
+#line 467 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (*(symbol**)(&yyval)) = (*(symbol**)(&yyvsp[-1]));
       symbol_user_token_number_set ((*(symbol**)(&yyvsp[-1])), (*(int*)(&yyvsp[0])), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyvsp[-1])), token_sym, (yylsp[-1]), false);
     }
-#line 2494 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2501 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 61:
-#line 478 "src/parse-gram.y" /* yacc.c:1649  */
+#line 477 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2500 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2507 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 62:
-#line 480 "src/parse-gram.y" /* yacc.c:1649  */
+#line 479 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
-#line 2506 "src/parse-gram.c" /* yacc.c:1649  */
-    break;
-
-  case 63:
-#line 484 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = (*(symbol_list**)(&yyvsp[0])); }
-#line 2512 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2513 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 64:
-#line 485 "src/parse-gram.y" /* yacc.c:1649  */
+#line 484 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), (*(symbol_list**)(&yyvsp[0]))); }
-#line 2518 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2519 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 65:
-#line 489 "src/parse-gram.y" /* yacc.c:1649  */
+#line 488 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2524 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2525 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 66:
-#line 490 "src/parse-gram.y" /* yacc.c:1649  */
+#line 489 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol_list**)(&yyval)) = symbol_list_type_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2530 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2531 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 68:
-#line 495 "src/parse-gram.y" /* yacc.c:1649  */
+#line 494 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(uniqstr*)(&yyval)) = uniqstr_new ("*"); }
-#line 2536 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2537 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 69:
-#line 496 "src/parse-gram.y" /* yacc.c:1649  */
+#line 495 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(uniqstr*)(&yyval)) = uniqstr_new (""); }
-#line 2542 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2543 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 70:
-#line 502 "src/parse-gram.y" /* yacc.c:1649  */
+#line 501 "src/parse-gram.y" /* yacc.c:1649  */
     {
       current_type = (*(uniqstr*)(&yyvsp[0]));
       tag_seen = true;
     }
-#line 2551 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2552 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 71:
-#line 507 "src/parse-gram.y" /* yacc.c:1649  */
+#line 506 "src/parse-gram.y" /* yacc.c:1649  */
     {
       symbol_class_set ((*(symbol**)(&yyvsp[-2])), current_class, (yylsp[-2]), true);
       symbol_type_set ((*(symbol**)(&yyvsp[-2])), current_type, (yylsp[-2]));
@@ -2574,155 +2575,155 @@ yyreduce:
       if (current_class != token_sym && (0 <= (*(int*)(&yyvsp[-1])) || !(*(symbol**)(&yyvsp[0]))))
         YYERROR;
     }
-#line 2578 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2579 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 72:
-#line 533 "src/parse-gram.y" /* yacc.c:1649  */
+#line 532 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(int*)(&yyval)) = -1; }
-#line 2584 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2585 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 80:
-#line 562 "src/parse-gram.y" /* yacc.c:1649  */
+#line 561 "src/parse-gram.y" /* yacc.c:1649  */
     {
       yyerrok;
     }
-#line 2592 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2593 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 81:
-#line 568 "src/parse-gram.y" /* yacc.c:1649  */
+#line 567 "src/parse-gram.y" /* yacc.c:1649  */
     { current_lhs ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
-#line 2598 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2599 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 82:
-#line 569 "src/parse-gram.y" /* yacc.c:1649  */
+#line 568 "src/parse-gram.y" /* yacc.c:1649  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2607 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2608 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 83:
-#line 576 "src/parse-gram.y" /* yacc.c:1649  */
+#line 575 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2613 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2614 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 84:
-#line 577 "src/parse-gram.y" /* yacc.c:1649  */
+#line 576 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2619 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2620 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 86:
-#line 584 "src/parse-gram.y" /* yacc.c:1649  */
+#line 583 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2626 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2627 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 87:
-#line 587 "src/parse-gram.y" /* yacc.c:1649  */
+#line 586 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_symbol_append ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
-#line 2632 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2633 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 88:
-#line 589 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_action_append ((*(char**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0])), current_type); }
-#line 2638 "src/parse-gram.c" /* yacc.c:1649  */
+#line 588 "src/parse-gram.y" /* yacc.c:1649  */
+    { grammar_current_rule_action_append ((*(char**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0])), (*(uniqstr*)(&yyvsp[-2]))); }
+#line 2639 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 89:
-#line 591 "src/parse-gram.y" /* yacc.c:1649  */
+#line 590 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_predicate_append ((*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2644 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2645 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 90:
-#line 593 "src/parse-gram.y" /* yacc.c:1649  */
+#line 592 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2650 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2651 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 91:
-#line 595 "src/parse-gram.y" /* yacc.c:1649  */
+#line 594 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_prec_set ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2656 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2657 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 92:
-#line 597 "src/parse-gram.y" /* yacc.c:1649  */
+#line 596 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_dprec_set ((*(int*)(&yyvsp[0])), (yylsp[0])); }
-#line 2662 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2663 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 93:
-#line 599 "src/parse-gram.y" /* yacc.c:1649  */
+#line 598 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_merge_set ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2668 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2669 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 94:
-#line 601 "src/parse-gram.y" /* yacc.c:1649  */
+#line 600 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_expect_sr ((*(int*)(&yyvsp[0])), (yylsp[0])); }
-#line 2674 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2675 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 95:
-#line 603 "src/parse-gram.y" /* yacc.c:1649  */
+#line 602 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_expect_rr ((*(int*)(&yyvsp[0])), (yylsp[0])); }
-#line 2680 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2681 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 96:
-#line 607 "src/parse-gram.y" /* yacc.c:1649  */
+#line 606 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(named_ref**)(&yyval)) = 0; }
-#line 2686 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2687 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 97:
-#line 608 "src/parse-gram.y" /* yacc.c:1649  */
+#line 607 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(named_ref**)(&yyval)) = named_ref_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2692 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2693 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 99:
-#line 641 "src/parse-gram.y" /* yacc.c:1649  */
+#line 640 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = ""; }
-#line 2698 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2699 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 100:
-#line 642 "src/parse-gram.y" /* yacc.c:1649  */
+#line 641 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = (*(uniqstr*)(&yyvsp[0])); }
-#line 2704 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2705 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 101:
-#line 643 "src/parse-gram.y" /* yacc.c:1649  */
+#line 642 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_string;  (*(value_type*)(&yyval)).chars = (*(char**)(&yyvsp[0])); }
-#line 2710 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2711 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 102:
-#line 644 "src/parse-gram.y" /* yacc.c:1649  */
+#line 643 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(value_type*)(&yyval)).kind = muscle_code;    (*(value_type*)(&yyval)).chars = strip_braces ((*(char**)(&yyvsp[0]))); }
-#line 2716 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2717 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 103:
-#line 657 "src/parse-gram.y" /* yacc.c:1649  */
+#line 656 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2722 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2723 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 104:
-#line 659 "src/parse-gram.y" /* yacc.c:1649  */
+#line 658 "src/parse-gram.y" /* yacc.c:1649  */
     {
       if (current_class == nterm_sym)
         {
@@ -2734,41 +2735,41 @@ yyreduce:
       symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((*(symbol**)(&yyval)), (*(unsigned char*)(&yyvsp[0])), (yylsp[0]));
     }
-#line 2738 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2739 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 105:
-#line 673 "src/parse-gram.y" /* yacc.c:1649  */
+#line 672 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2744 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2745 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 108:
-#line 685 "src/parse-gram.y" /* yacc.c:1649  */
+#line 684 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (*(symbol**)(&yyval)) = symbol_get (quotearg_style (c_quoting_style, (*(char**)(&yyvsp[0]))), (yylsp[0]));
       symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
     }
-#line 2753 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2754 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 109:
-#line 693 "src/parse-gram.y" /* yacc.c:1649  */
+#line 692 "src/parse-gram.y" /* yacc.c:1649  */
     { (*(symbol**)(&yyval)) = NULL; }
-#line 2759 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2760 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 112:
-#line 700 "src/parse-gram.y" /* yacc.c:1649  */
+#line 699 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_code_grow ("epilogue", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2768 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2769 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
 
-#line 2772 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2773 "src/parse-gram.c" /* yacc.c:1649  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3017,7 +3018,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 706 "src/parse-gram.y" /* yacc.c:1915  */
+#line 705 "src/parse-gram.y" /* yacc.c:1915  */
 
 
 /* Return the location of the left-hand side of a rule whose
