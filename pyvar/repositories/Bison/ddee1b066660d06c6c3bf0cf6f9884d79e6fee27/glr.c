@@ -1534,18 +1534,27 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
     {
       yyGLRState** yynewStates;
       yybool* yynewLookaheadStatuses;
-      if (! ((yystackp->yytops.yycapacity
-	      <= (YYSIZEMAX / (2 * sizeof yynewStates[0])))
-	     && (yynewStates =
-		 (yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
-					   ((yystackp->yytops.yycapacity *= 2)
-					    * sizeof yynewStates[0])))))
+
+      yynewStates = NULL;
+      
+      if (yystackp->yytops.yycapacity
+	  > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
+	yyMemoryExhausted (yystackp);
+      yystackp->yytops.yycapacity *= 2;
+
+      yynewStates =
+	(yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
+				  (yystackp->yytops.yycapacity
+				   * sizeof yynewStates[0]));
+      if (yynewStates == NULL)
 	yyMemoryExhausted (yystackp);
       yystackp->yytops.yystates = yynewStates;
-      if (! (yynewLookaheadStatuses =
-	     (yybool*) YYREALLOC (yystackp->yytops.yylookaheadStatuses,
-				  ((yystackp->yytops.yycapacity)
-				   * sizeof yynewLookaheadStatuses[0]))))
+
+      yynewLookaheadStatuses =
+	(yybool*) YYREALLOC (yystackp->yytops.yylookaheadStatuses,
+			     (yystackp->yytops.yycapacity
+			      * sizeof yynewLookaheadStatuses[0]));
+      if (yynewLookaheadStatuses == NULL)
 	yyMemoryExhausted (yystackp);
       yystackp->yytops.yylookaheadStatuses = yynewLookaheadStatuses;
     }
