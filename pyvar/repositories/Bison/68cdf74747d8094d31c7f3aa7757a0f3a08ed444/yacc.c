@@ -58,8 +58,8 @@ m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 # b4_lex_param arrives quoted twice, but we want to keep only one level.
 m4_define([b4_lex_param],
 m4_dquote(b4_pure_if([[[[YYSTYPE *]], [[&yylval]]][]dnl
-b4_location_if([, [[YYLTYPE *], [&yylloc]]])])dnl
-m4_ifdef([b4_lex_param], [, ]b4_lex_param)))
+b4_location_if([, [[YYLTYPE *], [&yylloc]]])m4_ifdef([b4_lex_param], [, ])])dnl
+m4_ifdef([b4_lex_param], b4_lex_param)))
 
 
 
