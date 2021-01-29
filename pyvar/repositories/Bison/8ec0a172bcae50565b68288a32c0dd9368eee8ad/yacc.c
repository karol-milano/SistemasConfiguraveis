@@ -190,9 +190,7 @@ b4_token_enums_defines(b4_tokens)[
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 ]m4_ifdef([b4_stype],
 [[typedef union ]b4_union_name
-b4_stype
-/* Line __line__ of yacc.c.  */
-b4_syncline([@oline@], [@ofile@])
+b4_user_stype
 	YYSTYPE;],
 [typedef int YYSTYPE;])[
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -218,10 +216,7 @@ m4_ifdef([b4_end_header],
 ]b4_end_header])[]dnl
 
 [/* Copy the second part of user declarations.  */
-]b4_post_prologue
-
-[/* Line __line__ of yacc.c.  */
-]b4_syncline([@oline@], [@ofile@])[
+]b4_user_post_prologue[
 
 #ifdef short
 # undef short
@@ -1077,12 +1072,9 @@ m4_ifdef([b4_initial_action], [
 m4_pushdef([b4_at_dollar],     [m4_define([b4_at_dollar_used])yylloc])dnl
 m4_pushdef([b4_dollar_dollar], [m4_define([b4_dollar_dollar_used])yylval])dnl
   /* User initialization code.  */
-b4_initial_action
+  b4_user_initial_action
 m4_popdef([b4_dollar_dollar])dnl
-m4_popdef([b4_at_dollar])dnl
-/* Line __line__ of yacc.c.  */
-b4_syncline([@oline@], [@ofile@])
-])dnl
+m4_popdef([b4_at_dollar])])dnl
 m4_ifdef([b4_dollar_dollar_used],[[  yyvsp[0] = yylval;
 ]])dnl
 m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
@@ -1270,9 +1262,7 @@ yyreduce:
   YY_REDUCE_PRINT (yyn);
   switch (yyn)
     {
-      ]b4_actions
-/* Line __line__ of yacc.c.  */
-b4_syncline([@oline@], [@ofile@])[
+      ]b4_user_actions[
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -1507,9 +1497,7 @@ b4_token_enums_defines(b4_tokens)
 [#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 ]m4_ifdef([b4_stype],
 [[typedef union ]b4_union_name
-b4_stype
-/* Line __line__ of yacc.c.  */
-b4_syncline([@oline@], [@ofile@])
+b4_user_stype
 	YYSTYPE;],
 [typedef int YYSTYPE;])[
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
