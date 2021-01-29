@@ -42,7 +42,7 @@ add_column_width (int column, char const *buf, size_t bufsize)
   if (buf)
     {
       if (INT_MAX / 2 <= bufsize)
-	return INT_MAX;
+        return INT_MAX;
       width = mbsnwidth (buf, bufsize, 0);
     }
   else
@@ -69,19 +69,19 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
     switch (*p)
       {
       case '\n':
-	line += line < INT_MAX;
-	column = 1;
-	p0 = p + 1;
-	break;
+        line += line < INT_MAX;
+        column = 1;
+        p0 = p + 1;
+        break;
 
       case '\t':
-	column = add_column_width (column, p0, p - p0);
-	column = add_column_width (column, NULL, 8 - ((column - 1) & 7));
-	p0 = p + 1;
-	break;
+        column = add_column_width (column, p0, p - p0);
+        column = add_column_width (column, NULL, 8 - ((column - 1) & 7));
+        p0 = p + 1;
+        break;
 
       default:
-	break;
+        break;
       }
 
   cur->line = line;
