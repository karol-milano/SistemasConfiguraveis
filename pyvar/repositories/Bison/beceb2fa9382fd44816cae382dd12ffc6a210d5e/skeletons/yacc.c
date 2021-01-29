@@ -1490,7 +1490,7 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
   yystacksize = YYINITDEPTH;]b4_lac_if([[
 
   yyes = yyesa;
-  yyes_capacity = (YYPTRDIFF_T) (sizeof yyesa / sizeof *yyes);
+  yyes_capacity = ]b4_percent_define_get([[parse.lac.es-capacity-initial]])[;
   if (YYMAXDEPTH < yyes_capacity)
     yyes_capacity = YYMAXDEPTH;]])[
 
