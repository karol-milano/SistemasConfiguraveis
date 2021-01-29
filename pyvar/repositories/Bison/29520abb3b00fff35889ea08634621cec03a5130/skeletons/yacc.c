@@ -176,48 +176,47 @@ YYLTYPE yylloc]b4_yyloc_default[;]])[
 int yynerrs;]])])
 
 
-# b4_declare_parser_state_variables
-# ---------------------------------
+# b4_declare_parser_state_variables([INIT])
+# -----------------------------------------
 # Declare all the variables that are needed to maintain the parser state
 # between calls to yypush_parse.
+# If INIT is non-null, initialize these variables.
 m4_define([b4_declare_parser_state_variables],
 [b4_pure_if([[
     /* Number of syntax errors so far.  */
-    int yynerrs;
+    int yynerrs]m4_ifval([$1], [ = 0])[;
 ]])[
-    yy_state_fast_t yystate;
+    yy_state_fast_t yystate]m4_ifval([$1], [ = 0])[;
     /* Number of tokens to shift before error messages enabled.  */
-    int yyerrstatus;
-
-    /* The stacks and their tools:
-       'yyss': related to states.
-       'yyvs': related to semantic values.]b4_locations_if([[
-       'yyls': related to locations.]])[
+    int yyerrstatus]m4_ifval([$1], [ = 0])[;
 
-       Refer to the stacks through separate pointers, to allow yyoverflow
+    /* Refer to the stacks through separate pointers, to allow yyoverflow
        to reallocate them elsewhere.  */
 
     /* Their size.  */
-    YYPTRDIFF_T yystacksize;
+    YYPTRDIFF_T yystacksize]m4_ifval([$1], [ = YYINITDEPTH])[;
 
-    /* The state stack.  */
+    /* The state stack: array, bottom, top.  */
     yy_state_t yyssa[YYINITDEPTH];
-    yy_state_t *yyss;
-    yy_state_t *yyssp;
+    yy_state_t *yyss]m4_ifval([$1], [ = yyssa])[;
+    yy_state_t *yyssp]m4_ifval([$1], [ = yyss])[;
 
-    /* The semantic value stack.  */
+    /* The semantic value stack: array, bottom, top.  */
     YYSTYPE yyvsa[YYINITDEPTH];
-    YYSTYPE *yyvs;
-    YYSTYPE *yyvsp;]b4_locations_if([[
+    YYSTYPE *yyvs]m4_ifval([$1], [ = yyvsa])[;
+    YYSTYPE *yyvsp]m4_ifval([$1], [ = yyvs])[;]b4_locations_if([[
 
-    /* The location stack.  */
+    /* The location stack: array, bottom, top.  */
     YYLTYPE yylsa[YYINITDEPTH];
-    YYLTYPE *yyls;
-    YYLTYPE *yylsp;]])[]b4_lac_if([[
+    YYLTYPE *yyls]m4_ifval([$1], [ = yylsa])[;
+    YYLTYPE *yylsp]m4_ifval([$1], [ = yyls])[;]])[]b4_lac_if([[
 
     yy_state_t yyesa@{]b4_percent_define_get([[parse.lac.es-capacity-initial]])[@};
-    yy_state_t *yyes;
-    YYPTRDIFF_T yyes_capacity;]])])
+    yy_state_t *yyes]m4_ifval([$1], [ = yyesa])[;
+    YYPTRDIFF_T yyes_capacity][]m4_ifval([$1],
+            [m4_do([ = b4_percent_define_get([[parse.lac.es-capacity-initial]]) < YYMAXDEPTH],
+                   [ ? b4_percent_define_get([[parse.lac.es-capacity-initial]])],
+                   [ : YYMAXDEPTH])])[;]])])
 
 
 # b4_initialize_parser_state_variables
@@ -1542,7 +1541,7 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])[
   YYSTYPE yypushed_val = yylval;]b4_locations_if([[
   YYLTYPE yypushed_loc = yylloc;]])
 ])],
-  [b4_declare_parser_state_variables
+  [b4_declare_parser_state_variables([init])
 ])b4_lac_if([[
   /* Whether LAC context is established.  A Boolean.  */
   int yy_lac_established = 0;]])[
@@ -1569,14 +1568,13 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])[
 
   /* The number of symbols on the RHS of the reduced rule.
      Keep to zero when no symbol should be popped.  */
-  int yylen = 0;
-]b4_push_if([[
+  int yylen = 0;]b4_push_if([[
+
   if (!yyps->yynew)
     {
       yyn = yypact[yystate];
       goto yyread_pushed_token;
-    }]], [
-b4_initialize_parser_state_variables])[
+    }]])[
 
   YYDPRINTF ((stderr, "Starting parse\n"));
 
