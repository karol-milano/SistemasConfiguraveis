@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.0.5.60-37fce.  */
+/* A Bison parser, made by GNU Bison 3.0.5.75-d835.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.0.5.60-37fce"
+#define YYBISON_VERSION "3.0.5.75-d835"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -129,7 +129,7 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 647 "src/parse-gram.y" /* yacc.c:355  */
+#line 644 "src/parse-gram.y" /* yacc.c:355  */
 #include "muscle-tab.h"
 
 #line 136 "src/parse-gram.c" /* yacc.c:355  */
@@ -221,9 +221,9 @@ symbol_list *list;
 named_ref *named_ref;
 #line 241 "src/parse-gram.y" /* yacc.c:355  */
 param_type param;
-#line 409 "src/parse-gram.y" /* yacc.c:355  */
+#line 408 "src/parse-gram.y" /* yacc.c:355  */
 code_props_type code_type;
-#line 649 "src/parse-gram.y" /* yacc.c:355  */
+#line 646 "src/parse-gram.y" /* yacc.c:355  */
 
   struct
   {
@@ -622,15 +622,15 @@ static const yytype_uint16 yyrline[] =
        0,   264,   264,   273,   274,   278,   279,   285,   289,   294,
      295,   300,   306,   307,   308,   309,   314,   319,   320,   321,
      322,   323,   324,   324,   325,   326,   350,   351,   352,   353,
-     357,   358,   367,   368,   369,   373,   385,   389,   393,   401,
-     412,   413,   423,   424,   430,   442,   442,   447,   447,   452,
-     463,   478,   479,   480,   481,   485,   486,   491,   493,   498,
-     503,   513,   515,   520,   521,   525,   526,   530,   531,   532,
-     537,   542,   547,   553,   559,   570,   571,   580,   581,   587,
-     588,   589,   596,   596,   604,   605,   606,   611,   614,   616,
-     618,   620,   622,   624,   626,   631,   632,   642,   643,   668,
-     669,   670,   671,   683,   685,   694,   699,   700,   705,   713,
-     714
+     357,   358,   367,   368,   369,   373,   384,   388,   392,   400,
+     411,   412,   422,   423,   429,   441,   441,   446,   446,   451,
+     461,   475,   476,   477,   478,   482,   483,   488,   490,   495,
+     500,   510,   512,   517,   518,   522,   523,   527,   528,   529,
+     534,   539,   544,   550,   556,   567,   568,   577,   578,   584,
+     585,   586,   593,   593,   601,   602,   603,   608,   611,   613,
+     615,   617,   619,   621,   623,   628,   629,   639,   640,   665,
+     666,   667,   668,   680,   682,   691,   696,   697,   702,   710,
+     711
 };
 #endif
 
@@ -1091,7 +1091,7 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
         break;
 
     case 65: /* code_props_type  */
-#line 410 "src/parse-gram.y" /* yacc.c:684  */
+#line 409 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
 #line 1097 "src/parse-gram.c" /* yacc.c:684  */
         break;
@@ -1115,7 +1115,7 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
         break;
 
     case 89: /* value  */
-#line 658 "src/parse-gram.y" /* yacc.c:684  */
+#line 655 "src/parse-gram.y" /* yacc.c:684  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1843,7 +1843,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 108 "src/parse-gram.y" /* yacc.c:1430  */
+#line 108 "src/parse-gram.y" /* yacc.c:1433  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1851,7 +1851,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1855 "src/parse-gram.c" /* yacc.c:1430  */
+#line 1855 "src/parse-gram.c" /* yacc.c:1433  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2046,143 +2046,143 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-#line 280 "src/parse-gram.y" /* yacc.c:1648  */
+#line 280 "src/parse-gram.y" /* yacc.c:1651  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2056 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2056 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 7:
-#line 286 "src/parse-gram.y" /* yacc.c:1648  */
+#line 286 "src/parse-gram.y" /* yacc.c:1651  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2064 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2064 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 8:
-#line 290 "src/parse-gram.y" /* yacc.c:1648  */
+#line 290 "src/parse-gram.y" /* yacc.c:1651  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2073 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2073 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 9:
-#line 294 "src/parse-gram.y" /* yacc.c:1648  */
+#line 294 "src/parse-gram.y" /* yacc.c:1651  */
     { defines_flag = true; }
