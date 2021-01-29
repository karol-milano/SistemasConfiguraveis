@@ -70,7 +70,7 @@
 
 /* Copy the first part of user declarations.  */
 /* Line 164 of yacc.c.  */
-#line 1 "../../src/parse-gram.y"
+#line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
@@ -292,9 +292,9 @@ static int current_prec = 0;
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
-/* Line 198 of yacc.c.  */
-#line 97 "../../src/parse-gram.y"
-{
+{/* Line 198 of yacc.c.  */
+#line 97 "parse-gram.y"
+
   symbol *symbol;
   symbol_list *list;
   int integer;
@@ -304,7 +304,7 @@ typedef union YYSTYPE
   unsigned char character;
 }
 /* Line 198 of yacc.c.  */
-#line 308 "../../src/parse-gram.c"
+#line 308 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -328,7 +328,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 221 of yacc.c.  */
-#line 332 "../../src/parse-gram.c"
+#line 332 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -653,12 +653,12 @@ static const yytype_uint16 yyrline[] =
      224,   225,   226,   227,   228,   229,   230,   231,   236,   240,
      241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      251,   252,   253,   254,   258,   259,   260,   264,   272,   280,
-     284,   298,   299,   303,   325,   325,   330,   330,   335,   346,
-     361,   362,   363,   367,   368,   373,   374,   379,   384,   389,
-     395,   401,   412,   413,   422,   423,   429,   430,   431,   438,
-     438,   442,   443,   444,   449,   450,   452,   454,   456,   458,
-     468,   469,   475,   479,   484,   500,   502,   511,   516,   517,
-     522,   529,   531
+     284,   298,   299,   303,   331,   331,   336,   336,   341,   352,
+     367,   368,   369,   373,   374,   379,   380,   385,   390,   395,
+     401,   407,   418,   419,   428,   429,   435,   436,   437,   444,
+     444,   448,   449,   450,   455,   456,   458,   460,   462,   464,
+     474,   475,   481,   485,   490,   506,   508,   517,   522,   523,
+     528,   535,   537
 };
 #endif
 
@@ -1006,115 +1006,115 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 /* Line 670 of yacc.c.  */
-#line 183 "../../src/parse-gram.y"
+#line 183 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 /* Line 670 of yacc.c.  */
-#line 1013 "../../src/parse-gram.c"
+#line 1013 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 /* Line 670 of yacc.c.  */
-#line 194 "../../src/parse-gram.y"
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 /* Line 670 of yacc.c.  */
-#line 1020 "../../src/parse-gram.c"
+#line 1020 "parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
 /* Line 670 of yacc.c.  */
-#line 185 "../../src/parse-gram.y"
+#line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1027 "../../src/parse-gram.c"
+#line 1027 "parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
 /* Line 670 of yacc.c.  */
-#line 178 "../../src/parse-gram.y"
+#line 178 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 /* Line 670 of yacc.c.  */
-#line 1034 "../../src/parse-gram.c"
+#line 1034 "parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
 /* Line 670 of yacc.c.  */
-#line 185 "../../src/parse-gram.y"
+#line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1041 "../../src/parse-gram.c"
+#line 1041 "parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
 /* Line 670 of yacc.c.  */
-#line 190 "../../src/parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 /* Line 670 of yacc.c.  */
-#line 1048 "../../src/parse-gram.c"
+#line 1048 "parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
 /* Line 670 of yacc.c.  */
-#line 191 "../../src/parse-gram.y"
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 /* Line 670 of yacc.c.  */
-#line 1055 "../../src/parse-gram.c"
+#line 1055 "parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
 /* Line 670 of yacc.c.  */
-#line 185 "../../src/parse-gram.y"
+#line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1062 "../../src/parse-gram.c"
+#line 1062 "parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
 /* Line 670 of yacc.c.  */
-#line 189 "../../src/parse-gram.y"
+#line 189 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 /* Line 670 of yacc.c.  */
-#line 1069 "../../src/parse-gram.c"
+#line 1069 "parse-gram.c"
 	break;
       case 78: /* "content" */
 /* Line 670 of yacc.c.  */
-#line 185 "../../src/parse-gram.y"
+#line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1076 "../../src/parse-gram.c"
+#line 1076 "parse-gram.c"
 	break;
       case 79: /* "content.opt" */
 /* Line 670 of yacc.c.  */
-#line 185 "../../src/parse-gram.y"
+#line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1083 "../../src/parse-gram.c"
+#line 1083 "parse-gram.c"
 	break;
       case 80: /* "braceless" */
 /* Line 670 of yacc.c.  */
