@@ -57,8 +57,7 @@ transitions_new (int num, state **the_states)
 state *
 transitions_to (transitions *shifts, symbol_number sym)
 {
-  int j;
-  for (j = 0; ; j++)
+  for (int j = 0; ; j++)
     {
       aver (j < shifts->num);
       if (TRANSITION_SYMBOL (shifts, j) == sym)
@@ -131,12 +130,10 @@ state *
 state_new (symbol_number accessing_symbol,
            size_t nitems, item_number *core)
 {
-  state *res;
-  size_t items_size = nitems * sizeof *core;
-
   aver (nstates < STATE_NUMBER_MAXIMUM);
 
-  res = xmalloc (offsetof (state, items) + items_size);
+  size_t items_size = nitems * sizeof *core;
+  state *res = xmalloc (offsetof (state, items) + items_size);
   res->number = nstates++;
   res->accessing_symbol = accessing_symbol;
   res->transitions = NULL;
@@ -158,12 +155,10 @@ state_new (symbol_number accessing_symbol,
 state *
 state_new_isocore (state const *s)
 {
-  state *res;
-  size_t items_size = s->nitems * sizeof *s->items;
-
   aver (nstates < STATE_NUMBER_MAXIMUM);
 
-  res = xmalloc (offsetof (state, items) + items_size);
+  size_t items_size = s->nitems * sizeof *s->items;
+  state *res = xmalloc (offsetof (state, items) + items_size);
   res->number = nstates++;
   res->accessing_symbol = s->accessing_symbol;
   res->transitions =
@@ -223,9 +218,8 @@ state_reductions_set (state *s, int num, rule **reds)
 int
 state_reduction_find (state *s, rule *r)
 {
-  int i;
   reductions *reds = s->reductions;
-  for (i = 0; i < reds->num; ++i)
+  for (int i = 0; i < reds->num; ++i)
     if (reds->rules[i] == r)
       return i;
   return -1;
@@ -310,12 +304,10 @@ static struct hash_table *state_table = NULL;
 static inline bool
 state_compare (state const *s1, state const *s2)
 {
-  size_t i;
-
   if (s1->nitems != s2->nitems)
     return false;
 
-  for (i = 0; i < s1->nitems; ++i)
+  for (size_t i = 0; i < s1->nitems; ++i)
     if (s1->items[i] != s2->items[i])
       return false;
 
@@ -333,8 +325,7 @@ state_hash (state const *s, size_t tablesize)
 {
   /* Add up the state's item numbers to get a hash key.  */
   size_t key = 0;
-  size_t i;
-  for (i = 0; i < s->nitems; ++i)
+  for (size_t i = 0; i < s->nitems; ++i)
     key += s->items[i];
   return key % tablesize;
 }
@@ -394,11 +385,9 @@ state_hash_lookup (size_t nitems, item_number *core)
 {
   size_t items_size = nitems * sizeof *core;
   state *probe = xmalloc (offsetof (state, items) + items_size);
-  state *entry;
-
   probe->nitems = nitems;
   memcpy (probe->items, core, items_size);
-  entry = hash_lookup (state_table, probe);
+  state *entry = hash_lookup (state_table, probe);
   free (probe);
   return entry;
 }
@@ -414,12 +403,9 @@ state_record_reachable_states (state *s, bitset reachable)
   if (bitset_test (reachable, s->number))
     return;
   bitset_set (reachable, s->number);
-  {
-    int i;
-    for (i = 0; i < s->transitions->num; ++i)
-      if (!TRANSITION_IS_DISABLED (s->transitions, i))
-        state_record_reachable_states (s->transitions->states[i], reachable);
-  }
+  for (int i = 0; i < s->transitions->num; ++i)
+    if (!TRANSITION_IS_DISABLED (s->transitions, i))
+      state_record_reachable_states (s->transitions->states[i], reachable);
 }
 
 void
@@ -428,23 +414,20 @@ state_remove_unreachable_states (state_number old_to_new[])
   state_number nstates_reachable = 0;
   bitset reachable = bitset_create (nstates, BITSET_FIXED);
   state_record_reachable_states (states[0], reachable);
-  {
-    state_number i;
-    for (i = 0; i < nstates; ++i)
-      {
-        if (bitset_test (reachable, states[i]->number))
-          {
-            states[nstates_reachable] = states[i];
-            states[nstates_reachable]->number = nstates_reachable;
-            old_to_new[i] = nstates_reachable++;
-          }
-        else
-          {
-            state_free (states[i]);
-            old_to_new[i] = nstates;
-          }
-      }
-  }
+  for (state_number i = 0; i < nstates; ++i)
+    {
+      if (bitset_test (reachable, states[i]->number))
+        {
+          states[nstates_reachable] = states[i];
+          states[nstates_reachable]->number = nstates_reachable;
+          old_to_new[i] = nstates_reachable++;
+        }
+      else
+        {
+          state_free (states[i]);
+          old_to_new[i] = nstates;
+        }
+    }
   nstates = nstates_reachable;
   bitset_free (reachable);
 }
@@ -460,8 +443,7 @@ state **states = NULL;
 void
 states_free (void)
 {
-  state_number i;
-  for (i = 0; i < nstates; ++i)
+  for (state_number i = 0; i < nstates; ++i)
     state_free (states[i]);
   free (states);
 }
