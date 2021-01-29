@@ -169,7 +169,7 @@
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
-   Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -198,6 +198,7 @@
 #include "gram.h"
 #include "muscle_tab.h"
 #include "output.h"
+#include "quotearg.h"
 #include "reader.h"
 #include "symlist.h"
 
@@ -242,7 +243,7 @@ int current_prec = 0;
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 81 "parse-gram.y"
+#line 82 "parse-gram.y"
 typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
@@ -252,7 +253,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 191 of yacc.c.  */
-#line 256 "parse-gram.c"
+#line 257 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -276,7 +277,7 @@ typedef struct YYLTYPE
 
 
 /* Line 214 of yacc.c.  */
-#line 280 "parse-gram.c"
+#line 281 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -302,13 +303,21 @@ typedef struct YYLTYPE
 # ifdef YYSTACK_ALLOC
    /* Pacify GCC's `empty if-body' warning. */
 #  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
+#  ifndef YYSTACK_ALLOC_MAXIMUM
+#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
+#  endif
 # else
 #  if defined (__STDC__) || defined (__cplusplus)
 #   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
 #   define YYSIZE_T size_t
+#  else
+#   define YYSIZE_T unsigned long int
 #  endif
 #  define YYSTACK_ALLOC YYMALLOC
 #  define YYSTACK_FREE YYFREE
+#  ifndef YYSTACK_ALLOC_MAXIMUM
+#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
+#  endif
 # endif
 #endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */
 
@@ -478,14 +487,14 @@ static const yysigned_char yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short int yyrline[] =
 {
-       0,   174,   174,   182,   184,   188,   189,   190,   191,   192,
-     193,   194,   195,   196,   197,   202,   206,   207,   208,   209,
-     210,   211,   212,   213,   214,   215,   216,   217,   218,   222,
-     223,   224,   228,   234,   241,   248,   252,   259,   259,   264,
-     264,   269,   279,   294,   295,   296,   300,   301,   307,   308,
-     313,   317,   322,   328,   334,   345,   346,   355,   356,   362,
-     363,   368,   375,   375,   379,   380,   381,   386,   387,   389,
-     391,   393,   395,   400,   401,   405,   411,   420,   427,   429
+       0,   175,   175,   183,   185,   189,   190,   191,   192,   193,
+     194,   195,   196,   197,   198,   203,   207,   208,   209,   210,
+     211,   212,   213,   214,   215,   216,   217,   218,   219,   223,
+     224,   225,   229,   235,   242,   249,   253,   260,   260,   265,
+     265,   270,   280,   295,   296,   297,   301,   302,   308,   309,
+     314,   318,   323,   329,   335,   346,   347,   356,   357,   363,
+     364,   369,   376,   376,   380,   381,   382,   387,   388,   390,
+     392,   394,   396,   401,   402,   406,   412,   421,   426,   428
 };
 #endif
 
@@ -882,7 +891,7 @@ int yydebug;
    if the built-in stack extension method is used).
 
    Do not make this value too large; the results are undefined if
-   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
+   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
    evaluated with infinite-precision integer arithmetic.  */
 
 #ifndef YYMAXDEPTH
@@ -1144,7 +1153,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code. */
-#line 71 "parse-gram.y"
+#line 72 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1152,8 +1161,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 848 of yacc.c.  */
-#line 1157 "parse-gram.c"
+/* Line 856 of yacc.c.  */
+#line 1166 "parse-gram.c"
   yyvsp[0] = yylval;
     yylsp[0] = yylloc;
 
