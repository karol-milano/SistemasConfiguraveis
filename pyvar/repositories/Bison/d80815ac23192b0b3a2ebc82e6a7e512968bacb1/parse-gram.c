@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.4.  */
+/* A Bison parser, made by GNU Bison 3.4.1.26-d17af.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4"
+#define YYBISON_VERSION "3.4.1.26-d17af"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -886,6 +886,7 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
 /* "%code pre-printer" blocks.  */
 tron (yyo);
 
+  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   switch (yytype)
     {
     case 3: /* "string"  */
@@ -1069,6 +1070,7 @@ tron (yyo);
       default:
         break;
     }
+  YY_IGNORE_MAYBE_UNINITIALIZED_END
 /* "%code post-printer" blocks.  */
 troff (yyo);
 
