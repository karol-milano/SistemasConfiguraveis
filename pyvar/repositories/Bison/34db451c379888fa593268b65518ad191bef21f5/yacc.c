@@ -1477,28 +1477,34 @@ yyerrlab:
 #if ! YYERROR_VERBOSE
       yyerror (]b4_yyerror_args[YY_("syntax error"));
 #else
-      while (1)
-        {
-          int yysyntax_error_status =
-            yysyntax_error (&yymsg_alloc, &yymsg, yystate, yytoken);
-          if (yysyntax_error_status == 2 && 0 < yymsg_alloc)
-            {
-              if (yymsg != yymsgbuf)
-                YYSTACK_FREE (yymsg);
-              yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
-              if (yymsg)
-                continue;
-              yymsg = yymsgbuf;
-              yymsg_alloc = sizeof yymsgbuf;
-            }
-          if (yysyntax_error_status == 0)
-            yyerror (]b4_yyerror_args[yymsg);
-          else
-            yyerror (]b4_yyerror_args[YY_("syntax error"));
-          if (yysyntax_error_status == 2)
-            goto yyexhaustedlab;
-          break;
-        }
+# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, yystate, \
+                                        yytoken)
+      {
+        char const *yymsgp = YY_("syntax error");
+        int yysyntax_error_status = YYSYNTAX_ERROR;
+        if (yysyntax_error_status == 0)
+          yymsgp = yymsg;
+        else if (yysyntax_error_status == 2 && 0 < yymsg_alloc)
+          {
+            if (yymsg != yymsgbuf)
+              YYSTACK_FREE (yymsg);
+            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
+            if (!yymsg)
+              {
+                yymsg = yymsgbuf;
+                yymsg_alloc = sizeof yymsgbuf;
+              }
+            else
+              {
+                yysyntax_error_status = YYSYNTAX_ERROR;
+                yymsgp = yymsg;
+              }
+          }
+        yyerror (]b4_yyerror_args[yymsgp);
+        if (yysyntax_error_status == 2)
+          goto yyexhaustedlab;
+      }
+# undef YYSYNTAX_ERROR
 #endif
     }
 
