@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.156-d497.  */
+/* A Bison parser, made by GNU Bison 2.4.170-dd704.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.156-d497"
+#define YYBISON_VERSION "2.4.170-dd704"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1903,11 +1903,11 @@ yyreduce:
 #line 219 "parse-gram.y"
     {
       code_props plain_code;
-      code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
+      code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
       code_props_translate_code (&plain_code);
       gram_scanner_last_string_free ();
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
-                        plain_code.code, (yylsp[(1) - (1)]));
+                        plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
 
@@ -1930,7 +1930,7 @@ yyreduce:
 /* Line 1459 of yacc.c  */
 #line 230 "parse-gram.y"
     {
-      muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars));
+      muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars));
     }
 
 /* Line 1459 of yacc.c  */
@@ -1953,7 +1953,7 @@ yyreduce:
 #line 235 "parse-gram.y"
     {
       defines_flag = true;
-      spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
+      spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 
 /* Line 1459 of yacc.c  */
@@ -1974,7 +1974,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 240 "parse-gram.y"
-    { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
+    { expected_sr_conflicts = (yyvsp[0].integer); }
 
 /* Line 1459 of yacc.c  */
 #line 1981 "../../src/parse-gram.c"
@@ -1984,7 +1984,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 241 "parse-gram.y"
-    { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
+    { expected_rr_conflicts = (yyvsp[0].integer); }
 
 /* Line 1459 of yacc.c  */
 #line 1991 "../../src/parse-gram.c"
@@ -1994,7 +1994,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 242 "parse-gram.y"
-    { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
+    { spec_file_prefix = (yyvsp[0].chars); }
 
 /* Line 1459 of yacc.c  */
 #line 2001 "../../src/parse-gram.c"
@@ -2004,7 +2004,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 243 "parse-gram.y"
-    { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
+    { spec_file_prefix = (yyvsp[0].chars); }
 
 /* Line 1459 of yacc.c  */
 #line 2011 "../../src/parse-gram.c"
@@ -2029,10 +2029,10 @@ yyreduce:
 #line 250 "parse-gram.y"
     {
       code_props action;
-      code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
+      code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
       code_props_translate_code (&action);
       gram_scanner_last_string_free ();
-      muscle_code_grow ("initial_action", action.code, (yylsp[(2) - (2)]));
+      muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
 
@@ -2044,7 +2044,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 258 "parse-gram.y"
-    { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
+    { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 
 /* Line 1459 of yacc.c  */
 #line 2051 "../../src/parse-gram.c"
@@ -2054,7 +2054,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 259 "parse-gram.y"
-    { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
+    { add_param ("lex_param", (yyvsp[0].code), (yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2061 "../../src/parse-gram.c"
@@ -2074,7 +2074,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 261 "parse-gram.y"
-    { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
+    { spec_name_prefix = (yyvsp[0].chars); }
 
 /* Line 1459 of yacc.c  */
 #line 2081 "../../src/parse-gram.c"
@@ -2084,7 +2084,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 262 "parse-gram.y"
-    { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
+    { spec_name_prefix = (yyvsp[0].chars); }
 
 /* Line 1459 of yacc.c  */
 #line 2091 "../../src/parse-gram.c"
@@ -2114,7 +2114,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 265 "parse-gram.y"
-    { spec_outfile = (yyvsp[(2) - (2)].chars); }
+    { spec_outfile = (yyvsp[0].chars); }
 
 /* Line 1459 of yacc.c  */
 #line 2121 "../../src/parse-gram.c"
@@ -2124,7 +2124,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 266 "parse-gram.y"
-    { spec_outfile = (yyvsp[(3) - (3)].chars); }
+    { spec_outfile = (yyvsp[0].chars); }
 
 /* Line 1459 of yacc.c  */
 #line 2131 "../../src/parse-gram.c"
@@ -2134,7 +2134,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 267 "parse-gram.y"
-    { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
+    { add_param ("parse_param", (yyvsp[0].code), (yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2141 "../../src/parse-gram.c"
@@ -2149,12 +2149,12 @@ yyreduce:
          `%define api.pure' in a backward-compatible manner here.  First, don't
          complain if %pure-parser is specified multiple times.  */
       if (!muscle_find_const ("percent_define(api.pure)"))
-        muscle_percent_define_insert ("api.pure", (yylsp[(1) - (1)]), "");
+        muscle_percent_define_insert ("api.pure", (yylsp[0]), "");
       /* In all cases, use api.pure now so that the backend doesn't complain if
          the skeleton ignores api.pure, but do warn now if there's a previous
          conflicting definition from an actual %define.  */
       if (!muscle_percent_define_flag_if ("api.pure"))
-        muscle_percent_define_insert ("api.pure", (yylsp[(1) - (1)]), "");
+        muscle_percent_define_insert ("api.pure", (yylsp[0]), "");
     }
 
 /* Line 1459 of yacc.c  */
@@ -2165,7 +2165,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 281 "parse-gram.y"
-    { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
+    { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 
 /* Line 1459 of yacc.c  */
 #line 2172 "../../src/parse-gram.c"
@@ -2176,7 +2176,7 @@ yyreduce:
 /* Line 1459 of yacc.c  */
 #line 283 "parse-gram.y"
     {
-      char const *skeleton_user = (yyvsp[(2) - (2)].chars);
+      char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
         {
           size_t dir_length = strlen (current_file);
@@ -2196,7 +2196,7 @@ yyreduce:
           skeleton_user = uniqstr_new (skeleton_build);
           free (skeleton_build);
         }
-      skeleton_arg (skeleton_user, grammar_prio, (yylsp[(1) - (2)]));
+      skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 
 /* Line 1459 of yacc.c  */
@@ -2238,7 +2238,7 @@ yyreduce:
 /* Line 1459 of yacc.c  */
 #line 316 "parse-gram.y"
     {
-      grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
+      grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 
 /* Line 1459 of yacc.c  */
@@ -2251,9 +2251,9 @@ yyreduce:
 #line 320 "parse-gram.y"
     {
       symbol_list *list;
-      for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
-	symbol_list_destructor_set (list, (yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
-      symbol_list_free ((yyvsp[(3) - (3)].list));
+      for (list = (yyvsp[0].list); list; list = list->next)
+	symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
+      symbol_list_free ((yyvsp[0].list));
     }
 
 /* Line 1459 of yacc.c  */
@@ -2266,9 +2266,9 @@ yyreduce:
 #line 327 "parse-gram.y"
     {
       symbol_list *list;
-      for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
-	symbol_list_printer_set (list, (yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
-      symbol_list_free ((yyvsp[(3) - (3)].list));
+      for (list = (yyvsp[0].list); list; list = list->next)
+	symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
+      symbol_list_free ((yyvsp[0].list));
     }
 
 /* Line 1459 of yacc.c  */
@@ -2306,7 +2306,7 @@ yyreduce:
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
-      muscle_code_grow ("percent_code()", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
+      muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 
@@ -2319,7 +2319,7 @@ yyreduce:
 /* Line 1459 of yacc.c  */
 #line 349 "parse-gram.y"
     {
-      muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
+      muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 
@@ -2341,7 +2341,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 364 "parse-gram.y"
-    { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+    { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2348 "../../src/parse-gram.c"
@@ -2353,7 +2353,7 @@ yyreduce:
 #line 369 "parse-gram.y"
     {
       union_seen = true;
-      muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
+      muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 
@@ -2414,9 +2414,9 @@ yyreduce:
     {
       symbol_list *list;
       tag_seen = true;
-      for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
-	symbol_type_set (list->content.sym, (yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]));
-      symbol_list_free ((yyvsp[(3) - (3)].list));
+      for (list = (yyvsp[0].list); list; list = list->next)
+	symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
+      symbol_list_free ((yyvsp[0].list));
     }
 
 /* Line 1459 of yacc.c  */
@@ -2430,12 +2430,12 @@ yyreduce:
     {
       symbol_list *list;
       ++current_prec;
-      for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
+      for (list = (yyvsp[0].list); list; list = list->next)
 	{
-	  symbol_type_set (list->content.sym, current_type, (yylsp[(2) - (3)]));
-	  symbol_precedence_set (list->content.sym, current_prec, (yyvsp[(1) - (3)].assoc), (yylsp[(1) - (3)]));
+	  symbol_type_set (list->content.sym, current_type, (yylsp[-1]));
+	  symbol_precedence_set (list->content.sym, current_prec, (yyvsp[-2].assoc), (yylsp[-2]));
 	}
-      symbol_list_free ((yyvsp[(3) - (3)].list));
+      symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
 
@@ -2497,7 +2497,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 424 "parse-gram.y"
-    { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
+    { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 
 /* Line 1459 of yacc.c  */
 #line 2504 "../../src/parse-gram.c"
@@ -2507,7 +2507,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 430 "parse-gram.y"
-    { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
+    { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2514 "../../src/parse-gram.c"
@@ -2517,7 +2517,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 432 "parse-gram.y"
-    { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
+    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 
 /* Line 1459 of yacc.c  */
 #line 2524 "../../src/parse-gram.c"
@@ -2527,7 +2527,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 436 "parse-gram.y"
-    { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
+    { (yyval.symbol) = (yyvsp[0].symbol); }
 
 /* Line 1459 of yacc.c  */
 #line 2534 "../../src/parse-gram.c"
@@ -2537,7 +2537,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 437 "parse-gram.y"
-    { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
+    { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2544 "../../src/parse-gram.c"
@@ -2547,7 +2547,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 443 "parse-gram.y"
-    { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
+    { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2554 "../../src/parse-gram.c"
@@ -2557,7 +2557,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 445 "parse-gram.y"
-    { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
+    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 
 /* Line 1459 of yacc.c  */
 #line 2564 "../../src/parse-gram.c"
@@ -2567,7 +2567,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 449 "parse-gram.y"
-    { (yyval.list) = (yyvsp[(1) - (1)].list); }
+    { (yyval.list) = (yyvsp[0].list); }
 
 /* Line 1459 of yacc.c  */
 #line 2574 "../../src/parse-gram.c"
@@ -2577,7 +2577,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 450 "parse-gram.y"
-    { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
+    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 
 /* Line 1459 of yacc.c  */
 #line 2584 "../../src/parse-gram.c"
@@ -2587,7 +2587,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 454 "parse-gram.y"
-    { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
+    { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2594 "../../src/parse-gram.c"
@@ -2597,7 +2597,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 455 "parse-gram.y"
-    { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+    { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2604 "../../src/parse-gram.c"
@@ -2607,7 +2607,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 456 "parse-gram.y"
-    { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
+    { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2614 "../../src/parse-gram.c"
@@ -2617,7 +2617,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 457 "parse-gram.y"
-    { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
+    { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2624 "../../src/parse-gram.c"
@@ -2628,7 +2628,7 @@ yyreduce:
 /* Line 1459 of yacc.c  */
 #line 463 "parse-gram.y"
     {
-       current_type = (yyvsp[(1) - (1)].uniqstr);
+       current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
 
@@ -2641,8 +2641,8 @@ yyreduce:
 /* Line 1459 of yacc.c  */
 #line 468 "parse-gram.y"
     {
-       symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
-       symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
+       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
+       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 
 /* Line 1459 of yacc.c  */
@@ -2654,9 +2654,9 @@ yyreduce:
 /* Line 1459 of yacc.c  */
 #line 473 "parse-gram.y"
     {
-      symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
-      symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
-      symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)]));
+      symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
+      symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
+      symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 
 /* Line 1459 of yacc.c  */
@@ -2668,9 +2668,9 @@ yyreduce:
 /* Line 1459 of yacc.c  */
 #line 479 "parse-gram.y"
     {
-      symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
-      symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
-      symbol_make_alias ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].symbol), (yyloc));
+      symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
+      symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
+      symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 
 /* Line 1459 of yacc.c  */
@@ -2682,10 +2682,10 @@ yyreduce:
 /* Line 1459 of yacc.c  */
 #line 485 "parse-gram.y"
     {
-      symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
-      symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
-      symbol_user_token_number_set ((yyvsp[(1) - (3)].symbol), (yyvsp[(2) - (3)].integer), (yylsp[(2) - (3)]));
-      symbol_make_alias ((yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].symbol), (yyloc));
+      symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
+      symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
+      symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
+      symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 
 /* Line 1459 of yacc.c  */
@@ -2708,7 +2708,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 521 "parse-gram.y"
-    { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
+    { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
 
 /* Line 1459 of yacc.c  */
 #line 2715 "../../src/parse-gram.c"
@@ -2718,7 +2718,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 525 "parse-gram.y"
-    { grammar_current_rule_end ((yylsp[(1) - (1)])); }
+    { grammar_current_rule_end ((yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2725 "../../src/parse-gram.c"
@@ -2728,7 +2728,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 526 "parse-gram.y"
-    { grammar_current_rule_end ((yylsp[(3) - (3)])); }
+    { grammar_current_rule_end ((yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2735 "../../src/parse-gram.c"
@@ -2748,7 +2748,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 534 "parse-gram.y"
-    { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
+    { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2755 "../../src/parse-gram.c"
@@ -2758,7 +2758,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 536 "parse-gram.y"
-    { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
+    { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2765 "../../src/parse-gram.c"
@@ -2768,7 +2768,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 538 "parse-gram.y"
-    { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
+    { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2775 "../../src/parse-gram.c"
@@ -2778,7 +2778,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 540 "parse-gram.y"
-    { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
+    { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2785 "../../src/parse-gram.c"
@@ -2788,7 +2788,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 542 "parse-gram.y"
-    { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
+    { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2795 "../../src/parse-gram.c"
@@ -2798,7 +2798,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 552 "parse-gram.y"
-    { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
+    { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 
 /* Line 1459 of yacc.c  */
 #line 2805 "../../src/parse-gram.c"
@@ -2822,8 +2822,8 @@ yyreduce:
 #line 571 "parse-gram.y"
     {
       code_props plain_code;
-      (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
-      code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].code)+1, (yylsp[(1) - (1)]));
+      (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
+      code_props_plain_init (&plain_code, (yyvsp[0].code)+1, (yylsp[0]));
       code_props_translate_code (&plain_code);
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
@@ -2837,7 +2837,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 591 "parse-gram.y"
-    { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+    { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2844 "../../src/parse-gram.c"
@@ -2848,9 +2848,9 @@ yyreduce:
 /* Line 1459 of yacc.c  */
 #line 593 "parse-gram.y"
     {
-      (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
-      symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
-      symbol_user_token_number_set ((yyval.symbol), (yyvsp[(1) - (1)].character), (yylsp[(1) - (1)]));
+      (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
+      symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
+      symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 
 /* Line 1459 of yacc.c  */
@@ -2861,7 +2861,7 @@ yyreduce:
 
 /* Line 1459 of yacc.c  */
 #line 601 "parse-gram.y"
-    { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+    { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 
 /* Line 1459 of yacc.c  */
 #line 2868 "../../src/parse-gram.c"
@@ -2872,8 +2872,8 @@ yyreduce:
 /* Line 1459 of yacc.c  */
 #line 613 "parse-gram.y"
     {
-      (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
-      symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
+      (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
+      symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 
 /* Line 1459 of yacc.c  */
@@ -2886,10 +2886,10 @@ yyreduce:
 #line 622 "parse-gram.y"
     {
       code_props plain_code;
-      code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
+      code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
       code_props_translate_code (&plain_code);
       gram_scanner_last_string_free ();
-      muscle_code_grow ("epilogue", plain_code.code, (yylsp[(2) - (2)]));
+      muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
 
