@@ -28,15 +28,12 @@
 #include "reader.h"
 #include "LR0.h"
 
-int any_conflicts = 0;
 errs **err_table = NULL;
 int expected_conflicts;
 static char *conflicts = NULL;
 
 static unsigned *shiftset = NULL;
 static unsigned *lookaheadset = NULL;
-static int src_count;
-static int rrc_count;
 
 
 static inline void
@@ -244,13 +241,8 @@ set_conflicts (int state)
       fp3 = lookaheadset;
 
       while (fp3 < fp4)
-	{
-	  if (*fp2++ & *fp3++)
-	    {
-	      conflicts[state] = 1;
-	      any_conflicts = 1;
-	    }
-	}
+	if (*fp2++ & *fp3++)
+	  conflicts[state] = 1;
 
       fp2 = fp1;
       fp3 = lookaheadset;
@@ -271,8 +263,6 @@ solve_conflicts (void)
 
   err_table = XCALLOC (errs *, nstates);
 
-  any_conflicts = 0;
-
   for (i = 0; i < nstates; i++)
     set_conflicts (i);
 }
@@ -282,7 +272,7 @@ solve_conflicts (void)
 | Count the number of shift/reduce conflicts.  |
 `---------------------------------------------*/
 
-static void
+static int
 count_sr_conflicts (int state)
 {
   int i;
@@ -294,11 +284,11 @@ count_sr_conflicts (int state)
   unsigned *fp3;
   int symbol;
 
-  src_count = 0;
+  int src_count = 0;
 
   shiftp = shift_table[state];
   if (!shiftp)
-    return;
+    return 0;
 
   for (i = 0; i < tokensetsize; i++)
     {
@@ -349,6 +339,8 @@ count_sr_conflicts (int state)
 	  fp2++;
 	}
     }
+
+  return src_count;
 }
 
 
@@ -356,33 +348,29 @@ count_sr_conflicts (int state)
 | Count the number of reduce/reduce conflicts.  |
 `----------------------------------------------*/
 
-static void
+static int
 count_rr_conflicts (int state)
 {
   int i;
-  int j;
-  int count;
   unsigned mask;
   unsigned *baseword;
-  unsigned *wordp;
-  int m;
-  int n;
 
-  rrc_count = 0;
+  int rrc_count = 0;
 
-  m = lookaheads[state];
-  n = lookaheads[state + 1];
+  int m = lookaheads[state];
+  int n = lookaheads[state + 1];
 
   if (n - m < 2)
-    return;
+    return 0;
 
   mask = 1;
   baseword = LA + m * tokensetsize;
   for (i = 0; i < ntokens; i++)
     {
-      wordp = baseword;
+      unsigned *wordp = baseword;
 
-      count = 0;
+      int count = 0;
+      int j;
       for (j = m; j < n; j++)
 	{
 	  if (mask & *wordp)
@@ -401,6 +389,8 @@ count_rr_conflicts (int state)
 	  baseword++;
 	}
     }
+
+  return rrc_count;
 }
 
 /*--------------------------------------------------------------.
@@ -450,58 +440,64 @@ conflict_report (int src_num, int rrc_num)
 }
 
 
-/*---------------------------------------------.
-| Compute and give a report on the conflicts.  |
-`---------------------------------------------*/
+/*-----------------------------------------------------------.
+| Output the detailed description of states with conflicts.  |
+`-----------------------------------------------------------*/
 
 void
-print_conflicts (FILE *out)
+conflicts_output (FILE *out)
 {
   int i;
-  int src_total;
-  int rrc_total;
+  for (i = 0; i < nstates; i++)
+    if (conflicts[i])
+      {
+	fprintf (out, _("State %d contains"), i);
+	fputs (conflict_report (count_sr_conflicts (i),
+				count_rr_conflicts (i)), out);
+      }
+}
 
-  src_total = 0;
-  rrc_total = 0;
 
-  /* Count the total number of conflicts, and if wanted, give a
-     detailed report in FOUTPUT.  */
-  for (i = 0; i < nstates; i++)
-    {
-      if (conflicts[i])
-	{
-	  count_sr_conflicts (i);
-	  count_rr_conflicts (i);
-	  src_total += src_count;
-	  rrc_total += rrc_count;
+/*------------------------------------------.
+| Reporting the total number of conflicts.  |
+`------------------------------------------*/
 
-	  if (verbose_flag)
-	    {
-	      fprintf (out, _("State %d contains"), i);
-	      fputs (conflict_report (src_count, rrc_count), out);
-	    }
-	}
-    }
+void
+conflicts_print (void)
+{
+  int i;
+
+  int src_total = 0;
+  int rrc_total = 0;
+
+  /* Conflicts by state.  */
+  for (i = 0; i < nstates; i++)
+    if (conflicts[i])
+      {
+	src_total += count_sr_conflicts (i);
+	rrc_total += count_rr_conflicts (i);
+      }
 
   /* Report the total number of conflicts on STDERR.  */
-  if (yacc_flag)
-    {
-      /* If invoked with `--yacc', use the output format specified by
-	 POSIX.  */
-      fprintf (stderr, _("conflicts: "));
-      if (src_total > 0)
-	fprintf (stderr, _(" %d shift/reduce"), src_total);
-      if (src_total > 0 && rrc_total > 0)
-	fprintf (stderr, ",");
-      if (rrc_total > 0)
-	fprintf (stderr, _(" %d reduce/reduce"), rrc_total);
-      putc ('\n', stderr);
-    }
-  else
-    {
-      fprintf (stderr, _("%s contains"), infile);
-      fputs (conflict_report (src_total, rrc_total), stderr);
-    }
+  if (src_total || rrc_total)
+    if (yacc_flag)
+      {
+	/* If invoked with `--yacc', use the output format specified by
+	   POSIX.  */
+	fprintf (stderr, _("conflicts: "));
+	if (src_total > 0)
+	  fprintf (stderr, _(" %d shift/reduce"), src_total);
+	if (src_total > 0 && rrc_total > 0)
+	  fprintf (stderr, ",");
+	if (rrc_total > 0)
+	  fprintf (stderr, _(" %d reduce/reduce"), rrc_total);
+	putc ('\n', stderr);
+      }
+    else
+      {
+	fprintf (stderr, _("%s contains"), infile);
+	fputs (conflict_report (src_total, rrc_total), stderr);
+      }
 }
 
 
