@@ -1997,8 +1997,7 @@ yyerrlab:
 
       if (yychar <= YYEOF)
         {
-          /* If at end of input, pop the error token,
-	     then the rest of the stack, then return failure.  */
+	  /* Return failure if at end of input.  */
 	  if (yychar == YYEOF)
 	    YYABORT;
         }
@@ -2110,16 +2109,12 @@ yyreturn:
   if (yychar != YYEOF && yychar != YYEMPTY)
      yydestruct ("Error: discarding lookahead",
 		 yytoken, &yylval, &yylloc);
-  if (yyssp != yyss)
-    for (;;)
-      {
-	yyerror_range[0] = *yylsp;
-	YYPOPSTACK;
-	if (yyssp == yyss)
-	  break;
-	yydestruct ("Error: popping",
-		    yystos[*yyssp], yyvsp, yylsp);
-      }
+  while (yyssp != yyss)
+    {
+      yydestruct ("Error: popping",
+		  yystos[*yyssp], yyvsp, yylsp);
+      YYPOPSTACK;
+    }
 #ifndef yyoverflow
   if (yyss != yyssa)
     YYSTACK_FREE (yyss);
