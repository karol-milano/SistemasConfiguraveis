@@ -1823,7 +1823,6 @@ yyreduce:
 
   YYPOPSTACK (yylen);
   yylen = 0;
-  YY_STACK_PRINT (yyss, yyssp);
 
   *++yyvsp = yyval;]b4_locations_if([
   *++yylsp = yyloc;])[
