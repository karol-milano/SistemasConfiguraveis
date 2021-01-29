@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.5.2.140-15e57-dirty.  */
+/* A Bison parser, made by GNU Bison 3.5.3.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.5.2.140-15e57-dirty"
+#define YYBISON_VERSION "3.5.3"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -922,7 +922,8 @@ do {                                                                      \
 `-----------------------------------*/
 
 static void
-yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
+yy_symbol_value_print (FILE *yyo,
+                       int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 {
   FILE *yyoutput = yyo;
   YYUSE (yyoutput);
@@ -1132,7 +1133,8 @@ troff (yyo);
 `---------------------------*/
 
 static void
-yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
+yy_symbol_print (FILE *yyo,
+                 int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 {
   YYFPRINTF (yyo, "%s %s (",
              yytype < YYNTOKENS ? "token" : "nterm", yysymbol_name (yytype));
@@ -1172,7 +1174,8 @@ do {                                                            \
 `------------------------------------------------*/
 
 static void
-yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
+yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
+                 int yyrule)
 {
   int yylno = yyrline[yyrule];
   int yynrhs = yyr2[yyrule];
@@ -1224,6 +1227,7 @@ int yydebug;
 # define YYMAXDEPTH 10000
 #endif
 
+
 /* Given a state stack such that *YYBOTTOM is its bottom, such that
    *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
    stack, and such that *YYCAPACITY is the maximum number of elements it
@@ -1311,23 +1315,22 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
    current lookahead, then check if that lookahead can eventually be
    shifted if syntactic actions continue from the current context.
    Report a syntax error if it cannot.  */
-#define YY_LAC_ESTABLISH                                         \
-do {                                                             \
-  if (!yy_lac_established)                                       \
-    {                                                            \
-      YYDPRINTF ((stderr,                                        \
-                  "LAC: initial context established for %s\n",   \
-                  yysymbol_name (yytoken)));                     \
-      yy_lac_established = 1;                                    \
-      {                                                          \
-        int yy_lac_status =                                      \
-          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
-        if (yy_lac_status == 2)                                  \
-          goto yyexhaustedlab;                                   \
-        if (yy_lac_status == 1)                                  \
-          goto yyerrlab;                                         \
-      }                                                          \
-    }                                                            \
+#define YY_LAC_ESTABLISH                                                \
+do {                                                                    \
+  if (!yy_lac_established)                                              \
+    {                                                                   \
+      YYDPRINTF ((stderr,                                               \
+                  "LAC: initial context established for %s\n",          \
+                  yysymbol_name (yytoken)));                            \
+      yy_lac_established = 1;                                           \
+      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
+        {                                                               \
+        case 2:                                                         \
+          goto yyexhaustedlab;                                          \
+        case 1:                                                         \
+          goto yyerrlab;                                                \
+        }                                                               \
+    }                                                                   \
 } while (0)
 
 /* Discard any previous initial lookahead context because of Event,
@@ -1468,14 +1471,15 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
     }
 }
 
+/* Context of a parse error.  */
 typedef struct
 {
   yy_state_t *yyssp;
+  yy_state_t *yyesa;
+  yy_state_t **yyes;
+  YYPTRDIFF_T *yyes_capacity;
   int yytoken;
   YYLTYPE *yylloc;
-  yy_state_t *yyesa;
-  yy_state_t **yyes_p;
-  YYPTRDIFF_T *yyes_capacity_p;
 } yyparse_context_t;
 
 /* Put in YYARG at most YYARGN of the expected tokens given the
@@ -1492,25 +1496,25 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
   int yyx;
   for (yyx = 0; yyx < YYNTOKENS; ++yyx)
     if (yyx != YYTERROR && yyx != YYUNDEFTOK)
-      {
+      switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yyx))
         {
-          int yy_lac_status = yy_lac (yyctx->yyesa, yyctx->yyes_p, yyctx->yyes_capacity_p,
-                                      yyctx->yyssp, yyx);
-          if (yy_lac_status == 2)
-            return -2;
-          if (yy_lac_status == 1)
-            continue;
+        case 2:
+          return -2;
+        case 1:
+          continue;
+        default:
+          if (!yyarg)
+            ++yycount;
+          else if (yycount == yyargn)
+            return 0;
+          else
+            yyarg[yycount++] = yyx;
         }
-        if (!yyarg)
-          ++yycount;
-        else if (yycount == yyargn)
-          return 0;
-        else
-          yyarg[yycount++] = yyx;
-      }
   return yycount;
 }
 
+
+
 static int
 yysyntax_error_arguments (const yyparse_context_t *yyctx,
                           int yyarg[], int yyargn)
@@ -1565,14 +1569,16 @@ yyparse_context_location (const yyparse_context_t *yyctx)
 }
 
 /* User defined function to report a syntax error.  */
-static int yyreport_syntax_error (const yyparse_context_t *yyctx);
+static int
+yyreport_syntax_error (const yyparse_context_t *yyctx);
 
 /*-----------------------------------------------.
 | Release the memory associated to this symbol.  |
 `-----------------------------------------------*/
 
 static void
-yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
+yydestruct (const char *yymsg,
+            int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
 {
   YYUSE (yyvaluep);
   YYUSE (yylocationp);
@@ -1628,6 +1634,8 @@ yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocatio
 
 
 
+
+
 /*----------.
 | yyparse.  |
 `----------*/
@@ -1668,6 +1676,9 @@ YYLTYPE yylloc = yyloc_default;
        Refer to the stacks through separate pointers, to allow yyoverflow
        to reallocate them elsewhere.  */
 
+    /* Their size.  */
+    YYPTRDIFF_T yystacksize;
+
     /* The state stack.  */
     yy_state_t yyssa[YYINITDEPTH];
     yy_state_t *yyss;
@@ -1683,11 +1694,6 @@ YYLTYPE yylloc = yyloc_default;
     YYLTYPE *yyls;
     YYLTYPE *yylsp;
 
-    /* The locations where the error started and ended.  */
-    YYLTYPE yyerror_range[3];
-
-    YYPTRDIFF_T yystacksize;
-
     yy_state_t yyesa[20];
     yy_state_t *yyes;
     YYPTRDIFF_T yyes_capacity;
@@ -1704,6 +1710,9 @@ YYLTYPE yylloc = yyloc_default;
   YYSTYPE yyval;
   YYLTYPE yyloc;
 
+  /* The locations where the error started and ended.  */
+  YYLTYPE yyerror_range[3];
+
 
 
 #define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))
@@ -1712,21 +1721,23 @@ YYLTYPE yylloc = yyloc_default;
      Keep to zero when no symbol should be popped.  */
   int yylen = 0;
 
+  yynerrs = 0;
+  yystate = 0;
+  yyerrstatus = 0;
+
+  yystacksize = YYINITDEPTH;
   yyssp = yyss = yyssa;
   yyvsp = yyvs = yyvsa;
   yylsp = yyls = yylsa;
-  yystacksize = YYINITDEPTH;
 
   yyes = yyesa;
   yyes_capacity = 20;
   if (YYMAXDEPTH < yyes_capacity)
     yyes_capacity = YYMAXDEPTH;
 
+
   YYDPRINTF ((stderr, "Starting parse\n"));
 
-  yystate = 0;
-  yyerrstatus = 0;
-  yynerrs = 0;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
@@ -2534,7 +2545,7 @@ yyerrlab:
       ++yynerrs;
       {
         yyparse_context_t yyctx
-          = {yyssp, yytoken, &yylloc, yyesa, &yyes, &yyes_capacity};
+          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken, &yylloc};
         if (yychar != YYEMPTY)
           YY_LAC_ESTABLISH;
         if (yyreport_syntax_error (&yyctx) == 2)
@@ -2699,6 +2710,7 @@ yyreturn:
 }
 
 
+
 int
 yyreport_syntax_error (const yyparse_context_t *ctx)
 {
