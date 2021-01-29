@@ -39,10 +39,24 @@
 #include "conflicts.h"
 #include "print_graph.h"
 #include "muscle_tab.h"
+#include <malloc.h>
+#include <sys/times.h>
 
 /* The name this program was run with, for messages.  */
 char *program_name;
 
+static void
+stage (const char *title)
+{
+  struct mallinfo minfo = mallinfo ();
+  struct tms tinfo;
+  times (&tinfo);
+  fprintf (stderr, "STAGE: %30s: %9d (%9d): %ldu %lds\n",
+	   title,
+	   minfo.uordblks, minfo.arena,
+	   tinfo.tms_utime, tinfo.tms_stime);
+}
+
 int
 main (int argc, char *argv[])
 {
@@ -58,16 +72,23 @@ main (int argc, char *argv[])
 
   muscle_init ();
 
+  stage ("initialized muscles");
+
   /* Read the input.  Copy some parts of it to FGUARD, FACTION, FTABLE
      and FATTRS.  In file reader.c.  The other parts are recorded in
      the grammar; see gram.h.  */
   reader ();
+
+  stage ("reader");
+
   if (complain_message_count)
     exit (1);
 
   /* Find useless nonterminals and productions and reduce the grammar. */
   reduce_grammar ();
 
+  stage ("reduced grammar");
+
   /* Record other info about the grammar.  In files derives and
      nullable.  */
   set_derives ();
@@ -77,9 +98,11 @@ main (int argc, char *argv[])
      See state.h for more info.  */
   generate_states ();
 
+  stage ("generated states");
   /* make it deterministic.  In file lalr.  */
   lalr ();
 
+  stage ("lalred");
   /* Find and record any conflicts: places where one token of
      lookahead is not enough to disambiguate the parsing.  In file
      conflicts.  Also resolve s/r conflicts based on precedence
@@ -87,6 +110,7 @@ main (int argc, char *argv[])
   conflicts_solve ();
   conflicts_print ();
 
+  stage ("solved conflicts");
   /* Output file names. */
   compute_output_file_names ();
 
@@ -94,6 +118,7 @@ main (int argc, char *argv[])
   if (report_flag)
     print_results ();
 
+  stage ("printed results");
   /* Stop if there were errors, to avoid trashing previous output
      files.  */
   if (complain_message_count)
@@ -105,26 +130,35 @@ main (int argc, char *argv[])
 
   /* Output the tables and the parser to ftable.  In file output.  */
   output ();
+  stage ("made output");
 
   states_free ();
+  stage ("freed states");
   reduce_free ();
+  stage ("freed reduce");
   conflicts_free ();
+  stage ("freed conflicts");
   free_nullable ();
+  stage ("freed nullable");
   free_derives ();
+  stage ("freed derives");
   grammar_free ();
+  stage ("freed grammar");
 
   /* The scanner memory cannot be released right after parsing, as it
      contains things such as user actions, prologue, epilogue etc.  */
   scanner_free ();
+  stage ("freed scanner");
   muscle_free ();
+  stage ("freed muscles");
   /* If using alloca.c, flush the alloca'ed memory for the benefit of
      people running Bison as a library in IDEs.  */
 #if C_ALLOCA
-    alloca (0);
+  alloca (0);
 #endif
 
-    if (trace_flag)
-      bitset_stats_dump (stderr);
+  if (trace_flag)
+    bitset_stats_dump (stderr);
 
   return complain_message_count ? EXIT_FAILURE : EXIT_SUCCESS;
 }
