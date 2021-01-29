@@ -204,7 +204,7 @@ solve_conflicts (void)
   lookaheadset = XCALLOC (unsigned, tokensetsize);
 
   for (i = 0; i < nstates; i++)
-    set_conflicts (state_table[i]);
+    set_conflicts (states[i]);
 }
 
 
@@ -327,8 +327,8 @@ conflicts_output (FILE *out)
     if (conflicts[i])
       {
 	fprintf (out, _("State %d contains "), i);
-	fputs (conflict_report (count_sr_conflicts (state_table[i]),
-				count_rr_conflicts (state_table[i])), out);
+	fputs (conflict_report (count_sr_conflicts (states[i]),
+				count_rr_conflicts (states[i])), out);
 	printed_sth = TRUE;
       }
   if (printed_sth)
@@ -357,8 +357,8 @@ conflicts_print (void)
   for (i = 0; i < nstates; i++)
     if (conflicts[i])
       {
-	src_total += count_sr_conflicts (state_table[i]);
-	rrc_total += count_rr_conflicts (state_table[i]);
+	src_total += count_sr_conflicts (states[i]);
+	rrc_total += count_rr_conflicts (states[i]);
       }
 
   src_ok = src_total == (expected_conflicts == -1 ? 0 : expected_conflicts);
