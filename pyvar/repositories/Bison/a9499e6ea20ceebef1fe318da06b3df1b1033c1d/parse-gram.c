@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.4.1.45-9bde-dirty.  */
+/* A Bison parser, made by GNU Bison 3.4.1.72-9d4b.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4.1.45-9bde-dirty"
+#define YYBISON_VERSION "3.4.1.72-9d4b"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -886,6 +886,7 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
 /* "%code pre-printer" blocks.  */
 tron (yyo);
 
+  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   switch (yytype)
     {
     case 3: /* "string"  */
@@ -1065,6 +1066,7 @@ tron (yyo);
       default:
         break;
     }
+  YY_IGNORE_MAYBE_UNINITIALIZED_END
 /* "%code post-printer" blocks.  */
 troff (yyo);
 
