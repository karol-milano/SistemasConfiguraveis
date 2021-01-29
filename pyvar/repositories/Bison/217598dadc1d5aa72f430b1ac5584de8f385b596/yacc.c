@@ -667,7 +667,7 @@ b4_c_function([yyreport_parse_error],
 	 YYCHECK.  */
       for (yyx = yyn < 0 ? -yyn : 0;
 	   yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
-	if (yycheck[yyx + yyn] == yyx)
+	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 	  yysize += yystrlen (yytname[yyx]) + 15, yycount++;
       yysize += yystrlen ("parse error, unexpected ") + 1;
       yysize += yystrlen (yytname[yytype]);
@@ -683,7 +683,7 @@ b4_c_function([yyreport_parse_error],
 	      for (yyx = yyn < 0 ? -yyn : 0;
 		   yyx < (int) (sizeof (yytname) / sizeof (char *));
 		   yyx++)
-		if (yycheck[yyx + yyn] == yyx)
+		if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 		  {
 		    const char *yyq = ! yycount ? ", expecting " : " or ";
 		    yyp = yystpcpy (yyp, yyq);
