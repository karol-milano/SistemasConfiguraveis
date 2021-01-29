@@ -1446,20 +1446,13 @@ yytnamerr (char *yyres, const char *yystr)
 /* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
    about the unexpected token YYTOKEN while in state YYSTATE.
 
-   Return 0 if *YYMSG was successfully written.  Return 1 if an ordinary
-   "syntax error" message will suffice instead.  Return 2 if *YYMSG is
-   not large enough to hold the message.  In the last case, also set
-   *YYMSG_ALLOC to either (a) the required number of bytes or (b) zero
-   if the required number of bytes is too large to store.  */
+   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
+   not large enough to hold the message.  In that case, also set
+   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
+   required number of bytes is too large to store.  */
 static int
 yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                 int yystate, int yytoken)
-{
-  int yyn = yypact[yystate];
-
-  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
-    return 1;
-  else
 {
   YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
@@ -1469,22 +1462,51 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
   const char *yyformat = 0;
   /* Arguments of yyformat. */
   char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
+  /* Number of reported tokens (one for the "unexpected", one per
+     "expected"). */
+  int yycount = 0;
 
+  /* There are many possibilities here to consider:
+     - Assume YYFAIL is not used.  It's too flawed to consider.  See
+       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
+       for details.  YYERROR is fine as it does not invoke this
+       function.
+     - If this state is a consistent state with a default action, then
+       the only way this function was invoked is if the default action
+       is an error action.  In that case, don't check for expected
+       tokens because there are none.
+     - The only way there can be no lookahead present (in yychar) is if
+       this state is a consistent state with a default action.  Thus,
+       detecting the absence of a lookahead is sufficient to determine
+       that there is no unexpected or expected token to report.  In that
+       case, just report a simple "syntax error".
+     - Don't assume there isn't a lookahead just because this state is a
+       consistent state with a default action.  There might have been a
+       previous inconsistent state, consistent state with a non-default
+       action, or user semantic action that manipulated yychar.
+     - Of course, the expected token list depends on states to have
+       correct lookahead information, and it depends on the parser not
+       to perform extra reductions after fetching a lookahead from the
+       scanner and before detecting a syntax error.  Thus, state merging
+       (from LALR or IELR) and default reductions corrupt the expected
+       token list.  However, the list is correct for canonical LR with
+       one exception: it will still contain any token that will not be
+       accepted due to an error action in a later state.
+  */
+  if (yytoken != YYEMPTY)
+    {
+      int yyn = yypact[yystate];
+      yyarg[yycount++] = yytname[yytoken];
+      if (!yypact_value_is_default (yyn))
+        {
           /* Start YYX at -YYN if negative to avoid negative indexes in
              YYCHECK.  In other words, skip the first -YYN actions for
              this state because they are default actions.  */
           int yyxbegin = yyn < 0 ? -yyn : 0;
-
           /* Stay within bounds of both yycheck and yytname.  */
           int yychecklim = YYLAST - yyn + 1;
           int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-  /* Number of reported tokens (one for the "unexpected", one per
-     "expected"). */
-  int yycount = 0;
           int yyx;
-
-  yyarg[yycount++] = yytname[yytoken];
-
           for (yyx = yyxbegin; yyx < yyxend; ++yyx)
             if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                 && !yytable_value_is_error (yytable[yyx + yyn]))
@@ -1497,14 +1519,13 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                   }
                 yyarg[yycount++] = yytname[yyx];
                 yysize1 = yysize + yytnamerr (0, yytname[yyx]);
-                if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
-                  {
-                    /* Overflow.  */
-                    *yymsg_alloc = 0;
-                    return 2;
-                  }
+                if (! (yysize <= yysize1
+                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+                  return 2;
                 yysize = yysize1;
               }
+        }
+    }
 
   switch (yycount)
     {
@@ -1512,6 +1533,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
       case N:                               \
         yyformat = S;                       \
       break
+      YYCASE_(0, YY_("syntax error"));
       YYCASE_(1, YY_("syntax error, unexpected %s"));
       YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
       YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
@@ -1522,11 +1544,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 
   yysize1 = yysize + yystrlen (yyformat);
   if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
-    {
-      /* Overflow.  */
-      *yymsg_alloc = 0;
-      return 2;
-    }
+    return 2;
   yysize = yysize1;
 
   if (*yymsg_alloc < yysize)
@@ -1535,7 +1553,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
       if (! (yysize <= *yymsg_alloc
              && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
         *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
-      return 2;
+      return 1;
     }
 
   /* Avoid sprintf, as that infringes on the user's name space.
@@ -1558,7 +1576,6 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
   }
   return 0;
 }
-}
 #endif /* YYERROR_VERBOSE */
 
 
@@ -1733,7 +1750,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1279 of yacc.c  */
+/* Line 1296 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1742,8 +1759,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1279 of yacc.c  */
-#line 1747 "parse-gram.c"
+/* Line 1296 of yacc.c  */
+#line 1764 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1930,7 +1947,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 225 "parse-gram.y"
     {
       code_props plain_code;
@@ -1945,14 +1962,14 @@ yyreduce:
 
   case 7:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 234 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 236 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -1962,14 +1979,14 @@ yyreduce:
 
   case 9:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 240 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 242 "parse-gram.y"
     {
       defines_flag = true;
@@ -1979,42 +1996,42 @@ yyreduce:
 
   case 11:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 246 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 247 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 248 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 249 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 250 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 252 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -2024,7 +2041,7 @@ yyreduce:
 
   case 17:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 257 "parse-gram.y"
     {
       code_props action;
@@ -2038,77 +2055,77 @@ yyreduce:
 
   case 18:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 265 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 266 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 267 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 268 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 269 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 270 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 271 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 272 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 273 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 274 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 276 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2128,14 +2145,14 @@ yyreduce:
 
   case 29:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 290 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 292 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2164,28 +2181,28 @@ yyreduce:
 
   case 31:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 315 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 316 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 317 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 325 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2194,7 +2211,7 @@ yyreduce:
 
   case 38:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 329 "parse-gram.y"
     {
       symbol_list *list;
@@ -2206,7 +2223,7 @@ yyreduce:
 
   case 39:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 336 "parse-gram.y"
     {
       symbol_list *list;
@@ -2218,7 +2235,7 @@ yyreduce:
 
   case 40:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 343 "parse-gram.y"
     {
       default_prec = true;
@@ -2227,7 +2244,7 @@ yyreduce:
 
   case 41:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 347 "parse-gram.y"
     {
       default_prec = false;
@@ -2236,7 +2253,7 @@ yyreduce:
 
   case 42:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 351 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2248,7 +2265,7 @@ yyreduce:
 
   case 43:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 358 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2258,21 +2275,21 @@ yyreduce:
 
   case 44:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 372 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 373 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 378 "parse-gram.y"
     {
       union_seen = true;
@@ -2283,14 +2300,14 @@ yyreduce:
 
   case 47:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 389 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 390 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2300,14 +2317,14 @@ yyreduce:
 
   case 49:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 394 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 395 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2317,7 +2334,7 @@ yyreduce:
 
   case 51:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 400 "parse-gram.y"
     {
       symbol_list *list;
@@ -2330,7 +2347,7 @@ yyreduce:
 
   case 52:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 411 "parse-gram.y"
     {
       symbol_list *list;
@@ -2347,126 +2364,126 @@ yyreduce:
 
   case 53:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 425 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 426 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 427 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 431 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 432 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 438 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 440 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 444 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 445 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 451 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 457 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 458 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 462 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 463 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 464 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 465 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 471 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2476,7 +2493,7 @@ yyreduce:
 
   case 71:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 476 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2486,7 +2503,7 @@ yyreduce:
 
   case 72:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 481 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2497,7 +2514,7 @@ yyreduce:
 
   case 73:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 487 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2508,7 +2525,7 @@ yyreduce:
 
   case 74:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 493 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2520,7 +2537,7 @@ yyreduce:
 
   case 81:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 523 "parse-gram.y"
     {
       yyerrok;
@@ -2529,7 +2546,7 @@ yyreduce:
 
   case 82:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 529 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (2)].symbol); current_lhs_location = (yylsp[(1) - (2)]);
     current_lhs_named_ref = (yyvsp[(2) - (2)].named_ref); }
@@ -2537,21 +2554,21 @@ yyreduce:
 
   case 84:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 534 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 535 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 541 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
@@ -2559,77 +2576,77 @@ yyreduce:
 
   case 88:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 544 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 546 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 548 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 550 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 552 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 556 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 558 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 570 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 575 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 576 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 587 "parse-gram.y"
     {
       code_props plain_code;
@@ -2643,14 +2660,14 @@ yyreduce:
 
   case 101:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 607 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 609 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2661,14 +2678,14 @@ yyreduce:
 
   case 103:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 617 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 629 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2678,7 +2695,7 @@ yyreduce:
 
   case 108:
 
-/* Line 1492 of yacc.c  */
+/* Line 1509 of yacc.c  */
 #line 638 "parse-gram.y"
     {
       code_props plain_code;
@@ -2692,8 +2709,8 @@ yyreduce:
 
 
 
-/* Line 1492 of yacc.c  */
-#line 2697 "parse-gram.c"
+/* Line 1509 of yacc.c  */
+#line 2714 "parse-gram.c"
       default: break;
     }
   /* User semantic actions sometimes alter yychar, and that requires
@@ -2737,7 +2754,7 @@ yyreduce:
 yyerrlab:
   /* Make sure we have latest lookahead translation.  See comments at
      user semantic actions for why this is necessary.  */
-  yytoken = YYTRANSLATE (yychar);
+  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
 
   /* If not already recovering from an error, report this error.  */
   if (!yyerrstatus)
@@ -2753,7 +2770,7 @@ yyerrlab:
         int yysyntax_error_status = YYSYNTAX_ERROR;
         if (yysyntax_error_status == 0)
           yymsgp = yymsg;
-        else if (yysyntax_error_status == 2 && 0 < yymsg_alloc)
+        else if (yysyntax_error_status == 1)
           {
             if (yymsg != yymsgbuf)
               YYSTACK_FREE (yymsg);
@@ -2762,6 +2779,7 @@ yyerrlab:
               {
                 yymsg = yymsgbuf;
                 yymsg_alloc = sizeof yymsgbuf;
+                yysyntax_error_status = 2;
               }
             else
               {
@@ -2928,7 +2946,7 @@ yyreturn:
 
 
 
-/* Line 1729 of yacc.c  */
+/* Line 1747 of yacc.c  */
 #line 648 "parse-gram.y"
 
 
