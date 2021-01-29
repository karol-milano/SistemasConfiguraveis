@@ -33,6 +33,26 @@
 
 location const empty_loc = EMPTY_LOCATION_INIT;
 
+static int
+min_int (int a, int b)
+{
+  return a < b ? a : b;
+}
+
+/* The terminal width.  */
+static int
+columns (void)
+{
+  const char *cp = getenv ("COLUMNS");
+  int res = 80;
+  if (cp && *cp)
+    {
+      unsigned long ul = strtoul (cp, NULL, 10);
+      res = ul < INT_MAX ? ul : INT_MAX;
+    }
+  return res;
+}
+
 /* If BUF is null, add BUFSIZE (which in this case must be less than
    INT_MAX) to COLUMN; otherwise, add mbsnwidth (BUF, BUFSIZE, 0) to
    COLUMN.  If an overflow occurs, return INT_MAX.  */
@@ -179,6 +199,8 @@ static struct
 } caret_info;
 
 
+/* Open FILE for quoting, if needed, and if possible.  Return whether
+   the file can quoted. */
 static bool
 caret_set_file (const char *file)
 {
@@ -276,6 +298,38 @@ location_caret (location loc, const char *style, FILE *out)
      FIXME: should be done in mbfile.  */
   caret_info.mbfile.eof_seen = 0;
 
+  /* Find the number of columns of this line.  */
+  while (true)
+    {
+      mbchar_t c;
+      caret_getc (c);
+      if (mb_iseof (c) || mb_iseq (c, '\n'))
+        break;
+      boundary_compute (&caret_info.pos, mb_ptr (c), mb_len (c));
+    }
+  int line_len = caret_info.pos.column;
+
+  /* Available width.  Eight chars are consumed by the left-margin of
+     the quoting lines.  */
+  int width = columns () - 8;
+  int skip = 0;
+  if (width < line_len)
+    {
+      /* We cannot quote the whole line.  Make sure we can see the
+         beginning of the location.  */
+      skip = width < loc.start.column ? loc.start.column - 10 : 0;
+    }
+  /* If we skip the initial part, we insert "..." before.  */
+  if (skip)
+    width -= 3;
+
+  /* Go back to the beginning of line.  */
+  fseek (caret_info.file, caret_info.offset, SEEK_SET);
+  /* Reset mbf's internal state.
+     FIXME: should be done in mbfile.  */
+  caret_info.mbfile.eof_seen = 0;
+  caret_info.pos.column = 1;
+
   /* Read the actual line.  Don't update the offset, so that we keep a pointer
      to the start of the line.  */
   {
@@ -283,15 +337,19 @@ location_caret (location loc, const char *style, FILE *out)
     caret_getc (c);
     if (!mb_iseof (c))
       {
-        bool single_line = loc.start.line == loc.end.line;
+        /* The last column to highlight.  Only the first line of
+           multiline locations are quoted, in which case the ending
+           column is the end of line.  Single point locations (with
+           equal boundaries) denote the character that they
+           follow.  */
+        int col_end
+          = loc.start.line == loc.end.line
+          ? loc.end.column + (loc.start.column == loc.end.column)
+          : line_len;
         /* Quote the file (at most the first line in the case of
            multiline locations).  */
         {
-          fprintf (out, "%5d | ", loc.start.line);
-          /* Consider that single point location (with equal boundaries)
-             actually denote the character that they follow.  */
-          int col_end = loc.end.column +
-            (single_line && loc.start.column == loc.end.column);
+          fprintf (out, "%5d | %s", loc.start.line, skip ? "..." : "");
           /* Whether we opened the style.  If the line is not as
              expected (maybe the file was changed since the scanner
              ran), we might reach the end before we actually saw the
@@ -304,29 +362,35 @@ location_caret (location loc, const char *style, FILE *out)
                   begin_use_class (style, out);
                   opened = true;
                 }
-              mb_putc (c, out);
+              if (skip < caret_info.pos.column)
+                mb_putc (c, out);
               boundary_compute (&caret_info.pos, mb_ptr (c), mb_len (c));
               caret_getc (c);
               if (opened
-                  && (single_line
-                      ? caret_info.pos.column == col_end
-                      : mb_iseq (c, '\n') || mb_iseof (c)))
-                end_use_class (style, out);
+                  && (caret_info.pos.column == col_end
+                      || width < caret_info.pos.column - skip))
+                {
+                  end_use_class (style, out);
+                  opened = false;
+                }
+              if (width < caret_info.pos.column - skip)
+                break;
             }
           putc ('\n', out);
         }
 
         /* Print the carets with the same indentation as above.  */
         {
-          fprintf (out, "      | %*s", loc.start.column - 1, "");
+          fprintf (out, "      | %s%*s",
+                   skip ? "..." : "",
+                   loc.start.column - 1 - skip, "");
           begin_use_class (style, out);
           putc ('^', out);
           /* Underlining a multiline location ends with the first
              line.  */
-          int len = single_line
-            ? loc.end.column
-            : ftell (caret_info.file) - caret_info.offset;
-          for (int i = loc.start.column + 1; i < len; ++i)
+          for (int i = loc.start.column - 1 - skip + 1,
+                 i_end = min_int (col_end - 1 - skip, width);
+               i < i_end; ++i)
             putc ('~', out);
           end_use_class (style, out);
           putc ('\n', out);
