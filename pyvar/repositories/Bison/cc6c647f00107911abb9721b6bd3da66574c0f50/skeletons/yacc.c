@@ -1046,6 +1046,95 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
     }
 }]])[
 
+]m4_if(b4_percent_define_get([[parse.error]]), [simple], [],
+[[typedef struct
+{
+  yy_state_t *yyssp;
+  int yytoken;]b4_lac_if([[
+  yy_state_t *yyesa;
+  yy_state_t **yyes_p;
+  YYPTRDIFF_T *yyes_capacity_p;]])[
+} yyparse_context_t;
+
+static int
+yysyntax_error_arguments (const yyparse_context_t *yyctx,
+                          const char *yyarg[], int yyargn)
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
+       action, or user semantic action that manipulated yychar.]b4_lac_if([[
+       In the first two cases, it might appear that the current syntax
+       error should have been detected in the previous state when yy_lac
+       was invoked.  However, at that time, there might have been a
+       different syntax error that discarded a different initial context
+       during error recovery, leaving behind the current lookahead.]], [[
+     - Of course, the expected token list depends on states to have
+       correct lookahead information, and it depends on the parser not
+       to perform extra reductions after fetching a lookahead from the
+       scanner and before detecting a syntax error.  Thus, state merging
+       (from LALR or IELR) and default reductions corrupt the expected
+       token list.  However, the list is correct for canonical LR with
+       one exception: it will still contain any token that will not be
+       accepted due to an error action in a later state.]])[
+  */
+  if (yyctx->yytoken != YYEMPTY)
+    {
+      int yyn = yypact[+*yyctx->yyssp];]b4_lac_if([[
+      YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
+      yyarg[yycount++] = yytname[yyctx->yytoken];
+      if (!yypact_value_is_default (yyn))
+        {]b4_lac_if([[
+          int yyx;
+          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
+            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
+              {
+                {
+                  int yy_lac_status = yy_lac (yyctx->yyesa, yyctx->yyes_p, yyctx->yyes_capacity_p,
+                                              yyctx->yyssp, yyx);
+                  if (yy_lac_status == 2)
+                    return -2;
+                  if (yy_lac_status == 1)
+                    continue;
+                }]], [[
+          /* Start YYX at -YYN if negative to avoid negative indexes in
+             YYCHECK.  In other words, skip the first -YYN actions for
+             this state because they are default actions.  */
+          int yyxbegin = yyn < 0 ? -yyn : 0;
+          /* Stay within bounds of both yycheck and yytname.  */
+          int yychecklim = YYLAST - yyn + 1;
+          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
+          int yyx;
+          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
+            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
+                && !yytable_value_is_error (yytable[yyx + yyn]))
+              {]])[
+                if (yycount == yyargn)
+                  {
+                    yycount = 1;
+                    break;
+                  }
+                yyarg[yycount++] = yytname[yyx];
+              }
+        }]b4_lac_if([[
+      else
+        YYDPRINTF ((stderr, "No expected tokens.\n"));]])[
+    }
+  return yycount;
+}
+]])[
 
 ]m4_case(b4_percent_define_get([[parse.error]]), [verbose],
 [[# ifndef yystrlen
@@ -1135,6 +1224,7 @@ yytnamerr (char *yyres, const char *yystr)
 }
 # endif
 
+
 /* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
    about the unexpected token YYTOKEN for the state stack whose top is
    YYSSP.]b4_lac_if([[  In order to see if a particular token T is a
@@ -1147,8 +1237,7 @@ yytnamerr (char *yyres, const char *yystr)
    yy_lac returned 2]])[.  */
 static int
 yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
-                ]b4_lac_if([[yy_state_t *yyesa, yy_state_t **yyes,
-                YYPTRDIFF_T *yyes_capacity, ]])[yy_state_t *yyssp, int yytoken)
+                const yyparse_context_t *yyctx)
 {
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
@@ -1161,76 +1250,15 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
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
-       action, or user semantic action that manipulated yychar.]b4_lac_if([[
-       In the first two cases, it might appear that the current syntax
-       error should have been detected in the previous state when yy_lac
-       was invoked.  However, at that time, there might have been a
-       different syntax error that discarded a different initial context
-       during error recovery, leaving behind the current lookahead.]], [[
-     - Of course, the expected token list depends on states to have
-       correct lookahead information, and it depends on the parser not
-       to perform extra reductions after fetching a lookahead from the
-       scanner and before detecting a syntax error.  Thus, state merging
-       (from LALR or IELR) and default reductions corrupt the expected
-       token list.  However, the list is correct for canonical LR with
-       one exception: it will still contain any token that will not be
-       accepted due to an error action in a later state.]])[
-  */
-  if (yytoken != YYEMPTY)
-    {
-      int yyn = yypact[+*yyssp];]b4_lac_if([[
-      YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
-      yyarg[yycount++] = yytname[yytoken];
-      if (!yypact_value_is_default (yyn))
-        {]b4_lac_if([[
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
-                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
-                  {
-                    yycount = 1;
-                    break;
-                  }
-                yyarg[yycount++] = yytname[yyx];
-              }
-        }]b4_lac_if([[
-      else
-        YYDPRINTF ((stderr, "No expected tokens.\n"));]])[
-    }
+  {
+    int yyn
+      = yysyntax_error_arguments (yyctx, yyarg,
+                                  YYSIZEOF (yyarg) / YYSIZEOF (*yyarg));
+    if (yyn == -2)
+      return 2;
+    else
+      yycount = yyn;
+  }
 
   switch (yycount)
     {
@@ -1760,11 +1788,11 @@ yyerrlab:
          [simple],
 [[      yyerror (]b4_yyerror_args[YY_("syntax error"));]],
          [verbose],
-[[# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \]b4_lac_if([[
-                                        yyesa, &yyes, &yyes_capacity, \]])[
-                                        yyssp, yytoken)
+[[# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, &yyctx)
       {
         char const *yymsgp = YY_("syntax error");
+        yyparse_context_t yyctx
+          = {yyssp, yytoken]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])[};
         int yysyntax_error_status;]b4_lac_if([[
         if (yychar != YYEMPTY)
           YY_LAC_ESTABLISH;]])[
