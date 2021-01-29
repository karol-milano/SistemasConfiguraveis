@@ -307,19 +307,20 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 /* Line 198 of yacc.c  */
-#line 98 "parse-gram.y"
+#line 97 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
   int integer;
-  char *chars;
+  char const *chars;
+  char *code;
   assoc assoc;
   uniqstr uniqstr;
   unsigned char character;
 }
 
 /* Line 198 of yacc.c  */
-#line 323 "parse-gram.c"
+#line 324 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -344,7 +345,7 @@ typedef struct YYLTYPE
 
 
 /* Line 221 of yacc.c  */
-#line 348 "parse-gram.c"
+#line 349 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -667,16 +668,16 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   209,   209,   217,   219,   223,   224,   225,   226,   227,
-     228,   229,   230,   231,   232,   237,   241,   242,   243,   244,
-     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
-     255,   259,   260,   261,   265,   273,   281,   285,   289,   290,
-     291,   292,   303,   304,   308,   336,   336,   341,   341,   346,
-     357,   372,   373,   374,   378,   379,   384,   386,   391,   392,
-     396,   397,   398,   399,   404,   409,   414,   420,   426,   437,
-     438,   447,   448,   454,   455,   456,   463,   463,   467,   468,
-     469,   474,   475,   477,   479,   481,   483,   493,   494,   500,
-     504,   509,   525,   527,   536,   541,   542,   547,   554,   556
+       0,   210,   210,   218,   220,   224,   225,   226,   227,   228,
+     229,   230,   231,   232,   233,   238,   242,   243,   244,   245,
+     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
+     256,   260,   261,   262,   266,   274,   282,   286,   290,   291,
+     292,   293,   304,   305,   309,   337,   337,   342,   342,   347,
+     358,   373,   374,   375,   379,   380,   385,   387,   392,   393,
+     397,   398,   399,   400,   405,   410,   415,   421,   427,   438,
+     439,   448,   449,   455,   456,   457,   464,   464,   468,   469,
+     470,   475,   476,   478,   480,   482,   484,   494,   495,   501,
+     505,   510,   526,   528,   537,   542,   543,   548,   555,   557
 };
 #endif
 
@@ -1036,29 +1037,29 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 
 /* Line 670 of yacc.c  */
-#line 187 "parse-gram.y"
+#line 188 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1044 "parse-gram.c"
+#line 1045 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
 /* Line 670 of yacc.c  */
-#line 198 "parse-gram.y"
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 670 of yacc.c  */
-#line 1053 "parse-gram.c"
+#line 1054 "parse-gram.c"
 	break;
       case 46: /* "\"{...}\"" */
 
 /* Line 670 of yacc.c  */
-#line 189 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 190 "parse-gram.y"
+	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
 /* Line 670 of yacc.c  */
-#line 1062 "parse-gram.c"
+#line 1063 "parse-gram.c"
 	break;
       case 47: /* "\"char\"" */
 
@@ -1067,115 +1068,115 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1071 "parse-gram.c"
+#line 1072 "parse-gram.c"
 	break;
       case 48: /* "\"epilogue\"" */
 
 /* Line 670 of yacc.c  */
-#line 189 "parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1080 "parse-gram.c"
+#line 1081 "parse-gram.c"
 	break;
       case 50: /* "\"identifier\"" */
 
 /* Line 670 of yacc.c  */
-#line 194 "parse-gram.y"
+#line 195 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 670 of yacc.c  */
-#line 1089 "parse-gram.c"
+#line 1090 "parse-gram.c"
 	break;
       case 51: /* "\"identifier:\"" */
 
 /* Line 670 of yacc.c  */
-#line 195 "parse-gram.y"
+#line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 670 of yacc.c  */
-#line 1098 "parse-gram.c"
+#line 1099 "parse-gram.c"
 	break;
       case 54: /* "\"%{...%}\"" */
 
 /* Line 670 of yacc.c  */
-#line 189 "parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1107 "parse-gram.c"
+#line 1108 "parse-gram.c"
 	break;
       case 56: /* "\"type\"" */
 
 /* Line 670 of yacc.c  */
-#line 193 "parse-gram.y"
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 670 of yacc.c  */
-#line 1116 "parse-gram.c"
+#line 1117 "parse-gram.c"
 	break;
       case 83: /* "content" */
 
 /* Line 670 of yacc.c  */
-#line 189 "parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1125 "parse-gram.c"
+#line 1126 "parse-gram.c"
 	break;
       case 84: /* "content.opt" */
 
 /* Line 670 of yacc.c  */
-#line 189 "parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1134 "parse-gram.c"
+#line 1135 "parse-gram.c"
 	break;
       case 85: /* "braceless" */
 
 /* Line 670 of yacc.c  */
