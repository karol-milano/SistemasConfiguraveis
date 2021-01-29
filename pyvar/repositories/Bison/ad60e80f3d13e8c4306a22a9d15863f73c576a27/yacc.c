@@ -230,22 +230,27 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
 # Declaration of yyparse (and dependencies) when using the push parser
 # (including in pull mode).
 m4_define([b4_declare_yyparse_push_],
-[[typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
+[[#ifndef YYPUSH_MORE_DEFINED
+# define YYPUSH_MORE_DEFINED
 enum { YYPUSH_MORE = 4 };
+#endif
+
+typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
+
 ]b4_pull_if([b4_c_function_decl([b4_prefix[parse]], [[int]], b4_parse_param)
 ])b4_c_function_decl([b4_prefix[push_parse]], [[int]],
-  [[b4_prefix[pstate *yyps]], [[yyps]]]b4_pure_if([,
-  [[[int yypushed_char]], [[yypushed_char]]],
-  [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
-  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
+  [[b4_prefix[pstate *ps]], [[ps]]]b4_pure_if([,
+  [[[int pushed_char]], [[pushed_char]]],
+  [[b4_api_PREFIX[STYPE const *pushed_val]], [[pushed_val]]]b4_locations_if([,
+  [[b4_api_PREFIX[LTYPE const *pushed_loc]], [[pushed_loc]]]])])m4_ifset([b4_parse_param], [,
   b4_parse_param]))
 b4_pull_if([b4_c_function_decl([b4_prefix[pull_parse]], [[int]],
-  [[b4_prefix[pstate *yyps]], [[yyps]]]m4_ifset([b4_parse_param], [,
+  [[b4_prefix[pstate *ps]], [[ps]]]m4_ifset([b4_parse_param], [,
   b4_parse_param]))])
 b4_c_function_decl([b4_prefix[pstate_new]], [b4_prefix[pstate *]],
                     [[[void]], []])
 b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
-                   [[b4_prefix[pstate *yyps]], [[yyps]]])dnl
+                   [[b4_prefix[pstate *ps]], [[ps]]])dnl
 ])
 
 # b4_declare_yyparse_
