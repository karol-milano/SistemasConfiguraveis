@@ -130,7 +130,7 @@ static char const *char_name (char);
 static void add_param (char const *, char *, location);
 
 static symbol_class current_class = unknown_sym;
-static uniqstr current_type = 0;
+static uniqstr current_type = NULL;
 static symbol *current_lhs;
 static location current_lhs_location;
 static int current_prec = 0;
@@ -223,12 +223,69 @@ static int current_prec = 0;
      PERCENT_UNION = 311
    };
 #endif
+/* Tokens.  */
+#define GRAM_EOF 0
+#define STRING 258
+#define INT 259
+#define PERCENT_TOKEN 260
+#define PERCENT_NTERM 261
+#define PERCENT_TYPE 262
+#define PERCENT_DESTRUCTOR 263
+#define PERCENT_PRINTER 264
+#define PERCENT_LEFT 265
+#define PERCENT_RIGHT 266
+#define PERCENT_NONASSOC 267
+#define PERCENT_PREC 268
+#define PERCENT_DPREC 269
+#define PERCENT_MERGE 270
+#define PERCENT_AFTER_HEADER 271
+#define PERCENT_BEFORE_HEADER 272
+#define PERCENT_DEBUG 273
+#define PERCENT_DEFAULT_PREC 274
+#define PERCENT_DEFINE 275
+#define PERCENT_DEFINES 276
+#define PERCENT_END_HEADER 277
+#define PERCENT_ERROR_VERBOSE 278
+#define PERCENT_EXPECT 279
+#define PERCENT_EXPECT_RR 280
+#define PERCENT_FILE_PREFIX 281
+#define PERCENT_GLR_PARSER 282
+#define PERCENT_INITIAL_ACTION 283
+#define PERCENT_LEX_PARAM 284
+#define PERCENT_LOCATIONS 285
+#define PERCENT_NAME_PREFIX 286
+#define PERCENT_NO_DEFAULT_PREC 287
+#define PERCENT_NO_LINES 288
+#define PERCENT_NONDETERMINISTIC_PARSER 289
+#define PERCENT_OUTPUT 290
+#define PERCENT_PARSE_PARAM 291
+#define PERCENT_PURE_PARSER 292
+#define PERCENT_REQUIRE 293
+#define PERCENT_SKELETON 294
+#define PERCENT_START 295
+#define PERCENT_START_HEADER 296
+#define PERCENT_TOKEN_TABLE 297
+#define PERCENT_VERBOSE 298
+#define PERCENT_YACC 299
+#define BRACED_CODE 300
+#define CHAR 301
+#define EPILOGUE 302
+#define EQUAL 303
+#define ID 304
+#define ID_COLON 305
+#define PERCENT_PERCENT 306
+#define PIPE 307
+#define PROLOGUE 308
+#define SEMICOLON 309
+#define TYPE 310
+#define PERCENT_UNION 311
+
 
 
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
-/* Line 195 of yacc.c.  */
+/* Line 198 of yacc.c.  */
 #line 90 "parse-gram.y"
 {
   symbol *symbol;
@@ -239,12 +296,12 @@ typedef union YYSTYPE
   uniqstr uniqstr;
   unsigned char character;
 }
-/* Line 195 of yacc.c.  */
-#line 244 "parse-gram.c"
+/* Line 198 of yacc.c.  */
+#line 301 "parse-gram.c"
 	YYSTYPE;
+# define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
-# define YYSTYPE_IS_TRIVIAL 1
 #endif
 
 #if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
@@ -263,8 +320,8 @@ typedef struct YYLTYPE
 
 /* Copy the second part of user declarations.  */
 
-/* Line 219 of yacc.c.  */
-#line 268 "parse-gram.c"
+/* Line 221 of yacc.c.  */
+#line 325 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -589,10 +646,10 @@ static const yytype_uint16 yyrline[] =
      253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      263,   269,   270,   271,   272,   276,   277,   278,   282,   290,
      298,   302,   316,   317,   321,   343,   343,   348,   348,   353,
-     363,   378,   379,   380,   384,   385,   390,   391,   396,   400,
-     405,   411,   417,   428,   429,   438,   439,   445,   446,   447,
-     454,   454,   458,   459,   460,   465,   466,   468,   470,   472,
-     474,   487,   489,   498,   503,   504,   509,   518,   523,   525
+     364,   379,   380,   381,   385,   386,   391,   392,   397,   402,
+     407,   413,   419,   430,   431,   440,   441,   447,   448,   449,
+     456,   456,   460,   461,   462,   467,   468,   470,   472,   474,
+     476,   489,   491,   500,   505,   506,   511,   520,   525,   527
 };
 #endif
 
