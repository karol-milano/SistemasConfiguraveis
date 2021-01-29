@@ -86,6 +86,15 @@ m4_define([b4_int_type],
 					       [int])])
 
 
+# b4_safest_int_type
+# ------------------
+# The safest int type to cast to when it's necessary to compare a signed int
+# type against an int type set by b4_int_type.  Overwrite the version from
+# c.m4 as a reminder to keep it consistent with overwritten b4_int_type.
+m4_define([b4_safest_int_type],[int])
+
+
+
 ## ----------------- ##
 ## Semantic Values.  ##
 ## ----------------- ##
@@ -900,7 +909,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
       yyfmt = yystpcpy (yyformat, yyunexpected);
 
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+	if ((]b4_safest_int_type[)yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 	  {
 	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
 	      {
@@ -1205,7 +1214,7 @@ yybackup:
   /* If the proper action on seeing token YYTOKEN is to reduce or to
      detect an error, take that action.  */
   yyn += yytoken;
-  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
+  if (yyn < 0 || YYLAST < yyn || (]b4_safest_int_type[)yycheck[yyn] != yytoken)
     goto yydefault;
   yyn = yytable[yyn];
   if (yyn <= 0)
@@ -1285,7 +1294,8 @@ yyreduce:
   yyn = yyr1[yyn];
 
   yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
-  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
+  if (0 <= yystate && yystate <= YYLAST
+      && (]b4_safest_int_type[)yycheck[yystate] == *yyssp)
     yystate = yytable[yystate];
   else
     yystate = yydefgoto[yyn - YYNTOKENS];
