@@ -238,8 +238,8 @@ location_caret (location loc, const char *style, FILE *out)
     int c = getc (caret_info.source);
     if (c != EOF)
       {
-        /* Quote the file (at most first line in the case of multiline
-           location).  Indent by a single column.  */
+        /* Quote the file (at most the first line in the case of
+           multiline locations).  */
         fprintf (out, "%5d | ", loc.start.line);
         bool single_line = loc.start.line == loc.end.line;
         /* Consider that single point location (with equal boundaries)
@@ -269,9 +269,9 @@ location_caret (location loc, const char *style, FILE *out)
           putc ('^', out);
           /* Underlining a multiline location ends with the first
              line.  */
-          int len = loc.start.line != loc.end.line
-            ? ftell (caret_info.source) - caret_info.offset
-            : loc.end.column;
+          int len = single_line
+            ? loc.end.column
+            : ftell (caret_info.source) - caret_info.offset;
           for (int i = loc.start.column + 1; i < len; ++i)
             putc ('~', out);
           end_use_class (style, out);
@@ -289,17 +289,29 @@ location_empty (location loc)
 }
 
 void
-boundary_set_from_string (boundary *bound, char *loc_str)
+boundary_set_from_string (boundary *bound, char *str)
 {
-  /* Must search in reverse since the file name field may
-   * contain '.' or ':'.  */
-  char *delim = strrchr (loc_str, '.');
-  aver (delim);
-  *delim = '\0';
-  bound->byte = bound->column = atoi (delim+1);
-  delim = strrchr (loc_str, ':');
-  aver (delim);
-  *delim = '\0';
-  bound->line = atoi (delim+1);
-  bound->file = uniqstr_new (loc_str);
+  /* Must search in reverse since the file name field may contain '.'
+     or ':'.  */
+  char *at = strrchr (str, '@');
+  if (at)
+    {
+      *at = '\0';
+      bound->byte = atoi (at+1);
+    }
+  {
+    char *dot = strrchr (str, '.');
+    aver (dot);
+    *dot = '\0';
+    bound->column = atoi (dot+1);
+    if (!at)
+      bound->byte = bound->column;
+  }
+  {
+    char *colon = strrchr (str, ':');
+    aver (colon);
+    *colon = '\0';
+    bound->line = atoi (colon+1);
+  }
+  bound->file = uniqstr_new (str);
 }
