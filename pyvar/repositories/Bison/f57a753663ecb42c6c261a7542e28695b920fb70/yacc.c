@@ -714,12 +714,12 @@ do {								\
   /* The symbols being reduced.  */
   for (yyi = 0; yyi < yynrhs; yyi++)
     {
-      fprintf (stderr, "   $%d = ", yyi + 1);
+      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
 		       &]b4_rhs_value(yynrhs, yyi + 1)[
 		       ]b4_locations_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
 		       b4_user_args[);
-      fprintf (stderr, "\n");
+      YYFPRINTF (stderr, "\n");
     }
 }
 
