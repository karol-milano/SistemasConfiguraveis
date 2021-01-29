@@ -470,23 +470,36 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 #  define YYFPRINTF fprintf
 # endif
 
-]b4_yy_location_print_define[
+# define YY_FPRINTF                             \
+  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_
 
-# define YYDPRINTF(Args)                        \
+# define YY_FPRINTF_(Args)                      \
+  do {                                          \
+    YYFPRINTF Args;                             \
+    YY_IGNORE_USELESS_CAST_END                  \
+  } while (0)
+
+# define YY_DPRINTF                             \
+  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_
+
+# define YY_DPRINTF_(Args)                      \
   do {                                          \
     if (yydebug)                                \
       YYFPRINTF Args;                           \
+    YY_IGNORE_USELESS_CAST_END                  \
   } while (0)
 
+]b4_yy_location_print_define[
+
 ]b4_yy_symbol_print_define[
 
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
   do {                                                                  \
     if (yydebug)                                                        \
       {                                                                 \
-        YYFPRINTF (stderr, "%s ", Title);                               \
+        YY_FPRINTF ((stderr, "%s ", Title));                            \
         yy_symbol_print (stderr, Type, Value]b4_locuser_args([Location])[);        \
-        YYFPRINTF (stderr, "\n");                                       \
+        YY_FPRINTF ((stderr, "\n"));                                    \
       }                                                                 \
   } while (0)
 
@@ -502,7 +515,7 @@ static void yypdumpstack (struct yyGLRStack* yystackp)
 
 #else /* !]b4_api_PREFIX[DEBUG */
 
-# define YYDPRINTF(Args) do {} while (yyfalse)
+# define YY_DPRINTF(Args) do {} while (yyfalse)
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 
 #endif /* !]b4_api_PREFIX[DEBUG */
@@ -786,7 +799,7 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
 ]b4_parse_param_use()dnl
 [  if (*yycharp == YYEMPTY)
     {
-      YYDPRINTF ((stderr, "Reading a token: "));]b4_glr_cc_if([[
+      YY_DPRINTF ((stderr, "Reading a token: "));]b4_glr_cc_if([[
 #if YY_EXCEPTIONS
       try
         {
@@ -796,7 +809,7 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
         }
       catch (const ]b4_namespace_ref[::]b4_parser_class[::syntax_error& yyexc)
         {
-          YYDPRINTF ((stderr, "Caught exception: %s\n", yyexc.what()));]b4_locations_if([
+          YY_DPRINTF ((stderr, "Caught exception: %s\n", yyexc.what()));]b4_locations_if([
           yylloc = yyexc.location;])[
           yyerror (]b4_lyyerror_args[yyexc.what ());
           // Map errors caught in the scanner to the undefined token
@@ -810,7 +823,7 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
   if (*yycharp <= YYEOF)
     {
       *yycharp = yytoken = YYEOF;
-      YYDPRINTF ((stderr, "Now at end of input.\n"));
+      YY_DPRINTF ((stderr, "Now at end of input.\n"));
     }
   else
     {
@@ -892,7 +905,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   }
   catch (const syntax_error& yyexc)
     {
-      YYDPRINTF ((stderr, "Caught exception: %s\n", yyexc.what()));]b4_locations_if([
+      YY_DPRINTF ((stderr, "Caught exception: %s\n", yyexc.what()));]b4_locations_if([
       *yylocp = yyexc.location;])[
       yyerror (]b4_yyerror_args[yyexc.what ());
       YYERROR;
@@ -946,9 +959,9 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
       if (yydebug)
         {
           if (yys->yysemantics.yyfirstVal)
-            YYFPRINTF (stderr, "%s unresolved", yymsg);
+            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
           else
-            YYFPRINTF (stderr, "%s incomplete", yymsg);
+            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
           YY_SYMBOL_PRINT ("", yystos[yys->yylrState], YY_NULLPTR, &yys->yyloc);
         }
 #endif
@@ -1258,7 +1271,7 @@ yyundeleteLastStack (yyGLRStack* yystackp)
     return;
   yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
   yystackp->yytops.yysize = 1;
-  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
+  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
   yystackp->yylastDeleted = YY_NULLPTR;
 }
 
@@ -1272,7 +1285,7 @@ yyremoveDeletes (yyGLRStack* yystackp)
       if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
         {
           if (yyi == yyj)
-            YYDPRINTF ((stderr, "Removing dead stacks.\n"));
+            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
           yystackp->yytops.yysize -= 1;
         }
       else
@@ -1286,7 +1299,7 @@ yyremoveDeletes (yyGLRStack* yystackp)
           yystackp->yytops.yylookaheadNeeds[yyj] =
             yystackp->yytops.yylookaheadNeeds[yyi];
           if (yyj != yyi)
-            YYDPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
+            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                         YY_CAST (long, yyi), YY_CAST (long, yyj)));
           yyj += 1;
         }
@@ -1356,22 +1369,22 @@ yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, ptrdiff_t yyk,
   int yynrhs = yyrhsLength (yyrule);]b4_locations_if([
   int yylow = 1;])[
   int yyi;
-  YYFPRINTF (stderr, "Reducing stack %ld by rule %d (line %d):\n",
-             YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]);
+  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
+               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
   if (! yynormal)
     yyfillin (yyvsp, 1, -yynrhs);
   /* The symbols being reduced.  */
   for (yyi = 0; yyi < yynrhs; yyi++)
     {
-      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
+      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
       yy_symbol_print (stderr,
                        yystos[yyvsp[yyi - yynrhs + 1].yystate.yylrState],
                        &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval]b4_locations_if([,
                        &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
                        b4_user_args[);
       if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
-        YYFPRINTF (stderr, " (unresolved)");
-      YYFPRINTF (stderr, "\n");
+        YY_FPRINTF ((stderr, " (unresolved)"));
+      YY_FPRINTF ((stderr, "\n"));
     }
 }
 #endif
@@ -1447,9 +1460,9 @@ yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
 
       YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval]b4_locuser_args([&yyloc])[);
       if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
-        YYDPRINTF ((stderr,
-                    "Parse on stack %ld rejected by rule %d (line %d).\n",
-                    YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1]));
+        YY_DPRINTF ((stderr,
+                     "Parse on stack %ld rejected by rule %d (line %d).\n",
+                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1]));
       if (yyflag != yyok)
         return yyflag;
       YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
@@ -1473,11 +1486,11 @@ yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
         }
       yyupdateSplit (yystackp, yys);
       yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
-      YYDPRINTF ((stderr,
-                  "Reduced stack %ld by rule %d (line %d); action deferred.  "
-                  "Now in state %d.\n",
-                  YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1],
-                  yynewLRState));
+      YY_DPRINTF ((stderr,
+                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
+                   "Now in state %d.\n",
+                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1],
+                   yynewLRState));
       for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
         if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
           {
@@ -1489,8 +1502,8 @@ yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
                   {
                     yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                     yymarkStackDeleted (yystackp, yyk);
-                    YYDPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
-                                YY_CAST (long, yyk), YY_CAST (long, yyi)));
+                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
+                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                     return yyok;
                   }
                 yyp = yyp->yypred;
