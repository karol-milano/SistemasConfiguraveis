@@ -63,6 +63,31 @@ b4_locations_if([, [[YYLTYPE *], [&yylloc]]])m4_ifdef([b4_lex_param], [, ])])dnl
 m4_ifdef([b4_lex_param], b4_lex_param)))
 
 
+# b4_generate_macro_args([A], [B], [C], ...)
+# ---------------------------------------------------
+# Generate a comma-delimited list whose size is equal to the number of input
+# arguments and whose form is:
+#
+#   YYARG1, YYARG2, YYARG3, ...
+#
+# No argument should be the empty string except A in the special invocation
+# b4_generate_macro_args(), which generates an empty string.
+m4_define([b4_generate_macro_args],
+[m4_if([$1], [], [], [$#], [1], [[YYARG1]],
+       [b4_generate_macro_args(m4_shift($@)), [YYARG$#]])])
+
+
+# b4_parenthesize([A], [B], [C], ...)
+# ---------------------------------------------------
+# Convert arguments to the form:
+#
+#   (A), (B), (C), ...
+#
+# No argument should be the empty string except A in the special invocation
+# b4_parenthesize(), which generates an empty string.
+m4_define([b4_parenthesize],
+[m4_if([$1], [], [], [$#], [1], [[($1)]],
+       [($1), b4_parenthesize(m4_shift($@))])])
 
 ## ------------ ##
 ## Data Types.  ##
@@ -152,6 +177,7 @@ b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
 m4_if(b4_prefix, [yy], [],
 [/* Substitute the variable and function names.  */
 ]b4_push_if([#define yypush_parse b4_prefix[]push_parse
+#define yypull_parse b4_prefix[]pull_parse
 #define yypstate_new b4_prefix[]pstate_new
 #define yypstate_delete b4_prefix[]pstate_delete
 #define yypstate b4_prefix[]pstate],
@@ -222,6 +248,7 @@ b4_push_if([[#ifndef YYPUSH_DECLS
 struct yypstate;
 typedef struct yypstate yypstate;
 enum { YYPUSH_MORE = 4 };
+#  define yyparse(]b4_generate_macro_args(b4_parse_param))[ yypull_parse (0, &yylex]m4_ifset([b4_parse_param], [, b4_parenthesize(b4_generate_macro_args(b4_parse_param))])[)
 ]b4_c_function_decl([[yypstate_new]], [[yypstate *]], [[[void]], []])
 b4_c_function_decl([[yypstate_delete]], [[void]],
                    [[[yypstate *yyps]], [[yyps]]])
@@ -230,6 +257,10 @@ b4_c_function_decl([[yypush_parse]], [[int]],
   [[[int yypushed_char]], [[yypushed_char]]],
   [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
   [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
+  b4_parse_param]))
+b4_c_function_decl([[yypull_parse]], [[int]],
+  [[[yypstate *yyps]], [[yyps]]],
+  [[[int (*yylexp)(]b4_c_ansi_formals(b4_lex_param)[)]], [[yylexp]]]m4_ifset([b4_parse_param], [,
   b4_parse_param]))[
 #endif
 ]])
@@ -1065,6 +1096,31 @@ b4_push_if(
     int yynew;
   };
 
+]b4_c_function_def([[yypull_parse]], [[int]],
+  [[[yypstate *yyps]], [[yyps]]],
+  [[[int (*yylexp)(]b4_c_ansi_formals(b4_lex_param)[)]], [[yylexp]]]m4_ifset([b4_parse_param], [,
+  b4_parse_param]))[
+{
+  int yystatus;
+  yypstate *yyps_local;
+]b4_pure_if([[  int yychar;
+  YYSTYPE yylval;
+]b4_locations_if([[  YYLTYPE yylloc;
+]])])[
+  if (yyps == 0)
+     yyps_local = yypstate_new ();
+   else
+     yyps_local = yyps;
+   do {
+     yychar = ]b4_c_function_call([yylexp], [int], b4_lex_param)[;
+     yystatus =
+       yypush_parse (yyps_local]b4_pure_if([[, yychar, &yylval]b4_locations_if([[, &yylloc]])])m4_ifset([b4_parse_param], [, b4_c_args(b4_parse_param)])[);
+  } while (yystatus == YYPUSH_MORE);
+  if (yyps == 0)
+    yypstate_delete (yyps_local);
+  return yystatus;
+}
+
 /* Initialize the parser data structure.  */
 ]b4_c_function_def([[yypstate_new]], [[yypstate *]])[
 {
@@ -1651,6 +1707,7 @@ b4_push_if([[#ifndef YYPUSH_DECLS
 struct ]b4_prefix[pstate;
 typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
 enum { YYPUSH_MORE = 4 };
+#  define ]b4_prefix[parse(]b4_generate_macro_args(b4_parse_param)) b4_prefix[pull_parse (0, &]b4_prefix[lex]m4_ifset([b4_parse_param], [, b4_parenthesize(b4_generate_macro_args(b4_parse_param))])[)
 ]b4_c_function_decl([b4_prefix[pstate_new]], [b4_prefix[pstate *]],
                     [[[void]], []])
 b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
@@ -1660,6 +1717,10 @@ b4_c_function_decl([b4_prefix[push_parse]], [[int]],
   [[[int yypushed_char]], [[yypushed_char]]],
   [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
   [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
+  b4_parse_param]))
+b4_c_function_decl([b4_prefix[pull_parse]], [[int]],
+  [[b4_prefix[pstate *yyps]], [[yyps]]],
+  [[[int (*yylexp)(]b4_c_ansi_formals(b4_lex_param)[)]], [[yylexp]]]m4_ifset([b4_parse_param], [,
   b4_parse_param]))[
 #endif
 ]])
