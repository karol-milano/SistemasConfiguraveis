@@ -1777,11 +1777,10 @@ yyerrlab:
 | yyerrorlab -- error raised explicitly by YYERROR.  |
 `---------------------------------------------------*/
 yyerrorlab:
-  /* Pacify compilers like GCC when the user code never invokes
-     YYERROR and the label yyerrorlab therefore never appears in user
-     code.  */
+  /* Pacify compilers when the user code never invokes YYERROR and the
+     label yyerrorlab therefore never appears in user code.  */
   if (0)
-    goto yyerrorlab;
+    YYERROR;
 
   /* Do not reclaim the symbols of the rule whose action triggered
      this YYERROR.  */
