@@ -877,7 +877,7 @@ static char yypstate_allocated = 0;]])])[
    *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
    location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
    using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
-   required.  Return 1 if memory is exhausted.  */
+   required.  Return -2 if memory is exhausted.  */
 static int
 yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
 #if ]b4_api_PREFIX[DEBUG
@@ -902,7 +902,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
         {
           YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                       yydebug_suffix));
-          return 1;
+          return -2;
         }
       if (YYMAXDEPTH < yyalloc)
         yyalloc = YYMAXDEPTH;
@@ -914,7 +914,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
         {
           YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                       yydebug_suffix));
-          return 1;
+          return -2;
         }
       if (*yytop != yytop_empty)
         {
@@ -970,7 +970,7 @@ do {                                                                    \
       yy_lac_established = 1;                                           \
       switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
         {                                                               \
-        case 2:                                                         \
+        case -2:                                                        \
           goto yyexhaustedlab;                                          \
         case 1:                                                         \
           goto yyerrlab;                                                \
@@ -1005,7 +1005,7 @@ do {                                                                     \
 
 /* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
    eventually (after perhaps some reductions) be shifted, return 1 if
-   not, or return 2 if memory is exhausted.  As preconditions and
+   not, or return -2 if memory is exhausted.  As preconditions and
    postconditions: *YYES_CAPACITY is the allocated size of the array to
    which *YYES points, and either *YYES = YYESA or *YYES points to an
    array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
@@ -1105,7 +1105,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
                                       yyes, yyesa, &yyesp, yyes_prev))
               {
                 YYDPRINTF ((stderr, "\n"));
-                return 2;
+                return -2;
               }
             YY_IGNORE_USELESS_CAST_BEGIN
             *++yyesp = YY_CAST (yy_state_t, yystate);
@@ -1132,7 +1132,9 @@ typedef struct
 /* Put in YYARG at most YYARGN of the expected tokens given the
    current YYCTX, and return the number of tokens stored in YYARG.  If
    YYARG is null, return the number of expected tokens (guaranteed to
-   be less than YYNTOKENS).  */]b4_push_if([[
+   be less than YYNTOKENS).  Return -2 on memory exhaustion.  Return 0
+   if there are more than YYARGN expected tokens, yet fill YYARG up to
+   YYARGN. */]b4_push_if([[
 static int
 yypstate_expected_tokens (yypstate *yyps,
                           int yyarg[], int yyargn)]], [[
@@ -1149,7 +1151,7 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
       switch (yy_lac (]b4_push_if([[yyps->yyesa, &yyps->yyes, &yyps->yyes_capacity, yyps->yyssp, yyx]],
                                   [[yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yyx]])[))
         {
-        case 2:
+        case -2:
           return -2;
         case 1:
           continue;
@@ -1358,11 +1360,11 @@ yytnamerr (char *yyres, const char *yystr)
    YYSSP.]b4_lac_if([[  In order to see if a particular token T is a
    valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).]])[
 
-   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
+   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
    not large enough to hold the message.  In that case, also set
-   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
+   *YYMSG_ALLOC to the required number of bytes.  Return -2 if the
    required number of bytes is too large to store]b4_lac_if([[ or if
-   yy_lac returned 2]])[.  */
+   yy_lac returned -2]])[.  */
 static int
 yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                 const yyparse_context_t *yyctx)
@@ -1379,7 +1381,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
   /* Actual size of YYARG. */
   int yycount = yysyntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
   if (yycount == -2)
-    return 2;
+    return -2;
 
   switch (yycount)
     {
@@ -1411,7 +1413,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
         if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
           yysize = yysize1;
         else
-          return 2;
+          return -2;
       }
   }
 
@@ -1421,7 +1423,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
       if (! (yysize <= *yymsg_alloc
              && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
         *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
-      return 1;
+      return -1;
     }
 
   /* Avoid sprintf, as that infringes on the user's name space.
@@ -1906,7 +1908,7 @@ yyerrlab:
         yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
         if (yysyntax_error_status == 0)
           yymsgp = yymsg;
-        else if (yysyntax_error_status == 1)
+        else if (yysyntax_error_status == -1)
           {
             if (yymsg != yymsgbuf)
               YYSTACK_FREE (yymsg);
@@ -1922,11 +1924,11 @@ yyerrlab:
               {
                 yymsg = yymsgbuf;
                 yymsg_alloc = sizeof yymsgbuf;
-                yysyntax_error_status = 2;
+                yysyntax_error_status = -2;
               }
           }
         yyerror (]b4_yyerror_args[yymsgp);
-        if (yysyntax_error_status == 2)
+        if (yysyntax_error_status == -2)
           goto yyexhaustedlab;
       }]])[
     }
