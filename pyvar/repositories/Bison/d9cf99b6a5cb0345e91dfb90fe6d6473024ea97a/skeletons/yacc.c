@@ -116,6 +116,16 @@ m4_ifset([b4_parse_param], [b4_args(b4_parse_param), ])])
 ## ----------------- ##
 
 
+# b4_accept([SYMBOL-NUM])
+# -----------------------
+# Used in actions of the rules of accept, the initial symbol, to call
+# YYACCEPT.  If SYMBOL-NUM is specified, run "yyvalue->SLOT = $2;"
+# before, using the slot of SYMBOL-NUM.
+m4_define([b4_accept],
+[m4_ifval([$1],
+          [b4_symbol_value((*yyvalue), [$1]) = b4_rhs_value(2, 1, [$1]); ])YYACCEPT])
+
+
 # b4_lhs_value(SYMBOL-NUM, [TYPE])
 # --------------------------------
 # See README.
@@ -155,21 +165,48 @@ m4_define([b4_rhs_location],
 ## Declarations.  ##
 ## -------------- ##
 
-# _b4_declare_sub_yyparse(START-SYMBOL-NUM)
-# -----------------------------------
+# _b4_declare_sub_yyparse(START-SYMBOL-NUM, SWITCHING-TOKEN-SYMBOL-NUM)
+# ---------------------------------------------------------------------
+# Define the return type of the parsing function for SYMBOL-NUM, and
+# declare its parsing function.
 m4_define([_b4_declare_sub_yyparse],
-[[int ]b4_prefix[parse_]_b4_symbol($1, id)[ (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[);]])
+[[
+// Return type when parsing one ]_b4_symbol($1, tag)[.
+typedef struct
+{]b4_symbol_if([$1], [has_type], [[
+  ]_b4_symbol($1, type)[ yyvalue;]])[
+  int yystatus;
+} ]b4_prefix[parse_]_b4_symbol($1, id)[_t;
+
+// Parse one ]_b4_symbol($1, tag)[.
+]b4_prefix[parse_]_b4_symbol($1, id)[_t ]b4_prefix[parse_]_b4_symbol($1, id)[ (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[);
+]])
+
+
+# _b4_first_switching_token
+# -------------------------
+m4_define([b4_first], [$1])
+m4_define([b4_second], [$2])
+m4_define([_b4_first_switching_token],
+[b4_second(b4_first(b4_start_symbols))])
 
 
 # _b4_define_sub_yyparse(START-SYMBOL-NUM, SWITCHING-TOKEN-SYMBOL-NUM)
 # --------------------------------------------------------------------
+# Define the parsing function for START-SYMBOL-NUM.
 m4_define([_b4_define_sub_yyparse],
-[[int
+[[
+]b4_prefix[parse_]_b4_symbol($1, id)[_t
 yyparse_]_b4_symbol($1, id)[ (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
 {
-  return yyparse_impl (]b4_symbol($2, id)[]m4_ifset([b4_parse_param],
-                                                    [[, ]b4_args(b4_parse_param)])[);
-}]])
+  ]b4_prefix[parse_]_b4_symbol($1, id)[_t yyres;
+  YYSTYPE yyvalue;
+  yyres.yystatus = yy_parse_impl (]b4_symbol($2, id)[, &yyvalue]m4_ifset([b4_parse_param],
+                           [[, ]b4_args(b4_parse_param)])[);]b4_symbol_if([$1], [has_type], [[
+  yyres.yyvalue = yyvalue.]b4_symbol($1, slot)[;]])[
+  return yyres;
+}
+]])
 
 
 # b4_declare_scanner_communication_variables
@@ -179,8 +216,8 @@ yyparse_]_b4_symbol($1, id)[ (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_p
 m4_define([b4_declare_scanner_communication_variables], [[
 ]m4_ifdef([b4_start_symbols], [],
 [[/* Lookahead token kind.  */
-int yychar;]])[
-
+int yychar;
+]])[
 ]b4_pure_if([[
 /* The semantic value of the lookahead symbol.  */
 /* Default value used for initialization, for pacifying older GCCs
@@ -1560,20 +1597,19 @@ yypush_parse (yypstate *yyps]b4_pure_if([[,
 ]m4_ifdef([b4_start_symbols],
 [[
 static int
-yyparse_impl (int yychar]m4_ifset([b4_parse_param], [, b4_formals(b4_parse_param)])[);
+yy_parse_impl (int yychar, YYSTYPE *yyvalue]m4_ifset([b4_parse_param], [, b4_formals(b4_parse_param)])[);
 
 ]m4_map([_b4_define_sub_yyparse], m4_defn([b4_start_symbols]))[
 
 int
 yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
 {
-  /* ]b4_symbol(-2, id)[ causes a token to be read.  */
-  return yyparse_impl (]b4_symbol(-2, id)[]m4_ifset([b4_parse_param],
+  return yy_parse_impl (]b4_symbol(_b4_first_switching_token, id)[, YY_NULLPTR]m4_ifset([b4_parse_param],
                                                     [[, ]b4_args(b4_parse_param)])[);
 }
 
 static int
-yyparse_impl (int yychar]m4_ifset([b4_parse_param], [, b4_formals(b4_parse_param)])[)]],
+yy_parse_impl (int yychar, YYSTYPE *yyvalue]m4_ifset([b4_parse_param], [, b4_formals(b4_parse_param)])[)]],
 [[int
 yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])])[
 {]b4_pure_if([b4_declare_scanner_communication_variables
@@ -1812,9 +1848,7 @@ yyread_pushed_token:]])[
     {
       if (yytable_value_is_error (yyn))
         goto yyerrlab;
-      yyn = -yyn;]m4_ifdef([b4_start_symbols], [[
-      if (yyr1[yyn] == YYNTOKENS)
-        YYACCEPT;]])[]b4_lac_if([[
+      yyn = -yyn;]b4_lac_if([[
       YY_LAC_ESTABLISH;]])[
       goto yyreduce;
     }
@@ -1844,9 +1878,7 @@ yyread_pushed_token:]])[
 yydefault:
   yyn = yydefact[yystate];
   if (yyn == 0)
-    goto yyerrlab;]m4_ifdef([b4_start_symbols], [[
-  else if (yyr1[yyn] == YYNTOKENS)
-    YYACCEPT;]])[
+    goto yyerrlab;
   goto yyreduce;
 
 
