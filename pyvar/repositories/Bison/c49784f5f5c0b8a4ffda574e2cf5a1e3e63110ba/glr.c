@@ -511,9 +511,9 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 
 #define YYCHK(YYE)                              \
   do {                                          \
-    YYRESULTTAG yyflag = YYE;                   \
-    if (yyflag != yyok)                         \
-      return yyflag;                            \
+    YYRESULTTAG yychk_flag = YYE;               \
+    if (yychk_flag != yyok)                     \
+      return yychk_flag;                        \
   } while (YYID (0))
 
 #if YYDEBUG
@@ -1429,7 +1429,7 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
 		     (unsigned long int) yyk, yyrule - 1));
         }
       if (yyflag != yyok)
-        return yyflag;      
+        return yyflag;
       YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
       yyglrShift (yystackp, yyk,
 		  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
@@ -1964,11 +1964,6 @@ static YYRESULTTAG
 yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 		   size_t yyposn]b4_pure_formals[)
 {
-  int yyaction;
-  const short int* yyconflicts;
-  yyRuleNum yyrule;
-  YYRESULTTAG yyflag;
-
   while (yystackp->yytops.yystates[yyk] != NULL)
     {
       yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
@@ -1979,7 +1974,8 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 
       if (yyisDefaultedState (yystate))
 	{
-	  yyrule = yydefaultAction (yystate);
+          YYRESULTTAG yyflag;
+          yyRuleNum yyrule = yydefaultAction (yystate);
 	  if (yyrule == 0)
 	    {
 	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
@@ -2001,6 +1997,8 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
       else
 	{
 	  yySymbol yytoken;
+          int yyaction;
+          const short int* yyconflicts;
 
 	  yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
 	  if (yychar == YYEMPTY)
@@ -2037,7 +2035,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 					  yyposn]b4_pure_args[));
 	      else if (yyflag == yyerr)
 		{
-		  YYDPRINTF ((stderr, "Stack %lu dies.\n", 
+		  YYDPRINTF ((stderr, "Stack %lu dies.\n",
 			      (unsigned long int) yynewStack));
 		  yymarkStackDeleted (yystackp, yynewStack);
 		}
@@ -2057,8 +2055,8 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 	    }
 	  else
             {
-	      yyflag = yyglrReduce (yystackp, yyk, -yyaction,
-		  		    yyimmediate[-yyaction]]b4_user_args[);
+	      YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
+                                                yyimmediate[-yyaction]]b4_user_args[);
 	      if (yyflag == yyerr)
                 {
 	          YYDPRINTF ((stderr, "Stack %lu dies (predicate failure or explicit user error).\n",
