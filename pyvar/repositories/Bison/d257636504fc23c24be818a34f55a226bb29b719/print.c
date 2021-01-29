@@ -178,9 +178,9 @@ print_errs (FILE *out, state_t *state)
   int i;
 
   /* Compute the width of the lookaheads column.  */
-  for (i = 0; i < errp->nerrs; ++i)
-    if (errp->errs[i])
-      max_length (&width, symbol_tag_get (symbols[errp->errs[i]]));
+  for (i = 0; i < errp->num; ++i)
+    if (errp->symbols[i])
+      max_length (&width, symbol_tag_get (symbols[errp->symbols[i]]));
 
   /* Nothing to report. */
   if (!width)
@@ -190,10 +190,10 @@ print_errs (FILE *out, state_t *state)
   width += 2;
 
   /* Report lookaheads and errors.  */
-  for (i = 0; i < errp->nerrs; ++i)
-    if (errp->errs[i])
+  for (i = 0; i < errp->num; ++i)
+    if (errp->symbols[i])
       {
-	const char *tag = symbol_tag_get (symbols[errp->errs[i]]);
+	const char *tag = symbol_tag_get (symbols[errp->symbols[i]]);
 	int j;
 	fprintf (out, "    %s", tag);
 	for (j = width - strlen (tag); j > 0; --j)
@@ -240,9 +240,9 @@ state_default_rule (state_t *state)
      we raise an error (due to %nonassoc).  */
   {
     errs_t *errp = state->errs;
-    for (i = 0; i < errp->nerrs; i++)
-      if (errp->errs[i])
-	bitset_set (shiftset, errp->errs[i]);
+    for (i = 0; i < errp->num; i++)
+      if (errp->symbols[i])
+	bitset_set (shiftset, errp->symbols[i]);
   }
 
   for (i = 0; i < state->nlookaheads; ++i)
@@ -308,7 +308,7 @@ print_reductions (FILE *out, state_t *state)
   size_t width = 0;
   int i, j;
 
-  if (redp->nreds == 0)
+  if (redp->num == 0)
     return;
 
   default_rule = state_default_rule (state);
@@ -398,7 +398,7 @@ print_actions (FILE *out, state_t *state)
   reductions_t *redp = state->reductions;
   transitions_t *transitions = state->shifts;
 
-  if (transitions->num == 0 && redp->nreds == 0)
+  if (transitions->num == 0 && redp->num == 0)
     {
       fputc ('\n', out);
       if (state->number == final_state->number)
