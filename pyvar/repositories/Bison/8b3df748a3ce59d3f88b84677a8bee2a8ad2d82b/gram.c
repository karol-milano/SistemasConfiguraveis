@@ -1,5 +1,5 @@
 /* Allocate input grammar variables for bison,
-   Copyright 1984, 1986, 1989, 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -20,6 +20,7 @@
 
 
 #include "system.h"
+#include "quotearg.h"
 #include "gram.h"
 #include "symtab.h"
 #include "reader.h"
@@ -77,7 +78,8 @@ ritem_print (FILE *out)
   fputs ("RITEM\n", out);
   for (i = 0; i < nritems; ++i)
     if (ritem[i] >= 0)
-      fprintf (out, "  %s", symbols[ritem[i]]->tag);
+      fprintf (out, "  %s", quotearg_style (escape_quoting_style,
+					    symbols[ritem[i]]->tag));
     else
       fprintf (out, "  (rule %d)\n", -ritem[i] - 1);
   fputs ("\n\n", out);
