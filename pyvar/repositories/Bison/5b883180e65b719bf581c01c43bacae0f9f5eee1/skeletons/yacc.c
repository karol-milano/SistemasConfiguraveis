@@ -1789,25 +1789,26 @@ yyerrlab:
          [simple],
 [[      yyerror (]b4_yyerror_args[YY_("syntax error"));]],
          [verbose],
-[[# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, &yyctx)
-      {
+[[      {
         char const *yymsgp = YY_("syntax error");
         yyparse_context_t yyctx
           = {yyssp, yytoken]b4_lac_if([[, yyesa, &yyes, &yyes_capacity]])[};
         int yysyntax_error_status;]b4_lac_if([[
         if (yychar != YYEMPTY)
           YY_LAC_ESTABLISH;]])[
-        yysyntax_error_status = YYSYNTAX_ERROR;
+        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
         if (yysyntax_error_status == 0)
           yymsgp = yymsg;
         else if (yysyntax_error_status == 1)
           {
             if (yymsg != yymsgbuf)
               YYSTACK_FREE (yymsg);
-            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
+            yymsg = YY_CAST (char *,
+                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
             if (yymsg)
               {
-                yysyntax_error_status = YYSYNTAX_ERROR;
+                yysyntax_error_status
+                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                 yymsgp = yymsg;
               }
             else
@@ -1820,8 +1821,7 @@ yyerrlab:
         yyerror (]b4_yyerror_args[yymsgp);
         if (yysyntax_error_status == 2)
           goto yyexhaustedlab;
-      }
-# undef YYSYNTAX_ERROR]])[
+      }]])[
     }
 
 ]b4_locations_if([[  yyerror_range[1] = yylloc;]])[
