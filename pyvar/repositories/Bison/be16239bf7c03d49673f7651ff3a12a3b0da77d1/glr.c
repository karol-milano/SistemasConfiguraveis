@@ -876,7 +876,7 @@ yyinitStateSet (yyGLRStateSet* yyset)
 {
   yyset->yysize = 1;
   yyset->yycapacity = 16;
-  yyset->yystates = YYMALLOC (16 * sizeof yyset->yystates[0]);
+  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
   yyset->yystates[0] = NULL;
 }
 
@@ -895,7 +895,7 @@ yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
   yynerrs = 0;
   yystack->yyspaceLeft = yysize;
   yystack->yynextFree = yystack->yyitems =
-    YYMALLOC (yysize * sizeof yystack->yynextFree[0]);
+    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystack->yynextFree[0]);
   yystack->yysplitPoint = NULL;
   yystack->yylastDeleted = NULL;
   yyinitStateSet (&yystack->yytops);
@@ -1237,9 +1237,9 @@ yysplitStack (yyGLRStack* yystack, int yyk)
     {
       yystack->yytops.yycapacity *= 2;
       yystack->yytops.yystates =
-	YYREALLOC (yystack->yytops.yystates,
-		   (yystack->yytops.yycapacity
-		    * sizeof yystack->yytops.yystates[0]));
+	(yyGLRState**) YYREALLOC (yystack->yytops.yystates,
+				  (yystack->yytops.yycapacity
+				   * sizeof yystack->yytops.yystates[0]));
     }
   yystack->yytops.yystates[yystack->yytops.yysize]
     = yystack->yytops.yystates[yyk];
@@ -1649,7 +1649,7 @@ yyreportSyntaxError (yyGLRStack* yystack,
 	      }
 	  yysize += (sizeof ("syntax error, unexpected ")
 		     + strlen (yytokenName (*yytokenp)));
-	  yymsg = YYMALLOC (yysize);
+	  yymsg = (char*) YYMALLOC (yysize);
 	  if (yymsg != 0)
 	    {
 	      char* yyp = yymsg;
