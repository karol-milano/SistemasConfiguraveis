@@ -1022,7 +1022,7 @@ yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState,
  *  have been previously resolved. Set *VALP to the resulting value,
  *  and *LOCP to the computed location (if any).  Return value is as
  *  for userAction. */
-static inline int
+static inline YYRESULTTAG
 yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
  	    YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
@@ -1168,7 +1168,7 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 		    yymarkStackDeleted (yystack, yyk);
 		    YYDPRINTF ((stderr, "Merging stack %d into stack %d.\n",
 				yyk, yyi));
-		    return 0;
+		    return yyok;
 		  }
 		yyp = yyp->yypred;
 	      }
@@ -1176,7 +1176,7 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
       yystack->yytops.yystates[yyk] = yys;
       yyglrShiftDefer (yystack, yyk, yynewLRState, yyposn, yys0, yyrule]b4_pure_args[);
     }
-  return 0;
+  return yyok;
 }
 
 static int
