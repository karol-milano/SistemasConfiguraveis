@@ -439,6 +439,11 @@ conflicts_print (void)
 {
   int i;
 
+  /* Is the number of SR conflicts OK?  Either EXPECTED_CONFLICTS is
+     not set, and then we want 0 SR, or else it is specified, in which
+     case we want equality.  */
+  int src_ok = 0;
+
   int src_total = 0;
   int rrc_total = 0;
 
@@ -450,31 +455,34 @@ conflicts_print (void)
 	rrc_total += count_rr_conflicts (i);
       }
 
+  src_ok = src_total == (expected_conflicts == -1 ? 0 : expected_conflicts);
+
+  /* If there are no RR conflicts, and as many SR conflicts as
+     expected, then there is nothing to report.  */
+  if (!rrc_total && src_ok)
+    return;
+
   /* Report the total number of conflicts on STDERR.  */
-  if (src_total || rrc_total)
+  if (yacc_flag)
     {
-      if (yacc_flag)
-	{
-	  /* If invoked with `--yacc', use the output format specified by
-	     POSIX.  */
-	  fprintf (stderr, _("conflicts: "));
-	  if (src_total > 0)
-	    fprintf (stderr, _(" %d shift/reduce"), src_total);
-	  if (src_total > 0 && rrc_total > 0)
-	    fprintf (stderr, ",");
-	  if (rrc_total > 0)
-	    fprintf (stderr, _(" %d reduce/reduce"), rrc_total);
-	  putc ('\n', stderr);
-	}
-      else
-	{
-	  fprintf (stderr, _("%s contains "), infile);
-	  fputs (conflict_report (src_total, rrc_total), stderr);
-	}
+      /* If invoked with `--yacc', use the output format specified by
+	 POSIX.  */
+      fprintf (stderr, _("conflicts: "));
+      if (src_total > 0)
+	fprintf (stderr, _(" %d shift/reduce"), src_total);
+      if (src_total > 0 && rrc_total > 0)
+	fprintf (stderr, ",");
+      if (rrc_total > 0)
+	fprintf (stderr, _(" %d reduce/reduce"), rrc_total);
+      putc ('\n', stderr);
+    }
+  else
+    {
+      fprintf (stderr, _("%s contains "), infile);
+      fputs (conflict_report (src_total, rrc_total), stderr);
     }
 
-  if (expected_conflicts != -1
-      && src_total != expected_conflicts)
+  if (expected_conflicts != -1 && !src_ok)
     {
       complain_message_count++;
       fprintf (stderr, ngettext ("expected %d shift/reduce conflict\n",
