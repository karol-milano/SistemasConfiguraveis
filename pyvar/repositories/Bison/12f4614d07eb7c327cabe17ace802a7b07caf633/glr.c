@@ -1101,8 +1101,10 @@ yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
   return yynewItem;
 }
 
-/** Stack #K = the stack from which RHS is taken.  This might not be the stack
- *  containing STATE, to which the deferred action is added.  */
+/** Add a new semantic action that will execute the action for rule
+ *  RULENUM on the semantic values in RHS to the list of
+ *  alternative actions for STATE.  Assumes that RHS comes from 
+ *  stack #K of *STACKP. */
 static void
 yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
 		     yyGLRState* rhs, yyRuleNum yyrule)
