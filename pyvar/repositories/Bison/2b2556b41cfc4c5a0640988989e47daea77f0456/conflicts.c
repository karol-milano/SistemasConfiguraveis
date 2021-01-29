@@ -506,26 +506,25 @@ count_rr_conflicts (bool one_per_token)
 
 /*----------------------------------------------------------------------.
 | For a given rule, count the number of states for which it is involved |
-| in shift/reduce conflicts.                                               |
+| in shift/reduce conflicts.                                            |
 `----------------------------------------------------------------------*/
 
 static bool
 rule_has_state_sr_conflicts (rule *r, state *s)
 {
-  int i;
-  int j;
   transitions *trans = s->transitions;
   reductions *reds = s->reductions;
 
-  for (i = 0; i < reds->num; i++)
+  for (int i = 0; i < reds->num; ++i)
     if (reds->rules[i] == r)
-      break;
-  if (i >= reds->num)
-    return false;
-
-  FOR_EACH_SHIFT (trans, j)
-    if (bitset_test (reds->lookahead_tokens[i], TRANSITION_SYMBOL (trans, j)))
-      return true;
+      {
+        bitset lookaheads = reds->lookahead_tokens[i];
+        int j;
+        FOR_EACH_SHIFT (trans, j)
+          if (bitset_test (lookaheads, TRANSITION_SYMBOL (trans, j)))
+            return true;
+        break;
+      }
 
   return false;
 }
@@ -533,11 +532,8 @@ rule_has_state_sr_conflicts (rule *r, state *s)
 static size_t
 count_rule_sr_conflicts (rule *r)
 {
-  state_number i;
-  size_t res;
-
-  res = 0;
-  for (i = 0; i < nstates; i++)
+  size_t res = 0;
+  for (state_number i = 0; i < nstates; ++i)
     if (conflicts[i] && rule_has_state_sr_conflicts (r, states[i]))
       res++;
   return res;
@@ -551,22 +547,18 @@ count_rule_sr_conflicts (rule *r)
 static bool
 rule_has_state_rr_conflicts (rule *r, state *s)
 {
-  int i;
   reductions *reds = s->reductions;
-  size_t res;
-  bitset lookaheads;
-  
-  for (i = 0; i < reds->num; i++)
-    if (reds->rules[i] == r)
-      break;
-  if (i >= reds->num)
-    return 0;
-  lookaheads = reds->lookahead_tokens[i];
 
-  for (i = 0; i < reds->num; i++)
-    if (reds->rules[i] != r &&
-        !bitset_disjoint_p (lookaheads, reds->lookahead_tokens[i]))
-      return true;
+  for (int i = 0; i < reds->num; ++i)
+    if (reds->rules[i] == r)
+      {
+        bitset lookaheads = reds->lookahead_tokens[i];
+        for (int j = 0; j < reds->num; ++j)
+          if (reds->rules[j] != r &&
+              !bitset_disjoint_p (lookaheads, reds->lookahead_tokens[j]))
+            return true;
+        break;
+      }
 
   return false;
 }
@@ -574,13 +566,10 @@ rule_has_state_rr_conflicts (rule *r, state *s)
 static size_t
 count_rule_rr_conflicts (rule *r)
 {
-  state_number i;
-  size_t res;
-
-  res = 0;
-  for (i = 0; i < nstates; i++)
+  size_t res = 0;
+  for (state_number i = 0; i < nstates; ++i)
     if (conflicts[i] && rule_has_state_rr_conflicts (r, states[i]))
-	res++;
+      res++;
   return res;
 }
 
@@ -635,25 +624,25 @@ conflicts_total_count (void)
 static void
 rule_conflicts_print (void)
 {
-  rule_number i;
-
-  for (i = 0; i < nrules; i += 1)
+  for (rule_number i = 0; i < nrules; i += 1)
     {
       rule *r = &rules[i];
       int expected_sr = r->expected_sr_conflicts;
       int expected_rr = r->expected_rr_conflicts;
 
-      if (expected_sr != -1 || expected_rr != -1) 
+      if (expected_sr != -1 || expected_rr != -1)
         {
           int sr = count_rule_sr_conflicts (r);
-          int rr = count_rule_rr_conflicts (r);
           if (sr != expected_sr && (sr != 0 || expected_sr != -1))
-            complain (&r->location, complaint, _("\
-shift/reduce conflicts for rule %d: %d found, %d expected"),
+            complain (&r->location, complaint,
+                      _("shift/reduce conflicts for rule %d:"
+                        " %d found, %d expected"),
                       r->user_number, sr, expected_sr);
+          int rr = count_rule_rr_conflicts (r);
           if (rr != expected_rr && (rr != 0 || expected_rr != -1))
-            complain (&r->location, complaint, _("\
-reduce/reduce conflicts for rule %d: %d found, %d expected"),
+            complain (&r->location, complaint,
+                      _("reduce/reduce conflicts for rule %d:"
+                        " %d found, %d expected"),
                       r->user_number, rr, expected_rr);
         }
     }
