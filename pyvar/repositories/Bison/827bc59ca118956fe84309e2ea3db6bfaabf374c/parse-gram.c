@@ -129,7 +129,7 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 645 "src/parse-gram.y" /* yacc.c:355  */
+#line 647 "src/parse-gram.y" /* yacc.c:355  */
 #include "muscle-tab.h"
 
 #line 136 "src/parse-gram.c" /* yacc.c:355  */
@@ -200,7 +200,7 @@ extern int gram_debug;
 
 /* Value type.  */
 #if ! defined GRAM_STYPE && ! defined GRAM_STYPE_IS_DECLARED
-typedef union GRAM_STYPE GRAM_STYPE;
+
 union GRAM_STYPE
 {
 #line 182 "src/parse-gram.y" /* yacc.c:355  */
@@ -223,7 +223,7 @@ named_ref *named_ref;
 param_type param;
 #line 409 "src/parse-gram.y" /* yacc.c:355  */
 code_props_type code_type;
-#line 647 "src/parse-gram.y" /* yacc.c:355  */
+#line 649 "src/parse-gram.y" /* yacc.c:355  */
 
   struct
   {
@@ -233,6 +233,8 @@ code_props_type code_type;
 
 #line 235 "src/parse-gram.c" /* yacc.c:355  */
 };
+
+typedef union GRAM_STYPE GRAM_STYPE;
 # define GRAM_STYPE_IS_TRIVIAL 1
 # define GRAM_STYPE_IS_DECLARED 1
 #endif
@@ -259,7 +261,7 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-#line 263 "src/parse-gram.c" /* yacc.c:358  */
+#line 265 "src/parse-gram.c" /* yacc.c:358  */
 /* Unqualified %code blocks.  */
 #line 33 "src/parse-gram.y" /* yacc.c:359  */
 
@@ -335,7 +337,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 339 "src/parse-gram.c" /* yacc.c:359  */
+#line 341 "src/parse-gram.c" /* yacc.c:359  */
 
 #ifdef short
 # undef short
@@ -621,14 +623,14 @@ static const yytype_uint16 yyrline[] =
      295,   300,   306,   307,   308,   309,   314,   319,   320,   321,
      322,   323,   324,   324,   325,   326,   350,   351,   352,   353,
      357,   358,   367,   368,   369,   373,   385,   389,   393,   401,
-     412,   413,   423,   424,   428,   440,   440,   445,   445,   450,
-     461,   476,   477,   478,   479,   483,   484,   489,   491,   496,
-     501,   511,   513,   518,   519,   523,   524,   528,   529,   530,
-     535,   540,   545,   551,   557,   568,   569,   578,   579,   585,
-     586,   587,   594,   594,   602,   603,   604,   609,   612,   614,
-     616,   618,   620,   622,   624,   629,   630,   640,   641,   666,
-     667,   668,   669,   681,   683,   692,   697,   698,   703,   711,
-     712
+     412,   413,   423,   424,   430,   442,   442,   447,   447,   452,
+     463,   478,   479,   480,   481,   485,   486,   491,   493,   498,
+     503,   513,   515,   520,   521,   525,   526,   530,   531,   532,
+     537,   542,   547,   553,   559,   570,   571,   580,   581,   587,
+     588,   589,   596,   596,   604,   605,   606,   611,   614,   616,
+     618,   620,   622,   624,   626,   631,   632,   642,   643,   668,
+     669,   670,   671,   683,   685,   694,   699,   700,   705,   713,
+     714
 };
 #endif
 
@@ -1002,73 +1004,73 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
           case 3: /* "string"  */
 #line 188 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).code)), yyo); }
-#line 1006 "src/parse-gram.c" /* yacc.c:684  */
+#line 1008 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 23: /* "%<flag>"  */
 #line 196 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 1012 "src/parse-gram.c" /* yacc.c:684  */
+#line 1014 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 39: /* "{...}"  */
 #line 189 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1018 "src/parse-gram.c" /* yacc.c:684  */
+#line 1020 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 40: /* "%?{...}"  */
 #line 189 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1024 "src/parse-gram.c" /* yacc.c:684  */
