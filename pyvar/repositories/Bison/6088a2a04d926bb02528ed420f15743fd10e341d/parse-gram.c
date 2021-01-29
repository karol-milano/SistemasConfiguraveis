@@ -166,7 +166,7 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 1 "../../src/parse-gram.y"
+#line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
@@ -239,7 +239,7 @@ int current_prec = 0;
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 79 "../../src/parse-gram.y"
+#line 79 "parse-gram.y"
 typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
@@ -249,7 +249,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 191 of yacc.c.  */
-#line 253 "../../src/parse-gram.c"
+#line 253 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -273,7 +273,7 @@ typedef struct YYLTYPE
 
 
 /* Line 214 of yacc.c.  */
-#line 277 "../../src/parse-gram.c"
+#line 277 "parse-gram.c"
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
 # define YYSIZE_T __SIZE_TYPE__
@@ -289,6 +289,18 @@ typedef struct YYLTYPE
 # define YYSIZE_T unsigned int
 #endif
 
+#ifndef YY_
+# if YYENABLE_NLS
+#  if ENABLE_NLS
+#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
+#   define YY_(msgid) dgettext ("bison-runtime", msgid)
+#  endif
+# endif
+# ifndef YY_
+#  define YY_(msgid) msgid
+# endif
+#endif
+
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
@@ -546,11 +558,6 @@ static const char *const yytname[] =
 };
 #endif
 
-/* INFRINGES ON USER NAME SPACE */
-#ifndef _
-# define _(msgid) msgid
-#endif
-
 # ifdef YYPRINT
 /* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
    token YYLEX-NUM.  */
@@ -735,7 +742,7 @@ do								\
     }								\
   else								\
     { 								\
-      yyerror (_("syntax error: cannot back up")); \
+      yyerror (YY_("syntax error: cannot back up")); \
       YYERROR;							\
     }								\
 while (0)
