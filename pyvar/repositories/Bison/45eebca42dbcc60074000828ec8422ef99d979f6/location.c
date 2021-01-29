@@ -219,7 +219,7 @@ void
 boundary_set_from_string (boundary *bound, char *loc_str)
 {
   /* Must search in reverse since the file name field may
-   * contain `.' or `:'.  */
+   * contain '.' or ':'.  */
   char *delim = strrchr (loc_str, '.');
   aver (delim);
   *delim = '\0';
