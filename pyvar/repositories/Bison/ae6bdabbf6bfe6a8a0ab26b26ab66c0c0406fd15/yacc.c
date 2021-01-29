@@ -224,6 +224,39 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
     yytype_int16 *yyes;
     YYSIZE_T yyes_capacity;]])])
 
+
+# b4_shared_declarations
+# ----------------------
+# Declaration that might either go into the header (if --defines)
+# or open coded in the parser body.
+m4_define([b4_shared_declarations],
+[b4_percent_code_get([[requires]])[
+]b4_token_enums_defines(b4_tokens)[
+]b4_declare_yylstype[
+]b4_push_if([[
+#ifndef YYPUSH_DECLS
+# define YYPUSH_DECLS
+typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
+enum { YYPUSH_MORE = 4 };
+]b4_pull_if([b4_c_function_decl([b4_prefix[parse]], [[int]], b4_parse_param)
+])b4_c_function_decl([b4_prefix[push_parse]], [[int]],
+  [[b4_prefix[pstate *yyps]], [[yyps]]]b4_pure_if([,
+  [[[int yypushed_char]], [[yypushed_char]]],
+  [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
+  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
+  b4_parse_param]))
+b4_pull_if([b4_c_function_decl([b4_prefix[pull_parse]], [[int]],
+  [[b4_prefix[pstate *yyps]], [[yyps]]]m4_ifset([b4_parse_param], [,
+  b4_parse_param]))])
+b4_c_function_decl([b4_prefix[pstate_new]], [b4_prefix[pstate *]],
+                    [[[void]], []])
+b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
+                   [[b4_prefix[pstate *yyps]], [[yyps]]])[
+#endif
+]])
+b4_percent_code_get([[provides]])[]dnl
+])
+
 ## -------------- ##
 ## Output files.  ##
 ## -------------- ##
@@ -286,34 +319,9 @@ m4_if(b4_prefix, [yy], [],
 # define YYTOKEN_TABLE ]b4_token_table[
 #endif
 
-]b4_percent_code_get([[requires]])[
-]b4_token_enums_defines(b4_tokens)[
-]b4_declare_yylstype[
-]b4_push_if([[
-#ifndef YYPUSH_DECLS
-#  define YYPUSH_DECLS
-struct yypstate;
-typedef struct yypstate yypstate;
-enum { YYPUSH_MORE = 4 };
-
-]b4_pull_if([b4_c_function_decl([[yyparse]], [[int]], b4_parse_param)
-])b4_c_function_decl([[yypush_parse]], [[int]],
-  [[[yypstate *yyps]], [[yyps]]]b4_pure_if([,
-  [[[int yypushed_char]], [[yypushed_char]]],
-  [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
-  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
-  b4_parse_param]))
-b4_pull_if([b4_c_function_decl([[yypull_parse]], [[int]],
-  [[[yypstate *yyps]], [[yyps]]]m4_ifset([b4_parse_param], [,
-  b4_parse_param]))])
-b4_c_function_decl([[yypstate_new]], [[yypstate *]], [[[void]], []])
-b4_c_function_decl([[yypstate_delete]], [[void]],
-                   [[[yypstate *yyps]], [[yyps]]])[
-#endif]])
-
-b4_percent_code_get([[provides]])[]dnl
+]b4_shared_declarations[
 
-[/* Copy the second part of user declarations.  */
+/* Copy the second part of user declarations.  */
 ]b4_user_post_prologue
 b4_percent_code_get[]dnl
 
@@ -2044,36 +2052,9 @@ yypushreturn:]])[
 b4_defines_if(
 [@output(b4_spec_defines_file@)@
 b4_copyright([Bison interface for Yacc-like parsers in C],
-             [1984, 1989-1990, 2000-2012])
-
-b4_percent_code_get([[requires]])[]dnl
-
-b4_token_enums_defines(b4_tokens)[
-]b4_declare_yylstype[
+             [1984, 1989-1990, 2000-2012])[
+]b4_shared_declarations[
 ]b4_pure_if([], [[extern YYSTYPE ]b4_prefix[lval;
 ]b4_locations_if([[extern YYLTYPE ]b4_prefix[lloc;]])])dnl
-b4_push_if([[
-#ifndef YYPUSH_DECLS
-#  define YYPUSH_DECLS
-struct ]b4_prefix[pstate;
-typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
-enum { YYPUSH_MORE = 4 };
-]b4_pull_if([b4_c_function_decl([b4_prefix[parse]], [[int]], b4_parse_param)
-])b4_c_function_decl([b4_prefix[push_parse]], [[int]],
-  [[b4_prefix[pstate *yyps]], [[yyps]]]b4_pure_if([,
-  [[[int yypushed_char]], [[yypushed_char]]],
-  [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
-  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
-  b4_parse_param]))
-b4_pull_if([b4_c_function_decl([b4_prefix[pull_parse]], [[int]],
-  [[b4_prefix[pstate *yyps]], [[yyps]]]m4_ifset([b4_parse_param], [,
-  b4_parse_param]))])
-b4_c_function_decl([b4_prefix[pstate_new]], [b4_prefix[pstate *]],
-                    [[[void]], []])
-b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
-                   [[b4_prefix[pstate *yyps]], [[yyps]]])[
-#endif
-]])
-b4_percent_code_get([[provides]])[]dnl
 ])dnl b4_defines_if
 m4_divert_pop(0)
