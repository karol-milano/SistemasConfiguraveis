@@ -1804,7 +1804,7 @@ yyerrorlab:
      goto yyerrorlab;
 
 ]b4_locations_if([[  yyerror_range[1] = yylsp[1-yylen];
-]])[  /* Do not reclaim the symbols of the rule which action triggered
+]])[  /* Do not reclaim the symbols of the rule whose action triggered
      this YYERROR.  */
   YYPOPSTACK (yylen);
   yylen = 0;
@@ -1899,7 +1899,7 @@ yyreturn:
       yydestruct ("Cleanup: discarding lookahead",
                   yytoken, &yylval]b4_locations_if([, &yylloc])[]b4_user_args[);
     }
-  /* Do not reclaim the symbols of the rule which action triggered
+  /* Do not reclaim the symbols of the rule whose action triggered
      this YYABORT or YYACCEPT.  */
   YYPOPSTACK (yylen);
   YY_STACK_PRINT (yyss, yyssp);
