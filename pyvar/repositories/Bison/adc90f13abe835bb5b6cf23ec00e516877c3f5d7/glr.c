@@ -1981,9 +1981,10 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    }
 	}
 ]b4_location_if([[      yystack->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
-      yydestruct ("Error: popping",
-		  yystos[yys->yylrState],
-	          &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
+      if (yys->yyresolved)
+	yydestruct ("Error: popping",
+		    yystos[yys->yylrState],
+		    &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
       yystack->yytops.yystates[0] = yys->yypred;
       yystack->yynextFree -= 1;
       yystack->yyspaceLeft += 1;
@@ -2183,9 +2184,10 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	  {
 	    yyGLRState *yys = yystates[0];
 ]b4_location_if([[	  yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
-)[	    yydestruct ("Cleanup: popping",
-			yystos[yys->yylrState],
-			&yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
+)[	    if (yys->yyresolved)
+	      yydestruct ("Cleanup: popping",
+			  yystos[yys->yylrState],
+			  &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
 	    yystates[0] = yys->yypred;
 	    yystack.yynextFree -= 1;
 	    yystack.yyspaceLeft += 1;
