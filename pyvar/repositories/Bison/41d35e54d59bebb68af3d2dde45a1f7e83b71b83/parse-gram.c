@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.1.155-0ab4-dirty.  */
+/* A Bison parser, made by GNU Bison 2.4.1.171-692d.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.155-0ab4-dirty"
+#define YYBISON_VERSION "2.4.1.171-692d"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -393,7 +393,7 @@ typedef short int yytype_int16;
 #define YYSIZE_MAXIMUM ((YYSIZE_T) -1)
 
 #ifndef YY_
-# if YYENABLE_NLS
+# if defined YYENABLE_NLS && YYENABLE_NLS
 #  if ENABLE_NLS
 #   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
 #   define YY_(msgid) dgettext ("bison-runtime", msgid)
@@ -906,9 +906,18 @@ static const yytype_uint8 yystos[] =
 
 /* Like YYERROR except do call yyerror.  This remains here temporarily
    to ease the transition to the new meaning of YYERROR, for GCC.
-   Once GCC version 2 has supplanted version 1, this can go.  */
+   Once GCC version 2 has supplanted version 1, this can go.  However,
+   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
+   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
+   discussed.  */
 
 #define YYFAIL		goto yyerrlab
+#if defined YYFAIL
+  /* This is here to suppress warnings from the GCC cpp's
+     -Wunused-macros.  Normally we don't worry about that warning, but
+     some users do, and we want to make it easy for users to remove
+     YYFAIL uses, which will produce warnings from Bison 2.5.  */
+#endif
 
 #define YYRECOVERING()  (!!yyerrstatus)
 
@@ -965,7 +974,7 @@ while (YYID (0))
    we won't break user code: when these are the locations we know.  */
 
 #ifndef YY_LOCATION_PRINT
