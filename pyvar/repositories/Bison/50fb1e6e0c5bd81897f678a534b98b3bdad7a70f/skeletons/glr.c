@@ -502,7 +502,6 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
   } while (0)
 #endif
 
-
 /** State numbers. */
 typedef int yy_state_t;
 
@@ -2060,30 +2059,50 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
   return yyok;
 }
 
-static void
-yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
+]m4_if(b4_percent_define_get([[parse.error]]), [simple], [],
+[[/* Put in YYARG at most YYARGN of the expected tokens given the
+   current YYSTACKP, and return the number of tokens stored in YYARG.  If
+   YYARG is null, return the number of expected tokens (guaranteed to
+   be less than YYNTOKENS).  */
+static int
+yyexpected_tokens (const yyGLRStack* yystackp,
+                   int yyarg[], int yyargn)
 {
-  if (yystackp->yyerrState != 0)
-    return;
-]m4_case(b4_percent_define_get([parse.error]),
-         [simple],
-[[  yyerror (]b4_lyyerror_args[YY_("syntax error"));]],
-         [verbose],
-[[  {
-  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
-  yybool yysize_overflow = yyfalse;
-  char* yymsg = YY_NULLPTR;
-  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
-  /* Internationalized format string. */
-  const char *yyformat = YY_NULLPTR;
-  /* Arguments of yyformat: reported tokens (one for the "unexpected",
-     one per "expected"). */
-  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
   /* Actual size of YYARG. */
   int yycount = 0;
-  /* Cumulated lengths of YYARG.  */
-  ptrdiff_t yysize = 0;
+  int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
+  if (!yypact_value_is_default (yyn))
+    {
+      /* Start YYX at -YYN if negative to avoid negative indexes in
+         YYCHECK.  In other words, skip the first -YYN actions for
+         this state because they are default actions.  */
+      int yyxbegin = yyn < 0 ? -yyn : 0;
+      /* Stay within bounds of both yycheck and yytname.  */
+      int yychecklim = YYLAST - yyn + 1;
+      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
+      int yyx;
+      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
+        if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
+            && !yytable_value_is_error (yytable[yyx + yyn]))
+          {
+            if (!yyarg)
+              ++yycount;
+            else if (yycount == yyargn)
+              return 0;
+            else
+              yyarg[yycount++] = yyx;
+          }
+    }
+  return yycount;
+}
 
+static int
+yysyntax_error_arguments (const yyGLRStack* yystackp,
+                          int yyarg[], int yyargn)
+{
+  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
+  /* Actual size of YYARG. */
+  int yycount = 0;
   /* There are many possibilities here to consider:
      - If this state is a consistent state with a default action, then
        the only way this function was invoked is if the default action
@@ -2097,7 +2116,12 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
      - Don't assume there isn't a lookahead just because this state is a
        consistent state with a default action.  There might have been a
        previous inconsistent state, consistent state with a non-default
-       action, or user semantic action that manipulated yychar.
+       action, or user semantic action that manipulated yychar.]b4_lac_if([[
+       In the first two cases, it might appear that the current syntax
+       error should have been detected in the previous state when yy_lac
+       was invoked.  However, at that time, there might have been a
+       different syntax error that discarded a different initial context
+       during error recovery, leaving behind the current lookahead.]], [[
      - Of course, the expected token list depends on states to have
        correct lookahead information, and it depends on the parser not
        to perform extra reductions after fetching a lookahead from the
@@ -2105,35 +2129,46 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
        (from LALR or IELR) and default reductions corrupt the expected
        token list.  However, the list is correct for canonical LR with
        one exception: it will still contain any token that will not be
-       accepted due to an error action in a later state.
+       accepted due to an error action in a later state.]])[
   */
   if (yytoken != YYEMPTY)
     {
-      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
-      yyarg[yycount++] = yysymbol_name (yytoken);
-      if (!yypact_value_is_default (yyn))
-        {
-          /* Start YYX at -YYN if negative to avoid negative indexes in
-             YYCHECK.  In other words, skip the first -YYN actions for this
-             state because they are default actions.  */
-          int yyxbegin = yyn < 0 ? -yyn : 0;
-          /* Stay within bounds of both yycheck and yytname.  */
-          int yychecklim = YYLAST - yyn + 1;
-          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-          int yyx;
-          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
-                && !yytable_value_is_error (yytable[yyx + yyn]))
-              {
-                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
-                  {
-                    yycount = 1;
-                    break;
-                  }
-                yyarg[yycount++] = yysymbol_name (yyx);
-              }
-        }
+      int yyn;
+      yyarg[yycount++] = yytoken;
+      yyn = yyexpected_tokens (yystackp, yyarg ? yyarg + 1 : yyarg, yyargn - 1);
+      if (yyn == -2)
+        return -2;
+      else
+        yycount += yyn;
     }
+  return yycount;
+}
+]])[
+
+static void
+yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
+{
+  if (yystackp->yyerrState != 0)
+    return;
+]m4_case(b4_percent_define_get([parse.error]),
+         [simple],
+[[  yyerror (]b4_lyyerror_args[YY_("syntax error"));]],
+         [verbose],
+[[  {
+  yybool yysize_overflow = yyfalse;
+  char* yymsg = YY_NULLPTR;
+  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
+  /* Internationalized format string. */
+  const char *yyformat = YY_NULLPTR;
+  /* Arguments of yyformat: reported tokens (one for the "unexpected",
+     one per "expected"). */
+  yySymbol yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
+  /* Cumulated lengths of YYARG.  */
+  ptrdiff_t yysize = 0;
+
+  /* Actual size of YYARG. */
+  int yycount
+    = yysyntax_error_arguments (yystackp, yyarg, YYERROR_VERBOSE_ARGS_MAXIMUM);
 
   switch (yycount)
     {
@@ -2158,7 +2193,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
     int yyi;
     for (yyi = 0; yyi < yycount; ++yyi)
       {
-        ptrdiff_t yysz = yytnamerr (YY_NULLPTR, yyarg[yyi]);
+        ptrdiff_t yysz = yytnamerr (YY_NULLPTR, yysymbol_name (yyarg[yyi]));
         if (YYSIZEMAX - yysize < yysz)
           yysize_overflow = yytrue;
         else
@@ -2177,7 +2212,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
         {
           if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
             {
-              yyp += yytnamerr (yyp, yyarg[yyi++]);
+              yyp += yytnamerr (yyp, yysymbol_name (yyarg[yyi++]));
               yyformat += 2;
             }
           else
