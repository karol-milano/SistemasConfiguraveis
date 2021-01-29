@@ -1,7 +1,7 @@
                                                                     -*- C -*-
 
 # GLR skeleton for Bison
-# Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
+# Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009 Free Software
 # Foundation, Inc.
 
 # This program is free software: you can redistribute it and/or modify
@@ -1366,8 +1366,7 @@ do {					\
 `----------------------------------------------------------*/
 
 /*ARGSUSED*/ static inline void
-yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
-		 YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
+yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule]b4_user_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);
   yybool yynormal __attribute__ ((__unused__)) =
@@ -1375,8 +1374,6 @@ yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
   yyGLRStackItem* yyvsp = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
   int yylow = 1;
   int yyi;
-  YYUSE (yyvalp);
-  YYUSE (yylocp);
 ]b4_parse_param_use[]dnl
 [  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
 	     (unsigned long int) yyk, yyrule - 1,
@@ -1417,7 +1414,7 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       YYSTYPE yysval;
       YYLTYPE yyloc;
 
-      YY_REDUCE_PRINT ((yystackp, yyk, yyrule, &yysval, &yyloc]b4_user_args[));
+      YY_REDUCE_PRINT ((yystackp, yyk, yyrule]b4_user_args[));
       YYCHK (yydoAction (yystackp, yyk, yyrule, &yysval,
 			 &yyloc]b4_user_args[));
       YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
