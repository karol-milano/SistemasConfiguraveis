@@ -100,15 +100,6 @@ m4_define([b4_yyerror_args],
 m4_ifset([b4_parse_param], [b4_args(b4_parse_param), ])])
 
 
-# b4_lex_param
-# ------------
-# Accumulate in b4_lex_param all the yylex arguments.
-# b4_lex_param arrives quoted twice, but we want to keep only one level.
-m4_define([b4_lex_param],
-m4_dquote(b4_pure_if([[[[YYSTYPE *yylval]], [[&yylval]]][]dnl
-b4_locations_if([, [[YYLTYPE *yylloc], [&yylloc]]])m4_ifdef([b4_lex_param], [, ])])dnl
-m4_ifdef([b4_lex_param], b4_lex_param)))
-
 
 ## ------------ ##
 ## Data Types.  ##
@@ -686,9 +677,6 @@ while (0)
 ]])[
 ]b4_yy_location_print_define[
 
-/* YYLEX -- calling `yylex' with the right arguments.  */
-#define YYLEX ]b4_function_call([yylex], [int], b4_lex_param)[
-
 /* Enable debugging if requested.  */
 #if ]b4_api_PREFIX[DEBUG
 
@@ -1332,7 +1320,7 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
         }
     }
   do {
-    yychar = YYLEX;
+    yychar = ]b4_lex[;
     yystatus =
       yypush_parse (yyps_local]b4_pure_if([[, yychar, &yylval]b4_locations_if([[, &yylloc]])])m4_ifset([b4_parse_param], [, b4_args(b4_parse_param)])[);
   } while (yystatus == YYPUSH_MORE);
@@ -1593,7 +1581,7 @@ yyread_pushed_token:]])[
         yylval = *yypushed_val;]b4_locations_if([[
       if (yypushed_loc)
         yylloc = *yypushed_loc;]])])], [[
-      yychar = YYLEX;]])[
+      yychar = ]b4_lex[;]])[
     }
 
   if (yychar <= YYEOF)
