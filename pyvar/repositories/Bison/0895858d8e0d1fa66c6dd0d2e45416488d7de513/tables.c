@@ -547,7 +547,7 @@ static void
 goto_actions (void)
 {
   size_t *state_count = xnmalloc (nstates, sizeof *state_count);
-  yydefgoto = xnmalloc (nvars, sizeof *yydefgoto);
+  yydefgoto = xnmalloc (nnterms, sizeof *yydefgoto);
 
   /* For a given nterm I, STATE_COUNT[S] is the number of times there
      is a GOTO to S on I.  */
@@ -780,9 +780,9 @@ tables_generate (void)
      correlated.  In particular the signedness is not taken into
      account.  But it's not useless.  */
   verify (sizeof nstates <= sizeof nvectors);
-  verify (sizeof nvars <= sizeof nvectors);
+  verify (sizeof nnterms <= sizeof nvectors);
 
-  nvectors = state_number_as_int (nstates) + nvars;
+  nvectors = state_number_as_int (nstates) + nnterms;
 
   froms = xcalloc (nvectors, sizeof *froms);
   tos = xcalloc (nvectors, sizeof *tos);
