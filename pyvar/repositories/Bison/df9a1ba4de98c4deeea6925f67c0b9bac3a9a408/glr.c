@@ -687,7 +687,7 @@ struct yyGLRStack {
   yyGLRStateSet yytops;
 };
 
-static void yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[);
+static void yyexpandGLRStack (yyGLRStack* yystack);
 
 static void
 yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yymsg)
@@ -927,7 +927,7 @@ yyisErrorAction (int yyaction)
 
 static void
 yyaddDeferredAction (yyGLRStack* yystack, yyGLRState* yystate,
-		     yyGLRState* rhs, yyRuleNum yyrule]b4_pure_formals[)
+		     yyGLRState* rhs, yyRuleNum yyrule)
 {
   yySemanticOption* yynewItem;
   yynewItem = &yystack->yynextFree->yyoption;
@@ -939,7 +939,7 @@ yyaddDeferredAction (yyGLRStack* yystack, yyGLRState* yystate,
   yynewItem->yynext = yystate->yysemantics.yyfirstVal;
   yystate->yysemantics.yyfirstVal = yynewItem;
   if (yystack->yyspaceLeft < YYHEADROOM)
-    yyexpandGLRStack (yystack]b4_pure_args[);
+    yyexpandGLRStack (yystack);
 }
 
 				/* GLRStacks */
@@ -986,7 +986,7 @@ yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
     allocation, so that we can avoid having external pointers exist
     across an allocation. */
 static void
-yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[)
+yyexpandGLRStack (yyGLRStack* yystack)
 {
 #if YYSTACKEXPANDABLE
   yyGLRStackItem* yynewItems;
@@ -1043,7 +1043,6 @@ yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[)
   yystack->yyspaceLeft = yynewSize - yysize;
 
 #else
-
   yyMemoryExhausted (yystack);
 #endif
 }
@@ -1122,7 +1121,7 @@ yyremoveDeletes (yyGLRStack* yystack)
 static inline void
 yyglrShift (yyGLRStack* yystack, size_t yyk, yyStateNum yylrState,
 	    size_t yyposn,
-	    YYSTYPE yysval, YYLTYPE* yylocp]b4_user_formals[)
+	    YYSTYPE yysval, YYLTYPE* yylocp)
 {
   yyGLRStackItem* yynewItem;
 
@@ -1138,7 +1137,7 @@ yyglrShift (yyGLRStack* yystack, size_t yyk, yyStateNum yylrState,
   yynewItem->yystate.yysemantics.yysval = yysval;
   yynewItem->yystate.yyloc = *yylocp;
   if (yystack->yyspaceLeft < YYHEADROOM)
-    yyexpandGLRStack (yystack]b4_pure_args[);
+    yyexpandGLRStack (yystack);
 }
 
 /** Shift stack #K of YYSTACK, to a new state corresponding to LR
@@ -1146,7 +1145,7 @@ yyglrShift (yyGLRStack* yystack, size_t yyk, yyStateNum yylrState,
  *  semantic value of YYRHS under the action for YYRULE. */
 static inline void
 yyglrShiftDefer (yyGLRStack* yystack, size_t yyk, yyStateNum yylrState,
-		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule]b4_pure_formals[)
+		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
 {
   yyGLRStackItem* yynewItem;
 
@@ -1160,7 +1159,7 @@ yyglrShiftDefer (yyGLRStack* yystack, size_t yyk, yyStateNum yylrState,
   yystack->yytops.yystates[yyk] = &yynewItem->yystate;
   yystack->yynextFree += 1;
   yystack->yyspaceLeft -= 1;
-  yyaddDeferredAction (yystack, &yynewItem->yystate, rhs, yyrule]b4_pure_args[);
+  yyaddDeferredAction (yystack, &yynewItem->yystate, rhs, yyrule);
 }
 
 /** Pop the symbols consumed by reduction #RULE from the top of stack
@@ -1245,7 +1244,7 @@ yy_reduce_print (size_t yyk, yyRuleNum yyrule)
  */
 static inline YYRESULTTAG
 yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
-             yybool yyforceEval]b4_pure_formals[)
+             yybool yyforceEval]b4_user_formals[)
 {
   size_t yyposn = yystack->yytops.yystates[yyk]->yyposn;
 
@@ -1259,7 +1258,7 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
       yyglrShift (yystack, yyk,
 		  yyLRgotoState (yystack->yytops.yystates[yyk]->yylrState,
 				 yylhsNonterm (yyrule)),
-		  yyposn, yysval, &yyloc]b4_user_args[);
+		  yyposn, yysval, &yyloc);
     }
   else
     {
@@ -1288,7 +1287,7 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 	      {
 		if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
 		  {
-		    yyaddDeferredAction (yystack, yyp, yys0, yyrule]b4_pure_args[);
+		    yyaddDeferredAction (yystack, yyp, yys0, yyrule);
 		    yymarkStackDeleted (yystack, yyk);
 		    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
 				(unsigned long int) yyk,
@@ -1299,13 +1298,13 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 	      }
 	  }
       yystack->yytops.yystates[yyk] = yys;
-      yyglrShiftDefer (yystack, yyk, yynewLRState, yyposn, yys0, yyrule]b4_pure_args[);
+      yyglrShiftDefer (yystack, yyk, yynewLRState, yyposn, yys0, yyrule);
     }
   return yyok;
 }
 
 static size_t
