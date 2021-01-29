@@ -2705,7 +2705,7 @@ yyerrorlab:
 yyerrlab1:
   yyerrstatus = 3;      /* Each real token shifted decrements this.  */
 
-  // Pop stack until we find a state that shifts the error token.
+  /* Pop stack until we find a state that shifts the error token.  */
   for (;;)
     {
       yyn = yypact[yystate];
