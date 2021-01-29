@@ -58,6 +58,9 @@
 /* Push parsers.  */
 #define YYPUSH 0
 
+/* Pull parsers.  */
+#define YYPULL 1
+
 /* Using locations.  */
 #define YYLSP_NEEDED 1
 
@@ -73,11 +76,12 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 164 of yacc.c  */
+/* Line 167 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
-   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007 Free Software Foundation,
+   Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -152,8 +156,8 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 164 of yacc.c  */
-#line 157 "parse-gram.c"
+/* Line 167 of yacc.c  */
+#line 161 "parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -310,8 +314,8 @@ static int current_prec = 0;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 198 of yacc.c  */
-#line 97 "parse-gram.y"
+/* Line 201 of yacc.c  */
+#line 98 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -323,8 +327,8 @@ typedef union YYSTYPE
   unsigned char character;
 }
 
-/* Line 198 of yacc.c  */
-#line 328 "parse-gram.c"
+/* Line 201 of yacc.c  */
+#line 332 "parse-gram.c"
 	YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -348,8 +352,8 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 221 of yacc.c  */
-#line 353 "parse-gram.c"
+/* Line 224 of yacc.c  */
+#line 357 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -674,17 +678,17 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   213,   213,   221,   223,   227,   228,   229,   230,   231,
-     232,   237,   238,   239,   240,   241,   242,   247,   251,   252,
-     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
-     263,   264,   265,   266,   267,   268,   269,   273,   274,   275,
-     279,   287,   295,   299,   303,   304,   305,   306,   317,   318,
-     322,   350,   350,   355,   355,   360,   371,   386,   387,   388,
-     392,   393,   398,   400,   405,   406,   410,   411,   412,   413,
-     418,   423,   428,   434,   440,   451,   452,   461,   462,   468,
-     469,   470,   477,   477,   481,   482,   483,   488,   489,   491,
-     493,   495,   497,   507,   508,   514,   518,   523,   539,   541,
-     550,   555,   556,   561,   568,   570
+       0,   214,   214,   222,   224,   228,   229,   238,   239,   240,
+     241,   246,   247,   248,   249,   250,   251,   256,   265,   266,
+     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
+     277,   278,   279,   280,   281,   282,   283,   287,   288,   289,
+     293,   300,   307,   311,   315,   316,   317,   318,   329,   330,
+     334,   363,   363,   368,   368,   373,   384,   399,   400,   401,
+     405,   406,   411,   413,   418,   419,   423,   424,   425,   426,
+     431,   436,   441,   447,   453,   464,   465,   474,   475,   481,
+     482,   483,   490,   490,   494,   495,   496,   501,   502,   504,
+     506,   508,   510,   520,   521,   527,   531,   536,   556,   558,
+     567,   572,   573,   578,   585,   587
 };
 #endif
 
@@ -1054,147 +1058,147 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 670 of yacc.c  */
-#line 191 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 192 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 670 of yacc.c  */
-#line 1063 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1067 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 670 of yacc.c  */
-#line 202 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 203 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 670 of yacc.c  */
-#line 1072 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1076 "parse-gram.c"
 	break;
       case 48: /* "\"{...}\"" */
 
-/* Line 670 of yacc.c  */
-#line 193 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 670 of yacc.c  */
-#line 1081 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1085 "parse-gram.c"
 	break;
       case 49: /* "\"char\"" */
 
-/* Line 670 of yacc.c  */
-#line 185 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 186 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 670 of yacc.c  */
-#line 1090 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1094 "parse-gram.c"
 	break;
       case 50: /* "\"epilogue\"" */
 
-/* Line 670 of yacc.c  */
-#line 193 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 670 of yacc.c  */
-#line 1099 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1103 "parse-gram.c"
 	break;
       case 52: /* "\"identifier\"" */
 
-/* Line 670 of yacc.c  */
-#line 198 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 199 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 670 of yacc.c  */
-#line 1108 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1112 "parse-gram.c"
 	break;
       case 53: /* "\"identifier:\"" */
 
-/* Line 670 of yacc.c  */
-#line 199 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 670 of yacc.c  */
-#line 1117 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1121 "parse-gram.c"
 	break;
       case 56: /* "\"%{...%}\"" */
 
-/* Line 670 of yacc.c  */
-#line 193 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 670 of yacc.c  */
-#line 1126 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1130 "parse-gram.c"
 	break;
       case 58: /* "\"type\"" */
 
