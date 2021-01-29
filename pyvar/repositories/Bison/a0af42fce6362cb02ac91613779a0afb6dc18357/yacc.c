@@ -647,13 +647,13 @@ do {									  \
   if (yydebug)								  \
     {									  \
       YYFPRINTF (stderr, "%s ", Title);					  \
-      yysymprint (stderr,						  \
+      yy_symbol_print (stderr,						  \
                   Type, Value]b4_location_if([, Location])[]b4_user_args[); \
       YYFPRINTF (stderr, "\n");						  \
     }									  \
 } while (YYID (0))
 
-]b4_yysymprint_generate([b4_c_function_def])[
+]b4_yy_symbol_print_generate([b4_c_function_def])[
 
 /*------------------------------------------------------------------.
 | yy_stack_print -- Print the state stack from its BOTTOM up to its |
@@ -696,10 +696,10 @@ do {								\
   for (yyi = 0; yyi < yynrhs; yyi++)
     {
       fprintf (stderr, "   $%d = ", yyi + 1);
-      yysymprint (stderr, yyrhs[yyprhs[yyrule] + yyi],
-                  &]b4_rhs_value(yynrhs, yyi + 1)[
-                  ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
-	          b4_user_args[);
+      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
+                       &]b4_rhs_value(yynrhs, yyi + 1)[
+                       ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
+	               b4_user_args[);
       fprintf (stderr, "\n");
     }
 }
