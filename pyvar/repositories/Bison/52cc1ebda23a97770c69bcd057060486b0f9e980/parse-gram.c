@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.6.1.835-7c52-dirty.  */
+/* A Bison parser, made by GNU Bison 2.6.2.834-6d7b9.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.1.835-7c52-dirty"
+#define YYBISON_VERSION "2.6.2.834-6d7b9"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -3198,8 +3198,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-
-/* Line 1937 of yacc.c  */
+/* Line 1936 of yacc.c  */
 #line 724 "src/parse-gram.y"
 
 
@@ -3255,11 +3254,13 @@ add_param (param_type type, char *decl, location loc)
 
     /* Strip the surrounding '{' and '}', and any blanks just inside
        the braces.  */
-    while (*--p == ' ' || *p == '\t')
-      continue;
+    --p;
+    while (isspace ((unsigned char) *p))
+      --p;
     p[1] = '\0';
-    while (*++decl == ' ' || *decl == '\t')
-      continue;
+    ++decl;
+    while (isspace ((unsigned char) *decl))
+      ++decl;
   }
 
   if (! name_start)
