@@ -165,9 +165,9 @@ m4_define([b4_symbol_actions],
 [m4_pushdef([b4_dollar_dollar], [yyvalue.$6])dnl
 m4_pushdef([b4_at_dollar], [yylocation])dnl
       case $4: /* $3 */
-#line $2 "$1"
+b4_syncline([$2], [$1])
         $5;
-#line __oline__ "__ofile__"
+b4_syncline([__oline__], [__ofile__])
         break;
 m4_popdef([b4_at_dollar])dnl
 m4_popdef([b4_dollar_dollar])dnl
@@ -229,10 +229,10 @@ b4_pre_prologue
 
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
 # define YYSTYPE_IS_TRIVIAL 1
@@ -254,7 +254,7 @@ typedef struct yyltype
 b4_post_prologue
 
 /* Line __line__ of __file__.  */
-#line __oline__ "__ofile__"
+b4_syncline([__oline__], [__ofile__])
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -1053,7 +1053,7 @@ yyreduce:
     }
 
 /* Line __line__ of __file__.  */
-#line __oline__ "__ofile__"
+b4_syncline([__oline__], [__ofile__])
 
 [  yyvsp -= yylen;
   yyssp -= yylen;
@@ -1290,10 +1290,10 @@ b4_token_defines(b4_tokens)
 
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
