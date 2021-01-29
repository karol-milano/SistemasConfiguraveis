@@ -1237,7 +1237,7 @@ int yydebug;
    *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
    location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
    using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
-   required.  Return 1 if memory is exhausted.  */
+   required.  Return -2 if memory is exhausted.  */
 static int
 yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
 #if GRAM_DEBUG
@@ -1262,7 +1262,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
         {
           YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                       yydebug_suffix));
-          return 1;
+          return -2;
         }
       if (YYMAXDEPTH < yyalloc)
         yyalloc = YYMAXDEPTH;
@@ -1274,7 +1274,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
         {
           YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                       yydebug_suffix));
-          return 1;
+          return -2;
         }
       if (*yytop != yytop_empty)
         {
@@ -1325,7 +1325,7 @@ do {                                                                    \
       yy_lac_established = 1;                                           \
       switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
         {                                                               \
-        case 2:                                                         \
+        case -2:                                                        \
           goto yyexhaustedlab;                                          \
         case 1:                                                         \
           goto yyerrlab;                                                \
@@ -1360,7 +1360,7 @@ do {                                                                     \
 
 /* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
    eventually (after perhaps some reductions) be shifted, return 1 if
-   not, or return 2 if memory is exhausted.  As preconditions and
+   not, or return -2 if memory is exhausted.  As preconditions and
    postconditions: *YYES_CAPACITY is the allocated size of the array to
    which *YYES points, and either *YYES = YYESA or *YYES points to an
    array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
@@ -1460,7 +1460,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
                                       yyes, yyesa, &yyesp, yyes_prev))
               {
                 YYDPRINTF ((stderr, "\n"));
-                return 2;
+                return -2;
               }
             YY_IGNORE_USELESS_CAST_BEGIN
             *++yyesp = YY_CAST (yy_state_t, yystate);
@@ -1485,7 +1485,9 @@ typedef struct
 /* Put in YYARG at most YYARGN of the expected tokens given the
    current YYCTX, and return the number of tokens stored in YYARG.  If
    YYARG is null, return the number of expected tokens (guaranteed to
-   be less than YYNTOKENS).  */
+   be less than YYNTOKENS).  Return -2 on memory exhaustion.  Return 0
+   if there are more than YYARGN expected tokens, yet fill YYARG up to
+   YYARGN. */
 static int
 yyexpected_tokens (const yyparse_context_t *yyctx,
                    int yyarg[], int yyargn)
@@ -1498,7 +1500,7 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
     if (yyx != YYTERROR && yyx != YYUNDEFTOK)
       switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yyx))
         {
-        case 2:
+        case -2:
           return -2;
         case 1:
           continue;
@@ -1515,6 +1517,10 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
 
 
 
+static int
+yysyntax_error_arguments (const yyparse_context_t *yyctx,
+                          int yyarg[], int yyargn) YY_ATTRIBUTE_UNUSED;
+
 static int
 yysyntax_error_arguments (const yyparse_context_t *yyctx,
                           int yyarg[], int yyargn)
@@ -1558,7 +1564,17 @@ yysyntax_error_arguments (const yyparse_context_t *yyctx,
 }
 
 
-/*  The location of this context.  */
+/* The token type of the lookahead of this context.  */
+static int
+yyparse_context_token (const yyparse_context_t *yyctx) YY_ATTRIBUTE_UNUSED;
+
+static int
+yyparse_context_token (const yyparse_context_t *yyctx)
+{
+  return yyctx->yytoken;
+}
+
+/* The location of the lookahead of this context.  */
 static YYLTYPE *
 yyparse_context_location (const yyparse_context_t *yyctx) YY_ATTRIBUTE_UNUSED;
 
@@ -2714,18 +2730,26 @@ yyreturn:
 int
 yyreport_syntax_error (const yyparse_context_t *ctx)
 {
-  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
+  int res = 0;
   /* Arguments of format: reported tokens (one for the "unexpected",
      one per "expected"). */
-  int arg[YYERROR_VERBOSE_ARGS_MAXIMUM];
-  int n = yysyntax_error_arguments (ctx, arg, YYERROR_VERBOSE_ARGS_MAXIMUM);
-  if (n == -2)
-    return 2;
-  const char *argv[YYERROR_VERBOSE_ARGS_MAXIMUM];
-  for (int i = 0; i < n; ++i)
-    argv[i] = yysymbol_name (arg[i]);
-  syntax_error (*yyparse_context_location (ctx), n, argv);
-  return 0;
+  enum { ARGS_MAX = 5 };
+  const char *argv[ARGS_MAX];
+  int argc = 0;
+  int unexpected = yyparse_context_token (ctx);
+  if (unexpected != YYEMPTY)
+    {
+      argv[argc++] = yysymbol_name (unexpected);
+      int expected[ARGS_MAX - 1];
+      int nexpected = yyexpected_tokens (ctx, expected, ARGS_MAX - 1);
+      if (nexpected < 0)
+        res = nexpected;
+      else
+        for (int i = 0; i < nexpected; ++i)
+          argv[argc++] = yysymbol_name (expected[i]);
+    }
+  syntax_error (*yyparse_context_location (ctx), argc, argv);
+  return res;
 }
 
 
