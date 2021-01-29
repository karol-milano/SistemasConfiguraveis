@@ -68,13 +68,10 @@ hash_pair_free (hash_pair *hp)
 static bitset
 hash_pair_lookup (Hash_table *tab, int key)
 {
-  hash_pair *l = xmalloc (sizeof (hash_pair));
-  l->key = key;
-  hash_pair *hp = (hash_pair *) hash_lookup (tab, l);
-  if (!hp)
-    return NULL;
-  free (l);
-  return hp->l;
+  hash_pair probe;
+  probe.key = key;
+  hash_pair *hp = hash_lookup (tab, &probe);
+  return hp ? hp->l : NULL;
 }
 
 static void
@@ -83,15 +80,18 @@ hash_pair_insert (Hash_table *tab, int key, bitset val)
   hash_pair *hp = xmalloc (sizeof (hash_pair));
   hp->key = key;
   hp->l = val;
-  hash_xinsert (tab, hp);
+  hash_pair *res = hash_xinsert (tab, hp);
+  // This must be the first insertion.
+  (void) res;
+  assert (res == hp);
 }
 
 static void
 hash_pair_remove (Hash_table *tab, int key)
 {
-  hash_pair *hp = xmalloc (sizeof (hash_pair));
-  hp->key = key;
-  hash_delete (tab, hp);
+  hash_pair probe;
+  probe.key = key;
+  hash_delete (tab, &probe);
 }
 
 /* A state_item from a state's id and the offset of the item within
@@ -193,11 +193,9 @@ state_sym_comparator (const void *s1, const void *s2)
 static state *
 state_sym_lookup (symbol_number sym, Hash_table *h)
 {
-  state *s = xmalloc (sizeof (state));
-  s->accessing_symbol = sym;
-  state *res = hash_lookup (h, s);
-  free (s);
-  return res;
+  state probe;
+  probe.accessing_symbol = sym;
+  return hash_lookup (h, &probe);
 }
 
 static void
@@ -298,11 +296,8 @@ init_prods (void)
             {
               bitset copy = bitset_create (nstate_items, BITSET_SPARSE);
               bitset_copy (copy, lb);
-              hash_pair *prod_hp = xmalloc (sizeof (hash_pair));
-              prod_hp->key = j;
-              prod_hp->l = copy;
               // update prods.
-              hash_xinsert (si_prods, prod_hp);
+              hash_pair_insert (si_prods, j, copy);
 
               // update revs.
               bitset_iterator biter;
