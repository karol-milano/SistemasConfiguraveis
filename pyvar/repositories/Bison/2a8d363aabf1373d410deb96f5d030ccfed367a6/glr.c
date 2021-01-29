@@ -31,6 +31,15 @@ m4_define_default([b4_stack_depth_init],  [200])
 # Location type.
 m4_define_default([b4_location_type], [yyltype])
 
+
+
+## ------------------------ ##
+## Pure/impure interfaces.  ##
+## ------------------------ ##
+
+
+# b4_lex_param
+# ------------
 # Accumule in b4_lex_param all the yylex arguments.
 # Yes, this is quite ugly...
 m4_define([b4_lex_param],
@@ -38,13 +47,40 @@ m4_dquote(b4_pure_if([[[[YYSTYPE *]], [[yylvalp]]][]dnl
 b4_location_if([, [[YYLTYPE *], [yyllocp]]])])dnl
 m4_ifdef([b4_lex_param], [, ]b4_lex_param)))
 
-# Yes, this is quite ugly...
-  m4_define_default([b4_parse_param])
-m4_ifdef([b4_parse_param],
-[m4_define([b4_parse_param],
-	   b4_parse_param)])
+
+# b4_user_formals
+# ---------------
+m4_define([b4_user_formals],
+[m4_ifset([b4_parse_param], [, b4_c_ansi_formals(b4_parse_param)])])
+
+
+# b4_pure_args
+# ------------
+# Arguments passed to yyerror: user args plus yylloc.
+m4_define([b4_pure_args],
+[b4_pure_if([b4_location_if([, yylocp])])[]b4_user_args])
+
+
+# b4_pure_formals
+# ---------------
+# Arguments passed to yyerror: user formals plus yyllocp.
+m4_define([b4_pure_formals],
+[b4_pure_if([b4_location_if([, YYLTYPE *yylocp])])[]b4_user_formals])
+
+
+# b4_lpure_args
+# -------------
+# Same as above, but on the lookahead, hence yyllocp instead of yylocp.
+m4_define([b4_lpure_args],
+[b4_pure_if([b4_location_if([, yyllocp])])[]b4_user_args])
 
 
+# b4_lpure_formals
+# ----------------
+# Same as above, but on the lookahead, hence yyllocp instead of yylocp.
+m4_define([b4_lpure_formals],
+[b4_pure_if([b4_location_if([YYLTYPE *yyllocp])])[]b4_user_formals])
+
 
 ## ----------------- ##
 ## Semantic Values.  ##
@@ -119,24 +155,15 @@ b4_copyright([Skeleton parser for GLR parsing with Bison], [2002])
 [
 /* This is the parser code for GLR (Generalized LR) parser. */
 
-/* FIXME: minimize these */
 #include <assert.h>
-#include <setjmp.h>
-#include <stdarg.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <stdarg.h>
+#include <setjmp.h>
 
-/* Identify Bison output.  */
-#define YYBISON	1
-
-/* Pure parsers.  */
-#define YYPURE	]b4_pure[
-
-/* Using locations.  */
-#define YYLSP_NEEDED ]b4_locations_flag[
-
-]m4_if(b4_prefix[], [yy], [],
+]b4_identification
+m4_if(b4_prefix[], [yy], [],
 [/* If NAME_PREFIX is specified substitute the variables and functions
    names.  */
 #define yyparse b4_prefix[]parse
@@ -378,16 +405,9 @@ static const ]b4_int_type_for([b4_check])[ yycheck[] =
 
 
 /* Prevent warning if -Wmissing-prototypes.  */
-]b4_c_ansi_function_decl([yyparse], [int], b4_parse_param)
-
-m4_ifset([b4_parse_param],
-[#define YY_USER_FORMALS , b4_c_ansi_formals(b4_parse_param)
-#define YY_USER_ARGS    , b4_c_args(b4_parse_param)],
-[#define YY_USER_FORMALS
-#define YY_USER_ARGS])
+]b4_c_ansi_function_decl([yyparse], [int], b4_parse_param)[
 
-
-[/* Error token number */
+/* Error token number */
 #define YYTERROR 1
 
 /* YYLLOC_DEFAULT -- Compute the default location (before the actions
@@ -548,11 +568,11 @@ struct yyGLRStack {
 };
 
 static void yyinitGLRStack (yyGLRStack* yystack, size_t yysize);
-static void yyexpandGLRStack (yyGLRStack* yystack);
+static void yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[);
 static void yyfreeGLRStack (yyGLRStack* yystack);
 
 static void
-yyFail (yyGLRStack* yystack, const char* yyformat, ...)
+yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yyformat, ...)
 {
   if (yyformat != NULL)
     {
@@ -561,7 +581,7 @@ yyFail (yyGLRStack* yystack, const char* yyformat, ...)
       va_start (yyap, yyformat);
       yystack->yyerrflag = 1;
       vsprintf (yymsg, yyformat, yyap);
-      yyerror (yymsg);
+      yyerror (yymsg]b4_pure_args[);
     }
   longjmp (yystack->yyexception_buffer, 1);
 }
@@ -584,7 +604,7 @@ yytokenName (yySymbol yytoken)
 static YYRESULTTAG
 yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 	      YYSTYPE* yyvalp, YYLTYPE* yylocp, yyGLRStack* yystack
-	      YY_USER_FORMALS)
+              ]b4_user_formals[)
 {
   /* Avoid `unused' warnings in there are no $n. */
   (void) yystack;
@@ -616,7 +636,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef YYBACKUP
 # define YYBACKUP(Token, Value)						     \
   do {									     \
-    yyerror ("syntax error: cannot back up");				     \
+    yyerror ("syntax error: cannot back up"]b4_pure_args[);		     \
     YYERROR;								     \
   } while (0)
 
@@ -644,7 +664,7 @@ static YYSTYPE
 yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 {
   YYSTYPE yyval = *yy0;
-  /* `Use' the arguments. */
+  /* `Use' the arguments.  */
   (void) yy0;
   (void) yy1;
 
@@ -655,7 +675,7 @@ yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
   return yyval;
 }
 [
-				/* Bison grammar-table manipulation */
+			      /* Bison grammar-table manipulation.  */
 
 /** Number of symbols composing the right hand side of rule #RULE. */
 static inline int
@@ -751,7 +771,7 @@ yyhasResolvedValue (yyGLRState* yystate)
 
 static void
 yyaddDeferredAction (yyGLRStack* yystack, yyGLRState* yystate,
-		     yyGLRState* rhs, yyRuleNum yyrule)
+		     yyGLRState* rhs, yyRuleNum yyrule]b4_pure_formals[)
 {
   yySemanticOption* yynewItem;
   yynewItem = &yystack->yynextFree->yyoption;
@@ -763,7 +783,7 @@ yyaddDeferredAction (yyGLRStack* yystack, yyGLRState* yystate,
   yynewItem->yynext = yystate->yysemantics.yyfirstVal;
   yystate->yysemantics.yyfirstVal = yynewItem;
   if (yystack->yyspaceLeft < YYHEADROOM)
-    yyexpandGLRStack (yystack);
+    yyexpandGLRStack (yystack]b4_pure_args[);
 }
 
 				/* GLRStacks */
@@ -808,7 +828,7 @@ yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
     allocation, so that we can avoid having external pointers exist
     across an allocation. */
 static void
-yyexpandGLRStack (yyGLRStack* yystack)
+yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[)
 {
 #if YYSTACKEXPANDABLE
   yyGLRStack yynewStack;
@@ -817,7 +837,8 @@ yyexpandGLRStack (yyGLRStack* yystack)
   size_t yyn;
   yysize = yystack->yynextFree - yystack->yyitems;
   if (YYMAXDEPTH <= yysize)
-    yyFail (yystack, "parsing stack overflow (%d items)", yysize);
+    yyFail (yystack][]b4_pure_args[,
+	    "parsing stack overflow (%d items)", yysize);
   yynewSize = 2*yysize;
   if (YYMAXDEPTH < yynewSize)
     yynewSize = YYMAXDEPTH;
@@ -864,8 +885,8 @@ yyexpandGLRStack (yyGLRStack* yystack)
 
 #else
 
-  yyFail (yystack, "parsing stack overflow (%d items)", yysize);
-
+  yyFail (yystack][]b4_lpure_args[,
+          "parsing stack overflow (%d items)", yysize);
 #endif
 }
 
@@ -937,7 +958,7 @@ yyremoveDeletes (yyGLRStack* yystack)
  * LRSTATE, at input position POSN, with (resolved) semantic value SVAL. */
 static inline void
 yyglrShift (yyGLRStack* yystack, int yyk, yyStateNum yylrState, size_t yyposn,
-	    YYSTYPE yysval, YYLTYPE* yylocp)
+	    YYSTYPE yysval, YYLTYPE* yylocp]b4_user_formals[)
 {
   yyGLRStackItem* yynewItem;
 
@@ -953,7 +974,7 @@ yyglrShift (yyGLRStack* yystack, int yyk, yyStateNum yylrState, size_t yyposn,
   yynewItem->yystate.yysemantics.yysval = yysval;
   yynewItem->yystate.yyloc = *yylocp;
   if (yystack->yyspaceLeft < YYHEADROOM)
-    yyexpandGLRStack (yystack);
+    yyexpandGLRStack (yystack]b4_pure_args[);
 }
 
 /** Shift to a new state on stack #K of STACK, to a new state
@@ -961,7 +982,7 @@ yyglrShift (yyGLRStack* yystack, int yyk, yyStateNum yylrState, size_t yyposn,
  * the (unresolved) semantic value of RHS under the action for RULE. */
 static inline void
 yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState,
-		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
+		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule]b4_pure_formals[)
 {
   yyGLRStackItem* yynewItem;
 
@@ -975,7 +996,7 @@ yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState,
   yystack->yytops.yystates[yyk] = &yynewItem->yystate;
   yystack->yynextFree += 1;
   yystack->yyspaceLeft -= 1;
-  yyaddDeferredAction (yystack, &yynewItem->yystate, rhs, yyrule);
+  yyaddDeferredAction (yystack, &yynewItem->yystate, rhs, yyrule]b4_pure_args[);
 }
 
 /** Pop the symbols consumed by reduction #RULE from the top of stack
@@ -986,7 +1007,7 @@ yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState,
  *  for userAction. */
 static inline int
 yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
- 	    YYSTYPE* yyvalp, YYLTYPE* yylocp YY_USER_FORMALS)
+ 	    YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);
 
@@ -1009,7 +1030,7 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
 	  *yylocp = rhs[1-yynrhs].yystate.yyloc;
 	}
       return yyuserAction (yyrule, yynrhs, rhs,
-			   yyvalp, yylocp, yystack YY_USER_ARGS);
+			   yyvalp, yylocp, yystack]b4_user_args[);
     }
   else
     {
@@ -1037,7 +1058,7 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
 	  *yylocp = yyrhsVals[0].yystate.yyloc;
 	}
       return yyuserAction (yyrule, yynrhs, yyrhsVals + (yynrhs-1),
-			   yyvalp, yylocp, yystack YY_USER_ARGS);
+			   yyvalp, yylocp, yystack]b4_user_args[);
     }
 }
 
@@ -1080,7 +1101,7 @@ yy_reduce_print (size_t yyk, yyRuleNum yyrule)
  */
 static inline YYRESULTTAG
 yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
-             bool yyforceEval YY_USER_FORMALS)
+             bool yyforceEval]b4_pure_formals[)
 {
   size_t yyposn = yystack->yytops.yystates[yyk]->yyposn;
 
@@ -1090,11 +1111,11 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
       YYLTYPE yyloc;
 
       YY_REDUCE_PRINT (yyk, yyrule);
-      YYCHK (yydoAction (yystack, yyk, yyrule, &yysval, &yyloc YY_USER_ARGS));
+      YYCHK (yydoAction (yystack, yyk, yyrule, &yysval, &yyloc]b4_user_args[));
       yyglrShift (yystack, yyk,
 		  yyLRgotoState (yystack->yytops.yystates[yyk]->yylrState,
 				 yylhsNonterm (yyrule)),
-		yyposn, yysval, &yyloc);
+		  yyposn, yysval, &yyloc]b4_user_args[);
       YYDPRINTF ((stderr, "Stack %d entering state %d\n",
 		  yyk, yystack->yytops.yystates[yyk]->yylrState));
     }
@@ -1126,7 +1147,7 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 	      {
 		if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
 		  {
-		    yyaddDeferredAction (yystack, yyp, yys0, yyrule);
+		    yyaddDeferredAction (yystack, yyp, yys0, yyrule]b4_pure_args[);
 		    yymarkStackDeleted (yystack, yyk);
 		    YYDPRINTF ((stderr, "Merging stack %d into stack %d.\n",
 				yyk, yyi));
@@ -1136,7 +1157,7 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 	      }
 	  }
       yystack->yytops.yystates[yyk] = yys;
-      yyglrShiftDefer (yystack, yyk, yynewLRState, yyposn, yys0, yyrule);
+      yyglrShiftDefer (yystack, yyk, yynewLRState, yyposn, yys0, yyrule]b4_pure_args[);
     }
   return 0;
 }
@@ -1236,23 +1257,23 @@ yypreference (yySemanticOption* y0, yySemanticOption* y1)
 
 static YYRESULTTAG yyresolveValue (yySemanticOption* yyoptionList,
 				   yyGLRStack* yystack, YYSTYPE* yyvalp,
-				   YYLTYPE* yylocp YY_USER_FORMALS);
+				   YYLTYPE* yylocp]b4_user_formals[);
 
 static YYRESULTTAG
-yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack YY_USER_FORMALS)
+yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack]b4_user_formals[)
 {
   YYRESULTTAG yyflag;
   if (0 < yyn)
     {
       assert (yys->yypred != NULL);
-      yyflag = yyresolveStates (yys->yypred, yyn-1, yystack YY_USER_ARGS);
+      yyflag = yyresolveStates (yys->yypred, yyn-1, yystack]b4_user_args[);
       if (yyflag != yyok)
 	return yyflag;
       if (! yys->yyresolved)
 	{
 	  yyflag = yyresolveValue (yys->yysemantics.yyfirstVal, yystack,
 				   &yys->yysemantics.yysval, &yys->yyloc
-				   YY_USER_ARGS);
+				  ]b4_user_args[);
 	  if (yyflag != yyok)
 	    return yyflag;
 	  yys->yyresolved = yytrue;
@@ -1263,14 +1284,14 @@ yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack YY_USER_FORMALS)
 
 static YYRESULTTAG
 yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
-	         YYSTYPE* yyvalp, YYLTYPE* yylocp YY_USER_FORMALS)
+	         YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
   yyGLRStackItem yyrhsVals[YYMAXRHS];
   int yynrhs, yyi;
   yyGLRState* yys;
 
   yynrhs = yyrhsLength (yyopt->yyrule);
-  YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystack YY_USER_ARGS));
+  YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystack]b4_user_args[));
   for (yyi = yynrhs-1, yys = yyopt->yystate; 0 <= yyi;
        yyi -= 1, yys = yys->yypred)
     {
@@ -1280,7 +1301,7 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
       yyrhsVals[yyi].yystate.yyloc = yys->yyloc;
     }
   return yyuserAction (yyopt->yyrule, yynrhs, yyrhsVals + (yynrhs-1),
-		       yyvalp, yylocp, yystack YY_USER_ARGS);
+		       yyvalp, yylocp, yystack]b4_user_args[);
 }
 
 #if YYDEBUG
@@ -1331,7 +1352,7 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
 
 static void
 yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
-		   yyGLRStack* yystack)
+		   yyGLRStack* yystack]b4_pure_formals[)
 {
   /* `Unused' warnings.  */
   (void) yyx0;
@@ -1345,7 +1366,7 @@ yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
   yyreportTree (yyx1, 2);
   YYFPRINTF (stderr, "\n");
 #endif
-  yyFail (yystack, "ambiguity detected");
+  yyFail (yystack][]b4_pure_args[, "ambiguity detected");
 }
 
 
@@ -1353,7 +1374,7 @@ yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
  *  actions, and return the result. */
 static YYRESULTTAG
 yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
-		YYSTYPE* yyvalp, YYLTYPE* yylocp YY_USER_FORMALS)
+		YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
   yySemanticOption* yybest;
   yySemanticOption* yyp;
@@ -1369,7 +1390,7 @@ yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
 	switch (yypreference (yybest, yyp))
 	  {
 	  case 0:
-	    yyreportAmbiguity (yybest, yyp, yystack);
+	    yyreportAmbiguity (yybest, yyp, yystack]b4_pure_args[);
 	    break;
 	  case 1:
 	    yymerge = 1;
@@ -1386,25 +1407,25 @@ yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
   if (yymerge)
     {
       int yyprec = yydprec[yybest->yyrule];
-      YYCHK (yyresolveAction (yybest, yystack, yyvalp, yylocp YY_USER_ARGS));
+      YYCHK (yyresolveAction (yybest, yystack, yyvalp, yylocp]b4_user_args[));
       for (yyp = yybest->yynext; yyp != NULL; yyp = yyp->yynext)
 	{
 	  if (yyprec == yydprec[yyp->yyrule])
 	    {
 	      YYSTYPE yyval1;
 	      YYLTYPE yydummy;
-	      YYCHK (yyresolveAction (yyp, yystack, &yyval1, &yydummy YY_USER_ARGS));
+	      YYCHK (yyresolveAction (yyp, yystack, &yyval1, &yydummy]b4_user_args[));
 	      *yyvalp = yyuserMerge (yymerger[yyp->yyrule], yyvalp, &yyval1);
 	    }
 	}
       return yyok;
     }
   else
-    return yyresolveAction (yybest, yystack, yyvalp, yylocp YY_USER_ARGS);
+    return yyresolveAction (yybest, yystack, yyvalp, yylocp]b4_user_args[);
 }
 
 static YYRESULTTAG
-yyresolveStack (yyGLRStack* yystack YY_USER_FORMALS)
+yyresolveStack (yyGLRStack* yystack]b4_user_formals[)
 {
   if (yystack->yysplitPoint != NULL)
     {
@@ -1416,7 +1437,7 @@ yyresolveStack (yyGLRStack* yystack YY_USER_FORMALS)
 	   yys = yys->yypred, yyn += 1)
 	;
       YYCHK (yyresolveStates (yystack->yytops.yystates[0], yyn, yystack
-			      YY_USER_ARGS));
+			     ]b4_user_args[));
     }
   return yyok;
 }
@@ -1454,7 +1475,7 @@ yycompressStack (yyGLRStack* yystack)
 static YYRESULTTAG
 yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	           size_t yyposn, YYSTYPE* yylvalp, YYLTYPE* yyllocp
-		   YY_USER_FORMALS)
+		  ]b4_user_formals[)
 {
   int yyaction;
   const short* yyconflicts;
@@ -1475,7 +1496,7 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	      yymarkStackDeleted (yystack, yyk);
 	      return yyok;
 	    }
-	  YYCHK (yyglrReduce (yystack, yyk, yyrule, yyfalse YY_USER_ARGS));
+	  YYCHK (yyglrReduce (yystack, yyk, yyrule, yyfalse]b4_lpure_args[));
 	}
       else
 	{
@@ -1495,9 +1516,9 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	      YYDPRINTF ((stderr, "Splitting off stack %d from %d.\n",
 			  yynewStack, yyk));
 	      YYCHK (yyglrReduce (yystack, yynewStack,
-				  *yyconflicts, yyfalse YY_USER_ARGS));
+				  *yyconflicts, yyfalse]b4_lpure_args[));
 	      YYCHK (yyprocessOneStack (yystack, yynewStack, yyposn,
-					yylvalp, yyllocp YY_USER_ARGS));
+					yylvalp, yyllocp]b4_user_args[));
 	      yyconflicts += 1;
 	    }
 
