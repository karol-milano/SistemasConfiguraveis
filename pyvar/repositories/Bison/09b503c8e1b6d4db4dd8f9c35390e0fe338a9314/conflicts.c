@@ -474,24 +474,26 @@ conflicts_print (void)
 
   /* Report the total number of conflicts on STDERR.  */
   if (src_total || rrc_total)
-    if (yacc_flag)
-      {
-	/* If invoked with `--yacc', use the output format specified by
-	   POSIX.  */
-	fprintf (stderr, _("conflicts: "));
-	if (src_total > 0)
-	  fprintf (stderr, _(" %d shift/reduce"), src_total);
-	if (src_total > 0 && rrc_total > 0)
-	  fprintf (stderr, ",");
-	if (rrc_total > 0)
-	  fprintf (stderr, _(" %d reduce/reduce"), rrc_total);
-	putc ('\n', stderr);
-      }
-    else
-      {
-	fprintf (stderr, _("%s contains "), infile);
-	fputs (conflict_report (src_total, rrc_total), stderr);
-      }
+    {
+      if (yacc_flag)
+	{
+	  /* If invoked with `--yacc', use the output format specified by
+	     POSIX.  */
+	  fprintf (stderr, _("conflicts: "));
+	  if (src_total > 0)
+	    fprintf (stderr, _(" %d shift/reduce"), src_total);
+	  if (src_total > 0 && rrc_total > 0)
+	    fprintf (stderr, ",");
+	  if (rrc_total > 0)
+	    fprintf (stderr, _(" %d reduce/reduce"), rrc_total);
+	  putc ('\n', stderr);
+	}
+      else
+	{
+	  fprintf (stderr, _("%s contains "), infile);
+	  fputs (conflict_report (src_total, rrc_total), stderr);
+	}
+    }
 
   if (expected_conflicts != -1
       && src_total != expected_conflicts)
