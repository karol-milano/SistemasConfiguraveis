@@ -1123,9 +1123,9 @@ static inline void
 yy_reduce_print (size_t yyk, yyRuleNum yyrule)
 {
   int yyi;
-  unsigned int yylineno = yyrline[yyrule];
+  unsigned int yylno = yyrline[yyrule];
   YYFPRINTF (stderr, "Reducing stack %d by rule %d (line %u), ",
-	     yyk, yyrule - 1, yylineno);
+	     yyk, yyrule - 1, yylno);
   /* Print the symbols being reduced, and their result.  */
   for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
     YYFPRINTF (stderr, "%s ", yytokenName (yyrhs[yyi]));
