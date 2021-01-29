@@ -1174,8 +1174,9 @@ yyparse_context_location (const yyparse_context_t *yyctx)
 }]])[
 
 /* User defined funtion to report a syntax error.  */
-static int
-yyreport_syntax_error (const yyparse_context_t *yyctx);]],
+]b4_function_declare([yyreport_syntax_error], [static int],
+                     [[[const yyparse_context_t *yyctx]], [[yyctx]]],
+                     b4_parse_param)],
          [verbose],
 [[# ifndef yystrlen
 #  if defined __GLIBC__ && defined _STRING_H
@@ -1832,7 +1833,8 @@ yyerrlab:
           = {yyssp, yytoken]b4_locations_if([[, &yylloc]])[]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])[};]b4_lac_if([[
         if (yychar != YYEMPTY)
           YY_LAC_ESTABLISH;]])[
-        if (yyreport_syntax_error (&yyctx) == 2)
+        if (yyreport_syntax_error (&yyctx]m4_ifset([b4_parse_param],
+                                  [[, ]b4_args(b4_parse_param)])[) == 2)
           goto yyexhaustedlab;
       }]],
          [simple],
