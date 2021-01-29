@@ -2169,7 +2169,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 
  yyreturn:
   if (yytoken != YYEOF && yytoken != YYEMPTY)
-    yydestruct ("Error: discarding lookahead",
+    yydestruct ("Cleanup: discarding lookahead",
                 yytoken, yylvalp]b4_location_if([, yyllocp])[);
 
   /* If the stack is well-formed, pop the stack until it is empty,
@@ -2183,7 +2183,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	  {
 	    yyGLRState *yys = yystates[0];
 ]b4_location_if([[	  yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
-)[	    yydestruct ("Error: popping",
+)[	    yydestruct ("Cleanup: popping",
 			yystos[yys->yylrState],
 			&yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
 	    yystates[0] = yys->yypred;
