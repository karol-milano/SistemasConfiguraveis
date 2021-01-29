@@ -77,7 +77,7 @@ hash_pair_lookup (Hash_table *tab, int key)
 static void
 hash_pair_insert (Hash_table *tab, int key, bitset val)
 {
-  hash_pair *hp = xmalloc (sizeof (hash_pair));
+  hash_pair *hp = xmalloc (sizeof *hp);
   hp->key = key;
   hp->l = val;
   hash_pair *res = hash_xinsert (tab, hp);
@@ -236,7 +236,7 @@ init_trans (void)
                 }
             }
         }
-      free (transition_set);
+      hash_free (transition_set);
     }
 }
 
@@ -306,7 +306,7 @@ init_prods (void)
                 bitset_set (si_revs[prod], j);
             }
         }
-      free (closure_map);
+      hash_free (closure_map);
     }
 }
 
