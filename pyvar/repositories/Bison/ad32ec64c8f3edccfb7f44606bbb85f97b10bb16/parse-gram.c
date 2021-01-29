@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.4.90.16-c313.  */
+/* A Bison parser, made by GNU Bison 3.4.90.26-44cd.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4.90.16-c313"
+#define YYBISON_VERSION "3.4.90.26-44cd"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1236,8 +1236,9 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
       if (YYMAXDEPTH < yyalloc)
         yyalloc = YYMAXDEPTH;
       yybottom_new =
-        YY_CAST(yy_state_t *,
-                YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yyalloc * YYSIZEOF (*yybottom_new))));
+        YY_CAST (yy_state_t *,
+                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
+                                         yyalloc * YYSIZEOF (*yybottom_new))));
       if (!yybottom_new)
         {
           YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
