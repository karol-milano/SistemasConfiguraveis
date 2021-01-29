@@ -55,15 +55,6 @@ m4_define([b4_user_formals],
 [m4_ifset([b4_parse_param], [, b4_formals(b4_parse_param)])])
 
 
-# b4_lex_formals
-# --------------
-# All the yylex formal arguments.
-m4_define([b4_lex_formals],
-m4_dquote(b4_pure_if([[[[YYSTYPE *yylvalp]], [[&yylval]]][]dnl
-b4_locations_if([, [[YYLTYPE *yyllocp], [&yylloc]]])])dnl
-m4_ifdef([b4_lex_param], [, ]b4_lex_param)))
-
-
 # b4_yyerror_args
 # ---------------
 # Optional effective arguments passed to yyerror: user args plus yylloc, and
@@ -406,11 +397,6 @@ dnl We probably ought to introduce a type for confl.
 ]])[
 ]b4_yy_location_print_define[
 
-/* YYLEX -- calling `yylex' with the right arguments.  */
-#ifndef YYLEX
-# define YYLEX ]b4_function_call([yylex], [int], b4_lex_formals)[
-#endif
-
 ]b4_pure_if(
 [
 #undef yynerrs
@@ -1926,7 +1912,7 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
           if (yychar == YYEMPTY)
             {
               YYDPRINTF ((stderr, "Reading a token: "));
-              yychar = YYLEX;
+              yychar = ]b4_lex[;
             }
 
           if (yychar <= YYEOF)
@@ -2161,7 +2147,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
                         yytoken, &yylval]b4_locuser_args([&yylloc])[);
           }
         YYDPRINTF ((stderr, "Reading a token: "));
-        yychar = YYLEX;
+        yychar = ]b4_lex[;
         if (yychar <= YYEOF)
           {
             yychar = yytoken = YYEOF;
@@ -2315,7 +2301,7 @@ b4_dollar_popdef])[]dnl
               if (yychar == YYEMPTY)
                 {
                   YYDPRINTF ((stderr, "Reading a token: "));
-                  yychar = YYLEX;
+                  yychar = ]b4_lex[;
                 }
 
               if (yychar <= YYEOF)
