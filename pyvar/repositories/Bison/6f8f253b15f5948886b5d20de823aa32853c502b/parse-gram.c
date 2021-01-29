@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.680-a7497-dirty.  */
+/* A Bison parser, made by GNU Bison 2.4.687-d4fc-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.680-a7497-dirty"
+#define YYBISON_VERSION "2.4.687-d4fc-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -3425,7 +3425,7 @@ version_check (location const *loc, char const *version)
     {
       complain_at (*loc, "require bison %s, but have %s",
                    version, PACKAGE_VERSION);
-      exit (EX_CONFIG);
+      exit (EX_MISMATCH);
     }
 }
 
