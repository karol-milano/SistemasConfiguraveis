@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.1b.  */
+/* A Bison parser, made by GNU Bison 2.3+.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
 
@@ -47,7 +47,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.1b"
+#define YYBISON_VERSION "2.3+"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -184,7 +184,7 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 1 "../../src/parse-gram.y"
+#line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
@@ -238,6 +238,8 @@ static void version_check (location const *loc, char const *version);
 	gram_error (&yylloc, Msg)
 static void gram_error (location const *, char const *);
 
+static char const *char_name (char);
+
 static void add_param (char const *, char *, location);
 
 static symbol_class current_class = unknown_sym;
@@ -280,7 +282,7 @@ static int current_prec = 0;
 
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
-#line 95 "../../src/parse-gram.y"
+#line 97 "parse-gram.y"
 {
   symbol *symbol;
   symbol_list *list;
@@ -291,7 +293,7 @@ typedef union YYSTYPE
   unsigned char character;
 }
 /* Line 193 of yacc.c.  */
-#line 295 "../../src/parse-gram.c"
+#line 297 "parse-gram.c"
 	YYSTYPE;
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -316,7 +318,7 @@ typedef struct YYLTYPE
 
 
 /* Line 216 of yacc.c.  */
-#line 320 "../../src/parse-gram.c"
+#line 322 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -634,15 +636,15 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   195,   195,   203,   205,   209,   210,   212,   213,   218,
-     219,   220,   221,   222,   223,   224,   229,   233,   234,   235,
-     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
-     246,   250,   251,   252,   256,   264,   272,   276,   290,   291,
-     295,   317,   317,   322,   322,   327,   337,   352,   353,   354,
-     358,   359,   364,   365,   370,   374,   379,   385,   391,   402,
-     403,   412,   413,   419,   420,   421,   428,   428,   432,   433,
-     434,   439,   440,   442,   445,   447,   449,   462,   463,   472,
-     477,   478,   483,   492,   497,   499
+       0,   198,   198,   206,   208,   212,   213,   215,   216,   221,
+     222,   223,   224,   225,   226,   227,   232,   236,   237,   238,
+     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
+     249,   253,   254,   255,   259,   267,   275,   279,   293,   294,
+     298,   320,   320,   325,   325,   330,   340,   355,   356,   357,
+     361,   362,   367,   368,   373,   377,   382,   388,   394,   405,
+     406,   415,   416,   422,   423,   424,   431,   431,   435,   436,
+     437,   442,   443,   445,   448,   450,   452,   465,   467,   476,
+     481,   482,   487,   496,   501,   503
 };
 #endif
 
@@ -952,14 +954,14 @@ do {									  \
 #if (defined __STDC__ || defined __C99__FUNC__ \
      || defined __cplusplus || defined _MSC_VER)
 static void
-yy_symbol_value_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep, const YYLTYPE * const yylocationp)
+yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 #else
 static void
 yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     FILE *yyoutput;
     int yytype;
