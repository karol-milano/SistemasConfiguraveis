@@ -1634,16 +1634,15 @@ yyread_pushed_token:]])[
 
   /* Shift the lookahead token.  */
   YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
-
-  /* Discard the shifted token.  */
-  yychar = YYEMPTY;]b4_lac_if([[
-  YY_LAC_DISCARD ("shift");]])[
-
   yystate = yyn;
   YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   *++yyvsp = yylval;
   YY_IGNORE_MAYBE_UNINITIALIZED_END]b4_locations_if([
   *++yylsp = yylloc;])[
+
+  /* Discard the shifted token.  */
+  yychar = YYEMPTY;]b4_lac_if([[
+  YY_LAC_DISCARD ("shift");]])[
   goto yynewstate;
 
 