@@ -1732,26 +1745,26 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
     yystates[0] = yys;
 
   if (yyx->yystate->yyposn < yys->yyposn + 1)
-    YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
-               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
-               yyx->yyrule - 1);
+    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
+                 yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
+                 yyx->yyrule - 1));
   else
-    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
-               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
-               yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
-               YY_CAST (long, yyx->yystate->yyposn));
+    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
+                 yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
+                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
+                 YY_CAST (long, yyx->yystate->yyposn)));
   for (yyi = 1; yyi <= yynrhs; yyi += 1)
     {
       if (yystates[yyi]->yyresolved)
         {
           if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
-            YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
-                       yytokenName (yystos[yystates[yyi]->yylrState]));
+            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
+                         yytokenName (yystos[yystates[yyi]->yylrState])));
           else
-            YYFPRINTF (stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
-                       yytokenName (yystos[yystates[yyi]->yylrState]),
-                       YY_CAST (long, yystates[yyi-1]->yyposn + 1),
-                       YY_CAST (long, yystates[yyi]->yyposn));
+            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
+                         yytokenName (yystos[yystates[yyi]->yylrState]),
+                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
+                         YY_CAST (long, yystates[yyi]->yyposn)));
         }
       else
         yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
@@ -1767,12 +1780,12 @@ yyreportAmbiguity (yySemanticOption* yyx0,
   YYUSE (yyx1);
 
 #if ]b4_api_PREFIX[DEBUG
-  YYFPRINTF (stderr, "Ambiguity detected.\n");
-  YYFPRINTF (stderr, "Option 1,\n");
+  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
+  YY_FPRINTF ((stderr, "Option 1,\n"));
   yyreportTree (yyx0, 2);
-  YYFPRINTF (stderr, "\nOption 2,\n");
+  YY_FPRINTF ((stderr, "\nOption 2,\n"));
   yyreportTree (yyx1, 2);
-  YYFPRINTF (stderr, "\n");
+  YY_FPRINTF ((stderr, "\n"));
 #endif
 
   yyerror (]b4_yyerror_args[YY_("syntax is ambiguous"));
@@ -1970,7 +1983,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
   while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
     {
       yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
-      YYDPRINTF ((stderr, "Stack %ld Entering state %d\n", yyk, yystate));
+      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n", yyk, yystate));
 
       YYASSERT (yystate != YYFINAL);
 
@@ -1980,17 +1993,17 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
           yyRuleNum yyrule = yydefaultAction (yystate);
           if (yyrule == 0)
             {
-              YYDPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
+              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
               yymarkStackDeleted (yystackp, yyk);
               return yyok;
             }
           yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]]b4_user_args[);
           if (yyflag == yyerr)
             {
-              YYDPRINTF ((stderr,
-                          "Stack %ld dies "
-                          "(predicate failure or explicit user error).\n",
-                          YY_CAST (long, yyk)));
+              YY_DPRINTF ((stderr,
+                           "Stack %ld dies "
+                           "(predicate failure or explicit user error).\n",
+                           YY_CAST (long, yyk)));
               yymarkStackDeleted (yystackp, yyk);
               return yyok;
             }
@@ -2008,8 +2021,8 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
             {
               YYRESULTTAG yyflag;
               ptrdiff_t yynewStack = yysplitStack (yystackp, yyk);
-              YYDPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
-                          YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
+              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
+                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
               yyflag = yyglrReduce (yystackp, yynewStack,
                                     *yyconflicts,
                                     yyimmediate[*yyconflicts]]b4_user_args[);
@@ -2018,7 +2031,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
                                           yyposn]b4_pure_args[));
               else if (yyflag == yyerr)
                 {
-                  YYDPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
+                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                   yymarkStackDeleted (yystackp, yynewStack);
                 }
               else
@@ -2030,7 +2043,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
             break;
           else if (yyisErrorAction (yyaction))
             {
-              YYDPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
+              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
               yymarkStackDeleted (yystackp, yyk);
               break;
             }
@@ -2040,10 +2053,10 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
                                                 yyimmediate[-yyaction]]b4_user_args[);
               if (yyflag == yyerr)
                 {
-                  YYDPRINTF ((stderr,
-                              "Stack %ld dies "
-                              "(predicate failure or explicit user error).\n",
-                              YY_CAST (long, yyk)));
+                  YY_DPRINTF ((stderr,
+                               "Stack %ld dies "
+                               "(predicate failure or explicit user error).\n",
+                               YY_CAST (long, yyk)));
                   yymarkStackDeleted (yystackp, yyk);
                   break;
                 }
@@ -2319,7 +2332,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   yyGLRStack* const yystackp = &yystack;
   ptrdiff_t yyposn;
 
-  YYDPRINTF ((stderr, "Starting parse\n"));
+  YY_DPRINTF ((stderr, "Starting parse\n"));
 
   yychar = YYEMPTY;
   yylval = yyval_default;]b4_locations_if([
@@ -2350,7 +2363,7 @@ b4_dollar_popdef])[]dnl
       while (yytrue)
         {
           yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
-          YYDPRINTF ((stderr, "Entering state %d\n", yystate));
+          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
           if (yystate == YYFINAL)
             goto yyacceptlab;
           if (yyisDefaultedState (yystate))
@@ -2430,7 +2443,7 @@ b4_dollar_popdef])[]dnl
               if (yystack.yytops.yysize == 0)
                 yyFail (&yystack][]b4_lpure_args[, YY_("syntax error"));
               YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
