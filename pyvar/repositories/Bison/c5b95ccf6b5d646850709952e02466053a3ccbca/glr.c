@@ -149,8 +149,7 @@ b4_copyright([Skeleton parser for GLR parsing with Bison], [2002, 2003, 2004])
 
 ]b4_identification
 m4_if(b4_prefix[], [yy], [],
-[/* If NAME_PREFIX is specified substitute the variables and functions
-   names.  */
+[/* Substitute the variable and function names.  */
 #define yyparse b4_prefix[]parse
 #define yylex   b4_prefix[]lex
 #define yyerror b4_prefix[]error
