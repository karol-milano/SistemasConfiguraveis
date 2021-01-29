@@ -49,8 +49,8 @@ m4_define([b4_user_formals],
 # Accumule in b4_lex_param all the yylex arguments.
 # Yes, this is quite ugly...
 m4_define([b4_lex_param],
-m4_dquote(b4_pure_if([[[[YYSTYPE *]], [[yylvalp]]][]dnl
-b4_location_if([, [[YYLTYPE *], [yyllocp]]])])dnl
+m4_dquote(b4_pure_if([[[[YYSTYPE *]], [[&yylval]]][]dnl
+b4_location_if([, [[YYLTYPE *], [&yylloc]]])])dnl
 m4_ifdef([b4_lex_param], [, ]b4_lex_param)))
 
 
@@ -65,9 +65,9 @@ m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 
 # b4_lyyerror_args
 # ----------------
-# Same as above, but on the look-ahead, hence yyllocp instead of yylocp.
+# Same as above, but on the look-ahead, hence &yylloc instead of yylocp.
 m4_define([b4_lyyerror_args],
-[b4_pure_if([b4_location_if([yyllocp, ])])dnl
+[b4_pure_if([b4_location_if([&yylloc, ])])dnl
 m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 
 
@@ -80,14 +80,14 @@ m4_define([b4_pure_args],
 
 # b4_lpure_args
 # -------------
-# Same as above, but on the look-ahead, hence yyllocp instead of yylocp.
+# Same as above, but on the look-ahead, hence &yylloc instead of yylocp.
 m4_define([b4_lpure_args],
-[b4_pure_if([b4_location_if([, yyllocp])])[]b4_user_args])
+[b4_pure_if([b4_location_if([, &yylloc])])[]b4_user_args])
 
 
 # b4_pure_formals
 # ---------------
-# Arguments passed to yyerror: user formals plus yyllocp.
+# Arguments passed to yyerror: user formals plus yylocp.
 m4_define([b4_pure_formals],
 [b4_pure_if([b4_location_if([, YYLTYPE *yylocp])])[]b4_user_formals])
 
@@ -495,7 +495,7 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 #ifndef YYLLOC_DEFAULT
 # define YYLLOC_DEFAULT(Current, Rhs, N)				\
     do									\
-      if (N)								\
+      if (YYID (N))                                                    \
 	{								\
 	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
 	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
@@ -539,7 +539,16 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 #undef yynerrs
 #define yynerrs (yystackp->yyerrcnt)
 #undef yychar
-#define yychar (yystackp->yyrawchar)],
+#define yychar (yystackp->yyrawchar)
+#undef yylval
+#define yylval (yystackp->yyval)
+#undef yylloc
+#define yylloc (yystackp->yyloc)
+m4_if(b4_prefix[], [yy], [],
+[#define b4_prefix[]nerrs yynerrs
+#define b4_prefix[]char yychar
+#define b4_prefix[]lval yylval
+#define b4_prefix[]lloc yylloc])],
 [YYSTYPE yylval;
 
 YYLTYPE yylloc;
@@ -786,6 +795,8 @@ struct yyGLRStack {
 [
   int yyerrcnt;
   int yyrawchar;
+  YYSTYPE yyval;
+  YYLTYPE yyloc;
 ])[
   yySymbol* yytokenp;
   YYJMP_BUF yyexception_buffer;
@@ -1840,8 +1851,7 @@ yycompressStack (yyGLRStack* yystackp)
 
 static YYRESULTTAG
 yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
-		   size_t yyposn, YYSTYPE* yylvalp, YYLTYPE* yyllocp
-		  ]b4_pure_formals[)
+                  size_t yyposn]b4_pure_formals[)
 {
   int yyaction;
   const short int* yyconflicts;
@@ -1875,7 +1885,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 	      YYDPRINTF ((stderr, "Reading a token: "));
 	      yychar = YYLEX;
 	      *yytokenp = YYTRANSLATE (yychar);
-	      YY_SYMBOL_PRINT ("Next token is", *yytokenp, yylvalp, yyllocp);
+             YY_SYMBOL_PRINT ("Next token is", *yytokenp, &yylval, &yylloc);
 	    }
 	  yygetLRActions (yystate, *yytokenp, &yyaction, &yyconflicts);
 
@@ -1887,8 +1897,8 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 			  (unsigned long int) yyk));
 	      YYCHK (yyglrReduce (yystackp, yynewStack,
 				  *yyconflicts, yyfalse]b4_user_args[));
-	      YYCHK (yyprocessOneStack (yystackp, yynewStack, yyposn,
-					yylvalp, yyllocp]b4_pure_args[));
+             YYCHK (yyprocessOneStack (yystackp, yynewStack,
+                                       yyposn]b4_pure_args[));
 	      yyconflicts += 1;
 	    }
 
@@ -1902,19 +1912,16 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 	      break;
 	    }
 	  else
-	    YYCHK (yyglrReduce (yystackp, yyk, -yyaction, yyfalse]b4_user_args[));
+           YYCHK (yyglrReduce (yystackp, yyk, -yyaction,
+                               yyfalse]b4_user_args[));
 	}
     }
   return yyok;
 }
 
 /*ARGSUSED*/ static void
-yyreportSyntaxError (yyGLRStack* yystackp,
-		     YYSTYPE* yylvalp, YYLTYPE* yyllocp]b4_user_formals[)
+yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 {
-  YYUSE (yylvalp);
-  YYUSE (yyllocp);
-
   if (yystackp->yyerrState == 0)
     {
 #if YYERROR_VERBOSE
@@ -2013,14 +2020,11 @@ yyreportSyntaxError (yyGLRStack* yystackp,
     }
 }
 
-/* Recover from a syntax error on YYSTACK, assuming that YYTOKENP,
-   YYLVALP, and YYLLOCP point to the syntactic category, semantic
-   value, and location of the look-ahead.  */
+/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
+   yylval, and yylloc are the syntactic category, semantic value, and location
+   of the look-ahead.  */
 /*ARGSUSED*/ static void
-yyrecoverSyntaxError (yyGLRStack* yystackp,
-		      YYSTYPE* yylvalp,
-		      YYLTYPE* YYOPTIONAL_LOC (yyllocp)
-		      ]b4_user_formals[)
+yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 {
   yySymbol* const yytokenp = yystackp->yytokenp;
   size_t yyk;
@@ -2040,15 +2044,15 @@ yyrecoverSyntaxError (yyGLRStack* yystackp,
 	    yyGLRState *yys = yystackp->yytops.yystates[0];
 	    yyGLRStackItem yyerror_range[3];
 	    yyerror_range[1].yystate.yyloc = yys->yyloc;
-	    yyerror_range[2].yystate.yyloc = *yyllocp;
+           yyerror_range[2].yystate.yyloc = yylloc;
 	    YYLLOC_DEFAULT (yys->yyloc, yyerror_range, 2);]])[
 	    yydestruct ("Error: discarding",
-			*yytokenp, yylvalp]b4_location_if([, yyllocp])[]b4_user_args[);
+                       *yytokenp, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
 	  }
 	YYDPRINTF ((stderr, "Reading a token: "));
 	yychar = YYLEX;
 	*yytokenp = YYTRANSLATE (yychar);
-	YY_SYMBOL_PRINT ("Next token is", *yytokenp, yylvalp, yyllocp);
+       YY_SYMBOL_PRINT ("Next token is", *yytokenp, &yylval, &yylloc);
 	yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
 	if (yyis_pact_ninf (yyj))
 	  return;
@@ -2087,12 +2091,12 @@ yyrecoverSyntaxError (yyGLRStack* yystackp,
 	    {
 	      /* Shift the error token having adjusted its location.  */
 	      YYLTYPE yyerrloc;]b4_location_if([[
-	      yystackp->yyerror_range[2].yystate.yyloc = *yyllocp;
+             yystackp->yyerror_range[2].yystate.yyloc = yylloc;
 	      YYLLOC_DEFAULT (yyerrloc, yystackp->yyerror_range, 2);]])[
 	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
-			       yylvalp, &yyerrloc);
+                              &yylval, &yyerrloc);
 	      yyglrShift (yystackp, 0, yytable[yyj],
-			  yys->yyposn, yylvalp, &yyerrloc);
+                         yys->yyposn, &yylval, &yyerrloc);
 	      yys = yystackp->yytops.yystates[0];
 	      break;
 	    }
@@ -2133,17 +2137,8 @@ yyrecoverSyntaxError (yyGLRStack* yystackp,
   int yyresult;
   yySymbol yytoken;
   yyGLRStack yystack;
+  yyGLRStack* const yystackp = &yystack;
   size_t yyposn;
-]b4_pure_if(
-[
-  YYSTYPE yylval;
-  YYLTYPE yylloc;
-  #undef yychar
-  #define yychar (yystack.yyrawchar)
-])[
-
-  YYSTYPE* const yylvalp = &yylval;
-  YYLTYPE* const yyllocp = &yylloc;
 
   YYDPRINTF ((stderr, "Starting parse\n"));
 
@@ -2165,7 +2160,7 @@ m4_popdef([b4_at_dollar])dnl
 /* Line __line__ of glr.c.  */
 b4_syncline([@oline@], [@ofile@])])dnl
 [
-  if (! yyinitGLRStack (&yystack, YYINITDEPTH))
+  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
     goto yyexhaustedlab;
   switch (YYSETJMP (yystack.yyexception_buffer))
     {
@@ -2199,8 +2194,8 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	      yyrule = yydefaultAction (yystate);
 	      if (yyrule == 0)
 		{
-]b4_location_if([[		  yystack.yyerror_range[1].yystate.yyloc = *yyllocp;]])[
-		  yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
+]b4_location_if([[               yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+                 yyreportSyntaxError (&yystack]b4_user_args[);
 		  goto yyuser_error;
 		}
 	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue]b4_user_args[));
@@ -2212,25 +2207,25 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		  YYDPRINTF ((stderr, "Reading a token: "));
 		  yychar = YYLEX;
 		  yytoken = YYTRANSLATE (yychar);
-		  YY_SYMBOL_PRINT ("Next token is", yytoken, yylvalp, yyllocp);
+                 YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
 		}
 	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
 	      if (*yyconflicts != 0)
 		break;
 	      if (yyisShiftAction (yyaction))
 		{
-		  YY_SYMBOL_PRINT ("Shifting", yytoken, yylvalp, yyllocp);
+                 YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 		  if (yytoken != YYEOF)
 		    yytoken = YYEMPTY;
 		  yyposn += 1;
-		  yyglrShift (&yystack, 0, yyaction, yyposn, yylvalp, yyllocp);
+                 yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
 		  if (0 < yystack.yyerrState)
 		    yystack.yyerrState -= 1;
 		}
 	      else if (yyisErrorAction (yyaction))
 		{
-]b4_location_if([[		  yystack.yyerror_range[1].yystate.yyloc = *yyllocp;]])[
-		  yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
+]b4_location_if([[               yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+                 yyreportSyntaxError (&yystack]b4_user_args[);
 		  goto yyuser_error;
 		}
 	      else
@@ -2264,8 +2259,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	     on yylval in the event of memory exhaustion.  */
 
 	  for (yys = 0; yys < yyn; yys += 1)
-	    YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn,
-				       yylvalp, yyllocp]b4_lpure_args[));
+           YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn]b4_lpure_args[));
 	  yyremoveDeletes (&yystack);
 	  yyn = yystack.yytops.yysize;
 
