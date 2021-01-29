@@ -63,32 +63,6 @@ b4_locations_if([, [[YYLTYPE *], [&yylloc]]])m4_ifdef([b4_lex_param], [, ])])dnl
 m4_ifdef([b4_lex_param], b4_lex_param)))
 
 
-# b4_generate_macro_args([A], [B], [C], ...)
-# ---------------------------------------------------
-# Generate a comma-delimited list whose size is equal to the number of input
-# arguments and whose form is:
-#
-#   YYARG1, YYARG2, YYARG3, ...
-#
-# No argument should be the empty string except A in the special invocation
-# b4_generate_macro_args(), which generates an empty string.
-m4_define([b4_generate_macro_args],
-[m4_if([$1], [], [], [$#], [1], [[YYARG1]],
-       [b4_generate_macro_args(m4_shift($@)), [YYARG$#]])])
-
-
-# b4_parenthesize([A], [B], [C], ...)
-# ---------------------------------------------------
-# Convert arguments to the form:
-#
-#   (A), (B), (C), ...
-#
-# No argument should be the empty string except A in the special invocation
-# b4_parenthesize(), which generates an empty string.
-m4_define([b4_parenthesize],
-[m4_if([$1], [], [], [$#], [1], [[($1)]],
-       [($1), b4_parenthesize(m4_shift($@))])])
-
 ## ------------ ##
 ## Data Types.  ##
 ## ------------ ##
@@ -175,20 +149,20 @@ b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
 
 ]b4_identification
 m4_if(b4_prefix, [yy], [],
-[/* Substitute the variable and function names.  */
-]b4_push_if([#define yypush_parse b4_prefix[]push_parse
-#define yypull_parse b4_prefix[]pull_parse
-#define yypstate_new b4_prefix[]pstate_new
-#define yypstate_delete b4_prefix[]pstate_delete
-#define yypstate b4_prefix[]pstate],
-[#define yyparse b4_prefix[]parse])[
-#define yylex   b4_prefix[]lex
-#define yyerror b4_prefix[]error
-#define yylval  b4_prefix[]lval
-#define yychar  b4_prefix[]char
-#define yydebug b4_prefix[]debug
-#define yynerrs b4_prefix[]nerrs
-b4_locations_if([#define yylloc b4_prefix[]lloc])])[
+[[/* Substitute the variable and function names.  */
+]b4_pull_if([[#define yyparse         ]b4_prefix[parse
+]])b4_push_if([[#define yypush_parse    ]b4_prefix[push_parse
+]b4_pull_if([[#define yypull_parse    ]b4_prefix[pull_parse
+]])[#define yypstate_new    ]b4_prefix[pstate_new
+#define yypstate_delete ]b4_prefix[pstate_delete
+#define yypstate        ]b4_prefix[pstate
+]])[#define yylex           ]b4_prefix[lex
+#define yyerror         ]b4_prefix[error
+#define yylval          ]b4_prefix[lval
+#define yychar          ]b4_prefix[char
+#define yydebug         ]b4_prefix[debug
+#define yynerrs         ]b4_prefix[nerrs
+]b4_locations_if([[#define yylloc          ]b4_prefix[lloc]])])[
 
 /* Copy the first part of user declarations.  */
 ]b4_user_pre_prologue[
@@ -248,20 +222,20 @@ b4_push_if([[#ifndef YYPUSH_DECLS
 struct yypstate;
 typedef struct yypstate yypstate;
 enum { YYPUSH_MORE = 4 };
-#  define yyparse(]b4_generate_macro_args(b4_parse_param))[ yypull_parse (0, &yylex]m4_ifset([b4_parse_param], [, b4_parenthesize(b4_generate_macro_args(b4_parse_param))])[)
-]b4_c_function_decl([[yypstate_new]], [[yypstate *]], [[[void]], []])
-b4_c_function_decl([[yypstate_delete]], [[void]],
-                   [[[yypstate *yyps]], [[yyps]]])
-b4_c_function_decl([[yypush_parse]], [[int]],
+
+]b4_pull_if([b4_c_function_decl([[yyparse]], [[int]], b4_parse_param)
+])b4_c_function_decl([[yypush_parse]], [[int]],
   [[[yypstate *yyps]], [[yyps]]]b4_pure_if([,
   [[[int yypushed_char]], [[yypushed_char]]],
   [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
   [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
   b4_parse_param]))
-b4_c_function_decl([[yypull_parse]], [[int]],
-  [[[yypstate *yyps]], [[yyps]]],
-  [[[int (*yylexp)(]b4_c_ansi_formals(b4_lex_param)[)]], [[yylexp]]]m4_ifset([b4_parse_param], [,
-  b4_parse_param]))[
+b4_pull_if([b4_c_function_decl([[yypull_parse]], [[int]],
+  [[[yypstate *yyps]], [[yyps]]]m4_ifset([b4_parse_param], [,
+  b4_parse_param]))])
+b4_c_function_decl([[yypstate_new]], [[yypstate *]], [[[void]], []])
+b4_c_function_decl([[yypstate_delete]], [[void]],
+                   [[[yypstate *yyps]], [[yyps]]])[
 #endif
 ]])
 m4_ifdef([b4_provides],
@@ -1087,9 +1061,14 @@ b4_push_if(
     int yynew;
   };
 
+]b4_pull_if([b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
+{
+  return yypull_parse (0]m4_ifset([b4_parse_param],
+                                  [[, ]b4_c_args(b4_parse_param)])[);
+}
+
 ]b4_c_function_def([[yypull_parse]], [[int]],
-  [[[yypstate *yyps]], [[yyps]]],
-  [[[int (*yylexp)(]b4_c_ansi_formals(b4_lex_param)[)]], [[yylexp]]]m4_ifset([b4_parse_param], [,
+  [[[yypstate *yyps]], [[yyps]]]m4_ifset([b4_parse_param], [,
   b4_parse_param]))[
 {
   int yystatus;
@@ -1103,7 +1082,7 @@ b4_push_if(
    else
      yyps_local = yyps;
    do {
-     yychar = ]b4_c_function_call([yylexp], [int], b4_lex_param)[;
+     yychar = YYLEX;
      yystatus =
        yypush_parse (yyps_local]b4_pure_if([[, yychar, &yylval]b4_locations_if([[, &yylloc]])])m4_ifset([b4_parse_param], [, b4_c_args(b4_parse_param)])[);
   } while (yystatus == YYPUSH_MORE);
@@ -1111,7 +1090,7 @@ b4_push_if(
     yypstate_delete (yyps_local);
   return yystatus;
 }
-
+]])[
 /* Initialize the parser data structure.  */
 ]b4_c_function_def([[yypstate_new]], [[yypstate *]])[
 {
@@ -1703,21 +1682,20 @@ b4_push_if([[#ifndef YYPUSH_DECLS
 struct ]b4_prefix[pstate;
 typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
 enum { YYPUSH_MORE = 4 };
-#  define ]b4_prefix[parse(]b4_generate_macro_args(b4_parse_param)) b4_prefix[pull_parse (0, &]b4_prefix[lex]m4_ifset([b4_parse_param], [, b4_parenthesize(b4_generate_macro_args(b4_parse_param))])[)
-]b4_c_function_decl([b4_prefix[pstate_new]], [b4_prefix[pstate *]],
-                    [[[void]], []])
-b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
-                   [[b4_prefix[pstate *yyps]], [[yyps]]])
-b4_c_function_decl([b4_prefix[push_parse]], [[int]],
+]b4_pull_if([b4_c_function_decl([b4_prefix[parse]], [[int]], b4_parse_param)
+])b4_c_function_decl([b4_prefix[push_parse]], [[int]],
   [[b4_prefix[pstate *yyps]], [[yyps]]]b4_pure_if([,
   [[[int yypushed_char]], [[yypushed_char]]],
   [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
   [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
   b4_parse_param]))
-b4_c_function_decl([b4_prefix[pull_parse]], [[int]],
-  [[b4_prefix[pstate *yyps]], [[yyps]]],
-  [[[int (*yylexp)(]b4_c_ansi_formals(b4_lex_param)[)]], [[yylexp]]]m4_ifset([b4_parse_param], [,
-  b4_parse_param]))[
+b4_pull_if([b4_c_function_decl([b4_prefix[pull_parse]], [[int]],
+  [[b4_prefix[pstate *yyps]], [[yyps]]]m4_ifset([b4_parse_param], [,
+  b4_parse_param]))])
+b4_c_function_decl([b4_prefix[pstate_new]], [b4_prefix[pstate *]],
+                    [[[void]], []])
+b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
+                   [[b4_prefix[pstate *yyps]], [[yyps]]])[
 #endif
 ]])
 m4_ifdef([b4_provides],