-#line 189 "parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 670 of yacc.c  */
-#line 1143 "parse-gram.c"
+#line 1144 "parse-gram.c"
 	break;
       case 86: /* "id" */
 
 /* Line 670 of yacc.c  */
-#line 201 "parse-gram.y"
+#line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1152 "parse-gram.c"
+#line 1153 "parse-gram.c"
 	break;
       case 87: /* "id_colon" */
 
 /* Line 670 of yacc.c  */
-#line 202 "parse-gram.y"
+#line 203 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1161 "parse-gram.c"
+#line 1162 "parse-gram.c"
 	break;
       case 88: /* "symbol" */
 
 /* Line 670 of yacc.c  */
-#line 201 "parse-gram.y"
+#line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1170 "parse-gram.c"
+#line 1171 "parse-gram.c"
 	break;
       case 89: /* "string_as_id" */
 
 /* Line 670 of yacc.c  */
-#line 201 "parse-gram.y"
+#line 202 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 670 of yacc.c  */
-#line 1179 "parse-gram.c"
+#line 1180 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1699,7 +1700,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 1082 of yacc.c  */
-#line 1703 "parse-gram.c"
+#line 1704 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1885,63 +1886,63 @@ yyreduce:
         case 6:
 
 /* Line 1269 of yacc.c  */
-#line 224 "parse-gram.y"
+#line 225 "parse-gram.y"
     { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), union_seen); }
     break;
 
   case 7:
 
 /* Line 1269 of yacc.c  */
-#line 225 "parse-gram.y"
+#line 226 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
 /* Line 1269 of yacc.c  */
-#line 226 "parse-gram.y"
+#line 227 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 9:
 
 /* Line 1269 of yacc.c  */
-#line 227 "parse-gram.y"
+#line 228 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
 /* Line 1269 of yacc.c  */
-#line 228 "parse-gram.y"
+#line 229 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 11:
 
 /* Line 1269 of yacc.c  */
-#line 229 "parse-gram.y"
+#line 230 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 12:
 
 /* Line 1269 of yacc.c  */
-#line 230 "parse-gram.y"
+#line 231 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
 /* Line 1269 of yacc.c  */
-#line 231 "parse-gram.y"
+#line 232 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 14:
 
 /* Line 1269 of yacc.c  */
-#line 233 "parse-gram.y"
+#line 234 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1951,114 +1952,114 @@ yyreduce:
   case 15:
 
 /* Line 1269 of yacc.c  */
