@@ -198,7 +198,7 @@ m4_define([_b4_first_switching_token],
 m4_define([_b4_define_sub_yyparse],
 [[
 ]b4_prefix[parse_]_b4_symbol($1, id)[_t
-yyparse_]_b4_symbol($1, id)[ (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
+]b4_prefix[parse_]_b4_symbol($1, id)[ (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)
 {
   ]b4_prefix[parse_]_b4_symbol($1, id)[_t yyres;
   yy_parse_impl_t yyimpl;
