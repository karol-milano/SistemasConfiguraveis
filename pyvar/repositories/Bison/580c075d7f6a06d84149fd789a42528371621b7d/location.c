@@ -1,5 +1,6 @@
 /* Locations for Bison
-   Copyright (C) 2002, 2005, 2006, 2007, 2008 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2005, 2006, 2007, 2008, 2009 Free Software Foundation,
+   Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -100,21 +101,37 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
 void
 location_print (FILE *out, location loc)
 {
-  int end_col = 0 < loc.end.column ? loc.end.column - 1 : 0;
-  fprintf (out, "%s:%d",
-	   quotearg_n_style (3, escape_quoting_style, loc.start.file),
-	   loc.start.line);
-  if (0 <= loc.start.column)
-    fprintf (out, ".%d", loc.start.column);
-
+  int end_col = 0 != loc.end.column ? loc.end.column - 1 : 0;
+  fprintf (out, "%s",
+           quotearg_n_style (3, escape_quoting_style, loc.start.file));
+  if (0 <= loc.start.line)
+    {
+      fprintf(out, ":%d", loc.start.line);
+      if (0 <= loc.start.column)
+        fprintf (out, ".%d", loc.start.column);
+    }
   if (loc.start.file != loc.end.file)
-    fprintf (out, "-%s:%d.%d",
-	     quotearg_n_style (3, escape_quoting_style, loc.end.file),
-	     loc.end.line, end_col);
-  else if (loc.start.line < loc.end.line)
-    fprintf (out, "-%d.%d", loc.end.line, end_col);
-  else if (0 <= loc.start.column && loc.start.column < end_col)
-    fprintf (out, "-%d", end_col);
+    {
+      fprintf (out, "-%s",
+               quotearg_n_style (3, escape_quoting_style, loc.end.file));
+      if (0 <= loc.end.line)
+        {
+          fprintf(out, ":%d", loc.end.line);
+          if (0 <= end_col)
+            fprintf (out, ".%d", end_col);
+        }
+    }
+  else if (0 <= loc.end.line)
+    {
+      if (loc.start.line < loc.end.line)
+        {
+          fprintf (out, "-%d", loc.end.line);
+          if (0 <= end_col)
+            fprintf (out, ".%d", end_col);
+        }
+      else if (0 <= end_col && loc.start.column < end_col)
+        fprintf (out, "-%d", end_col);
+    }
 }
 
 void
