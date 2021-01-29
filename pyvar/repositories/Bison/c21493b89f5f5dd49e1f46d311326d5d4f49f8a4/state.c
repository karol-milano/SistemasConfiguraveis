@@ -1,6 +1,7 @@
 /* Type definitions for nondeterministic finite state machine for Bison.
 
-   Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006 Free Software
+   Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -58,10 +59,13 @@ state *
 transitions_to (transitions *shifts, symbol_number sym)
 {
   int j;
-  for (j = 0; j < shifts->num; j++)
-    if (TRANSITION_SYMBOL (shifts, j) == sym)
-      return shifts->states[j];
-  abort ();
+  for (j = 0; ; j++)
+    {
+      if (shifts->num <= j)
+	abort ();
+      if (TRANSITION_SYMBOL (shifts, j) == sym)
+	return shifts->states[j];
+    }
 }
 
 
