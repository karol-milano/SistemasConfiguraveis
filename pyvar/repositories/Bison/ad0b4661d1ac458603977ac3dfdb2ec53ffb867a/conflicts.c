@@ -467,15 +467,13 @@ count_sr_conflicts (void)
 
 
 
-/*----------------------------------------------------------------.
-| Count the number of reduce/reduce conflicts.  If ONE_PER_TOKEN, |
-| count one conflict for each token that has any reduce/reduce    |
-| conflicts.  Otherwise, count one conflict for each reduction    |
-| after the first for a given token.                              |
-`----------------------------------------------------------------*/
+/*-----------------------------------------------------------------.
+| Count the number of reduce/reduce conflicts.  Count one conflict |
+| for each reduction after the first for a given token.            |
+`-----------------------------------------------------------------*/
 
 static size_t
-count_state_rr_conflicts (state *s, bool one_per_token)
+count_state_rr_conflicts (state *s)
 {
   reductions *reds = s->reductions;
   size_t res = 0;
@@ -486,20 +484,20 @@ count_state_rr_conflicts (state *s, bool one_per_token)
       for (int j = 0; j < reds->num; ++j)
         count += bitset_test (reds->lookahead_tokens[j], i);
       if (count >= 2)
-        res += one_per_token ? 1 : count-1;
+        res += count-1;
     }
 
   return res;
 }
 
 static size_t
-count_rr_conflicts (bool one_per_token)
+count_rr_conflicts (void)
 {
   size_t res = 0;
   /* Conflicts by state.  */
   for (state_number i = 0; i < nstates; ++i)
     if (conflicts[i])
-      res += count_state_rr_conflicts (states[i], one_per_token);
+      res += count_state_rr_conflicts (states[i]);
   return res;
 }
 
@@ -591,7 +589,7 @@ conflicts_output (FILE *out)
       if (conflicts[i])
         {
           int src = count_state_sr_conflicts (s);
-          int rrc = count_state_rr_conflicts (s, true);
+          int rrc = count_state_rr_conflicts (s);
           fprintf (out, _("State %d "), i);
           if (src && rrc)
             fprintf (out,
@@ -608,17 +606,14 @@ conflicts_output (FILE *out)
     fputs ("\n\n", out);
 }
 
-/*--------------------------------------------------------.
-| Total the number of S/R and R/R conflicts.  Unlike the  |
-| code in conflicts_output, however, count EACH pair of   |
-| reductions for the same state and lookahead as one      |
-| conflict.                                               |
-`--------------------------------------------------------*/
+/*--------------------------------------------.
+| Total the number of S/R and R/R conflicts.  |
+`--------------------------------------------*/
 
 int
 conflicts_total_count (void)
 {
-  return count_sr_conflicts () + count_rr_conflicts (false);
+  return count_sr_conflicts () + count_rr_conflicts ();
 }
 
 /*------------------------------.
@@ -692,7 +687,7 @@ conflicts_print (void)
   }
 
   {
-    int total = count_rr_conflicts (true);
+    int total = count_rr_conflicts ();
     /* If %expect-rr is not used, but %expect is, then expect 0 rr.  */
     int expected =
       (expected_rr_conflicts == -1 && expected_sr_conflicts != -1)
