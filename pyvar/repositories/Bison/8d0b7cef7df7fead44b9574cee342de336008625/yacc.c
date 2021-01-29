@@ -1108,11 +1108,11 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                 ]b4_lac_if([[yytype_int16 *yyesa, yytype_int16 **yyes,
                 YYSIZE_T *yyes_capacity, ]])[yytype_int16 *yyssp, int yytoken)
 {
-  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
+  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
-  const char *yyformat = YY_NULL;
+  const char *yyformat = YY_NULLPTR;
   /* Arguments of yyformat. */
   char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
   /* Number of reported tokens (one for the "unexpected", one per
@@ -1187,7 +1187,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                   }
                 yyarg[yycount++] = yytname[yyx];
                 {
-                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
+                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                   if (! (yysize <= yysize1
                          && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                     return 2;
@@ -1271,7 +1271,7 @@ static char yypstate_allocated = 0;]])b4_pull_if([
 
 b4_function_define([[yyparse]], [[int]], b4_parse_param)[
 {
-  return yypull_parse (YY_NULL]m4_ifset([b4_parse_param],
+  return yypull_parse (YY_NULLPTR]m4_ifset([b4_parse_param],
                                   [[, ]b4_args(b4_parse_param)])[);
 }
 
@@ -1313,10 +1313,10 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
 {
   yypstate *yyps;]b4_pure_if([], [[
   if (yypstate_allocated)
-    return YY_NULL;]])[
+    return YY_NULLPTR;]])[
   yyps = (yypstate *) malloc (sizeof *yyps);
   if (!yyps)
-    return YY_NULL;
+    return YY_NULLPTR;
   yyps->yynew = 1;]b4_pure_if([], [[
   yypstate_allocated = 1;]])[
   return yyps;
