@@ -1197,63 +1197,9 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
 {
   return yypstate_expected_tokens (yyctx->yyps, yyarg, yyargn);
 }]])[
-
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
-  if (yyctx->yytoken != YYEMPTY)
-    {
-      int yyn;]b4_lac_if([[
-      YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
-      yyarg[yycount++] = yyctx->yytoken;
-      yyn = yyexpected_tokens (yyctx, yyarg ? yyarg + 1 : yyarg, yyargn - 1);
-      if (yyn == -2)
-        return -2;]b4_lac_if([[
-      else if (yyn == 0)
-        YYDPRINTF ((stderr, "No expected tokens.\n"));]])[
-      else
-        yycount += yyn;
-    }
-  return yycount;
-}
 ]])[
 
-]b4_parse_error_case(
+]b4_parse_error_bmatch(
          [custom],
 [[/* The token type of the lookahead of this context.  */
 static int
@@ -1278,8 +1224,7 @@ yyparse_context_location (const yyparse_context_t *yyctx)
 /* User defined function to report a syntax error.  */
 static int
 yyreport_syntax_error (const yyparse_context_t *yyctx]b4_user_formals[);]],
-         [simple],
-[[]],
+         [detailed\|verbose],
 [[#ifndef yystrlen
 # if defined __GLIBC__ && defined _STRING_H
 #  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
@@ -1369,6 +1314,56 @@ yytnamerr (char *yyres, const char *yystr)
 #endif
 ]])[
 
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
+      int yyn;]b4_lac_if([[
+      YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
+      yyarg[yycount++] = yyctx->yytoken;
+      yyn = yyexpected_tokens (yyctx, yyarg ? yyarg + 1 : yyarg, yyargn - 1);
+      if (yyn == -2)
+        return -2;]b4_lac_if([[
+      else if (yyn == 0)
+        YYDPRINTF ((stderr, "No expected tokens.\n"));]])[
+      else
+        yycount += yyn;
+    }
+  return yycount;
+}
+
 /* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
    about the unexpected token YYTOKEN for the state stack whose top is
    YYSSP.]b4_lac_if([[  In order to see if a particular token T is a
