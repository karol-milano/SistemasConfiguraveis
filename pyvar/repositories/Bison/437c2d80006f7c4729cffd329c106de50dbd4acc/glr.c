@@ -195,10 +195,10 @@ b4_pre_prologue[
 
 #ifndef YYSTYPE
 ]m4_ifdef([b4_stype],
-[#line b4_stype_line "b4_filename"
+[b4_syncline([b4_stype_line], [b4_filename])
 typedef union b4_stype yystype;
 /* Line __line__ of __file__.  */
-#line __oline__ "__ofile__"],
+b4_syncline([__oline__], [__ofile__])],
 [typedef int yystype;])[
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
@@ -228,7 +228,7 @@ static YYLTYPE yyloc_default;
 ]b4_post_prologue[
 
 ]/* Line __line__ of __file__.  */
-#line __oline__ "__ofile__"
+b4_syncline([__oline__], [__ofile__])
 [
 #if ! defined (__cplusplus)
    typedef char bool;
@@ -656,7 +656,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef yyclearin
 # undef YYRECOVERING
 /* Line __line__ of __file__.  */
-#line __oline__ "__ofile__"
+b4_syncline([__oline__], [__ofile__])
 }
 
 
@@ -1906,10 +1906,10 @@ b4_token_defines(b4_tokens)
 
 #ifndef YYSTYPE
 m4_ifdef([b4_stype],
-[#line b4_stype_line "b4_filename"
+[b4_syncline([b4_stype_line], [b4_filename])
 typedef union b4_stype yystype;
 /* Line __line__ of __file__.  */
-#line __oline__ "__ofile__"],
+b4_syncline([__oline__], [__ofile__])],
 [typedef int yystype;])
 # define YYSTYPE yystype
 #endif
