@@ -946,7 +946,7 @@ yybackup:
     YYACCEPT;
 
   /* Shift the look-ahead token.  */
-  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));
+  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 
   /* Discard the token being shifted unless it is eof.  */
   if (yychar != YYEOF)
@@ -1185,12 +1185,13 @@ yyerrlab1:
   if (yyn == YYFINAL)
     YYACCEPT;
 
-  YYDPRINTF ((stderr, "Shifting error token, "));
-
   *++yyvsp = yylval;
 ]b4_location_if([  YYLLOC_DEFAULT (yyloc, yylsp, yylerrsp - yylsp);
   *++yylsp = yyloc;])[
 
+  /* Shift the error token. */
+  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);
+
   yystate = yyn;
   goto yynewstate;
 
