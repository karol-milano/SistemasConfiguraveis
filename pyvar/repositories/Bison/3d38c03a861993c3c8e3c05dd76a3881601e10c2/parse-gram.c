@@ -1,4 +1,4 @@
-/* A Bison parser, made from parse-gram.y, by GNU bison 1.49b.  */
+/* A Bison parser, made from parse-gram.y, by GNU bison 1.49c.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
@@ -233,7 +233,7 @@ typedef union {
   char *string;
   assoc_t assoc;
 } yystype;
-/* Line 188 of /tmp/prefix/share/bison/yacc.c.  */
+/* Line 188 of /usr/local/share/bison/yacc.c.  */
 #line 238 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
@@ -254,7 +254,7 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line 208 of /tmp/prefix/share/bison/yacc.c.  */
+/* Line 208 of /usr/local/share/bison/yacc.c.  */
 #line 259 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
@@ -444,14 +444,14 @@ static const signed char yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   159,   159,   172,   174,   177,   179,   180,   181,   182,
-     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
-     193,   194,   195,   198,   200,   201,   205,   212,   211,   222,
-     221,   234,   233,   239,   239,   244,   253,   268,   270,   271,
-     274,   276,   281,   283,   287,   292,   297,   303,   309,   319,
-     322,   331,   333,   339,   341,   346,   353,   352,   357,   359,
-     362,   365,   367,   369,   371,   373,   377,   379,   380,   383,
-     389,   398,   406,   411,   417,   419
+       0,   162,   162,   175,   177,   180,   182,   183,   184,   185,
+     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
+     196,   197,   198,   201,   203,   204,   208,   215,   214,   225,
+     224,   237,   236,   242,   242,   247,   256,   271,   273,   274,
+     277,   279,   284,   286,   290,   295,   300,   306,   312,   322,
+     325,   334,   336,   342,   344,   349,   356,   355,   360,   362,
+     365,   368,   370,   372,   374,   376,   380,   382,   383,   386,
+     392,   401,   409,   414,   420,   422
 };
 #endif
 
@@ -460,16 +460,16 @@ static const unsigned short yyrline[] =
    First, the terminals, then, starting at YYNTOKENS, nonterminals. */
 static const char *const yytname[] =
 {
-  "\"end of string\"", "error", "$undefined", "STRING", "CHARACTER", "INT", 
-  "\"%token\"", "\"%nterm\"", "\"%type\"", "\"%destructor\"", 
-  "\"%printer\"", "\"%union\"", "\"%left\"", "\"%right\"", 
-  "\"%nonassoc\"", "\"%expect\"", "\"%start\"", "\"%prec\"", "\"%dprec\"", 
-  "\"%merge\"", "\"%verbose\"", "\"%error-verbose\"", "\"%output\"", 
-  "\"%file-prefix\"", "\"%name-prefix\"", "\"%define\"", 
+  "\"end of file\"", "error", "$undefined", "\"string\"", "\"character\"", 
+  "\"integer\"", "\"%token\"", "\"%nterm\"", "\"%type\"", 
+  "\"%destructor\"", "\"%printer\"", "\"%union\"", "\"%left\"", 
+  "\"%right\"", "\"%nonassoc\"", "\"%expect\"", "\"%start\"", "\"%prec\"", 
+  "\"%dprec\"", "\"%merge\"", "\"%verbose\"", "\"%error-verbose\"", 
+  "\"%output\"", "\"%file-prefix\"", "\"%name-prefix\"", "\"%define\"", 
   "\"%pure-parser\"", "\"%glr-parser\"", "\"%defines\"", "\"%yacc\"", 
   "\"%debug\"", "\"%locations\"", "\"%no-lines\"", "\"%skeleton\"", 
-  "\"%token-table\"", "TYPE", "\"=\"", "\";\"", "\":\"", "\"|\"", 
-  "\"identifier\"", "\"%%\"", "PROLOGUE", "EPILOGUE", "BRACED_CODE", 
+  "\"%token-table\"", "\"type\"", "\"=\"", "\";\"", "\":\"", "\"|\"", 
+  "\"identifier\"", "\"%%\"", "\"%{...%}\"", "\"epilogue\"", "\"{...}\"", 
   "$accept", "input", "declarations", "declaration", 
   "grammar_declaration", "@1", "@2", "symbol_declaration", "@3", "@4", 
   "precedence_declaration", "precedence_declarator", "type.opt", 
@@ -480,6 +480,7 @@ static const char *const yytname[] =
 };
 #endif
 
