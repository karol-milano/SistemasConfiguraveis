@@ -2804,7 +2804,7 @@ yyreduce:
   case 69:
 /* Line 1721 of yacc.c  */
 #line 526 "src/parse-gram.y"
-    { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
+    { (yyval.list) = symbol_list_type_new ("*", (yylsp[0])); }
 /* Line 1721 of yacc.c  */
 #line 2810 "src/parse-gram.c"
     break;
@@ -2812,7 +2812,7 @@ yyreduce:
   case 70:
 /* Line 1721 of yacc.c  */
 #line 527 "src/parse-gram.y"
-    { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
+    { (yyval.list) = symbol_list_type_new ("", (yylsp[0])); }
 /* Line 1721 of yacc.c  */
 #line 2818 "src/parse-gram.c"
     break;
