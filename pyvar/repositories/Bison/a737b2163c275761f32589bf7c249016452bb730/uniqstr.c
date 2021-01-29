@@ -1,6 +1,6 @@
 /* Keep a unique copy of strings.
 
-   Copyright (C) 2002 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -41,13 +41,13 @@ static struct hash_table *uniqstrs_table = NULL;
 `-------------------------------------*/
 
 uniqstr
-uniqstr_new (char const *s)
+uniqstr_new (char const *str)
 {
-  uniqstr res = hash_lookup (uniqstrs_table, s);
+  uniqstr res = hash_lookup (uniqstrs_table, str);
   if (!res)
     {
       /* First insertion in the hash. */
-      res = xstrdup (s);
+      res = xstrdup (str);
       hash_insert (uniqstrs_table, res);
     }
   return res;
@@ -59,11 +59,11 @@ uniqstr_new (char const *s)
 `------------------------------*/
 
 void
-uniqstr_assert (char const *s)
+uniqstr_assert (char const *str)
 {
-  if (!hash_lookup (uniqstrs_table, s))
+  if (!hash_lookup (uniqstrs_table, str))
     {
-      error (0, 0, "not a uniqstr: %s", quotearg (s));
+      error (0, 0, "not a uniqstr: %s", quotearg (str));
       abort ();
     }
 }
@@ -74,16 +74,16 @@ uniqstr_assert (char const *s)
 `--------------------*/
 
 static inline bool
-uniqstr_print (uniqstr s)
+uniqstr_print (uniqstr ustr)
 {
-  fprintf (stderr, "%s\n", s);
+  fprintf (stderr, "%s\n", ustr);
   return true;
 }
 
 static bool
-uniqstr_print_processor (void *s, void *null ATTRIBUTE_UNUSED)
+uniqstr_print_processor (void *ustr, void *null ATTRIBUTE_UNUSED)
 {
-  return uniqstr_print (s);
+  return uniqstr_print (ustr);
 }
 
 