@@ -1505,7 +1526,8 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	    {
 	      YYDPRINTF ((stderr, "Shifting token %s on stack %d, ",
 			  yytokenName (*yytokenp), yyk));
-	      yyglrShift (yystack, yyk, yyaction, yyposn+1, *yylvalp, yyllocp);
+	      yyglrShift (yystack, yyk, yyaction, yyposn+1,
+			  *yylvalp, yyllocp]b4_user_args[);
 	      YYDPRINTF ((stderr, "which is now in state #%d\n",
 			  yystack->yytops.yystates[yyk]->yylrState));
 	      break;
@@ -1517,14 +1539,15 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	      break;
 	    }
 	  else
-	    YYCHK (yyglrReduce (yystack, yyk, -yyaction, yyfalse YY_USER_ARGS));
+	    YYCHK (yyglrReduce (yystack, yyk, -yyaction, yyfalse]b4_lpure_args[));
 	}
     }
   return yyok;
 }
 
 static void
-yyreportParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
+yyreportParseError (yyGLRStack* yystack,
+		    YYSTYPE* yylvalp, YYLTYPE* yyllocp]b4_user_formals[)
 {
   /* `Unused' warnings. */
   (void) yylvalp;
@@ -1568,12 +1591,12 @@ yyreportParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 		    yyprefix = " or ";
 		  }
 	    }
-	  yyerror (yymsg);
+	  yyerror (yymsg]b4_lpure_args[);
 	  free (yymsg);
 	}
       else
 #endif
-	yyerror ("parse error");
+	yyerror ("parse error"]b4_lpure_args[);
       yynerrs += 1;
     }
 }
@@ -1582,7 +1605,8 @@ yyreportParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
    YYLVALP, and YYLLOCP point to the syntactic category, semantic
    value, and location of the lookahead.  */
 static void
-yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
+yyrecoverParseError (yyGLRStack* yystack,
+		     YYSTYPE* yylvalp, YYLTYPE* yyllocp]b4_user_formals[)
 {
   yySymbol* const yytokenp = yystack->yytokenp;
   size_t yyk;
@@ -1596,7 +1620,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
     while (yytrue)
       {
 	if (*yytokenp == YYEOF)
-	  yyFail (yystack, NULL);
+	  yyFail (yystack][]b4_lpure_args[, NULL);
 	if (*yytokenp != YYEMPTY)
 	  YYDPRINTF ((stderr, "Discarding token %s\n",
 		      yytokenName (*yytokenp)));
@@ -1607,7 +1631,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	yyj = yypact[yystack->yytops.yystates[0]->yylrState];
 	if (yyj == YYPACT_NINF)
 	  /* Something's not right; we shouldn't be here.  */
-	  yyFail (yystack, NULL);
+	  yyFail (yystack][]b4_lpure_args[, NULL);
 	yyj += *yytokenp;
 	if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != *yytokenp)
 	  {
@@ -1623,7 +1647,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
     if (yystack->yytops.yystates[yyk] != NULL)
       break;
   if (yyk >= yystack->yytops.yysize)
-    yyFail (yystack, NULL);
+    yyFail (yystack][]b4_lpure_args[, NULL);
   for (yyk += 1; yyk < yystack->yytops.yysize; yyk += 1)
     yymarkStackDeleted (yystack, yyk);
   yyremoveDeletes (yystack);
@@ -1637,7 +1661,8 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	  yycheck[yyj] == YYTERROR && yyisShiftAction (yytable[yyj]))
 	{
 	  yyglrShift (yystack, 0, yytable[yyj],
-		      yystack->yytops.yystates[0]->yyposn, *yylvalp, yyllocp);
+		      yystack->yytops.yystates[0]->yyposn,
+		      *yylvalp, yyllocp]b4_user_args[);
 	  break;
 	}
       yystack->yytops.yystates[0] = yystack->yytops.yystates[0]->yypred;
