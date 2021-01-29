@@ -1578,11 +1578,11 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 
 	  if (yyisShiftAction (yyaction))
 	    {
-	      YYDPRINTF ((stderr, "Shifting token %s on stack %d, ",
-			  yytokenName (*yytokenp), yyk));
+	      YYDPRINTF ((stderr, "On stack %d, ", yyk));
+	      YY_SYMBOL_PRINT ("shifting", yytokenp, yylvalp, yyllocp);
 	      yyglrShift (yystack, yyk, yyaction, yyposn+1,
 			  *yylvalp, yyllocp]b4_user_args[);
-	      YYDPRINTF ((stderr, "which is now in state #%d\n",
+	      YYDPRINTF ((stderr, ", now in state #%d\n",
 			  yystack->yytops.yystates[yyk]->yylrState));
 	      break;
 	    }
@@ -1750,7 +1750,8 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	  if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
 	      && yyisShiftAction (yytable[yyj]))
 	    {
-	      YYDPRINTF ((stderr, "Shifting error token, "));
+	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
+			       yylvalp, yyllocp);
 	      yyglrShift (yystack, 0, yytable[yyj],
 			  yys->yyposn, *yylvalp, yyllocp]b4_user_args[);
 	      break;
@@ -1856,8 +1857,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 		break;
 	      if (yyisShiftAction (yyaction))
 		{
-		  YYDPRINTF ((stderr, "Shifting token %s, ",
-			      yytokenName (yytoken)));
+		  YY_SYMBOL_PRINT ("Shifting", yytoken, yylvalp, yyllocp);
 		  if (yytoken != YYEOF)
 		    yytoken = YYEMPTY;
 		  yyposn += 1;