-#line 185 "../../src/parse-gram.y"
+#line 185 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 670 of yacc.c.  */
-#line 1090 "../../src/parse-gram.c"
+#line 1090 "parse-gram.c"
 	break;
       case 81: /* "id" */
 /* Line 670 of yacc.c.  */
-#line 197 "../../src/parse-gram.y"
+#line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1097 "../../src/parse-gram.c"
+#line 1097 "parse-gram.c"
 	break;
       case 82: /* "id_colon" */
 /* Line 670 of yacc.c.  */
-#line 198 "../../src/parse-gram.y"
+#line 198 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1104 "../../src/parse-gram.c"
+#line 1104 "parse-gram.c"
 	break;
       case 83: /* "symbol" */
 /* Line 670 of yacc.c.  */
-#line 197 "../../src/parse-gram.y"
+#line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1111 "../../src/parse-gram.c"
+#line 1111 "parse-gram.c"
 	break;
       case 84: /* "string_as_id" */
 /* Line 670 of yacc.c.  */
-#line 197 "../../src/parse-gram.y"
+#line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 670 of yacc.c.  */
-#line 1118 "../../src/parse-gram.c"
+#line 1118 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1628,7 +1628,7 @@ YYLTYPE yylloc;
 
   /* User initialization code.  */
   /* Line 1082 of yacc.c.  */
-#line 88 "../../src/parse-gram.y"
+#line 88 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1636,7 +1636,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1082 of yacc.c.  */
-#line 1640 "../../src/parse-gram.c"
+#line 1640 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1822,73 +1822,73 @@ yyreduce:
     {
         case 6:
 /* Line 1270 of yacc.c.  */
-#line 220 "../../src/parse-gram.y"
+#line 220 "parse-gram.y"
     { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), union_seen); }
     break;
 
   case 7:
 /* Line 1270 of yacc.c.  */
-#line 221 "../../src/parse-gram.y"
+#line 221 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
     break;
 
   case 8:
 /* Line 1270 of yacc.c.  */
-#line 222 "../../src/parse-gram.y"
+#line 222 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), false); }
     break;
 
   case 9:
 /* Line 1270 of yacc.c.  */
-#line 223 "../../src/parse-gram.y"
+#line 223 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 10:
 /* Line 1270 of yacc.c.  */
-#line 224 "../../src/parse-gram.y"
+#line 224 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 11:
 /* Line 1270 of yacc.c.  */
-#line 225 "../../src/parse-gram.y"
+#line 225 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 12:
 /* Line 1270 of yacc.c.  */
