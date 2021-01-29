@@ -54,7 +54,7 @@ m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 
 # b4_lex_param
 # ------------
-# Accumule in b4_lex_param all the yylex arguments.
+# Accumulate in b4_lex_param all the yylex arguments.
 # b4_lex_param arrives quoted twice, but we want to keep only one level.
 m4_define([b4_lex_param],
 m4_dquote(b4_pure_if([[[[YYSTYPE *]], [[&yylval]]][]dnl
@@ -767,7 +767,8 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 [[  /* The location stack.  */
   YYLTYPE yylsa[YYINITDEPTH];
   YYLTYPE *yyls = yylsa;
-  YYLTYPE *yylsp;]])[
+  YYLTYPE *yylsp;
+  YYLTYPE *yylerrsp;]])[
 
 #define YYPOPSTACK   (yyvsp--, yyssp--]b4_location_if([, yylsp--])[)
 
@@ -1072,6 +1073,8 @@ yyerrlab:
 	yyerror (]b4_yyerror_args["syntax error");
     }
 
+]b4_location_if([  yylerrsp = yylsp;])[
+
   if (yyerrstatus == 3)
     {
       /* If just tried and failed to reuse lookahead token after an
@@ -1095,17 +1098,34 @@ yyerrlab:
       YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
       yydestruct (yytoken, &yylval]b4_location_if([, &yylloc])[);
       yychar = YYEMPTY;
+]b4_location_if([      *++yylerrsp = yylloc;])[
     }
 
   /* Else will try to reuse lookahead token after shifting the error
      token.  */
-  goto yyerrlab1;
+  goto yyerrlab2;
 
 
 /*----------------------------------------------------.
 | yyerrlab1 -- error raised explicitly by an action.  |
 `----------------------------------------------------*/
 yyerrlab1:
+
+  /* Suppress GCC warning that yyerrlab1 is unused when no action
+     invokes YYERROR.  */
+#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
+  __attribute__ ((__unused__))
+#endif
+
+]b4_location_if([  yylerrsp = yylsp;
+  *++yylerrsp = yyloc;])[
+  goto yyerrlab2;
+
+
+/*---------------------------------------------------------------.
+| yyerrlab2 -- pop states until the error token can be shifted.  |
+`---------------------------------------------------------------*/
+yyerrlab2:
   yyerrstatus = 3;	/* Each real token shifted decrements this.  */
 
   for (;;)
@@ -1140,7 +1160,8 @@ yyerrlab1:
   YYDPRINTF ((stderr, "Shifting error token, "));
 
   *++yyvsp = yylval;
-]b4_location_if([  *++yylsp = yylloc;])[
+]b4_location_if([  YYLLOC_DEFAULT (yyloc, yylsp, (yylerrsp - yylsp));
+  *++yylsp = yyloc;])[
 
   yystate = yyn;
   goto yynewstate;
