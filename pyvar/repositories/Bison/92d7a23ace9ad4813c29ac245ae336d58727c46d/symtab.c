@@ -735,7 +735,8 @@ symbol_from_uniqstr (const uniqstr key, location loc)
     {
       /* First insertion in the hash. */
       entry = symbol_new (key, loc);
-      hash_insert (symbol_table, entry);
+      if (!hash_insert (symbol_table, entry))
+        xalloc_die ();
     }
   return entry;
 }
@@ -759,7 +760,8 @@ semantic_type_from_uniqstr (const uniqstr key)
     {
       /* First insertion in the hash. */
       entry = semantic_type_new (key);
-      hash_insert (semantic_type_table, entry);
+      if (!hash_insert (semantic_type_table, entry))
+        xalloc_die ();
     }
   return entry;
 }
