@@ -1,6 +1,7 @@
 /* Symbol table manager for Bison.
 
-   Copyright (C) 1984, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2004 Free Software
+   Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -403,15 +404,15 @@ hash_symbol_comparator (void const *m1, void const *m2)
   return hash_compare_symbol (m1, m2);
 }
 
-static inline unsigned int
-hash_symbol (const symbol *m, unsigned int tablesize)
+static inline size_t
+hash_symbol (const symbol *m, size_t tablesize)
 {
   /* Since tags are unique, we can hash the pointer itself.  */
   return ((uintptr_t) m->tag) % tablesize;
 }
 
-static unsigned int
-hash_symbol_hasher (void const *m, unsigned int tablesize)
+static size_t
+hash_symbol_hasher (void const *m, size_t tablesize)
 {
   return hash_symbol (m, tablesize);
 }
