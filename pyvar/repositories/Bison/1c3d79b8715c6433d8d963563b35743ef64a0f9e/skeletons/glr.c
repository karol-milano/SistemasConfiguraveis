@@ -2034,7 +2034,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
           const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
           yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
 
-          while (*yyconflicts != 0)
+          for (/* nothing */; *yyconflicts; yyconflicts += 1)
             {
               YYRESULTTAG yyflag;
               ptrdiff_t yynewStack = yysplitStack (yystackp, yyk);
@@ -2053,7 +2053,6 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
                 }
               else
                 return yyflag;
-              yyconflicts += 1;
             }
 
           if (yyisShiftAction (yyaction))
@@ -2450,7 +2449,7 @@ b4_dollar_popdef])[]dnl
       /* For efficiency, we have two loops, the first of which is
          specialized to deterministic operation (single stack, no
          potential ambiguity).  */
-      /* Standard mode */
+      /* Standard mode. */
       while (yytrue)
         {
           yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
@@ -2473,7 +2472,8 @@ b4_dollar_popdef])[]dnl
               yysymbol_kind_t yytoken = ]b4_yygetToken_call;[
               const short* yyconflicts;
               int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
-              if (*yyconflicts != 0)
+              if (*yyconflicts)
+                /* Enter nondeterministic mode.  */
                 break;
               if (yyisShiftAction (yyaction))
                 {
@@ -2499,6 +2499,7 @@ b4_dollar_popdef])[]dnl
             }
         }
 
+      /* Nondeterministic mode. */
       while (yytrue)
         {
           yysymbol_kind_t yytoken_to_shift;
