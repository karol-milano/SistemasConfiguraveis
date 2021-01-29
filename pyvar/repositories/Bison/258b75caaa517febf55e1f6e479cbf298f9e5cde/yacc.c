@@ -1220,8 +1220,7 @@ yyerrlab:
 
       if (yychar <= YYEOF)
         {
-          /* If at end of input, pop the error token,
-	     then the rest of the stack, then return failure.  */
+	  /* Return failure if at end of input.  */
 	  if (yychar == YYEOF)
 	    YYABORT;
         }
@@ -1333,16 +1332,12 @@ yyreturn:
   if (yychar != YYEOF && yychar != YYEMPTY)
      yydestruct ("Error: discarding lookahead",
 		 yytoken, &yylval]b4_location_if([, &yylloc])[);
-  if (yyssp != yyss)
-    for (;;)
-      {
-]b4_location_if([[	yyerror_range[0] = *yylsp;]])[
-	YYPOPSTACK;
-	if (yyssp == yyss)
-	  break;
-	yydestruct ("Error: popping",
-		    yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
-      }
+  while (yyssp != yyss)
+    {
+      yydestruct ("Error: popping",
+		  yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
+      YYPOPSTACK;
+    }
 #ifndef yyoverflow
   if (yyss != yyssa)
     YYSTACK_FREE (yyss);
