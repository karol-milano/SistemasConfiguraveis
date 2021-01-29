@@ -113,7 +113,7 @@ print_shifts (FILE *out, state_t *state)
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       {
-	int state1 = shiftp->shifts[i];
+	state_number_t state1 = shiftp->shifts[i];
 	symbol_number_t symbol = states[state1]->accessing_symbol;
 	fprintf (out,
 		 _("    %-4s\tshift, and go to state %d\n"),
@@ -155,7 +155,7 @@ print_gotos (FILE *out, state_t *state)
       for (; i < shiftp->nshifts; i++)
 	if (!SHIFT_IS_DISABLED (shiftp, i))
 	  {
-	    int state1 = shiftp->shifts[i];
+	    state_number_t state1 = shiftp->shifts[i];
 	    symbol_number_t symbol = states[state1]->accessing_symbol;
 	    fprintf (out, _("    %-4s\tgo to state %d\n"),
 		     symbol_tag_get (symbols[symbol]), state1);
@@ -309,7 +309,7 @@ print_actions (FILE *out, state_t *state)
 
   if (shiftp->nshifts == 0 && redp->nreds == 0)
     {
-      if (final_state == state->number)
+      if (state->number == final_state->number)
        fprintf (out, _("    $default\taccept\n"));
       else
        fprintf (out, _("    NO ACTIONS\n"));
@@ -449,7 +449,7 @@ print_grammar (FILE *out)
 void
 print_results (void)
 {
-  size_t i;
+  state_number_t i;
 
   /* We used to use just .out if SPEC_NAME_PREFIX (-p) was used, but
      that conflicts with Posix.  */
