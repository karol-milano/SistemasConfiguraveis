@@ -69,7 +69,7 @@
 #define yylloc gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 173 of yacc.c.  */
+/* Line 164 of yacc.c.  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -292,8 +292,8 @@ static int current_prec = 0;
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
-{/* Line 207 of yacc.c.  */
-#line 97 "parse-gram.y"
+{/* Line 198 of yacc.c.  */
+#line 98 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -303,7 +303,7 @@ typedef union YYSTYPE
   uniqstr uniqstr;
   unsigned char character;
 }
-/* Line 207 of yacc.c.  */
+/* Line 198 of yacc.c.  */
 #line 308 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -327,7 +327,7 @@ typedef struct YYLTYPE
 
 /* Copy the second part of user declarations.  */
 
-/* Line 230 of yacc.c.  */
+/* Line 221 of yacc.c.  */
 #line 332 "parse-gram.c"
 
 #ifdef short
@@ -650,16 +650,16 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   205,   205,   213,   215,   219,   220,   221,   222,   223,
-     224,   225,   226,   227,   228,   229,   230,   231,   236,   240,
-     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
-     251,   252,   253,   254,   258,   259,   260,   264,   268,   276,
-     284,   288,   292,   306,   307,   311,   339,   339,   344,   344,
-     349,   360,   375,   376,   377,   381,   382,   387,   388,   393,
-     398,   403,   409,   415,   426,   427,   436,   437,   443,   444,
-     445,   452,   452,   456,   457,   458,   463,   464,   466,   468,
-     470,   472,   482,   483,   489,   493,   498,   514,   516,   525,
-     530,   531,   536,   543,   545
+       0,   206,   206,   214,   216,   220,   221,   222,   223,   224,
+     225,   226,   227,   228,   229,   230,   231,   232,   237,   241,
+     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
+     252,   253,   254,   255,   259,   260,   261,   265,   269,   277,
+     285,   289,   293,   307,   308,   312,   340,   340,   345,   345,
+     350,   361,   376,   377,   378,   382,   383,   388,   389,   394,
+     399,   404,   410,   416,   427,   428,   437,   438,   444,   445,
+     446,   453,   453,   457,   458,   459,   464,   465,   467,   469,
+     471,   473,   483,   484,   490,   494,   499,   515,   517,   526,
+     531,   532,   537,   544,   546
 };
 #endif
 
@@ -1006,115 +1006,115 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-/* Line 679 of yacc.c.  */
-#line 183 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 184 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1014 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
-/* Line 679 of yacc.c.  */
-#line 194 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 195 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1021 "parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
-/* Line 679 of yacc.c.  */
-#line 185 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1028 "parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
-/* Line 679 of yacc.c.  */
-#line 178 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 179 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1035 "parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
-/* Line 679 of yacc.c.  */
-#line 185 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1042 "parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
-/* Line 679 of yacc.c.  */
-#line 190 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 191 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1049 "parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
-/* Line 679 of yacc.c.  */
-#line 191 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 192 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1056 "parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
-/* Line 679 of yacc.c.  */
-#line 185 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1063 "parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
-/* Line 679 of yacc.c.  */
-#line 189 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1070 "parse-gram.c"
 	break;
       case 78: /* "content" */
-/* Line 679 of yacc.c.  */
-#line 185 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1077 "parse-gram.c"
 	break;
       case 79: /* "content.opt" */
-/* Line 679 of yacc.c.  */
-#line 185 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1084 "parse-gram.c"
 	break;
       case 80: /* "braceless" */
-/* Line 679 of yacc.c.  */
-#line 185 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1091 "parse-gram.c"
 	break;
       case 81: /* "id" */
-/* Line 679 of yacc.c.  */
-#line 197 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 198 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1098 "parse-gram.c"
 	break;
       case 82: /* "id_colon" */
-/* Line 679 of yacc.c.  */
-#line 198 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1105 "parse-gram.c"
 	break;
       case 83: /* "symbol" */
-/* Line 679 of yacc.c.  */
-#line 197 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 198 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1112 "parse-gram.c"
 	break;
       case 84: /* "string_as_id" */
-/* Line 679 of yacc.c.  */
-#line 197 "parse-gram.y"
+/* Line 670 of yacc.c.  */
+#line 198 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-/* Line 679 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 1119 "parse-gram.c"
 	break;
       default:
