@@ -252,7 +252,7 @@ resolve_sr_conflict (state_t *state, int ruleno,
 | Solve the S/R conflicts of STATE using the                         |
 | precedence/associativity, and flag it inconsistent if it still has |
 | conflicts.  ERRS can be used as storage to compute the list of     |
-| lookaheads on which this STATE raises a parse error (%nonassoc).   |
+| lookaheads on which this STATE raises a syntax error (%nonassoc).  |
 `-------------------------------------------------------------------*/
 
 static void
@@ -302,7 +302,7 @@ void
 conflicts_solve (void)
 {
   state_number_t i;
-  /* List of lookaheads on which we explicitly raise a parse error.  */
+  /* List of lookaheads on which we explicitly raise a syntax error.  */
   symbol_t **errs = XMALLOC (symbol_t *, ntokens + 1);
 
   conflicts = XCALLOC (char, nstates);