-#line 226 "../../src/parse-gram.y"
+#line 226 "parse-gram.y"
     { muscle_code_grow ("end_header", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 13:
 /* Line 1270 of yacc.c.  */
-#line 227 "../../src/parse-gram.y"
+#line 227 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 14:
 /* Line 1270 of yacc.c.  */
-#line 228 "../../src/parse-gram.y"
+#line 228 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 15:
 /* Line 1270 of yacc.c.  */
-#line 229 "../../src/parse-gram.y"
+#line 229 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 16:
 /* Line 1270 of yacc.c.  */
-#line 230 "../../src/parse-gram.y"
+#line 230 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 17:
 /* Line 1270 of yacc.c.  */
-#line 232 "../../src/parse-gram.y"
+#line 232 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1897,7 +1897,7 @@ yyreduce:
 
   case 18:
 /* Line 1270 of yacc.c.  */
-#line 237 "../../src/parse-gram.y"
+#line 237 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
@@ -1905,91 +1905,91 @@ yyreduce:
 
   case 19:
 /* Line 1270 of yacc.c.  */
-#line 240 "../../src/parse-gram.y"
+#line 240 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 /* Line 1270 of yacc.c.  */
-#line 241 "../../src/parse-gram.y"
+#line 241 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 /* Line 1270 of yacc.c.  */
-#line 242 "../../src/parse-gram.y"
+#line 242 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 22:
 /* Line 1270 of yacc.c.  */
-#line 243 "../../src/parse-gram.y"
+#line 243 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 23:
 /* Line 1270 of yacc.c.  */
-#line 244 "../../src/parse-gram.y"
+#line 244 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 24:
 /* Line 1270 of yacc.c.  */
-#line 245 "../../src/parse-gram.y"
+#line 245 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 25:
 /* Line 1270 of yacc.c.  */
-#line 246 "../../src/parse-gram.y"
+#line 246 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 26:
 /* Line 1270 of yacc.c.  */
-#line 247 "../../src/parse-gram.y"
+#line 247 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 27:
 /* Line 1270 of yacc.c.  */
-#line 248 "../../src/parse-gram.y"
+#line 248 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 28:
 /* Line 1270 of yacc.c.  */
-#line 249 "../../src/parse-gram.y"
+#line 249 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 29:
 /* Line 1270 of yacc.c.  */
-#line 250 "../../src/parse-gram.y"
+#line 250 "parse-gram.y"
     { muscle_code_grow ("start_header", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 30:
 /* Line 1270 of yacc.c.  */
-#line 251 "../../src/parse-gram.y"
+#line 251 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 31:
 /* Line 1270 of yacc.c.  */
-#line 252 "../../src/parse-gram.y"
+#line 252 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 32:
 /* Line 1270 of yacc.c.  */
-#line 253 "../../src/parse-gram.y"
+#line 253 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 36:
 /* Line 1270 of yacc.c.  */
-#line 261 "../../src/parse-gram.y"
+#line 261 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -1997,7 +1997,7 @@ yyreduce:
 
   case 37:
 /* Line 1270 of yacc.c.  */
-#line 265 "../../src/parse-gram.y"
+#line 265 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -2009,7 +2009,7 @@ yyreduce:
 
   case 38:
 /* Line 1270 of yacc.c.  */
-#line 273 "../../src/parse-gram.y"
+#line 273 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -2021,7 +2021,7 @@ yyreduce:
 
   case 39:
 /* Line 1270 of yacc.c.  */
-#line 281 "../../src/parse-gram.y"
+#line 281 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2029,7 +2029,7 @@ yyreduce:
 
   case 40:
 /* Line 1270 of yacc.c.  */
-#line 285 "../../src/parse-gram.y"
+#line 285 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2037,30 +2037,36 @@ yyreduce:
 
   case 41:
 /* Line 1270 of yacc.c.  */
-#line 298 "../../src/parse-gram.y"
+#line 298 "parse-gram.y"
     {}
     break;
 
   case 42:
 /* Line 1270 of yacc.c.  */
-#line 299 "../../src/parse-gram.y"
+#line 299 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 43:
 /* Line 1270 of yacc.c.  */
-#line 304 "../../src/parse-gram.y"
+#line 304 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
 
-      if (union_seen)
+      /* Concatenate the %union bodies.  If this is the first %union, make sure
+	 the synchronization line appears after the opening '{' so as not to
+	 confuse Doxygen.  Otherwise, turn the previous %union's trailing '}'
+	 into '\n', and omit the new %union's leading '{'.  */
+      if (!union_seen)
+	{
+	  muscle_grow ("stype", "{", "");
+	}
+      else
 	{
-	  /* Concatenate the union bodies, turning the first one's
-	     trailing '}' into '\n', and omitting the second one's '{'.  */
 	  char *code = muscle_find ("stype");
 	  code[strlen (code) - 1] = '\n';
-	  body++;
 	}
+      body++;
 
       union_seen = true;
       muscle_code_grow ("stype", body, (yylsp[(3) - (3)]));
@@ -2069,13 +2075,13 @@ yyreduce:
 
   case 44:
 /* Line 1270 of yacc.c.  */
-#line 325 "../../src/parse-gram.y"
+#line 331 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 45:
 /* Line 1270 of yacc.c.  */
-#line 326 "../../src/parse-gram.y"
+#line 332 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2084,13 +2090,13 @@ yyreduce:
 
   case 46:
 /* Line 1270 of yacc.c.  */
-#line 330 "../../src/parse-gram.y"
+#line 336 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 47:
 /* Line 1270 of yacc.c.  */
-#line 331 "../../src/parse-gram.y"
+#line 337 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2099,7 +2105,7 @@ yyreduce:
 
   case 48:
 /* Line 1270 of yacc.c.  */
-#line 336 "../../src/parse-gram.y"
+#line 342 "parse-gram.y"
     {
       tag_seen = true;
       symbol_list *list;
@@ -2111,7 +2117,7 @@ yyreduce:
 
   case 49:
 /* Line 1270 of yacc.c.  */
-#line 347 "../../src/parse-gram.y"
+#line 353 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2127,49 +2133,49 @@ yyreduce:
 
   case 50:
 /* Line 1270 of yacc.c.  */
-#line 361 "../../src/parse-gram.y"
+#line 367 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 51:
 /* Line 1270 of yacc.c.  */
-#line 362 "../../src/parse-gram.y"
+#line 368 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 52:
 /* Line 1270 of yacc.c.  */
-#line 363 "../../src/parse-gram.y"
+#line 369 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 53:
 /* Line 1270 of yacc.c.  */
-#line 367 "../../src/parse-gram.y"
+#line 373 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 54:
 /* Line 1270 of yacc.c.  */
-#line 368 "../../src/parse-gram.y"
+#line 374 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 55:
 /* Line 1270 of yacc.c.  */
-#line 373 "../../src/parse-gram.y"
+#line 379 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 56:
 /* Line 1270 of yacc.c.  */
-#line 374 "../../src/parse-gram.y"
+#line 380 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 57:
 /* Line 1270 of yacc.c.  */
-#line 380 "../../src/parse-gram.y"
+#line 386 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2178,7 +2184,7 @@ yyreduce:
 
   case 58:
 /* Line 1270 of yacc.c.  */
-#line 385 "../../src/parse-gram.y"
+#line 391 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2187,7 +2193,7 @@ yyreduce:
 
   case 59:
 /* Line 1270 of yacc.c.  */
-#line 390 "../../src/parse-gram.y"
+#line 396 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2197,7 +2203,7 @@ yyreduce:
 
   case 60:
 /* Line 1270 of yacc.c.  */
-#line 396 "../../src/parse-gram.y"
+#line 402 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2207,7 +2213,7 @@ yyreduce:
 
   case 61:
 /* Line 1270 of yacc.c.  */
-#line 402 "../../src/parse-gram.y"
+#line 408 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2218,7 +2224,7 @@ yyreduce:
 
   case 68:
 /* Line 1270 of yacc.c.  */
-#line 432 "../../src/parse-gram.y"
+#line 438 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2226,61 +2232,61 @@ yyreduce:
 
   case 69:
 /* Line 1270 of yacc.c.  */
-#line 438 "../../src/parse-gram.y"
+#line 444 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 71:
 /* Line 1270 of yacc.c.  */
-#line 442 "../../src/parse-gram.y"
+#line 448 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 72:
 /* Line 1270 of yacc.c.  */
-#line 443 "../../src/parse-gram.y"
+#line 449 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 74:
 /* Line 1270 of yacc.c.  */
-#line 449 "../../src/parse-gram.y"
+#line 455 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 75:
 /* Line 1270 of yacc.c.  */
-#line 451 "../../src/parse-gram.y"
+#line 457 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 76:
 /* Line 1270 of yacc.c.  */
-#line 453 "../../src/parse-gram.y"
+#line 459 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 77:
 /* Line 1270 of yacc.c.  */
-#line 455 "../../src/parse-gram.y"
+#line 461 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 78:
 /* Line 1270 of yacc.c.  */
-#line 457 "../../src/parse-gram.y"
+#line 463 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 79:
 /* Line 1270 of yacc.c.  */
-#line 459 "../../src/parse-gram.y"
+#line 465 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 82:
 /* Line 1270 of yacc.c.  */
-#line 475 "../../src/parse-gram.y"
+#line 481 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
@@ -2289,7 +2295,7 @@ yyreduce:
 
   case 84:
 /* Line 1270 of yacc.c.  */
-#line 485 "../../src/parse-gram.y"
+#line 491 "parse-gram.y"
     {
       (yyvsp[(1) - (1)].chars)[strlen ((yyvsp[(1) - (1)].chars)) - 1] = '\n';
       (yyval.chars) = translate_code ((yyvsp[(1) - (1)].chars) + 1, (yylsp[(1) - (1)]));
@@ -2298,13 +2304,13 @@ yyreduce:
 
   case 85:
 /* Line 1270 of yacc.c.  */
-#line 501 "../../src/parse-gram.y"
+#line 507 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 86:
 /* Line 1270 of yacc.c.  */
-#line 503 "../../src/parse-gram.y"
+#line 509 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2314,13 +2320,13 @@ yyreduce:
 
   case 87:
 /* Line 1270 of yacc.c.  */
-#line 511 "../../src/parse-gram.y"
+#line 517 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 90:
 /* Line 1270 of yacc.c.  */
-#line 523 "../../src/parse-gram.y"
+#line 529 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2329,7 +2335,7 @@ yyreduce:
 
   case 92:
 /* Line 1270 of yacc.c.  */
-#line 532 "../../src/parse-gram.y"
+#line 538 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2338,7 +2344,7 @@ yyreduce:
 
 
 /* Line 1270 of yacc.c.  */
-#line 2342 "../../src/parse-gram.c"
+#line 2348 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2559,7 +2565,7 @@ yyreturn:
 
 
 /* Line 1490 of yacc.c.  */
-#line 538 "../../src/parse-gram.y"
+#line 544 "parse-gram.y"
 
 
 
