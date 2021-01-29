@@ -172,7 +172,7 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 1 "../../src/parse-gram.y"
+#line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
@@ -253,7 +253,7 @@ static int current_prec = 0;
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 82 "../../src/parse-gram.y"
+#line 82 "parse-gram.y"
 typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
@@ -263,7 +263,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 196 of yacc.c.  */
-#line 267 "../../src/parse-gram.c"
+#line 267 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -287,7 +287,7 @@ typedef struct YYLTYPE
 
 
 /* Line 219 of yacc.c.  */
-#line 291 "../../src/parse-gram.c"
+#line 291 "parse-gram.c"
 
 #ifndef YYSIZE_T
 # if defined (__SIZE_TYPE__)
@@ -840,9 +840,14 @@ while (0)
 /* Enable debugging if requested.  */
 #if YYDEBUG
 
-# ifndef YYFPRINTF
+# ifdef YYFPRINTF
+#  define YYFPUTC(Char, Stream) YYFPRINTF (Stream, "%c", Char)
+#  define YYFPUTS(Char, Stream) YYFPRINTF (Stream, "%s", String)
+# else
 #  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYFPRINTF fprintf
+#  define YYFPUTC fputc
+#  define YYFPUTS fputs
 # endif
 
 # define YYDPRINTF(Args)			\
@@ -851,6 +856,12 @@ do {						\
     YYFPRINTF Args;				\
 } while (0)
 
+# define YYDPUTS(String, Stream)		\
+do {						\
+  if (yydebug)					\
+    YYFPUTS (String, Stream);			\
+} while (0)
+
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
 do {								\
   if (yydebug)							\
@@ -858,7 +869,7 @@ do {								\
       YYFPRINTF (stderr, "%s ", Title);				\
       yysymprint (stderr,					\
                   Type, Value, Location);	\
-      YYFPRINTF (stderr, "\n");					\
+      YYFPUTC ('\n', stderr);					\
     }								\
 } while (0)
 
@@ -877,10 +888,10 @@ yy_stack_print (bottom, top)
     short int *top;
 #endif
 {
-  YYFPRINTF (stderr, "Stack now");
+  YYFPUTS ("Stack now", stderr);
   for (/* Nothing. */; bottom <= top; ++bottom)
     YYFPRINTF (stderr, " %d", *bottom);
-  YYFPRINTF (stderr, "\n");
+  YYFPUTC ('\n', stderr);
 }
 
 # define YY_STACK_PRINT(Bottom, Top)				\
@@ -922,11 +933,15 @@ do {					\
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
 int yydebug;
+
 #else /* !YYDEBUG */
+
+# define YYDPUTS(String, File)
 # define YYDPRINTF(Args)
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 # define YY_STACK_PRINT(Bottom, Top)
 # define YY_REDUCE_PRINT(Rule)
+
 #endif /* !YYDEBUG */
 
 
@@ -1184,7 +1199,7 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
     YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);
 
   YY_LOCATION_PRINT (yyoutput, *yylocationp);
-  YYFPRINTF (yyoutput, ": ");
+  YYFPUTS (": ", yyoutput);
 
 # ifdef YYPRINT
   if (yytype < YYNTOKENS)
@@ -1193,99 +1208,99 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 169 "../../src/parse-gram.y"
+#line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1199 "../../src/parse-gram.c"
+#line 1214 "parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
-#line 182 "../../src/parse-gram.y"
+#line 182 "parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 1204 "../../src/parse-gram.c"
+#line 1219 "parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
-#line 171 "../../src/parse-gram.y"
+#line 171 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1209 "../../src/parse-gram.c"
+#line 1224 "parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
-#line 175 "../../src/parse-gram.y"
+#line 175 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1214 "../../src/parse-gram.c"
+#line 1229 "parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
-#line 176 "../../src/parse-gram.y"
+#line 176 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1219 "../../src/parse-gram.c"
+#line 1234 "parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
-#line 172 "../../src/parse-gram.y"
+#line 172 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1224 "../../src/parse-gram.c"
+#line 1239 "parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
-#line 173 "../../src/parse-gram.y"
+#line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1229 "../../src/parse-gram.c"
+#line 1244 "parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
-#line 174 "../../src/parse-gram.y"
+#line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1234 "../../src/parse-gram.c"
+#line 1249 "parse-gram.c"
         break;
       case 42: /* "\"type\"" */
