@@ -50,8 +50,7 @@ uniqstr_new (char const *str)
     {
       /* First insertion in the hash. */
       res = xstrdup (str);
-      if (!hash_insert (uniqstrs_table, res))
-        xalloc_die ();
+      hash_xinsert (uniqstrs_table, res);
     }
   return res;
 }
@@ -81,9 +80,7 @@ uniqstr_concat (int nargs, ...)
   va_end (args);
 
   *p = '\0';
-  uniqstr res = hash_insert (uniqstrs_table, str);
-  if (!res)
-    xalloc_die ();
+  uniqstr res = hash_xinsert (uniqstrs_table, str);
   if (res != str)
     free (str);
   return res;
