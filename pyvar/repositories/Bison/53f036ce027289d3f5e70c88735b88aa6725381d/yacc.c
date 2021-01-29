@@ -869,7 +869,8 @@ yysyntax_error (char *yyresult, int yystate, int yytoken)
       yyarg[yycount++] = yytname[yytoken];
 
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
+	    && !yyis_table_ninf (yytable[yyx + yyn]))
 	  {
 	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
 	      {
