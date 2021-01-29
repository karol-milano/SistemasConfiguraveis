@@ -1179,12 +1179,12 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                 ]b4_lac_if([[yytype_int16 *yyesa, yytype_int16 **yyes,
                 YYSIZE_T *yyes_capacity, ]])[yytype_int16 *yyssp, int yytoken)
 {
-  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
+  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
   YYSIZE_T yysize1;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
-  const char *yyformat = 0;
+  const char *yyformat = YY_NULL;
   /* Arguments of yyformat. */
   char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
   /* Number of reported tokens (one for the "unexpected", one per
@@ -1262,7 +1262,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                     break;
                   }
                 yyarg[yycount++] = yytname[yyx];
-                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
+                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                 if (! (yysize <= yysize1
                        && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                   return 2;
@@ -1351,7 +1351,7 @@ static char yypstate_allocated = 0;]])b4_pull_if([
 
 b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
 {
-  return yypull_parse (0]m4_ifset([b4_parse_param],
+  return yypull_parse (YY_NULL]m4_ifset([b4_parse_param],
                                   [[, ]b4_c_args(b4_parse_param)])[);
 }
 
@@ -1364,7 +1364,9 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   int yychar;
   YYSTYPE yylval;]b4_locations_if([[
   YYLTYPE yylloc;]])])[
-  if (yyps == 0)
+  if (yyps)
+    yyps_local = yyps;
+  else
     {
       yyps_local = yypstate_new ();
       if (!yyps_local)
@@ -1375,14 +1377,12 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
           return 2;
         }
     }
-  else
-    yyps_local = yyps;
   do {
     yychar = YYLEX;
     yystatus =
       yypush_parse (yyps_local]b4_pure_if([[, yychar, &yylval]b4_locations_if([[, &yylloc]])])m4_ifset([b4_parse_param], [, b4_c_args(b4_parse_param)])[);
   } while (yystatus == YYPUSH_MORE);
-  if (yyps == 0)
+  if (!yyps)
     yypstate_delete (yyps_local);
   return yystatus;
 }]])[
@@ -1392,10 +1392,10 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
 {
   yypstate *yyps;]b4_pure_if([], [[
   if (yypstate_allocated)
-    return 0;]])[
+    return YY_NULL;]])[
   yyps = (yypstate *) malloc (sizeof *yyps);
   if (!yyps)
-    return 0;
+    return YY_NULL;
   yyps->yynew = 1;]b4_pure_if([], [[
   yypstate_allocated = 1;]])[
   return yyps;
