@@ -1140,8 +1140,8 @@ static int
 yypstate_expected_tokens (yypstate *yyps,
                           yysymbol_kind_t yyarg[], int yyargn)]], [[
 static int
-yyexpected_tokens (const yypcontext_t *yyctx,
-                   yysymbol_kind_t yyarg[], int yyargn)]])[
+yypcontext_expected_tokens (const yypcontext_t *yyctx,
+                            yysymbol_kind_t yyarg[], int yyargn)]])[
 {
   /* Actual size of YYARG. */
   int yycount = 0;
@@ -1196,8 +1196,8 @@ yyexpected_tokens (const yypcontext_t *yyctx,
 ]b4_push_if([[
 /* Similar to the previous function.  */
 static int
-yyexpected_tokens (const yypcontext_t *yyctx,
-                   yysymbol_kind_t yyarg[], int yyargn)
+yypcontext_expected_tokens (const yypcontext_t *yyctx,
+                            yysymbol_kind_t yyarg[], int yyargn)
 {
   return yypstate_expected_tokens (yyctx->yyps, yyarg, yyargn);
 }]])[
@@ -1359,7 +1359,8 @@ yy_syntax_error_arguments (const yypcontext_t *yyctx,
       if (yyarg)
         yyarg[yycount] = yyctx->yytoken;
       ++yycount;
-      yyn = yyexpected_tokens (yyctx, yyarg ? yyarg + 1 : yyarg, yyargn - 1);
+      yyn = yypcontext_expected_tokens (yyctx,
+                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
       if (yyn == YYENOMEM)
         return YYENOMEM;]b4_lac_if([[
       else if (yyn == 0)
@@ -1513,8 +1514,8 @@ void
 yypstate_clear (yypstate *yyps)
 {
 ]b4_initialize_parser_state_variables[
-  /* Initialize the state stack, in case yyexpected_tokens is called
-     before the first call to yyparse. */
+  /* Initialize the state stack, in case yypcontext_expected_tokens is
+     called before the first call to yyparse. */
   *yyssp = 0;
 }
 
