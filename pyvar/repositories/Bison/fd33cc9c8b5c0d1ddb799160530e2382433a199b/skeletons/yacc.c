@@ -1050,7 +1050,8 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
 [[typedef struct
 {
   yy_state_t *yyssp;
-  int yytoken;]b4_lac_if([[
+  int yytoken;]b4_locations_if([[
+  YYLTYPE *yylloc;]])[]b4_lac_if([[
   yy_state_t *yyesa;
   yy_state_t **yyes_p;
   YYPTRDIFF_T *yyes_capacity_p;]])[
@@ -1165,7 +1166,15 @@ yysyntax_error_arguments (const yyparse_context_t *yyctx,
 
 ]m4_case(b4_percent_define_get([[parse.error]]),
          [custom],
-[[static int
+[b4_locations_if([[/*  The location of this context.  */
+static YYLTYPE *
+yyparse_context_location (const yyparse_context_t *yyctx)
+{
+  return yyctx->yylloc;
+}]])[
+
+/* User defined funtion to report a syntax error.  */
+static int
 yyreport_syntax_error (const yyparse_context_t *yyctx);]],
          [verbose],
 [[# ifndef yystrlen
@@ -1820,10 +1829,10 @@ yyerrlab:
          [custom],
 [[      {
         yyparse_context_t yyctx
-          = {yyssp, yytoken]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])[};]b4_lac_if([[
+          = {yyssp, yytoken]b4_locations_if([[, &yylloc]])[]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])[};]b4_lac_if([[
         if (yychar != YYEMPTY)
           YY_LAC_ESTABLISH;]])[
-        if (yyreport_syntax_error (]b4_yyerror_args[&yyctx) == 2)
+        if (yyreport_syntax_error (&yyctx) == 2)
           goto yyexhaustedlab;
       }]],
          [simple],
@@ -1832,7 +1841,7 @@ yyerrlab:
 [[      {
         char const *yymsgp = YY_("syntax error");
         yyparse_context_t yyctx
-          = {yyssp, yytoken]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])[};
+          = {yyssp, yytoken]b4_locations_if([[, &yylloc]])[]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])[};
         int yysyntax_error_status;]b4_lac_if([[
         if (yychar != YYEMPTY)
           YY_LAC_ESTABLISH;]])[
