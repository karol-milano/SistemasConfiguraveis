@@ -44,27 +44,6 @@
 char *program_name;
 
 
-/*--------------------------.
-| Tracking space and time.  |
-`--------------------------*/
-
-static void
-stage (const char *title)
-{
-#if HAVE_MALLINFO && HAVE_STRUCT_MALLINFO & HAVE_TIMES & HAVE_STRUCT_TMS
-  if (trace_flag & trace_resource)
-    {
-      struct mallinfo minfo = mallinfo ();
-      struct tms tinfo;
-      times (&tinfo);
-      fprintf (stderr, "STAGE: %30s: %9d (%9d): %ldu %lds\n",
-	       title,
-	       minfo.uordblks, minfo.arena,
-	       tinfo.tms_utime, tinfo.tms_stime);
-    }
-#endif
-}
-
 
 int
 main (int argc, char *argv[])
@@ -76,58 +55,69 @@ main (int argc, char *argv[])
 
   getargs (argc, argv);
 
+  time_report = trace_flag & trace_time;
+  init_timevar ();
+  timevar_start (TV_TOTAL);
+
   if (trace_flag & trace_bitsets)
     bitset_stats_enable ();
 
   muscle_init ();
 
-  stage ("initialized muscles");
-
   /* Read the input.  Copy some parts of it to FGUARD, FACTION, FTABLE
      and FATTRS.  In file reader.c.  The other parts are recorded in
      the grammar; see gram.h.  */
-  reader ();
 
-  stage ("reader");
+  timevar_push (TV_READER);
+  reader ();
+  timevar_pop (TV_READER);
 
   if (complain_message_count)
     exit (1);
 
   /* Find useless nonterminals and productions and reduce the grammar. */
+  timevar_push (TV_REDUCE);
   reduce_grammar ();
-
-  stage ("reduced grammar");
+  timevar_pop (TV_REDUCE);
 
   /* Record other info about the grammar.  In files derives and
      nullable.  */
+  timevar_push (TV_SETS);
   set_derives ();
   set_nullable ();
+  timevar_pop (TV_SETS);
 
   /* Convert to nondeterministic finite state machine.  In file LR0.
      See state.h for more info.  */
+  timevar_push (TV_LR0);
   generate_states ();
+  timevar_pop (TV_LR0);
 
-  stage ("generated states");
   /* make it deterministic.  In file lalr.  */
+  timevar_push (TV_LALR);
   lalr ();
+  timevar_pop (TV_LALR);
 
-  stage ("lalred");
   /* Find and record any conflicts: places where one token of
      lookahead is not enough to disambiguate the parsing.  In file
      conflicts.  Also resolve s/r conflicts based on precedence
      declarations.  */
+  timevar_push (TV_CONFLICTS);
   conflicts_solve ();
   conflicts_print ();
+  timevar_pop (TV_CONFLICTS);
 
-  stage ("solved conflicts");
   /* Output file names. */
   compute_output_file_names ();
 
   /* Output the detailed report on the grammar.  */
   if (report_flag)
-    print_results ();
+    {
+      timevar_push (TV_REPORT);
+      print_results ();
+      timevar_pop (TV_REPORT);
+    }
 
-  stage ("printed results");
   /* Stop if there were errors, to avoid trashing previous output
      files.  */
   if (complain_message_count)
@@ -135,39 +125,42 @@ main (int argc, char *argv[])
 
   /* Output the VCG graph.  */
   if (graph_flag)
-    print_graph ();
+    {
+      timevar_push (TV_GRAPH);
+      print_graph ();
+      timevar_pop (TV_GRAPH);
+    }
 
   /* Output the tables and the parser to ftable.  In file output.  */
+  timevar_push (TV_PARSER);
   output ();
-  stage ("made output");
+  timevar_pop (TV_PARSER);
 
+  timevar_push (TV_FREE);
   states_free ();
-  stage ("freed states");
   reduce_free ();
-  stage ("freed reduce");
   conflicts_free ();
-  stage ("freed conflicts");
   free_nullable ();
-  stage ("freed nullable");
   free_derives ();
-  stage ("freed derives");
   grammar_free ();
-  stage ("freed grammar");
 
   /* The scanner memory cannot be released right after parsing, as it
      contains things such as user actions, prologue, epilogue etc.  */
   scanner_free ();
-  stage ("freed scanner");
   muscle_free ();
-  stage ("freed muscles");
   /* If using alloca.c, flush the alloca'ed memory for the benefit of
      people running Bison as a library in IDEs.  */
 #if C_ALLOCA
   alloca (0);
 #endif
+  timevar_pop (TV_FREE);
 
   if (trace_flag & trace_bitsets)
     bitset_stats_dump (stderr);
 
+  /* Stop timing and print the times.  */
+  timevar_stop (TV_TOTAL);
+  timevar_print (stderr);
+
   return complain_message_count ? EXIT_FAILURE : EXIT_SUCCESS;
 }
