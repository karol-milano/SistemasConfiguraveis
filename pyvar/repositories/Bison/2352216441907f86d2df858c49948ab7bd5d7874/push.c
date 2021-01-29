@@ -217,6 +217,22 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif])
 
+b4_push_if([[#ifndef YYPUSH_DECLS
+#  define YYPUSH_DECLS
+struct yypstate;
+typedef struct yypstate yypstate;
+enum { YYPUSH_MORE = 4 };
+]b4_c_function_decl([[yypstate_new]], [[yypstate *]], [[[void]], []])
+b4_c_function_decl([[yypstate_delete]], [[void]],
+                   [[[yypstate *yyps]], [[yyps]]])
+b4_c_function_decl([[yypush_parse]], [[int]],
+  [[[yypstate *yyps]], [[yyps]]],
+  [[[int yynchar]], [[yynchar]]],
+  [[[YYSTYPE const *yynlval]], [[yynlval]]]b4_locations_if([,
+  [[[YYLTYPE const *yynlloc]], [[yynlloc]]]])m4_ifset([b4_parse_param], [,
+  b4_parse_param]))[
+#endif
+]])
 m4_ifdef([b4_provides],
 [[/* Copy the %provides blocks.  */
 ]b4_user_provides])[]dnl
@@ -957,36 +973,23 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 
 
 ]b4_yydestruct_generate([b4_c_function_def])[
-
-
-/* Prevent warnings from -Wmissing-prototypes.  */
 
-]b4_push_if([
-struct yypstate;
-typedef struct yypstate yypstate;
-enum { YYPUSH_MORE = 4 };
-]b4_c_function_decl([yypstate_new], [yypstate *], [[void], []])[
-]b4_c_function_decl([yypstate_delete], [void], [[yypstate *yyps], [yyps]])[
-]b4_c_function_decl([yypush_parse], [int],
-   [[yypstate *yyps], [yyps]],
-   [[int yynchar], [yynchar]],
-   [[YYSTYPE const *yynlval], [yynlval]]
-   b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]])
-   m4_ifset([b4_parse_param], [, b4_parse_param]))[
-],[#ifdef YYPARSE_PARAM
+]b4_push_if([],
+[[/* Prevent warnings from -Wmissing-prototypes.  */
+#ifdef YYPARSE_PARAM
 ]b4_c_function_decl([yyparse], [int],
    [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])[
 #else /* ! YYPARSE_PARAM */
 ]b4_c_function_decl([yyparse], [int], b4_parse_param)[
-#endif /* ! YYPARSE_PARAM */])[
+#endif /* ! YYPARSE_PARAM */]])
 
-]m4_divert_push([KILL])# ======================== M4 code.
+m4_divert_push([KILL])# ======================== M4 code.
 # b4_declare_scanner_communication_variables
 # ------------------------------------------
 # Declare the variables that are global, or local to YYPARSE if
 # pure-parser.
 m4_define([b4_declare_scanner_communication_variables],
-[/* The lookahead symbol.  */
+[[/* The lookahead symbol.  */
 int yychar;
 
 /* The semantic value of the lookahead symbol.  */
@@ -994,9 +997,9 @@ YYSTYPE yylval;
 
 /* Number of syntax errors so far.  */
 ]b4_push_if([],[
-int yynerrs;])[b4_locations_if([
+int yynerrs;])b4_locations_if([[
 /* Location data for the lookahead symbol.  */
-YYLTYPE yylloc;])
+YYLTYPE yylloc;]])
 ])
 
 m4_define([b4_yyssa],b4_push_if([yyps->yyssa],[yyssa]))
@@ -1060,7 +1063,7 @@ b4_push_if(
   };
 
 /* Initialize the parser data structure.  */
-]b4_c_function_def([yypstate_new], [yypstate *])[
+]b4_c_function_def([[yypstate_new]], [[yypstate *]])[
 {
   yypstate *yyps = (yypstate *) malloc (sizeof *yyps);
   yyps->yystate = 0;
@@ -1085,8 +1088,8 @@ b4_push_if(
   return yyps;
 }
 
-]b4_c_function_def([yypstate_delete], [void],
-                   [[yypstate *yyps], [yyps]])[
+]b4_c_function_def([[yypstate_delete]], [[void]],
+                   [[[yypstate *yyps]], [[yyps]]])[
 {
   free (yyps);
 }
@@ -1112,11 +1115,11 @@ b4_push_if(
 `-------------------------*/
 
 ]b4_push_if([
-b4_c_function_def([yypush_parse], [int], [[yypstate *yyps], [yyps]], 
-                  [[int yynchar], [yynchar]],
-                  [[YYSTYPE const *yynlval], [yynlval]]
-		  b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]])
-                  m4_ifset([b4_parse_param], [, b4_parse_param]))],[
+b4_c_function_def([[yypush_parse]], [[int]], [[[yypstate *yyps]], [[yyps]]], 
+  [[[int yynchar]], [[yynchar]]],
+  [[[YYSTYPE const *yynlval]], [[yynlval]]]b4_locations_if([,
+  [[[YYLTYPE const *yynlloc]], [[yynlloc]]]])m4_ifset([b4_parse_param], [,
+  b4_parse_param]))], [
 #ifdef YYPARSE_PARAM
 b4_c_function_def([yyparse], [int], [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])
 #else /* ! YYPARSE_PARAM */
@@ -1156,7 +1159,6 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
      Waste one element of value and location stack
      so that they stay on the same level as the state stack.
      The wasted elements are never initialized.  */
-
   yyssp = yyss;
   yyvsp = yyvs;
 ]b4_locations_if([[  yylsp = yyls;
@@ -1634,20 +1636,23 @@ typedef struct YYLTYPE
 	   [extern YYLTYPE b4_prefix[]lloc;])
 )dnl b4_locations_if
 
-]b4_push_if([struct ]b4_prefix[pstate;
+b4_push_if([[#ifndef YYPUSH_DECLS
+#  define YYPUSH_DECLS
+struct ]b4_prefix[pstate;
 typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
-]b4_c_function_decl([]b4_prefix[pstate_new], []b4_prefix[pstate *],
-                    [[void], []])[
-]b4_c_function_decl([]b4_prefix[pstate_delete], [void],
-                    [[]b4_prefix[pstate *yyps],[yyps]])[
-]b4_c_function_decl([]b4_prefix[push_parse], [int],
-   [[]b4_prefix[pstate *]b4_prefix[pstate], []b4_prefix[pstate]],
-   [[int yynchar], [yynchar]],
-   [[YYSTYPE const *yynlval], [yynlval]]
-   b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]])
-   m4_ifset([b4_parse_param], [, b4_parse_param]))[
-enum { YYPUSH_MORE = 4 };])[
-
+enum { YYPUSH_MORE = 4 };
+]b4_c_function_decl([b4_prefix[pstate_new]], [b4_prefix[pstate *]],
+                    [[[void]], []])
+b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
+                   [[b4_prefix[pstate *yyps]], [[yyps]]])
+b4_c_function_decl([b4_prefix[push_parse]], [[int]],
+  [[b4_prefix[pstate *yyps]], [[yyps]]],
+  [[[int yynchar]], [[yynchar]]],
+  [[[YYSTYPE const *yynlval]], [[yynlval]]]b4_locations_if([,
+  [[[YYLTYPE const *yynlloc]], [[yynlloc]]]])m4_ifset([b4_parse_param], [,
+  b4_parse_param]))[
+#endif
+]])
 m4_ifdef([b4_provides],
 [[/* Copy the %provides blocks.  */
 ]b4_user_provides])[]
