@@ -100,12 +100,9 @@ do {							\
 #define yyerror(Msg) \
         gram_error (yycontrol, &yylloc, Msg)
 
-/* When debugging our pure parser, we want to see values and locations
-   of the tokens.  */
 #define YYPRINT(File, Type, Value) \
-        yyprint (File, &yylloc, Type, &Value)
-static void yyprint (FILE *file, const location_t *loc,
-                     int type, const yystype *value);
+        yyprint (File, Type, &Value)
+static void yyprint (FILE *file, int type, const yystype *value);
 
 symbol_class current_class = unknown_sym;
 char *current_type = 0;
@@ -225,7 +222,7 @@ braced_code_t current_braced_code = action_braced_code;
 #endif
 
 #ifndef YYSTYPE
-#line 91 "parse-gram.y"
+#line 88 "parse-gram.y"
 typedef union {
   symbol_t *symbol;
   symbol_list_t *list;
@@ -234,7 +231,7 @@ typedef union {
   associativity assoc;
 } yystype;
 /* Line 232 of /usr/local/share/bison/bison.simple.  */
-#line 238 "parse-gram.c"
+#line 235 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
@@ -255,7 +252,7 @@ typedef struct yyltype
 
 
 /* Line 252 of /usr/local/share/bison/bison.simple.  */
-#line 259 "parse-gram.c"
+#line 256 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -444,14 +441,14 @@ static const signed char yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   158,   158,   171,   173,   176,   178,   179,   180,   181,
-     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
-     192,   193,   196,   198,   199,   203,   210,   209,   220,   219,
-     232,   231,   237,   237,   242,   251,   266,   268,   269,   272,
-     274,   279,   281,   285,   290,   295,   301,   307,   317,   320,
-     329,   331,   337,   339,   343,   342,   347,   349,   352,   355,
-     357,   359,   363,   365,   366,   369,   375,   384,   392,   397,
-     403,   405
+       0,   155,   155,   168,   170,   173,   175,   176,   177,   178,
+     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
+     189,   190,   193,   195,   196,   200,   207,   206,   217,   216,
+     229,   228,   234,   234,   239,   248,   263,   265,   266,   269,
+     271,   276,   278,   282,   287,   292,   298,   304,   314,   317,
+     326,   328,   334,   336,   340,   339,   344,   346,   349,   352,
+     354,   356,   360,   362,   363,   366,   372,   381,   389,   394,
+     400,   402
 };
 #endif
 
@@ -696,7 +693,7 @@ while (0)
 #ifdef YYLEX_PARAM
 # define YYLEX	yylex (&yylval, &yylloc, YYLEX_PARAM)
 #else
-# define YYLEX	yylex (&yylval, &yylloc, )
+# define YYLEX	yylex (&yylval, &yylloc)
 #endif
 
 /* Enable debugging if requested.  */
@@ -712,11 +709,17 @@ do {						\
   if (yydebug)					\
     YYFPRINTF Args;				\
 } while (0)
+# define YYDSYMPRINT(Args)			\
+do {						\
+  if (yydebug)					\
+    yysymprint Args;				\
+} while (0)
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
 int yydebug;
 #else /* !YYDEBUG */
 # define YYDPRINTF(Args)
+# define YYDSYMPRINT(Args)
 #endif /* !YYDEBUG */
 
 /* YYINITDEPTH -- initial size of the parser's stacks.  */
@@ -823,7 +826,15 @@ int yyparse (void *);
 int yyparse (void);
 # endif
 #endif
-static void yydestructor (int symbol_type, YYSTYPE symbol_value);
+
+#if defined (__STDC__) || defined (__cplusplus)
+static void yydestructor (int yytype,
+			  YYSTYPE yyvalue, YYLTYPE yylocation);
+# if YYDEBUG
+static void yysymprint (FILE* out, int yytype,
+			YYSTYPE yyvalue, YYLTYPE yylocation);
+# endif
+#endif
 
 
 
@@ -1024,21 +1035,11 @@ yybackup:
     {
       yychar1 = YYTRANSLATE (yychar);
 
-#if YYDEBUG
-     /* We have to keep this `#if YYDEBUG', since we use variables
-	which are defined only if `YYDEBUG' is set.  */
-      if (yydebug)
-	{
-	  YYFPRINTF (stderr, "Next token is %d (%s",
-		     yychar, yytname[yychar1]);
-	  /* Give the individual parser a way to print the precise
-	     meaning of a token, for further debugging info.  */
-# ifdef YYPRINT
-	  YYPRINT (stderr, yychar, yylval);
-# endif
-	  YYFPRINTF (stderr, ")\n");
-	}
-#endif
+      /* We have to keep this `#if YYDEBUG', since we use variables
+	 which are defined only if `YYDEBUG' is set.  */
+      YYDPRINTF ((stderr, "Next token is "));
+      YYDSYMPRINT ((stderr, yychar1, yylval, yyloc));
+      YYDPRINTF ((stderr, "\n"));
     }
 
   yyn += yychar1;
@@ -1136,7 +1137,7 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 160 "parse-gram.y"
+#line 157 "parse-gram.y"
     {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
@@ -1144,94 +1145,94 @@ yyreduce:
     break;
 
   case 6:
-#line 178 "parse-gram.y"
+#line 175 "parse-gram.y"
     { prologue_augment (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 7:
-#line 179 "parse-gram.y"
+#line 176 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 180 "parse-gram.y"
+#line 177 "parse-gram.y"
     { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
 
   case 9:
-#line 181 "parse-gram.y"
+#line 178 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 182 "parse-gram.y"
+#line 179 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 183 "parse-gram.y"
+#line 180 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 184 "parse-gram.y"
+#line 181 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].string; }
     break;
 
   case 13:
-#line 185 "parse-gram.y"
+#line 182 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 14:
-#line 186 "parse-gram.y"
+#line 183 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].string; }
     break;
 
   case 15:
-#line 187 "parse-gram.y"
+#line 184 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 16:
-#line 188 "parse-gram.y"
+#line 185 "parse-gram.y"
     { spec_outfile = yyvsp[0].string; }
     break;
 
   case 17:
-#line 189 "parse-gram.y"
+#line 186 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 18:
-#line 190 "parse-gram.y"
+#line 187 "parse-gram.y"
     { skeleton = yyvsp[0].string; }
     break;
 
   case 19:
-#line 191 "parse-gram.y"
+#line 188 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
   case 20:
-#line 192 "parse-gram.y"
+#line 189 "parse-gram.y"
     { report_flag = 1; }
     break;
 
   case 21:
-#line 193 "parse-gram.y"
+#line 190 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
   case 24:
-#line 200 "parse-gram.y"
+#line 197 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 25:
-#line 204 "parse-gram.y"
+#line 201 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
@@ -1240,12 +1241,12 @@ yyreduce:
     break;
 
   case 26:
-#line 210 "parse-gram.y"
+#line 207 "parse-gram.y"
     { current_braced_code = destructor_braced_code; }
     break;
 
   case 27:
-#line 212 "parse-gram.y"
+#line 209 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1256,12 +1257,12 @@ yyreduce:
     break;
 
   case 28:
-#line 220 "parse-gram.y"
+#line 217 "parse-gram.y"
     { current_braced_code = printer_braced_code; }
     break;
 
   case 29:
-#line 222 "parse-gram.y"
+#line 219 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1272,12 +1273,12 @@ yyreduce:
     break;
 
   case 30:
-#line 232 "parse-gram.y"
+#line 229 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 31:
-#line 233 "parse-gram.y"
+#line 230 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1285,12 +1286,12 @@ yyreduce:
     break;
 
   case 32:
-#line 237 "parse-gram.y"
+#line 234 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 33:
-#line 238 "parse-gram.y"
+#line 235 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1298,7 +1299,7 @@ yyreduce:
     break;
 
   case 34:
-#line 243 "parse-gram.y"
+#line 240 "parse-gram.y"
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1308,7 +1309,7 @@ yyreduce:
     break;
 
   case 35:
-#line 253 "parse-gram.y"
+#line 250 "parse-gram.y"
     {
       symbol_list_t *list;
       ++current_prec;
@@ -1323,163 +1324,163 @@ yyreduce:
     break;
 
   case 36:
-#line 267 "parse-gram.y"
+#line 264 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
   case 37:
-#line 268 "parse-gram.y"
+#line 265 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
   case 38:
-#line 269 "parse-gram.y"
+#line 266 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
   case 39:
-#line 273 "parse-gram.y"
+#line 270 "parse-gram.y"
     { current_type = NULL;}
     break;
 
   case 40:
-#line 274 "parse-gram.y"
+#line 271 "parse-gram.y"
     { current_type = yyvsp[0].string; }
     break;
 
   case 41:
-#line 280 "parse-gram.y"
+#line 277 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 42:
-#line 281 "parse-gram.y"
+#line 278 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 43:
-#line 287 "parse-gram.y"
+#line 284 "parse-gram.y"
     {
        current_type = yyvsp[0].string;
      }
     break;
 
   case 44:
-#line 291 "parse-gram.y"
+#line 288 "parse-gram.y"
     {
-       symbol_class_set (yyvsp[0].symbol, current_class);
+       symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, yylsp[0], current_type);
      }
     break;
 
   case 45:
-#line 296 "parse-gram.y"
+#line 293 "parse-gram.y"
     {
-      symbol_class_set (yyvsp[-1].symbol, current_class);
+      symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, yylsp[-1], current_type);
-      symbol_user_token_number_set (yyvsp[-1].symbol, yyvsp[0].integer);
+      symbol_user_token_number_set (yyvsp[-1].symbol, yyvsp[0].integer, yylsp[0]);
     }
     break;
 
   case 46:
-#line 302 "parse-gram.y"
+#line 299 "parse-gram.y"
     {
-      symbol_class_set (yyvsp[-1].symbol, current_class);
+      symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, yylsp[-1], current_type);
       symbol_make_alias (yyvsp[-1].symbol, yyvsp[0].symbol);
     }
     break;
 
   case 47:
-#line 308 "parse-gram.y"
+#line 305 "parse-gram.y"
     {
-      symbol_class_set (yyvsp[-2].symbol, current_class);
+      symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, yylsp[-2], current_type);
-      symbol_user_token_number_set (yyvsp[-2].symbol, yyvsp[-1].integer);
+      symbol_user_token_number_set (yyvsp[-2].symbol, yyvsp[-1].integer, yylsp[-1]);
       symbol_make_alias (yyvsp[-2].symbol, yyvsp[0].symbol);
     }
     break;
 
   case 48:
-#line 319 "parse-gram.y"
+#line 316 "parse-gram.y"
     {;}
     break;
 
   case 49:
-#line 321 "parse-gram.y"
+#line 318 "parse-gram.y"
     {;}
     break;
 
   case 54:
-#line 343 "parse-gram.y"
+#line 340 "parse-gram.y"
     { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
     break;
 
   case 55:
-#line 344 "parse-gram.y"
+#line 341 "parse-gram.y"
     {;}
     break;
 
   case 56:
-#line 348 "parse-gram.y"
+#line 345 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 57:
-#line 349 "parse-gram.y"
+#line 346 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 58:
-#line 354 "parse-gram.y"
+#line 351 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 59:
-#line 356 "parse-gram.y"
+#line 353 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 60:
-#line 358 "parse-gram.y"
+#line 355 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 61:
-#line 360 "parse-gram.y"
-    { grammar_current_rule_prec_set (yyvsp[0].symbol); }
+#line 357 "parse-gram.y"
+    { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 62:
-#line 364 "parse-gram.y"
+#line 361 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 63:
-#line 365 "parse-gram.y"
+#line 362 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 64:
-#line 366 "parse-gram.y"
+#line 363 "parse-gram.y"
     { yyval.symbol = getsym (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 65:
-#line 371 "parse-gram.y"
+#line 368 "parse-gram.y"
     { yyval.string = yyvsp[0].string; }
     break;
 
   case 66:
-#line 377 "parse-gram.y"
+#line 374 "parse-gram.y"
     {
       yyval.symbol = getsym (yyvsp[0].string, yylsp[0]);
-      symbol_class_set (yyval.symbol, token_sym);
+      symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
     }
     break;
 
   case 67:
-#line 386 "parse-gram.y"
+#line 383 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
@@ -1487,14 +1488,14 @@ yyreduce:
     break;
 
   case 68:
-#line 394 "parse-gram.y"
+#line 391 "parse-gram.y"
     {
       yyval.string = xstrdup ("");
     }
     break;
 
   case 69:
-#line 398 "parse-gram.y"
+#line 395 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string;
     }
@@ -1503,8 +1504,8 @@ yyreduce:
 
     }
 
-/* Line 996 of /usr/local/share/bison/bison.simple.  */
-#line 1508 "parse-gram.c"
+/* Line 1000 of /usr/local/share/bison/bison.simple.  */
+#line 1509 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1616,27 +1617,12 @@ yyerrlab1:
 	  /* Pop the rest of the stack.  */
 	  while (yyssp > yyss)
 	    {
-#if YYDEBUG
-	      if (yydebug)
-		{
-		  if (yystos[*yyssp] < YYNTOKENS)
-		    {
-		      YYFPRINTF (stderr, "Error: popping token %d (%s",
-				 yytoknum[yystos[*yyssp]],
-				 yytname[yystos[*yyssp]]);
-# ifdef YYPRINT
-		      YYPRINT (stderr, yytoknum[yystos[*yyssp]], *yyvsp);
-# endif
-		      YYFPRINTF (stderr, ")\n");
-		    }
-		  else
-		    {
-		      YYFPRINTF (stderr, "Error: popping nonterminal (%s)\n",
-				 yytname[yystos[*yyssp]]);
-		    }
-		}
-#endif
-	      yydestructor (yystos[*yyssp], *yyvsp);
+	      YYDPRINTF ((stderr, "Error: popping "));
+	      YYDSYMPRINT ((stderr,
+			    yystos[*yyssp],
+			    *yyvsp, *yylsp));
+	      YYDPRINTF ((stderr, "\n"));
+	      yydestructor (yystos[*yyssp], *yyvsp, *yylsp);
 	      YYPOPSTACK;
 	    }
 	  YYABORT;
@@ -1644,7 +1630,7 @@ yyerrlab1:
 
       YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
 		  yychar, yytname[yychar1]));
-      yydestructor (yychar1, yylval);
+      yydestructor (yychar1, yylval, yylloc);
       yychar = YYEMPTY;
     }
 
@@ -1671,27 +1657,12 @@ yyerrlab1:
       if (yyssp == yyss)
 	YYABORT;
 
-#if YYDEBUG
-      if (yydebug)
-	{
-	  if (yystos[yystate] < YYNTOKENS)
-	    {
-	      YYFPRINTF (stderr, "Error: popping token %d (%s",
-			 yytoknum[yystos[yystate]], yytname[yystos[yystate]]);
-# ifdef YYPRINT
-	      YYPRINT (stderr, yytoknum[yystos[yystate]], *yyvsp);
-# endif
-	      YYFPRINTF (stderr, ")\n");
-	    }
-	  else
-	    {
-	      YYFPRINTF (stderr, "Error: popping nonterminal (%s)\n",
-			 yytname[yystos[yystate]]);
-	    }
-	}
-#endif
+      YYDPRINTF ((stderr, "Error: popping "));
+      YYDSYMPRINT ((stderr,
+		    yystos[*yyssp], *yyvsp, *yylsp));
+      YYDPRINTF ((stderr, "\n"));
 
-      yydestructor (yystos[yystate], *yyvsp);
+      yydestructor (yystos[yystate], *yyvsp, *yylsp);
       yyvsp--;
       yystate = *--yyssp;
       yylsp--;
@@ -1753,23 +1724,49 @@ yyreturn:
 }
 
 
