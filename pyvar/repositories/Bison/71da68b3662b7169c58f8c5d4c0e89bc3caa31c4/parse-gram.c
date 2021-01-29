@@ -2307,7 +2307,7 @@ yyreduce:
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
-        symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
+        symbol_list_code_props_set (list, destructor, (yylsp[-1]), (yyvsp[-1].code));
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1735 of yacc.c  */
@@ -2320,7 +2320,7 @@ yyreduce:
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
-        symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
+        symbol_list_code_props_set (list, printer, (yylsp[-1]), (yyvsp[-1].code));
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1735 of yacc.c  */
