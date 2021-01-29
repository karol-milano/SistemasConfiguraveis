@@ -154,7 +154,7 @@ b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
    USER NAME SPACE" below.  */
 
 ]b4_identification
-m4_if(b4_prefix[], [yy], [],
+m4_if(b4_prefix, [yy], [],
 [/* Substitute the variable and function names.  */
 #define yyparse b4_prefix[]parse
 #define yylex   b4_prefix[]lex
