@@ -1596,6 +1596,7 @@ yysetstate:
   YY_IGNORE_USELESS_CAST_BEGIN
   *yyssp = YY_CAST (yy_state_t, yystate);
   YY_IGNORE_USELESS_CAST_END
+  YY_STACK_PRINT (yyss, yyssp);
 
   if (yyss + yystacksize - 1 <= yyssp)
 #if !defined yyoverflow && !defined YYSTACK_RELOCATE
