@@ -1661,7 +1661,7 @@ yyreportAmbiguity (yySemanticOption* yyx0,
  *  ending at YYS1.  Has no effect on previously resolved states.
  *  The first semantic option of a state is always chosen.  */
 static void
-yyresolveLocations (yyGLRState* yys1, int yyn1,
+yyresolveLocations (yyGLRState *yys1, int yyn1,
                     yyGLRStack *yystackp]b4_user_formals[)
 {
   if (0 < yyn1)
@@ -1672,9 +1672,9 @@ yyresolveLocations (yyGLRState* yys1, int yyn1,
           yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
           int yynrhs;
           yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
-          YYASSERT (yyoption != YY_NULL);
+          YYASSERT (yyoption);
           yynrhs = yyrhsLength (yyoption->yyrule);
-          if (yynrhs > 0)
+          if (0 < yynrhs)
             {
               yyGLRState *yys;
               int yyn;
@@ -1697,18 +1697,7 @@ yyresolveLocations (yyGLRState* yys1, int yyn1,
               yyGLRState *yyprevious = yyoption->yystate;
               yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
             }
-          {
-            int yychar_current = yychar;
-            YYSTYPE yylval_current = yylval;
-            YYLTYPE yylloc_current = yylloc;
-            yychar = yyoption->yyrawchar;
-            yylval = yyoption->yyval;
-            yylloc = yyoption->yyloc;
-            YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
-            yychar = yychar_current;
-            yylval = yylval_current;
-            yylloc = yylloc_current;
-          }
+          YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
         }
     }
 }]])[
