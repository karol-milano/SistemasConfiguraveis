@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.7.1.1188-e7178.  */
+/* A Bison parser, made by GNU Bison 2.7.90.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.7.1.1188-e7178"
+#define YYBISON_VERSION "2.7.90"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1734,7 +1734,7 @@ static YYLTYPE yyloc_default
 #endif
 
 /* The semantic value of the lookahead symbol.  */
-YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);
+YYSTYPE yylval YY_INITIAL_VALUE (yyval_default);
 
 /* Location data for the lookahead symbol.  */
 YYLTYPE yylloc = yyloc_default;
@@ -2624,7 +2624,7 @@ yyreduce:
 
   case 96:
 #line 630 "src/parse-gram.y" /* yacc.c:1663  */
-    { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
+    { (yyval.named_ref) = named_ref_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 #line 2629 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
@@ -2981,7 +2981,7 @@ lloc_default (YYLTYPE const *rhs, int n)
 static
 char *strip_braces (char *code)
 {
-  code[strlen(code) - 1] = 0;
+  code[strlen (code) - 1] = 0;
   return code + 1;
 }
 
