@@ -963,11 +963,12 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 
 ]b4_push_if([
 struct yypstate;
+typedef struct yypstate yypstate;
 enum { YYPUSH_MORE = 4 };
-]b4_c_function_decl([yypstate_new], [struct yypstate *], [[void], []])[
-]b4_c_function_decl([yypstate_delete], [void], [[struct yypstate *yyps], [yyps]])[
+]b4_c_function_decl([yypstate_new], [yypstate *], [[void], []])[
+]b4_c_function_decl([yypstate_delete], [void], [[yypstate *yyps], [yyps]])[
 ]b4_c_function_decl([yypush_parse], [int],
-   [[struct yypstate *yyps], [yyps]],
+   [[yypstate *yyps], [yyps]],
    [[int yynchar], [yynchar]],
    [[YYSTYPE const *yynlval], [yynlval]]
    b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]]))[
@@ -1047,9 +1048,9 @@ m4_define([b4_declare_yyparse_variables],
   };
 
 /* Initialize the parser data structure.  */
-]b4_c_function_def([yypstate_new], [struct yypstate *])[
+]b4_c_function_def([yypstate_new], [yypstate *])[
 {
-  struct yypstate *yyps = (struct yypstate *) malloc (sizeof *yyps);
+  yypstate *yyps = (yypstate *) malloc (sizeof *yyps);
   yyps->yystate = 0;
   yyps->yyresult = -1;
   yyps->yyerrstatus = 0;
@@ -1073,7 +1074,7 @@ m4_define([b4_declare_yyparse_variables],
 }
 
 ]b4_c_function_def([yypstate_delete], [void],
-                   [[struct yypstate *yyps], [yyps]])[
+                   [[yypstate *yyps], [yyps]])[
 {
   free (yyps);
 }
@@ -1090,7 +1091,7 @@ b4_push_if([b4_declare_yyparse_variables])
 `-------------------------*/
 
 b4_push_if([
-b4_c_function_def([yypush_parse], [int], [[struct yypstate *yyps], [yyps]], 
+b4_c_function_def([yypush_parse], [int], [[yypstate *yyps], [yyps]], 
                   [[int yynchar], [yynchar]],
                   [[YYSTYPE const *yynlval], [yynlval]]
 		  b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]]))],[
@@ -1690,12 +1691,13 @@ typedef struct YYLTYPE
 )dnl b4_locations_if
 
 ]b4_push_if([struct ]b4_prefix[pstate;
-]b4_c_function_decl([]b4_prefix[pstate_new], [struct ]b4_prefix[pstate *],
+typedef struct ]b4_prefix[pstate ]b4_prefix[pstate;
+]b4_c_function_decl([]b4_prefix[pstate_new], []b4_prefix[pstate *],
                     [[void], []])[
 ]b4_c_function_decl([]b4_prefix[pstate_delete], [void],
-                    [[struct ]b4_prefix[pstate *yyps],[yyps]])[
+                    [[]b4_prefix[pstate *yyps],[yyps]])[
 ]b4_c_function_decl([]b4_prefix[push_parse], [int],
-   [[struct ]b4_prefix[pstate *]b4_prefix[pstate], []b4_prefix[pstate]],
+   [[]b4_prefix[pstate *]b4_prefix[pstate], []b4_prefix[pstate]],
    [[int yynchar], [yynchar]],
    [[YYSTYPE const *yynlval], [yynlval]]
    b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]]))[
