@@ -224,6 +224,13 @@ static struct
   size_t offset;
   /* Length of the current line.  */
   int line_len;
+  /* Given the initial column to display, the offset (number of
+     characters to skip at the beginning of the line). */
+  int skip;
+
+  /* Available width to quote the source file.  Eight chars are
+     consumed by the left-margin (with line number).  */
+  int width;
 } caret_info;
 
 void caret_init (void)
@@ -352,33 +359,45 @@ caret_set_line (int line)
   return true;
 }
 
-void
-location_caret (location loc, const char *style, FILE *out)
+/* Compute CARET_INFO.WIDTH and CARET_INFO.SKIP based on the fact that
+   the first column to display in the current line is COL.  */
+static bool
+caret_set_column (int col)
 {
-  if (loc.start.column == -1 || loc.start.line == -1)
-    return;
-  if (!caret_set_file (loc.start.file))
-    return;
-  if (!caret_set_line (loc.start.line))
-    return;
-
   /* Available width.  Eight chars are consumed by the left-margin
      (with line number).  */
-  int width = screen_width - 8;
-  int skip = 0;
-  if (width < caret_info.line_len)
+  caret_info.width = screen_width - 8;
+  caret_info.skip = 0;
+  if (caret_info.width < caret_info.line_len)
     {
       /* We cannot quote the whole line.  Make sure we can see the
          beginning of the location.  */
-      skip = width < loc.start.column ? loc.start.column - 10 : 0;
+      caret_info.skip = caret_info.width < col ? col - 10 : 0;
     }
   /* If we skip the initial part, we insert "..." before.  */
-  if (skip)
-    width -= 3;
+  if (caret_info.skip)
+    caret_info.width -= 3;
   /* If the end of line does not fit, we also need to truncate the
      end, and leave "..." there.  */
-  if (width < caret_info.line_len - skip)
-    width -= 3;
+  if (caret_info.width < caret_info.line_len - caret_info.skip)
+    caret_info.width -= 3;
+  return true;
+}
+
+void
+location_caret (location loc, const char *style, FILE *out)
+{
+  if (loc.start.column == -1 || loc.start.line == -1)
+    return;
+  if (!caret_set_file (loc.start.file))
+    return;
+  if (!caret_set_line (loc.start.line))
+    return;
+  if (!caret_set_column (loc.start.column))
+    return;
+
+  const int width = caret_info.width;
+  const int skip = caret_info.skip;
 
   /* Read the actual line.  Don't update the offset, so that we keep a pointer
      to the start of the line.  */
