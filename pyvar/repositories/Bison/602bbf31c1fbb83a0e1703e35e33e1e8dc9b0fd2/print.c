@@ -216,7 +216,7 @@ print_reductions (FILE *out, state_t *state)
       int default_rule = LAruleno[state->lookaheadsp];
 
       for (i = 0; i < ntokens; ++i)
-	if (BITISSET (LA (state->lookaheadsp), i)
+	if (bitset_test (LA[state->lookaheadsp], i)
 	    && bitset_test (shiftset, i))
 	  bitset_set (lookaheadset, i);
 	else
@@ -244,7 +244,7 @@ print_reductions (FILE *out, state_t *state)
 	    int j, k;
 
 	    for (k = 0; k < ntokens; ++k)
-	      if (BITISSET (LA (state->lookaheadsp + i), k)
+	      if (bitset_test (LA[state->lookaheadsp + i], k)
 		  && ! bitset_test (shiftset, k))
 		bitset_set (lookaheadset, k);
 	      else
@@ -278,7 +278,7 @@ print_reductions (FILE *out, state_t *state)
 
 	  for (j = 0; j < state->nlookaheads; ++j)
 	    {
-	      if (BITISSET (LA (state->lookaheadsp + j), i))
+	      if (bitset_test (LA[state->lookaheadsp + j], i))
 		{
 		  if (count == 0)
 		    {
@@ -479,7 +479,7 @@ print_grammar (FILE *out)
 void
 print_results (void)
 {
-  int i;
+  size_t i;
 
   /* We used to use just .out if SPEC_NAME_PREFIX (-p) was used, but
      that conflicts with Posix.  */
