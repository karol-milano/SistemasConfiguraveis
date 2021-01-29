@@ -82,8 +82,7 @@ hash_pair_insert (Hash_table *tab, int key, bitset val)
   hash_pair *hp = xmalloc (sizeof (hash_pair));
   hp->key = key;
   hp->l = val;
-  if (!hash_insert (tab, hp))
-    xalloc_die ();
+  hash_xinsert (tab, hp);
 }
 
 static void
@@ -211,8 +210,7 @@ init_trans (void)
                            (Hash_comparator) state_sym_comparator, NULL);
       for (int j = 0; j < t->num; ++j)
         if (!TRANSITION_IS_DISABLED (t, j))
-          if (!hash_insert (transition_set, t->states[j]))
-            xalloc_die ();
+          hash_xinsert (transition_set, t->states[j]);
       for (int j = state_item_map[i]; j < state_item_map[i + 1]; ++j)
         {
           item_number *item = state_items[j].item;
@@ -298,11 +296,10 @@ init_prods (void)
               hash_pair *prod_hp = xmalloc (sizeof (hash_pair));
               prod_hp->key = j;
               prod_hp->l = copy;
-              //update prods
-              if (!hash_insert (si_prods, prod_hp))
-                xalloc_die ();
+              // update prods.
+              hash_xinsert (si_prods, prod_hp);
 
-              //update revs
+              // update revs.
               bitset_iterator biter;
               state_item_number prod;
               BITSET_FOR_EACH (biter, copy, prod, 0)
