@@ -591,6 +591,21 @@ int yydebug;
 # endif
 #endif
 
+#if YYSTACKEXPANDABLE
+# define YY_RESERVE_GLRSTACK(Yystack)			\
+  do {							\
+    if (Yystack->yyspaceLeft < YYHEADROOM)		\
+      yyexpandGLRStack (Yystack);			\
+  } while (/*CONSTCOND*/ 0)
+#else
+# define YY_RESERVE_GLRSTACK(Yystack)			\
+  do {							\
+    if (Yystack->yyspaceLeft < YYHEADROOM)		\
+      yyMemoryExhausted (Yystack);			\
+  } while (/*CONSTCOND*/ 0)
+#endif
+
+
 #if YYERROR_VERBOSE
 
 # ifndef yystpcpy
@@ -1020,21 +1035,32 @@ yyisErrorAction (int yyaction)
 
 				/* GLRStates */
 
+/** Return a fresh GLRStackItem.  Callers should call
+ * YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
+ * headroom.  */
+
+static inline yyGLRStackItem*
+yynewGLRStackItem (yyGLRStack* yystack, yybool yyisState)
+{
+  yyGLRStackItem* yynewItem = yystack->yynextFree;
+  yystack->yyspaceLeft -= 1;
+  yystack->yynextFree += 1;
+  yynewItem->yystate.yyisState = yyisState;
+  return yynewItem;
+}
+
 static void
 yyaddDeferredAction (yyGLRStack* yystack, yyGLRState* yystate,
 		     yyGLRState* rhs, yyRuleNum yyrule)
 {
-  yySemanticOption* yynewItem;
-  yynewItem = &yystack->yynextFree->yyoption;
-  yystack->yyspaceLeft -= 1;
-  yystack->yynextFree += 1;
-  yynewItem->yyisState = yyfalse;
-  yynewItem->yystate = rhs;
-  yynewItem->yyrule = yyrule;
-  yynewItem->yynext = yystate->yysemantics.yyfirstVal;
-  yystate->yysemantics.yyfirstVal = yynewItem;
-  if (yystack->yyspaceLeft < YYHEADROOM)
-    yyexpandGLRStack (yystack);
+  yySemanticOption* yynewOption =
+    &yynewGLRStackItem (yystack, yyfalse)->yyoption;
+  yynewOption->yystate = rhs;
+  yynewOption->yyrule = yyrule;
+  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
+  yystate->yysemantics.yyfirstVal = yynewOption;
+
+  YY_RESERVE_GLRSTACK (yystack);
 }
 
 				/* GLRStacks */
@@ -1075,7 +1101,9 @@ yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
   return yyinitStateSet (&yystack->yytops);
 }
 
-#define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
+
+#if YYSTACKEXPANDABLE
+# define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
   &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE
 
 /** If STACK is expandable, extend it.  WARNING: Pointers into the
@@ -1086,7 +1114,6 @@ yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
 static void
 yyexpandGLRStack (yyGLRStack* yystack)
 {
-#if YYSTACKEXPANDABLE
   yyGLRStackItem* yynewItems;
   yyGLRStackItem* yyp0, *yyp1;
   size_t yysize, yynewSize;
@@ -1139,11 +1166,8 @@ yyexpandGLRStack (yyGLRStack* yystack)
   yystack->yyitems = yynewItems;
   yystack->yynextFree = yynewItems + yysize;
   yystack->yyspaceLeft = yynewSize - yysize;
-
-#else
-  yyMemoryExhausted (yystack);
-#endif
 }
+#endif
 
 static void
 yyfreeGLRStack (yyGLRStack* yystack)
@@ -1221,21 +1245,17 @@ yyglrShift (yyGLRStack* yystack, size_t yyk, yyStateNum yylrState,
 	    size_t yyposn,
 	    YYSTYPE yysval, YYLTYPE* yylocp)
 {
-  yyGLRStackItem* yynewItem;
+  yyGLRState* yynewState = &yynewGLRStackItem (yystack, yytrue)->yystate;
 
-  yynewItem = yystack->yynextFree;
-  yystack->yynextFree += 1;
-  yystack->yyspaceLeft -= 1;
-  yynewItem->yystate.yyisState = yytrue;
-  yynewItem->yystate.yylrState = yylrState;
-  yynewItem->yystate.yyposn = yyposn;
-  yynewItem->yystate.yyresolved = yytrue;
-  yynewItem->yystate.yypred = yystack->yytops.yystates[yyk];
-  yystack->yytops.yystates[yyk] = &yynewItem->yystate;
-  yynewItem->yystate.yysemantics.yysval = yysval;
-  yynewItem->yystate.yyloc = *yylocp;
-  if (yystack->yyspaceLeft < YYHEADROOM)
-    yyexpandGLRStack (yystack);
+  yynewState->yylrState = yylrState;
+  yynewState->yyposn = yyposn;
+  yynewState->yyresolved = yytrue;
+  yynewState->yypred = yystack->yytops.yystates[yyk];
+  yynewState->yysemantics.yysval = yysval;
+  yynewState->yyloc = *yylocp;
+  yystack->yytops.yystates[yyk] = yynewState;
+
+  YY_RESERVE_GLRSTACK (yystack);
 }
 
 /** Shift stack #K of YYSTACK, to a new state corresponding to LR
@@ -1245,19 +1265,17 @@ static inline void
 yyglrShiftDefer (yyGLRStack* yystack, size_t yyk, yyStateNum yylrState,
 		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
 {
-  yyGLRStackItem* yynewItem;
+  yyGLRState* yynewState = &yynewGLRStackItem (yystack, yytrue)->yystate;
 
-  yynewItem = yystack->yynextFree;
-  yynewItem->yystate.yyisState = yytrue;
-  yynewItem->yystate.yylrState = yylrState;
-  yynewItem->yystate.yyposn = yyposn;
-  yynewItem->yystate.yyresolved = yyfalse;
-  yynewItem->yystate.yypred = yystack->yytops.yystates[yyk];
-  yynewItem->yystate.yysemantics.yyfirstVal = NULL;
-  yystack->yytops.yystates[yyk] = &yynewItem->yystate;
-  yystack->yynextFree += 1;
-  yystack->yyspaceLeft -= 1;
-  yyaddDeferredAction (yystack, &yynewItem->yystate, rhs, yyrule);
+  yynewState->yylrState = yylrState;
+  yynewState->yyposn = yyposn;
+  yynewState->yyresolved = yyfalse;
+  yynewState->yypred = yystack->yytops.yystates[yyk];
+  yynewState->yysemantics.yyfirstVal = NULL;
+  yystack->yytops.yystates[yyk] = yynewState;
+
+  /* Invokes YY_RESERVE_GLRSTACK. */
+  yyaddDeferredAction (yystack, yynewState, rhs, yyrule);
 }
 
 /** Pop the symbols consumed by reduction #RULE from the top of stack
