@@ -64,8 +64,7 @@ main (int argc, char *argv[])
   if (complain_message_count)
     exit (1);
 
-  /* Find useless nonterminals and productions and reduce the grammar.
-     In file reduce.c.  */
+  /* Find useless nonterminals and productions and reduce the grammar. */
   reduce_grammar ();
 
   /* Record other info about the grammar.  In files derives and
