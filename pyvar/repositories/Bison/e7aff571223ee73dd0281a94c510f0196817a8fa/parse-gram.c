@@ -2367,7 +2367,7 @@ yyreduce:
       (yyval.token_decl) = (yyvsp[-2].id);
       symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
       if (0 <= (yyvsp[-1].yykind_82))
-        symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yykind_82), (yylsp[-1]));
+        symbol_code_set ((yyvsp[-2].id), (yyvsp[-1].yykind_82), (yylsp[-1]));
       if ((yyvsp[0].alias))
         symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].alias), (yylsp[0]));
     }
@@ -2424,7 +2424,7 @@ yyreduce:
       (yyval.token_decl_for_prec) = (yyvsp[-1].id);
       symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
       if (0 <= (yyvsp[0].yykind_82))
-        symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yykind_82), (yylsp[0]));
+        symbol_code_set ((yyvsp[-1].id), (yyvsp[0].yykind_82), (yylsp[0]));
     }
     break;
 
@@ -2573,7 +2573,7 @@ yyreduce:
         }
       (yyval.id) = symbol_get (char_name ((yyvsp[0].CHAR)), (yylsp[0]));
       symbol_class_set ((yyval.id), token_sym, (yylsp[0]), false);
-      symbol_user_token_number_set ((yyval.id), (yyvsp[0].CHAR), (yylsp[0]));
+      symbol_code_set ((yyval.id), (yyvsp[0].CHAR), (yylsp[0]));
     }
     break;
 
