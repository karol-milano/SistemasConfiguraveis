@@ -912,8 +912,6 @@ yybackup:
     }
   else
     {
-      /* We have to keep this `#if YYDEBUG', since we use variables
-	 which are defined only if `YYDEBUG' is set.  */
       YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
     }
 
@@ -1073,13 +1071,7 @@ yyerrlab:
 #endif /* YYERROR_VERBOSE */
 	yyerror (]b4_yyerror_args["syntax error");
     }
-  goto yyerrlab1;
-
 
-/*----------------------------------------------------.
-| yyerrlab1 -- error raised explicitly by an action.  |
-`----------------------------------------------------*/
-yyerrlab1:
   if (yyerrstatus == 3)
     {
       /* If just tried and failed to reuse lookahead token after an
@@ -1107,7 +1099,13 @@ yyerrlab1:
 
   /* Else will try to reuse lookahead token after shifting the error
      token.  */
+  goto yyerrlab1;
+
 
+/*----------------------------------------------------.
+| yyerrlab1 -- error raised explicitly by an action.  |
+`----------------------------------------------------*/
+yyerrlab1:
   yyerrstatus = 3;	/* Each real token shifted decrements this.  */
 
   for (;;)
