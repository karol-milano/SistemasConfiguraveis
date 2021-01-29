@@ -69,7 +69,7 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -146,7 +146,7 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 151 "parse-gram.c"
 
 /* Enabling traces.  */
@@ -295,7 +295,7 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 94 "parse-gram.y"
 
   symbol *symbol;
@@ -309,7 +309,7 @@ typedef union YYSTYPE
 
 
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 314 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -334,7 +334,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 339 "parse-gram.c"
 
 #ifdef short
@@ -661,15 +661,15 @@ static const yytype_uint16 yyrline[] =
 {
        0,   204,   204,   212,   214,   218,   219,   229,   230,   234,
      235,   240,   241,   242,   243,   244,   245,   250,   259,   260,
-     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
-     271,   295,   296,   297,   298,   302,   303,   304,   308,   315,
-     322,   326,   330,   337,   352,   353,   357,   369,   369,   374,
-     374,   379,   390,   405,   406,   407,   411,   412,   417,   419,
-     424,   425,   429,   430,   431,   432,   437,   442,   447,   453,
-     459,   470,   471,   480,   481,   487,   488,   489,   496,   496,
-     500,   501,   502,   507,   508,   510,   512,   514,   516,   526,
-     527,   533,   536,   545,   565,   567,   576,   581,   582,   587,
-     594,   596
+     261,   262,   263,   264,   265,   266,   267,   268,   269,   282,
+     283,   307,   308,   309,   310,   314,   315,   316,   320,   327,
+     334,   338,   342,   349,   364,   365,   369,   381,   381,   386,
+     386,   391,   402,   417,   418,   419,   423,   424,   429,   431,
+     436,   437,   441,   442,   443,   444,   449,   454,   459,   465,
+     471,   482,   483,   492,   493,   499,   500,   501,   508,   508,
+     512,   513,   514,   519,   520,   522,   524,   526,   528,   538,
+     539,   545,   548,   557,   577,   579,   588,   593,   594,   599,
+     606,   608
 };
 #endif
 
@@ -1020,146 +1020,146 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 182 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1029 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 193 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1038 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1047 "parse-gram.c"
 	break;
       case 44: /* "\"char\"" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 176 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1056 "parse-gram.c"
 	break;
       case 45: /* "\"epilogue\"" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1065 "parse-gram.c"
 	break;
       case 47: /* "\"identifier\"" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 189 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1074 "parse-gram.c"
 	break;
       case 48: /* "\"identifier:\"" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1083 "parse-gram.c"
 	break;
       case 51: /* "\"%{...%}\"" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1092 "parse-gram.c"
 	break;
       case 53: /* "\"type\"" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 188 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1101 "parse-gram.c"
 	break;
       case 80: /* "variable" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 189 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1110 "parse-gram.c"
 	break;
       case 81: /* "content.opt" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1119 "parse-gram.c"
 	break;
       case 82: /* "braceless" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1128 "parse-gram.c"
 	break;
       case 83: /* "id" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1137 "parse-gram.c"
 	break;
       case 84: /* "id_colon" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1146 "parse-gram.c"
 	break;
       case 85: /* "symbol" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1155 "parse-gram.c"
 	break;
       case 86: /* "string_as_id" */
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1164 "parse-gram.c"
 	break;
       default:
@@ -1674,7 +1674,7 @@ YYLTYPE yylloc;
 
   /* User initialization code.  */
   
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1683,7 +1683,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 1688 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
@@ -1869,7 +1869,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 220 "parse-gram.y"
     {
       code_props plain_code;
@@ -1884,14 +1884,14 @@ yyreduce:
 
   case 7:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 229 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 231 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars));
