@@ -1387,8 +1387,8 @@ yy_reduce_print (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
     {
       fprintf (stderr, "   $%d = ", yyi + 1);
       yysymprint (stderr, yyrhs[yyprhs[yyrule] + yyi],
-                  &]b4_rhs_value(yynrhs, yyi - 1)[
-                  ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi - 1))[]dnl
+                  &]b4_rhs_value(yynrhs, yyi + 1)[
+                  ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
 	          b4_user_args[);
       fprintf (stderr, "\n");
     }
