@@ -836,12 +836,10 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
       if (yydebug)
         {
           if (yys->yysemantics.yyfirstVal)
-            YYFPRINTF (stderr, "%s unresolved ", yymsg);
+            YYFPRINTF (stderr, "%s unresolved", yymsg);
           else
-            YYFPRINTF (stderr, "%s incomplete ", yymsg);
-          yy_symbol_print (stderr, yystos[yys->yylrState],
-                           YY_NULL]b4_locuser_args([&yys->yyloc])[);
-          YYFPRINTF (stderr, "\n");
+            YYFPRINTF (stderr, "%s incomplete", yymsg);
+          YY_SYMBOL_PRINT ("", yystos[yys->yylrState], YY_NULL, &yys->yyloc);
         }
 #endif
 
