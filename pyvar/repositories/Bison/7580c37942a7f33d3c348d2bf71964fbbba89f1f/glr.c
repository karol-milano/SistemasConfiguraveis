@@ -1011,8 +1011,7 @@ yygetLRActions (yyStateNum yystate, int yytoken,
 static inline yyStateNum
 yyLRgotoState (yyStateNum yystate, yySymbol yylhs)
 {
-  int yyr;
-  yyr = yypgoto[yylhs - YYNTOKENS] + yystate;
+  int yyr = yypgoto[yylhs - YYNTOKENS] + yystate;
   if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
     return yytable[yyr];
   else
