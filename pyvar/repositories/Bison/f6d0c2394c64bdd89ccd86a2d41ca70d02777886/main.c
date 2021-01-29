@@ -74,7 +74,7 @@ main (int argc, char *argv[])
   timevar_pop (TV_READER);
 
   if (complaint_issued)
-    return EXIT_FAILURE;
+    goto finish;
 
   /* Find useless nonterminals and productions and reduce the grammar. */
   timevar_push (TV_REDUCE);
@@ -138,7 +138,7 @@ main (int argc, char *argv[])
   /* Stop if there were errors, to avoid trashing previous output
      files.  */
   if (complaint_issued)
-    return EXIT_FAILURE;
+    goto finish;
 
   /* Lookaheads are no longer needed. */
   timevar_push (TV_FREE);
@@ -173,6 +173,8 @@ main (int argc, char *argv[])
   if (trace_flag & trace_bitsets)
     bitset_stats_dump (stderr);
 
+ finish:
+
   /* Stop timing and print the times.  */
   timevar_stop (TV_TOTAL);
   timevar_print (stderr);
