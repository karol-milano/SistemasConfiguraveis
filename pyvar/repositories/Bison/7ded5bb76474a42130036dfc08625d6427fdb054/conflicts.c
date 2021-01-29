@@ -483,7 +483,7 @@ count_state_rr_conflicts (state *s)
       int count = 0;
       for (int j = 0; j < reds->num; ++j)
         count += bitset_test (reds->lookahead_tokens[j], i);
-      if (count >= 2)
+      if (2 <= count)
         res += count-1;
     }
 
@@ -546,23 +546,25 @@ count_rule_sr_conflicts (rule *r)
 | involved in reduce/reduce conflicts.                             |
 `-----------------------------------------------------------------*/
 
-static bool
-rule_has_state_rr_conflicts (rule *r, state *s)
+static size_t
+count_rule_state_rr_conflicts (rule *r, state *s)
 {
-  reductions *reds = s->reductions;
+  size_t res = 0;
+  const reductions *reds = s->reductions;
+  bitset lookaheads = bitset_create (ntokens, BITSET_FIXED);
 
   for (int i = 0; i < reds->num; ++i)
     if (reds->rules[i] == r)
-      {
-        bitset lookaheads = reds->lookahead_tokens[i];
-        for (int j = 0; j < reds->num; ++j)
-          if (reds->rules[j] != r &&
-              !bitset_disjoint_p (lookaheads, reds->lookahead_tokens[j]))
-            return true;
-        break;
-      }
-
-  return false;
+      for (int j = 0; j < reds->num; ++j)
+        if (reds->rules[j] != r)
+          {
+            bitset_and (lookaheads,
+                        reds->lookahead_tokens[i],
+                        reds->lookahead_tokens[j]);
+            res += bitset_count (lookaheads);
+          }
+  bitset_free (lookaheads);
+  return res;
 }
 
 static size_t
@@ -570,8 +572,7 @@ count_rule_rr_conflicts (rule *r)
 {
   size_t res = 0;
   for (state_number i = 0; i < nstates; ++i)
-    if (conflicts[i] && rule_has_state_rr_conflicts (r, states[i]))
-      res++;
+    res += count_rule_state_rr_conflicts (r, states[i]);
   return res;
 }
 
