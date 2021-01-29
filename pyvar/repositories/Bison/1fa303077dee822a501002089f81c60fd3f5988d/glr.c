@@ -2128,7 +2128,8 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	  yyfmt = yystpcpy (yyformat, yyunexpected);
 
 	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
+		&& !yyis_table_ninf (yytable[yyx + yyn]))
 	      {
 		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
 		  {
