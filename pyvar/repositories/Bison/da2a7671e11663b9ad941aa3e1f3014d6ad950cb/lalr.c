@@ -80,8 +80,8 @@ set_goto_map (void)
   state_number s;
   goto_number *temp_map;
 
-  CALLOC (goto_map, nvars + 1);
-  CALLOC (temp_map, nvars + 1);
+  goto_map = xcalloc (nvars + 1, sizeof *goto_map);
+  temp_map = xnmalloc (nvars + 1, sizeof *temp_map);
 
   ngotos = 0;
   for (s = 0; s < nstates; ++s)
@@ -116,8 +116,8 @@ set_goto_map (void)
     temp_map[nsyms - ntokens] = ngotos;
   }
 
-  CALLOC (from_state, ngotos);
-  CALLOC (to_state, ngotos);
+  from_state = xcalloc (ngotos, sizeof *from_state);
+  to_state = xcalloc (ngotos, sizeof *to_state);
 
   for (s = 0; s < nstates; ++s)
     {
@@ -170,8 +170,8 @@ map_goto (state_number s0, symbol_number sym)
 static void
 initialize_F (void)
 {
-  goto_number **reads = CALLOC (reads, ngotos);
-  goto_number *edge = CALLOC (edge, ngotos + 1);
+  goto_number **reads = xnmalloc (ngotos, sizeof *reads);
+  goto_number *edge = xnmalloc (ngotos + 1, sizeof *edge);
   goto_number nedges = 0;
 
   goto_number i;
@@ -194,10 +194,12 @@ initialize_F (void)
 	    edge[nedges++] = map_goto (stateno, sym);
 	}
 
-      if (nedges)
+      if (nedges == 0)
+	reads[i] = NULL;
+      else
 	{
-	  CALLOC (reads[i], nedges + 1);
-	  memcpy (reads[i], edge, nedges * sizeof (edge[0]));
+	  reads[i] = xnmalloc (nedges + 1, sizeof reads[i][0]);
+	  memcpy (reads[i], edge, nedges * sizeof edge[0]);
 	  reads[i][nedges] = END_NODE;
 	  nedges = 0;
 	}
@@ -217,7 +219,7 @@ static void
 add_lookback_edge (state *s, rule *r, goto_number gotono)
 {
   int ri = state_reduction_find (s, r);
-  goto_list *sp = MALLOC (sp, 1);
+  goto_list *sp = xmalloc (sizeof *sp);
   sp->next = lookback[(s->reductions->look_ahead_tokens - LA) + ri];
   sp->value = gotono;
   lookback[(s->reductions->look_ahead_tokens - LA) + ri] = sp;
@@ -228,11 +230,11 @@ add_lookback_edge (state *s, rule *r, goto_number gotono)
 static void
 build_relations (void)
 {
-  goto_number *edge = CALLOC (edge, ngotos + 1);
-  state_number *states1 = CALLOC (states1, ritem_longest_rhs () + 1);
+  goto_number *edge = xnmalloc (ngotos + 1, sizeof *edge);
+  state_number *states1 = xnmalloc (ritem_longest_rhs () + 1, sizeof *states1);
   goto_number i;
 
-  CALLOC (includes, ngotos);
+  includes = xnmalloc (ngotos, sizeof *includes);
 
   for (i = 0; i < ngotos; i++)
     {
@@ -276,10 +278,12 @@ build_relations (void)
 	    }
 	}
 
-      if (nedges)
+      if (nedges == 0)
+	includes[i] = NULL;
+      else
 	{
 	  int j;
-	  CALLOC (includes[i], nedges + 1);
+	  includes[i] = xnmalloc (nedges + 1, sizeof includes[i][0]);
 	  for (j = 0; j < nedges; j++)
 	    includes[i][j] = edge[j];
 	  includes[i][nedges] = END_NODE;
@@ -381,7 +385,7 @@ initialize_LA (void)
     nLA = 1;
 
   pLA = LA = bitsetv_create (nLA, ntokens, BITSET_FIXED);
-  CALLOC (lookback, nLA);
+  lookback = xcalloc (nLA, sizeof *lookback);
 
   /* Initialize the members LOOK_AHEAD_TOKENS for each state whose reductions
      require look-ahead tokens.  */
