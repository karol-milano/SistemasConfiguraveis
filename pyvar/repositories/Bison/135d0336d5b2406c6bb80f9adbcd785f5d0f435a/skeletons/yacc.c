@@ -1058,7 +1058,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
 
 static int
 yysyntax_error_arguments (const yyparse_context_t *yyctx,
-                          const char *yyarg[], int yyargn)
+                          int yyarg[], int yyargn)
 {
   /* Actual size of YYARG. */
   int yycount = 0;
@@ -1094,7 +1094,7 @@ yysyntax_error_arguments (const yyparse_context_t *yyctx,
     {
       int yyn = yypact[+*yyctx->yyssp];]b4_lac_if([[
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
-      yyarg[yycount++] = yytname[yyctx->yytoken];
+      yyarg[yycount++] = yyctx->yytoken;
       if (!yypact_value_is_default (yyn))
         {]b4_lac_if([[
           int yyx;
@@ -1126,7 +1126,7 @@ yysyntax_error_arguments (const yyparse_context_t *yyctx,
                     yycount = 1;
                     break;
                   }
-                yyarg[yycount++] = yytname[yyx];
+                yyarg[yycount++] = yyx;
               }
         }]b4_lac_if([[
       else
@@ -1244,7 +1244,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
   const char *yyformat = YY_NULLPTR;
   /* Arguments of yyformat: reported tokens (one for the "unexpected",
      one per "expected"). */
-  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
+  int yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
   /* Actual size of YYARG. */
   int yycount = 0;
   /* Cumulated lengths of YYARG.  */
@@ -1283,7 +1283,8 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
     int yyi;
     for (yyi = 0; yyi < yycount; ++yyi)
       {
-        YYPTRDIFF_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yyarg[yyi]);
+        YYPTRDIFF_T yysize1
+          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
         if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
           yysize = yysize1;
         else
@@ -1309,7 +1310,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
     while ((*yyp = *yyformat) != '\0')
       if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
         {
-          yyp += yytnamerr (yyp, yyarg[yyi++]);
+          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
           yyformat += 2;
         }
       else
