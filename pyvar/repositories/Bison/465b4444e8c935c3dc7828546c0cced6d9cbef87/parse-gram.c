@@ -284,7 +284,8 @@ typedef struct YYLTYPE
 
 #if (! defined (yyoverflow) \
      && (! defined (__cplusplus) \
-	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))
+	 || (defined (YYLTYPE_IS_TRIVIAL) && YYLTYPE_IS_TRIVIAL \
+             && defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))
 
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
@@ -306,7 +307,7 @@ union yyalloc
 /* Copy COUNT objects from FROM to TO.  The source and destination do
    not overlap.  */
 # ifndef YYCOPY
-#  if 1 < __GNUC__
+#  if defined (__GNUC__) && 1 < __GNUC__
 #   define YYCOPY(To, From, Count) \
       __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
 #  else
@@ -655,13 +656,7 @@ static const unsigned char yystos[] =
 
 #define YYACCEPT	goto yyacceptlab
 #define YYABORT		goto yyabortlab
-#define YYERROR		do				\
-			  {				\
-			    yylerrsp = yylsp;		\
-			    *++yylerrsp = yyloc;	\
-			    goto yyerrlab1;		\
-			  }				\
-			while (0)
+#define YYERROR		goto yyerrorlab
 
 
 /* Like YYERROR except do call yyerror.  This remains here temporarily
@@ -1624,8 +1619,8 @@ yyreduce:
 
     }
 
-/* Line 999 of yacc.c.  */
-#line 1629 "parse-gram.c"
+/* Line 993 of yacc.c.  */
+#line 1624 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1728,25 +1723,27 @@ yyerrlab:
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
-	      yydestruct (yystos[*yyssp], yyvsp, yylsp);
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
+		 yydestruct (yystos[*yyssp], yyvsp, yylsp);
+	       }
         }
-
-      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
-      yydestruct (yytoken, &yylval, &yylloc);
-      yychar = YYEMPTY;
-      *++yylerrsp = yylloc;
+      else
+	{
+	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
+	  yydestruct (yytoken, &yylval, &yylloc);
+	  yychar = YYEMPTY;
+	  *++yylerrsp = yylloc;
+	}
     }
 
   /* Else will try to reuse lookahead token after shifting the error
@@ -1754,9 +1751,30 @@ yyerrlab:
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
+  yylerrsp = yylsp;
+  *++yylerrsp = yyloc;
+  yylsp -= yylen;
+  goto yyerrlab1;
+
+
+/*-------------------------------------------------------------.
+| yyerrlab1 -- common code for both syntax error and YYERROR.  |
+`-------------------------------------------------------------*/
 yyerrlab1:
   yyerrstatus = 3;	/* Each real token shifted decrements this.  */
 
@@ -1780,9 +1798,8 @@ yyerrlab1:
 
       YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
       yydestruct (yystos[yystate], yyvsp, yylsp);
-      yyvsp--;
-      yystate = *--yyssp;
-      yylsp--;
+      YYPOPSTACK;
+      yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
     }
 
