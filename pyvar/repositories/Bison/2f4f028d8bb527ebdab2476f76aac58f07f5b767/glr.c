@@ -519,14 +519,9 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 
 #if YYDEBUG
 
-# ifdef YYFPRINTF
-#  define YYFPUTC(Char, Stream) YYFPRINTF (Stream, "%c", Char)
-#  define YYFPUTS(Char, Stream) YYFPRINTF (Stream, "%s", String)
-# else
+#if ! defined (YYFPRINTF)
 #  define YYFPRINTF fprintf
-#  define YYFPUTC fputc
-#  define YYFPUTS fputs
-# endif
+#endif
 
 # define YYDPRINTF(Args)			\
 do {						\
@@ -534,12 +529,6 @@ do {						\
     YYFPRINTF Args;				\
 } while (0)
 
-# define YYDPUTS(String, Stream)		\
-do {						\
-  if (yydebug)					\
-    YYFPUTS (String, Stream);			\
-} while (0)
-
 ]b4_yysymprint_generate([b4_c_ansi_function_def])[
 
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
@@ -549,7 +538,7 @@ do {								\
       YYFPRINTF (stderr, "%s ", Title);				\
       yysymprint (stderr,					\
                   Type, Value]b4_location_if([, Location])[);	\
-      YYFPUTC ('\n', stderr);					\
+      YYFPRINTF (stderr, "\n");					\
     }								\
 } while (0)
 
@@ -559,7 +548,6 @@ int yydebug;
 
 #else /* !YYDEBUG */
 
-# define YYDPUTS(String, File)
 # define YYDPRINTF(Args)
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 
@@ -925,7 +913,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys)
 	  YYFPRINTF (stderr, "%s unresolved ", yymsg);
 	  yysymprint (stderr, yystos[yys->yylrState],
 		      &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
-	  YYFPUTC ('\n', stderr);
+	  YYFPRINTF (stderr, "\n");
 	}
 #endif
 
@@ -1190,7 +1178,7 @@ yyundeleteLastStack (yyGLRStack* yystack)
     return;
   yystack->yytops.yystates[0] = yystack->yylastDeleted;
   yystack->yytops.yysize = 1;
-  YYDPUTS ("Restoring last deleted stack as stack #0.\n", stderr);
+  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
   yystack->yylastDeleted = NULL;
 }
 
@@ -1205,7 +1193,7 @@ yyremoveDeletes (yyGLRStack* yystack)
 	{
 	  if (yyi == yyj)
 	    {
-	      YYDPUTS ("Removing dead stacks.\n", stderr);
+	      YYDPRINTF ((stderr, "Removing dead stacks.\n"));
 	    }
 	  yystack->yytops.yysize -= 1;
 	}
@@ -1638,11 +1626,12 @@ yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
   yyx1 = yyx1;
 
 #if YYDEBUG
-  YYFPUTS ("Ambiguity detected.\nOption 1,\n", stderr);
+  YYFPRINTF (stderr, "Ambiguity detected.\n");
+  YYFPRINTF (stderr, "Option 1,\n");
   yyreportTree (yyx0, 2);
-  YYFPUTS ("\nOption 2,\n", stderr);
+  YYFPRINTF (stderr, "\nOption 2,\n");
   yyreportTree (yyx1, 2);
-  YYFPUTC ('\n', stderr);
+  YYFPRINTF (stderr, "\n");
 #endif
   yyFail (yystack][]b4_pure_args[, YY_("syntax is ambiguous"));
 }
@@ -1798,7 +1787,7 @@ yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
 	{
 	  if (*yytokenp == YYEMPTY)
 	    {
-	      YYDPUTS ("Reading a token: ", stderr);
+	      YYDPRINTF ((stderr, "Reading a token: "));
 	      yychar = YYLEX;
 	      *yytokenp = YYTRANSLATE (yychar);
 	      YY_SYMBOL_PRINT ("Next token is", *yytokenp, yylvalp, yyllocp);
@@ -1981,7 +1970,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    yydestruct ("Error: discarding",
 			*yytokenp, yylvalp]b4_location_if([, yyllocp])[);
 	  }
-	YYDPUTS ("Reading a token: ", stderr);
+	YYDPRINTF ((stderr, "Reading a token: "));
 	yychar = YYLEX;
 	*yytokenp = YYTRANSLATE (yychar);
 	YY_SYMBOL_PRINT ("Next token is", *yytokenp, yylvalp, yyllocp);
@@ -2081,7 +2070,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
   YYSTYPE* const yylvalp = &yylval;
   YYLTYPE* const yyllocp = &yylloc;
 
-  YYDPUTS ("Starting parse\n", stderr);
+  YYDPRINTF ((stderr, "Starting parse\n"));
 
   yytoken = YYEMPTY;
   yylval = yyval_default;
@@ -2145,7 +2134,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	    {
 	      if (yytoken == YYEMPTY)
 		{
-		  YYDPUTS ("Reading a token: ", stderr);
+		  YYDPRINTF ((stderr, "Reading a token: "));
 		  yychar = YYLEX;
 		  yytoken = YYTRANSLATE (yychar);
                   YY_SYMBOL_PRINT ("Next token is", yytoken, yylvalp, yyllocp);
@@ -2190,7 +2179,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	      if (yystack.yytops.yysize == 0)
 		yyFail (&yystack][]b4_lpure_args[, YY_("syntax error"));
 	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
-	      YYDPUTS ("Returning to deterministic operation.\n", stderr);
+	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
 ]b4_location_if([[	      yystack.yyerror_range[1].yystate.yyloc = *yyllocp;]])[
 	      yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 	      goto yyuser_error;
@@ -2198,7 +2187,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	  else if (yystack.yytops.yysize == 1)
 	    {
 	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
-	      YYDPUTS ("Returning to deterministic operation.\n", stderr);
+	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
 	      yycompressStack (&yystack);
 	      break;
 	    }
@@ -2265,7 +2254,7 @@ yy_yypstack (yyGLRState* yys)
   if (yys->yypred)
     {
       yy_yypstack (yys->yypred);
-      fputs (" -> ", stderr);
+      fprintf (stderr, " -> ");
     }
   fprintf (stderr, "%d@@%lu", yys->yylrState, (unsigned long int) yys->yyposn);
 }
@@ -2274,10 +2263,10 @@ static void
 yypstates (yyGLRState* yyst)
 {
   if (yyst == NULL)
-    fputs ("<null>", stderr);
+    fprintf (stderr, "<null>");
   else
     yy_yypstack (yyst);
-  fputc ('\n', stderr);
+  fprintf (stderr, "\n");
 }
 
 static void
@@ -2315,13 +2304,13 @@ yypdumpstack (yyGLRStack* yystack)
 		   (long int) YYINDEX (yyp->yyoption.yystate),
 		   (long int) YYINDEX (yyp->yyoption.yynext));
 	}
-      fputc ('\n', stderr);
+      fprintf (stderr, "\n");
     }
-  fputs ("Tops:", stderr);
+  fprintf (stderr, "Tops:");
   for (yyi = 0; yyi < yystack->yytops.yysize; yyi += 1)
     fprintf (stderr, "%lu: %ld; ", (unsigned long int) yyi,
 	     (long int) YYINDEX (yystack->yytops.yystates[yyi]));
-  fputc ('\n', stderr);
+  fprintf (stderr, "\n");
 }
 #endif
 ]
