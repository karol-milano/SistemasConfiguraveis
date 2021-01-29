@@ -198,6 +198,12 @@ static YYLTYPE yyloc_default;
 #  define yyfalse 0
 #endif
 
+#if defined (__STDC__) || defined (__cplusplus)
+   typedef signed char yysigned_char;
+#else
+   typedef short yysigned_char;
+#endif
+
 /*-----------------.
 | GCC extensions.  |
 `-----------------*/