+#line 1026 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 41: /* "[identifier]"  */
 #line 194 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 1030 "src/parse-gram.c" /* yacc.c:684  */
+#line 1032 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 42: /* "char"  */
 #line 184 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 1036 "src/parse-gram.c" /* yacc.c:684  */
+#line 1038 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 43: /* "epilogue"  */
 #line 189 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1042 "src/parse-gram.c" /* yacc.c:684  */
+#line 1044 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 45: /* "identifier"  */
 #line 193 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1048 "src/parse-gram.c" /* yacc.c:684  */
+#line 1050 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 46: /* "identifier:"  */
 #line 195 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1054 "src/parse-gram.c" /* yacc.c:684  */
+#line 1056 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 49: /* "%{...%}"  */
 #line 189 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1060 "src/parse-gram.c" /* yacc.c:684  */
+#line 1062 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 51: /* "<tag>"  */
 #line 197 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1066 "src/parse-gram.c" /* yacc.c:684  */
+#line 1068 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 54: /* "integer"  */
 #line 201 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1072 "src/parse-gram.c" /* yacc.c:684  */
+#line 1074 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 55: /* "%param"  */
@@ -1085,35 +1087,35 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-#line 1089 "src/parse-gram.c" /* yacc.c:684  */
+#line 1091 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 65: /* code_props_type  */
 #line 410 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1095 "src/parse-gram.c" /* yacc.c:684  */
+#line 1097 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 74: /* symbol.prec  */
 #line 205 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1101 "src/parse-gram.c" /* yacc.c:684  */
+#line 1103 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 78: /* tag  */
 #line 197 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1107 "src/parse-gram.c" /* yacc.c:684  */
+#line 1109 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 88: /* variable  */
 #line 193 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1113 "src/parse-gram.c" /* yacc.c:684  */
+#line 1115 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 89: /* value  */
-#line 656 "src/parse-gram.y" /* yacc.c:684  */
+#line 658 "src/parse-gram.y" /* yacc.c:684  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1122,31 +1124,31 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1126 "src/parse-gram.c" /* yacc.c:684  */
+#line 1128 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 90: /* id  */
 #line 205 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1132 "src/parse-gram.c" /* yacc.c:684  */
+#line 1134 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 91: /* id_colon  */
 #line 206 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1138 "src/parse-gram.c" /* yacc.c:684  */
+#line 1140 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 92: /* symbol  */
 #line 205 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1144 "src/parse-gram.c" /* yacc.c:684  */
+#line 1146 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 93: /* string_as_id  */
 #line 205 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1150 "src/parse-gram.c" /* yacc.c:684  */
+#line 1152 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
 
@@ -1848,7 +1850,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1852 "src/parse-gram.c" /* yacc.c:1429  */
+#line 1854 "src/parse-gram.c" /* yacc.c:1429  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2048,7 +2050,7 @@ yyreduce:
                         translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2052 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2054 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 7:
@@ -2056,7 +2058,7 @@ yyreduce:
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2060 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2062 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 8:
@@ -2065,13 +2067,13 @@ yyreduce:
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2069 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2071 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 9:
 #line 294 "src/parse-gram.y" /* yacc.c:1646  */
     { defines_flag = true; }
-#line 2075 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2077 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 10:
@@ -2080,7 +2082,7 @@ yyreduce:
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].code));
     }
-#line 2084 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2086 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 11:
@@ -2090,25 +2092,25 @@ yyreduce:
                                     "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2094 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2096 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 12:
 #line 306 "src/parse-gram.y" /* yacc.c:1646  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2100 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2102 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 13:
 #line 307 "src/parse-gram.y" /* yacc.c:1646  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2106 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2108 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 14:
 #line 308 "src/parse-gram.y" /* yacc.c:1646  */
     { spec_file_prefix = (yyvsp[0].code); }
-#line 2112 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2114 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 15:
@@ -2117,7 +2119,7 @@ yyreduce:
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2121 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2123 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 16:
@@ -2126,55 +2128,55 @@ yyreduce:
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].code), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2130 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2132 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 17:
 #line 319 "src/parse-gram.y" /* yacc.c:1646  */
     { language_argmatch ((yyvsp[0].code), grammar_prio, (yylsp[-1])); }
-#line 2136 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2138 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 18:
 #line 320 "src/parse-gram.y" /* yacc.c:1646  */
     { spec_name_prefix = (yyvsp[0].code); }
-#line 2142 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2144 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 19:
 #line 321 "src/parse-gram.y" /* yacc.c:1646  */
     { no_lines_flag = true; }
-#line 2148 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2150 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 20:
 #line 322 "src/parse-gram.y" /* yacc.c:1646  */
     { nondeterministic_parser = true; }
-#line 2154 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2156 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 21:
 #line 323 "src/parse-gram.y" /* yacc.c:1646  */
     { spec_outfile = (yyvsp[0].code); }
-#line 2160 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2162 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 22:
 #line 324 "src/parse-gram.y" /* yacc.c:1646  */
     { current_param = (yyvsp[0].param); }
-#line 2166 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2168 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 23:
 #line 324 "src/parse-gram.y" /* yacc.c:1646  */
     { current_param = param_none; }
-#line 2172 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2174 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 24:
 #line 325 "src/parse-gram.y" /* yacc.c:1646  */
     { version_check (&(yylsp[0]), (yyvsp[0].code)); }
-#line 2178 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2180 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 25:
@@ -2202,37 +2204,37 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2206 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2208 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 26:
 #line 350 "src/parse-gram.y" /* yacc.c:1646  */
     { token_table_flag = true; }
-#line 2212 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2214 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 27:
 #line 351 "src/parse-gram.y" /* yacc.c:1646  */
     { report_flag |= report_states; }
-#line 2218 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2220 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 28:
 #line 352 "src/parse-gram.y" /* yacc.c:1646  */
     { yacc_flag = true; }
-#line 2224 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2226 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 30:
 #line 357 "src/parse-gram.y" /* yacc.c:1646  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2230 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2232 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 31:
 #line 358 "src/parse-gram.y" /* yacc.c:1646  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2236 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2238 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 34:
@@ -2240,7 +2242,7 @@ yyreduce:
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2244 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2246 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 35:
@@ -2256,7 +2258,7 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2260 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2262 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 36:
@@ -2264,7 +2266,7 @@ yyreduce:
     {
       default_prec = true;
     }
-#line 2268 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2270 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 37:
@@ -2272,7 +2274,7 @@ yyreduce:
     {
       default_prec = false;
     }
-#line 2276 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2278 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 38:
@@ -2284,7 +2286,7 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2288 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2290 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 39:
@@ -2293,75 +2295,77 @@ yyreduce:
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2297 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2299 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 40:
 #line 412 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.code_type) = destructor; }
-#line 2303 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2305 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 41:
 #line 413 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.code_type) = printer; }
-#line 2309 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2311 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 42:
 #line 423 "src/parse-gram.y" /* yacc.c:1646  */
     {}
-#line 2315 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2317 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 43:
 #line 424 "src/parse-gram.y" /* yacc.c:1646  */