-/*-------------------------------------------------.
-| Release the memory associated to SYMBOL-NUMBER.  |
-`-------------------------------------------------*/
+/*-----------------------------------------------.
+| Release the memory associated to this symbol.  |
+`-----------------------------------------------*/
+
+static void
+yydestructor (int yytype,
+	      YYSTYPE yyvalue, YYLTYPE yylocation)
+{
+  switch (yytype)
+    {
+      default:
+        break;
+    }
+}
+
+
+#if YYDEBUG
+/*-----------------------------.
+| Print this symbol on YYOUT.  |
+`-----------------------------*/
 
 static void
-yydestructor (int symbol_type, YYSTYPE symbol_value)
+yysymprint (FILE* yyout, int yytype,
+	    YYSTYPE yyvalue, YYLTYPE yylocation)
 {
-  switch (symbol_type)
+  if (yytype < YYNTOKENS)
+    YYFPRINTF (yyout, "token %s (", yytname[yytype]);
+  else
+    YYFPRINTF (yyout, "nterm %s (", yytname[yytype]);
+# ifdef YYPRINT
+  YYPRINT (yyout, yytype, yyvalue);
+# else
+  switch (yytype)
     {
       default:
-        YYDPRINTF ((stderr, "yydestructor: unknown symbol type: %d (%s)\n",
-		    symbol_type, yytname[symbol_type]));
         break;
     }
+# endif /* !defined YYPRINT. */
+  YYFPRINTF (yyout, ")");
 }
+#endif /* YYDEBUG. */
 
-#line 407 "parse-gram.y"
+#line 404 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
@@ -1777,11 +1774,9 @@ yydestructor (int symbol_type, YYSTYPE symbol_value)
 
 static void
 yyprint (FILE *file,
-         const location_t *loc, int type, const yystype *value)
+         int type, const yystype *value)
 {
-  fputs (" (", file);
-  LOCATION_PRINT (file, *loc);
-  fputs (")", file);
+  fputc (' ', file);
   switch (type)
     {
     case CHARACTER:
