@@ -77,7 +77,8 @@ uniqstr_vsprintf (char const *format, ...)
 void
 uniqstr_assert (char const *str)
 {
-  if (!hash_lookup (uniqstrs_table, str))
+  uniqstr *s = hash_lookup (uniqstrs_table, str);
+  if (!s || s != (uniqstr *)str)
     {
       error (0, 0,
              "not a uniqstr: %s", quotearg (str));
