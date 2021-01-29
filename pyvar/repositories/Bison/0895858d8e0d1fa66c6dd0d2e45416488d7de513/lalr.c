@@ -99,7 +99,7 @@ void
 set_goto_map (void)
 {
   /* Count the number of gotos (ngotos) per nterm (goto_map). */
-  goto_map = xcalloc (nvars + 1, sizeof *goto_map);
+  goto_map = xcalloc (nnterms + 1, sizeof *goto_map);
   ngotos = 0;
   for (state_number s = 0; s < nstates; ++s)
     {
@@ -113,7 +113,7 @@ set_goto_map (void)
         }
     }
 
-  goto_number *temp_map = xnmalloc (nvars + 1, sizeof *temp_map);
+  goto_number *temp_map = xnmalloc (nnterms + 1, sizeof *temp_map);
   {
     goto_number k = 0;
     for (symbol_number i = ntokens; i < nsyms; ++i)
@@ -583,7 +583,7 @@ lalr_update_state_numbers (state_number old_to_new[], state_number nstates_old)
 {
   goto_number ngotos_reachable = 0;
   symbol_number nonterminal = 0;
-  aver (nsyms == nvars + ntokens);
+  aver (nsyms == nnterms + ntokens);
 
   for (goto_number i = 0; i < ngotos; ++i)
     {
@@ -601,7 +601,7 @@ lalr_update_state_numbers (state_number old_to_new[], state_number nstates_old)
           ++ngotos_reachable;
         }
     }
-  while (nonterminal <= nvars)
+  while (nonterminal <= nnterms)
     {
       aver (ngotos == goto_map[nonterminal]);
       goto_map[nonterminal++] = ngotos_reachable;
