@@ -1136,7 +1136,11 @@ yysyntax_error_arguments (const yyparse_context_t *yyctx,
 }
 ]])[
 
-]m4_case(b4_percent_define_get([[parse.error]]), [verbose],
+]m4_case(b4_percent_define_get([[parse.error]]),
+         [custom],
+[[static int
+yyreport_syntax_error (const yyparse_context_t *yyctx);]],
+         [verbose],
 [[# ifndef yystrlen
 #  if defined __GLIBC__ && defined _STRING_H
 #   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
@@ -1786,6 +1790,15 @@ yyerrlab:
     {
       ++yynerrs;
 ]m4_case(b4_percent_define_get([[parse.error]]),
+         [custom],
+[[      {
+        yyparse_context_t yyctx
+          = {yyssp, yytoken]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])[};]b4_lac_if([[
+        if (yychar != YYEMPTY)
+          YY_LAC_ESTABLISH;]])[
+        if (yyreport_syntax_error (]b4_yyerror_args[&yyctx) == 2)
+          goto yyexhaustedlab;
+      }]],
          [simple],
 [[      yyerror (]b4_yyerror_args[YY_("syntax error"));]],
          [verbose],
