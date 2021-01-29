@@ -46,11 +46,11 @@ print_token (int extnum, int token)
 `--------------------------------*/
 
 static void
-print_core (FILE *out, int state)
+print_core (FILE *out, state_t *state)
 {
   int i;
-  short *sitems = state_table[state]->items;
-  int snitems   = state_table[state]->nitems;
+  short *sitems = state->items;
+  int snitems   = state->nitems;
 
   /* New experimental feature: if TRACE_FLAGS output all the items of
      a state, not only its kernel.  */
@@ -94,17 +94,17 @@ print_core (FILE *out, int state)
 }
 
 static void
-print_actions (FILE *out, int state)
+print_actions (FILE *out, state_t *state)
 {
   int i;
 
-  shifts   *shiftp = state_table[state]->shifts;
-  reductions *redp = state_table[state]->reductions;
-  errs       *errp = state_table[state]->errs;
+  shifts   *shiftp = state->shifts;
+  reductions *redp = state->reductions;
+  errs       *errp = state->errs;
 
   if (!shiftp->nshifts && !redp)
     {
-      if (final_state == state)
+      if (final_state == state->number)
 	fprintf (out, _("    $default\taccept\n"));
       else
 	fprintf (out, _("    NO ACTIONS\n"));
@@ -140,7 +140,7 @@ print_actions (FILE *out, int state)
 	fputc ('\n', out);
     }
 
-  if (state_table[state]->consistent && redp)
+  if (state->consistent && redp)
     {
       int rule = redp->rules[0];
       int symbol = rule_table[rule].lhs;
@@ -168,9 +168,9 @@ print_actions (FILE *out, int state)
 }
 
 static void
-print_state (FILE *out, int state)
+print_state (FILE *out, state_t *state)
 {
-  fprintf (out, _("state %d"), state);
+  fprintf (out, _("state %d"), state->number);
   fputs ("\n\n", out);
   print_core (out, state);
   print_actions (out, state);
@@ -331,7 +331,7 @@ print_results (void)
   if (trace_flag)
     new_closure (nitems);
   for (i = 0; i < nstates; i++)
-    print_state (out, i);
+    print_state (out, state_table[i]);
   if (trace_flag)
     free_closure ();
 
