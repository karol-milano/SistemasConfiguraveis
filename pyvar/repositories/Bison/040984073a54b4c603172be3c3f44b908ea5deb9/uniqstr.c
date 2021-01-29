@@ -1,6 +1,6 @@
 /* Keep a unique copy of strings.
 
-   Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -63,7 +63,8 @@ uniqstr_assert (char const *str)
 {
   if (!hash_lookup (uniqstrs_table, str))
     {
-      error (0, 0, "not a uniqstr: %s", quotearg (str));
+      error (0, 0,
+	     "not a uniqstr: %s", quotearg (str));
       abort ();
     }
 }
