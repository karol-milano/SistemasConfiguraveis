@@ -167,7 +167,7 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 1 "parse-gram.y"
+#line 1 "../../src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
@@ -205,6 +205,9 @@
 #define YYLLOC_DEFAULT(Current, Rhs, N)  (Current) = lloc_default (Rhs, N)
 static YYLTYPE lloc_default (YYLTYPE const *, int);
 
+#define YY_LOCATION_PRINT(File, Loc) \
+          location_print (File, Loc)
+
 /* Request detailed syntax error messages, and pass them to GRAM_ERROR.
    FIXME: depends on the undocumented availability of YYLLOC.  */
 #undef  yyerror
@@ -240,7 +243,7 @@ int current_prec = 0;
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 78 "parse-gram.y"
+#line 81 "../../src/parse-gram.y"
 typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
@@ -250,7 +253,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 191 of yacc.c.  */
-#line 254 "parse-gram.c"
+#line 257 "../../src/parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -274,7 +277,7 @@ typedef struct YYLTYPE
 
 
 /* Line 214 of yacc.c.  */
-#line 278 "parse-gram.c"
+#line 281 "../../src/parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -480,14 +483,14 @@ static const yysigned_char yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short int yyrline[] =
 {
-       0,   171,   171,   179,   181,   185,   186,   187,   188,   189,
-     190,   191,   192,   193,   194,   199,   203,   204,   205,   206,
-     207,   208,   209,   210,   211,   212,   213,   214,   215,   219,
-     220,   221,   225,   231,   238,   245,   249,   256,   256,   261,
-     261,   266,   276,   291,   292,   293,   297,   298,   304,   305,
-     310,   314,   319,   325,   331,   342,   343,   352,   353,   359,
-     360,   365,   372,   372,   376,   377,   378,   383,   384,   386,
-     388,   390,   392,   397,   398,   402,   408,   417,   424,   426
+       0,   174,   174,   182,   184,   188,   189,   190,   191,   192,
+     193,   194,   195,   196,   197,   202,   206,   207,   208,   209,
+     210,   211,   212,   213,   214,   215,   216,   217,   218,   222,
+     223,   224,   228,   234,   241,   248,   252,   259,   259,   264,
+     264,   269,   279,   294,   295,   296,   300,   301,   307,   308,
+     313,   317,   322,   328,   334,   345,   346,   355,   356,   362,
+     363,   368,   375,   375,   379,   380,   381,   386,   387,   389,
+     391,   393,   395,   400,   401,   405,   411,   420,   427,   429
 };
 #endif
 
@@ -722,20 +725,50 @@ do								\
     }								\
 while (0)
 
+
 #define YYTERROR	1
 #define YYERRCODE	256
 
-/* YYLLOC_DEFAULT -- Compute the default location (before the actions
-   are run).  */
+
+/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
+   If N is 0, then set CURRENT to the empty location which ends
+   the previous symbol: RHS[0] (always defined).  */
 
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(Current, Rhs, N)		\
-   ((Current).first_line   = (Rhs)[1].first_line,	\
-    (Current).first_column = (Rhs)[1].first_column,	\
-    (Current).last_line    = (Rhs)[N].last_line,	\
-    (Current).last_column  = (Rhs)[N].last_column)
+# define YYLLOC_DEFAULT(Current, Rhs, N)				     \
+do {									     \
+  if (N)								     \
+    {									     \
+      (Current).first_line   = (Rhs)[1].first_line;			     \
+      (Current).first_column = (Rhs)[1].first_column;			     \
+      (Current).last_line    = (Rhs)[N].last_line;			     \
+      (Current).last_column  = (Rhs)[N].last_column;			     \
+    }									     \
+  else									     \
+    {									     \
+      (Current).first_line   = (Current).last_line   = (Rhs)[0].last_line;   \
+      (Current).first_column = (Current).last_column = (Rhs)[0].last_column; \
+    }									     \
+} while(0)
+#endif
+
+
+/* YY_LOCATION_PRINT -- Print the location on the stream.
+   This macro was not mandated originally: define only if we know
+   we won't break user code: when these are the locations we know.  */
+
+#ifndef YY_LOCATION_PRINT
+# if YYLTYPE_IS_TRIVIAL
+#  define YY_LOCATION_PRINT(File, Loc)			\
+     fprintf (File, "%d.%d-%d.%d",			\
+              (Loc).first_line, (Loc).first_column,	\
+              (Loc).last_line,  (Loc).last_column)
+# else
+#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
+# endif
 #endif
 
