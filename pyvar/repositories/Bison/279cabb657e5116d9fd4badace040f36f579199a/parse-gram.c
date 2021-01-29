@@ -685,7 +685,7 @@ static const yytype_uint16 yyrline[] =
      448,   454,   460,   471,   472,   481,   482,   488,   489,   490,
      497,   497,   501,   502,   503,   508,   509,   511,   513,   515,
      517,   527,   528,   534,   538,   547,   567,   569,   578,   583,
-     584,   589,   596,   598
+     584,   589,   598,   600
 };
 #endif
 
@@ -2577,14 +2577,16 @@ yyreduce:
 #line 590 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
-      symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
+      symbol_class_set ((yyval.symbol),
+                        current_class == unknown_sym
+                        ? token_sym : current_class, (yylsp[(1) - (1)]), false);
     }
     break;
 
   case 103:
 
 /* Line 1537 of yacc.c  */
-#line 599 "parse-gram.y"
+#line 601 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2598,7 +2600,7 @@ yyreduce:
 
 
 /* Line 1537 of yacc.c  */
-#line 2602 "parse-gram.c"
+#line 2604 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2817,7 +2819,7 @@ yyreturn:
 
 
 /* Line 1537 of yacc.c  */
-#line 609 "parse-gram.y"
+#line 611 "parse-gram.y"
 
 
 
