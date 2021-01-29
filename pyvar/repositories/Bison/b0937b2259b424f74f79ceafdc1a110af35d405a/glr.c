@@ -1106,8 +1106,8 @@ static inline void
 yy_reduce_print (size_t yyk, yyRuleNum yyrule)
 {
   int yyi;
-  YYDPRINTF ((stderr, "Reducing stack %d by rule %d (line %d), ",
-	      yyk, yyrule - 1, yyrline[yyrule]));
+  YYFPRINTF (stderr, "Reducing stack %d by rule %d (line %d), ",
+	     yyk, yyrule - 1, yyrline[yyrule]);
   /* Print the symbols being reduced, and their result.  */
   for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
     YYFPRINTF (stderr, "%s ", yytokenName (yyrhs[yyi]));
@@ -1143,8 +1143,6 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 		  yyLRgotoState (yystack->yytops.yystates[yyk]->yylrState,
 				 yylhsNonterm (yyrule)),
 		  yyposn, yysval, &yyloc]b4_user_args[);
-      YYDPRINTF ((stderr, "Stack %d entering state %d\n",
-		  yyk, yystack->yytops.yystates[yyk]->yylrState));
     }
   else
     {
@@ -1512,6 +1510,7 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
   while (yystack->yytops.yystates[yyk] != NULL)
     {
       yyStateNum yystate = yystack->yytops.yystates[yyk]->yylrState;
+      YYDPRINTF ((stderr, "Stack %d Entering state %d\n", yyk, yystate));
 
       assert (yystate != YYFINAL);
       if (yyisDefaultedState (yystate))
@@ -1711,8 +1710,6 @@ yyrecoverParseError (yyGLRStack* yystack,
 	      YYDPRINTF ((stderr, "Shifting error token, "));
 	      yyglrShift (yystack, 0, yytable[yyj],
 			  yys->yyposn, *yylvalp, yyllocp]b4_user_args[);
-	      YYDPRINTF ((stderr, "Entering state %d\n",
-			  yystack->yytops.yystates[0]->yylrState));
 	      break;
 	    }
 	}
@@ -1783,7 +1780,6 @@ yyrecoverParseError (yyGLRStack* yystack,
       /* For efficiency, we have two loops, the first of which is
 	 specialized to deterministic operation (single stack, no
 	 potential ambiguity).  */
-
       /* Standard mode */
       while (yytrue)
 	{
@@ -1792,6 +1788,7 @@ yyrecoverParseError (yyGLRStack* yystack,
 	  const short* yyconflicts;
 
 	  yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
+          YYDPRINTF ((stderr, "Entering state %d\n", yystate));
 	  if (yystate == YYFINAL)
 	    goto yyDone;
 	  if (yyisDefaultedState (yystate))
@@ -1827,8 +1824,6 @@ yyrecoverParseError (yyGLRStack* yystack,
 		              yylval, yyllocp]b4_user_args[);
 		  if (0 < yystack.yyerrState)
 		    yystack.yyerrState -= 1;
-		  YYDPRINTF ((stderr, "Entering state %d\n",
-			      yystack.yytops.yystates[0]->yylrState));
 		}
 	      else if (yyisErrorAction (yyaction))
 		{
