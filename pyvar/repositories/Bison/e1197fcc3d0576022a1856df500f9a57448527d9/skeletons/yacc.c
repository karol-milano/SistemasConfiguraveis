@@ -1057,10 +1057,10 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
   YYPTRDIFF_T *yyes_capacity_p;]])[
 } yyparse_context_t;
 
-/* Put in YYARG at most YYARGN of the expected tokens given
-   the current YYCTX, and return the number of tokens stored
-   in YYARG.
-   If YYARG is null, return the number of expected tokens.  */
+/* Put in YYARG at most YYARGN of the expected tokens given the
+   current YYCTX, and return the number of tokens stored in YYARG.  If
+   YYARG is null, return the number of expected tokens (guaranteed to
+   be less than YYNTOKENS).  */
 static int
 yyexpected_tokens (const yyparse_context_t *yyctx,
                    int yyarg[], int yyargn)
@@ -1286,20 +1286,14 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
   /* Arguments of yyformat: reported tokens (one for the "unexpected",
      one per "expected"). */
   int yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
-  /* Actual size of YYARG. */
-  int yycount = 0;
   /* Cumulated lengths of YYARG.  */
   YYPTRDIFF_T yysize = 0;
 
-  {
-    int yyn
-      = yysyntax_error_arguments (yyctx, yyarg,
-                                  YYSIZEOF (yyarg) / YYSIZEOF (*yyarg));
-    if (yyn == -2)
-      return 2;
-    else
-      yycount = yyn;
-  }
+  /* Actual size of YYARG. */
+  int yycount
+    = yysyntax_error_arguments (yyctx, yyarg, YYERROR_VERBOSE_ARGS_MAXIMUM);
+  if (yycount == -2)
+    return 2;
 
   switch (yycount)
     {
