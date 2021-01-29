@@ -1209,6 +1209,9 @@ yyacceptlab:
 | yyabortlab -- YYABORT comes here.  |
 `-----------------------------------*/
 yyabortlab:
+  YY_SYMBOL_PRINT ("Error: discarding lookahead", yytoken, &yylval, &yylloc);
+  yydestruct (yytoken, &yylval]b4_location_if([, &yylloc])[);
+  yychar = YYEMPTY;
   yyresult = 1;
   goto yyreturn;
 
