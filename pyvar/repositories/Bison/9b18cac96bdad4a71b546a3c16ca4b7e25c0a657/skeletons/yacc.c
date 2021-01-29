@@ -2182,7 +2182,8 @@ yypushreturn:]], [[
 ]b4_parse_error_bmatch([detailed\|verbose],
 [[  if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);]])[]m4_ifdef([b4_start_symbols], [[
-  yyimpl->yynerrs = yynerrs;]])[
+  if (yyimpl)
+    yyimpl->yynerrs = yynerrs;]])[
   return yyresult;
 }
 ]b4_push_if([b4_parse_state_variable_macros([b4_macro_undef])])[
