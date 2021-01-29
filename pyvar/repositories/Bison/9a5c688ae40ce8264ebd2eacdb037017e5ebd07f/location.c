@@ -37,7 +37,7 @@ static inline int
 add_column_width (int column, char const *buf, size_t bufsize)
 {
   size_t width;
-  unsigned int remaining_columns = INT_MAX - column;
+  unsigned remaining_columns = INT_MAX - column;
 
   if (buf)
     {
