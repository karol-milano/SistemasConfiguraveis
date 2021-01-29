@@ -235,14 +235,12 @@ location_caret (location loc, const char *style, FILE *out)
   /* If the line we want to quote is seekable (the same line as the previous
      location), just seek it. If it was a previous line, we lost track of it,
      so return to the start of file.  */
-  if (caret_info.line <= loc.start.line)
-    fseek (caret_info.source, caret_info.offset, SEEK_SET);
-  else
+  if (loc.start.line < caret_info.line)
     {
       caret_info.line = 1;
       caret_info.offset = 0;
-      fseek (caret_info.source, caret_info.offset, SEEK_SET);
     }
+  fseek (caret_info.source, caret_info.offset, SEEK_SET);
 
   /* Advance to the line's position, keeping track of the offset.  */
   while (caret_info.line < loc.start.line)
