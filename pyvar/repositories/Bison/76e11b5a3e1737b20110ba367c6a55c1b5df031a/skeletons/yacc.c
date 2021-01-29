@@ -1132,7 +1132,7 @@ typedef struct
   YYPTRDIFF_T *yyes_capacity;]])])[
   yysymbol_type_t yytoken;]b4_locations_if([[
   YYLTYPE *yylloc;]])[
-} yyparse_context_t;
+} yypcontext_t;
 
 /* Put in YYARG at most YYARGN of the expected tokens given the
    current YYCTX, and return the number of tokens stored in YYARG.  If
@@ -1144,7 +1144,7 @@ static int
 yypstate_expected_tokens (yypstate *yyps,
                           yysymbol_type_t yyarg[], int yyargn)]], [[
 static int
-yyexpected_tokens (const yyparse_context_t *yyctx,
+yyexpected_tokens (const yypcontext_t *yyctx,
                    yysymbol_type_t yyarg[], int yyargn)]])[
 {
   /* Actual size of YYARG. */
@@ -1200,7 +1200,7 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
 ]b4_push_if([[
 /* Similar to the previous function.  */
 static int
-yyexpected_tokens (const yyparse_context_t *yyctx,
+yyexpected_tokens (const yypcontext_t *yyctx,
                    yysymbol_type_t yyarg[], int yyargn)
 {
   return yypstate_expected_tokens (yyctx->yyps, yyarg, yyargn);
@@ -1211,27 +1211,27 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
          [custom],
 [[/* The token type of the lookahead of this context.  */
 static yysymbol_type_t
-yyparse_context_token (const yyparse_context_t *yyctx) YY_ATTRIBUTE_UNUSED;
+yypcontext_token (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;
 
 static yysymbol_type_t
-yyparse_context_token (const yyparse_context_t *yyctx)
+yypcontext_token (const yypcontext_t *yyctx)
 {
   return yyctx->yytoken;
 }
 
 ]b4_locations_if([[/* The location of the lookahead of this context.  */
 static YYLTYPE *
-yyparse_context_location (const yyparse_context_t *yyctx) YY_ATTRIBUTE_UNUSED;
+yypcontext_location (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;
 
 static YYLTYPE *
-yyparse_context_location (const yyparse_context_t *yyctx)
+yypcontext_location (const yypcontext_t *yyctx)
 {
   return yyctx->yylloc;
 }]])[
 
 /* User defined function to report a syntax error.  */
 static int
-yyreport_syntax_error (const yyparse_context_t *yyctx]b4_user_formals[);]],
+yyreport_syntax_error (const yypcontext_t *yyctx]b4_user_formals[);]],
          [detailed\|verbose],
 [[#ifndef yystrlen
 # if defined __GLIBC__ && defined _STRING_H
@@ -1323,7 +1323,7 @@ yytnamerr (char *yyres, const char *yystr)
 ]])[
 
 static int
-yysyntax_error_arguments (const yyparse_context_t *yyctx,
+yysyntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_type_t yyarg[], int yyargn)
 {
   /* Actual size of YYARG. */
@@ -1384,7 +1384,7 @@ yysyntax_error_arguments (const yyparse_context_t *yyctx,
    yy_lac returned YYNOMEM]])[.  */
 static int
 yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
-                const yyparse_context_t *yyctx)
+                const yypcontext_t *yyctx)
 {
   enum { YYARGS_MAX = 5 };
   /* Internationalized format string. */
@@ -1906,7 +1906,7 @@ yyerrlab:
 ]b4_parse_error_case(
          [custom],
 [[      {
-        yyparse_context_t yyctx
+        yypcontext_t yyctx
           = {]b4_push_if([[yyps]], [[yyssp]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])])[, yytoken]b4_locations_if([[, &yylloc]])[};]b4_lac_if([[
         if (yychar != YYEMPTY)
           YY_LAC_ESTABLISH;]])[
@@ -1917,7 +1917,7 @@ yyerrlab:
          [simple],
 [[      yyerror (]b4_yyerror_args[YY_("syntax error"));]],
 [[      {
-        yyparse_context_t yyctx
+        yypcontext_t yyctx
           = {]b4_push_if([[yyps]], [[yyssp]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])])[, yytoken]b4_locations_if([[, &yylloc]])[};
         char const *yymsgp = YY_("syntax error");
         int yysyntax_error_status;]b4_lac_if([[
