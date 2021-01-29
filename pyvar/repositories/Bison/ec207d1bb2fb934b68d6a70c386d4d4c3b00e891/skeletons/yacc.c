@@ -1444,36 +1444,33 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
 int
 yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
 {
-  return yypull_parse (YY_NULLPTR]b4_user_args[);
+  yypstate *yyps = yypstate_new ();
+  if (!yyps)
+    {]b4_pure_if([b4_locations_if([[
+      static YYLTYPE yyloc_default][]b4_yyloc_default[;
+      YYLTYPE yylloc = yyloc_default;]])[
+      yyerror (]b4_yyerror_args[YY_("memory exhausted"));]], [[
+      if (!yypstate_allocated)
+        yyerror (]b4_yyerror_args[YY_("memory exhausted"));]])[
+      return 2;
+    }
+  int yystatus = yypull_parse (yyps]b4_user_args[);
+  yypstate_delete (yyps);
+  return yystatus;
 }
 
 int
 yypull_parse (yypstate *yyps]b4_user_formals[)
-{]b4_pure_if([b4_locations_if([[
+{
+  YY_ASSERT (yyps);]b4_pure_if([b4_locations_if([[
   static YYLTYPE yyloc_default][]b4_yyloc_default[;
   YYLTYPE yylloc = yyloc_default;]])])[
-  yypstate *yyps_local;
-  if (yyps)
-    yyps_local = yyps;
-  else
-    {
-      yyps_local = yypstate_new ();
-      if (!yyps_local)
-        {]b4_pure_if([[
-          yyerror (]b4_yyerror_args[YY_("memory exhausted"));]], [[
-          if (!yypstate_allocated)
-            yyerror (]b4_yyerror_args[YY_("memory exhausted"));]])[
-          return 2;
-        }
-    }
   int yystatus;
   do {
 ]b4_pure_if([[    YYSTYPE yylval;
     int ]])[yychar = ]b4_lex[;
-    yystatus = yypush_parse (yyps_local]b4_pure_if([[, yychar, &yylval]b4_locations_if([[, &yylloc]])])m4_ifset([b4_parse_param], [, b4_args(b4_parse_param)])[);
+    yystatus = yypush_parse (yyps]b4_pure_if([[, yychar, &yylval]b4_locations_if([[, &yylloc]])])m4_ifset([b4_parse_param], [, b4_args(b4_parse_param)])[);
   } while (yystatus == YYPUSH_MORE);
-  if (!yyps)
-    yypstate_delete (yyps_local);
   return yystatus;
 }]])[
 
