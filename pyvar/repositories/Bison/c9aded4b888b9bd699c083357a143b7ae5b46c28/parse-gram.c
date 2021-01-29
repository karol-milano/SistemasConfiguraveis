@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.305-d937.  */
+/* A Bison parser, made by GNU Bison 2.4.307-8f0d-dirty.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.305-d937"
+#define YYBISON_VERSION "2.4.307-8f0d-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -615,8 +615,8 @@ static const yytype_uint16 yyrline[] =
      428,   430,   435,   436,   440,   441,   442,   443,   448,   453,
      458,   464,   470,   481,   482,   491,   492,   498,   499,   500,
      507,   507,   511,   512,   513,   518,   519,   521,   523,   525,
-     527,   537,   538,   543,   544,   553,   573,   575,   584,   589,
-     590,   595,   602,   604
+     527,   539,   540,   545,   546,   555,   575,   577,   586,   591,
+     592,   597,   604,   606
 };
 #endif
 
@@ -2546,7 +2546,7 @@ yyreduce:
 
   case 92:
 /* Line 1380 of yacc.c  */
-#line 538 "parse-gram.y"
+#line 540 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
 #line 2553 "src/parse-gram.c"
@@ -2554,7 +2554,7 @@ yyreduce:
 
   case 93:
 /* Line 1380 of yacc.c  */
-#line 543 "parse-gram.y"
+#line 545 "parse-gram.y"
     { (yyval.chars) = ""; }
 /* Line 1380 of yacc.c  */
 #line 2561 "src/parse-gram.c"
@@ -2562,7 +2562,7 @@ yyreduce:
 
   case 95:
 /* Line 1380 of yacc.c  */
-#line 554 "parse-gram.y"
+#line 556 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2577,7 +2577,7 @@ yyreduce:
 
   case 96:
 /* Line 1380 of yacc.c  */
-#line 574 "parse-gram.y"
+#line 576 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
 #line 2584 "src/parse-gram.c"
@@ -2585,7 +2585,7 @@ yyreduce:
 
   case 97:
 /* Line 1380 of yacc.c  */
-#line 576 "parse-gram.y"
+#line 578 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
@@ -2597,7 +2597,7 @@ yyreduce:
 
   case 98:
 /* Line 1380 of yacc.c  */
-#line 584 "parse-gram.y"
+#line 586 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
 #line 2604 "src/parse-gram.c"
@@ -2605,7 +2605,7 @@ yyreduce:
 
   case 101:
 /* Line 1380 of yacc.c  */
-#line 596 "parse-gram.y"
+#line 598 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
@@ -2616,7 +2616,7 @@ yyreduce:
 
   case 103:
 /* Line 1380 of yacc.c  */
-#line 605 "parse-gram.y"
+#line 607 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2848,7 +2848,7 @@ yyreturn:
 }
 
 /* Line 1599 of yacc.c  */
-#line 615 "parse-gram.y"
+#line 617 "parse-gram.y"
 
 
 
