@@ -504,14 +504,15 @@ count_rr_conflicts (bool one_per_token)
 }
 
 
-/*----------------------------------------------------------------------.
-| For a given rule, count the number of states for which it is involved |
-| in shift/reduce conflicts.                                            |
-`----------------------------------------------------------------------*/
+/*------------------------------------------------------------------.
+| For a given rule, the number of shift/reduce conflicts in a given |
+| state.                                                            |
+`------------------------------------------------------------------*/
 
-static bool
-rule_has_state_sr_conflicts (rule *r, state *s)
+static size_t
+count_rule_state_sr_conflicts (rule *r, state *s)
 {
+  size_t res = 0;
   transitions *trans = s->transitions;
   reductions *reds = s->reductions;
 
@@ -521,21 +522,24 @@ rule_has_state_sr_conflicts (rule *r, state *s)
         bitset lookaheads = reds->lookahead_tokens[i];
         int j;
         FOR_EACH_SHIFT (trans, j)
-          if (bitset_test (lookaheads, TRANSITION_SYMBOL (trans, j)))
-            return true;
-        break;
+          res += bitset_test (lookaheads, TRANSITION_SYMBOL (trans, j));
       }
 
-  return false;
+  return res;
 }
 
+/*----------------------------------------------------------------------.
+| For a given rule, count the number of states for which it is involved |
+| in shift/reduce conflicts.                                            |
+`----------------------------------------------------------------------*/
+
 static size_t
 count_rule_sr_conflicts (rule *r)
 {
   size_t res = 0;
   for (state_number i = 0; i < nstates; ++i)
-    if (conflicts[i] && rule_has_state_sr_conflicts (r, states[i]))
-      res++;
+    if (conflicts[i])
+      res += count_rule_state_sr_conflicts (r, states[i]);
   return res;
 }
 
