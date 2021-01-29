@@ -509,7 +509,6 @@ do {								\
       YYFPRINTF (stderr, "%s ", Title);				\
       yysymprint (stderr,					\
                   Type, Value]b4_location_if([, Location])[);	\
-      YYFPRINTF (stderr, "\n");					\
     }								\
 } while (0)
 
@@ -575,15 +574,26 @@ typedef struct yyGLRStack yyGLRStack;
 typedef struct yyGLRStateSet yyGLRStateSet;
 
 struct yyGLRState {
+  /** Type tag: always true. */
   yybool yyisState;
+  /** Type tag for yysemantics. If true, yysval applies, otherwise
+   *  yyfirstVal applies. */
   yybool yyresolved;
+  /** Number of corresponding LALR(1) machine state. */
   yyStateNum yylrState;
+  /** Preceding state in this stack */
   yyGLRState* yypred;
+  /** Source position of the first token produced by my symbol */
   size_t yyposn;
   union {
+    /** First in a chain of alternative reductions producing the
+     *  non-terminal corresponding to this state, threaded through 
+     *  yynext. */
     yySemanticOption* yyfirstVal;
+    /** Semantic value for this state. */
     YYSTYPE yysval;
   } yysemantics;
+  /** Source location for this state. */
   YYLTYPE yyloc;
 };
 
@@ -593,12 +603,19 @@ struct yyGLRStateSet {
 };
 
 struct yySemanticOption {
+  /** Type tag: always false. */
   yybool yyisState;
+  /** Rule number for this reduction */
   yyRuleNum yyrule;
+  /** The last RHS state in the list of states to be reduced. */
   yyGLRState* yystate;
+  /** Next sibling in chain of options. To facilitate merging,
+   *  options are chained in decreasing order by address. */
   yySemanticOption* yynext;
 };
 
+/** Type of the items in the GLR stack. The yyisState field 
+ *  indicates which item of the union is valid. */
 union yyGLRStackItem {
   yyGLRState yystate;
   yySemanticOption yyoption;
@@ -1282,9 +1299,8 @@ yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
     return yyfalse;
 }
 
-/** Assuming identicalOptions (Y0,Y1), (destructively) merge the
- *  alternative semantic values for the RHS-symbols of Y1 into the
- *  corresponding semantic value sets of the symbols of Y0. */
+/** Assuming identicalOptions (Y0,Y1), destructively merge the
+ *  alternative semantic values for the RHS-symbols of Y1 and Y0. */
 static void
 yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
 {
@@ -1294,16 +1310,46 @@ yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
        yyn = yyrhsLength (yyy0->yyrule);
        yyn > 0;
        yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
-    if (yys0 == yys1)
-      break;
-    else if (! yys0->yyresolved && ! yys1->yyresolved)
-      {
-	yySemanticOption* yyz;
-	for (yyz = yys0->yysemantics.yyfirstVal; yyz->yynext != NULL;
-	     yyz = yyz->yynext)
-	  continue;
-	yyz->yynext = yys1->yysemantics.yyfirstVal;
-      }
+    {
+      if (yys0 == yys1)
+	break;
+      else if (yys0->yyresolved) 
+	{
+	  yys1->yyresolved = yytrue;
+	  yys1->yysemantics.yysval = yys0->yysemantics.yysval;
+	}
+      else if (yys1->yyresolved)
+	{
+	  yys0->yyresolved = yytrue;
+	  yys0->yysemantics.yysval = yys1->yysemantics.yysval;
+	}
+      else 
+	{
+	  yySemanticOption** yyz0p;
+	  yySemanticOption* yyz1;
+	  yyz0p = &yys0->yysemantics.yyfirstVal;
+	  yyz1 = yys1->yysemantics.yyfirstVal;
+	  while (yytrue)
+	    {
+	      if (yyz1 == *yyz0p || yyz1 == NULL)
+		break;
+	      else if (*yyz0p == NULL)
+		{
+		  *yyz0p = yyz1;
+		  break;
+		}
+	      else if (*yyz0p < yyz1)
+		{
+		  yySemanticOption* yyz = *yyz0p;
+		  *yyz0p = yyz1;
+		  yyz1 = yyz1->yynext;
+		  (*yyz0p)->yynext = yyz;
+		}
+	      yyz0p = &(*yyz0p)->yynext;
+	    }
+	  yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
+	}
+    }
 }
 
 /** Y0 and Y1 represent two possible actions to take in a given
@@ -1579,6 +1625,7 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	      yychar = YYLEX;
 	      *yytokenp = YYTRANSLATE (yychar);
 	      YY_SYMBOL_PRINT ("Next token is", *yytokenp, yylvalp, yyllocp);
+	      YYDPRINTF ((stderr, "\n"));
 	    }
 	  yygetLRActions (yystate, *yytokenp, &yyaction, &yyconflicts);
 
@@ -1744,6 +1791,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	yychar = YYLEX;
 	*yytokenp = YYTRANSLATE (yychar);
 	YY_SYMBOL_PRINT ("Next token is", *yytokenp, yylvalp, yyllocp);
+	YYDPRINTF ((stderr, "\n"));
 	yyj = yypact[yystack->yytops.yystates[0]->yylrState];
 	if (yyis_pact_ninf (yyj))
 	  return;
@@ -1786,6 +1834,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	      YYLLOC_DEFAULT (yyerrloc, yystack->yyerror_range, 2);]])[
 	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
 			       yylvalp, &yyerrloc);
+	      YYDPRINTF ((stderr, "\n"));
 	      yyglrShift (yystack, 0, yytable[yyj],
 			  yys->yyposn, *yylvalp, &yyerrloc]b4_user_args[);
 	      yys = yystack->yytops.yystates[0];
@@ -1905,6 +1954,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		  yychar = YYLEX;
 		  yytoken = YYTRANSLATE (yychar);
                   YY_SYMBOL_PRINT ("Next token is", yytoken, yylvalp, yyllocp);
+                  YYDPRINTF ((stderr, "\n"));
 		}
 	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
 	      if (*yyconflicts != 0)
@@ -1912,6 +1962,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	      if (yyisShiftAction (yyaction))
 		{
 		  YY_SYMBOL_PRINT ("Shifting", yytoken, yylvalp, yyllocp);
+	          YYDPRINTF ((stderr, "\n"));
 		  if (yytoken != YYEOF)
 		    yytoken = YYEMPTY;
 		  yyposn += 1;