@@ -1645,7 +1670,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
       yystack->yyspaceLeft += 1;
     }
   if (yystack->yytops.yystates[0] == NULL)
-    yyFail (yystack, NULL);
+    yyFail (yystack][]b4_lpure_args[, NULL);
 }
 
 #define YYCHK1(YYE)							     \
@@ -1693,7 +1718,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
   if (setjmp (yystack.yyexception_buffer) != 0)
     goto yyDone;
 
-  yyglrShift (&yystack, 0, 0, 0, yyval_default, &yyloc_default);
+  yyglrShift (&yystack, 0, 0, 0, yyval_default, &yyloc_default]b4_user_args[);
   yytoken = YYEMPTY;
   yyposn = 0;
 
@@ -1718,10 +1743,10 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	      yyrule = yydefaultAction (yystate);
 	      if (yyrule == 0)
 		{
-		  yyreportParseError (&yystack, yylvalp, yyllocp);
+		  yyreportParseError (&yystack, yylvalp, yyllocp]b4_user_args[);
 		  goto yyuser_error;
 		}
-	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue YY_USER_ARGS));
+	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue]b4_lpure_args[));
 	    }
 	  else
 	    {
@@ -1743,7 +1768,8 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 		  if (yytoken != YYEOF)
 		    yytoken = YYEMPTY;
 		  yyposn += 1;
-		  yyglrShift (&yystack, 0, yyaction, yyposn, yylval, yyllocp);
+		  yyglrShift (&yystack, 0, yyaction, yyposn,
+		              yylval, yyllocp]b4_user_args[);
 		  if (0 < yystack.yyerrState)
 		    yystack.yyerrState -= 1;
 		  YYDPRINTF ((stderr, "Entering state %d\n",
@@ -1751,11 +1777,11 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 		}
 	      else if (yyisErrorAction (yyaction))
 		{
-		  yyreportParseError (&yystack, yylvalp, yyllocp);
+		  yyreportParseError (&yystack, yylvalp, yyllocp]b4_user_args[);
 		  goto yyuser_error;
 		}
 	      else
-		YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue YY_USER_ARGS));
+		YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue]b4_lpure_args[));
 	    }
 	}
 
@@ -1765,7 +1791,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	  int yyn = yystack.yytops.yysize;
 	  for (yys = 0; yys < yyn; yys += 1)
 	    YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn,
-				       yylvalp, yyllocp YY_USER_ARGS));
+				       yylvalp, yyllocp]b4_user_args[));
 	  yytoken = YYEMPTY;
 	  yyposn += 1;
 	  yyremoveDeletes (&yystack);
@@ -1773,15 +1799,15 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	    {
 	      yyundeleteLastStack (&yystack);
 	      if (yystack.yytops.yysize == 0)
-		yyFail (&yystack, "parse error");
-	      YYCHK1 (yyresolveStack (&yystack YY_USER_ARGS));
+		yyFail (&yystack][]b4_lpure_args[, "parse error");
+	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
 	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
-	      yyreportParseError (&yystack, yylvalp, yyllocp);
+	      yyreportParseError (&yystack, yylvalp, yyllocp]b4_user_args[);
 	      goto yyuser_error;
 	    }
 	  else if (yystack.yytops.yysize == 1)
 	    {
-	      YYCHK1 (yyresolveStack (&yystack YY_USER_ARGS));
+	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
 	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
 	      yycompressStack (&yystack);
 	      break;
@@ -1789,7 +1815,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	}
       continue;
     yyuser_error:
-      yyrecoverParseError (&yystack, yylvalp, yyllocp);
+      yyrecoverParseError (&yystack, yylvalp, yyllocp]b4_user_args[);
       yyposn = yystack.yytops.yystates[0]->yyposn;
     }
  yyDone:
