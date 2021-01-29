@@ -564,7 +564,7 @@ do								\
       yychar = (Token);						\
       yylval = (Value);						\
       yytoken = YYTRANSLATE (yychar);				\
-      YYPOPSTACK;						\
+      YYPOPSTACK (1);						\
       goto yybackup;						\
     }								\
   else								\
@@ -1042,7 +1042,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   /* The locations where the error started and ended. */
   YYLTYPE yyerror_range[2];]])[
 
-#define YYPOPSTACK   (yyvsp--, yyssp--]b4_location_if([, yylsp--])[)
+#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N)]b4_location_if([, yylsp -= (N)])[)
 
   YYSIZE_T yystacksize = YYINITDEPTH;
 
@@ -1051,9 +1051,9 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   YYSTYPE yyval;
 ]b4_location_if([  YYLTYPE yyloc;])[
 
-  /* When reducing, the number of symbols on the RHS of the reduced
-     rule.  */
-  int yylen;
+  /* The number of symbols on the RHS of the reduced rule.
+     Keep to zero when no symbol should be popped off. */
+  int yylen = 0;
 
   YYDPRINTF ((stderr, "Starting parse\n"));
 
@@ -1178,12 +1178,10 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 `-----------*/
 yybackup:
 
-/* Do appropriate processing given the current state.  */
-/* Read a look-ahead token if we need one and don't already have one.  */
-/* yyresume: */
+  /* Do appropriate processing given the current state.  Read a
+     look-ahead token if we need one and don't already have one.  */
 
   /* First try to decide what to do without reference to look-ahead token.  */
-
   yyn = yypact[yystate];
   if (yyn == YYPACT_NINF)
     goto yydefault;
@@ -1225,22 +1223,21 @@ yybackup:
   if (yyn == YYFINAL)
     YYACCEPT;
 
+  /* Count tokens shifted since error; after three, turn off error
+     status.  */
+  if (yyerrstatus)
+    yyerrstatus--;
+
   /* Shift the look-ahead token.  */
   YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 
-  /* Discard the token being shifted unless it is eof.  */
+  /* Discard the shifted token unless it is eof.  */
   if (yychar != YYEOF)
     yychar = YYEMPTY;
 
+  yystate = yyn;
   *++yyvsp = yylval;
 ]b4_location_if([  *++yylsp = yylloc;])[
-
-  /* Count tokens shifted since error; after three, turn off error
-     status.  */
-  if (yyerrstatus)
-    yyerrstatus--;
-
-  yystate = yyn;
   goto yynewstate;
 
 
@@ -1277,18 +1274,15 @@ yyreduce:
   YY_REDUCE_PRINT (yyn);
   switch (yyn)
     {
-      ]b4_actions[
+      ]b4_actions
+/* Line __line__ of yacc.c.  */
+b4_syncline([@oline@], [@ofile@])[
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
 
-/* Line __line__ of yacc.c.  */
-]b4_syncline([@oline@], [@ofile@])[
-
-  yyvsp -= yylen;
-  yyssp -= yylen;
-]b4_location_if([  yylsp -= yylen;])[
-
+  YYPOPSTACK (yylen);
+  yylen = 0;
   YY_STACK_PRINT (yyss, yyssp);
 
   *++yyvsp = yyval;
@@ -1392,9 +1386,11 @@ yyerrorlab:
      goto yyerrorlab;
 
 ]b4_location_if([[  yyerror_range[0] = yylsp[1-yylen];
-  yylsp -= yylen;
-  ]])[yyvsp -= yylen;
-  yyssp -= yylen;
+]])[  /* Do not reclaim the symbols of the rule which action triggered
+     this YYERROR. */
+  YYPOPSTACK (yylen);
+  yylen = 0;
+  YY_STACK_PRINT (yyss, yyssp);
   yystate = *yyssp;
   goto yyerrlab1;
 
@@ -1426,7 +1422,7 @@ yyerrlab1:
 ]b4_location_if([[      yyerror_range[0] = *yylsp;]])[
       yydestruct ("Error: popping",
                   yystos[yystate], yyvsp]b4_location_if([, yylsp])[]b4_user_args[);
-      YYPOPSTACK;
+      YYPOPSTACK (1);
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
     }
@@ -1477,11 +1473,15 @@ yyreturn:
   if (yychar != YYEOF && yychar != YYEMPTY)
      yydestruct ("Cleanup: discarding lookahead",
 		 yytoken, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
+  /* Do not reclaim the symbols of the rule which action triggered
+     this YYABORT or YYACCEPT. */
+  YYPOPSTACK (yylen);
+  YY_STACK_PRINT (yyss, yyssp);
   while (yyssp != yyss)
     {
       yydestruct ("Cleanup: popping",
 		  yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[]b4_user_args[);
-      YYPOPSTACK;
+      YYPOPSTACK (1);
     }
 #ifndef yyoverflow
   if (yyss != yyssa)