-#line 2079 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2079 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 10:
-#line 296 "src/parse-gram.y" /* yacc.c:1648  */
+#line 296 "src/parse-gram.y" /* yacc.c:1651  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].code));
     }
-#line 2088 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2088 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 11:
-#line 301 "src/parse-gram.y" /* yacc.c:1648  */
+#line 301 "src/parse-gram.y" /* yacc.c:1651  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), muscle_keyword,
                                     "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2098 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2098 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 12:
-#line 306 "src/parse-gram.y" /* yacc.c:1648  */
+#line 306 "src/parse-gram.y" /* yacc.c:1651  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2104 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2104 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 13:
-#line 307 "src/parse-gram.y" /* yacc.c:1648  */
+#line 307 "src/parse-gram.y" /* yacc.c:1651  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2110 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2110 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 14:
-#line 308 "src/parse-gram.y" /* yacc.c:1648  */
+#line 308 "src/parse-gram.y" /* yacc.c:1651  */
     { spec_file_prefix = (yyvsp[0].code); }
-#line 2116 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2116 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 15:
-#line 310 "src/parse-gram.y" /* yacc.c:1648  */
+#line 310 "src/parse-gram.y" /* yacc.c:1651  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2125 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2125 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 16:
-#line 315 "src/parse-gram.y" /* yacc.c:1648  */
+#line 315 "src/parse-gram.y" /* yacc.c:1651  */
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].code), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2134 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2134 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 17:
-#line 319 "src/parse-gram.y" /* yacc.c:1648  */
+#line 319 "src/parse-gram.y" /* yacc.c:1651  */
     { language_argmatch ((yyvsp[0].code), grammar_prio, (yylsp[-1])); }
-#line 2140 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2140 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 18:
-#line 320 "src/parse-gram.y" /* yacc.c:1648  */
+#line 320 "src/parse-gram.y" /* yacc.c:1651  */
     { spec_name_prefix = (yyvsp[0].code); }
-#line 2146 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2146 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 19:
-#line 321 "src/parse-gram.y" /* yacc.c:1648  */
+#line 321 "src/parse-gram.y" /* yacc.c:1651  */
     { no_lines_flag = true; }
-#line 2152 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2152 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 20:
-#line 322 "src/parse-gram.y" /* yacc.c:1648  */
+#line 322 "src/parse-gram.y" /* yacc.c:1651  */
     { nondeterministic_parser = true; }
-#line 2158 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2158 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 21:
-#line 323 "src/parse-gram.y" /* yacc.c:1648  */
+#line 323 "src/parse-gram.y" /* yacc.c:1651  */
     { spec_outfile = (yyvsp[0].code); }
-#line 2164 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2164 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 22:
-#line 324 "src/parse-gram.y" /* yacc.c:1648  */
+#line 324 "src/parse-gram.y" /* yacc.c:1651  */
     { current_param = (yyvsp[0].param); }
-#line 2170 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2170 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 23:
-#line 324 "src/parse-gram.y" /* yacc.c:1648  */
+#line 324 "src/parse-gram.y" /* yacc.c:1651  */
     { current_param = param_none; }
-#line 2176 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2176 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 24:
-#line 325 "src/parse-gram.y" /* yacc.c:1648  */
+#line 325 "src/parse-gram.y" /* yacc.c:1651  */
     { version_check (&(yylsp[0]), (yyvsp[0].code)); }
