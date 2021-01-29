@@ -98,40 +98,44 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
 
 /* Output to OUT the location LOC.
    Warning: it uses quotearg's slot 3.  */
-void
+unsigned
 location_print (FILE *out, location loc)
 {
+  unsigned res = 0;
   int end_col = 0 != loc.end.column ? loc.end.column - 1 : 0;
-  fprintf (out, "%s",
-           quotearg_n_style (3, escape_quoting_style, loc.start.file));
+  res += fprintf (out, "%s",
+                  quotearg_n_style (3, escape_quoting_style, loc.start.file));
   if (0 <= loc.start.line)
     {
-      fprintf(out, ":%d", loc.start.line);
+      res += fprintf(out, ":%d", loc.start.line);
       if (0 <= loc.start.column)
-        fprintf (out, ".%d", loc.start.column);
+        res += fprintf (out, ".%d", loc.start.column);
     }
   if (loc.start.file != loc.end.file)
     {
-      fprintf (out, "-%s",
-               quotearg_n_style (3, escape_quoting_style, loc.end.file));
+      res += fprintf (out, "-%s",
+                      quotearg_n_style (3, escape_quoting_style,
+                                        loc.end.file));
       if (0 <= loc.end.line)
         {
-          fprintf(out, ":%d", loc.end.line);
+          res += fprintf(out, ":%d", loc.end.line);
           if (0 <= end_col)
-            fprintf (out, ".%d", end_col);
+            res += fprintf (out, ".%d", end_col);
         }
     }
   else if (0 <= loc.end.line)
     {
       if (loc.start.line < loc.end.line)
         {
-          fprintf (out, "-%d", loc.end.line);
+          res += fprintf (out, "-%d", loc.end.line);
           if (0 <= end_col)
-            fprintf (out, ".%d", end_col);
+            res += fprintf (out, ".%d", end_col);
         }
       else if (0 <= end_col && loc.start.column < end_col)
-        fprintf (out, "-%d", end_col);
+        res += fprintf (out, "-%d", end_col);
     }
+
+  return res;
 }
 
 void
