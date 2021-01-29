@@ -910,14 +910,18 @@ yygetLRActions (yyStateNum yystate, int yytoken,
     }
 }
 
+/** Compute post-reduction state.
+ * \param yystate   the current state
+ * \param yysym     the nonterminal to push on the stack
+ */
 static inline yyStateNum
-yyLRgotoState (yyStateNum yystate, yySymbol yylhs)
+yyLRgotoState (yyStateNum yystate, yySymbol yysym)
 {
-  int yyr = yypgoto[yylhs - YYNTOKENS] + yystate;
+  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
   if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
     return yytable[yyr];
   else
-    return yydefgoto[yylhs - YYNTOKENS];
+    return yydefgoto[yysym - YYNTOKENS];
 }
 
 static inline yybool
