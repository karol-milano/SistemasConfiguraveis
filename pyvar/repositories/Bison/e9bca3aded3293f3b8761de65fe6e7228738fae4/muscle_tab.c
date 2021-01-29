@@ -73,8 +73,10 @@ void
 muscle_insert (const char *key, const char *value)
 {
   muscle_entry_t pair;
+  muscle_entry_t *entry = NULL;
+
   pair.key = key;
-  muscle_entry_t *entry = hash_lookup (muscle_table, &pair);
+  entry = hash_lookup (muscle_table, &pair);
 
   if (!entry)
     {
@@ -90,8 +92,10 @@ const char*
 muscle_find (const char *key)
 {
   muscle_entry_t pair;
+  muscle_entry_t *result = NULL;
+
   pair.key = key;
-  muscle_entry_t *result = hash_lookup (muscle_table, &pair);
+  result = hash_lookup (muscle_table, &pair);
   return result ? result->value : NULL;
 }
 
