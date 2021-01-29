@@ -1275,13 +1275,10 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
 ]b4_function_define([[yypull_parse]], [[int]],
   [[[yypstate *yyps]], [[yyps]]]m4_ifset([b4_parse_param], [,
   b4_parse_param]))[
-{
-  int yystatus;
-  yypstate *yyps_local;]b4_pure_if([[
-  int yychar;
-  YYSTYPE yylval;]b4_locations_if([[
+{]b4_pure_if([b4_locations_if([[
   static YYLTYPE yyloc_default][]b4_yyloc_default[;
   YYLTYPE yylloc = yyloc_default;]])])[
+  yypstate *yyps_local;
   if (yyps)
     yyps_local = yyps;
   else
@@ -1295,8 +1292,10 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
           return 2;
         }
     }
-  do {
-    yychar = ]b4_lex[;
+  int yystatus;
+  do {]b4_pure_if([[
+    YYSTYPE yylval;
+    int ]])[yychar = ]b4_lex[;
     yystatus =
       yypush_parse (yyps_local]b4_pure_if([[, yychar, &yylval]b4_locations_if([[, &yylloc]])])m4_ifset([b4_parse_param], [, b4_args(b4_parse_param)])[);
   } while (yystatus == YYPUSH_MORE);
