@@ -187,7 +187,7 @@ b4_pre_prologue[
 ]m4_ifdef([b4_stype],
 [b4_syncline([b4_stype_line], [b4_filename])
 typedef union b4_stype yystype;
-/* Line __line__ of __file__.  */
+/* Line __line__ of glr.c.  */
 b4_syncline([@oline@], [@ofile@])],
 [typedef int yystype;])[
 # define YYSTYPE yystype
@@ -217,7 +217,7 @@ static YYLTYPE yyloc_default;
 /* Copy the second part of user declarations.  */
 ]b4_post_prologue[
 
-]/* Line __line__ of __file__.  */
+]/* Line __line__ of glr.c.  */
 b4_syncline([@oline@], [@ofile@])
 [
 #if ! defined (__cplusplus)
@@ -671,7 +671,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef YYBACKUP
 # undef yyclearin
 # undef YYRECOVERING
-/* Line __line__ of __file__.  */
+/* Line __line__ of glr.c.  */
 b4_syncline([@oline@], [@ofile@])
 }
 
@@ -1959,7 +1959,7 @@ b4_token_defines(b4_tokens)
 m4_ifdef([b4_stype],
 [b4_syncline([b4_stype_line], [b4_filename])
 typedef union b4_stype yystype;
-/* Line __line__ of __file__.  */
+/* Line __line__ of glr.c.  */
 b4_syncline([@oline@], [@ofile@])],
 [typedef int yystype;])
 # define YYSTYPE yystype