-    const YYSTYPE * const yyvaluep;
-    const YYLTYPE * const yylocationp;
+    YYSTYPE const * const yyvaluep;
+    YYLTYPE const * const yylocationp;
 #endif
 {
   if (!yyvaluep)
@@ -974,74 +976,74 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 175 "../../src/parse-gram.y"
-	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 980 "../../src/parse-gram.c"
+#line 177 "parse-gram.y"
+	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
+#line 982 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
-#line 184 "../../src/parse-gram.y"
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 985 "../../src/parse-gram.c"
+#line 987 "parse-gram.c"
 	break;
       case 41: /* "\"{...}\"" */
-#line 176 "../../src/parse-gram.y"
+#line 179 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 990 "../../src/parse-gram.c"
+#line 992 "parse-gram.c"
 	break;
       case 42: /* "\"char\"" */
-#line 172 "../../src/parse-gram.y"
-	{ fprintf (stderr, "'%c' (%d)", (yyvaluep->character), (yyvaluep->character)); };
-#line 995 "../../src/parse-gram.c"
+#line 174 "parse-gram.y"
+	{ fputs (char_name ((yyvaluep->character)), stderr); };
+#line 997 "parse-gram.c"
 	break;
       case 43: /* "\"epilogue\"" */
-#line 176 "../../src/parse-gram.y"
+#line 179 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1000 "../../src/parse-gram.c"
+#line 1002 "parse-gram.c"
 	break;
       case 45: /* "\"identifier\"" */
-#line 180 "../../src/parse-gram.y"
-	{ fprintf (stderr, "%s", (yyvaluep->uniqstr)); };
-#line 1005 "../../src/parse-gram.c"
+#line 183 "parse-gram.y"
+	{ fputs ((yyvaluep->uniqstr), stderr); };
+#line 1007 "parse-gram.c"
 	break;
       case 46: /* "\"identifier:\"" */
-#line 181 "../../src/parse-gram.y"
+#line 184 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
-#line 1010 "../../src/parse-gram.c"
+#line 1012 "parse-gram.c"
 	break;
       case 49: /* "\"%{...%}\"" */
-#line 176 "../../src/parse-gram.y"
+#line 179 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1015 "../../src/parse-gram.c"
+#line 1017 "parse-gram.c"
 	break;
       case 51: /* "\"type\"" */
-#line 179 "../../src/parse-gram.y"
+#line 182 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1020 "../../src/parse-gram.c"
+#line 1022 "parse-gram.c"
 	break;
       case 74: /* "id" */
-#line 187 "../../src/parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1025 "../../src/parse-gram.c"
+#line 1027 "parse-gram.c"
 	break;
       case 75: /* "id_colon" */
-#line 188 "../../src/parse-gram.y"
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1030 "../../src/parse-gram.c"
+#line 1032 "parse-gram.c"
 	break;
       case 76: /* "symbol" */
-#line 187 "../../src/parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1035 "../../src/parse-gram.c"
+#line 1037 "parse-gram.c"
 	break;
       case 77: /* "string_as_id" */
-#line 187 "../../src/parse-gram.y"
+#line 190 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1040 "../../src/parse-gram.c"
+#line 1042 "parse-gram.c"
 	break;
       case 78: /* "string_content" */
-#line 175 "../../src/parse-gram.y"
-	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1045 "../../src/parse-gram.c"
+#line 177 "parse-gram.y"
+	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
+#line 1047 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1056,14 +1058,14 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #if (defined __STDC__ || defined __C99__FUNC__ \
      || defined __cplusplus || defined _MSC_VER)
 static void
-yy_symbol_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep, const YYLTYPE * const yylocationp)
+yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 #else
 static void
 yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
     FILE *yyoutput;
     int yytype;
