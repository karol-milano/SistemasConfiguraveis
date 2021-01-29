@@ -2163,11 +2163,11 @@ yyexhaustedlab:
 
 yyreturn:
   if (yychar != YYEOF && yychar != YYEMPTY)
-     yydestruct ("Error: discarding lookahead",
+     yydestruct ("Cleanup: discarding lookahead",
 		 yytoken, &yylval, &yylloc);
   while (yyssp != yyss)
     {
-      yydestruct ("Error: popping",
+      yydestruct ("Cleanup: popping",
 		  yystos[*yyssp], yyvsp, yylsp);
       YYPOPSTACK;
     }