-yysplitStack (yyGLRStack* yystack, size_t yyk]b4_pure_formals[)
+yysplitStack (yyGLRStack* yystack, size_t yyk)
 {
   if (yystack->yysplitPoint == NULL)
     {
@@ -1670,7 +1669,7 @@ yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
 	      yymarkStackDeleted (yystack, yyk);
 	      return yyok;
 	    }
-	  YYCHK (yyglrReduce (yystack, yyk, yyrule, yyfalse]b4_lpure_args[));
+	  YYCHK (yyglrReduce (yystack, yyk, yyrule, yyfalse]b4_user_args[));
 	}
       else
 	{
@@ -1686,12 +1685,12 @@ yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
 
 	  while (*yyconflicts != 0)
 	    {
-	      size_t yynewStack = yysplitStack (yystack, yyk]b4_pure_args[);
+	      size_t yynewStack = yysplitStack (yystack, yyk);
 	      YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
 			  (unsigned long int) yynewStack,
 			  (unsigned long int) yyk));
 	      YYCHK (yyglrReduce (yystack, yynewStack,
-				  *yyconflicts, yyfalse]b4_lpure_args[));
+				  *yyconflicts, yyfalse]b4_user_args[));
 	      YYCHK (yyprocessOneStack (yystack, yynewStack, yyposn,
 					yylvalp, yyllocp]b4_pure_args[));
 	      yyconflicts += 1;
@@ -1702,7 +1701,7 @@ yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
 	      YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yyk));
 	      YY_SYMBOL_PRINT ("shifting", *yytokenp, yylvalp, yyllocp);
 	      yyglrShift (yystack, yyk, yyaction, yyposn+1,
-			  *yylvalp, yyllocp]b4_user_args[);
+			  *yylvalp, yyllocp);
 	      YYDPRINTF ((stderr, ", now in state #%d\n",
 			  yystack->yytops.yystates[yyk]->yylrState));
 	      break;
@@ -1715,7 +1714,7 @@ yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
 	      break;
 	    }
 	  else
-	    YYCHK (yyglrReduce (yystack, yyk, -yyaction, yyfalse]b4_lpure_args[));
+	    YYCHK (yyglrReduce (yystack, yyk, -yyaction, yyfalse]b4_user_args[));
 	}
     }
   return yyok;
@@ -1908,7 +1907,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 			       yylvalp, &yyerrloc);
 	      YYDPRINTF ((stderr, "\n"));
 	      yyglrShift (yystack, 0, yytable[yyj],
-			  yys->yyposn, *yylvalp, &yyerrloc]b4_user_args[);
+			  yys->yyposn, *yylvalp, &yyerrloc);
 	      yys = yystack->yytops.yystates[0];
 	      break;
 	    }
@@ -1989,7 +1988,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
     case 2: goto yyexhaustedlab;
     }
   yystack.yytokenp = &yytoken;
-  yyglrShift (&yystack, 0, 0, 0, yylval, &yylloc]b4_user_args[);
+  yyglrShift (&yystack, 0, 0, 0, yylval, &yylloc);
   yyposn = 0;
 
   while (yytrue)
@@ -2017,7 +2016,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		  yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 		  goto yyuser_error;
 		}
-	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue]b4_lpure_args[));
+	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue]b4_user_args[));
 	    }
 	  else
 	    {
@@ -2039,8 +2038,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		  if (yytoken != YYEOF)
 		    yytoken = YYEMPTY;
 		  yyposn += 1;
-		  yyglrShift (&yystack, 0, yyaction, yyposn,
-		              yylval, yyllocp]b4_user_args[);
+		  yyglrShift (&yystack, 0, yyaction, yyposn, yylval, yyllocp);
 		  if (0 < yystack.yyerrState)
 		    yystack.yyerrState -= 1;
 		}
@@ -2051,7 +2049,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		  goto yyuser_error;
 		}
 	      else
-		YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue]b4_lpure_args[));
+		YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue]b4_user_args[));
 	    }
 	}
 
