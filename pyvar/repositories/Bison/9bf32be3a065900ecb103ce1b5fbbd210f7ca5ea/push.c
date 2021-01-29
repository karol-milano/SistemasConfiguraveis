@@ -153,7 +153,8 @@ m4_if(b4_prefix, [yy], [],
 [/* Substitute the variable and function names.  */
 #define yyparse b4_prefix[]parse
 ]b4_push_if([#define yypush_parse b4_prefix[]push_parse
-#define yypstate_init b4_prefix[]pstate_init
+#define yypstate_new b4_prefix[]pstate_new
+#define yypstate_delete b4_prefix[]pstate_delete
 #define yypstate b4_prefix[]pstate])[
 #define yylex   b4_prefix[]lex
 #define yyerror b4_prefix[]error
@@ -970,12 +971,13 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 ]b4_push_if([
 struct yypstate;
 enum { YYPUSH_MORE = 4 };
-]b4_c_function_decl([yypstate_init], [struct yypstate *], [[void], []])[
+]b4_c_function_decl([yypstate_new], [struct yypstate *], [[void], []])[
+]b4_c_function_decl([yypstate_delete], [void], [[struct yypstate *yyps], [yyps]])[
 ]b4_c_function_decl([yypush_parse], [int],
    [[struct yypstate *yyps], [yyps]],
    [[int yynchar], [yynchar]],
-   [[YYSTYPE *yynlval], [yynlval]]
-   b4_locations_if([,[[YYLTYPE *yynlloc], [yynlloc]]]))[
+   [[YYSTYPE const *yynlval], [yynlval]]
+   b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]]))[
 ])[
 
 ]m4_divert_push([KILL])# ======================== M4 code.
@@ -1047,8 +1049,7 @@ m4_define([b4_declare_yyparse_variables],
   };
 
 /* Initialize the parser data structure.  */
-struct yypstate*
-yypstate_init (void)
+]b4_c_function_def([yypstate_new], [struct yypstate *])[
 {
   struct yypstate *yyps = (struct yypstate *) malloc (sizeof *yyps);
   yyps->yystate = 0;
@@ -1071,7 +1072,14 @@ yypstate_init (void)
 ]b4_locations_if([  yyps->yylsp = yyps->yyls;])[
 
   return yyps;
-}])
+}
+
+]b4_c_function_def([yypstate_delete], [void],
+                   [[struct yypstate *yyps], [yyps]])[
+{
+  free (yyps);
+}
+])
 m4_divert_pop([KILL])dnl# ====================== End of M4 code.
 
 b4_push_if([],[b4_pure_if([],
@@ -1085,8 +1093,9 @@ b4_push_if([b4_declare_yyparse_variables])
 
 b4_push_if([
 b4_c_function_def([yypush_parse], [int], [[struct yypstate *yyps], [yyps]], 
-                  [[int yynchar], [yynchar]], [[YYSTYPE *yynlval], [yynlval]]
-		  b4_locations_if([,[[YYLTYPE *yynlloc], [yynlloc]]]))],[
+                  [[int yynchar], [yynchar]],
+                  [[YYSTYPE const *yynlval], [yynlval]]
+		  b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]]))],[
 #ifdef YYPARSE_PARAM
 b4_c_function_def([yyparse], [int], [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])
 #else /* ! YYPARSE_PARAM */
@@ -1679,12 +1688,15 @@ typedef struct YYLTYPE
 #endif
 
 ]b4_push_if([struct ]b4_prefix[pstate;
-]b4_c_function_decl([]b4_prefix[pstate_init], [struct ]b4_prefix[pstate *], [[void], []])[
+]b4_c_function_decl([]b4_prefix[pstate_new], [struct ]b4_prefix[pstate *],
+                    [[void], []])[
+]b4_c_function_decl([]b4_prefix[pstate_delete], [void],
+                    [[struct ]b4_prefix[pstate *yyps],[yyps]])[
 ]b4_c_function_decl([]b4_prefix[push_parse], [int],
    [[struct ]b4_prefix[pstate *]b4_prefix[pstate], []b4_prefix[pstate]],
    [[int yynchar], [yynchar]],
-   [[YYSTYPE *yynlval], [yynlval]]
-   b4_locations_if([,[[YYLTYPE *yynlloc], [yynlloc]]]))[
+   [[YYSTYPE const *yynlval], [yynlval]]
+   b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]]))[
 enum { YYPUSH_MORE = 4 };])[
 ]b4_pure_if([],
 	   [extern YYLTYPE b4_prefix[]lloc;])