-    { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2321 "src/parse-gram.c" /* yacc.c:1646  */
+    { muscle_percent_define_insert ("api.value.union.name",
+                                         (yylsp[0]), muscle_keyword, (yyvsp[0].uniqstr),
+                                         MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
+#line 2325 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 44:
-#line 429 "src/parse-gram.y" /* yacc.c:1646  */
+#line 431 "src/parse-gram.y" /* yacc.c:1646  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2331 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2335 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 45:
-#line 440 "src/parse-gram.y" /* yacc.c:1646  */
+#line 442 "src/parse-gram.y" /* yacc.c:1646  */
     { current_class = nterm_sym; }
-#line 2337 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2341 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 46:
-#line 441 "src/parse-gram.y" /* yacc.c:1646  */
+#line 443 "src/parse-gram.y" /* yacc.c:1646  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2346 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2350 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 47:
-#line 445 "src/parse-gram.y" /* yacc.c:1646  */
+#line 447 "src/parse-gram.y" /* yacc.c:1646  */
     { current_class = token_sym; }
-#line 2352 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2356 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 48:
-#line 446 "src/parse-gram.y" /* yacc.c:1646  */
+#line 448 "src/parse-gram.y" /* yacc.c:1646  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2361 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2365 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 49:
-#line 451 "src/parse-gram.y" /* yacc.c:1646  */
+#line 453 "src/parse-gram.y" /* yacc.c:1646  */
     {
       symbol_list *list;
       tag_seen = true;
@@ -2369,11 +2373,11 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2373 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2377 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 50:
-#line 462 "src/parse-gram.y" /* yacc.c:1646  */
+#line 464 "src/parse-gram.y" /* yacc.c:1646  */
     {
       symbol_list *list;
       ++current_prec;
@@ -2385,341 +2389,341 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2389 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2393 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 51:
-#line 476 "src/parse-gram.y" /* yacc.c:1646  */
+#line 478 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.assoc) = left_assoc; }
-#line 2395 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2399 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 52:
-#line 477 "src/parse-gram.y" /* yacc.c:1646  */
+#line 479 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.assoc) = right_assoc; }
-#line 2401 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2405 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 53:
-#line 478 "src/parse-gram.y" /* yacc.c:1646  */
+#line 480 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.assoc) = non_assoc; }
-#line 2407 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2411 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 54:
-#line 479 "src/parse-gram.y" /* yacc.c:1646  */
+#line 481 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2413 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2417 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 55:
-#line 483 "src/parse-gram.y" /* yacc.c:1646  */
+#line 485 "src/parse-gram.y" /* yacc.c:1646  */
     { current_type = NULL; }
-#line 2419 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2423 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 56:
-#line 484 "src/parse-gram.y" /* yacc.c:1646  */
+#line 486 "src/parse-gram.y" /* yacc.c:1646  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2425 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2429 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 57:
-#line 490 "src/parse-gram.y" /* yacc.c:1646  */
+#line 492 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2431 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2435 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 58:
-#line 492 "src/parse-gram.y" /* yacc.c:1646  */
+#line 494 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2437 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2441 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 59:
-#line 497 "src/parse-gram.y" /* yacc.c:1646  */
+#line 499 "src/parse-gram.y" /* yacc.c:1646  */
     {
       (yyval.symbol) = (yyvsp[0].symbol);
       symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2446 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2450 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 60:
-#line 502 "src/parse-gram.y" /* yacc.c:1646  */
+#line 504 "src/parse-gram.y" /* yacc.c:1646  */
     {
       (yyval.symbol) = (yyvsp[-1].symbol);
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
     }
-#line 2456 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2460 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 61:
-#line 512 "src/parse-gram.y" /* yacc.c:1646  */
+#line 514 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2462 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2466 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 62:
-#line 514 "src/parse-gram.y" /* yacc.c:1646  */
+#line 516 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2468 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2472 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 63:
-#line 518 "src/parse-gram.y" /* yacc.c:1646  */
+#line 520 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2474 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2478 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 64:
-#line 519 "src/parse-gram.y" /* yacc.c:1646  */
+#line 521 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2480 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2484 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 65:
-#line 523 "src/parse-gram.y" /* yacc.c:1646  */
+#line 525 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2486 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2490 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 66:
-#line 524 "src/parse-gram.y" /* yacc.c:1646  */
+#line 526 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2492 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2496 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 68:
-#line 529 "src/parse-gram.y" /* yacc.c:1646  */
+#line 531 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2498 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2502 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 69:
-#line 530 "src/parse-gram.y" /* yacc.c:1646  */
+#line 532 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2504 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2508 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 70:
-#line 536 "src/parse-gram.y" /* yacc.c:1646  */
+#line 538 "src/parse-gram.y" /* yacc.c:1646  */
     {
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2513 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2517 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 71:
-#line 541 "src/parse-gram.y" /* yacc.c:1646  */
+#line 543 "src/parse-gram.y" /* yacc.c:1646  */
     {
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2522 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2526 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 72:
-#line 546 "src/parse-gram.y" /* yacc.c:1646  */
+#line 548 "src/parse-gram.y" /* yacc.c:1646  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2532 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2536 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 73:
-#line 552 "src/parse-gram.y" /* yacc.c:1646  */
+#line 554 "src/parse-gram.y" /* yacc.c:1646  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2542 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2546 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 74:
-#line 558 "src/parse-gram.y" /* yacc.c:1646  */
+#line 560 "src/parse-gram.y" /* yacc.c:1646  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2553 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2557 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 81:
-#line 588 "src/parse-gram.y" /* yacc.c:1646  */
+#line 590 "src/parse-gram.y" /* yacc.c:1646  */
     {
       yyerrok;
     }
-#line 2561 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2565 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 82:
-#line 594 "src/parse-gram.y" /* yacc.c:1646  */
+#line 596 "src/parse-gram.y" /* yacc.c:1646  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2567 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2571 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 83:
-#line 595 "src/parse-gram.y" /* yacc.c:1646  */
+#line 597 "src/parse-gram.y" /* yacc.c:1646  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2576 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2580 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 84:
-#line 602 "src/parse-gram.y" /* yacc.c:1646  */
+#line 604 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2582 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2586 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 85:
-#line 603 "src/parse-gram.y" /* yacc.c:1646  */
+#line 605 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2588 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2592 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 87:
-#line 610 "src/parse-gram.y" /* yacc.c:1646  */
+#line 612 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2595 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2599 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 88:
-#line 613 "src/parse-gram.y" /* yacc.c:1646  */
+#line 615 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2601 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2605 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 89:
-#line 615 "src/parse-gram.y" /* yacc.c:1646  */
+#line 617 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-#line 2607 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2611 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 90:
-#line 617 "src/parse-gram.y" /* yacc.c:1646  */
+#line 619 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-#line 2613 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2617 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 91:
-#line 619 "src/parse-gram.y" /* yacc.c:1646  */
+#line 621 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2619 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2623 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 92:
-#line 621 "src/parse-gram.y" /* yacc.c:1646  */
+#line 623 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2625 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2629 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 93:
-#line 623 "src/parse-gram.y" /* yacc.c:1646  */
+#line 625 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2631 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2635 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 94:
-#line 625 "src/parse-gram.y" /* yacc.c:1646  */
+#line 627 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2637 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2641 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 95:
-#line 629 "src/parse-gram.y" /* yacc.c:1646  */
+#line 631 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.named_ref) = 0; }
-#line 2643 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2647 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 96:
-#line 630 "src/parse-gram.y" /* yacc.c:1646  */
+#line 632 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.named_ref) = named_ref_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2649 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2653 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 98:
-#line 641 "src/parse-gram.y" /* yacc.c:1646  */
+#line 643 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].code)); }
-#line 2655 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2659 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 99:
-#line 666 "src/parse-gram.y" /* yacc.c:1646  */
+#line 668 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2661 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2665 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 100:
-#line 667 "src/parse-gram.y" /* yacc.c:1646  */
+#line 669 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].uniqstr); }
-#line 2667 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2671 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 101:
-#line 668 "src/parse-gram.y" /* yacc.c:1646  */
+#line 670 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].code); }
-#line 2673 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2677 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 102:
-#line 669 "src/parse-gram.y" /* yacc.c:1646  */
+#line 671 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].code)); }
-#line 2679 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2683 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 103:
-#line 682 "src/parse-gram.y" /* yacc.c:1646  */
+#line 684 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2685 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2689 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 104:
-#line 684 "src/parse-gram.y" /* yacc.c:1646  */
+#line 686 "src/parse-gram.y" /* yacc.c:1646  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2695 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2699 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 105:
-#line 692 "src/parse-gram.y" /* yacc.c:1646  */
+#line 694 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2701 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2705 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 108:
-#line 704 "src/parse-gram.y" /* yacc.c:1646  */
+#line 706 "src/parse-gram.y" /* yacc.c:1646  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].code)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2710 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2714 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 110:
-#line 713 "src/parse-gram.y" /* yacc.c:1646  */
+#line 715 "src/parse-gram.y" /* yacc.c:1646  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2719 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2723 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
 
-#line 2723 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2727 "src/parse-gram.c" /* yacc.c:1646  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2966,7 +2970,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 719 "src/parse-gram.y" /* yacc.c:1906  */
+#line 721 "src/parse-gram.y" /* yacc.c:1906  */
 
 
 /* Return the location of the left-hand side of a rule whose
