@@ -143,15 +143,13 @@ location_print (FILE *out, location loc)
    same file all over for each error.  */
 struct caret_info
 {
-  FILE* source;
+  FILE *source;
   size_t line;
   size_t offset;
 };
 
 static struct caret_info caret_info = { NULL, 1, 0 };
 
-/* Free any allocated ressources and close any open file handles that are
-   left-over by the usage of location_caret.  */
 void
 cleanup_caret ()
 {
@@ -159,11 +157,10 @@ cleanup_caret ()
     fclose (caret_info.source);
 }
 
-/* Output to OUT the line and caret corresponding to location LOC.  */
 void
 location_caret (FILE *out, location loc)
 {
-  /* FIXME: find a way to support X-file locations, and only open once each
+  /* FIXME: find a way to support multifile locations, and only open once each
      file. That would make the procedure future-proof.  */
   if (! (caret_info.source
          || (caret_info.source = fopen (loc.start.file, "r")))
@@ -183,41 +180,36 @@ location_caret (FILE *out, location loc)
     }
 
   /* Advance to the line's position, keeping track of the offset.  */
-  {
-    int i;
-    for (i = caret_info.line; i < loc.start.line; caret_info.offset++)
-      if (fgetc (caret_info.source) == '\n')
-        ++i;
-  }
-  caret_info.line = loc.start.line;
+  while (caret_info.line < loc.start.line)
+    caret_info.line += fgetc (caret_info.source) == '\n';
+  caret_info.offset = ftell (caret_info.source);
 
   /* Read the actual line.  Don't update the offset, so that we keep a pointer
      to the start of the line.  */
   {
-    ssize_t len = 0;
     char *buf = NULL;
-    if ((len = getline (&buf, (size_t*) &len, caret_info.source)) != -1)
+    size_t size = 0;
+    ssize_t len = getline (&buf, &size, caret_info.source);
+    if (0 < len)
       {
         /* The caret of a multiline location ends with the first line.  */
         int end = loc.start.line != loc.end.line ? len : loc.end.column;
 
-        if (len)
-          {
-            int i = loc.start.column;
-            /* Quote the file, indent by a single column.  */
-            fputc (' ', out);
-            fwrite (buf, 1, len, out);
-
-            /* Print the caret, with the same indent as above.  */
-            fputc (' ', out);
-            fprintf (out, "%*s", loc.start.column - 1, "");
-            do {
-              fputc ('^', out);
-            } while (++i < end);
-          }
+        /* Quote the file, indent by a single column.  */
+        fputc (' ', out);
+        fwrite (buf, 1, len, out);
+
+        /* Print the caret, with the same indent as above.  */
+        fprintf (out, " %*s", loc.start.column - 1, "");
+        {
+          int i = loc.start.column;
+          do
+            fputc ('^', out);
+          while (++i < end);
+        }
         fputc ('\n', out);
-        free (buf);
       }
+    free (buf);
   }
 }
 
