@@ -67,7 +67,7 @@ m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 
 # b4_lyyerror_args
 # ----------------
-# Same as above, but on the look-ahead, hence &yylloc instead of yylocp.
+# Same as above, but on the lookahead, hence &yylloc instead of yylocp.
 m4_define([b4_lyyerror_args],
 [b4_pure_if([b4_locations_if([&yylloc, ])])dnl
 m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
@@ -82,7 +82,7 @@ m4_define([b4_pure_args],
 
 # b4_lpure_args
 # -------------
-# Same as above, but on the look-ahead, hence &yylloc instead of yylocp.
+# Same as above, but on the lookahead, hence &yylloc instead of yylocp.
 m4_define([b4_lpure_args],
 [b4_pure_if([b4_locations_if([, &yylloc])])[]b4_user_args])
 
@@ -2178,7 +2178,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 
 /* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
    yylval, and yylloc are the syntactic category, semantic value, and location
-   of the look-ahead.  */
+   of the lookahead.  */
 /*ARGSUSED*/ static void
 yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 {
