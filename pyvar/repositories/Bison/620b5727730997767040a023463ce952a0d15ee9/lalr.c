@@ -328,7 +328,7 @@ compute_lookahead_tokens (void)
 `----------------------------------------------------*/
 
 static int
-state_lookahead_tokens_count (state *s, bool default_rule_only_for_accept)
+state_lookahead_tokens_count (state *s, bool default_reduction_only_for_accept)
 {
   int n_lookahead_tokens = 0;
   reductions *rp = s->reductions;
@@ -344,14 +344,14 @@ state_lookahead_tokens_count (state *s, bool default_rule_only_for_accept)
   /* We need a lookahead either to distinguish different reductions
      (i.e., there are two or more), or to distinguish a reduction from a
      shift.  Otherwise, it is straightforward, and the state is
-     `consistent'.  However, for states that have any rules, treat only
-     the accepting state as consistent (since there is never a lookahead
-     token that makes sense there, and so no lookahead token should be
-     read) if the user has otherwise disabled default rules.  */
+     `consistent'.  However, treat only the accepting state as
+     consistent (because there is never a lookahead token that makes
+     sense there, and so no lookahead token should be read) if the user
+     has otherwise disabled default reductions.  */
   if (rp->num > 1
       || (rp->num == 1 && sp->num && TRANSITION_IS_SHIFT (sp, 0))
       || (rp->num == 1 && rp->rules[0]->number != 0
-          && default_rule_only_for_accept))
+          && default_reduction_only_for_accept))
     n_lookahead_tokens += rp->num;
   else
     s->consistent = 1;
@@ -369,18 +369,21 @@ initialize_LA (void)
 {
   state_number i;
   bitsetv pLA;
-  bool default_rule_only_for_accept;
+  bool default_reduction_only_for_accept;
   {
-    char *default_rules = muscle_percent_define_get ("lr.default_rules");
-    default_rule_only_for_accept = 0 == strcmp (default_rules, "accepting");
-    free (default_rules);
+    char *default_reductions =
+      muscle_percent_define_get ("lr.default_reductions");
+    default_reduction_only_for_accept =
+      0 == strcmp (default_reductions, "accepting");
+    free (default_reductions);
   }
 
   /* Compute the total number of reductions requiring a lookahead.  */
   nLA = 0;
   for (i = 0; i < nstates; i++)
     nLA +=
-      state_lookahead_tokens_count (states[i], default_rule_only_for_accept);
+      state_lookahead_tokens_count (states[i],
+                                    default_reduction_only_for_accept);
   /* Avoid having to special case 0.  */
   if (!nLA)
     nLA = 1;
@@ -392,7 +395,8 @@ initialize_LA (void)
   for (i = 0; i < nstates; i++)
     {
       int count =
-        state_lookahead_tokens_count (states[i], default_rule_only_for_accept);
+        state_lookahead_tokens_count (states[i],
+                                      default_reduction_only_for_accept);
       if (count)
 	{
 	  states[i]->reductions->lookahead_tokens = pLA;
