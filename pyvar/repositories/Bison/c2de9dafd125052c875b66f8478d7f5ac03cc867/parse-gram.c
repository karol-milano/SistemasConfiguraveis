@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.0.5.23-f58b-dirty.  */
+/* A Bison parser, made by GNU Bison 3.0.5.60-37fce.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.0.5.23-f58b-dirty"
+#define YYBISON_VERSION "3.0.5.60-37fce"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -358,13 +358,13 @@ typedef signed char yytype_int8;
 #ifdef YYTYPE_UINT16
 typedef YYTYPE_UINT16 yytype_uint16;
 #else
-typedef unsigned short int yytype_uint16;
+typedef unsigned short yytype_uint16;
 #endif
 
 #ifdef YYTYPE_INT16
 typedef YYTYPE_INT16 yytype_int16;
 #else
-typedef short int yytype_int16;
+typedef short yytype_int16;
 #endif
 
 #ifndef YYSIZE_T
@@ -376,7 +376,7 @@ typedef short int yytype_int16;
 #  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYSIZE_T size_t
 # else
-#  define YYSIZE_T unsigned int
+#  define YYSIZE_T unsigned
 # endif
 #endif
 
@@ -575,7 +575,7 @@ union yyalloc
 #define YYMAXUTOK   312
 
 #define YYTRANSLATE(YYX)                                                \
-  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
+  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, without out-of-bounds checking.  */
@@ -1205,7 +1205,7 @@ do {                                                            \
 static void
 yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
 {
-  unsigned long int yylno = yyrline[yyrule];
+  unsigned long yylno = yyrline[yyrule];
   int yynrhs = yyr2[yyrule];
   int yyi;
   YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
@@ -1926,7 +1926,7 @@ YYLTYPE yylloc = yyloc_default;
       yylsp = yyls + yysize - 1;
 
       YYDPRINTF ((stderr, "Stack size increased to %lu\n",
-                  (unsigned long int) yystacksize));
+                  (unsigned long) yystacksize));
 
       if (yyss + yystacksize - 1 <= yyssp)
         YYABORT;
