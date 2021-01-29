@@ -2571,7 +2571,7 @@ yyreduce:
           else
             symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_94), (yylsp[0]));
         }
-      if (current_class != token_sym && (0 <= (yyvsp[-1].yytype_79) || !(yyvsp[0].yytype_94)))
+      if (current_class != token_sym && (0 <= (yyvsp[-1].yytype_79) || (yyvsp[0].yytype_94)))
         YYERROR;
     }
 #line 2578 "src/parse-gram.c" /* yacc.c:1649  */
