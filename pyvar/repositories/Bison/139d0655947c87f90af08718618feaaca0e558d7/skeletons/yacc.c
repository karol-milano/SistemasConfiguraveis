@@ -755,7 +755,7 @@ do {                                                            \
     {
       YYFPRINTF (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr,
-                       yystos[yyssp[yyi + 1 - yynrhs]],
+                       yystos[+yyssp[yyi + 1 - yynrhs]],
                        &]b4_rhs_value(yynrhs, yyi + 1)[
                        ]b4_locations_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
                        b4_user_args[);
@@ -955,12 +955,12 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
     }
   while (1)
     {
-      int yyrule = yypact[*yyesp];
+      int yyrule = yypact[+*yyesp];
       if (yypact_value_is_default (yyrule)
           || (yyrule += yytoken) < 0 || YYLAST < yyrule
           || yycheck[yyrule] != yytoken)
         {
-          yyrule = yydefact[*yyesp];
+          yyrule = yydefact[+*yyesp];
           if (yyrule == 0)
             {
               YYDPRINTF ((stderr, " Err\n"));
@@ -1184,7 +1184,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
   */
   if (yytoken != YYEMPTY)
     {
-      int yyn = yypact[*yyssp];
+      int yyn = yypact[+*yyssp];
       YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
       yysize = yysize0;]b4_lac_if([[
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
@@ -1940,7 +1940,7 @@ yyreturn:
   while (yyssp != yyss)
     {
       yydestruct ("Cleanup: popping",
-                  yystos[*yyssp], yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
+                  yystos[+*yyssp], yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
       YYPOPSTACK (1);
     }
 #ifndef yyoverflow
