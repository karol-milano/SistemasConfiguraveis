@@ -2134,15 +2134,13 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 static void
 yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 {
-  size_t yyk;
-  int yyj;
-
   if (yystackp->yyerrState == 3)
     /* We just shifted the error token and (perhaps) took some
        reductions.  Skip tokens until we can proceed.  */
     while (yytrue)
       {
         yySymbol yytoken;
+        int yyj;
         if (yychar == YYEOF)
           yyFail (yystackp][]b4_lpure_args[, YY_NULLPTR);
         if (yychar != YYEMPTY)
@@ -2184,22 +2182,25 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
       }
 
   /* Reduce to one stack.  */
-  for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
-    if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
-      break;
-  if (yyk >= yystackp->yytops.yysize)
-    yyFail (yystackp][]b4_lpure_args[, YY_NULLPTR);
-  for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
-    yymarkStackDeleted (yystackp, yyk);
-  yyremoveDeletes (yystackp);
-  yycompressStack (yystackp);
+  {
+    size_t yyk;
+    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
+      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
+        break;
+    if (yyk >= yystackp->yytops.yysize)
+      yyFail (yystackp][]b4_lpure_args[, YY_NULLPTR);
+    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
+      yymarkStackDeleted (yystackp, yyk);
+    yyremoveDeletes (yystackp);
+    yycompressStack (yystackp);
+  }
 
   /* Now pop stack until we find a state that shifts the error token.  */
   yystackp->yyerrState = 3;
   while (yystackp->yytops.yystates[0] != YY_NULLPTR)
     {
       yyGLRState *yys = yystackp->yytops.yystates[0];
-      yyj = yypact[yys->yylrState];
+      int yyj = yypact[yys->yylrState];
       if (! yypact_value_is_default (yyj))
         {
           yyj += YYTERROR;
@@ -2287,17 +2288,13 @@ b4_dollar_popdef])[]dnl
       /* Standard mode */
       while (yytrue)
         {
-          yyRuleNum yyrule;
-          int yyaction;
-          const short* yyconflicts;
-
           yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
           YYDPRINTF ((stderr, "Entering state %d\n", yystate));
           if (yystate == YYFINAL)
             goto yyacceptlab;
           if (yyisDefaultedState (yystate))
             {
-              yyrule = yydefaultAction (yystate);
+              yyRuleNum yyrule = yydefaultAction (yystate);
               if (yyrule == 0)
                 {]b4_locations_if([[
                   yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
@@ -2308,6 +2305,8 @@ b4_dollar_popdef])[]dnl
             }
           else
             {
+              int yyaction;
+              const short* yyconflicts;
               yySymbol yytoken;
               if (yychar == YYEMPTY)
                 {
