@@ -1489,7 +1489,7 @@ yyreduce:
 
   case 64:
 #line 339 "parse-gram.y"
-    { yyval.symbol = getsym (yyvsp[0].string); }
+    { yyval.symbol = getsym (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 65:
@@ -1500,7 +1500,7 @@ yyreduce:
   case 66:
 #line 350 "parse-gram.y"
     {
-      yyval.symbol = getsym (yyvsp[0].string);
+      yyval.symbol = getsym (yyvsp[0].string, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym);
     }
     break;
