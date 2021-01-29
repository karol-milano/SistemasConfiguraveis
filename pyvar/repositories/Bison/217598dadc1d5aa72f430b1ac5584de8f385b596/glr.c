@@ -1512,7 +1512,7 @@ yyreportParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	  yyprefix = ", expecting ";
 	  for (yyx = yyn < 0 ? -yyn : 0; yyx < yytname_size && yycount <= 5;
 	       yyx += 1)
-	    if (yycheck[yyx + yyn] == yyx)
+	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 	      yysize += strlen (yytokenName (yyx)) + strlen (yyprefix),
 		yycount += 1, yyprefix = " or ";
 	  yymsg = yyp = (char*) malloc (yysize);