@@ -1900,14 +1900,14 @@ yyreduce:
 
   case 9:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 234 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 236 "parse-gram.y"
     {
       defines_flag = true;
@@ -1917,42 +1917,42 @@ yyreduce:
 
   case 11:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 240 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 241 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 242 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 243 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 244 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 246 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -1962,7 +1962,7 @@ yyreduce:
 
   case 17:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 251 "parse-gram.y"
     {
       code_props action;
@@ -1976,92 +1976,103 @@ yyreduce:
 
   case 18:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 259 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 260 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 261 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 262 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 263 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 264 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 265 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 266 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 267 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1538 of yacc.c  */
+/* Line 1542 of yacc.c  */
 #line 268 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1538 of yacc.c  */
-#line 269 "parse-gram.y"
-    { pure_parser = true; }
+/* Line 1542 of yacc.c  */
+#line 270 "parse-gram.y"
+    {
+      /* %pure-parser is deprecated in favor of `%define api.pure', so use
+         `%define api.pure' in a backward-compatible manner here.  First, don't
+         complain if %pure-parser is specified multiple times.  */
+      if (!muscle_find_const ("percent_define(api.pure)"))
+        muscle_percent_define_insert ("api.pure", (yylsp[(1) - (1)]), "");
+      /* In all cases, use api.pure now so that the backend doesn't complain if
+         the skeleton ignores api.pure, but do warn now if there's a previous
+         conflicting definition from an actual %define.  */
+      if (!muscle_percent_define_flag_if ("api.pure"))
+        muscle_percent_define_insert ("api.pure", (yylsp[(1) - (1)]), "");
+    }
     break;
 
   case 29:
 
-/* Line 1538 of yacc.c  */
-#line 270 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 282 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1538 of yacc.c  */
-#line 272 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 284 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (strchr (skeleton_user, '/'))
@@ -2089,29 +2100,29 @@ yyreduce:
 
   case 31:
 
-/* Line 1538 of yacc.c  */
-#line 295 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 307 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1538 of yacc.c  */
-#line 296 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 308 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 33:
 
-/* Line 1538 of yacc.c  */
-#line 297 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 309 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1538 of yacc.c  */
-#line 305 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 317 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2119,8 +2130,8 @@ yyreduce:
 
   case 38:
 
-/* Line 1538 of yacc.c  */
-#line 309 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 321 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2131,8 +2142,8 @@ yyreduce:
 
   case 39:
 
-/* Line 1538 of yacc.c  */
-#line 316 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 328 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2143,8 +2154,8 @@ yyreduce:
 
   case 40:
 
-/* Line 1538 of yacc.c  */
-#line 323 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 335 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2152,8 +2163,8 @@ yyreduce:
 
   case 41:
 
-/* Line 1538 of yacc.c  */
-#line 327 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 339 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2161,8 +2172,8 @@ yyreduce:
 
   case 42:
 
-/* Line 1538 of yacc.c  */
-#line 331 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 343 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2173,8 +2184,8 @@ yyreduce:
 
   case 43:
 
-/* Line 1538 of yacc.c  */
-#line 338 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 350 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
@@ -2183,22 +2194,22 @@ yyreduce:
 
   case 44:
 
-/* Line 1538 of yacc.c  */
-#line 352 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 364 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1538 of yacc.c  */
-#line 353 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 365 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1538 of yacc.c  */
-#line 358 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 370 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2208,15 +2219,15 @@ yyreduce:
 
   case 47:
 
-/* Line 1538 of yacc.c  */
-#line 369 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 381 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1538 of yacc.c  */
-#line 370 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 382 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2225,15 +2236,15 @@ yyreduce:
 
   case 49:
 
-/* Line 1538 of yacc.c  */
-#line 374 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 386 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1538 of yacc.c  */
-#line 375 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 387 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2242,8 +2253,8 @@ yyreduce:
 
   case 51:
 
-/* Line 1538 of yacc.c  */
-#line 380 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 392 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2255,8 +2266,8 @@ yyreduce:
 
   case 52:
 
-/* Line 1538 of yacc.c  */
-#line 391 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 403 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2272,99 +2283,99 @@ yyreduce:
 
   case 53:
 
-/* Line 1538 of yacc.c  */
-#line 405 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 417 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1538 of yacc.c  */
-#line 406 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 418 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1538 of yacc.c  */
-#line 407 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 419 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1538 of yacc.c  */
-#line 411 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 423 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1538 of yacc.c  */
-#line 412 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 424 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1538 of yacc.c  */
-#line 418 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1538 of yacc.c  */
-#line 420 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 432 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1538 of yacc.c  */
-#line 424 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 436 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 61:
 
-/* Line 1538 of yacc.c  */
-#line 425 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 437 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 62:
 
-/* Line 1538 of yacc.c  */
-#line 429 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 441 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1538 of yacc.c  */
-#line 430 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 442 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 64:
 
-/* Line 1538 of yacc.c  */
-#line 431 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 65:
 
-/* Line 1538 of yacc.c  */
-#line 432 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 444 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 66:
 
-/* Line 1538 of yacc.c  */
-#line 438 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 450 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2373,8 +2384,8 @@ yyreduce:
 
   case 67:
 
-/* Line 1538 of yacc.c  */
-#line 443 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 455 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2383,8 +2394,8 @@ yyreduce:
 
   case 68:
 
-/* Line 1538 of yacc.c  */
-#line 448 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 460 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2394,8 +2405,8 @@ yyreduce:
 
   case 69:
 
-/* Line 1538 of yacc.c  */
-#line 454 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 466 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2405,8 +2416,8 @@ yyreduce:
 
   case 70:
 
-/* Line 1538 of yacc.c  */
-#line 460 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 472 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2417,8 +2428,8 @@ yyreduce:
 
   case 77:
 
-/* Line 1538 of yacc.c  */
-#line 490 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 502 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2426,78 +2437,78 @@ yyreduce:
 
   case 78:
 
-/* Line 1538 of yacc.c  */
-#line 496 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 508 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 80:
 
-/* Line 1538 of yacc.c  */
-#line 500 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 512 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 81:
 
-/* Line 1538 of yacc.c  */
-#line 501 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 513 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 83:
 
-/* Line 1538 of yacc.c  */
-#line 507 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 519 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 84:
 
-/* Line 1538 of yacc.c  */
-#line 509 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 521 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 85:
 
-/* Line 1538 of yacc.c  */
-#line 511 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 523 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 86:
 
-/* Line 1538 of yacc.c  */
-#line 513 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 525 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1538 of yacc.c  */
-#line 515 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 527 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 88:
 
-/* Line 1538 of yacc.c  */
-#line 517 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 529 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 90:
 
-/* Line 1538 of yacc.c  */
-#line 527 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 539 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 91:
 
-/* Line 1538 of yacc.c  */
-#line 533 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 545 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
@@ -2505,8 +2516,8 @@ yyreduce:
 
   case 93:
 
-/* Line 1538 of yacc.c  */
-#line 546 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 558 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2519,15 +2530,15 @@ yyreduce:
 
   case 94:
 
-/* Line 1538 of yacc.c  */
-#line 566 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 578 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 95:
 
-/* Line 1538 of yacc.c  */
-#line 568 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 580 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2537,15 +2548,15 @@ yyreduce:
 
   case 96:
 
-/* Line 1538 of yacc.c  */
-#line 576 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 588 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 99:
 
-/* Line 1538 of yacc.c  */
-#line 588 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 600 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2554,8 +2565,8 @@ yyreduce:
 
   case 101:
 
-/* Line 1538 of yacc.c  */
-#line 597 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 609 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2568,8 +2579,8 @@ yyreduce:
 
 
 
-/* Line 1538 of yacc.c  */
-#line 2573 "parse-gram.c"
+/* Line 1542 of yacc.c  */
+#line 2584 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2787,8 +2798,8 @@ yyreturn:
 
 
 
-/* Line 1538 of yacc.c  */
-#line 607 "parse-gram.y"
+/* Line 1542 of yacc.c  */
+#line 619 "parse-gram.y"
 
 
 
