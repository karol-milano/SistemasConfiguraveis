@@ -150,7 +150,7 @@ b4_copyright([Skeleton parser for GLR parsing with Bison],
 
 ]b4_identification
 
-m4_if(b4_prefix[], [yy], [],
+m4_if(b4_prefix, [yy], [],
 [/* Substitute the variable and function names.  */
 #define yyparse b4_prefix[]parse
 #define yylex   b4_prefix[]lex
