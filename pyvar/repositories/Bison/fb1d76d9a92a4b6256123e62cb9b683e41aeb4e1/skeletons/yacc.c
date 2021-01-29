@@ -2052,10 +2052,8 @@ yyerrlab1:
   YY_IGNORE_MAYBE_UNINITIALIZED_END
 ]b4_locations_if([[
   yyerror_range[2] = yylloc;
-  /* Using YYLLOC is tempting, but would change the location of
-     the lookahead.  YYLOC is available though.  */
-  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
-  *++yylsp = yyloc;]])[
+  ++yylsp;
+  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);]])[
 
   /* Shift the error token.  */
   YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);
