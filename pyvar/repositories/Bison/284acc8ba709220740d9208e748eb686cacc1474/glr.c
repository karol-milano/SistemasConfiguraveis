@@ -479,19 +479,13 @@ do {						\
 
 ]b4_yysymprint_generate([b4_c_ansi_function_def])[
 
-# define YYDSYMPRINT(Args)			\
-do {						\
-  if (yydebug)					\
-    yysymprint Args;				\
-} while (0)
-
-# define YYDSYMPRINTF(Title, Token, Value, Location)		\
+# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
 do {								\
   if (yydebug)							\
     {								\
       YYFPRINTF (stderr, "%s ", Title);				\
       yysymprint (stderr,					\
-                  Token, Value]b4_location_if([, Location])[);	\
+                  Type, Value]b4_location_if([, Location])[);	\
       YYFPRINTF (stderr, "\n");					\
     }								\
 } while (0)
@@ -502,10 +496,8 @@ int yydebug;
 
 #else /* !YYDEBUG */
 
-  /* Avoid empty `if' bodies.  */
 # define YYDPRINTF(Args)
-# define YYDSYMPRINT(Args)
-# define YYDSYMPRINTF(Title, Token, Value, Location)
+# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 
 #endif /* !YYDEBUG */
 
@@ -1568,7 +1560,7 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	      YYDPRINTF ((stderr, "Reading a token: "));
 	      yychar = YYLEX;
 	      *yytokenp = YYTRANSLATE (yychar);
-	      YYDSYMPRINTF ("Next token is", *yytokenp, yylvalp, yyllocp);
+	      YY_SYMBOL_PRINT ("Next token is", *yytokenp, yylvalp, yyllocp);
 	    }
 	  yygetLRActions (yystate, *yytokenp, &yyaction, &yyconflicts);
 
@@ -1706,9 +1698,9 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    while (yystack->yytops.yystates[0] != NULL)
 	      {
 		yyGLRState *yys = yystack->yytops.yystates[0];
-		YYDSYMPRINTF ("Error: popping",
-			      yystos[yys->yylrState],
-			      &yys->yysemantics.yysval, &yys->yyloc);
+		YY_SYMBOL_PRINT ("Error: popping",
+			         yystos[yys->yylrState],
+			         &yys->yysemantics.yysval, &yys->yyloc);
 		yydestruct (yystos[yys->yylrState],
 			    &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
 		yystack->yytops.yystates[0] = yys->yypred;
@@ -1719,13 +1711,13 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	  }
 	if (*yytokenp != YYEMPTY)
 	  {
-	    YYDSYMPRINTF ("Error: discarding", *yytokenp, yylvalp, yyllocp);
+	    YY_SYMBOL_PRINT ("Error: discarding", *yytokenp, yylvalp, yyllocp);
 	    yydestruct (*yytokenp, yylvalp]b4_location_if([, yyllocp])[);
 	  }
 	YYDPRINTF ((stderr, "Reading a token: "));
 	yychar = YYLEX;
 	*yytokenp = YYTRANSLATE (yychar);
-	YYDSYMPRINTF ("Next token is", *yytokenp, yylvalp, yyllocp);
+	YY_SYMBOL_PRINT ("Next token is", *yytokenp, yylvalp, yyllocp);
 	yyj = yypact[yystack->yytops.yystates[0]->yylrState];
 	if (yyis_pact_ninf (yyj))
 	  return;
@@ -1768,9 +1760,9 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	      break;
 	    }
 	}
-      YYDSYMPRINTF ("Error: popping",
-		    yystos[yys->yylrState],
-		    &yys->yysemantics.yysval, &yys->yyloc);
+      YY_SYMBOL_PRINT ("Error: popping",
+		       yystos[yys->yylrState],
+		       &yys->yysemantics.yysval, &yys->yyloc);
       yydestruct (yystos[yys->yylrState],
 	          &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
       yystack->yytops.yystates[0] = yys->yypred;
@@ -1863,7 +1855,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 		  YYDPRINTF ((stderr, "Reading a token: "));
 		  yychar = YYLEX;
 		  yytoken = YYTRANSLATE (yychar);
-                  YYDSYMPRINTF ("Next token is", yytoken, yylvalp, yyllocp);
+                  YY_SYMBOL_PRINT ("Next token is", yytoken, yylvalp, yyllocp);
 		}
 	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
 	      if (*yyconflicts != 0)
