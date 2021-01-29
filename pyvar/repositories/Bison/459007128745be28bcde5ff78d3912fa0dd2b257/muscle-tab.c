@@ -107,8 +107,7 @@ muscle_entry_new (char const *key)
   res->key = key;
   res->value = NULL;
   res->storage = NULL;
-  if (!hash_insert (muscle_table, res))
-    xalloc_die ();
+  hash_xinsert (muscle_table, res);
   return res;
 }
 
