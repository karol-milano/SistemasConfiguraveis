@@ -1,5 +1,5 @@
 /* Locations for Bison
-   Copyright (C) 2002  Free Software Foundation, Inc.
+   Copyright (C) 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -20,5 +20,25 @@
 
 #include "system.h"
 #include "location.h"
+#include <quotearg.h>
 
-location_t empty_location = { NULL, 0, 0, 0, 0 };
+location_t const empty_location;
+
+/* Output to OUT the location LOC.
+   Warning: it uses quotearg's slot 3.  */
+void
+location_print (FILE *out, location_t loc)
+{
+  fprintf (out, "%s:%d.%d",
+	   quotearg_n_style (3, escape_quoting_style, loc.start.file),
+	   loc.start.line, loc.start.column);
+
+  if (loc.start.file != loc.end.file)
+    fprintf (out, "-%s:%d.%d",
+	     quotearg_n_style (3, escape_quoting_style, loc.end.file),
+	     loc.end.line, loc.end.column - 1);
+  else if (loc.start.line < loc.end.line)
+    fprintf (out, "-%d.%d", loc.end.line, loc.end.column - 1);
+  else if (loc.start.column < loc.end.column - 1)
+    fprintf (out, "-%d", loc.end.column - 1);
+}
