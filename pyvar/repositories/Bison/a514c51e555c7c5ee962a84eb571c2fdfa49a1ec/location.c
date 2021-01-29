@@ -296,7 +296,7 @@ boundary_set_from_string (boundary *bound, char *loc_str)
   char *delim = strrchr (loc_str, '.');
   aver (delim);
   *delim = '\0';
-  bound->column = atoi (delim+1);
+  bound->byte = bound->column = atoi (delim+1);
   delim = strrchr (loc_str, ':');
   aver (delim);
   *delim = '\0';
