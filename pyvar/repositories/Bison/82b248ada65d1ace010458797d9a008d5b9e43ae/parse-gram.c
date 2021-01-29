@@ -166,7 +166,7 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 1 "parse-gram.y"
+#line 1 "../../src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
@@ -215,10 +215,6 @@ static YYLTYPE lloc_default (YYLTYPE const *, int);
         gram_error (&yylloc, Msg)
 static void gram_error (location const *, char const *);
 
-#define YYPRINT(File, Type, Value) \
-	print_token_value (File, Type, &Value)
-static void print_token_value (FILE *, int, YYSTYPE const *);
-
 static void add_param (char const *, char *, location);
 
 symbol_class current_class = unknown_sym;
@@ -243,7 +239,7 @@ int current_prec = 0;
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 82 "parse-gram.y"
+#line 79 "../../src/parse-gram.y"
 typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
@@ -253,7 +249,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 191 of yacc.c.  */
-#line 257 "parse-gram.c"
+#line 253 "../../src/parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -277,7 +273,7 @@ typedef struct YYLTYPE
 
 
 /* Line 214 of yacc.c.  */
-#line 281 "parse-gram.c"
+#line 277 "../../src/parse-gram.c"
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
 # define YYSIZE_T __SIZE_TYPE__
@@ -516,14 +512,14 @@ static const yysigned_char yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short int yyrline[] =
 {
-       0,   175,   175,   183,   185,   189,   190,   191,   192,   193,
-     194,   195,   196,   197,   198,   203,   207,   208,   209,   210,
-     211,   212,   213,   214,   215,   216,   217,   218,   219,   223,
-     224,   225,   229,   235,   242,   249,   253,   260,   260,   265,
-     265,   270,   280,   295,   296,   297,   301,   302,   308,   309,
-     314,   318,   323,   329,   335,   346,   347,   356,   357,   363,
-     364,   369,   376,   376,   380,   381,   382,   387,   388,   390,
-     392,   394,   396,   401,   402,   406,   412,   421,   426,   428
+       0,   188,   188,   196,   198,   202,   203,   204,   205,   206,
+     207,   208,   209,   210,   211,   216,   220,   221,   222,   223,
+     224,   225,   226,   227,   228,   229,   230,   231,   232,   236,
+     237,   238,   242,   248,   255,   262,   266,   273,   273,   278,
+     278,   283,   293,   308,   309,   310,   314,   315,   321,   322,
+     327,   331,   336,   342,   348,   359,   360,   369,   370,   376,
+     377,   382,   389,   389,   393,   394,   395,   400,   401,   403,
+     405,   407,   409,   414,   415,   419,   425,   434,   439,   441
 };
 #endif
 
