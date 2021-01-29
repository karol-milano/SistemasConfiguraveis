@@ -1650,8 +1650,8 @@ yyread_pushed_token:]])[
   yystate = yyn;
   YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   *++yyvsp = yylval;
-  YY_IGNORE_MAYBE_UNINITIALIZED_END
-]b4_locations_if([  *++yylsp = yylloc;])[
+  YY_IGNORE_MAYBE_UNINITIALIZED_END]b4_locations_if([
+  *++yylsp = yylloc;])[
   goto yynewstate;
 
 
