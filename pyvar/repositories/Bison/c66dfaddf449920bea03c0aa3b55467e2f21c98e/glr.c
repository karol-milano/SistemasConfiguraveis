@@ -253,7 +253,7 @@ b4_syncline([@oline@], [@ofile@])
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
-#ifndef lint
+#if !defined (lint) || defined (__GNUC__)
 # define YYUSE(e) ((void) (e))
 #else
 # define YYUSE(e) /* empty */
@@ -1103,7 +1103,7 @@ yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
 
 /** Add a new semantic action that will execute the action for rule
  *  RULENUM on the semantic values in RHS to the list of
- *  alternative actions for STATE.  Assumes that RHS comes from 
+ *  alternative actions for STATE.  Assumes that RHS comes from
  *  stack #K of *STACKP. */
 static void
 yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
@@ -1536,7 +1536,7 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
       yybool* yynewLookaheadNeeds;
 
       yynewStates = NULL;
-      
+
       if (yystackp->yytops.yycapacity
 	  > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
 	yyMemoryExhausted (yystackp);
