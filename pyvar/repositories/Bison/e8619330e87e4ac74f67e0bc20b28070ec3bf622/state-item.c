@@ -65,6 +65,16 @@ hash_pair_free (hash_pair *hp)
   free (hp);
 }
 
+Hash_table *
+hash_pair_table_create (int size)
+{
+  return hash_xinitialize (size,
+                           NULL,
+                           (Hash_hasher) hash_pair_hasher,
+                           (Hash_comparator) hash_pair_comparator,
+                           (Hash_data_freer) hash_pair_free);
+}
+
 static bitset
 hash_pair_lookup (Hash_table *tab, int key)
 {
@@ -208,8 +218,8 @@ init_trans (void)
       state *s = states[i];
       transitions *t = s->transitions;
       Hash_table *transition_set
-        = hash_initialize (t->num, NULL, (Hash_hasher) state_sym_hasher,
-                           (Hash_comparator) state_sym_comparator, NULL);
+        = hash_xinitialize (t->num, NULL, (Hash_hasher) state_sym_hasher,
+                            (Hash_comparator) state_sym_comparator, NULL);
       for (int j = 0; j < t->num; ++j)
         if (!TRANSITION_IS_DISABLED (t, j))
           hash_xinsert (transition_set, t->states[j]);
@@ -249,21 +259,13 @@ si_prods_lookup (state_item_number si)
 static void
 init_prods (void)
 {
-  si_prods = hash_initialize (nstate_items,
-                              NULL,
-                              (Hash_hasher) hash_pair_hasher,
-                              (Hash_comparator) hash_pair_comparator,
-                              (Hash_data_freer) hash_pair_free);
+  si_prods = hash_pair_table_create (nstate_items);
   for (int i = 0; i < nstates; ++i)
     {
       state *s = states[i];
       // closure_map is a hash map from nonterminals to a set
       // of the items that produce those nonterminals
-      Hash_table *closure_map
-        = hash_initialize (nsyms - ntokens, NULL,
-                           (Hash_hasher) hash_pair_hasher,
-                           (Hash_comparator) hash_pair_comparator,
-                           NULL);
+      Hash_table *closure_map = hash_pair_table_create (nsyms - ntokens);
 
       // Add the nitems of state to skip to the production portion
       // of that state's state_items
@@ -379,8 +381,7 @@ init_firsts (void)
           symbol_number lhs = r->lhs->number;
           bitset f_lhs = FIRSTS (lhs);
           for (item_number *n = r->rhs;
-               item_number_is_symbol_number (*n) &&
-                 ISVAR (*n);
+               item_number_is_symbol_number (*n) && ISVAR (*n);
                ++n)
             {
               bitset f = FIRSTS (*n);
