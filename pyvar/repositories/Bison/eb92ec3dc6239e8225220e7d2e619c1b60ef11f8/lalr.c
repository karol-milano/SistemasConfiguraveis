@@ -93,13 +93,13 @@ set_goto_map (void)
   ngotos = 0;
   for (state_number s = 0; s < nstates; ++s)
     {
-      transitions *sp = states[s]->transitions;
-      for (int i = sp->num - 1; 0 <= i && TRANSITION_IS_GOTO (sp, i); --i)
+      transitions *trans = states[s]->transitions;
+      for (int i = trans->num - 1; 0 <= i && TRANSITION_IS_GOTO (trans, i); --i)
         {
           ngotos++;
           /* Abort if (ngotos + 1) would overflow.  */
           aver (ngotos != GOTO_NUMBER_MAXIMUM);
-          goto_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
+          goto_map[TRANSITION_SYMBOL (trans, i) - ntokens]++;
         }
     }
 
@@ -124,12 +124,12 @@ set_goto_map (void)
 
   for (state_number s = 0; s < nstates; ++s)
     {
-      const transitions *sp = states[s]->transitions;
-      for (int i = sp->num - 1; 0 <= i && TRANSITION_IS_GOTO (sp, i); --i)
+      const transitions *trans = states[s]->transitions;
+      for (int i = trans->num - 1; 0 <= i && TRANSITION_IS_GOTO (trans, i); --i)
         {
-          goto_number k = temp_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
+          goto_number k = temp_map[TRANSITION_SYMBOL (trans, i) - ntokens]++;
           from_state[k] = s;
-          to_state[k] = sp->states[i]->number;
+          to_state[k] = trans->states[i]->number;
         }
     }
 
@@ -196,17 +196,20 @@ initialize_goto_follows (void)
   for (goto_number i = 0; i < ngotos; ++i)
     {
       state_number dst = to_state[i];
-      const transitions *sp = states[dst]->transitions;
+      const transitions *trans = states[dst]->transitions;
 
       int j;
-      FOR_EACH_SHIFT (sp, j)
-        bitset_set (goto_follows[i], TRANSITION_SYMBOL (sp, j));
+      FOR_EACH_SHIFT (trans, j)
+        bitset_set (goto_follows[i], TRANSITION_SYMBOL (trans, j));
 
-      for (; j < sp->num; ++j)
+      for (; j < trans->num; ++j)
         {
-          symbol_number sym = TRANSITION_SYMBOL (sp, j);
+          symbol_number sym = TRANSITION_SYMBOL (trans, j);
           if (nullable[sym - ntokens])
-            edge[nedges++] = map_goto (dst, sym);
+            {
+              assert (nedges < ngotos + 1);
+              edge[nedges++] = map_goto (dst, sym);
+            }
         }
 
       if (nedges == 0)
@@ -352,15 +355,15 @@ compute_lookahead_tokens (void)
 static int
 state_lookahead_tokens_count (state *s, bool default_reduction_only_for_accept)
 {
-  const reductions *rp = s->reductions;
-  const transitions *sp = s->transitions;
+  const reductions *reds = s->reductions;
+  const transitions *trans = s->transitions;
 
   /* Transitions are only disabled during conflict resolution, and that
      hasn't happened yet, so there should be no need to check that
      transition 0 hasn't been disabled before checking if it is a shift.
      However, this check was performed at one time, so we leave it as an
      aver.  */
-  aver (sp->num == 0 || !TRANSITION_IS_DISABLED (sp, 0));
+  aver (trans->num == 0 || !TRANSITION_IS_DISABLED (trans, 0));
 
   /* We need a lookahead either to distinguish different reductions
      (i.e., there are two or more), or to distinguish a reduction from a
@@ -371,12 +374,12 @@ state_lookahead_tokens_count (state *s, bool default_reduction_only_for_accept)
      should be read) if the user has otherwise disabled default
      reductions.  */
   s->consistent =
-    !(rp->num > 1
-      || (rp->num == 1 && sp->num && TRANSITION_IS_SHIFT (sp, 0))
-      || (rp->num == 1 && rp->rules[0]->number != 0
+    !(reds->num > 1
+      || (reds->num == 1 && trans->num && TRANSITION_IS_SHIFT (trans, 0))
+      || (reds->num == 1 && reds->rules[0]->number != 0
           && default_reduction_only_for_accept));
 
-  return s->consistent ? 0 : rp->num;
+  return s->consistent ? 0 : reds->num;
 }
 
 
