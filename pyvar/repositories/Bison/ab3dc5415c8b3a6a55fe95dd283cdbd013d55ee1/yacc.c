@@ -974,9 +974,10 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
         {
           const int yylhs = yyr1[yyrule] - YYNTOKENS;
           const int yyi = yypgoto[yylhs] + *yyesp;
-          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
-                     ? yytable[yyi]
-                     : yydefgoto[yylhs]);
+          yystate = ((yytype_int16)
+                     (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
+                      ? yytable[yyi]
+                      : yydefgoto[yylhs]));
         }
         if (yyesp == yyes_prev)
           {
@@ -996,7 +997,7 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
               }
             *++yyesp = yystate;
           }
-        YYDPRINTF ((stderr, " G%d", yystate));
+        YYDPRINTF ((stderr, " G%hd", yystate));
       }
     }
 }]])[
