@@ -1048,7 +1048,8 @@ yygetLRActions (yyStateNum yystate, int yytoken,
 		int* yyaction, const short int** yyconflicts)
 {
   int yyindex = yypact[yystate] + yytoken;
-  if (yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
+  if (yyindex < 0 || YYLAST < yyindex
+      || (]b4_safest_int_type[)yycheck[yyindex] != yytoken)
     {
       *yyaction = -yydefact[yystate];
       *yyconflicts = yyconfl;
@@ -1070,7 +1071,8 @@ yyLRgotoState (yyStateNum yystate, yySymbol yylhs)
 {
   int yyr;
   yyr = yypgoto[yylhs - YYNTOKENS] + yystate;
-  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
+  if (0 <= yyr && yyr <= YYLAST
+      && (]b4_safest_int_type[)yycheck[yyr] == yystate)
     return yytable[yyr];
   else
     return yydefgoto[yylhs - YYNTOKENS];
@@ -2120,7 +2122,8 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	  yyfmt = yystpcpy (yyformat, yyunexpected);
 
 	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+	    if ((]b4_safest_int_type[)yycheck[yyx + yyn] == yyx
+                && yyx != YYTERROR)
 	      {
 		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
 		  {
@@ -2216,7 +2219,8 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	if (yyis_pact_ninf (yyj))
 	  return;
 	yyj += yytoken;
-	if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
+	if (yyj < 0 || YYLAST < yyj
+            || (]b4_safest_int_type[)yycheck[yyj] != yytoken)
 	  {
 	    if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
 	      return;
