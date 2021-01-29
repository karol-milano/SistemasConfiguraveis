@@ -360,7 +360,7 @@ static const ]b4_int_type_for([b4_pgoto])[ yypgoto[] =
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
-   If YYTABLE_NINF, parse error.  */
+   If YYTABLE_NINF, syntax error.  */
 #define YYTABLE_NINF ]b4_table_ninf[
 static const ]b4_int_type_for([b4_table])[ yytable[] =
 {
@@ -866,8 +866,7 @@ yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[)
   size_t yyn;
   yysize = yystack->yynextFree - yystack->yyitems;
   if (YYMAXDEPTH <= yysize)
-    yyFail (yystack][]b4_pure_args[,
-	    "parsing stack overflow (%d items)", yysize);
+    yyFail (yystack][]b4_pure_args[, "parser stack overflow");
   yynewSize = 2*yysize;
   if (YYMAXDEPTH < yynewSize)
     yynewSize = YYMAXDEPTH;
@@ -914,8 +913,7 @@ yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[)
 
 #else
 
-  yyFail (yystack][]b4_lpure_args[,
-          "parsing stack overflow (%d items)", yysize);
+  yyFail (yystack][]b4_lpure_args[, "parser stack overflow");
 #endif
 }
 
@@ -1596,7 +1594,7 @@ yyreportParseError (yyGLRStack* yystack,
 	  yycount = 0;
 	  /* Start YYX at -YYN if negative to avoid negative indexes in
 	     YYCHECK.  */
-	  yysize = sizeof ("parse error, unexpected ")
+	  yysize = sizeof ("syntax error, unexpected ")
 	    + strlen (yytokenName (*yytokenp));
 	  yyprefix = ", expecting ";
 	  for (yyx = yyn < 0 ? -yyn : 0; yyx < yytname_size && yycount <= 5;
@@ -1605,7 +1603,8 @@ yyreportParseError (yyGLRStack* yystack,
 	      yysize += strlen (yytokenName (yyx)) + strlen (yyprefix),
 		yycount += 1, yyprefix = " or ";
 	  yymsg = yyp = (char*) malloc (yysize);
-	  sprintf (yyp, "parse error, unexpected %s", yytokenName (*yytokenp));
+	  sprintf (yyp, "syntax error, unexpected %s",
+		   yytokenName (*yytokenp));
 	  yyp += strlen (yyp);
 	  if (yycount < 5)
 	    {
@@ -1623,7 +1622,7 @@ yyreportParseError (yyGLRStack* yystack,
 	}
       else
 #endif
-	yyerror (]b4_lyyerror_args["parse error");
+	yyerror (]b4_lyyerror_args["syntax error");
       yynerrs += 1;
     }
 }
@@ -1855,7 +1854,7 @@ yyrecoverParseError (yyGLRStack* yystack,
 	    {
 	      yyundeleteLastStack (&yystack);
 	      if (yystack.yytops.yysize == 0)
-		yyFail (&yystack][]b4_lpure_args[, "parse error");
+		yyFail (&yystack][]b4_lpure_args[, "syntax error");
 	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
 	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
 	      yyreportParseError (&yystack, yylvalp, yyllocp]b4_user_args[);
