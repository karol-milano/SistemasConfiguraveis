@@ -1461,20 +1461,13 @@ yytnamerr (char *yyres, const char *yystr)
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
@@ -1484,22 +1477,51 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
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
@@ -1512,14 +1534,13 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
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
@@ -1527,6 +1548,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
       case N:                               \
         yyformat = S;                       \
       break
+      YYCASE_(0, YY_("syntax error"));
       YYCASE_(1, YY_("syntax error, unexpected %s"));
       YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
       YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
@@ -1537,11 +1559,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 
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
@@ -1550,7 +1568,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
       if (! (yysize <= *yymsg_alloc
              && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
         *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
-      return 2;
+      return 1;
     }
 
   /* Avoid sprintf, as that infringes on the user's name space.
@@ -1573,7 +1591,6 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
   }
   return 0;
 }
-}
 #endif /* YYERROR_VERBOSE */
 
 
@@ -1748,7 +1765,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1213 of yacc.c  */
+/* Line 1230 of yacc.c  */
 #line 80 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1756,8 +1773,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1213 of yacc.c  */
-#line 1761 "src/parse-gram.c"
+/* Line 1230 of yacc.c  */
+#line 1778 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1943,7 +1960,7 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 267 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -1954,106 +1971,106 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1426 of yacc.c  */
-#line 1959 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 1976 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 277 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1426 of yacc.c  */
-#line 1969 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 1986 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 281 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1426 of yacc.c  */
-#line 1980 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 1997 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 285 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1426 of yacc.c  */
-#line 1988 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2005 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 287 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1426 of yacc.c  */
-#line 1999 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2016 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 292 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1426 of yacc.c  */
-#line 2010 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2027 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 296 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1426 of yacc.c  */
-#line 2018 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2035 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 297 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1426 of yacc.c  */
-#line 2026 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2043 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 298 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1426 of yacc.c  */
-#line 2034 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2051 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 299 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1426 of yacc.c  */
-#line 2042 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2059 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 301 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1426 of yacc.c  */
-#line 2053 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2070 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 306 "src/parse-gram.y"
     {
       code_props action;
@@ -2063,92 +2080,92 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1426 of yacc.c  */
-#line 2068 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2085 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 314 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1426 of yacc.c  */
-#line 2076 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2093 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 315 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1426 of yacc.c  */
-#line 2084 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2101 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 316 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1426 of yacc.c  */
-#line 2092 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2109 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1426 of yacc.c  */
-#line 2100 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2117 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 318 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1426 of yacc.c  */
-#line 2108 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2125 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 319 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1426 of yacc.c  */
-#line 2116 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2133 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 320 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1426 of yacc.c  */
-#line 2124 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2141 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 321 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1426 of yacc.c  */
-#line 2132 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2149 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 321 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1426 of yacc.c  */
-#line 2140 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2157 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 322 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1426 of yacc.c  */
-#line 2148 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2165 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 324 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2173,62 +2190,62 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1426 of yacc.c  */
-#line 2178 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2195 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 347 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1426 of yacc.c  */
-#line 2186 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2203 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 348 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1426 of yacc.c  */
-#line 2194 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2211 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 349 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1426 of yacc.c  */
-#line 2202 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2219 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 354 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2210 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2227 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 355 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2218 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2235 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 367 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1426 of yacc.c  */
-#line 2228 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2245 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 371 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2236,12 +2253,12 @@ yyreduce:
 	symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1426 of yacc.c  */
-#line 2241 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2258 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 378 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2249,32 +2266,32 @@ yyreduce:
 	symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1426 of yacc.c  */
-#line 2254 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2271 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 385 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1426 of yacc.c  */
-#line 2264 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2281 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 389 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1426 of yacc.c  */
-#line 2274 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2291 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 393 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2282,89 +2299,89 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1426 of yacc.c  */
-#line 2287 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2304 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 400 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1426 of yacc.c  */
-#line 2298 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2315 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 414 "src/parse-gram.y"
     {}
-/* Line 1426 of yacc.c  */
-#line 2306 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2323 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 415 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2314 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2331 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 420 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1426 of yacc.c  */
-#line 2326 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2343 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 431 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1426 of yacc.c  */
-#line 2334 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2351 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 432 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1426 of yacc.c  */
-#line 2345 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2362 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 436 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1426 of yacc.c  */
-#line 2353 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2370 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 437 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1426 of yacc.c  */
-#line 2364 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2381 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 442 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2373,12 +2390,12 @@ yyreduce:
 	symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1426 of yacc.c  */
-#line 2378 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2395 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 453 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2391,202 +2408,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1426 of yacc.c  */
-#line 2396 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2413 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 467 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1426 of yacc.c  */
-#line 2404 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2421 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 468 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1426 of yacc.c  */
-#line 2412 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2429 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 469 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1426 of yacc.c  */
-#line 2420 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2437 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 470 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1426 of yacc.c  */
-#line 2428 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2445 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 474 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1426 of yacc.c  */
-#line 2436 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2453 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 475 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1426 of yacc.c  */
-#line 2444 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2461 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 481 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2452 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2469 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 483 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1426 of yacc.c  */
-#line 2460 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2477 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 487 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1426 of yacc.c  */
-#line 2468 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2485 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 488 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2476 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2493 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 494 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2484 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2501 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 496 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1426 of yacc.c  */
-#line 2492 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2509 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 500 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1426 of yacc.c  */
-#line 2500 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2517 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 501 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1426 of yacc.c  */
-#line 2508 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2525 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 505 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2516 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2533 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2524 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2541 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 507 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2532 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2549 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 508 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2540 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2557 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 514 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1426 of yacc.c  */
-#line 2551 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2568 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 519 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1426 of yacc.c  */
-#line 2562 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2579 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 524 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1426 of yacc.c  */
-#line 2574 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2591 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 530 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1426 of yacc.c  */
-#line 2586 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2603 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 536 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2594,144 +2611,144 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1426 of yacc.c  */
-#line 2599 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2616 "src/parse-gram.c"
     break;
 
   case 82:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 566 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1426 of yacc.c  */
-#line 2609 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2626 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 572 "src/parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
-/* Line 1426 of yacc.c  */
-#line 2618 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2635 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 577 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2626 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2643 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 578 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2634 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2651 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 584 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
-/* Line 1426 of yacc.c  */
-#line 2643 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2660 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 587 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1426 of yacc.c  */
-#line 2651 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2668 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 589 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1426 of yacc.c  */
-#line 2659 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2676 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 591 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1426 of yacc.c  */
-#line 2667 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2684 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 593 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2675 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2692 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 595 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2683 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2700 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 597 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2691 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2708 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 601 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1426 of yacc.c  */
-#line 2699 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2716 "src/parse-gram.c"
     break;
 
   case 96:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 603 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2707 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2724 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 614 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1426 of yacc.c  */
-#line 2715 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2732 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 619 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1426 of yacc.c  */
-#line 2723 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2740 "src/parse-gram.c"
     break;
 
   case 100:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 620 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1426 of yacc.c  */
-#line 2731 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2748 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 631 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2741,51 +2758,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1426 of yacc.c  */
-#line 2746 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2763 "src/parse-gram.c"
     break;
 
   case 103:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 651 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2754 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2771 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 653 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1426 of yacc.c  */
-#line 2766 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2783 "src/parse-gram.c"
     break;
 
   case 105:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 661 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1426 of yacc.c  */
-#line 2774 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2791 "src/parse-gram.c"
     break;
 
   case 108:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 673 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1426 of yacc.c  */
-#line 2785 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2802 "src/parse-gram.c"
     break;
 
   case 110:
-/* Line 1426 of yacc.c  */
+/* Line 1443 of yacc.c  */
 #line 682 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2795,13 +2812,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1426 of yacc.c  */
-#line 2800 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2817 "src/parse-gram.c"
     break;
 
 
-/* Line 1426 of yacc.c  */
-#line 2805 "src/parse-gram.c"
+/* Line 1443 of yacc.c  */
+#line 2822 "src/parse-gram.c"
       default: break;
     }
   /* User semantic actions sometimes alter yychar, and that requires
@@ -2845,7 +2862,7 @@ yyreduce:
 yyerrlab:
   /* Make sure we have latest lookahead translation.  See comments at
      user semantic actions for why this is necessary.  */
-  yytoken = YYTRANSLATE (yychar);
+  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
 
   /* If not already recovering from an error, report this error.  */
   if (!yyerrstatus)
@@ -2861,7 +2878,7 @@ yyerrlab:
         int yysyntax_error_status = YYSYNTAX_ERROR;
         if (yysyntax_error_status == 0)
           yymsgp = yymsg;
-        else if (yysyntax_error_status == 2 && 0 < yymsg_alloc)
+        else if (yysyntax_error_status == 1)
           {
             if (yymsg != yymsgbuf)
               YYSTACK_FREE (yymsg);
@@ -2870,6 +2887,7 @@ yyerrlab:
               {
                 yymsg = yymsgbuf;
                 yymsg_alloc = sizeof yymsgbuf;
+                yysyntax_error_status = 2;
               }
             else
               {
@@ -3034,7 +3052,7 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 1662 of yacc.c  */
+/* Line 1680 of yacc.c  */
 #line 692 "src/parse-gram.y"
 
 
