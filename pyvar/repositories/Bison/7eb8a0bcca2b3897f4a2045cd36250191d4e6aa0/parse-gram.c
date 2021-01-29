@@ -77,7 +77,7 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 171 of yacc.c  */
+/* Line 176 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -157,7 +157,7 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 171 of yacc.c  */
+/* Line 176 of yacc.c  */
 #line 162 "parse-gram.c"
 
 /* Enabling traces.  */
@@ -309,8 +309,8 @@ static int current_prec = 0;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 205 of yacc.c  */
-#line 98 "parse-gram.y"
+/* Line 210 of yacc.c  */
+#line 97 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -322,7 +322,7 @@ typedef union YYSTYPE
   unsigned char character;
 }
 
-/* Line 205 of yacc.c  */
+/* Line 210 of yacc.c  */
 #line 327 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -347,7 +347,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 228 of yacc.c  */
+/* Line 233 of yacc.c  */
 #line 352 "parse-gram.c"
 
 #ifdef short
@@ -673,17 +673,17 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   211,   211,   219,   221,   225,   226,   235,   236,   237,
-     238,   243,   244,   245,   246,   247,   248,   253,   262,   263,
-     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
-     274,   275,   276,   277,   278,   279,   280,   284,   285,   286,
-     290,   297,   304,   308,   312,   317,   344,   345,   349,   378,
-     378,   383,   383,   388,   399,   414,   415,   416,   420,   421,
-     426,   428,   433,   434,   438,   439,   440,   441,   446,   451,
-     456,   462,   468,   479,   480,   489,   490,   496,   497,   498,
-     505,   505,   509,   510,   511,   516,   517,   519,   521,   523,
-     525,   535,   536,   542,   546,   551,   571,   573,   582,   587,
-     588,   593,   600,   602
+       0,   210,   210,   218,   220,   224,   225,   234,   235,   244,
+     245,   250,   251,   252,   253,   254,   255,   260,   269,   270,
+     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
+     281,   282,   283,   284,   285,   286,   287,   291,   292,   293,
+     297,   304,   311,   315,   319,   324,   347,   348,   352,   381,
+     381,   386,   386,   391,   402,   417,   418,   419,   423,   424,
+     429,   431,   436,   437,   441,   442,   443,   444,   449,   454,
+     459,   465,   471,   482,   483,   492,   493,   499,   500,   501,
+     508,   508,   512,   513,   514,   519,   520,   522,   524,   526,
+     528,   538,   539,   545,   549,   554,   574,   576,   585,   590,
+     591,   596,   603,   605
 };
 #endif
 
@@ -1044,146 +1044,146 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 681 of yacc.c  */
-#line 189 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 188 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1053 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 681 of yacc.c  */
-#line 200 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1062 "parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
 
-/* Line 681 of yacc.c  */
-#line 191 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1071 "parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
 
-/* Line 681 of yacc.c  */
-#line 183 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 182 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1080 "parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
 
-/* Line 681 of yacc.c  */
-#line 191 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1089 "parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
 
-/* Line 681 of yacc.c  */
-#line 196 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 195 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1098 "parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
 
-/* Line 681 of yacc.c  */
-#line 197 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1107 "parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
 
-/* Line 681 of yacc.c  */
-#line 191 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1116 "parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
 
-/* Line 681 of yacc.c  */
-#line 195 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1125 "parse-gram.c"
 	break;
       case 82: /* "content" */
 
-/* Line 681 of yacc.c  */
-#line 191 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1134 "parse-gram.c"
 	break;
       case 83: /* "content.opt" */
 
-/* Line 681 of yacc.c  */
-#line 191 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1143 "parse-gram.c"
 	break;
       case 84: /* "braceless" */
 
-/* Line 681 of yacc.c  */
-#line 191 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1152 "parse-gram.c"
 	break;
       case 85: /* "id" */
 
-/* Line 681 of yacc.c  */
-#line 203 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1161 "parse-gram.c"
 	break;
       case 86: /* "id_colon" */
 
