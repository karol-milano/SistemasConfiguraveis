@@ -502,7 +502,7 @@ static void yypdumpstack (struct yyGLRStack* yystackp)
 
 #else /* !]b4_api_PREFIX[DEBUG */
 
-# define YYDPRINTF(Args)
+# define YYDPRINTF(Args) do {} while (yyfalse)
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 
 #endif /* !]b4_api_PREFIX[DEBUG */
@@ -1272,9 +1272,7 @@ yyremoveDeletes (yyGLRStack* yystackp)
       if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
         {
           if (yyi == yyj)
-            {
-              YYDPRINTF ((stderr, "Removing dead stacks.\n"));
-            }
+            YYDPRINTF ((stderr, "Removing dead stacks.\n"));
           yystackp->yytops.yysize -= 1;
         }
       else
@@ -1288,10 +1286,8 @@ yyremoveDeletes (yyGLRStack* yystackp)
           yystackp->yytops.yylookaheadNeeds[yyj] =
             yystackp->yytops.yylookaheadNeeds[yyi];
           if (yyj != yyi)
-            {
-              YYDPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
-                          YY_CAST (long, yyi), YY_CAST (long, yyj)));
-            }
+            YYDPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
+                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
           yyj += 1;
         }
       yyi += 1;
@@ -1451,11 +1447,9 @@ yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
 
       YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval]b4_locuser_args([&yyloc])[);
       if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
-        {
-          YYDPRINTF ((stderr,
-                      "Parse on stack %ld rejected by rule %d (line %d).\n",
-                      YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1]));
-        }
+        YYDPRINTF ((stderr,
+                    "Parse on stack %ld rejected by rule %d (line %d).\n",
+                    YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1]));
       if (yyflag != yyok)
         return yyflag;
       YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
