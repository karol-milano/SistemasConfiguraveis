@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.0.4.26-d132-dirty.  */
+/* A Bison parser, made by GNU Bison 3.0.4.38-1047-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.0.4.26-d132-dirty"
+#define YYBISON_VERSION "3.0.4.38-1047-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -3034,7 +3034,7 @@ translate_code_braceless (char *code, location loc)
 static void
 add_param (param_type type, char *decl, location loc)
 {
-  static char const alphanum[26 + 26 + 1 + 10] =
+  static char const alphanum[26 + 26 + 1 + 10 + 1] =
     "abcdefghijklmnopqrstuvwxyz"
     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
     "_"
@@ -3046,14 +3046,14 @@ add_param (param_type type, char *decl, location loc)
     /* Stop on last actual character.  */
     for (p = decl; p[1]; p++)
       if ((p == decl
-           || ! memchr (alphanum, p[-1], sizeof alphanum))
-          && memchr (alphanum, p[0], sizeof alphanum - 10))
+           || ! memchr (alphanum, p[-1], sizeof alphanum - 1))
+          && memchr (alphanum, p[0], sizeof alphanum - 10 - 1))
         name_start = p;
 
     /* Strip the surrounding '{' and '}', and any blanks just inside
        the braces.  */
     --p;
-  while (c_isspace ((unsigned char) *p))
+    while (c_isspace ((unsigned char) *p))
       --p;
     p[1] = '\0';
     ++decl;
