@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.1.220-3e56-dirty.  */
+/* A Bison parser, made by GNU Bison 3.1.222-4227c.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.1.220-3e56-dirty"
+#define YYBISON_VERSION "3.1.222-4227c"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -2499,22 +2499,16 @@ yyreduce:
 #line 2500 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
-  case 67:
-#line 528 "src/parse-gram.y" /* yacc.c:1651  */
-    { (yyval.uniqstr) = (yyvsp[0].uniqstr); }
-#line 2506 "src/parse-gram.c" /* yacc.c:1651  */
-    break;
-
   case 68:
 #line 529 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2512 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2506 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 69:
 #line 530 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2518 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2512 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 70:
@@ -2523,7 +2517,7 @@ yyreduce:
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2527 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2521 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 71:
@@ -2532,7 +2526,7 @@ yyreduce:
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2536 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2530 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 72:
@@ -2542,7 +2536,7 @@ yyreduce:
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2546 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2540 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 73:
@@ -2552,7 +2546,7 @@ yyreduce:
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2556 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2550 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 74:
@@ -2563,7 +2557,7 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2567 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2561 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 81:
@@ -2571,13 +2565,13 @@ yyreduce:
     {
       yyerrok;
     }
-#line 2575 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2569 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 82:
 #line 594 "src/parse-gram.y" /* yacc.c:1651  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2581 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2575 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 83:
@@ -2586,122 +2580,116 @@ yyreduce:
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2590 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2584 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 84:
 #line 602 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2596 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2590 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 85:
 #line 603 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2602 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2596 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 87:
 #line 610 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2609 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2603 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 88:
 #line 613 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2615 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2609 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 89:
 #line 615 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), current_type); }
-#line 2621 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2615 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 90:
 #line 617 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_predicate_append ((yyvsp[0].code), (yylsp[0])); }
-#line 2627 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2621 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 91:
 #line 619 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2633 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2627 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 92:
 #line 621 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2639 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2633 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 93:
 #line 623 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2645 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2639 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 94:
 #line 625 "src/parse-gram.y" /* yacc.c:1651  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2651 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2645 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 95:
 #line 629 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.named_ref) = 0; }
-#line 2657 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2651 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 96:
 #line 630 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.named_ref) = named_ref_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2663 "src/parse-gram.c" /* yacc.c:1651  */
-    break;
-
-  case 97:
-#line 640 "src/parse-gram.y" /* yacc.c:1651  */
-    { (yyval.uniqstr) = (yyvsp[0].uniqstr); }
-#line 2669 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2657 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 98:
 #line 641 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].code)); }
-#line 2675 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2663 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 99:
 #line 666 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2681 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2669 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 100:
 #line 667 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].uniqstr); }
-#line 2687 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2675 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 101:
 #line 668 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].code); }
-#line 2693 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2681 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 102:
 #line 669 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].code)); }
-#line 2699 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2687 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 103:
 #line 682 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2705 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2693 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 104:
@@ -2711,25 +2699,13 @@ yyreduce:
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2715 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2703 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 105:
 #line 692 "src/parse-gram.y" /* yacc.c:1651  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2721 "src/parse-gram.c" /* yacc.c:1651  */
-    break;
-
-  case 106:
-#line 697 "src/parse-gram.y" /* yacc.c:1651  */
-    { (yyval.symbol) = (yyvsp[0].symbol); }
-#line 2727 "src/parse-gram.c" /* yacc.c:1651  */
-    break;
-
-  case 107:
-#line 698 "src/parse-gram.y" /* yacc.c:1651  */
-    { (yyval.symbol) = (yyvsp[0].symbol); }
-#line 2733 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2709 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 108:
@@ -2738,7 +2714,7 @@ yyreduce:
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].code)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2742 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2718 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
   case 110:
@@ -2747,11 +2723,11 @@ yyreduce:
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2751 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2727 "src/parse-gram.c" /* yacc.c:1651  */
     break;
 
 
-#line 2755 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2731 "src/parse-gram.c" /* yacc.c:1651  */
         default: break;
       }
     if (yychar_backup != yychar)
