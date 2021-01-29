@@ -1018,11 +1018,14 @@ yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
   yystack->yyerrState = 0;
   yynerrs = 0;
   yystack->yyspaceLeft = yysize;
-  yystack->yynextFree = yystack->yyitems =
+  yystack->yyitems =
     (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystack->yynextFree[0]);
+  if (!yystack->yyitems)
+    return yyfalse;
+  yystack->yynextFree = yystack->yyitems;
   yystack->yysplitPoint = NULL;
   yystack->yylastDeleted = NULL;
-  return yyinitStateSet (&yystack->yytops) && yystack->yyitems;
+  return yyinitStateSet (&yystack->yytops);
 }
 
 #define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
@@ -2154,24 +2157,27 @@ b4_syncline([@oline@], [@ofile@])])dnl
     yydestruct ("Error: discarding lookahead",
                 yytoken, yylvalp]b4_location_if([, yyllocp])[);
 
-  /* Now pop stack until empty, destroying its entries as we go.  */
-  {
-    yyGLRState** yystates = yystack.yytops.yystates;
-    if (yystates)
-      while (yystates[0])
-	{
-	  yyGLRState *yys = yystates[0];
+  /* If the stack is well-formed, pop the stack until it is empty,
+     destroying its entries as we go.  But free the stack regardless
+     of whether it is well-formed.  */
+  if (yystack.yyitems)
+    {
+      yyGLRState** yystates = yystack.yytops.yystates;
+      if (yystates)
+	while (yystates[0])
+	  {
+	    yyGLRState *yys = yystates[0];
 ]b4_location_if([[	  yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
-)[	  yydestruct ("Error: popping",
-		      yystos[yys->yylrState],
-		      &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
-	  yystates[0] = yys->yypred;
-	  yystack.yynextFree -= 1;
-	  yystack.yyspaceLeft += 1;
-	}
-  }
+)[	    yydestruct ("Error: popping",
+			yystos[yys->yylrState],
+			&yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
+	    yystates[0] = yys->yypred;
+	    yystack.yynextFree -= 1;
+	    yystack.yyspaceLeft += 1;
+	  }
+      yyfreeGLRStack (&yystack);
+    }
 
-  yyfreeGLRStack (&yystack);
   return yyresult;
 }
 
