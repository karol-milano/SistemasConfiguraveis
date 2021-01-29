@@ -1039,17 +1039,34 @@ yyerrlab:
 	  YYSIZE_T yysize = 0;
 	  int yytype = YYTRANSLATE (yychar);
 	  char *yymsg;
-	  int yyx, yycount;
+	  int yyx;
 
-	  yycount = 0;
 	  /* Start YYX at -YYN if negative to avoid negative indexes in
 	     YYCHECK.  */
-	  for (yyx = yyn < 0 ? -yyn : 0;
-	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
+	  int yyxbase = yyn < 0 ? -yyn : 0;
+
+	  /* Stay within bounds of both yycheck and yytname.  */
+	  int yychecklim = YYLAST - yyn;
+	  int yynsyms = sizeof (yytname) / sizeof (yytname[0]);
+	  int yyxlim = yychecklim < yynsyms ? yychecklim : yynsyms;
+	  int yycount = 0;
+
+	  for (yyx = yyxbase; yyx < yyxlim; yyx++)
 	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
-	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
-	  yysize += yystrlen ("syntax error, unexpected ") + 1;
-	  yysize += yystrlen (yytname[yytype]);
+	      {
+	        yysize += (! yycount
+			   ? sizeof (", expecting ") - 1
+			   : sizeof (" or ") - 1);
+		yysize += yystrlen (yytname[yyx]);
+		yycount++;
+		if (yycount == 5)
+		  {
+		    yysize = 0;
+		    break;
+		  }     	
+	      }
+	  yysize += (sizeof ("syntax error, unexpected ")
+		     + yystrlen (yytname[yytype]));
 	  yymsg = (char *) YYSTACK_ALLOC (yysize);
 	  if (yymsg != 0)
 	    {
@@ -1059,9 +1076,7 @@ yyerrlab:
 	      if (yycount < 5)
 		{
 		  yycount = 0;
-		  for (yyx = yyn < 0 ? -yyn : 0;
-		       yyx < (int) (sizeof (yytname) / sizeof (char *));
-		       yyx++)
+		  for (yyx = yyxbase; yyx < yyxlim; yyx++)
 		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 		      {
 			const char *yyq = ! yycount ? ", expecting " : " or ";
