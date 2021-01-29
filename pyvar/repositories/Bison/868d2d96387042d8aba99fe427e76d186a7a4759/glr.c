@@ -2261,7 +2261,8 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	    }
 	}
 ]b4_locations_if([[      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
-      yydestroyGLRState ("Error: popping", yys]b4_user_args[);
+      if (yys->yypred != NULL)
+	yydestroyGLRState ("Error: popping", yys]b4_user_args[);
       yystackp->yytops.yystates[0] = yys->yypred;
       yystackp->yynextFree -= 1;
       yystackp->yyspaceLeft += 1;
@@ -2373,8 +2374,7 @@ m4_popdef([b4_at_dollar])])dnl
 	      if (yyisShiftAction (yyaction))
 		{
 		  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
-		  if (yychar != YYEOF)
-		    yychar = YYEMPTY;
+		  yychar = YYEMPTY;
 		  yyposn += 1;
 		  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
 		  if (0 < yystack.yyerrState)
@@ -2490,7 +2490,7 @@ m4_popdef([b4_at_dollar])])dnl
   goto yyreturn;
 
  yyreturn:
-  if (yychar != YYEOF && yychar != YYEMPTY)
+  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
 		YYTRANSLATE (yychar),
 		&yylval]b4_locations_if([, &yylloc])[]b4_user_args[);
@@ -2512,7 +2512,8 @@ m4_popdef([b4_at_dollar])])dnl
 		  {
 		    yyGLRState *yys = yystates[yyk];
 ]b4_locations_if([[		    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
-)[		    yydestroyGLRState ("Cleanup: popping", yys]b4_user_args[);
+)[		    if (yys->yypred != NULL)
+		      yydestroyGLRState ("Cleanup: popping", yys]b4_user_args[);
 		    yystates[yyk] = yys->yypred;
 		    yystack.yynextFree -= 1;
 		    yystack.yyspaceLeft += 1;
