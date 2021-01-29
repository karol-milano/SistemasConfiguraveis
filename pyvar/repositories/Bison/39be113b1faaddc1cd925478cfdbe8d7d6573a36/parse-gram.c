@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.6.2.71-273f.  */
+/* A Bison parser, made by GNU Bison 3.6.3.74-5ca2.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -49,7 +49,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.6.2.71-273f"
+#define YYBISON_VERSION "3.6.3.74-5ca2"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -2055,7 +2055,7 @@ yyreduce:
     int yychar_backup = yychar;
     switch (yyn)
       {
-  case 6:
+  case 6:  /* prologue_declaration: "%{...%}"  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((yyvsp[0].PROLOGUE), (yylsp[0]), true), (yylsp[0]));
@@ -2063,131 +2063,131 @@ yyreduce:
     }
     break;
 
-  case 7:
+  case 7:  /* prologue_declaration: "%<flag>"  */
     {
       muscle_percent_define_ensure ((yyvsp[0].PERCENT_FLAG), (yylsp[0]), true);
     }
     break;
 
-  case 8:
+  case 8:  /* prologue_declaration: "%define" variable value  */
     {
       muscle_percent_define_insert ((yyvsp[-1].variable), (yyloc), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
     break;
 
-  case 9:
+  case 9:  /* prologue_declaration: "%defines"  */
                                    { defines_flag = true; }
     break;
 
-  case 10:
+  case 10:  /* prologue_declaration: "%defines" "string"  */
     {
       defines_flag = true;
       spec_header_file = xstrdup ((yyvsp[0].STRING));
     }
     break;
 
-  case 11:
+  case 11:  /* prologue_declaration: "%error-verbose"  */
                                    { handle_error_verbose (&(yyloc), (yyvsp[0].PERCENT_ERROR_VERBOSE)); }
     break;
 
-  case 12:
+  case 12:  /* prologue_declaration: "%expect" "integer literal"  */
                                    { expected_sr_conflicts = (yyvsp[0].INT); }
     break;
 
-  case 13:
+  case 13:  /* prologue_declaration: "%expect-rr" "integer literal"  */
                                    { expected_rr_conflicts = (yyvsp[0].INT); }
     break;
 
-  case 14:
+  case 14:  /* prologue_declaration: "%file-prefix" "string"  */
                                    { handle_file_prefix (&(yyloc), &(yylsp[-1]), (yyvsp[-1].PERCENT_FILE_PREFIX), (yyvsp[0].STRING)); }
     break;
 
-  case 15:
+  case 15:  /* prologue_declaration: "%glr-parser"  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
     break;
 
-  case 16:
+  case 16:  /* prologue_declaration: "%initial-action" "{...}"  */
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].BRACED_CODE), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
     break;
 
-  case 17:
+  case 17:  /* prologue_declaration: "%language" "string"  */
                                 { language_argmatch ((yyvsp[0].STRING), grammar_prio, (yylsp[-1])); }
     break;
 
-  case 18:
+  case 18:  /* prologue_declaration: "%name-prefix" "string"  */
                                 { handle_name_prefix (&(yyloc), (yyvsp[-1].PERCENT_NAME_PREFIX), (yyvsp[0].STRING)); }
     break;
 
-  case 19:
+  case 19:  /* prologue_declaration: "%no-lines"  */
                                 { no_lines_flag = true; }
     break;
 
-  case 20:
+  case 20:  /* prologue_declaration: "%nondeterministic-parser"  */
                                 { nondeterministic_parser = true; }
     break;
 
-  case 21:
+  case 21:  /* prologue_declaration: "%output" "string"  */
                                 { spec_outfile = (yyvsp[0].STRING); }
     break;
 
-  case 22:
+  case 22:  /* $@1: %empty  */
            { current_param = (yyvsp[0].PERCENT_PARAM); }
     break;
 
-  case 23:
+  case 23:  /* prologue_declaration: "%param" $@1 params  */
                                           { current_param = param_none; }
     break;
 
-  case 24:
+  case 24:  /* prologue_declaration: "%pure-parser"  */
                                 { handle_pure_parser (&(yyloc), (yyvsp[0].PERCENT_PURE_PARSER)); }
     break;
 
-  case 25:
+  case 25:  /* prologue_declaration: "%require" "string"  */
                                 { handle_require (&(yylsp[0]), (yyvsp[0].STRING)); }
     break;
 
