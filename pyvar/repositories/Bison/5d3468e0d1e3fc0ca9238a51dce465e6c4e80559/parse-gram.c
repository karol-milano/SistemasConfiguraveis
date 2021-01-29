@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.4.  */
+/* A Bison parser, made by GNU Bison 3.4.1.45-9bde-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4"
+#define YYBISON_VERSION "3.4.1.45-9bde-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -889,75 +889,75 @@ tron (yyo);
   switch (yytype)
     {
     case 3: /* "string"  */
-      { fputs (((*yyvaluep).STRING), yyo); }
+         { fputs (((*yyvaluep).STRING), yyo); }
         break;
 
     case 20: /* "%error-verbose"  */
-      { fputs (((*yyvaluep).PERCENT_ERROR_VERBOSE), yyo); }
+         { fputs (((*yyvaluep).PERCENT_ERROR_VERBOSE), yyo); }
         break;
 
     case 23: /* "%<flag>"  */
-      { fprintf (yyo, "%%%s", ((*yyvaluep).PERCENT_FLAG)); }
+         { fprintf (yyo, "%%%s", ((*yyvaluep).PERCENT_FLAG)); }
         break;
 
     case 24: /* "%file-prefix"  */
-      { fputs (((*yyvaluep).PERCENT_FILE_PREFIX), yyo); }
+         { fputs (((*yyvaluep).PERCENT_FILE_PREFIX), yyo); }
         break;
 
     case 28: /* "%name-prefix"  */
-      { fputs (((*yyvaluep).PERCENT_NAME_PREFIX), yyo); }
+         { fputs (((*yyvaluep).PERCENT_NAME_PREFIX), yyo); }
         break;
 
     case 33: /* "%pure-parser"  */
-      { fputs (((*yyvaluep).PERCENT_PURE_PARSER), yyo); }
+         { fputs (((*yyvaluep).PERCENT_PURE_PARSER), yyo); }
         break;
 
     case 39: /* "%yacc"  */
-      { fputs (((*yyvaluep).PERCENT_YACC), yyo); }
+         { fputs (((*yyvaluep).PERCENT_YACC), yyo); }
         break;
 
     case 40: /* "{...}"  */
-      { fputs (((*yyvaluep).BRACED_CODE), yyo); }
+         { fputs (((*yyvaluep).BRACED_CODE), yyo); }
         break;
 
     case 41: /* "%?{...}"  */
-      { fputs (((*yyvaluep).BRACED_PREDICATE), yyo); }
+         { fputs (((*yyvaluep).BRACED_PREDICATE), yyo); }
         break;
 
     case 42: /* "[identifier]"  */
-      { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
+         { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
         break;
 
     case 43: /* "char"  */
-      { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
+         { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
         break;
 
     case 45: /* "epilogue"  */
-      { fputs (((*yyvaluep).EPILOGUE), yyo); }
+         { fputs (((*yyvaluep).EPILOGUE), yyo); }
         break;
 
     case 47: /* "identifier"  */
-      { fputs (((*yyvaluep).ID), yyo); }
+         { fputs (((*yyvaluep).ID), yyo); }
         break;
 
     case 48: /* "identifier:"  */
-      { fprintf (yyo, "%s:", ((*yyvaluep).ID_COLON)); }
+         { fprintf (yyo, "%s:", ((*yyvaluep).ID_COLON)); }
         break;
 
     case 51: /* "%{...%}"  */
-      { fputs (((*yyvaluep).PROLOGUE), yyo); }
+         { fputs (((*yyvaluep).PROLOGUE), yyo); }
         break;
 
     case 53: /* "<tag>"  */
-      { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
+         { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
         break;
 
     case 56: /* "integer"  */
-      { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
+         { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
         break;
 
     case 57: /* "%param"  */
-      {
+{
   switch (((*yyvaluep).PERCENT_PARAM))
     {
 #define CASE(In, Out)                                           \
@@ -972,71 +972,71 @@ tron (yyo);
         break;
 
     case 67: /* code_props_type  */
-      { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
+         { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
         break;
 
     case 73: /* tag.opt  */
-      { fputs (((*yyvaluep).yytype_73), yyo); }
+         { fputs (((*yyvaluep).yytype_73), yyo); }
         break;
 
     case 74: /* generic_symlist  */
-      { symbol_list_syms_print (((*yyvaluep).generic_symlist), yyo); }
+         { symbol_list_syms_print (((*yyvaluep).generic_symlist), yyo); }
         break;
 
     case 75: /* generic_symlist_item  */
-      { symbol_list_syms_print (((*yyvaluep).generic_symlist_item), yyo); }
+         { symbol_list_syms_print (((*yyvaluep).generic_symlist_item), yyo); }
         break;
 
     case 76: /* tag  */
-      { fprintf (yyo, "<%s>", ((*yyvaluep).tag)); }
+         { fprintf (yyo, "<%s>", ((*yyvaluep).tag)); }
         break;
 
     case 77: /* nterm_decls  */
-      { symbol_list_syms_print (((*yyvaluep).nterm_decls), yyo); }
+         { symbol_list_syms_print (((*yyvaluep).nterm_decls), yyo); }
         break;
 
     case 78: /* token_decls  */
-      { symbol_list_syms_print (((*yyvaluep).token_decls), yyo); }
+         { symbol_list_syms_print (((*yyvaluep).token_decls), yyo); }
         break;
 
     case 79: /* token_decl.1  */
-      { symbol_list_syms_print (((*yyvaluep).yytype_79), yyo); }
+         { symbol_list_syms_print (((*yyvaluep).yytype_79), yyo); }
         break;
 
     case 80: /* token_decl  */
-      { fprintf (yyo, "%s", ((*yyvaluep).token_decl) ? ((*yyvaluep).token_decl)->tag : "<NULL>"); }
+         { fprintf (yyo, "%s", ((*yyvaluep).token_decl) ? ((*yyvaluep).token_decl)->tag : "<NULL>"); }
         break;
 
     case 81: /* int.opt  */
-      { fprintf (yyo, "%d", ((*yyvaluep).yytype_81)); }
+         { fprintf (yyo, "%d", ((*yyvaluep).yytype_81)); }
         break;
 
     case 82: /* token_decls_for_prec  */
-      { symbol_list_syms_print (((*yyvaluep).token_decls_for_prec), yyo); }
+         { symbol_list_syms_print (((*yyvaluep).token_decls_for_prec), yyo); }
         break;
 
     case 83: /* token_decl_for_prec.1  */
-      { symbol_list_syms_print (((*yyvaluep).yytype_83), yyo); }
+         { symbol_list_syms_print (((*yyvaluep).yytype_83), yyo); }
         break;
 
     case 84: /* token_decl_for_prec  */
-      { fprintf (yyo, "%s", ((*yyvaluep).token_decl_for_prec) ? ((*yyvaluep).token_decl_for_prec)->tag : "<NULL>"); }
+         { fprintf (yyo, "%s", ((*yyvaluep).token_decl_for_prec) ? ((*yyvaluep).token_decl_for_prec)->tag : "<NULL>"); }
         break;
 
     case 85: /* symbol_decls  */
-      { symbol_list_syms_print (((*yyvaluep).symbol_decls), yyo); }
+         { symbol_list_syms_print (((*yyvaluep).symbol_decls), yyo); }
         break;
 
     case 86: /* symbol_decl.1  */
-      { symbol_list_syms_print (((*yyvaluep).yytype_86), yyo); }
+         { symbol_list_syms_print (((*yyvaluep).yytype_86), yyo); }
         break;
 
     case 94: /* variable  */
-      { fputs (((*yyvaluep).variable), yyo); }
+         { fputs (((*yyvaluep).variable), yyo); }
         break;
 
     case 95: /* value  */
-      {
+{
   switch (((*yyvaluep).value).kind)
     {
     case muscle_code:    fprintf (yyo,  "{%s}",  ((*yyvaluep).value).chars); break;
@@ -1047,23 +1047,23 @@ tron (yyo);
         break;
 
     case 96: /* id  */
-      { fprintf (yyo, "%s", ((*yyvaluep).id) ? ((*yyvaluep).id)->tag : "<NULL>"); }
+         { fprintf (yyo, "%s", ((*yyvaluep).id) ? ((*yyvaluep).id)->tag : "<NULL>"); }
         break;
 
     case 97: /* id_colon  */
-      { fprintf (yyo, "%s:", ((*yyvaluep).id_colon)->tag); }
+         { fprintf (yyo, "%s:", ((*yyvaluep).id_colon)->tag); }
         break;
 
     case 98: /* symbol  */
-      { fprintf (yyo, "%s", ((*yyvaluep).symbol) ? ((*yyvaluep).symbol)->tag : "<NULL>"); }
+         { fprintf (yyo, "%s", ((*yyvaluep).symbol) ? ((*yyvaluep).symbol)->tag : "<NULL>"); }
         break;
 
     case 99: /* string_as_id  */
-      { fprintf (yyo, "%s", ((*yyvaluep).string_as_id) ? ((*yyvaluep).string_as_id)->tag : "<NULL>"); }
+         { fprintf (yyo, "%s", ((*yyvaluep).string_as_id) ? ((*yyvaluep).string_as_id)->tag : "<NULL>"); }
         break;
 
     case 100: /* string_as_id.opt  */
-      { fprintf (yyo, "%s", ((*yyvaluep).yytype_100) ? ((*yyvaluep).yytype_100)->tag : "<NULL>"); }
+         { fprintf (yyo, "%s", ((*yyvaluep).yytype_100) ? ((*yyvaluep).yytype_100)->tag : "<NULL>"); }
         break;
 
       default:
@@ -1654,39 +1654,39 @@ yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocatio
   switch (yytype)
     {
     case 74: /* generic_symlist  */
-      { symbol_list_free (((*yyvaluep).generic_symlist)); }
+            { symbol_list_free (((*yyvaluep).generic_symlist)); }
         break;
 
     case 75: /* generic_symlist_item  */
-      { symbol_list_free (((*yyvaluep).generic_symlist_item)); }
+            { symbol_list_free (((*yyvaluep).generic_symlist_item)); }
         break;
 
     case 77: /* nterm_decls  */
-      { symbol_list_free (((*yyvaluep).nterm_decls)); }
+            { symbol_list_free (((*yyvaluep).nterm_decls)); }
         break;
 
     case 78: /* token_decls  */
-      { symbol_list_free (((*yyvaluep).token_decls)); }
+            { symbol_list_free (((*yyvaluep).token_decls)); }
         break;
 
     case 79: /* token_decl.1  */
-      { symbol_list_free (((*yyvaluep).yytype_79)); }
+            { symbol_list_free (((*yyvaluep).yytype_79)); }
         break;
 
     case 82: /* token_decls_for_prec  */
-      { symbol_list_free (((*yyvaluep).token_decls_for_prec)); }
+            { symbol_list_free (((*yyvaluep).token_decls_for_prec)); }
         break;
 
     case 83: /* token_decl_for_prec.1  */
-      { symbol_list_free (((*yyvaluep).yytype_83)); }
+            { symbol_list_free (((*yyvaluep).yytype_83)); }
         break;
 
     case 85: /* symbol_decls  */
-      { symbol_list_free (((*yyvaluep).symbol_decls)); }
+            { symbol_list_free (((*yyvaluep).symbol_decls)); }
         break;
 
     case 86: /* symbol_decl.1  */
-      { symbol_list_free (((*yyvaluep).yytype_86)); }
+            { symbol_list_free (((*yyvaluep).yytype_86)); }
         break;
 
       default:
@@ -2030,7 +2030,7 @@ yyreduce:
     break;
 
   case 9:
-    { defines_flag = true; }
+                                   { defines_flag = true; }
     break;
 
   case 10:
@@ -2041,19 +2041,19 @@ yyreduce:
     break;
 
   case 11:
-    { handle_error_verbose (&(yyloc), (yyvsp[0].PERCENT_ERROR_VERBOSE)); }
+                                   { handle_error_verbose (&(yyloc), (yyvsp[0].PERCENT_ERROR_VERBOSE)); }
     break;
 
   case 12:
-    { expected_sr_conflicts = (yyvsp[0].INT); }
+                                   { expected_sr_conflicts = (yyvsp[0].INT); }
     break;
 
   case 13:
-    { expected_rr_conflicts = (yyvsp[0].INT); }
+                                   { expected_rr_conflicts = (yyvsp[0].INT); }
     break;
 
   case 14:
-    { handle_file_prefix (&(yyloc), &(yylsp[-1]), (yyvsp[-1].PERCENT_FILE_PREFIX), (yyvsp[0].STRING)); }
+                                   { handle_file_prefix (&(yyloc), &(yylsp[-1]), (yyvsp[-1].PERCENT_FILE_PREFIX), (yyvsp[0].STRING)); }
     break;
 
   case 15:
@@ -2071,67 +2071,67 @@ yyreduce:
     break;
 
   case 17:
-    { language_argmatch ((yyvsp[0].STRING), grammar_prio, (yylsp[-1])); }
+                                { language_argmatch ((yyvsp[0].STRING), grammar_prio, (yylsp[-1])); }
     break;
 
   case 18:
-    { handle_name_prefix (&(yyloc), (yyvsp[-1].PERCENT_NAME_PREFIX), (yyvsp[0].STRING)); }
+                                { handle_name_prefix (&(yyloc), (yyvsp[-1].PERCENT_NAME_PREFIX), (yyvsp[0].STRING)); }
     break;
 
   case 19:
-    { no_lines_flag = true; }
+                                { no_lines_flag = true; }
     break;
 
   case 20:
-    { nondeterministic_parser = true; }
+                                { nondeterministic_parser = true; }
     break;
 
   case 21:
-    { spec_outfile = (yyvsp[0].STRING); }
+                                { spec_outfile = (yyvsp[0].STRING); }
     break;
 
   case 22:
-    { current_param = (yyvsp[0].PERCENT_PARAM); }
+           { current_param = (yyvsp[0].PERCENT_PARAM); }
     break;
 
   case 23:
-    { current_param = param_none; }
+                                          { current_param = param_none; }
     break;
 
   case 24:
-    { handle_pure_parser (&(yyloc), (yyvsp[0].PERCENT_PURE_PARSER)); }
+                                { handle_pure_parser (&(yyloc), (yyvsp[0].PERCENT_PURE_PARSER)); }
     break;
 
   case 25:
-    { handle_require (&(yylsp[0]), (yyvsp[0].STRING)); }
+                                { handle_require (&(yylsp[0]), (yyvsp[0].STRING)); }
     break;
 
   case 26:
-    { handle_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
+                                { handle_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
     break;
 
   case 27:
-    { token_table_flag = true; }
+                                { token_table_flag = true; }
     break;
 
   case 28:
-    { report_flag |= report_states; }
+                                { report_flag |= report_states; }
     break;
 
   case 29:
-    { handle_yacc (&(yyloc), (yyvsp[0].PERCENT_YACC)); }
+                                { handle_yacc (&(yyloc), (yyvsp[0].PERCENT_YACC)); }
     break;
 
   case 30:
-    { current_class = unknown_sym; yyerrok; }
+                                { current_class = unknown_sym; yyerrok; }
     break;
 
   case 32:
-    { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
+                   { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
     break;
 
   case 33:
-    { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
+                   { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
     break;
 
   case 35:
@@ -2183,19 +2183,19 @@ yyreduce:
     break;
 
   case 41:
-    { (yyval.code_props_type) = destructor; }
+                 { (yyval.code_props_type) = destructor; }
     break;
 
   case 42:
-    { (yyval.code_props_type) = printer; }
+                 { (yyval.code_props_type) = printer; }
     break;
 
   case 43:
-    {}
+         {}
     break;
 
   case 44:
-    { muscle_percent_define_insert ("api.value.union.name",
+         { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].ID),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
     break;
@@ -2209,7 +2209,7 @@ yyreduce:
     break;
 
   case 46:
-    { current_class = nterm_sym; }
+           { current_class = nterm_sym; }
     break;
 
   case 47:
@@ -2220,7 +2220,7 @@ yyreduce:
     break;
 
   case 48:
-    { current_class = token_sym; }
+           { current_class = token_sym; }
     break;
 
   case 49:
@@ -2246,47 +2246,47 @@ yyreduce:
     break;
 
   case 52:
-    { (yyval.precedence_declarator) = left_assoc; }
+                { (yyval.precedence_declarator) = left_assoc; }
     break;
 
   case 53:
-    { (yyval.precedence_declarator) = right_assoc; }
+                { (yyval.precedence_declarator) = right_assoc; }
     break;
 
   case 54:
-    { (yyval.precedence_declarator) = non_assoc; }
+                { (yyval.precedence_declarator) = non_assoc; }
     break;
 
   case 55:
-    { (yyval.precedence_declarator) = precedence_assoc; }
+                { (yyval.precedence_declarator) = precedence_assoc; }
     break;
 
   case 56:
-    { (yyval.yytype_73) = NULL; }
+         { (yyval.yytype_73) = NULL; }
     break;
 
   case 57:
-    { (yyval.yytype_73) = (yyvsp[0].TAG); }
+         { (yyval.yytype_73) = (yyvsp[0].TAG); }
     break;
 
   case 59:
-    { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
+                                         { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
     break;
 
   case 60:
-    { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
+            { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 61:
-    { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
+            { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
     break;
 
   case 63:
-    { (yyval.tag) = uniqstr_new ("*"); }
+        { (yyval.tag) = uniqstr_new ("*"); }
     break;
 
   case 64:
-    { (yyval.tag) = uniqstr_new (""); }
+        { (yyval.tag) = uniqstr_new (""); }
     break;
 
   case 66:
@@ -2308,11 +2308,11 @@ yyreduce:
     break;
 
   case 69:
-    { (yyval.yytype_79) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
+                            { (yyval.yytype_79) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
     break;
 
   case 70:
-    { (yyval.yytype_79) = symbol_list_append ((yyvsp[-1].yytype_79), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
+                            { (yyval.yytype_79) = symbol_list_append ((yyvsp[-1].yytype_79), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
     break;
 
   case 71:
@@ -2327,7 +2327,7 @@ yyreduce:
     break;
 
   case 72:
-    { (yyval.yytype_81) = -1; }
+          { (yyval.yytype_81) = -1; }
     break;
 
   case 74:
@@ -2384,11 +2384,11 @@ yyreduce:
     break;
 
   case 84:
-    { (yyval.yytype_86) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
+                        { (yyval.yytype_86) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
     break;
 
   case 85:
-    { (yyval.yytype_86) = symbol_list_append ((yyvsp[-1].yytype_86), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
+                        { (yyval.yytype_86) = symbol_list_append ((yyvsp[-1].yytype_86), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
     break;
 
   case 90:
@@ -2398,7 +2398,7 @@ yyreduce:
     break;
 
   case 91:
-    { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_93)); }
+                         { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_93)); }
     break;
 
   case 92:
@@ -2409,11 +2409,11 @@ yyreduce:
     break;
 
   case 93:
-    { grammar_current_rule_end ((yylsp[0])); }
+                     { grammar_current_rule_end ((yylsp[0])); }
     break;
 
   case 94:
-    { grammar_current_rule_end ((yylsp[0])); }
+                     { grammar_current_rule_end ((yylsp[0])); }
     break;
 
   case 96:
@@ -2458,27 +2458,27 @@ yyreduce:
     break;
 
   case 106:
-    { (yyval.yytype_93) = NULL; }
+                 { (yyval.yytype_93) = NULL; }
     break;
 
   case 107:
-    { (yyval.yytype_93) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
+                 { (yyval.yytype_93) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
     break;
 
   case 109:
-    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
+          { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
     break;
 
   case 110:
-    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
+          { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
     break;
 
   case 111:
-    { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
+          { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
     break;
 
   case 112:
-    { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
+          { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
     break;
 
   case 113:
@@ -2500,7 +2500,7 @@ yyreduce:
     break;
 
   case 115:
-    { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
+           { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
     break;
 
   case 118:
@@ -2511,7 +2511,7 @@ yyreduce:
     break;
 
   case 119:
-    { (yyval.yytype_100) = NULL; }
+                     { (yyval.yytype_100) = NULL; }
     break;
 
   case 122:
