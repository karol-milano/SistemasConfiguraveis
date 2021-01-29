@@ -304,9 +304,9 @@ conflicts_solve (void)
 {
   state_number i;
   /* List of lookaheads on which we explicitly raise a syntax error.  */
-  symbol **errors = XMALLOC (symbol *, ntokens + 1);
+  symbol **errors = MALLOC (errors, ntokens + 1);
 
-  conflicts = XCALLOC (char, nstates);
+  CALLOC (conflicts, nstates);
   shiftset = bitset_create (ntokens, BITSET_FIXED);
   lookaheadset = bitset_create (ntokens, BITSET_FIXED);
   obstack_init (&solved_conflicts_obstack);
@@ -545,7 +545,7 @@ conflicts_print (void)
 void
 conflicts_free (void)
 {
-  XFREE (conflicts);
+  free (conflicts);
   bitset_free (shiftset);
   bitset_free (lookaheadset);
   obstack_free (&solved_conflicts_obstack, NULL);
