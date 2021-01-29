@@ -631,10 +631,10 @@ union yyalloc
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
 ]b4_api_token_raw_if(dnl
-[[#define YYTRANSLATE(YYX) YY_CAST (yysymbol_type_t, YYX)]],
+[[#define YYTRANSLATE(YYX) YY_CAST (yysymbol_kind_t, YYX)]],
 [[#define YYTRANSLATE(YYX)                                \
   (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
-   ? YY_CAST (yysymbol_type_t, yytranslate[YYX])        \
+   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
    : YYSYMBOL_YYUNDEF)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
@@ -650,12 +650,12 @@ static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
 #endif
 
 /** Accessing symbol of state STATE.  */
-#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_type_t, yystos[State])
+#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])
 
 #if ]b4_parse_error_case([simple], [b4_api_PREFIX[DEBUG || ]b4_token_table_flag], [[1]])[
 /* The user-facing name of the symbol whose (internal) number is
    YYSYMBOL.  No bounds checking.  */
-static const char *yysymbol_name (yysymbol_type_t yysymbol) YY_ATTRIBUTE_UNUSED;
+static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;
 
 ]b4_parse_error_bmatch([simple\|verbose],
 [[/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
@@ -666,12 +666,12 @@ static const char *const yytname[] =
 };
 
 static const char *
-yysymbol_name (yysymbol_type_t yysymbol)
+yysymbol_name (yysymbol_kind_t yysymbol)
 {
   return yytname[yysymbol];
 }]],
 [[static const char *
-yysymbol_name (yysymbol_type_t yysymbol)
+yysymbol_name (yysymbol_kind_t yysymbol)
 {
   static const char *const yy_sname[] =
   {
@@ -1018,7 +1018,7 @@ do {                                                                     \
    any old *YYES other than YYESA.  */
 static int
 yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
-        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_type_t yytoken)
+        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
 {
   yy_state_t *yyes_prev = yyssp;
   yy_state_t *yyesp = yyes_prev;
@@ -1130,7 +1130,7 @@ typedef struct
   yy_state_t *yyesa;
   yy_state_t **yyes;
   YYPTRDIFF_T *yyes_capacity;]])])[
-  yysymbol_type_t yytoken;]b4_locations_if([[
+  yysymbol_kind_t yytoken;]b4_locations_if([[
   YYLTYPE *yylloc;]])[
 } yypcontext_t;
 
@@ -1142,10 +1142,10 @@ typedef struct
    YYARG up to YYARGN. */]b4_push_if([[
 static int
 yypstate_expected_tokens (yypstate *yyps,
-                          yysymbol_type_t yyarg[], int yyargn)]], [[
+                          yysymbol_kind_t yyarg[], int yyargn)]], [[
 static int
 yyexpected_tokens (const yypcontext_t *yyctx,
-                   yysymbol_type_t yyarg[], int yyargn)]])[
+                   yysymbol_kind_t yyarg[], int yyargn)]])[
 {
   /* Actual size of YYARG. */
   int yycount = 0;
@@ -1153,7 +1153,7 @@ yyexpected_tokens (const yypcontext_t *yyctx,
   int yyx;
   for (yyx = 0; yyx < YYNTOKENS; ++yyx)
     {
-      yysymbol_type_t yysym = YY_CAST (yysymbol_type_t, yyx);
+      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
       if (yysym != YYSYMBOL_YYERROR && yysym != YYSYMBOL_YYUNDEF)
         switch (yy_lac (]b4_push_if([[yyps->yyesa, &yyps->yyes, &yyps->yyes_capacity, yyps->yyssp, yysym]],
                                     [[yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym]])[))
@@ -1191,7 +1191,7 @@ yyexpected_tokens (const yypcontext_t *yyctx,
             else if (yycount == yyargn)
               return 0;
             else
-              yyarg[yycount++] = YY_CAST (yysymbol_type_t, yyx);
+              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
           }
     }]])[
   return yycount;
@@ -1201,7 +1201,7 @@ yyexpected_tokens (const yypcontext_t *yyctx,
 /* Similar to the previous function.  */
 static int
 yyexpected_tokens (const yypcontext_t *yyctx,
-                   yysymbol_type_t yyarg[], int yyargn)
+                   yysymbol_kind_t yyarg[], int yyargn)
 {
   return yypstate_expected_tokens (yyctx->yyps, yyarg, yyargn);
 }]])[
@@ -1210,10 +1210,10 @@ yyexpected_tokens (const yypcontext_t *yyctx,
 ]b4_parse_error_bmatch(
          [custom],
 [[/* The token type of the lookahead of this context.  */
-static yysymbol_type_t
+static yysymbol_kind_t
 yypcontext_token (const yypcontext_t *yyctx) YY_ATTRIBUTE_UNUSED;
 
-static yysymbol_type_t
+static yysymbol_kind_t
 yypcontext_token (const yypcontext_t *yyctx)
 {
   return yyctx->yytoken;
@@ -1324,7 +1324,7 @@ yytnamerr (char *yyres, const char *yystr)
 
 static int
 yy_syntax_error_arguments (const yypcontext_t *yyctx,
-                           yysymbol_type_t yyarg[], int yyargn)
+                           yysymbol_kind_t yyarg[], int yyargn)
 {
   /* Actual size of YYARG. */
   int yycount = 0;
@@ -1391,7 +1391,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
   const char *yyformat = YY_NULLPTR;
   /* Arguments of yyformat: reported tokens (one for the "unexpected",
      one per "expected"). */
-  yysymbol_type_t yyarg[YYARGS_MAX];
+  yysymbol_kind_t yyarg[YYARGS_MAX];
   /* Cumulated lengths of YYARG.  */
   YYPTRDIFF_T yysize = 0;
 
@@ -1584,7 +1584,7 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])[
   /* The return value of yyparse.  */
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
-  yysymbol_type_t yytoken = YYSYMBOL_YYEMPTY;
+  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;]b4_locations_if([[
@@ -1869,7 +1869,7 @@ yyreduce:
      case of YYERROR or YYBACKUP, subsequent parser actions might lead
      to an incorrect destructor call or verbose syntax error message
      before the lookahead is translated.  */
-  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_type_t, yyr1[yyn]), &yyval, &yyloc);
+  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);
 
   YYPOPSTACK (yylen);
   yylen = 0;
