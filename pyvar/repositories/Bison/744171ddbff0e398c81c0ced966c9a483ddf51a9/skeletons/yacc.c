@@ -195,6 +195,9 @@ m4_define([b4_declare_parser_state_variables],
        Refer to the stacks through separate pointers, to allow yyoverflow
        to reallocate them elsewhere.  */
 
+    /* Their size.  */
+    YYPTRDIFF_T yystacksize;
+
     /* The state stack.  */
     yy_state_t yyssa[YYINITDEPTH];
     yy_state_t *yyss;
@@ -211,15 +214,34 @@ m4_define([b4_declare_parser_state_variables],
     YYLTYPE *yylsp;
 
     /* The locations where the error started and ended.  */
-    YYLTYPE yyerror_range[3];]])[
-
-    YYPTRDIFF_T yystacksize;]b4_lac_if([[
+    YYLTYPE yyerror_range[3];]])[]b4_lac_if([[
 
     yy_state_t yyesa@{]b4_percent_define_get([[parse.lac.es-capacity-initial]])[@};
     yy_state_t *yyes;
     YYPTRDIFF_T yyes_capacity;]])])
 
 
+# b4_initialize_parser_state_variables
+# ------------------------------------
+# Initialize these variables.
+m4_define([b4_initialize_parser_state_variables],
+[[  yynerrs = 0;
+  yystate = 0;
+  yyerrstatus = 0;
+
+  yystacksize = YYINITDEPTH;
+  yyssp = yyss = yyssa;
+  yyvsp = yyvs = yyvsa;]b4_locations_if([[
+  yylsp = yyls = yylsa;]])[]b4_lac_if([[
+
+  yyes = yyesa;
+  yyes_capacity = ]b4_percent_define_get([[parse.lac.es-capacity-initial]])[;
+  if (YYMAXDEPTH < yyes_capacity)
+    yyes_capacity = YYMAXDEPTH;]])[
+]])
+
+
+
 # _b4_declare_yyparse_push
 # ------------------------
 # Declaration of yyparse (and dependencies) when using the push parser
@@ -328,6 +350,7 @@ m4_if(b4_api_prefix, [yy], [],
 #define yypush_parse    ]b4_prefix[push_parse]b4_pull_if([[
 #define yypull_parse    ]b4_prefix[pull_parse]])[
 #define yypstate_new    ]b4_prefix[pstate_new
+#define yypstate_clear  ]b4_prefix[pstate_clear
 #define yypstate_delete ]b4_prefix[pstate_delete
 #define yypstate        ]b4_prefix[pstate]])[
 #define yylex           ]b4_prefix[lex
@@ -1382,8 +1405,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
 ]b4_push_if([[
 struct yypstate
   {]b4_declare_parser_state_variables[
-    /* Used to determine if this is the first time this instance has
-       been used.  */
+    /* Whether this instance has not started parsing yet.  */
     int yynew;
   };]b4_pure_if([], [[
 
@@ -1425,6 +1447,34 @@ yypull_parse (yypstate *yyps]b4_user_formals[)
   return yystatus;
 }]])[
 
+]b4_pure_if([[#define ]b4_prefix[nerrs yyps->]b4_prefix[nerrs]])[
+#define yystate yyps->yystate
+#define yyerrstatus yyps->yyerrstatus
+#define yyssa yyps->yyssa
+#define yyss yyps->yyss
+#define yyssp yyps->yyssp
+#define yyvsa yyps->yyvsa
+#define yyvs yyps->yyvs
+#define yyvsp yyps->yyvsp]b4_locations_if([[
+#define yylsa yyps->yylsa
+#define yyls yyps->yyls
+#define yylsp yyps->yylsp
+#define yyerror_range yyps->yyerror_range]])[
+#define yystacksize yyps->yystacksize]b4_lac_if([[
+#define yyesa yyps->yyesa
+#define yyes yyps->yyes
+#define yyes_capacity yyps->yyes_capacity]])[
+
+/* Initialize the parser data structure.  */
+void
+yypstate_clear (yypstate *yyps)
+{
+]b4_initialize_parser_state_variables[
+  /* Initialize the state stack, in case yyexpected_tokens is called
+     before the first call to yyparse. */
+  *yyssp = 0;
+}
+
 /* Initialize the parser data structure.  */
 yypstate *
 yypstate_new (void)
@@ -1437,6 +1487,7 @@ yypstate_new (void)
     return YY_NULLPTR;
   yyps->yynew = 1;]b4_pure_if([], [[
   yypstate_allocated = 1;]])[
+  yypstate_clear (yyps);
   return yyps;
 }
 
@@ -1448,33 +1499,15 @@ yypstate_delete (yypstate *yyps)
 #ifndef yyoverflow
       /* If the stack was reallocated but the parse did not complete, then the
          stack still needs to be freed.  */
-      if (!yyps->yynew && yyps->yyss != yyps->yyssa)
-        YYSTACK_FREE (yyps->yyss);
+      if (!yyps->yynew && yyss != yyssa)
+        YYSTACK_FREE (yyss);
 #endif]b4_lac_if([[
-      if (!yyps->yynew && yyps->yyes != yyps->yyesa)
-        YYSTACK_FREE (yyps->yyes);]])[
+      if (!yyps->yynew && yyes != yyesa)
+        YYSTACK_FREE (yyes);]])[
       free (yyps);]b4_pure_if([], [[
       yypstate_allocated = 0;]])[
     }
 }
