@@ -1,6 +1,6 @@
 /* Keep a unique copy of strings.
 
-   Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004, 2005, 2009 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -47,7 +47,8 @@ uniqstr_new (char const *str)
     {
       /* First insertion in the hash. */
       res = xstrdup (str);
-      hash_insert (uniqstrs_table, res);
+      if (!hash_insert (uniqstrs_table, res))
+        xalloc_die ();
     }
   return res;
 }
