@@ -886,6 +886,26 @@ yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 
 ]b4_yydestruct_generate([b4_c_ansi_function_def])[
 
+static void
+yydestroyStackItem (char const *yymsg, yyGLRState *yys)
+{
+  if (yys->yyresolved)
+    yydestruct (yymsg, yystos[yys->yylrState],
+		&yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
+  else
+    {
+#if YYDEBUG
+      if (yydebug)
+	{
+	  YYFPRINTF (stderr, "%s unresolved ", yymsg);
+	  yysymprint (stderr, yystos[yys->yylrState],
+		      &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
+	  YYFPRINTF (stderr, "\n");
+	}
+#endif
+    }
+}
+
 /** Number of symbols composing the right hand side of rule #RULE. */
 static inline int
 yyrhsLength (yyRuleNum yyrule)
@@ -1981,10 +2001,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    }
 	}
 ]b4_location_if([[      yystack->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
-      if (yys->yyresolved)
-	yydestruct ("Error: popping",
-		    yystos[yys->yylrState],
-		    &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
+      yydestroyStackItem ("Error: popping", yys);
       yystack->yytops.yystates[0] = yys->yypred;
       yystack->yynextFree -= 1;
       yystack->yyspaceLeft += 1;
@@ -2184,10 +2201,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	  {
 	    yyGLRState *yys = yystates[0];
 ]b4_location_if([[	  yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
-)[	    if (yys->yyresolved)
-	      yydestruct ("Cleanup: popping",
-			  yystos[yys->yylrState],
-			  &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
+)[	    yydestroyStackItem ("Cleanup: popping", yys);
 	    yystates[0] = yys->yypred;
 	    yystack.yynextFree -= 1;
 	    yystack.yyspaceLeft += 1;
