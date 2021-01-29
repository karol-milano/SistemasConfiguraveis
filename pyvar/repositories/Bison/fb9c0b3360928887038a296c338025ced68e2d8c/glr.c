@@ -519,9 +519,14 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 
 #if YYDEBUG
 
-#if ! defined (YYFPRINTF)
+# ifdef YYFPRINTF
+#  define YYFPUTC(Char, Stream) YYFPRINTF (Stream, "%c", Char)
+#  define YYFPUTS(Char, Stream) YYFPRINTF (Stream, "%s", String)
+# else
 #  define YYFPRINTF fprintf
-#endif
+#  define YYFPUTC fputc
+#  define YYFPUTS fputs
+# endif
 
 # define YYDPRINTF(Args)			\
 do {						\
@@ -529,6 +534,12 @@ do {						\
     YYFPRINTF Args;				\
 } while (0)
 
+# define YYDPUTS(String, Stream)		\
+do {						\
+  if (yydebug)					\
+    YYFPUTS (String, Stream);			\
+} while (0)
+
 ]b4_yysymprint_generate([b4_c_ansi_function_def])[
 
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
@@ -538,7 +549,7 @@ do {								\
       YYFPRINTF (stderr, "%s ", Title);				\
       yysymprint (stderr,					\
                   Type, Value]b4_location_if([, Location])[);	\
-      YYFPRINTF (stderr, "\n");					\
+      YYFPUTC ('\n', stderr);					\
     }								\
 } while (0)
 
@@ -548,6 +559,7 @@ int yydebug;
 
 #else /* !YYDEBUG */
 
+# define YYDPUTS(String, File)
 # define YYDPRINTF(Args)
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 
@@ -913,7 +925,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys)
 	  YYFPRINTF (stderr, "%s unresolved ", yymsg);
 	  yysymprint (stderr, yystos[yys->yylrState],
 		      &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[);
-	  YYFPRINTF (stderr, "\n");
+	  YYFPUTC ('\n', stderr);
 	}
 #endif
 
@@ -1178,7 +1190,7 @@ yyundeleteLastStack (yyGLRStack* yystack)
     return;
   yystack->yytops.yystates[0] = yystack->yylastDeleted;
   yystack->yytops.yysize = 1;
-  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
+  YYDPUTS ("Restoring last deleted stack as stack #0.\n", stderr);
   yystack->yylastDeleted = NULL;
 }
 
@@ -1193,7 +1205,7 @@ yyremoveDeletes (yyGLRStack* yystack)
 	{
 	  if (yyi == yyj)
 	    {
-	      YYDPRINTF ((stderr, "Removing dead stacks.\n"));
+	      YYDPUTS ("Removing dead stacks.\n", stderr);
 	    }
 	  yystack->yytops.yysize -= 1;
 	}
@@ -1626,12 +1638,11 @@ yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
   (void) yyx1;
 
 #if YYDEBUG
-  YYFPRINTF (stderr, "Ambiguity detected.\n");
-  YYFPRINTF (stderr, "Option 1,\n");
+  YYFPUTS ("Ambiguity detected.\nOption 1,\n", stderr);
   yyreportTree (yyx0, 2);
-  YYFPRINTF (stderr, "\nOption 2,\n");
+  YYFPUTS ("\nOption 2,\n", stderr);
   yyreportTree (yyx1, 2);
-  YYFPRINTF (stderr, "\n");
+  YYFPUTC ('\n', stderr);
 #endif
   yyFail (yystack][]b4_pure_args[, YY_("syntax is ambiguous"));
 }
@@ -1787,7 +1798,7 @@ yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
 	{
 	  if (*yytokenp == YYEMPTY)
 	    {
-	      YYDPRINTF ((stderr, "Reading a token: "));
+	      YYDPUTS ("Reading a token: ", stderr);
 	      yychar = YYLEX;
 	      *yytokenp = YYTRANSLATE (yychar);
 	      YY_SYMBOL_PRINT ("Next token is", *yytokenp, yylvalp, yyllocp);
@@ -1970,7 +1981,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	    yydestruct ("Error: discarding",
 			*yytokenp, yylvalp]b4_location_if([, yyllocp])[);
 	  }
-	YYDPRINTF ((stderr, "Reading a token: "));
+	YYDPUTS ("Reading a token: ", stderr);
 	yychar = YYLEX;
 	*yytokenp = YYTRANSLATE (yychar);
 	YY_SYMBOL_PRINT ("Next token is", *yytokenp, yylvalp, yyllocp);
@@ -2070,7 +2081,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
   YYSTYPE* const yylvalp = &yylval;
   YYLTYPE* const yyllocp = &yylloc;
 
-  YYDPRINTF ((stderr, "Starting parse\n"));
+  YYDPUTS ("Starting parse\n", stderr);
 
   yytoken = YYEMPTY;
   yylval = yyval_default;
@@ -2134,7 +2145,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	    {
 	      if (yytoken == YYEMPTY)
 		{
-		  YYDPRINTF ((stderr, "Reading a token: "));
+		  YYDPUTS ("Reading a token: ", stderr);
 		  yychar = YYLEX;
 		  yytoken = YYTRANSLATE (yychar);
                   YY_SYMBOL_PRINT ("Next token is", yytoken, yylvalp, yyllocp);
@@ -2179,7 +2190,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	      if (yystack.yytops.yysize == 0)
 		yyFail (&yystack][]b4_lpure_args[, YY_("syntax error"));
 	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
-	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
+	      YYDPUTS ("Returning to deterministic operation.\n", stderr);
 ]b4_location_if([[	      yystack.yyerror_range[1].yystate.yyloc = *yyllocp;]])[
 	      yyreportSyntaxError (&yystack, yylvalp, yyllocp]b4_user_args[);
 	      goto yyuser_error;
@@ -2187,7 +2198,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 	  else if (yystack.yytops.yysize == 1)
 	    {
 	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
-	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
+	      YYDPUTS ("Returning to deterministic operation.\n", stderr);
 	      yycompressStack (&yystack);
 	      break;
 	    }
@@ -2254,7 +2265,7 @@ yy_yypstack (yyGLRState* yys)
   if (yys->yypred)
     {
       yy_yypstack (yys->yypred);
-      fprintf (stderr, " -> ");
+      fputs (" -> ", stderr);
     }
   fprintf (stderr, "%d@@%lu", yys->yylrState, (unsigned long int) yys->yyposn);
 }
@@ -2263,10 +2274,10 @@ static void
 yypstates (yyGLRState* yyst)
 {
   if (yyst == NULL)
-    fprintf (stderr, "<null>");
+    fputs ("<null>", stderr);
   else
     yy_yypstack (yyst);
-  fprintf (stderr, "\n");
+  fputc ('\n', stderr);
 }
 
 static void
@@ -2304,13 +2315,13 @@ yypdumpstack (yyGLRStack* yystack)
 		   (long int) YYINDEX (yyp->yyoption.yystate),
 		   (long int) YYINDEX (yyp->yyoption.yynext));
 	}
-      fprintf (stderr, "\n");
+      fputc ('\n', stderr);
     }
-  fprintf (stderr, "Tops:");
+  fputs ("Tops:", stderr);
   for (yyi = 0; yyi < yystack->yytops.yysize; yyi += 1)
     fprintf (stderr, "%lu: %ld; ", (unsigned long int) yyi,
 	     (long int) YYINDEX (yystack->yytops.yystates[yyi]));
-  fprintf (stderr, "\n");
+  fputc ('\n', stderr);
 }
 #endif
 ]
