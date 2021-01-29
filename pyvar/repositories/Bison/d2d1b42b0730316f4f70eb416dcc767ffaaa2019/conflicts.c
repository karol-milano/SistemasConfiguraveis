@@ -419,6 +419,7 @@ conflict_report (int src_num, int rrc_num)
 void
 conflicts_output (FILE *out)
 {
+  bool printed_sth = FALSE;
   int i;
   for (i = 0; i < nstates; i++)
     if (conflicts[i])
@@ -426,7 +427,10 @@ conflicts_output (FILE *out)
 	fprintf (out, _("State %d contains "), i);
 	fputs (conflict_report (count_sr_conflicts (i),
 				count_rr_conflicts (i)), out);
+	printed_sth = TRUE;
       }
+  if (printed_sth)
+    fputs ("\n\n", out);
 }
 
 