-/* Line 670 of yacc.c  */
-#line 197 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 198 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 670 of yacc.c  */
-#line 1135 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1139 "parse-gram.c"
 	break;
       case 85: /* "content" */
 
-/* Line 670 of yacc.c  */
-#line 193 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 670 of yacc.c  */
-#line 1144 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1148 "parse-gram.c"
 	break;
       case 86: /* "content.opt" */
 
-/* Line 670 of yacc.c  */
-#line 193 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 670 of yacc.c  */
-#line 1153 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1157 "parse-gram.c"
 	break;
       case 87: /* "braceless" */
 
-/* Line 670 of yacc.c  */
-#line 193 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 670 of yacc.c  */
-#line 1162 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1166 "parse-gram.c"
 	break;
       case 88: /* "id" */
 
-/* Line 670 of yacc.c  */
-#line 205 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 206 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 670 of yacc.c  */
-#line 1171 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1175 "parse-gram.c"
 	break;
       case 89: /* "id_colon" */
 
-/* Line 670 of yacc.c  */
-#line 206 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 207 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 670 of yacc.c  */
-#line 1180 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1184 "parse-gram.c"
 	break;
       case 90: /* "symbol" */
 
-/* Line 670 of yacc.c  */
-#line 205 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 206 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 670 of yacc.c  */
-#line 1189 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1193 "parse-gram.c"
 	break;
       case 91: /* "string_as_id" */
 
-/* Line 670 of yacc.c  */
-#line 205 "parse-gram.y"
+/* Line 673 of yacc.c  */
+#line 206 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 670 of yacc.c  */
-#line 1198 "parse-gram.c"
+/* Line 673 of yacc.c  */
+#line 1202 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1708,8 +1712,8 @@ YYLTYPE yylloc;
 
   /* User initialization code.  */
   
-/* Line 1082 of yacc.c  */
-#line 89 "parse-gram.y"
+/* Line 1085 of yacc.c  */
+#line 90 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1717,8 +1721,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1082 of yacc.c  */
-#line 1722 "parse-gram.c"
+/* Line 1085 of yacc.c  */
+#line 1726 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1903,36 +1907,43 @@ yyreduce:
     {
         case 6:
 
-/* Line 1269 of yacc.c  */
-#line 228 "parse-gram.y"
-    { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])), (yylsp[(1) - (1)]), union_seen); }
+/* Line 1272 of yacc.c  */
+#line 230 "parse-gram.y"
+    {
+      code_props plain_code;
+      code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
+      code_props_translate_code (&plain_code);
+      gram_scanner_last_string_free ();
+      prologue_augment (plain_code.code, (yylsp[(1) - (1)]), union_seen);
+      code_scanner_last_string_free ();
+    }
     break;
 
   case 7:
 
-/* Line 1269 of yacc.c  */
-#line 229 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 238 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1269 of yacc.c  */
-#line 230 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 239 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 9:
 
-/* Line 1269 of yacc.c  */
-#line 231 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 240 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1269 of yacc.c  */
-#line 233 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 242 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1941,43 +1952,43 @@ yyreduce:
 
   case 11:
 
-/* Line 1269 of yacc.c  */
-#line 237 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 246 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1269 of yacc.c  */
-#line 238 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 247 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1269 of yacc.c  */
-#line 239 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 248 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1269 of yacc.c  */
-#line 240 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 249 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1269 of yacc.c  */
-#line 241 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 250 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1269 of yacc.c  */
-#line 243 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 252 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1986,143 +1997,148 @@ yyreduce:
 
   case 17:
 
-/* Line 1269 of yacc.c  */
-#line 248 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 257 "parse-gram.y"
     {
-      muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
+      code_props action;
+      code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
+      code_props_translate_code (&action);
+      gram_scanner_last_string_free ();
+      muscle_code_grow ("initial_action", action.code, (yylsp[(2) - (2)]));
+      code_scanner_last_string_free ();
     }
     break;
 
   case 18:
 
-/* Line 1269 of yacc.c  */
-#line 251 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 265 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1269 of yacc.c  */
-#line 252 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 266 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1269 of yacc.c  */
-#line 253 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 267 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1269 of yacc.c  */
-#line 254 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 268 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1269 of yacc.c  */
-#line 255 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 269 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1269 of yacc.c  */
-#line 256 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 270 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1269 of yacc.c  */
-#line 257 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 271 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1269 of yacc.c  */
-#line 258 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 272 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1269 of yacc.c  */
-#line 259 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 273 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1269 of yacc.c  */
-#line 260 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 274 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1269 of yacc.c  */
-#line 261 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 275 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 29:
 