@@ -835,7 +842,7 @@ yy_stack_print (bottom, top)
     short int *top;
 #endif
 {
-  YYFPRINTF (stderr, _("Stack now"));
+  YYFPRINTF (stderr, "Stack now");
   for (/* Nothing. */; bottom <= top; ++bottom)
     YYFPRINTF (stderr, " %d", *bottom);
   YYFPRINTF (stderr, "\n");
@@ -862,8 +869,8 @@ yy_reduce_print (yyrule)
 #endif
 {
   int yyi;
-  unsigned int yylno = yyrline[yyrule];
-  YYFPRINTF (stderr, _("Reducing stack by rule %d (line %u), "),
+  unsigned long int yylno = yyrline[yyrule];
+  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
              yyrule - 1, yylno);
   /* Print the symbols being reduced, and their result.  */
   for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
@@ -988,7 +995,7 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
     YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);
 
   YY_LOCATION_PRINT (yyoutput, *yylocationp);
-  fprintf (yyoutput, ": ");
+  YYFPRINTF (yyoutput, ": ");
 
 # ifdef YYPRINT
   if (yytype < YYNTOKENS)
@@ -997,94 +1004,94 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 165 "../../src/parse-gram.y"
+#line 165 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1003 "../../src/parse-gram.c"
+#line 1010 "parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
-#line 178 "../../src/parse-gram.y"
+#line 178 "parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 1008 "../../src/parse-gram.c"
+#line 1015 "parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
-#line 167 "../../src/parse-gram.y"
+#line 167 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1013 "../../src/parse-gram.c"
+#line 1020 "parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
-#line 171 "../../src/parse-gram.y"
+#line 171 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1018 "../../src/parse-gram.c"
+#line 1025 "parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
-#line 172 "../../src/parse-gram.y"
+#line 172 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1023 "../../src/parse-gram.c"
+#line 1030 "parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
-#line 168 "../../src/parse-gram.y"
+#line 168 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1028 "../../src/parse-gram.c"
+#line 1035 "parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
-#line 169 "../../src/parse-gram.y"
+#line 169 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1033 "../../src/parse-gram.c"
+#line 1040 "parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
-#line 170 "../../src/parse-gram.y"
+#line 170 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1038 "../../src/parse-gram.c"
+#line 1045 "parse-gram.c"
         break;
       case 41: /* "\"type\"" */
-#line 176 "../../src/parse-gram.y"
+#line 176 "parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1043 "../../src/parse-gram.c"
+#line 1050 "parse-gram.c"
         break;
       case 45: /* "\"identifier\"" */
-#line 180 "../../src/parse-gram.y"
+#line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1048 "../../src/parse-gram.c"
+#line 1055 "parse-gram.c"
         break;
       case 46: /* "\"identifier:\"" */
-#line 182 "../../src/parse-gram.y"
+#line 182 "parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1053 "../../src/parse-gram.c"
+#line 1060 "parse-gram.c"
         break;
       case 48: /* "\"%{...%}\"" */
-#line 174 "../../src/parse-gram.y"
+#line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1058 "../../src/parse-gram.c"
+#line 1065 "parse-gram.c"
         break;
       case 49: /* "\"epilogue\"" */
-#line 174 "../../src/parse-gram.y"
+#line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1063 "../../src/parse-gram.c"
+#line 1070 "parse-gram.c"
         break;
       case 50: /* "\"{...}\"" */
-#line 173 "../../src/parse-gram.y"
+#line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1068 "../../src/parse-gram.c"
+#line 1075 "parse-gram.c"
         break;
       case 71: /* "symbol" */
-#line 180 "../../src/parse-gram.y"
+#line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1073 "../../src/parse-gram.c"
+#line 1080 "parse-gram.c"
         break;
       case 72: /* "action" */
-#line 173 "../../src/parse-gram.y"
+#line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1078 "../../src/parse-gram.c"
+#line 1085 "parse-gram.c"
         break;
       case 73: /* "string_as_id" */
-#line 180 "../../src/parse-gram.y"
+#line 180 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1083 "../../src/parse-gram.c"
+#line 1090 "parse-gram.c"
         break;
       case 74: /* "string_content" */
-#line 165 "../../src/parse-gram.y"
+#line 165 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1088 "../../src/parse-gram.c"
+#line 1095 "parse-gram.c"
         break;
       default:
         break;
@@ -1249,7 +1256,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code. */
-#line 69 "../../src/parse-gram.y"
+#line 69 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1257,8 +1264,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 870 of yacc.c.  */
-#line 1262 "../../src/parse-gram.c"
+/* Line 877 of yacc.c.  */
+#line 1269 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1292,7 +1299,7 @@ YYLTYPE yylloc;
 	   data in use in that stack, in bytes.  This used to be a
 	   conditional around just the two extra args, but that might
 	   be undefined if yyoverflow is a macro.  */
-	yyoverflow (_("parser stack overflow"),
+	yyoverflow (YY_("memory exhausted"),
 		    &yyss1, yysize * sizeof (*yyssp),
 		    &yyvs1, yysize * sizeof (*yyvsp),
 		    &yyls1, yysize * sizeof (*yylsp),
@@ -1303,11 +1310,11 @@ YYLTYPE yylloc;
       }
 #else /* no yyoverflow */
 # ifndef YYSTACK_RELOCATE
-      goto yyoverflowlab;
+      goto yyexhaustedlab;
 # else
       /* Extend the stack our own way.  */
       if (YYMAXDEPTH <= yystacksize)
-	goto yyoverflowlab;
+	goto yyexhaustedlab;
       yystacksize *= 2;
       if (YYMAXDEPTH < yystacksize)
 	yystacksize = YYMAXDEPTH;
@@ -1317,7 +1324,7 @@ YYLTYPE yylloc;
 	union yyalloc *yyptr =
 	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
 	if (! yyptr)
-	  goto yyoverflowlab;
+	  goto yyexhaustedlab;
 	YYSTACK_RELOCATE (yyss);
 	YYSTACK_RELOCATE (yyvs);
 	YYSTACK_RELOCATE (yyls);
@@ -1332,14 +1339,14 @@ YYLTYPE yylloc;
       yyvsp = yyvs + yysize - 1;
       yylsp = yyls + yysize - 1;
 
-      YYDPRINTF ((stderr, _("Stack size increased to %lu\n"),
+      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
 		  (unsigned long int) yystacksize));
 
       if (yyss + yystacksize - 1 <= yyssp)
 	YYABORT;
     }
 
-  YYDPRINTF ((stderr, _("Entering state %d\n"), yystate));
+  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
 
   goto yybackup;
 
@@ -1363,19 +1370,19 @@ yybackup:
   /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
   if (yychar == YYEMPTY)
     {
-      YYDPRINTF ((stderr, _("Reading a token: ")));
+      YYDPRINTF ((stderr, "Reading a token: "));
       yychar = YYLEX;
     }
 
   if (yychar <= YYEOF)
     {
       yychar = yytoken = YYEOF;
-      YYDPRINTF ((stderr, _("Now at end of input.\n")));
+      YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
   else
     {
       yytoken = YYTRANSLATE (yychar);
-      YY_SYMBOL_PRINT (_("Next token is"), yytoken, &yylval, &yylloc);
+      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
     }
 
   /* If the proper action on seeing token YYTOKEN is to reduce or to
@@ -1396,7 +1403,7 @@ yybackup:
     YYACCEPT;
 
   /* Shift the look-ahead token.  */
-  YY_SYMBOL_PRINT (_("Shifting"), yytoken, &yylval, &yylloc);
+  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 
   /* Discard the token being shifted unless it is eof.  */
   if (yychar != YYEOF)
@@ -1447,47 +1454,47 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 203 "../../src/parse-gram.y"
+#line 203 "parse-gram.y"
     { prologue_augment ((yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 7:
-#line 204 "../../src/parse-gram.y"
+#line 204 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 205 "../../src/parse-gram.y"
+#line 205 "parse-gram.y"
     { muscle_insert ((yyvsp[-1].chars), (yyvsp[0].chars)); }
     break;
 
   case 9:
-#line 206 "../../src/parse-gram.y"
+#line 206 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-#line 207 "../../src/parse-gram.y"
+#line 207 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 11:
-#line 208 "../../src/parse-gram.y"
+#line 208 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
     break;
 
   case 12:
-#line 209 "../../src/parse-gram.y"
+#line 209 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
     break;
 
   case 13:
-#line 210 "../../src/parse-gram.y"
+#line 210 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
     break;
 
   case 14:
-#line 212 "../../src/parse-gram.y"
+#line 212 "parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
@@ -1495,81 +1502,81 @@ yyreduce:
     break;
 
   case 15:
-#line 217 "../../src/parse-gram.y"
+#line 217 "parse-gram.y"
     {
     muscle_code_grow ("initial_action", (yyvsp[0].chars), (yylsp[0]));
   }
     break;
 
   case 16:
-#line 220 "../../src/parse-gram.y"
+#line 220 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 17:
-#line 221 "../../src/parse-gram.y"
+#line 221 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 18:
-#line 222 "../../src/parse-gram.y"
+#line 222 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
     break;
 
   case 19:
-#line 223 "../../src/parse-gram.y"
+#line 223 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 20:
-#line 224 "../../src/parse-gram.y"
+#line 224 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 21:
-#line 225 "../../src/parse-gram.y"
+#line 225 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
     break;
 
   case 22:
-#line 226 "../../src/parse-gram.y"
+#line 226 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 23:
-#line 227 "../../src/parse-gram.y"
+#line 227 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 24:
-#line 228 "../../src/parse-gram.y"
+#line 228 "parse-gram.y"
     { skeleton = (yyvsp[0].chars); }
     break;
 
   case 25:
-#line 229 "../../src/parse-gram.y"
+#line 229 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 26:
-#line 230 "../../src/parse-gram.y"
+#line 230 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 27:
-#line 231 "../../src/parse-gram.y"
+#line 231 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 31:
-#line 239 "../../src/parse-gram.y"
+#line 239 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
     break;
 
   case 32:
-#line 243 "../../src/parse-gram.y"
+#line 243 "parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", (yylsp[0]).start.line);
@@ -1578,7 +1585,7 @@ yyreduce:
     break;
 
   case 33:
-#line 249 "../../src/parse-gram.y"
+#line 249 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1588,7 +1595,7 @@ yyreduce:
     break;
 
   case 34:
-#line 256 "../../src/parse-gram.y"
+#line 256 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1598,26 +1605,26 @@ yyreduce:
     break;
 
   case 35:
-#line 263 "../../src/parse-gram.y"
+#line 263 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 36:
-#line 267 "../../src/parse-gram.y"
+#line 267 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 37:
-#line 273 "../../src/parse-gram.y"
+#line 273 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 38:
-#line 274 "../../src/parse-gram.y"
+#line 274 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1625,12 +1632,12 @@ yyreduce:
     break;
 
   case 39:
-#line 278 "../../src/parse-gram.y"
+#line 278 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 40:
-#line 279 "../../src/parse-gram.y"
+#line 279 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1638,7 +1645,7 @@ yyreduce:
     break;
 
   case 41:
-#line 284 "../../src/parse-gram.y"
+#line 284 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1648,7 +1655,7 @@ yyreduce:
     break;
 
   case 42:
-#line 294 "../../src/parse-gram.y"
+#line 294 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1663,49 +1670,49 @@ yyreduce:
     break;
 
   case 43:
-#line 308 "../../src/parse-gram.y"
+#line 308 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 44:
-#line 309 "../../src/parse-gram.y"
+#line 309 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 45:
-#line 310 "../../src/parse-gram.y"
+#line 310 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 46:
-#line 314 "../../src/parse-gram.y"
+#line 314 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 47:
-#line 315 "../../src/parse-gram.y"
+#line 315 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); }
     break;
 
   case 48:
-#line 321 "../../src/parse-gram.y"
+#line 321 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 49:
-#line 322 "../../src/parse-gram.y"
+#line 322 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 50:
-#line 328 "../../src/parse-gram.y"
+#line 328 "parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
      }
     break;
 
   case 51:
-#line 332 "../../src/parse-gram.y"
+#line 332 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]));
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
@@ -1713,7 +1720,7 @@ yyreduce:
     break;
 
   case 52:
-#line 337 "../../src/parse-gram.y"
+#line 337 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]));
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
@@ -1722,7 +1729,7 @@ yyreduce:
     break;
 
   case 53:
-#line 343 "../../src/parse-gram.y"
+#line 343 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]));
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
@@ -1731,7 +1738,7 @@ yyreduce:
     break;
 
   case 54:
-#line 349 "../../src/parse-gram.y"
+#line 349 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]));
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -1741,7 +1748,7 @@ yyreduce:
     break;
 
   case 60:
-#line 378 "../../src/parse-gram.y"
+#line 378 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at ((yyloc), _("POSIX forbids declarations in the grammar"));
@@ -1749,74 +1756,74 @@ yyreduce:
     break;
 
   case 61:
-#line 383 "../../src/parse-gram.y"
+#line 383 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 62:
-#line 389 "../../src/parse-gram.y"
+#line 389 "parse-gram.y"
     { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
     break;
 
   case 64:
-#line 393 "../../src/parse-gram.y"
+#line 393 "parse-gram.y"
     { grammar_rule_end ((yylsp[0])); }
     break;
 
   case 65:
-#line 394 "../../src/parse-gram.y"
+#line 394 "parse-gram.y"
     { grammar_rule_end ((yylsp[0])); }
     break;
 
   case 67:
-#line 400 "../../src/parse-gram.y"
+#line 400 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 68:
-#line 402 "../../src/parse-gram.y"
+#line 402 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 69:
-#line 404 "../../src/parse-gram.y"
+#line 404 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 70:
-#line 406 "../../src/parse-gram.y"
+#line 406 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 71:
-#line 408 "../../src/parse-gram.y"
+#line 408 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
     break;
 
   case 72:
-#line 410 "../../src/parse-gram.y"
+#line 410 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
     break;
 
   case 73:
-#line 414 "../../src/parse-gram.y"
+#line 414 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
     break;
 
   case 74:
-#line 415 "../../src/parse-gram.y"
+#line 415 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
     break;
 
   case 75:
-#line 420 "../../src/parse-gram.y"
+#line 420 "parse-gram.y"
     { (yyval.chars) = (yyvsp[0].chars); }
     break;
 
   case 76:
-#line 426 "../../src/parse-gram.y"
+#line 426 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]));
@@ -1824,12 +1831,12 @@ yyreduce:
     break;
 
   case 77:
-#line 435 "../../src/parse-gram.y"
+#line 435 "parse-gram.y"
     { (yyval.chars) = (yyvsp[0].chars); }
     break;
 
   case 79:
-#line 442 "../../src/parse-gram.y"
+#line 442 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", (yyvsp[0].chars), (yylsp[0]));
       scanner_last_string_free ();
@@ -1840,8 +1847,8 @@ yyreduce:
       default: break;
     }
 
-/* Line 1066 of yacc.c.  */
-#line 1845 "../../src/parse-gram.c"
+/* Line 1073 of yacc.c.  */
+#line 1852 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1893,11 +1900,11 @@ yyerrlab:
 #if 0
 	  /* This is so xgettext sees the translatable formats that are
 	     constructed on the fly.  */
-	  _("syntax error, unexpected %s");
-	  _("syntax error, unexpected %s, expecting %s");
-	  _("syntax error, unexpected %s, expecting %s or %s");
-	  _("syntax error, unexpected %s, expecting %s or %s or %s");
-	  _("syntax error, unexpected %s, expecting %s or %s or %s or %s");
+	  YY_("syntax error, unexpected %s");
+	  YY_("syntax error, unexpected %s, expecting %s");
+	  YY_("syntax error, unexpected %s, expecting %s or %s");
+	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
+	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
 #endif
 	  char *yyfmt;
 	  char const *yyf;
@@ -1940,7 +1947,7 @@ yyerrlab:
 		yyprefix = yyor;
 	      }
 
-	  yyf = _(yyformat);
+	  yyf = YY_(yyformat);
 	  yysize1 = yysize + yystrlen (yyf);
 	  yysize_overflow |= yysize1 < yysize;
 	  yysize = yysize1;
@@ -1971,11 +1978,14 @@ yyerrlab:
 	      YYSTACK_FREE (yymsg);
 	    }
 	  else
-	    yyerror (_("syntax error; also memory exhausted"));
+	    {
+	      yyerror (YY_("syntax error"));
+	      goto yyexhaustedlab;
+	    }
 	}
       else
 #endif /* YYERROR_VERBOSE */
-	yyerror (_("syntax error"));
+	yyerror (YY_("syntax error"));
     }
 
   yyerror_range[0] = yylloc;