-#line 238 "parse-gram.y"
+#line 239 "parse-gram.y"
     {
-      muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
+      muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
     break;
 
   case 16:
 
 /* Line 1269 of yacc.c  */
-#line 241 "parse-gram.y"
-    { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
+#line 242 "parse-gram.y"
+    { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 17:
 
 /* Line 1269 of yacc.c  */
-#line 242 "parse-gram.y"
+#line 243 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 18:
 
 /* Line 1269 of yacc.c  */
-#line 243 "parse-gram.y"
+#line 244 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 19:
 
 /* Line 1269 of yacc.c  */
-#line 244 "parse-gram.y"
+#line 245 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 20:
 
 /* Line 1269 of yacc.c  */
-#line 245 "parse-gram.y"
+#line 246 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 21:
 
 /* Line 1269 of yacc.c  */
-#line 246 "parse-gram.y"
+#line 247 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 22:
 
 /* Line 1269 of yacc.c  */
-#line 247 "parse-gram.y"
-    { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
+#line 248 "parse-gram.y"
+    { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 23:
 
 /* Line 1269 of yacc.c  */
-#line 248 "parse-gram.y"
+#line 249 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 24:
 
 /* Line 1269 of yacc.c  */
-#line 249 "parse-gram.y"
+#line 250 "parse-gram.y"
     { push_parser = true; }
     break;
 
   case 25:
 
 /* Line 1269 of yacc.c  */
-#line 250 "parse-gram.y"
+#line 251 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 26:
 
 /* Line 1269 of yacc.c  */
-#line 251 "parse-gram.y"
+#line 252 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 27:
 
 /* Line 1269 of yacc.c  */
-#line 252 "parse-gram.y"
+#line 253 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 28:
 
 /* Line 1269 of yacc.c  */
-#line 253 "parse-gram.y"
+#line 254 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 29:
 
 /* Line 1269 of yacc.c  */
-#line 254 "parse-gram.y"
+#line 255 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 33:
 
 /* Line 1269 of yacc.c  */
-#line 262 "parse-gram.y"
+#line 263 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2067,12 +2068,12 @@ yyreduce:
   case 34:
 
 /* Line 1269 of yacc.c  */
-#line 266 "parse-gram.y"
+#line 267 "parse-gram.y"
     {
       symbol_list *list;
-      const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
+      const char *action = translate_symbol_action ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
-        symbol_list_destructor_set (list, action, (yylsp[(2) - (3)]));
+	symbol_list_destructor_set (list, action, (yylsp[(2) - (3)]));
       symbol_list_free ((yyvsp[(3) - (3)].list));
     }
     break;
@@ -2080,12 +2081,12 @@ yyreduce:
   case 35:
 
 /* Line 1269 of yacc.c  */
-#line 274 "parse-gram.y"
+#line 275 "parse-gram.y"
     {
       symbol_list *list;
-      const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
+      const char *action = translate_symbol_action ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
-        symbol_list_printer_set (list, action, (yylsp[(2) - (3)]));
+	symbol_list_printer_set (list, action, (yylsp[(2) - (3)]));
       symbol_list_free ((yyvsp[(3) - (3)].list));
     }
     break;
@@ -2093,7 +2094,7 @@ yyreduce:
   case 36:
 
 /* Line 1269 of yacc.c  */
-#line 282 "parse-gram.y"
+#line 283 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2102,7 +2103,7 @@ yyreduce:
   case 37:
 
 /* Line 1269 of yacc.c  */
-#line 286 "parse-gram.y"
+#line 287 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2111,51 +2112,51 @@ yyreduce:
   case 38:
 
 /* Line 1269 of yacc.c  */
-#line 289 "parse-gram.y"
+#line 290 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
     break;
 
   case 39:
 
 /* Line 1269 of yacc.c  */
-#line 290 "parse-gram.y"
+#line 291 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), false); }
     break;
 
   case 40:
 
 /* Line 1269 of yacc.c  */
-#line 291 "parse-gram.y"
+#line 292 "parse-gram.y"
     { muscle_code_grow ("provides", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 41:
 
 /* Line 1269 of yacc.c  */
-#line 292 "parse-gram.y"
+#line 293 "parse-gram.y"
     { muscle_code_grow ("requires", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 42:
 
 /* Line 1269 of yacc.c  */
-#line 303 "parse-gram.y"
+#line 304 "parse-gram.y"
     {}
     break;
 
   case 43:
 
 /* Line 1269 of yacc.c  */
-#line 304 "parse-gram.y"
+#line 305 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 44:
 
 /* Line 1269 of yacc.c  */
-#line 309 "parse-gram.y"
+#line 310 "parse-gram.y"
     {
-      char const *body = (yyvsp[(3) - (3)].chars);
+      char const *body = (yyvsp[(3) - (3)].code);
 
       /* Concatenate the %union bodies.  If this is the first %union, make sure
 	 the synchronization line appears after the opening '{' so as not to
@@ -2180,14 +2181,14 @@ yyreduce:
   case 45:
 
 /* Line 1269 of yacc.c  */
-#line 336 "parse-gram.y"
+#line 337 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 46:
 
 /* Line 1269 of yacc.c  */
-#line 337 "parse-gram.y"
+#line 338 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2197,14 +2198,14 @@ yyreduce:
   case 47:
 
 /* Line 1269 of yacc.c  */
-#line 341 "parse-gram.y"
+#line 342 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 48:
 
 /* Line 1269 of yacc.c  */
-#line 342 "parse-gram.y"
+#line 343 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2214,7 +2215,7 @@ yyreduce:
   case 49:
 
 /* Line 1269 of yacc.c  */
-#line 347 "parse-gram.y"
+#line 348 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2227,7 +2228,7 @@ yyreduce:
   case 50:
 
 /* Line 1269 of yacc.c  */
-#line 358 "parse-gram.y"
+#line 359 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2244,98 +2245,98 @@ yyreduce:
   case 51:
 
 /* Line 1269 of yacc.c  */
-#line 372 "parse-gram.y"
+#line 373 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 52:
 
 /* Line 1269 of yacc.c  */
-#line 373 "parse-gram.y"
+#line 374 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 53:
 
 /* Line 1269 of yacc.c  */
-#line 374 "parse-gram.y"
+#line 375 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 54:
 
 /* Line 1269 of yacc.c  */
-#line 378 "parse-gram.y"
+#line 379 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 55:
 
 /* Line 1269 of yacc.c  */
-#line 379 "parse-gram.y"
+#line 380 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 56:
 
 /* Line 1269 of yacc.c  */
-#line 385 "parse-gram.y"
+#line 386 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 57:
 
 /* Line 1269 of yacc.c  */
-#line 387 "parse-gram.y"
+#line 388 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 58:
 
 /* Line 1269 of yacc.c  */
-#line 391 "parse-gram.y"
+#line 392 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 59:
 
 /* Line 1269 of yacc.c  */
-#line 392 "parse-gram.y"
+#line 393 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 60:
 
 /* Line 1269 of yacc.c  */
-#line 396 "parse-gram.y"
+#line 397 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 61:
 
 /* Line 1269 of yacc.c  */
-#line 397 "parse-gram.y"
+#line 398 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 62:
 
 /* Line 1269 of yacc.c  */
-#line 398 "parse-gram.y"
+#line 399 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
 /* Line 1269 of yacc.c  */
-#line 399 "parse-gram.y"
+#line 400 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 64:
 
 /* Line 1269 of yacc.c  */
-#line 405 "parse-gram.y"
+#line 406 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2345,7 +2346,7 @@ yyreduce:
   case 65:
 
 /* Line 1269 of yacc.c  */
-#line 410 "parse-gram.y"
+#line 411 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2355,7 +2356,7 @@ yyreduce:
   case 66:
 
 /* Line 1269 of yacc.c  */
-#line 415 "parse-gram.y"
+#line 416 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2366,7 +2367,7 @@ yyreduce:
   case 67:
 
 /* Line 1269 of yacc.c  */
-#line 421 "parse-gram.y"
+#line 422 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2377,7 +2378,7 @@ yyreduce:
   case 68:
 
 /* Line 1269 of yacc.c  */
-#line 427 "parse-gram.y"
+#line 428 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2389,7 +2390,7 @@ yyreduce:
   case 75:
 
 /* Line 1269 of yacc.c  */
-#line 457 "parse-gram.y"
+#line 458 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2398,70 +2399,70 @@ yyreduce:
   case 76:
 
 /* Line 1269 of yacc.c  */
-#line 463 "parse-gram.y"
+#line 464 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 78:
 
 /* Line 1269 of yacc.c  */
-#line 467 "parse-gram.y"
+#line 468 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 79:
 
 /* Line 1269 of yacc.c  */
-#line 468 "parse-gram.y"
+#line 469 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 81:
 
 /* Line 1269 of yacc.c  */
-#line 474 "parse-gram.y"
+#line 475 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 82:
 
 /* Line 1269 of yacc.c  */
-#line 476 "parse-gram.y"
+#line 477 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 83:
 
 /* Line 1269 of yacc.c  */
-#line 478 "parse-gram.y"
-    { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
+#line 479 "parse-gram.y"
+    { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 84:
 
 /* Line 1269 of yacc.c  */
-#line 480 "parse-gram.y"
+#line 481 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 85:
 
 /* Line 1269 of yacc.c  */
-#line 482 "parse-gram.y"
+#line 483 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 86:
 
 /* Line 1269 of yacc.c  */
-#line 484 "parse-gram.y"
+#line 485 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 89:
 
 /* Line 1269 of yacc.c  */
-#line 500 "parse-gram.y"
+#line 501 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
@@ -2471,24 +2472,24 @@ yyreduce:
   case 91:
 
 /* Line 1269 of yacc.c  */
-#line 510 "parse-gram.y"
+#line 511 "parse-gram.y"
     {
-      (yyvsp[(1) - (1)].chars)[strlen ((yyvsp[(1) - (1)].chars)) - 1] = '\n';
-      (yyval.chars) = translate_code ((yyvsp[(1) - (1)].chars) + 1, (yylsp[(1) - (1)]));
+      (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
+      (yyval.chars) = translate_code ((yyvsp[(1) - (1)].code) + 1, (yylsp[(1) - (1)]));
     }
     break;
 
   case 92:
 
 /* Line 1269 of yacc.c  */
-#line 526 "parse-gram.y"
+#line 527 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 93:
 
 /* Line 1269 of yacc.c  */
-#line 528 "parse-gram.y"
+#line 529 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2499,14 +2500,14 @@ yyreduce:
   case 94:
 
 /* Line 1269 of yacc.c  */
-#line 536 "parse-gram.y"
+#line 537 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 97:
 
 /* Line 1269 of yacc.c  */
-#line 548 "parse-gram.y"
+#line 549 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2516,7 +2517,7 @@ yyreduce:
   case 99:
 
 /* Line 1269 of yacc.c  */
-#line 557 "parse-gram.y"
+#line 558 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2526,7 +2527,7 @@ yyreduce:
 
 
 /* Line 1269 of yacc.c  */
-#line 2530 "parse-gram.c"
+#line 2531 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2745,7 +2746,7 @@ yyreturn:
 
 
 /* Line 1486 of yacc.c  */
-#line 563 "parse-gram.y"
+#line 564 "parse-gram.y"
 
 
 
