@@ -1383,11 +1383,11 @@ yyexhaustedlab:
 
 yyreturn:
   if (yychar != YYEOF && yychar != YYEMPTY)
-     yydestruct ("Error: discarding lookahead",
+     yydestruct ("Cleanup: discarding lookahead",
 		 yytoken, &yylval]b4_location_if([, &yylloc])[);
   while (yyssp != yyss)
     {
-      yydestruct ("Error: popping",
+      yydestruct ("Cleanup: popping",
 		  yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
       YYPOPSTACK;
     }
