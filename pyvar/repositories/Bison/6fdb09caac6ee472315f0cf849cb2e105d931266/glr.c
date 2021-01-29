@@ -2107,17 +2107,21 @@ b4_syncline([@oline@], [@ofile@])])dnl
                 yytoken, yylvalp]b4_location_if([, yyllocp])[);
 
   /* Now pop stack until empty, destroying its entries as we go.  */
-  while (yystack.yytops.yystates[0] != NULL)
-    {
-      yyGLRState *yys = yystack.yytops.yystates[0];
-]b4_location_if([[      yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
-      yydestruct ("Error: popping",
-		  yystos[yys->yylrState],
-		  &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
-      yystack.yytops.yystates[0] = yys->yypred;
-      yystack.yynextFree -= 1;
-      yystack.yyspaceLeft += 1;
-    }
+  {
+    yyGLRState** yystates = yystack.yytops.yystates;
+    if (yystates)
+      while (yystates[0])
+	{
+	  yyGLRState *yys = yystates[0];
+]b4_location_if([[	  yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
+)[	  yydestruct ("Error: popping",
+		      yystos[yys->yylrState],
+		      &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
+	  yystates[0] = yys->yypred;
+	  yystack.yynextFree -= 1;
+	  yystack.yyspaceLeft += 1;
+	}
+  }
 
   yyfreeGLRStack (&yystack);
   return yyresult;
