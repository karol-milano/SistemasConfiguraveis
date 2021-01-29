@@ -783,6 +783,8 @@ static const yytype_int8 yyr2[] =
 };
 
 
+enum { YYNOMEM = -2 };
+
 #define yyerrok         (yyerrstatus = 0)
 #define yyclearin       (yychar = YYEMPTY)
 #define YYEMPTY         (-2)
@@ -1237,7 +1239,7 @@ int yydebug;
    *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
    location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
    using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
-   required.  Return -2 if memory is exhausted.  */
+   required.  Return YYNOMEM if memory is exhausted.  */
 static int
 yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
 #if GRAM_DEBUG
@@ -1262,7 +1264,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
         {
           YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                       yydebug_suffix));
-          return -2;
+          return YYNOMEM;
         }
       if (YYMAXDEPTH < yyalloc)
         yyalloc = YYMAXDEPTH;
@@ -1274,7 +1276,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
         {
           YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                       yydebug_suffix));
-          return -2;
+          return YYNOMEM;
         }
       if (*yytop != yytop_empty)
         {
@@ -1325,7 +1327,7 @@ do {                                                                    \
       yy_lac_established = 1;                                           \
       switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
         {                                                               \
-        case -2:                                                        \
+        case YYNOMEM:                                                   \
           goto yyexhaustedlab;                                          \
         case 1:                                                         \
           goto yyerrlab;                                                \
@@ -1360,7 +1362,7 @@ do {                                                                     \
 
 /* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
    eventually (after perhaps some reductions) be shifted, return 1 if
-   not, or return -2 if memory is exhausted.  As preconditions and
+   not, or return YYNOMEM if memory is exhausted.  As preconditions and
    postconditions: *YYES_CAPACITY is the allocated size of the array to
    which *YYES points, and either *YYES = YYESA or *YYES points to an
    array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
@@ -1460,7 +1462,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
                                       yyes, yyesa, &yyesp, yyes_prev))
               {
                 YYDPRINTF ((stderr, "\n"));
-                return -2;
+                return YYNOMEM;
               }
             YY_IGNORE_USELESS_CAST_BEGIN
             *++yyesp = YY_CAST (yy_state_t, yystate);
@@ -1485,9 +1487,9 @@ typedef struct
 /* Put in YYARG at most YYARGN of the expected tokens given the
    current YYCTX, and return the number of tokens stored in YYARG.  If
    YYARG is null, return the number of expected tokens (guaranteed to
-   be less than YYNTOKENS).  Return -2 on memory exhaustion.  Return 0
-   if there are more than YYARGN expected tokens, yet fill YYARG up to
-   YYARGN. */
+   be less than YYNTOKENS).  Return YYNOMEM on memory exhaustion.
+   Return 0 if there are more than YYARGN expected tokens, yet fill
+   YYARG up to YYARGN. */
 static int
 yyexpected_tokens (const yyparse_context_t *yyctx,
                    int yyarg[], int yyargn)
@@ -1500,8 +1502,8 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
     if (yyx != YYTERROR && yyx != YYUNDEFTOK)
       switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yyx))
         {
-        case -2:
-          return -2;
+        case YYNOMEM:
+          return YYNOMEM;
         case 1:
           continue;
         default:
