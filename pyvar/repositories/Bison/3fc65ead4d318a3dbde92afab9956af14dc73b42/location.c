@@ -116,3 +116,19 @@ location_print (FILE *out, location loc)
   else if (loc.start.column < end_col)
     fprintf (out, "-%d", end_col);
 }
+
+void
+boundary_set_from_string (boundary *bound, char *loc_str)
+{
+  /* Must search in reverse since the file name field may
+   * contain `.' or `:'.  */
+  char *delim = strrchr (loc_str, '.');
+  aver (delim);
+  *delim = '\0';
+  bound->column = atoi (delim+1);
+  delim = strrchr (loc_str, ':');
+  aver (delim);
+  *delim = '\0';
+  bound->line = atoi (delim+1);
+  bound->file = uniqstr_new (loc_str);
+}
