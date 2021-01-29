@@ -612,8 +612,8 @@ union yyGLRStackItem {
 struct yyGLRStack {
   int yyerrflag;
   int yyerrState;
-]b4_location_if([[  /* To compute the location of the error token,  */
-  yyGLRStackItem yyerror_range[2];]])[
+]b4_location_if([[  /* To compute the location of the error token.  */
+  yyGLRStackItem yyerror_range[3];]])[
 ]b4_pure_if(
 [
   int yyerrcnt;
@@ -1722,7 +1722,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    while (yystack->yytops.yystates[0] != NULL)
 	      {
 		yyGLRState *yys = yystack->yytops.yystates[0];
-]b4_location_if([[		yystack->yyerror_range[0].yystate.yyloc = yys->yyloc;]])[
+]b4_location_if([[		yystack->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
 		yydestruct ("Error: popping",
                             yystos[yys->yylrState],
 			    &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
@@ -1737,8 +1737,10 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    /* We throw away the lookahead, but the error range
 	       of the shifted error token must take it into account. */
 	    yyGLRState *yys = yystack->yytops.yystates[0];
-	    yys->yyloc.last_line   = yyllocp->last_line;
-	    yys->yyloc.last_column = yyllocp->last_column;]])[
+	    yyGLRStackItem yyerror_range[3];
+	    yyerror_range[1].yystate.yyloc = yys->yyloc;
+	    yyerror_range[2].yystate.yyloc = *yyllocp;
+	    YYLLOC_DEFAULT (yys->yyloc, yyerror_range, 2);]])[
 	    yydestruct ("Error: discarding",
 			*yytokenp, yylvalp]b4_location_if([, yyllocp])[);
 	  }
@@ -1784,8 +1786,8 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    {
 	      /* Shift the error token having adjusted its location.  */
 	      YYLTYPE yyerrloc;]b4_location_if([[
-	      yystack->yyerror_range[1].yystate.yyloc = *yyllocp;
-	      YYLLOC_DEFAULT (yyerrloc, yystack->yyerror_range - 1, 2);]])[
+	      yystack->yyerror_range[2].yystate.yyloc = *yyllocp;
+	      YYLLOC_DEFAULT (yyerrloc, yystack->yyerror_range, 2);]])[
 	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
 			       yylvalp, &yyerrloc);
 	      yyglrShift (yystack, 0, yytable[yyj],
@@ -1794,7 +1796,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	      break;
 	    }
 	}
-]b4_location_if([[      yystack->yyerror_range[0].yystate.yyloc = yys->yyloc;]])[
+]b4_location_if([[      yystack->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
       yydestruct ("Error: popping",
 		  yystos[yys->yylrState],
 	          &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
@@ -1893,7 +1895,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	      yyrule = yydefaultAction (yystate);
 	      if (yyrule == 0)
 		{
-]b4_location_if([[		  yystack.yyerror_range[0].yystate.yyloc = *yyllocp;]])[
+]b4_location_if([[		  yystack.yyerror_range[1].yystate.yyloc = *yyllocp;]])[
 		  yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 		  goto yyuser_error;
 		}
@@ -1924,7 +1926,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		}
 	      else if (yyisErrorAction (yyaction))
 		{
-]b4_location_if([[		  yystack.yyerror_range[0].yystate.yyloc = *yyllocp;]])[
+]b4_location_if([[		  yystack.yyerror_range[1].yystate.yyloc = *yyllocp;]])[
 		  yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 		  goto yyuser_error;
 		}
@@ -1950,7 +1952,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		yyFail (&yystack][]b4_lpure_args[, "syntax error");
 	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
 	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
-]b4_location_if([[	      yystack.yyerror_range[0].yystate.yyloc = *yyllocp;]])[
+]b4_location_if([[	      yystack.yyerror_range[1].yystate.yyloc = *yyllocp;]])[
 	      yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 	      goto yyuser_error;
 	    }
