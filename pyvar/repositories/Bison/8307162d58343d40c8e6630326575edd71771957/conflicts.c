@@ -450,7 +450,7 @@ conflict_report_yacc (int src_num, int rrc_num)
 void
 conflicts_output (FILE *out)
 {
-  bool printed_sth = FALSE;
+  bool printed_sth = false;
   state_number_t i;
   for (i = 0; i < nstates; i++)
     {
@@ -460,8 +460,8 @@ conflicts_output (FILE *out)
 	  fprintf (out, _("State %d contains "), i);
 	  fprintf (out, "%s.\n",
 		   conflict_report (count_sr_conflicts (s),
-				    count_rr_conflicts (s, TRUE)));
-	  printed_sth = TRUE;
+				    count_rr_conflicts (s, true)));
+	  printed_sth = true;
 	}
     }
   if (printed_sth)
@@ -487,7 +487,7 @@ conflicts_total_count (void)
     if (conflicts[i])
       {
 	count += count_sr_conflicts (states[i]);
-	count += count_rr_conflicts (states[i], FALSE);
+	count += count_rr_conflicts (states[i], false);
       }
   return count;
 }
@@ -516,7 +516,7 @@ conflicts_print (void)
       if (conflicts[i])
 	{
 	  src_total += count_sr_conflicts (states[i]);
-	  rrc_total += count_rr_conflicts (states[i], TRUE);
+	  rrc_total += count_rr_conflicts (states[i], true);
 	}
   }
 
