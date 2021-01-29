@@ -120,7 +120,8 @@ muscle_insert (char const *key, char const *value)
       /* First insertion in the hash. */
       entry = xmalloc (sizeof *entry);
       entry->key = key;
-      hash_insert (muscle_table, entry);
+      if (!hash_insert (muscle_table, entry))
+        xalloc_die ();
     }
   else
     free (entry->storage);
@@ -149,7 +150,8 @@ muscle_grow (const char *key, const char *val, const char *separator)
       /* First insertion in the hash. */
       entry = xmalloc (sizeof *entry);
       entry->key = key;
-      hash_insert (muscle_table, entry);
+      if (!hash_insert (muscle_table, entry))
+        xalloc_die ();
       entry->value = entry->storage = xstrdup (val);
     }
   else
