@@ -145,6 +145,7 @@ state_new (symbol_number accessing_symbol,
   res->errs = NULL;
   res->consistent = 0;
   res->solved_conflicts = NULL;
+  res->reachable = false;
 
   res->nitems = nitems;
   memcpy (res->items, core, items_size);
@@ -352,6 +353,44 @@ state_hash_lookup (size_t nitems, item_number *core)
   return entry;
 }
 
+
+/*------------------------------------------------------.
+| Mark S and all states reachable from S as reachable.  |
+`------------------------------------------------------*/
+
+static void
+state_mark_reachable_states (state *s)
+{
+  if (s->reachable)
+    return;
+  s->reachable = true;
+  for (int i = 0; i < s->transitions->num; ++i)
+    if (!TRANSITION_IS_DISABLED (s->transitions, i))
+      state_mark_reachable_states (s->transitions->states[i]);
+}
+
+void
+state_remove_unreachable_states (state_number old_to_new[])
+{
+  state_number nstates_reachable = 0;
+  state_mark_reachable_states (states[0]);
+  for (state_number i = 0; i < nstates; ++i)
+    {
+      if (states[i]->reachable)
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
+  nstates = nstates_reachable;
+}
+
 /* All the decorated states, indexed by the state number.  */
 state **states = NULL;
 
