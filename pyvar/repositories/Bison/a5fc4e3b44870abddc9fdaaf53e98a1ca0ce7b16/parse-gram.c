@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.4.2.191-54c5d.  */
+/* A Bison parser, made by GNU Bison 3.4.2.213-aa24.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4.2.191-54c5d"
+#define YYBISON_VERSION "3.4.2.213-aa24"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1821,8 +1821,8 @@ YYLTYPE yylloc = yyloc_default;
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
-  boundary_set (&yylloc.start, current_file, 1, 1, 1);
-  boundary_set (&yylloc.end, current_file, 1, 1, 1);
+  boundary_set (&yylloc.start, grammar_file, 1, 1, 1);
+  boundary_set (&yylloc.end, grammar_file, 1, 1, 1);
 }
 
 
@@ -1840,7 +1840,7 @@ yynewstate:
 
 
 /*--------------------------------------------------------------------.
-| yynewstate -- set current state (the top of the stack) to yystate.  |
+| yysetstate -- set current state (the top of the stack) to yystate.  |
 `--------------------------------------------------------------------*/
 yysetstate:
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
@@ -3042,16 +3042,16 @@ handle_skeleton (location const *loc, char const *skel)
   char const *skeleton_user = skel;
   if (strchr (skeleton_user, '/'))
     {
-      size_t dir_length = strlen (current_file);
-      while (dir_length && current_file[dir_length - 1] != '/')
+      size_t dir_length = strlen (grammar_file);
+      while (dir_length && grammar_file[dir_length - 1] != '/')
         --dir_length;
-      while (dir_length && current_file[dir_length - 1] == '/')
+      while (dir_length && grammar_file[dir_length - 1] == '/')
         --dir_length;
       char *skeleton_build =
         xmalloc (dir_length + 1 + strlen (skeleton_user) + 1);
       if (dir_length > 0)
         {
-          memcpy (skeleton_build, current_file, dir_length);
+          memcpy (skeleton_build, grammar_file, dir_length);
           skeleton_build[dir_length++] = '/';
         }
       strcpy (skeleton_build + dir_length, skeleton_user);
