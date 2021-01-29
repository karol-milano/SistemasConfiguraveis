@@ -143,11 +143,11 @@ boundary_set_from_string (boundary *bound, char *loc_str)
 {
   /* Must search in reverse since the file name field may
    * contain `.' or `:'.  */
-  char *delim = mbsrchr (loc_str, '.');
+  char *delim = strrchr (loc_str, '.');
   aver (delim);
   *delim = '\0';
   bound->column = atoi (delim+1);
-  delim = mbsrchr (loc_str, ':');
+  delim = strrchr (loc_str, ':');
   aver (delim);
   *delim = '\0';
   bound->line = atoi (delim+1);
