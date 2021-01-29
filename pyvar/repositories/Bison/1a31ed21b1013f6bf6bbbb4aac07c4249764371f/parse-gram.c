@@ -1250,7 +1250,7 @@ yyreduce:
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
-	symbol_destructor_set (list->sym, list->location, yyvsp[-1].string);
+	symbol_destructor_set (list->sym, yyvsp[-1].string, yylsp[-1]);
       symbol_list_free (yyvsp[0].list);
       current_braced_code = action_braced_code;
     }
@@ -1303,7 +1303,7 @@ yyreduce:
     {
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
-	symbol_type_set (list->sym, list->location, yyvsp[-1].string);
+	symbol_type_set (list->sym, yyvsp[-1].string, yylsp[-1]);
       symbol_list_free (yyvsp[0].list);
     }
     break;
@@ -1315,8 +1315,8 @@ yyreduce:
       ++current_prec;
       for (list = yyvsp[0].list; list; list = list->next)
 	{
-	  symbol_type_set (list->sym, list->location, current_type);
-	  symbol_precedence_set (list->sym, list->location, current_prec, yyvsp[-2].assoc);
+	  symbol_type_set (list->sym, current_type, yylsp[-1]);
+	  symbol_precedence_set (list->sym, current_prec, yyvsp[-2].assoc, yylsp[-2]);
 	}
       symbol_list_free (yyvsp[0].list);
       current_type = NULL;
@@ -1369,7 +1369,7 @@ yyreduce:
 #line 288 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
-       symbol_type_set (yyvsp[0].symbol, yylsp[0], current_type);
+       symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
      }
     break;
 
@@ -1377,7 +1377,7 @@ yyreduce:
 #line 293 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
-      symbol_type_set (yyvsp[-1].symbol, yylsp[-1], current_type);
+      symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
       symbol_user_token_number_set (yyvsp[-1].symbol, yyvsp[0].integer, yylsp[0]);
     }
     break;
@@ -1386,7 +1386,7 @@ yyreduce:
 #line 299 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
-      symbol_type_set (yyvsp[-1].symbol, yylsp[-1], current_type);
+      symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
       symbol_make_alias (yyvsp[-1].symbol, yyvsp[0].symbol);
     }
     break;
@@ -1395,7 +1395,7 @@ yyreduce:
 #line 305 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
-      symbol_type_set (yyvsp[-2].symbol, yylsp[-2], current_type);
+      symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
       symbol_user_token_number_set (yyvsp[-2].symbol, yyvsp[-1].integer, yylsp[-1]);
       symbol_make_alias (yyvsp[-2].symbol, yyvsp[0].symbol);
     }
