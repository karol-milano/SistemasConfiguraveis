@@ -1552,15 +1552,17 @@ yyreportParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	      yysize += strlen (yytokenName (yyx)) + strlen (yyprefix),
 		yycount += 1, yyprefix = " or ";
 	  yymsg = yyp = (char*) malloc (yysize);
-	  yyp += sprintf (yyp, "parse error, unexpected %s",
-			  yytokenName (*yytokenp));
+	  sprintf (yyp, "parse error, unexpected %s",
+		   yytokenName (*yytokenp));
+	  yyp += strlen (yyp);
 	  if (yycount < 5)
 	    {
 	      yyprefix = ", expecting ";
 	      for (yyx = yyn < 0 ? -yyn : 0; yyx < yytname_size; yyx += 1)
 		if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 		  {
-		    yyp += sprintf (yyp, "%s%s", yyprefix, yytokenName (yyx));
+		    sprintf (yyp, "%s%s", yyprefix, yytokenName (yyx));
+		    yyp += strlen (yyp);
 		    yyprefix = " or ";
 		  }
 	    }
