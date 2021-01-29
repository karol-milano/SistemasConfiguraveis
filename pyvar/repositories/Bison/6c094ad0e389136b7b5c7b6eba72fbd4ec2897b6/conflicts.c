@@ -422,11 +422,10 @@ conflicts_update_state_numbers (state_number old_to_new[],
 | Count the number of shift/reduce conflicts.  |
 `---------------------------------------------*/
 
-static int
-count_sr_conflicts (state *s)
+static size_t
+count_state_sr_conflicts (state *s)
 {
   int i;
-  int src_count = 0;
   transitions *trans = s->transitions;
   reductions *reds = s->reductions;
 
@@ -444,56 +443,82 @@ count_sr_conflicts (state *s)
 
   bitset_and (lookahead_set, lookahead_set, shift_set);
 
-  src_count = bitset_count (lookahead_set);
+  return bitset_count (lookahead_set);
+}
 
-  return src_count;
+/*---------------------------------------------.
+| The total number of shift/reduce conflicts.  |
+`---------------------------------------------*/
+
+static size_t
+count_sr_conflicts (void)
+{
+  size_t res = 0;
+  state_number i;
+
+  /* Conflicts by state.  */
+  for (i = 0; i < nstates; i++)
+    if (conflicts[i])
+      res += count_state_sr_conflicts (states[i]);
+  return res;
 }
 
 
+
 /*----------------------------------------------------------------.
 | Count the number of reduce/reduce conflicts.  If ONE_PER_TOKEN, |
 | count one conflict for each token that has any reduce/reduce    |
 | conflicts.  Otherwise, count one conflict for each pair of      |
 | conflicting reductions.                                         |
-+`----------------------------------------------------------------*/
+`----------------------------------------------------------------*/
 
-static int
-count_rr_conflicts (state *s, bool one_per_token)
+static size_t
+count_state_rr_conflicts (state *s, bool one_per_token)
 {
   int i;
   reductions *reds = s->reductions;
-  int rrc_count = 0;
+  size_t res = 0;
 
   for (i = 0; i < ntokens; i++)
     {
       int count = 0;
       int j;
       for (j = 0; j < reds->num; ++j)
-        if (bitset_test (reds->lookahead_tokens[j], i))
-          count++;
-
+        count += bitset_test (reds->lookahead_tokens[j], i);
       if (count >= 2)
-        rrc_count += one_per_token ? 1 : count-1;
+        res += one_per_token ? 1 : count-1;
     }
 
-  return rrc_count;
+  return res;
 }
 
+static size_t
+count_rr_conflicts (bool one_per_token)
+{
+  size_t res = 0;
+  state_number i;
+
+  /* Conflicts by state.  */
+  for (i = 0; i < nstates; i++)
+    if (conflicts[i])
+      res += count_state_rr_conflicts (states[i], one_per_token);
+  return res;
+}
 
 /*--------------------------------------------------------.
 | Report the number of conflicts, using the Yacc format.  |
 `--------------------------------------------------------*/
 
 static void
-conflict_report (FILE *out, int src_num, int rrc_num)
+conflict_report (FILE *out, size_t src_num, size_t rrc_num)
 {
   if (src_num && rrc_num)
-    fprintf (out, _("conflicts: %d shift/reduce, %d reduce/reduce\n"),
+    fprintf (out, _("conflicts: %zd shift/reduce, %zd reduce/reduce\n"),
              src_num, rrc_num);
   else if (src_num)
-    fprintf (out, _("conflicts: %d shift/reduce\n"), src_num);
+    fprintf (out, _("conflicts: %zd shift/reduce\n"), src_num);
   else if (rrc_num)
-    fprintf (out, _("conflicts: %d reduce/reduce\n"), rrc_num);
+    fprintf (out, _("conflicts: %zd reduce/reduce\n"), rrc_num);
 }
 
 
@@ -512,8 +537,9 @@ conflicts_output (FILE *out)
       if (conflicts[i])
         {
           fprintf (out, _("State %d "), i);
-          conflict_report (out, count_sr_conflicts (s),
-                           count_rr_conflicts (s, true));
+          conflict_report (out,
+                           count_state_sr_conflicts (s),
+                           count_state_rr_conflicts (s, true));
           printed_sth = true;
         }
     }
@@ -531,18 +557,7 @@ conflicts_output (FILE *out)
 int
 conflicts_total_count (void)
 {
-  state_number i;
-  int count;
-
-  /* Conflicts by state.  */
-  count = 0;
-  for (i = 0; i < nstates; i++)
-    if (conflicts[i])
-      {
-        count += count_sr_conflicts (states[i]);
-        count += count_rr_conflicts (states[i], false);
-      }
-  return count;
+  return count_sr_conflicts () + count_rr_conflicts (false);
 }
 
 
@@ -559,22 +574,11 @@ conflicts_print (void)
   bool src_ok;
   bool rrc_ok;
 
-  int src_total = 0;
-  int rrc_total = 0;
   int src_expected;
   int rrc_expected;
 
-  /* Conflicts by state.  */
-  {
-    state_number i;
-
-    for (i = 0; i < nstates; i++)
-      if (conflicts[i])
-        {
-          src_total += count_sr_conflicts (states[i]);
-          rrc_total += count_rr_conflicts (states[i], true);
-        }
-  }
+  int src_total = count_sr_conflicts ();
+  int rrc_total = count_rr_conflicts (true);
 
   if (! glr_parser && expected_rr_conflicts != -1)
     {