-# if YYLTYPE_IS_TRIVIAL
+# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
 #  define YY_LOCATION_PRINT(File, Loc)			\
      fprintf (File, "%d.%d-%d.%d",			\
 	      (Loc).first_line, (Loc).first_column,	\
@@ -1041,165 +1050,165 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 783 of yacc.c  */
-#line 1050 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1059 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 783 of yacc.c  */
-#line 1059 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1068 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 783 of yacc.c  */
-#line 1068 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1077 "parse-gram.c"
 	break;
       case 44: /* "\"[identifier]\"" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 191 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", (yyvaluep->uniqstr)); };
 
-/* Line 783 of yacc.c  */
-#line 1077 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1086 "parse-gram.c"
 	break;
       case 45: /* "\"char\"" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 178 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 783 of yacc.c  */
-#line 1086 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1095 "parse-gram.c"
 	break;
       case 46: /* "\"epilogue\"" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 783 of yacc.c  */
-#line 1095 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1104 "parse-gram.c"
 	break;
       case 48: /* "\"identifier\"" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 783 of yacc.c  */
-#line 1104 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1113 "parse-gram.c"
 	break;
       case 49: /* "\"identifier:\"" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 192 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 783 of yacc.c  */
-#line 1113 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1122 "parse-gram.c"
 	break;
       case 52: /* "\"%{...%}\"" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 783 of yacc.c  */
-#line 1122 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1131 "parse-gram.c"
 	break;
       case 54: /* "\"type\"" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 193 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 783 of yacc.c  */
-#line 1131 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1140 "parse-gram.c"
 	break;
       case 71: /* "symbol.prec" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 783 of yacc.c  */
-#line 1140 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1149 "parse-gram.c"
 	break;
       case 84: /* "variable" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 783 of yacc.c  */
-#line 1149 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1158 "parse-gram.c"
 	break;
       case 85: /* "content.opt" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 783 of yacc.c  */
-#line 1158 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1167 "parse-gram.c"
 	break;
       case 86: /* "braceless" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 783 of yacc.c  */
-#line 1167 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1176 "parse-gram.c"
 	break;
       case 87: /* "id" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 783 of yacc.c  */
-#line 1176 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1185 "parse-gram.c"
 	break;
       case 88: /* "id_colon" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 783 of yacc.c  */
-#line 1185 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1194 "parse-gram.c"
 	break;
       case 89: /* "symbol" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 783 of yacc.c  */
-#line 1194 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1203 "parse-gram.c"
 	break;
       case 90: /* "string_as_id" */
 
-/* Line 783 of yacc.c  */
+/* Line 799 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 783 of yacc.c  */
-#line 1203 "parse-gram.c"
+/* Line 799 of yacc.c  */
+#line 1212 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1718,7 +1727,7 @@ YYLTYPE yylloc;
   yyvsp = yyvs;
   yylsp = yyls;
 
-#if YYLTYPE_IS_TRIVIAL
+#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
   yylloc.first_line   = yylloc.last_line   = 1;
   yylloc.first_column = yylloc.last_column = 1;
@@ -1726,7 +1735,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1266 of yacc.c  */
+/* Line 1282 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1735,8 +1744,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1266 of yacc.c  */
-#line 1740 "parse-gram.c"
+/* Line 1282 of yacc.c  */
+#line 1749 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1923,7 +1932,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 225 "parse-gram.y"
     {
       code_props plain_code;
@@ -1938,14 +1947,14 @@ yyreduce:
 
   case 7:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 234 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 236 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -1955,14 +1964,14 @@ yyreduce:
 
   case 9:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 240 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 242 "parse-gram.y"
     {
       defines_flag = true;
@@ -1972,42 +1981,42 @@ yyreduce:
 
   case 11:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 246 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 247 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 248 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 249 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 250 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 252 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -2017,7 +2026,7 @@ yyreduce:
 
   case 17:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 257 "parse-gram.y"
     {
       code_props action;
@@ -2031,77 +2040,77 @@ yyreduce:
 
   case 18:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 265 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 266 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 267 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 268 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 269 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 270 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 271 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 272 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 273 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 274 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 276 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2121,14 +2130,14 @@ yyreduce:
 
   case 29:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 290 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 292 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2157,28 +2166,28 @@ yyreduce:
 
   case 31:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 315 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 316 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 317 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 325 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2187,7 +2196,7 @@ yyreduce:
 
   case 38:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 329 "parse-gram.y"
     {
       symbol_list *list;
@@ -2199,7 +2208,7 @@ yyreduce:
 
   case 39:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 336 "parse-gram.y"
     {
       symbol_list *list;
@@ -2211,7 +2220,7 @@ yyreduce:
 
   case 40:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 343 "parse-gram.y"
     {
       default_prec = true;
@@ -2220,7 +2229,7 @@ yyreduce:
 
   case 41:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 347 "parse-gram.y"
     {
       default_prec = false;
@@ -2229,7 +2238,7 @@ yyreduce:
 
   case 42:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 351 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2241,7 +2250,7 @@ yyreduce:
 
   case 43:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 358 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2251,21 +2260,21 @@ yyreduce:
 
   case 44:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 372 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 373 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 378 "parse-gram.y"
     {
       union_seen = true;
@@ -2276,14 +2285,14 @@ yyreduce:
 
   case 47:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 389 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 390 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2293,14 +2302,14 @@ yyreduce:
 
   case 49:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 394 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 395 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2310,7 +2319,7 @@ yyreduce:
 
   case 51:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 400 "parse-gram.y"
     {
       symbol_list *list;
@@ -2323,7 +2332,7 @@ yyreduce:
 
   case 52:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 411 "parse-gram.y"
     {
       symbol_list *list;
@@ -2340,126 +2349,126 @@ yyreduce:
 
   case 53:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 425 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 426 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 427 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 431 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 432 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 438 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 440 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 444 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 445 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 451 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 457 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 458 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 462 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 463 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 464 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 465 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 471 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2469,7 +2478,7 @@ yyreduce:
 
   case 71:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 476 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2479,7 +2488,7 @@ yyreduce:
 
   case 72:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 481 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2490,7 +2499,7 @@ yyreduce:
 
   case 73:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 487 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2501,7 +2510,7 @@ yyreduce:
 
   case 74:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 493 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2513,7 +2522,7 @@ yyreduce:
 
   case 81:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 523 "parse-gram.y"
     {
       yyerrok;
@@ -2522,7 +2531,7 @@ yyreduce:
 
   case 82:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 529 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (2)].symbol); current_lhs_location = (yylsp[(1) - (2)]);
     current_lhs_named_ref = (yyvsp[(2) - (2)].named_ref); }
@@ -2530,21 +2539,21 @@ yyreduce:
 
   case 84:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 534 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 535 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 541 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
@@ -2552,77 +2561,77 @@ yyreduce:
 
   case 88:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 544 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 546 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 548 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 550 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 552 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 556 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 558 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 570 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 575 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 576 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 587 "parse-gram.y"
     {
       code_props plain_code;
@@ -2636,14 +2645,14 @@ yyreduce:
 
   case 101:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 607 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 609 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2654,14 +2663,14 @@ yyreduce:
 
   case 103:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 617 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 629 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2671,7 +2680,7 @@ yyreduce:
 
   case 108:
 
-/* Line 1479 of yacc.c  */
+/* Line 1495 of yacc.c  */
 #line 638 "parse-gram.y"
     {
       code_props plain_code;
@@ -2685,8 +2694,8 @@ yyreduce:
 
 
 
-/* Line 1479 of yacc.c  */
-#line 2690 "parse-gram.c"
+/* Line 1495 of yacc.c  */
+#line 2699 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2895,7 +2904,7 @@ yyreturn:
 
 
 
-/* Line 1690 of yacc.c  */
+/* Line 1706 of yacc.c  */
 #line 648 "parse-gram.y"
 
 