@@ -1409,7 +1409,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       yyfmt = yystpcpy (yyformat, yyunexpected);
 
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-	if ((int)yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 	  {
 	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
 	      {
@@ -1628,15 +1628,15 @@ YYLTYPE yylloc;
 
 
   /* User initialization code.  */
-  /* Line 1091 of yacc.c.  */
-#line 88 "parse-gram.y"
+  /* Line 1082 of yacc.c.  */
+#line 89 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1091 of yacc.c.  */
+/* Line 1082 of yacc.c.  */
 #line 1641 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
@@ -1760,7 +1760,7 @@ yybackup:
   /* If the proper action on seeing token YYTOKEN is to reduce or to
      detect an error, take that action.  */
   yyn += yytoken;
-  if (yyn < 0 || YYLAST < yyn || (int)yycheck[yyn] != yytoken)
+  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
     goto yydefault;
   yyn = yytable[yyn];
   if (yyn <= 0)
@@ -1821,74 +1821,74 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-/* Line 1278 of yacc.c.  */
-#line 220 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 221 "parse-gram.y"
     { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), union_seen); }
     break;
 
   case 7:
-/* Line 1278 of yacc.c.  */
-#line 221 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 222 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
     break;
 
   case 8:
-/* Line 1278 of yacc.c.  */
-#line 222 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 223 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), false); }
     break;
 
   case 9:
-/* Line 1278 of yacc.c.  */
-#line 223 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 224 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 10:
-/* Line 1278 of yacc.c.  */
-#line 224 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 225 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 11:
-/* Line 1278 of yacc.c.  */
-#line 225 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 226 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 12:
-/* Line 1278 of yacc.c.  */
-#line 226 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 227 "parse-gram.y"
     { muscle_code_grow ("end_header", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 13:
-/* Line 1278 of yacc.c.  */
-#line 227 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 228 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 14:
-/* Line 1278 of yacc.c.  */
-#line 228 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 229 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 15:
-/* Line 1278 of yacc.c.  */
-#line 229 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 230 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 16:
-/* Line 1278 of yacc.c.  */
-#line 230 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 231 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 17:
-/* Line 1278 of yacc.c.  */
-#line 232 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 233 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1896,116 +1896,116 @@ yyreduce:
     break;
 
   case 18:
-/* Line 1278 of yacc.c.  */
-#line 237 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 238 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
     break;
 
   case 19:
-/* Line 1278 of yacc.c.  */
-#line 240 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 241 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
-/* Line 1278 of yacc.c.  */
-#line 241 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 242 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
-/* Line 1278 of yacc.c.  */
-#line 242 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 243 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 22:
-/* Line 1278 of yacc.c.  */
-#line 243 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 244 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 23:
-/* Line 1278 of yacc.c.  */
-#line 244 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 245 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 24:
-/* Line 1278 of yacc.c.  */
-#line 245 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 246 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 25:
-/* Line 1278 of yacc.c.  */
-#line 246 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 247 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 26:
-/* Line 1278 of yacc.c.  */
-#line 247 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 248 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 27:
-/* Line 1278 of yacc.c.  */
-#line 248 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 249 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 28:
-/* Line 1278 of yacc.c.  */
-#line 249 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 250 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 29:
-/* Line 1278 of yacc.c.  */
-#line 250 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 251 "parse-gram.y"
     { muscle_code_grow ("start_header", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 30:
-/* Line 1278 of yacc.c.  */
-#line 251 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 252 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 31:
-/* Line 1278 of yacc.c.  */
-#line 252 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 253 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 32:
-/* Line 1278 of yacc.c.  */
-#line 253 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 254 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 36:
-/* Line 1278 of yacc.c.  */
-#line 261 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 262 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
   case 37:
-/* Line 1278 of yacc.c.  */
-#line 265 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 266 "parse-gram.y"
     {
       default_destructor_set (translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
     break;
 
   case 38:
-/* Line 1278 of yacc.c.  */
-#line 269 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 270 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -2016,8 +2016,8 @@ yyreduce:
     break;
 
   case 39:
-/* Line 1278 of yacc.c.  */
-#line 277 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 278 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -2028,44 +2028,44 @@ yyreduce:
     break;
 
   case 40:
-/* Line 1278 of yacc.c.  */
-#line 285 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 286 "parse-gram.y"
     {
       default_printer_set (translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
     break;
 
   case 41:
-/* Line 1278 of yacc.c.  */
-#line 289 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 290 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 42:
-/* Line 1278 of yacc.c.  */
-#line 293 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 294 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 43:
-/* Line 1278 of yacc.c.  */
-#line 306 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 307 "parse-gram.y"
     {}
     break;
 
   case 44:
-/* Line 1278 of yacc.c.  */
-#line 307 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 308 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 45:
-/* Line 1278 of yacc.c.  */
-#line 312 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 313 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
 
@@ -2090,14 +2090,14 @@ yyreduce:
     break;
 
   case 46:
-/* Line 1278 of yacc.c.  */
-#line 339 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 340 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 47:
-/* Line 1278 of yacc.c.  */
-#line 340 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 341 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2105,14 +2105,14 @@ yyreduce:
     break;
 
   case 48:
-/* Line 1278 of yacc.c.  */
-#line 344 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 345 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 49:
-/* Line 1278 of yacc.c.  */
-#line 345 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 346 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2120,8 +2120,8 @@ yyreduce:
     break;
 
   case 50:
-/* Line 1278 of yacc.c.  */
-#line 350 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 351 "parse-gram.y"
     {
       tag_seen = true;
       symbol_list *list;
@@ -2132,8 +2132,8 @@ yyreduce:
     break;
 
   case 51:
-/* Line 1278 of yacc.c.  */
-#line 361 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 362 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2148,50 +2148,50 @@ yyreduce:
     break;
 
   case 52:
-/* Line 1278 of yacc.c.  */
-#line 375 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 376 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 53:
-/* Line 1278 of yacc.c.  */
-#line 376 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 377 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 54:
-/* Line 1278 of yacc.c.  */
-#line 377 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 378 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 55:
-/* Line 1278 of yacc.c.  */
-#line 381 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 382 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 56:
-/* Line 1278 of yacc.c.  */
-#line 382 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 383 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 57:
-/* Line 1278 of yacc.c.  */
-#line 387 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 388 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 58:
-/* Line 1278 of yacc.c.  */
-#line 388 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 389 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 59:
-/* Line 1278 of yacc.c.  */
-#line 394 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 395 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2199,8 +2199,8 @@ yyreduce:
     break;
 
   case 60:
-/* Line 1278 of yacc.c.  */
-#line 399 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 400 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2208,8 +2208,8 @@ yyreduce:
     break;
 
   case 61:
-/* Line 1278 of yacc.c.  */
-#line 404 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 405 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2218,8 +2218,8 @@ yyreduce:
     break;
 
   case 62:
-/* Line 1278 of yacc.c.  */
-#line 410 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 411 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2228,8 +2228,8 @@ yyreduce:
     break;
 
   case 63:
-/* Line 1278 of yacc.c.  */
-#line 416 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 417 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2239,70 +2239,70 @@ yyreduce:
     break;
 
   case 70:
-/* Line 1278 of yacc.c.  */
-#line 446 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 447 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 71:
-/* Line 1278 of yacc.c.  */
-#line 452 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 453 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 73:
-/* Line 1278 of yacc.c.  */
-#line 456 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 457 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 74:
-/* Line 1278 of yacc.c.  */
-#line 457 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 458 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 76:
-/* Line 1278 of yacc.c.  */
-#line 463 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 464 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 77:
-/* Line 1278 of yacc.c.  */
-#line 465 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 466 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 78:
-/* Line 1278 of yacc.c.  */
-#line 467 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 468 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 79:
-/* Line 1278 of yacc.c.  */
-#line 469 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 470 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 80:
-/* Line 1278 of yacc.c.  */
-#line 471 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 472 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 81:
-/* Line 1278 of yacc.c.  */
-#line 473 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 474 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 84:
-/* Line 1278 of yacc.c.  */
-#line 489 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 490 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
@@ -2310,8 +2310,8 @@ yyreduce:
     break;
 
   case 86:
-/* Line 1278 of yacc.c.  */
-#line 499 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 500 "parse-gram.y"
     {
       (yyvsp[(1) - (1)].chars)[strlen ((yyvsp[(1) - (1)].chars)) - 1] = '\n';
       (yyval.chars) = translate_code ((yyvsp[(1) - (1)].chars) + 1, (yylsp[(1) - (1)]));
@@ -2319,14 +2319,14 @@ yyreduce:
     break;
 
   case 87:
-/* Line 1278 of yacc.c.  */
-#line 515 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 516 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 88:
-/* Line 1278 of yacc.c.  */
-#line 517 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 518 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2335,14 +2335,14 @@ yyreduce:
     break;
 
   case 89:
-/* Line 1278 of yacc.c.  */
-#line 525 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 526 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 92:
-/* Line 1278 of yacc.c.  */
-#line 537 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 538 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2350,8 +2350,8 @@ yyreduce:
     break;
 
   case 94:
-/* Line 1278 of yacc.c.  */
-#line 546 "parse-gram.y"
+/* Line 1269 of yacc.c.  */
+#line 547 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2359,7 +2359,7 @@ yyreduce:
     break;
 
 
-/* Line 1278 of yacc.c.  */
+/* Line 1269 of yacc.c.  */
 #line 2364 "parse-gram.c"
       default: break;
     }
@@ -2379,8 +2379,7 @@ yyreduce:
   yyn = yyr1[yyn];
 
   yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
-  if (0 <= yystate && yystate <= YYLAST
-      && (int)yycheck[yystate] == *yyssp)
+  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
     yystate = yytable[yystate];
   else
     yystate = yydefgoto[yyn - YYNTOKENS];
@@ -2578,8 +2577,8 @@ yyreturn:
 }
 
 
-/* Line 1496 of yacc.c.  */
-#line 552 "parse-gram.y"
+/* Line 1486 of yacc.c.  */
+#line 553 "parse-gram.y"
 
 
 
