@@ -367,19 +367,6 @@ static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
 };
 
 #if YYDEBUG
-/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
-   YYRHS.  */
-static const ]b4_int_type_for([b4_prhs])[ yyprhs[] =
-{
-  ]b4_prhs[
-};
-
-/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
-static const ]b4_int_type_for([b4_rhs])[ yyrhs[] =
-{
-  ]b4_rhs[
-};
-
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const ]b4_int_type_for([b4_rline])[ yyrline[] =
 {
@@ -1453,7 +1440,8 @@ yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
   for (yyi = 0; yyi < yynrhs; yyi++)
     {
       YYFPRINTF (stderr, "   $%d = ", yyi + 1);
-      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
+      yy_symbol_print (stderr,
+                       ]yystos@{b4_rhs_data(yynrhs, yyi + 1).yylrState@}[,
 		       &]b4_rhs_value(yynrhs, yyi + 1)[
 		       ]b4_locations_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
 		       b4_user_args[);
@@ -1782,11 +1770,11 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
 	{
 	  if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
 	    YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
-		       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]));
+		       yytokenName (yystos[yystates[yyi-1]->yylrState]));
 	  else
 	    YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
-		       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]),
-		       (unsigned long int) (yystates[yyi - 1]->yyposn + 1),
+		       yytokenName (yystos[yystates[yyi-1]->yylrState]),
+		       (unsigned long int) (yystates[yyi-1]->yyposn + 1),
 		       (unsigned long int) yystates[yyi]->yyposn);
 	}
       else
