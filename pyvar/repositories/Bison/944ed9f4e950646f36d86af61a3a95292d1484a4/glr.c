@@ -707,12 +707,17 @@ yylhsNonterm (yyRuleNum yyrule)
   return yyr1[yyrule];
 }
 
+#define yyis_pact_ninf(yystate) \
+  ]m4_if(m4_eval(b4_pact_ninf < b4_pact_min), 1,
+	 0,
+	 ((yystate) == YYPACT_NINF))[
+
 /** True iff LR state STATE has only a default reduction (regardless
  *  of token). */
 static inline bool
 yyisDefaultedState (yyStateNum yystate)
 {
-  return yypact[yystate] == YYPACT_NINF;
+  return yyis_pact_ninf (yypact[yystate]);
 }
 
 /** The default reduction for STATE, assuming it has one. */
@@ -722,6 +727,11 @@ yydefaultAction (yyStateNum yystate)
   return yydefact[yystate];
 }
 
+#define yyis_table_ninf(yyindex) \
+  ]m4_if(m4_eval(b4_table_ninf < b4_table_min), 1,
+	 0,
+	 ((yyindex) == YYTABLE_NINF))[
+
 /** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
  *  Result R means
  *    R < 0:  Reduce on rule -R.
@@ -740,7 +750,7 @@ yygetLRActions (yyStateNum yystate, int yytoken,
       *yyaction = -yydefact[yystate];
       *yyconflicts = yyconfl;
     }
-  else if (yytable[yyindex] != YYTABLE_NINF)
+  else if (! yyis_table_ninf (yyindex))
     {
       *yyaction = yytable[yyindex];
       *yyconflicts = yyconfl + yyconflp[yyindex];
@@ -1645,7 +1655,7 @@ yyrecoverParseError (yyGLRStack* yystack,
 	*yytokenp = YYTRANSLATE (yychar);
 	YYDPRINTF ((stderr, "Next token is %s\n", yytokenName (*yytokenp)));
 	yyj = yypact[yystack->yytops.yystates[0]->yylrState];
-	if (yyj == YYPACT_NINF)
+	if (yyis_pact_ninf (yyj))
 	  /* Something's not right; we shouldn't be here.  */
 	  yyFail (yystack][]b4_lpure_args[, NULL);
 	yyj += *yytokenp;
@@ -1654,7 +1664,7 @@ yyrecoverParseError (yyGLRStack* yystack,
 	    if (yydefact[yystack->yytops.yystates[0]->yylrState] != 0)
 	      return;
 	  }
-	else if (yytable[yyj] != 0 && yytable[yyj] != YYTABLE_NINF)
+	else if (yytable[yyj] != 0 && ! yyis_table_ninf (yytable[yyj]))
 	  return;
       }
 
@@ -1672,14 +1682,18 @@ yyrecoverParseError (yyGLRStack* yystack,
   /* Now pop stack until we find a state that shifts the error token. */
   while (yystack->yytops.yystates[0] != NULL)
     {
-      yyj = yypact[yystack->yytops.yystates[0]->yylrState] + YYTERROR;
-      if (yyj != YYPACT_NINF + YYTERROR && yyj >= 0 && yyj <= YYLAST &&
-	  yycheck[yyj] == YYTERROR && yyisShiftAction (yytable[yyj]))
+      yyj = yypact[yystack->yytops.yystates[0]->yylrState];
+      if (! yyis_pact_ninf (yyj))
 	{
-	  yyglrShift (yystack, 0, yytable[yyj],
-		      yystack->yytops.yystates[0]->yyposn,
-		      *yylvalp, yyllocp]b4_user_args[);
-	  break;
+	  yyj += YYTERROR;
+	  if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
+	      && yyisShiftAction (yytable[yyj]))
+	    {
+	      yyglrShift (yystack, 0, yytable[yyj],
+			  yystack->yytops.yystates[0]->yyposn,
+			  *yylvalp, yyllocp]b4_user_args[);
+	      break;
+	    }
 	}
       yystack->yytops.yystates[0] = yystack->yytops.yystates[0]->yypred;
       yystack->yynextFree -= 1;
