@@ -82,7 +82,7 @@ main (int argc, char *argv[])
 
   timevar_enabled = trace_flag & trace_time;
   timevar_init ();
-  timevar_start (TV_TOTAL);
+  timevar_start (tv_total);
 
   if (trace_flag & trace_bitsets)
     bitset_stats_enable ();
@@ -91,29 +91,29 @@ main (int argc, char *argv[])
      and FATTRS.  In file reader.c.  The other parts are recorded in
      the grammar; see gram.h.  */
 
-  timevar_push (TV_READER);
+  timevar_push (tv_reader);
   reader ();
-  timevar_pop (TV_READER);
+  timevar_pop (tv_reader);
 
   if (complaint_status == status_complaint)
     goto finish;
 
   /* Find useless nonterminals and productions and reduce the grammar. */
-  timevar_push (TV_REDUCE);
+  timevar_push (tv_reduce);
   reduce_grammar ();
-  timevar_pop (TV_REDUCE);
+  timevar_pop (tv_reduce);
 
   /* Record other info about the grammar.  In files derives and
      nullable.  */
-  timevar_push (TV_SETS);
+  timevar_push (tv_sets);
   derives_compute ();
   nullable_compute ();
-  timevar_pop (TV_SETS);
+  timevar_pop (tv_sets);
 
   /* Compute LR(0) parser states.  See state.h for more info.  */
-  timevar_push (TV_LR0);
+  timevar_push (tv_lr0);
   generate_states ();
-  timevar_pop (TV_LR0);
+  timevar_pop (tv_lr0);
 
   /* Add lookahead sets to parser states.  Except when LALR(1) is
      requested, split states to eliminate LR(1)-relative
@@ -124,7 +124,7 @@ main (int argc, char *argv[])
      lookahead is not enough to disambiguate the parsing.  In file
      conflicts.  Also resolve s/r conflicts based on precedence
      declarations.  */
-  timevar_push (TV_CONFLICTS);
+  timevar_push (tv_conflicts);
   conflicts_solve ();
   if (!muscle_percent_define_flag_if ("lr.keep-unreachable-state"))
     {
@@ -136,12 +136,12 @@ main (int argc, char *argv[])
       free (old_to_new);
     }
   conflicts_print ();
-  timevar_pop (TV_CONFLICTS);
+  timevar_pop (tv_conflicts);
 
   /* Compute the parser tables.  */
-  timevar_push (TV_ACTIONS);
+  timevar_push (tv_actions);
   tables_generate ();
-  timevar_pop (TV_ACTIONS);
+  timevar_pop (tv_actions);
 
   grammar_rules_useless_report (_("rule useless in parser due to conflicts"));
 
@@ -153,25 +153,25 @@ main (int argc, char *argv[])
   /* Output the detailed report on the grammar.  */
   if (report_flag)
     {
-      timevar_push (TV_REPORT);
+      timevar_push (tv_report);
       print_results ();
-      timevar_pop (TV_REPORT);
+      timevar_pop (tv_report);
     }
 
   /* Output the graph.  */
   if (graph_flag)
     {
-      timevar_push (TV_GRAPH);
+      timevar_push (tv_graph);
       print_graph ();
-      timevar_pop (TV_GRAPH);
+      timevar_pop (tv_graph);
     }
 
   /* Output xml.  */
   if (xml_flag)
     {
-      timevar_push (TV_XML);
+      timevar_push (tv_xml);
       print_xml ();
-      timevar_pop (TV_XML);
+      timevar_pop (tv_xml);
     }
 
   /* Stop if there were errors, to avoid trashing previous output
@@ -180,16 +180,16 @@ main (int argc, char *argv[])
     goto finish;
 
   /* Lookahead tokens are no longer needed. */
-  timevar_push (TV_FREE);
+  timevar_push (tv_free);
   lalr_free ();
-  timevar_pop (TV_FREE);
+  timevar_pop (tv_free);
 
   /* Output the tables and the parser to ftable.  In file output.  */
-  timevar_push (TV_PARSER);
+  timevar_push (tv_parser);
   output ();
-  timevar_pop (TV_PARSER);
+  timevar_pop (tv_parser);
 
-  timevar_push (TV_FREE);
+  timevar_push (tv_free);
   nullable_free ();
   derives_free ();
   tables_free ();
@@ -207,7 +207,7 @@ main (int argc, char *argv[])
   code_scanner_free ();
   skel_scanner_free ();
   quotearg_free ();
-  timevar_pop (TV_FREE);
+  timevar_pop (tv_free);
 
   if (trace_flag & trace_bitsets)
     bitset_stats_dump (stderr);
@@ -215,7 +215,7 @@ main (int argc, char *argv[])
  finish:
 
   /* Stop timing and print the times.  */
-  timevar_stop (TV_TOTAL);
+  timevar_stop (tv_total);
   timevar_print (stderr);
 
   cleanup_caret ();
