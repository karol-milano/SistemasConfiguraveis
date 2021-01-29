@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.1.287-8f46.  */
+/* A Bison parser, made by GNU Bison 2.4.1.302-e8fa.  */
 
 /* Bison implementation for Yacc-like parsers in C
    
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.287-8f46"
+#define YYBISON_VERSION "2.4.1.302-e8fa"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -2410,7 +2410,7 @@ yyreduce:
 #line 311 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
-      if (strchr (skeleton_user, '/'))
+      if (mbschr (skeleton_user, '/'))
         {
           size_t dir_length = strlen (current_file);
           char *skeleton_build;
