@@ -1386,7 +1386,7 @@ yy_reduce_print (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
   //for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
   for (yyi = 0; yyi < yynrhs; yyi++)
     {
-      fprintf (stderr, "   $%d = ", yyi);
+      fprintf (stderr, "   $%d = ", yyi + 1);
       yysymprint (stderr, yyrhs[yyprhs[yyrule] + yyi],
                   &]b4_rhs_value(yynrhs, yyi)[
                   ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi))[]dnl
