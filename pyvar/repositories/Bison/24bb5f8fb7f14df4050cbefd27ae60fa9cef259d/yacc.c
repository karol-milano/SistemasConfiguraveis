@@ -2018,7 +2018,7 @@ yyabortlab:
   yyresult = 1;
   goto yyreturn;
 
-#if ]b4_lac_if([[1]], [[!defined(yyoverflow) || YYERROR_VERBOSE]])[
+#if ]b4_lac_if([[1]], [[!defined yyoverflow || YYERROR_VERBOSE]])[
 /*-------------------------------------------------.
 | yyexhaustedlab -- memory exhaustion comes here.  |
 `-------------------------------------------------*/
