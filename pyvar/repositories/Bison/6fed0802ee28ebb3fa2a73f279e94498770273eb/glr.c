@@ -757,14 +757,14 @@ yyhasResolvedValue (yyGLRState* yystate)
 
 static void
 yyaddDeferredAction (yyGLRStack* yystack, yyGLRState* yystate,
-		     yyGLRState* yyrhs, yyRuleNum yyrule)
+		     yyGLRState* rhs, yyRuleNum yyrule)
 {
   yySemanticOption* yynewItem;
   yynewItem = &yystack->yynextFree->yyoption;
   yystack->yyspaceLeft -= 1;
   yystack->yynextFree += 1;
   yynewItem->yyisState = yyfalse;
-  yynewItem->yystate = yyrhs;
+  yynewItem->yystate = rhs;
   yynewItem->yyrule = yyrule;
   yynewItem->yynext = yystate->yysemantics.yyfirstVal;
   yystate->yysemantics.yyfirstVal = yynewItem;
@@ -967,7 +967,7 @@ yyglrShift (yyGLRStack* yystack, int yyk, yyStateNum yylrState, size_t yyposn,
  * the (unresolved) semantic value of RHS under the action for RULE. */
 static inline void
 yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState,
-		 size_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
+		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
 {
   yyGLRStackItem* yynewItem;
 
@@ -981,7 +981,7 @@ yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState,
   yystack->yytops.yystates[yyk] = &yynewItem->yystate;
   yystack->yynextFree += 1;
   yystack->yyspaceLeft -= 1;
-  yyaddDeferredAction (yystack, &yynewItem->yystate, yyrhs, yyrule);
+  yyaddDeferredAction (yystack, &yynewItem->yystate, rhs, yyrule);
 }
 
 /** Pop the symbols consumed by reduction #RULE from the top of stack
@@ -999,7 +999,7 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
   if (yystack->yysplitPoint == NULL)
     {
       /* Standard special case: single stack. */
-      yyGLRStackItem* yyrhs = (yyGLRStackItem*) yystack->yytops.yystates[yyk];
+      yyGLRStackItem* rhs = (yyGLRStackItem*) yystack->yytops.yystates[yyk];
       assert (yyk == 0);
       yystack->yynextFree -= yynrhs;
       yystack->yyspaceLeft += yynrhs;
@@ -1011,10 +1011,10 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
 	}
       else
 	{
-	  *yyvalp = yyrhs[1-yynrhs].yystate.yysemantics.yysval;
-	  *yylocp = yyrhs[1-yynrhs].yystate.yyloc;
+	  *yyvalp = rhs[1-yynrhs].yystate.yysemantics.yysval;
+	  *yylocp = rhs[1-yynrhs].yystate.yyloc;
 	}
-      return yyuserAction (yyrule, yynrhs, yyrhs, yyvalp, yylocp, yystack);
+      return yyuserAction (yyrule, yynrhs, rhs, yyvalp, yylocp, yystack);
     }
   else
     {
@@ -1273,6 +1273,7 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
 }
 
 #if YYDEBUG
+/* FIXME: How can we initialize the lloc bit?  */
 static yyGLRState YYLEFTMOST_STATE = { 0, 0, -1, NULL, 0, { NULL } };
 
 static void yyreportTree (yySemanticOption* yyx, int yyindent)
