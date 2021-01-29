@@ -115,7 +115,7 @@ m4_define([b4_lhs_value],
 # Expansion of $<TYPE>NUM, where the current rule has RULE-LENGTH
 # symbols on RHS.
 m4_define([b4_rhs_value],
-[yyvsp@<:@m4_eval([$2 - $1])@:>@.yystate.yysemantics.yysval[]m4_ifval([$3], [.$3])])
+[yyvsp@{m4_eval([$2 - $1])@}.yystate.yysemantics.yysval[]m4_ifval([$3], [.$3])])
 
 
 
@@ -135,38 +135,13 @@ m4_define([b4_lhs_location],
 # Expansion of @NUM, where the current rule has RULE-LENGTH symbols
 # on RHS.
 m4_define([b4_rhs_location],
-[yyvsp@<:@m4_eval([$2 - $1])@:>@.yystate.yyloc])
-
-
-
-## ------------------- ##
-## Output file names.  ##
-## ------------------- ##
-
-m4_define_default([b4_input_suffix], [.y])
-
-m4_define_default([b4_output_parser_suffix],
-[m4_translit(b4_input_suffix, [yY], [cC])])
-
-m4_define_default([b4_output_parser_name],
-[b4_output_prefix[]b4_output_infix[]b4_output_parser_suffix[]])
-
-
-m4_define_default([b4_output_header_suffix],
-[m4_translit(b4_input_suffix, [yY], [hH])])
-
-m4_define_default([b4_output_header_name],
-[b4_output_prefix[]b4_output_infix[]b4_output_header_suffix[]])
-
-m4_define_default([b4_header_guard],
-                  [m4_bpatsubst(m4_toupper([BISON_]b4_output_header_name),
-                                [[^ABCDEFGHIJKLMNOPQRSTUVWXYZ]], [_])])
+[yyvsp@{m4_eval([$2 - $1])@}.yystate.yyloc])
 
 
 # We do want M4 expansion after # for CPP macros.
 m4_changecom()
 m4_divert(0)dnl
-#output "b4_output_parser_name"
+@output @output_parser_name@
 b4_copyright([Skeleton parser for GLR parsing with Bison], [2002])
 [
 /* This is the parser code for GLR (Generalized LR) parser. */
@@ -214,7 +189,7 @@ b4_pre_prologue[
 [b4_syncline([b4_stype_line], [b4_filename])
 typedef union b4_stype yystype;
 /* Line __line__ of __file__.  */
-b4_syncline([__oline__], [__ofile__])],
+b4_syncline([@oline@], [@ofile@])],
 [typedef int yystype;])[
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
@@ -234,7 +209,7 @@ typedef struct yyltype
 
 /* Default (constant) values used for initialization for null
    right-hand sides.  Unlike the standard bison.simple template,
-   here we set the default values of the $$ and $@ to zeroed-out
+   here we set the default values of $$ and $@@ to zeroed-out
    values.  Since the default value of these quantities is undefined,
    this behavior is technically correct. */
 static YYSTYPE yyval_default;
@@ -244,7 +219,7 @@ static YYLTYPE yyloc_default;
 ]b4_post_prologue[
 
 ]/* Line __line__ of __file__.  */
-b4_syncline([__oline__], [__ofile__])
+b4_syncline([@oline@], [@ofile@])
 [
 #if ! defined (__cplusplus)
    typedef char bool;
@@ -615,7 +590,7 @@ yytokenName (yySymbol yytoken)
 /** Perform user action for rule number YYN, with RHS length YYRHSLEN,
  *  and top stack item YYVSP.  YYLVALP points to place to put semantic
  *  value ($$), and yylocp points to place for location information
- *  (@$). Returns yyok for normal return, yyaccept for YYACCEPT,
+ *  (@@$). Returns yyok for normal return, yyaccept for YYACCEPT,
  *  yyerr for YYERROR, yyabort for YYABORT. */
 static YYRESULTTAG
 yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
@@ -672,7 +647,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef yyclearin
 # undef YYRECOVERING
 /* Line __line__ of __file__.  */
-b4_syncline([__oline__], [__ofile__])
+b4_syncline([@oline@], [@ofile@])
 }
 
 
@@ -1867,7 +1842,7 @@ yy_yypstack (yyGLRState* yys)
       yy_yypstack (yys->yypred);
       fprintf (stderr, " -> ");
     }
-  fprintf (stderr, "%d@%lu", yys->yylrState, (unsigned long) yys->yyposn);
+  fprintf (stderr, "%d@@%lu", yys->yylrState, (unsigned long) yys->yyposn);
 }
 
 static void
@@ -1927,10 +1902,8 @@ yypdumpstack (yyGLRStack* yystack)
 
 b4_epilogue
 m4_if(b4_defines_flag, 0, [],
-[#output "b4_output_header_name"
+[@output @output_header_name@
 b4_copyright([Skeleton parser for GLR parsing with Bison], [2002])
-#ifndef b4_header_guard
-# define b4_header_guard
 
 b4_token_defines(b4_tokens)
 
@@ -1939,9 +1912,10 @@ m4_ifdef([b4_stype],
 [b4_syncline([b4_stype_line], [b4_filename])
 typedef union b4_stype yystype;
 /* Line __line__ of __file__.  */
-b4_syncline([__oline__], [__ofile__])],
+b4_syncline([@oline@], [@ofile@])],
 [typedef int yystype;])
 # define YYSTYPE yystype
+# define YYSTYPE_IS_TRIVIAL 1
 #endif
 
 b4_pure_if([],
@@ -1962,5 +1936,4 @@ typedef struct yyltype
 m4_if(b4_pure, [0],
 [extern YYLTYPE b4_prefix[]lloc;])
 ])
-#endif /* not b4_header_guard */
 ])
