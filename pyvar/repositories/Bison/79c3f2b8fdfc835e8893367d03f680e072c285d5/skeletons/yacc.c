@@ -231,27 +231,20 @@ enum { YYPUSH_MORE = 4 };
 
 typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
 
-]b4_pull_if([b4_function_declare([b4_prefix[parse]], [[int]], b4_parse_param)
-])b4_function_declare([b4_prefix[push_parse]], [[int]],
-  [[b4_prefix[pstate *ps]], [[ps]]]b4_pure_if([,
-  [[[int pushed_char]], [[pushed_char]]],
-  [[b4_api_PREFIX[STYPE const *pushed_val]], [[pushed_val]]]b4_locations_if([,
-  [[b4_api_PREFIX[LTYPE *pushed_loc]], [[pushed_loc]]]])])m4_ifset([b4_parse_param], [,
-  b4_parse_param]))
-b4_pull_if([b4_function_declare([b4_prefix[pull_parse]], [[int]],
-  [[b4_prefix[pstate *ps]], [[ps]]]m4_ifset([b4_parse_param], [,
-  b4_parse_param]))])
-b4_function_declare([b4_prefix[pstate_new]], [b4_prefix[pstate *]],
-                    [[[void]], []])
-b4_function_declare([b4_prefix[pstate_delete]], [[void]],
-                   [[b4_prefix[pstate *ps]], [[ps]]])dnl
-])
+]b4_pull_if([[
+int ]b4_prefix[parse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[);]])[
+int ]b4_prefix[push_parse (]b4_prefix[pstate *ps]b4_pure_if([[,
+                  int pushed_char, ]b4_api_PREFIX[STYPE const *pushed_val]b4_locations_if([[, ]b4_api_PREFIX[LTYPE *pushed_loc]])])b4_user_formals[);
+]b4_pull_if([[int ]b4_prefix[pull_parse (]b4_prefix[pstate *ps]b4_user_formals[);]])[
+]b4_prefix[pstate *]b4_prefix[pstate_new (void);
+void ]b4_prefix[pstate_delete (]b4_prefix[pstate *ps);
+]])
 
 # _b4_declare_yyparse
 # -------------------
 # When not the push parser.
 m4_define([_b4_declare_yyparse],
-[b4_function_declare(b4_prefix[parse], [int], b4_parse_param)])
+[[int ]b4_prefix[parse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[);]])
 
 
 # b4_declare_yyparse
@@ -1193,9 +1186,8 @@ yyparse_context_location (const yyparse_context_t *yyctx)
 }]])[
 
 /* User defined function to report a syntax error.  */
-]b4_function_declare([yyreport_syntax_error], [static int],
-                     [[[const yyparse_context_t *yyctx]], [[yyctx]]],
-                     b4_parse_param)],
+static int
+yyreport_syntax_error (const yyparse_context_t *yyctx]b4_user_formals[);]],
          [simple],
 [[]],
 [[#ifndef yystrlen