-]b4_pure_if([[
-#define ]b4_prefix[nerrs yyps->]b4_prefix[nerrs]])[
-#define yystate yyps->yystate
-#define yyerrstatus yyps->yyerrstatus
-#define yyssa yyps->yyssa
-#define yyss yyps->yyss
-#define yyssp yyps->yyssp
-#define yyvsa yyps->yyvsa
-#define yyvs yyps->yyvs
-#define yyvsp yyps->yyvsp]b4_locations_if([[
-#define yylsa yyps->yylsa
-#define yyls yyps->yyls
-#define yylsp yyps->yylsp
-#define yyerror_range yyps->yyerror_range]])[
-#define yystacksize yyps->yystacksize]b4_lac_if([[
-#define yyesa yyps->yyesa
-#define yyes yyps->yyes
-#define yyes_capacity yyps->yyes_capacity]])[
 ]])[
 
 ]b4_push_if([[
@@ -1522,29 +1555,17 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])[
 
   /* The number of symbols on the RHS of the reduced rule.
      Keep to zero when no symbol should be popped.  */
-  int yylen = 0;]b4_push_if([[
-
+  int yylen = 0;
+]b4_push_if([[
   if (!yyps->yynew)
     {
       yyn = yypact[yystate];
       goto yyread_pushed_token;
-    }]])[
-
-  yyssp = yyss = yyssa;
-  yyvsp = yyvs = yyvsa;]b4_locations_if([[
-  yylsp = yyls = yylsa;]])[
-  yystacksize = YYINITDEPTH;]b4_lac_if([[
-
-  yyes = yyesa;
-  yyes_capacity = ]b4_percent_define_get([[parse.lac.es-capacity-initial]])[;
-  if (YYMAXDEPTH < yyes_capacity)
-    yyes_capacity = YYMAXDEPTH;]])[
+    }]], [
+b4_initialize_parser_state_variables])[
 
   YYDPRINTF ((stderr, "Starting parse\n"));
 
-  yystate = 0;
-  yyerrstatus = 0;
-  yynerrs = 0;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 ]m4_ifdef([b4_initial_action], [
 b4_dollar_pushdef([m4_define([b4_dollar_dollar_used])yylval], [], [],
@@ -2033,6 +2054,7 @@ yyreturn:
 #endif]b4_lac_if([[
   if (yyes != yyesa)
     YYSTACK_FREE (yyes);]])b4_push_if([[
+  yypstate_clear (yyps);
   yyps->yynew = 1;
 
 
