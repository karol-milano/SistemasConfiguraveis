@@ -895,7 +895,7 @@ do {                                                             \
     {                                                            \
       YYDPRINTF ((stderr,                                        \
                   "LAC: initial context established for %s\n",   \
-                  yysymbol_name(yytoken)));                      \
+                  yysymbol_name (yytoken)));                     \
       yy_lac_established = 1;                                    \
       {                                                          \
         int yy_lac_status =                                      \
@@ -948,7 +948,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
   yy_state_t *yyes_prev = yyssp;
   yy_state_t *yyesp = yyes_prev;
   /* Reduce until we encounter a shift and thereby accept the token.  */
-  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name(yytoken)));
+  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
   if (yytoken == YYUNDEFTOK)
     {
       YYDPRINTF ((stderr, " Always Err\n"));
@@ -1056,6 +1056,62 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
   YYPTRDIFF_T *yyes_capacity_p;]])[
 } yyparse_context_t;
 
+/* Put in YYARG at most YYARGN of the expected tokens given
+   the current YYCTX, and return the number of tokens stored
+   in YYARG.
+   If YYARG is null, return the number of expected tokens.  */
+static int
+yyexpected_tokens (const yyparse_context_t *yyctx,
+                   int yyarg[], int yyargn)
+{
+  /* Actual size of YYARG. */
+  int yycount = 0;
+]b4_lac_if([[
+  int yyx;
+  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
+    if (yyx != YYTERROR && yyx != YYUNDEFTOK)
+      {
+        {
+          int yy_lac_status = yy_lac (yyctx->yyesa, yyctx->yyes_p, yyctx->yyes_capacity_p,
+                                      yyctx->yyssp, yyx);
+          if (yy_lac_status == 2)
+            return -2;
+          if (yy_lac_status == 1)
+            continue;
+        }
+        if (!yyarg)
+          ++yycount;
+        else if (yycount == yyargn)
+          return 0;
+        else
+          yyarg[yycount++] = yyx;
+      }]],
+[[  int yyn = yypact[+*yyctx->yyssp];
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
+    }]])[
+  return yycount;
+}
+
 static int
 yysyntax_error_arguments (const yyparse_context_t *yyctx,
                           int yyarg[], int yyargn)
@@ -1092,45 +1148,16 @@ yysyntax_error_arguments (const yyparse_context_t *yyctx,
   */
   if (yyctx->yytoken != YYEMPTY)
     {
-      int yyn = yypact[+*yyctx->yyssp];]b4_lac_if([[
+      int yyn;]b4_lac_if([[
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
       yyarg[yycount++] = yyctx->yytoken;
-      if (!yypact_value_is_default (yyn))
-        {]b4_lac_if([[
-          int yyx;
-          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
-            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
-              {
-                {
-                  int yy_lac_status = yy_lac (yyctx->yyesa, yyctx->yyes_p, yyctx->yyes_capacity_p,
-                                              yyctx->yyssp, yyx);
-                  if (yy_lac_status == 2)
-                    return -2;
-                  if (yy_lac_status == 1)
-                    continue;
-                }]], [[
-          /* Start YYX at -YYN if negative to avoid negative indexes in
-             YYCHECK.  In other words, skip the first -YYN actions for
-             this state because they are default actions.  */
-          int yyxbegin = yyn < 0 ? -yyn : 0;
-          /* Stay within bounds of both yycheck and yytname.  */
-          int yychecklim = YYLAST - yyn + 1;
-          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-          int yyx;
-          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
-                && !yytable_value_is_error (yytable[yyx + yyn]))
-              {]])[
-                if (yycount == yyargn)
-                  {
-                    yycount = 1;
-                    break;
-                  }
-                yyarg[yycount++] = yyx;
-              }
-        }]b4_lac_if([[
-      else
+      yyn = yyexpected_tokens (yyctx, yyarg ? yyarg + 1 : yyarg, yyargn - 1);
+      if (yyn == -2)
+        return -2;]b4_lac_if([[
+      else if (yyn == 0)
         YYDPRINTF ((stderr, "No expected tokens.\n"));]])[
+      else
+        yycount += yyn;
     }
   return yycount;
 }
