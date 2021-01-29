@@ -463,6 +463,17 @@ do {						\
     yysymprint Args;				\
 } while (0)
 
+# define YYDSYMPRINTF(Title, Token, Value, Location)		\
+do {								\
+  if (yydebug)							\
+    {								\
+      YYFPRINTF (stderr, "%s ", Title);				\
+      yysymprint (stderr, 					\
+                  Token, Value]b4_location_if([, Location])[);	\
+      YYFPRINTF (stderr, "\n");					\
+    }								\
+} while (0)
+
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
 int yydebug;
@@ -472,6 +483,7 @@ int yydebug;
   /* Avoid empty `if' bodies.  */
 # define YYDPRINTF(Args)   {}
 # define YYDSYMPRINT(Args) {}
+# define YYDSYMPRINTF(Title, Token, Value, Location) {}
 
 #endif /* !YYDEBUG */
 
@@ -1096,12 +1108,12 @@ static inline void
 yy_reduce_print (size_t yyk, yyRuleNum yyrule)
 {
   int yyi;
-  YYDPRINTF ((stderr, "Reducing stack %d by rule %d (line %d),",
+  YYDPRINTF ((stderr, "Reducing stack %d by rule %d (line %d), ",
 	      yyk, yyrule - 1, yyrline[yyrule]));
   /* Print the symbols being reduced, and their result.  */
   for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
     YYFPRINTF (stderr, "%s ", yytokenName (yyrhs[yyi]));
-  YYFPRINTF (stderr, " -> %s\n", yytokenName (yyr1[yyrule]));
+  YYFPRINTF (stderr, "-> %s\n", yytokenName (yyr1[yyrule]));
 }
 #endif
 
@@ -1522,8 +1534,7 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	      YYDPRINTF ((stderr, "Reading a token: "));
 	      yychar = YYLEX;
 	      *yytokenp = YYTRANSLATE (yychar);
-	      YYDPRINTF ((stderr, "Next token is %s\n",
-			  yytokenName (*yytokenp)));
+	      YYDSYMPRINTF ("Next token is", *yytokenp, yylvalp, yyllocp);
 	    }
 	  yygetLRActions (yystate, *yytokenp, &yyaction, &yyconflicts);
 
@@ -1642,11 +1653,9 @@ yyrecoverParseError (yyGLRStack* yystack,
 	    while (yystack->yytops.yystates[0] != NULL)
 	      {
 		yyGLRState *yys = yystack->yytops.yystates[0];
-		YYDPRINTF ((stderr, "Error: popping "));
-		YYDSYMPRINT ((stderr,
+		YYDSYMPRINTF ("Error: popping",
 			      yystos[yys->yylrState],
-			      &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[));
-		YYDPRINTF ((stderr, "\n"));
+			      &yys->yysemantics.yysval, &yys->yyloc);
 		yydestruct (yystos[yys->yylrState],
 			    &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
 		yystack->yytops.yystates[0] = yys->yypred;
@@ -1657,14 +1666,13 @@ yyrecoverParseError (yyGLRStack* yystack,
 	  }
 	if (*yytokenp != YYEMPTY)
 	  {
-	    YYDPRINTF ((stderr, "Discarding token %s\n",
-			yytokenName (*yytokenp)));
+	    YYDSYMPRINTF ("Error: discarding", *yytokenp, yylvalp, yyllocp);
 	    yydestruct (*yytokenp, yylvalp]b4_location_if([, yyllocp])[);
 	  }
 	YYDPRINTF ((stderr, "Reading a token: "));
 	yychar = YYLEX;
 	*yytokenp = YYTRANSLATE (yychar);
-	YYDPRINTF ((stderr, "Next token is %s\n", yytokenName (*yytokenp)));
+	YYDSYMPRINTF ("Next token is", *yytokenp, yylvalp, yyllocp);
 	yyj = yypact[yystack->yytops.yystates[0]->yylrState];
 	if (yyis_pact_ninf (yyj))
 	  /* Something's not right; we shouldn't be here.  */
@@ -1704,14 +1712,14 @@ yyrecoverParseError (yyGLRStack* yystack,
 	      YYDPRINTF ((stderr, "Shifting error token, "));
 	      yyglrShift (yystack, 0, yytable[yyj],
 			  yys->yyposn, *yylvalp, yyllocp]b4_user_args[);
+	      YYDPRINTF ((stderr, "Entering state %d\n",
+			  yystack->yytops.yystates[0]->yylrState));
 	      break;
 	    }
 	}
-      YYDPRINTF ((stderr, "Error: popping "));
-      YYDSYMPRINT ((stderr,
+      YYDSYMPRINTF ("Error: popping",
  		    yystos[yys->yylrState],
- 		    &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[));
-      YYDPRINTF ((stderr, "\n"));
+ 		    &yys->yysemantics.yysval, &yys->yyloc);
       yydestruct (yystos[yys->yylrState],
  	          &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
       yystack->yytops.yystates[0] = yys->yypred;
@@ -1804,8 +1812,7 @@ yyrecoverParseError (yyGLRStack* yystack,
 		  YYDPRINTF ((stderr, "Reading a token: "));
 		  yychar = YYLEX;
 		  yytoken = YYTRANSLATE (yychar);
-		  YYDPRINTF ((stderr, "Next token is %s\n",
-			      yytokenName (yytoken)));
+                  YYDSYMPRINTF ("Next token is", yytoken, yylvalp, yyllocp);
 		}
 	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
 	      if (*yyconflicts != 0)
