@@ -847,7 +847,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 {
   int yyn = yypact[yystate];
 
-  if (! (YYPACT_NINF < yyn && yyn < YYLAST))
+  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
     return 0;
   else
     {
@@ -885,7 +885,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       int yyxbegin = yyn < 0 ? -yyn : 0;
 
       /* Stay within bounds of both yycheck and yytname.  */
-      int yychecklim = YYLAST - yyn;
+      int yychecklim = YYLAST - yyn + 1;
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
       int yycount = 1;
 
