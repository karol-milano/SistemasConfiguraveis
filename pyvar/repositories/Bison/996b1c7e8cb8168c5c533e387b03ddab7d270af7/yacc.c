@@ -190,7 +190,7 @@ b4_location_if([#define yylloc b4_prefix[]lloc])])[
 ]m4_ifdef([b4_stype],
 [b4_syncline([b4_stype_line], [b4_filename])
 typedef union b4_stype yystype;
-/* Line __line__ of __file__.  */
+/* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])],
 [typedef int yystype;])[
 # define YYSTYPE yystype
@@ -212,7 +212,7 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 ]b4_post_prologue
 
-/* Line __line__ of __file__.  */
+/* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])[
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
@@ -988,7 +988,7 @@ yyreduce:
       b4_actions
     }
 
-/* Line __line__ of __file__.  */
+/* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])
 
 [  yyvsp -= yylen;
@@ -1197,7 +1197,7 @@ b4_token_defines(b4_tokens)
 m4_ifdef([b4_stype],
 [b4_syncline([b4_stype_line], [b4_filename])
 typedef union b4_stype yystype;
-/* Line __line__ of __file__.  */
+/* Line __line__ of yacc.c.  */
 b4_syncline([@oline@], [@ofile@])],
 [typedef int yystype;])
 # define YYSTYPE yystype