-#line 180 "../../src/parse-gram.y"
+#line 180 "parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1239 "../../src/parse-gram.c"
+#line 1254 "parse-gram.c"
         break;
       case 46: /* "\"identifier\"" */
-#line 184 "../../src/parse-gram.y"
-        { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1244 "../../src/parse-gram.c"
+#line 184 "parse-gram.y"
+        { fputs ((yyvaluep->symbol)->tag, stderr); };
+#line 1259 "parse-gram.c"
         break;
       case 47: /* "\"identifier:\"" */
-#line 186 "../../src/parse-gram.y"
+#line 186 "parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1249 "../../src/parse-gram.c"
+#line 1264 "parse-gram.c"
         break;
       case 49: /* "\"%{...%}\"" */
-#line 178 "../../src/parse-gram.y"
+#line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1254 "../../src/parse-gram.c"
+#line 1269 "parse-gram.c"
         break;
       case 50: /* "\"epilogue\"" */
-#line 178 "../../src/parse-gram.y"
+#line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1259 "../../src/parse-gram.c"
+#line 1274 "parse-gram.c"
         break;
       case 51: /* "\"{...}\"" */
-#line 177 "../../src/parse-gram.y"
+#line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1264 "../../src/parse-gram.c"
+#line 1279 "parse-gram.c"
         break;
       case 72: /* "symbol" */
-#line 184 "../../src/parse-gram.y"
-        { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1269 "../../src/parse-gram.c"
+#line 184 "parse-gram.y"
+        { fputs ((yyvaluep->symbol)->tag, stderr); };
+#line 1284 "parse-gram.c"
         break;
       case 73: /* "action" */
-#line 177 "../../src/parse-gram.y"
+#line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1274 "../../src/parse-gram.c"
+#line 1289 "parse-gram.c"
         break;
       case 74: /* "string_as_id" */
-#line 184 "../../src/parse-gram.y"
-        { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1279 "../../src/parse-gram.c"
+#line 184 "parse-gram.y"
+        { fputs ((yyvaluep->symbol)->tag, stderr); };
+#line 1294 "parse-gram.c"
         break;
       case 75: /* "string_content" */
-#line 169 "../../src/parse-gram.y"
+#line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1284 "../../src/parse-gram.c"
+#line 1299 "parse-gram.c"
         break;
       default:
         break;
     }
-  YYFPRINTF (yyoutput, ")");
+  YYFPUTC (')', yyoutput);
 }
 
 #endif /* ! YYDEBUG */
@@ -1428,7 +1443,7 @@ YYLTYPE yylloc;
      rule.  */
   int yylen;
 
-  YYDPRINTF ((stderr, "Starting parse\n"));
+  YYDPUTS ("Starting parse\n", stderr);
 
   yystate = 0;
   yyerrstatus = 0;
@@ -1451,7 +1466,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code. */
-#line 72 "../../src/parse-gram.y"
+#line 72 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1459,8 +1474,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 1053 of yacc.c.  */
-#line 1464 "../../src/parse-gram.c"
+/* Line 1068 of yacc.c.  */
+#line 1479 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1565,14 +1580,14 @@ yybackup:
   /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
   if (yychar == YYEMPTY)
     {
-      YYDPRINTF ((stderr, "Reading a token: "));
+      YYDPUTS ("Reading a token: ", stderr);
       yychar = YYLEX;
     }
 
   if (yychar <= YYEOF)
     {
       yychar = yytoken = YYEOF;
-      YYDPRINTF ((stderr, "Now at end of input.\n"));
+      YYDPUTS ("Now at end of input.\n", stderr);
     }
   else
     {
@@ -1649,52 +1664,52 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 207 "../../src/parse-gram.y"
+#line 207 "parse-gram.y"
     { prologue_augment ((yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 7:
-#line 208 "../../src/parse-gram.y"
+#line 208 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 209 "../../src/parse-gram.y"
+#line 209 "parse-gram.y"
     { muscle_insert ((yyvsp[0].chars), "1"); }
     break;
 
   case 9:
-#line 210 "../../src/parse-gram.y"
+#line 210 "parse-gram.y"
     { muscle_insert ((yyvsp[-1].chars), (yyvsp[0].chars)); }
     break;
 
   case 10:
-#line 211 "../../src/parse-gram.y"
+#line 211 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 11:
-#line 212 "../../src/parse-gram.y"
+#line 212 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-#line 213 "../../src/parse-gram.y"
+#line 213 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
     break;
 
   case 13:
-#line 214 "../../src/parse-gram.y"
+#line 214 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
     break;
 
   case 14:
-#line 215 "../../src/parse-gram.y"
+#line 215 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
     break;
 
   case 15:
-#line 217 "../../src/parse-gram.y"
+#line 217 "parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
@@ -1702,86 +1717,86 @@ yyreduce:
     break;
 
   case 16:
-#line 222 "../../src/parse-gram.y"
+#line 222 "parse-gram.y"
     {
     muscle_code_grow ("initial_action", (yyvsp[0].chars), (yylsp[0]));
   }
     break;
 
   case 17:
-#line 225 "../../src/parse-gram.y"
+#line 225 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 18:
-#line 226 "../../src/parse-gram.y"
+#line 226 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 19:
-#line 227 "../../src/parse-gram.y"
+#line 227 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
     break;
 
   case 20:
-#line 228 "../../src/parse-gram.y"
+#line 228 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 21:
-#line 229 "../../src/parse-gram.y"
+#line 229 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 22:
-#line 230 "../../src/parse-gram.y"
+#line 230 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
     break;
 
   case 23:
-#line 231 "../../src/parse-gram.y"
+#line 231 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 24:
-#line 232 "../../src/parse-gram.y"
+#line 232 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 25:
-#line 233 "../../src/parse-gram.y"
+#line 233 "parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
     break;
 
   case 26:
-#line 234 "../../src/parse-gram.y"
+#line 234 "parse-gram.y"
     { skeleton = (yyvsp[0].chars); }
     break;
 
   case 27:
-#line 235 "../../src/parse-gram.y"
+#line 235 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 28:
-#line 236 "../../src/parse-gram.y"
+#line 236 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 29:
-#line 237 "../../src/parse-gram.y"
+#line 237 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 33:
-#line 245 "../../src/parse-gram.y"
+#line 245 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
     break;
 
   case 34:
-#line 249 "../../src/parse-gram.y"
+#line 249 "parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", (yylsp[0]).start.line);
@@ -1790,7 +1805,7 @@ yyreduce:
     break;
 
   case 35:
-#line 255 "../../src/parse-gram.y"
+#line 255 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1800,7 +1815,7 @@ yyreduce:
     break;
 
   case 36:
-#line 262 "../../src/parse-gram.y"
+#line 262 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1810,26 +1825,26 @@ yyreduce:
     break;
 
   case 37:
-#line 269 "../../src/parse-gram.y"
+#line 269 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 38:
-#line 273 "../../src/parse-gram.y"
+#line 273 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 39:
-#line 279 "../../src/parse-gram.y"
+#line 279 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 40:
-#line 280 "../../src/parse-gram.y"
+#line 280 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1837,12 +1852,12 @@ yyreduce:
     break;
 
   case 41:
-#line 284 "../../src/parse-gram.y"
+#line 284 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 42:
-#line 285 "../../src/parse-gram.y"
+#line 285 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1850,7 +1865,7 @@ yyreduce:
     break;
 
   case 43:
-#line 290 "../../src/parse-gram.y"
+#line 290 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1860,7 +1875,7 @@ yyreduce:
     break;
 
   case 44:
-#line 300 "../../src/parse-gram.y"
+#line 300 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1875,49 +1890,49 @@ yyreduce:
     break;
 
   case 45:
-#line 314 "../../src/parse-gram.y"
+#line 314 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 46:
-#line 315 "../../src/parse-gram.y"
+#line 315 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 47:
-#line 316 "../../src/parse-gram.y"
+#line 316 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 48:
-#line 320 "../../src/parse-gram.y"
+#line 320 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 49:
-#line 321 "../../src/parse-gram.y"
+#line 321 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); }
     break;
 
   case 50:
-#line 327 "../../src/parse-gram.y"
+#line 327 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 51:
-#line 328 "../../src/parse-gram.y"
+#line 328 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 52:
-#line 334 "../../src/parse-gram.y"
+#line 334 "parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
      }
     break;
 
   case 53:
-#line 338 "../../src/parse-gram.y"
+#line 338 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]));
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
@@ -1925,7 +1940,7 @@ yyreduce:
     break;
 
   case 54:
-#line 343 "../../src/parse-gram.y"
+#line 343 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]));
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
@@ -1934,7 +1949,7 @@ yyreduce:
     break;
 
   case 55:
-#line 349 "../../src/parse-gram.y"
+#line 349 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]));
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
@@ -1943,7 +1958,7 @@ yyreduce:
     break;
 
   case 56:
-#line 355 "../../src/parse-gram.y"
+#line 355 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]));
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -1953,7 +1968,7 @@ yyreduce:
     break;
 
   case 62:
-#line 384 "../../src/parse-gram.y"
+#line 384 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at ((yyloc), _("POSIX forbids declarations in the grammar"));
@@ -1961,74 +1976,74 @@ yyreduce:
     break;
 
   case 63:
-#line 389 "../../src/parse-gram.y"
+#line 389 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 64:
-#line 395 "../../src/parse-gram.y"
+#line 395 "parse-gram.y"
     { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
     break;
 
   case 66:
-#line 399 "../../src/parse-gram.y"
+#line 399 "parse-gram.y"
     { grammar_rule_end ((yylsp[0])); }
     break;
 
   case 67:
-#line 400 "../../src/parse-gram.y"
+#line 400 "parse-gram.y"
     { grammar_rule_end ((yylsp[0])); }
     break;
 
   case 69:
-#line 406 "../../src/parse-gram.y"
+#line 406 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 70:
-#line 408 "../../src/parse-gram.y"
+#line 408 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 71:
-#line 410 "../../src/parse-gram.y"
+#line 410 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 72:
-#line 412 "../../src/parse-gram.y"
+#line 412 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 73:
-#line 414 "../../src/parse-gram.y"
+#line 414 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
     break;
 
   case 74:
-#line 416 "../../src/parse-gram.y"
+#line 416 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
     break;
 
   case 75:
-#line 420 "../../src/parse-gram.y"
+#line 420 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
     break;
 
   case 76:
-#line 421 "../../src/parse-gram.y"
+#line 421 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
     break;
 
   case 77:
-#line 426 "../../src/parse-gram.y"
+#line 426 "parse-gram.y"
     { (yyval.chars) = (yyvsp[0].chars); }
     break;
 
   case 78:
-#line 432 "../../src/parse-gram.y"
+#line 432 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]));
@@ -2036,12 +2051,12 @@ yyreduce:
     break;
 
   case 79:
-#line 441 "../../src/parse-gram.y"
+#line 441 "parse-gram.y"
     { (yyval.chars) = (yyvsp[0].chars); }
     break;
 
   case 81:
-#line 448 "../../src/parse-gram.y"
+#line 448 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", (yyvsp[0].chars), (yylsp[0]));
       scanner_last_string_free ();
@@ -2052,8 +2067,8 @@ yyreduce:
       default: break;
     }
 
-/* Line 1249 of yacc.c.  */
-#line 2057 "../../src/parse-gram.c"
+/* Line 1264 of yacc.c.  */
+#line 2072 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -2263,7 +2278,7 @@ yyreturn:
 }
 
 
-#line 454 "../../src/parse-gram.y"
+#line 454 "parse-gram.y"
 
 
 