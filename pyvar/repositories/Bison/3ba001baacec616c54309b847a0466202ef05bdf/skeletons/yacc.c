@@ -398,6 +398,7 @@ m4_if(b4_api_prefix, [yy], [],
                                 [/* Use api.header.include to #include this header
    instead of duplicating it here.  */
 ])b4_shared_declarations])[
+]b4_declare_symbol_enum[
 
 ]b4_user_post_prologue[
 ]b4_percent_code_get[]dnl
@@ -624,7 +625,6 @@ union yyalloc
 /* YYNSTATES -- Number of states.  */
 #define YYNSTATES  ]b4_states_number[
 
-#define YYUNDEFTOK  ]b4_undef_token_number[
 #define YYMAXUTOK   ]b4_user_token_number_max[
 
 
@@ -633,7 +633,7 @@ union yyalloc
 ]b4_api_token_raw_if(dnl
 [[#define YYTRANSLATE(YYX) (YYX)]],
 [[#define YYTRANSLATE(YYX)                                                \
-  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
+  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYSYMBOL_YYUNDEF)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex.  */
@@ -738,8 +738,6 @@ enum { YYNOMEM = -2 };
       }                                                           \
   while (0)
 
-/* Error symbol internal number. */
-#define YYTERROR        1
 /* Error token external number. */
 #define YYERRCODE       ]b4_symbol(1, user_number)[
 
@@ -1021,7 +1019,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
   yy_state_t *yyesp = yyes_prev;
   /* Reduce until we encounter a shift and thereby accept the token.  */
   YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
-  if (yytoken == YYUNDEFTOK)
+  if (yytoken == YYSYMBOL_YYUNDEF)
     {
       YYDPRINTF ((stderr, " Always Err\n"));
       return 1;
@@ -1149,7 +1147,7 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
 ]b4_lac_if([[
   int yyx;
   for (yyx = 0; yyx < YYNTOKENS; ++yyx)
-    if (yyx != YYTERROR && yyx != YYUNDEFTOK)
+    if (yyx != YYSYMBOL_error && yyx != YYSYMBOL_YYUNDEF)
       switch (yy_lac (]b4_push_if([[yyps->yyesa, &yyps->yyes, &yyps->yyes_capacity, yyps->yyssp, yyx]],
                                   [[yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yyx]])[))
         {
@@ -1177,7 +1175,7 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
       int yyx;
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-        if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
+        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_error
             && !yytable_value_is_error (yytable[yyx + yyn]))
           {
             if (!yyarg)
@@ -1729,7 +1727,7 @@ yybackup:
 
   /* Not known => get a lookahead token if don't already have one.  */
 
-  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
+  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
   if (yychar == YYEMPTY)
     {]b4_push_if([[
       if (!yyps->yynew)
@@ -1757,7 +1755,8 @@ yyread_pushed_token:]])[
 
   if (yychar <= YYEOF)
     {
-      yychar = yytoken = YYEOF;
+      yychar = YYEOF;
+      yytoken = YYSYMBOL_YYEOF;
       YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
   else
@@ -1999,8 +1998,8 @@ yyerrlab1:
       yyn = yypact[yystate];
       if (!yypact_value_is_default (yyn))
         {
-          yyn += YYTERROR;
-          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
+          yyn += YYSYMBOL_error;
+          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_error)
             {
               yyn = yytable[yyn];
               if (0 < yyn)