@@ -1344,47 +1353,47 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 189 "parse-gram.y"
+#line 190 "parse-gram.y"
     { prologue_augment ((yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 7:
-#line 190 "parse-gram.y"
+#line 191 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 191 "parse-gram.y"
+#line 192 "parse-gram.y"
     { muscle_insert ((yyvsp[-1].chars), (yyvsp[0].chars)); }
     break;
 
   case 9:
-#line 192 "parse-gram.y"
+#line 193 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-#line 193 "parse-gram.y"
+#line 194 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 11:
-#line 194 "parse-gram.y"
+#line 195 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
     break;
 
   case 12:
-#line 195 "parse-gram.y"
+#line 196 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
     break;
 
   case 13:
-#line 196 "parse-gram.y"
+#line 197 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
     break;
 
   case 14:
-#line 198 "parse-gram.y"
+#line 199 "parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
@@ -1392,81 +1401,81 @@ yyreduce:
     break;
 
   case 15:
-#line 203 "parse-gram.y"
+#line 204 "parse-gram.y"
     {
     muscle_code_grow ("initial_action", (yyvsp[0].chars), (yylsp[0]));
   }
     break;
 
   case 16:
-#line 206 "parse-gram.y"
+#line 207 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 17:
-#line 207 "parse-gram.y"
+#line 208 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 18:
-#line 208 "parse-gram.y"
+#line 209 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
     break;
 
   case 19:
-#line 209 "parse-gram.y"
+#line 210 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 20:
-#line 210 "parse-gram.y"
+#line 211 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 21:
-#line 211 "parse-gram.y"
+#line 212 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
     break;
 
   case 22:
-#line 212 "parse-gram.y"
+#line 213 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 23:
-#line 213 "parse-gram.y"
+#line 214 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 24:
-#line 214 "parse-gram.y"
+#line 215 "parse-gram.y"
     { skeleton = (yyvsp[0].chars); }
     break;
 
   case 25:
-#line 215 "parse-gram.y"
+#line 216 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 26:
-#line 216 "parse-gram.y"
+#line 217 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 27:
-#line 217 "parse-gram.y"
+#line 218 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 31:
-#line 225 "parse-gram.y"
+#line 226 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
     break;
 
   case 32:
-#line 229 "parse-gram.y"
+#line 230 "parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", (yylsp[0]).start.line);
@@ -1475,7 +1484,7 @@ yyreduce:
     break;
 
   case 33:
-#line 235 "parse-gram.y"
+#line 236 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1485,7 +1494,7 @@ yyreduce:
     break;
 
   case 34:
-#line 242 "parse-gram.y"
+#line 243 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1495,26 +1504,26 @@ yyreduce:
     break;
 
   case 35:
-#line 249 "parse-gram.y"
+#line 250 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 36:
-#line 253 "parse-gram.y"
+#line 254 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 37:
-#line 259 "parse-gram.y"
+#line 260 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 38:
-#line 260 "parse-gram.y"
+#line 261 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1522,12 +1531,12 @@ yyreduce:
     break;
 
   case 39:
-#line 264 "parse-gram.y"
+#line 265 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 40:
-#line 265 "parse-gram.y"
+#line 266 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1535,7 +1544,7 @@ yyreduce:
     break;
 
   case 41:
-#line 270 "parse-gram.y"
+#line 271 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -1545,7 +1554,7 @@ yyreduce:
     break;
 
   case 42:
-#line 280 "parse-gram.y"
+#line 281 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1560,49 +1569,49 @@ yyreduce:
     break;
 
   case 43:
-#line 294 "parse-gram.y"
+#line 295 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 44:
-#line 295 "parse-gram.y"
+#line 296 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 45:
-#line 296 "parse-gram.y"
+#line 297 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 46:
-#line 300 "parse-gram.y"
+#line 301 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 47:
-#line 301 "parse-gram.y"
+#line 302 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); }
     break;
 
   case 48:
-#line 307 "parse-gram.y"
+#line 308 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 49:
-#line 308 "parse-gram.y"
+#line 309 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 50:
-#line 314 "parse-gram.y"
+#line 315 "parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
      }
     break;
 
   case 51:
-#line 318 "parse-gram.y"
+#line 319 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]));
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
@@ -1610,7 +1619,7 @@ yyreduce:
     break;
 
   case 52:
-#line 323 "parse-gram.y"
+#line 324 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]));
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
@@ -1619,7 +1628,7 @@ yyreduce:
     break;
 
   case 53:
-#line 329 "parse-gram.y"
+#line 330 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]));
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
@@ -1628,7 +1637,7 @@ yyreduce:
     break;
 
   case 54:
-#line 335 "parse-gram.y"
+#line 336 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]));
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -1638,7 +1647,7 @@ yyreduce:
     break;
 
   case 60:
-#line 364 "parse-gram.y"
+#line 365 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at ((yyloc), _("POSIX forbids declarations in the grammar"));
@@ -1646,90 +1655,87 @@ yyreduce:
     break;
 
   case 61:
-#line 369 "parse-gram.y"
+#line 370 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 62:
-#line 375 "parse-gram.y"
+#line 376 "parse-gram.y"
     { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
     break;
 
   case 64:
-#line 379 "parse-gram.y"
+#line 380 "parse-gram.y"
     { grammar_rule_end ((yylsp[0])); }
     break;
 
   case 65:
-#line 380 "parse-gram.y"
+#line 381 "parse-gram.y"
     { grammar_rule_end ((yylsp[0])); }
     break;
 
   case 67:
-#line 386 "parse-gram.y"
+#line 387 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 68:
-#line 388 "parse-gram.y"
+#line 389 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 69:
-#line 390 "parse-gram.y"
+#line 391 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 70:
-#line 392 "parse-gram.y"
+#line 393 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 71:
-#line 394 "parse-gram.y"
+#line 395 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
     break;
 
   case 72:
-#line 396 "parse-gram.y"
+#line 397 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
     break;
 
   case 73:
-#line 400 "parse-gram.y"
+#line 401 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
     break;
 
   case 74:
-#line 401 "parse-gram.y"
+#line 402 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
     break;
 
   case 75:
-#line 406 "parse-gram.y"
+#line 407 "parse-gram.y"
     { (yyval.chars) = (yyvsp[0].chars); }
     break;
 
   case 76:
-#line 412 "parse-gram.y"
+#line 413 "parse-gram.y"
     {
-      (yyval.symbol) = symbol_get ((yyvsp[0].chars), (yylsp[0]));
+      (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]));
     }
     break;
 
   case 77:
-#line 421 "parse-gram.y"
-    {
-      (yyval.chars) = (yyvsp[0].chars) + 1;
-      (yyval.chars)[strlen ((yyval.chars)) - 1] = '\0';
-    }
+#line 422 "parse-gram.y"
+    { (yyval.chars) = (yyvsp[0].chars); }
     break;
 
   case 79:
-#line 430 "parse-gram.y"
+#line 429 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", (yyvsp[0].chars), (yylsp[0]));
       scanner_last_string_free ();
@@ -1740,8 +1746,8 @@ yyreduce:
       default: break;
     }
 
