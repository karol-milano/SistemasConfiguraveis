@@ -297,8 +297,6 @@ static const char *const yytname[] =
 {
   ]b4_tname[
 };
-
-#define yytname_size ((int) (sizeof (yytname) / sizeof (yytname[0])))
 #endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
@@ -1598,45 +1596,66 @@ yyreportSyntaxError (yyGLRStack* yystack,
     {
 #if YYERROR_VERBOSE
       yySymbol* const yytokenp = yystack->yytokenp;
-      int yyn, yyx, yycount;
-      size_t yysize;
+      int yyn;
       const char* yyprefix;
-      char* yyp;
-      char* yymsg;
       yyn = yypact[yystack->yytops.yystates[0]->yylrState];
       if (YYPACT_NINF < yyn && yyn < YYLAST)
 	{
-	  yycount = 0;
+	  size_t yysize = 0;
+	  char* yymsg;
+	  int yyx;
+
 	  /* Start YYX at -YYN if negative to avoid negative indexes in
 	     YYCHECK.  */
-	  yysize = sizeof ("syntax error, unexpected ")
-	    + strlen (yytokenName (*yytokenp));
+	  int yyxbase = yyn < 0 ? -yyn : 0;
+
+	  /* Stay within bounds of both yycheck and yytname.  */
+	  int yychecklim = YYLAST - yyn;
+	  int yynsyms = sizeof (yytname) / sizeof (yytname[0]);
+	  int yyxlim = yychecklim < yynsyms ? yychecklim : yynsyms;
+	  int yycount = 0;
+
 	  yyprefix = ", expecting ";
-	  for (yyx = yyn < 0 ? -yyn : 0; yyx < yytname_size && yycount <= 5;
-	       yyx += 1)
+	  for (yyx = yyxbase; yyx < yyxlim && yycount < 5; yyx += 1)
 	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
-	      yysize += strlen (yytokenName (yyx)) + strlen (yyprefix),
-		yycount += 1, yyprefix = " or ";
-	  yymsg = yyp = (char*) malloc (yysize);
-	  sprintf (yyp, "syntax error, unexpected %s",
-		   yytokenName (*yytokenp));
-	  yyp += strlen (yyp);
-	  if (yycount < 5)
-	    {
-	      yyprefix = ", expecting ";
-	      for (yyx = yyn < 0 ? -yyn : 0; yyx < yytname_size; yyx += 1)
-		if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+	      {
+		yysize += strlen (yytokenName (yyx)) + strlen (yyprefix);
+		yycount += 1;
+		if (yycount == 5)
 		  {
-		    sprintf (yyp, "%s%s", yyprefix, yytokenName (yyx));
-		    yyp += strlen (yyp);
-		    yyprefix = " or ";
+		    yysize = 0;
+		    break;
 		  }
+		yyprefix = " or ";
+	      }
+	  yysize += (sizeof ("syntax error, unexpected ")
+		     + strlen (yytokenName (*yytokenp)));
+	  yymsg = (char*) malloc (yysize);
+	  if (yymsg != 0)
+	    {
+	      char* yyp = yymsg;
+	      sprintf (yyp, "syntax error, unexpected %s",
+		       yytokenName (*yytokenp));
+	      yyp += strlen (yyp);
+	      if (yycount < 5)
+		{
+		  yyprefix = ", expecting ";
+		  for (yyx = yyxbase; yyx < yyxlim; yyx += 1)
+		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+		      {
+			sprintf (yyp, "%s%s", yyprefix, yytokenName (yyx));
+			yyp += strlen (yyp);
+			yyprefix = " or ";
+		      }
+		}
+	      yyerror (]b4_lyyerror_args[yymsg);
+	      free (yymsg);
 	    }
-	  yyerror (]b4_lyyerror_args[yymsg);
-	  free (yymsg);
+	  else
+	    yyerror (]b4_lyyerror_args["syntax error; also virtual memory exhausted");
 	}
       else
-#endif
+#endif /* YYERROR_VERBOSE */
 	yyerror (]b4_lyyerror_args["syntax error");
       yynerrs += 1;
     }
