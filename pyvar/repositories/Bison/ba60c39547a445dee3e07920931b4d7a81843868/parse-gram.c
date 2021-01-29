@@ -2422,7 +2422,7 @@ yyreduce:
 #line 342 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
-      if (strchr (skeleton_user, '/'))
+      if (mbschr (skeleton_user, '/'))
         {
           size_t dir_length = strlen (current_file);
           char *skeleton_build;
