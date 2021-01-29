@@ -199,7 +199,7 @@ static YYLTYPE yyloc_default][]b4_yyloc_default[;]])])[
 #endif
 
 /* The semantic value of the lookahead symbol.  */
-YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);]b4_locations_if([[
+YYSTYPE yylval YY_INITIAL_VALUE (yyval_default);]b4_locations_if([[
 
 /* Location data for the lookahead symbol.  */
 YYLTYPE yylloc]b4_pure_if([ = yyloc_default], [b4_yyloc_default])[;
