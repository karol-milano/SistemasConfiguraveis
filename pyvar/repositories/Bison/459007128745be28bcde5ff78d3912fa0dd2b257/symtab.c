@@ -887,17 +887,16 @@ symbol_from_uniqstr (const uniqstr key, location loc)
   symbol probe;
 
   probe.tag = key;
-  symbol *entry = hash_lookup (symbol_table, &probe);
+  symbol *res = hash_lookup (symbol_table, &probe);
 
-  if (!entry)
+  if (!res)
     {
       /* First insertion in the hash. */
       aver (!symbols_sorted);
-      entry = symbol_new (key, loc);
-      if (!hash_insert (symbol_table, entry))
-        xalloc_die ();
+      res = symbol_new (key, loc);
+      hash_xinsert (symbol_table, res);
     }
-  return entry;
+  return res;
 }
 
 
@@ -912,16 +911,15 @@ semantic_type_from_uniqstr (const uniqstr key, const location *loc)
   semantic_type probe;
 
   probe.tag = key;
-  semantic_type *entry = hash_lookup (semantic_type_table, &probe);
+  semantic_type *res = hash_lookup (semantic_type_table, &probe);
 
-  if (!entry)
+  if (!res)
     {
       /* First insertion in the hash. */
-      entry = semantic_type_new (key, loc);
-      if (!hash_insert (semantic_type_table, entry))
-        xalloc_die ();
+      res = semantic_type_new (key, loc);
+      hash_xinsert (semantic_type_table, res);
     }
-  return entry;
+  return res;
 }
 
 
