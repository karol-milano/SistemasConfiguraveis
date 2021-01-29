@@ -337,7 +337,7 @@ b4_percent_code_get[]dnl
 #define YYMAXUTOK   ]b4_user_token_number_max[
 
 #define YYTRANSLATE(YYX)                                                \
-  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
+  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
 static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
@@ -398,9 +398,9 @@ static const ]b4_int_type_for([b4_conflict_list_heads])[ yyconflp[] =
 /* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
    0, pointed into by YYCONFLP.  */
 ]dnl Do not use b4_int_type_for here, since there are places where
-dnl pointers onto yyconfl are taken, whose type is "short int *".
+dnl pointers onto yyconfl are taken, whose type is "short*".
 dnl We probably ought to introduce a type for confl.
-[static const short int yyconfl[] =
+[static const short yyconfl[] =
 {
   ]b4_conflicting_rules[
 };
@@ -613,7 +613,7 @@ typedef int yyRuleNum;
 typedef int yySymbol;
 
 /** Item references, as in LALR(1) machine */
-typedef short int yyItemNum;
+typedef short yyItemNum;
 
 typedef struct yyGLRState yyGLRState;
 typedef struct yyGLRStateSet yyGLRStateSet;
@@ -923,7 +923,7 @@ yydefaultAction (yyStateNum yystate)
  */
 static inline void
 yygetLRActions (yyStateNum yystate, int yytoken,
-                int* yyaction, const short int** yyconflicts)
+                int* yyaction, const short** yyconflicts)
 {
   int yyindex = yypact[yystate] + yytoken;
   if (yypact_value_is_default (yypact[yystate])
@@ -1196,7 +1196,7 @@ yyremoveDeletes (yyGLRStack* yystackp)
           if (yyj != yyi)
             {
               YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
-                          (unsigned long int) yyi, (unsigned long int) yyj));
+                          (unsigned long) yyi, (unsigned long) yyj));
             }
           yyj += 1;
         }
@@ -1267,8 +1267,8 @@ yy_reduce_print (int yynormal, yyGLRStackItem* yyvsp, size_t yyk,
   int yylow = 1;])[
   int yyi;
   YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
-             (unsigned long int) yyk, yyrule - 1,
-             (unsigned long int) yyrline[yyrule]);
+             (unsigned long) yyk, yyrule - 1,
+             (unsigned long) yyrline[yyrule]);
   if (! yynormal)
     yyfillin (yyvsp, 1, -yynrhs);
   /* The symbols being reduced.  */
@@ -1360,7 +1360,7 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
         {
           YYDPRINTF ((stderr, "Parse on stack %lu rejected by rule #%d.\n",
-                     (unsigned long int) yyk, yyrule - 1));
+                     (unsigned long) yyk, yyrule - 1));
         }
       if (yyflag != yyok)
         return yyflag;
@@ -1388,7 +1388,7 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       YYDPRINTF ((stderr,
                   "Reduced stack %lu by rule #%d; action deferred.  "
                   "Now in state %d.\n",
-                  (unsigned long int) yyk, yyrule - 1, yynewLRState));
+                  (unsigned long) yyk, yyrule - 1, yynewLRState));
       for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
         if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
           {
@@ -1401,8 +1401,8 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
                     yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                     yymarkStackDeleted (yystackp, yyk);
                     YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
-                                (unsigned long int) yyk,
-                                (unsigned long int) yyi));
+                                (unsigned long) yyk,
+                                (unsigned long) yyi));
                     return yyok;
                   }
                 yyp = yyp->yypred;
@@ -1648,8 +1648,8 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
   else
     YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
                yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
-               yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
-               (unsigned long int) yyx->yystate->yyposn);
+               yyx->yyrule - 1, (unsigned long) (yys->yyposn + 1),
+               (unsigned long) yyx->yystate->yyposn);
   for (yyi = 1; yyi <= yynrhs; yyi += 1)
     {
       if (yystates[yyi]->yyresolved)
@@ -1660,8 +1660,8 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
           else
             YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
                        yytokenName (yystos[yystates[yyi]->yylrState]),
-                       (unsigned long int) (yystates[yyi-1]->yyposn + 1),
-                       (unsigned long int) yystates[yyi]->yyposn);
+                       (unsigned long) (yystates[yyi-1]->yyposn + 1),
+                       (unsigned long) yystates[yyi]->yyposn);
         }
       else
         yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
@@ -1881,7 +1881,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
     {
       yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
       YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
-                  (unsigned long int) yyk, yystate));
+                  (unsigned long) yyk, yystate));
 
       YYASSERT (yystate != YYFINAL);
 
@@ -1892,7 +1892,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
           if (yyrule == 0)
             {
               YYDPRINTF ((stderr, "Stack %lu dies.\n",
-                          (unsigned long int) yyk));
+                          (unsigned long) yyk));
               yymarkStackDeleted (yystackp, yyk);
               return yyok;
             }
@@ -1902,7 +1902,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
               YYDPRINTF ((stderr,
                           "Stack %lu dies "
                           "(predicate failure or explicit user error).\n",
-                          (unsigned long int) yyk));
+                          (unsigned long) yyk));
               yymarkStackDeleted (yystackp, yyk);
               return yyok;
             }
