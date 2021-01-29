@@ -46,11 +46,8 @@ add_column_width (int column, char const *buf, size_t bufsize)
   return column <= INT_MAX - width ? column + width : INT_MAX;
 }
 
-/* Set *LOC and adjust scanner cursor to account for token TOKEN of
-   size SIZE.  */
-
-void
-location_compute (location *loc, boundary *cur, char const *token, size_t size)
+static void
+boundary_compute (boundary *cur, char const *token, size_t size)
 {
   int line = cur->line;
   int column = cur->column;
@@ -59,8 +56,6 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
   char const *p = token;
   char const *lim = token + size;
 
-  loc->start = *cur;
-
   for (p = token; p < lim; ++p)
     switch (*p)
       {
@@ -82,18 +77,29 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
         byte += byte < INT_MAX;
         break;
       }
+  column = add_column_width (column, p0, p - p0);
 
   cur->line = line;
-  cur->column = column = add_column_width (column, p0, p - p0);
+  cur->column = column;
   cur->byte = byte;
+}
 
+
+/* Set *LOC and adjust scanner cursor to account for token TOKEN of
+   size SIZE.  */
+
+void
+location_compute (location *loc, boundary *cur, char const *token, size_t size)
+{
+  loc->start = *cur;
+  boundary_compute (cur, token, size);
   loc->end = *cur;
 
-  if (line == INT_MAX && loc->start.line != INT_MAX)
+  if (loc->end.line == INT_MAX && loc->start.line != INT_MAX)
     complain (loc, Wother, _("line number overflow"));
-  if (column == INT_MAX && loc->start.column != INT_MAX)
+  if (loc->end.column == INT_MAX && loc->start.column != INT_MAX)
     complain (loc, Wother, _("column number overflow"));
-  if (byte == INT_MAX && loc->start.byte != INT_MAX)
+  if (loc->end.byte == INT_MAX && loc->start.byte != INT_MAX)
     complain (loc, Wother, _("byte number overflow"));
 }
 
