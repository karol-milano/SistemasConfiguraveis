@@ -420,8 +420,7 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 /* Error token number */
 #define YYTERROR 1
 
-/* YYLLOC_DEFAULT -- Compute the default location (before the actions
-   are run).  */
+/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].  */
 
 ]b4_location_if([[
 #define YYRHSLOC(yyRhs,YYK) ((yyRhs)[YYK].yystate.yyloc)
@@ -432,6 +431,15 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
     (yyCurrent).first_column = YYRHSLOC(yyRhs, 1).first_column,	\
     (yyCurrent).last_line = YYRHSLOC(yyRhs, YYN).last_line,	\
     (yyCurrent).last_column  = YYRHSLOC(yyRhs, YYN).last_column)
+
+/* YY_LOCATION_PRINT -- Print the location on the stream.
+   This macro was not mandated originally: define only if we know
+   we won't break user code: when these are the locations we know.  */
+
+# define YY_LOCATION_PRINT(File, Loc)			\
+    fprintf (File, "%d.%d-%d.%d",			\
+             (Loc).first_line, (Loc).first_column,	\
+             (Loc).last_line,  (Loc).last_column)
 #endif
 ]],[
 #ifndef YYLLOC_DEFAULT
@@ -439,6 +447,10 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 #endif
 ])[
 
+#ifndef YY_LOCATION_PRINT
+# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
+#endif
+
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
 #define YYLEX ]b4_c_function_call([yylex], [int], b4_lex_param)[
@@ -1579,7 +1591,7 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	  if (yyisShiftAction (yyaction))
 	    {
 	      YYDPRINTF ((stderr, "On stack %d, ", yyk));
-	      YY_SYMBOL_PRINT ("shifting", yytokenp, yylvalp, yyllocp);
+	      YY_SYMBOL_PRINT ("shifting", *yytokenp, yylvalp, yyllocp);
 	      yyglrShift (yystack, yyk, yyaction, yyposn+1,
 			  *yylvalp, yyllocp]b4_user_args[);
 	      YYDPRINTF ((stderr, ", now in state #%d\n",
