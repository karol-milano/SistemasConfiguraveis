@@ -972,13 +972,11 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
       {
         int yystate;
         {
-          int yylhs = yyr1[yyrule] - YYNTOKENS;
-          yystate = yypgoto[yylhs] + *yyesp;
-          if (yystate < 0 || YYLAST < yystate
-              || yycheck[yystate] != *yyesp)
-            yystate = yydefgoto[yylhs];
-          else
-            yystate = yytable[yystate];
+          const int yylhs = yyr1[yyrule] - YYNTOKENS;
+          const int yyi = yypgoto[yylhs] + *yyesp;
+          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
+                     ? yytable[yyi]
+                     : yydefgoto[yylhs]);
         }
         if (yyesp == yyes_prev)
           {
@@ -1683,14 +1681,13 @@ yyreduce:
   /* Now 'shift' the result of the reduction.  Determine what state
      that goes to, based on the state we popped back to and the rule
      number reduced by.  */
-
-  yyn = yyr1[yyn];
-
-  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
-  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
-    yystate = yytable[yystate];
-  else
-    yystate = yydefgoto[yyn - YYNTOKENS];
+  {
+    const int yylhs = yyr1[yyn] - YYNTOKENS;
+    const int yyi = yypgoto[yylhs] + *yyssp;
+    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
+               ? yytable[yyi]
+               : yydefgoto[yylhs]);
+  }
 
   goto yynewstate;
 
