@@ -22,6 +22,7 @@ m4_pushdef([b4_copyright_years],
 
 m4_include(b4_skeletonsdir/[c.m4])
 
+
 ## ---------- ##
 ## api.pure.  ##
 ## ---------- ##
@@ -154,13 +155,31 @@ m4_define([b4_rhs_location],
 ## Declarations.  ##
 ## -------------- ##
 
+# _b4_declare_sub_yyparse(START-SYMBOL-NUM)
+# -----------------------------------
+m4_define([_b4_declare_sub_yyparse],
+[[int ]b4_prefix[parse_]_b4_symbol($1, id)[ (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[);]])
+
+
+# _b4_define_sub_yyparse(START-SYMBOL-NUM, SWITCHING-TOKEN-SYMBOL-NUM)
+# --------------------------------------------------------------------
+m4_define([_b4_define_sub_yyparse],
+[[int
+yyparse_]_b4_symbol($1, id)[ (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
+{
+  return yyparse_impl (]b4_symbol($2, id)[]m4_ifset([b4_parse_param],
+                                                    [[, ]b4_args(b4_parse_param)])[);
+}]])
+
+
 # b4_declare_scanner_communication_variables
 # ------------------------------------------
 # Declare the variables that are global, or local to YYPARSE if
 # pure-parser.
 m4_define([b4_declare_scanner_communication_variables], [[
-/* Lookahead token kind.  */
-int yychar;
+]m4_ifdef([b4_start_symbols], [],
+[[/* Lookahead token kind.  */
+int yychar;]])[
 
 ]b4_pure_if([[
 /* The semantic value of the lookahead symbol.  */
@@ -276,11 +295,14 @@ int ]b4_prefix[push_parse (]b4_prefix[pstate *ps]b4_pure_if([[,
 void ]b4_prefix[pstate_delete (]b4_prefix[pstate *ps);
 ]])
 
+
 # _b4_declare_yyparse
 # -------------------
 # When not the push parser.
 m4_define([_b4_declare_yyparse],
-[[int ]b4_prefix[parse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[);]])
+[[int ]b4_prefix[parse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[);
+]m4_ifdef([b4_start_symbols],
+          [m4_map([_b4_declare_sub_yyparse], m4_defn([b4_start_symbols]))])])
 
 
 # b4_declare_yyparse
@@ -291,6 +313,7 @@ m4_define([b4_declare_yyparse],
 ])
 
 
+
 # b4_shared_declarations
 # ----------------------
 # Declaration that might either go into the header (if --header)
@@ -1534,8 +1557,25 @@ yypush_parse (yypstate *yyps]b4_pure_if([[,
 | yyparse.  |
 `----------*/
 
+]m4_ifdef([b4_start_symbols],
+[[
+static int
+yyparse_impl (int yychar]m4_ifset([b4_parse_param], [, b4_formals(b4_parse_param)])[);
+
+]m4_map([_b4_define_sub_yyparse], m4_defn([b4_start_symbols]))[
+
 int
-yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])[
+yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
+{
+  /* ]b4_symbol(-2, id)[ causes a token to be read.  */
+  return yyparse_impl (]b4_symbol(-2, id)[]m4_ifset([b4_parse_param],
+                                                    [[, ]b4_args(b4_parse_param)])[);
+}
+
+static int
+yyparse_impl (int yychar]m4_ifset([b4_parse_param], [, b4_formals(b4_parse_param)])[)]],
+[[int
+yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])])[
 {]b4_pure_if([b4_declare_scanner_communication_variables
 ])b4_push_if([b4_pure_if([], [[
   int yypushed_char = yychar;
@@ -1585,7 +1625,9 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])[
 
   YYDPRINTF ((stderr, "Starting parse\n"));
 
-  yychar = ]b4_symbol(-2, id)[; /* Cause a token to be read.  */
+]m4_ifdef([b4_start_symbols], [],
+[[  yychar = ]b4_symbol(-2, id)[; /* Cause a token to be read.  */
+]])[
 ]m4_ifdef([b4_initial_action], [
 b4_dollar_pushdef([m4_define([b4_dollar_dollar_used])yylval], [], [],
                   [b4_push_if([b4_pure_if([*])yypushed_loc], [yylloc])])dnl
@@ -1686,8 +1728,9 @@ yysetstate:
     }
 #endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */
 
+]m4_ifdef([b4_start_symbols], [], [[
   if (yystate == YYFINAL)
-    YYACCEPT;
+    YYACCEPT;]])[
 
   goto yybackup;
 
@@ -1768,9 +1811,11 @@ yyread_pushed_token:]])[
   if (yyn <= 0)
     {
       if (yytable_value_is_error (yyn))
-        goto yyerrlab;]b4_lac_if([[
+        goto yyerrlab;
+      yyn = -yyn;]m4_ifdef([b4_start_symbols], [[
+      if (yyr1[yyn] == YYNTOKENS)
+        YYACCEPT;]])[]b4_lac_if([[
       YY_LAC_ESTABLISH;]])[
-      yyn = -yyn;
       goto yyreduce;
     }
 
@@ -1799,7 +1844,9 @@ yyread_pushed_token:]])[
 yydefault:
   yyn = yydefact[yystate];
   if (yyn == 0)
-    goto yyerrlab;
+    goto yyerrlab;]m4_ifdef([b4_start_symbols], [[
+  else if (yyr1[yyn] == YYNTOKENS)
+    YYACCEPT;]])[
   goto yyreduce;
 
 