-              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));]b4_locations_if([[
+              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));]b4_locations_if([[
               yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
               yyreportSyntaxError (&yystack]b4_user_args[);
               goto yyuser_error;
@@ -2451,19 +2464,19 @@ b4_dollar_popdef])[]dnl
               int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                               &yyconflicts);
               /* Note that yyconflicts were handled by yyprocessOneStack.  */
-              YYDPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
+              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
               YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
               yyglrShift (&yystack, yys, yyaction, yyposn,
                           &yylval]b4_locations_if([, &yylloc])[);
-              YYDPRINTF ((stderr, "Stack %ld now in state #%d\n",
-                          YY_CAST (long, yys),
-                          yystack.yytops.yystates[yys]->yylrState));
+              YY_DPRINTF ((stderr, "Stack %ld now in state #%d\n",
+                           YY_CAST (long, yys),
+                           yystack.yytops.yystates[yys]->yylrState));
             }
 
           if (yystack.yytops.yysize == 1)
             {
               YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
-              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
+              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
               yycompressStack (&yystack);
               break;
             }
@@ -2536,19 +2549,19 @@ yy_yypstack (yyGLRState* yys)
   if (yys->yypred)
     {
       yy_yypstack (yys->yypred);
-      YYFPRINTF (stderr, " -> ");
+      YY_FPRINTF ((stderr, " -> "));
     }
-  YYFPRINTF (stderr, "%d@@%ld", yys->yylrState, YY_CAST (long, yys->yyposn));
+  YY_FPRINTF ((stderr, "%d@@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
 }
 
 static void
 yypstates (yyGLRState* yyst)
 {
   if (yyst == YY_NULLPTR)
-    YYFPRINTF (stderr, "<null>");
+    YY_FPRINTF ((stderr, "<null>"));
   else
     yy_yypstack (yyst);
-  YYFPRINTF (stderr, "\n");
+  YY_FPRINTF ((stderr, "\n"));
 }
 
 static void
@@ -2569,39 +2582,39 @@ yypdumpstack (yyGLRStack* yystackp)
   yyGLRStackItem* yyp;
   for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
     {
-      YYFPRINTF (stderr, "%3ld. ",
-                 YY_CAST (long, yyp - yystackp->yyitems));
+      YY_FPRINTF ((stderr, "%3ld. ",
+                   YY_CAST (long, yyp - yystackp->yyitems)));
       if (*YY_REINTERPRET_CAST (yybool *, yyp))
         {
           YYASSERT (yyp->yystate.yyisState);
           YYASSERT (yyp->yyoption.yyisState);
-          YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
-                     yyp->yystate.yyresolved, yyp->yystate.yylrState,
-                     YY_CAST (long, yyp->yystate.yyposn),
-                     YYINDEX (yyp->yystate.yypred));
+          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
+                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
+                       YY_CAST (long, yyp->yystate.yyposn),
+                       YYINDEX (yyp->yystate.yypred)));
           if (! yyp->yystate.yyresolved)
-            YYFPRINTF (stderr, ", firstVal: %ld",
-                       YYINDEX (yyp->yystate.yysemantics.yyfirstVal));
+            YY_FPRINTF ((stderr, ", firstVal: %ld",
+                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
         }
       else
         {
           YYASSERT (!yyp->yystate.yyisState);
           YYASSERT (!yyp->yyoption.yyisState);
-          YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
-                     yyp->yyoption.yyrule - 1,
-                     YYINDEX (yyp->yyoption.yystate),
-                     YYINDEX (yyp->yyoption.yynext));
+          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
+                       yyp->yyoption.yyrule - 1,
+                       YYINDEX (yyp->yyoption.yystate),
+                       YYINDEX (yyp->yyoption.yynext)));
         }
-      YYFPRINTF (stderr, "\n");
+      YY_FPRINTF ((stderr, "\n"));
     }
 
-  YYFPRINTF (stderr, "Tops:");
+  YY_FPRINTF ((stderr, "Tops:"));
   {
     ptrdiff_t yyi;
     for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
-      YYFPRINTF (stderr, "%ld: %ld; ", YY_CAST (long, yyi),
-                 YYINDEX (yystackp->yytops.yystates[yyi]));
-    YYFPRINTF (stderr, "\n");
+      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
+                   YYINDEX (yystackp->yytops.yystates[yyi])));
+    YY_FPRINTF ((stderr, "\n"));
   }
 #undef YYINDEX
 }
