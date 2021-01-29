@@ -64,15 +64,16 @@ main (int argc, char *argv[])
   if (complain_message_count)
     exit (1);
 
-  /* find useless nonterminals and productions and reduce the grammar.  In
-     file reduce.c */
+  /* Find useless nonterminals and productions and reduce the grammar.
+     In file reduce.c.  */
   reduce_grammar ();
 
-  /* record other info about the grammar.  In files derives and nullable.  */
+  /* Record other info about the grammar.  In files derives and
+     nullable.  */
   set_derives ();
   set_nullable ();
 
-  /* convert to nondeterministic finite state machine.  In file LR0.
+  /* Convert to nondeterministic finite state machine.  In file LR0.
      See state.h for more info.  */
   generate_states ();
 
@@ -103,14 +104,14 @@ main (int argc, char *argv[])
   /* Output the tables and the parser to ftable.  In file output.  */
   output ();
 
+  /* Close the input files. */
+  close_files ();
+
   /* Free the symbol table data structure.  */
   free_symtab ();
 
   lex_free ();
 
-  /* Close the input files. */
-  close_files ();
-
   reduce_free ();
   free_conflicts ();
   free_nullable ();
