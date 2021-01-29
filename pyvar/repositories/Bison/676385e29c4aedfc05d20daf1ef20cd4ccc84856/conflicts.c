@@ -331,12 +331,15 @@ count_sr_conflicts (state_t *state)
 }
 
 
-/*----------------------------------------------.
-| Count the number of reduce/reduce conflicts.  |
-`----------------------------------------------*/
+/*----------------------------------------------------------------.
+| Count the number of reduce/reduce conflicts.  If ONE_PER_TOKEN, |
+| count one conflict for each token that has any reduce/reduce    |
+| conflicts.  Otherwise, count one conflict for each pair of      |
+| conflicting reductions.                                         |
++`----------------------------------------------------------------*/
 
 static int
-count_rr_conflicts (state_t *state)
+count_rr_conflicts (state_t *state, int one_per_token)
 {
   int i;
   int rrc_count = 0;
@@ -353,7 +356,7 @@ count_rr_conflicts (state_t *state)
 	  count++;
 
       if (count >= 2)
-	rrc_count++;
+	rrc_count += one_per_token ? 1 : count-1;
     }
 
   return rrc_count;
@@ -412,13 +415,37 @@ conflicts_output (FILE *out)
       {
 	fprintf (out, _("State %d contains "), i);
 	fputs (conflict_report (count_sr_conflicts (states[i]),
-				count_rr_conflicts (states[i])), out);
+				count_rr_conflicts (states[i], TRUE)), out);
 	printed_sth = TRUE;
       }
   if (printed_sth)
     fputs ("\n\n", out);
 }
 
+/*--------------------------------------------------------.
+| Total the number of S/R and R/R conflicts.  Unlike the  |
+| code in conflicts_output, however, count EACH pair of   |
+| reductions for the same state and lookahead as one      |
+| conflict.						  |
+`--------------------------------------------------------*/
+
+int
+conflicts_total_count (void)
+{
+  int i;
+  int count;
+
+  /* Conflicts by state.  */
+  count = 0;
+  for (i = 0; i < nstates; i++)
+    if (conflicts[i])
+      {
+	count += count_sr_conflicts (states[i]);
+	count += count_rr_conflicts (states[i], FALSE);
+      }
+  return count;
+}
+ 
 
 /*------------------------------------------.
 | Reporting the total number of conflicts.  |
@@ -442,7 +469,7 @@ conflicts_print (void)
     if (conflicts[i])
       {
 	src_total += count_sr_conflicts (states[i]);
-	rrc_total += count_rr_conflicts (states[i]);
+	rrc_total += count_rr_conflicts (states[i], TRUE);
       }
 
   src_ok = src_total == (expected_conflicts == -1 ? 0 : expected_conflicts);
