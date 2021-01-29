@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.266-78f6.  */
+/* A Bison parser, made by GNU Bison 2.4.294-184e3.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.266-78f6"
+#define YYBISON_VERSION "2.4.294-184e3"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -615,8 +615,8 @@ static const yytype_uint16 yyrline[] =
      428,   430,   435,   436,   440,   441,   442,   443,   448,   453,
      458,   464,   470,   481,   482,   491,   492,   498,   499,   500,
      507,   507,   511,   512,   513,   518,   519,   521,   523,   525,
-     527,   537,   538,   544,   547,   556,   576,   578,   587,   592,
-     593,   598,   605,   607
+     527,   537,   538,   543,   544,   553,   573,   575,   584,   589,
+     590,   595,   602,   604
 };
 #endif
 
@@ -2554,17 +2554,15 @@ yyreduce:
 
   case 93:
 /* Line 1380 of yacc.c  */
-#line 544 "parse-gram.y"
-    {
-      (yyval.chars) = "";
-    }
+#line 543 "parse-gram.y"
+    { (yyval.chars) = ""; }
 /* Line 1380 of yacc.c  */
-#line 2563 "../../src/parse-gram.c"
+#line 2561 "../../src/parse-gram.c"
     break;
 
   case 95:
 /* Line 1380 of yacc.c  */
-#line 557 "parse-gram.y"
+#line 554 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2574,51 +2572,51 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1380 of yacc.c  */
-#line 2578 "../../src/parse-gram.c"
+#line 2576 "../../src/parse-gram.c"
     break;
 
   case 96:
 /* Line 1380 of yacc.c  */
-#line 577 "parse-gram.y"
+#line 574 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2586 "../../src/parse-gram.c"
+#line 2584 "../../src/parse-gram.c"
     break;
 
   case 97:
 /* Line 1380 of yacc.c  */
-#line 579 "parse-gram.y"
+#line 576 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2598 "../../src/parse-gram.c"
+#line 2596 "../../src/parse-gram.c"
     break;
 
   case 98:
 /* Line 1380 of yacc.c  */
-#line 587 "parse-gram.y"
+#line 584 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2606 "../../src/parse-gram.c"
+#line 2604 "../../src/parse-gram.c"
     break;
 
   case 101:
 /* Line 1380 of yacc.c  */
-#line 599 "parse-gram.y"
+#line 596 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1380 of yacc.c  */
-#line 2617 "../../src/parse-gram.c"
+#line 2615 "../../src/parse-gram.c"
     break;
 
   case 103:
 /* Line 1380 of yacc.c  */
-#line 608 "parse-gram.y"
+#line 605 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2628,12 +2626,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2632 "../../src/parse-gram.c"
+#line 2630 "../../src/parse-gram.c"
     break;
 
 
 /* Line 1380 of yacc.c  */
-#line 2637 "../../src/parse-gram.c"
+#line 2635 "../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2850,7 +2848,7 @@ yyreturn:
 }
 
 /* Line 1599 of yacc.c  */
-#line 618 "parse-gram.y"
+#line 615 "parse-gram.y"
 
 
 
