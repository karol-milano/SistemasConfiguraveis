@@ -956,14 +956,14 @@ yytnamerr (char *yyres, const char *yystr)
 # endif
 
 /* Copy into YYRESULT an error message about the unexpected token
-   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
+   YYTOKEN while in state YYSTATE.  Return the number of bytes copied,
    including the terminating null byte.  If YYRESULT is null, do not
    copy anything; just return the number of bytes that would be
    copied.  As a special case, return 0 if an ordinary "syntax error"
    message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
    size calculation.  */
 static YYSIZE_T
-yysyntax_error (char *yyresult, int yystate, int yychar)
+yysyntax_error (char *yyresult, int yystate, int yytoken)
 {
   int yyn = yypact[yystate];
 
@@ -971,8 +971,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
     return 0;
   else
     {
-      int yytype = YYTRANSLATE (yychar);
-      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
+      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
       YYSIZE_T yysize = yysize0;
       YYSIZE_T yysize1;
       int yysize_overflow = 0;
@@ -995,7 +994,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       int yycount = 0;
       int yyx;
 
-      yyarg[yycount++] = yytname[yytype];
+      yyarg[yycount++] = yytname[yytoken];
 
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
@@ -1499,7 +1498,7 @@ yyerrlab:
       yyerror (]b4_yyerror_args[YY_("syntax error"));
 #else
       {
-	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
+	YYSIZE_T yysize = yysyntax_error (0, yystate, yytoken);
 	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
 	  {
 	    YYSIZE_T yyalloc = 2 * yysize;
@@ -1519,7 +1518,7 @@ yyerrlab:
 
 	if (0 < yysize && yysize <= yymsg_alloc)
 	  {
-	    (void) yysyntax_error (yymsg, yystate, yychar);
+	    (void) yysyntax_error (yymsg, yystate, yytoken);
 	    yyerror (]b4_yyerror_args[yymsg);
 	  }
 	else
