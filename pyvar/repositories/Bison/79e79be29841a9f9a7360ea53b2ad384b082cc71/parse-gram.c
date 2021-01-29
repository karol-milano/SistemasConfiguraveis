@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.2.90.  */
+/* A Bison parser, made by GNU Bison 3.2.90.11-ccb3-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.2.90"
+#define YYBISON_VERSION "3.2.90.11-ccb3-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -2292,7 +2292,7 @@ yyreduce:
   case 8:
 #line 293 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      muscle_percent_define_insert ((yyvsp[-1].variable), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
+      muscle_percent_define_insert ((yyvsp[-1].variable), (yyloc), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 #line 2299 "src/parse-gram.c" /* yacc.c:1649  */
