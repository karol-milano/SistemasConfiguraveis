@@ -92,13 +92,6 @@ m4_define([b4_pure_formals],
 [b4_pure_if([b4_location_if([, YYLTYPE *yylocp])])[]b4_user_formals])
 
 
-# b4_lpure_formals
-# ----------------
-# Same as above, but on the look-ahead, hence yyllocp instead of yylocp.
-m4_define([b4_lpure_formals],
-[b4_pure_if([b4_location_if([YYLTYPE *yyllocp])])[]b4_user_formals])
-
-
 ## ----------------- ##
 ## Semantic Values.  ##
 ## ----------------- ##
@@ -495,7 +488,7 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 #ifndef YYLLOC_DEFAULT
 # define YYLLOC_DEFAULT(Current, Rhs, N)				\
     do									\
-      if (YYID (N))                                                    \
+      if (YYID (N))							\
 	{								\
 	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
 	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
@@ -584,8 +577,8 @@ do {									    \
   if (yydebug)								    \
     {									    \
       YYFPRINTF (stderr, "%s ", Title);					    \
-      yy_symbol_print (stderr,						    \
-		  Type, Value]b4_location_if([, Location])[]b4_user_args[); \
+      yy_symbol_print (stderr, Type,					    \
+		       Value]b4_location_if([, Location])[]b4_user_args[);  \
       YYFPRINTF (stderr, "\n");						    \
     }									    \
 } while (YYID (0))
@@ -977,7 +970,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 	{
 	  YYFPRINTF (stderr, "%s unresolved ", yymsg);
 	  yy_symbol_print (stderr, yystos[yys->yylrState],
-		      &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[]b4_user_args[);
+			   &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[]b4_user_args[);
 	  YYFPRINTF (stderr, "\n");
 	}
 #endif
@@ -1851,7 +1844,7 @@ yycompressStack (yyGLRStack* yystackp)
 
 static YYRESULTTAG
 yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
-                  size_t yyposn]b4_pure_formals[)
+		   size_t yyposn]b4_pure_formals[)
 {
   int yyaction;
   const short int* yyconflicts;
@@ -1885,7 +1878,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 	      YYDPRINTF ((stderr, "Reading a token: "));
 	      yychar = YYLEX;
 	      *yytokenp = YYTRANSLATE (yychar);
-             YY_SYMBOL_PRINT ("Next token is", *yytokenp, &yylval, &yylloc);
+	      YY_SYMBOL_PRINT ("Next token is", *yytokenp, &yylval, &yylloc);
 	    }
 	  yygetLRActions (yystate, *yytokenp, &yyaction, &yyconflicts);
 
@@ -1897,8 +1890,8 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 			  (unsigned long int) yyk));
 	      YYCHK (yyglrReduce (yystackp, yynewStack,
 				  *yyconflicts, yyfalse]b4_user_args[));
-             YYCHK (yyprocessOneStack (yystackp, yynewStack,
-                                       yyposn]b4_pure_args[));
+	      YYCHK (yyprocessOneStack (yystackp, yynewStack,
+					yyposn]b4_pure_args[));
 	      yyconflicts += 1;
 	    }
 
@@ -1912,8 +1905,8 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 	      break;
 	    }
 	  else
-           YYCHK (yyglrReduce (yystackp, yyk, -yyaction,
-                               yyfalse]b4_user_args[));
+	    YYCHK (yyglrReduce (yystackp, yyk, -yyaction,
+				yyfalse]b4_user_args[));
 	}
     }
   return yyok;
@@ -2044,15 +2037,15 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	    yyGLRState *yys = yystackp->yytops.yystates[0];
 	    yyGLRStackItem yyerror_range[3];
 	    yyerror_range[1].yystate.yyloc = yys->yyloc;
