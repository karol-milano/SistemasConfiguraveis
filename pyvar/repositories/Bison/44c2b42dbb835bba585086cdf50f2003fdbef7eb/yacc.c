@@ -205,7 +205,7 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
     YYLTYPE *yylsp;
 
     /* The locations where the error started and ended.  */
-    YYLTYPE yyerror_range[2];]])[
+    YYLTYPE yyerror_range[3];]])[
 
     YYSIZE_T yystacksize;]])
 
@@ -1502,7 +1502,7 @@ yyerrlab:
 #endif
     }
 
-]b4_locations_if([[  yyerror_range[0] = yylloc;]])[
+]b4_locations_if([[  yyerror_range[1] = yylloc;]])[
 
   if (yyerrstatus == 3)
     {
@@ -1539,7 +1539,7 @@ yyerrorlab:
   if (/*CONSTCOND*/ 0)
      goto yyerrorlab;
 
-]b4_locations_if([[  yyerror_range[0] = yylsp[1-yylen];
+]b4_locations_if([[  yyerror_range[1] = yylsp[1-yylen];
 ]])[  /* Do not reclaim the symbols of the rule which action triggered
      this YYERROR.  */
   YYPOPSTACK (yylen);
@@ -1573,7 +1573,7 @@ yyerrlab1:
       if (yyssp == yyss)
 	YYABORT;
 
-]b4_locations_if([[      yyerror_range[0] = *yylsp;]])[
+]b4_locations_if([[      yyerror_range[1] = *yylsp;]])[
       yydestruct ("Error: popping",
 		  yystos[yystate], yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
       YYPOPSTACK (1);
@@ -1583,10 +1583,10 @@ yyerrlab1:
 
   *++yyvsp = yylval;
 ]b4_locations_if([[
-  yyerror_range[1] = yylloc;
+  yyerror_range[2] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
      the lookahead.  YYLOC is available though.  */
-  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
+  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
   *++yylsp = yyloc;]])[
 
   /* Shift the error token.  */
