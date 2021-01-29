@@ -111,7 +111,7 @@ uniqstr_print_processor (void *ustr, void *null ATTRIBUTE_UNUSED)
 static bool
 hash_compare_uniqstr (void const *m1, void const *m2)
 {
-  return strcmp (m1, m2) == 0;
+  return STREQ (m1, m2);
 }
 
 static size_t