-#line 2182 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2182 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 25:
-#line 327 "src/parse-gram.y" /* yacc.c:1648  */
+#line 327 "src/parse-gram.y" /* yacc.c:1651  */
     {
       char const *skeleton_user = (yyvsp[0].code);
       if (strchr (skeleton_user, '/'))
@@ -2206,81 +2206,80 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2210 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2210 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 26:
-#line 350 "src/parse-gram.y" /* yacc.c:1648  */
+#line 350 "src/parse-gram.y" /* yacc.c:1651  */
     { token_table_flag = true; }
-#line 2216 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2216 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 27:
-#line 351 "src/parse-gram.y" /* yacc.c:1648  */
+#line 351 "src/parse-gram.y" /* yacc.c:1651  */
     { report_flag |= report_states; }
-#line 2222 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2222 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 28:
-#line 352 "src/parse-gram.y" /* yacc.c:1648  */
+#line 352 "src/parse-gram.y" /* yacc.c:1651  */
     { yacc_flag = true; }
-#line 2228 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2228 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 30:
-#line 357 "src/parse-gram.y" /* yacc.c:1648  */
+#line 357 "src/parse-gram.y" /* yacc.c:1651  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2234 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2234 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 31:
-#line 358 "src/parse-gram.y" /* yacc.c:1648  */
+#line 358 "src/parse-gram.y" /* yacc.c:1651  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2240 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2240 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 34:
-#line 370 "src/parse-gram.y" /* yacc.c:1648  */
+#line 370 "src/parse-gram.y" /* yacc.c:1651  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2248 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2248 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 35:
-#line 374 "src/parse-gram.y" /* yacc.c:1648  */
+#line 374 "src/parse-gram.y" /* yacc.c:1651  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
       code_props_translate_code (&code);
       {
-        symbol_list *list;
-        for (list = (yyvsp[0].list); list; list = list->next)
+        for (symbol_list *list = (yyvsp[0].list); list; list = list->next)
           symbol_list_code_props_set (list, (yyvsp[-2].code_type), &code);
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2264 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2263 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 36:
-#line 386 "src/parse-gram.y" /* yacc.c:1648  */
+#line 385 "src/parse-gram.y" /* yacc.c:1651  */
     {
       default_prec = true;
     }
-#line 2272 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2271 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 37:
-#line 390 "src/parse-gram.y" /* yacc.c:1648  */
+#line 389 "src/parse-gram.y" /* yacc.c:1651  */
     {
       default_prec = false;
     }
-#line 2280 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2279 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 38:
-#line 394 "src/parse-gram.y" /* yacc.c:1648  */
+#line 393 "src/parse-gram.y" /* yacc.c:1651  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2288,102 +2287,100 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2292 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2291 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 39:
-#line 402 "src/parse-gram.y" /* yacc.c:1648  */
+#line 401 "src/parse-gram.y" /* yacc.c:1651  */
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2301 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2300 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 40:
-#line 412 "src/parse-gram.y" /* yacc.c:1648  */
+#line 411 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.code_type) = destructor; }
-#line 2307 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2306 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 41:
-#line 413 "src/parse-gram.y" /* yacc.c:1648  */
+#line 412 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.code_type) = printer; }
-#line 2313 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2312 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 42:
-#line 423 "src/parse-gram.y" /* yacc.c:1648  */
+#line 422 "src/parse-gram.y" /* yacc.c:1651  */
     {}
-#line 2319 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2318 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 43:
-#line 424 "src/parse-gram.y" /* yacc.c:1648  */
+#line 423 "src/parse-gram.y" /* yacc.c:1651  */
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].uniqstr),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2327 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2326 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 44:
-#line 431 "src/parse-gram.y" /* yacc.c:1648  */
+#line 430 "src/parse-gram.y" /* yacc.c:1651  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2337 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2336 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 45:
-#line 442 "src/parse-gram.y" /* yacc.c:1648  */
+#line 441 "src/parse-gram.y" /* yacc.c:1651  */
     { current_class = nterm_sym; }
-#line 2343 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2342 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 46:
-#line 443 "src/parse-gram.y" /* yacc.c:1648  */
+#line 442 "src/parse-gram.y" /* yacc.c:1651  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2352 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2351 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 47:
-#line 447 "src/parse-gram.y" /* yacc.c:1648  */
+#line 446 "src/parse-gram.y" /* yacc.c:1651  */
     { current_class = token_sym; }
