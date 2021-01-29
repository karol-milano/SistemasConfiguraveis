@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.1.49-783b.  */
+/* A Bison parser, made by GNU Bison 2.4.1.52-77be.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.49-783b"
+#define YYBISON_VERSION "2.4.1.52-77be"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -672,8 +672,8 @@ static const yytype_uint16 yyrline[] =
      434,   435,   440,   442,   447,   448,   452,   453,   454,   455,
      460,   465,   470,   476,   482,   493,   494,   503,   504,   510,
      511,   512,   519,   519,   523,   524,   525,   530,   531,   533,
-     535,   537,   539,   549,   550,   556,   559,   568,   588,   590,
-     599,   604,   605,   610,   617,   619
+     535,   537,   539,   549,   550,   555,   556,   565,   585,   587,
+     596,   601,   602,   607,   614,   616
 };
 #endif
 
@@ -2551,16 +2551,14 @@ yyreduce:
   case 95:
 
 /* Line 1456 of yacc.c  */
-#line 556 "parse-gram.y"
-    {
-      (yyval.chars) = "";
-    }
+#line 555 "parse-gram.y"
+    { (yyval.chars) = ""; }
     break;
 
   case 97:
 
 /* Line 1456 of yacc.c  */
-#line 569 "parse-gram.y"
+#line 566 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2574,14 +2572,14 @@ yyreduce:
   case 98:
 
 /* Line 1456 of yacc.c  */
-#line 589 "parse-gram.y"
+#line 586 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 99:
 
 /* Line 1456 of yacc.c  */
-#line 591 "parse-gram.y"
+#line 588 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2592,14 +2590,14 @@ yyreduce:
   case 100:
 
 /* Line 1456 of yacc.c  */
-#line 599 "parse-gram.y"
+#line 596 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 103:
 
 /* Line 1456 of yacc.c  */
-#line 611 "parse-gram.y"
+#line 608 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2609,7 +2607,7 @@ yyreduce:
   case 105:
 
 /* Line 1456 of yacc.c  */
-#line 620 "parse-gram.y"
+#line 617 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2623,7 +2621,7 @@ yyreduce:
 
 
 /* Line 1456 of yacc.c  */
-#line 2627 "parse-gram.c"
+#line 2625 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2842,7 +2840,7 @@ yyreturn:
 
 
 /* Line 1676 of yacc.c  */
-#line 630 "parse-gram.y"
+#line 627 "parse-gram.y"
 
 
 
