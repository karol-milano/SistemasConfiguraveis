@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.6.3.87-3efc5-dirty.  */
+/* A Bison parser, made by GNU Bison 3.6.4.130-76c4d.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -49,7 +49,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.6.3.87-3efc5-dirty"
+#define YYBISON_VERSION "3.6.4.130-76c4d"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1767,41 +1767,36 @@ static YYLTYPE yyloc_default
 YYLTYPE yylloc = yyloc_default;
 
     /* Number of syntax errors so far.  */
-    int yynerrs;
+    int yynerrs = 0;
 
-    yy_state_fast_t yystate;
+    yy_state_fast_t yystate = 0;
     /* Number of tokens to shift before error messages enabled.  */
-    int yyerrstatus;
+    int yyerrstatus = 0;
 
-    /* The stacks and their tools:
-       'yyss': related to states.
-       'yyvs': related to semantic values.
-       'yyls': related to locations.
-
-       Refer to the stacks through separate pointers, to allow yyoverflow
+    /* Refer to the stacks through separate pointers, to allow yyoverflow
        to reallocate them elsewhere.  */
 
     /* Their size.  */
-    YYPTRDIFF_T yystacksize;
+    YYPTRDIFF_T yystacksize = YYINITDEPTH;
 
-    /* The state stack.  */
+    /* The state stack: array, bottom, top.  */
     yy_state_t yyssa[YYINITDEPTH];
-    yy_state_t *yyss;
-    yy_state_t *yyssp;
+    yy_state_t *yyss = yyssa;
+    yy_state_t *yyssp = yyss;
 
-    /* The semantic value stack.  */
+    /* The semantic value stack: array, bottom, top.  */
     YYSTYPE yyvsa[YYINITDEPTH];
-    YYSTYPE *yyvs;
-    YYSTYPE *yyvsp;
+    YYSTYPE *yyvs = yyvsa;
+    YYSTYPE *yyvsp = yyvs;
 
-    /* The location stack.  */
+    /* The location stack: array, bottom, top.  */
     YYLTYPE yylsa[YYINITDEPTH];
-    YYLTYPE *yyls;
-    YYLTYPE *yylsp;
+    YYLTYPE *yyls = yylsa;
+    YYLTYPE *yylsp = yyls;
 
     yy_state_t yyesa[20];
-    yy_state_t *yyes;
-    YYPTRDIFF_T yyes_capacity;
+    yy_state_t *yyes = yyesa;
+    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;
 
   /* Whether LAC context is established.  A Boolean.  */
   int yy_lac_established = 0;
@@ -1826,21 +1821,6 @@ YYLTYPE yylloc = yyloc_default;
      Keep to zero when no symbol should be popped.  */
   int yylen = 0;
 
-  yynerrs = 0;
-  yystate = 0;
-  yyerrstatus = 0;
-
-  yystacksize = YYINITDEPTH;
-  yyssp = yyss = yyssa;
-  yyvsp = yyvs = yyvsa;
-  yylsp = yyls = yylsa;
-
-  yyes = yyesa;
-  yyes_capacity = 20;
-  if (YYMAXDEPTH < yyes_capacity)
-    yyes_capacity = YYMAXDEPTH;
-
-
   YYDPRINTF ((stderr, "Starting parse\n"));
 
   yychar = GRAM_EMPTY; /* Cause a token to be read.  */
@@ -2784,13 +2764,13 @@ yyabortlab:
 yyexhaustedlab:
   yyerror (&yylloc, YY_("memory exhausted"));
   yyresult = 2;
-  /* Fall through.  */
+  goto yyreturn;
 #endif
 
 
-/*-----------------------------------------------------.
-| yyreturn -- parsing is finished, return the result.  |
-`-----------------------------------------------------*/
+/*-------------------------------------------------------.
+| yyreturn -- parsing is finished, clean up and return.  |
+`-------------------------------------------------------*/
 yyreturn:
   if (yychar != GRAM_EMPTY)
     {
