@@ -1038,32 +1038,30 @@ yyerrlab:
 	{
 	  YYSIZE_T yysize = 0;
 	  int yytype = YYTRANSLATE (yychar);
+	  const char* yyprefix;
 	  char *yymsg;
 	  int yyx;
 
 	  /* Start YYX at -YYN if negative to avoid negative indexes in
 	     YYCHECK.  */
-	  int yyxbase = yyn < 0 ? -yyn : 0;
+	  int yyxbegin = yyn < 0 ? -yyn : 0;
 
 	  /* Stay within bounds of both yycheck and yytname.  */
 	  int yychecklim = YYLAST - yyn;
-	  int yynsyms = sizeof (yytname) / sizeof (yytname[0]);
-	  int yyxlim = yychecklim < yynsyms ? yychecklim : yynsyms;
+	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
 	  int yycount = 0;
 
-	  for (yyx = yyxbase; yyx < yyxlim; yyx++)
+	  yyprefix = ", expecting ";
+	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 	      {
-	        yysize += (! yycount
-			   ? sizeof (", expecting ") - 1
-			   : sizeof (" or ") - 1);
-		yysize += yystrlen (yytname[yyx]);
-		yycount++;
+		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
+		yycount += 1;
 		if (yycount == 5)
 		  {
 		    yysize = 0;
 		    break;
-		  }     	
+		  }
 	      }
 	  yysize += (sizeof ("syntax error, unexpected ")
 		     + yystrlen (yytname[yytype]));
@@ -1075,14 +1073,13 @@ yyerrlab:
 
 	      if (yycount < 5)
 		{
-		  yycount = 0;
-		  for (yyx = yyxbase; yyx < yyxlim; yyx++)
+		  yyprefix = ", expecting ";
+		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 		      {
-			const char *yyq = ! yycount ? ", expecting " : " or ";
-			yyp = yystpcpy (yyp, yyq);
+			yyp = yystpcpy (yyp, yyprefix);
 			yyp = yystpcpy (yyp, yytname[yyx]);
-			yycount++;
+			yyprefix = " or ";
 		      }
 		}
 	      yyerror (]b4_yyerror_args[yymsg);
