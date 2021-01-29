@@ -1,6 +1,6 @@
 /* Keep a unique copy of strings.
 
-   Copyright (C) 2002, 2003 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -97,8 +97,8 @@ hash_compare_uniqstr (void const *m1, void const *m2)
   return strcmp (m1, m2) == 0;
 }
 
-static unsigned int
-hash_uniqstr (void const *m, unsigned int tablesize)
+static size_t
+hash_uniqstr (void const *m, size_t tablesize)
 {
   return hash_string (m, tablesize);
 }
