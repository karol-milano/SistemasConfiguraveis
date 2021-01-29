@@ -1517,52 +1517,6 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
 
 
 
-static int
-yysyntax_error_arguments (const yyparse_context_t *yyctx,
-                          int yyarg[], int yyargn) YY_ATTRIBUTE_UNUSED;
-
-static int
-yysyntax_error_arguments (const yyparse_context_t *yyctx,
-                          int yyarg[], int yyargn)
-{
-  /* Actual size of YYARG. */
-  int yycount = 0;
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
-  if (yyctx->yytoken != YYEMPTY)
-    {
-      int yyn;
-      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
-      yyarg[yycount++] = yyctx->yytoken;
-      yyn = yyexpected_tokens (yyctx, yyarg ? yyarg + 1 : yyarg, yyargn - 1);
-      if (yyn == -2)
-        return -2;
-      else if (yyn == 0)
-        YYDPRINTF ((stderr, "No expected tokens.\n"));
-      else
-        yycount += yyn;
-    }
-  return yycount;
-}
-
 
 /* The token type of the lookahead of this context.  */
 static int