-/* Line 1269 of yacc.c  */
-#line 262 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 276 "parse-gram.y"
     { push_parser = true; pull_parser = false; }
     break;
 
   case 30:
 
-/* Line 1269 of yacc.c  */
-#line 263 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 277 "parse-gram.y"
     { push_parser = true; pull_parser = true; }
     break;
 
   case 31:
 
-/* Line 1269 of yacc.c  */
-#line 264 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 278 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 32:
 
-/* Line 1269 of yacc.c  */
-#line 265 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 279 "parse-gram.y"
     { skeleton_arg ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 33:
 
-/* Line 1269 of yacc.c  */
-#line 266 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 280 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 34:
 
-/* Line 1269 of yacc.c  */
-#line 267 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 281 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 35:
 
-/* Line 1269 of yacc.c  */
-#line 268 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 282 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 39:
 
-/* Line 1269 of yacc.c  */
-#line 276 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 290 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2130,34 +2146,32 @@ yyreduce:
 
   case 40:
 
-/* Line 1269 of yacc.c  */
-#line 280 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 294 "parse-gram.y"
     {
       symbol_list *list;
-      const char *action = translate_symbol_action ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
-	symbol_list_destructor_set (list, action, (yylsp[(2) - (3)]));
+	symbol_list_destructor_set (list, (yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
       symbol_list_free ((yyvsp[(3) - (3)].list));
     }
     break;
 
   case 41:
 
-/* Line 1269 of yacc.c  */
-#line 288 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 301 "parse-gram.y"
     {
       symbol_list *list;
-      const char *action = translate_symbol_action ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
-	symbol_list_printer_set (list, action, (yylsp[(2) - (3)]));
+	symbol_list_printer_set (list, (yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
       symbol_list_free ((yyvsp[(3) - (3)].list));
     }
     break;
 
   case 42:
 
-/* Line 1269 of yacc.c  */
-#line 296 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 308 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2165,8 +2179,8 @@ yyreduce:
 
   case 43:
 
-/* Line 1269 of yacc.c  */
-#line 300 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 312 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2174,50 +2188,50 @@ yyreduce:
 
   case 44:
 
-/* Line 1269 of yacc.c  */
-#line 303 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 315 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), true); }
     break;
 
   case 45:
 
-/* Line 1269 of yacc.c  */
-#line 304 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 316 "parse-gram.y"
     { prologue_augment ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]), false); }
     break;
 
   case 46:
 
-/* Line 1269 of yacc.c  */
-#line 305 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 317 "parse-gram.y"
     { muscle_code_grow ("provides", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 47:
 
-/* Line 1269 of yacc.c  */
-#line 306 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 318 "parse-gram.y"
     { muscle_code_grow ("requires", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 48:
 
-/* Line 1269 of yacc.c  */
-#line 317 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 329 "parse-gram.y"
     {}
     break;
 
   case 49:
 
-/* Line 1269 of yacc.c  */
-#line 318 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 330 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 50:
 
-/* Line 1269 of yacc.c  */
-#line 323 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 335 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].code);
 
@@ -2238,20 +2252,21 @@ yyreduce:
 
       union_seen = true;
       muscle_code_grow ("stype", body, (yylsp[(3) - (3)]));
+      gram_scanner_last_string_free ();
     }
     break;
 
   case 51:
 
-/* Line 1269 of yacc.c  */
-#line 350 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 363 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 52:
 
-/* Line 1269 of yacc.c  */
-#line 351 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 364 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2260,15 +2275,15 @@ yyreduce:
 
   case 53:
 
-/* Line 1269 of yacc.c  */
-#line 355 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 368 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 54:
 
-/* Line 1269 of yacc.c  */
-#line 356 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 369 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2277,8 +2292,8 @@ yyreduce:
 
   case 55:
 
-/* Line 1269 of yacc.c  */
-#line 361 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 374 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2290,8 +2305,8 @@ yyreduce:
 
   case 56:
 
-/* Line 1269 of yacc.c  */
-#line 372 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 385 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2307,99 +2322,99 @@ yyreduce:
 
   case 57:
 
-/* Line 1269 of yacc.c  */
-#line 386 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 399 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 58:
 
-/* Line 1269 of yacc.c  */
-#line 387 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 400 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 59:
 
-/* Line 1269 of yacc.c  */
-#line 388 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 401 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 60:
 
-/* Line 1269 of yacc.c  */
-#line 392 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 405 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 61:
 
-/* Line 1269 of yacc.c  */
-#line 393 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 406 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 62:
 
-/* Line 1269 of yacc.c  */
-#line 399 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 412 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1269 of yacc.c  */
-#line 401 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 414 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1269 of yacc.c  */
-#line 405 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 418 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1269 of yacc.c  */
-#line 406 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 419 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1269 of yacc.c  */
-#line 410 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 423 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1269 of yacc.c  */
-#line 411 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 424 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1269 of yacc.c  */
-#line 412 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 425 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1269 of yacc.c  */
-#line 413 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 426 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1269 of yacc.c  */
-#line 419 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 432 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2408,8 +2423,8 @@ yyreduce:
 
   case 71:
 
-/* Line 1269 of yacc.c  */
-#line 424 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 437 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2418,8 +2433,8 @@ yyreduce:
 
   case 72:
 
-/* Line 1269 of yacc.c  */
-#line 429 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 442 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2429,8 +2444,8 @@ yyreduce:
 
   case 73:
 
-/* Line 1269 of yacc.c  */
-#line 435 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 448 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2440,8 +2455,8 @@ yyreduce:
 
   case 74:
 
-/* Line 1269 of yacc.c  */
-#line 441 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 454 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2452,8 +2467,8 @@ yyreduce:
 
   case 81:
 
-/* Line 1269 of yacc.c  */
-#line 471 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 484 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2461,71 +2476,71 @@ yyreduce:
 
   case 82:
 
-/* Line 1269 of yacc.c  */
-#line 477 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 490 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 84:
 
-/* Line 1269 of yacc.c  */
-#line 481 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 494 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1269 of yacc.c  */
-#line 482 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 495 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1269 of yacc.c  */
-#line 488 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 501 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 88:
 
-/* Line 1269 of yacc.c  */
-#line 490 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 503 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 89:
 
-/* Line 1269 of yacc.c  */
-#line 492 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 505 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 90:
 
-/* Line 1269 of yacc.c  */
-#line 494 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 507 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1269 of yacc.c  */
-#line 496 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 509 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1269 of yacc.c  */
-#line 498 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 511 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 95:
 
-/* Line 1269 of yacc.c  */
-#line 514 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 527 "parse-gram.y"
     {
       static char one[] = "1";
       (yyval.chars) = one;
@@ -2534,25 +2549,29 @@ yyreduce:
 
   case 97:
 
-/* Line 1269 of yacc.c  */
-#line 524 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 537 "parse-gram.y"
     {
+      code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
-      (yyval.chars) = translate_code ((yyvsp[(1) - (1)].code) + 1, (yylsp[(1) - (1)]));
+      code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].code)+1, (yylsp[(1) - (1)]));
+      code_props_translate_code (&plain_code);
+      gram_scanner_last_string_free ();
+      (yyval.chars) = plain_code.code;
     }
     break;
 
   case 98:
 
-/* Line 1269 of yacc.c  */
-#line 540 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 557 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 99:
 
-/* Line 1269 of yacc.c  */
-#line 542 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 559 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2562,15 +2581,15 @@ yyreduce:
 
   case 100:
 
-/* Line 1269 of yacc.c  */
-#line 550 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 567 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 103:
 
-/* Line 1269 of yacc.c  */
-#line 562 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 579 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2579,18 +2598,22 @@ yyreduce:
 
   case 105:
 
-/* Line 1269 of yacc.c  */
-#line 571 "parse-gram.y"
+/* Line 1272 of yacc.c  */
+#line 588 "parse-gram.y"
     {
-      muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
+      code_props plain_code;
+      code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
+      code_props_translate_code (&plain_code);
       gram_scanner_last_string_free ();
+      muscle_code_grow ("epilogue", plain_code.code, (yylsp[(2) - (2)]));
+      code_scanner_last_string_free ();
     }
     break;
 
 
 
-/* Line 1269 of yacc.c  */
-#line 2594 "parse-gram.c"
+/* Line 1272 of yacc.c  */
+#line 2617 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2808,8 +2831,8 @@ yyreturn:
 
 
 
-/* Line 1486 of yacc.c  */
-#line 577 "parse-gram.y"
+/* Line 1489 of yacc.c  */
+#line 598 "parse-gram.y"
 
 
 