+
 /* YYLEX -- calling `yylex' with the right arguments.  */
 
 #ifdef YYLEX_PARAM
@@ -758,19 +791,13 @@ do {						\
     YYFPRINTF Args;				\
 } while (0)
 
-# define YYDSYMPRINT(Args)			\
-do {						\
-  if (yydebug)					\
-    yysymprint Args;				\
-} while (0)
-
-# define YYDSYMPRINTF(Title, Token, Value, Location)		\
+# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
 do {								\
   if (yydebug)							\
     {								\
       YYFPRINTF (stderr, "%s ", Title);				\
       yysymprint (stderr, 					\
-                  Token, Value, Location);	\
+                  Type, Value, Location);	\
       YYFPRINTF (stderr, "\n");					\
     }								\
 } while (0)
@@ -837,8 +864,7 @@ do {					\
 int yydebug;
 #else /* !YYDEBUG */
 # define YYDPRINTF(Args)
-# define YYDSYMPRINT(Args)
-# define YYDSYMPRINTF(Title, Token, Value, Location)
+# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 # define YY_STACK_PRINT(Bottom, Top)
 # define YY_REDUCE_PRINT(Rule)
 #endif /* !YYDEBUG */
@@ -943,15 +969,17 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
   (void) yylocationp;
 
   if (yytype < YYNTOKENS)
-    {
-      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
-# ifdef YYPRINT
-      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
-# endif
-    }
+    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
   else
     YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);
 
+  YY_LOCATION_PRINT (yyoutput, *yylocationp);
+  fprintf (yyoutput, ": ");
+
+# ifdef YYPRINT
+  if (yytype < YYNTOKENS)
+    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
+# endif
   switch (yytype)
     {
       default:
@@ -967,10 +995,11 @@ yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
 
 #if defined (__STDC__) || defined (__cplusplus)
 static void
-yydestruct (int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
+yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
 #else
 static void
-yydestruct (yytype, yyvaluep, yylocationp)
+yydestruct (yymsg, yytype, yyvaluep, yylocationp)
+    const char *yymsg;
     int yytype;
     YYSTYPE *yyvaluep;
     YYLTYPE *yylocationp;
@@ -980,6 +1009,10 @@ yydestruct (yytype, yyvaluep, yylocationp)
   (void) yyvaluep;
   (void) yylocationp;
 
+  if (!yymsg)
+    yymsg = "Deleting";
+  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);
+
   switch (yytype)
     {
 
@@ -1073,7 +1106,8 @@ YYLTYPE yylloc;
   YYLTYPE yylsa[YYINITDEPTH];
   YYLTYPE *yyls = yylsa;
   YYLTYPE *yylsp;
-  YYLTYPE *yylerrsp;
+  /* The locations where the error started and ended. */
+  YYLTYPE yyerror_range[2];
 
 #define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
 
@@ -1103,18 +1137,27 @@ YYLTYPE yylloc;
   yyssp = yyss;
   yyvsp = yyvs;
   yylsp = yyls;
+#if YYLTYPE_IS_TRIVIAL
+  /* Initialize the default location before parsing starts.  */
+  yylloc.first_line   = yylloc.last_line   = 1;
+  yylloc.first_column = yylloc.last_column = 0;
+#endif
+
 
   /* User initialization code. */
-  #line 68 "parse-gram.y"
+  #line 71 "../../src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
-  (*yylsp).start.file   = (*yylsp).end.file   = current_file;
-  (*yylsp).start.line   = (*yylsp).end.line   = 1;
-  (*yylsp).start.column = (*yylsp).end.column = 0;
+  yylloc.start.file   = yylloc.end.file   = current_file;
+  yylloc.start.line   = yylloc.end.line   = 1;
+  yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 818 of yacc.c.  */
-#line 1118 "parse-gram.c"
+/* Line 848 of yacc.c.  */
+#line 1158 "../../src/parse-gram.c"
+  yyvsp[0] = yylval;
+    yylsp[0] = yylloc;
+
   goto yysetstate;
 
 /*------------------------------------------------------------.
@@ -1230,7 +1273,7 @@ yybackup:
   else
     {
       yytoken = YYTRANSLATE (yychar);
-      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
+      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
     }
 
   /* If the proper action on seeing token YYTOKEN is to reduce or to
@@ -1251,7 +1294,7 @@ yybackup:
     YYACCEPT;
 
   /* Shift the look-ahead token.  */
-  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));
+  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 
   /* Discard the token being shifted unless it is eof.  */
   if (yychar != YYEOF)
