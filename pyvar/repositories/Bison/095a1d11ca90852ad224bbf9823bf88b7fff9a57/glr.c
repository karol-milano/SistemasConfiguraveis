@@ -2094,11 +2094,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 #if ! YYERROR_VERBOSE
   yyerror (]b4_lyyerror_args[YY_("syntax error"));
 #else
-      int yyn;
-      yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
-if (YYPACT_NINF < yyn && yyn <= YYLAST)
-  {
-  yySymbol yytoken = YYTRANSLATE (yychar);
+  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
   size_t yysize0 = yytnamerr (NULL, yytokenName (yytoken));
   size_t yysize = yysize0;
   size_t yysize1;
@@ -2109,23 +2105,47 @@ if (YYPACT_NINF < yyn && yyn <= YYLAST)
   const char *yyformat = 0;
   /* Arguments of yyformat. */
   char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
+  /* Number of reported tokens (one for the "unexpected", one per
+     "expected").  */
+  int yycount = 0;
 
+  /* There are many possibilities here to consider:
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
+      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
+      yyarg[yycount++] = yytokenName (yytoken);
+      if (!yypact_value_is_default (yyn))
+        {
           /* Start YYX at -YYN if negative to avoid negative indexes in
              YYCHECK.  In other words, skip the first -YYN actions for this
              state because they are default actions.  */
           int yyxbegin = yyn < 0 ? -yyn : 0;
-
           /* Stay within bounds of both yycheck and yytname.  */
           int yychecklim = YYLAST - yyn + 1;
           int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-
-  /* Number of reported tokens (one for the "unexpected", one per
-     "expected").  */
-  int yycount = 0;
           int yyx;
-
-    yyarg[yycount++] = yytokenName (yytoken);
-
           for (yyx = yyxbegin; yyx < yyxend; ++yyx)
             if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                 && !yytable_value_is_error (yytable[yyx + yyn]))
@@ -2141,6 +2161,8 @@ if (YYPACT_NINF < yyn && yyn <= YYLAST)
                 yysize_overflow |= yysize1 < yysize;
                 yysize = yysize1;
               }
+        }
+    }
 
   switch (yycount)
     {
@@ -2148,6 +2170,7 @@ if (YYPACT_NINF < yyn && yyn <= YYLAST)
       case N:                           \
         yyformat = S;                   \
       break
+      YYCASE_(0, YY_("syntax error"));
       YYCASE_(1, YY_("syntax error, unexpected %s"));
       YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
       YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
@@ -2188,9 +2211,6 @@ if (YYPACT_NINF < yyn && yyn <= YYLAST)
       yyerror (]b4_lyyerror_args[YY_("syntax error"));
       yyMemoryExhausted (yystackp);
     }
-  }
-else
-  yyerror (]b4_lyyerror_args[YY_("syntax error"));
 #endif /* YYERROR_VERBOSE */
   yynerrs += 1;
 }
