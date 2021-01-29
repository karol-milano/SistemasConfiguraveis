@@ -237,11 +237,11 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
     YYSIZE_T yyes_capacity;]])])
 
 
-# b4_declare_yyparse_push_
+# _b4_declare_yyparse_push
 # ------------------------
 # Declaration of yyparse (and dependencies) when using the push parser
 # (including in pull mode).
-m4_define([b4_declare_yyparse_push_],
+m4_define([_b4_declare_yyparse_push],
 [[#ifndef YYPUSH_MORE_DEFINED
 # define YYPUSH_MORE_DEFINED
 enum { YYPUSH_MORE = 4 };
@@ -265,18 +265,18 @@ b4_function_declare([b4_prefix[pstate_delete]], [[void]],
                    [[b4_prefix[pstate *ps]], [[ps]]])dnl
 ])
 
-# b4_declare_yyparse_
+# _b4_declare_yyparse
 # -------------------
 # When not the push parser.
-m4_define([b4_declare_yyparse_],
+m4_define([_b4_declare_yyparse],
 [b4_function_declare(b4_prefix[parse], [int], b4_parse_param)])
 
 
 # b4_declare_yyparse
 # ------------------
 m4_define([b4_declare_yyparse],
-[b4_push_if([b4_declare_yyparse_push_],
-            [b4_declare_yyparse_])[]dnl
+[b4_push_if([_b4_declare_yyparse_push],
+            [_b4_declare_yyparse])[]dnl
 ])
 
 