-           yyerror_range[2].yystate.yyloc = yylloc;
+	    yyerror_range[2].yystate.yyloc = yylloc;
 	    YYLLOC_DEFAULT (yys->yyloc, yyerror_range, 2);]])[
 	    yydestruct ("Error: discarding",
-                       *yytokenp, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
+			*yytokenp, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
 	  }
 	YYDPRINTF ((stderr, "Reading a token: "));
 	yychar = YYLEX;
 	*yytokenp = YYTRANSLATE (yychar);
-       YY_SYMBOL_PRINT ("Next token is", *yytokenp, &yylval, &yylloc);
+	YY_SYMBOL_PRINT ("Next token is", *yytokenp, &yylval, &yylloc);
 	yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
 	if (yyis_pact_ninf (yyj))
 	  return;
@@ -2091,12 +2084,12 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	    {
 	      /* Shift the error token having adjusted its location.  */
 	      YYLTYPE yyerrloc;]b4_location_if([[
-             yystackp->yyerror_range[2].yystate.yyloc = yylloc;
+	      yystackp->yyerror_range[2].yystate.yyloc = yylloc;
 	      YYLLOC_DEFAULT (yyerrloc, yystackp->yyerror_range, 2);]])[
 	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
-                              &yylval, &yyerrloc);
+			       &yylval, &yyerrloc);
 	      yyglrShift (yystackp, 0, yytable[yyj],
-                         yys->yyposn, &yylval, &yyerrloc);
+			  yys->yyposn, &yylval, &yyerrloc);
 	      yys = yystackp->yytops.yystates[0];
 	      break;
 	    }
@@ -2194,8 +2187,8 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	      yyrule = yydefaultAction (yystate);
 	      if (yyrule == 0)
 		{
-]b4_location_if([[               yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
-                 yyreportSyntaxError (&yystack]b4_user_args[);
+]b4_location_if([[		  yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+		  yyreportSyntaxError (&yystack]b4_user_args[);
 		  goto yyuser_error;
 		}
 	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue]b4_user_args[));
@@ -2207,25 +2200,25 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		  YYDPRINTF ((stderr, "Reading a token: "));
 		  yychar = YYLEX;
 		  yytoken = YYTRANSLATE (yychar);
-                 YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
+		  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
 		}
 	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
 	      if (*yyconflicts != 0)
 		break;
 	      if (yyisShiftAction (yyaction))
 		{
-                 YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
+		  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 		  if (yytoken != YYEOF)
 		    yytoken = YYEMPTY;
 		  yyposn += 1;
-                 yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
+		  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
 		  if (0 < yystack.yyerrState)
 		    yystack.yyerrState -= 1;
 		}
 	      else if (yyisErrorAction (yyaction))
 		{
-]b4_location_if([[               yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
-                 yyreportSyntaxError (&yystack]b4_user_args[);
+]b4_location_if([[		  yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+		  yyreportSyntaxError (&yystack]b4_user_args[);
 		  goto yyuser_error;
 		}
 	      else
@@ -2259,7 +2252,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	     on yylval in the event of memory exhaustion.  */
 
 	  for (yys = 0; yys < yyn; yys += 1)
-           YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn]b4_lpure_args[));
+	    YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn]b4_lpure_args[));
 	  yyremoveDeletes (&yystack);
 	  yyn = yystack.yytops.yysize;
 
@@ -2280,9 +2273,9 @@ b4_syncline([@oline@], [@ofile@])])dnl
 			      &yyconflicts);
 	      /* Note that yyconflicts were handled by yyprocessOneStack.  */
 	      YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
-             YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
+	      YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
 	      yyglrShift (&yystack, yys, yyaction, yyposn,
-                         &yylval, &yylloc);
+			  &yylval, &yylloc);
 	      YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
 			  (unsigned long int) yys,
 			  yystack.yytops.yystates[yys]->yylrState));
@@ -2294,8 +2287,8 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		yyFail (&yystack][]b4_lpure_args[, YY_("syntax error"));
 	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
 	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
-]b4_location_if([[           yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
-             yyreportSyntaxError (&yystack]b4_user_args[);
+]b4_location_if([[	      yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+	      yyreportSyntaxError (&yystack]b4_user_args[);
 	      goto yyuser_error;
 	    }
 	  else if (yystack.yytops.yysize == 1)
@@ -2332,7 +2325,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
  yyreturn:
   if (yytoken != YYEOF && yytoken != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
-               yytoken, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
+		yytoken, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
 
   /* If the stack is well-formed, pop the stack until it is empty,
      destroying its entries as we go.  But free the stack regardless