-  case 26:
+  case 26:  /* prologue_declaration: "%skeleton" "string"  */
                                 { handle_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
     break;
 
-  case 27:
+  case 27:  /* prologue_declaration: "%token-table"  */
                                 { token_table_flag = true; }
     break;
 
-  case 28:
+  case 28:  /* prologue_declaration: "%verbose"  */
                                 { report_flag |= report_states; }
     break;
 
-  case 29:
+  case 29:  /* prologue_declaration: "%yacc"  */
                                 { handle_yacc (&(yyloc)); }
     break;
 
-  case 30:
+  case 30:  /* prologue_declaration: error ";"  */
                                 { current_class = unknown_sym; yyerrok; }
     break;
 
-  case 32:
+  case 32:  /* params: params "{...}"  */
                    { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
     break;
 
-  case 33:
+  case 33:  /* params: "{...}"  */
                    { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
     break;
 
-  case 35:
+  case 35:  /* grammar_declaration: "%start" symbol  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
     break;
 
-  case 36:
+  case 36:  /* grammar_declaration: code_props_type "{...}" generic_symlist  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].BRACED_CODE), (yylsp[-1]));
@@ -2200,19 +2200,19 @@ yyreduce:
     }
     break;
 
-  case 37:
+  case 37:  /* grammar_declaration: "%default-prec"  */
     {
       default_prec = true;
     }
     break;
 
-  case 38:
+  case 38:  /* grammar_declaration: "%no-default-prec"  */
     {
       default_prec = false;
     }
     break;
 
-  case 39:
+  case 39:  /* grammar_declaration: "%code" "{...}"  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2222,32 +2222,32 @@ yyreduce:
     }
     break;
 
-  case 40:
+  case 40:  /* grammar_declaration: "%code" "identifier" "{...}"  */
     {
       muscle_percent_code_grow ((yyvsp[-1].ID), (yylsp[-1]), translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
     break;
 
-  case 41:
+  case 41:  /* code_props_type: "%destructor"  */
                  { (yyval.code_props_type) = destructor; }
     break;
 
-  case 42:
+  case 42:  /* code_props_type: "%printer"  */
                  { (yyval.code_props_type) = printer; }
     break;
 
-  case 43:
+  case 43:  /* union_name: %empty  */
          {}
     break;
 
-  case 44:
+  case 44:  /* union_name: "identifier"  */
          { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].ID),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
     break;
 
-  case 45:
+  case 45:  /* grammar_declaration: "%union" union_name "{...}"  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
@@ -2255,35 +2255,35 @@ yyreduce:
     }
     break;
 
-  case 46:
+  case 46:  /* $@2: %empty  */
            { current_class = nterm_sym; }
     break;
 
-  case 47:
+  case 47:  /* symbol_declaration: "%nterm" $@2 nterm_decls  */
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].nterm_decls));
     }
     break;
 
-  case 48:
+  case 48:  /* $@3: %empty  */
            { current_class = token_sym; }
     break;
 
-  case 49:
+  case 49:  /* symbol_declaration: "%token" $@3 token_decls  */
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].token_decls));
     }
     break;
 
-  case 50:
+  case 50:  /* symbol_declaration: "%type" symbol_decls  */
     {
       symbol_list_free ((yyvsp[0].symbol_decls));
     }
     break;
 
-  case 51:
+  case 51:  /* symbol_declaration: precedence_declarator token_decls_for_prec  */
     {
       ++current_prec;
       for (symbol_list *list = (yyvsp[0].token_decls_for_prec); list; list = list->next)
@@ -2292,77 +2292,77 @@ yyreduce:
     }
     break;
 
-  case 52:
+  case 52:  /* precedence_declarator: "%left"  */
                 { (yyval.precedence_declarator) = left_assoc; }
     break;
 
-  case 53:
+  case 53:  /* precedence_declarator: "%right"  */
                 { (yyval.precedence_declarator) = right_assoc; }
     break;
 
-  case 54:
+  case 54:  /* precedence_declarator: "%nonassoc"  */
                 { (yyval.precedence_declarator) = non_assoc; }
     break;
 
-  case 55:
+  case 55:  /* precedence_declarator: "%precedence"  */
                 { (yyval.precedence_declarator) = precedence_assoc; }
     break;
 
