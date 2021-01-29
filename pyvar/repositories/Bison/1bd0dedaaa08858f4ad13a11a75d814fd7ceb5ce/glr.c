@@ -920,12 +920,12 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys)
       if (yys->yysemantics.yyfirstVal)
         {
           yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
-          yyGLRState *yyrhs;
+          yyGLRState *yyrh;
           int yyn;
-          for (yyrhs = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
+          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
                yyn > 0;
-               yyrhs = yyrhs->yypred, yyn -= 1)
-            yydestroyGLRState (yymsg, yyrhs);
+               yyrh = yyrh->yypred, yyn -= 1)
+            yydestroyGLRState (yymsg, yyrh);
         }
     }
 }
