@@ -38,7 +38,7 @@ hash_compare_muscles (void const *x, void const *y)
 {
   const muscle_entry_t *m1 = x;
   const muscle_entry_t *m2 = y;
-  return strcmp (m1->key, m2->key) ? FALSE : TRUE;
+  return strcmp (m1->key, m2->key) == 0;
 }
 
 static unsigned int
