@@ -223,63 +223,6 @@ static int current_prec = 0;
      PERCENT_UNION = 311
    };
 #endif
-/* Tokens.  */
-#define GRAM_EOF 0
-#define STRING 258
-#define INT 259
-#define PERCENT_TOKEN 260
-#define PERCENT_NTERM 261
-#define PERCENT_TYPE 262
-#define PERCENT_DESTRUCTOR 263
-#define PERCENT_PRINTER 264
-#define PERCENT_LEFT 265
-#define PERCENT_RIGHT 266
-#define PERCENT_NONASSOC 267
-#define PERCENT_PREC 268
-#define PERCENT_DPREC 269
-#define PERCENT_MERGE 270
-#define PERCENT_AFTER_HEADER 271
-#define PERCENT_BEFORE_HEADER 272
-#define PERCENT_DEBUG 273
-#define PERCENT_DEFAULT_PREC 274
-#define PERCENT_DEFINE 275
-#define PERCENT_DEFINES 276
-#define PERCENT_END_HEADER 277
-#define PERCENT_ERROR_VERBOSE 278
-#define PERCENT_EXPECT 279
-#define PERCENT_EXPECT_RR 280
-#define PERCENT_FILE_PREFIX 281
-#define PERCENT_GLR_PARSER 282
-#define PERCENT_INITIAL_ACTION 283
-#define PERCENT_LEX_PARAM 284
-#define PERCENT_LOCATIONS 285
-#define PERCENT_NAME_PREFIX 286
-#define PERCENT_NO_DEFAULT_PREC 287
-#define PERCENT_NO_LINES 288
-#define PERCENT_NONDETERMINISTIC_PARSER 289
-#define PERCENT_OUTPUT 290
-#define PERCENT_PARSE_PARAM 291
-#define PERCENT_PURE_PARSER 292
-#define PERCENT_REQUIRE 293
-#define PERCENT_SKELETON 294
-#define PERCENT_START 295
-#define PERCENT_START_HEADER 296
-#define PERCENT_TOKEN_TABLE 297
-#define PERCENT_VERBOSE 298
-#define PERCENT_YACC 299
-#define BRACED_CODE 300
-#define CHAR 301
-#define EPILOGUE 302
-#define EQUAL 303
-#define ID 304
-#define ID_COLON 305
-#define PERCENT_PERCENT 306
-#define PIPE 307
-#define PROLOGUE 308
-#define SEMICOLON 309
-#define TYPE 310
-#define PERCENT_UNION 311
-
 
 
 
@@ -297,7 +240,7 @@ typedef union YYSTYPE
   unsigned char character;
 }
 /* Line 195 of yacc.c.  */
-#line 301 "parse-gram.c"
+#line 244 "parse-gram.c"
 	YYSTYPE;
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -321,7 +264,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 219 of yacc.c.  */
-#line 325 "parse-gram.c"
+#line 268 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -396,14 +339,14 @@ typedef short int yytype_int16;
 #if (defined __STDC__ || defined __C99__FUNC__ \
      || defined __cplusplus || defined _MSC_VER)
 static int
-YYID (int i)
+YYID (int yyi)
 #else
 static int
-YYID (i)
-    int i;
+YYID (yyi)
+    int yyi;
 #endif
 {
-  return i;
+  return yyi;
 }
 #endif
 
@@ -1001,98 +944,98 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 174 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 /* Line 668 of yacc.c.  */
-#line 1005 "parse-gram.c"
+#line 948 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 /* Line 668 of yacc.c.  */
 #line 184 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 /* Line 668 of yacc.c.  */
-#line 1012 "parse-gram.c"
+#line 955 "parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
 /* Line 668 of yacc.c.  */
 #line 176 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 668 of yacc.c.  */
-#line 1019 "parse-gram.c"
+#line 962 "parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
 /* Line 668 of yacc.c.  */
 #line 171 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 /* Line 668 of yacc.c.  */
