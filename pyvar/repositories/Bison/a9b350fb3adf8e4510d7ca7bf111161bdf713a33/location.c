@@ -191,7 +191,7 @@ location_caret (location loc, const char *style, FILE *out)
       {
         /* Quote the file (at most first line in the case of multiline
            location).  Indent by a single column.  */
-        fputc (' ', out);
+        fprintf (out, "%5d | ", loc.start.line);
         bool single_line = loc.start.line == loc.end.line;
         /* Consider that single point location (with equal boundaries)
            actually denote the character that they follow.  */
@@ -215,7 +215,7 @@ location_caret (location loc, const char *style, FILE *out)
 
         {
           /* Print the carets with the same indentation as above.  */
-          fprintf (out, " %*s", loc.start.column - 1, "");
+          fprintf (out, "      | %*s", loc.start.column - 1, "");
           begin_use_class (style, out);
           putc ('^', out);
           /* Underlining a multiline location ends with the first