-  case 56:
+  case 56:  /* tag.opt: %empty  */
          { (yyval.yykind_74) = NULL; }
     break;
 
-  case 57:
+  case 57:  /* tag.opt: "<tag>"  */
          { (yyval.yykind_74) = (yyvsp[0].TAG); }
     break;
 
-  case 59:
+  case 59:  /* generic_symlist: generic_symlist generic_symlist_item  */
                                          { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
     break;
 
-  case 60:
+  case 60:  /* generic_symlist_item: symbol  */
             { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
-  case 61:
+  case 61:  /* generic_symlist_item: tag  */
             { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
     break;
 
-  case 63:
+  case 63:  /* tag: "<*>"  */
         { (yyval.tag) = uniqstr_new ("*"); }
     break;
 
-  case 64:
+  case 64:  /* tag: "<>"  */
         { (yyval.tag) = uniqstr_new (""); }
     break;
 
-  case 66:
+  case 66:  /* token_decls: token_decl.1  */
     {
       (yyval.token_decls) = (yyvsp[0].yykind_80);
     }
     break;
 
-  case 67:
+  case 67:  /* token_decls: "<tag>" token_decl.1  */
     {
       (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yykind_80), (yyvsp[-1].TAG), (yylsp[-1]));
     }
     break;
 
-  case 68:
+  case 68:  /* token_decls: token_decls "<tag>" token_decl.1  */
     {
       (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yykind_80), (yyvsp[-1].TAG), (yylsp[-1])));
     }
     break;
 
-  case 69:
+  case 69:  /* token_decl.1: token_decl  */
                             { (yyval.yykind_80) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
     break;
 
-  case 70:
+  case 70:  /* token_decl.1: token_decl.1 token_decl  */
                             { (yyval.yykind_80) = symbol_list_append ((yyvsp[-1].yykind_80), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
     break;
 
-  case 71:
+  case 71:  /* token_decl: id int.opt alias  */
     {
       (yyval.token_decl) = (yyvsp[-2].id);
       symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
@@ -2373,19 +2373,19 @@ yyreduce:
     }
     break;
 
-  case 72:
+  case 72:  /* int.opt: %empty  */
           { (yyval.yykind_82) = -1; }
     break;
 
-  case 74:
+  case 74:  /* alias: %empty  */
                  { (yyval.alias) = NULL; }
     break;
 
-  case 75:
+  case 75:  /* alias: string_as_id  */
                  { (yyval.alias) = (yyvsp[0].string_as_id); }
     break;
 
-  case 76:
+  case 76:  /* alias: "translatable string"  */
     {
       (yyval.alias) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].TSTRING)), (yylsp[0]));
       symbol_class_set ((yyval.alias), token_sym, (yylsp[0]), false);
@@ -2393,33 +2393,33 @@ yyreduce:
     }
     break;
 
-  case 77:
+  case 77:  /* token_decls_for_prec: token_decl_for_prec.1  */
     {
       (yyval.token_decls_for_prec) = (yyvsp[0].yykind_85);
     }
     break;
 
-  case 78:
+  case 78:  /* token_decls_for_prec: "<tag>" token_decl_for_prec.1  */
     {
       (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yykind_85), (yyvsp[-1].TAG), (yylsp[-1]));
     }
     break;
 
-  case 79:
+  case 79:  /* token_decls_for_prec: token_decls_for_prec "<tag>" token_decl_for_prec.1  */
     {
       (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yykind_85), (yyvsp[-1].TAG), (yylsp[-1])));
     }
     break;
 
-  case 80:
+  case 80:  /* token_decl_for_prec.1: token_decl_for_prec  */
     { (yyval.yykind_85) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
     break;
 
-  case 81:
+  case 81:  /* token_decl_for_prec.1: token_decl_for_prec.1 token_decl_for_prec  */
     { (yyval.yykind_85) = symbol_list_append ((yyvsp[-1].yykind_85), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
     break;
 
-  case 82:
+  case 82:  /* token_decl_for_prec: id int.opt  */
     {
       (yyval.token_decl_for_prec) = (yyvsp[-1].id);
       symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
@@ -2428,133 +2428,133 @@ yyreduce:
     }
     break;
 
-  case 84:
+  case 84:  /* symbol_decls: symbol_decl.1  */
     {
       (yyval.symbol_decls) = (yyvsp[0].yykind_88);
     }
     break;
 
-  case 85:
+  case 85:  /* symbol_decls: "<tag>" symbol_decl.1  */
     {
       (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yykind_88), (yyvsp[-1].TAG), (yylsp[-1]));
     }
     break;
 
-  case 86:
+  case 86:  /* symbol_decls: symbol_decls "<tag>" symbol_decl.1  */
     {
       (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yykind_88), (yyvsp[-1].TAG), (yylsp[-1])));
     }
     break;
 
