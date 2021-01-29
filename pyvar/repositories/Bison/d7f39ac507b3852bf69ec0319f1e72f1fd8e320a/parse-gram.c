@@ -103,6 +103,7 @@
 /* Symbol type.  */
 enum yysymbol_type_t
 {
+  YYSYMBOL_YYEMPTY = -2,
   YYSYMBOL_YYEOF = 0,
   YYSYMBOL_error = 1,
   YYSYMBOL_YYUNDEF = 2,
@@ -620,10 +621,10 @@ static const yytype_int16 yyrline[] =
 #if 1
 /* The user-facing name of the symbol whose (internal) number is
    YYSYMBOL.  No bounds checking.  */
-static const char *yysymbol_name (int yysymbol) YY_ATTRIBUTE_UNUSED;
+static const char *yysymbol_name (yysymbol_type_t yysymbol) YY_ATTRIBUTE_UNUSED;
 
 static const char *
-yysymbol_name (int yysymbol)
+yysymbol_name (yysymbol_type_t yysymbol)
 {
   static const char *const yy_sname[] =
   {
@@ -1464,7 +1465,7 @@ do {                                                                     \
    any old *YYES other than YYESA.  */
 static int
 yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
-        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, int yytoken)
+        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_type_t yytoken)
 {
   yy_state_t *yyes_prev = yyssp;
   yy_state_t *yyesp = yyes_prev;
@@ -1574,7 +1575,7 @@ typedef struct
   yy_state_t *yyesa;
   yy_state_t **yyes;
   YYPTRDIFF_T *yyes_capacity;
-  int yytoken;
+  yysymbol_type_t yytoken;
   YYLTYPE *yylloc;
 } yyparse_context_t;
 
@@ -1586,7 +1587,7 @@ typedef struct
    YYARG up to YYARGN. */
 static int
 yyexpected_tokens (const yyparse_context_t *yyctx,
-                   int yyarg[], int yyargn)
+                   yysymbol_type_t yyarg[], int yyargn)
 {
   /* Actual size of YYARG. */
   int yycount = 0;
@@ -1615,10 +1616,10 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
 
 
 /* The token type of the lookahead of this context.  */
-static int
+static yysymbol_type_t
 yyparse_context_token (const yyparse_context_t *yyctx) YY_ATTRIBUTE_UNUSED;
 
-static int
+static yysymbol_type_t
 yyparse_context_token (const yyparse_context_t *yyctx)
 {
   return yyctx->yytoken;
@@ -1770,7 +1771,7 @@ YYLTYPE yylloc = yyloc_default;
   /* The return value of yyparse.  */
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
-  int yytoken = 0;
+  yysymbol_type_t yytoken = YYSYMBOL_YYEMPTY;
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;
@@ -2604,7 +2605,7 @@ yyreduce:
 yyerrlab:
   /* Make sure we have latest lookahead translation.  See comments at
      user semantic actions for why this is necessary.  */
-  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
+  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
 
   /* If not already recovering from an error, report this error.  */
   if (!yyerrstatus)
@@ -2787,11 +2788,11 @@ yyreport_syntax_error (const yyparse_context_t *ctx)
   enum { ARGS_MAX = 5 };
   const char *argv[ARGS_MAX];
   int argc = 0;
-  int unexpected = yyparse_context_token (ctx);
-  if (unexpected != YYEMPTY)
+  yysymbol_type_t unexpected = yyparse_context_token (ctx);
+  if (unexpected != YYSYMBOL_YYEMPTY)
     {
       argv[argc++] = yysymbol_name (unexpected);
-      int expected[ARGS_MAX - 1];
+      yysymbol_type_t expected[ARGS_MAX - 1];
       int nexpected = yyexpected_tokens (ctx, expected, ARGS_MAX - 1);
       if (nexpected < 0)
         res = nexpected;
