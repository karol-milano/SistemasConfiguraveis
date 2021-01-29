@@ -155,6 +155,9 @@ cleanup_caret ()
 {
   if (caret_info.source)
     fclose (caret_info.source);
+  caret_info.source = NULL;
+  caret_info.line = 1;
+  caret_info.offset = 0;
 }
 
 void
@@ -168,8 +171,8 @@ location_caret (FILE *out, location loc)
     return;
 
   /* If the line we want to quote is seekable (the same line as the previous
-     location), just seek it. If it was before, we lost track of it, so
-     return to the start of file.  */
+     location), just seek it. If it was a previous line, we lost track of it,
+     so return to the start of file.  */
   if (caret_info.line <= loc.start.line)
     fseek (caret_info.source, caret_info.offset, SEEK_SET);
   else
@@ -181,35 +184,36 @@ location_caret (FILE *out, location loc)
 
   /* Advance to the line's position, keeping track of the offset.  */
   while (caret_info.line < loc.start.line)
-    caret_info.line += fgetc (caret_info.source) == '\n';
+    caret_info.line += getc (caret_info.source) == '\n';
   caret_info.offset = ftell (caret_info.source);
 
   /* Read the actual line.  Don't update the offset, so that we keep a pointer
      to the start of the line.  */
   {
-    char *buf = NULL;
-    size_t size = 0;
-    ssize_t len = getline (&buf, &size, caret_info.source);
-    if (0 < len)
+    char c = getc (caret_info.source);
+    if (c != EOF)
       {
-        /* The caret of a multiline location ends with the first line.  */
-        int end = loc.start.line != loc.end.line ? len : loc.end.column;
-
         /* Quote the file, indent by a single column.  */
-        fputc (' ', out);
-        fwrite (buf, 1, len, out);
+        putc (' ', out);
+        do
+          putc (c, out);
+        while ((c = getc (caret_info.source)) != EOF && c != '\n');
+        putc ('\n', out);
 
-        /* Print the caret, with the same indent as above.  */
-        fprintf (out, " %*s", loc.start.column - 1, "");
         {
-          int i = loc.start.column;
-          do
-            fputc ('^', out);
-          while (++i < end);
-        }
-        fputc ('\n', out);
+          /* The caret of a multiline location ends with the first line.  */
+          size_t len = loc.start.line != loc.end.line
+            ? ftell (caret_info.source) - caret_info.offset
+            : loc.end.column;
+          int i;
+
+          /* Print the carets (at least one), with the same indent as above.*/
+          fprintf (out, " %*s", loc.start.column - 1, "");
+          for (i = loc.start.column; i == loc.start.column || i < len; ++i)
+            putc ('^', out);
+          }
+        putc ('\n', out);
       }
-    free (buf);
   }
 }
 