-    const YYSTYPE * const yyvaluep;
-    const YYLTYPE * const yylocationp;
+    YYSTYPE const * const yyvaluep;
+    YYLTYPE const * const yylocationp;
 #endif
 {
   if (yytype < YYNTOKENS)
@@ -1116,8 +1118,7 @@ static void
 yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
 #else
 static void
-yy_reduce_print (yyvsp, yylsp, yyrule
-		   )
+yy_reduce_print (yyvsp, yylsp, yyrule)
     YYSTYPE *yyvsp;
     YYLTYPE *yylsp;
     int yyrule;
@@ -1240,7 +1241,7 @@ yytnamerr (char *yyres, const char *yystr)
 {
   if (*yystr == '"')
     {
-      size_t yyn = 0;
+      YYSIZE_T yyn = 0;
       char const *yyp = yystr;
 
       for (;;)
@@ -1287,7 +1288,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 {
   int yyn = yypact[yystate];
 
-  if (! (YYPACT_NINF < yyn && yyn < YYLAST))
+  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
     return 0;
   else
     {
@@ -1325,7 +1326,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       int yyxbegin = yyn < 0 ? -yyn : 0;
 
       /* Stay within bounds of both yycheck and yytname.  */
-      int yychecklim = YYLAST - yyn;
+      int yychecklim = YYLAST - yyn + 1;
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
       int yycount = 1;
 
@@ -1466,15 +1467,15 @@ yyparse ()
 #endif
 #endif
 {
-  /* The look-ahead symbol.  */
+  /* The lookahead symbol.  */
 int yychar;
 
-/* The semantic value of the look-ahead symbol.  */
+/* The semantic value of the lookahead symbol.  */
 YYSTYPE yylval;
 
 /* Number of syntax errors so far.  */
 int yynerrs;
-/* Location data for the look-ahead symbol.  */
+/* Location data for the lookahead symbol.  */
 YYLTYPE yylloc;
 
   int yystate;
@@ -1482,7 +1483,7 @@ YYLTYPE yylloc;
   int yyresult;
   /* Number of tokens to shift before error messages enabled.  */
   int yyerrstatus;
-  /* Look-ahead token as an internal (translated) token number.  */
+  /* Lookahead token as an internal (translated) token number.  */
   int yytoken = 0;
 #if YYERROR_VERBOSE
   /* Buffer for error messages, and its allocated size.  */
@@ -1552,7 +1553,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code.  */
-#line 86 "../../src/parse-gram.y"
+#line 88 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1560,7 +1561,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 0);
 }
 /* Line 1078 of yacc.c.  */
-#line 1564 "../../src/parse-gram.c"
+#line 1565 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1650,16 +1651,16 @@ YYLTYPE yylloc;
 yybackup:
 
   /* Do appropriate processing given the current state.  Read a
-     look-ahead token if we need one and don't already have one.  */
+     lookahead token if we need one and don't already have one.  */
 
-  /* First try to decide what to do without reference to look-ahead token.  */
+  /* First try to decide what to do without reference to lookahead token.  */
   yyn = yypact[yystate];
   if (yyn == YYPACT_NINF)
     goto yydefault;
 
-  /* Not known => get a look-ahead token if don't already have one.  */
+  /* Not known => get a lookahead token if don't already have one.  */
 
-  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
+  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
   if (yychar == YYEMPTY)
     {
       YYDPRINTF ((stderr, "Reading a token: "));
@@ -1699,7 +1700,7 @@ yybackup:
   if (yyerrstatus)
     yyerrstatus--;
 
-  /* Shift the look-ahead token.  */
+  /* Shift the lookahead token.  */
   YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 
   /* Discard the shifted token unless it is eof.  */
@@ -1745,18 +1746,18 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 210 "../../src/parse-gram.y"
+#line 213 "parse-gram.y"
     { prologue_augment (translate_code ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])),
 						       (yylsp[(1) - (1)])); }
     break;
 
   case 7:
-#line 212 "../../src/parse-gram.y"
+#line 215 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 214 "../../src/parse-gram.y"
+#line 217 "parse-gram.y"
     {
       static char one[] = "1";
       muscle_insert ((yyvsp[(2) - (2)].chars), one);
@@ -1764,37 +1765,37 @@ yyreduce:
     break;
 
   case 9:
-#line 218 "../../src/parse-gram.y"
+#line 221 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 10:
-#line 219 "../../src/parse-gram.y"
+#line 222 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 11:
-#line 220 "../../src/parse-gram.y"
+#line 223 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-#line 221 "../../src/parse-gram.y"
+#line 224 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-#line 222 "../../src/parse-gram.y"
+#line 225 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-#line 223 "../../src/parse-gram.y"
+#line 226 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 15:
-#line 225 "../../src/parse-gram.y"
+#line 228 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1802,86 +1803,86 @@ yyreduce:
     break;
 
   case 16:
-#line 230 "../../src/parse-gram.y"
+#line 233 "parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_symbol_action ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
     }
     break;
 
   case 17:
-#line 233 "../../src/parse-gram.y"
+#line 236 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 18:
-#line 234 "../../src/parse-gram.y"
+#line 237 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 19:
-#line 235 "../../src/parse-gram.y"
+#line 238 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 20:
-#line 236 "../../src/parse-gram.y"
+#line 239 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 21:
-#line 237 "../../src/parse-gram.y"
+#line 240 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 22:
-#line 238 "../../src/parse-gram.y"
+#line 241 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-#line 239 "../../src/parse-gram.y"
+#line 242 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 24:
-#line 240 "../../src/parse-gram.y"
+#line 243 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 25:
-#line 241 "../../src/parse-gram.y"
+#line 244 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 26:
-#line 242 "../../src/parse-gram.y"
+#line 245 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 27:
-#line 243 "../../src/parse-gram.y"
+#line 246 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 28:
-#line 244 "../../src/parse-gram.y"
+#line 247 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 29:
-#line 245 "../../src/parse-gram.y"
+#line 248 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 33:
-#line 253 "../../src/parse-gram.y"
+#line 256 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
   case 34:
-#line 257 "../../src/parse-gram.y"
+#line 260 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -1892,7 +1893,7 @@ yyreduce:
     break;
 
   case 35:
-#line 265 "../../src/parse-gram.y"
+#line 268 "parse-gram.y"
     {
       symbol_list *list;
       const char *action = translate_symbol_action ((yyvsp[(2) - (3)].chars), (yylsp[(2) - (3)]));
@@ -1903,31 +1904,31 @@ yyreduce:
     break;
 
   case 36:
-#line 273 "../../src/parse-gram.y"
+#line 276 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 37:
-#line 277 "../../src/parse-gram.y"
+#line 280 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 38:
-#line 290 "../../src/parse-gram.y"
+#line 293 "parse-gram.y"
     {}
     break;
 
   case 39:
-#line 291 "../../src/parse-gram.y"
+#line 294 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 40:
-#line 296 "../../src/parse-gram.y"
+#line 299 "parse-gram.y"
     {
       char const *body = (yyvsp[(3) - (3)].chars);
 
@@ -1946,12 +1947,12 @@ yyreduce:
     break;
 
   case 41:
-#line 317 "../../src/parse-gram.y"
+#line 320 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 42:
-#line 318 "../../src/parse-gram.y"
+#line 321 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1959,12 +1960,12 @@ yyreduce:
     break;
 
   case 43:
-#line 322 "../../src/parse-gram.y"
+#line 325 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 44:
-#line 323 "../../src/parse-gram.y"
+#line 326 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1972,7 +1973,7 @@ yyreduce:
     break;
 
   case 45:
-#line 328 "../../src/parse-gram.y"
+#line 331 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -1982,7 +1983,7 @@ yyreduce:
     break;
 
   case 46:
-#line 338 "../../src/parse-gram.y"
+#line 341 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1997,49 +1998,49 @@ yyreduce:
     break;
 
   case 47:
-#line 352 "../../src/parse-gram.y"
+#line 355 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 48:
-#line 353 "../../src/parse-gram.y"
+#line 356 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 49:
-#line 354 "../../src/parse-gram.y"
+#line 357 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 50:
-#line 358 "../../src/parse-gram.y"
+#line 361 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 51:
-#line 359 "../../src/parse-gram.y"
+#line 362 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 52:
-#line 364 "../../src/parse-gram.y"
+#line 367 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 53:
-#line 365 "../../src/parse-gram.y"
+#line 368 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 54:
-#line 371 "../../src/parse-gram.y"
+#line 374 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
      }
     break;
 
   case 55:
-#line 375 "../../src/parse-gram.y"
+#line 378 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2047,7 +2048,7 @@ yyreduce:
     break;
 
   case 56:
-#line 380 "../../src/parse-gram.y"
+#line 383 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2056,7 +2057,7 @@ yyreduce:
     break;
 
   case 57:
-#line 386 "../../src/parse-gram.y"
+#line 389 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2065,7 +2066,7 @@ yyreduce:
     break;
 
   case 58:
-#line 392 "../../src/parse-gram.y"
+#line 395 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2075,80 +2076,79 @@ yyreduce:
     break;
 
   case 65:
-#line 422 "../../src/parse-gram.y"
+#line 425 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 66:
-#line 428 "../../src/parse-gram.y"
+#line 431 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 68:
-#line 432 "../../src/parse-gram.y"
+#line 435 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
-#line 433 "../../src/parse-gram.y"
+#line 436 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 71:
-#line 439 "../../src/parse-gram.y"
+#line 442 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 72:
-#line 441 "../../src/parse-gram.y"
+#line 444 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 73:
-#line 443 "../../src/parse-gram.y"
+#line 446 "parse-gram.y"
     { grammar_current_rule_action_append (gram_last_string,
 					  gram_last_braced_code_loc); }
     break;
 
   case 74:
-#line 446 "../../src/parse-gram.y"
+#line 449 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 75:
-#line 448 "../../src/parse-gram.y"
+#line 451 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 76:
-#line 450 "../../src/parse-gram.y"
+#line 453 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 77:
-#line 462 "../../src/parse-gram.y"
+#line 466 "parse-gram.y"
     { (yyval.symbol) = symbol_get ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 78:
-#line 463 "../../src/parse-gram.y"
-    { char cp[4] = { '\'', (yyvsp[(1) - (1)].character), '\'', 0 };
-                    (yyval.symbol) = symbol_get (quotearg_style (escape_quoting_style, cp),
-				     (yylsp[(1) - (1)]));
-		    symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
-		    symbol_user_token_number_set ((yyval.symbol), (yyvsp[(1) - (1)].character), (yylsp[(1) - (1)]));
-                  }
+#line 468 "parse-gram.y"
+    {
+      (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
+      symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
+      symbol_user_token_number_set ((yyval.symbol), (yyvsp[(1) - (1)].character), (yylsp[(1) - (1)]));
+    }
     break;
 
   case 79:
-#line 472 "../../src/parse-gram.y"
+#line 476 "parse-gram.y"
     { (yyval.symbol) = symbol_get ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 82:
-#line 484 "../../src/parse-gram.y"
+#line 488 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2156,12 +2156,12 @@ yyreduce:
     break;
 
   case 83:
-#line 493 "../../src/parse-gram.y"
+#line 497 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 85:
-#line 500 "../../src/parse-gram.y"
+#line 504 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2170,7 +2170,7 @@ yyreduce:
 
 
 /* Line 1267 of yacc.c.  */
-#line 2174 "../../src/parse-gram.c"
+#line 2174 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2246,7 +2246,7 @@ yyerrlab:
 
   if (yyerrstatus == 3)
     {
-      /* If just tried and failed to reuse look-ahead token after an
+      /* If just tried and failed to reuse lookahead token after an
 	 error, discard it.  */
 
       if (yychar <= YYEOF)
@@ -2263,7 +2263,7 @@ yyerrlab:
 	}
     }
 
-  /* Else will try to reuse look-ahead token after shifting the error
+  /* Else will try to reuse lookahead token after shifting the error
      token.  */
   goto yyerrlab1;
 
@@ -2328,7 +2328,7 @@ yyerrlab1:
 
   yyerror_range[1] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
-     the look-ahead.  YYLOC is available though.  */
+     the lookahead.  YYLOC is available though.  */
   YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
   *++yylsp = yyloc;
 
@@ -2385,11 +2385,12 @@ yyreturn:
   if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);
 #endif
-  return yyresult;
+  /* Make sure YYID is used.  */
+  return YYID (yyresult);
 }
 
 
-#line 506 "../../src/parse-gram.y"
+#line 510 "parse-gram.y"
 
 
 
@@ -2497,3 +2498,16 @@ token_name (int type)
   return yytname[YYTRANSLATE (type)];
 }
 
+static char const *
+char_name (char c)
+{
+  if (c == '\'')
+    return "'\\''";
+  else
+    {
+      char buf[4];
+      buf[0] = '\''; buf[1] = c; buf[2] = '\''; buf[3] = '\0';
+      return quotearg_style (escape_quoting_style, buf);
+    }
+}
+
