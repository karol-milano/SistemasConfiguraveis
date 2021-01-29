@@ -2490,7 +2490,8 @@ b4_dollar_popdef])[]dnl
                   /* Don't issue an error message again for exceptions
                      thrown from the scanner.  */
                   if (yychar != YYFAULTYTOK)
-  ]])[                  yyreportSyntaxError (&yystack]b4_user_args[);
+  ]], [[
+]])[                  yyreportSyntaxError (&yystack]b4_user_args[);
                   goto yyuser_error;
                 }
               else
