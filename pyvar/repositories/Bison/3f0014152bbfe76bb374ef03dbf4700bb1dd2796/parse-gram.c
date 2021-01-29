@@ -1912,7 +1912,7 @@ yyreduce:
     {
       symbol_list *list;
       for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
-	symbol_printer_set (list->sym, (yyvsp[(1) - (2)].chars), list->location);
+	symbol_printer_set (list->sym, (yyvsp[(1) - (2)].chars), (yylsp[(1) - (2)]));
       symbol_list_free ((yyvsp[(2) - (2)].list));
     }
     break;
