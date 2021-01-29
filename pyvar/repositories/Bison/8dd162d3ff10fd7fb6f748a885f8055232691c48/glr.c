@@ -60,7 +60,7 @@ m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 
 # b4_lyyerror_args
 # ----------------
-# Same as above, but on the lookahead, hence yyllocp instead of yylocp.
+# Same as above, but on the look-ahead, hence yyllocp instead of yylocp.
 m4_define([b4_lyyerror_args],
 [b4_pure_if([b4_location_if([yyllocp, ])])dnl
 m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
@@ -82,14 +82,14 @@ m4_define([b4_pure_formals],
 
 # b4_lpure_args
 # -------------
-# Same as above, but on the lookahead, hence yyllocp instead of yylocp.
+# Same as above, but on the look-ahead, hence yyllocp instead of yylocp.
 m4_define([b4_lpure_args],
 [b4_pure_if([b4_location_if([, yyllocp])])[]b4_user_args])
 
 
 # b4_lpure_formals
 # ----------------
-# Same as above, but on the lookahead, hence yyllocp instead of yylocp.
+# Same as above, but on the look-ahead, hence yyllocp instead of yylocp.
 m4_define([b4_lpure_formals],
 [b4_pure_if([b4_location_if([YYLTYPE *yyllocp])])[]b4_user_formals])
 
@@ -1686,7 +1686,7 @@ yyreportSyntaxError (yyGLRStack* yystack,
 
 /* Recover from a syntax error on YYSTACK, assuming that YYTOKENP,
    YYLVALP, and YYLLOCP point to the syntactic category, semantic
-   value, and location of the lookahead.  */
+   value, and location of the look-ahead.  */
 static void
 yyrecoverSyntaxError (yyGLRStack* yystack,
 		      YYSTYPE* yylvalp, YYLTYPE* yyllocp]b4_user_formals[)
