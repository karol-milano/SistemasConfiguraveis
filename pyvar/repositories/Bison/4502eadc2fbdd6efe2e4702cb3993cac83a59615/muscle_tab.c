@@ -123,9 +123,11 @@ muscle_insert (char const *key, char const *value)
       entry = xmalloc (sizeof *entry);
       entry->key = key;
       hash_insert (muscle_table, entry);
-      entry->storage = NULL;
     }
+  else
+    free (entry->storage);
   entry->value = value;
+  entry->storage = NULL;
 }
 
 
@@ -207,9 +209,11 @@ void muscle_pair_list_grow (const char *muscle,
   obstack_free (&muscle_obstack, pair);
 }
 
-/*-------------------------------.
-| Find the value of muscle KEY.  |
-`-------------------------------*/
+/*----------------------------------------------------------------------------.
+| Find the value of muscle KEY.  Abort if muscle_insert was invoked more      |
+| recently than muscle_grow for KEY since muscle_find can't return a          |
+| char const *.                                                               |
+`----------------------------------------------------------------------------*/
 
 char *
 muscle_find (const char *key)
@@ -219,7 +223,12 @@ muscle_find (const char *key)
 
   probe.key = key;
   result = hash_lookup (muscle_table, &probe);
-  return result ? result->value : NULL;
+  if (result)
+    {
+      aver (result->value == result->storage);
+      return result->storage;
+    }
+  return NULL;
 }
 
 
