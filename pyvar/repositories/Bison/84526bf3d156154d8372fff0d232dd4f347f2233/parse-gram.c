@@ -2431,7 +2431,7 @@ yyreduce:
 #line 343 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
-      if (mbschr (skeleton_user, '/'))
+      if (strchr (skeleton_user, '/'))
         {
           size_t dir_length = strlen (current_file);
           char *skeleton_build;