@@ -2286,9 +2280,9 @@ b4_syncline([@oline@], [@ofile@])])dnl
 			      &yyconflicts);
 	      /* Note that yyconflicts were handled by yyprocessOneStack.  */
 	      YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
-	      YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, yylvalp, yyllocp);
+             YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
 	      yyglrShift (&yystack, yys, yyaction, yyposn,
-			  yylvalp, yyllocp);
+                         &yylval, &yylloc);
 	      YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
 			  (unsigned long int) yys,
 			  yystack.yytops.yystates[yys]->yylrState));
@@ -2300,8 +2294,8 @@ b4_syncline([@oline@], [@ofile@])])dnl
 		yyFail (&yystack][]b4_lpure_args[, YY_("syntax error"));
 	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
 	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
-]b4_location_if([[	      yystack.yyerror_range[1].yystate.yyloc = *yyllocp;]])[
-	      yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
+]b4_location_if([[           yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+             yyreportSyntaxError (&yystack]b4_user_args[);
 	      goto yyuser_error;
 	    }
 	  else if (yystack.yytops.yysize == 1)
@@ -2314,7 +2308,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	}
       continue;
     yyuser_error:
-      yyrecoverSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
+      yyrecoverSyntaxError (&yystack]b4_user_args[);
       yyposn = yystack.yytops.yystates[0]->yyposn;
     }
 
@@ -2338,7 +2332,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
  yyreturn:
   if (yytoken != YYEOF && yytoken != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
-		yytoken, yylvalp]b4_location_if([, yyllocp])[]b4_user_args[);
+               yytoken, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
 
   /* If the stack is well-formed, pop the stack until it is empty,
      destroying its entries as we go.  But free the stack regardless
