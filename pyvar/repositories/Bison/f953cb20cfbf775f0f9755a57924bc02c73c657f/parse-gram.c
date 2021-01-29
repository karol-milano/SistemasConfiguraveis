@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.1.243-8699.  */
+/* A Bison parser, made by GNU Bison 2.4.1.247-0e0f-dirty.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.243-8699"
+#define YYBISON_VERSION "2.4.1.247-0e0f-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1460,105 +1460,104 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
   if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
     return 1;
   else
+{
+  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
+  YYSIZE_T yysize = yysize0;
+  YYSIZE_T yysize1;
+  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
+  /* Internationalized format string. */
+  const char *yyformat = 0;
+  /* Arguments of yyformat. */
+  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
+
+          /* Start YYX at -YYN if negative to avoid negative indexes in
+             YYCHECK.  In other words, skip the first -YYN actions for
+             this state because they are default actions.  */
+          int yyxbegin = yyn < 0 ? -yyn : 0;
+
+          /* Stay within bounds of both yycheck and yytname.  */
+          int yychecklim = YYLAST - yyn + 1;
+          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
+  /* Number of reported tokens (one for the "unexpected", one per
+     "expected"). */
+  int yycount = 0;
+          int yyx;
+
+  yyarg[yycount++] = yytname[yytoken];
+
+          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
+            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
+                && !yytable_value_is_error (yytable[yyx + yyn]))
+              {
+                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
+                  {
+                    yycount = 1;
+                    yysize = yysize0;
+                    break;
+                  }
+                yyarg[yycount++] = yytname[yyx];
+                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
+                if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+                  {
+                    /* Overflow.  */
+                    *yymsg_alloc = 0;
+                    return 2;
+                  }
+                yysize = yysize1;
+              }
+
+  switch (yycount)
     {
-      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
-      YYSIZE_T yysize = yysize0;
-      YYSIZE_T yysize1;
-      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
-      /* Internationalized format string. */
-      const char *yyformat = 0;
-      /* Arguments of yyformat. */
-      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
-
-      /* Start YYX at -YYN if negative to avoid negative indexes in
-	 YYCHECK.  In other words, skip the first -YYN actions for this
-	 state because they are default actions.  */
-      int yyxbegin = yyn < 0 ? -yyn : 0;
-
-      /* Stay within bounds of both yycheck and yytname.  */
-      int yychecklim = YYLAST - yyn + 1;
-      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-      /* Number of reported tokens (one for the "unexpected", one per
-         "expected"). */
-      int yycount = 0;
-      int yyx;
-
-      yyarg[yycount++] = yytname[yytoken];
-
-      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
-	    && !yytable_value_is_error (yytable[yyx + yyn]))
-	  {
-	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
-	      {
-		yycount = 1;
-		yysize = yysize0;
-		break;
-	      }
-	    yyarg[yycount++] = yytname[yyx];
-	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
-	    if (! (yysize <= yysize1
-		   && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
-	      {
-		/* Overflow.  */
-		*yymsg_alloc = 0;
-		return 2;
-	      }
-	    yysize = yysize1;
-	  }
-
-      switch (yycount)
-        {
-#define YYCASE_(N, S)                           \
-          case N:                               \
-            yyformat = S;                       \
-          break
-          YYCASE_(1, YY_("syntax error, unexpected %s"));
-          YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
-          YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
-          YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
-          YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
+#define YYCASE_(N, S)                       \
+      case N:                               \
+        yyformat = S;                       \
+      break
+      YYCASE_(1, YY_("syntax error, unexpected %s"));
+      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
+      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
+      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
+      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
 #undef YYCASE_
-        }
+    }
 
-      yysize1 = yysize + yystrlen (yyformat);
-      if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+  yysize1 = yysize + yystrlen (yyformat);
+  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+    {
+      /* Overflow.  */
+      *yymsg_alloc = 0;
+      return 2;
+    }
+  yysize = yysize1;
+
+  if (*yymsg_alloc < yysize)
+    {
+      *yymsg_alloc = 2 * yysize;
+      if (! (yysize <= *yymsg_alloc
+             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
+        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
+      return 2;
+    }
+
+  /* Avoid sprintf, as that infringes on the user's name space.
+     Don't have undefined behavior even if the translation
+     produced a string with the wrong number of "%s"s.  */
+  {
+    char *yyp = *yymsg;
+    int yyi = 0;
+    while ((*yyp = *yyformat) != '\0')
+      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
         {
-          /* Overflow.  */
-          *yymsg_alloc = 0;
-          return 2;
+          yyp += yytnamerr (yyp, yyarg[yyi++]);
+          yyformat += 2;
         }
-      yysize = yysize1;
-
-      if (*yymsg_alloc < yysize)
+      else
         {
-          *yymsg_alloc = 2 * yysize;
-          if (! (yysize <= *yymsg_alloc
-                 && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
-            *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
-          return 2;
+          yyp++;
+          yyformat++;
         }
-
-      /* Avoid sprintf, as that infringes on the user's name space.
-         Don't have undefined behavior even if the translation
-         produced a string with the wrong number of "%s"s.  */
-      {
-        char *yyp = *yymsg;
-        int yyi = 0;
-        while ((*yyp = *yyformat) != '\0')
-          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
-            {
-              yyp += yytnamerr (yyp, yyarg[yyi++]);
-              yyformat += 2;
-            }
-          else
-            {
-              yyp++;
-              yyformat++;
-            }
-      }
-      return 0;
-    }
+  }
+  return 0;
+}
 }
 #endif /* YYERROR_VERBOSE */
 
@@ -1734,7 +1733,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1280 of yacc.c  */
+/* Line 1279 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1743,8 +1742,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1280 of yacc.c  */
-#line 1748 "parse-gram.c"
+/* Line 1279 of yacc.c  */
+#line 1747 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1931,7 +1930,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 225 "parse-gram.y"
     {
       code_props plain_code;
@@ -1946,14 +1945,14 @@ yyreduce:
 
   case 7:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 234 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 236 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -1963,14 +1962,14 @@ yyreduce:
 
   case 9:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 240 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 242 "parse-gram.y"
     {
       defines_flag = true;
@@ -1980,42 +1979,42 @@ yyreduce:
 
   case 11:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 246 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 247 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 248 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 249 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 250 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 252 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -2025,7 +2024,7 @@ yyreduce:
 
   case 17:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 257 "parse-gram.y"
     {
       code_props action;
@@ -2039,77 +2038,77 @@ yyreduce:
 
   case 18:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 265 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 266 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 267 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 268 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 269 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 270 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 271 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 272 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 273 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 274 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 276 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2129,14 +2128,14 @@ yyreduce:
 
   case 29:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 290 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 292 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2165,28 +2164,28 @@ yyreduce:
 
   case 31:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 315 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 316 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 317 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 325 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2195,7 +2194,7 @@ yyreduce:
 
   case 38:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 329 "parse-gram.y"
     {
       symbol_list *list;
@@ -2207,7 +2206,7 @@ yyreduce:
 
   case 39:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 336 "parse-gram.y"
     {
       symbol_list *list;
@@ -2219,7 +2218,7 @@ yyreduce:
 
   case 40:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 343 "parse-gram.y"
     {
       default_prec = true;
@@ -2228,7 +2227,7 @@ yyreduce:
 
   case 41:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 347 "parse-gram.y"
     {
       default_prec = false;
@@ -2237,7 +2236,7 @@ yyreduce:
 
   case 42:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 351 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2249,7 +2248,7 @@ yyreduce:
 
   case 43:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 358 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2259,21 +2258,21 @@ yyreduce:
 
   case 44:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 372 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 373 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 378 "parse-gram.y"
     {
       union_seen = true;
@@ -2284,14 +2283,14 @@ yyreduce:
 
   case 47:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 389 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 390 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2301,14 +2300,14 @@ yyreduce:
 
   case 49:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 394 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 395 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2318,7 +2317,7 @@ yyreduce:
 
   case 51:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 400 "parse-gram.y"
     {
       symbol_list *list;
@@ -2331,7 +2330,7 @@ yyreduce:
 
   case 52:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 411 "parse-gram.y"
     {
       symbol_list *list;
@@ -2348,126 +2347,126 @@ yyreduce:
 
   case 53:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 425 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 426 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 427 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 431 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 432 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 438 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 440 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 444 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 445 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 451 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 457 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 458 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 462 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 463 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 464 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 465 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 471 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2477,7 +2476,7 @@ yyreduce:
 
   case 71:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 476 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2487,7 +2486,7 @@ yyreduce:
 
   case 72:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 481 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2498,7 +2497,7 @@ yyreduce:
 
   case 73:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 487 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2509,7 +2508,7 @@ yyreduce:
 
   case 74:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 493 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2521,7 +2520,7 @@ yyreduce:
 
   case 81:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 523 "parse-gram.y"
     {
       yyerrok;
@@ -2530,7 +2529,7 @@ yyreduce:
 
   case 82:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 529 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (2)].symbol); current_lhs_location = (yylsp[(1) - (2)]);
     current_lhs_named_ref = (yyvsp[(2) - (2)].named_ref); }
@@ -2538,21 +2537,21 @@ yyreduce:
 
   case 84:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 534 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 535 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 541 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
@@ -2560,77 +2559,77 @@ yyreduce:
 
   case 88:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 544 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 546 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 548 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 550 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 552 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 556 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 558 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 570 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 575 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 576 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 587 "parse-gram.y"
     {
       code_props plain_code;
@@ -2644,14 +2643,14 @@ yyreduce:
 
   case 101:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 607 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 609 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2662,14 +2661,14 @@ yyreduce:
 
   case 103:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 617 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 629 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2679,7 +2678,7 @@ yyreduce:
 
   case 108:
 
-/* Line 1493 of yacc.c  */
+/* Line 1492 of yacc.c  */
 #line 638 "parse-gram.y"
     {
       code_props plain_code;
@@ -2693,8 +2692,8 @@ yyreduce:
 
 
 
-/* Line 1493 of yacc.c  */
-#line 2698 "parse-gram.c"
+/* Line 1492 of yacc.c  */
+#line 2697 "parse-gram.c"
       default: break;
     }
   /* User semantic actions sometimes alter yychar, and that requires
@@ -2747,28 +2746,34 @@ yyerrlab:
 #if ! YYERROR_VERBOSE
       yyerror (YY_("syntax error"));
 #else
-      while (1)
-        {
-          int yysyntax_error_status =
-            yysyntax_error (&yymsg_alloc, &yymsg, yystate, yytoken);
-          if (yysyntax_error_status == 2 && 0 < yymsg_alloc)
-            {
-              if (yymsg != yymsgbuf)
-                YYSTACK_FREE (yymsg);
-              yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
-              if (yymsg)
-                continue;
-              yymsg = yymsgbuf;
-              yymsg_alloc = sizeof yymsgbuf;
-            }
-          if (yysyntax_error_status == 0)
-            yyerror (yymsg);
-          else
-            yyerror (YY_("syntax error"));
-          if (yysyntax_error_status == 2)
-            goto yyexhaustedlab;
-          break;
-        }
+# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, yystate, \
+                                        yytoken)
+      {
+        char const *yymsgp = YY_("syntax error");
+        int yysyntax_error_status = YYSYNTAX_ERROR;
+        if (yysyntax_error_status == 0)
+          yymsgp = yymsg;
+        else if (yysyntax_error_status == 2 && 0 < yymsg_alloc)
+          {
+            if (yymsg != yymsgbuf)
+              YYSTACK_FREE (yymsg);
+            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
+            if (!yymsg)
+              {
+                yymsg = yymsgbuf;
+                yymsg_alloc = sizeof yymsgbuf;
+              }
+            else
+              {
+                yysyntax_error_status = YYSYNTAX_ERROR;
+                yymsgp = yymsg;
+              }
+          }
+        yyerror (yymsgp);
+        if (yysyntax_error_status == 2)
+          goto yyexhaustedlab;
+      }
+# undef YYSYNTAX_ERROR
 #endif
     }
 
@@ -2923,7 +2928,7 @@ yyreturn:
 
 
 
-/* Line 1724 of yacc.c  */
+/* Line 1729 of yacc.c  */
 #line 648 "parse-gram.y"
 
 
