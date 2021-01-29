@@ -78,8 +78,8 @@
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
-   Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
-   Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009 Free
+   Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -672,8 +672,8 @@ static const yytype_uint16 yyrline[] =
      434,   435,   440,   442,   447,   448,   452,   453,   454,   455,
      460,   465,   470,   476,   482,   493,   494,   503,   504,   510,
      511,   512,   519,   519,   523,   524,   525,   530,   531,   533,
-     535,   537,   539,   549,   550,   555,   556,   565,   585,   587,
-     596,   601,   602,   607,   614,   616
+     535,   537,   539,   551,   552,   557,   558,   567,   587,   589,
+     598,   603,   604,   609,   616,   618
 };
 #endif
 
@@ -2544,21 +2544,21 @@ yyreduce:
   case 94:
 
 /* Line 1456 of yacc.c  */
-#line 550 "parse-gram.y"
+#line 552 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 95:
 
 /* Line 1456 of yacc.c  */
-#line 555 "parse-gram.y"
+#line 557 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 97:
 
 /* Line 1456 of yacc.c  */
-#line 566 "parse-gram.y"
+#line 568 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2572,14 +2572,14 @@ yyreduce:
   case 98:
 
 /* Line 1456 of yacc.c  */
-#line 586 "parse-gram.y"
+#line 588 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 99:
 
 /* Line 1456 of yacc.c  */
-#line 588 "parse-gram.y"
+#line 590 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2590,14 +2590,14 @@ yyreduce:
   case 100:
 
 /* Line 1456 of yacc.c  */
-#line 596 "parse-gram.y"
+#line 598 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 103:
 
 /* Line 1456 of yacc.c  */
-#line 608 "parse-gram.y"
+#line 610 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2607,7 +2607,7 @@ yyreduce:
   case 105:
 
 /* Line 1456 of yacc.c  */
-#line 617 "parse-gram.y"
+#line 619 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2840,7 +2840,7 @@ yyreturn:
 
 
 /* Line 1676 of yacc.c  */
-#line 627 "parse-gram.y"
+#line 629 "parse-gram.y"
 
 
 
