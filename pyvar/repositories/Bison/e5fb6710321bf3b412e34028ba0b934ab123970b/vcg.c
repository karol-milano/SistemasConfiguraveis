@@ -1,5 +1,5 @@
 /* VCG description handler for Bison.
-   Copyright 2001 Free Software Foundation, Inc.
+   Copyright 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -23,12 +23,14 @@
 #include "vcg_defaults.h"
 #include "quotearg.h"
 
-/* Return an unambiguous printable representated, allocated in slot 0,
-   for NAME, suitable for C strings.  */
+/* Return an unambiguous printable representated, for NAME, suitable
+   for C strings.  Use slot 2 since the user may use slots 0 and 1.
+   */
+
 static char const *
 quote (char const *name)
 {
-  return quotearg_n_style (0, c_quoting_style, name);
+  return quotearg_n_style (2, c_quoting_style, name);
 }
 
 