-#line 1026 "parse-gram.c"
+#line 969 "parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
 /* Line 668 of yacc.c.  */
 #line 176 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 668 of yacc.c.  */
-#line 1033 "parse-gram.c"
+#line 976 "parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
 /* Line 668 of yacc.c.  */
 #line 180 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 /* Line 668 of yacc.c.  */
-#line 1040 "parse-gram.c"
+#line 983 "parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
 /* Line 668 of yacc.c.  */
 #line 181 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 /* Line 668 of yacc.c.  */
-#line 1047 "parse-gram.c"
+#line 990 "parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
 /* Line 668 of yacc.c.  */
 #line 176 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 /* Line 668 of yacc.c.  */
-#line 1054 "parse-gram.c"
+#line 997 "parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
 /* Line 668 of yacc.c.  */
 #line 179 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 /* Line 668 of yacc.c.  */
-#line 1061 "parse-gram.c"
+#line 1004 "parse-gram.c"
 	break;
       case 78: /* "id" */
 /* Line 668 of yacc.c.  */
 #line 187 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 668 of yacc.c.  */
-#line 1068 "parse-gram.c"
+#line 1011 "parse-gram.c"
 	break;
       case 79: /* "id_colon" */
 /* Line 668 of yacc.c.  */
 #line 188 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 /* Line 668 of yacc.c.  */
-#line 1075 "parse-gram.c"
+#line 1018 "parse-gram.c"
 	break;
       case 80: /* "symbol" */
 /* Line 668 of yacc.c.  */
 #line 187 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 668 of yacc.c.  */
-#line 1082 "parse-gram.c"
+#line 1025 "parse-gram.c"
 	break;
       case 81: /* "string_as_id" */
 /* Line 668 of yacc.c.  */
 #line 187 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 /* Line 668 of yacc.c.  */
-#line 1089 "parse-gram.c"
+#line 1032 "parse-gram.c"
 	break;
       case 82: /* "string_content" */
 /* Line 668 of yacc.c.  */
 #line 174 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 /* Line 668 of yacc.c.  */
-#line 1096 "parse-gram.c"
+#line 1039 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1136,17 +1079,20 @@ yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
 #if (defined __STDC__ || defined __C99__FUNC__ \
      || defined __cplusplus || defined _MSC_VER)
 static void
-yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
+yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
 #else
 static void
-yy_stack_print (bottom, top)
-    yytype_int16 *bottom;
-    yytype_int16 *top;
+yy_stack_print (yybottom, yytop)
+    yytype_int16 *yybottom;
+    yytype_int16 *yytop;
 #endif
 {
   YYFPRINTF (stderr, "Stack now");
-  for (; bottom <= top; ++bottom)
-    YYFPRINTF (stderr, " %d", *bottom);
+  for (; yybottom <= yytop; yybottom++)
+    {
+      int yybot = *yybottom;
+      YYFPRINTF (stderr, " %d", yybot);
+    }
   YYFPRINTF (stderr, "\n");
 }
 
@@ -1602,7 +1548,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code.  */
-  /* Line 1077 of yacc.c.  */
+  /* Line 1080 of yacc.c.  */
 #line 81 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1610,8 +1556,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1077 of yacc.c.  */
-#line 1615 "parse-gram.c"
+/* Line 1080 of yacc.c.  */
+#line 1561 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1796,7 +1742,7 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 211 "parse-gram.y"
     {
       prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), typed);
@@ -1804,7 +1750,7 @@ yyreduce:
     break;
 
   case 7:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 215 "parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
@@ -1814,7 +1760,7 @@ yyreduce:
     break;
 
   case 8:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 221 "parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
