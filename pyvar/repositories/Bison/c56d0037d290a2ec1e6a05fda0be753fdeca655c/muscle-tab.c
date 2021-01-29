@@ -60,6 +60,19 @@ hash_muscle (const void *x, size_t tablesize)
   return hash_string (m->key, tablesize);
 }
 
+/* Create a fresh muscle name KEY, and insert in the hash table.  */
+static void *
+muscle_entry_new (char const *key)
+{
+  muscle_entry *res = xmalloc (sizeof *res);
+  res->key = key;
+  res->value = NULL;
+  res->storage = NULL;
+  if (!hash_insert (muscle_table, res))
+    xalloc_die ();
+  return res;
+}
+
 static void
 muscle_entry_free (void *entry)
 {
@@ -89,26 +102,26 @@ muscle_free (void)
   obstack_free (&muscle_obstack, NULL);
 }
 
-
-void
-muscle_insert (char const *key, char const *value)
+/* Look for the muscle named KEY.  Return NULL if does not exist.  */
+static
+muscle_entry *
+muscle_lookup (char const *key)
 {
   muscle_entry probe;
-  muscle_entry *entry;
-
   probe.key = key;
-  entry = hash_lookup (muscle_table, &probe);
+  return hash_lookup (muscle_table, &probe);
+}
 
-  if (!entry)
-    {
-      /* First insertion in the hash. */
-      entry = xmalloc (sizeof *entry);
-      entry->key = key;
-      if (!hash_insert (muscle_table, entry))
-        xalloc_die ();
-    }
-  else
+
+void
+muscle_insert (char const *key, char const *value)
+{
+  muscle_entry *entry = muscle_lookup (key);
+  if (entry)
     free (entry->storage);
+  else
+    /* First insertion in the hash. */
+    entry = muscle_entry_new (key);
   entry->value = value;
   entry->storage = NULL;
 }
@@ -123,22 +136,9 @@ muscle_insert (char const *key, char const *value)
 void
 muscle_grow (const char *key, const char *val, const char *separator)
 {
-  muscle_entry probe;
-  muscle_entry *entry = NULL;
+  muscle_entry *entry = muscle_lookup (key);
 
-  probe.key = key;
-  entry = hash_lookup (muscle_table, &probe);
-
-  if (!entry)
-    {
-      /* First insertion in the hash. */
-      entry = xmalloc (sizeof *entry);
-      entry->key = key;
-      if (!hash_insert (muscle_table, entry))
-        xalloc_die ();
-      entry->value = entry->storage = xstrdup (val);
-    }
-  else
+  if (entry)
     {
       /* Grow the current value. */
       char *new_val;
@@ -148,6 +148,12 @@ muscle_grow (const char *key, const char *val, const char *separator)
       entry->value = entry->storage = xstrdup (new_val);
       obstack_free (&muscle_obstack, new_val);
     }
+  else
+    {
+      /* First insertion in the hash. */
+      entry = muscle_entry_new (key);
+      entry->value = entry->storage = xstrdup (val);
+    }
 }
 
 /*------------------------------------------------------------------.
@@ -182,8 +188,9 @@ muscle_code_grow (const char *key, const char *val, location loc)
 }
 
 
-void muscle_pair_list_grow (const char *muscle,
-                            const char *a1, const char *a2)
+void
+muscle_pair_list_grow (const char *muscle,
+                       const char *a1, const char *a2)
 {
   char *pair;
   obstack_sgrow (&muscle_obstack, "[");
@@ -200,29 +207,19 @@ void muscle_pair_list_grow (const char *muscle,
 char const *
 muscle_find_const (char const *key)
 {
-  muscle_entry probe;
-  muscle_entry *result = NULL;
-
-  probe.key = key;
-  result = hash_lookup (muscle_table, &probe);
-  if (result)
-    return result->value;
-  return NULL;
+  muscle_entry *entry = muscle_lookup (key);
+  return entry ? entry->value : NULL;
 }
 
 
 char *
 muscle_find (char const *key)
 {
-  muscle_entry probe;
-  muscle_entry *result = NULL;
-
-  probe.key = key;
-  result = hash_lookup (muscle_table, &probe);
-  if (result)
+  muscle_entry *entry = muscle_lookup (key);
+  if (entry)
     {
-      aver (result->value == result->storage);
-      return result->storage;
+      aver (entry->value == entry->storage);
+      return entry->storage;
     }
   return NULL;
 }
