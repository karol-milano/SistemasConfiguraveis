@@ -123,7 +123,7 @@ m4_ifset([b4_parse_param], [b4_args(b4_parse_param), ])])
 # before, using the slot of SYMBOL-NUM.
 m4_define([b4_accept],
 [m4_ifval([$1],
-          [b4_symbol_value((*yyvalue), [$1]) = b4_rhs_value(2, 1, [$1]); ])YYACCEPT])
+          [b4_symbol_value(yyimpl->yyvalue, [$1]) = b4_rhs_value(2, 1, [$1]); ]) YYACCEPT])
 
 
 # b4_lhs_value(SYMBOL-NUM, [TYPE])
@@ -176,6 +176,7 @@ typedef struct
 {]b4_symbol_if([$1], [has_type], [[
   ]_b4_symbol($1, type)[ yyvalue;]])[
   int yystatus;
+  int yynerrs;
 } ]b4_prefix[parse_]_b4_symbol($1, id)[_t;
 
 // Parse one ]_b4_symbol($1, tag)[.
@@ -200,10 +201,11 @@ m4_define([_b4_define_sub_yyparse],
 yyparse_]_b4_symbol($1, id)[ (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
 {
   ]b4_prefix[parse_]_b4_symbol($1, id)[_t yyres;
-  YYSTYPE yyvalue;
-  yyres.yystatus = yy_parse_impl (]b4_symbol($2, id)[, &yyvalue]m4_ifset([b4_parse_param],
+  yy_parse_impl_t yyimpl;
+  yyres.yystatus = yy_parse_impl (]b4_symbol($2, id)[, &yyimpl]m4_ifset([b4_parse_param],
                            [[, ]b4_args(b4_parse_param)])[);]b4_symbol_if([$1], [has_type], [[
-  yyres.yyvalue = yyvalue.]b4_symbol($1, slot)[;]])[
+  yyres.yyvalue = yyimpl.yyvalue.]b4_symbol($1, slot)[;]])[
+  yyres.yynerrs = yyimpl.yynerrs;
   return yyres;
 }
 ]])
@@ -1595,9 +1597,16 @@ yypush_parse (yypstate *yyps]b4_pure_if([[,
 `----------*/
 
 ]m4_ifdef([b4_start_symbols],
-[[
+[[// Extract data from the parser.
+typedef struct
+{
+  YYSTYPE yyvalue;
+  int yynerrs;
+} yy_parse_impl_t;
+
+// Run a full parse, using YYCHAR as switching token.
 static int
-yy_parse_impl (int yychar, YYSTYPE *yyvalue]m4_ifset([b4_parse_param], [, b4_formals(b4_parse_param)])[);
+yy_parse_impl (int yychar, yy_parse_impl_t *yyimpl]m4_ifset([b4_parse_param], [, b4_formals(b4_parse_param)])[);
 
 ]m4_map([_b4_define_sub_yyparse], m4_defn([b4_start_symbols]))[
 
@@ -1609,7 +1618,7 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
 }
 
 static int
-yy_parse_impl (int yychar, YYSTYPE *yyvalue]m4_ifset([b4_parse_param], [, b4_formals(b4_parse_param)])[)]],
+yy_parse_impl (int yychar, yy_parse_impl_t *yyimpl]m4_ifset([b4_parse_param], [, b4_formals(b4_parse_param)])[)]],
 [[int
 yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])])[
 {]b4_pure_if([b4_declare_scanner_communication_variables
@@ -2172,7 +2181,8 @@ yypushreturn:]], [[
     YYSTACK_FREE (yyes);]])])[
 ]b4_parse_error_bmatch([detailed\|verbose],
 [[  if (yymsg != yymsgbuf)
-    YYSTACK_FREE (yymsg);]])[
+    YYSTACK_FREE (yymsg);]])[]m4_ifdef([b4_start_symbols], [[
+  yyimpl->yynerrs = yynerrs;]])[
   return yyresult;
 }
 ]b4_push_if([b4_parse_state_variable_macros([b4_macro_undef])])[
