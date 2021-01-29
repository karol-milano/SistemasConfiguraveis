@@ -1390,7 +1390,7 @@ yyreduce:
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
-      symbol_make_alias (yyvsp[-1].symbol, yyvsp[0].symbol);
+      symbol_make_alias (yyvsp[-1].symbol, yyvsp[0].symbol, yyloc);
     }
     break;
 
@@ -1400,7 +1400,7 @@ yyreduce:
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
       symbol_user_token_number_set (yyvsp[-2].symbol, yyvsp[-1].integer, yylsp[-1]);
-      symbol_make_alias (yyvsp[-2].symbol, yyvsp[0].symbol);
+      symbol_make_alias (yyvsp[-2].symbol, yyvsp[0].symbol, yyloc);
     }
     break;
 
