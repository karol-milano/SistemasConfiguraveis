@@ -72,7 +72,8 @@ muscle_init (void)
 void
 muscle_insert (const char *key, const char *value)
 {
-  muscle_entry_t pair = { key, NULL };
+  muscle_entry_t pair;
+  pair.key = key;
   muscle_entry_t *entry = hash_lookup (muscle_table, &pair);
 
   if (!entry)
@@ -88,7 +89,8 @@ muscle_insert (const char *key, const char *value)
 const char*
 muscle_find (const char *key)
 {
-  muscle_entry_t pair = { key, NULL };
+  muscle_entry_t pair;
+  pair.key = key;
   muscle_entry_t *result = hash_lookup (muscle_table, &pair);
   return result ? result->value : NULL;
 }
