@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 1.875a.  */
+/* A Bison parser, made by GNU Bison 1.875b.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.
@@ -654,7 +654,14 @@ static const unsigned char yystos[] =
 
 #define YYACCEPT	goto yyacceptlab
 #define YYABORT		goto yyabortlab
-#define YYERROR		goto yyerrlab1
+#define YYERROR		do				\
+			  {				\
+			    yylerrsp = yylsp;		\
+			    *++yylerrsp = yyloc;	\
+			    goto yyerrlab1;		\
+			  }				\
+			while (0)
+
 
 /* Like YYERROR except do call yyerror.  This remains here temporarily
    to ease the transition to the new meaning of YYERROR, for GCC.
@@ -776,9 +783,9 @@ yy_reduce_print (yyrule)
 #endif
 {
   int yyi;
-  unsigned int yylineno = yyrline[yyrule];
+  unsigned int yylno = yyrline[yyrule];
   YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
-             yyrule - 1, yylineno);
+             yyrule - 1, yylno);
   /* Print the symbols being reduced, and their result.  */
   for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
     YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
@@ -1610,8 +1617,8 @@ yyreduce:
 
     }
 
-/* Line 991 of yacc.c.  */
-#line 1615 "parse-gram.c"
+/* Line 999 of yacc.c.  */
+#line 1622 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1653,17 +1660,34 @@ yyerrlab:
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
@@ -1673,9 +1697,7 @@ yyerrlab:
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
@@ -1725,33 +1747,13 @@ yyerrlab:
 
   /* Else will try to reuse lookahead token after shifting the error
      token.  */
-  goto yyerrlab2;
+  goto yyerrlab1;
 
 
 /*----------------------------------------------------.
 | yyerrlab1 -- error raised explicitly by an action.  |
 `----------------------------------------------------*/
 yyerrlab1:
-
-  /* Suppress GCC warning that yyerrlab1 is unused when no action
-     invokes YYERROR.  MacOS 10.2.3's buggy "smart preprocessor"
-     insists on the trailing semicolon.  */
-#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
-  /* GNU C++ (as of version 3.2.1) does not allow attributes on labels.  */
-# ifndef __cplusplus
-  __attribute__ ((__unused__));
-# endif
-#endif
-
-  yylerrsp = yylsp;
-  *++yylerrsp = yyloc;
-  goto yyerrlab2;
-
-
-/*---------------------------------------------------------------.
-| yyerrlab2 -- pop states until the error token can be shifted.  |
-`---------------------------------------------------------------*/
-yyerrlab2:
   yyerrstatus = 3;	/* Each real token shifted decrements this.  */
 
   for (;;)
