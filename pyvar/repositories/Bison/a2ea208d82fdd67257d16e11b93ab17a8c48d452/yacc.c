@@ -1448,7 +1448,7 @@ yyabortlab:
   yyresult = 1;
   goto yyreturn;
 
-#ifndef yyoverflow
+#if !defined(yyoverflow) || YYERROR_VERBOSE
 /*-------------------------------------------------.
 | yyexhaustedlab -- memory exhaustion comes here.  |
 `-------------------------------------------------*/