-#line 2358 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2357 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 48:
-#line 448 "src/parse-gram.y" /* yacc.c:1648  */
+#line 447 "src/parse-gram.y" /* yacc.c:1651  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2367 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2366 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 49:
-#line 453 "src/parse-gram.y" /* yacc.c:1648  */
+#line 452 "src/parse-gram.y" /* yacc.c:1651  */
     {
-      symbol_list *list;
       tag_seen = true;
-      for (list = (yyvsp[0].list); list; list = list->next)
+      for (symbol_list *list = (yyvsp[0].list); list; list = list->next)
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2379 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2377 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 50:
-#line 464 "src/parse-gram.y" /* yacc.c:1648  */
+#line 462 "src/parse-gram.y" /* yacc.c:1651  */
     {
-      symbol_list *list;
       ++current_prec;
-      for (list = (yyvsp[0].list); list; list = list->next)
+      for (symbol_list *list = (yyvsp[0].list); list; list = list->next)
         {
           symbol_type_set (list->content.sym, current_type, (yylsp[-1]));
           symbol_precedence_set (list->content.sym, current_prec, (yyvsp[-2].assoc), (yylsp[-2]));
@@ -2391,341 +2388,341 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2395 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2392 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 51:
-#line 478 "src/parse-gram.y" /* yacc.c:1648  */
+#line 475 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.assoc) = left_assoc; }
-#line 2401 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2398 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 52:
-#line 479 "src/parse-gram.y" /* yacc.c:1648  */
+#line 476 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.assoc) = right_assoc; }
-#line 2407 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2404 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 53:
-#line 480 "src/parse-gram.y" /* yacc.c:1648  */
+#line 477 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.assoc) = non_assoc; }
-#line 2413 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2410 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 54:
-#line 481 "src/parse-gram.y" /* yacc.c:1648  */
+#line 478 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2419 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2416 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 55:
-#line 485 "src/parse-gram.y" /* yacc.c:1648  */
+#line 482 "src/parse-gram.y" /* yacc.c:1651  */
     { current_type = NULL; }
-#line 2425 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2422 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 56:
-#line 486 "src/parse-gram.y" /* yacc.c:1648  */
+#line 483 "src/parse-gram.y" /* yacc.c:1651  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2431 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2428 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 57:
-#line 492 "src/parse-gram.y" /* yacc.c:1648  */
+#line 489 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2437 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2434 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 58:
-#line 494 "src/parse-gram.y" /* yacc.c:1648  */
+#line 491 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2443 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2440 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 59:
-#line 499 "src/parse-gram.y" /* yacc.c:1648  */
+#line 496 "src/parse-gram.y" /* yacc.c:1651  */
     {
       (yyval.symbol) = (yyvsp[0].symbol);
       symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2452 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2449 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 60:
-#line 504 "src/parse-gram.y" /* yacc.c:1648  */
+#line 501 "src/parse-gram.y" /* yacc.c:1651  */
     {
       (yyval.symbol) = (yyvsp[-1].symbol);
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
     }
-#line 2462 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2459 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 61:
-#line 514 "src/parse-gram.y" /* yacc.c:1648  */
+#line 511 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2468 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2465 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 62:
-#line 516 "src/parse-gram.y" /* yacc.c:1648  */
+#line 513 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2474 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2471 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 63:
-#line 520 "src/parse-gram.y" /* yacc.c:1648  */
+#line 517 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2480 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2477 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 64:
-#line 521 "src/parse-gram.y" /* yacc.c:1648  */
+#line 518 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2486 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2483 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 65:
-#line 525 "src/parse-gram.y" /* yacc.c:1648  */
+#line 522 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2492 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2489 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 66:
-#line 526 "src/parse-gram.y" /* yacc.c:1648  */
+#line 523 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2498 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2495 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 68:
-#line 531 "src/parse-gram.y" /* yacc.c:1648  */
+#line 528 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2504 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2501 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 69:
-#line 532 "src/parse-gram.y" /* yacc.c:1648  */
+#line 529 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2510 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2507 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 70:
-#line 538 "src/parse-gram.y" /* yacc.c:1648  */
+#line 535 "src/parse-gram.y" /* yacc.c:1651  */
     {
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2519 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2516 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 71:
-#line 543 "src/parse-gram.y" /* yacc.c:1648  */
+#line 540 "src/parse-gram.y" /* yacc.c:1651  */
     {
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2528 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2525 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 72:
-#line 548 "src/parse-gram.y" /* yacc.c:1648  */
+#line 545 "src/parse-gram.y" /* yacc.c:1651  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2538 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2535 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 73:
-#line 554 "src/parse-gram.y" /* yacc.c:1648  */
+#line 551 "src/parse-gram.y" /* yacc.c:1651  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2548 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2545 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 74:
-#line 560 "src/parse-gram.y" /* yacc.c:1648  */
+#line 557 "src/parse-gram.y" /* yacc.c:1651  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2559 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2556 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 81:
-#line 590 "src/parse-gram.y" /* yacc.c:1648  */
+#line 587 "src/parse-gram.y" /* yacc.c:1651  */
     {
       yyerrok;
     }
-#line 2567 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2564 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 82:
-#line 596 "src/parse-gram.y" /* yacc.c:1648  */
+#line 593 "src/parse-gram.y" /* yacc.c:1651  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2573 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2570 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 83:
-#line 597 "src/parse-gram.y" /* yacc.c:1648  */
+#line 594 "src/parse-gram.y" /* yacc.c:1651  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2582 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2579 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 84:
-#line 604 "src/parse-gram.y" /* yacc.c:1648  */
+#line 601 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2588 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2585 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 85:
-#line 605 "src/parse-gram.y" /* yacc.c:1648  */
+#line 602 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2594 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2591 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 87:
-#line 612 "src/parse-gram.y" /* yacc.c:1648  */
+#line 609 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2601 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2598 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 88:
-#line 615 "src/parse-gram.y" /* yacc.c:1648  */
+#line 612 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2607 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2604 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 89:
-#line 617 "src/parse-gram.y" /* yacc.c:1648  */
+#line 614 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), current_type); }
-#line 2613 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2610 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 90:
-#line 619 "src/parse-gram.y" /* yacc.c:1648  */
+#line 616 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_predicate_append ((yyvsp[0].code), (yylsp[0])); }
-#line 2619 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2616 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 91:
-#line 621 "src/parse-gram.y" /* yacc.c:1648  */
+#line 618 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2625 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2622 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 92:
-#line 623 "src/parse-gram.y" /* yacc.c:1648  */
+#line 620 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2631 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2628 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 93:
-#line 625 "src/parse-gram.y" /* yacc.c:1648  */
+#line 622 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2637 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2634 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 94:
-#line 627 "src/parse-gram.y" /* yacc.c:1648  */
+#line 624 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2643 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2640 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 95:
-#line 631 "src/parse-gram.y" /* yacc.c:1648  */
+#line 628 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.named_ref) = 0; }
-#line 2649 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2646 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 96:
-#line 632 "src/parse-gram.y" /* yacc.c:1648  */
+#line 629 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.named_ref) = named_ref_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2655 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2652 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 98:
-#line 643 "src/parse-gram.y" /* yacc.c:1648  */
+#line 640 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].code)); }
-#line 2661 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2658 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 99:
-#line 668 "src/parse-gram.y" /* yacc.c:1648  */
+#line 665 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2667 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2664 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 100:
-#line 669 "src/parse-gram.y" /* yacc.c:1648  */
+#line 666 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].uniqstr); }
-#line 2673 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2670 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 101:
-#line 670 "src/parse-gram.y" /* yacc.c:1648  */
+#line 667 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].code); }
-#line 2679 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2676 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 102:
-#line 671 "src/parse-gram.y" /* yacc.c:1648  */
+#line 668 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].code)); }
-#line 2685 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2682 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 103:
-#line 684 "src/parse-gram.y" /* yacc.c:1648  */
+#line 681 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2691 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2688 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 104:
-#line 686 "src/parse-gram.y" /* yacc.c:1648  */
+#line 683 "src/parse-gram.y" /* yacc.c:1651  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2701 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2698 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 105:
-#line 694 "src/parse-gram.y" /* yacc.c:1648  */
+#line 691 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2707 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2704 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 108:
-#line 706 "src/parse-gram.y" /* yacc.c:1648  */
+#line 703 "src/parse-gram.y" /* yacc.c:1651  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].code)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2716 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2713 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 110:
-#line 715 "src/parse-gram.y" /* yacc.c:1648  */
+#line 712 "src/parse-gram.y" /* yacc.c:1651  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2725 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2722 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
 
-#line 2729 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2726 "src/parse-gram.c" /* yacc.c:1651  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2971,7 +2968,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 721 "src/parse-gram.y" /* yacc.c:1907  */
+#line 718 "src/parse-gram.y" /* yacc.c:1910  */
 
 
 /* Return the location of the left-hand side of a rule whose
@@ -2982,7 +2979,6 @@ yyreturn:
 static YYLTYPE
 lloc_default (YYLTYPE const *rhs, int n)
 {
-  int i;
   YYLTYPE loc;
 
   /* SGI MIPSpro 7.4.1m miscompiles "loc.start = loc.end = rhs[n].end;".
@@ -2993,7 +2989,7 @@ lloc_default (YYLTYPE const *rhs, int n)
   /* Ignore empty nonterminals the start of the right-hand side.
      Do not bother to ignore them at the end of the right-hand side,
      since empty nonterminals have the same end as their predecessors.  */
-  for (i = 1; i <= n; i++)
+  for (int i = 1; i <= n; i++)
     if (! equal_boundaries (rhs[i].start, rhs[i].end))
       {
         loc.start = rhs[i].start;
