@@ -208,8 +208,8 @@ typedef struct YYLTYPE
 /* Default (constant) value used for initialization for null
    right-hand sides.  Unlike the standard yacc.c template,
    here we set the default value of $$ to a zeroed-out value.
-   Since the default value of these quantities is undefined,
-   this behavior is technically correct. */
+   Since the default value is undefined, this behavior is
+   technically correct. */
 static YYSTYPE yyval_default;
 
 /* Copy the second part of user declarations.  */