+# ifdef YYPRINT
 /* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
    token YYLEX-NUM.  */
 static const unsigned short yytoknum[] =
@@ -490,6 +491,7 @@ static const unsigned short yytoknum[] =
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      295,   296,   297,   298,   299
 };
+# endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const unsigned char yyr1[] =
@@ -1267,7 +1269,7 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 161 "parse-gram.y"
+#line 164 "parse-gram.y"
     {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
@@ -1275,99 +1277,99 @@ yyreduce:
     break;
 
   case 6:
-#line 179 "parse-gram.y"
+#line 182 "parse-gram.y"
     { prologue_augment (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 7:
-#line 180 "parse-gram.y"
+#line 183 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 181 "parse-gram.y"
+#line 184 "parse-gram.y"
     { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
 
   case 9:
-#line 182 "parse-gram.y"
+#line 185 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 183 "parse-gram.y"
+#line 186 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 184 "parse-gram.y"
+#line 187 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 185 "parse-gram.y"
+#line 188 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].string; }
     break;
 
   case 13:
-#line 186 "parse-gram.y"
+#line 189 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 14:
-#line 187 "parse-gram.y"
+#line 190 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].string; }
     break;
 
   case 15:
-#line 188 "parse-gram.y"
+#line 191 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 16:
-#line 189 "parse-gram.y"
+#line 192 "parse-gram.y"
     { spec_outfile = yyvsp[0].string; }
     break;
 
   case 17:
-#line 190 "parse-gram.y"
+#line 193 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 18:
-#line 191 "parse-gram.y"
+#line 194 "parse-gram.y"
     { glr_parser = 1; }
     break;
 
   case 19:
-#line 192 "parse-gram.y"
+#line 195 "parse-gram.y"
     { skeleton = yyvsp[0].string; }
     break;
 
   case 20:
-#line 193 "parse-gram.y"
+#line 196 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
   case 21:
-#line 194 "parse-gram.y"
+#line 197 "parse-gram.y"
     { report_flag = 1; }
     break;
 
   case 22:
-#line 195 "parse-gram.y"
+#line 198 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
   case 25:
-#line 202 "parse-gram.y"
+#line 205 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 26:
-#line 206 "parse-gram.y"
+#line 209 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
@@ -1376,12 +1378,12 @@ yyreduce:
     break;
 
   case 27:
-#line 212 "parse-gram.y"
+#line 215 "parse-gram.y"
     { current_braced_code = destructor_braced_code; }
     break;
 
   case 28:
-#line 214 "parse-gram.y"
+#line 217 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1392,12 +1394,12 @@ yyreduce:
     break;
 
   case 29:
-#line 222 "parse-gram.y"
+#line 225 "parse-gram.y"
     { current_braced_code = printer_braced_code; }
     break;
 
   case 30:
-#line 224 "parse-gram.y"
+#line 227 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1408,12 +1410,12 @@ yyreduce:
     break;
 
   case 31:
-#line 234 "parse-gram.y"
+#line 237 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 32:
-#line 235 "parse-gram.y"
+#line 238 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1421,12 +1423,12 @@ yyreduce:
     break;
 
   case 33:
-#line 239 "parse-gram.y"
+#line 242 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 34:
-#line 240 "parse-gram.y"
+#line 243 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1434,7 +1436,7 @@ yyreduce:
     break;
 
   case 35:
-#line 245 "parse-gram.y"
+#line 248 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1444,7 +1446,7 @@ yyreduce:
     break;
 
   case 36:
-#line 255 "parse-gram.y"
+#line 258 "parse-gram.y"
     {
       symbol_list_t *list;
       ++current_prec;
@@ -1459,49 +1461,49 @@ yyreduce:
     break;
 
   case 37:
-#line 269 "parse-gram.y"
+#line 272 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
   case 38:
-#line 270 "parse-gram.y"
+#line 273 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
   case 39:
-#line 271 "parse-gram.y"
+#line 274 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
   case 40:
-#line 275 "parse-gram.y"
+#line 278 "parse-gram.y"
     { current_type = NULL;}
     break;
 
   case 41:
-#line 276 "parse-gram.y"
+#line 279 "parse-gram.y"
     { current_type = yyvsp[0].string; }
     break;
 
   case 42:
-#line 282 "parse-gram.y"
+#line 285 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 43:
-#line 283 "parse-gram.y"
+#line 286 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 44:
-#line 289 "parse-gram.y"
+#line 292 "parse-gram.y"
     {
        current_type = yyvsp[0].string;
      }
     break;
 
   case 45:
-#line 293 "parse-gram.y"
+#line 296 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
@@ -1509,7 +1511,7 @@ yyreduce:
     break;
 
   case 46:
-#line 298 "parse-gram.y"
+#line 301 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1518,7 +1520,7 @@ yyreduce:
     break;
 
   case 47:
-#line 304 "parse-gram.y"
+#line 307 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1527,7 +1529,7 @@ yyreduce:
     break;
 
   case 48:
-#line 310 "parse-gram.y"
+#line 313 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1537,17 +1539,17 @@ yyreduce:
     break;
 
   case 49:
-#line 321 "parse-gram.y"
+#line 324 "parse-gram.y"
     {;}
     break;
 
   case 50:
-#line 323 "parse-gram.y"
+#line 326 "parse-gram.y"
     {;}
     break;
 
   case 54:
-#line 342 "parse-gram.y"
+#line 345 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
@@ -1555,84 +1557,84 @@ yyreduce:
     break;
 
   case 55:
-#line 347 "parse-gram.y"
+#line 350 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 56:
-#line 353 "parse-gram.y"
+#line 356 "parse-gram.y"
     { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
     break;
 
   case 57:
-#line 354 "parse-gram.y"
+#line 357 "parse-gram.y"
     {;}
     break;
 
   case 58:
-#line 358 "parse-gram.y"
+#line 361 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 59:
-#line 359 "parse-gram.y"
+#line 362 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 60:
-#line 364 "parse-gram.y"
+#line 367 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 61:
-#line 366 "parse-gram.y"
+#line 369 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 62:
-#line 368 "parse-gram.y"
+#line 371 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 63:
-#line 370 "parse-gram.y"
+#line 373 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 64:
-#line 372 "parse-gram.y"
+#line 375 "parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
   case 65:
-#line 374 "parse-gram.y"
+#line 377 "parse-gram.y"
     { grammar_current_rule_merge_set (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 66:
-#line 378 "parse-gram.y"
+#line 381 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 67:
-#line 379 "parse-gram.y"
+#line 382 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 68:
-#line 380 "parse-gram.y"
+#line 383 "parse-gram.y"
     { yyval.symbol = symbol_get (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 69:
-#line 385 "parse-gram.y"
+#line 388 "parse-gram.y"
     { yyval.string = yyvsp[0].string; }
     break;
 
   case 70:
-#line 391 "parse-gram.y"
+#line 394 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].string, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
@@ -1640,7 +1642,7 @@ yyreduce:
     break;
 
   case 71:
-#line 400 "parse-gram.y"
+#line 403 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
@@ -1648,14 +1650,14 @@ yyreduce:
     break;
 
   case 72:
-#line 408 "parse-gram.y"
+#line 411 "parse-gram.y"
     {
       yyval.string = xstrdup ("");
     }
     break;
 
   case 73:
-#line 412 "parse-gram.y"
+#line 415 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string;
     }
@@ -1664,8 +1666,8 @@ yyreduce:
 
     }
 
-/* Line 1079 of /tmp/prefix/share/bison/yacc.c.  */
-#line 1669 "parse-gram.c"
+/* Line 1081 of /usr/local/share/bison/yacc.c.  */
+#line 1671 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1837,7 +1839,7 @@ yyreturn:
 }
 
 
-#line 421 "parse-gram.y"
+#line 424 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
