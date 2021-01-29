@@ -654,8 +654,8 @@ static const yytype_uint16 yyrline[] =
      305,   309,   323,   324,   328,   350,   350,   355,   355,   360,
      370,   385,   386,   387,   391,   392,   397,   398,   403,   407,
      412,   418,   424,   435,   436,   445,   446,   452,   453,   454,
-     461,   461,   465,   466,   467,   472,   473,   475,   478,   480,
-     482,   495,   497,   506,   511,   512,   517,   526,   531,   533
+     461,   461,   465,   466,   467,   472,   473,   475,   481,   483,
+     485,   498,   500,   509,   514,   515,   520,   529,   534,   536
 };
 #endif
 
@@ -2173,32 +2173,35 @@ yyreduce:
 
   case 77:
 #line 476 "parse-gram.y"
-    { grammar_current_rule_action_append (gram_last_string,
-					  gram_last_braced_code_loc); }
+    {
+      if (current_rule && current_rule->action)
+	grammar_midrule_action ();
+      grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
+    }
     break;
 
   case 78:
-#line 479 "parse-gram.y"
+#line 482 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 79:
-#line 481 "parse-gram.y"
+#line 484 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 80:
-#line 483 "parse-gram.y"
+#line 486 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 81:
-#line 496 "parse-gram.y"
+#line 499 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 82:
-#line 498 "parse-gram.y"
+#line 501 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2207,12 +2210,12 @@ yyreduce:
     break;
 
   case 83:
-#line 506 "parse-gram.y"
+#line 509 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 86:
-#line 518 "parse-gram.y"
+#line 521 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2220,12 +2223,12 @@ yyreduce:
     break;
 
   case 87:
-#line 527 "parse-gram.y"
+#line 530 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 89:
-#line 534 "parse-gram.y"
+#line 537 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])), (yylsp[(2) - (2)]));
       gram_scanner_last_string_free ();
@@ -2234,7 +2237,7 @@ yyreduce:
 
 
 /* Line 1274 of yacc.c.  */
-#line 2238 "parse-gram.c"
+#line 2241 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2454,7 +2457,7 @@ yyreturn:
 }
 
 
-#line 540 "parse-gram.y"
+#line 543 "parse-gram.y"
 
 
 
