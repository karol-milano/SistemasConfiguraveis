@@ -1019,7 +1019,8 @@ yyremoveDeletes (yyGLRStack* yystack)
 	  yystack->yytops.yystates[yyj] = yystack->yytops.yystates[yyi];
 	  if (yyj != yyi)
 	    {
-	      YYDPRINTF ((stderr, "Rename stack %d -> %d.\n", yyi, yyj));
+	      YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
+			  (unsigned long int) yyi, (unsigned long int) yyj));
 	    }
 	  yyj += 1;
 	}
@@ -1133,9 +1134,9 @@ static inline void
 yy_reduce_print (size_t yyk, yyRuleNum yyrule)
 {
   int yyi;
-  unsigned int yylno = yyrline[yyrule];
-  YYFPRINTF (stderr, "Reducing stack %d by rule %d (line %u), ",
-	     yyk, yyrule - 1, yylno);
+  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu), ",
+	     (unsigned long int) yyk, yyrule - 1,
+	     (unsigned long int) yyrline[yyrule]);
   /* Print the symbols being reduced, and their result.  */
   for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
     YYFPRINTF (stderr, "%s ", yytokenName (yyrhs[yyi]));
@@ -1189,9 +1190,9 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
       yyupdateSplit (yystack, yys);
       yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
       YYDPRINTF ((stderr,
-		  "Reduced stack %d by rule #%d; action deferred. "
+		  "Reduced stack %lu by rule #%d; action deferred. "
 		  "Now in state %d.\n",
-		  yyk, yyrule-1, yynewLRState));
+		  (unsigned long int) yyk, yyrule - 1, yynewLRState));
       for (yyi = 0; yyi < yystack->yytops.yysize; yyi += 1)
 	if (yyi != yyk && yystack->yytops.yystates[yyi] != NULL)
 	  {
@@ -1203,8 +1204,9 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 		  {
 		    yyaddDeferredAction (yystack, yyp, yys0, yyrule]b4_pure_args[);
 		    yymarkStackDeleted (yystack, yyk);
-		    YYDPRINTF ((stderr, "Merging stack %d into stack %d.\n",
-				yyk, yyi));
+		    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
+				(unsigned long int) yyk,
+				(unsigned long int) yyi));
 		    return yyok;
 		  }
 		yyp = yyp->yypred;
@@ -1378,9 +1380,10 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
 	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
 	       yyx->yyrule);
   else
-    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %d .. %d>\n",
+    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
 	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
-	       yyx->yyrule, yys->yyposn+1, yyx->yystate->yyposn);
+	       yyx->yyrule, (unsigned long int) (yys->yyposn + 1),
+	       (unsigned long int) yyx->yystate->yyposn);
   for (yyi = 1; yyi <= yynrhs; yyi += 1)
     {
       if (yystates[yyi]->yyresolved)
@@ -1389,9 +1392,10 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
 	    YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
 		       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]));
 	  else
-	    YYFPRINTF (stderr, "%*s%s <tokens %d .. %d>\n", yyindent+2, "",
+	    YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
 		       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]),
-		       yystates[yyi-1]->yyposn+1, yystates[yyi]->yyposn);
+		       (unsigned long int) (yystates[yyi - 1]->yyposn + 1),
+		       (unsigned long int) yystates[yyi]->yyposn);
 	}
       else
 	yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
