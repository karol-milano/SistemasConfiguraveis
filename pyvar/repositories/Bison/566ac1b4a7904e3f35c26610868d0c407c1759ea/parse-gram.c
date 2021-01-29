@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.2.  */
+/* A Bison parser, made by GNU Bison 2.2a.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
 
@@ -47,7 +47,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.2"
+#define YYBISON_VERSION "2.2a"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -951,14 +951,14 @@ do {									  \
 #if (defined __STDC__ || defined __C99__FUNC__ \
      || defined __cplusplus || defined _MSC_VER)
 static void
-yy_symbol_value_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep, const YYLTYPE * const yylocationp)
+yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 #else
 static void
 yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     FILE *yyoutput;
     int yytype;
-    const YYSTYPE * const yyvaluep;
-    const YYLTYPE * const yylocationp;
+    YYSTYPE const * const yyvaluep;
+    YYLTYPE const * const yylocationp;
 #endif
 {
   if (!yyvaluep)
@@ -1065,14 +1065,14 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #if (defined __STDC__ || defined __C99__FUNC__ \
      || defined __cplusplus || defined _MSC_VER)
 static void
-yy_symbol_print (FILE *yyoutput, int yytype, const YYSTYPE * const yyvaluep, const YYLTYPE * const yylocationp)
+yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 #else
 static void
 yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
     FILE *yyoutput;
     int yytype;
-    const YYSTYPE * const yyvaluep;
-    const YYLTYPE * const yylocationp;
+    YYSTYPE const * const yyvaluep;
+    YYLTYPE const * const yylocationp;
 #endif
 {
   if (yytype < YYNTOKENS)