-  case 87:
+  case 87:  /* symbol_decl.1: symbol  */
     {
       symbol_class_set ((yyvsp[0].symbol), pct_type_sym, (yylsp[0]), false);
       (yyval.yykind_88) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]));
     }
     break;
 
-  case 88:
+  case 88:  /* symbol_decl.1: symbol_decl.1 symbol  */
     {
       symbol_class_set ((yyvsp[0].symbol), pct_type_sym, (yylsp[0]), false);
       (yyval.yykind_88) = symbol_list_append ((yyvsp[-1].yykind_88), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])));
     }
     break;
 
-  case 93:
+  case 93:  /* rules_or_grammar_declaration: error ";"  */
     {
       yyerrok;
     }
     break;
 
-  case 94:
+  case 94:  /* $@4: %empty  */
                          { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yykind_95)); }
     break;
 
-  case 95:
+  case 95:  /* rules: id_colon named_ref.opt $@4 ":" rhses.1  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-4]), 0);
     }
     break;
 
-  case 96:
+  case 96:  /* rhses.1: rhs  */
                      { grammar_current_rule_end ((yylsp[0])); }
     break;
 
-  case 97:
+  case 97:  /* rhses.1: rhses.1 "|" rhs  */
                      { grammar_current_rule_end ((yylsp[0])); }
     break;
 
-  case 99:
+  case 99:  /* rhs: %empty  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_loc,
                                   current_lhs_named_ref); }
     break;
 
-  case 100:
+  case 100:  /* rhs: rhs symbol named_ref.opt  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yykind_95)); }
     break;
 
-  case 101:
+  case 101:  /* rhs: rhs tag.opt "{...}" named_ref.opt  */
     { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yykind_95), (yyvsp[-2].yykind_74)); }
     break;
 
-  case 102:
+  case 102:  /* rhs: rhs "%?{...}"  */
     { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
     break;
 
-  case 103:
+  case 103:  /* rhs: rhs "%empty"  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
     break;
 
-  case 104:
+  case 104:  /* rhs: rhs "%prec" symbol  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
-  case 105:
+  case 105:  /* rhs: rhs "%dprec" "integer literal"  */
     { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
     break;
 
-  case 106:
+  case 106:  /* rhs: rhs "%merge" "<tag>"  */
     { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
     break;
 
-  case 107:
+  case 107:  /* rhs: rhs "%expect" "integer literal"  */
     { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
     break;
 
-  case 108:
+  case 108:  /* rhs: rhs "%expect-rr" "integer literal"  */
     { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
     break;
 
-  case 109:
+  case 109:  /* named_ref.opt: %empty  */
                  { (yyval.yykind_95) = NULL; }
     break;
 
-  case 110:
+  case 110:  /* named_ref.opt: "[identifier]"  */
                  { (yyval.yykind_95) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
     break;
 
-  case 112:
+  case 112:  /* value: %empty  */
           { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
     break;
 
-  case 113:
+  case 113:  /* value: "identifier"  */
           { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
     break;
 
-  case 114:
+  case 114:  /* value: "string"  */
           { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
     break;
 
-  case 115:
+  case 115:  /* value: "{...}"  */
           { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
     break;
 
-  case 116:
+  case 116:  /* id: "identifier"  */
     { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
     break;
 
-  case 117:
+  case 117:  /* id: "character literal"  */
     {
       const char *var = "api.token.raw";
       if (current_class == nterm_sym)
@@ -2577,18 +2577,18 @@ yyreduce:
     }
     break;
 
-  case 118:
+  case 118:  /* id_colon: "identifier:"  */
            { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
     break;
 
-  case 121:
+  case 121:  /* string_as_id: "string"  */
     {
       (yyval.string_as_id) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].STRING)), (yylsp[0]));
       symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
     break;
 
-  case 123:
+  case 123:  /* epilogue.opt: "%%" "epilogue"  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].EPILOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
