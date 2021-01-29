@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.1.137-628b-dirty.  */
+/* A Bison parser, made by GNU Bison 2.4.1.144-419e.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.137-628b-dirty"
+#define YYBISON_VERSION "2.4.1.144-419e"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1417,50 +1417,32 @@ yytnamerr (char *yyres, const char *yystr)
 }
 # endif
 
-/* Copy into YYRESULT an error message about the unexpected token
-   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
-   including the terminating null byte.  If YYRESULT is null, do not
-   copy anything; just return the number of bytes that would be
-   copied.  As a special case, return 0 if an ordinary "syntax error"
-   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
-   size calculation.  */
-static YYSIZE_T
-yysyntax_error (char *yyresult, int yystate, int yychar)
+/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
+   about the unexpected token YYTOKEN while in state YYSTATE.
+
+   Return 0 if *YYMSG was successfully written.  Return 1 if an ordinary
+   "syntax error" message will suffice instead.  Return 2 if *YYMSG is
+   not large enough to hold the message.  In the last case, also set
+   *YYMSG_ALLOC to either (a) the required number of bytes or (b) zero
+   if the required number of bytes is too large to store.  */
+static int
+yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
+                int yystate, int yytoken)
 {
   int yyn = yypact[yystate];
 
   if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
-    return 0;
+    return 1;
   else
     {
-      int yytype = YYTRANSLATE (yychar);
-      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
+      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
       YYSIZE_T yysize = yysize0;
       YYSIZE_T yysize1;
-      int yysize_overflow = 0;
       enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
+      /* Internationalized format string. */
+      const char *yyformat = 0;
+      /* Arguments of yyformat. */
       char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
-      int yyx;
-
-# if 0
-      /* This is so xgettext sees the translatable formats that are
-	 constructed on the fly.  */
-      YY_("syntax error, unexpected %s");
-      YY_("syntax error, unexpected %s, expecting %s");
-      YY_("syntax error, unexpected %s, expecting %s or %s");
-      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
-      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
-# endif
-      char *yyfmt;
-      char const *yyf;
-      static char const yyunexpected[] = "syntax error, unexpected %s";
-      static char const yyexpecting[] = ", expecting %s";
-      static char const yyor[] = " or %s";
-      char yyformat[sizeof yyunexpected
-		    + sizeof yyexpecting - 1
-		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
-		       * (sizeof yyor - 1))];
-      char const *yyprefix = yyexpecting;
 
       /* Start YYX at -YYN if negative to avoid negative indexes in
 	 YYCHECK.  In other words, skip the first -YYN actions for this
@@ -1470,10 +1452,12 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       /* Stay within bounds of both yycheck and yytname.  */
       int yychecklim = YYLAST - yyn + 1;
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-      int yycount = 1;
+      /* Number of reported tokens (one for the "unexpected", one per
+         "expected"). */
+      int yycount = 0;
+      int yyx;
 
-      yyarg[0] = yytname[yytype];
-      yyfmt = yystpcpy (yyformat, yyunexpected);
+      yyarg[yycount++] = yytname[yytoken];
 
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
@@ -1483,47 +1467,71 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 	      {
 		yycount = 1;
 		yysize = yysize0;
-		yyformat[sizeof yyunexpected - 1] = '\0';
 		break;
 	      }
 	    yyarg[yycount++] = yytname[yyx];
 	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
-	    yysize_overflow |= (yysize1 < yysize);
+	    if (! (yysize <= yysize1
+		   && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+	      {
+		/* Overflow.  */
+		*yymsg_alloc = 0;
+		return 2;
+	      }
 	    yysize = yysize1;
-	    yyfmt = yystpcpy (yyfmt, yyprefix);
-	    yyprefix = yyor;
 	  }
 
-      yyf = YY_(yyformat);
-      yysize1 = yysize + yystrlen (yyf);
-      yysize_overflow |= (yysize1 < yysize);
+      switch (yycount)
+        {
+#define YYCASE_(N, S)                           \
+          case N:                               \
+            yyformat = S;                       \
+          break
+          YYCASE_(1, YY_("syntax error, unexpected %s"));
+          YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
+          YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
+          YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
+          YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
+#undef YYCASE_
+        }
+
+      yysize1 = yysize + yystrlen (yyformat);
+      if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+        {
+          /* Overflow.  */
+          *yymsg_alloc = 0;
+          return 2;
+        }
       yysize = yysize1;
 
-      if (yysize_overflow)
-	return YYSIZE_MAXIMUM;
+      if (*yymsg_alloc < yysize)
+        {
+          *yymsg_alloc = 2 * yysize;
+          if (! (yysize <= *yymsg_alloc
+                 && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
+            *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
+          return 2;
+        }
 
-      if (yyresult)
-	{
-	  /* Avoid sprintf, as that infringes on the user's name space.
-	     Don't have undefined behavior even if the translation
-	     produced a string with the wrong number of "%s"s.  */
-	  char *yyp = yyresult;
-	  int yyi = 0;
-	  while ((*yyp = *yyf) != '\0')
-	    {
-	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
-		{
-		  yyp += yytnamerr (yyp, yyarg[yyi++]);
-		  yyf += 2;
-		}
-	      else
-		{
-		  yyp++;
-		  yyf++;
-		}
-	    }
-	}
-      return yysize;
+      /* Avoid sprintf, as that infringes on the user's name space.
+         Don't have undefined behavior even if the translation
+         produced a string with the wrong number of "%s"s.  */
+      {
+        char *yyp = *yymsg;
+        int yyi = 0;
+        while ((*yyp = *yyformat) != '\0')
+          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
+            {
+              yyp += yytnamerr (yyp, yyarg[yyi++]);
+              yyformat += 2;
+            }
+          else
+            {
+              yyp++;
+              yyformat++;
+            }
+      }
+      return 0;
     }
 }
 #endif /* YYERROR_VERBOSE */
@@ -1700,7 +1708,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1258 of yacc.c  */
+/* Line 1266 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1709,8 +1717,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1258 of yacc.c  */
-#line 1714 "parse-gram.c"
+/* Line 1266 of yacc.c  */
+#line 1722 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1897,7 +1905,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 223 "parse-gram.y"
     {
       code_props plain_code;
@@ -1912,14 +1920,14 @@ yyreduce:
 
   case 7:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 232 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 234 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -1929,14 +1937,14 @@ yyreduce:
 
   case 9:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 238 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 240 "parse-gram.y"
     {
       defines_flag = true;
@@ -1946,42 +1954,42 @@ yyreduce:
 
   case 11:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 244 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 245 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 246 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 247 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 248 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 250 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -1991,7 +1999,7 @@ yyreduce:
 
   case 17:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 255 "parse-gram.y"
     {
       code_props action;
@@ -2005,77 +2013,77 @@ yyreduce:
 
   case 18:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 263 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 264 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 265 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 266 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 267 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 268 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 269 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 270 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 271 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 272 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 274 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2095,14 +2103,14 @@ yyreduce:
 
   case 29:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 288 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 290 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2131,28 +2139,28 @@ yyreduce:
 
   case 31:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 313 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 314 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 315 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 323 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2161,7 +2169,7 @@ yyreduce:
 
   case 38:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 327 "parse-gram.y"
     {
       symbol_list *list;
@@ -2173,7 +2181,7 @@ yyreduce:
 
   case 39:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 334 "parse-gram.y"
     {
       symbol_list *list;
@@ -2185,7 +2193,7 @@ yyreduce:
 
   case 40:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 341 "parse-gram.y"
     {
       default_prec = true;
@@ -2194,7 +2202,7 @@ yyreduce:
 
   case 41:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 345 "parse-gram.y"
     {
       default_prec = false;
@@ -2203,7 +2211,7 @@ yyreduce:
 
   case 42:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 349 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2215,7 +2223,7 @@ yyreduce:
 
   case 43:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 356 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2225,21 +2233,21 @@ yyreduce:
 
   case 44:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 370 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 371 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 376 "parse-gram.y"
     {
       union_seen = true;
@@ -2250,14 +2258,14 @@ yyreduce:
 
   case 47:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 387 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 388 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2267,14 +2275,14 @@ yyreduce:
 
   case 49:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 392 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 393 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2284,7 +2292,7 @@ yyreduce:
 
   case 51:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 398 "parse-gram.y"
     {
       symbol_list *list;
@@ -2297,7 +2305,7 @@ yyreduce:
 
   case 52:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 409 "parse-gram.y"
     {
       symbol_list *list;
@@ -2314,126 +2322,126 @@ yyreduce:
 
   case 53:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 423 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 424 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 425 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 429 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 430 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 436 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 438 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 442 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 443 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 449 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 451 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 455 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 456 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 460 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 461 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 462 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 463 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 469 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2443,7 +2451,7 @@ yyreduce:
 
   case 71:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 474 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2453,7 +2461,7 @@ yyreduce:
 
   case 72:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 479 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2464,7 +2472,7 @@ yyreduce:
 
   case 73:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 485 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2475,7 +2483,7 @@ yyreduce:
 
   case 74:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 491 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2487,7 +2495,7 @@ yyreduce:
 
   case 81:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 521 "parse-gram.y"
     {
       yyerrok;
@@ -2496,7 +2504,7 @@ yyreduce:
 
   case 82:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 527 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (2)].symbol); current_lhs_location = (yylsp[(1) - (2)]);
     current_lhs_named_ref = (yyvsp[(2) - (2)].named_ref); }
@@ -2504,21 +2512,21 @@ yyreduce:
 
   case 84:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 532 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 533 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 539 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
@@ -2526,77 +2534,77 @@ yyreduce:
 
   case 88:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 542 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 544 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 546 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 548 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 550 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 554 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 556 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 568 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 573 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 574 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 585 "parse-gram.y"
     {
       code_props plain_code;
@@ -2610,14 +2618,14 @@ yyreduce:
 
   case 101:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 605 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 607 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2628,14 +2636,14 @@ yyreduce:
 
   case 103:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 615 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 627 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2645,7 +2653,7 @@ yyreduce:
 
   case 108:
 
-/* Line 1471 of yacc.c  */
+/* Line 1479 of yacc.c  */
 #line 636 "parse-gram.y"
     {
       code_props plain_code;
@@ -2659,8 +2667,8 @@ yyreduce:
 
 
 
-/* Line 1471 of yacc.c  */
-#line 2664 "parse-gram.c"
+/* Line 1479 of yacc.c  */
+#line 2672 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2698,37 +2706,28 @@ yyerrlab:
 #if ! YYERROR_VERBOSE
       yyerror (YY_("syntax error"));
 #else
-      {
-	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
-	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
-	  {
-	    YYSIZE_T yyalloc = 2 * yysize;
-	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
-	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
-	    if (yymsg != yymsgbuf)
-	      YYSTACK_FREE (yymsg);
-	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
-	    if (yymsg)
-	      yymsg_alloc = yyalloc;
-	    else
-	      {
-		yymsg = yymsgbuf;
-		yymsg_alloc = sizeof yymsgbuf;
-	      }
-	  }
-
-	if (0 < yysize && yysize <= yymsg_alloc)
-	  {
-	    (void) yysyntax_error (yymsg, yystate, yychar);
-	    yyerror (yymsg);
-	  }
-	else
-	  {
-	    yyerror (YY_("syntax error"));
-	    if (yysize != 0)
-	      goto yyexhaustedlab;
-	  }
-      }
+      while (1)
+        {
+          int yysyntax_error_status =
+            yysyntax_error (&yymsg_alloc, &yymsg, yystate, yytoken);
+          if (yysyntax_error_status == 2 && 0 < yymsg_alloc)
+            {
+              if (yymsg != yymsgbuf)
+                YYSTACK_FREE (yymsg);
+              yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
+              if (yymsg)
+                continue;
+              yymsg = yymsgbuf;
+              yymsg_alloc = sizeof yymsgbuf;
+            }
+          if (yysyntax_error_status == 0)
+            yyerror (yymsg);
+          else
+            yyerror (YY_("syntax error"));
+          if (yysyntax_error_status == 2)
+            goto yyexhaustedlab;
+          break;
+        }
 #endif
     }
 
@@ -2878,7 +2877,7 @@ yyreturn:
 
 
 
-/* Line 1691 of yacc.c  */
+/* Line 1690 of yacc.c  */
 #line 646 "parse-gram.y"
 
 
