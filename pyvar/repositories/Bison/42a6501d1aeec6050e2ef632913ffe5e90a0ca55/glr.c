@@ -886,8 +886,15 @@ yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 
 ]b4_yydestruct_generate([b4_c_ansi_function_def])[
 
+/** Number of symbols composing the right hand side of rule #RULE.  */
+static inline int
+yyrhsLength (yyRuleNum yyrule)
+{
+  return yyr2[yyrule];
+}
+
 static void
-yydestroyStackItem (char const *yymsg, yyGLRState *yys)
+yydestroyGLRState (char const *yymsg, yyGLRState *yys)
 {
   if (yys->yyresolved)
     yydestruct (yymsg, yystos[yys->yylrState],
@@ -903,14 +910,18 @@ yydestroyStackItem (char const *yymsg, yyGLRState *yys)
 	  YYFPRINTF (stderr, "\n");
 	}
 #endif
-    }
-}
 
-/** Number of symbols composing the right hand side of rule #RULE. */
-static inline int
-yyrhsLength (yyRuleNum yyrule)
-{
-  return yyr2[yyrule];
+      if (yys->yysemantics.yyfirstVal)
+        {
+          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
+          yyGLRState *yyrhs;
+          int yyn;
+          for (yyrhs = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
+               yyn > 0;
+               yyrhs = yyrhs->yypred, yyn -= 1)
+            yydestroyGLRState (yymsg, yyrhs);
+        }
+    }
 }
 
 /** Left-hand-side symbol for rule #RULE. */
@@ -2001,7 +2012,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    }
 	}
 ]b4_location_if([[      yystack->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
-      yydestroyStackItem ("Error: popping", yys);
+      yydestroyGLRState ("Error: popping", yys);
       yystack->yytops.yystates[0] = yys->yypred;
       yystack->yynextFree -= 1;
       yystack->yyspaceLeft += 1;
@@ -2201,7 +2212,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	  {
 	    yyGLRState *yys = yystates[0];
 ]b4_location_if([[	  yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
-)[	    yydestroyStackItem ("Cleanup: popping", yys);
+)[	    yydestroyGLRState ("Cleanup: popping", yys);
 	    yystates[0] = yys->yypred;
 	    yystack.yynextFree -= 1;
 	    yystack.yyspaceLeft += 1;
