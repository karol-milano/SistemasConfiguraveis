@@ -481,9 +481,9 @@ int yydebug;
 #else /* !YYDEBUG */
 
   /* Avoid empty `if' bodies.  */
-# define YYDPRINTF(Args)   {}
-# define YYDSYMPRINT(Args) {}
-# define YYDSYMPRINTF(Title, Token, Value, Location) {}
+# define YYDPRINTF(Args)
+# define YYDSYMPRINT(Args)
+# define YYDSYMPRINTF(Title, Token, Value, Location)
 
 #endif /* !YYDEBUG */
 
@@ -790,14 +790,6 @@ yyisErrorAction (int yyaction)
 
 				/* GLRStates */
 
-/** True iff the semantic value of the edge leading to STATE is
- *  resolved. */
-static inline bool
-yyhasResolvedValue (yyGLRState* yystate)
-{
-  return yystate->yyresolved;
-}
-
 static void
 yyaddDeferredAction (yyGLRStack* yystack, yyGLRState* yystate,
 		     yyGLRState* rhs, yyRuleNum yyrule]b4_pure_formals[)
@@ -967,14 +959,18 @@ yyremoveDeletes (yyGLRStack* yystack)
       if (yystack->yytops.yystates[yyi] == NULL)
 	{
 	  if (yyi == yyj)
-	    YYDPRINTF ((stderr, "Removing dead stacks.\n"));
+	    {
+	      YYDPRINTF ((stderr, "Removing dead stacks.\n"));
+	    }
 	  yystack->yytops.yysize -= 1;
 	}
       else
 	{
 	  yystack->yytops.yystates[yyj] = yystack->yytops.yystates[yyi];
 	  if (yyj != yyi)
-	    YYDPRINTF ((stderr, "Rename stack %d -> %d.\n", yyi, yyj));
+	    {
+	      YYDPRINTF ((stderr, "Rename stack %d -> %d.\n", yyi, yyj));
+	    }
 	  yyj += 1;
 	}
       yyi += 1;
@@ -1250,7 +1246,7 @@ yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
 	yySemanticOption* yyz;
 	for (yyz = yys0->yysemantics.yyfirstVal; yyz->yynext != NULL;
 	     yyz = yyz->yynext)
-	  ;
+	  continue;
 	yyz->yynext = yys1->yysemantics.yyfirstVal;
       }
 }
@@ -1460,7 +1456,7 @@ yyresolveStack (yyGLRStack* yystack]b4_user_formals[)
       for (yyn = 0, yys = yystack->yytops.yystates[0];
 	   yys != yystack->yysplitPoint;
 	   yys = yys->yypred, yyn += 1)
-	;
+	continue;
       YYCHK (yyresolveStates (yystack->yytops.yystates[0], yyn, yystack
 			     ]b4_user_args[));
     }
@@ -1571,8 +1567,8 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 }
 
 static void
-yyreportParseError (yyGLRStack* yystack,
-		    YYSTYPE* yylvalp, YYLTYPE* yyllocp]b4_user_formals[)
+yyreportSyntaxError (yyGLRStack* yystack,
+		     YYSTYPE* yylvalp, YYLTYPE* yyllocp]b4_user_formals[)
 {
   /* `Unused' warnings. */
   (void) yylvalp;
@@ -1630,8 +1626,8 @@ yyreportParseError (yyGLRStack* yystack,
    YYLVALP, and YYLLOCP point to the syntactic category, semantic
    value, and location of the lookahead.  */
 static void
-yyrecoverParseError (yyGLRStack* yystack,
-		     YYSTYPE* yylvalp, YYLTYPE* yyllocp]b4_user_formals[)
+yyrecoverSyntaxError (yyGLRStack* yystack,
+		      YYSTYPE* yylvalp, YYLTYPE* yyllocp]b4_user_formals[)
 {
   yySymbol* const yytokenp = yystack->yytokenp;
   size_t yyk;
@@ -1796,7 +1792,7 @@ yyrecoverParseError (yyGLRStack* yystack,
 	      yyrule = yydefaultAction (yystate);
 	      if (yyrule == 0)
 		{
-		  yyreportParseError (&yystack, yylvalp, yyllocp]b4_user_args[);
+		  yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 		  goto yyuser_error;
 		}
 	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue]b4_lpure_args[));
@@ -1827,7 +1823,7 @@ yyrecoverParseError (yyGLRStack* yystack,
 		}
 	      else if (yyisErrorAction (yyaction))
 		{
-		  yyreportParseError (&yystack, yylvalp, yyllocp]b4_user_args[);
+		  yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 		  goto yyuser_error;
 		}
 	      else
@@ -1852,7 +1848,7 @@ yyrecoverParseError (yyGLRStack* yystack,
 		yyFail (&yystack][]b4_lpure_args[, "syntax error");
 	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
 	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
-	      yyreportParseError (&yystack, yylvalp, yyllocp]b4_user_args[);
+	      yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 	      goto yyuser_error;
 	    }
 	  else if (yystack.yytops.yysize == 1)
@@ -1865,7 +1861,7 @@ yyrecoverParseError (yyGLRStack* yystack,
 	}
       continue;
     yyuser_error:
-      yyrecoverParseError (&yystack, yylvalp, yyllocp]b4_user_args[);
+      yyrecoverSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
       yyposn = yystack.yytops.yystates[0]->yyposn;
     }
  yyDone:
