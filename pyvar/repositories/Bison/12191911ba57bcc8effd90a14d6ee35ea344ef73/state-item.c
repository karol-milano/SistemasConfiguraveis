@@ -211,7 +211,7 @@ init_trans (void)
       for (int j = 0; j < t->num; ++j)
         if (!TRANSITION_IS_DISABLED (t, j))
           hash_xinsert (transition_set, t->states[j]);
-      for (int j = state_item_map[i]; j < state_item_map[i + 1]; ++j)
+      for (state_item_number j = state_item_map[i]; j < state_item_map[i + 1]; ++j)
         {
           item_number *item = state_items[j].item;
           if (item_number_is_rule_number (*item))
@@ -248,7 +248,7 @@ init_prods (void)
 
       // Add the nitems of state to skip to the production portion
       // of that state's state_items
-      for (int j = state_item_map[i] + s->nitems;
+      for (state_item_number j = state_item_map[i] + s->nitems;
            j < state_item_map[i + 1]; ++j)
         {
           state_item *src = &state_items[j];
@@ -264,7 +264,7 @@ init_prods (void)
         }
       // For each item with a dot followed by a nonterminal,
       // try to create a production edge.
-      for (int j = state_item_map[i]; j < state_item_map[i + 1]; ++j)
+      for (state_item_number j = state_item_map[i]; j < state_item_map[i + 1]; ++j)
         {
           state_item *src = &state_items[j];
           item_number item = *(src->item);
@@ -492,7 +492,7 @@ state_items_report (void)
   for (state_number i = 0; i < nstates; ++i)
     {
       printf ("State %d:\n", i);
-      for (int j = state_item_map[i]; j < state_item_map[i + 1]; ++j)
+      for (state_item_number j = state_item_map[i]; j < state_item_map[i + 1]; ++j)
         {
           state_item *si = &state_items[j];
           item_print (si->item, NULL, stdout);
@@ -560,7 +560,7 @@ state_items_init (void)
 void
 state_items_free (void)
 {
-  for (int i = 0; i < nstate_items; ++i)
+  for (state_item_number i = 0; i < nstate_items; ++i)
     if (!SI_DISABLED (i))
       {
         state_item *si = &state_items[i];
@@ -592,5 +592,5 @@ production_allowed (const state_item *si, const state_item *next)
       if (prec1 == prec2 && s1->assoc == left_assoc)
         return false;
     }
-    return true;
+  return true;
 }
