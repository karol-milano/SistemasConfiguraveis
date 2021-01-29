@@ -51,6 +51,7 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
 {
   int line = cur->line;
   int column = cur->column;
+  int byte = cur->byte;
   char const *p0 = token;
   char const *p = token;
   char const *lim = token + size;
@@ -63,6 +64,7 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
       case '\n':
         line += line < INT_MAX;
         column = 1;
+        byte = 1;
         p0 = p + 1;
         break;
 
@@ -70,14 +72,17 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
         column = add_column_width (column, p0, p - p0);
         column = add_column_width (column, NULL, 8 - ((column - 1) & 7));
         p0 = p + 1;
+        byte += byte < INT_MAX;
         break;
 
       default:
+        byte += byte < INT_MAX;
         break;
       }
 
   cur->line = line;
   cur->column = column = add_column_width (column, p0, p - p0);
+  cur->byte = byte;
 
   loc->end = *cur;
 
@@ -85,6 +90,8 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
     complain (loc, Wother, _("line number overflow"));
   if (column == INT_MAX && loc->start.column != INT_MAX)
     complain (loc, Wother, _("column number overflow"));
+  if (byte == INT_MAX && loc->start.byte != INT_MAX)
+    complain (loc, Wother, _("byte number overflow"));
 }
 
 
@@ -135,6 +142,7 @@ struct caret_info
 {
   FILE *source;
   size_t line;
+  /* Offset in SOURCE where line LINE starts.  */
   size_t offset;
 };
 
@@ -153,8 +161,6 @@ caret_free ()
 void
 location_caret (location loc, const char *style, FILE *out)
 {
-  /* FIXME: find a way to support multifile locations, and only open once each
-     file. That would make the procedure future-proof.  */
   if (! (caret_info.source
          || (caret_info.source = fopen (loc.start.file, "r")))
       || loc.start.column == -1 || loc.start.line == -1)
@@ -186,22 +192,25 @@ location_caret (location loc, const char *style, FILE *out)
         /* Quote the file (at most first line in the case of multiline
            location).  Indent by a single column.  */
         fputc (' ', out);
-        int col = 0;
-        do
+        bool single_line = loc.start.line == loc.end.line;
+        /* Consider that single point location (with equal boundaries)
+           actually denote the character that they follow.  */
+        int byte_end = loc.end.byte +
+          (single_line && loc.start.byte == loc.end.byte);
+        /* Byte number.  */
+        int byte = 1;
+        while (c != EOF && c != '\n')
           {
-            ++col;
-            if (col == loc.start.column)
+            if (byte == loc.start.byte)
               begin_use_class (style, out);
             fputc (c, out);
-            if (loc.start.column == loc.end.column
-                ? col == loc.end.column
-                : col + 1 == loc.end.column)
+            c = getc (caret_info.source);
+            ++byte;
+            if (single_line
+                ? byte == byte_end
+                : c == '\n' || c == EOF)
               end_use_class (style, out);
           }
-        while ((c = getc (caret_info.source)) != EOF && c != '\n');
-        /* Close the style, in the case of a multiline location.  */
-        if (loc.start.line != loc.end.line)
-          end_use_class (style, out);
         putc ('\n', out);
 
         {
