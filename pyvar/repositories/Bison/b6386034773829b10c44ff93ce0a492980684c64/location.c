@@ -421,12 +421,14 @@ location_caret (location loc, const char *style, FILE *out)
       {
         /* The last column to highlight.  Only the first line of
            multiline locations are quoted, in which case the ending
-           column is the end of line.  Single point locations (with
-           equal boundaries) denote the character that they
-           follow.  */
-        int col_end
+           column is the end of line.
+
+           We used to work with byte offsets, and that was much
+           easier.  However, we went back to using (visual) columns to
+           support truncating of long lines.  */
+        const int col_end
           = loc.start.line == loc.end.line
-          ? loc.end.column + (loc.start.column == loc.end.column)
+          ? loc.end.column
           : caret_info.line_len;
         /* Quote the file (at most the first line in the case of
            multiline locations).  */
@@ -436,24 +438,28 @@ location_caret (location loc, const char *style, FILE *out)
              expected (maybe the file was changed since the scanner
              ran), we might reach the end before we actually saw the
              opening column.  */
-          bool opened = false;
+          enum { before, inside, after } state = before;
           while (!mb_iseof (c) && !mb_iseq (c, '\n'))
             {
-              if (caret_info.pos.column == loc.start.column)
+              // We might have already opened (and even closed!) the
+              // style and yet have the equality of the columns if we
+              // just saw zero-width characters.
+              if (state == before
+                  && caret_info.pos.column == loc.start.column)
                 {
                   begin_use_class (style, out);
-                  opened = true;
+                  state = inside;
                 }
               if (skip < caret_info.pos.column)
                 mb_putc (c, out);
               boundary_compute (&caret_info.pos, mb_ptr (c), mb_len (c));
               caret_getc (c);
-              if (opened
+              if (state == inside
                   && (caret_info.pos.column == col_end
                       || width < caret_info.pos.column - skip))
                 {
                   end_use_class (style, out);
-                  opened = false;
+                  state = after;
                 }
               if (width < caret_info.pos.column - skip)
                 {
@@ -461,11 +467,11 @@ location_caret (location loc, const char *style, FILE *out)
                   break;
                 }
             }
-          // The line is shorter than expected.
-          if (opened)
+          if (state == inside)
             {
+              // The line is shorter than expected.
               end_use_class (style, out);
-              opened = false;
+              state = after;
             }
           putc ('\n', out);
         }
