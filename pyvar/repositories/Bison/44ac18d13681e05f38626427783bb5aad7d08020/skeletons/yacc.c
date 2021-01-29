@@ -856,7 +856,17 @@ int yydebug;
 
 #ifndef YYMAXDEPTH
 # define YYMAXDEPTH ]b4_stack_depth_max[
-#endif]b4_lac_if([[
+#endif]b4_push_if([[
+/* Parser data structure.  */
+struct yypstate
+  {]b4_declare_parser_state_variables[
+    /* Whether this instance has not started parsing yet.  */
+    int yynew;
+  };]b4_pure_if([], [[
+
+/* Whether the only allowed instance of yypstate is allocated.  */
+static char yypstate_allocated = 0;]])])[
+]b4_lac_if([[
 
 /* Given a state stack such that *YYBOTTOM is its bottom, such that
    *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
@@ -1108,23 +1118,28 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
 }]])[
 
 ]b4_parse_error_case([simple], [],
-[[typedef struct
-{
-  yy_state_t *yyssp;
-  int yytoken;]b4_locations_if([[
-  YYLTYPE *yylloc;]])[]b4_lac_if([[
+[[/* Context of a parse error.  */
+typedef struct
+{]b4_push_if([[
+  yypstate* yyps;]], [[
+  yy_state_t *yyssp;]b4_lac_if([[
   yy_state_t *yyesa;
   yy_state_t **yyes;
-  YYPTRDIFF_T *yyes_capacity;]])[
+  YYPTRDIFF_T *yyes_capacity;]])])[
+  int yytoken;]b4_locations_if([[
+  YYLTYPE *yylloc;]])[
 } yyparse_context_t;
 
 /* Put in YYARG at most YYARGN of the expected tokens given the
    current YYCTX, and return the number of tokens stored in YYARG.  If
    YYARG is null, return the number of expected tokens (guaranteed to
-   be less than YYNTOKENS).  */
+   be less than YYNTOKENS).  */]b4_push_if([[
+static int
+yypstate_expected_tokens (yypstate *yyps,
+                          int yyarg[], int yyargn)]], [[
 static int
 yyexpected_tokens (const yyparse_context_t *yyctx,
-                   int yyarg[], int yyargn)
+                   int yyarg[], int yyargn)]])[
 {
   /* Actual size of YYARG. */
   int yycount = 0;
@@ -1134,8 +1149,9 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
     if (yyx != YYTERROR && yyx != YYUNDEFTOK)
       {
         {
-          int yy_lac_status = yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity,
-                                      yyctx->yyssp, yyx);
+          int yy_lac_status
+            = yy_lac (]b4_push_if([[yyps->yyesa, &yyps->yyes, &yyps->yyes_capacity, yyps->yyssp, yyx]],
+                                  [[yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yyx]])[);
           if (yy_lac_status == 2)
             return -2;
           if (yy_lac_status == 1)
@@ -1148,7 +1164,7 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
         else
           yyarg[yycount++] = yyx;
       }]],
-[[  int yyn = yypact[+*yyctx->yyssp];
+[[  int yyn = yypact@{+*]b4_push_if([yyps], [yyctx])[->yyssp@};
   if (!yypact_value_is_default (yyn))
     {
       /* Start YYX at -YYN if negative to avoid negative indexes in
@@ -1174,6 +1190,15 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
   return yycount;
 }
 
+]b4_push_if([[
+/* Similar to the previous function.  */
+static int
+yyexpected_tokens (const yyparse_context_t *yyctx,
+                   int yyarg[], int yyargn)
+{
+  return yypstate_expected_tokens (yyctx->yyps, yyarg, yyargn);
+}]])[
+
 static int
 yysyntax_error_arguments (const yyparse_context_t *yyctx,
                           int yyarg[], int yyargn)
@@ -1430,14 +1455,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
 
 ]b4_pure_if([], [b4_declare_scanner_communication_variables])[
 
-]b4_push_if([[
-struct yypstate
-  {]b4_declare_parser_state_variables[
-    /* Whether this instance has not started parsing yet.  */
-    int yynew;
-  };]b4_pure_if([], [[
-
-static char yypstate_allocated = 0;]])b4_pull_if([[
+]b4_push_if([b4_pull_if([[
 
 int
 yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
@@ -1873,7 +1891,7 @@ yyerrlab:
          [custom],
 [[      {
         yyparse_context_t yyctx
-          = {yyssp, yytoken]b4_locations_if([[, &yylloc]])[]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])[};]b4_lac_if([[
+          = {]b4_push_if([[yyps]], [[yyssp]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])])[, yytoken]b4_locations_if([[, &yylloc]])[};]b4_lac_if([[
         if (yychar != YYEMPTY)
           YY_LAC_ESTABLISH;]])[
         if (yyreport_syntax_error (&yyctx]m4_ifset([b4_parse_param],
@@ -1883,9 +1901,9 @@ yyerrlab:
          [simple],
 [[      yyerror (]b4_yyerror_args[YY_("syntax error"));]],
 [[      {
-        char const *yymsgp = YY_("syntax error");
         yyparse_context_t yyctx
-          = {yyssp, yytoken]b4_locations_if([[, &yylloc]])[]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])[};
+          = {]b4_push_if([[yyps]], [[yyssp]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])])[, yytoken]b4_locations_if([[, &yylloc]])[};
+        char const *yymsgp = YY_("syntax error");
         int yysyntax_error_status;]b4_lac_if([[
         if (yychar != YYEMPTY)
           YY_LAC_ESTABLISH;]])[
