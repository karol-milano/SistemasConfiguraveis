@@ -183,7 +183,8 @@ location_caret (location loc, const char *style, FILE *out)
     int c = getc (caret_info.source);
     if (c != EOF)
       {
-        /* Quote the file, indent by a single column.  */
+        /* Quote the file (at most first line in the case of multiline
+           location).  Indent by a single column.  */
         fputc (' ', out);
         int col = 0;
         do
@@ -204,17 +205,17 @@ location_caret (location loc, const char *style, FILE *out)
         putc ('\n', out);
 
         {
-          /* The caret of a multiline location ends with the first line.  */
-          size_t len = loc.start.line != loc.end.line
-            ? ftell (caret_info.source) - caret_info.offset
-            : loc.end.column;
-          int i;
-
-          /* Print the carets (at least one), with the same indent as above.*/
+          /* Print the carets with the same indentation as above.  */
           fprintf (out, " %*s", loc.start.column - 1, "");
           begin_use_class (style, out);
-          for (i = loc.start.column; i == loc.start.column || i < len; ++i)
-            putc (i == loc.start.column ? '^' : '~', out);
+          putc ('^', out);
+          /* Underlining a multiline location ends with the first
+             line.  */
+          int len = loc.start.line != loc.end.line
+            ? ftell (caret_info.source) - caret_info.offset
+            : loc.end.column;
+          for (int i = loc.start.column + 1; i < len; ++i)
+            putc ('~', out);
           end_use_class (style, out);
         }
         putc ('\n', out);
