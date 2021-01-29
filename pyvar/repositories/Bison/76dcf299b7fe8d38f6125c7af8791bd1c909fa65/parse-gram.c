@@ -45,8 +45,7 @@
 /* Using locations.  */
 #define YYLSP_NEEDED 1
 
-/* If NAME_PREFIX is specified substitute the variables and functions
-   names.  */
+/* Substitute the variable and function names.  */
 #define yyparse gram_parse
 #define yylex   gram_lex
 #define yyerror gram_error
@@ -252,8 +251,8 @@ typedef union YYSTYPE {
   assoc assoc;
   uniqstr uniqstr;
 } YYSTYPE;
-/* Line 191 of yacc.c.  */
-#line 257 "parse-gram.c"
+/* Line 190 of yacc.c.  */
+#line 256 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -276,8 +275,8 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 214 of yacc.c.  */
-#line 281 "parse-gram.c"
+/* Line 213 of yacc.c.  */
+#line 280 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -1156,8 +1155,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 851 of yacc.c.  */
-#line 1161 "parse-gram.c"
+/* Line 850 of yacc.c.  */
+#line 1160 "parse-gram.c"
   yyvsp[0] = yylval;
     yylsp[0] = yylloc;
 
@@ -1349,7 +1348,7 @@ yyreduce:
     {
         case 6:
 #line 189 "parse-gram.y"
-    { prologue_augment (yyvsp[0].chars, yylsp[0]); }
+    { prologue_augment ((yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 7:
@@ -1359,7 +1358,7 @@ yyreduce:
 
   case 8:
 #line 191 "parse-gram.y"
-    { muscle_insert (yyvsp[-1].chars, yyvsp[0].chars); }
+    { muscle_insert ((yyvsp[-1].chars), (yyvsp[0].chars)); }
     break;
 
   case 9:
@@ -1374,17 +1373,17 @@ yyreduce:
 
   case 11:
 #line 194 "parse-gram.y"
-    { expected_sr_conflicts = yyvsp[0].integer; }
+    { expected_sr_conflicts = (yyvsp[0].integer); }
     break;
 
   case 12:
 #line 195 "parse-gram.y"
-    { expected_rr_conflicts = yyvsp[0].integer; }
+    { expected_rr_conflicts = (yyvsp[0].integer); }
     break;
 
   case 13:
 #line 196 "parse-gram.y"
-    { spec_file_prefix = yyvsp[0].chars; }
+    { spec_file_prefix = (yyvsp[0].chars); }
     break;
 
   case 14:
@@ -1398,13 +1397,13 @@ yyreduce:
   case 15:
 #line 203 "parse-gram.y"
     {
-    muscle_code_grow ("initial_action", yyvsp[0].chars, yylsp[0]);
+    muscle_code_grow ("initial_action", (yyvsp[0].chars), (yylsp[0]));
   }
     break;
 
   case 16:
 #line 206 "parse-gram.y"
-    { add_param ("lex_param", yyvsp[0].chars, yylsp[0]); }
+    { add_param ("lex_param", (yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 17:
@@ -1414,7 +1413,7 @@ yyreduce:
 
   case 18:
 #line 208 "parse-gram.y"
-    { spec_name_prefix = yyvsp[0].chars; }
+    { spec_name_prefix = (yyvsp[0].chars); }
     break;
 
   case 19:
@@ -1429,12 +1428,12 @@ yyreduce:
 
   case 21:
 #line 211 "parse-gram.y"
-    { spec_outfile = yyvsp[0].chars; }
+    { spec_outfile = (yyvsp[0].chars); }
     break;
 
   case 22:
 #line 212 "parse-gram.y"
-    { add_param ("parse_param", yyvsp[0].chars, yylsp[0]); }
+    { add_param ("parse_param", (yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 23:
@@ -1444,7 +1443,7 @@ yyreduce:
 
   case 24:
 #line 214 "parse-gram.y"
-    { skeleton = yyvsp[0].chars; }
+    { skeleton = (yyvsp[0].chars); }
     break;
 
   case 25:
@@ -1465,7 +1464,7 @@ yyreduce:
   case 31:
 #line 225 "parse-gram.y"
     {
-      grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
+      grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
     break;
 
@@ -1473,8 +1472,8 @@ yyreduce:
 #line 229 "parse-gram.y"
     {
       typed = true;
-      MUSCLE_INSERT_INT ("stype_line", yylsp[0].start.line);
-      muscle_insert ("stype", yyvsp[0].chars);
+      MUSCLE_INSERT_INT ("stype_line", (yylsp[0]).start.line);
+      muscle_insert ("stype", (yyvsp[0].chars));
     }
     break;
 
@@ -1482,9 +1481,9 @@ yyreduce:
 #line 235 "parse-gram.y"
     {
       symbol_list *list;
-      for (list = yyvsp[0].list; list; list = list->next)
-	symbol_destructor_set (list->sym, yyvsp[-1].chars, yylsp[-1]);
-      symbol_list_free (yyvsp[0].list);
+      for (list = (yyvsp[0].list); list; list = list->next)
+	symbol_destructor_set (list->sym, (yyvsp[-1].chars), (yylsp[-1]));
+      symbol_list_free ((yyvsp[0].list));
     }
     break;
 
@@ -1492,9 +1491,9 @@ yyreduce:
 #line 242 "parse-gram.y"
     {
       symbol_list *list;
-      for (list = yyvsp[0].list; list; list = list->next)
-	symbol_printer_set (list->sym, yyvsp[-1].chars, list->location);
-      symbol_list_free (yyvsp[0].list);
+      for (list = (yyvsp[0].list); list; list = list->next)
+	symbol_printer_set (list->sym, (yyvsp[-1].chars), list->location);
+      symbol_list_free ((yyvsp[0].list));
     }
     break;
 
@@ -1542,9 +1541,9 @@ yyreduce:
 #line 270 "parse-gram.y"
     {
       symbol_list *list;
-      for (list = yyvsp[0].list; list; list = list->next)
-	symbol_type_set (list->sym, yyvsp[-1].uniqstr, yylsp[-1]);
-      symbol_list_free (yyvsp[0].list);
+      for (list = (yyvsp[0].list); list; list = list->next)
+	symbol_type_set (list->sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
+      symbol_list_free ((yyvsp[0].list));
     }
     break;
 
@@ -1553,29 +1552,29 @@ yyreduce:
     {
       symbol_list *list;
       ++current_prec;
-      for (list = yyvsp[0].list; list; list = list->next)
+      for (list = (yyvsp[0].list); list; list = list->next)
 	{
-	  symbol_type_set (list->sym, current_type, yylsp[-1]);
-	  symbol_precedence_set (list->sym, current_prec, yyvsp[-2].assoc, yylsp[-2]);
+	  symbol_type_set (list->sym, current_type, (yylsp[-1]));
+	  symbol_precedence_set (list->sym, current_prec, (yyvsp[-2].assoc), (yylsp[-2]));
 	}
-      symbol_list_free (yyvsp[0].list);
+      symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
     break;
 
   case 43:
 #line 294 "parse-gram.y"
-    { yyval.assoc = left_assoc; }
+    { (yyval.assoc) = left_assoc; }
     break;
 
   case 44:
 #line 295 "parse-gram.y"
-    { yyval.assoc = right_assoc; }
+    { (yyval.assoc) = right_assoc; }
     break;
 
   case 45:
 #line 296 "parse-gram.y"
-    { yyval.assoc = non_assoc; }
+    { (yyval.assoc) = non_assoc; }
     break;
 
   case 46:
@@ -1585,59 +1584,59 @@ yyreduce:
 
   case 47:
 #line 301 "parse-gram.y"
-    { current_type = yyvsp[0].uniqstr; }
+    { current_type = (yyvsp[0].uniqstr); }
     break;
 
   case 48:
 #line 307 "parse-gram.y"
-    { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
+    { (yyval.list) = symbol_list_new ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 49:
 #line 308 "parse-gram.y"
-    { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
+    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 50:
 #line 314 "parse-gram.y"
     {
-       current_type = yyvsp[0].uniqstr;
+       current_type = (yyvsp[0].uniqstr);
      }
     break;
 
   case 51:
 #line 318 "parse-gram.y"
     {
-       symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
-       symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
+       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]));
+       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
     break;
 
   case 52:
 #line 323 "parse-gram.y"
     {
-      symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
-      symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
-      symbol_user_token_number_set (yyvsp[-1].symbol, yyvsp[0].integer, yylsp[0]);
+      symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]));
+      symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
+      symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
     break;
 
   case 53:
 #line 329 "parse-gram.y"
     {
-      symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
-      symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
-      symbol_make_alias (yyvsp[-1].symbol, yyvsp[0].symbol, yyloc);
+      symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]));
+      symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
+      symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
     break;
 
   case 54:
 #line 335 "parse-gram.y"
     {
-      symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
-      symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
-      symbol_user_token_number_set (yyvsp[-2].symbol, yyvsp[-1].integer, yylsp[-1]);
-      symbol_make_alias (yyvsp[-2].symbol, yyvsp[0].symbol, yyloc);
+      symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]));
+      symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
+      symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
+      symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
     break;
 
@@ -1645,7 +1644,7 @@ yyreduce:
 #line 364 "parse-gram.y"
     {
       if (yacc_flag)
-	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
+	complain_at ((yyloc), _("POSIX forbids declarations in the grammar"));
     }
     break;
 
@@ -1658,17 +1657,17 @@ yyreduce:
 
   case 62:
 #line 375 "parse-gram.y"
-    { current_lhs = yyvsp[0].symbol; current_lhs_location = yylsp[0]; }
+    { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
     break;
 
   case 64:
 #line 379 "parse-gram.y"
-    { grammar_rule_end (yylsp[0]); }
+    { grammar_rule_end ((yylsp[0])); }
     break;
 
   case 65:
 #line 380 "parse-gram.y"
-    { grammar_rule_end (yylsp[0]); }
+    { grammar_rule_end ((yylsp[0])); }
     break;
 
   case 67:
@@ -1678,64 +1677,64 @@ yyreduce:
 
   case 68:
 #line 388 "parse-gram.y"
-    { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
+    { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 69:
 #line 390 "parse-gram.y"
-    { grammar_current_rule_action_append (yyvsp[0].chars, yylsp[0]); }
+    { grammar_current_rule_action_append ((yyvsp[0].chars), (yylsp[0])); }
     break;
 
   case 70:
 #line 392 "parse-gram.y"
-    { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
+    { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 71:
 #line 394 "parse-gram.y"
-    { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
+    { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
     break;
 
   case 72:
 #line 396 "parse-gram.y"
-    { grammar_current_rule_merge_set (yyvsp[0].uniqstr, yylsp[0]); }
+    { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
     break;
 
   case 73:
 #line 400 "parse-gram.y"
-    { yyval.symbol = yyvsp[0].symbol; }
+    { (yyval.symbol) = (yyvsp[0].symbol); }
     break;
 
   case 74:
 #line 401 "parse-gram.y"
-    { yyval.symbol = yyvsp[0].symbol; }
+    { (yyval.symbol) = (yyvsp[0].symbol); }
     break;
 
   case 75:
 #line 406 "parse-gram.y"
-    { yyval.chars = yyvsp[0].chars; }
+    { (yyval.chars) = (yyvsp[0].chars); }
     break;
 
   case 76:
 #line 412 "parse-gram.y"
     {
-      yyval.symbol = symbol_get (yyvsp[0].chars, yylsp[0]);
-      symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
+      (yyval.symbol) = symbol_get ((yyvsp[0].chars), (yylsp[0]));
+      symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]));
     }
     break;
 
   case 77:
 #line 421 "parse-gram.y"
     {
-      yyval.chars = yyvsp[0].chars + 1;
-      yyval.chars[strlen (yyval.chars) - 1] = '\0';
+      (yyval.chars) = (yyvsp[0].chars) + 1;
+      (yyval.chars)[strlen ((yyval.chars)) - 1] = '\0';
     }
     break;
 
   case 79:
 #line 430 "parse-gram.y"
     {
-      muscle_code_grow ("epilogue", yyvsp[0].chars, yylsp[0]);
+      muscle_code_grow ("epilogue", (yyvsp[0].chars), (yylsp[0]));
       scanner_last_string_free ();
     }
     break;
@@ -1743,8 +1742,8 @@ yyreduce:
 
     }
 
-/* Line 1046 of yacc.c.  */
-#line 1748 "parse-gram.c"
+/* Line 1045 of yacc.c.  */
+#line 1747 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
