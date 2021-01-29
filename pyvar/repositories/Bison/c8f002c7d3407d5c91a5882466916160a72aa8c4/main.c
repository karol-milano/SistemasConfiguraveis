@@ -108,6 +108,14 @@ main (int argc, char *argv[])
   conflicts_print ();
   timevar_pop (TV_CONFLICTS);
 
+  /* Compute the parser tables.  */
+  timevar_push (TV_ACTIONS);
+  tables_generate ();
+  timevar_pop (TV_ACTIONS);
+
+  grammar_rules_never_reduced_report
+    (_("rule never reduced because of conflicts"));
+
   /* Output file names. */
   compute_output_file_names ();
 
@@ -119,11 +127,6 @@ main (int argc, char *argv[])
       timevar_pop (TV_REPORT);
     }
 
-  /* Stop if there were errors, to avoid trashing previous output
-     files.  */
-  if (complain_message_count)
-    exit (1);
-
   /* Output the VCG graph.  */
   if (graph_flag)
     {
@@ -132,10 +135,10 @@ main (int argc, char *argv[])
       timevar_pop (TV_GRAPH);
     }
 
-  /* Compute the parser tables.  */
-  timevar_push (TV_ACTIONS);
-  tables_generate ();
-  timevar_pop (TV_ACTIONS);
+  /* Stop if there were errors, to avoid trashing previous output
+     files.  */
+  if (complain_message_count)
+    exit (1);
 
   /* Lookaheads are no longer needed. */
   timevar_push (TV_FREE);
