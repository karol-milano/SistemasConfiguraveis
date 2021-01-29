@@ -178,9 +178,7 @@ b4_token_enums(b4_tokens)
 [#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 ]m4_ifdef([b4_stype],
 [typedef union b4_union_name
-b4_stype
-/* Line __line__ of glr.c.  */
-b4_syncline([@oline@], [@ofile@])
+b4_user_stype
 	YYSTYPE;],
 [typedef int YYSTYPE;])[
 # define YYSTYPE_IS_DECLARED 1
@@ -237,11 +235,8 @@ b4_defines_if([#include @output_header_name@],
 static YYSTYPE yyval_default;
 
 /* Copy the second part of user declarations.  */
-]b4_post_prologue[
+]b4_user_post_prologue[
 
-]/* Line __line__ of glr.c.  */
-b4_syncline([@oline@], [@ofile@])
-[
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -934,9 +929,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 ]])[
   switch (yyn)
     {
-      ]b4_actions
-/* Line __line__ of glr.c.  */
-b4_syncline([@oline@], [@ofile@])[
+      ]b4_user_actions[
       default: break;
     }
 
@@ -2318,11 +2311,9 @@ m4_ifdef([b4_initial_action], [
 m4_pushdef([b4_at_dollar],     [yylloc])dnl
 m4_pushdef([b4_dollar_dollar], [yylval])dnl
   /* User initialization code.  */
-  b4_initial_action
+  b4_user_initial_action
 m4_popdef([b4_dollar_dollar])dnl
-m4_popdef([b4_at_dollar])dnl
-/* Line __line__ of glr.c.  */
-b4_syncline([@oline@], [@ofile@])])dnl
+m4_popdef([b4_at_dollar])])dnl
 [
   if (! yyinitGLRStack (yystackp, YYINITDEPTH))
     goto yyexhaustedlab;
