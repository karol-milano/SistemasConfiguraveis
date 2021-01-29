@@ -259,13 +259,7 @@ b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
 # -------------------
 # When not the push parser.
 m4_define([b4_declare_yyparse_],
-[[#ifdef YYPARSE_PARAM
-]b4_c_function_decl(b4_prefix[parse], [int],
-                    [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])[
-#else /* ! YYPARSE_PARAM */
-]b4_c_function_decl(b4_prefix[parse], [int], b4_parse_param)[
-#endif /* ! YYPARSE_PARAM */]dnl
-])
+[b4_c_function_decl(b4_prefix[parse], [int], b4_parse_param)])
 
 
 # b4_declare_yyparse
@@ -1407,12 +1401,7 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
 | yyparse.  |
 `----------*/
 
-#ifdef YYPARSE_PARAM
-]b4_c_function_def([yyparse], [int],
-                   [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])[
-#else /* ! YYPARSE_PARAM */
-]b4_c_function_def([yyparse], [int], b4_parse_param)[
-#endif]])[
+]b4_c_function_def([yyparse], [int], b4_parse_param)])[
 {]b4_pure_if([b4_declare_scanner_communication_variables
 ])b4_push_if([b4_pure_if([], [[
   int yypushed_char = yychar;
