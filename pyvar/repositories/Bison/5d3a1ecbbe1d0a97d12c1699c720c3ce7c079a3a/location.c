@@ -1,5 +1,5 @@
 /* Locations for Bison
-   Copyright (C) 2002, 2005, 2006, 2007 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2005, 2006, 2007, 2008 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -101,9 +101,11 @@ void
 location_print (FILE *out, location loc)
 {
   int end_col = 0 < loc.end.column ? loc.end.column - 1 : 0;
-  fprintf (out, "%s:%d.%d",
+  fprintf (out, "%s:%d",
 	   quotearg_n_style (3, escape_quoting_style, loc.start.file),
-	   loc.start.line, loc.start.column);
+	   loc.start.line);
+  if (0 <= loc.start.column)
+    fprintf (out, ".%d", loc.start.column);
 
   if (loc.start.file != loc.end.file)
     fprintf (out, "-%s:%d.%d",
@@ -111,7 +113,7 @@ location_print (FILE *out, location loc)
 	     loc.end.line, end_col);
   else if (loc.start.line < loc.end.line)
     fprintf (out, "-%d.%d", loc.end.line, end_col);
-  else if (loc.start.column < end_col)
+  else if (0 <= loc.start.column && loc.start.column < end_col)
     fprintf (out, "-%d", end_col);
 }
 