@@ -1824,13 +1770,13 @@ yyreduce:
     break;
 
   case 9:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 226 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 10:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 228 "parse-gram.y"
     {
       static char one[] = "1";
@@ -1839,19 +1785,19 @@ yyreduce:
     break;
 
   case 11:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 232 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 12:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 233 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 13:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 235 "parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
@@ -1861,31 +1807,31 @@ yyreduce:
     break;
 
   case 14:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 240 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 15:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 241 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 16:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 242 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 17:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 243 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 18:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 245 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -1894,7 +1840,7 @@ yyreduce:
     break;
 
   case 19:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 250 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
@@ -1902,67 +1848,67 @@ yyreduce:
     break;
 
   case 20:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 253 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 21:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 254 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 22:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 255 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 256 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 257 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 258 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 26:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 259 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 27:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 260 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 28:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 261 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 29:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 262 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 30:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 264 "parse-gram.y"
     {
       /* Remove the '{', and replace the '}' with '\n'.  */
@@ -1972,25 +1918,25 @@ yyreduce:
     break;
 
   case 31:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 269 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 270 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 33:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 271 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 279 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -1998,7 +1944,7 @@ yyreduce:
     break;
 
   case 38:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 283 "parse-gram.y"
     {
       symbol_list *list;
@@ -2010,7 +1956,7 @@ yyreduce:
     break;
 
   case 39:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 291 "parse-gram.y"
     {
       symbol_list *list;
@@ -2022,7 +1968,7 @@ yyreduce:
     break;
 
   case 40:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 299 "parse-gram.y"
     {
       default_prec = true;
@@ -2030,7 +1976,7 @@ yyreduce:
     break;
 
   case 41:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 303 "parse-gram.y"
     {
       default_prec = false;
@@ -2038,19 +1984,19 @@ yyreduce:
     break;
 
   case 42:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 316 "parse-gram.y"
     {}
     break;
 
   case 43:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 317 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 44:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 322 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
@@ -2070,13 +2016,13 @@ yyreduce:
     break;
 
   case 45:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 343 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 46:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 344 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2085,13 +2031,13 @@ yyreduce:
     break;
 
   case 47:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 348 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 48:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 349 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2100,7 +2046,7 @@ yyreduce:
     break;
 
   case 49:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 354 "parse-gram.y"
     {
       symbol_list *list;
@@ -2111,7 +2057,7 @@ yyreduce:
     break;
 
   case 50:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 364 "parse-gram.y"
     {
       symbol_list *list;
@@ -2127,49 +2073,49 @@ yyreduce:
     break;
 
   case 51:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 378 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 52:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 379 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 53:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 380 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 54:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 384 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 55:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 385 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 56:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 390 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 57:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 391 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 58:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 397 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2177,7 +2123,7 @@ yyreduce:
     break;
 
   case 59:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 401 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2186,7 +2132,7 @@ yyreduce:
     break;
 
   case 60:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 406 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2196,7 +2142,7 @@ yyreduce:
     break;
 
   case 61:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 412 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2206,7 +2152,7 @@ yyreduce:
     break;
 
   case 62:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 418 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2217,7 +2163,7 @@ yyreduce:
     break;
 
   case 69:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 448 "parse-gram.y"
     {
       yyerrok;
@@ -2225,67 +2171,67 @@ yyreduce:
     break;
 
   case 70:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 454 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 72:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 458 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 73:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 459 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 75:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 465 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 76:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 467 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 77:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 469 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 78:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 471 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 79:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 473 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 80:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 475 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 81:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 488 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 82:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 490 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2295,13 +2241,13 @@ yyreduce:
     break;
 
   case 83:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 498 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 86:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 510 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2310,13 +2256,13 @@ yyreduce:
     break;
 
   case 87:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 519 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 89:
-/* Line 1265 of yacc.c.  */
+/* Line 1268 of yacc.c.  */
 #line 526 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
@@ -2325,8 +2271,8 @@ yyreduce:
     break;
 
 
-/* Line 1265 of yacc.c.  */
-#line 2330 "parse-gram.c"
+/* Line 1268 of yacc.c.  */
+#line 2276 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2546,7 +2492,7 @@ yyreturn:
 }
 
 
-/* Line 1485 of yacc.c.  */
+/* Line 1488 of yacc.c.  */
 #line 532 "parse-gram.y"
 
 