@@ -1302,47 +1345,47 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 186 "parse-gram.y"
+#line 189 "../../src/parse-gram.y"
     { prologue_augment (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 7:
-#line 187 "parse-gram.y"
+#line 190 "../../src/parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 188 "parse-gram.y"
+#line 191 "../../src/parse-gram.y"
     { muscle_insert (yyvsp[-1].chars, yyvsp[0].chars); }
     break;
 
   case 9:
-#line 189 "parse-gram.y"
+#line 192 "../../src/parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-#line 190 "parse-gram.y"
+#line 193 "../../src/parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 11:
-#line 191 "parse-gram.y"
+#line 194 "../../src/parse-gram.y"
     { expected_sr_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 192 "parse-gram.y"
+#line 195 "../../src/parse-gram.y"
     { expected_rr_conflicts = yyvsp[0].integer; }
     break;
 
   case 13:
-#line 193 "parse-gram.y"
+#line 196 "../../src/parse-gram.y"
     { spec_file_prefix = yyvsp[0].chars; }
     break;
 
   case 14:
-#line 195 "parse-gram.y"
+#line 198 "../../src/parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
@@ -1350,81 +1393,81 @@ yyreduce:
     break;
 
   case 15:
-#line 200 "parse-gram.y"
+#line 203 "../../src/parse-gram.y"
     {
     muscle_code_grow ("initial_action", yyvsp[0].chars, yylsp[0]);
   }
     break;
 
   case 16:
-#line 203 "parse-gram.y"
+#line 206 "../../src/parse-gram.y"
     { add_param ("lex_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 17:
-#line 204 "parse-gram.y"
+#line 207 "../../src/parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 18:
-#line 205 "parse-gram.y"
+#line 208 "../../src/parse-gram.y"
     { spec_name_prefix = yyvsp[0].chars; }
     break;
 
   case 19:
-#line 206 "parse-gram.y"
+#line 209 "../../src/parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 20:
-#line 207 "parse-gram.y"
+#line 210 "../../src/parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 21:
-#line 208 "parse-gram.y"
+#line 211 "../../src/parse-gram.y"
     { spec_outfile = yyvsp[0].chars; }
     break;
 
   case 22:
-#line 209 "parse-gram.y"
+#line 212 "../../src/parse-gram.y"
     { add_param ("parse_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 23:
-#line 210 "parse-gram.y"
+#line 213 "../../src/parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 24:
-#line 211 "parse-gram.y"
+#line 214 "../../src/parse-gram.y"
     { skeleton = yyvsp[0].chars; }
     break;
 
   case 25:
-#line 212 "parse-gram.y"
+#line 215 "../../src/parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 26:
-#line 213 "parse-gram.y"
+#line 216 "../../src/parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 27:
-#line 214 "parse-gram.y"
+#line 217 "../../src/parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 31:
-#line 222 "parse-gram.y"
+#line 225 "../../src/parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 32:
-#line 226 "parse-gram.y"
+#line 229 "../../src/parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].start.line);
@@ -1433,7 +1476,7 @@ yyreduce:
     break;
 
   case 33:
-#line 232 "parse-gram.y"
+#line 235 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1443,7 +1486,7 @@ yyreduce:
     break;
 
   case 34:
-#line 239 "parse-gram.y"
+#line 242 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1453,26 +1496,26 @@ yyreduce:
     break;
 
   case 35:
-#line 246 "parse-gram.y"
+#line 249 "../../src/parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 36:
-#line 250 "parse-gram.y"
+#line 253 "../../src/parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 37:
-#line 256 "parse-gram.y"
+#line 259 "../../src/parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 38:
-#line 257 "parse-gram.y"
+#line 260 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1480,12 +1523,12 @@ yyreduce:
     break;
 
   case 39:
-#line 261 "parse-gram.y"
+#line 264 "../../src/parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 40:
-#line 262 "parse-gram.y"
+#line 265 "../../src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1493,7 +1536,7 @@ yyreduce:
     break;
 
   case 41:
-#line 267 "parse-gram.y"
+#line 270 "../../src/parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1503,7 +1546,7 @@ yyreduce:
     break;
 
   case 42:
-#line 277 "parse-gram.y"
+#line 280 "../../src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1518,49 +1561,49 @@ yyreduce:
     break;
 
   case 43:
-#line 291 "parse-gram.y"
+#line 294 "../../src/parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
   case 44:
-#line 292 "parse-gram.y"
+#line 295 "../../src/parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
   case 45:
-#line 293 "parse-gram.y"
+#line 296 "../../src/parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
   case 46:
-#line 297 "parse-gram.y"
+#line 300 "../../src/parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 47:
-#line 298 "parse-gram.y"
+#line 301 "../../src/parse-gram.y"
     { current_type = yyvsp[0].uniqstr; }
     break;
 
   case 48:
-#line 304 "parse-gram.y"
+#line 307 "../../src/parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 49:
-#line 305 "parse-gram.y"
+#line 308 "../../src/parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 50:
-#line 311 "parse-gram.y"
+#line 314 "../../src/parse-gram.y"
     {
        current_type = yyvsp[0].uniqstr;
      }
     break;
 
   case 51:
-#line 315 "parse-gram.y"
+#line 318 "../../src/parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
@@ -1568,7 +1611,7 @@ yyreduce:
     break;
 
   case 52:
-#line 320 "parse-gram.y"
+#line 323 "../../src/parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1577,7 +1620,7 @@ yyreduce:
     break;
 
   case 53:
-#line 326 "parse-gram.y"
+#line 329 "../../src/parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1586,7 +1629,7 @@ yyreduce:
     break;
 
   case 54:
-#line 332 "parse-gram.y"
+#line 335 "../../src/parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1596,7 +1639,7 @@ yyreduce:
     break;
 
   case 60:
-#line 361 "parse-gram.y"
+#line 364 "../../src/parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
@@ -1604,74 +1647,74 @@ yyreduce:
     break;
 
   case 61:
-#line 366 "parse-gram.y"
+#line 369 "../../src/parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 62:
-#line 372 "parse-gram.y"
+#line 375 "../../src/parse-gram.y"
     { current_lhs = yyvsp[0].symbol; current_lhs_location = yylsp[0]; }
     break;
 
   case 64:
-#line 376 "parse-gram.y"
+#line 379 "../../src/parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 65:
-#line 377 "parse-gram.y"
+#line 380 "../../src/parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 67:
-#line 383 "parse-gram.y"
+#line 386 "../../src/parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 68:
-#line 385 "parse-gram.y"
+#line 388 "../../src/parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 69:
-#line 387 "parse-gram.y"
+#line 390 "../../src/parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 70:
-#line 389 "parse-gram.y"
+#line 392 "../../src/parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 71:
-#line 391 "parse-gram.y"
+#line 394 "../../src/parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
   case 72:
-#line 393 "parse-gram.y"
+#line 396 "../../src/parse-gram.y"
     { grammar_current_rule_merge_set (yyvsp[0].uniqstr, yylsp[0]); }
     break;
 
   case 73:
-#line 397 "parse-gram.y"
+#line 400 "../../src/parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 74:
-#line 398 "parse-gram.y"
+#line 401 "../../src/parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 75:
-#line 403 "parse-gram.y"
+#line 406 "../../src/parse-gram.y"
     { yyval.chars = yyvsp[0].chars; }
     break;
 
   case 76:
-#line 409 "parse-gram.y"
+#line 412 "../../src/parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].chars, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
@@ -1679,7 +1722,7 @@ yyreduce:
     break;
 
   case 77:
-#line 418 "parse-gram.y"
+#line 421 "../../src/parse-gram.y"
     {
       yyval.chars = yyvsp[0].chars + 1;
       yyval.chars[strlen (yyval.chars) - 1] = '\0';
@@ -1687,7 +1730,7 @@ yyreduce:
     break;
 
   case 79:
-#line 427 "parse-gram.y"
+#line 430 "../../src/parse-gram.y"
     {
       muscle_code_grow ("epilogue", yyvsp[0].chars, yylsp[0]);
       scanner_last_string_free ();
@@ -1697,8 +1740,8 @@ yyreduce:
 
     }
 
-/* Line 1010 of yacc.c.  */
-#line 1702 "parse-gram.c"
+/* Line 1043 of yacc.c.  */
+#line 1745 "../../src/parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1794,7 +1837,7 @@ yyerrlab:
 	yyerror ("syntax error");
     }
 
-  yylerrsp = yylsp;
+  yyerror_range[0] = yylloc;
 
   if (yyerrstatus == 3)
     {
@@ -1808,19 +1851,18 @@ yyerrlab:
 	  if (yychar == YYEOF)
 	     for (;;)
 	       {
+                 yyerror_range[0] = *yylsp;
 		 YYPOPSTACK;
 		 if (yyssp == yyss)
 		   YYABORT;
-		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
-		 yydestruct (yystos[*yyssp], yyvsp, yylsp);
+		 yydestruct ("Error: popping",
+                             yystos[*yyssp], yyvsp, yylsp);
 	       }
         }
       else
 	{
-	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
-	  yydestruct (yytoken, &yylval, &yylloc);
+	  yydestruct ("Error: discarding", yytoken, &yylval, &yylloc);
 	  yychar = YYEMPTY;
-	  *++yylerrsp = yylloc;
 	}
     }
 
@@ -1841,12 +1883,11 @@ yyerrorlab:
      goto yyerrorlab;
 #endif
 
+  yyerror_range[0] = yylsp[1-yylen];
+  yylsp -= yylen;
   yyvsp -= yylen;
   yyssp -= yylen;
   yystate = *yyssp;
-  yylerrsp = yylsp;
-  *++yylerrsp = yyloc;
-  yylsp -= yylen;
   goto yyerrlab1;
 
 
@@ -1874,8 +1915,8 @@ yyerrlab1:
       if (yyssp == yyss)
 	YYABORT;
 
-      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
-      yydestruct (yystos[yystate], yyvsp, yylsp);
+      yyerror_range[0] = *yylsp;
+      yydestruct ("Error: popping", yystos[yystate], yyvsp, yylsp);
       YYPOPSTACK;
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
@@ -1884,12 +1925,17 @@ yyerrlab1:
   if (yyn == YYFINAL)
     YYACCEPT;
 
-  YYDPRINTF ((stderr, "Shifting error token, "));
-
   *++yyvsp = yylval;
-  YYLLOC_DEFAULT (yyloc, yylsp, yylerrsp - yylsp);
+
+  yyerror_range[1] = yylloc;
+  /* Using YYLLOC is tempting, but would change the location of
+     the look-ahead.  YYLOC is available though. */
+  YYLLOC_DEFAULT (yyloc, yyerror_range - 1, 2);
   *++yylsp = yyloc;
 
+  /* Shift the error token. */
+  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);
+
   yystate = yyn;
   goto yynewstate;
 
@@ -1905,6 +1951,9 @@ yyacceptlab:
 | yyabortlab -- YYABORT comes here.  |
 `-----------------------------------*/
 yyabortlab:
+  yydestruct ("Error: discarding lookahead",
+              yytoken, &yylval, &yylloc);
+  yychar = YYEMPTY;
   yyresult = 1;
   goto yyreturn;
 
@@ -1927,7 +1976,7 @@ yyreturn:
 }
 
 
-#line 433 "parse-gram.y"
+#line 436 "../../src/parse-gram.y"
 
 
 
@@ -1967,22 +2016,27 @@ lloc_default (YYLTYPE const *rhs, int n)
 static void
 add_param (char const *type, char *decl, location loc)
 {
-  static char const alphanum[] =
-    "0123456789"
+  static char const alphanum[26 + 26 + 1 + 10] =
     "abcdefghijklmnopqrstuvwxyz"
     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
-    "_";
-  char const *alpha = alphanum + 10;
+    "_"
+    "0123456789";
   char const *name_start = NULL;
   char *p;
 
   for (p = decl; *p; p++)
-    if ((p == decl || ! strchr (alphanum, p[-1])) && strchr (alpha, p[0]))
+    if ((p == decl
+	 || ! memchr (alphanum, p[-1], sizeof alphanum))
+	&& memchr (alphanum, p[0], sizeof alphanum - 10))
       name_start = p;
 
-  /* Strip the surrounding '{' and '}'.  */
-  decl++;
-  p[-1] = '\0';
+  /* Strip the surrounding '{' and '}', and any blanks just inside
+     the braces.  */
+  while (*--p == ' ' || *p == '\t')
+    continue;
+  *p = '\0';
+  while (*++decl == ' ' || *decl == '\t')
+    continue;
 
   if (! name_start)
     complain_at (loc, _("missing identifier in parameter declaration"));
@@ -1992,7 +2046,7 @@ add_param (char const *type, char *decl, location loc)
       size_t name_len;
 
       for (name_len = 1;
-	   name_start[name_len] && strchr (alphanum, name_start[name_len]);
+	   memchr (alphanum, name_start[name_len], sizeof alphanum);
 	   name_len++)
 	continue;
 
