@@ -649,6 +649,9 @@ static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
      [[YYRLINE[YYN] -- Source line where rule number YYN was defined.]])[
 #endif
 
+/** Accessing symbol of state STATE.  */
+#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_type_t, yystos[State])
+
 #if ]b4_parse_error_case([simple], [b4_api_PREFIX[DEBUG || ]b4_token_table_flag], [[1]])[
 /* The user-facing name of the symbol whose (internal) number is
    YYSYMBOL.  No bounds checking.  */
@@ -819,7 +822,7 @@ yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,]b4_locations_if([[ YYLTYPE *
     {
       YYFPRINTF (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr,
-                       yystos[+yyssp[yyi + 1 - yynrhs]],
+                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                        &]b4_rhs_value(yynrhs, yyi + 1)[
                        ]b4_locations_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
                        b4_user_args[);
@@ -1866,7 +1869,7 @@ yyreduce:
      case of YYERROR or YYBACKUP, subsequent parser actions might lead
      to an incorrect destructor call or verbose syntax error message
      before the lookahead is translated.  */
-  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
+  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_type_t, yyr1[yyn]), &yyval, &yyloc);
 
   YYPOPSTACK (yylen);
   yylen = 0;
@@ -2018,7 +2021,7 @@ yyerrlab1:
 
 ]b4_locations_if([[      yyerror_range[1] = *yylsp;]])[
       yydestruct ("Error: popping",
-                  yystos[yystate], yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
+                  YY_ACCESSING_SYMBOL (yystate), yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
       YYPOPSTACK (1);
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
@@ -2039,7 +2042,7 @@ yyerrlab1:
   *++yylsp = yyloc;]])[
 
   /* Shift the error token.  */
-  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);
+  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);
 
   yystate = yyn;
   goto yynewstate;
@@ -2091,7 +2094,7 @@ yyreturn:
   while (yyssp != yyss)
     {
       yydestruct ("Cleanup: popping",
-                  yystos[+*yyssp], yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
+                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
       YYPOPSTACK (1);
     }
 #ifndef yyoverflow