@@ -940,102 +997,102 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-/* Line 668 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 174 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
-/* Line 668 of yacc.c.  */
-#line 948 "parse-gram.c"
+/* Line 670 of yacc.c.  */
+#line 1005 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
-/* Line 668 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-/* Line 668 of yacc.c.  */
-#line 955 "parse-gram.c"
+/* Line 670 of yacc.c.  */
+#line 1012 "parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
-/* Line 668 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 176 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-/* Line 668 of yacc.c.  */
-#line 962 "parse-gram.c"
+/* Line 670 of yacc.c.  */
+#line 1019 "parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
-/* Line 668 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 171 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
-/* Line 668 of yacc.c.  */
-#line 969 "parse-gram.c"
+/* Line 670 of yacc.c.  */
+#line 1026 "parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
-/* Line 668 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 176 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-/* Line 668 of yacc.c.  */
-#line 976 "parse-gram.c"
+/* Line 670 of yacc.c.  */
+#line 1033 "parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
-/* Line 668 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 180 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
-/* Line 668 of yacc.c.  */
-#line 983 "parse-gram.c"
+/* Line 670 of yacc.c.  */
+#line 1040 "parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
-/* Line 668 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 181 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
-/* Line 668 of yacc.c.  */
-#line 990 "parse-gram.c"
+/* Line 670 of yacc.c.  */
+#line 1047 "parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
-/* Line 668 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 176 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-/* Line 668 of yacc.c.  */
-#line 997 "parse-gram.c"
+/* Line 670 of yacc.c.  */
+#line 1054 "parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
-/* Line 668 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 179 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-/* Line 668 of yacc.c.  */
-#line 1004 "parse-gram.c"
+/* Line 670 of yacc.c.  */
+#line 1061 "parse-gram.c"
 	break;
       case 78: /* "id" */
-/* Line 668 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 187 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-/* Line 668 of yacc.c.  */
-#line 1011 "parse-gram.c"
+/* Line 670 of yacc.c.  */
+#line 1068 "parse-gram.c"
 	break;
       case 79: /* "id_colon" */
-/* Line 668 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 188 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-/* Line 668 of yacc.c.  */
-#line 1018 "parse-gram.c"
+/* Line 670 of yacc.c.  */
+#line 1075 "parse-gram.c"
 	break;
       case 80: /* "symbol" */
-/* Line 668 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 187 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-/* Line 668 of yacc.c.  */
-#line 1025 "parse-gram.c"
+/* Line 670 of yacc.c.  */
+#line 1082 "parse-gram.c"
 	break;
       case 81: /* "string_as_id" */
-/* Line 668 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 187 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-/* Line 668 of yacc.c.  */
-#line 1032 "parse-gram.c"
+/* Line 670 of yacc.c.  */
+#line 1089 "parse-gram.c"
 	break;
       case 82: /* "string_content" */
-/* Line 668 of yacc.c.  */
+/* Line 670 of yacc.c.  */
 #line 174 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
-/* Line 668 of yacc.c.  */
-#line 1039 "parse-gram.c"
+/* Line 670 of yacc.c.  */
+#line 1096 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1548,7 +1605,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code.  */
-  /* Line 1080 of yacc.c.  */
+  /* Line 1082 of yacc.c.  */
 #line 81 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1556,8 +1613,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1080 of yacc.c.  */
-#line 1561 "parse-gram.c"
+/* Line 1082 of yacc.c.  */
+#line 1618 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1742,15 +1799,15 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 211 "parse-gram.y"
     {
-      prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), typed);
+      prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), union_seen);
     }
     break;
 
   case 7:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 215 "parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
@@ -1760,7 +1817,7 @@ yyreduce:
     break;
 
   case 8:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 221 "parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
