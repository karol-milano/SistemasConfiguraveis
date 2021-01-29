@@ -895,7 +895,7 @@ static const yytype_int8 yyr2[] =
 };
 
 
-enum { YYNOMEM = -2 };
+enum { YYENOMEM = -2 };
 
 #define yyerrok         (yyerrstatus = 0)
 #define yyclearin       (yychar = YYEMPTY)
@@ -1349,7 +1349,7 @@ int yydebug;
    *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
    location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
    using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
-   required.  Return YYNOMEM if memory is exhausted.  */
+   required.  Return YYENOMEM if memory is exhausted.  */
 static int
 yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
 #if GRAM_DEBUG
@@ -1374,7 +1374,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
         {
           YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                       yydebug_suffix));
-          return YYNOMEM;
+          return YYENOMEM;
         }
       if (YYMAXDEPTH < yyalloc)
         yyalloc = YYMAXDEPTH;
@@ -1386,7 +1386,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
         {
           YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                       yydebug_suffix));
-          return YYNOMEM;
+          return YYENOMEM;
         }
       if (*yytop != yytop_empty)
         {
@@ -1437,7 +1437,7 @@ do {                                                                    \
       yy_lac_established = 1;                                           \
       switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
         {                                                               \
-        case YYNOMEM:                                                   \
+        case YYENOMEM:                                                  \
           goto yyexhaustedlab;                                          \
         case 1:                                                         \
           goto yyerrlab;                                                \
@@ -1472,7 +1472,7 @@ do {                                                                     \
 
 /* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
    eventually (after perhaps some reductions) be shifted, return 1 if
-   not, or return YYNOMEM if memory is exhausted.  As preconditions and
+   not, or return YYENOMEM if memory is exhausted.  As preconditions and
    postconditions: *YYES_CAPACITY is the allocated size of the array to
    which *YYES points, and either *YYES = YYESA or *YYES points to an
    array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
@@ -1572,7 +1572,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
                                       yyes, yyesa, &yyesp, yyes_prev))
               {
                 YYDPRINTF ((stderr, "\n"));
-                return YYNOMEM;
+                return YYENOMEM;
               }
             YY_IGNORE_USELESS_CAST_BEGIN
             *++yyesp = YY_CAST (yy_state_t, yystate);
@@ -1597,7 +1597,7 @@ typedef struct
 /* Put in YYARG at most YYARGN of the expected tokens given the
    current YYCTX, and return the number of tokens stored in YYARG.  If
    YYARG is null, return the number of expected tokens (guaranteed to
-   be less than YYNTOKENS).  Return YYNOMEM on memory exhaustion.
+   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
    Return 0 if there are more than YYARGN expected tokens, yet fill
    YYARG up to YYARGN. */
 static int
@@ -1614,8 +1614,8 @@ yyexpected_tokens (const yypcontext_t *yyctx,
       if (yysym != YYSYMBOL_YYERROR && yysym != YYSYMBOL_YYUNDEF)
         switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
           {
-          case YYNOMEM:
-            return YYNOMEM;
+          case YYENOMEM:
+            return YYENOMEM;
           case 1:
             continue;
           default:
