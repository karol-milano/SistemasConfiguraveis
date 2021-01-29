@@ -2676,7 +2676,7 @@ yyreduce:
 #line 683 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props plain_code;
-      (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
+      (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\0';
       code_props_plain_init (&plain_code, (yyvsp[0].code)+1, (yylsp[0]));
       code_props_translate_code (&plain_code);
       gram_scanner_last_string_free ();
