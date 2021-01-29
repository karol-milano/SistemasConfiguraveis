@@ -1284,17 +1284,6 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
 }
 
 #if YYDEBUG
-static yyGLRState YYLEFTMOST_STATE =
-  {
-    0, 0, -1, NULL, 0, { NULL },
-    /* yyloc.  */
-    {
-#if YYLTYPE_IS_TRIVIAL
-]b4_location_if([      0, 0, 0, 0])[
-#endif
-    }
-  };
-
 static void
 yyreportTree (yySemanticOption* yyx, int yyindent)
 {
@@ -1302,11 +1291,15 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
   int yyi;
   yyGLRState* yys;
   yyGLRState* yystates[YYMAXRHS];
+  yyGLRState yyleftmost_state;
 
   for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
     yystates[yyi] = yys;
   if (yys == NULL)
-    yystates[0] = &YYLEFTMOST_STATE;
+    {
+      yyleftmost_state.yyposn = 0;
+      yystates[0] = &yyleftmost_state;
+    }
   else
     yystates[0] = yys;
 