-/* Line 1044 of yacc.c.  */
-#line 1745 "parse-gram.c"
+/* Line 1052 of yacc.c.  */
+#line 1751 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1780,12 +1786,36 @@ yyerrlab:
 
       if (YYPACT_NINF < yyn && yyn < YYLAST)
 	{
-	  YYSIZE_T yysize = 0;
 	  int yytype = YYTRANSLATE (yychar);
-	  const char* yyprefix;
-	  char *yymsg;
+	  YYSIZE_T yysize0 = yystrlen (yytname[yytype]);
+	  YYSIZE_T yysize = yysize0;
+	  YYSIZE_T yysize1;
+	  int yysize_overflow = 0;
+	  char *yymsg = 0;
+#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
+	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
 	  int yyx;
 
+#if 0
+	  /* This is so xgettext sees the translatable formats that are
+	     constructed on the fly.  */
+	  _("syntax error, unexpected %s");
+	  _("syntax error, unexpected %s, expecting %s");
+	  _("syntax error, unexpected %s, expecting %s or %s");
+	  _("syntax error, unexpected %s, expecting %s or %s or %s");
+	  _("syntax error, unexpected %s, expecting %s or %s or %s or %s");
+#endif
+	  char *yyfmt;
+	  char const *yyf;
+	  static char const yyunexpected[] = "syntax error, unexpected %s";
+	  static char const yyexpecting[] = ", expecting %s";
+	  static char const yyor[] = " or %s";
+	  char yyformat[sizeof yyunexpected
+			+ sizeof yyexpecting - 1
+			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
+			   * (sizeof yyor - 1))];
+	  char const *yyprefix = yyexpecting;
+
 	  /* Start YYX at -YYN if negative to avoid negative indexes in
 	     YYCHECK.  */
 	  int yyxbegin = yyn < 0 ? -yyn : 0;
