@@ -1303,7 +1303,7 @@ do {                                                             \
     {                                                            \
       YYDPRINTF ((stderr,                                        \
                   "LAC: initial context established for %s\n",   \
-                  yysymbol_name(yytoken)));                      \
+                  yysymbol_name (yytoken)));                     \
       yy_lac_established = 1;                                    \
       {                                                          \
         int yy_lac_status =                                      \
@@ -1356,7 +1356,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
   yy_state_t *yyes_prev = yyssp;
   yy_state_t *yyesp = yyes_prev;
   /* Reduce until we encounter a shift and thereby accept the token.  */
-  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name(yytoken)));
+  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
   if (yytoken == YYUNDEFTOK)
     {
       YYDPRINTF ((stderr, " Always Err\n"));
@@ -1454,6 +1454,91 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
     }
 }
 
+typedef struct
+{
+  yy_state_t *yyssp;
+  int yytoken;
+  YYLTYPE *yylloc;
+  yy_state_t *yyesa;
+  yy_state_t **yyes_p;
+  YYPTRDIFF_T *yyes_capacity_p;
+} yyparse_context_t;
+
+/* Put in YYARG at most YYARGN of the expected tokens given the
+   current YYCTX, and return the number of tokens stored in YYARG.  If
+   YYARG is null, return the number of expected tokens (guaranteed to
+   be less than YYNTOKENS).  */
+static int
+yyexpected_tokens (const yyparse_context_t *yyctx,
+                   int yyarg[], int yyargn)
+{
+  /* Actual size of YYARG. */
+  int yycount = 0;
+
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
+      }
+  return yycount;
+}
+
+static int
+yysyntax_error_arguments (const yyparse_context_t *yyctx,
+                          int yyarg[], int yyargn)
+{
+  /* Actual size of YYARG. */
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
+       In the first two cases, it might appear that the current syntax
+       error should have been detected in the previous state when yy_lac
+       was invoked.  However, at that time, there might have been a
+       different syntax error that discarded a different initial context
+       during error recovery, leaving behind the current lookahead.
+  */
+  if (yyctx->yytoken != YYEMPTY)
+    {
+      int yyn;
+      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
+      yyarg[yycount++] = yyctx->yytoken;
+      yyn = yyexpected_tokens (yyctx, yyarg ? yyarg + 1 : yyarg, yyargn - 1);
+      if (yyn == -2)
+        return -2;
+      else if (yyn == 0)
+        YYDPRINTF ((stderr, "No expected tokens.\n"));
+      else
+        yycount += yyn;
+    }
+  return yycount;
+}
+
 
 # ifndef yystrlen
 #  if defined __GLIBC__ && defined _STRING_H
@@ -1542,6 +1627,7 @@ yytnamerr (char *yyres, const char *yystr)
 }
 # endif
 
+
 /* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
    about the unexpected token YYTOKEN for the state stack whose top is
    YYSSP.  In order to see if a particular token T is a
@@ -1554,70 +1640,22 @@ yytnamerr (char *yyres, const char *yystr)
    yy_lac returned 2.  */
 static int
 yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
-                yy_state_t *yyesa, yy_state_t **yyes,
-                YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, int yytoken)
+                const yyparse_context_t *yyctx)
 {
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
   const char *yyformat = YY_NULLPTR;
   /* Arguments of yyformat: reported tokens (one for the "unexpected",
      one per "expected"). */
-  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
-  /* Actual size of YYARG. */
-  int yycount = 0;
+  int yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
   /* Cumulated lengths of YYARG.  */
   YYPTRDIFF_T yysize = 0;
 
-  /* There are many possibilities here to consider:
-     - If this state is a consistent state with a default action, then
-       the only way this function was invoked is if the default action
-       is an error action.  In that case, don't check for expected
-       tokens because there are none.
-     - The only way there can be no lookahead present (in yychar) is if
-       this state is a consistent state with a default action.  Thus,
-       detecting the absence of a lookahead is sufficient to determine
-       that there is no unexpected or expected token to report.  In that
-       case, just report a simple "syntax error".
-     - Don't assume there isn't a lookahead just because this state is a
-       consistent state with a default action.  There might have been a
-       previous inconsistent state, consistent state with a non-default
-       action, or user semantic action that manipulated yychar.
-       In the first two cases, it might appear that the current syntax
-       error should have been detected in the previous state when yy_lac
-       was invoked.  However, at that time, there might have been a
-       different syntax error that discarded a different initial context
-       during error recovery, leaving behind the current lookahead.
-  */
-  if (yytoken != YYEMPTY)
-    {
-      int yyn = yypact[+*yyssp];
-      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
-      yyarg[yycount++] = yytname[yytoken];
-      if (!yypact_value_is_default (yyn))
-        {
-          int yyx;
-          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
-            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
-              {
-                {
-                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
-                                              yyssp, yyx);
-                  if (yy_lac_status == 2)
-                    return 2;
-                  if (yy_lac_status == 1)
-                    continue;
-                }
-                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
-                  {
-                    yycount = 1;
-                    break;
-                  }
-                yyarg[yycount++] = yytname[yyx];
-              }
-        }
-      else
-        YYDPRINTF ((stderr, "No expected tokens.\n"));
-    }
+  /* Actual size of YYARG. */
+  int yycount
+    = yysyntax_error_arguments (yyctx, yyarg, YYERROR_VERBOSE_ARGS_MAXIMUM);
+  if (yycount == -2)
+    return 2;
 
   switch (yycount)
     {
@@ -1642,7 +1680,8 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
     int yyi;
     for (yyi = 0; yyi < yycount; ++yyi)
       {
-        YYPTRDIFF_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yyarg[yyi]);
+        YYPTRDIFF_T yysize1
+          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
         if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
           yysize = yysize1;
         else
@@ -1668,7 +1707,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
     while ((*yyp = *yyformat) != '\0')
       if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
         {
-          yyp += yytnamerr (yyp, yyarg[yyi++]);
+          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
           yyformat += 2;
         }
       else
@@ -2640,25 +2679,26 @@ yyerrlab:
   if (!yyerrstatus)
     {
       ++yynerrs;
-# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
-                                        yyesa, &yyes, &yyes_capacity, \
-                                        yyssp, yytoken)
       {
         char const *yymsgp = YY_("syntax error");
+        yyparse_context_t yyctx
+          = {yyssp, yytoken, &yylloc, yyesa, &yyes, &yyes_capacity};
         int yysyntax_error_status;
         if (yychar != YYEMPTY)
           YY_LAC_ESTABLISH;
-        yysyntax_error_status = YYSYNTAX_ERROR;
+        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
         if (yysyntax_error_status == 0)
           yymsgp = yymsg;
         else if (yysyntax_error_status == 1)
           {
             if (yymsg != yymsgbuf)
               YYSTACK_FREE (yymsg);
-            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
+            yymsg = YY_CAST (char *,
+                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
             if (yymsg)
               {
-                yysyntax_error_status = YYSYNTAX_ERROR;
+                yysyntax_error_status
+                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                 yymsgp = yymsg;
               }
             else
@@ -2672,7 +2712,6 @@ yyerrlab:
         if (yysyntax_error_status == 2)
           goto yyexhaustedlab;
       }
-# undef YYSYNTAX_ERROR
     }
 
   yyerror_range[1] = yylloc;
