@@ -808,7 +808,8 @@ int yydebug;
 /* Parser data structure.  */
 struct yypstate
   {]b4_declare_parser_state_variables[
-    /* Whether this instance has not started parsing yet.  */
+    /* Whether this instance has not started parsing yet.
+     * If 2, it corresponds to a finished parsing.  */
     int yynew;
   };]b4_pure_if([], [[
 
@@ -1463,18 +1464,14 @@ yypstate_clear (yypstate *yyps)
   yystate = 0;
   yyerrstatus = 0;
 
-  yystacksize = YYINITDEPTH;
-  yyssp = yyss = yyssa;
-  yyvsp = yyvs = yyvsa;]b4_locations_if([[
-  yylsp = yyls = yylsa;]])[]b4_lac_if([[
+  yyssp = yyss;
+  yyvsp = yyvs;]b4_locations_if([[
+  yylsp = yyls;]])[
 
-  yyes = yyesa;
-  yyes_capacity = ]b4_percent_define_get([[parse.lac.es-capacity-initial]])[;
-  if (YYMAXDEPTH < yyes_capacity)
-    yyes_capacity = YYMAXDEPTH;]])[
   /* Initialize the state stack, in case yypcontext_expected_tokens is
      called before the first call to yyparse. */
   *yyssp = 0;
+  yyps->yynew = 1;
 }
 
 /* Initialize the parser data structure.  */
@@ -1486,9 +1483,16 @@ yypstate_new (void)
     return YY_NULLPTR;]])[
   yyps = YY_CAST (yypstate *, malloc (sizeof *yyps));
   if (!yyps)
-    return YY_NULLPTR;
-  yyps->yynew = 1;]b4_pure_if([], [[
+    return YY_NULLPTR;]b4_pure_if([], [[
   yypstate_allocated = 1;]])[
+  yystacksize = YYINITDEPTH;
+  yyss = yyssa;
+  yyvs = yyvsa;]b4_locations_if([[
+  yyls = yylsa;]])[]b4_lac_if([[
+  yyes = yyesa;
+  yyes_capacity = ]b4_percent_define_get([[parse.lac.es-capacity-initial]])[;
+  if (YYMAXDEPTH < yyes_capacity)
+    yyes_capacity = YYMAXDEPTH;]])[
   yypstate_clear (yyps);
   return yyps;
 }
@@ -1501,10 +1505,10 @@ yypstate_delete (yypstate *yyps)
 #ifndef yyoverflow
       /* If the stack was reallocated but the parse did not complete, then the
          stack still needs to be freed.  */
-      if (!yyps->yynew && yyss != yyssa)
+      if (yyss != yyssa)
         YYSTACK_FREE (yyss);
 #endif]b4_lac_if([[
-      if (!yyps->yynew && yyes != yyesa)
+      if (yyes != yyesa)
         YYSTACK_FREE (yyes);]])[
       free (yyps);]b4_pure_if([], [[
       yypstate_allocated = 0;]])[
@@ -1562,8 +1566,14 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])[
      Keep to zero when no symbol should be popped.  */
   int yylen = 0;]b4_push_if([[
 
-  if (!yyps->yynew)
+  switch (yyps->yynew)
     {
+    case 2:
+      yypstate_clear (yyps);
+      goto case_0;
+
+    case_0:
+    case 0:
       yyn = yypact[yystate];
       goto yyread_pushed_token;
     }]])[
@@ -2060,22 +2070,21 @@ yyreturn:
       yydestruct ("Cleanup: popping",
                   YY_ACCESSING_SYMBOL (+*yyssp), yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
       YYPOPSTACK (1);
-    }
-#ifndef yyoverflow
-  if (yyss != yyssa)
-    YYSTACK_FREE (yyss);
-#endif]b4_lac_if([[
-  if (yyes != yyesa)
-    YYSTACK_FREE (yyes);]])b4_push_if([[
-  yypstate_clear (yyps);
-  yyps->yynew = 1;
+    }]b4_push_if([[
+  yyps->yynew = 2;
   goto yypushreturn;
 
 
 /*-------------------------.
 | yypushreturn -- return.  |
 `-------------------------*/
-yypushreturn:]])[
+yypushreturn:]], [[
+#ifndef yyoverflow
+  if (yyss != yyssa)
+    YYSTACK_FREE (yyss);
+#endif]b4_lac_if([[
+  if (yyes != yyesa)
+    YYSTACK_FREE (yyes);]])])[
 ]b4_parse_error_bmatch([detailed\|verbose],
 [[  if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);]])[
