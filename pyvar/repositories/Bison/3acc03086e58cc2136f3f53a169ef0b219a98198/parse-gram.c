@@ -2129,8 +2129,8 @@ yyreduce:
 /* Line 1269 of yacc.c.  */
 #line 347 "parse-gram.y"
     {
-      tag_seen = true;
       symbol_list *list;
+      tag_seen = true;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
 	symbol_type_set (list->content.sym, (yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]));
       symbol_list_free ((yyvsp[(3) - (3)].list));
