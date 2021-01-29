@@ -210,10 +210,10 @@ typedef struct yyltype
 #endif
 
 /* Copy the second part of user declarations.  */
-]b4_post_prologue[
+]b4_post_prologue
 
 /* Line __line__ of __file__.  */
-]b4_syncline([@oline@], [@ofile@])[
+b4_syncline([@oline@], [@ofile@])[
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
