@@ -1,6 +1,5 @@
 /* Locations for Bison
-
-   Copyright (C) 2002, 2005 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2005, 2006 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -28,11 +27,80 @@
 
 location const empty_location;
 
+/* If BUF is null, add BUFSIZE (which in this case must be less than
+   INT_MAX) to COLUMN; otherwise, add mbsnwidth (BUF, BUFSIZE, 0) to
+   COLUMN.  If an overflow occurs, or might occur but is undetectable,
+   return INT_MAX.  Assume COLUMN is nonnegative.  */
+
+static inline int
+add_column_width (int column, char const *buf, size_t bufsize)
+{
+  size_t width;
+  unsigned int remaining_columns = INT_MAX - column;
+
+  if (buf)
+    {
+      if (INT_MAX / 2 <= bufsize)
+	return INT_MAX;
+      width = mbsnwidth (buf, bufsize, 0);
+    }
+  else
+    width = bufsize;
+
+  return width <= remaining_columns ? column + width : INT_MAX;
+}
+
+/* Set *LOC and adjust scanner cursor to account for token TOKEN of
+   size SIZE.  */
+
+void
+location_compute (location *loc, boundary *cur, char const *token, size_t size)
+{
+  int line = cur->line;
+  int column = cur->column;
+  char const *p0 = token;
+  char const *p = token;
+  char const *lim = token + size;
+
+  loc->start = *cur;
+
+  for (p = token; p < lim; p++)
+    switch (*p)
+      {
+      case '\n':
+	line += line < INT_MAX;
+	column = 1;
+	p0 = p + 1;
+	break;
+
+      case '\t':
+	column = add_column_width (column, p0, p - p0);
+	column = add_column_width (column, NULL, 8 - ((column - 1) & 7));
+	p0 = p + 1;
+	break;
+
+      default:
+	break;
+      }
+
+  cur->line = line;
+  cur->column = column = add_column_width (column, p0, p - p0);
+
+  loc->end = *cur;
+
+  if (line == INT_MAX && loc->start.line != INT_MAX)
+    warn_at (*loc, _("line number overflow"));
+  if (column == INT_MAX && loc->start.column != INT_MAX)
+    warn_at (*loc, _("column number overflow"));
+}
+
+
 /* Output to OUT the location LOC.
    Warning: it uses quotearg's slot 3.  */
 void
 location_print (FILE *out, location loc)
 {
+  int end_col = 0 < loc.end.column ? loc.end.column - 1 : 0;
   fprintf (out, "%s:%d.%d",
 	   quotearg_n_style (3, escape_quoting_style, loc.start.file),
 	   loc.start.line, loc.start.column);
@@ -40,9 +108,9 @@ location_print (FILE *out, location loc)
   if (loc.start.file != loc.end.file)
     fprintf (out, "-%s:%d.%d",
 	     quotearg_n_style (3, escape_quoting_style, loc.end.file),
-	     loc.end.line, loc.end.column - 1);
+	     loc.end.line, end_col);
   else if (loc.start.line < loc.end.line)
-    fprintf (out, "-%d.%d", loc.end.line, loc.end.column - 1);
-  else if (loc.start.column < loc.end.column - 1)
-    fprintf (out, "-%d", loc.end.column - 1);
+    fprintf (out, "-%d.%d", loc.end.line, end_col);
+  else if (loc.start.column < end_col)
+    fprintf (out, "-%d", end_col);
 }
