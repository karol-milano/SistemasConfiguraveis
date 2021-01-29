@@ -25,22 +25,16 @@
 #include "gram.h"
 #include "state.h"
 #include "lalr.h"
+#include "conflicts.h"
 
 extern char **tags;
 extern int fixed_outfiles;
 
-extern void initialize_conflicts PARAMS ((void));
-extern void conflict_log PARAMS ((void));
-extern void verbose_conflict_log PARAMS ((void));
-extern void print_reductions PARAMS ((int));
-extern void finalize_conflicts PARAMS ((void));
-
-char any_conflicts;
+int any_conflicts = 0;
 errs **err_table;
 int expected_conflicts;
 static char *conflicts;
 
-
 static unsigned *shiftset;
 static unsigned *lookaheadset;
 static int src_total;
@@ -275,7 +269,6 @@ void
 initialize_conflicts (void)
 {
   int i;
-/*  errs *sp; JF unused */
 
   conflicts = NEW2 (nstates, char);
   shiftset = NEW2 (tokensetsize, unsigned);
@@ -290,13 +283,6 @@ initialize_conflicts (void)
 }
 
 
-
-
-
-
-
-
-
 /*---------------------------------------------.
 | Count the number of shift/reduce conflicts.  |
 `---------------------------------------------*/
@@ -422,49 +408,29 @@ count_rr_conflicts (int state)
     }
 }
 
-/*------------------------------------.
-| Give a report about the conflicts.  |
-`------------------------------------*/
+/*----------------------------------------------------------.
+| Output to OUT a human readable report on shift/reduce and |
+| reduce/reduce conflict numbers (SRC_NUM, RRC_NUM).        |
+`----------------------------------------------------------*/
 
 static void
-total_conflicts (void)
+conflict_report (FILE *out, int src_num, int rrc_num)
 {
-  if (src_total == expected_conflicts && rrc_total == 0)
-    return;
+  if (src_num == 1)
+    fprintf (out, _(" 1 shift/reduce conflict"));
+  else if (src_num > 1)
+    fprintf (out, _(" %d shift/reduce conflicts"), src_num);
 
-  if (fixed_outfiles)
-    {
-      /* If invoked under the name `yacc', use the output format
-         specified by POSIX.  */
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
+  if (src_num > 0 && rrc_num > 0)
+    fprintf (out, _(" and"));
 
-      if (src_total == 1)
-	fprintf (stderr, _(" 1 shift/reduce conflict"));
-      else if (src_total > 1)
-	fprintf (stderr, _(" %d shift/reduce conflicts"), src_total);
+  if (rrc_num == 1)
+    fprintf (out, _(" 1 reduce/reduce conflict"));
+  else if (rrc_num > 1)
+    fprintf (out, _(" %d reduce/reduce conflicts"), rrc_num);
 
-      if (src_total > 0 && rrc_total > 0)
-	fprintf (stderr, _(" and"));
-
-      if (rrc_total == 1)
-	fprintf (stderr, _(" 1 reduce/reduce conflict"));
-      else if (rrc_total > 1)
-	fprintf (stderr, _(" %d reduce/reduce conflicts"), rrc_total);
-
-      putc ('.', stderr);
-      putc ('\n', stderr);
-    }
+  putc ('.', out);
+  putc ('\n', out);
 }
 
 
@@ -473,13 +439,15 @@ total_conflicts (void)
 `---------------------------------------------*/
 
 void
-conflict_log (void)
+print_conflicts (void)
 {
   int i;
 
   src_total = 0;
   rrc_total = 0;
 
+  /* Count the total number of conflicts, and if wanted, give a
+     detailed report in FOUTPUT.  */
   for (i = 0; i < nstates; i++)
     {
       if (conflicts[i])
@@ -488,58 +456,37 @@ conflict_log (void)
 	  count_rr_conflicts (i);
 	  src_total += src_count;
 	  rrc_total += rrc_count;
+
+	  if (verboseflag)
+	    {
+	      fprintf (foutput, _("State %d contains"), i);
+	      conflict_report (foutput, src_count, rrc_count);
+	    }
 	}
     }
 
-  total_conflicts ();
-}
-
-
-void
-verbose_conflict_log (void)
-{
-  int i;
-
-  src_total = 0;
-  rrc_total = 0;
-
-  for (i = 0; i < nstates; i++)
+  /* Report the total number of conflicts on STDERR.  */
+  if (fixed_outfiles)
     {
-      if (conflicts[i])
-	{
-	  count_sr_conflicts (i);
-	  count_rr_conflicts (i);
-	  src_total += src_count;
-	  rrc_total += rrc_count;
-
-	  fprintf (foutput, _("State %d contains"), i);
-
-	  if (src_count == 1)
-	    fprintf (foutput, _(" 1 shift/reduce conflict"));
-	  else if (src_count > 1)
-	    fprintf (foutput, _(" %d shift/reduce conflicts"), src_count);
-
-	  if (src_count > 0 && rrc_count > 0)
-	    fprintf (foutput, _(" and"));
-
-	  if (rrc_count == 1)
-	    fprintf (foutput, _(" 1 reduce/reduce conflict"));
-	  else if (rrc_count > 1)
-	    fprintf (foutput, _(" %d reduce/reduce conflicts"), rrc_count);
-
-	  putc ('.', foutput);
-	  putc ('\n', foutput);
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
+      fprintf (stderr, _("%s contains"), infile);
+      conflict_report (stderr, src_total, rrc_total);
     }
-
-  total_conflicts ();
 }
 
 
-
-
-
-
 void
 print_reductions (int state)
 {
