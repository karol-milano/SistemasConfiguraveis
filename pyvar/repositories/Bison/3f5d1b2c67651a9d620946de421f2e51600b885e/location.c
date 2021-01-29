@@ -138,6 +138,89 @@ location_print (FILE *out, location loc)
   return res;
 }
 
+
+/* Persistant data used by location_caret to avoid reopening and rereading the
+   same file all over for each error.  */
+struct caret_info
+{
+  FILE* source;
+  size_t line;
+  size_t offset;
+};
+
+static struct caret_info caret_info = { NULL, 1, 0 };
+
+/* Free any allocated ressources and close any open file handles that are
+   left-over by the usage of location_caret.  */
+void
+cleanup_caret ()
+{
+  if (caret_info.source)
+    fclose (caret_info.source);
+}
+
+/* Output to OUT the line and caret corresponding to location LOC.  */
+void
+location_caret (FILE *out, location loc)
+{
+  /* FIXME: find a way to support X-file locations, and only open once each
+     file. That would make the procedure future-proof.  */
+  if (! (caret_info.source
+         || (caret_info.source = fopen (loc.start.file, "r")))
+      || loc.start.column == -1 || loc.start.line == -1)
+    return;
+
+  /* If the line we want to quote is seekable (the same line as the previous
+     location), just seek it. If it was before, we lost track of it, so
+     return to the start of file.  */
+  if (caret_info.line <= loc.start.line)
+    fseek (caret_info.source, caret_info.offset, SEEK_SET);
+  else
+    {
+      caret_info.line = 1;
+      caret_info.offset = 0;
+      fseek (caret_info.source, caret_info.offset, SEEK_SET);
+    }
+
+  /* Advance to the line's position, keeping track of the offset.  */
+  {
+    int i;
+    for (i = caret_info.line; i < loc.start.line; caret_info.offset++)
+      if (fgetc (caret_info.source) == '\n')
+        ++i;
+  }
+  caret_info.line = loc.start.line;
+
+  /* Read the actual line.  Don't update the offset, so that we keep a pointer
+     to the start of the line.  */
+  {
+    ssize_t len = 0;
+    char *buf = NULL;
+    if ((len = getline (&buf, (size_t*) &len, caret_info.source)) != -1)
+      {
+        /* The caret of a multiline location ends with the first line.  */
+        int end = loc.start.line != loc.end.line ? len : loc.end.column;
+
+        if (len)
+          {
+            int i = loc.start.column;
+            /* Quote the file, indent by a single column.  */
+            fputc (' ', out);
+            fwrite (buf, 1, len, out);
+
+            /* Print the caret, with the same indent as above.  */
+            fputc (' ', out);
+            fprintf (out, "%*s", loc.start.column - 1, "");
+            do {
+              fputc ('^', out);
+            } while (++i < end);
+          }
+        fputc ('\n', out);
+        free (buf);
+      }
+  }
+}
+
 void
 boundary_set_from_string (boundary *bound, char *loc_str)
 {
