@@ -335,9 +335,7 @@ m4_if(b4_api_prefix, [yy], [],
 #define yychar          ]b4_prefix[char]b4_locations_if([[
 #define yylloc          ]b4_prefix[lloc]])]))[
 
-/* Copy the first part of user declarations.  */
 ]b4_user_pre_prologue[
-
 ]b4_null_define[
 
 /* Enabling verbose error messages.  */
@@ -354,9 +352,8 @@ m4_if(b4_api_prefix, [yy], [],
 ]])dnl
 b4_shared_declarations[
 
-/* Copy the second part of user declarations.  */
-]b4_user_post_prologue
-b4_percent_code_get[]dnl
+]b4_user_post_prologue[
+]b4_percent_code_get[]dnl
 
 [#ifdef short
 # undef short
@@ -1433,7 +1430,6 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
 ]m4_ifdef([b4_initial_action], [
 b4_dollar_pushdef([m4_define([b4_dollar_dollar_used])yylval], [],
                   [b4_push_if([b4_pure_if([*])yypushed_loc], [yylloc])])dnl
-/* User initialization code.  */
 b4_user_initial_action
 b4_dollar_popdef[]dnl
 m4_ifdef([b4_dollar_dollar_used],[[  yyvsp[0] = yylval;
@@ -1653,7 +1649,7 @@ yyreduce:
     int yychar_backup = yychar;
     switch (yyn)
       {
-        ]b4_user_actions[
+]b4_user_actions[
         default: break;
       }
     if (yychar_backup != yychar)