@@ -1994,7 +2004,7 @@ yyerrlab:
         }
       else
 	{
-	  yydestruct (_("Error: discarding"), yytoken, &yylval, &yylloc);
+	  yydestruct ("Error: discarding", yytoken, &yylval, &yylloc);
 	  yychar = YYEMPTY;
 	}
     }
@@ -2048,7 +2058,7 @@ yyerrlab1:
 	YYABORT;
 
       yyerror_range[0] = *yylsp;
-      yydestruct (_("Error: popping"), yystos[yystate], yyvsp, yylsp);
+      yydestruct ("Error: popping", yystos[yystate], yyvsp, yylsp);
       YYPOPSTACK;
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
@@ -2066,7 +2076,7 @@ yyerrlab1:
   *++yylsp = yyloc;
 
   /* Shift the error token. */
-  YY_SYMBOL_PRINT (_("Shifting"), yystos[yyn], yyvsp, yylsp);
+  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);
 
   yystate = yyn;
   goto yynewstate;
@@ -2087,18 +2097,18 @@ yyabortlab:
   goto yyreturn;
 
 #ifndef yyoverflow
-/*----------------------------------------------.
-| yyoverflowlab -- parser overflow comes here.  |
-`----------------------------------------------*/
-yyoverflowlab:
-  yyerror (_("parser stack overflow"));
+/*-------------------------------------------------.
+| yyexhaustedlab -- memory exhaustion comes here.  |
+`-------------------------------------------------*/
+yyexhaustedlab:
+  yyerror (YY_("memory exhausted"));
   yyresult = 2;
   /* Fall through.  */
 #endif
 
 yyreturn:
   if (yychar != YYEOF && yychar != YYEMPTY)
-     yydestruct (_("Error: discarding lookahead"),
+     yydestruct ("Error: discarding lookahead",
 		 yytoken, &yylval, &yylloc);
   if (yyssp != yyss)
     for (;;)
@@ -2107,7 +2117,7 @@ yyreturn:
 	YYPOPSTACK;
 	if (yyssp == yyss)
 	  break;
-	yydestruct (_("Error: popping"),
+	yydestruct ("Error: popping",
 		    yystos[*yyssp], yyvsp, yylsp);
       }
 #ifndef yyoverflow
@@ -2118,7 +2128,7 @@ yyreturn:
 }
 
 
-#line 448 "../../src/parse-gram.y"
+#line 448 "parse-gram.y"
 
 
 
