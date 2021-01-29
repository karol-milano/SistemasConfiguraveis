@@ -113,7 +113,7 @@ m4_define([b4_lhs_value],
 # Expansion of $<TYPE>NUM, where the current rule has RULE-LENGTH
 # symbols on RHS.
 m4_define([b4_rhs_value],
-[(((yyGLRStackItem const *)yyvsp)@{YYFILL (m4_eval([$2 - $1]))@}.yystate.yysemantics.yysval[]m4_ifval([$3], [.$3]))])
+[(((yyGLRStackItem const *)yyvsp)@{YYFILL ($2 - $1)@}.yystate.yysemantics.yysval[]m4_ifval([$3], [.$3]))])
 
 
 
@@ -133,7 +133,7 @@ m4_define([b4_lhs_location],
 # Expansion of @NUM, where the current rule has RULE-LENGTH symbols
 # on RHS.
 m4_define([b4_rhs_location],
-[(((yyGLRStackItem const *)yyvsp)@{YYFILL (m4_eval([$2 - $1]))@}.yystate.yyloc)])
+[(((yyGLRStackItem const *)yyvsp)@{YYFILL ($2 - $1)@}.yystate.yyloc)])
 
 # We do want M4 expansion after # for CPP macros.
 m4_changecom()
@@ -956,9 +956,9 @@ yylhsNonterm (yyRuleNum yyrule)
 }
 
 #define yyis_pact_ninf(yystate) \
-  ]m4_if(m4_eval(b4_pact_ninf < b4_pact_min), 1,
-	 0,
-	 ((yystate) == YYPACT_NINF))[
+  ]m4_if(m4_eval(b4_pact_ninf < b4_pact_min), [1],
+	 [0],
+	 [((yystate) == YYPACT_NINF)])[
 
 /** True iff LR state STATE has only a default reduction (regardless
  *  of token). */
@@ -976,9 +976,9 @@ yydefaultAction (yyStateNum yystate)
 }
 
 #define yyis_table_ninf(yytable_value) \
-  ]m4_if(m4_eval(b4_table_ninf < b4_table_min), 1,
-	 0,
-	 ((yytable_value) == YYTABLE_NINF))[
+  ]m4_if(m4_eval(b4_table_ninf < b4_table_min), [1],
+	 [0],
+	 [((yytable_value) == YYTABLE_NINF)])[
 
 /** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
  *  Result R means
@@ -1328,12 +1328,12 @@ yydoAction (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 }
 
 #if !YYDEBUG
-# define YY_REDUCE_PRINT(K, Rule)
+# define YY_REDUCE_PRINT(Args)
 #else
-# define YY_REDUCE_PRINT(K, Rule)	\
+# define YY_REDUCE_PRINT(Args)		\
 do {					\
   if (yydebug)				\
-    yy_reduce_print (K, Rule);		\
+    yy_reduce_print Args;		\
 } while (/*CONSTCOND*/ 0)
 
 /*----------------------------------------------------------.
@@ -1341,16 +1341,29 @@ do {					\
 `----------------------------------------------------------*/
 
 static inline void
-yy_reduce_print (size_t yyk, yyRuleNum yyrule)
+yy_reduce_print (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
+		 YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
+  int yynrhs = yyrhsLength (yyrule);
+  yybool yynormal __attribute__ ((__unused__)) =
+    (yystack->yysplitPoint == NULL);
+  yyGLRStackItem* yyvsp = (yyGLRStackItem*) yystack->yytops.yystates[yyk];
+  int yylow = 1;
   int yyi;
-  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu), ",
+  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
 	     (unsigned long int) yyk, yyrule - 1,
 	     (unsigned long int) yyrline[yyrule]);
   /* Print the symbols being reduced, and their result.  */
-  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
-    YYFPRINTF (stderr, "%s ", yytokenName (yyrhs[yyi]));
-  YYFPRINTF (stderr, "-> %s\n", yytokenName (yyr1[yyrule]));
+  //for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
+  for (yyi = 0; yyi < yynrhs; yyi++)
+    {
+      fprintf (stderr, "   $%d = ", yyi);
+      yysymprint (stderr, yyrhs[yyprhs[yyrule] + yyi],
+                  &]b4_rhs_value(yynrhs, yyi)[
+                  ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi))[]dnl
+	          b4_user_args[);
+      fprintf (stderr, "\n");
+    }
 }
 #endif
 
@@ -1376,8 +1389,9 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
       YYSTYPE yysval;
       YYLTYPE yyloc;
 
-      YY_REDUCE_PRINT (yyk, yyrule);
+      YY_REDUCE_PRINT ((yystack, yyk, yyrule, &yysval, &yyloc]b4_user_args[));
       YYCHK (yydoAction (yystack, yyk, yyrule, &yysval, &yyloc]b4_user_args[));
+      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
       yyglrShift (yystack, yyk,
 		  yyLRgotoState (yystack->yytops.yystates[yyk]->yylrState,
 				 yylhsNonterm (yyrule)),
