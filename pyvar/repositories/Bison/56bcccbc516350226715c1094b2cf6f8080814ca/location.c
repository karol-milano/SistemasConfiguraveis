@@ -219,10 +219,27 @@ static struct
      NULL, but FILE is NULL, it means this file is special and should
      not be quoted. */
   boundary pos;
-  /* Offset in FILE where line POS.LINE starts.  */
+  /* Offset in FILE of the current line (i.e., where line POS.LINE
+     starts).  */
   size_t offset;
+  /* Length of the current line.  */
+  int line_len;
 } caret_info;
 
+void caret_init (void)
+{
+  screen_width = columns ();
+}
+
+void
+caret_free (void)
+{
+  if (caret_info.file)
+    {
+      fclose (caret_info.file);
+      caret_info.file = NULL;
+    }
+}
 
 /* Open FILE for quoting, if needed, and if possible.  Return whether
    the file can quoted. */
@@ -260,21 +277,6 @@ caret_set_file (const char *file)
   return !!caret_info.file;
 }
 
-void caret_init (void)
-{
-  screen_width = columns ();
-}
-
-void
-caret_free (void)
-{
-  if (caret_info.file)
-    {
-      fclose (caret_info.file);
-      caret_info.file = NULL;
-    }
-}
-
 /* Getc, but smash \r\n as \n.  */
 static void
 caret_getc_internal (mbchar_t *res)
@@ -293,33 +295,35 @@ caret_getc_internal (mbchar_t *res)
 
 #define caret_getc(Var) caret_getc_internal(&Var)
 
-void
-location_caret (location loc, const char *style, FILE *out)
+/* Move CARET_INFO (which has a valid FILE) to the line number LINE.
+   Compute and cache that line's length in CARET_INFO.LINE_LEN.
+   Return whether succesful.*/
+static bool
+caret_set_line (int line)
 {
-  if (loc.start.column == -1 || loc.start.line == -1)
-    return;
-  if (!caret_set_file (loc.start.file))
-    return;
-
-
   /* If the line we want to quote is seekable (the same line as the previous
      location), just seek it. If it was a previous line, we lost track of it,
      so return to the start of file.  */
-  if (loc.start.line < caret_info.pos.line)
+  if (line < caret_info.pos.line)
     {
       caret_info.pos.line = 1;
       caret_info.offset = 0;
     }
-  fseek (caret_info.file, caret_info.offset, SEEK_SET);
+  if (fseek (caret_info.file, caret_info.offset, SEEK_SET))
+    return false;
+
+  /* If this is the same line as the previous one, we are done. */
+  if (line < caret_info.pos.line)
+    return true;
 
   /* Advance to the line's position, keeping track of the offset.  */
-  while (caret_info.pos.line < loc.start.line)
+  while (caret_info.pos.line < line)
     {
       mbchar_t c;
       caret_getc (c);
       if (mb_iseof (c))
         /* Something is wrong, that line number does not exist.  */
-        return;
+        return false;
       caret_info.pos.line += mb_iseq (c, '\n');
     }
   caret_info.offset = ftell (caret_info.file);
@@ -337,20 +341,32 @@ location_caret (location loc, const char *style, FILE *out)
         break;
       boundary_compute (&caret_info.pos, mb_ptr (c), mb_len (c));
     }
-  int line_len = caret_info.pos.column;
+  caret_info.line_len = caret_info.pos.column;
   /* Go back to the beginning of line.  */
-  fseek (caret_info.file, caret_info.offset, SEEK_SET);
+  if (fseek (caret_info.file, caret_info.offset, SEEK_SET))
+    return false;
   /* Reset mbf's internal state.
      FIXME: should be done in mbfile.  */
   caret_info.mbfile.eof_seen = 0;
   caret_info.pos.column = 1;
+  return true;
+}
 
+void
+location_caret (location loc, const char *style, FILE *out)
+{
+  if (loc.start.column == -1 || loc.start.line == -1)
+    return;
+  if (!caret_set_file (loc.start.file))
+    return;
+  if (!caret_set_line (loc.start.line))
+    return;
 
-  /* Available width.  Eight chars are consumed by the left-margin of
-     the quoting lines.  */
+  /* Available width.  Eight chars are consumed by the left-margin
+     (with line number).  */
   int width = screen_width - 8;
   int skip = 0;
-  if (width < line_len)
+  if (width < caret_info.line_len)
     {
       /* We cannot quote the whole line.  Make sure we can see the
          beginning of the location.  */
@@ -361,7 +377,7 @@ location_caret (location loc, const char *style, FILE *out)
     width -= 3;
   /* If the end of line does not fit, we also need to truncate the
      end, and leave "..." there.  */
-  if (width < line_len - skip)
+  if (width < caret_info.line_len - skip)
     width -= 3;
 
   /* Read the actual line.  Don't update the offset, so that we keep a pointer
@@ -379,7 +395,7 @@ location_caret (location loc, const char *style, FILE *out)
         int col_end
           = loc.start.line == loc.end.line
           ? loc.end.column + (loc.start.column == loc.end.column)
-          : line_len;
+          : caret_info.line_len;
         /* Quote the file (at most the first line in the case of
            multiline locations).  */
         {
