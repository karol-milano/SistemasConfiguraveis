@@ -1114,15 +1114,13 @@ yyerrlab:
 		 YYPOPSTACK;
 		 if (yyssp == yyss)
 		   YYABORT;
-		 YY_SYMBOL_PRINT ("Error: popping",
-	                          yystos[*yyssp], yyvsp, yylsp);
-		 yydestruct (yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
+		 yydestruct ("Error: popping",
+                             yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
 	       }
         }
       else
 	{
-	  YY_SYMBOL_PRINT ("Error: discarding", yytoken, &yylval, &yylloc);
-	  yydestruct (yytoken, &yylval]b4_location_if([, &yylloc])[);
+	  yydestruct ("Error: discarding", yytoken, &yylval]b4_location_if([, &yylloc])[);
 	  yychar = YYEMPTY;
 ]b4_location_if([	  *++yylerrsp = yylloc;])[
 	}
@@ -1178,8 +1176,7 @@ yyerrlab1:
       if (yyssp == yyss)
 	YYABORT;
 
-      YY_SYMBOL_PRINT ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
-      yydestruct (yystos[yystate], yyvsp]b4_location_if([, yylsp])[);
+      yydestruct ("Error: popping", yystos[yystate], yyvsp]b4_location_if([, yylsp])[);
       YYPOPSTACK;
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
@@ -1209,8 +1206,8 @@ yyacceptlab:
 | yyabortlab -- YYABORT comes here.  |
 `-----------------------------------*/
 yyabortlab:
-  YY_SYMBOL_PRINT ("Error: discarding lookahead", yytoken, &yylval, &yylloc);
-  yydestruct (yytoken, &yylval]b4_location_if([, &yylloc])[);
+  yydestruct ("Error: discarding lookahead",
+              yytoken, &yylval]b4_location_if([, &yylloc])[);
   yychar = YYEMPTY;
   yyresult = 1;
   goto yyreturn;
