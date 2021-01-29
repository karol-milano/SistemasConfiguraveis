@@ -1094,17 +1094,20 @@ yyinitStateSet (yyGLRStateSet* yyset)
 {
   yyset->yysize = 1;
   yyset->yycapacity = 16;
-  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
+  yyset->yystates
+    = (yyGLRState**) YYMALLOC (yyset->yycapacity * sizeof yyset->yystates[0]);
   if (! yyset->yystates)
     return yyfalse;
   yyset->yystates[0] = YY_NULLPTR;
-  yyset->yylookaheadNeeds =
-    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
+  yyset->yylookaheadNeeds
+    = (yybool*) YYMALLOC (yyset->yycapacity * sizeof yyset->yylookaheadNeeds[0]);
   if (! yyset->yylookaheadNeeds)
     {
       YYFREE (yyset->yystates);
       return yyfalse;
     }
+  memset (yyset->yylookaheadNeeds,
+          0, yyset->yycapacity * sizeof yyset->yylookaheadNeeds[0]);
   return yytrue;
 }
 
