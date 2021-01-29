@@ -1780,8 +1780,8 @@ yyerrorlab:
   /* Pacify compilers like GCC when the user code never invokes
      YYERROR and the label yyerrorlab therefore never appears in user
      code.  */
-  if (/*CONSTCOND*/ 0)
-     goto yyerrorlab;
+  if (0)
+    goto yyerrorlab;
 
   /* Do not reclaim the symbols of the rule whose action triggered
      this YYERROR.  */
