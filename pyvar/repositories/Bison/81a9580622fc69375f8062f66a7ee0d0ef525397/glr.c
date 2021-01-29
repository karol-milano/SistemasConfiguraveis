@@ -236,7 +236,6 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 #define yynerrs ]b4_prefix[nerrs]b4_locations_if([[
 #define yylloc  ]b4_prefix[lloc]])]))[
 
-/* First part of user declarations.  */
 ]b4_user_pre_prologue[
 
 ]b4_null_define[
@@ -259,9 +258,8 @@ b4_copyright([Skeleton implementation for Bison GLR parsers in C],
 static YYSTYPE yyval_default;]b4_locations_if([[
 static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 
-/* Copy the second part of user declarations.  */
-]b4_user_post_prologue
-b4_percent_code_get[]dnl
+]b4_user_post_prologue[
+]b4_percent_code_get[]dnl
 
 [#include <stdio.h>
 #include <stdlib.h>
@@ -820,7 +818,7 @@ yyuserAction (yyRuleNum yyn, size_t yyrhslen, yyGLRStackItem* yyvsp,
 ]])[
   switch (yyn)
     {
-      ]b4_user_actions[
+]b4_user_actions[
       default: break;
     }
 
@@ -2266,7 +2264,6 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   yylloc = yyloc_default;])[
 ]m4_ifdef([b4_initial_action], [
 b4_dollar_pushdef([yylval], [], [yylloc])dnl
-  /* User initialization code.  */
   b4_user_initial_action
 b4_dollar_popdef])[]dnl
 [
