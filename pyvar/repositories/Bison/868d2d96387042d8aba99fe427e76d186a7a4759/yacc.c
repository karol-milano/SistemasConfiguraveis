@@ -1164,6 +1164,9 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
 
+  if (yystate == YYFINAL)
+    YYACCEPT;
+
   goto yybackup;
 
 /*-----------.
@@ -1213,9 +1216,6 @@ yybackup:
       goto yyreduce;
     }
 
-  if (yyn == YYFINAL)
-    YYACCEPT;
-
   /* Count tokens shifted since error; after three, turn off error
      status.  */
   if (yyerrstatus)
@@ -1224,9 +1224,8 @@ yybackup:
   /* Shift the lookahead token.  */
   YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 
-  /* Discard the shifted token unless it is eof.  */
-  if (yychar != YYEOF)
-    yychar = YYEMPTY;
+  /* Discard the shifted token.  */
+  yychar = YYEMPTY;
 
   yystate = yyn;
   *++yyvsp = yylval;
@@ -1418,9 +1417,6 @@ yyerrlab1:
       YY_STACK_PRINT (yyss, yyssp);
     }
 
-  if (yyn == YYFINAL)
-    YYACCEPT;
-
   *++yyvsp = yylval;
 ]b4_locations_if([[
   yyerror_range[1] = yylloc;
@@ -1461,7 +1457,7 @@ yyexhaustedlab:
 #endif
 
 yyreturn:
-  if (yychar != YYEOF && yychar != YYEMPTY)
+  if (yychar != YYEMPTY)
      yydestruct ("Cleanup: discarding lookahead",
 		 yytoken, &yylval]b4_locations_if([, &yylloc])[]b4_user_args[);
   /* Do not reclaim the symbols of the rule which action triggered