-/* Line 681 of yacc.c  */
-#line 204 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 203 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1170 "parse-gram.c"
 	break;
       case 87: /* "symbol" */
 
-/* Line 681 of yacc.c  */
-#line 203 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1179 "parse-gram.c"
 	break;
       case 88: /* "string_as_id" */
 
-/* Line 681 of yacc.c  */
-#line 203 "parse-gram.y"
+/* Line 686 of yacc.c  */
+#line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 681 of yacc.c  */
+/* Line 686 of yacc.c  */
 #line 1188 "parse-gram.c"
 	break;
       default:
@@ -1698,8 +1698,8 @@ YYLTYPE yylloc;
 
   /* User initialization code.  */
   
-/* Line 1093 of yacc.c  */
-#line 90 "parse-gram.y"
+/* Line 1098 of yacc.c  */
+#line 89 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1707,7 +1707,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1093 of yacc.c  */
+/* Line 1098 of yacc.c  */
 #line 1712 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
@@ -1893,8 +1893,8 @@ yyreduce:
     {
         case 6:
 
-/* Line 1280 of yacc.c  */
-#line 227 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 226 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
@@ -1907,29 +1907,36 @@ yyreduce:
 
   case 7:
 
-/* Line 1280 of yacc.c  */
-#line 235 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 234 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1280 of yacc.c  */
+/* Line 1285 of yacc.c  */
 #line 236 "parse-gram.y"
-    { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
+    {
+      /* FIXME: Special characters in $2 may break %define.
+         For example: `['.  */
+      if (muscle_find_const ((yyvsp[(2) - (3)].chars)))
+        warn_at ((yylsp[(2) - (3)]), _("%s: `%s' redefined"), "%define", (yyvsp[(2) - (3)].chars));
+      muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars));
+      muscle_grow_used_name_list ("used_percent_define_variables", (yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
+    }
     break;
 
   case 9:
 
-/* Line 1280 of yacc.c  */
-#line 237 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 244 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1280 of yacc.c  */
-#line 239 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 246 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1938,43 +1945,43 @@ yyreduce:
 
   case 11:
 
-/* Line 1280 of yacc.c  */
-#line 243 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 250 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1280 of yacc.c  */
-#line 244 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 251 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1280 of yacc.c  */
-#line 245 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 252 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1280 of yacc.c  */
-#line 246 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 253 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1280 of yacc.c  */
-#line 247 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 254 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1280 of yacc.c  */
-#line 249 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 256 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1983,8 +1990,8 @@ yyreduce:
 
   case 17:
 
-/* Line 1280 of yacc.c  */
-#line 254 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 261 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -1997,134 +2004,134 @@ yyreduce:
 
   case 18:
 
-/* Line 1280 of yacc.c  */
-#line 262 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 269 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1280 of yacc.c  */
-#line 263 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 270 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1280 of yacc.c  */
-#line 264 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 271 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1280 of yacc.c  */
-#line 265 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 272 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1280 of yacc.c  */
-#line 266 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 273 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1280 of yacc.c  */
-#line 267 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 274 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1280 of yacc.c  */
-#line 268 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 275 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1280 of yacc.c  */
-#line 269 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 276 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1280 of yacc.c  */
-#line 270 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 277 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1280 of yacc.c  */
-#line 271 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 278 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1280 of yacc.c  */
-#line 272 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 279 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 29:
 
-/* Line 1280 of yacc.c  */
-#line 273 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 280 "parse-gram.y"
     { push_parser = true; pull_parser = false; }
     break;
 
   case 30:
 
-/* Line 1280 of yacc.c  */
-#line 274 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 281 "parse-gram.y"
     { push_parser = true; pull_parser = true; }
     break;
 
   case 31:
 
-/* Line 1280 of yacc.c  */
-#line 275 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 282 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 32:
 
-/* Line 1280 of yacc.c  */
-#line 276 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 283 "parse-gram.y"
     { skeleton_arg ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 33:
 
-/* Line 1280 of yacc.c  */
-#line 277 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 284 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 34:
 
-/* Line 1280 of yacc.c  */
-#line 278 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 285 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 35:
 
-/* Line 1280 of yacc.c  */
-#line 279 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 286 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 39:
 
-/* Line 1280 of yacc.c  */
-#line 287 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 294 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2132,8 +2139,8 @@ yyreduce:
 
   case 40:
 
-/* Line 1280 of yacc.c  */
-#line 291 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 298 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2144,8 +2151,8 @@ yyreduce:
 
   case 41:
 
-/* Line 1280 of yacc.c  */
-#line 298 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 305 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2156,8 +2163,8 @@ yyreduce:
 
   case 42:
 
-/* Line 1280 of yacc.c  */
-#line 305 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 312 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2165,8 +2172,8 @@ yyreduce:
 
   case 43:
 
-/* Line 1280 of yacc.c  */
-#line 309 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 316 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2174,8 +2181,8 @@ yyreduce:
 
   case 44:
 
-/* Line 1280 of yacc.c  */
-#line 313 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 320 "parse-gram.y"
     {
       muscle_code_grow ("percent_code", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       code_scanner_last_string_free ();
@@ -2184,9 +2191,11 @@ yyreduce:
 
   case 45:
 
-/* Line 1280 of yacc.c  */
-#line 318 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 325 "parse-gram.y"
     {
+      /* FIXME: Special characters in $2 may break %code.
+         For example: `['.  */
       char const name_prefix[] = "percent_code_";
       char *name = xmalloc (sizeof name_prefix + strlen ((yyvsp[(2) - (3)].chars)));
       strcpy (name, name_prefix);
@@ -2194,34 +2203,28 @@ yyreduce:
       muscle_code_grow (uniqstr_new (name), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       free (name);
       code_scanner_last_string_free ();
-      muscle_grow ("used_percent_code_qualifiers", "[[[[", ",");
-      muscle_grow ("used_percent_code_qualifiers", (yyvsp[(2) - (3)].chars), "");
-      muscle_grow ("used_percent_code_qualifiers", "]], [[", "");
-      muscle_boundary_grow ("used_percent_code_qualifiers", (yylsp[(2) - (3)]).start);
-      muscle_grow ("used_percent_code_qualifiers", "]], [[", "");
-      muscle_boundary_grow ("used_percent_code_qualifiers", (yylsp[(2) - (3)]).end);
-      muscle_grow ("used_percent_code_qualifiers", "]]]]", "");
+      muscle_grow_used_name_list ("used_percent_code_qualifiers", (yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
     }
     break;
 
   case 46:
 
-/* Line 1280 of yacc.c  */
-#line 344 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 347 "parse-gram.y"
     {}
     break;
 
   case 47:
 
-/* Line 1280 of yacc.c  */
-#line 345 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 348 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 48:
 
-/* Line 1280 of yacc.c  */
-#line 350 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 353 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].code);
 
@@ -2248,15 +2251,15 @@ yyreduce:
 
   case 49:
 
-/* Line 1280 of yacc.c  */
-#line 378 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 381 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 50:
 
-/* Line 1280 of yacc.c  */
-#line 379 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 382 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2265,15 +2268,15 @@ yyreduce:
 
   case 51:
 
-/* Line 1280 of yacc.c  */
-#line 383 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 386 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 52:
 
-/* Line 1280 of yacc.c  */
-#line 384 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 387 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2282,8 +2285,8 @@ yyreduce:
 
   case 53:
 
-/* Line 1280 of yacc.c  */
-#line 389 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 392 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2295,8 +2298,8 @@ yyreduce:
 
   case 54:
 
-/* Line 1280 of yacc.c  */
-#line 400 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 403 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2312,99 +2315,99 @@ yyreduce:
 
   case 55:
 
-/* Line 1280 of yacc.c  */
-#line 414 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 417 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 56:
 
-/* Line 1280 of yacc.c  */
-#line 415 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 418 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 57:
 
-/* Line 1280 of yacc.c  */
-#line 416 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 419 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 58:
 
-/* Line 1280 of yacc.c  */
-#line 420 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 423 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 59:
 
-/* Line 1280 of yacc.c  */
-#line 421 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 424 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 60:
 
-/* Line 1280 of yacc.c  */
-#line 427 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 61:
 
-/* Line 1280 of yacc.c  */
-#line 429 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 432 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 62:
 
-/* Line 1280 of yacc.c  */
-#line 433 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 436 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 63:
 
-/* Line 1280 of yacc.c  */
-#line 434 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 437 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 64:
 
-/* Line 1280 of yacc.c  */
-#line 438 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 441 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 65:
 
-/* Line 1280 of yacc.c  */
-#line 439 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 442 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 66:
 
-/* Line 1280 of yacc.c  */
-#line 440 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1280 of yacc.c  */
-#line 441 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 444 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1280 of yacc.c  */
-#line 447 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 450 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2413,8 +2416,8 @@ yyreduce:
 
   case 69:
 
-/* Line 1280 of yacc.c  */
-#line 452 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 455 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2423,8 +2426,8 @@ yyreduce:
 
   case 70:
 
-/* Line 1280 of yacc.c  */
-#line 457 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 460 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2434,8 +2437,8 @@ yyreduce:
 
   case 71:
 
-/* Line 1280 of yacc.c  */
-#line 463 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 466 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2445,8 +2448,8 @@ yyreduce:
 
   case 72:
 
-/* Line 1280 of yacc.c  */
-#line 469 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 472 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2457,8 +2460,8 @@ yyreduce:
 
   case 79:
 
-/* Line 1280 of yacc.c  */
-#line 499 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 502 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2466,71 +2469,71 @@ yyreduce:
 
   case 80:
 
-/* Line 1280 of yacc.c  */
-#line 505 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 508 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 82:
 
-/* Line 1280 of yacc.c  */
-#line 509 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 512 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 83:
 
-/* Line 1280 of yacc.c  */
-#line 510 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 513 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 85:
 
-/* Line 1280 of yacc.c  */
-#line 516 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 519 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 86:
 
-/* Line 1280 of yacc.c  */
-#line 518 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 521 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 87:
 
-/* Line 1280 of yacc.c  */
-#line 520 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 523 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 88:
 
-/* Line 1280 of yacc.c  */
-#line 522 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 525 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 89:
 
-/* Line 1280 of yacc.c  */
-#line 524 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 527 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 90:
 
-/* Line 1280 of yacc.c  */
-#line 526 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 529 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
-/* Line 1280 of yacc.c  */
-#line 542 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 545 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
@@ -2539,8 +2542,8 @@ yyreduce:
 
   case 95:
 
-/* Line 1280 of yacc.c  */
-#line 552 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 555 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2553,15 +2556,15 @@ yyreduce:
 
   case 96:
 
-/* Line 1280 of yacc.c  */
-#line 572 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 575 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 97:
 
-/* Line 1280 of yacc.c  */
-#line 574 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 577 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2571,15 +2574,15 @@ yyreduce:
 
   case 98:
 
-/* Line 1280 of yacc.c  */
-#line 582 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 585 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 101:
 
-/* Line 1280 of yacc.c  */
-#line 594 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 597 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2588,8 +2591,8 @@ yyreduce:
 
   case 103:
 
-/* Line 1280 of yacc.c  */
-#line 603 "parse-gram.y"
+/* Line 1285 of yacc.c  */
+#line 606 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2602,8 +2605,8 @@ yyreduce:
 
 
 
-/* Line 1280 of yacc.c  */
-#line 2607 "parse-gram.c"
+/* Line 1285 of yacc.c  */
+#line 2610 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2821,8 +2824,8 @@ yyreturn:
 
 
 
-/* Line 1497 of yacc.c  */
-#line 613 "parse-gram.y"
+/* Line 1502 of yacc.c  */
+#line 616 "parse-gram.y"
 
 
 
