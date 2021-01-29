@@ -577,14 +577,14 @@ do {						\
     YYFPRINTF Args;				\
 } while (YYID (0))
 
-]b4_yysymprint_generate([b4_c_ansi_function_def])[
+]b4_yy_symbol_print_generate([b4_c_ansi_function_def])[
 
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)			    \
 do {									    \
   if (yydebug)								    \
     {									    \
       YYFPRINTF (stderr, "%s ", Title);					    \
-      yysymprint (stderr,						    \
+      yy_symbol_print (stderr,						    \
 		  Type, Value]b4_location_if([, Location])[]b4_user_args[); \
       YYFPRINTF (stderr, "\n");						    \
     }									    \
@@ -976,7 +976,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
       if (yydebug)
 	{
 	  YYFPRINTF (stderr, "%s unresolved ", yymsg);
-	  yysymprint (stderr, yystos[yys->yylrState],
+	  yy_symbol_print (stderr, yystos[yys->yylrState],
 		      &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[]b4_user_args[);
 	  YYFPRINTF (stderr, "\n");
 	}
@@ -1407,10 +1407,10 @@ yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
   for (yyi = 0; yyi < yynrhs; yyi++)
     {
       fprintf (stderr, "   $%d = ", yyi + 1);
-      yysymprint (stderr, yyrhs[yyprhs[yyrule] + yyi],
-		  &]b4_rhs_value(yynrhs, yyi + 1)[
-		  ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
-		  b4_user_args[);
+      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
+		       &]b4_rhs_value(yynrhs, yyi + 1)[
+		       ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
+		       b4_user_args[);
       fprintf (stderr, "\n");
     }
 }