@@ -1913,7 +1913,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
         {
           yySymbol yytoken;
           int yyaction;
-          const short int* yyconflicts;
+          const short* yyconflicts;
 
           yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
           if (yychar == YYEMPTY)
@@ -1940,8 +1940,8 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
               YYRESULTTAG yyflag;
               size_t yynewStack = yysplitStack (yystackp, yyk);
               YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
-                          (unsigned long int) yynewStack,
-                          (unsigned long int) yyk));
+                          (unsigned long) yynewStack,
+                          (unsigned long) yyk));
               yyflag = yyglrReduce (yystackp, yynewStack,
                                     *yyconflicts,
                                     yyimmediate[*yyconflicts]]b4_user_args[);
@@ -1951,7 +1951,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
               else if (yyflag == yyerr)
                 {
                   YYDPRINTF ((stderr, "Stack %lu dies.\n",
-                              (unsigned long int) yynewStack));
+                              (unsigned long) yynewStack));
                   yymarkStackDeleted (yystackp, yynewStack);
                 }
               else
@@ -1964,7 +1964,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
           else if (yyisErrorAction (yyaction))
             {
               YYDPRINTF ((stderr, "Stack %lu dies.\n",
-                          (unsigned long int) yyk));
+                          (unsigned long) yyk));
               yymarkStackDeleted (yystackp, yyk);
               break;
             }
@@ -1977,7 +1977,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
                   YYDPRINTF ((stderr,
                               "Stack %lu dies "
                               "(predicate failure or explicit user error).\n",
-                              (unsigned long int) yyk));
+                              (unsigned long) yyk));
                   yymarkStackDeleted (yystackp, yyk);
                   break;
                 }
@@ -2286,7 +2286,7 @@ b4_dollar_popdef])[]dnl
         {
           yyRuleNum yyrule;
           int yyaction;
-          const short int* yyconflicts;
+          const short* yyconflicts;
 
           yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
           YYDPRINTF ((stderr, "Entering state %d\n", yystate));
@@ -2399,17 +2399,17 @@ b4_dollar_popdef])[]dnl
           for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
             {
               int yyaction;
-              const short int* yyconflicts;
+              const short* yyconflicts;
               yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
               yygetLRActions (yystate, yytoken_to_shift, &yyaction,
                               &yyconflicts);
               /* Note that yyconflicts were handled by yyprocessOneStack.  */
-              YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
+              YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long) yys));
               YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
               yyglrShift (&yystack, yys, yyaction, yyposn,
                           &yylval]b4_locations_if([, &yylloc])[);
               YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
-                          (unsigned long int) yys,
+                          (unsigned long) yys,
                           yystack.yytops.yystates[yys]->yylrState));
             }
 
@@ -2492,7 +2492,7 @@ yy_yypstack (yyGLRState* yys)
       YYFPRINTF (stderr, " -> ");
     }
   YYFPRINTF (stderr, "%d@@%lu", yys->yylrState,
-             (unsigned long int) yys->yyposn);
+             (unsigned long) yys->yyposn);
 }
 
 static void
@@ -2523,18 +2523,18 @@ yypdumpstack (yyGLRStack* yystackp)
   for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
     {
       YYFPRINTF (stderr, "%3lu. ",
-                 (unsigned long int) (yyp - yystackp->yyitems));
+                 (unsigned long) (yyp - yystackp->yyitems));
       if (*(yybool *) yyp)
         {
           YYASSERT (yyp->yystate.yyisState);
           YYASSERT (yyp->yyoption.yyisState);
           YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
                      yyp->yystate.yyresolved, yyp->yystate.yylrState,
-                     (unsigned long int) yyp->yystate.yyposn,
-                     (long int) YYINDEX (yyp->yystate.yypred));
+                     (unsigned long) yyp->yystate.yyposn,
+                     (long) YYINDEX (yyp->yystate.yypred));
           if (! yyp->yystate.yyresolved)
             YYFPRINTF (stderr, ", firstVal: %ld",
-                       (long int) YYINDEX (yyp->yystate
+                       (long) YYINDEX (yyp->yystate
                                              .yysemantics.yyfirstVal));
         }
       else
@@ -2543,15 +2543,15 @@ yypdumpstack (yyGLRStack* yystackp)
           YYASSERT (!yyp->yyoption.yyisState);
           YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
                      yyp->yyoption.yyrule - 1,
-                     (long int) YYINDEX (yyp->yyoption.yystate),
-                     (long int) YYINDEX (yyp->yyoption.yynext));
+                     (long) YYINDEX (yyp->yyoption.yystate),
+                     (long) YYINDEX (yyp->yyoption.yynext));
         }
       YYFPRINTF (stderr, "\n");
     }
   YYFPRINTF (stderr, "Tops:");
   for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
-    YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long int) yyi,
-               (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
+    YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long) yyi,
+               (long) YYINDEX (yystackp->yytops.yystates[yyi]));
   YYFPRINTF (stderr, "\n");
 }
 #endif
