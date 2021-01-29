@@ -1319,7 +1319,7 @@ yyreduce:
       symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
 	symbol_type_set (list->sym, list->location, yyvsp[-1].string);
-      LIST_FREE (symbol_list_t, yyvsp[0].list);
+      symbol_list_free (yyvsp[0].list);
     }
     break;
 
@@ -1333,7 +1333,7 @@ yyreduce:
 	  symbol_type_set (list->sym, list->location, current_type);
 	  symbol_precedence_set (list->sym, list->location, current_prec, yyvsp[-2].assoc);
 	}
-      LIST_FREE (symbol_list_t, yyvsp[0].list);
+      symbol_list_free (yyvsp[0].list);
       current_type = NULL;
     }
     break;
