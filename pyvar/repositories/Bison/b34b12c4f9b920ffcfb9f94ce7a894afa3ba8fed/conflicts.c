@@ -470,8 +470,8 @@ count_sr_conflicts (void)
 /*----------------------------------------------------------------.
 | Count the number of reduce/reduce conflicts.  If ONE_PER_TOKEN, |
 | count one conflict for each token that has any reduce/reduce    |
-| conflicts.  Otherwise, count one conflict for each pair of      |
-| conflicting reductions.                                         |
+| conflicts.  Otherwise, count one conflict for each reduction    |
+| after the first for a given token.                              |
 `----------------------------------------------------------------*/
 
 static size_t
@@ -504,6 +504,86 @@ count_rr_conflicts (bool one_per_token)
 }
 
 
+/*----------------------------------------------------------------------.
+| For a given rule, count the number of states for which it is involved |
+| in shift/reduce conflicts.                                               |
+`----------------------------------------------------------------------*/
+
+static bool
+rule_has_state_sr_conflicts (rule *r, state *s)
+{
+  int i;
+  int j;
+  transitions *trans = s->transitions;
+  reductions *reds = s->reductions;
+
+  for (i = 0; i < reds->num; i++)
+    if (reds->rules[i] == r)
+      break;
+  if (i >= reds->num)
+    return false;
+
+  FOR_EACH_SHIFT (trans, j)
+    if (bitset_test (reds->lookahead_tokens[i], TRANSITION_SYMBOL (trans, j)))
+      return true;
+
+  return false;
+}
+
+static size_t
+count_rule_sr_conflicts (rule *r)
+{
+  state_number i;
+  size_t res;
+
+  res = 0;
+  for (i = 0; i < nstates; i++)
+    if (conflicts[i] && rule_has_state_sr_conflicts (r, states[i]))
+      res++;
+  return res;
+}
+
+/*-----------------------------------------------------------------.
+| For a given rule, count the number of states in which it is      |
+| involved in reduce/reduce conflicts.                             |
+`-----------------------------------------------------------------*/
+
+static bool
+rule_has_state_rr_conflicts (rule *r, state *s)
+{
+  int i;
+  reductions *reds = s->reductions;
+  size_t res;
+  bitset lookaheads;
+  
+  for (i = 0; i < reds->num; i++)
+    if (reds->rules[i] == r)
+      break;
+  if (i >= reds->num)
+    return 0;
+  lookaheads = reds->lookahead_tokens[i];
+
+  for (i = 0; i < reds->num; i++)
+    if (reds->rules[i] != r &&
+        !bitset_disjoint_p (lookaheads, reds->lookahead_tokens[i]))
+      return true;
+
+  return false;
+}
+
+static size_t
+count_rule_rr_conflicts (rule *r)
+{
+  state_number i;
+  size_t res;
+
+  res = 0;
+  for (i = 0; i < nstates; i++)
+    if (conflicts[i] && rule_has_state_rr_conflicts (r, states[i]))
+	res++;
+  return res;
+}
+
 /*-----------------------------------------------------------.
 | Output the detailed description of states with conflicts.  |
 `-----------------------------------------------------------*/
@@ -548,14 +628,46 @@ conflicts_total_count (void)
   return count_sr_conflicts () + count_rr_conflicts (false);
 }
 
+/*------------------------------.
+| Reporting per-rule conflicts. |
+`------------------------------*/
 
-/*------------------------------------------.
-| Reporting the total number of conflicts.  |
-`------------------------------------------*/
+static void
+rule_conflicts_print (void)
+{
+  rule_number i;
+
+  for (i = 0; i < nrules; i += 1)
+    {
+      rule *r = &rules[i];
+      int expected_sr = r->expected_sr_conflicts;
+      int expected_rr = r->expected_rr_conflicts;
+
+      if (expected_sr != -1 || expected_rr != -1) 
+        {
+          int sr = count_rule_sr_conflicts (r);
+          int rr = count_rule_rr_conflicts (r);
+          if (sr != expected_sr && (sr != 0 || expected_sr != -1))
+            complain (&r->location, complaint, _("\
+shift/reduce conflicts for rule %d: %d found, %d expected"),
+                      r->user_number, sr, expected_sr);
+          if (rr != expected_rr && (rr != 0 || expected_rr != -1))
+            complain (&r->location, complaint, _("\
+reduce/reduce conflicts for rule %d: %d found, %d expected"),
+                      r->user_number, rr, expected_rr);
+        }
+    }
+}
+
+/*---------------------------------.
+| Reporting numbers of conflicts.  |
+`---------------------------------*/
 
 void
 conflicts_print (void)
 {
+  rule_conflicts_print ();
+
   if (! glr_parser && expected_rr_conflicts != -1)
     {
       complain (NULL, Wother, _("%%expect-rr applies only to GLR parsers"));
@@ -609,7 +721,6 @@ conflicts_print (void)
   }
 }
 
-
 void
 conflicts_free (void)
 {
