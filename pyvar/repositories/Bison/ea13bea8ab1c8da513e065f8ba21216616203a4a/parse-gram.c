@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.1.247-0e0f-dirty.  */
+/* A Bison parser, made by GNU Bison 2.4.1.252-dcd39.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.247-0e0f-dirty"
+#define YYBISON_VERSION "2.4.1.252-dcd39"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -74,7 +74,7 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 251 of yacc.c  */
+/* Line 261 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -151,7 +151,7 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 251 of yacc.c  */
+/* Line 261 of yacc.c  */
 #line 156 "parse-gram.c"
 
 /* Enabling traces.  */
@@ -302,7 +302,7 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 
-/* Line 276 of yacc.c  */
+/* Line 286 of yacc.c  */
 #line 94 "parse-gram.y"
 
   symbol *symbol;
@@ -317,7 +317,7 @@ typedef union YYSTYPE
 
 
 
-/* Line 276 of yacc.c  */
+/* Line 286 of yacc.c  */
 #line 322 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -342,7 +342,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 326 of yacc.c  */
+/* Line 336 of yacc.c  */
 #line 347 "parse-gram.c"
 
 #ifdef short
@@ -1049,164 +1049,164 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 184 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1058 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1067 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1076 "parse-gram.c"
 	break;
       case 44: /* "\"[identifier]\"" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 191 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", (yyvaluep->uniqstr)); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1085 "parse-gram.c"
 	break;
       case 45: /* "\"char\"" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 178 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1094 "parse-gram.c"
 	break;
       case 46: /* "\"epilogue\"" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1103 "parse-gram.c"
 	break;
       case 48: /* "\"identifier\"" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1112 "parse-gram.c"
 	break;
       case 49: /* "\"identifier:\"" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 192 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1121 "parse-gram.c"
 	break;
       case 52: /* "\"%{...%}\"" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1130 "parse-gram.c"
 	break;
       case 54: /* "\"type\"" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 193 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1139 "parse-gram.c"
 	break;
       case 71: /* "symbol.prec" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1148 "parse-gram.c"
 	break;
       case 84: /* "variable" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 190 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1157 "parse-gram.c"
 	break;
       case 85: /* "content.opt" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1166 "parse-gram.c"
 	break;
       case 86: /* "braceless" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 186 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1175 "parse-gram.c"
 	break;
       case 87: /* "id" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1184 "parse-gram.c"
 	break;
       case 88: /* "id_colon" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1193 "parse-gram.c"
 	break;
       case 89: /* "symbol" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1202 "parse-gram.c"
 	break;
       case 90: /* "string_as_id" */
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 797 of yacc.c  */
+/* Line 808 of yacc.c  */
 #line 1211 "parse-gram.c"
 	break;
       default:
@@ -1340,7 +1340,6 @@ int yydebug;
 # define YYMAXDEPTH 10000
 #endif
 
-
 
 #if YYERROR_VERBOSE
 
@@ -1444,7 +1443,8 @@ yytnamerr (char *yyres, const char *yystr)
 # endif
 
 /* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
-   about the unexpected token YYTOKEN while in state YYSTATE.
+   about the unexpected token YYTOKEN for the state stack whose top is
+   YYSSP.
 
    Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
    not large enough to hold the message.  In that case, also set
@@ -1452,7 +1452,7 @@ yytnamerr (char *yyres, const char *yystr)
    required number of bytes is too large to store.  */
 static int
 yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