@@ -1000,6 +996,96 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
 # endif
   switch (yytype)
     {
+      case 3: /* "\"string\"" */
+#line 165 "../../src/parse-gram.y"
+        { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
+#line 1003 "../../src/parse-gram.c"
+        break;
+      case 4: /* "\"integer\"" */
+#line 178 "../../src/parse-gram.y"
+        { fprintf (stderr, "%d", (yyvaluep->integer)); };
+#line 1008 "../../src/parse-gram.c"
+        break;
+      case 8: /* "\"%destructor {...}\"" */
+#line 167 "../../src/parse-gram.y"
+        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1013 "../../src/parse-gram.c"
+        break;
+      case 9: /* "\"%printer {...}\"" */
+#line 171 "../../src/parse-gram.y"
+        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1018 "../../src/parse-gram.c"
+        break;
+      case 10: /* "\"%union {...}\"" */
+#line 172 "../../src/parse-gram.y"
+        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1023 "../../src/parse-gram.c"
+        break;
+      case 26: /* "\"%initial-action {...}\"" */
+#line 168 "../../src/parse-gram.y"
+        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1028 "../../src/parse-gram.c"
+        break;
+      case 27: /* "\"%lex-param {...}\"" */
+#line 169 "../../src/parse-gram.y"
+        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1033 "../../src/parse-gram.c"
+        break;
+      case 34: /* "\"%parse-param {...}\"" */
+#line 170 "../../src/parse-gram.y"
+        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1038 "../../src/parse-gram.c"
+        break;
+      case 41: /* "\"type\"" */
+#line 176 "../../src/parse-gram.y"
+        { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
+#line 1043 "../../src/parse-gram.c"
+        break;
+      case 45: /* "\"identifier\"" */
+#line 180 "../../src/parse-gram.y"
+        { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
+#line 1048 "../../src/parse-gram.c"
+        break;
+      case 46: /* "\"identifier:\"" */
+#line 182 "../../src/parse-gram.y"
+        { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
+#line 1053 "../../src/parse-gram.c"
+        break;
+      case 48: /* "\"%{...%}\"" */
+#line 174 "../../src/parse-gram.y"
+        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1058 "../../src/parse-gram.c"
+        break;
+      case 49: /* "\"epilogue\"" */
+#line 174 "../../src/parse-gram.y"
+        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1063 "../../src/parse-gram.c"
+        break;
+      case 50: /* "\"{...}\"" */
+#line 173 "../../src/parse-gram.y"
+        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1068 "../../src/parse-gram.c"
+        break;
+      case 71: /* "symbol" */
+#line 180 "../../src/parse-gram.y"
+        { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
+#line 1073 "../../src/parse-gram.c"
+        break;
+      case 72: /* "action" */
+#line 173 "../../src/parse-gram.y"
+        { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+#line 1078 "../../src/parse-gram.c"
+        break;
+      case 73: /* "string_as_id" */
+#line 180 "../../src/parse-gram.y"
+        { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
+#line 1083 "../../src/parse-gram.c"
+        break;
+      case 74: /* "string_content" */
+#line 165 "../../src/parse-gram.y"
+        { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
+#line 1088 "../../src/parse-gram.c"
+        break;
       default:
         break;
     }
@@ -1163,7 +1249,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code. */
-#line 72 "parse-gram.y"
+#line 69 "../../src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1172,7 +1258,7 @@ YYLTYPE yylloc;
   yylloc.start.column = yylloc.end.column = 0;
 }
 /* Line 870 of yacc.c.  */
-#line 1176 "parse-gram.c"
+#line 1262 "../../src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1361,47 +1447,47 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 190 "parse-gram.y"
+#line 203 "../../src/parse-gram.y"
     { prologue_augment ((yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 7:
-#line 191 "parse-gram.y"
+#line 204 "../../src/parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 192 "parse-gram.y"
+#line 205 "../../src/parse-gram.y"
     { muscle_insert ((yyvsp[-1].chars), (yyvsp[0].chars)); }
     break;
 
   case 9:
-#line 193 "parse-gram.y"
+#line 206 "../../src/parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-#line 194 "parse-gram.y"
+#line 207 "../../src/parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 11:
-#line 195 "parse-gram.y"
+#line 208 "../../src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
     break;
 
   case 12:
-#line 196 "parse-gram.y"
+#line 209 "../../src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
     break;
 
   case 13:
-#line 197 "parse-gram.y"
+#line 210 "../../src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
     break;
 
   case 14:
-#line 199 "parse-gram.y"
+#line 212 "../../src/parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
@@ -1409,81 +1495,81 @@ yyreduce:
     break;
 
   case 15:
-#line 204 "parse-gram.y"
+#line 217 "../../src/parse-gram.y"
     {
     muscle_code_grow ("initial_action", (yyvsp[0].chars), (yylsp[0]));
   }
     break;
 
   case 16:
-#line 207 "parse-gram.y"
+#line 220 "../../src/parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 17:
-#line 208 "parse-gram.y"
+#line 221 "../../src/parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 18:
-#line 209 "parse-gram.y"
+#line 222 "../../src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
     break;
 
   case 19:
-#line 210 "parse-gram.y"
+#line 223 "../../src/parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 20:
-#line 211 "parse-gram.y"
+#line 224 "../../src/parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 21:
-#line 212 "parse-gram.y"
+#line 225 "../../src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
     break;
 
   case 22:
-#line 213 "parse-gram.y"
+#line 226 "../../src/parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 23:
-#line 214 "parse-gram.y"
+#line 227 "../../src/parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 24:
-#line 215 "parse-gram.y"
+#line 228 "../../src/parse-gram.y"
     { skeleton = (yyvsp[0].chars); }
     break;
 
   case 25:
-#line 216 "parse-gram.y"
+#line 229 "../../src/parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 26:
-#line 217 "parse-gram.y"
+#line 230 "../../src/parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 27:
-#line 218 "parse-gram.y"
+#line 231 "../../src/parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 31:
-#line 226 "parse-gram.y"
+#line 239 "../../src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
     break;
 
   case 32:
-#line 230 "parse-gram.y"
+#line 243 "../../src/parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", (yylsp[0]).start.line);
@@ -1492,7 +1578,7 @@ yyreduce:
     break;
 
   case 33:
-#line 236 "parse-gram.y"
+#line 249 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1502,7 +1588,7 @@ yyreduce:
     break;
 
   case 34:
-#line 243 "parse-gram.y"
+#line 256 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1512,26 +1598,26 @@ yyreduce:
     break;
 
   case 35:
-#line 250 "parse-gram.y"
+#line 263 "../../src/parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 36:
-#line 254 "parse-gram.y"
+#line 267 "../../src/parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 37:
-#line 260 "parse-gram.y"
+#line 273 "../../src/parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 38:
-#line 261 "parse-gram.y"
+#line 274 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1539,12 +1625,12 @@ yyreduce:
     break;
 
   case 39:
-#line 265 "parse-gram.y"
+#line 278 "../../src/parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 40:
-#line 266 "parse-gram.y"
+#line 279 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1552,7 +1638,7 @@ yyreduce:
     break;
 
   case 41:
-#line 271 "parse-gram.y"
+#line 284 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1562,7 +1648,7 @@ yyreduce:
     break;
 
   case 42:
-#line 281 "parse-gram.y"
+#line 294 "../../src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1577,49 +1663,49 @@ yyreduce:
     break;
 
   case 43:
-#line 295 "parse-gram.y"
+#line 308 "../../src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 44:
-#line 296 "parse-gram.y"
+#line 309 "../../src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 45:
-#line 297 "parse-gram.y"
+#line 310 "../../src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 46:
-#line 301 "parse-gram.y"
+#line 314 "../../src/parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 47:
-#line 302 "parse-gram.y"
+#line 315 "../../src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); }
     break;
 
   case 48:
-#line 308 "parse-gram.y"
+#line 321 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 49:
-#line 309 "parse-gram.y"
+#line 322 "../../src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 50:
-#line 315 "parse-gram.y"
+#line 328 "../../src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
      }
     break;
 
   case 51:
-#line 319 "parse-gram.y"
+#line 332 "../../src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]));
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
@@ -1627,7 +1713,7 @@ yyreduce:
     break;
 
   case 52:
-#line 324 "parse-gram.y"
+#line 337 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]));
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
@@ -1636,7 +1722,7 @@ yyreduce:
     break;
 
   case 53:
-#line 330 "parse-gram.y"
+#line 343 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]));
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
@@ -1645,7 +1731,7 @@ yyreduce:
     break;
 
   case 54:
-#line 336 "parse-gram.y"
+#line 349 "../../src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]));
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -1655,7 +1741,7 @@ yyreduce:
     break;
 
   case 60:
-#line 365 "parse-gram.y"
+#line 378 "../../src/parse-gram.y"
     {
       if (yacc_flag)
 	complain_at ((yyloc), _("POSIX forbids declarations in the grammar"));
@@ -1663,74 +1749,74 @@ yyreduce:
     break;
 
   case 61:
-#line 370 "parse-gram.y"
+#line 383 "../../src/parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 62:
-#line 376 "parse-gram.y"
+#line 389 "../../src/parse-gram.y"
     { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
     break;
 
   case 64:
-#line 380 "parse-gram.y"
+#line 393 "../../src/parse-gram.y"
     { grammar_rule_end ((yylsp[0])); }
     break;
 
   case 65:
-#line 381 "parse-gram.y"
+#line 394 "../../src/parse-gram.y"
     { grammar_rule_end ((yylsp[0])); }
     break;
 
   case 67:
-#line 387 "parse-gram.y"
+#line 400 "../../src/parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 68:
-#line 389 "parse-gram.y"
+#line 402 "../../src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 69:
-#line 391 "parse-gram.y"
+#line 404 "../../src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 70:
-#line 393 "parse-gram.y"
+#line 406 "../../src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 71:
-#line 395 "parse-gram.y"
+#line 408 "../../src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
     break;
 
   case 72:
-#line 397 "parse-gram.y"
+#line 410 "../../src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
     break;
 
   case 73:
-#line 401 "parse-gram.y"
+#line 414 "../../src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
     break;
 
   case 74:
-#line 402 "parse-gram.y"
+#line 415 "../../src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
     break;
 
   case 75:
-#line 407 "parse-gram.y"
+#line 420 "../../src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].chars); }
     break;
 
   case 76:
-#line 413 "parse-gram.y"
+#line 426 "../../src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]));
@@ -1738,12 +1824,12 @@ yyreduce:
     break;
 
   case 77:
-#line 422 "parse-gram.y"
+#line 435 "../../src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].chars); }
     break;
 
   case 79:
-#line 429 "parse-gram.y"
+#line 442 "../../src/parse-gram.y"
     {
       muscle_code_grow ("epilogue", (yyvsp[0].chars), (yylsp[0]));
       scanner_last_string_free ();
@@ -1755,7 +1841,7 @@ yyreduce:
     }
 
 /* Line 1066 of yacc.c.  */
-#line 1759 "parse-gram.c"
+#line 1845 "../../src/parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -2032,7 +2118,7 @@ yyreturn:
 }
 
 
-#line 435 "parse-gram.y"
+#line 448 "../../src/parse-gram.y"
 
 
 
@@ -2117,49 +2203,6 @@ add_param (char const *type, char *decl, location loc)
   scanner_last_string_free ();
 }
 
-/*----------------------------------------------------.
-| When debugging the parser, display tokens' values.  |
-`----------------------------------------------------*/
-
-static void
-print_token_value (FILE *file, int type, YYSTYPE const *value)
-{
-  fputc (' ', file);
-  switch (type)
-    {
-    case ID:
-      fprintf (file, " = %s", value->symbol->tag);
-      break;
-
-    case INT:
-      fprintf (file, " = %d", value->integer);
-      break;
-
-    case STRING:
-      fprintf (file, " = \"%s\"", value->chars);
-      break;
-
-    case TYPE:
-      fprintf (file, " = <%s>", value->uniqstr);
-      break;
-
-    case BRACED_CODE:
-    case PERCENT_DESTRUCTOR:
-    case PERCENT_LEX_PARAM:
-    case PERCENT_PARSE_PARAM:
-    case PERCENT_PRINTER:
-    case PERCENT_UNION:
-    case PROLOGUE:
-    case EPILOGUE:
-      fprintf (file, " = {{ %s }}", value->chars);
-      break;
-
-    default:
-      fprintf (file, "unknown token type");
-      break;
-    }
-}
-
 static void
 gram_error (location const *loc, char const *msg)
 {
