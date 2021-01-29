@@ -55,13 +55,12 @@ m4_define([b4_user_formals],
 [m4_ifset([b4_parse_param], [, b4_formals(b4_parse_param)])])
 
 
-# b4_lex_param
-# ------------
-# Accumule in b4_lex_param all the yylex arguments.
-# Yes, this is quite ugly...
-m4_define([b4_lex_param],
-m4_dquote(b4_pure_if([[[[YYSTYPE *]], [[&yylval]]][]dnl
-b4_locations_if([, [[YYLTYPE *], [&yylloc]]])])dnl
+# b4_lex_formals
+# --------------
+# All the yylex formal arguments.
+m4_define([b4_lex_formals],
+m4_dquote(b4_pure_if([[[[YYSTYPE *yylvalp]], [[&yylval]]][]dnl
+b4_locations_if([, [[YYLTYPE *yyllocp], [&yylloc]]])])dnl
 m4_ifdef([b4_lex_param], [, ]b4_lex_param)))
 
 
@@ -408,7 +407,9 @@ dnl We probably ought to introduce a type for confl.
 ]b4_yy_location_print_define[
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
-#define YYLEX ]b4_function_call([yylex], [int], b4_lex_param)[
+#ifndef YYLEX
+# define YYLEX ]b4_function_call([yylex], [int], b4_lex_formals)[
+#endif
 
 ]b4_pure_if(
 [
