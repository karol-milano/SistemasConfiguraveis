@@ -1769,16 +1769,16 @@ yyerrlab:
             if (yymsg != yymsgbuf)
               YYSTACK_FREE (yymsg);
             yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
-            if (!yymsg)
+            if (yymsg)
               {
-                yymsg = yymsgbuf;
-                yymsg_alloc = sizeof yymsgbuf;
-                yysyntax_error_status = 2;
+                yysyntax_error_status = YYSYNTAX_ERROR;
+                yymsgp = yymsg;
               }
             else
               {
-                yysyntax_error_status = YYSYNTAX_ERROR;
-                yymsgp = yymsg;
+                yymsg = yymsgbuf;
+                yymsg_alloc = sizeof yymsgbuf;
+                yysyntax_error_status = 2;
               }
           }
         yyerror (]b4_yyerror_args[yymsgp);
