@@ -1846,21 +1846,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
     while (yytrue)
       {
 	if (*yytokenp == YYEOF)
-	  {
-	    /* Now pop stack until empty and fail. */
-	    while (yystack->yytops.yystates[0] != NULL)
-	      {
-		yyGLRState *yys = yystack->yytops.yystates[0];
-]b4_location_if([[		yystack->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
-		yydestruct ("Error: popping",
-                            yystos[yys->yylrState],
-			    &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
-		yystack->yytops.yystates[0] = yys->yypred;
-		yystack->yynextFree -= 1;
-		yystack->yyspaceLeft += 1;
-	      }
-	    yyFail (yystack][]b4_lpure_args[, NULL);
-	  }
+	  yyFail (yystack][]b4_lpure_args[, NULL);
 	if (*yytokenp != YYEMPTY)
 	  {]b4_location_if([[
 	    /* We throw away the lookahead, but the error range
@@ -2122,6 +2108,19 @@ b4_syncline([@oline@], [@ofile@])])dnl
     yydestruct ("Error: discarding lookahead",
                 yytoken, yylvalp]b4_location_if([, yyllocp])[);
 
+  /* Now pop stack until empty, destroying its entries as we go.  */
+  while (yystack.yytops.yystates[0] != NULL)
+    {
+      yyGLRState *yys = yystack.yytops.yystates[0];
+]b4_location_if([[      yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
+      yydestruct ("Error: popping",
+		  yystos[yys->yylrState],
+		  &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
+      yystack.yytops.yystates[0] = yys->yypred;
+      yystack.yynextFree -= 1;
+      yystack.yyspaceLeft += 1;
+    }
+
   yyfreeGLRStack (&yystack);
   return yyresult;
 }
