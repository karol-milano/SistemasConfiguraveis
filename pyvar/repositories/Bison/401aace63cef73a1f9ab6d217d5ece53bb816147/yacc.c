@@ -1262,7 +1262,7 @@ yyreduce:
 
 ]b4_location_if(
 [[  /* Default location.  */
-  YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);]])[
+  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);]])[
   YY_REDUCE_PRINT (yyn);
   switch (yyn)
     {
@@ -1427,7 +1427,7 @@ yyerrlab1:
   yyerror_range[1] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
      the look-ahead.  YYLOC is available though.  */
-  YYLLOC_DEFAULT (yyloc, yyerror_range - 1, 2);
+  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
   *++yylsp = yyloc;]])[
 
   /* Shift the error token.  */
