@@ -38,7 +38,7 @@
 /* -1 stands for not specified. */
 int expected_sr_conflicts = -1;
 int expected_rr_conflicts = -1;
-static char *conflicts = NULL;
+static char *conflicts;
 struct obstack solved_conflicts_obstack;
 
 static bitset shift_set;
@@ -305,9 +305,9 @@ conflicts_solve (void)
 {
   state_number i;
   /* List of look-ahead tokens on which we explicitly raise a syntax error.  */
-  symbol **errors = MALLOC (errors, ntokens + 1);
+  symbol **errors = xnmalloc (ntokens + 1, sizeof *errors);
 
-  CALLOC (conflicts, nstates);
+  conflicts = xcalloc (nstates, sizeof *conflicts);
   shift_set = bitset_create (ntokens, BITSET_FIXED);
   look_ahead_set = bitset_create (ntokens, BITSET_FIXED);
   obstack_init (&solved_conflicts_obstack);
