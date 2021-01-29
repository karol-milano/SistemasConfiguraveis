@@ -1698,10 +1698,8 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    while (yystack->yytops.yystates[0] != NULL)
 	      {
 		yyGLRState *yys = yystack->yytops.yystates[0];
-		YY_SYMBOL_PRINT ("Error: popping",
-			         yystos[yys->yylrState],
-			         &yys->yysemantics.yysval, &yys->yyloc);
-		yydestruct (yystos[yys->yylrState],
+		yydestruct ("Error: popping",
+                            yystos[yys->yylrState],
 			    &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
 		yystack->yytops.yystates[0] = yys->yypred;
 		yystack->yynextFree -= 1;
@@ -1710,10 +1708,8 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    yyFail (yystack][]b4_lpure_args[, NULL);
 	  }
 	if (*yytokenp != YYEMPTY)
-	  {
-	    YY_SYMBOL_PRINT ("Error: discarding", *yytokenp, yylvalp, yyllocp);
-	    yydestruct (*yytokenp, yylvalp]b4_location_if([, yyllocp])[);
-	  }
+	  yydestruct ("Error: discarding",
+                      *yytokenp, yylvalp]b4_location_if([, yyllocp])[);
 	YYDPRINTF ((stderr, "Reading a token: "));
 	yychar = YYLEX;
 	*yytokenp = YYTRANSLATE (yychar);
@@ -1760,10 +1756,8 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	      break;
 	    }
 	}
-      YY_SYMBOL_PRINT ("Error: popping",
-		       yystos[yys->yylrState],
-		       &yys->yysemantics.yysval, &yys->yyloc);
-      yydestruct (yystos[yys->yylrState],
+      yydestruct ("Error: popping",
+		  yystos[yys->yylrState],
 	          &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
       yystack->yytops.yystates[0] = yys->yypred;
       yystack->yynextFree -= 1;
@@ -1918,11 +1912,8 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
  yyDone:
   /* On YYABORT, free the lookahead. */
   if (yystack.yyerrflag == 1 && yytoken != YYEMPTY)
-    {
-      YY_SYMBOL_PRINT ("Error: discarding lookahead",
-                       yytoken, yylvalp, yyllocp);
-      yydestruct (yytoken, yylvalp]b4_location_if([, yyllocp])[);
-    }
+    yydestruct ("Error: discarding lookahead",
+                yytoken, yylvalp]b4_location_if([, yyllocp])[);
 
   yyfreeGLRStack (&yystack);
   return yystack.yyerrflag;
