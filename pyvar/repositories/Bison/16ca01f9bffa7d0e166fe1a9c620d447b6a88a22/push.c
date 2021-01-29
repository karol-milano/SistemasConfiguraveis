@@ -1685,6 +1685,10 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
+]b4_pure_if([],
+	   [extern YYLTYPE b4_prefix[]lloc;])
+)dnl b4_locations_if
+
 ]b4_push_if([struct ]b4_prefix[pstate;
 ]b4_c_function_decl([]b4_prefix[pstate_new], [struct ]b4_prefix[pstate *],
                     [[void], []])[
@@ -1696,9 +1700,6 @@ typedef struct YYLTYPE
    [[YYSTYPE const *yynlval], [yynlval]]
    b4_locations_if([,[[YYLTYPE const *yynlloc], [yynlloc]]]))[
 enum { YYPUSH_MORE = 4 };])[
-]b4_pure_if([],
-	   [extern YYLTYPE b4_prefix[]lloc;])
-)dnl b4_locations_if
 
 m4_ifdef([b4_provides],
 [[/* Copy the %provides blocks.  */
