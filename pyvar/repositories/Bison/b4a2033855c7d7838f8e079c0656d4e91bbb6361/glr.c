@@ -420,17 +420,31 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 /* Error token number */
 #define YYTERROR 1
 
-/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].  */
+/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
+   If N is 0, then set CURRENT to the empty location which ends
+   the previous symbol: RHS[0] (always defined).  */
 
 ]b4_location_if([[
 #define YYRHSLOC(yyRhs,YYK) ((yyRhs)[YYK].yystate.yyloc)
 
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN)			\
-   ((yyCurrent).first_line   = YYRHSLOC(yyRhs, 1).first_line,	\
-    (yyCurrent).first_column = YYRHSLOC(yyRhs, 1).first_column,	\
-    (yyCurrent).last_line    = YYRHSLOC(yyRhs, YYN).last_line,	\
-    (yyCurrent).last_column  = YYRHSLOC(yyRhs, YYN).last_column)
+# define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN)				\
+do {									\
+  if (YYN)								\
+    {									\
+      (yyCurrent).first_line   = YYRHSLOC(yyRhs, 1).first_line;		\
+      (yyCurrent).first_column = YYRHSLOC(yyRhs, 1).first_column;	\
+      (yyCurrent).last_line    = YYRHSLOC(yyRhs, YYN).last_line;	\
+      (yyCurrent).last_column  = YYRHSLOC(yyRhs, YYN).last_column;	\
+    }									\
+  else									\
+    {									\
+      (yyCurrent).first_line   = YYRHSLOC(yyRhs, 0).last_line;		\
+      (yyCurrent).first_column = YYRHSLOC(yyRhs, 0).last_column;	\
+      (yyCurrent).last_line    = YYRHSLOC(yyRhs, 0).last_line;		\
+      (yyCurrent).last_column  = YYRHSLOC(yyRhs, 0).last_column;	\
+    }									\
+} while(0)
 
 /* YY_LOCATION_PRINT -- Print the location on the stream.
    This macro was not mandated originally: define only if we know
@@ -718,15 +732,10 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 
   yylow = 1;
   if (yyrhslen == 0)
-    {
-      *yyvalp = yyval_default;
-      *yylocp = yyvsp[0].yystate.yyloc;
-    }
+    *yyvalp = yyval_default;
   else
-    {
-      *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
-      YYLLOC_DEFAULT (*yylocp, yyvsp - yyrhslen, yyrhslen);
-    }
+    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
+  YYLLOC_DEFAULT (*yylocp, yyvsp - yyrhslen, yyrhslen);
 
 ]
   switch (yyn)
