@@ -706,6 +706,8 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 
 ]b4_parser_tables_define[
 
+enum { YYNOMEM = -2 };
+
 #define yyerrok         (yyerrstatus = 0)
 #define yyclearin       (yychar = YYEMPTY)
 #define YYEMPTY         (-2)
@@ -877,7 +879,7 @@ static char yypstate_allocated = 0;]])])[
    *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
    location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
    using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
-   required.  Return -2 if memory is exhausted.  */
+   required.  Return YYNOMEM if memory is exhausted.  */
 static int
 yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
 #if ]b4_api_PREFIX[DEBUG
@@ -902,7 +904,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
         {
           YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                       yydebug_suffix));
-          return -2;
+          return YYNOMEM;
         }
       if (YYMAXDEPTH < yyalloc)
         yyalloc = YYMAXDEPTH;
@@ -914,7 +916,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
         {
           YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                       yydebug_suffix));
-          return -2;
+          return YYNOMEM;
         }
       if (*yytop != yytop_empty)
         {
@@ -970,7 +972,7 @@ do {                                                                    \
       yy_lac_established = 1;                                           \
       switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
         {                                                               \
-        case -2:                                                        \
+        case YYNOMEM:                                                   \
           goto yyexhaustedlab;                                          \
         case 1:                                                         \
           goto yyerrlab;                                                \
@@ -1005,7 +1007,7 @@ do {                                                                     \
 
 /* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
    eventually (after perhaps some reductions) be shifted, return 1 if
-   not, or return -2 if memory is exhausted.  As preconditions and
+   not, or return YYNOMEM if memory is exhausted.  As preconditions and
    postconditions: *YYES_CAPACITY is the allocated size of the array to
    which *YYES points, and either *YYES = YYESA or *YYES points to an
    array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
@@ -1105,7 +1107,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
                                       yyes, yyesa, &yyesp, yyes_prev))
               {
                 YYDPRINTF ((stderr, "\n"));
-                return -2;
+                return YYNOMEM;
               }
             YY_IGNORE_USELESS_CAST_BEGIN
             *++yyesp = YY_CAST (yy_state_t, yystate);
@@ -1132,9 +1134,9 @@ typedef struct
 /* Put in YYARG at most YYARGN of the expected tokens given the
    current YYCTX, and return the number of tokens stored in YYARG.  If
    YYARG is null, return the number of expected tokens (guaranteed to
-   be less than YYNTOKENS).  Return -2 on memory exhaustion.  Return 0
-   if there are more than YYARGN expected tokens, yet fill YYARG up to
-   YYARGN. */]b4_push_if([[
+   be less than YYNTOKENS).  Return YYNOMEM on memory exhaustion.
+   Return 0 if there are more than YYARGN expected tokens, yet fill
+   YYARG up to YYARGN. */]b4_push_if([[
 static int
 yypstate_expected_tokens (yypstate *yyps,
                           int yyarg[], int yyargn)]], [[
@@ -1151,8 +1153,8 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
       switch (yy_lac (]b4_push_if([[yyps->yyesa, &yyps->yyes, &yyps->yyes_capacity, yyps->yyssp, yyx]],
                                   [[yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yyx]])[))
         {
-        case -2:
-          return -2;
+        case YYNOMEM:
+          return YYNOMEM;
         case 1:
           continue;
         default:
@@ -1354,8 +1356,8 @@ yysyntax_error_arguments (const yyparse_context_t *yyctx,
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
       yyarg[yycount++] = yyctx->yytoken;
       yyn = yyexpected_tokens (yyctx, yyarg ? yyarg + 1 : yyarg, yyargn - 1);
-      if (yyn == -2)
-        return -2;]b4_lac_if([[
+      if (yyn == YYNOMEM)
+        return YYNOMEM;]b4_lac_if([[
       else if (yyn == 0)
         YYDPRINTF ((stderr, "No expected tokens.\n"));]])[
       else
@@ -1371,9 +1373,9 @@ yysyntax_error_arguments (const yyparse_context_t *yyctx,
 
    Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
    not large enough to hold the message.  In that case, also set
-   *YYMSG_ALLOC to the required number of bytes.  Return -2 if the
+   *YYMSG_ALLOC to the required number of bytes.  Return YYNOMEM if the
    required number of bytes is too large to store]b4_lac_if([[ or if
-   yy_lac returned -2]])[.  */
+   yy_lac returned YYNOMEM]])[.  */
 static int
 yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                 const yyparse_context_t *yyctx)
@@ -1389,8 +1391,8 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
 
   /* Actual size of YYARG. */
   int yycount = yysyntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
-  if (yycount == -2)
-    return -2;
+  if (yycount == YYNOMEM)
+    return YYNOMEM;
 
   switch (yycount)
     {
@@ -1422,7 +1424,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
         if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
           yysize = yysize1;
         else
-          return -2;
+          return YYNOMEM;
       }
   }
 
@@ -1933,11 +1935,11 @@ yyerrlab:
               {
                 yymsg = yymsgbuf;
                 yymsg_alloc = sizeof yymsgbuf;
-                yysyntax_error_status = -2;
+                yysyntax_error_status = YYNOMEM;
               }
           }
         yyerror (]b4_yyerror_args[yymsgp);
-        if (yysyntax_error_status == -2)
+        if (yysyntax_error_status == YYNOMEM)
           goto yyexhaustedlab;
       }]])[
     }
