@@ -1265,6 +1265,11 @@ static void
 yydestruct (int yytype,
 	    YYSTYPE yyvalue[]b4_location_if([, YYLTYPE yylocation]))
 {
+  /* Pacify ``unused variable'' warnings.  */
+  (void) yyvalue;
+b4_location_if([  (void) yylocation;
+])dnl
+
   switch (yytype)
     {
 m4_map([b4_symbol_actions], m4_defn([b4_symbol_destructors]))dnl
@@ -1283,6 +1288,11 @@ static void
 yysymprint (FILE* yyout, int yytype,
 	    YYSTYPE yyvalue[]b4_location_if([, YYLTYPE yylocation]))
 {
+  /* Pacify ``unused variable'' warnings.  */
+  (void) yyvalue;
+b4_location_if([  (void) yylocation;
+])dnl
+
   if (yytype < YYNTOKENS)
     {
       YYFPRINTF (yyout, "token %s (", yytname[[yytype]]);
