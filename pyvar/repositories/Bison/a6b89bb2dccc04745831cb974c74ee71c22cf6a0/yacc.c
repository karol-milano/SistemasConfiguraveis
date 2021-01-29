@@ -466,14 +466,7 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 
 #define YYACCEPT	goto yyacceptlab
 #define YYABORT		goto yyabortlab
-#define YYERROR		]b4_location_if([do				\
-			  {				\
-			    yylerrsp = yylsp;		\
-			    *++yylerrsp = yyloc;	\
-			    goto yyerrlab1;		\
-			  }				\
-			while (0)],
-			[goto yyerrlab1])[
+#define YYERROR		goto yyerrorlab
 
 
 /* Like YYERROR except do call yyerror.  This remains here temporarily
@@ -1101,25 +1094,27 @@ yyerrlab:
       /* If just tried and failed to reuse lookahead token after an
 	 error, discard it.  */
 
-      /* Return failure if at end of input.  */
-      if (yychar == YYEOF)
+      if (yychar <= YYEOF)
         {
-	  /* Pop the error token.  */
-          YYPOPSTACK;
-	  /* Pop the rest of the stack.  */
-	  while (yyss < yyssp)
-	    {
-	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
-	      yydestruct (yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
-	      YYPOPSTACK;
-	    }
-	  YYABORT;
+          /* If at end of input, pop the error token,
+	     then the rest of the stack, then return failure.  */
+	  if (yychar == YYEOF)
+	     for (;;)
+	       {
+		 YYPOPSTACK;
+		 if (yyssp == yyss)
+		   YYABORT;
+		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
+		 yydestruct (yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
+	       }
         }
-
-      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
-      yydestruct (yytoken, &yylval]b4_location_if([, &yylloc])[);
-      yychar = YYEMPTY;
-]b4_location_if([      *++yylerrsp = yylloc;])[
+      else
+	{
+	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
+	  yydestruct (yytoken, &yylval]b4_location_if([, &yylloc])[);
+	  yychar = YYEMPTY;
+]b4_location_if([	  *++yylerrsp = yylloc;])[
+	}
     }
 
   /* Else will try to reuse lookahead token after shifting the error
@@ -1127,9 +1122,30 @@ yyerrlab:
   goto yyerrlab1;
 
 
-/*----------------------------------------------------.
-| yyerrlab1 -- error raised explicitly by an action.  |
-`----------------------------------------------------*/
+/*---------------------------------------------------.
+| yyerrorlab -- error raised explicitly by YYERROR.  |
+`---------------------------------------------------*/
+yyerrorlab:
+
+#ifdef __GNUC__
+  /* Pacify GCC when the user code never invokes YYERROR and the label
+     yyerrorlab therefore never appears in user code.  */
+  if (0)
+     goto yyerrorlab;
+#endif
+
+  yyvsp -= yylen;
+  yyssp -= yylen;
+  yystate = *yyssp;
+  ]b4_location_if([yylerrsp = yylsp;
+  *++yylerrsp = yyloc;
+  yylsp -= yylen;
+  ])[goto yyerrlab1;
+
+
+/*-------------------------------------------------------------.
+| yyerrlab1 -- common code for both syntax error and YYERROR.  |
+`-------------------------------------------------------------*/
 yyerrlab1:
   yyerrstatus = 3;	/* Each real token shifted decrements this.  */
 
@@ -1153,9 +1169,8 @@ yyerrlab1:
 
       YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
       yydestruct (yystos[yystate], yyvsp]b4_location_if([, yylsp])[);
-      yyvsp--;
-      yystate = *--yyssp;
-]b4_location_if([      yylsp--;])[
+      YYPOPSTACK;
+      yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
     }
 
