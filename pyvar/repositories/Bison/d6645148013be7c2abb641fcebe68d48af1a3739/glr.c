@@ -2077,7 +2077,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 #if YYERROR_VERBOSE
       int yyn;
       yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
-      if (YYPACT_NINF < yyn && yyn < YYLAST)
+      if (YYPACT_NINF < yyn && yyn <= YYLAST)
 	{
 	  yySymbol yytoken = YYTRANSLATE (yychar);
 	  size_t yysize0 = yytnamerr (NULL, yytokenName (yytoken));
@@ -2104,7 +2104,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	  int yyxbegin = yyn < 0 ? -yyn : 0;
 
 	  /* Stay within bounds of both yycheck and yytname.  */
-	  int yychecklim = YYLAST - yyn;
+	  int yychecklim = YYLAST - yyn + 1;
 	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
 	  int yycount = 1;
 
