@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.6.2.873-d87e-dirty.  */
+/* A Bison parser, made by GNU Bison 2.6.2.891-3f15-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.2.873-d87e-dirty"
+#define YYBISON_VERSION "2.6.2.891-3f15-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -148,8 +148,8 @@ static char const *char_name (char);
 
 /* In a future release of Bison, this section will be replaced
    by #include "src/parse-gram.h".  */
-#ifndef GRAM_SRC_PARSE_GRAM_H
-# define GRAM_SRC_PARSE_GRAM_H
+#ifndef YY_GRAM_SRC_PARSE_GRAM_H_INCLUDED
+# define YY_GRAM_SRC_PARSE_GRAM_H_INCLUDED
 /* Enabling traces.  */
 #ifndef YYDEBUG
 # define YYDEBUG 1
@@ -344,7 +344,7 @@ typedef struct YYLTYPE
 
 int gram_parse (void);
 
-#endif /* !GRAM_SRC_PARSE_GRAM_H  */
+#endif /* !YY_GRAM_SRC_PARSE_GRAM_H_INCLUDED  */
 
 /* Copy the second part of user declarations.  */
 
@@ -3264,8 +3264,7 @@ add_param (param_type type, char *decl, location loc)
   }
 
   if (! name_start)
-    complain_at (loc, complaint,
-                 _("missing identifier in parameter declaration"));
+    complain (&loc, complaint, _("missing identifier in parameter declaration"));
   else
     {
       char *name = xmemdup0 (name_start, strspn (name_start, alphanum));
@@ -3285,8 +3284,8 @@ version_check (location const *loc, char const *version)
 {
   if (strverscmp (version, PACKAGE_VERSION) > 0)
     {
-      complain_at (*loc, complaint, "require bison %s, but have %s",
-                   version, PACKAGE_VERSION);
+      complain (loc, complaint, "require bison %s, but have %s",
+                version, PACKAGE_VERSION);
       exit (EX_MISMATCH);
     }
 }
@@ -3294,7 +3293,7 @@ version_check (location const *loc, char const *version)
 static void
 gram_error (location const *loc, char const *msg)
 {
-  complain_at (*loc, complaint, "%s", msg);
+  complain (loc, complaint, "%s", msg);
 }
 
 char const *
