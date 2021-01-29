@@ -105,8 +105,8 @@ m4_ifset([b4_parse_param], [b4_args(b4_parse_param), ])])
 # Accumulate in b4_lex_param all the yylex arguments.
 # b4_lex_param arrives quoted twice, but we want to keep only one level.
 m4_define([b4_lex_param],
-m4_dquote(b4_pure_if([[[[YYSTYPE *]], [[&yylval]]][]dnl
-b4_locations_if([, [[YYLTYPE *], [&yylloc]]])m4_ifdef([b4_lex_param], [, ])])dnl
+m4_dquote(b4_pure_if([[[[YYSTYPE *yylval]], [[&yylval]]][]dnl
+b4_locations_if([, [[YYLTYPE *yylloc], [&yylloc]]])m4_ifdef([b4_lex_param], [, ])])dnl
 m4_ifdef([b4_lex_param], b4_lex_param)))
 
 
