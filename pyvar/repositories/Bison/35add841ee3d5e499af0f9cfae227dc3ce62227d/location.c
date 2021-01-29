@@ -31,25 +31,16 @@ location const empty_location = EMPTY_LOCATION_INIT;
 
 /* If BUF is null, add BUFSIZE (which in this case must be less than
    INT_MAX) to COLUMN; otherwise, add mbsnwidth (BUF, BUFSIZE, 0) to
-   COLUMN.  If an overflow occurs, or might occur but is undetectable,
-   return INT_MAX.  Assume COLUMN is nonnegative.  */
+   COLUMN.  If an overflow occurs, return INT_MAX.  */
 
 static inline int
 add_column_width (int column, char const *buf, size_t bufsize)
 {
-  size_t width;
-  unsigned remaining_columns = INT_MAX - column;
-
-  if (buf)
-    {
-      if (INT_MAX / 2 <= bufsize)
-        return INT_MAX;
-      width = mbsnwidth (buf, bufsize, 0);
-    }
-  else
-    width = bufsize;
-
-  return width <= remaining_columns ? column + width : INT_MAX;
+  int width
+    = buf ? mbsnwidth (buf, bufsize, 0)
+    : INT_MAX <= bufsize ? INT_MAX
+    : bufsize;
+  return column <= INT_MAX - width ? column + width : INT_MAX;
 }
 
 /* Set *LOC and adjust scanner cursor to account for token TOKEN of
@@ -66,7 +57,7 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
 
   loc->start = *cur;
 
-  for (p = token; p < lim; p++)
+  for (p = token; p < lim; ++p)
     switch (*p)
       {
       case '\n':
