@@ -1,6 +1,7 @@
 /* Closures for Bison
 
-   Copyright (C) 1984, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2004 Free Software
+   Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -180,9 +181,9 @@ set_fderives (void)
 
 
 void
-new_closure (int n)
+new_closure (unsigned int n)
 {
-  CALLOC (itemset, n);
+  itemset = xnmalloc (n, sizeof *itemset);
 
   ruleset = bitset_create (nrules, BITSET_FIXED);
 