-                int yystate, int yytoken)
+                yytype_int16 *yyssp, int yytoken)
 {
   YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
@@ -1495,7 +1495,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
   */
   if (yytoken != YYEMPTY)
     {
-      int yyn = yypact[yystate];
+      int yyn = yypact[*yyssp];
       yyarg[yycount++] = yytname[yytoken];
       if (!yypact_value_is_default (yyn))
         {
@@ -1507,6 +1507,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
           int yychecklim = YYLAST - yyn + 1;
           int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
           int yyx;
+
           for (yyx = yyxbegin; yyx < yyxend; ++yyx)
             if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                 && !yytable_value_is_error (yytable[yyx + yyn]))
@@ -1529,7 +1530,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 
   switch (yycount)
     {
-#define YYCASE_(N, S)                       \
+# define YYCASE_(N, S)                      \
       case N:                               \
         yyformat = S;                       \
       break
@@ -1539,7 +1540,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
       YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
       YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
       YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
-#undef YYCASE_
+# undef YYCASE_
     }
 
   yysize1 = yysize + yystrlen (yyformat);
@@ -1577,7 +1578,6 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
   return 0;
 }
 #endif /* YYERROR_VERBOSE */
-
 
 /*-----------------------------------------------.
 | Release the memory associated to this symbol.  |
@@ -1750,7 +1750,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1296 of yacc.c  */
+/* Line 1496 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1759,7 +1759,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1296 of yacc.c  */
+/* Line 1496 of yacc.c  */
 #line 1764 "parse-gram.c"
   yylsp[0] = yylloc;
 
@@ -1891,7 +1891,7 @@ yybackup:
   if (yyn <= 0)
     {
       if (yytable_value_is_error (yyn))
-	goto yyerrlab;
+        goto yyerrlab;
       yyn = -yyn;
       goto yyreduce;
     }
@@ -1947,7 +1947,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 225 "parse-gram.y"
     {
       code_props plain_code;
@@ -1962,14 +1962,14 @@ yyreduce:
 
   case 7:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 234 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 236 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -1979,14 +1979,14 @@ yyreduce:
 
   case 9:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 240 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 242 "parse-gram.y"
     {
       defines_flag = true;
@@ -1996,42 +1996,42 @@ yyreduce:
 
   case 11:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 246 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 247 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 248 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 249 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 250 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 252 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -2041,7 +2041,7 @@ yyreduce:
 
   case 17:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 257 "parse-gram.y"
     {
       code_props action;
@@ -2055,77 +2055,77 @@ yyreduce:
 
   case 18:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 265 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 266 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 267 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 268 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 269 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 270 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 271 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 272 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 273 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 274 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 276 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2145,14 +2145,14 @@ yyreduce:
 
   case 29:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 290 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 292 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2181,28 +2181,28 @@ yyreduce:
 
   case 31:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 315 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 316 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 317 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 325 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2211,7 +2211,7 @@ yyreduce:
 
   case 38:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 329 "parse-gram.y"
     {
       symbol_list *list;
@@ -2223,7 +2223,7 @@ yyreduce:
 
   case 39:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 336 "parse-gram.y"
     {
       symbol_list *list;
@@ -2235,7 +2235,7 @@ yyreduce:
 
   case 40:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 343 "parse-gram.y"
     {
       default_prec = true;
@@ -2244,7 +2244,7 @@ yyreduce:
 
   case 41:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 347 "parse-gram.y"
     {
       default_prec = false;
@@ -2253,7 +2253,7 @@ yyreduce:
 
   case 42:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 351 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2265,7 +2265,7 @@ yyreduce:
 
   case 43:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 358 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2275,21 +2275,21 @@ yyreduce:
 
   case 44:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 372 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 373 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 378 "parse-gram.y"
     {
       union_seen = true;
@@ -2300,14 +2300,14 @@ yyreduce:
 
   case 47:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 389 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 390 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2317,14 +2317,14 @@ yyreduce:
 
   case 49:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 394 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 395 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2334,7 +2334,7 @@ yyreduce:
 
   case 51:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 400 "parse-gram.y"
     {
       symbol_list *list;
@@ -2347,7 +2347,7 @@ yyreduce:
 
   case 52:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 411 "parse-gram.y"
     {
       symbol_list *list;
@@ -2364,126 +2364,126 @@ yyreduce:
 
   case 53:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 425 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 426 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 427 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 431 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 432 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 438 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 440 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 444 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 445 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 451 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 457 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 458 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 462 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 463 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 464 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 465 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 471 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2493,7 +2493,7 @@ yyreduce:
 
   case 71:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 476 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2503,7 +2503,7 @@ yyreduce:
 
   case 72:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 481 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2514,7 +2514,7 @@ yyreduce:
 
   case 73:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 487 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2525,7 +2525,7 @@ yyreduce:
 
   case 74:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 493 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2537,7 +2537,7 @@ yyreduce:
 
   case 81:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 523 "parse-gram.y"
     {
       yyerrok;
@@ -2546,7 +2546,7 @@ yyreduce:
 
   case 82:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 529 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (2)].symbol); current_lhs_location = (yylsp[(1) - (2)]);
     current_lhs_named_ref = (yyvsp[(2) - (2)].named_ref); }
@@ -2554,21 +2554,21 @@ yyreduce:
 
   case 84:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 534 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 535 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 541 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
@@ -2576,77 +2576,77 @@ yyreduce:
 
   case 88:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 544 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 546 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 548 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 550 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 552 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 556 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 558 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 570 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 575 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 576 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 587 "parse-gram.y"
     {
       code_props plain_code;
@@ -2660,14 +2660,14 @@ yyreduce:
 
   case 101:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 607 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 609 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2678,14 +2678,14 @@ yyreduce:
 
   case 103:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 617 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 629 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2695,7 +2695,7 @@ yyreduce:
 
   case 108:
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 638 "parse-gram.y"
     {
       code_props plain_code;
@@ -2709,7 +2709,7 @@ yyreduce:
 
 
 
-/* Line 1509 of yacc.c  */
+/* Line 1712 of yacc.c  */
 #line 2714 "parse-gram.c"
       default: break;
     }
@@ -2763,11 +2763,12 @@ yyerrlab:
 #if ! YYERROR_VERBOSE
       yyerror (YY_("syntax error"));
 #else
-# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, yystate, \
+# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, yyssp, \
                                         yytoken)
       {
         char const *yymsgp = YY_("syntax error");
-        int yysyntax_error_status = YYSYNTAX_ERROR;
+        int yysyntax_error_status;
+        yysyntax_error_status = YYSYNTAX_ERROR;
         if (yysyntax_error_status == 0)
           yymsgp = yymsg;
         else if (yysyntax_error_status == 1)
@@ -2946,7 +2947,7 @@ yyreturn:
 
 
 
-/* Line 1747 of yacc.c  */
+/* Line 1970 of yacc.c  */
 #line 648 "parse-gram.y"
 
 
