@@ -615,9 +615,10 @@ yytokenName (yySymbol yytoken)
 /** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
  *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
  *  containing the pointer to the next state in the chain. Assumes
- *  YYLOW1 < YYLOW0.  For convenience, returns YYLOW1. */
-static int
-yyfill (yyGLRStackItem* yyvsp, int yylow0, int yylow1)
+ *  YYLOW1 < YYLOW0.  */
+static void yyfillin (yyGLRStackItem *, int, int) ATTRIBUTE_UNUSED;
+static void
+yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
 {
   yyGLRState* s;
   int i;
@@ -631,6 +632,21 @@ yyfill (yyGLRStackItem* yyvsp, int yylow0, int yylow1)
       yyvsp[i].yystate.yyloc = s->yyloc;
       s = yyvsp[i].yystate.yypred = s->yypred;
     }
+}
+
+/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
+   YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
+   For convenience, always return YYLOW1.  */
+static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
+     ATTRIBUTE_UNUSED;
+static inline int
+yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
+{
+  if (!yynormal && yylow1 < *yylow)
+    {
+      yyfillin (yyvsp, *yylow, yylow1);
+      *yylow = yylow1;
+    }
   return yylow1;
 }
 
@@ -644,7 +660,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 	      YYSTYPE* yyvalp, YYLTYPE* yylocp, yyGLRStack* yystack
               ]b4_user_formals[)
 {
-  int yynormal = (yystack->yysplitPoint == NULL);
+  yybool yynormal ATTRIBUTE_UNUSED = (yystack->yysplitPoint == NULL);
   int yylow;
 
   if (yyrhslen == 0)
@@ -670,8 +686,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef yyclearin
 # define yyclearin (yychar = *(yystack->yytokenp) = YYEMPTY)
 # undef YYFILL
-# define YYFILL(N)							     \
-  ((yynormal || yylow <= (N)) ? (N) : (yylow = yyfill (yyvsp, yylow, N)))
+# define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
 # undef YYBACKUP
 # define YYBACKUP(Token, Value)						     \
   do {									     \
