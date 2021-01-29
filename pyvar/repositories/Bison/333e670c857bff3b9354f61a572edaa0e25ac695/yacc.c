@@ -1079,26 +1079,25 @@ b4_push_if(
     /* Used to determine if this is the first time this instance has
        been used.  */
     int yynew;
-  };
+  };]b4_pure_if([], [[
 
-]b4_pull_if([b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
+static char yypstate_allocated = 0;]])b4_pull_if([
+
+b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
 {
   return yypull_parse (0]m4_ifset([b4_parse_param],
                                   [[, ]b4_c_args(b4_parse_param)])[);
-}]b4_pure_if([], [[
-
-static char yypstate_allocated = 0;]])[
+}
 
 ]b4_c_function_def([[yypull_parse]], [[int]],
   [[[yypstate *yyps]], [[yyps]]]m4_ifset([b4_parse_param], [,
   b4_parse_param]))[
 {
   int yystatus;
-  yypstate *yyps_local;
-]b4_pure_if([[  int yychar;
-  YYSTYPE yylval;
-]b4_locations_if([[  YYLTYPE yylloc;
-]])])[
+  yypstate *yyps_local;]b4_pure_if([[
+  int yychar;
+  YYSTYPE yylval;]b4_locations_if([[
+  YYLTYPE yylloc;]])])[
   if (yyps == 0)
     {
       yyps_local = yypstate_new ();
@@ -1120,17 +1119,14 @@ static char yypstate_allocated = 0;]])[
   if (yyps == 0)
     yypstate_delete (yyps_local);
   return yystatus;
-}
-]])[
+}]])[
+
 /* Initialize the parser data structure.  */
 ]b4_c_function_def([[yypstate_new]], [[yypstate *]])[
 {
   yypstate *yyps;]b4_pure_if([], [[
   if (yypstate_allocated)
-    {
-      yyerror (]b4_yyerror_args[YY_("cannot allocate multiple impure push-parser instances"));
-      return 0;
-    }]])[
+    return 0;]])[
   yyps = (yypstate *) malloc (sizeof *yyps);
   if (!yyps)
     return 0;
