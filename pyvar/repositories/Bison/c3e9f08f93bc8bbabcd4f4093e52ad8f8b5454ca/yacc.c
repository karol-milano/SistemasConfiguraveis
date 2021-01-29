@@ -225,18 +225,10 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
     YYSIZE_T yyes_capacity;]])])
 
 
-# b4_shared_declarations
-# ----------------------
-# Declaration that might either go into the header (if --defines)
-# or open coded in the parser body.
-m4_define([b4_shared_declarations],
-[b4_percent_code_get([[requires]])[
-]b4_token_enums_defines(b4_tokens)[
-]b4_declare_yylstype[
-]b4_push_if([[
-#ifndef YYPUSH_DECLS
-# define YYPUSH_DECLS
-typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
+# b4_declare_yyparse_push_
+# ------------------------
+m4_define([b4_declare_yyparse_push_],
+[[typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
 enum { YYPUSH_MORE = 4 };
 ]b4_pull_if([b4_c_function_decl([b4_prefix[parse]], [[int]], b4_parse_param)
 ])b4_c_function_decl([b4_prefix[push_parse]], [[int]],
@@ -251,10 +243,40 @@ b4_pull_if([b4_c_function_decl([b4_prefix[pull_parse]], [[int]],
 b4_c_function_decl([b4_prefix[pstate_new]], [b4_prefix[pstate *]],
                     [[[void]], []])
 b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
-                   [[b4_prefix[pstate *yyps]], [[yyps]]])[
-#endif
-]])
-b4_percent_code_get([[provides]])[]dnl
+                   [[b4_prefix[pstate *yyps]], [[yyps]]])dnl
+])
+
+# b4_declare_yyparse_
+# -------------------
+# When not the push parser.
+m4_define([b4_declare_yyparse_],
+[[#ifdef YYPARSE_PARAM
+]b4_c_function_decl(b4_prefix[parse], [int],
+                    [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])[
+#else /* ! YYPARSE_PARAM */
+]b4_c_function_decl(b4_prefix[parse], [int], b4_parse_param)[
+#endif /* ! YYPARSE_PARAM */]dnl
+])
+
+
+# b4_declare_yyparse
+# ------------------
+m4_define([b4_declare_yyparse],
+[b4_push_if([b4_declare_yyparse_push_],
+            [b4_declare_yyparse_])[]dnl
+])
+
+
+# b4_shared_declarations
+# ----------------------
+# Declaration that might either go into the header (if --defines)
+# or open coded in the parser body.
+m4_define([b4_shared_declarations],
+[b4_percent_code_get([[requires]])[
+]b4_token_enums_defines(b4_tokens)[
+]b4_declare_yylstype[
+]b4_declare_yyparse[
+]b4_percent_code_get([[provides]])[]dnl
 ])
 
 ## -------------- ##
@@ -1373,20 +1395,12 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 }
 #endif /* YYERROR_VERBOSE */
 
-]b4_yydestruct_generate([b4_c_function_def])b4_push_if([], [[
+]b4_yydestruct_generate([b4_c_function_def])[
 
-
-/* Prevent warnings from -Wmissing-prototypes.  */
-#ifdef YYPARSE_PARAM
-]b4_c_function_decl([yyparse], [int],
-                    [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])[
-#else /* ! YYPARSE_PARAM */
-]b4_c_function_decl([yyparse], [int], b4_parse_param)[
-#endif /* ! YYPARSE_PARAM */]])b4_pure_if([], [
+]b4_pure_if([], [
 
 b4_declare_scanner_communication_variables])[]b4_push_if([[
 
-
 struct yypstate
   {]b4_declare_parser_state_variables[
     /* Used to determine if this is the first time this instance has
@@ -2054,8 +2068,11 @@ b4_defines_if(
 [@output(b4_spec_defines_file@)@
 b4_copyright([Bison interface for Yacc-like parsers in C],
              [1984, 1989-1990, 2000-2012])[
+
+]b4_cpp_guard_open([b4_spec_defines_file])[
 ]b4_shared_declarations[
 ]b4_pure_if([], [[extern YYSTYPE ]b4_prefix[lval;
-]b4_locations_if([[extern YYLTYPE ]b4_prefix[lloc;]])])dnl
-])dnl b4_defines_if
+]b4_locations_if([[extern YYLTYPE ]b4_prefix[lloc;]])])[
+]b4_cpp_guard_close([b4_spec_defines_file])[
+]])dnl b4_defines_if
 m4_divert_pop(0)
