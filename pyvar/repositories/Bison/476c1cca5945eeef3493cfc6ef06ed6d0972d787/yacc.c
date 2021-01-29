@@ -1641,8 +1641,9 @@ yyreduce:
   yyval = yyvsp[1-yylen];
 
 ]b4_locations_if(
-[[  /* Default location.  */
-  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);]])[
+[[  /* Default location. */
+  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
+  yyerror_range[1] = yyloc;]])[
   YY_REDUCE_PRINT (yyn);]b4_lac_if([[
   {
     int yychar_backup = yychar;
@@ -1782,8 +1783,7 @@ yyerrorlab:
   if (/*CONSTCOND*/ 0)
      goto yyerrorlab;
 
-]b4_locations_if([[  yyerror_range[1] = yylsp[1-yylen];
-]])[  /* Do not reclaim the symbols of the rule whose action triggered
+  /* Do not reclaim the symbols of the rule whose action triggered
      this YYERROR.  */
   YYPOPSTACK (yylen);
   yylen = 0;
