@@ -205,13 +205,12 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
-/* Default (constant) values used for initialization for null
+/* Default (constant) value used for initialization for null
    right-hand sides.  Unlike the standard yacc.c template,
-   here we set the default values of $$ and $@@ to zeroed-out
-   values.  Since the default value of these quantities is undefined,
+   here we set the default value of $$ to a zeroed-out value.
+   Since the default value of these quantities is undefined,
    this behavior is technically correct. */
 static YYSTYPE yyval_default;
-static YYLTYPE yyloc_default;
 
 /* Copy the second part of user declarations.  */
 ]b4_post_prologue[
