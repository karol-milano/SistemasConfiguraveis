@@ -583,9 +583,9 @@ do {								\
                    [[int yyrule], [yyrule]])[
 {
   int yyi;
-  unsigned int yylineno = yyrline[yyrule];
+  unsigned int yylno = yyrline[yyrule];
   YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
-             yyrule - 1, yylineno);
+             yyrule - 1, yylno);
   /* Print the symbols being reduced, and their result.  */
   for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
     YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
