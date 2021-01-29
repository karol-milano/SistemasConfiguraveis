@@ -1,6 +1,6 @@
 /* Type definitions for nondeterministic finite state machine for Bison.
 
-   Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -279,19 +279,19 @@ state_comparator (void const *s1, void const *s2)
   return state_compare (s1, s2);
 }
 
-static inline unsigned int
-state_hash (state const *s, unsigned int tablesize)
+static inline size_t
+state_hash (state const *s, size_t tablesize)
 {
   /* Add up the state's item numbers to get a hash key.  */
-  unsigned int key = 0;
+  size_t key = 0;
   int i;
   for (i = 0; i < s->nitems; ++i)
     key += s->items[i];
   return key % tablesize;
 }
 
-static unsigned int
-state_hasher (void const *s, unsigned int tablesize)
+static size_t
+state_hasher (void const *s, size_t tablesize)
 {
   return state_hash (s, tablesize);
 }
