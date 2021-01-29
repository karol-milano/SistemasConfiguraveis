@@ -1,6 +1,6 @@
 /* Muscle table manager for Bison.
 
-   Copyright (C) 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -50,8 +50,8 @@ hash_compare_muscles (void const *x, void const *y)
   return strcmp (m1->key, m2->key) == 0;
 }
 
-static unsigned int
-hash_muscle (const void *x, unsigned int tablesize)
+static size_t
+hash_muscle (const void *x, size_t tablesize)
 {
   muscle_entry const *m = x;
   return hash_string (m->key, tablesize);
