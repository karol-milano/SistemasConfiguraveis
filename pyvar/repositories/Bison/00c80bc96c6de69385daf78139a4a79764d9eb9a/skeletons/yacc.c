@@ -637,7 +637,7 @@ union yyalloc
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex.  */
-static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
+static const yysymbol_type_t yytranslate[] =
 {
   ]b4_translate[
 };]])[
@@ -650,7 +650,7 @@ static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
 #if ]b4_parse_error_case([simple], [b4_api_PREFIX[DEBUG || ]b4_token_table_flag], [[1]])[
 /* The user-facing name of the symbol whose (internal) number is
    YYSYMBOL.  No bounds checking.  */
-static const char *yysymbol_name (int yysymbol) YY_ATTRIBUTE_UNUSED;
+static const char *yysymbol_name (yysymbol_type_t yysymbol) YY_ATTRIBUTE_UNUSED;
 
 ]b4_parse_error_bmatch([simple\|verbose],
 [[/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
@@ -661,12 +661,12 @@ static const char *const yytname[] =
 };
 
 static const char *
-yysymbol_name (int yysymbol)
+yysymbol_name (yysymbol_type_t yysymbol)
 {
   return yytname[yysymbol];
 }]],
 [[static const char *
-yysymbol_name (int yysymbol)
+yysymbol_name (yysymbol_type_t yysymbol)
 {
   static const char *const yy_sname[] =
   {
@@ -1013,7 +1013,7 @@ do {                                                                     \
    any old *YYES other than YYESA.  */
 static int
 yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
-        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, int yytoken)
+        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_type_t yytoken)
 {
   yy_state_t *yyes_prev = yyssp;
   yy_state_t *yyesp = yyes_prev;
@@ -1125,7 +1125,7 @@ typedef struct
   yy_state_t *yyesa;
   yy_state_t **yyes;
   YYPTRDIFF_T *yyes_capacity;]])])[
-  int yytoken;]b4_locations_if([[
+  yysymbol_type_t yytoken;]b4_locations_if([[
   YYLTYPE *yylloc;]])[
 } yyparse_context_t;
 
@@ -1137,10 +1137,10 @@ typedef struct
    YYARG up to YYARGN. */]b4_push_if([[
 static int
 yypstate_expected_tokens (yypstate *yyps,
-                          int yyarg[], int yyargn)]], [[
+                          yysymbol_type_t yyarg[], int yyargn)]], [[
 static int
 yyexpected_tokens (const yyparse_context_t *yyctx,
-                   int yyarg[], int yyargn)]])[
+                   yysymbol_type_t yyarg[], int yyargn)]])[
 {
   /* Actual size of YYARG. */
   int yycount = 0;
@@ -1193,7 +1193,7 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
 /* Similar to the previous function.  */
 static int
 yyexpected_tokens (const yyparse_context_t *yyctx,
-                   int yyarg[], int yyargn)
+                   yysymbol_type_t yyarg[], int yyargn)
 {
   return yypstate_expected_tokens (yyctx->yyps, yyarg, yyargn);
 }]])[
@@ -1202,10 +1202,10 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
 ]b4_parse_error_bmatch(
          [custom],
 [[/* The token type of the lookahead of this context.  */
-static int
+static yysymbol_type_t
 yyparse_context_token (const yyparse_context_t *yyctx) YY_ATTRIBUTE_UNUSED;
 
-static int
+static yysymbol_type_t
 yyparse_context_token (const yyparse_context_t *yyctx)
 {
   return yyctx->yytoken;
@@ -1316,7 +1316,7 @@ yytnamerr (char *yyres, const char *yystr)
 
 static int
 yysyntax_error_arguments (const yyparse_context_t *yyctx,
-                          int yyarg[], int yyargn)
+                          yysymbol_type_t yyarg[], int yyargn)
 {
   /* Actual size of YYARG. */
   int yycount = 0;
@@ -1383,7 +1383,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
   const char *yyformat = YY_NULLPTR;
   /* Arguments of yyformat: reported tokens (one for the "unexpected",
      one per "expected"). */
-  int yyarg[YYARGS_MAX];
+  yysymbol_type_t yyarg[YYARGS_MAX];
   /* Cumulated lengths of YYARG.  */
   YYPTRDIFF_T yysize = 0;
 
@@ -1576,7 +1576,7 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])[
   /* The return value of yyparse.  */
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
-  int yytoken = 0;
+  yysymbol_type_t yytoken = 0;
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;]b4_locations_if([[
