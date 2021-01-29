@@ -99,7 +99,7 @@ void
 muscle_insert (const char *key, char *value)
 {
   muscle_entry probe;
-  muscle_entry *entry = NULL;
+  muscle_entry *entry;
 
   probe.key = key;
   entry = hash_lookup (muscle_table, &probe);
@@ -107,7 +107,7 @@ muscle_insert (const char *key, char *value)
   if (!entry)
     {
       /* First insertion in the hash. */
-      MALLOC (entry, 1);
+      entry = xmalloc (sizeof *entry);
       entry->key = key;
       hash_insert (muscle_table, entry);
     }
@@ -133,7 +133,7 @@ muscle_grow (const char *key, const char *val, const char *separator)
   if (!entry)
     {
       /* First insertion in the hash. */
-      MALLOC (entry, 1);
+      entry = xmalloc (sizeof *entry);
       entry->key = key;
       hash_insert (muscle_table, entry);
       entry->value = xstrdup (val);
