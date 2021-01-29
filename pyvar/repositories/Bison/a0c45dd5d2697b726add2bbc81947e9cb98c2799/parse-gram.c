@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.6.29-cd73-dirty.  */
+/* A Bison parser, made by GNU Bison 2.6.1.6-b045.  */
 
 /* Bison implementation for Yacc-like parsers in C
    
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.29-cd73-dirty"
+#define YYBISON_VERSION "2.6.1.6-b045"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -3169,11 +3169,13 @@ add_param (char const *type, char *decl, location loc)
 
   /* Strip the surrounding '{' and '}', and any blanks just inside
      the braces.  */
-  while (*--p == ' ' || *p == '\t')
-    continue;
+  --p;
+  while (isspace ((unsigned char) *p))
+    --p;
   p[1] = '\0';
-  while (*++decl == ' ' || *decl == '\t')
-    continue;
+  ++decl;
+  while (isspace ((unsigned char) *decl))
+    ++decl;
 
   if (! name_start)
     complain_at (loc, _("missing identifier in parameter declaration"));
