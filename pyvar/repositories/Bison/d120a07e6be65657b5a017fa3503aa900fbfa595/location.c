@@ -229,7 +229,13 @@ location_caret (location loc, const char *style, FILE *out)
 
   /* Advance to the line's position, keeping track of the offset.  */
   while (caret_info.line < loc.start.line)
-    caret_info.line += getc (caret_info.source) == '\n';
+    {
+      int c = getc (caret_info.source);
+      if (c == EOF)
+        /* Something is wrong, that line number does not exist.  */
+        return;
+      caret_info.line += c == '\n';
+    }
   caret_info.offset = ftell (caret_info.source);
 
   /* Read the actual line.  Don't update the offset, so that we keep a pointer
@@ -238,32 +244,43 @@ location_caret (location loc, const char *style, FILE *out)
     int c = getc (caret_info.source);
     if (c != EOF)
       {
+        bool single_line = loc.start.line == loc.end.line;
         /* Quote the file (at most the first line in the case of
            multiline locations).  */
-        fprintf (out, "%5d | ", loc.start.line);
-        bool single_line = loc.start.line == loc.end.line;
-        /* Consider that single point location (with equal boundaries)
-           actually denote the character that they follow.  */
-        int byte_end = loc.end.byte +
-          (single_line && loc.start.byte == loc.end.byte);
-        /* Byte number.  */
-        int byte = 1;
-        while (c != EOF && c != '\n')
-          {
-            if (byte == loc.start.byte)
-              begin_use_class (style, out);
-            fputc (c, out);
-            c = getc (caret_info.source);
-            ++byte;
-            if (single_line
-                ? byte == byte_end
-                : c == '\n' || c == EOF)
-              end_use_class (style, out);
-          }
-        putc ('\n', out);
+        {
+          fprintf (out, "%5d | ", loc.start.line);
+          /* Consider that single point location (with equal boundaries)
+             actually denote the character that they follow.  */
+          int byte_end = loc.end.byte +
+            (single_line && loc.start.byte == loc.end.byte);
+          /* Byte number.  */
+          int byte = 1;
+          /* Whether we opened the style.  If the line is not as
+             expected (maybe the file was changed since the scanner
+             ran), we might reach the end before we actually saw the
+             opening column.  */
+          bool opened = false;
+          while (c != EOF && c != '\n')
+            {
+              if (byte == loc.start.byte)
+                {
+                  begin_use_class (style, out);
+                  opened = true;
+                }
+              fputc (c, out);
+              c = getc (caret_info.source);
+              ++byte;
+              if (opened
+                  && (single_line
+                      ? byte == byte_end
+                      : c == '\n' || c == EOF))
+                end_use_class (style, out);
+            }
+          putc ('\n', out);
+        }
 
+        /* Print the carets with the same indentation as above.  */
         {
-          /* Print the carets with the same indentation as above.  */
           fprintf (out, "      | %*s", loc.start.column - 1, "");
           begin_use_class (style, out);
           putc ('^', out);
@@ -275,8 +292,8 @@ location_caret (location loc, const char *style, FILE *out)
           for (int i = loc.start.column + 1; i < len; ++i)
             putc ('~', out);
           end_use_class (style, out);
+          putc ('\n', out);
         }
-        putc ('\n', out);
       }
   }
 }
