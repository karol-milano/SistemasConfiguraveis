@@ -183,7 +183,7 @@ conflict_row (state *s)
   int i, j;
   reductions *reds = s->reductions;
 
-  if (! glr_parser)
+  if (!nondeterministic_parser)
     return;
 
   for (j = 0; j < ntokens; j += 1)
@@ -334,7 +334,7 @@ action_row (state *s)
 	      int j;
 	      for (j = 0; j < ntokens; j++)
 		if (actrow[j] == rule_number_as_item_number (default_rule->number)
-		    && ! (glr_parser && conflrow[j]))
+		    && ! (nondeterministic_parser && conflrow[j]))
 		  actrow[j] = 0;
 	    }
 	}
@@ -381,7 +381,7 @@ save_row (state_number s)
   /* Allocate non defaulted actions.  */
   froms[s] = sp = CALLOC (sp1, count);
   tos[s] = CALLOC (sp2, count);
-  conflict_tos[s] = glr_parser ? CALLOC (sp3, count) : NULL;
+  conflict_tos[s] = nondeterministic_parser ? CALLOC (sp3, count) : NULL;
 
   /* Store non defaulted actions.  */
   for (i = 0; i < ntokens; i++)
@@ -389,7 +389,7 @@ save_row (state_number s)
       {
 	*sp1++ = i;
 	*sp2++ = actrow[i];
-	if (glr_parser)
+	if (nondeterministic_parser)
 	  *sp3++ = conflrow[i];
       }
 
@@ -413,7 +413,7 @@ token_actions (void)
   symbol_number j;
   rule_number r;
 
-  int nconflict = glr_parser ? conflicts_total_count () : 0;
+  int nconflict = nondeterministic_parser ? conflicts_total_count () : 0;
 
   CALLOC (yydefact, nstates);
 
@@ -425,7 +425,7 @@ token_actions (void)
   conflict_list_cnt = 1;
 
   /* Find the rules which are reduced.  */
-  if (!glr_parser)
+  if (!nondeterministic_parser)
     for (r = 0; r < nrules; ++r)
       rules[r].useful = false;
 
@@ -438,7 +438,7 @@ token_actions (void)
       /* Now that the parser was computed, we can find which rules are
 	 really reduced, and which are not because of SR or RR
 	 conflicts.  */
-      if (!glr_parser)
+      if (!nondeterministic_parser)
 	{
 	  for (j = 0; j < ntokens; ++j)
 	    if (actrow[j] < 0 && actrow[j] != ACTION_NUMBER_MINIMUM)
@@ -663,7 +663,7 @@ pack_vector (vector_number vector)
   base_number *to = tos[i];
   unsigned int *conflict_to = conflict_tos[i];
 
-  if (! t)
+  if (!t)
     abort ();
 
   for (j = lowzero - from[0]; ; j++)
@@ -694,7 +694,7 @@ pack_vector (vector_number vector)
 	    {
 	      loc = j + from[k];
 	      table[loc] = to[k];
-	      if (glr_parser && conflict_to != NULL)
+	      if (nondeterministic_parser && conflict_to != NULL)
 		conflict_table[loc] = conflict_to[k];
 	      check[loc] = from[k];
 	    }
