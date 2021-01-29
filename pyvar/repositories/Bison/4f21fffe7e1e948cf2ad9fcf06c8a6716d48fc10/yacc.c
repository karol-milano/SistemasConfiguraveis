@@ -577,8 +577,9 @@ do {								\
                    [[int yyrule], [yyrule]])[
 {
   int yyi;
-  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d), ",
-             yyrule - 1, yyrline[yyrule]);
+  unsigned int yylineno = yyrline[yyrule];
+  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
+             yyrule - 1, yylineno);
   /* Print the symbols being reduced, and their result.  */
   for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
     YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
