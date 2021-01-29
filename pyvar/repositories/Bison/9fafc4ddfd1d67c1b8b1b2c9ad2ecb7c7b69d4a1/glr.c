@@ -424,24 +424,25 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
    the previous symbol: RHS[0] (always defined).  */
 
 ]b4_location_if([[
+#define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN)				\
-do {									\
-  if (YYN)								\
-    {									\
-      (yyCurrent).first_line   = YYRHSLOC(yyRhs, 1).first_line;		\
-      (yyCurrent).first_column = YYRHSLOC(yyRhs, 1).first_column;	\
-      (yyCurrent).last_line    = YYRHSLOC(yyRhs, YYN).last_line;	\
-      (yyCurrent).last_column  = YYRHSLOC(yyRhs, YYN).last_column;	\
-    }									\
-  else									\
-    {									\
-      (yyCurrent).first_line   = YYRHSLOC(yyRhs, 0).last_line;		\
-      (yyCurrent).first_column = YYRHSLOC(yyRhs, 0).last_column;	\
-      (yyCurrent).last_line    = YYRHSLOC(yyRhs, 0).last_line;		\
-      (yyCurrent).last_column  = YYRHSLOC(yyRhs, 0).last_column;	\
-    }									\
-} while(0)
+# define YYLLOC_DEFAULT(Current, Rhs, N)				\
+    do									\
+      if (N)								\
+	{								\
+	  (Current).first_line   = YYRHSLOC(Rhs, 1).first_line;		\
+	  (Current).first_column = YYRHSLOC(Rhs, 1).first_column;	\
+	  (Current).last_line    = YYRHSLOC(Rhs, N).last_line;		\
+	  (Current).last_column  = YYRHSLOC(Rhs, N).last_column;	\
+	}								\
+      else								\
+	{								\
+	  (Current).first_line   = (Current).last_line   =		\
+	    YYRHSLOC(Rhs, 0).last_line;					\
+	  (Current).first_column = (Current).last_column =		\
+	    YYRHSLOC(Rhs, 0).last_column;				\
+	}								\
+    while (0)
 
 /* YY_LOCATION_PRINT -- Print the location on the stream.
    This macro was not mandated originally: define only if we know
@@ -454,7 +455,7 @@ do {									\
 #endif
 ]],[
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN) ((void) 0)
+# define YYLLOC_DEFAULT(Current, Rhs, N) ((void) 0)
 #endif
 ])[
 
@@ -612,7 +613,7 @@ struct yyGLRStack {
   int yyerrflag;
   int yyerrState;
 ]b4_location_if([[  /* To compute the location of the error token,  */
-  YYLTYPE yyerror_range[2];]])[
+  yyGLRStackItem yyerror_range[2];]])[
 ]b4_pure_if(
 [
   int yyerrcnt;
@@ -736,9 +737,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
     *yyvalp = yyval_default;
   else
     *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
-# define YYRHSLOC(yyRhs,YYK) ((yyRhs)[YYK].yystate.yyloc)
   YYLLOC_DEFAULT (*yylocp, yyvsp - yyrhslen, yyrhslen);
-# undef YYRHSLOC
 ]
   switch (yyn)
     {
@@ -1723,7 +1722,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    while (yystack->yytops.yystates[0] != NULL)
 	      {
 		yyGLRState *yys = yystack->yytops.yystates[0];
-]b4_location_if([[		yystack->yyerror_range[0] = yys->yyloc;]])[
+]b4_location_if([[		yystack->yyerror_range[0].yystate.yyloc = yys->yyloc;]])[
 		yydestruct ("Error: popping",
                             yystos[yys->yylrState],
 			    &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
@@ -1785,10 +1784,8 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    {
 	      /* Shift the error token having adjusted its location.  */
 	      YYLTYPE yyerrloc;]b4_location_if([[
-	      yystack->yyerror_range[1] = *yyllocp;
-#             define YYRHSLOC(yyRhs,YYK) ((yyRhs)[YYK])
-	      YYLLOC_DEFAULT (yyerrloc, yystack->yyerror_range - 1, 2);
-#             undef YYRHSLOC]])[
+	      yystack->yyerror_range[1].yystate.yyloc = *yyllocp;
+	      YYLLOC_DEFAULT (yyerrloc, yystack->yyerror_range - 1, 2);]])[
 	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
 			       yylvalp, &yyerrloc);
 	      yyglrShift (yystack, 0, yytable[yyj],
@@ -1797,7 +1794,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	      break;
 	    }
 	}
-]b4_location_if([[      yystack->yyerror_range[0] = yys->yyloc;]])[
+]b4_location_if([[      yystack->yyerror_range[0].yystate.yyloc = yys->yyloc;]])[
       yydestruct ("Error: popping",
 		  yystos[yys->yylrState],
 	          &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
@@ -1896,7 +1893,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	      yyrule = yydefaultAction (yystate);
 	      if (yyrule == 0)
 		{
-]b4_location_if([[		  yystack.yyerror_range[0] = *yyllocp;]])[
+]b4_location_if([[		  yystack.yyerror_range[0].yystate.yyloc = *yyllocp;]])[
 		  yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 		  goto yyuser_error;
 		}
@@ -1927,7 +1924,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		}
 	      else if (yyisErrorAction (yyaction))
 		{
-]b4_location_if([[		  yystack.yyerror_range[0] = *yyllocp;]])[
+]b4_location_if([[		  yystack.yyerror_range[0].yystate.yyloc = *yyllocp;]])[
 		  yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 		  goto yyuser_error;
 		}
@@ -1953,7 +1950,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		yyFail (&yystack][]b4_lpure_args[, "syntax error");
 	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
 	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
-]b4_location_if([[	      yystack.yyerror_range[0] = *yyllocp;]])[
+]b4_location_if([[	      yystack.yyerror_range[0].yystate.yyloc = *yyllocp;]])[
 	      yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 	      goto yyuser_error;
 	    }
