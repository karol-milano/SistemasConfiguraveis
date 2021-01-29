@@ -711,7 +711,7 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 
 ]b4_parser_tables_define[
 
-enum { YYNOMEM = -2 };
+enum { YYENOMEM = -2 };
 
 #define yyerrok         (yyerrstatus = 0)
 #define yyclearin       (yychar = YYEMPTY)
@@ -882,7 +882,7 @@ static char yypstate_allocated = 0;]])])[
    *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
    location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
    using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
-   required.  Return YYNOMEM if memory is exhausted.  */
+   required.  Return YYENOMEM if memory is exhausted.  */
 static int
 yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
 #if ]b4_api_PREFIX[DEBUG
@@ -907,7 +907,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
         {
           YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                       yydebug_suffix));
-          return YYNOMEM;
+          return YYENOMEM;
         }
       if (YYMAXDEPTH < yyalloc)
         yyalloc = YYMAXDEPTH;
@@ -919,7 +919,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
         {
           YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                       yydebug_suffix));
-          return YYNOMEM;
+          return YYENOMEM;
         }
       if (*yytop != yytop_empty)
         {
@@ -975,7 +975,7 @@ do {                                                                    \
       yy_lac_established = 1;                                           \
       switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
         {                                                               \
-        case YYNOMEM:                                                   \
+        case YYENOMEM:                                                  \
           goto yyexhaustedlab;                                          \
         case 1:                                                         \
           goto yyerrlab;                                                \
@@ -1010,7 +1010,7 @@ do {                                                                     \
 
 /* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
    eventually (after perhaps some reductions) be shifted, return 1 if
-   not, or return YYNOMEM if memory is exhausted.  As preconditions and
+   not, or return YYENOMEM if memory is exhausted.  As preconditions and
    postconditions: *YYES_CAPACITY is the allocated size of the array to
    which *YYES points, and either *YYES = YYESA or *YYES points to an
    array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
@@ -1110,7 +1110,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
                                       yyes, yyesa, &yyesp, yyes_prev))
               {
                 YYDPRINTF ((stderr, "\n"));
-                return YYNOMEM;
+                return YYENOMEM;
               }
             YY_IGNORE_USELESS_CAST_BEGIN
             *++yyesp = YY_CAST (yy_state_t, yystate);
@@ -1137,7 +1137,7 @@ typedef struct
 /* Put in YYARG at most YYARGN of the expected tokens given the
    current YYCTX, and return the number of tokens stored in YYARG.  If
    YYARG is null, return the number of expected tokens (guaranteed to
-   be less than YYNTOKENS).  Return YYNOMEM on memory exhaustion.
+   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
    Return 0 if there are more than YYARGN expected tokens, yet fill
    YYARG up to YYARGN. */]b4_push_if([[
 static int
@@ -1158,8 +1158,8 @@ yyexpected_tokens (const yypcontext_t *yyctx,
         switch (yy_lac (]b4_push_if([[yyps->yyesa, &yyps->yyes, &yyps->yyes_capacity, yyps->yyssp, yysym]],
                                     [[yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym]])[))
           {
-          case YYNOMEM:
-            return YYNOMEM;
+          case YYENOMEM:
+            return YYENOMEM;
           case 1:
             continue;
           default:
@@ -1364,8 +1364,8 @@ yy_syntax_error_arguments (const yypcontext_t *yyctx,
         yyarg[yycount] = yyctx->yytoken;
       ++yycount;
       yyn = yyexpected_tokens (yyctx, yyarg ? yyarg + 1 : yyarg, yyargn - 1);
-      if (yyn == YYNOMEM)
-        return YYNOMEM;]b4_lac_if([[
+      if (yyn == YYENOMEM)
+        return YYENOMEM;]b4_lac_if([[
       else if (yyn == 0)
         YYDPRINTF ((stderr, "No expected tokens.\n"));]])[
       else
@@ -1381,9 +1381,9 @@ yy_syntax_error_arguments (const yypcontext_t *yyctx,
 
    Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
    not large enough to hold the message.  In that case, also set
-   *YYMSG_ALLOC to the required number of bytes.  Return YYNOMEM if the
+   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
    required number of bytes is too large to store]b4_lac_if([[ or if
-   yy_lac returned YYNOMEM]])[.  */
+   yy_lac returned YYENOMEM]])[.  */
 static int
 yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                 const yypcontext_t *yyctx)
@@ -1399,8 +1399,8 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
 
   /* Actual size of YYARG. */
   int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
-  if (yycount == YYNOMEM)
-    return YYNOMEM;
+  if (yycount == YYENOMEM)
+    return YYENOMEM;
 
   switch (yycount)
     {
@@ -1432,7 +1432,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
         if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
           yysize = yysize1;
         else
-          return YYNOMEM;
+          return YYENOMEM;
       }
   }
 
@@ -1944,11 +1944,11 @@ yyerrlab:
               {
                 yymsg = yymsgbuf;
                 yymsg_alloc = sizeof yymsgbuf;
-                yysyntax_error_status = YYNOMEM;
+                yysyntax_error_status = YYENOMEM;
               }
           }
         yyerror (]b4_yyerror_args[yymsgp);
-        if (yysyntax_error_status == YYNOMEM)
+        if (yysyntax_error_status == YYENOMEM)
           goto yyexhaustedlab;
       }]])[
     }
