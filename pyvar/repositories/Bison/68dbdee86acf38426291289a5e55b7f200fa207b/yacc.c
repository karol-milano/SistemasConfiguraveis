@@ -501,19 +501,6 @@ static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
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
@@ -748,24 +735,26 @@ do {								\
 `------------------------------------------------*/
 
 ]b4_c_function_def([yy_reduce_print], [static void],
-		   [[YYSTYPE *yyvsp], [yyvsp]],
+                   [[yytype_int16 *yyssp], [yyssp]],
+                   [[YYSTYPE *yyvsp], [yyvsp]],
     b4_locations_if([[[YYLTYPE *yylsp], [yylsp]],
-		   ])[[int yyrule], [yyrule]]m4_ifset([b4_parse_param], [,
-		   b4_parse_param]))[
+                   ])[[int yyrule], [yyrule]]m4_ifset([b4_parse_param], [,
+                   b4_parse_param]))[
 {
+  unsigned long int yylno = yyrline[yyrule];
   int yynrhs = yyr2[yyrule];
   int yyi;
-  unsigned long int yylno = yyrline[yyrule];
   YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
-	     yyrule - 1, yylno);
+             yyrule - 1, yylno);
   /* The symbols being reduced.  */
   for (yyi = 0; yyi < yynrhs; yyi++)
     {
       YYFPRINTF (stderr, "   $%d = ", yyi + 1);
-      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
-		       &]b4_rhs_value(yynrhs, yyi + 1)[
-		       ]b4_locations_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
-		       b4_user_args[);
+      yy_symbol_print (stderr,
+                       yystos[yyssp[yyi + 1 - yynrhs]],
+                       &]b4_rhs_value(yynrhs, yyi + 1)[
+                       ]b4_locations_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
+                       b4_user_args[);
       YYFPRINTF (stderr, "\n");
     }
 }
@@ -773,7 +762,7 @@ do {								\
 # define YY_REDUCE_PRINT(Rule)		\
 do {					\
   if (yydebug)				\
-    yy_reduce_print (yyvsp, ]b4_locations_if([yylsp, ])[Rule]b4_user_args[); \
+    yy_reduce_print (yyssp, yyvsp, ]b4_locations_if([yylsp, ])[Rule]b4_user_args[); \
 } while (YYID (0))
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