@@ -1793,44 +1823,61 @@ yyerrlab:
 	  /* Stay within bounds of both yycheck and yytname.  */
 	  int yychecklim = YYLAST - yyn;
 	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-	  int yycount = 0;
+	  int yycount = 1;
+
+	  yyarg[0] = yytname[yytype];
+	  yyfmt = yystpcpy (yyformat, yyunexpected);
 
-	  yyprefix = _(", expecting ");
 	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 	      {
-		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
-		yycount += 1;
-		if (yycount == 5)
+		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
 		  {
-		    yysize = 0;
+		    yycount = 1;
+		    yysize = yysize0;
+		    yyformat[sizeof yyunexpected - 1] = '\0';
 		    break;
 		  }
+		yyarg[yycount++] = yytname[yyx];
+		yysize1 = yysize + yystrlen (yytname[yyx]);
+		yysize_overflow |= yysize1 < yysize;
+		yysize = yysize1;
+		yyfmt = yystpcpy (yyfmt, yyprefix);
+		yyprefix = yyor;
 	      }
-	  yysize += (strlen (_("syntax error, unexpected "))
-		     + yystrlen (yytname[yytype]) + 1);
-	  yymsg = (char *) YYSTACK_ALLOC (yysize);
-	  if (yymsg != 0)
-	    {
-	      char *yyp = yystpcpy (yymsg, _("syntax error, unexpected "));
-	      yyp = yystpcpy (yyp, yytname[yytype]);
 
-	      if (yycount < 5)
+	  yyf = _(yyformat);
+	  yysize1 = yysize + strlen (yyf);
+	  yysize_overflow |= yysize1 < yysize;
+	  yysize = yysize1;
+
+	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
+	    yymsg = (char *) YYSTACK_ALLOC (yysize);
+	  if (yymsg)
+	    {
+	      /* Avoid sprintf, as that infringes on the user's name space.
+		 Don't have undefined behavior even if the translation
+		 produced a string with the wrong number of "%s"s.  */
+	      char *yyp = yymsg;
+	      int yyi = 0;
+	      while ((*yyp = *yyf))
 		{
-		  yyprefix = _(", expecting ");
-		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
-		      {
-			yyp = yystpcpy (yyp, yyprefix);
-			yyp = yystpcpy (yyp, yytname[yyx]);
-			yyprefix = _(" or ");
-		      }
+		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
+		    {
+		      yyp = yystpcpy (yyp, yyarg[yyi++]);
+		      yyf += 2;
+		    }
+		  else
+		    {
+		      yyp++;
+		      yyf++;
+		    }
 		}
 	      yyerror (yymsg);
 	      YYSTACK_FREE (yymsg);
 	    }
 	  else
-	    yyerror (_("syntax error; also virtual memory exhausted"));
+	    yyerror (_("syntax error; also memory exhausted"));
 	}
       else
 #endif /* YYERROR_VERBOSE */
@@ -1975,7 +2022,7 @@ yyreturn:
 }
 
 
-#line 436 "parse-gram.y"
+#line 435 "parse-gram.y"
 
 
 
