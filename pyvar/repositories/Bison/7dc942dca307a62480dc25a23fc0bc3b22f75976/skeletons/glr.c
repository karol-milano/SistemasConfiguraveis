@@ -2651,6 +2651,7 @@ b4_dollar_popdef])[]dnl
 
 /* DEBUGGING ONLY */
 #if ]b4_api_PREFIX[DEBUG
+/* Print *YYS and its predecessors. */
 static void
 yy_yypstack (yyGLRState* yys)
 {
@@ -2662,22 +2663,25 @@ yy_yypstack (yyGLRState* yys)
   YY_FPRINTF ((stderr, "%d@@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
 }
 
+/* Print YYS (possibly NULL) and its predecessors. */
 static void
-yypstates (yyGLRState* yyst)
+yypstates (yyGLRState* yys)
 {
-  if (yyst == YY_NULLPTR)
+  if (yys == YY_NULLPTR)
     YY_FPRINTF ((stderr, "<null>"));
   else
-    yy_yypstack (yyst);
+    yy_yypstack (yys);
   YY_FPRINTF ((stderr, "\n"));
 }
 
+/* Print the stack #YYK.  */
 static void
 yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
 {
   yypstates (yystackp->yytops.yystates[yyk]);
 }
 
+/* Print all the stacks.  */
 static void
 yypdumpstack (yyGLRStack* yystackp)
 {
