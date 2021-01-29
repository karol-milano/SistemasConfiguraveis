@@ -1103,8 +1103,9 @@ static inline void
 yy_reduce_print (size_t yyk, yyRuleNum yyrule)
 {
   int yyi;
-  YYFPRINTF (stderr, "Reducing stack %d by rule %d (line %d), ",
-	     yyk, yyrule - 1, yyrline[yyrule]);
+  unsigned int yylineno = yyrline[yyrule];
+  YYFPRINTF (stderr, "Reducing stack %d by rule %d (line %u), ",
+	     yyk, yyrule - 1, yylineno);
   /* Print the symbols being reduced, and their result.  */
   for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
     YYFPRINTF (stderr, "%s ", yytokenName (yyrhs[yyi]));
