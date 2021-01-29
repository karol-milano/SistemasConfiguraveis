@@ -532,6 +532,7 @@ do {								\
       YYFPRINTF (stderr, "%s ", Title);				\
       yysymprint (stderr,					\
                   Type, Value]b4_location_if([, Location])[);	\
+      YYFPRINTF (stderr, "\n");					\
     }								\
 } while (0)
 
@@ -1748,7 +1749,6 @@ yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
 	      yychar = YYLEX;
 	      *yytokenp = YYTRANSLATE (yychar);
 	      YY_SYMBOL_PRINT ("Next token is", *yytokenp, yylvalp, yyllocp);
-	      YYDPRINTF ((stderr, "\n"));
 	    }
 	  yygetLRActions (yystate, *yytokenp, &yyaction, &yyconflicts);
 
@@ -1771,7 +1771,8 @@ yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
 	      YY_SYMBOL_PRINT ("shifting", *yytokenp, yylvalp, yyllocp);
 	      yyglrShift (yystack, yyk, yyaction, yyposn+1,
 			  *yylvalp, yyllocp);
-	      YYDPRINTF ((stderr, ", now in state #%d\n",
+	      YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
+			  (unsigned long int) yyk,
 			  yystack->yytops.yystates[yyk]->yylrState));
 	      break;
 	    }
@@ -1931,7 +1932,6 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	yychar = YYLEX;
 	*yytokenp = YYTRANSLATE (yychar);
 	YY_SYMBOL_PRINT ("Next token is", *yytokenp, yylvalp, yyllocp);
-	YYDPRINTF ((stderr, "\n"));
 	yyj = yypact[yystack->yytops.yystates[0]->yylrState];
 	if (yyis_pact_ninf (yyj))
 	  return;
@@ -1974,7 +1974,6 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	      YYLLOC_DEFAULT (yyerrloc, yystack->yyerror_range, 2);]])[
 	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
 			       yylvalp, &yyerrloc);
-	      YYDPRINTF ((stderr, "\n"));
 	      yyglrShift (yystack, 0, yytable[yyj],
 			  yys->yyposn, *yylvalp, &yyerrloc);
 	      yys = yystack->yytops.yystates[0];
@@ -2095,7 +2094,6 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		  yychar = YYLEX;
 		  yytoken = YYTRANSLATE (yychar);
                   YY_SYMBOL_PRINT ("Next token is", yytoken, yylvalp, yyllocp);
-                  YYDPRINTF ((stderr, "\n"));
 		}
 	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
 	      if (*yyconflicts != 0)
@@ -2103,7 +2101,6 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	      if (yyisShiftAction (yyaction))
 		{
 		  YY_SYMBOL_PRINT ("Shifting", yytoken, yylvalp, yyllocp);
-	          YYDPRINTF ((stderr, "\n"));
 		  if (yytoken != YYEOF)
 		    yytoken = YYEMPTY;
 		  yyposn += 1;
