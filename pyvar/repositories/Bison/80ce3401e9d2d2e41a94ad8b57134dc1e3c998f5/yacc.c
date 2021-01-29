@@ -1203,15 +1203,7 @@ yyerrlab:
           /* If at end of input, pop the error token,
 	     then the rest of the stack, then return failure.  */
 	  if (yychar == YYEOF)
-	     for (;;)
-	       {
-]b4_location_if([[                 yyerror_range[0] = *yylsp;]])[
-		 YYPOPSTACK;
-		 if (yyssp == yyss)
-		   YYABORT;
-		 yydestruct (_("Error: popping"),
-                             yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
-	       }
+	    YYABORT;
         }
       else
 	{
@@ -1316,11 +1308,23 @@ yyabortlab:
 `----------------------------------------------*/
 yyoverflowlab:
   yyerror (]b4_yyerror_args[_("parser stack overflow"));
+  yydestruct (_("Error: discarding lookahead"),
+	      yytoken, &yylval]b4_location_if([, &yylloc])[);
   yyresult = 2;
   /* Fall through.  */
 #endif
 
 yyreturn:
+  if (yyssp != yyss)
+    for (;;)
+      {
+]b4_location_if([[	yyerror_range[0] = *yylsp;]])[
+	YYPOPSTACK;
+	if (yyssp == yyss)
+	  break;
+	yydestruct (_("Error: popping"),
+		    yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
+      }
 #ifndef yyoverflow
   if (yyss != yyssa)
     YYSTACK_FREE (yyss);
