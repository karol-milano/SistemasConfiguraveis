@@ -207,12 +207,6 @@ static YYLTYPE yyloc_default;
 #  define yyfalse 0
 #endif
 
-#if defined (__STDC__) || defined (__cplusplus)
-   typedef signed char yysigned_char;
-#else
-   typedef short yysigned_char;
-#endif
-
 /*-----------------.
 | GCC extensions.  |
 `-----------------*/
