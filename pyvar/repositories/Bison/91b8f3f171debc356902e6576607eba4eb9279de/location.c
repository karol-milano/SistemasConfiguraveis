@@ -27,6 +27,7 @@
 #include <sys/stat.h> /* fstat */
 
 #include "complain.h"
+#include "getargs.h"
 #include "location.h"
 
 location const empty_location = EMPTY_LOCATION_INIT;
@@ -96,42 +97,58 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
     complain (loc, Wother, _("byte number overflow"));
 }
 
+static unsigned
+boundary_print (boundary const *b, FILE *out)
+{
+  return fprintf (out, "%s:%d.%d@%d",
+                  quotearg_n_style (3, escape_quoting_style, b->file),
+                  b->line, b->column, b->byte);
+}
 
 unsigned
 location_print (location loc, FILE *out)
 {
   unsigned res = 0;
-  int end_col = 0 != loc.end.column ? loc.end.column - 1 : 0;
-  res += fprintf (out, "%s",
-                  quotearg_n_style (3, escape_quoting_style, loc.start.file));
-  if (0 <= loc.start.line)
+  if (trace_flag & trace_locations)
     {
-      res += fprintf (out, ":%d", loc.start.line);
-      if (0 <= loc.start.column)
-        res += fprintf (out, ".%d", loc.start.column);
+      res += boundary_print (&loc.start, out);
+      res += fprintf (out, "-");
+      res += boundary_print (&loc.end, out);
     }
-  if (loc.start.file != loc.end.file)
+  else
     {
-      res += fprintf (out, "-%s",
-                      quotearg_n_style (3, escape_quoting_style,
-                                        loc.end.file));
-      if (0 <= loc.end.line)
+      int end_col = 0 != loc.end.column ? loc.end.column - 1 : 0;
+      res += fprintf (out, "%s",
+                      quotearg_n_style (3, escape_quoting_style, loc.start.file));
+      if (0 <= loc.start.line)
         {
-          res += fprintf (out, ":%d", loc.end.line);
-          if (0 <= end_col)
-            res += fprintf (out, ".%d", end_col);
+          res += fprintf (out, ":%d", loc.start.line);
+          if (0 <= loc.start.column)
+            res += fprintf (out, ".%d", loc.start.column);
         }
-    }
-  else if (0 <= loc.end.line)
-    {
-      if (loc.start.line < loc.end.line)
+      if (loc.start.file != loc.end.file)
         {
-          res += fprintf (out, "-%d", loc.end.line);
-          if (0 <= end_col)
-            res += fprintf (out, ".%d", end_col);
+          res += fprintf (out, "-%s",
+                          quotearg_n_style (3, escape_quoting_style,
+                                            loc.end.file));
+          if (0 <= loc.end.line)
+            {
+              res += fprintf (out, ":%d", loc.end.line);
+              if (0 <= end_col)
+                res += fprintf (out, ".%d", end_col);
+            }
+        }
+      else if (0 <= loc.end.line)
+        {
+          if (loc.start.line < loc.end.line)
+            {
+              res += fprintf (out, "-%d", loc.end.line);
+              if (0 <= end_col)
+                res += fprintf (out, ".%d", end_col);
+            }
+          else if (0 <= end_col && loc.start.column < end_col)
+            res += fprintf (out, "-%d", end_col);
         }
-      else if (0 <= end_col && loc.start.column < end_col)
-        res += fprintf (out, "-%d", end_col);
     }
 
   return res;