@@ -1770,13 +1827,13 @@ yyreduce:
     break;
 
   case 9:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 226 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 10:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 228 "parse-gram.y"
     {
       static char one[] = "1";
@@ -1785,19 +1842,19 @@ yyreduce:
     break;
 
   case 11:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 232 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 12:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 233 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 13:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 235 "parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
@@ -1807,31 +1864,31 @@ yyreduce:
     break;
 
   case 14:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 240 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 15:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 241 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 16:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 242 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 17:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 243 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 18:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 245 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -1840,7 +1897,7 @@ yyreduce:
     break;
 
   case 19:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 250 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
@@ -1848,67 +1905,67 @@ yyreduce:
     break;
 
   case 20:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 253 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 21:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 254 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 22:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 255 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 256 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 257 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 258 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 26:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 259 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 27:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 260 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 28:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 261 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 29:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 262 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 30:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 264 "parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
@@ -1918,25 +1975,25 @@ yyreduce:
     break;
 
   case 31:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 269 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 270 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 33:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 271 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 279 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -1944,7 +2001,7 @@ yyreduce:
     break;
 
   case 38:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 283 "parse-gram.y"
     {
       symbol_list *list;
@@ -1956,7 +2013,7 @@ yyreduce:
     break;
 
   case 39:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 291 "parse-gram.y"
     {
       symbol_list *list;
@@ -1968,7 +2025,7 @@ yyreduce:
     break;
 
   case 40:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 299 "parse-gram.y"
     {
       default_prec = true;
@@ -1976,7 +2033,7 @@ yyreduce:
     break;
 
   case 41:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 303 "parse-gram.y"
     {
       default_prec = false;
@@ -1984,24 +2041,24 @@ yyreduce:
     break;
 
   case 42:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 316 "parse-gram.y"
     {}
     break;
 
   case 43:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 317 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 44:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 322 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
 
-      if (typed)
+      if (union_seen)
 	{
 	  /* Concatenate the union bodies, turning the first one's
 	     trailing '}' into '\n', and omitting the second one's '{'.  */
@@ -2010,19 +2067,19 @@ yyreduce:
 	  body++;
 	}
 
-      typed = true;
+      union_seen = true;
       muscle_code_grow ("stype", body, (yylsp[(3) - (3)]));
     }
     break;
 
   case 45:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 343 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 46:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 344 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2031,13 +2088,13 @@ yyreduce:
     break;
 
   case 47:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 348 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 48:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 349 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2046,9 +2103,10 @@ yyreduce:
     break;
 
   case 49:
-/* Line 1268 of yacc.c.  */
+/* Line 1270 of yacc.c.  */
 #line 354 "parse-gram.y"
     {
+      tag_seen = true;
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
 	symbol_type_set (list->sym, (yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]));
@@ -2057,8 +2115,8 @@ yyreduce:
     break;
 
   case 50:
-/* Line 1268 of yacc.c.  */
-#line 364 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 365 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2073,58 +2131,59 @@ yyreduce:
     break;
 
   case 51:
-/* Line 1268 of yacc.c.  */
-#line 378 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 379 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 52:
-/* Line 1268 of yacc.c.  */
-#line 379 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 380 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 53:
-/* Line 1268 of yacc.c.  */
-#line 380 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 381 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 54:
-/* Line 1268 of yacc.c.  */
-#line 384 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 385 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 55:
-/* Line 1268 of yacc.c.  */
-#line 385 "parse-gram.y"
-    { current_type = (yyvsp[(1) - (1)].uniqstr); }
+/* Line 1270 of yacc.c.  */
+#line 386 "parse-gram.y"
+    { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 56:
-/* Line 1268 of yacc.c.  */
-#line 390 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 391 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 57:
-/* Line 1268 of yacc.c.  */
-#line 391 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 392 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 58:
-/* Line 1268 of yacc.c.  */
-#line 397 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 398 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
+       tag_seen = true;
      }
     break;
 
   case 59:
-/* Line 1268 of yacc.c.  */
-#line 401 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 403 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2132,8 +2191,8 @@ yyreduce:
     break;
 
   case 60:
-/* Line 1268 of yacc.c.  */
-#line 406 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 408 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2142,8 +2201,8 @@ yyreduce:
     break;
 
   case 61:
-/* Line 1268 of yacc.c.  */
-#line 412 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 414 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2152,8 +2211,8 @@ yyreduce:
     break;
 
   case 62:
-/* Line 1268 of yacc.c.  */
-#line 418 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 420 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2163,76 +2222,76 @@ yyreduce:
     break;
 
   case 69:
-/* Line 1268 of yacc.c.  */
-#line 448 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 450 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 70:
-/* Line 1268 of yacc.c.  */
-#line 454 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 456 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 72:
-/* Line 1268 of yacc.c.  */
-#line 458 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 460 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 73:
-/* Line 1268 of yacc.c.  */
-#line 459 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 461 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 75:
-/* Line 1268 of yacc.c.  */
-#line 465 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 467 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 76:
-/* Line 1268 of yacc.c.  */
-#line 467 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 469 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 77:
-/* Line 1268 of yacc.c.  */
-#line 469 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 471 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 78:
-/* Line 1268 of yacc.c.  */
-#line 471 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 473 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 79:
-/* Line 1268 of yacc.c.  */
-#line 473 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 475 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 80:
-/* Line 1268 of yacc.c.  */
-#line 475 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 477 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 81:
-/* Line 1268 of yacc.c.  */
-#line 488 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 490 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 82:
-/* Line 1268 of yacc.c.  */
-#line 490 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 492 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2241,14 +2300,14 @@ yyreduce:
     break;
 
   case 83:
-/* Line 1268 of yacc.c.  */
-#line 498 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 500 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 86:
-/* Line 1268 of yacc.c.  */
-#line 510 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 512 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2256,14 +2315,14 @@ yyreduce:
     break;
 
   case 87:
-/* Line 1268 of yacc.c.  */
-#line 519 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 521 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 89:
-/* Line 1268 of yacc.c.  */
-#line 526 "parse-gram.y"
+/* Line 1270 of yacc.c.  */
+#line 528 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2271,8 +2330,8 @@ yyreduce:
     break;
 
 
-/* Line 1268 of yacc.c.  */
-#line 2276 "parse-gram.c"
+/* Line 1270 of yacc.c.  */
+#line 2335 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2492,8 +2551,8 @@ yyreturn:
 }
 
 
-/* Line 1488 of yacc.c.  */
-#line 532 "parse-gram.y"
+/* Line 1490 of yacc.c.  */
+#line 534 "parse-gram.y"
 
 
 
